/*!
 *  \file    AStringReplace.inl Contains general template implementation of
 *           the algorithm to find and replace (sub)string in the given string
 *           object using the given searching algorithm.
 *  \brief   Algorithm to find and replace (sub)string in the given string using the given searching algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find and replace (sub)string in the given string using the given searching algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   12.01.2010 02:37:40

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
#ifndef __ASTRINGREPLACE_INL__
#define __ASTRINGREPLACE_INL__
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
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringReplaceNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, T_SourceStringClass& a_rSource, const T_PatternStringType& a_crPattern, const T_ReplacePatternStringType& a_crReplacePattern, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  return stringReplaceNext(a_rFoundStart, a_rFoundEnd, a_rSource, 0, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax, a_crReplacePattern, 0, NConstants::CConstants::uintMax, a_StringSearchAlgorithm);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringReplaceNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, T_SourceStringClass& a_rSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  return stringReplaceNext(a_rFoundStart, a_rFoundEnd, a_rSource, 0, a_cSourceLength, a_crPattern, 0, a_cPatternLength, a_crReplacePattern, 0, a_cReplacePatternLength, a_StringSearchAlgorithm);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringReplaceNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternIndex, const Tuint a_cReplacePatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  // Check T_SourceStringClass template argument constraint to be a non constant string class.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIString<T_SourceStringClass> >();
  // Check T_StringSearchAlgorithm template argument constraint to be a string searching algorithm.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIStringSearch<T_StringSearchAlgorithm> >();

  // Initialize string searching algorithm with a pattern.
  T_StringSearchAlgorithm string_search_algorithm(a_StringSearchAlgorithm);
  if (!string_search_algorithm.initialize(a_crPattern, a_cPatternIndex, a_cPatternLength))
    return false;

  // Try to find pattern in the given source string.
  Tbool result = string_search_algorithm.findNext(a_rFoundStart, a_rFoundEnd, a_rSource, a_cSourceIndex, a_cSourceLength);

  // Try to replace the found pattern in the string.
  if (result)
  {
    result &= string_search_algorithm.replace(a_rSource, a_rFoundStart, a_rFoundEnd - a_rFoundStart + 1, a_crReplacePattern, a_cReplacePatternIndex, a_cReplacePatternLength).getFirst();
  }

  // Close string searching algorithm.
  result &= string_search_algorithm.close();

  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringReplacePrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, T_SourceStringClass& a_rSource, const T_PatternStringType& a_crPattern, const T_ReplacePatternStringType& a_crReplacePattern, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  return stringReplacePrev(a_rFoundStart, a_rFoundEnd, a_rSource, NConstants::CConstants::uintMax, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax, a_crReplacePattern, 0, NConstants::CConstants::uintMax, a_StringSearchAlgorithm);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringReplacePrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, T_SourceStringClass& a_rSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  return stringReplacePrev(a_rFoundStart, a_rFoundEnd, a_rSource, NConstants::CConstants::uintMax, a_cSourceLength, a_crPattern, 0, a_cPatternLength, a_crReplacePattern, 0, a_cReplacePatternLength, a_StringSearchAlgorithm);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringReplacePrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternIndex, const Tuint a_cReplacePatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  // Check T_SourceStringClass template argument constraint to be a non constant string class.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIString<T_SourceStringClass> >();
  // Check T_StringSearchAlgorithm template argument constraint to be a string searching algorithm.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIStringSearch<T_StringSearchAlgorithm> >();

  // Initialize string searching algorithm with a pattern.
  T_StringSearchAlgorithm string_search_algorithm(a_StringSearchAlgorithm);
  if (!string_search_algorithm.initialize(a_crPattern, a_cPatternIndex, a_cPatternLength))
    return false;

  // Try to find pattern in the given source string.
  Tbool result = string_search_algorithm.findPrev(a_rFoundStart, a_rFoundEnd, a_rSource, a_cSourceIndex, a_cSourceLength);

  // Try to replace the found pattern in the string.
  if (result)
  {
    result &= string_search_algorithm.replace(a_rSource, a_rFoundStart, a_rFoundEnd - a_rFoundStart + 1, a_crReplacePattern, a_cReplacePatternIndex, a_cReplacePatternLength).getFirst();
  }

  // Close string searching algorithm.
  result &= string_search_algorithm.close();

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
