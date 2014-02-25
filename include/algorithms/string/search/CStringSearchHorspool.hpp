/*!
 *  \file    CStringSearchHorspool.hpp Horspool (sub)string searching
 *           algorithm.
 *  \brief   Horspool (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Horspool (sub)string searching algorithm class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   09.02.2010 02:15:45

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
#ifndef __CSTRINGSEARCHHORSPOOL_HPP__
#define __CSTRINGSEARCHHORSPOOL_HPP__
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
//! Horspool (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li simplification of the Boyer-Moore algorithm;
    \li easy to implement;
    \li preprocessing phase in O(m+sigma) time and O(sigma) space complexity;
    \li searching phase in O(mn) time complexity;
    \li the  average  number  of comparisons for one text character is between
        1/sigma and 2/(sigma+1).

    <b>Description.</b>\n
    The bad-character shift used in the  Boyer-Moore  algorithm  (see  chapter
    Boyer-Moore algorithm) is not very efficient for small alphabets, but when
    the alphabet is large compared with the length of the pattern,  as  it  is
    often the case with the ASCII table and ordinary  searches  made  under  a
    text editor, it becomes very useful.

    Using it alone produces a very efficient algorithm in  practice.  Horspool
    proposed to use only the bad-character shift of the rightmost character of the
    window to compute the shifts in the Boyer-Moore algorithm.

    The  preprocessing  phase  is  in  O(m+sigma)  time  and  O(sigma)   space
    complexity.

    The searching phase has a quadratic worst case but it can be  proved  that
    the average number of  comparisons  for  one  text  character  is  between
    1/sigma and 2/(sigma+1).

    <b>References.</b>\n
    \li AHO, A.V., 1990,  Algorithms  for  finding  patterns  in  strings.  in
        Handbook of Theoretical Computer Science,  Volume  A,  Algorithms  and
        complexity, J. van Leeuwen  ed.,  Chapter  5,  pp  255-300,  Elsevier,
        Amsterdam.
    \li BAEZA-YATES, R.A., REGNIER, M., 1992,  Average  running  time  of  the
        Boyer-Moore-Horspool   algorithm,   Theoretical    Computer    Science
        92(1):19-31.
    \li BEAUQUIER,  D.,  BERSTEL,  J.,   CHRETIENNE,   P.,   1992,    Elements
        d'algorithmique, Chapter 10, pp 337-377, Masson, Paris.
    \li CROCHEMORE, M., HANCART, C., 1999, Pattern  Matching  in  Strings,  in
        Algorithms and Theory  of  Computation  Handbook,  M.J.  Atallah  ed.,
        Chapter 11, pp 11-1--11-28, CRC Press Inc., Boca Raton, FL.
    \li HANCART, C., 1993. Analyse  exacte  et  en  moyenne  d'algorithmes  de
        recherche d'un motif dans un texte, Ph. D. Thesis, University Paris 7,
        France.
    \li HORSPOOL R.N., 1980, Practical fast searching in strings,  Software  -
        Practice & Experience, 10(6):501-506.
    \li LECROQ, T., 1995, Experimental results on string matching  algorithms,
        Software - Practice & Experience 25(7):727-765.
    \li STEPHEN, G.A., 1994, String Searching Algorithms, World Scientific.

    <b>Taken from:</b>\n
    EXACT STRING MATCHING ALGORITHMS. Animation in Java.
    http://www-igm.univ-mlv.fr/~lecroq/string/index.html
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType>
class CStringSearchHorspool :
  public CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchHorspool<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchHorspool interface constraint to be a real Depth type.
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
  CStringSearchHorspool(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchHorspool class.
  */
  CStringSearchHorspool(const CStringSearchHorspool<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchHorspool();

  //! Operator: Assign another CStringSearchHorspool class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchHorspool class.
      \return Reference to the current class instance.
  */
  CStringSearchHorspool<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchHorspool<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchHorspool class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchHorspool class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchHorspool<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchHorspool class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchHorspool class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchHorspool class instance.
  */
  void swap(CStringSearchHorspool<T_SourceStringType, T_PatternStringType>& a_rInstance);

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
#include <Depth/include/algorithms/string/search/CStringSearchHorspool.inl>
/*==========================================================================*/
#endif
