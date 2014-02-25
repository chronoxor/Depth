/*!
 *  \file    CFilterURL.cpp URL string filter class converts given ASCII
 *           and Unicode strings into the corresponding URL encoded
 *           representation.
 *  \brief   URL string filter class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: URL string filter class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   12.11.2009 21:54:12

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
#include <Depth/include/memory/CMemory.hpp>
#include <Depth/include/stream/text/CFilterURL.hpp>
#include <Depth/include/stream/text/CFilterUTF8.hpp>
#include <Depth/include/string/details/CSystemStringHelper.hpp>
/*==========================================================================*/
#ifndef __CFILTERURL_CPP__
#define __CFILTERURL_CPP__
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
BASE_API Tbool CFilterURL::m_sIsInitialized = false;
BASE_API Tbyte CFilterURL::m_sEncodeTable[256];
BASE_API Tbyte CFilterURL::m_sDecodeTable[256];
BASE_API Tbyte CFilterURL::m_sHexTable1[256];
BASE_API Tbyte CFilterURL::m_sHexTable2[256];
/*--------------------------------------------------------------------------*/
Tbool CFilterURL::set(const CFilterURL& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CFilterURL class instance."))
  {
    return false;
  }

  // Initialize base filter class.
  return IFilter::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterURL::onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  Tuint result = 0;
  Tuint count = a_cSize;
  Tbuffer dst = (Tbuffer)a_pBuffer;

  while (count-- > 0)
  {
    Tschar d;

    // Read encoded binary stream.
    if (!a_rReader.read(d).getFirst())
      return result;

    // Check encoded binary stream.
    if (d == ASC('%'))
    {
      Tschar d1;
      Tschar d2;

      // Read encoded binary stream.
      if (!a_rReader.read(d1).getFirst())
        return result;
      if (!a_rReader.read(d2).getFirst())
        return result;

      Tuint b = (m_sDecodeTable[(Tuint)d1] << 4) | m_sDecodeTable[(Tuint)d2];
      if (b >=256)
      {
        WARNING(STR("URL encoded binary stream contains invalid characters pair - %s%s%s.") COMMA ASC('%') COMMA d1 COMMA d2);
        return result;
      }

      *dst = (Tbyte)b;
    }
    else
    {
      *dst = (Tbyte)d;
    }

    // Take next byte.
    dst += sizeof(Tbyte);
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterURL::onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  Tuint result = 0;
  Tuint count = a_cSize;
  Tsstr dst = a_pBuffer;

  CFilterUTF8 utf8_filter;

  while (count-- > 0)
  {
    Tschar d;

    // Read encoded binary stream.
    if (utf8_filter.onFilterReadText(a_rReader, &d, 1) != 1)
      return result;

    // Check encoded binary stream.
    if (d == ASC('%'))
    {
      Tschar d1;
      Tschar d2;

      // Read encoded binary stream.
      if (utf8_filter.onFilterReadText(a_rReader, &d1, 1) != 1)
        return result;
      if (utf8_filter.onFilterReadText(a_rReader, &d2, 1) != 1)
        return result;

      Tuint b = (m_sDecodeTable[(Tuint)d1] << 4) | m_sDecodeTable[(Tuint)d2];
      if (b >=256)
      {
        WARNING(STR("URL encoded binary stream contains invalid characters pair - %s%s%s.") COMMA ASC('%') COMMA d1 COMMA d2);
        return result;
      }

      *dst = (Tschar)b;
    }
    else
    {
      *dst = d;
    }

    // Take next character.
    ++dst;
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterURL::onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  Tuint result = 0;
  Tuint count = a_cSize;
  Twstr dst = a_pBuffer;

  CFilterUTF8 utf8_filter;

  while (count-- > 0)
  {
    Twchar d;

    // Read encoded binary stream.
    if (utf8_filter.onFilterReadText(a_rReader, &d, 1) != 1)
      return result;

    // Check encoded binary stream.
    if (d == UNC('%'))
    {
      Twchar d1;
      Twchar d2;

      // Read encoded binary stream.
      if (utf8_filter.onFilterReadText(a_rReader, &d1, 1) != 1)
        return result;
      if (utf8_filter.onFilterReadText(a_rReader, &d2, 1) != 1)
        return result;

      Tuint b = (m_sDecodeTable[d1] << 4) | m_sDecodeTable[d2];
      if (b >=256)
      {
        WARNING(STR("URL encoded binary stream contains invalid characters pair - %s%s%s.") COMMA ASC('%') COMMA d1 COMMA d2);
        return result;
      }

      *dst = (Twchar)b;
    }
    else
    {
      *dst = d;
    }

    // Take next character.
    ++dst;
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterURL::onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  Tuint result = 0;
  Tuint count = a_cSize;
  Tcbuffer src = (Tcbuffer)a_cpBuffer;

  while (count-- > 0)
  {
    Tbyte b = src[0];

    // Encode binary stream.
    Tbyte e = CFilterURL::m_sEncodeTable[b];
    if (e)
    {
      Tschar c = (Tschar)e;
      if (!a_rWriter.write(c).getFirst())
        return result;
    }
    else
    {
      Tschar c1 = (Tschar)CFilterURL::m_sHexTable1[b];
      Tschar c2 = (Tschar)CFilterURL::m_sHexTable2[b];
      if (!a_rWriter.write(ASC('%')).getFirst())
        return result;
      if (!a_rWriter.write(c1).getFirst())
        return result;
      if (!a_rWriter.write(c2).getFirst())
        return result;
    }

    // Take next byte.
    src += sizeof(Tbyte);
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterURL::onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  Tuint count = 0;
  Tuint size = 0;

  // Get count of ASCII string characters.
  if (!NString::NDetails::CSystemStringHelper::getASCIICharsCount(a_cpBuffer, a_cSize * sizeof(Tschar), count))
  {
    WARNING(STR("Cannot get count of ASCII characters in the current ASCII string buffer. Content of the ASCII string buffer has to be checked."));
    return 0;
  }

  // Get size of same string in UTF-8 encoding in bytes.
  if (!NString::NDetails::CSystemStringHelper::ASCIIToUTF8Count(a_cpBuffer, count, size))
  {
    WARNING(STR("Cannot get required buffer size to convert string buffer from ASCII encoding to UTF-8 one. Content of the ASCII string buffer has to be checked."));
    return 0;
  }

  // Save the ASCII buffer content.
  if (size > 0)
  {
    // Allocate required buffer.
    Tbuffer buffer = newex Tbyte[size];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate UTF-8 string buffer for saving ASCII string buffer (requested size is %u bytes).") COMMA size);
      return 0;
    }

    // Convert ASCII string in UTF-8 encoding.
    if (!NString::NDetails::CSystemStringHelper::ASCIIToUTF8(buffer, a_cpBuffer, count, size))
    {
      delete [] buffer;
      WARNING(STR("Cannot convert string from ASCII encoding to UTF-8 one. Content of the ASCII string buffer has to be checked."));
      return 0;
    }

    // Write ASCII string content in UTF-8 encoding.
    Tuint result = onFilterWriteBinary(a_rWriter, (Tcptr)buffer, size);
    if (!NString::NDetails::CSystemStringHelper::UTF8ToASCIICount(buffer, result, count))
    {
      WARNING(STR("Cannot get converted UTF-8 string buffer size. Content of the UTF-8 string buffer has to be checked."));
      return 0;
    }

    // Delete temporary buffer.
    delete [] buffer;

    return count / sizeof(Tschar);
  }
  return 0;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterURL::onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  Tuint count = 0;
  Tuint size = 0;

  // Get count of Unicode string characters.
  if (!NString::NDetails::CSystemStringHelper::getUnicodeCharsCount(a_cpBuffer, a_cSize * sizeof(Twchar), count))
  {
    WARNING(STR("Cannot get count of Unicode characters in the current Unicode string buffer. Content of the Unicode string buffer has to be checked."));
    return 0;
  }

  // Get size of same string in UTF-8 encoding in bytes.
  if (!NString::NDetails::CSystemStringHelper::UnicodeToUTF8Count(a_cpBuffer, count, size))
  {
    WARNING(STR("Cannot get required buffer size to convert string buffer from Unicode encoding to UTF-8 one. Content of the Unicode string buffer has to be checked."));
    return 0;
  }

  // Save the Unicode buffer content.
  if (size > 0)
  {
    // Allocate required buffer.
    Tbuffer buffer = newex Tbyte[size];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate UTF-8 string buffer for saving Unicode string buffer (requested size is %u bytes).") COMMA size);
      return 0;
    }

    // Convert Unicode string in UTF-8 encoding.
    if (!NString::NDetails::CSystemStringHelper::UnicodeToUTF8(buffer, a_cpBuffer, count, size))
    {
      delete [] buffer;
      WARNING(STR("Cannot convert string from Unicode encoding to UTF-8 one. Content of the Unicode string buffer has to be checked."));
      return 0;
    }

    // Write Unicode string content in UTF-8 encoding.
    Tuint result = onFilterWriteBinary(a_rWriter, (Tptr)buffer, size);
    if (!NString::NDetails::CSystemStringHelper::UTF8ToUnicodeCount(buffer, result, count))
    {
      WARNING(STR("Cannot get converted UTF-8 string buffer size. Content of the UTF-8 string buffer has to be checked."));
      return 0;
    }

    // Delete temporary buffer.
    delete [] buffer;

    return count / sizeof(Twchar);
  }
  return 0;
}
/*--------------------------------------------------------------------------*/
void CFilterURL::calculateTables()
{ CALL
  if (!m_sIsInitialized)
  {
    // Calculate encode table.
    NMemory::CMemory::zero(m_sEncodeTable, 256);
    // Digits.
    for (Tuint i = ASC('0'); i <= ASC('9'); ++i)
      m_sEncodeTable[i] = (Tbyte)i;
    // Uppercase letters.
    for (Tuint i = ASC('A'); i <= ASC('Z'); ++i)
      m_sEncodeTable[i] = (Tbyte)i;
    // Lowercase letters.
    for (Tuint i = ASC('a'); i <= ASC('z'); ++i)
      m_sEncodeTable[i] = (Tbyte)i;
    // Unreserved characters.
    m_sEncodeTable[ASC('-')] = (Tbyte)ASC('-');
    m_sEncodeTable[ASC('_')] = (Tbyte)ASC('_');
    m_sEncodeTable[ASC('.')] = (Tbyte)ASC('.');
    m_sEncodeTable[ASC('~')] = (Tbyte)ASC('~');
    // Reserved characters.
    m_sEncodeTable[ASC(':')]  = (Tbyte)ASC(':');
    m_sEncodeTable[ASC('/')]  = (Tbyte)ASC('/');
    m_sEncodeTable[ASC('?')]  = (Tbyte)ASC('?');
    m_sEncodeTable[ASC('#')]  = (Tbyte)ASC('#');
    m_sEncodeTable[ASC('[')]  = (Tbyte)ASC('[');
    m_sEncodeTable[ASC(']')]  = (Tbyte)ASC(']');
    m_sEncodeTable[ASC('@')]  = (Tbyte)ASC('@');
    m_sEncodeTable[ASC('!')]  = (Tbyte)ASC('!');
    m_sEncodeTable[ASC('$')]  = (Tbyte)ASC('$');
    m_sEncodeTable[ASC('&')]  = (Tbyte)ASC('&');
    m_sEncodeTable[ASC('\'')] = (Tbyte)ASC('\'');
    m_sEncodeTable[ASC('(')]  = (Tbyte)ASC('(');
    m_sEncodeTable[ASC(')')]  = (Tbyte)ASC(')');
    m_sEncodeTable[ASC('*')]  = (Tbyte)ASC('*');
    m_sEncodeTable[ASC('+')]  = (Tbyte)ASC('+');
    m_sEncodeTable[ASC(',')]  = (Tbyte)ASC(',');
    m_sEncodeTable[ASC(';')]  = (Tbyte)ASC(';');
    m_sEncodeTable[ASC('=')]  = (Tbyte)ASC('=');

    // Calculate decode table.
    NMemory::CMemory::fill(m_sDecodeTable, 256, 0xFF);
    // Digits.
    for (Tuint i = ASC('0'); i <= ASC('9'); ++i)
      m_sDecodeTable[i] = (Tbyte)(i - ASC('0'));
    // Uppercase letters.
    for (Tuint i = ASC('A'); i <= ASC('F'); ++i)
      m_sDecodeTable[i] = (Tbyte)(i - ASC('A') + 10);
    // Lowercase letters.
    for (Tuint i = ASC('a'); i <= ASC('z'); ++i)
      m_sDecodeTable[i] = (Tbyte)(i - ASC('a') + 10);

    // Calculate hex codes tables.
    static const Tschar hex_characters[] = ASC("0123456789ABCDEF");
    for (Tuint i = 0; i < 256; ++i)
    {
      m_sHexTable1[i] = hex_characters[i >> 4];
      m_sHexTable2[i] = hex_characters[i & 0x0F];
    }

    // Set the initialization flag.
    m_sIsInitialized = true;
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
