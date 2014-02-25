/*!
 *  \file    CStringSearchKnuthMorrisPratt.inl Knuth-Morris-Pratt (sub)string
 *           searching algorithm.
 *  \brief   Knuth-Morris-Pratt (sub)string searching algorithm class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Knuth-Morris-Pratt (sub)string searching algorithm class (inline).

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
#ifndef __CSTRINGSEARCHKNUTHMORRISPRATT_INL__
#define __CSTRINGSEARCHKNUTHMORRISPRATT_INL__
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
inline CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>::CStringSearchKnuthMorrisPratt(const Tbool a_cIgnoreCaseFlag/* = false */) :
  CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>::CStringSearchKnuthMorrisPratt(const CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>& a_crInstance) :
  CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>(a_crInstance)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>::~CStringSearchKnuthMorrisPratt()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>& CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>::operator = (const CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>::set(const CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  return CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>::onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  if (NDetails::CStringSearchHelper::copyPattern(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern, a_crPattern, a_cPatternIndex, a_cPatternLength))
  {
    Tuint i, j, m = CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    // Setup pattern shift values.
    if (!CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF.resize(m + 1) || !CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB.resize(m + 1))
      return false;

    // Calculate forward pattern shift values.
    i = 0;
    j = CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF[CONSTU(0)] = NConstants::CConstants::uintMax;
    while (i < m)
    {
      while (j != NConstants::CConstants::uintMax)
      {
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[i]).toLowerCase() == NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[j]).toLowerCase()) : (CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[i] == CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[j]))
          break;

        j = CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF[j];
      }

      ++i;
      ++j;

      if (i == m)
      {
        CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF[i] = j;
        break;
      }

      if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[i]).toLowerCase() == NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[j]).toLowerCase()) : (CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[i] == CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[j]))
        CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF[i] = CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF[j];
      else
        CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextF[i] = j;
    }

    // Calculate backward pattern shift values.
    i = 0;
    j = CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB[CONSTU(0)] = NConstants::CConstants::uintMax;
    while (i < m)
    {
      while (j != NConstants::CConstants::uintMax)
      {
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1]).toLowerCase() == NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - j - 1]).toLowerCase()) : (CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1] == CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - j - 1]))
          break;

        j = CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB[j];
      }

      ++i;
      ++j;

      if (i == m)
      {
        CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB[i] = j;
        break;
      }

      if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1]).toLowerCase() == NDepth::NString::CCharacter(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - j - 1]).toLowerCase()) : (CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1] == CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_Pattern[m - j - 1]))
        CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB[i] = CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB[j];
      else
        CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>::m_NextB[i] = j;
    }

    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_Archive>
inline Tbool CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::CStringSearchKnuthMorrisPratt")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline void CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>::swap(CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>&)(*this), (CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>&)a_rInstance);
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
