/*!
 *  \file    AStringRemoveAll.inl Contains general template implementation of
 *           the algorithm to find and remove all (sub)strings in the given
 *           string object using the given searching algorithm.
 *  \brief   Algorithm to find and remove all (sub)strings in the given string using the given searching algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find and remove all (sub)strings in the given string using the given searching algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   11.01.2010 22:49:04

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
#ifndef __ASTRINGREMOVEALL_INL__
#define __ASTRINGREMOVEALL_INL__
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
template <class T_SourceStringClass, typename T_PatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringRemoveAllNext(T_SourceStringClass& a_rSource, const T_PatternStringType& a_crPattern, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  return stringRemoveAllNext(a_rSource, 0, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax, a_StringSearchAlgorithm);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringRemoveAllNext(T_SourceStringClass& a_rSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  return stringRemoveAllNext(a_rSource, 0, a_cSourceLength, a_crPattern, 0, a_cPatternLength, a_StringSearchAlgorithm);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringRemoveAllNext(T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  // Check T_SourceStringClass template argument constraint to be a non constant string class.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIString<T_SourceStringClass> >();
  // Check T_StringSearchAlgorithm template argument constraint to be a string searching algorithm.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIStringSearch<T_StringSearchAlgorithm> >();

  // Initialize string searching algorithm with a pattern.
  T_StringSearchAlgorithm string_search_algorithm(a_StringSearchAlgorithm);
  if (!string_search_algorithm.initialize(a_crPattern, a_cPatternIndex, a_cPatternLength))
    return false;

  Tbool result = true;
  Tuint source_index = a_cSourceIndex;
  Tuint source_length = a_cSourceLength;
  Tuint found_start, found_end;

  while (result)
  {
    // Try to find and remove the given pattern string.
    if (string_search_algorithm.findNext(found_start, found_end, a_rSource, source_index, source_length))
    {
      NUtility::CPair<Tbool, Tuint> remove_result = string_search_algorithm.remove(a_rSource, found_start, found_end - found_start + 1);
      if (!remove_result.getFirst())
        result = false;
      else
      {
        source_index = found_start;
        source_length -= remove_result.getSecond();
        if (source_length == 0)
          break;
      }
    }
    else
      break;
  }

  // Close string searching algorithm.
  result &= string_search_algorithm.close();

  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringRemoveAllPrev(T_SourceStringClass& a_rSource, const T_PatternStringType& a_crPattern, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  return stringRemoveAllPrev(a_rSource, NConstants::CConstants::uintMax, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax, a_StringSearchAlgorithm);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringRemoveAllPrev(T_SourceStringClass& a_rSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  return stringRemoveAllPrev(a_rSource, NConstants::CConstants::uintMax, a_cSourceLength, a_crPattern, 0, a_cPatternLength, a_StringSearchAlgorithm);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_StringSearchAlgorithm>
inline Tbool stringRemoveAllPrev(T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm)
{ CALL
  // Check T_SourceStringClass template argument constraint to be a non constant string class.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIString<T_SourceStringClass> >();
  // Check T_StringSearchAlgorithm template argument constraint to be a string searching algorithm.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIStringSearch<T_StringSearchAlgorithm> >();

  // Initialize string searching algorithm with a pattern.
  T_StringSearchAlgorithm string_search_algorithm(a_StringSearchAlgorithm);
  if (!string_search_algorithm.initialize(a_crPattern, a_cPatternIndex, a_cPatternLength))
    return false;

  Tbool result = true;
  Tuint source_index = a_cSourceIndex;
  Tuint source_length = a_cSourceLength;
  Tuint found_start, found_end;

  while (result)
  {
    // Try to find and remove the given pattern string.
    if (string_search_algorithm.findPrev(found_start, found_end, a_rSource, source_index, source_length))
    {
      NUtility::CPair<Tbool, Tuint> remove_result = string_search_algorithm.remove(a_rSource, found_start, found_end - found_start + 1);
      if (!remove_result.getFirst())
        result = false;
      else
      {
        source_index = found_start;
        source_length -= remove_result.getSecond();
        if (source_length == 0)
          break;
      }
    }
    else
      break;
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
