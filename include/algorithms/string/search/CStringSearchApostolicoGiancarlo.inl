/*!
 *  \file    CStringSearchApostolicoGiancarlo.inl Apostolico-Giancarlo
 *           (sub)string searching algorithm.
 *  \brief   Apostolico-Giancarlo (sub)string searching algorithm class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Apostolico-Giancarlo (sub)string searching algorithm class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   12.02.2010 22:42:31

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
#ifndef __CSTRINGSEARCHAPOSTOLICOGIANCARLO_INL__
#define __CSTRINGSEARCHAPOSTOLICOGIANCARLO_INL__
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
inline CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>::CStringSearchApostolicoGiancarlo(const Tbool a_cIgnoreCaseFlag/* = false */) :
  CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>::CStringSearchApostolicoGiancarlo(const CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>& a_crInstance) :
  CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>::~CStringSearchApostolicoGiancarlo()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>& CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>::operator = (const CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>::set(const CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  return (CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::set(a_crInstance) && m_SkipF.set(a_crInstance.m_SkipF) && m_SkipB.set(a_crInstance.m_SkipB) && m_SuffixesF.set(a_crInstance.m_SuffixesF) && m_SuffixesB.set(a_crInstance.m_SuffixesB));
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>::onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  if (CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::onInitialize(a_crPattern, a_cPatternIndex, a_cPatternLength) && CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::calculateGoodSuffixShift(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag(), CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern, m_SuffixesF, m_SuffixesB))
  {
    Tuint m = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    // Setup skip values.
    if (!m_SkipF.resize(m) || !m_SkipB.resize(m))
      return false;

    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>::onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize())
  {
    Tuint i, j = 0;
    Tuint k, s, shift;
    Tuint n = a_cSourceLength;
    Tuint m = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    // Clear skip values.
    for (Tuint i = 0; i < m; ++i)
      m_SkipF[i] = 0;

    while (j <= n - m)
    {
      i = m - 1;
      while (i < m)
      {
        k = m_SkipF[i];
        s = m_SuffixesF[i];
        if (k > 0)
        {
          if (k > s)
          {
            if (i + 1 == s)
            {
              i = m;
              break;
            }
            else
            {
              if (s > i)
                i = m;
              else
                i -= s;
            }
            break;
          }
          else
          {
            if (k > i)
              i = m;
            else
              i -= k;
            if (k < s)
              break;
          }
        }
        else
        {
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i + j]).toLowerCase() == NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[i]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + i + j]) == ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[i])))
          {
            if (i > 0)
              --i;
            else
            {
              i = m;
              break;
            }
          }
          else
            break;
        }
      }
      if (i >= m)
      {
        a_rFoundStart = a_cSourceIndex + j;
        a_rFoundEnd = a_cSourceIndex + j + i - 1;
        m_SkipF[m - 1] = m;
        shift = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMGsF[CONSTU(0)];
        return true;
      }
      else
      {
        m_SkipF[m - 1] = m - 1 - i;
        typename CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::TCharacterTable::TIteratorConst it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcF.find(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i + j]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex + i + j]);
        shift = NAlgorithms::NCommon::max(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMGsF[i], ((it_const.isValid() ? it_const.getValueRef() : m) - m + 1 + i));
      }
      j += shift;
      for (Tuint i = 0; i < (m - shift); ++i)
        m_SkipF[i] = m_SkipF[i + shift];
      for (Tuint i = 0; i < shift; ++i)
        m_SkipF[i + m - shift] = 0;
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>::onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize())
  {
    Tuint i, j = 0;
    Tuint k, s, shift;
    Tuint n = a_cSourceLength;
    Tuint m = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    // Clear skip values.
    for (Tuint i = 0; i < m; ++i)
      m_SkipB[i] = 0;

    while (j <= n - m)
    {
      i = m - 1;
      while (i < m)
      {
        k = m_SkipF[i];
        s = m_SuffixesF[i];
        if (k > 0)
        {
          if (k > s)
          {
            if (i + 1 == s)
            {
              i = m;
              break;
            }
            else
            {
              if (s > i)
                i = m;
              else
                i -= s;
            }
            break;
          }
          else
          {
            if (k > i)
              i = m;
            else
              i -= k;
            if (k < s)
              break;
          }
        }
        else
        {
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i - j]).toLowerCase() == NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - i - j]) == ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1])))
          {
            if (i > 0)
              --i;
            else
            {
              i = m;
              break;
            }
          }
          else
            break;
        }
      }
      if (i >= m)
      {
        a_rFoundStart = a_cSourceIndex - j - i + 1;
        a_rFoundEnd = a_cSourceIndex - j;
        m_SkipB[m - 1] = m;
        shift = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMGsB[CONSTU(0)];
        return true;
      }
      else
      {
        m_SkipB[m - 1] = m - 1 - i;
        typename CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::TCharacterTable::TIteratorConst it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcB.find(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i - j]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex - i - j]);
        shift = NAlgorithms::NCommon::max(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMGsB[i], ((it_const.isValid() ? it_const.getValueRef() : m) - m + 1 + i));
      }
      j += shift;
      for (Tuint i = 0; i < (m - shift); ++i)
        m_SkipB[i] = m_SkipB[i + shift];
      for (Tuint i = 0; i < shift; ++i)
        m_SkipB[i + m - shift] = 0;
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>::onClose()
{ CALL
  return (CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::onClose() && m_SkipF.clear() && m_SkipB.clear() && m_SuffixesF.clear() && m_SuffixesB.clear());
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_Archive>
inline Tbool CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::CStringSearchApostolicoGiancarlo")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_SkipF, STR("m_SkipF")));
    CHECK(a_rArchive.doValue(m_SkipB, STR("m_SkipB")));
    CHECK(a_rArchive.doValue(m_SuffixesF, STR("SuffixesF")));
    CHECK(a_rArchive.doValue(m_SuffixesB, STR("SuffixesB")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline void CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>::swap(CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>&)(*this), (CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>&)a_rInstance);
  NAlgorithms::NCommon::swap(m_SkipF, a_rInstance.m_SkipF);
  NAlgorithms::NCommon::swap(m_SkipB, a_rInstance.m_SkipB);
  NAlgorithms::NCommon::swap(m_SuffixesF, a_rInstance.m_SuffixesF);
  NAlgorithms::NCommon::swap(m_SuffixesB, a_rInstance.m_SuffixesB);
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
