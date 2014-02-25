/*!
 *  \file    CStringSearchMorrisPratt.inl Morris-Pratt (sub)string searching
 *           algorithm.
 *  \brief   Morris-Pratt (sub)string searching algorithm class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Morris-Pratt (sub)string searching algorithm class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   14.01.2010 03:08:06

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
#ifndef __CSTRINGSEARCHMORRISPRATT_INL__
#define __CSTRINGSEARCHMORRISPRATT_INL__
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
inline CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::CStringSearchMorrisPratt(const Tbool a_cIgnoreCaseFlag/* = false */) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::CStringSearchMorrisPratt(const CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>& a_crInstance) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::~CStringSearchMorrisPratt()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>& CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::operator = (const CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::set(const CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  return (IStringSearch<T_SourceStringType, T_PatternStringType>::set(a_crInstance) && m_Pattern.set(a_crInstance.m_Pattern) && m_NextF.set(a_crInstance.m_NextF) && m_NextB.set(a_crInstance.m_NextB));
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  if (NDetails::CStringSearchHelper::copyPattern(m_Pattern, a_crPattern, a_cPatternIndex, a_cPatternLength))
  {
    Tuint i, j, m = m_Pattern.getSize();

    // Setup pattern shift values.
    if (!m_NextF.resize(m + 1) || !m_NextB.resize(m + 1))
      return false;

    // Calculate forward pattern shift values.
    i = 0;
    j = m_NextF[CONSTU(0)] = NConstants::CConstants::uintMax;
    while (i < m)
    {
      while (j != NConstants::CConstants::uintMax)
      {
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(m_Pattern[i]).toLowerCase() == NDepth::NString::CCharacter(m_Pattern[j]).toLowerCase()) : (m_Pattern[i] == m_Pattern[j]))
          break;

        j = m_NextF[j];
      }

      m_NextF[++i] = ++j;
    }

    // Calculate backward pattern shift values.
    i = 0;
    j = m_NextB[CONSTU(0)] = NConstants::CConstants::uintMax;
    while (i < m)
    {
      while (j != NConstants::CConstants::uintMax)
      {
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(m_Pattern[m - i - 1]).toLowerCase() == NDepth::NString::CCharacter(m_Pattern[m - j - 1]).toLowerCase()) : (m_Pattern[m - i - 1] == m_Pattern[m - j - 1]))
          break;

        j = m_NextB[j];
      }

      m_NextB[++i] = ++j;
    }

    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= m_Pattern.getSize())
  {
    Tuint i, j;
    Tuint n = a_cSourceLength;
    Tuint m = m_Pattern.getSize();

    i = j = 0;
    while (j < n)
    {
      while (i != NConstants::CConstants::uintMax)
      {
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + j]).toLowerCase() == NDepth::NString::CCharacter(m_Pattern[i]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + j]) == ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[i])))
          break;

        i = m_NextF[i];
      }
      ++i;
      ++j;
      if (i >= m)
      {
        a_rFoundStart = a_cSourceIndex + j - i;
        a_rFoundEnd = a_cSourceIndex + j - 1;
        return true;
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= m_Pattern.getSize())
  {
    Tuint i, j;
    Tuint n = a_cSourceLength;
    Tuint m = m_Pattern.getSize();

    i = j = 0;
    while (j < n)
    {
      while (i != NConstants::CConstants::uintMax)
      {
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - j]).toLowerCase() == NDepth::NString::CCharacter(m_Pattern[m - i - 1]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - j]) == ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[m - i - 1])))
          break;

        i = m_NextB[i];
      }
      ++i;
      ++j;
      if (i >= m)
      {
        a_rFoundStart = a_cSourceIndex - j + 1;
        a_rFoundEnd = a_cSourceIndex - j + i;
        return true;
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::onClose()
{ CALL
  return (m_Pattern.clear() && m_NextF.clear() && m_NextB.clear());
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_Archive>
inline Tbool CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::CStringSearchMorrisPratt")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_Pattern, STR("m_Pattern")));
    CHECK(a_rArchive.doValue(m_NextF, STR("m_NextF")));
    CHECK(a_rArchive.doValue(m_NextB, STR("m_NextB")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline void CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::swap(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), (IStringSearch<T_SourceStringType, T_PatternStringType>&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Pattern, a_rInstance.m_Pattern);
  NAlgorithms::NCommon::swap(m_NextF, a_rInstance.m_NextF);
  NAlgorithms::NCommon::swap(m_NextB, a_rInstance.m_NextB);
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
