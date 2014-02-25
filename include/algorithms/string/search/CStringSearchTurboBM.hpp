/*!
 *  \file    CStringSearchTurboBM.hpp Turbo Boyer-Moore (sub)string searching
 *           algorithm.
 *  \brief   Turbo Boyer-Moore (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Turbo Boyer-Moore (sub)string searching algorithm class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   11.02.2010 03:43:22

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
#ifndef __CSTRINGSEARCHTURBOBM_HPP__
#define __CSTRINGSEARCHTURBOBM_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMax.hpp>
#include <Depth/include/algorithms/common/AMin.hpp>
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
//! Turbo Boyer-Moore (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li variant of the Boyer-Moore;
    \li no  extra  preprocessing  needed  with  respect   to  the  Boyer-Moore
        algorithm;
    \li constant extra space needed with respect to the Boyer-Moore algorithm;
    \li preprocessing phase in O(m+sigma) time and space complexity;
    \li searching phase in O(n) time complexity;
    \li 2n text character comparisons in the worst case.

    <b>Description.</b>\n
    The Turbo Boyer-Moore algorithm is  an  amelioration  of  the  Boyer-Moore
    algorithm. It needs no extra preprocessing and requires  only  a  constant
    extra space  with  respect  to  the  original  Boyer-Moore  algorithm.  It
    consists in remembering the factor of the text that matched  a  suffix  of
    the pattern during the last attempt (and only if a good-suffix  shift  was
    performed).

    This technique presents two advantages:
    \li is possible to jump over this factor;
    \li can enable to perform a turbo-shift.

    A turbo-shift can occur if during the current attempt the  suffix  of  the
    pattern that matches the text is shorter than the one remembered from  the
    preceding attempt. In this case let us call u the remembered factor and  v
    the suffix matched during the current attempt such that uzv is a suffix of
    x. Let a and b be the  characters  that  cause  the  mismatch  during  the
    current attempt in the pattern and the text respectively.  Then  av  is  a
    suffix of x, and thus of u since |v| < |u|. The two  characters  a  and  b
    occur at distance p in the text, and the suffix of x of length |uzv| has a
    period of length p=|zv| since u is a border of uzv, thus it cannot overlap
    both occurrences of two different characters a and b, at  distance  p,  in
    the text. The smallest shift possible has length |u|-|v|, which we call  a
    turbo-shift:

    \image html Turbo-BM-1.png "A turbo-shift can apply when |v|<|u|."

    Still in the case where |v|<|u| if the length of the  bad-character  shift
    is larger than the length of the good-suffix shift and the length  of  the
    turbo-shift then the length of the actual shift must be greater  or  equal
    to |u|+1. Indeed, in this case the two characters c and  d  are  different
    since we assumed that the previous shift was  a  good-suffix  shift:

    \image html Turbo-BM-2.png "c neq d so they cannot be aligned with the same character in v."

    Then a shift greater than the turbo-shift but  smaller  than  |u|+1  would
    align c and d with a same character in v. Thus if this case the length  of
    the actual shift must be at least equal to |u|+1.

    The preprocessing phase can be performed  in  O(m+sigma)  time  and  space
    complexity. The searching phase is in O(n) time complexity. The number  of
    text character comparisons performed by the Turbo Boyer-Moore algorithm is
    bounded by 2n.

    <b>References.</b>\n
    \li CROCHEMORE, M., 1997.  Off-line  serial  exact  string  searching,  in
        Pattern Matching Algorithms, ed. A. Apostolico and Z.  Galil,  Chapter
        1, pp 1-53, Oxford University Press.
    \li CROCHEMORE, M., CZUMAJ A., GASIENIEC  L.,  JAROMINEK  S.,  LECROQ  T.,
        PLANDOWSKI  W.,  RYTTER  W.,  1992,  Deux  methodes   pour   accelerer
        l'algorithme de Boyer-Moore, in Theorie des Automates et Applications,
        Actes des 2e Journees Franco-Belges, D. Krob ed., Rouen, France, 1991,
        pp 45-63, PUR 176, Rouen, France.
    \li CROCHEMORE, M., CZUMAJ, A., GASIENIEC, L., JAROMINEK, S., LECROQ,  T.,
        PLANDOWSKI, W., RYTTER, W., 1994,  Speeding  up  two  string  matching
        algorithms, Algorithmica 12(4/5):247-267.
    \li CROCHEMORE, M., RYTTER, W., 1994, Text Algorithms,  Oxford  University
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
class CStringSearchTurboBM :
  public CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchTurboBM<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchTurboBM interface constraint to be a real Depth type.
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
  CStringSearchTurboBM(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchTurboBM class.
  */
  CStringSearchTurboBM(const CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchTurboBM();

  //! Operator: Assign another CStringSearchTurboBM class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchTurboBM class.
      \return Reference to the current class instance.
  */
  CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchTurboBM class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchTurboBM class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchTurboBM class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchTurboBM class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchTurboBM class instance.
  */
  void swap(CStringSearchTurboBM<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
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
#include <Depth/include/algorithms/string/search/CStringSearchTurboBM.inl>
/*==========================================================================*/
#endif
