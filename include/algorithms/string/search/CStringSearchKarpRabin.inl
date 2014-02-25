/*!
 *  \file    CStringSearchKarpRabin.inl Karp-Rabin (sub)string searching
 *           algorithm.
 *  \brief   Karp-Rabin (sub)string searching algorithm class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Karp-Rabin (sub)string searching algorithm class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   13.01.2010 20:00:33

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
#ifndef __CSTRINGSEARCHKARPRABIN_INL__
#define __CSTRINGSEARCHKARPRABIN_INL__
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
inline CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>::CStringSearchKarpRabin(const Tbool a_cIgnoreCaseFlag/* = false */) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>::CStringSearchKarpRabin(const CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>& a_crInstance) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>::~CStringSearchKarpRabin()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>& CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>::operator = (const CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>::set(const CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  if (IStringSearch<T_SourceStringType, T_PatternStringType>::set(a_crInstance) && m_Pattern.set(a_crInstance.m_Pattern))
  {
    m_PatternHashF = a_crInstance.m_PatternHashF;
    m_PatternHashB = a_crInstance.m_PatternHashB;
    m_D = a_crInstance.m_D;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>::onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  if (NDetails::CStringSearchHelper::copyPattern(m_Pattern, a_crPattern, a_cPatternIndex, a_cPatternLength))
  {
    Tuint i;
    Tuint m = m_Pattern.getSize();

    // Computes d = 2^(m-1) with the left-shift operator.
    for (m_D = i = 1; i < m; ++i)
      m_D <<= 1;

    // Calculate forward and backward pattern hash values.
    for (m_PatternHashF = m_PatternHashB = i = 0; i < m; ++i)
    {
      m_PatternHashF = ((m_PatternHashF << 1) + (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(m_Pattern[i]).toLowerCase().getUnsigned() : (Tuint)m_Pattern[i]));
      m_PatternHashB = ((m_PatternHashB << 1) + (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(m_Pattern[m - i - 1]).toLowerCase().getUnsigned() : (Tuint)m_Pattern[m - i - 1]));
    }

    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>::onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= m_Pattern.getSize())
  {
    Tuint i, j;
    Tuint n = a_cSourceLength;
    Tuint m = m_Pattern.getSize();

    // Calculate source hash values.
    Tuint source_hash;
    for (source_hash = i = 0; i < m; ++i)
      source_hash = ((source_hash << 1) + (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex + i]));

    for (j = 0; j <= (n - m); ++j)
    {
      // First compare hashes...
      if (source_hash == m_PatternHashF)
      {
        // Second compare content...
        for (i = 0; i < m; ++i)
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i + j]).toLowerCase() != NDepth::NString::CCharacter(m_Pattern[i]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + i + j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[i])))
            break;

        if (i >= m)
        {
          a_rFoundStart = a_cSourceIndex + j;
          a_rFoundEnd = a_cSourceIndex + j + i - 1;
          return true;
        }
      }

      // Perform rehashing.
      if (j < (n - m))
        source_hash = (((source_hash - (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + j]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex + j]) * m_D) << 1) + (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + j + m]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex + j + m]));
      else
        break;
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>::onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= m_Pattern.getSize())
  {
    Tuint i, j;
    Tuint n = a_cSourceLength;
    Tuint m = m_Pattern.getSize();

    // Calculate source hash values.
    Tuint source_hash;
    for (source_hash = i = 0; i < m; ++i)
      source_hash = ((source_hash << 1) + (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex - i]));

    for (j = 0; j <= (n - m); ++j)
    {
      // First compare hashes...
      if (source_hash == m_PatternHashB)
      {
        // Second compare content...
        for (i = 0; i < m; ++i)
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i - j]).toLowerCase() != NDepth::NString::CCharacter(m_Pattern[m - i - 1]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - i - j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)m_Pattern[m - i - 1])))
            break;

        if (i >= m)
        {
          a_rFoundStart = a_cSourceIndex - j - i + 1;
          a_rFoundEnd = a_cSourceIndex - j;
          return true;
        }
      }

      // Perform rehashing.
      if (j < (n - m))
        source_hash = (((source_hash - (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - j]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex - j]) * m_D) << 1) + (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - j - m]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex - j - m]));
      else
        break;
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>::onClose()
{ CALL
  return m_Pattern.clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_Archive>
inline Tbool CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::CStringSearchKarpRabin")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_Pattern, STR("m_Pattern")));
    CHECK(a_rArchive.doValue(m_PatternHashF, STR("m_PatternHashF")));
    CHECK(a_rArchive.doValue(m_PatternHashB, STR("m_PatternHashB")));
    CHECK(a_rArchive.doValue(m_D, STR("m_D")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline void CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>::swap(CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), (IStringSearch<T_SourceStringType, T_PatternStringType>&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Pattern, a_rInstance.m_Pattern);
  NAlgorithms::NCommon::swap(m_PatternHashF, a_rInstance.m_PatternHashF);
  NAlgorithms::NCommon::swap(m_PatternHashB, a_rInstance.m_PatternHashB);
  NAlgorithms::NCommon::swap(m_D, a_rInstance.m_D);
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
