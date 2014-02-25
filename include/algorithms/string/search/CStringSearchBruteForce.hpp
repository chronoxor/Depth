/*!
 *  \file    CStringSearchBruteForce.hpp Brute Force (sub)string searching
 *           algorithm.
 *  \brief   Brute Force (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Brute Force (sub)string searching algorithm class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   27.11.2009 21:35:48

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
#ifndef __CSTRINGSEARCHBRUTEFORCE_HPP__
#define __CSTRINGSEARCHBRUTEFORCE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/search/IStringSearch.hpp>
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
//! Brute Force (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li no preprocessing phase;
    \li constant extra space needed;
    \li always shifts the window by exactly 1 position to the right;
    \li comparisons can be done in any order;
    \li searching phase in O(mn) time complexity;
    \li 2n expected text characters comparisons.

    <b>Description.</b>\n
    The brute force algorithm consists in checking, at all  positions  in  the
    text between 0 and n-m, whether an occurrence of the pattern starts  there
    or not. Then, after each attempt, it shifts the  pattern  by  exactly  one
    position to the right.

    The brute force algorithm requires no preprocessing phase, and a  constant
    extra space in addition to the pattern and the text. During the  searching
    phase the text character comparisons can be done in any  order.  The  time
    complexity of this searching phase is O(mn) (when searching for  am-1b  in
    an for instance). The expected number of text character comparisons is 2n.

    <b>References.</b>\n
    \li EXACT STRING MATCHING ALGORITHMS. Animation in Java. Christian Charras
        - Thierry Lecroq. Laboratoire d'Informatique de Rouen.  Universite  de
        Rouen. Faculte des Sciences et des Techniques. 76821 Mont-Saint-Aignan
        Cedex. FRANCE

    <b>Taken from:</b>\n
    EXACT STRING MATCHING ALGORITHMS. Animation in Java.
    http://www-igm.univ-mlv.fr/~lecroq/string/index.html
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType>
class CStringSearchBruteForce :
  public IStringSearch<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchBruteForce<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchBruteForce interface constraint to be a real Depth type.
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
  CStringSearchBruteForce(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchBruteForce class.
  */
  CStringSearchBruteForce(const CStringSearchBruteForce<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchBruteForce();

  //! Operator: Assign another CStringSearchBruteForce class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchBruteForce class.
      \return Reference to the current class instance.
  */
  CStringSearchBruteForce<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchBruteForce<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchBruteForce class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchBruteForce class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchBruteForce<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchBruteForce class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchBruteForce class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchBruteForce class instance.
  */
  void swap(CStringSearchBruteForce<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onClose();

private:
  NDepth::NString::CString m_Pattern;   //!< Search algorithm pattern.
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
#include <Depth/include/algorithms/string/search/CStringSearchBruteForce.inl>
/*==========================================================================*/
#endif
