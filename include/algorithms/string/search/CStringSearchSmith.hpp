/*!
 *  \file    CStringSearchSmith.hpp Smith (sub)string searching algorithm.
 *  \brief   Smith (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Smith (sub)string searching algorithm class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   09.02.2010 22:11:40

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
#ifndef __CSTRINGSEARCHSMITH_HPP__
#define __CSTRINGSEARCHSMITH_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMax.hpp>
#include <Depth/include/algorithms/functions/FHashInteger.hpp>
#include <Depth/include/algorithms/functions/FHashIntegerComparator.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchBoyerMoore.hpp>
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
//! Smith (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li takes the maximum of the Horspool bad-character shift function and the
        Quick Search bad-character shift function;
    \li preprocessing phase in O(m+sigma) time and O(sigma) space complexity;
    \li searching phase in O(mn) time complexity.

    <b>Description.</b>\n
    Smith noticed that computing the shift with the text character  just  next
    the rightmost text character of the window gives sometimes  shorter  shift
    than using the rightmost text character of the window.

    He advised then to take the maximum between the two values.

    The preprocessing phase of the Smith algorithm consists in  computing  the
    bad-character shift function (see chapter Boyer-Moore algorithm)  and  the
    Quick Search  bad-character  shift  function  (see  chapter  Quick  Search
    algorithm).

    The  preprocessing  phase  is  in  O(m+sigma)  time  and  O(sigma)   space
    complexity.

    The searching phase of the Smith algorithm has a quadratic worst case time
    complexity.

    <b>References.</b>\n
    \li SMITH P.D., 1991,  Experiments  with  a  very  fast  substring  search
        algorithm, Software - Practice & Experience 21(10):1065-1074.

    <b>Taken from:</b>\n
    EXACT STRING MATCHING ALGORITHMS. Animation in Java.
    http://www-igm.univ-mlv.fr/~lecroq/string/index.html
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType>
class CStringSearchSmith :
  public CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchSmith<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchSmith interface constraint to be a real Depth type.
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
  CStringSearchSmith(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchSmith class.
  */
  CStringSearchSmith(const CStringSearchSmith<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchSmith();

  //! Operator: Assign another CStringSearchSmith class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchSmith class.
      \return Reference to the current class instance.
  */
  CStringSearchSmith<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchSmith<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchSmith class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchSmith class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchSmith<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchSmith class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchSmith class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchSmith class instance.
  */
  void swap(CStringSearchSmith<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onClose();

protected:
  //! Type of the characters table.
  typedef NContainers::CHashTableChain<Tuint, Tuint, NAlgorithms::NFunctions::FHashInteger<Tuint>, NAlgorithms::NFunctions::FHashIntegerComparator<Tuint> > TCharacterTable;

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
#include <Depth/include/algorithms/string/search/CStringSearchSmith.inl>
/*==========================================================================*/
#endif
