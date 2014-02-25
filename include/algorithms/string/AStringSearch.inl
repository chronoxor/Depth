/*!
 *  \file    AStringSearch.inl Contains general template implementation of
 *           the algorithm to find (sub)string in the given string object
 *           using the given searching algorithm.
 *  \brief   Algorithm to find (sub)string in the given string using the given searching algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find (sub)string in the given string using the given searching algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   06.01.2010 02:34:30

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
#ifndef __ASTRINGSEARCH_INL__
#define __ASTRINGSEARCH_INL__
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
template <typename T_SourceStringType, typename T_PatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringSearchNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const T_PatternStringType& a_crPattern, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  return stringSearchNext(a_rFoundStart, a_rFoundEnd, a_crSource, 0, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax, a_StringSearchAlgorithm);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringSearchNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  return stringSearchNext(a_rFoundStart, a_rFoundEnd, a_crSource, 0, a_cSourceLength, a_crPattern, 0, a_cPatternLength, a_StringSearchAlgorithm);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringSearchNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  // Check T_StringSearchAlgorithm template argument constraint to be a string searching algorithm.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIStringSearch<T_StringSearchAlgorithm> >();

  // Initialize string searching algorithm with a pattern.
  T_StringSearchAlgorithm string_search_algorithm(a_StringSearchAlgorithm);
  if (!string_search_algorithm.initialize(a_crPattern, a_cPatternIndex, a_cPatternLength))
    return false;

  // Try to find pattern in the given source string.
  Tbool result = string_search_algorithm.findNext(a_rFoundStart, a_rFoundEnd, a_crSource, a_cSourceIndex, a_cSourceLength);

  // Close string searching algorithm.
  result &= string_search_algorithm.close();

  return result;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringSearchPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const T_PatternStringType& a_crPattern, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  return stringSearchPrev(a_rFoundStart, a_rFoundEnd, a_crSource, NConstants::CConstants::uintMax, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax, a_StringSearchAlgorithm);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringSearchPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  return stringSearchPrev(a_rFoundStart, a_rFoundEnd, a_crSource, NConstants::CConstants::uintMax, a_cSourceLength, a_crPattern, 0, a_cPatternLength, a_StringSearchAlgorithm);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringSearchPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  // Check T_StringSearchAlgorithm template argument constraint to be a string searching algorithm.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIStringSearch<T_StringSearchAlgorithm> >();

  // Initialize string searching algorithm with a pattern.
  T_StringSearchAlgorithm string_search_algorithm(a_StringSearchAlgorithm);
  if (!string_search_algorithm.initialize(a_crPattern, a_cPatternIndex, a_cPatternLength))
    return false;

  // Try to find pattern in the given source string.
  Tbool result = string_search_algorithm.findPrev(a_rFoundStart, a_rFoundEnd, a_crSource, a_cSourceIndex, a_cSourceLength);

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
