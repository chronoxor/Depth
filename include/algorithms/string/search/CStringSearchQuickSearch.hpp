/*!
 *  \file    CStringSearchQuickSearch.hpp Quick Search (sub)string searching
 *           algorithm.
 *  \brief   Quick Search (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Quick Search (sub)string searching algorithm class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   09.02.2010 02:50:44

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
#ifndef __CSTRINGSEARCHQUICKSEARCH_HPP__
#define __CSTRINGSEARCHQUICKSEARCH_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FHashInteger.hpp>
#include <Depth/include/algorithms/functions/FHashIntegerComparator.hpp>
#include <Depth/include/algorithms/string/search/IStringSearch.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
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
//! Quick Search (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li simplification of the Boyer-Moore algorithm;
    \li uses only the bad-character shift;
    \li easy to implement;
    \li preprocessing phase in O(m+sigma) time and O(sigma) space complexity;
    \li searching phase in O(mn) time complexity;
    \li very fast in practice for short patterns and large alphabets.

    <b>Description.</b>\n
    The Quick Search algorithm uses only the bad-character  shift  table  (see
    chapter Boyer-Moore algorithm). After  an  attempt  where  the  window  is
    positioned on the text factor y[j .. j+m-1], the length of the shift is at
    least equal to one. So, the character y[j+m] is  necessarily  involved  in
    the next attempt, and thus can be used for the bad-character shift of  the
    current attempt.

    The bad-character shift of the present algorithm is slightly  modified  to
    take into account the last character of x as  follows:  for  c  in  Sigma,
    qsBc[c]=min{i : 0 leq i < m and x[m-1-i]=c} if c occurs in x, m otherwise.

    The  preprocessing  phase  is  in  O(m+sigma)  time  and  O(sigma)   space
    complexity.

    During the searching  phase  the  comparisons  between  pattern  and  text
    characters during each attempt can be done in  any  order.  The  searching
    phase has a quadratic worst  case  time  complexity  but  it  has  a  good
    practical behaviour.

    <b>References.</b>\n
    \li CROCHEMORE,  M.,  LECROQ,  T.,  1996,  Pattern   matching   and   text
        compression algorithms,  in  CRC  Computer  Science   and  Engineering
        Handbook, A. Tucker ed., Chapter 8, pp 162-202, CRC  Press Inc.,  Boca
        Raton, FL.
    \li LECROQ, T., 1995, Experimental results on string matching  algorithms,
        Software - Practice & Experience 25(7):727-765.
    \li STEPHEN, G.A., 1994, String Searching Algorithms, World Scientific.
    \li SUNDAY  D.M.,  1990,  A   very  fast   substring   search   algorithm,
        Communications of the ACM . 33(8):132-142.

    <b>Taken from:</b>\n
    EXACT STRING MATCHING ALGORITHMS. Animation in Java.
    http://www-igm.univ-mlv.fr/~lecroq/string/index.html
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType>
class CStringSearchQuickSearch :
  public IStringSearch<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchQuickSearch interface constraint to be a real Depth type.
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
  CStringSearchQuickSearch(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchQuickSearch class.
  */
  CStringSearchQuickSearch(const CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchQuickSearch();

  //! Operator: Assign another CStringSearchQuickSearch class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchQuickSearch class.
      \return Reference to the current class instance.
  */
  CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchQuickSearch class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchQuickSearch class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchQuickSearch class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchQuickSearch class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchQuickSearch class instance.
  */
  void swap(CStringSearchQuickSearch<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onClose();

protected:
  //! Type of the characters table.
  typedef NContainers::CHashTableChain<Tuint, Tuint, NAlgorithms::NFunctions::FHashInteger<Tuint>, NAlgorithms::NFunctions::FHashIntegerComparator<Tuint> > TCharacterTable;

  NDepth::NString::CString m_Pattern;   //!< Search algorithm pattern.
  TCharacterTable m_QSBcF;              //!< Forward bad-character shift values.
  TCharacterTable m_QSBcB;              //!< Backward bad-character shift values.

  //! Calculate bad-character shift values.
  /*!
      \param a_cIgnoreCaseFlag - Ignore case flag.
      \param a_crPattern - Constant reference to the pattern string.
      \param a_rQSBcF - Reference to the forward map of the bad-character shift values.
      \param a_rQSBcB - Reference to the backward map of the bad-character shift values.
      \return true  - if bad-character shift values were successfully calculated. \n
              false - if bad-character shift values were not successfully calculated. \n
  */
  static Tbool calculateBadCharacterShift(const Tbool a_cIgnoreCaseFlag, const NDepth::NString::CString& a_crPattern, TCharacterTable& a_rQSBcF, TCharacterTable& a_rQSBcB);
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
#include <Depth/include/algorithms/string/search/CStringSearchQuickSearch.inl>
/*==========================================================================*/
#endif
