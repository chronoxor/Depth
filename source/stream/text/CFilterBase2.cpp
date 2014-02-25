/*!
 *  \file    CFilterBase2.cpp Base2 string filter class converts given ASCII
 *           and Unicode strings into the corresponding bit representation.
 *  \brief   Base2 string filter class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base2 string filter class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   13.11.2009 02:26:13

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
#include <Depth/include/stream/text/CFilterBase2.hpp>
/*==========================================================================*/
#ifndef __CFILTERBASE2_CPP__
#define __CFILTERBASE2_CPP__
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
Tbool CFilterBase2::set(const CFilterBase2& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CFilterBase2 class instance."))
  {
    return false;
  }

  // Initialize base filter class.
  return IFilter::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBase2::onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize)
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
    Tbyte b = 0;

    for (Tuint i = 0; i < 8; ++i)
    {
      Tschar d = cache_character;

      // Read encoded binary stream.
      if (!cache && !a_rReader.read(d).getFirst())
        return result;
      cache = false;

      // Check encoded binary stream.
      if ((d != ASC('0')) && (d != ASC('1')))
      {
        WARNING(STR("Base2 encoded binary stream contains invalid character (%s).") COMMA d);
        return result;
      }

      // Calculate the next bit value.
      if (d == ASC('1'))
        b ^= (1 << (7 - i));
    }

    // Decode binary stream.
    *dst = b;

    // Take next byte.
    dst += sizeof(Tbyte);
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBase2::onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onFilterReadBinary(a_rReader, (Tptr)a_pBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBase2::onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onFilterReadBinary(a_rReader, (Tptr)a_pBuffer, a_cSize * sizeof(Twchar)) / sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBase2::onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  const Tschar binary_characters[] = ASC("01");

  Tuint result = 0;
  Tuint count = a_cSize;
  Tcbuffer src = (Tcbuffer)a_cpBuffer;

  while (count-- > 0)
  {
    Tbyte b = src[0];

    for (Tuint i = 0; i < 8; ++i)
    {
      // Encode binary stream.
      Tbyte e = (b >> (7 - i)) & 1;

      // Write encoded binary stream.
      Tschar c = (Tschar)binary_characters[e];
      if (!a_rWriter.write(c).getFirst())
        return result;
    }

    // Take next byte.
    src += sizeof(Tbyte);
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBase2::onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return onFilterWriteBinary(a_rWriter, (Tcptr)a_cpBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBase2::onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return onFilterWriteBinary(a_rWriter, (Tcptr)a_cpBuffer, a_cSize * sizeof(Twchar)) / sizeof(Twchar);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
