/*!
 *  \file    CStringSearchKarpRabin.hpp Karp-Rabin (sub)string searching
 *           algorithm.
 *  \brief   Karp-Rabin (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Karp-Rabin (sub)string searching algorithm class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   13.01.2010 20:00:33

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
#ifndef __CSTRINGSEARCHKARPRABIN_HPP__
#define __CSTRINGSEARCHKARPRABIN_HPP__
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
//! Karp-Rabin (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li uses an hashing function;
    \li preprocessing phase in O(m) time complexity and constant space;
    \li searching phase in O(mn) time complexity;
    \li O(n+m) expected running time.

    <b>Description.</b>\n
    Hashing provides a simple method to avoid a quadratic number of  character
    comparisons in most practical situations.  Instead  of  checking  at  each
    position of the text if the pattern occurs, it seems to be more  efficient
    to check only if the contents of the window "looks like" the  pattern.  In
    order to check the resemblance between these two words an hashing function
    is used.

    To be helpful for the string matching problem  an  hashing  function  hash
    should have the following properties:
    \li efficiently computable;
    \li highly discriminating for strings;
    \li hash(y[j+1 .. j+m]) must be easily computable from hash(y[j .. j+m-1])
        and y[j+m]: hash(y[j+1 .. j+m]) =  rehash(y[j],  y[j+m],  hash(y[j  ..
        j+m-1]).

    For a word w of length m let hash(w) be defined as follows:
    hash(w[0 .. m-1])=(w[0]*2m-1+ w[1]*2m-2+תתת+ w[m-1]*20) mod q
    where q is a large number.

    Then, rehash(a,b,h)= ((h-a*2m-1)*2+b) mod q

    The preprocessing phase of the Karp-Rabin algorithm consists in  computing
    hash(x). It can be done in constant space and O(m) time.

    During searching phase, it is enough to compare hash(x) with  hash(y[j  ..
    j+m-1]) for 0 leq j < n-m. If an equality is found, it is still  necessary
    to check the equality x=y[j .. j+m-1] character by character.

    The time complexity of the searching phase of the Karp-Rabin algorithm  is
    O(mn) (when searching for am in an for instance). Its expected  number  of
    text character comparisons is O(n+m).

    <b>References.</b>\n
    \li EXACT STRING MATCHING ALGORITHMS. Animation in Java. Christian Charras
        - Thierry Lecroq. Laboratoire d'Informatique de Rouen.  Universite  de
        Rouen. Faculte des Sciences et des Techniques. 76821 Mont-Saint-Aignan
        Cedex. FRANCE
    \li AHO, A.V., 1990,  Algorithms  for  finding  patterns  in  strings.  in
        Handbook of Theoretical Computer Science,  Volume  A,  Algorithms  and
        complexity, J. van Leeuwen  ed.,  Chapter  5,  pp  255-300,  Elsevier,
        Amsterdam.
    \li CORMEN, T.H., LEISERSON, C.E., RIVEST,  R.L.,  1990.  Introduction  to
        Algorithms, Chapter 34, pp 853-885, MIT Press.
    \li CROCHEMORE, M., HANCART, C., 1999, Pattern  Matching  in  Strings,  in
        Algorithms and Theory  of  Computation  Handbook,  M.J.  Atallah  ed.,
        Chapter 11, pp 11-1--11-28, CRC Press Inc., Boca Raton, FL.
    \li GONNET, G.H., BAEZA-YATES, R.A., 1991. Handbook of Algorithms and Data
        Structures in Pascal and C,  2nd  Edition,  Chapter  7,  pp.  251-288,
        Addison-Wesley Publishing Company.
    \li HANCART, C., 1993. Analyse  exacte  et  en  moyenne  d'algorithmes  de
        recherche d'un motif dans un texte, Ph. D. Thesis, University Paris 7,
        France.
    \li CROCHEMORE,  M.,  LECROQ,  T.,  1996,  Pattern   matching   and   text
        compression  algorithms,  in  CRC  Computer  Science  and  Engineering
        Handbook, A. Tucker ed., Chapter 8, pp 162-202, CRC Press  Inc.,  Boca
        Raton, FL.
    \li KARP R.M., RABIN M.O.,  1987,  Efficient  randomized  pattern-matching
        algorithms. IBM J. Res. Dev. 31(2):249-260.
    \li SEDGEWICK,  R.,   1988,   Algorithms,   Chapter   19,   pp.   277-292,
        Addison-Wesley Publishing Company.
    \li SEDGEWICK, R., 1988,  Algorithms  in  C,  Chapter  19,  Addison-Wesley
        Publishing Company.
    \li STEPHEN, G.A., 1994, String Searching Algorithms, World Scientific.

    <b>Taken from:</b>\n
    EXACT STRING MATCHING ALGORITHMS. Animation in Java.
    http://www-igm.univ-mlv.fr/~lecroq/string/index.html
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType>
class CStringSearchKarpRabin :
  public IStringSearch<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchKarpRabin interface constraint to be a real Depth type.
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
  CStringSearchKarpRabin(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchKarpRabin class.
  */
  CStringSearchKarpRabin(const CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchKarpRabin();

  //! Operator: Assign another CStringSearchKarpRabin class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchKarpRabin class.
      \return Reference to the current class instance.
  */
  CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchKarpRabin class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchKarpRabin class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchKarpRabin class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchKarpRabin class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchKarpRabin class instance.
  */
  void swap(CStringSearchKarpRabin<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onClose();

private:
  NDepth::NString::CString m_Pattern;   //!< Search algorithm pattern.
  Tuint m_PatternHashF;                 //!< Forward pattern hash value.
  Tuint m_PatternHashB;                 //!< Backward pattern hash value.
  Tuint m_D;                            //!< D calculated value.
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
#include <Depth/include/algorithms/string/search/CStringSearchKarpRabin.inl>
/*==========================================================================*/
#endif
