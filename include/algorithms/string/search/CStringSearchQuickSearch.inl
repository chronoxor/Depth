/*!
 *  \file    CStringSearchQuickSearch.inl Quick Search (sub)string searching
 *           algorithm.
 *  \brief   Quick Search (sub)string searching algorithm class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Quick Search (sub)string searching algorithm class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   09.02.2010 02:50:44

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
#ifndef __CSTRINGSEARCHQUICKSEARCH_INL__
#define __CSTRINGSEARCHQUICKSEARCH_INL__
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
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>::CStringSearchQuickSearch(const Tbool a_cIgnoreCaseFlag/* = false */) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>::CStringSearchQuickSearch(const CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>& a_crInstance) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>::~CStringSearchQuickSearch()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>& CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>::operator = (const CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>::set(const CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  return (IStringSearch<T_SourceStringType, T_PatternStringType>::set(a_crInstance) && m_Pattern.set(a_crInstance.m_Pattern) && m_QSBcF.set(a_crInstance.m_QSBcF) && m_QSBcB.set(a_crInstance.m_QSBcB));
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>::onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  if (NDetails::CStringSearchHelper::copyPattern(m_Pattern, a_crPattern, a_cPatternIndex, a_cPatternLength))
    return calculateBadCharacterShift(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag(), m_Pattern, m_QSBcF, m_QSBcB);
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>::onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= m_Pattern.getSize())
  {
    Tuint i, j = 0;
    Tuint n = a_cSourceLength;
    Tuint m = m_Pattern.getSize();

    while (j <= n - m)
    {
      for (i = 0; i < m; ++i)
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i + j]).toLowerCase() != NDepth::NString::CCharacter(m_Pattern[i]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + i + j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[i])))
          break;

      if (i >= m)
      {
        a_rFoundStart = a_cSourceIndex + j;
        a_rFoundEnd = a_cSourceIndex + j + i - 1;
        return true;
      }

      TCharacterTable::TIteratorConst it_const;
      if (j < n - m)
        it_const = m_QSBcF.find((IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + j + m]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex + j + m]));
      j += (it_const.isValid() ? it_const.getValueRef() : (m + 1));
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>::onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= m_Pattern.getSize())
  {
    Tuint i, j = 0;
    Tuint n = a_cSourceLength;
    Tuint m = m_Pattern.getSize();

    while (j <= n - m)
    {
      for (i = 0; i < m; ++i)
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i - j]).toLowerCase() != NDepth::NString::CCharacter(m_Pattern[m - i - 1]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - i - j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[m - i - 1])))
          break;

      if (i >= m)
      {
        a_rFoundStart = a_cSourceIndex - j - i + 1;
        a_rFoundEnd = a_cSourceIndex - j;
        return true;
      }

      TCharacterTable::TIteratorConst it_const;
      if (j < n - m)
        it_const = m_QSBcB.find((IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - j - m]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex - j - m]));
      j += (it_const.isValid() ? it_const.getValueRef() : (m + 1));
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>::onClose()
{ CALL
  return (m_Pattern.clear() && m_QSBcF.clear() && m_QSBcB.clear());
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>::calculateBadCharacterShift(const Tbool a_cIgnoreCaseFlag, const NDepth::NString::CString& a_crPattern, TCharacterTable& a_rQSBcF, TCharacterTable& a_rQSBcB)
{ CALL
  Tuint i, m = a_crPattern.getSize();

  // Allocate enough space for bad-character shift values.
  if (!a_rQSBcF.resize(256) || !a_rQSBcB.resize(256))
    return false;

  // Calculate forward bad-character shift values.
  for (i = 0; i < m; ++i)
  {
    Tuint key = (a_cIgnoreCaseFlag ? NDepth::NString::CCharacter(a_crPattern[i]).toLowerCase().getUnsigned() : (Tuint)a_crPattern[i]);
    TCharacterTable::TIterator it = a_rQSBcF.find(key);
    if (it.isValid())
      it.getValueRef() = (m - i);
    else
      if (!a_rQSBcF.insert(key, (m - i)))
        return false;
  }

  // Calculate backward bad-character shift values.
  for (i = 0; i < m; ++i)
  {
    Tuint key = (a_cIgnoreCaseFlag ? NDepth::NString::CCharacter(a_crPattern[m - i - 1]).toLowerCase().getUnsigned() : (Tuint)a_crPattern[m - i - 1]);
    TCharacterTable::TIterator it = a_rQSBcB.find(key);
    if (it.isValid())
      it.getValueRef() = (m - i);
    else
      if (!a_rQSBcB.insert(key, (m - i)))
        return false;
  }

  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_Archive>
inline Tbool CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::CStringSearchQuickSearch")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_Pattern, STR("m_Pattern")));
    CHECK(a_rArchive.doValue(m_QSBcF, STR("m_QSBcF")));
    CHECK(a_rArchive.doValue(m_QSBcB, STR("m_QSBcB")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline void CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>::swap(CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), (IStringSearch<T_SourceStringType, T_PatternStringType>&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Pattern, a_rInstance.m_Pattern);
  NAlgorithms::NCommon::swap(m_QSBcF, a_rInstance.m_QSBcF);
  NAlgorithms::NCommon::swap(m_QSBcB, a_rInstance.m_QSBcB);
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
