/*!
 *  \file    CFilterBase16.cpp Base16 string filter class converts given ASCII
 *           and Unicode strings into the corresponding hexadecimal
 *           representation.
 *  \brief   Base16 string filter class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base16 string filter class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   09.11.2009 20:32:59

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
#include <Depth/include/stream/text/CFilterBase16.hpp>
/*==========================================================================*/
#ifndef __CFILTERBASE16_CPP__
#define __CFILTERBASE16_CPP__
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
BASE_API Tbool CFilterBase16::m_sIsInitialized = false;
BASE_API Tbyte CFilterBase16::m_sEncodeTable[16] =
{
  Tbyte('0'), Tbyte('1'), Tbyte('2'), Tbyte('3'),
  Tbyte('4'), Tbyte('5'), Tbyte('6'), Tbyte('7'),
  Tbyte('8'), Tbyte('9'), Tbyte('A'), Tbyte('B'),
  Tbyte('C'), Tbyte('D'), Tbyte('E'), Tbyte('F')
};
BASE_API Tbyte CFilterBase16::m_sDecodeTable[256];
/*--------------------------------------------------------------------------*/
Tbool CFilterBase16::set(const CFilterBase16& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CFilterBase16 class instance."))
  {
    return false;
  }

  // Initialize base filter class.
  return IFilter::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBase16::onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  Tuint result = 0;
  Tuint count = a_cSize;
  Tbuffer dst = (Tbuffer)a_pBuffer;

  // Handle new line symbols.
  Tbool cache = false;
  Tschar cache_character = 0;
  while (!cache)
  {
    // Read cache character form the given reader.
    if (!a_rReader.read(cache_character).getFirst())
      return result;

    // Check for new line symbols.
    if ((cache_character == ASC('\r')) || (cache_character == ASC('\n')))
      continue;
    else
    {
      cache = true;
      break;
    }
  }

  while (count-- > 0)
  {
    Tschar d1 = cache_character;
    Tschar d2;

    // Read encoded binary stream.
    if (!cache && !a_rReader.read(d1).getFirst())
      return result;
    if (!a_rReader.read(d2).getFirst())
      return result;
    cache = false;

    // Check encoded binary stream.
    Tbyte b1 = m_sDecodeTable[(Tuint)d1];
    Tbyte b2 = m_sDecodeTable[(Tuint)d2];
    if ((b1 == (Tbyte)0xFF) || (b2 == (Tbyte)0xFF))
    {
      WARNING(STR("Base16 encoded binary stream contains invalid characters pair (%hU and %hU).") COMMA (Tuint)b1 COMMA (Tuint)b2);
      return result;
    }

    // Decode binary stream.
    *dst = (b1 << 4) | b2;

    // Take next byte.
    dst += sizeof(Tbyte);
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBase16::onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onFilterReadBinary(a_rReader, (Tptr)a_pBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBase16::onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onFilterReadBinary(a_rReader, (Tptr)a_pBuffer, a_cSize * sizeof(Twchar)) / sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBase16::onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  Tuint result = 0;
  Tuint count = a_cSize;
  Tcbuffer src = (Tcbuffer)a_cpBuffer;

  while (count-- > 0)
  {
    Tbyte b = src[0];

    // Encode binary stream.
    Tbyte e1 = CFilterBase16::m_sEncodeTable[(b >> 4) & 0x0F];
    Tbyte e2 = CFilterBase16::m_sEncodeTable[b & 0x0F];

    // Write encoded binary stream.
    Tschar c1 = (Tschar)e1;
    Tschar c2 = (Tschar)e2;
    if (!a_rWriter.write(c1).getFirst())
      return result;
    if (!a_rWriter.write(c2).getFirst())
      return result;

    // Take next byte.
    src += sizeof(Tbyte);
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBase16::onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return onFilterWriteBinary(a_rWriter, (Tcptr)a_cpBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBase16::onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return onFilterWriteBinary(a_rWriter, (Tcptr)a_cpBuffer, a_cSize * sizeof(Twchar)) / sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
void CFilterBase16::calculateTables()
{ CALL
  if (!m_sIsInitialized)
  {
    // Calculate decode table.
    NMemory::CMemory::fill(m_sDecodeTable, 256, 0xFF);
    m_sDecodeTable[ASC('0')] = 0;
    m_sDecodeTable[ASC('1')] = 1;
    m_sDecodeTable[ASC('2')] = 2;
    m_sDecodeTable[ASC('3')] = 3;
    m_sDecodeTable[ASC('4')] = 4;
    m_sDecodeTable[ASC('5')] = 5;
    m_sDecodeTable[ASC('6')] = 6;
    m_sDecodeTable[ASC('7')] = 7;
    m_sDecodeTable[ASC('8')] = 8;
    m_sDecodeTable[ASC('9')] = 9;
    m_sDecodeTable[ASC('A')] = 10;
    m_sDecodeTable[ASC('B')] = 11;
    m_sDecodeTable[ASC('C')] = 12;
    m_sDecodeTable[ASC('D')] = 13;
    m_sDecodeTable[ASC('E')] = 14;
    m_sDecodeTable[ASC('F')] = 15;
    m_sDecodeTable[ASC('a')] = 10;
    m_sDecodeTable[ASC('b')] = 11;
    m_sDecodeTable[ASC('c')] = 12;
    m_sDecodeTable[ASC('d')] = 13;
    m_sDecodeTable[ASC('e')] = 14;
    m_sDecodeTable[ASC('f')] = 15;

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
