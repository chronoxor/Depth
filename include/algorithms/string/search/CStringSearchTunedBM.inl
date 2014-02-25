/*!
 *  \file    CStringSearchTunedBM.inl Tuned Boyer-Moore (sub)string searching
 *           algorithm.
 *  \brief   Tuned Boyer-Moore (sub)string searching algorithm class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tuned Boyer-Moore (sub)string searching algorithm class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   11.02.2010 02:47:35

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
#ifndef __CSTRINGSEARCHTUNEDBM_INL__
#define __CSTRINGSEARCHTUNEDBM_INL__
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
inline CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>::CStringSearchTunedBM(const Tbool a_cIgnoreCaseFlag/* = false */) :
  CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>::CStringSearchTunedBM(const CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>& a_crInstance) :
  CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>::~CStringSearchTunedBM()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>& CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>::operator = (const CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>::set(const CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  if (CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::set(a_crInstance))
  {
    m_ShiftF = a_crInstance.m_ShiftF;
    m_ShiftB = a_crInstance.m_ShiftB;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>::onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  if (NDetails::CStringSearchHelper::copyPattern(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern, a_crPattern, a_cPatternIndex, a_cPatternLength) && calculateBadCharacterShift(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag(), CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern, CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcF, CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcB))
  {
    Tuint m = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    // Calculate forward shift value.
    typename CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::TCharacterTable::TIterator itF = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcF.find(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - 1]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - 1]);
    if (itF.isValid())
    {
      m_ShiftF = itF.getValueRef();
      itF.getValueRef() = 0;
    }
    else
    {
      m_ShiftF = m;
      if (!CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcF.insert(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - 1]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - 1], 0))
        return false;
    }

    // Calculate backward shift value.
    typename CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::TCharacterTable::TIterator itB = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcB.find(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[CONSTU(0)]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[CONSTU(0)]);
    if (itB.isValid())
    {
      m_ShiftB = itB.getValueRef();
      itB.getValueRef() = 0;
    }
    else
    {
      m_ShiftB = m;
      if (!CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcB.insert(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[CONSTU(0)]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[CONSTU(0)], 0))
        return false;
    }

    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>::onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize())
  {
    Tuint i, j = 0;
    Tuint k, l, p = a_cSourceIndex + a_cSourceLength;
    Tuint n = a_cSourceLength;
    Tuint m = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    while (j < n)
    {
      l = a_cSourceIndex + j + m - 1;
      typename CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::TCharacterTable::TIteratorConst it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcF.find((l < p) ? (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + j + m - 1]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex + j + m - 1]) : (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[l - p]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[l - p]));
      k = ((it_const.isValid() ? it_const.getValueRef() : m));

      while (k != 0)
      {
        // First step.
        j += k;
        l = a_cSourceIndex + j + m - 1;
        it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcF.find((l < p) ? (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + j + m - 1]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex + j + m - 1]) : (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[l - p]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[l - p]));
        k = ((it_const.isValid() ? it_const.getValueRef() : m));

        // Second step.
        j += k;
        l = a_cSourceIndex + j + m - 1;
        it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcF.find((l < p) ? (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + j + m - 1]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex + j + m - 1]) : (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[l - p]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[l - p]));
        k = ((it_const.isValid() ? it_const.getValueRef() : m));

        // Third step.
        j += k;
        l = a_cSourceIndex + j + m - 1;
        it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcF.find((l < p) ? (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + j + m - 1]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex + j + m - 1]) : (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[l - p]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[l - p]));
        k = ((it_const.isValid() ? it_const.getValueRef() : m));
      }

      if (j + m <= n)
      {
        for (i = 0; i < m - 1; ++i)
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i + j]).toLowerCase() != NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[i]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + i + j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[i])))
            break;

        if (i >= (m - 1))
        {
          a_rFoundStart = a_cSourceIndex + j;
          a_rFoundEnd = a_cSourceIndex + j + i;
          return true;
        }
      }

      j += m_ShiftF;
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>::onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize())
  {
    Tuint i, j = 0;
    Tuint k, l, p = a_cSourceIndex + 1;
    Tuint n = a_cSourceLength;
    Tuint m = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    while (j < n)
    {
      l = j + m;
      typename CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::TCharacterTable::TIteratorConst it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcB.find((l <= p) ? (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - j - m + 1]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex - j - m + 1]) : (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m + p - l]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m + p - l]));
      k = ((it_const.isValid() ? it_const.getValueRef() : m));

      while (k != 0)
      {
        // First step.
        j += k;
        l = j + m;
        it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcB.find((l <= p) ? (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - j - m + 1]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex - j - m + 1]) : (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m + p - l]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m + p - l]));
        k = ((it_const.isValid() ? it_const.getValueRef() : m));

        // Second step.
        j += k;
        l = j + m;
        it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcB.find((l <= p) ? (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - j - m + 1]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex - j - m + 1]) : (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m + p - l]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m + p - l]));
        k = ((it_const.isValid() ? it_const.getValueRef() : m));

        // Third step.
        j += k;
        l = j + m;
        it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcB.find((l <= p) ? (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - j - m + 1]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex - j - m + 1]) : (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m + p - l]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m + p - l]));
        k = ((it_const.isValid() ? it_const.getValueRef() : m));
      }

      if (j + m <= n)
      {
        for (i = 0; i < m - 1; ++i)
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i - j]).toLowerCase() != NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - i - j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1])))
            break;

        if (i >= (m - 1))
        {
          a_rFoundStart = a_cSourceIndex - j - i;
          a_rFoundEnd = a_cSourceIndex - j;
          return true;
        }
      }

      j += m_ShiftB;
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_Archive>
inline Tbool CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::CStringSearchTunedBM")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_ShiftF, STR("m_ShiftF")));
    CHECK(a_rArchive.doValue(m_ShiftB, STR("m_ShiftB")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline void CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>::swap(CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>&)(*this), (CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>&)a_rInstance);
  NAlgorithms::NCommon::swap(m_ShiftF, a_rInstance.m_ShiftF);
  NAlgorithms::NCommon::swap(m_ShiftB, a_rInstance.m_ShiftB);
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
