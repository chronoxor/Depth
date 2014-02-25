/*!
 *  \file    CStringSearchApostolicoGiancarlo.hpp Apostolico-Giancarlo
 *           (sub)string searching algorithm.
 *  \brief   Apostolico-Giancarlo (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Apostolico-Giancarlo (sub)string searching algorithm class.

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
#ifndef __CSTRINGSEARCHAPOSTOLICOGIANCARLO_HPP__
#define __CSTRINGSEARCHAPOSTOLICOGIANCARLO_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMax.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchBoyerMoore.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/containers/CArray.hpp>
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
//! Apostolico-Giancarlo (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li variant of the Boyer-Moore algorithm;
    \li preprocessing phase in O(m+sigma) time and space complexity;
    \li searching phase in O(n) time complexity;
    \li (3/2)*n comparisons in the worst case;

    <b>Description.</b>\n
    The Boyer-Moore algorithm is  difficult  to  analyze  because  after  each
    attempt it forgets all the characters it has already  matched.  Apostolico
    and Giancarlo designed an algorithm which  remembers  the  length  of  the
    longest suffix of the pattern ending at the right position of  the  window
    at the end of each attempt. These information are stored in a table skip.

    Let us assume that during an  attempt  at  a  position  less  than  j  the
    algorithm has matched a suffix of x of length k at position i+j with 0 < i
    < m then skip[i+j] is equal to k. Let suff[i], for 0 leq i < m be equal to
    the length of the longest suffix of x ending at the position i in  x  (see
    chapter Boyer-Moore algorithm).

    During the attempt at position j, if the algorithm  compares  successfully
    the factor of the text y[i+j+1 .. j+m-1] then four cases arise:

    \li Case 1: k > suff[i] and suff[i]=i+1. It means that an occurrence of  x
        is found at position j and skip[j+m-1] is set to m (see figure below).
        A shift of length per(x) is performed:

    \image html Apostolico-Giancarlo-1.png "An occurrence of x is found."

    \li Case 2: k > suff[i] and suff[i] leq i. It means that a mismatch occurs
        between characters x[i-suff[i]] and y[i+j-suff[i]] and skip[j+m-1]  is
        set to m-1-i+suff[i] (see figure below). A shift  is  performed  using
        bmBc[y[i+j-suff[i]]] and bmGs[i-suff[i]+1]:

    \image html Apostolico-Giancarlo-2.png "A mismatch occurs between y[i+j-suff[i]] and x[i-suff[i]]."

    \li Case 3:  k  <  suff[i].  It  means  that  a  mismatch  occurs  between
        characters x[i-k] and y[i+j-k] and skip[j+m-1] is set to m-1-i+k  (see
        figure  below).  A  shift  is  performed  using   bmBc[y[i+j-k]]   and
        bmGs[i-k+1]:

    \image html Apostolico-Giancarlo-3.png "A mismatch occurs between y[i+j-k] and x[i-k]."

    \li Case 4: k=suff[i]. This is the only case where a "jump" has to be done
        over the text  factor  y[i+j-k+1  ..  i+j]  in  order  to  resume  the
        comparisons between the characters y[i+j-k]  and  x[i-k]  (see  figure
        below):

    \image html Apostolico-Giancarlo-4.png "a neq b."

    In each case the only information which is needed is  the  length  of  the
    longest suffix of x ending at position i on x.

    The Apostolico-Giancarlo algorithm use two data structures:
    \li a table skip which is updated at the end of  each  attempt  j  in  the
        following way: skip[j+m-1]=max{ k : x[m-k .. m-1]=y[j+m-k .. +m-1]}
    \li the table suff used during the computation of the table  bmGs:  for  1
        leq i < msuff[i]=max{k : x[i-k+1 .. i]=x[m-k .. m-1]}

    The complexity in space  and  time  of  the  preprocessing  phase  of  the
    Apostolico-Giancarlo algorithm  is  the  same  than  for  the  Boyer-Moore
    algorithm: O(m+sigma).

    During the search phase only the last m informations of the table skip are
    needed at each attempt so the size of the table skip  can  be  reduced  to
    O(m).

    The Apostolico-Giancarlo algorithm performs in the worst case at most 3/2n
    text character comparisons.

    <b>References.</b>\n
    \li APOSTOLICO  A.,  GIANCARLO  R.,  1986,  The  Boyer-Moore-Galil  string
        searching   strategies   revisited,   SIAM   Journal   on    Computing
        15(1):98-105.
    \li CROCHEMORE, M., LECROQ, T., 1997, Tight bounds on  the  complexity  of
        the Apostolico-Giancarlo  algorithm,  Information  Processing  Letters
        63(4):195-203.
    \li CROCHEMORE, M., RYTTER, W., 1994, Text Algorithms,  Oxford  University
        Press.
    \li GUSFIELD, D., 1997,  Algorithms  on  strings,  trees,  and  sequences:
        Computer  Science  and  Computational  Biology,  Cambridge  University
        Press.
    \li LECROQ, T., 1992, Recherches de mot,  Ph.  D.  Thesis,  University  of
        Orleans, France.
    \li LECROQ, T., 1995, Experimental results on string matching  algorithms,
        Software - Practice & Experience 25(7):727-765.

    <b>Taken from:</b>\n
    EXACT STRING MATCHING ALGORITHMS. Animation in Java.
    http://www-igm.univ-mlv.fr/~lecroq/string/index.html
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType>
class CStringSearchApostolicoGiancarlo :
  public CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchApostolicoGiancarlo interface constraint to be a real Depth type.
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
  CStringSearchApostolicoGiancarlo(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchApostolicoGiancarlo class.
  */
  CStringSearchApostolicoGiancarlo(const CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchApostolicoGiancarlo();

  //! Operator: Assign another CStringSearchApostolicoGiancarlo class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchApostolicoGiancarlo class.
      \return Reference to the current class instance.
  */
  CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchApostolicoGiancarlo class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchApostolicoGiancarlo class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchApostolicoGiancarlo class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchApostolicoGiancarlo class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchApostolicoGiancarlo class instance.
  */
  void swap(CStringSearchApostolicoGiancarlo<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onClose();

protected:
  NContainers::CArray<Tuint> m_SkipF;     //!< Forward skip values.
  NContainers::CArray<Tuint> m_SkipB;     //!< Backward skip values.
  NContainers::CArray<Tuint> m_SuffixesF; //!< Forward suffix values.
  NContainers::CArray<Tuint> m_SuffixesB; //!< Backward suffix values.
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
#include <Depth/include/algorithms/string/search/CStringSearchApostolicoGiancarlo.inl>
/*==========================================================================*/
#endif
