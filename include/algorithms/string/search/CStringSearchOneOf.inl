/*!
 *  \file    CStringSearchOneOf.inl One Of (sub)string searching algorithm.
 *  \brief   One Of (sub)string searching algorithm class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: One Of (sub)string searching algorithm class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   15.02.2010 02:47:58

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
#ifndef __CSTRINGSEARCHONEOF_INL__
#define __CSTRINGSEARCHONEOF_INL__
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
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_SourceStringType, typename T_PatternStringType, class T_StringSearchAlgorithm>
inline CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>::CStringSearchOneOf(const Tbool a_cIgnoreCaseFlag/* = false */) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, class T_StringSearchAlgorithm>
inline CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>::CStringSearchOneOf(const CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>& a_crInstance) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, class T_StringSearchAlgorithm>
inline CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>::~CStringSearchOneOf()
{ CALL
  m_StringBuffer.clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, class T_StringSearchAlgorithm>
inline CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>& CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>::operator = (const CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, class T_StringSearchAlgorithm>
inline Tbool CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>::set(const CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>& a_crInstance)
{ CALL
  return (IStringSearch<T_SourceStringType, T_PatternStringType>::set(a_crInstance) && m_StringBuffer.set(a_crInstance.m_StringBuffer) && m_StringSearchers.set(a_crInstance.m_StringSearchers));
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, class T_StringSearchAlgorithm>
inline NContainers::CStringBuffer<NDepth::NString::CString>& CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>::getPatterns()
{ CALL
  typedef IStringSearch<T_SourceStringType, T_PatternStringType> TBase;

  // Check if the current string search algorithm is not initialized.
  ASSERT(!TBase::isInitialized(), STR("Cannot access to the patterns string buffer of the string search algorithm which is already initialized."));

  return m_StringBuffer;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, class T_StringSearchAlgorithm>
inline const NContainers::CStringBuffer<NDepth::NString::CString>& CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>::getPatterns() const
{ CALL
  typedef IStringSearch<T_SourceStringType, T_PatternStringType> TBase;

  // Check if the current string search algorithm is not initialized.
  ASSERT(!TBase::isInitialized(), STR("Cannot access to the patterns string buffer of the string search algorithm which is already initialized."));

  return m_StringBuffer;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, class T_StringSearchAlgorithm>
inline Tbool CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>::onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  NDepth::NString::CString pattern;
  Tuint i, size = m_StringBuffer.getSize();

  // Initialize searching string patterns from string buffer.
  for (i = 0; i < size; ++i)
  {
    // Get the next pattern.
    if (!NDetails::CStringSearchHelper::copyPattern(pattern, m_StringBuffer[i], 0, NConstants::CConstants::uintMax))
      return false;

    // Skip empty pattern.
    if (pattern.isEmpty())
      continue;

    // Insert new string searching algorithm.
    if (!m_StringSearchers.insertLast(T_StringSearchAlgorithm(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag())))
      return false;

    // Initialize corresponding string searching algorithm.
    if (!m_StringSearchers[i].initialize(pattern, 0, NConstants::CConstants::uintMax))
      return false;
  }

  // Get the last pattern.
  if (!NDetails::CStringSearchHelper::copyPattern(pattern, a_crPattern, a_cPatternIndex, a_cPatternLength))
    return false;

  // Insert the last string searching algorithm.
  if (!m_StringSearchers.insertLast(T_StringSearchAlgorithm(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag())))
    return false;

  // Initialize corresponding string searching algorithm.
  if (!m_StringSearchers[i].initialize(pattern, 0, NConstants::CConstants::uintMax))
    return false;

  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, class T_StringSearchAlgorithm>
inline Tbool CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>::onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  Tbool found = false;
  Tuint start, end, size = m_StringSearchers.getSize();

  // Try to sequentially find forward using searching string algorithms.
  for (Tuint i = 0; i < size; ++i)
  {
    if (m_StringSearchers[i].findNext(start, end, a_crSource, a_cSourceIndex, a_cSourceLength))
    {
      if (!found || (a_rFoundStart > start) || (a_rFoundEnd > end))
      {
        a_rFoundStart = start;
        a_rFoundEnd = end;
      }
      found = true;
    }
  }

  return found;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, class T_StringSearchAlgorithm>
inline Tbool CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>::onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  Tbool found = false;
  Tuint start, end, size = m_StringSearchers.getSize();

  // Try to sequentially find forward using searching string algorithms.
  for (Tuint i = 0; i < size; ++i)
  {
    if (m_StringSearchers[i].findPrev(start, end, a_crSource, a_cSourceIndex, a_cSourceLength))
    {
      if (!found || (a_rFoundStart < start) || (a_rFoundEnd < end))
      {
        a_rFoundStart = start;
        a_rFoundEnd = end;
      }
      found = true;
    }
  }

  return found;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, class T_StringSearchAlgorithm>
inline Tbool CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>::onClose()
{ CALL
  Tuint size = m_StringSearchers.getSize();

  // Close searching string algorithms.
  for (Tuint i = 0; i < size; ++i)
  {
    // Close corresponding string searching algorithm.
    if (!m_StringSearchers[i].close())
      return false;
  }

  return m_StringSearchers.clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, class T_StringSearchAlgorithm>
template <class T_Archive>
inline Tbool CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::CStringSearchOneOf")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_StringBuffer, STR("m_StringBuffer")));
    CHECK(a_rArchive.doValue(m_StringSearchers, STR("m_StringSearchers")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType, class T_StringSearchAlgorithm>
inline void CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>::swap(CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), (IStringSearch<T_SourceStringType, T_PatternStringType>&)a_rInstance);
  NAlgorithms::NCommon::swap(m_StringBuffer, a_rInstance.m_StringBuffer);
  NAlgorithms::NCommon::swap(m_StringSearchers, a_rInstance.m_StringSearchers);
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
