/*!
 *  \file    CFilterBase64.cpp Base64 string filter class converts given ASCII
 *           and Unicode strings into the corresponding hexadecimal
 *           representation.
 *  \brief   Base64 string filter class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base64 string filter class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   16.11.2009 02:50:23

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
#include <Depth/include/stream/text/CFilterBase64.hpp>
/*==========================================================================*/
#ifndef __CFILTERBASE64_CPP__
#define __CFILTERBASE64_CPP__
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
BASE_API Tbool CFilterBase64::m_sIsInitialized = false;
BASE_API Tbyte CFilterBase64::m_sEncodeTable[64] =
{
  Tbyte('A'), Tbyte('B'), Tbyte('C'), Tbyte('D'),
  Tbyte('E'), Tbyte('F'), Tbyte('G'), Tbyte('H'),
  Tbyte('I'), Tbyte('J'), Tbyte('K'), Tbyte('L'),
  Tbyte('M'), Tbyte('N'), Tbyte('O'), Tbyte('P'),
  Tbyte('Q'), Tbyte('R'), Tbyte('S'), Tbyte('T'),
  Tbyte('U'), Tbyte('V'), Tbyte('W'), Tbyte('X'),
  Tbyte('Y'), Tbyte('Z'), Tbyte('a'), Tbyte('b'),
  Tbyte('c'), Tbyte('d'), Tbyte('e'), Tbyte('f'),
  Tbyte('g'), Tbyte('h'), Tbyte('i'), Tbyte('j'),
  Tbyte('k'), Tbyte('l'), Tbyte('m'), Tbyte('n'),
  Tbyte('o'), Tbyte('p'), Tbyte('q'), Tbyte('r'),
  Tbyte('s'), Tbyte('t'), Tbyte('u'), Tbyte('v'),
  Tbyte('w'), Tbyte('x'), Tbyte('y'), Tbyte('z'),
  Tbyte('0'), Tbyte('1'), Tbyte('2'), Tbyte('3'),
  Tbyte('4'), Tbyte('5'), Tbyte('6'), Tbyte('7'),
  Tbyte('8'), Tbyte('9'), Tbyte('+'), Tbyte('/')
};
BASE_API Tbyte CFilterBase64::m_sDecodeTable[256];
/*--------------------------------------------------------------------------*/
Tbool CFilterBase64::set(const CFilterBase64& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CFilterBase64 class instance."))
  {
    return false;
  }

  // Initialize base filter class.
  return NPack::IFilterFramePack<3>::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBase64::onOpenReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  IGNORE_UNUSED(a_rReader);
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_rCurrentSize);
  IGNORE_UNUSED(a_cFullSize);

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBase64::onOpenWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  IGNORE_UNUSED(a_rWriter);
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_rCurrentSize);
  IGNORE_UNUSED(a_cFullSize);

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBase64::onPackReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  IGNORE_UNUSED(a_cFullSize);

  // Check if the Base64 cache frame is empty.
  ASSERT((a_rCurrentSize == 0), STR("Base64 cache frame should be empty (count = %u).") COMMA a_rCurrentSize)
  {
    return false;
  }

  Tbuffer dst = (Tbuffer)(a_pBuffer + a_rCurrentSize);

  // Handle new line symbols.
  Tbool cache = false;
  Tschar cache_character = 0;
  while (!cache)
  {
    // Read cache character form the given reader.
    if (!a_rReader.read(cache_character).getFirst())
      return true;

    // Check for new line symbols.
    if ((cache_character == ASC('\r')) || (cache_character == ASC('\n')))
      continue;
    else
    {
      cache = true;
      break;
    }
  }

  // Read Base64 encoded characters form the given reader.
  Tschar c1 = cache_character, c2 = 0, c3 = 0, c4 = 0;
  Tbool read1 = cache || a_rReader.read(c1).getFirst();
  Tbool read2 = (read1 && a_rReader.read(c2).getFirst());
  Tbool read3 = (read2 && a_rReader.read(c3).getFirst());
  Tbool read4 = (read3 && a_rReader.read(c4).getFirst());
  if (!read1 && !read2 && !read3 && !read4)
    return true;
  else if (!read1 || !read2 || !read3 || !read4)
  {
    WARNING(STR("Base64 encoded stream has incorrect format."));
    return false;
  }
  cache = false;

  // Calculate count of read bytes.
  a_rCurrentSize = 3;
  if (c3 == ASC('='))
    --a_rCurrentSize;
  if (c4 == ASC('='))
    --a_rCurrentSize;

  // Unpack Base64 encoded characters.
  Tbyte e1 = m_sDecodeTable[(Tuint)c1];
  Tbyte e2 = m_sDecodeTable[(Tuint)c2];
  Tbyte e3 = m_sDecodeTable[(Tuint)c3];
  Tbyte e4 = m_sDecodeTable[(Tuint)c4];
  if ((e1 == (Tbyte)0xFF) || (e2 == (Tbyte)0xFF) || ((a_rCurrentSize > 1) && (e3 == (Tbyte)0xFF)) || ((a_rCurrentSize > 2) && (e4 == (Tbyte)0xFF)))
  {
    WARNING(STR("Base64 encoded binary stream contains invalid characters (%hU, %hU, %hU, %hU).") COMMA (Tuint)e1 COMMA (Tuint)e2 COMMA (Tuint)e3 COMMA (Tuint)e4);
    return false;
  }

  Tbyte b1 = (e1 << 2) | (e2 >> 4);
  Tbyte b2 = (e2 << 4) | (e3 >> 2);
  Tbyte b3 = (e3 << 6) | e4;

  // Store characters into the read buffer.
  if (a_rCurrentSize > 0)
    *dst++ = b1;
  if (a_rCurrentSize > 1)
    *dst++ = b2;
  if (a_rCurrentSize > 2)
    *dst++ = b3;

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBase64::onPackWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  IGNORE_UNUSED(a_cFullSize);

  // If nothing to write.
  if (a_rCurrentSize == 0)
    return true;

  // Check if the count of Base64 packing bytes is less or equal to 3.
  ASSERT((a_rCurrentSize <= 3), STR("Count of Base64 packing bytes should be less or equal to 3 (count = %u).") COMMA a_rCurrentSize)
  {
    return false;
  }

  Tbyte b1 = a_pBuffer[0];
  Tbyte b2 = (a_rCurrentSize > 1) ? a_pBuffer[1] : 0;
  Tbyte b3 = (a_rCurrentSize > 2) ? a_pBuffer[2] : 0;

  // Encode Base64 characters.
  Tschar c1 = m_sEncodeTable[b1 >> 2];
  Tschar c2 = m_sEncodeTable[((b1 << 4) & 0x30) | (b2 >> 4)];
  Tschar c3 = (a_rCurrentSize > 1) ? m_sEncodeTable[((b2 << 2) & 0x3C) | (b3 >> 6)] : ASC('=');
  Tschar c4 = (a_rCurrentSize > 2) ? m_sEncodeTable[b3 & 0x3F] : ASC('=');

  // Write Base64 characters.
  if (!a_rWriter.write(c1).getFirst() || !a_rWriter.write(c2).getFirst() || !a_rWriter.write(c3).getFirst() || !a_rWriter.write(c4).getFirst())
  {
    WARNING(STR("Cannot write Base64 encoded characters into the stream."));
    return false;
  }

  // Update write frame buffer.
  a_rCurrentSize = 0;

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBase64::onCloseReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  IGNORE_UNUSED(a_rReader);
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_rCurrentSize);
  IGNORE_UNUSED(a_cFullSize);

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBase64::onCloseWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  return onPackWriteFrame(a_rWriter, a_pBuffer, a_rCurrentSize, a_cFullSize);
}
/*--------------------------------------------------------------------------*/
void CFilterBase64::calculateTables()
{ CALL
  if (!m_sIsInitialized)
  {
    // Calculate decode table.
    NMemory::CMemory::fill(m_sDecodeTable, 256, 0xFF);
    for (Tuint i = 0; i < 64; ++i)
      m_sDecodeTable[m_sEncodeTable[i]] = (Tbyte)i;

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
