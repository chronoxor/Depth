/*!
 *  \file    CStringSearchBoyerMoore.hpp Boyer-Moore (sub)string searching
 *           algorithm.
 *  \brief   Boyer-Moore (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    08.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Boyer-Moore (sub)string searching algorithm class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   08.02.2010 02:24:50

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
#ifndef __CSTRINGSEARCHBOYERMOORE_HPP__
#define __CSTRINGSEARCHBOYERMOORE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMax.hpp>
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
//! Boyer-Moore (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li performs the comparisons from right to left;
    \li preprocessing phase in O(m+sigma) time and space complexity;
    \li searching phase in O(mn) time complexity;
    \li 3n text character comparisons in the worst case when searching  for  a
        non periodic pattern;
    \li O(n / m) best performance.

    <b>Description.</b>\n
    The  Boyer-Moore  algorithm  is   considered   as   the   most   efficient
    string-matching algorithm in usual applications. A simplified  version  of
    it or the entire algorithm is often implemented in text  editors  for  the
    <search> and <substitute> commands.

    The algorithm scans the characters of  the  pattern  from  right  to  left
    beginning with the rightmost one. In case of a  mismatch  (or  a  complete
    match of the whole pattern) it uses two precomputed functions to shift the
    window to the right. These two shift functions are called the  good-suffix
    shift (also called matching shift and the bad-character shift (also called
    the occurrence shift).

    Assume that a mismatch occurs between the character x[i]=a of the  pattern
    and the character y[i+j]=b of the text during an attempt at position j.

    Then,  x[i+1  ..  m-1]=y[i+j+1  ..  j+m-1]=u  and  x[i]  neq  y[i+j].  The
    good-suffix shift consists in aligning the segment y[i+j+1 .. j+m-1]=x[i+1
    .. m-1] with its rightmost occurrence in x that is preceded by a character
    different from x[i]:

    \image html Boyer-Moore-1.png "The good-suffix shift, u re-occurs preceded by a character c different from a."

    If there exists no such  segment,  the  shift  consists  in  aligning  the
    longest suffix v of y[i+j+1 .. j+m-1] with a matching prefix of x:

    \image html Boyer-Moore-2.png "The good-suffix shift, only a suffix of u re-occurs in x."

    The bad-character shift consists in aligning  the  text  character  y[i+j]
    with its rightmost occurrence in x[0 .. m-2]:

    \image html Boyer-Moore-3.png "The bad-character shift, a occurs in x."

    If y[i+j] does not occur in the pattern x, no occurrence of  x  in  y  can
    include y[i+j], and the left  end  of  the  window  is  aligned  with  the
    character immediately after y[i+j], namely y[i+j+1]:

    \image html Boyer-Moore-3.png "The bad-character shift, b does not occur in x."

    Note that the bad-character shift can be negative, thus for  shifting  the
    window, the Boyer-Moore algorithm applies  the  maximum  between  the  the
    good-suffix shift and bad-character shift. More  formally  the  two  shift
    functions are defined as follows.

    The good-suffix shift function is stored in a table bmGs of size m+1.

    Let us define two conditions:
    \li Cs(i, s): for each k such that i < k < m, s geq k or x[k-s]=x[k] and
    \li Co(i, s): if s <i then x[i-s] neq x[i]

    Then, for 0 leq i < m: bmGs[i+1]=min{s>0 : Cs(i, s) and Co(i, s) hold} and
    we define bmGs[0] as the length of the period of x. The computation of the
    table bmGs use a table  suff  defined  as  follows:  for  1  leq  i  <  m,
    suff[i]=max{k : x[i-k+1 .. i]=x[m-k .. m-1]}

    The bad-character shift function is stored in a table bmBc of size  sigma.
    For c in Sigma: bmBc[c] = min{i : 1 leq i <m-1 and x[m-1-i]=c} if c occurs
    in x, m otherwise.

    Tables bmBc and bmGs can be precomputed  in  time  O(m+sigma)  before  the
    searching phase and require an extra-space in  O(m+sigma).  The  searching
    phase  time  complexity  is  quadratic  but  at  most  3n  text  character
    comparisons are performed when searching for a non  periodic  pattern.  On
    large alphabets (relatively to the length of the pattern) the algorithm is
    extremely fast. When searching for am-1b in bn the  algorithm  makes  only
    O(n  /  m)  comparisons,  which  is   the   absolute   minimum   for   any
    string-matching  algorithm  in  the  model  where  the  pattern  only   is
    preprocessed.

    <b>References.</b>\n
    \li AHO, A.V., 1990,  Algorithms  for  finding  patterns  in  strings.  in
        Handbook of Theoretical Computer Science,  Volume  A,  Algorithms  and
        complexity, J. van Leeuwen  ed.,  Chapter  5,  pp  255-300,  Elsevier,
        Amsterdam.
    \li AOE,  J.-I.,  1994,  Computer  algorithms:  string   pattern  matching
        strategies, IEEE Computer Society Press.
    \li BAASE, S., VAN GELDER, A., 1999, Computer Algorithms: Introduction  to
        Design  and  Analysis,   3rd   Edition,   Chapter   11,   pp.   ??-??,
        Addison-Wesley Publishing Company.
    \li BAEZA-YATES R.,  NAVARRO  G.,  RIBEIRO-NETO  B.,  1999,  Indexing  and
        Searching, in Modern Information Retrieval,  Chapter  8,  pp  191-228,
        Addison-Wesley.
    \li BEAUQUIER,  D.,  BERSTEL,  J.,   CHRETIENNE,   P.,   1992,    Elements
        d'algorithmique, Chapter 10, pp 337-377, Masson, Paris.
    \li BOYER R.S., MOORE J.S.,  1977,  A  fast  string  searching  algorithm.
        Communications of the ACM. 20:762-772.
    \li COLE, R., 1994, Tight bounds on  the  complexity  of  the  Boyer-Moore
        pattern matching algorithm, SIAM Journal on Computing 23(5):1075-1091.
    \li CORMEN, T.H., LEISERSON, C.E., RIVEST,  R.L.,  1990.  Introduction  to
        Algorithms, Chapter 34, pp 853-885, MIT Press.
    \li CROCHEMORE, M., 1997.  Off-line  serial  exact  string  searching,  in
        Pattern Matching Algorithms, ed. A. Apostolico and Z.  Galil,  Chapter
        1, pp 1-53, Oxford University Press.
    \li CROCHEMORE, M., HANCART, C., 1999, Pattern  Matching  in  Strings,  in
        Algorithms and Theory  of  Computation  Handbook,  M.J.  Atallah  ed.,
        Chapter 11, pp 11-1--11-28, CRC Press Inc., Boca Raton, FL.
    \li CROCHEMORE,  M.,  LECROQ,  T.,  1996,  Pattern  matching    and   text
        compression  algorithms,  in  CRC  Computer  Science  and  Engineering
        Handbook, A. Tucker ed., Chapter 8, pp 162-202, CRC Press  Inc.,  Boca
        Raton, FL.
    \li CROCHEMORE, M., RYTTER, W., 1994, Text Algorithms,  Oxford  University
        Press.
    \li GONNET, G.H., BAEZA-YATES, R.A., 1991. Handbook of Algorithms and Data
        Structures in Pascal and C,  2nd  Edition,  Chapter  7,  pp.  251-288,
        Addison-Wesley Publishing Company.
    \li GOODRICH, M.T., TAMASSIA, R., 1998, Data Structures and Algorithms  in
        JAVA, Chapter 11, pp 441-467, John Wiley & Sons.
    \li GUSFIELD, D., 1997,  Algorithms  on  strings,  trees,  and  sequences:
        Computer  Science  and  Computational  Biology,  Cambridge  University
        Press.
    \li HANCART, C., 1993. Analyse  exacte  et  en  moyenne  d'algorithmes  de
        recherche d'un motif dans un texte, Ph. D. Thesis, University Paris 7,
        France.
    \li KNUTH, D.E.,  MORRIS  (Jr)  J.H.,  PRATT,  V.R.,  1977,  Fast  pattern
        matching in strings, SIAM Journal on Computing 6(1):323-350.
    \li LECROQ, T., 1992, Recherches de mot,  Ph.  D.  Thesis,  University  of
        Orleans, France.
    \li LECROQ, T., 1995, Experimental results on string matching  algorithms,
        Software - Practice & Experience 25(7):727-765.
    \li SEDGEWICK,   R.,  1988,   Algorithms,   Chapter   19,   pp.   277-292,
        Addison-Wesley Publishing Company.
    \li SEDGEWICK, R., 1988,  Algorithms  in  C,  Chapter  19,  Addison-Wesley
        Publishing Company.
    \li STEPHEN, G.A., 1994, String Searching Algorithms, World Scientific.
    \li WATSON, B.W.,  1995,  Taxonomies  and  Toolkits  of  Regular  Language
        Algorithms, Ph. D. Thesis, Eindhoven  University  of  Technology,  The
        Netherlands.
    \li WIRTH, N., 1986, Algorithms & Data Structures, Chapter 1,  pp.  17-72,
        Prentice-Hall.

    <b>Taken from:</b>\n
    EXACT STRING MATCHING ALGORITHMS. Animation in Java.
    http://www-igm.univ-mlv.fr/~lecroq/string/index.html
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType>
class CStringSearchBoyerMoore :
  public IStringSearch<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchBoyerMoore interface constraint to be a real Depth type.
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
  CStringSearchBoyerMoore(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchBoyerMoore class.
  */
  CStringSearchBoyerMoore(const CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchBoyerMoore();

  //! Operator: Assign another CStringSearchBoyerMoore class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchBoyerMoore class.
      \return Reference to the current class instance.
  */
  CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchBoyerMoore class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchBoyerMoore class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchBoyerMoore class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchBoyerMoore class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchBoyerMoore class instance.
  */
  void swap(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>& a_rInstance);

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
  NContainers::CArray<Tuint> m_BMGsF;   //!< Forward good-suffix shift values.
  NContainers::CArray<Tuint> m_BMGsB;   //!< Backward good-suffix shift values.
  TCharacterTable m_BMBcF;              //!< Forward bad-character shift values.
  TCharacterTable m_BMBcB;              //!< Backward bad-character shift values.

  //! Calculate good-suffix shift values.
  /*!
      \param a_cIgnoreCaseFlag - Ignore case flag.
      \param a_crPattern - Constant reference to the pattern string.
      \param a_rBMGsF - Reference to the forward array of the good-suffix shift values.
      \param a_rBMGsB - Reference to the backward array of the good-suffix shift values.
      \return true  - if good-suffix shift values were successfully calculated. \n
              false - if good-suffix shift values were not successfully calculated. \n
  */
  static Tbool calculateGoodSuffixShift(const Tbool a_cIgnoreCaseFlag, const NDepth::NString::CString& a_crPattern, NContainers::CArray<Tuint>& a_rBMGsF, NContainers::CArray<Tuint>& a_rBMGsB);
  //! Calculate bad-character shift values.
  /*!
      \param a_cIgnoreCaseFlag - Ignore case flag.
      \param a_crPattern - Constant reference to the pattern string.
      \param a_rBMBcF - Reference to the forward map of the bad-character shift values.
      \param a_rBMBcB - Reference to the backward map of the bad-character shift values.
      \return true  - if bad-character shift values were successfully calculated. \n
              false - if bad-character shift values were not successfully calculated. \n
  */
  static Tbool calculateBadCharacterShift(const Tbool a_cIgnoreCaseFlag, const NDepth::NString::CString& a_crPattern, TCharacterTable& a_rBMBcF, TCharacterTable& a_rBMBcB);
  //! Calculate suffixes for the given string pattern.
  /*!
      \param a_cIgnoreCaseFlag - Ignore case flag.
      \param a_crPattern - Constant reference to the pattern string.
      \param a_rBMSuffixesF - Reference to the forward array of the suffixes values.
      \param a_rBMSuffixesB - Reference to the backward array of the suffixes values.
      \return true  - if suffixes for the given string pattern were successfully calculated. \n
              false - if suffixes for the given string pattern were not successfully calculated. \n
  */
  static Tbool calculateSuffixes(const Tbool a_cIgnoreCaseFlag, const NDepth::NString::CString& a_crPattern, NContainers::CArray<Tuint>& a_rBMSuffixesF, NContainers::CArray<Tuint>& a_rBMSuffixesB);
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
#include <Depth/include/algorithms/string/search/CStringSearchBoyerMoore.inl>
/*==========================================================================*/
#endif
