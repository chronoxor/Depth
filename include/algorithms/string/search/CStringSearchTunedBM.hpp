/*!
 *  \file    CStringSearchTunedBM.hpp Tuned Boyer-Moore (sub)string searching
 *           algorithm.
 *  \brief   Tuned Boyer-Moore (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tuned Boyer-Moore (sub)string searching algorithm class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   11.02.2010 02:47:35

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
#ifndef __CSTRINGSEARCHTUNEDBM_HPP__
#define __CSTRINGSEARCHTUNEDBM_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/search/CStringSearchBoyerMoore.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
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
//! Tuned Boyer-Moore (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li simplification of the Boyer-Moore algorithm;
    \li easy to implement;
    \li very fast in practice.

    <b>Description.</b>\n
    The Tuned Boyer-Moore is a implementation of a simplified version  of  the
    Boyer-Moore algorithm which is very fast in practice. The most costly part
    of a string-matching algorithm is to check whether the  character  of  the
    pattern match the character of the window. To avoid doing  this  part  too
    often, it is possible to unrolled several shifts before actually comparing
    the characters. The algorithm used the  bad-character  shift  function  to
    find x[m-1] in y and keep on shifting  until  finding  it,  doing  blindly
    three shifts in a row. This required to save the value of bmBc[x[m-1]]  in
    a variable shift and then to set bmBc[x[m-1]] to 0. This required also  to
    add m occurrences of x[m-1] at the end of y. When x[m-1] is found the  m-1
    other characters of the window are checked and a shift of length shift  is
    applied.

    The comparisons between pattern and text characters  during  each  attempt
    can be done in any order. This algorithm has a quadratic  worst-case  time
    complexity but a very good practical behaviour.

    <b>References.</b>\n
    \li HUME A. and SUNDAY D.M. , 1991.  Fast  string  searching.  Software  -
        Practice & Experience 21(11):1221-1248.
    \li STEPHEN, G.A., 1994, String Searching Algorithms, World Scientific.

    <b>Taken from:</b>\n
    EXACT STRING MATCHING ALGORITHMS. Animation in Java.
    http://www-igm.univ-mlv.fr/~lecroq/string/index.html
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType>
class CStringSearchTunedBM :
  public CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchTunedBM<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchTunedBM interface constraint to be a real Depth type.
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
  CStringSearchTunedBM(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchTunedBM class.
  */
  CStringSearchTunedBM(const CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchTunedBM();

  //! Operator: Assign another CStringSearchTunedBM class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchTunedBM class.
      \return Reference to the current class instance.
  */
  CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchTunedBM class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchTunedBM class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchTunedBM class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchTunedBM class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchTunedBM class instance.
  */
  void swap(CStringSearchTunedBM<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);

protected:
  Tuint m_ShiftF;                       //!< Forward shift value.
  Tuint m_ShiftB;                       //!< Backward shift value.
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
#include <Depth/include/algorithms/string/search/CStringSearchTunedBM.inl>
/*==========================================================================*/
#endif
