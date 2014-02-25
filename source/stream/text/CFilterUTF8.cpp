/*!
 *  \file    CFilterUTF8.cpp UTF-8 string filter class converts given ASCII
 *           and Unicode strings into the UTF-8 equivalents.
 *  \brief   UTF-8 string filter class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: UTF-8 string filter class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   02.11.2009 03:37:38

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
#include <Depth/include/stream/text/CFilterUTF8.hpp>
/*==========================================================================*/
#ifndef __CFILTERUTF8_CPP__
#define __CFILTERUTF8_CPP__
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
Tbool CFilterUTF8::set(const CFilterUTF8& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CFilterUTF8 class instance."))
  {
    return false;
  }

  // Initialize base filter class.
  return IFilter::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
/*!
    \def READ_BYTE
    Read next byte from cache or reader.
*/
#define READ_BYTE(character)                                                 \
{                                                                            \
  Tschar temp;                                                               \
  if (a_rReader.readBuffer(&temp, 1) != 1)                                   \
    return result;                                                           \
  else                                                                       \
    character = (Tbyte)temp;                                                 \
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
    return result;                                                           \
}
/*--------------------------------------------------------------------------*/
Tuint CFilterUTF8::onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  return a_rReader.readBuffer(a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterUTF8::onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  Tuint wc;
  Tuint result = 0;
  Tuint count = a_cSize;
  Tbuffer dst = (Tbuffer)a_pBuffer;

  while (count-- > 0)
  {
    // Read UTF-8 character.
    {
      Tbyte c[6];

      READ_BYTE(c[0]);
      if (c[0] < 0x80)
      {
        wc = c[0];
      }
      else if (c[0] < 0xC2)
      {
        WARNING(STR("The next read character is not a valid UTF-8 one."));
        return result;
      }
      else if (c[0] < 0xE0)
      {
        READ_BYTE(c[1]);
        if (!((c[1] ^ 0x80) < 0x40))
        {
          WARNING(STR("The next read character is not a valid UTF-8 one."));
          return result;
        }
        wc = ((c[0] & 0x1F) << 6) | (c[1] ^ 0x80);
      }
      else if (c[0] < 0xF0)
      {
        READ_BYTE(c[1]);
        READ_BYTE(c[2]);
        if (!(((c[1] ^ 0x80) < 0x40) && ((c[2] ^ 0x80) < 0x40) && ((c[0] >= 0xE1) || (c[1] >= 0xA0))))
        {
          WARNING(STR("The next read character is not a valid UTF-8 one."));
          return result;
        }
        wc = ((c[0] & 0x0F) << 12) | ((c[1] ^ 0x80) << 6) | (c[2] ^ 0x80);
      }
      else if (c[0] < 0xF8)
      {
        READ_BYTE(c[1]);
        READ_BYTE(c[2]);
        READ_BYTE(c[3]);
        if (!(((c[1] ^ 0x80) < 0x40) && ((c[2] ^ 0x80) < 0x40) && ((c[3] ^ 0x80) < 0x40) && ((c[0] >= 0xF1) || (c[1] >= 0x90))))
        {
          WARNING(STR("The next read character is not a valid UTF-8 one."));
          return result;
        }
        wc = ((c[0] & 0x07) << 18) | ((c[1] ^ 0x80) << 12) | ((c[2] ^ 0x80) << 6) | (c[3] ^ 0x80);
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
          return result;
        }
        wc = ((c[0] & 0x03) << 24) | ((c[1] ^ 0x80) << 18) | ((c[2] ^ 0x80) << 12) | ((c[3] ^ 0x80) << 6) | (c[4] ^ 0x80);
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
          return result;
        }
        wc = ((c[0] & 0x01) << 30) | ((c[1] ^ 0x80) << 24) | ((c[2] ^ 0x80) << 18) | ((c[3] ^ 0x80) << 12) | ((c[4] ^ 0x80) << 6) | (c[5] ^ 0x80);
      }
      else
      {
        WARNING(STR("The next read character is not a valid UTF-8 one."));
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
Tuint CFilterUTF8::onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  Tuint wc;
  Tuint result = 0;
  Tuint count = a_cSize;
  Tbuffer dst = (Tbuffer)a_pBuffer;

  while (count-- > 0)
  {
    // Read UTF-8 character.
    {
      Tbyte c[6];

      READ_BYTE(c[0]);
      if (c[0] < 0x80)
      {
        wc = c[0];
      }
      else if (c[0] < 0xC2)
      {
        WARNING(STR("The next read character is not a valid UTF-8 one."));
        return result;
      }
      else if (c[0] < 0xE0)
      {
        READ_BYTE(c[1]);
        if (!((c[1] ^ 0x80) < 0x40))
        {
          WARNING(STR("The next read character is not a valid UTF-8 one."));
          return result;
        }
        wc = ((c[0] & 0x1F) << 6) | (c[1] ^ 0x80);
      }
      else if (c[0] < 0xF0)
      {
        READ_BYTE(c[1]);
        READ_BYTE(c[2]);
        if (!(((c[1] ^ 0x80) < 0x40) && ((c[2] ^ 0x80) < 0x40) && ((c[0] >= 0xE1) || (c[1] >= 0xA0))))
        {
          WARNING(STR("The next read character is not a valid UTF-8 one."));
          return result;
        }
        wc = ((c[0] & 0x0F) << 12) | ((c[1] ^ 0x80) << 6) | (c[2] ^ 0x80);
      }
      else if (c[0] < 0xF8)
      {
        READ_BYTE(c[1]);
        READ_BYTE(c[2]);
        READ_BYTE(c[3]);
        if (!(((c[1] ^ 0x80) < 0x40) && ((c[2] ^ 0x80) < 0x40) && ((c[3] ^ 0x80) < 0x40) && ((c[0] >= 0xF1) || (c[1] >= 0x90))))
        {
          WARNING(STR("The next read character is not a valid UTF-8 one."));
          return result;
        }
        wc = ((c[0] & 0x07) << 18) | ((c[1] ^ 0x80) << 12) | ((c[2] ^ 0x80) << 6) | (c[3] ^ 0x80);
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
          return result;
        }
        wc = ((c[0] & 0x03) << 24) | ((c[1] ^ 0x80) << 18) | ((c[2] ^ 0x80) << 12) | ((c[3] ^ 0x80) << 6) | (c[4] ^ 0x80);
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
          return result;
        }
        wc = ((c[0] & 0x01) << 30) | ((c[1] ^ 0x80) << 24) | ((c[2] ^ 0x80) << 18) | ((c[3] ^ 0x80) << 12) | ((c[4] ^ 0x80) << 6) | (c[5] ^ 0x80);
      }
      else
      {
        WARNING(STR("The next read character is not a valid UTF-8 one."));
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
Tuint CFilterUTF8::onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return a_rWriter.writeBuffer(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterUTF8::onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  Tuint wc;
  Tuint result = 0;
  Tuint count = a_cSize;
  Tcbuffer src = (Tcbuffer)a_cpBuffer;

  while (count-- > 0)
  {
    // Convert from the ASCII buffer.
    wc = src[0];

    // Write UTF-8 character.
    {
      Tbyte dst[6];
      Tuint inc_dst = 0;

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
        return result;
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
    }

    // Take next character.
    src += sizeof(Tschar);
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterUTF8::onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize)
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

    // Write UTF-8 character.
    {
      Tbyte dst[6];
      Tuint inc_dst = 0;

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
        return result;
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
    }

    // Take next character.
    src += sizeof(Twchar);
    ++result;
  }
  return result;
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
