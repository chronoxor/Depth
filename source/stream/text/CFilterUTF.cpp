/*!
 *  \file    CFilterUTF.cpp UTF string filter class converts given ASCII and
 *           Unicode strings into the UTF equivalents.
 *  \brief   UTF string filter class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.10.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: UTF string filter class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   26.10.2009 23:23:33

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

    This program is distributed in the  hope  that  it  will  be  useful,  but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General  Public  License
    for more details.

    You should have received a copy of the GNU General  Public  License  along
    with this program; if not, write to the Free Software Foundation, Inc., 59
    Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
/*--------------------------------------------------------------------------*/
/*
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/stream/text/CFilterUTF.hpp>
/*==========================================================================*/
#ifndef __CFILTERUTF_CPP__
#define __CFILTERUTF_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NText {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CFilterUTF::set(const CFilterUTF& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CFilterUTF class instance."))
  {
    return false;
  }

  // Initialize base filter class.
  if (!IFilter::set(a_crInstance))
    return false;

  // Set cache, UTF type and BOM flag.
  m_Cache[0] = a_crInstance.m_Cache[0];
  m_Cache[1] = a_crInstance.m_Cache[1];
  m_Cache[2] = a_crInstance.m_Cache[2];
  m_Cache[3] = a_crInstance.m_Cache[3];
  m_CacheSize = a_crInstance.m_CacheSize;
  m_IsBOMUsed = a_crInstance.m_IsBOMUsed;
  m_UTFType = a_crInstance.m_UTFType;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterUTF::onOpen(const EOpenType a_cOpenType)
{ CALL
  // UTF types count.
  const Tuint count = 5;
  // Cache size.
  const Tuint size = 4;
  // BOM values.
  const Tuint BOM[][5] =
  {
    // BOM for UTF-8 encoding.
    { 3, 0xEF, 0xBB, 0xBF, 0xFF },
    // BOM for UTF-16 (Big-Endian) encoding.
    { 2, 0xFE, 0xFF, 0xFF, 0xFF },
    // BOM for UTF-16 (Little-Endian) encoding.
    { 2, 0xFF, 0xFE, 0xFF, 0xFF },
    // BOM for UTF-32 (Big-Endian) encoding.
    { 4, 0x00, 0x00, 0xFE, 0xFF },
    // BOM for UTF-32 (Little-Endian) encoding.
    { 4, 0xFF, 0xFE, 0x00, 0x00 }
  };

  // Try to open base filter.
  if (!IFilter::onOpen(a_cOpenType))
    return false;

  // Clear cache.
  m_CacheSize = 0;

  // Perform BOM read operation.
  if (m_IsBOMUsed)
  {
    Tuint indexes1[] = { 0, 0, 0, 0, 0 };
    Tuint indexes2[] = { 0, 0, 0, 0, 0 };

    switch (m_UTFType)
    {
      case e_AUTODETECT:
      {
        // Select all BOM values.
        indexes1[0] = indexes1[1] = indexes1[2] = indexes1[3] = indexes1[4] = 1;
        indexes2[0] = indexes2[1] = indexes2[2] = indexes2[3] = indexes2[4] = 1;
        break;
      }
      case e_UTF8:
      {
        // Select UTF-8 BOM value.
        indexes1[0] = indexes2[0] = 1;
        break;
      }
      case e_UTF16BE:
      {
        // Select UTF-16 (BE) BOM value.
        indexes1[1] = indexes2[1] = 1;
        break;
      }
      case e_UTF16LE:
      {
        // Select UTF-16 (LE) BOM value.
        indexes1[2] = indexes2[2] = 1;
        break;
      }
      case e_UTF32BE:
      {
        // Select UTF-32 (BE) BOM value.
        indexes1[3] = indexes2[3] = 1;
        break;
      }
      case e_UTF32LE:
      {
        // Select UTF-32 (LE) BOM value.
        indexes1[4] = indexes2[4] = 1;
        break;
      }
      default:
      {
        WARNING(STR("Cannot handle BOM for unknown UTF type."));
        return false;
      }
    }

    // Force reading BOM.
    if ((a_cOpenType == IStream::e_OPEN_READ) || (a_cOpenType == IStream::e_OPEN_READWRITE))
    {
      Tschar c;
      Tsint found = -1;

      // Go through all cache.
      for (Tuint i = 0; i < size; ++i)
      {
        // Read the next BOM character form the stream.
        if (getReader()->readBuffer(&c, 1) != 1)
        {
          WARNING(STR("Cannot read the next BOM character from the stream."));
          return false;
        }

        // Update cache.
        m_Cache[m_CacheSize++] = c;

        // Compare the next BOM character for the one in UTF types.
        for (Tuint j = 0; j < count; ++j)
        {
          // Check if we found required UTF type.
          if (c == (Tschar)BOM[j][i + 1])
          {
            // Stop searching in the current UTF type.
            if ((indexes1[j] > 0) && ((i + 1) == BOM[j][0]))
            {
              found = j;
              indexes1[j] = 0;
            }
          }
          else
            indexes1[j] = 0;
        }
      }

      // Validate the BOM flag.
      if (found >= 0)
      {
        if (indexes2[found] > 0)
        {
          // BOM flag was successfully read.
          m_UTFType = (EUTFType)(e_AUTODETECT + found + 1);

          // Correct the cache.
          for (Tuint i = BOM[found][0]; i < m_CacheSize; ++i)
            m_Cache[i - BOM[found][0]] = m_Cache[i];
          m_CacheSize = m_CacheSize - BOM[found][0];
        }
        else
        {
          WARNING(STR("Read BOM is not supported by the filter with the current UTF type (BOM = %u, UTF type = %u).") COMMA (Tuint)(found + 1) COMMA (Tuint)m_UTFType);
          return false;
        }
      }
      else
      {
        WARNING(STR("Cannot found suitable BOM in the stream to detect or commit the current UTF type (UTF type = %u).") COMMA (Tuint)m_UTFType);
        return false;
      }
    }
  }

  // Detect the UTF type.
  if (m_UTFType == e_AUTODETECT)
  {
    #if (defined(__SYSENC_UTF8__))
    m_UTFType = e_UTF8;
    #elif (defined(__SYSENC_UTF16BE__))
    m_UTFType = e_UTF16BE;
    #elif (defined(__SYSENC_UTF16LE__))
    m_UTFType = e_UTF16LE;
    #elif (defined(__SYSENC_UTF32BE__))
    m_UTFType = e_UTF32BE;
    #elif (defined(__SYSENC_UTF32LE__))
    m_UTFType = e_UTF32LE;
    #else
      #error "System UTF type is not defined!"
    #endif
  }

  // Perform BOM write operation.
  if (m_IsBOMUsed)
  {
    // Force writing BOM.
    if ((a_cOpenType == IStream::e_OPEN_WRITE) || (a_cOpenType == IStream::e_OPEN_READWRITE))
    {
      Tschar c;
      Tuint index = (Tuint)(m_UTFType - e_AUTODETECT - 1);

      // Go through all BOM values.
      for (Tuint i = 0; i < BOM[index][0]; ++i)
      {
        // Get the next BOM character.
        c = (Tschar)BOM[index][i + 1];

        // Write the next BOM character into the stream.
        if (getWriter()->writeBuffer(&c, 1) != 1)
        {
          WARNING(STR("Cannot write the next BOM character into the stream."));
          return false;
        }
      }
    }
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterUTF::onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  return a_rReader.readBuffer(a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterUTF::onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  Tuint wc;
  Tuint result = 0;
  Tuint count = a_cSize;
  Tbuffer dst = (Tbuffer)a_pBuffer;

  while (count-- > 0)
  {
    // Read UTF character.
    switch (m_UTFType)
    {
      case e_UTF8:
      {
        if (!readUTF8(a_rReader, wc))
          return result;
        break;
      }
      case e_UTF16BE:
      {
        if (!readUTF16(a_rReader, wc, true))
          return result;
        break;
      }
      case e_UTF16LE:
      {
        if (!readUTF16(a_rReader, wc, false))
          return result;
        break;
      }
      case e_UTF32BE:
      {
        if (!readUTF32(a_rReader, wc, true))
          return result;
        break;
      }
      case e_UTF32LE:
      {
        if (!readUTF32(a_rReader, wc, true))
          return result;
        break;
      }
      case e_AUTODETECT:
      default:
      {
        WARNING(STR("UTF type of the current filter is unknown."));
        return result;
      }
    }

    // Convert into the ASCII buffer.
    if (wc < 0x100)
      dst[0] = (Tbyte)(wc);
    else
    {
      WARNING(STR("Cannot convert wide character into the ASCII one (character code is %hU).") COMMA wc);
      return result;
    }

    // Take next character.
    dst += sizeof(Tschar);
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterUTF::onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  Tuint wc;
  Tuint result = 0;
  Tuint count = a_cSize;
  Tbuffer dst = (Tbuffer)a_pBuffer;

  while (count-- > 0)
  {
    // Read UTF character.
    switch (m_UTFType)
    {
      case e_UTF8:
      {
        if (!readUTF8(a_rReader, wc))
          return result;
        break;
      }
      case e_UTF16BE:
      {
        if (!readUTF16(a_rReader, wc, true))
          return result;
        break;
      }
      case e_UTF16LE:
      {
        if (!readUTF16(a_rReader, wc, false))
          return result;
        break;
      }
      case e_UTF32BE:
      {
        if (!readUTF32(a_rReader, wc, true))
          return result;
        break;
      }
      case e_UTF32LE:
      {
        if (!readUTF32(a_rReader, wc, true))
          return result;
        break;
      }
      case e_AUTODETECT:
      default:
      {
        WARNING(STR("UTF type of the current filter is unknown."));
        return result;
      }
    }

    // Convert into the Unicode buffer.
    #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
      if ((wc < 0x10000) && !((wc >= 0xD800) && (wc < 0xE000)))
      {
        #if defined(__BIG_ENDIAN__)
        dst[0] = (Tbyte)(wc >> 8);
        dst[1] = (Tbyte)(wc);
        #else
        dst[0] = (Tbyte)(wc);
        dst[1] = (Tbyte)(wc >> 8);
        #endif
      }
      else
      {
        WARNING(STR("Cannot convert wide character into the Unicode one (character code is %hU).") COMMA wc);
        return result;
      }
    #elif (defined(__WCHAR_S_UCS4__) || defined(__WCHAR_U_UCS4__))
      #if defined(__BIG_ENDIAN__)
      dst[0] = (Tbyte)(wc >> 24);
      dst[1] = (Tbyte)(wc >> 16);
      dst[2] = (Tbyte)(wc >> 8);
      dst[3] = (Tbyte)(wc);
      #else
      dst[0] = (Tbyte)(wc);
      dst[1] = (Tbyte)(wc >> 8);
      dst[2] = (Tbyte)(wc >> 16);
      dst[3] = (Tbyte)(wc >> 24);
      #endif
    #else
      #error "System Unicode size is not supported!"
    #endif

    // Take next character.
    dst += sizeof(Twchar);
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterUTF::onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return a_rWriter.writeBuffer(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterUTF::onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  Tuint wc;
  Tuint result = 0;
  Tuint count = a_cSize;
  Tcbuffer src = (Tcbuffer)a_cpBuffer;

  while (count-- > 0)
  {
    // Convert from the ASCII buffer.
    wc = src[0];

    // Write UTF character.
    switch (m_UTFType)
    {
      case e_UTF8:
      {
        if (!writeUTF8(a_rWriter, wc))
          return result;
        break;
      }
      case e_UTF16BE:
      {
        if (!writeUTF16(a_rWriter, wc, true))
          return result;
        break;
      }
      case e_UTF16LE:
      {
        if (!writeUTF16(a_rWriter, wc, false))
          return result;
        break;
      }
      case e_UTF32BE:
      {
        if (!writeUTF32(a_rWriter, wc, true))
          return result;
        break;
      }
      case e_UTF32LE:
      {
        if (!writeUTF32(a_rWriter, wc, true))
          return result;
        break;
      }
      case e_AUTODETECT:
      default:
      {
        WARNING(STR("UTF type of the current filter is unknown."));
        return result;
      }
    }

    // Take next character.
    src += sizeof(Tschar);
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterUTF::onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  Tuint wc;
  Tuint result = 0;
  Tuint count = a_cSize;
  Tcbuffer src = (Tcbuffer)a_cpBuffer;

  while (count-- > 0)
  {
    // Convert from the Unicode buffer.
    #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
      #if defined(__BIG_ENDIAN__)
      if ((src[0] >= 0xD8) && (src[0] < 0xE0))
      {
        WARNING(STR("Cannot convert Unicode character into the wide one (character code is %hU).") COMMA (Tuint)((Tcwstr)src[0]));
        return false;
      }
      wc = (src[0] << 8) + src[1];
      #else
      if ((src[1] >= 0xD8) && (src[1] < 0xE0))
      {
        WARNING(STR("Cannot convert Unicode character into the wide one (character code is %hU).") COMMA (Tuint)((Tcwstr)src[0]));
        return false;
      }
      wc = src[0] + (src[1] << 8);
      #endif
    #elif (defined(__WCHAR_S_UCS4__) || defined(__WCHAR_U_UCS4__))
      #if defined(__BIG_ENDIAN__)
      wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
      #else
      wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
      #endif
    #else
      #error "System Unicode size is not supported!"
    #endif

    // Write UTF character.
    switch (m_UTFType)
    {
      case e_UTF8:
      {
        if (!writeUTF8(a_rWriter, wc))
          return result;
        break;
      }
      case e_UTF16BE:
      {
        if (!writeUTF16(a_rWriter, wc, true))
          return result;
        break;
      }
      case e_UTF16LE:
      {
        if (!writeUTF16(a_rWriter, wc, false))
          return result;
        break;
      }
      case e_UTF32BE:
      {
        if (!writeUTF32(a_rWriter, wc, true))
          return result;
        break;
      }
      case e_UTF32LE:
      {
        if (!writeUTF32(a_rWriter, wc, true))
          return result;
        break;
      }
      case e_AUTODETECT:
      default:
      {
        WARNING(STR("UTF type of the current filter is unknown."));
        return result;
      }
    }

    // Take next character.
    src += sizeof(Twchar);
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
/*!
    \def READ_BYTE
    Read next byte from cache or reader.
*/
#define READ_BYTE(character)                                                 \
{                                                                            \
  if (m_CacheSize > 0)                                                       \
  {                                                                          \
    character = (Tbyte)m_Cache[0];                                           \
    for (Tuint i = 1; i < m_CacheSize; ++i)                                  \
      m_Cache[i - 1] = m_Cache[i];                                           \
    --m_CacheSize;                                                           \
  }                                                                          \
  else                                                                       \
  {                                                                          \
    Tschar temp;                                                             \
    if (a_rReader.readBuffer(&temp, 1) != 1)                                 \
      return false;                                                          \
    else                                                                     \
      character = (Tbyte)temp;                                               \
  }                                                                          \
}
/*--------------------------------------------------------------------------*/
/*!
    \def WRITE_BYTE
    Write next byte into writer.
*/
#define WRITE_BYTE(character)                                                \
{                                                                            \
  Tschar temp = (Tschar)character;                                           \
  if (a_rWriter.writeBuffer(&temp, 1) != 1)                                  \
    return false;                                                            \
}
/*--------------------------------------------------------------------------*/
Tbool CFilterUTF::readUTF8(IReader& a_rReader, Tuint& a_rResult)
{ CALL
  Tbyte c[6];

  READ_BYTE(c[0]);
  if (c[0] < 0x80)
  {
    a_rResult = c[0];
  }
  else if (c[0] < 0xC2)
  {
    WARNING(STR("The next read character is not a valid UTF-8 one."));
    return false;
  }
  else if (c[0] < 0xE0)
  {
    READ_BYTE(c[1]);
    if (!((c[1] ^ 0x80) < 0x40))
    {
      WARNING(STR("The next read character is not a valid UTF-8 one."));
      return false;
    }
    a_rResult = ((c[0] & 0x1F) << 6) | (c[1] ^ 0x80);
  }
  else if (c[0] < 0xF0)
  {
    READ_BYTE(c[1]);
    READ_BYTE(c[2]);
    if (!(((c[1] ^ 0x80) < 0x40) && ((c[2] ^ 0x80) < 0x40) && ((c[0] >= 0xE1) || (c[1] >= 0xA0))))
    {
      WARNING(STR("The next read character is not a valid UTF-8 one."));
      return false;
    }
    a_rResult = ((c[0] & 0x0F) << 12) | ((c[1] ^ 0x80) << 6) | (c[2] ^ 0x80);
  }
  else if (c[0] < 0xF8)
  {
    READ_BYTE(c[1]);
    READ_BYTE(c[2]);
    READ_BYTE(c[3]);
    if (!(((c[1] ^ 0x80) < 0x40) && ((c[2] ^ 0x80) < 0x40) && ((c[3] ^ 0x80) < 0x40) && ((c[0] >= 0xF1) || (c[1] >= 0x90))))
    {
      WARNING(STR("The next read character is not a valid UTF-8 one."));
      return false;
    }
    a_rResult = ((c[0] & 0x07) << 18) | ((c[1] ^ 0x80) << 12) | ((c[2] ^ 0x80) << 6) | (c[3] ^ 0x80);
  }
  else if (c[0] < 0xFC)
  {
    READ_BYTE(c[1]);
    READ_BYTE(c[2]);
    READ_BYTE(c[3]);
    READ_BYTE(c[4]);
    if (!(((c[1] ^ 0x80) < 0x40) && ((c[2] ^ 0x80) < 0x40) && ((c[3] ^ 0x80) < 0x40) && ((c[4] ^ 0x80) < 0x40) && ((c[0] >= 0xF9) || (c[1] >= 0x88))))
    {
      WARNING(STR("The next read character is not a valid UTF-8 one."));
      return false;
    }
    a_rResult = ((c[0] & 0x03) << 24) | ((c[1] ^ 0x80) << 18) | ((c[2] ^ 0x80) << 12) | ((c[3] ^ 0x80) << 6) | (c[4] ^ 0x80);
  }
  else if (c[0] < 0xFE)
  {
    READ_BYTE(c[1]);
    READ_BYTE(c[2]);
    READ_BYTE(c[3]);
    READ_BYTE(c[4]);
    READ_BYTE(c[5]);
    if (!(((c[1] ^ 0x80) < 0x40) && ((c[2] ^ 0x80) < 0x40) && ((c[3] ^ 0x80) < 0x40) && ((c[4] ^ 0x80) < 0x40) && ((c[5] ^ 0x80) < 0x40) && ((c[0] >= 0xFD) || (c[1] >= 0x84))))
    {
      WARNING(STR("The next read character is not a valid UTF-8 one."));
      return false;
    }
    a_rResult = ((c[0] & 0x01) << 30) | ((c[1] ^ 0x80) << 24) | ((c[2] ^ 0x80) << 18) | ((c[3] ^ 0x80) << 12) | ((c[4] ^ 0x80) << 6) | (c[5] ^ 0x80);
  }
  else
  {
    WARNING(STR("The next read character is not a valid UTF-8 one."));
    return false;
  }

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterUTF::readUTF16(IReader& a_rReader, Tuint& a_rResult, const Tbool a_cBigEndian)
{ CALL
  Tbyte c[4];

  READ_BYTE(c[0]);
  READ_BYTE(c[1]);
  if (a_cBigEndian)
    a_rResult = (c[0] << 8) + c[1];
  else
    a_rResult = c[0] + (c[1] << 8);
  if ((a_rResult >= 0xD800) && (a_rResult < 0xDC00))
  {
    READ_BYTE(c[2]);
    READ_BYTE(c[3]);
    Tuint wc_temp = (a_cBigEndian) ? ((c[2] << 8) + c[3]) : (c[2] + (c[3] << 8));
    if (!((wc_temp >= 0xDC00) && (wc_temp < 0xE000)))
    {
      WARNING(STR("The next read character is not a valid UTF-16 one."));
      return false;
    }
    a_rResult = 0x10000 + ((a_rResult - 0xD800) << 10) + (wc_temp - 0xDC00);
  }
  else if ((a_rResult >= 0xDC00) && (a_rResult < 0xE000))
  {
    WARNING(STR("The next read character is not a valid UTF-16 one."));
    return false;
  }

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterUTF::readUTF32(IReader& a_rReader, Tuint& a_rResult, const Tbool a_cBigEndian)
{ CALL
  Tbyte c[4];

  READ_BYTE(c[0]);
  READ_BYTE(c[1]);
  READ_BYTE(c[2]);
  READ_BYTE(c[3]);
  if (a_cBigEndian)
    a_rResult = (c[0] << 24) + (c[1] << 16) + (c[2] << 8) + c[3];
  else
    a_rResult = c[0] + (c[1] << 8) + (c[2] << 16) + (c[3] << 24);
  if ((a_rResult < 0x110000) && !((a_rResult >= 0xD800) && (a_rResult < 0xE000)))
    return true;
  else
  {
    WARNING(STR("The next read character is not a valid UTF-32 one."));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CFilterUTF::writeUTF8(IWriter& a_rWriter, const Tuint a_cCharacter)
{ CALL
  Tbyte dst[6];
  Tuint inc_dst = 0;
  Tuint wc = a_cCharacter;

  if (wc < 0x80)
    inc_dst = 1;
  else if (wc < 0x800)
    inc_dst = 2;
  else if (wc < 0x10000)
    inc_dst = 3;
  else if (wc < 0x200000)
    inc_dst = 4;
  else if (wc < 0x4000000)
    inc_dst = 5;
  else if (wc <= 0x7FFFFFFF)
    inc_dst = 6;
  else
  {
    WARNING(STR("The next write character is not a valid UTF-8 one."));
    return false;
  }

  switch (inc_dst)
  {
    case 6: dst[5] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x4000000;
    case 5: dst[4] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x200000;
    case 4: dst[3] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x10000;
    case 3: dst[2] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x800;
    case 2: dst[1] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0xC0;
    case 1: dst[0] = (Tbyte)(wc);
  }

  for (Tuint i = 0; i < inc_dst; ++i)
    WRITE_BYTE(dst[i]);

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterUTF::writeUTF16(IWriter& a_rWriter, const Tuint a_cCharacter, const Tbool a_cBigEndian)
{ CALL
  Tbyte dst[4];
  Tuint inc_dst = 0;
  Tuint wc = a_cCharacter;

  if (!((wc >= 0xD800) && (wc < 0xE000)))
  {
    if (wc < 0x10000)
    {
      if (a_cBigEndian)
      {
        dst[0] = (Tbyte)(wc >> 8);
        dst[1] = (Tbyte)(wc);
      }
      else
      {
        dst[0] = (Tbyte)(wc);
        dst[1] = (Tbyte)(wc >> 8);
      }
      inc_dst = 2;
    }
    else if (wc < 0x110000)
    {
      Tuint wc1 = 0xD800 + ((wc - 0x10000) >> 10);
      Tuint wc2 = 0xDC00 + ((wc - 0x10000) & 0X3FF);
      if (a_cBigEndian)
      {
        dst[0] = (Tbyte)(wc1 >> 8);
        dst[1] = (Tbyte)(wc1);
        dst[2] = (Tbyte)(wc2 >> 8);
        dst[3] = (Tbyte)(wc2);
      }
      else
      {
        dst[0] = (Tbyte)(wc1);
        dst[1] = (Tbyte)(wc1 >> 8);
        dst[2] = (Tbyte)(wc2);
        dst[3] = (Tbyte)(wc2 >> 8);
      }
      inc_dst = 4;
    }
  }
  else
  {
    WARNING(STR("The next write character is not a valid UTF-16 one."));
    return false;
  }

  for (Tuint i = 0; i < inc_dst; ++i)
    WRITE_BYTE(dst[i]);

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterUTF::writeUTF32(IWriter& a_rWriter, const Tuint a_cCharacter, const Tbool a_cBigEndian)
{ CALL
  Tbyte dst[4];
  Tuint inc_dst = 4;
  Tuint wc = a_cCharacter;

  // Convert into the destination buffer.
  if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
  {
    if (a_cBigEndian)
    {
      dst[0] = 0;
      dst[1] = (Tbyte)(wc >> 16);
      dst[2] = (Tbyte)(wc >> 8);
      dst[3] = (Tbyte)(wc);
    }
    else
    {
      dst[0] = (Tbyte)(wc);
      dst[1] = (Tbyte)(wc >> 8);
      dst[2] = (Tbyte)(wc >> 16);
      dst[3] = 0;
    }
  }
  else
  {
    WARNING(STR("The next write character is not a valid UTF-32 one."));
    return false;
  }

  for (Tuint i = 0; i < inc_dst; ++i)
    WRITE_BYTE(dst[i]);

  return true;
}
/*--------------------------------------------------------------------------*/
#undef READ_BYTE
#undef WRITE_BYTE
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
