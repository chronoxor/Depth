/*!
 *  \file    UCDTable.cpp Unicode Character Database table was generated with
 *           UCDParser utility and used as a source of Unicode information.
 *  \brief   Generated Unicode Character Database table (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.09.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Generated Unicode Character Database table (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD) details.
    VERSION:   1.0
    CREATED:   28.09.2009 23:19:39

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
#include <Depth/include/algorithms/common/ACountOf.hpp>
#include <Depth/include/string/UCD/details/UCDTable.hpp>
/*==========================================================================*/
#ifndef __UCDTABLE_CPP__
#define __UCDTABLE_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NUCD {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* GLOBAL VARIABLES DECLARATIONS                                            */
/*==========================================================================*/
const Tuint32 the_UCDIndexes[][4] = {
#include "UCDTable-UCDIndexes.inl"
};
/*--------------------------------------------------------------------------*/
const SUnicodeCharacterProperties the_UnicodeCharacterProperties[] = {
#include "UCDTable-UnicodeCharacterProperties.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_CharacterNames[] = {
#include "UCDTable-CharacterNames.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_CharacterNamesOld[] = {
#include "UCDTable-CharacterNamesOld.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_CharacterNamesJamo[] = {
#include "UCDTable-CharacterNamesJamo.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_DecimalDigitNames[] = {
#include "UCDTable-DecimalDigitNames.inl"
};
/*--------------------------------------------------------------------------*/
const Tsint the_DecimalDigitValues[] = {
#include "UCDTable-DecimalDigitValues.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_DigitNames[] = {
#include "UCDTable-DigitNames.inl"
};
/*--------------------------------------------------------------------------*/
const Tsint the_DigitValues[] = {
#include "UCDTable-DigitValues.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_NumericNames[] = {
#include "UCDTable-NumericNames.inl"
};
/*--------------------------------------------------------------------------*/
const Tdouble the_NumericValues[] = {
#include "UCDTable-NumericValues.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_BlockNames[] = {
#include "UCDTable-BlockNames.inl"
};
/*--------------------------------------------------------------------------*/
const Tsint32 the_DecompositionMapping[][20] = {
#include "UCDTable-DecompositionMapping.inl"
};
/*==========================================================================*/
/* GLOBAL FUNCTIONS IMPLEMENTATIONS                                         */
/*==========================================================================*/
BASE_API Tsint32 getUCDIndex(const Tuint32 a_cUnicodeCharacter)
{ CALL
  // Try to check in the first block of Unicode Characters.
  if ((a_cUnicodeCharacter >= the_UCDIndexes[0][0]) && (a_cUnicodeCharacter <= the_UCDIndexes[0][1]))
    return (Tsint32)(the_UCDIndexes[0][2] + (a_cUnicodeCharacter - the_UCDIndexes[0][0]));

  // Then perform a binary search for suitable Unicode Characters block.
  Tbool stop = false;
  Tuint size = NAlgorithms::NCommon::countOf(the_UCDIndexes);
  Tuint index_current;
  Tuint index_first = 0;
  Tuint index_last = size - 1;
  while (!stop)
  {
    // Update current index.
    index_current = index_first + ((index_last - index_first + 1) >> 1);

    // Search in left blocks.
    if (a_cUnicodeCharacter < the_UCDIndexes[index_current][0])
    {
      if (index_current < index_last)
      {
        index_last = index_current;
        continue;
      }
      else
        break;
    }
    // Search in right blocks.
    else if (a_cUnicodeCharacter > the_UCDIndexes[index_current][1])
    {
      if (index_current > index_first)
      {
        index_first = index_current;
        continue;
      }
      else
        break;
    }
    // Return found result.
    else
      return (Tsint32)(the_UCDIndexes[index_current][2] + (a_cUnicodeCharacter - the_UCDIndexes[index_current][0]));
  }

  // If nothing was found return invalid index.
  return -1;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
