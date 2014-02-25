/*!
 *  \file    CStringSearchTurboBM.inl Turbo Boyer-Moore (sub)string searching
 *           algorithm.
 *  \brief   Turbo Boyer-Moore (sub)string searching algorithm class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Turbo Boyer-Moore (sub)string searching algorithm class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   11.02.2010 03:43:22

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
#ifndef __CSTRINGSEARCHTURBOBM_INL__
#define __CSTRINGSEARCHTURBOBM_INL__
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
inline CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>::CStringSearchTurboBM(const Tbool a_cIgnoreCaseFlag/* = false */) :
  CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>::CStringSearchTurboBM(const CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>& a_crInstance) :
  CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>::~CStringSearchTurboBM()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>& CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>::operator = (const CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>::set(const CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  return CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>::onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize())
  {
    Tuint i, j, u, v;
    Tuint shift, bcShift, turboShift;
    Tuint n = a_cSourceLength;
    Tuint m = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    j = u = 0;
    shift = m;
    while (j <= n - m)
    {
      i = m - 1;
      while (/* (i >= 0) && */(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i + j]).toLowerCase() == NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[i]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + i + j]) == ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[i]))))
      {
        if (i == 0)
        {
          i = m;
          break;
        }
        else
        {
          --i;
          if ((u != 0) && (i == (m - 1 - shift)))
          {
            if (i < u)
            {
              i = m;
              break;
            }
            else
              i -= u;
          }
        }
      }
      if (i >= m)
      {
        a_rFoundStart = a_cSourceIndex + j;
        a_rFoundEnd = a_cSourceIndex + j + i - 1;
        shift = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMGsF[CONSTU(0)];
        u = m - shift;
        return true;
      }
      else
      {
        v = m - 1 - i;
        turboShift = (u >= v) ? (u - v) : 0;

        typename CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::TCharacterTable::TIteratorConst it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcF.find(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i + j]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex + i + j]);
        bcShift = ((it_const.isValid() ? it_const.getValueRef() : m) - m + 1 + i);

        shift = NAlgorithms::NCommon::max(turboShift, bcShift);
        shift = NAlgorithms::NCommon::max(shift, CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMGsF[i]);
        if (shift == CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMGsF[i])
          u = NAlgorithms::NCommon::min(m - shift, v);
        else
        {
          if (turboShift < bcShift)
            shift = NAlgorithms::NCommon::max(shift, u + 1);
          u = 0;
        }
      }
      j += shift;
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>::onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize())
  {
    Tuint i, j, u, v;
    Tuint shift, bcShift, turboShift;
    Tuint n = a_cSourceLength;
    Tuint m = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    j = u = 0;
    shift = m;
    while (j <= n - m)
    {
      i = m - 1;
      while (/* (i >= 0) && */(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i - j]).toLowerCase() == NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - i - j]) == ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1]))))
      {
        if (i == 0)
        {
          i = m;
          break;
        }
        else
        {
          --i;
          if ((u != 0) && (i == (m - 1 - shift)))
          {
            if (i < u)
            {
              i = m;
              break;
            }
            else
              i -= u;
          }
        }
      }
      if (i >= m)
      {
        a_rFoundStart = a_cSourceIndex - j - i + 1;
        a_rFoundEnd = a_cSourceIndex - j;
        shift = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMGsB[CONSTU(0)];
        u = m - shift;
        return true;
      }
      else
      {
        v = m - 1 - i;
        turboShift = (u >= v) ? (u - v) : 0;

        typename CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::TCharacterTable::TIteratorConst it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcB.find(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i - j]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex - i - j]);
        bcShift = ((it_const.isValid() ? it_const.getValueRef() : m) - m + 1 + i);

        shift = NAlgorithms::NCommon::max(turboShift, bcShift);
        shift = NAlgorithms::NCommon::max(shift, CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMGsB[i]);
        if (shift == CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMGsB[i])
          u = NAlgorithms::NCommon::min(m - shift, v);
        else
        {
          if (turboShift < bcShift)
            shift = NAlgorithms::NCommon::max(shift, u + 1);
          u = 0;
        }
      }
      j += shift;
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_Archive>
inline Tbool CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::CStringSearchTurboBM")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline void CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>::swap(CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>&)(*this), (CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>&)a_rInstance);
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
