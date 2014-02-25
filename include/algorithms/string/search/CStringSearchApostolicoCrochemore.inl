/*!
 *  \file    CStringSearchApostolicoCrochemore.inl Apostolico-Crochemore
 *           (sub)string searching algorithm.
 *  \brief   Apostolico-Crochemore (sub)string searching algorithm class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Apostolico-Crochemore (sub)string searching algorithm class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   14.01.2010 02:12:25

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
#ifndef __CSTRINGSEARCHAPOSTOLICOCROCHEMORE_INL__
#define __CSTRINGSEARCHAPOSTOLICOCROCHEMORE_INL__
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
inline CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>::CStringSearchApostolicoCrochemore(const Tbool a_cIgnoreCaseFlag/* = false */) :
  CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>::CStringSearchApostolicoCrochemore(const CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>& a_crInstance) :
  CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>(a_crInstance)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>::~CStringSearchApostolicoCrochemore()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>& CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>::operator = (const CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>::set(const CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  if (CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>::set(a_crInstance))
  {
    m_EllF = a_crInstance.m_EllF;
    m_EllB = a_crInstance.m_EllB;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>::onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  if (CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>::onInitialize(a_crPattern, a_cPatternIndex, a_cPatternLength))
  {
    Tuint i, m = CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    // Calculate forward ell value.
    m_EllF = 0;
    for (i = 1; i < m; ++i)
    {
      if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[i - 1]).toLowerCase() == NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[i]).toLowerCase()) : (CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[i - 1] == CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[i]))
        m_EllF = i;
      else
        break;
    }

    // Calculate backward ell value.
    m_EllB = 0;
    for (i = 1; i < m; ++i)
    {
      if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i]).toLowerCase() == NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1]).toLowerCase()) : (CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i] == CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1]))
        m_EllB = i;
      else
        break;
    }

    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>::onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize())
  {
    Tuint i, j, k;
    Tuint n = a_cSourceLength;
    Tuint m = CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    i = m_EllF;
    j = k = 0;
    while (j <= n - m)
    {
      while (i < m)
      {
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i + j]).toLowerCase() != NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[i]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + i + j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[i])))
          break;

        ++i;
      }
      if (i >= m)
      {
        while (k < m_EllF)
        {
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + j + k]).toLowerCase() != NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[k]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + j + k]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[k])))
            break;

          ++k;
        }
        if (k >= m_EllF)
        {
          a_rFoundStart = a_cSourceIndex + j;
          a_rFoundEnd = a_cSourceIndex + j + i - 1;
          return true;
        }
      }

      if (CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF[i] == NConstants::CConstants::uintMax)
        j += (i + 1);
      else
        j += (i - CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF[i]);

      if (i == m_EllF)
        k = (k > 0) ? (k - 1) : 0;
      else
      {
        if ((CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF[i] <= m_EllF) || (CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF[i] == NConstants::CConstants::uintMax))
        {
          k = (CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF[i] == NConstants::CConstants::uintMax) ? 0 : CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF[i];
          i = m_EllF;
        }
        else
        {
          k = m_EllF;
          i = CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF[i];
        }
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>::onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize())
  {
    Tuint i, j, k;
    Tuint n = a_cSourceLength;
    Tuint m = CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    i = m_EllB;
    j = k = 0;
    while (j <= n - m)
    {
      while (i < m)
      {
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i - j]).toLowerCase() != NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - i - j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1])))
          break;

        ++i;
      }
      if (i >= m)
      {
        while (k < m_EllB)
        {
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - j - k]).toLowerCase() != NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - k - 1]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - j - k]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - k - 1])))
            break;

          ++k;
        }
        if (k >= m_EllB)
        {
          a_rFoundStart = a_cSourceIndex - j - i + 1;
          a_rFoundEnd = a_cSourceIndex - j;
          return true;
        }
      }

      if (CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB[i] == NConstants::CConstants::uintMax)
        j += (i + 1);
      else
        j += (i - CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB[i]);

      if (i == m_EllB)
        k = (k > 0) ? (k - 1) : 0;
      else
      {
        if ((CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB[i] <= m_EllB) || (CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB[i] == NConstants::CConstants::uintMax))
        {
          k = (CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB[i] == NConstants::CConstants::uintMax) ? 0 : CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB[i];
          i = m_EllB;
        }
        else
        {
          k = m_EllB;
          i = CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB[i];
        }
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_Archive>
inline Tbool CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::CStringSearchApostolicoCrochemore")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_EllF, STR("m_EllF")));
    CHECK(a_rArchive.doValue(m_EllB, STR("m_EllB")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline void CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>::swap(CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>&)(*this), (CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>&)a_rInstance);
  NAlgorithms::NCommon::swap(m_EllF, a_rInstance.m_EllF);
  NAlgorithms::NCommon::swap(m_EllB, a_rInstance.m_EllB);
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
