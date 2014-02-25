/*!
 *  \file    CStringSearchDFA.hpp Deterministic Finite Automaton (sub)string
 *           searching algorithm.
 *  \brief   Deterministic Finite Automaton (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Deterministic Finite Automaton (sub)string searching algorithm class.

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
#ifndef __CSTRINGSEARCHDFA_HPP__
#define __CSTRINGSEARCHDFA_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FHashInteger.hpp>
#include <Depth/include/algorithms/functions/FHashIntegerComparator.hpp>
#include <Depth/include/algorithms/string/search/IStringSearch.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/containers/CArray.hpp>
#include <Depth/include/containers/CHashTableChain.hpp>
#include <Depth/include/string/CCharacter.hpp>
#include <Depth/include/traits/MTraitsString.hpp>
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
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Deterministic Finite Automaton (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li builds the minimal deterministic automaton  recognizing  the  language
        Sigma*x;
    \li extra space in O(msigma) if the automaton is stored in a direct access
        table;
    \li preprocessing phase in O(msigma) time complexity;
    \li searching phase in O(n) time complexity if the automaton is stored  in
        a direct access table, O(nlog(sigma)) otherwise.

    <b>Description.</b>\n
    Searching a word x with  an  automaton  consists  first  in  building  the
    minimal Deterministic Finite Automaton (DFA) A(x) recognizing the language
    Sigma*x.

    The DFA A(x) =(Q, q0, T, E) recognizing the language Sigma*x is defined as
    follows:

    \li Q is the set of all the prefixes of x: Q={epsilon, x[0],  x[0  ..  1],
      ... , x[0 .. m-2], x};
    \li q0=epsilon;
    \li T={x};
    \li for q in Q (q is a prefix of x) and a in Sigma, (q, a, qa) is in E  if
        and only if qa is also a prefix of x, otherwise (q, a, p) is in E such
        that p is the longest suffix of qa which is a prefix of x.

    The DFA A(x) can be constructed in O(m+sigma) time and O(msigma) space.

    Once the DFA A(x) is build, searching for a word x in a text y consists in
    parsing the text y with the DFA A(x) beginning with the initial state  q0.
    Each time the  terminal  state  is  encountered  an  occurrence  of  x  is
    reported.

    The searching phase can be performed in O(n)  time  if  the  automaton  is
    stored in a direct access table, in O(nlog(sigma)) otherwise.

    <b>References.</b>\n
    \li CORMEN, T.H., LEISERSON, C.E., RIVEST,  R.L.,  1990.  Introduction  to
        Algorithms, Chapter 34, pp 853-885, MIT Press.
    \li CROCHEMORE, M., 1997.  Off-line  serial  exact  string  searching,  in
        Pattern Matching Algorithms, ed. A. Apostolico and Z.  Galil,  Chapter
        1, pp 1-53, Oxford University Press.
    \li CROCHEMORE, M., HANCART, C., 1997. Automata for Matching Patterns,  in
        Handbook of Formal Languages, Volume 2,  Linear  Modeling:  Background
        and Application, G. Rozenberg  and  A.  Salomaa  ed.,  Chapter  9,  pp
        399-462, Springer-Verlag, Berlin.
    \li GONNET, G.H., BAEZA-YATES, R.A., 1991. Handbook of Algorithms and Data
        Structures in Pascal and C,  2nd  Edition,  Chapter  7,  pp.  251-288,
        Addison-Wesley Publishing Company.
    \li HANCART, C., 1993. Analyse  exacte  et  en  moyenne  d'algorithmes  de
        recherche d'un motif dans un texte, Ph. D. Thesis, University Paris 7,
        France.

    <b>Taken from:</b>\n
    EXACT STRING MATCHING ALGORITHMS. Animation in Java.
    http://www-igm.univ-mlv.fr/~lecroq/string/index.html
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType>
class CStringSearchDFA :
  public IStringSearch<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchDFA<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchDFA interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! String type of the search algorithm.
  typedef T_SourceStringType TStringType;
  //! Pattern string type of the search algorithm.
  typedef T_PatternStringType TPatternType;

  //! Default class constructor.
  /*!
      \param a_cIgnoreCaseFlag - Ignore case flag (default is false).
  */
  CStringSearchDFA(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchDFA class.
  */
  CStringSearchDFA(const CStringSearchDFA<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchDFA();

  //! Operator: Assign another CStringSearchDFA class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchDFA class.
      \return Reference to the current class instance.
  */
  CStringSearchDFA<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchDFA<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchDFA class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchDFA class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchDFA<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchDFA class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchDFA class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchDFA class instance.
  */
  void swap(CStringSearchDFA<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onClose();

private:
  //! Type of the characters table.
  typedef NContainers::CHashTableChain<Tuint, Tuint, NAlgorithms::NFunctions::FHashInteger<Tuint>, NAlgorithms::NFunctions::FHashIntegerComparator<Tuint> > TCharacterTable;

  NDepth::NString::CString  m_Pattern;  //!< Search algorithm pattern.
  NContainers::CArray<Tuint> m_DFAF;    //!< Forward Deterministic Finite Automaton.
  NContainers::CArray<Tuint> m_DFAB;    //!< Backward Deterministic Finite Automaton.
  TCharacterTable m_Alphabet;           //!< Alphabet characters table.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/search/CStringSearchDFA.inl>
/*==========================================================================*/
#endif
