/*!
 *  \file    IStringSearch.inl Interface for all (sub)string searching
 *           algorithms.
 *  \brief   String searching algorithm interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: String searching algorithm interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   25.11.2009 20:05:10

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
#ifndef __ISTRINGSEARCH_INL__
#define __ISTRINGSEARCH_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NSearch {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline IStringSearch<T_SourceStringType, T_PatternStringType>::IStringSearch(const Tbool a_cIgnoreCaseFlag/* = false */) :
  m_IsInitialized(false),
  m_IgnoreCaseFlag(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline IStringSearch<T_SourceStringType, T_PatternStringType>::IStringSearch(const IStringSearch<T_SourceStringType, T_PatternStringType>& a_crInstance) :
  m_IsInitialized(a_crInstance.m_IsInitialized),
  m_IgnoreCaseFlag(a_crInstance.m_IgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline IStringSearch<T_SourceStringType, T_PatternStringType>::~IStringSearch()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline IStringSearch<T_SourceStringType, T_PatternStringType>& IStringSearch<T_SourceStringType, T_PatternStringType>::operator = (const IStringSearch<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::set(const IStringSearch<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  m_IsInitialized = a_crInstance.m_IsInitialized;
  m_IgnoreCaseFlag = a_crInstance.m_IgnoreCaseFlag;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::setIgnoreCaseFlag(const Tbool a_cIgnoreCaseFlag)
{ CALL
  // Check if the current string search algorithm is not initialized.
  ASSERT(!isInitialized(), STR("Cannot set ignore case flag for the string search algorithm which is already initialized."))
  {
    return false;
  }

  m_IgnoreCaseFlag = a_cIgnoreCaseFlag;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() const
{ CALL
  return m_IgnoreCaseFlag;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::isInitialized() const
{ CALL
  return m_IsInitialized;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::initialize(const T_PatternStringType& a_crPattern)
{ CALL
  return initialize(a_crPattern, 0, NConstants::CConstants::uintMax);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::initialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength)
{ CALL
  return initialize(a_crPattern, 0, a_cPatternLength);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::initialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  // Check if the current string search algorithm is not initialized.
  ASSERT(!isInitialized(), STR("Cannot initialize the string search algorithm which is already initialized."))
  {
    return false;
  }

  Tuint length = stringLength(a_crPattern, a_cPatternIndex, a_cPatternLength);

  // Check if the pattern string is not empty.
  ASSERT((length > 0), STR("Pattern string cannot be empty. Its length should be greater than zero."))
  {
    return false;
  }

  // Perform initialization.
  m_IsInitialized = onInitialize(a_crPattern, a_cPatternIndex, length);

  // Return result value.
  return m_IsInitialized;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::findNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource)
{ CALL
  return findNext(a_rFoundStart, a_rFoundEnd, a_crSource, 0, NConstants::CConstants::uintMax);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::findNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceLength)
{ CALL
  return findNext(a_rFoundStart, a_rFoundEnd, a_crSource, 0, a_cSourceLength);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::findNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  // Check if the current string search algorithm is initialized.
  ASSERT(isInitialized(), STR("Cannot perform a forward find operation for the string search algorithm which is not initialized."))
  {
    return false;
  }

  Tuint length = stringLength(a_crSource, a_cSourceIndex, a_cSourceLength);

  // Check if we have enough length to search.
  if (length == 0)
    return false;

  // Reform forward searching and return result value.
  return onFindNext(a_rFoundStart, a_rFoundEnd, a_crSource, a_cSourceIndex, length);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::findPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource)
{ CALL
  return findPrev(a_rFoundStart, a_rFoundEnd, a_crSource, NConstants::CConstants::uintMax, NConstants::CConstants::uintMax);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::findPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceLength)
{ CALL
  return findPrev(a_rFoundStart, a_rFoundEnd, a_crSource, NConstants::CConstants::uintMax, a_cSourceLength);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::findPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  // Check if the current string search algorithm is initialized.
  ASSERT(isInitialized(), STR("Cannot perform a backward find operation for the string search algorithm which is not initialized."))
  {
    return false;
  }

  Tuint index = NCommon::min((a_cSourceIndex < NConstants::CConstants::uintMax) ? (a_cSourceIndex + 1) : a_cSourceIndex, stringLength(a_crSource));
  Tuint length = NCommon::min(index, a_cSourceLength);

  // Check if we have enough length to search.
  if (length == 0)
    return false;

  // Reform backward searching and return result value.
  return onFindPrev(a_rFoundStart, a_rFoundEnd, a_crSource, index - 1, length);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_SourceStringClass>
inline NUtility::CPair<Tbool, Tuint> IStringSearch<T_SourceStringType, T_PatternStringType>::remove(T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  // Check T_SourceStringClass template argument constraint to be a non constant string class.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIString<T_SourceStringClass> >();

  // Perform remove operation.
  return NUtility::CPair<Tbool, Tuint>(a_rSource.remove(a_cSourceIndex, a_cSourceLength), a_cSourceLength);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_SourceStringClass, typename T_ReplacePatternStringType>
inline NUtility::CPair<Tbool, Tuint> IStringSearch<T_SourceStringType, T_PatternStringType>::replace(T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_ReplacePatternStringType& a_crReplacePattern)
{ CALL
  return replace(a_rSource, a_cSourceIndex, a_cSourceLength, a_crReplacePattern, 0, NConstants::CConstants::uintMax);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_SourceStringClass, typename T_ReplacePatternStringType>
inline NUtility::CPair<Tbool, Tuint> IStringSearch<T_SourceStringType, T_PatternStringType>::replace(T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternLength)
{ CALL
  return replace(a_rSource, a_cSourceIndex, a_cSourceLength, a_crReplacePattern, 0, a_cReplacePatternLength);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_SourceStringClass, typename T_ReplacePatternStringType>
inline NUtility::CPair<Tbool, Tuint> IStringSearch<T_SourceStringType, T_PatternStringType>::replace(T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternIndex, const Tuint a_cReplacePatternLength)
{ CALL
  // Check T_SourceStringClass template argument constraint to be a non constant string class.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIString<T_SourceStringClass> >();

  // Prepare replace pattern.
  NDepth::NString::CString replace_pattern;
  if (!NDetails::CStringSearchHelper::copyPattern(replace_pattern, a_crReplacePattern, a_cReplacePatternIndex, a_cReplacePatternLength) || !updateReplacePattern(replace_pattern))
    return NUtility::CPair<Tbool, Tuint>(false, 0);

  // Prepare result pattern and get its length.
  T_SourceStringClass result_pattern(replace_pattern);
  Tuint result_pattern_length = result_pattern.getSize();

  // Perform replace operation.
  return NUtility::CPair<Tbool, Tuint>(a_rSource.replace(a_cSourceIndex, a_cSourceLength, result_pattern), result_pattern_length);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::close()
{ CALL
  // Check if the current string search algorithm is initialized.
  ASSERT(isInitialized(), STR("Cannot close the string search algorithm which is not initialized."))
  {
    return false;
  }

  // Perform close operation.
  Tbool result = onClose();

  // Update initialization flag.
  if (result)
    m_IsInitialized = false;

  // Return result value.
  return result;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::updateReplacePattern(NDepth::NString::CString& a_rReplacePattern)
{ CALL
  IGNORE_UNUSED(a_rReplacePattern);

  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_Archive>
inline Tbool IStringSearch<T_SourceStringType, T_PatternStringType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::IStringSearch")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_IsInitialized, STR("m_IsInitialized")));
    CHECK(a_rArchive.doValue(m_IgnoreCaseFlag, STR("m_IgnoreCaseFlag")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline void IStringSearch<T_SourceStringType, T_PatternStringType>::swap(IStringSearch<T_SourceStringType, T_PatternStringType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_IsInitialized, a_rInstance.m_IsInitialized);
  NAlgorithms::NCommon::swap(m_IgnoreCaseFlag, a_rInstance.m_IgnoreCaseFlag);
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
