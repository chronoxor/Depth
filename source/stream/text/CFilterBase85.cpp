/*!
 *  \file    CFilterBase85.cpp Base85 string filter class converts given ASCII
 *           and Unicode strings into the corresponding hexadecimal
 *           representation.
 *  \brief   Base85 string filter class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base85 string filter class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   16.11.2009 20:42:08

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
#include <Depth/include/stream/text/CFilterBase85.hpp>
#include <Depth/include/utility/CUtility.hpp>
/*==========================================================================*/
#ifndef __CFILTERBASE85_CPP__
#define __CFILTERBASE85_CPP__
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
BASE_API Tbool CFilterBase85::m_sIsInitialized = false;
BASE_API Tbyte CFilterBase85::m_sEncodeTable[85];
BASE_API Tuint32 CFilterBase85::m_sDecodeTable[256];
/*--------------------------------------------------------------------------*/
Tbool CFilterBase85::set(const CFilterBase85& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CFilterBase85 class instance."))
  {
    return false;
  }

  // Initialize base filter class.
  if (!NPack::IFilterFramePack<4>::set(a_crInstance))
    return false;

  // Initialize Base85 filter properties.
  m_IsWriteSuffixes = a_crInstance.m_IsWriteSuffixes;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBase85::onOpenReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  return internalPackReadFrame(true, a_rReader, a_pBuffer, a_rCurrentSize, a_cFullSize);
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBase85::onOpenWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_rCurrentSize);
  IGNORE_UNUSED(a_cFullSize);

  // Write Base85 prefix if necessary.
  if (m_IsWriteSuffixes)
  {
    if (!a_rWriter.write(ASC('<')).getFirst() || !a_rWriter.write(ASC('~')).getFirst())
    {
      WARNING(STR("Cannot write Base85 start prefix into the stream."));
      return false;
    }
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBase85::onPackReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  return internalPackReadFrame(false, a_rReader, a_pBuffer, a_rCurrentSize, a_cFullSize);
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBase85::onPackWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  IGNORE_UNUSED(a_cFullSize);

  // If nothing to write.
  if (a_rCurrentSize == 0)
    return true;

  // Check if the count of Base85 packing bytes is less or equal to 4.
  ASSERT((a_rCurrentSize <= 4), STR("Count of Base85 packing bytes should be less or equal to 4 (count = %u).") COMMA a_rCurrentSize)
  {
    return false;
  }

  Tbyte b1 = a_pBuffer[0];
  Tbyte b2 = (a_rCurrentSize > 1) ? a_pBuffer[1] : 0;
  Tbyte b3 = (a_rCurrentSize > 2) ? a_pBuffer[2] : 0;
  Tbyte b4 = (a_rCurrentSize > 3) ? a_pBuffer[3] : 0;

  // Perform a special checks for the Base85 encoding.
  Tuint32 e = NUtility::CUtility::makeInteger(b1, b2, b3, b4);
  if (a_rCurrentSize == 4)
  {
    if (e == 0x00000000)
    {
      if (!a_rWriter.write(ASC('z')).getFirst())
      {
        WARNING(STR("Cannot write Base85 encoded characters into the stream."));
        return false;
      }

      // Update write frame buffer.
      a_rCurrentSize = 0;

      return true;
    }
    else if (e == 0x20202020)
    {
      if (!a_rWriter.write(ASC('y')).getFirst())
      {
        WARNING(STR("Cannot write Base85 encoded characters into the stream."));
        return false;
      }

      // Update write frame buffer.
      a_rCurrentSize = 0;

      return true;
    }
  }

  // Encode Base85 characters.
  Tschar c[5];
  c[4] = m_sEncodeTable[e % 85]; e /= 85;
  c[3] = m_sEncodeTable[e % 85]; e /= 85;
  c[2] = m_sEncodeTable[e % 85]; e /= 85;
  c[1] = m_sEncodeTable[e % 85]; e /= 85;
  c[0] = m_sEncodeTable[e];

  // Write Base85 characters.
  for (Tuint i = 0; i < (a_rCurrentSize + 1); ++i)
  {
    if (!a_rWriter.write(c[i]).getFirst())
    {
      WARNING(STR("Cannot write Base85 encoded characters into the stream."));
      return false;
    }
  }

  // Update write frame buffer.
  a_rCurrentSize = 0;

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBase85::onCloseReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  IGNORE_UNUSED(a_rReader);
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_rCurrentSize);
  IGNORE_UNUSED(a_cFullSize);

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBase85::onCloseWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  Tbool result = onPackWriteFrame(a_rWriter, a_pBuffer, a_rCurrentSize, a_cFullSize);

  // Write Base85 suffix if necessary.
  if (result && m_IsWriteSuffixes)
  {
    if (!a_rWriter.write(ASC('~')).getFirst() || !a_rWriter.write(ASC('>')).getFirst())
    {
      WARNING(STR("Cannot write Base85 end suffix into the stream."));
      return false;
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
void CFilterBase85::calculateTables()
{ CALL
  if (!m_sIsInitialized)
  {
    // Calculate encode & decode tables.
    for (Tuint i = 0; i < 256; ++i)
      m_sDecodeTable[i] = 99;

    Tuint count = 0;

    // Available characters are in range from '!' up to '~'.
    for (Tuint i = ASC('!'); ((i <= ASC('~')) && (count < 85)); ++i)
    {
      // Special exceptions may be added here.
      if ((i == ASC('y')) || (i == ASC('z')) || (i == ASC('~')))
        continue;

      m_sEncodeTable[count] = (Tbyte)i;
      m_sDecodeTable[i] = (Tuint32)count;
      ++count;
    }

    // Verify that count of exceptions is equal to 85.
    VERIFY((count == 85), STR("Count of Base85 exceptions should be equal to 85 (count = %u).") COMMA count);

    // Set the initialization flag.
    m_sIsInitialized = true;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBase85::internalPackReadFrame(const Tbool a_cReadHeader, IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  IGNORE_UNUSED(a_cFullSize);

  // Check if the Base85 cache frame is empty.
  ASSERT((a_rCurrentSize == 0), STR("Base85 cache frame should be empty (count = %u).") COMMA a_rCurrentSize)
  {
    return false;
  }

  Tbuffer dst = (Tbuffer)(a_pBuffer + a_rCurrentSize);

  // Handle new line symbols.
  Tbool header = a_cReadHeader;
  Tbool cache = false;
  Tschar cache_character = 0;
  while (!cache)
  {
    // Read cache character form the given reader.
    if (!a_rReader.read(cache_character).getFirst())
      return true;

    // Check for Base85 header.
    if (header && (cache_character == ASC('<')))
    {
      Tschar endc;
      Tbool read = a_rReader.read(endc).getFirst();
      if (!read || (endc != ASC('~')))
      {
        WARNING(STR("Base85 encoded stream has incorrect format. Met '<' special character without '~'."));
        return false;
      }
      header = false;
      continue;
    }

    // Check for new line symbols.
    if ((cache_character == ASC('\r')) || (cache_character == ASC('\n')))
      continue;
    else
    {
      cache = true;
      break;
    }
  }

  // Read Base85 encoded characters form the given reader.
  Tuint count;
  Tuint32 d = 0;
  Tbool end_of_stream = true;
  const Tuint32 pow85[] = { 85 * 85 * 85 * 85, 85 * 85 * 85, 85 * 85, 85, 1};
  for (count = 0; count < 5; ++count)
  {
    Tschar c = cache_character;
    Tbool read = cache || a_rReader.read(c).getFirst();
    if (!read)
      break;
    cache = false;
    end_of_stream = false;

    // Perform special checks.
    if (c == ASC('z'))
    {
      if (count > 0)
      {
        WARNING(STR("Base85 encoded stream has incorrect format. Met 'z' special character inside the block."));
        return false;
      }

      // Store characters into the read buffer.
      a_rCurrentSize = 4;
      *dst++ = 0;
      *dst++ = 0;
      *dst++ = 0;
      *dst++ = 0;

      return true;
    }
    else if (c == ASC('y'))
    {
      if (count > 0)
      {
        WARNING(STR("Base85 encoded stream has incorrect format. Met 'y' special character inside the block."));
        return false;
      }

      // Store characters into the read buffer.
      a_rCurrentSize = 4;
      *dst++ = 0x20;
      *dst++ = 0x20;
      *dst++ = 0x20;
      *dst++ = 0x20;

      return true;
    }
    else if (c == ASC('~'))
    {
      Tschar endc;
      Tbool read = a_rReader.read(endc).getFirst();
      if (!read || (endc != ASC('>')))
      {
        WARNING(STR("Base85 encoded stream has incorrect format. Met '~' special character without '>'."));
        return false;
      }

      end_of_stream = true;
      break;
    }

    Tuint32 digit = m_sDecodeTable[(Tuint)c];
    if (digit >= 85)
    {
      WARNING(STR("Base85 encoded stream has incorrect format. Read digit is out of the 85 base (digit = %u).") COMMA digit);
      return false;
    }

    d += digit * pow85[count];
  }

  if (count > 0)
  {
    if (count == 1)
    {
      WARNING(STR("Base85 encoded stream has incorrect format. The last block of Base85 data cannot be a single byte."));
      return false;
    }
    else if (count < 5)
      d += pow85[--count];
  else
      --count;

    // Unpack value.
    Tbyte e[4];
    e[0] = (d >> 24) & 0xFF;
    e[1] = (d >> 16) & 0xFF;
    e[2] = (d >> 8) & 0xFF;
    e[3] = d & 0xFF;
    a_rCurrentSize = 0;
    for (Tuint i = 0; i < count; ++i)
    {
      ++a_rCurrentSize;
      *dst++ = e[i];
    }
  }

  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
