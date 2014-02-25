/*!
 *  \file    ARemoveStringAll.inl Contains general template implementation of
 *           the algorithm to find and remove all (sub)strings in the given
 *           string object using Brute Force searching algorithm.
 *  \brief   Algorithm to find and remove all (sub)strings in the given string using Brute Force searching algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find and remove all (sub)strings in the given string using Brute Force searching algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   11.01.2010 02:50:32

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
#ifndef __AREMOVESTRINGALL_INL__
#define __AREMOVESTRINGALL_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_SourceStringClass, typename T_PatternStringType>
inline Tbool removeStringAll(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, T_SourceStringClass& a_rSource, const T_PatternStringType& a_crPattern)
{ CALL
  if (a_cReverseSearch)
    return removeStringAll(a_cReverseSearch, a_cIgnoreCase, a_rSource, NConstants::CConstants::uintMax, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax);
  else
    return removeStringAll(a_cReverseSearch, a_cIgnoreCase, a_rSource, 0, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType>
inline Tbool removeStringAll(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, T_SourceStringClass& a_rSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength)
{ CALL
  if (a_cReverseSearch)
    return removeStringAll(a_cReverseSearch, a_cIgnoreCase, a_rSource, NConstants::CConstants::uintMax, a_cSourceLength, a_crPattern, 0, a_cPatternLength);
  else
    return removeStringAll(a_cReverseSearch, a_cIgnoreCase, a_rSource, 0, a_cSourceLength, a_crPattern, 0, a_cPatternLength);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType>
inline Tbool removeStringAll(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  // Check T_SourceStringClass template argument constraint to be a non constant string class.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIString<T_SourceStringClass> >();

  Tbool result = true;
  Tuint source_index = a_cSourceIndex;
  Tuint source_length = a_cSourceLength;
  Tuint found_start, found_end;

  while (result)
  {
    // Try to find and remove the given pattern string.
    if (findString(a_cReverseSearch, a_cIgnoreCase, found_start, found_end, a_rSource, source_index, source_length, a_crPattern, a_cPatternIndex, a_cPatternLength))
    {
      if (!a_rSource.remove(found_start, found_end - found_start + 1))
        result = false;
      else
      {
        source_index = found_start;
        source_length -= found_end - found_start + 1;
        if (source_length == 0)
          break;
      }
    }
    else
      break;
  }
  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
