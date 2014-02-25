/*!
 *  \file    CStringSearchDFA.inl Deterministic Finite Automaton (sub)string
 *           searching algorithm.
 *  \brief   Deterministic Finite Automaton (sub)string searching algorithm class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Deterministic Finite Automaton (sub)string searching algorithm class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   17.02.2010 20:02:34

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
#ifndef __CSTRINGSEARCHDFA_INL__
#define __CSTRINGSEARCHDFA_INL__
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
inline CStringSearchDFA<T_SourceStringType, T_PatternStringType>::CStringSearchDFA(const Tbool a_cIgnoreCaseFlag/* = false */) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchDFA<T_SourceStringType, T_PatternStringType>::CStringSearchDFA(const CStringSearchDFA<T_SourceStringType, T_PatternStringType>& a_crInstance) :
  IStringSearch<T_SourceStringType, T_PatternStringType>(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchDFA<T_SourceStringType, T_PatternStringType>::~CStringSearchDFA()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchDFA<T_SourceStringType, T_PatternStringType>& CStringSearchDFA<T_SourceStringType, T_PatternStringType>::operator = (const CStringSearchDFA<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchDFA<T_SourceStringType, T_PatternStringType>::set(const CStringSearchDFA<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  return (IStringSearch<T_SourceStringType, T_PatternStringType>::set(a_crInstance) && m_Pattern.set(a_crInstance.m_Pattern) && m_DFAF.set(a_crInstance.m_DFAF) && m_DFAB.set(a_crInstance.m_DFAB) && m_Alphabet.set(a_crInstance.m_Alphabet));
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchDFA<T_SourceStringType, T_PatternStringType>::onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  if (NDetails::CStringSearchHelper::copyPattern(m_Pattern, a_crPattern, a_cPatternIndex, a_cPatternLength))
  {
    Tuint i, j, key, m = m_Pattern.getSize();
    Tuint alphabet_size = 0;
    Tuint target, state;

    // Allocate enough space for alphabet character table.
    if (!m_Alphabet.resize(256))
      return false;

    // Create alphabet character table.
    for (i = 0; i < m; ++i)
    {
      key = (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(m_Pattern[i]).toLowerCase().getUnsigned() : (Tuint)m_Pattern[i]);
      TCharacterTable::TIterator it = m_Alphabet.find(key);
      if (!it.isValid())
        if (!m_Alphabet.insert(key, alphabet_size++))
          return false;
    }

    // Allocate enough space for the forward Deterministic Finite Automaton.
    if (!m_DFAF.resize(alphabet_size * (m + 1), 0))
      return false;

    // Create forward Deterministic Finite Automaton.
    state = 0;
    for (i = 0; i < m; ++i)
    {
      // Get key from alphabet.
      TCharacterTable::TIteratorConst it_const = m_Alphabet.find(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(m_Pattern[i]).toLowerCase().getUnsigned() : (Tuint)m_Pattern[i]);
      if (!it_const.isValid())
        return false;
      else
        key = it_const.getValueRef();

      // Get Automaton state form current by the given key from alphabet.
      Tuint old_target = m_DFAF[state * alphabet_size + key];

      // Create new target.
      target = i + 1;

      // Link current Automaton state and a new one by the given key from alphabet.
      m_DFAF[state * alphabet_size + key] = target;

      // Copy links form old target.
      for (j = 0; j < alphabet_size; ++j)
        m_DFAF[target * alphabet_size + j] = m_DFAF[old_target * alphabet_size + j];

      // Save new target.
      state = target;
    }

    // Allocate enough space for the backward Deterministic Finite Automaton.
    if (!m_DFAB.resize(alphabet_size * (m + 1), 0))
      return false;

    // Create backward Deterministic Finite Automaton.
    state = 0;
    for (i = 0; i < m; ++i)
    {
      // Get key from alphabet.
      TCharacterTable::TIteratorConst it_const = m_Alphabet.find(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(m_Pattern[m - i - 1]).toLowerCase().getUnsigned() : (Tuint)m_Pattern[m - i - 1]);
      if (!it_const.isValid())
        return false;
      else
        key = it_const.getValueRef();

      // Get Automaton state form current by the given key from alphabet.
      Tuint old_target = m_DFAB[state * alphabet_size + key];

      // Create new target.
      target = i + 1;

      // Link current Automaton state and a new one by the given key from alphabet.
      m_DFAB[state * alphabet_size + key] = target;

      // Copy links form old target.
      for (j = 0; j < alphabet_size; ++j)
        m_DFAB[target * alphabet_size + j] = m_DFAB[old_target * alphabet_size + j];

      // Save new target.
      state = target;
    }

    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchDFA<T_SourceStringType, T_PatternStringType>::onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= m_Pattern.getSize())
  {
    Tuint j, key, state = 0;
    Tuint n = a_cSourceLength;
    Tuint m = m_Pattern.getSize();

    Tuint alphabet_size = m_Alphabet.getSize();

    for (j = 0; j < n; ++j)
    {
      // Get current key from alphabet.
      TCharacterTable::TIteratorConst it_const = m_Alphabet.find(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + j]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex + j]);
      if (!it_const.isValid())
        continue;
      else
        key = it_const.getValueRef();

      // Get current target.
      state = m_DFAF[state * alphabet_size + key];

      // Check for terminal state.
      if (state >= m)
      {
        a_rFoundStart = a_cSourceIndex + j - state + 1;
        a_rFoundEnd = a_cSourceIndex + j;
        return true;
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchDFA<T_SourceStringType, T_PatternStringType>::onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= m_Pattern.getSize())
  {
    Tuint j, key, state = 0;
    Tuint n = a_cSourceLength;
    Tuint m = m_Pattern.getSize();

    Tuint alphabet_size = m_Alphabet.getSize();

    for (j = 0; j < n; ++j)
    {
      // Get current key from alphabet.
      TCharacterTable::TIteratorConst it_const = m_Alphabet.find(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - j]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex - j]);
      if (!it_const.isValid())
        continue;
      else
        key = it_const.getValueRef();

      // Get current target.
      state = m_DFAB[state * alphabet_size + key];

      // Check for terminal state.
      if (state >= m)
      {
        a_rFoundStart = a_cSourceIndex - j;
        a_rFoundEnd = a_cSourceIndex - j + state - 1;
        return true;
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchDFA<T_SourceStringType, T_PatternStringType>::onClose()
{ CALL
  return (m_Pattern.clear() && m_DFAF.clear() && m_DFAB.clear() && m_Alphabet.clear());
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_Archive>
inline Tbool CStringSearchDFA<T_SourceStringType, T_PatternStringType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::CStringSearchDFA")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_Pattern, STR("m_Pattern")));
    CHECK(a_rArchive.doValue(m_DFAF, STR("m_DFAF")));
    CHECK(a_rArchive.doValue(m_DFAB, STR("m_DFAB")));
    CHECK(a_rArchive.doValue(m_Alphabet, STR("m_Alphabet")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline void CStringSearchDFA<T_SourceStringType, T_PatternStringType>::swap(CStringSearchDFA<T_SourceStringType, T_PatternStringType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IStringSearch<T_SourceStringType, T_PatternStringType>&)(*this), (IStringSearch<T_SourceStringType, T_PatternStringType>&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Pattern, a_rInstance.m_Pattern);
  NAlgorithms::NCommon::swap(m_DFAF, a_rInstance.m_DFAF);
  NAlgorithms::NCommon::swap(m_DFAB, a_rInstance.m_DFAB);
  NAlgorithms::NCommon::swap(m_Alphabet, a_rInstance.m_Alphabet);
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
