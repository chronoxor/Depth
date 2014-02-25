/*!
 *  \file    CStringSearchBoyerMoore.inl Boyer-Moore (sub)string searching
 *           algorithm.
 *  \brief   Boyer-Moore (sub)string searching algorithm class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    08.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Boyer-Moore (sub)string searching algorithm class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   08.02.2010 02:24:50

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
#ifndef __CSTRINGSEARCHBOYERMOORE_INL__
#define __CSTRINGSEARCHBOYERMOORE_INL__
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
inline CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::CStringSearchBoyerMoore(const Tbool a_cIgnoreCaseFlag/* = false */) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::CStringSearchBoyerMoore(const CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>& a_crInstance) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::~CStringSearchBoyerMoore()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>& CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::operator = (const CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::set(const CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  return (IStringSearch<T_SourceStringType, T_PatternStringType>::set(a_crInstance) && m_Pattern.set(a_crInstance.m_Pattern) && m_BMGsF.set(a_crInstance.m_BMGsF) && m_BMGsB.set(a_crInstance.m_BMGsB) && m_BMBcF.set(a_crInstance.m_BMBcF) && m_BMBcB.set(a_crInstance.m_BMBcB));
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  if (NDetails::CStringSearchHelper::copyPattern(m_Pattern, a_crPattern, a_cPatternIndex, a_cPatternLength))
    return (calculateGoodSuffixShift(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag(), m_Pattern, m_BMGsF, m_BMGsB) && calculateBadCharacterShift(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag(), m_Pattern, m_BMBcF, m_BMBcB));
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= m_Pattern.getSize())
  {
    Tuint i, j = 0;
    Tuint n = a_cSourceLength;
    Tuint m = m_Pattern.getSize();

    while (j <= n - m)
    {
      for (i = m - 1; /* i >= 0 */ ; --i)
      {
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i + j]).toLowerCase() != NDepth::NString::CCharacter(m_Pattern[i]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + i + j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[i])))
          break;
        if (i == 0)
        {
          i = m;
          break;
        }
      }
      if (i >= m)
      {
        a_rFoundStart = a_cSourceIndex + j;
        a_rFoundEnd = a_cSourceIndex + j + i - 1;
        j += m_BMGsF[CONSTU(0)];
        return true;
      }
      else
      {
        TCharacterTable::TIteratorConst it_const = m_BMBcF.find(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i + j]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex + i + j]);
        j += NAlgorithms::NCommon::max(m_BMGsF[i], ((it_const.isValid() ? it_const.getValueRef() : m) - m + 1 + i));
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= m_Pattern.getSize())
  {
    Tuint i, j = 0;
    Tuint n = a_cSourceLength;
    Tuint m = m_Pattern.getSize();

    while (j <= n - m)
    {
      for (i = m - 1; /* i >= 0 */ ; --i)
      {
        if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i - j]).toLowerCase() != NDepth::NString::CCharacter(m_Pattern[m - i - 1]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - i - j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[m - i - 1])))
          break;
        if (i == 0)
        {
          i = m;
          break;
        }
      }
      if (i >= m)
      {
        a_rFoundStart = a_cSourceIndex - j - i + 1;
        a_rFoundEnd = a_cSourceIndex - j;
        j += m_BMGsB[CONSTU(0)];
        return true;
      }
      else
      {
        TCharacterTable::TIteratorConst it_const = m_BMBcB.find(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i - j]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex - i - j]);
        j += NAlgorithms::NCommon::max(m_BMGsB[i], ((it_const.isValid() ? it_const.getValueRef() : m) - m + 1 + i));
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::onClose()
{ CALL
  return (m_Pattern.clear() && m_BMGsF.clear() && m_BMGsB.clear() && m_BMBcF.clear() && m_BMBcB.clear());
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::calculateGoodSuffixShift(const Tbool a_cIgnoreCaseFlag, const NDepth::NString::CString& a_crPattern, NContainers::CArray<Tuint>& a_rBMGsF, NContainers::CArray<Tuint>& a_rBMGsB)
{ CALL
  Tuint i, j, m = a_crPattern.getSize();
  NContainers::CArray<Tuint> suffixesF, suffixesB;

  // Try to calculate suffixes for the given string pattern.
  if (!calculateSuffixes(a_cIgnoreCaseFlag, a_crPattern, suffixesF, suffixesB))
    return false;

  // Setup good-suffix shift values.
  if (!a_rBMGsF.resize(m) || !a_rBMGsB.resize(m))
    return false;

   // Calculate forward good-suffix shift values.
   for (i = 0; i < m; ++i)
     a_rBMGsF[i] = m;
   j = 0;
   for (i = m - 1; /* i >= 0 */ ; --i)
   {
     if (suffixesF[i] == i + 1)
       for (; j < m - 1 - i; ++j)
         if (a_rBMGsF[j] == m)
           a_rBMGsF[j] = m - 1 - i;
     if (i == 0)
       break;
   }
   if (m > 1)
     for (i = 0; i <= m - 2; ++i)
       a_rBMGsF[m - 1 - suffixesF[i]] = m - 1 - i;

   // Calculate backward good-suffix shift values.
   for (i = 0; i < m; ++i)
     a_rBMGsB[i] = m;
   j = 0;
   for (i = m - 1; /* i >= 0 */ ; --i)
   {
     if (suffixesB[i] == i + 1)
       for (; j < m - 1 - i; ++j)
         if (a_rBMGsB[j] == m)
           a_rBMGsB[j] = m - 1 - i;
     if (i == 0)
       break;
   }
   if (m > 1)
     for (i = 0; i <= m - 2; ++i)
       a_rBMGsB[m - 1 - suffixesB[i]] = m - 1 - i;

   return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::calculateBadCharacterShift(const Tbool a_cIgnoreCaseFlag, const NDepth::NString::CString& a_crPattern, TCharacterTable& a_rBMBcF, TCharacterTable& a_rBMBcB)
{ CALL
  Tuint i, m = a_crPattern.getSize();

  // Allocate enough space for bad-character shift values.
  if (!a_rBMBcF.resize(256) || !a_rBMBcB.resize(256))
    return false;

  // Calculate forward bad-character shift values.
  for (i = 0; i < m - 1; ++i)
  {
    Tuint key = (a_cIgnoreCaseFlag ? NDepth::NString::CCharacter(a_crPattern[i]).toLowerCase().getUnsigned() : (Tuint)a_crPattern[i]);
    TCharacterTable::TIterator it = a_rBMBcF.find(key);
    if (it.isValid())
      it.getValueRef() = (m - i - 1);
    else
      if (!a_rBMBcF.insert(key, (m - i - 1)))
        return false;
  }

  // Calculate backward bad-character shift values.
  for (i = 0; i < m - 1; ++i)
  {
    Tuint key = (a_cIgnoreCaseFlag ? NDepth::NString::CCharacter(a_crPattern[m - i - 1]).toLowerCase().getUnsigned() : (Tuint)a_crPattern[m - i - 1]);
    TCharacterTable::TIterator it = a_rBMBcB.find(key);
    if (it.isValid())
      it.getValueRef() = (m - i - 1);
    else
      if (!a_rBMBcB.insert(key, (m - i - 1)))
        return false;
  }

  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::calculateSuffixes(const Tbool a_cIgnoreCaseFlag, const NDepth::NString::CString& a_crPattern, NContainers::CArray<Tuint>& a_rBMSuffixesF, NContainers::CArray<Tuint>& a_rBMSuffixesB)
{ CALL
  Tuint f = 0, g, i, m = a_crPattern.getSize();

  // Setup suffixes for the given string pattern.
  if (!a_rBMSuffixesF.resize(m) || !a_rBMSuffixesB.resize(m))
    return false;

  // Calculate forward suffixes for the given string pattern.
  a_rBMSuffixesF[m - 1] = m;
  g = m - 1;
  if (m > 1)
  {
    for (i = m - 2; /* i >= 0 */ ; --i)
    {
      if (((g == NConstants::CConstants::uintMax) || (i > g)) && (a_rBMSuffixesF[i + m - 1 - f] < ((g == NConstants::CConstants::uintMax) ? (i - 1) : (i - g))))
        a_rBMSuffixesF[i] = a_rBMSuffixesF[i + m - 1 - f];
      else
      {
        if ((g != NConstants::CConstants::uintMax) && (i < g))
          g = i;
        f = i;
        while ((g != NConstants::CConstants::uintMax) && /* (g >= 0) && */ (a_cIgnoreCaseFlag ? (NDepth::NString::CCharacter(a_crPattern[g]).toLowerCase() == NDepth::NString::CCharacter(a_crPattern[g + m - 1 - f]).toLowerCase()) : (a_crPattern[g] == a_crPattern[g + m - 1 - f])))
        {
          if (g == 0)
            g = NConstants::CConstants::uintMax;
          else
            --g;
        }
        a_rBMSuffixesF[i] = ((g == NConstants::CConstants::uintMax) ? (f + 1) : (f - g));
      }
      if (i == 0)
        break;
    }
  }

  // Calculate backward suffixes for the given string pattern.
  a_rBMSuffixesB[m - 1] = m;
  g = m - 1;
  if (m > 1)
  {
    for (i = m - 2; /* i >= 0 */ ; --i)
    {
      if (((g == NConstants::CConstants::uintMax) || (i > g)) && (a_rBMSuffixesB[i + m - 1 - f] < ((g == NConstants::CConstants::uintMax) ? (i - 1) : (i - g))))
        a_rBMSuffixesB[i] = a_rBMSuffixesB[i + m - 1 - f];
      else
      {
        if ((g != NConstants::CConstants::uintMax) && (i < g))
          g = i;
        f = i;
        while ((g != NConstants::CConstants::uintMax) && /* (g >= 0) && */ (a_cIgnoreCaseFlag ? (NDepth::NString::CCharacter(a_crPattern[m - g - 1]).toLowerCase() == NDepth::NString::CCharacter(a_crPattern[f - g]).toLowerCase()) : (a_crPattern[m - g - 1] == a_crPattern[f - g])))
        {
          if (g == 0)
            g = NConstants::CConstants::uintMax;
          else
            --g;
        }
        a_rBMSuffixesB[i] = ((g == NConstants::CConstants::uintMax) ? (f + 1) : (f - g));
      }
      if (i == 0)
        break;
    }
  }

  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_Archive>
inline Tbool CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::CStringSearchBoyerMoore")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_Pattern, STR("m_Pattern")));
    CHECK(a_rArchive.doValue(m_BMGsF, STR("m_BMGsF")));
    CHECK(a_rArchive.doValue(m_BMGsB, STR("m_BMGsB")));
    CHECK(a_rArchive.doValue(m_BMBcF, STR("m_BMBcF")));
    CHECK(a_rArchive.doValue(m_BMBcB, STR("m_BMBcB")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline void CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::swap(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), (IStringSearch<T_SourceStringType, T_PatternStringType>&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Pattern, a_rInstance.m_Pattern);
  NAlgorithms::NCommon::swap(m_BMGsF, a_rInstance.m_BMGsF);
  NAlgorithms::NCommon::swap(m_BMGsB, a_rInstance.m_BMGsB);
  NAlgorithms::NCommon::swap(m_BMBcF, a_rInstance.m_BMBcF);
  NAlgorithms::NCommon::swap(m_BMBcB, a_rInstance.m_BMBcB);
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
