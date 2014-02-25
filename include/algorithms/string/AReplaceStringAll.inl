/*!
 *  \file    AReplaceStringAll.inl Contains general template implementation of
 *           the algorithm to find and replace all (sub)strings in the given
 *           string object using Brute Force searching algorithm.
 *  \brief   Algorithm to find and replace all (sub)strings in the given string using Brute Force searching algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find and replace all (sub)strings in the given string using Brute Force searching algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   11.01.2010 20:44:40

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
#ifndef __AREPLACESTRINGALL_INL__
#define __AREPLACESTRINGALL_INL__
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
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType>
inline Tbool replaceStringAll(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, T_SourceStringClass& a_rSource, const T_PatternStringType& a_crPattern, const T_ReplacePatternStringType& a_crReplacePattern)
{ CALL
  if (a_cReverseSearch)
    return replaceStringAll(a_cReverseSearch, a_cIgnoreCase, a_rSource, NConstants::CConstants::uintMax, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax, a_crReplacePattern, 0, NConstants::CConstants::uintMax);
  else
    return replaceStringAll(a_cReverseSearch, a_cIgnoreCase, a_rSource, 0, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax, a_crReplacePattern, 0, NConstants::CConstants::uintMax);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType>
inline Tbool replaceStringAll(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, T_SourceStringClass& a_rSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternLength)
{ CALL
  if (a_cReverseSearch)
    return replaceStringAll(a_cReverseSearch, a_cIgnoreCase, a_rSource, NConstants::CConstants::uintMax, a_cSourceLength, a_crPattern, 0, a_cPatternLength, a_crReplacePattern, 0, a_cReplacePatternLength);
  else
    return replaceStringAll(a_cReverseSearch, a_cIgnoreCase, a_rSource, 0, a_cSourceLength, a_crPattern, 0, a_cPatternLength, a_crReplacePattern, 0, a_cReplacePatternLength);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType>
inline Tbool replaceStringAll(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternIndex, const Tuint a_cReplacePatternLength)
{ CALL
  // Check T_SourceStringClass template argument constraint to be a non constant string class.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIString<T_SourceStringClass> >();

  // Prepare replace pattern.
  T_SourceStringClass replace_pattern;
  if (!NDetails::CStringSearchHelper::copyPattern(replace_pattern, a_crReplacePattern, a_cReplacePatternIndex, a_cReplacePatternLength))
    return false;

  // Get replace pattern length.
  Tuint replace_pattern_length = replace_pattern.getSize();

  Tbool result = true;
  Tuint source_index = a_cSourceIndex;
  Tuint source_length = a_cSourceLength;
  Tuint found_start, found_end;

  while (result)
  {
    // Try to find and replace the given pattern string.
    if (findString(a_cReverseSearch, a_cIgnoreCase, found_start, found_end, a_rSource, source_index, source_length, a_crPattern, a_cPatternIndex, a_cPatternLength))
    {
      if (!a_rSource.replace(found_start, found_end - found_start + 1, replace_pattern))
        result = false;
      else
      {
        source_index = found_start + replace_pattern_length;
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
