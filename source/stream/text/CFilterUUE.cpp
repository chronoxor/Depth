/*!
 *  \file    CFilterUUE.cpp UUE string filter class converts given ASCII
 *           and Unicode strings into the corresponding UUE-encoded
 *           representation.
 *  \brief   UUE string filter class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: UUE string filter class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   11.11.2009 03:35:28

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
#include <Depth/include/stream/text/CFilterUUE.hpp>
/*==========================================================================*/
#ifndef __CFILTERUUE_CPP__
#define __CFILTERUUE_CPP__
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
BASE_API Tbool CFilterUUE::m_sIsInitialized = false;
BASE_API Tbyte CFilterUUE::m_sEncodeTable[64] =
{
  Tbyte('`'),  Tbyte('!'),  Tbyte('\"'), Tbyte('#'),
  Tbyte('$'),  Tbyte('%'),  Tbyte('&'),  Tbyte('\''),
  Tbyte('('),  Tbyte(')'),  Tbyte('*'),  Tbyte('+'),
  Tbyte(','),  Tbyte('-'),  Tbyte('.'),  Tbyte('/'),
  Tbyte('0'),  Tbyte('1'),  Tbyte('2'),  Tbyte('3'),
  Tbyte('4'),  Tbyte('5'),  Tbyte('6'),  Tbyte('7'),
  Tbyte('8'),  Tbyte('9'),  Tbyte(':'),  Tbyte(';'),
  Tbyte('<'),  Tbyte('='),  Tbyte('>'),  Tbyte('?'),
  Tbyte('@'),  Tbyte('A'),  Tbyte('B'),  Tbyte('C'),
  Tbyte('D'),  Tbyte('E'),  Tbyte('F'),  Tbyte('G'),
  Tbyte('H'),  Tbyte('I'),  Tbyte('J'),  Tbyte('K'),
  Tbyte('L'),  Tbyte('M'),  Tbyte('N'),  Tbyte('O'),
  Tbyte('P'),  Tbyte('Q'),  Tbyte('R'),  Tbyte('S'),
  Tbyte('T'),  Tbyte('U'),  Tbyte('V'),  Tbyte('W'),
  Tbyte('X'),  Tbyte('Y'),  Tbyte('Z'),  Tbyte('['),
  Tbyte('\\'), Tbyte(']'),  Tbyte('^'),  Tbyte('_')
};
BASE_API Tbyte CFilterUUE::m_sDecodeTable[256];
/*--------------------------------------------------------------------------*/
Tbool CFilterUUE::set(const CFilterUUE& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CFilterUUE class instance."))
  {
    return false;
  }

  // Initialize base filter class.
  if (!NPack::IFilterFramePack<45>::set(a_crInstance))
    return false;

  // Initialize UUE filter properties.
  m_IsWriteLineEnding = a_crInstance.m_IsWriteLineEnding;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterUUE::onOpenReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  IGNORE_UNUSED(a_rReader);
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_rCurrentSize);
  IGNORE_UNUSED(a_cFullSize);

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterUUE::onOpenWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  IGNORE_UNUSED(a_rWriter);
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_rCurrentSize);
  IGNORE_UNUSED(a_cFullSize);

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterUUE::onPackReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  Tuint line = 0;
  Tuint count = a_cFullSize - a_rCurrentSize;
  Tbuffer dst = (Tbuffer)(a_pBuffer + a_rCurrentSize);

  while (line == 0)
  {
    // Read counter character form the given reader.
    Tschar c;
    if (!a_rReader.read(c).getFirst())
      return true;

    // Check for new line symbols.
    if ((c == ASC('\r')) || (c == ASC('\n')))
      continue;
    else
    {
      line = m_sDecodeTable[c & 0177];
      break;
    }
  }

  // Check if the length of UUE line is less or equal to 45.
  ASSERT(((line > 0) && (line <= 45)), STR("UUE encoded stream has incorrect format (length of UUE line = %u).") COMMA line)
  {
    return false;
  }
  // Check if the length read buffer is enough to unpack UUE line.
  ASSERT((line <= count), STR("Length of the read buffer of the UUE filter is not enough to unpack UUE line (length of UUE line = %u, UUE read buffer length = %u).") COMMA line COMMA count)
  {
    return false;
  }

  // Unpack UUE line.
  while (line > 0)
  {
    // Read UUE encoded characters form the given reader.
    Tschar c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    if (!a_rReader.read(c1).getFirst() || !a_rReader.read(c2).getFirst() || !a_rReader.read(c3).getFirst() || !a_rReader.read(c4).getFirst())
    {
      WARNING(STR("UUE encoded stream has incorrect format."));
      return false;
    }

    // Unpack UUE encoded characters.
    Tbyte b1 = m_sDecodeTable[c1 & 0177] << 2 | m_sDecodeTable[c2 & 0177] >> 4;
    Tbyte b2 = m_sDecodeTable[c2 & 0177] << 4 | m_sDecodeTable[c3 & 0177] >> 2;
    Tbyte b3 = m_sDecodeTable[c3 & 0177] << 6 | m_sDecodeTable[c4 & 0177];

    if ((b1 == (Tbyte)0xFF) || (b2 == (Tbyte)0xFF) || (b3 == (Tbyte)0xFF))
    {
      WARNING(STR("UUE encoded binary stream contains invalid characters (%hU, %hU and %hU).") COMMA (Tuint)b1 COMMA (Tuint)b2 COMMA (Tuint)b3);
      return false;
    }

    // Store characters into the read buffer.
    if (line > 0)
    {
      *dst++ = b1;
      --line;
      --count;
      ++a_rCurrentSize;
    }
    if (line > 0)
    {
      *dst++ = b2;
      --line;
      --count;
      ++a_rCurrentSize;
    }
    if (line > 0)
    {
      *dst++ = b3;
      --line;
      --count;
      ++a_rCurrentSize;
    }
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterUUE::onPackWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  IGNORE_UNUSED(a_cFullSize);

  Tuint count = a_rCurrentSize;
  Tbool endline = (isWriteLineEnding() && (count == 45));
  Tcbuffer src = (Tcbuffer)a_pBuffer;

  // If nothing to write.
  if (count == 0)
    return true;

  // Write counter character into the given writer.
  Tschar c = m_sEncodeTable[count & 077];
  if (!a_rWriter.write(c).getFirst())
  {
    WARNING(STR("Cannot write UUE counter character into the stream."));
    return false;
  }

  // Pack UUE line.
  while (count > 0)
  {
    Tbyte b1 = src[0];
    Tbyte b2 = (count > 1) ? src[1] : 0;
    Tbyte b3 = (count > 2) ? src[2] : 0;

    // Encode UUE characters.
    Tschar c1 = m_sEncodeTable[((b1 >> 2) & 077) & 077];
    Tschar c2 = m_sEncodeTable[((b1 << 4) & 060) | (((b2 >> 4) & 017) & 077)];
    Tschar c3 = m_sEncodeTable[((b2 << 2) & 074) | (((b3 >> 6) & 03) & 077)];
    Tschar c4 = m_sEncodeTable[(b3 & 077) & 077];

    // Write UUE characters.
    if (!a_rWriter.write(c1).getFirst() || !a_rWriter.write(c2).getFirst() || !a_rWriter.write(c3).getFirst() || !a_rWriter.write(c4).getFirst())
    {
      WARNING(STR("Cannot write UUE encoded characters into the stream."));
      return false;
    }

    // Update indexes.
    Tuint increment = NAlgorithms::NCommon::min(count, CONSTU(3));
    src += increment;
    count -= increment;
  }

  // Write end line characters.
  if (endline)
    if (!a_rWriter.writeLineEnd(true).getFirst())
      return false;

  // Update write frame buffer.
  NMemory::CMemory::move(a_pBuffer, a_pBuffer + a_rCurrentSize - count, count);
  a_rCurrentSize = count;

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterUUE::onCloseReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  IGNORE_UNUSED(a_rReader);
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_rCurrentSize);
  IGNORE_UNUSED(a_cFullSize);

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterUUE::onCloseWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize)
{ CALL
  return onPackWriteFrame(a_rWriter, a_pBuffer, a_rCurrentSize, a_cFullSize);
}
/*--------------------------------------------------------------------------*/
void CFilterUUE::calculateTables()
{ CALL
  if (!m_sIsInitialized)
  {
    // Calculate decode table.
    NMemory::CMemory::fill(m_sDecodeTable, 256, 0xFF);
    for (Tuint i = 0; i < 64; ++i)
      m_sDecodeTable[m_sEncodeTable[i] & 0177] = (Tbyte)i;

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
