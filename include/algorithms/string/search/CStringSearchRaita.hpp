/*!
 *  \file    CStringSearchRaita.hpp Raita (sub)string searching algorithm.
 *  \brief   Raita (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Raita (sub)string searching algorithm class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   09.02.2010 23:08:56

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
#ifndef __CSTRINGSEARCHRAITA_HPP__
#define __CSTRINGSEARCHRAITA_HPP__
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
//! Raita (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li first compares the last pattern character, then the first and  finally
        the middle one before actually comparing the others;
    \li performs the shifts like the Horspool algorithm;
    \li preprocessing phase in O(m+sigma) time and O(sigma) space complexity;
    \li searching phase in O(mn) time complexity.

    <b>Description.</b>\n
    Raita designed an algorithm which at each attempt first compares the  last
    character of the pattern with the rightmost text character of the  window,
    then if they match it compares the first character of the pattern with the
    leftmost text character of the window, then if they match it compares  the
    middle character of the pattern with the  middle  text  character  of  the
    window.  And  finally  if  they  match  it  actually  compares  the  other
    characters from the second to the last but one, possibly  comparing  again
    the middle character.

    Raita observed that its algorithm had a good behaviour  in  practice  when
    searching patterns in English texts and attributed  these  performance  to
    the existence of character dependencies.

    Smith made some more experiments and concluded that  this  phenomenon  may
    rather be due to compiler effects.

    The preprocessing phase of the Raita algorithm consists in  computing  the
    bad-character shift function (see chapter Boyer-Moore). It can be done  in
    O(m+sigma) time and O(sigma) space complexity.

    The searching phase of the Raita algorithm has a quadratic worst case time
    complexity.

    <b>References.</b>\n
    \li RAITA T.,  1992,  Tuning  the  Boyer-Moore-Horspool  string  searching
        algorithm, Software - Practice & Experience, 22(10):879-884.
    \li SMITH, P.D., 1994, On tuning the Boyer-Moore-Horspool string searching
        algorithms, Software - Practice & Experience, 24(4):435-436.

    <b>Taken from:</b>\n
    EXACT STRING MATCHING ALGORITHMS. Animation in Java.
    http://www-igm.univ-mlv.fr/~lecroq/string/index.html
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType>
class CStringSearchRaita :
  public CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchRaita<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchRaita interface constraint to be a real Depth type.
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
  CStringSearchRaita(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchRaita class.
  */
  CStringSearchRaita(const CStringSearchRaita<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchRaita();

  //! Operator: Assign another CStringSearchRaita class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchRaita class.
      \return Reference to the current class instance.
  */
  CStringSearchRaita<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchRaita<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchRaita class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchRaita class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchRaita<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchRaita class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchRaita class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchRaita class instance.
  */
  void swap(CStringSearchRaita<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onClose();
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
#include <Depth/include/algorithms/string/search/CStringSearchRaita.inl>
/*==========================================================================*/
#endif
