/*!
 *  \file    CStringSearchNotSoNaive.inl Not So Naive (sub)string searching
 *           algorithm.
 *  \brief   Not So Naive (sub)string searching algorithm class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Not So Naive (sub)string searching algorithm class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   15.01.2010 03:48:42

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
#ifndef __CSTRINGSEARCHNOTSONAIVE_INL__
#define __CSTRINGSEARCHNOTSONAIVE_INL__
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
inline CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>::CStringSearchNotSoNaive(const Tbool a_cIgnoreCaseFlag/* = false */) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>::CStringSearchNotSoNaive(const CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>& a_crInstance) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>::~CStringSearchNotSoNaive()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>& CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>::operator = (const CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>::set(const CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  if (IStringSearch<T_SourceStringType, T_PatternStringType>::set(a_crInstance) && m_Pattern.set(a_crInstance.m_Pattern))
  {
    m_EllF = a_crInstance.m_EllF;
    m_EllB = a_crInstance.m_EllB;
    m_KF = a_crInstance.m_KF;
    m_KB = a_crInstance.m_KB;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>::onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  if (NDetails::CStringSearchHelper::copyPattern(m_Pattern, a_crPattern, a_cPatternIndex, a_cPatternLength))
  {
    Tuint m = m_Pattern.getSize();

    // Calculate forward searching parameters.
    if ((m > 1) && (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(m_Pattern[CONSTU(0)]).toLowerCase() == NDepth::NString::CCharacter(m_Pattern[CONSTU(1)]).toLowerCase()) : (m_Pattern[CONSTU(0)] == m_Pattern[CONSTU(1)])))
    {
      m_EllF = 1;
      m_KF = 2;
    }
    else
    {
      m_EllF = 2;
      m_KF = 1;
    }

    // Calculate backward searching parameters.
    if ((m > 1) && (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(m_Pattern[m - 1]).toLowerCase() == NDepth::NString::CCharacter(m_Pattern[m - 2]).toLowerCase()) : (m_Pattern[m - 1] == m_Pattern[m - 2])))
    {
      m_EllB = 1;
      m_KB = 2;
    }
    else
    {
      m_EllB = 2;
      m_KB = 1;
    }

    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>::onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= m_Pattern.getSize())
  {
    Tuint i, j;
    Tuint n = a_cSourceLength;
    Tuint m = m_Pattern.getSize();

    // Special case for single character pattern.
    if (m == 1)
    {
      for (i = 0; i < n; ++i)
      {
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i]).toLowerCase() == NDepth::NString::CCharacter(m_Pattern[CONSTU(0)]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + i]) == ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[CONSTU(0)])))
        {
          a_rFoundStart = a_cSourceIndex + i;
          a_rFoundEnd = a_cSourceIndex + i;
          return true;
        }
      }
      return false;
    }

    j = 0;
    while (j <= (n - m))
    {
      Tbool skip = false;
      if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + j + 1]).toLowerCase() != NDepth::NString::CCharacter(m_Pattern[CONSTU(1)]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + j + 1]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[CONSTU(1)])))
      {
        j += m_KF;
        skip = true;
      }

      if (!skip)
      {
        for (i = 2; i < m; ++i)
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i + j]).toLowerCase() != NDepth::NString::CCharacter(m_Pattern[i]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + i + j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[i])))
            break;

        if (i >= m)
        {
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + j]).toLowerCase() != NDepth::NString::CCharacter(m_Pattern[CONSTU(0)]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[CONSTU(0)])))
            skip = true;

          if (!skip)
          {
            a_rFoundStart = a_cSourceIndex + j;
            a_rFoundEnd = a_cSourceIndex + j + i - 1;
            return true;
          }
        }

        j += m_EllF;
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>::onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= m_Pattern.getSize())
  {
    Tuint i, j;
    Tuint n = a_cSourceLength;
    Tuint m = m_Pattern.getSize();

    // Special case for single character pattern.
    if (m == 1)
    {
      for (i = 0; i < n; ++i)
      {
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i]).toLowerCase() == NDepth::NString::CCharacter(m_Pattern[CONSTU(0)]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - i]) == ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[CONSTU(0)])))
        {
          a_rFoundStart = a_cSourceIndex - i;
          a_rFoundEnd = a_cSourceIndex - i;
          return true;
        }
      }
      return false;
    }

    j = 0;
    while (j <= (n - m))
    {
      Tbool skip = false;
      if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - j - 1]).toLowerCase() != NDepth::NString::CCharacter(m_Pattern[m - 2]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - j - 1]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[m - 2])))
      {
        j += m_KB;
        skip = true;
      }

      if (!skip)
      {
        for (i = 2; i < m; ++i)
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i - j]).toLowerCase() != NDepth::NString::CCharacter(m_Pattern[m - i - 1]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - i - j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[m - i - 1])))
            break;

        if (i >= m)
        {
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - j]).toLowerCase() != NDepth::NString::CCharacter(m_Pattern[m - 1]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[m - 1])))
            skip = true;

          if (!skip)
          {
            a_rFoundStart = a_cSourceIndex - j - i + 1;
            a_rFoundEnd = a_cSourceIndex - j;
            return true;
          }
        }

        j += m_EllB;
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>::onClose()
{ CALL
  return m_Pattern.clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_Archive>
inline Tbool CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::CStringSearchNotSoNaive")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_Pattern, STR("m_Pattern")));
    CHECK(a_rArchive.doValue(m_EllF, STR("m_EllF")));
    CHECK(a_rArchive.doValue(m_EllB, STR("m_EllB")));
    CHECK(a_rArchive.doValue(m_KF, STR("m_KF")));
    CHECK(a_rArchive.doValue(m_KB, STR("m_KB")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline void CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>::swap(CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), (IStringSearch<T_SourceStringType, T_PatternStringType>&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Pattern, a_rInstance.m_Pattern);
  NAlgorithms::NCommon::swap(m_EllF, a_rInstance.m_EllF);
  NAlgorithms::NCommon::swap(m_EllB, a_rInstance.m_EllB);
  NAlgorithms::NCommon::swap(m_KF, a_rInstance.m_KF);
  NAlgorithms::NCommon::swap(m_KB, a_rInstance.m_KB);
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
