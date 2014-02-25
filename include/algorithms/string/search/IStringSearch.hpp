/*!
 *  \file    IStringSearch.hpp Interface for all (sub)string searching
 *           algorithms.
 *  \brief   String searching algorithm interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: String searching algorithm interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   25.11.2009 20:05:10

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
#ifndef __ISTRINGSEARCH_HPP__
#define __ISTRINGSEARCH_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/AStringLength.hpp>
#include <Depth/include/algorithms/string/details/CStringSearchHelper.hpp>
#include <Depth/include/concept/base/MConceptStringConst.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/types/MConceptIString.hpp>
#include <Depth/include/string/CString.hpp>
#include <Depth/include/utility/CPair.hpp>
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
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! String searching algorithm interface.
/*!
    String searching algorithm interface is used as a base interface  for  all
    algorithms which allow to search for the (sub)string in the  given  source
    string.

    Before using search algorithm should be initialized with a string  pattern
    by calling a method 'initialize()'. Then searching could be performed with
    methods 'findNext()', 'findPrev()'. And finally string pattern  should  be
    disposed by calling a method 'close()'.

    <b>Introduction.</b>\n
    String-matching is a very important subject in the wider  domain  of  text
    processing.  String-matching  algorithms  are  basic  components  used  in
    implementations of  practical  softwares  existing  under  most  operating
    systems. Moreover,  they  emphasize  programming  methods  that  serve  as
    paradigms in other fields of computer science (system or software design).
    Finally, they also play an important role in theoretical computer  science
    by providing challenging problems.

    Although data are memorized in various ways, text remains the main form to
    exchange information.  This  is  particularly  evident  in  literature  or
    linguistics where data are composed of huge corpus and dictionaries.  This
    apply as well to computer science where a large amount of data are  stored
    in linear files. And this is also the case,  for  instance,  in  molecular
    biology  because  biological  molecules  can  often  be  approximated   as
    sequences of nucleotides or amino  acids.  Furthermore,  the  quantity  of
    available data in these fields tend to double every eighteen months.  This
    is the reason why algorithms should be efficient even  if  the  speed  and
    capacity of storage of computers increase regularly.

    String-matching consists in  finding  one,  or  more  generally,  all  the
    occurrences of a string (more generally called a pattern) in a  text.  All
    the algorithms in this book output all occurrences of the pattern  in  the
    text. The pattern is denoted by x=x[0 .. m-1]; its length is equal  to  m.
    The text is denoted by y=y[0 .. n-1]; its  length  is  equal  to  n.  Both
    strings are build over a  finite  set  of  character  called  an  alphabet
    denoted by Sigma with size is equal to sigma.

    Applications require two kinds of solution depending on which string,  the
    pattern or the text, is given  first.  Algorithms  based  on  the  use  of
    automata or combinatorial properties of strings are  commonly  implemented
    to preprocess the pattern and solve the first kind of problem. The  notion
    of indexes realized by trees or automata is used in  the  second  kind  of
    solutions. This book will only investigate algorithms of the first kind.

    String-matching algorithms of the present book work as follows. They  scan
    the text with the help of a window which size is  generally  equal  to  m.
    They first align the left ends of the window and the  text,  then  compare
    the characters of the window with the characters of  the  pattern  -  this
    specific work is called an attempt -  and  after  a  whole  match  of  the
    pattern or after a mismatch they shift  the  window  to  the  right.  They
    repeat the same procedure again until the right end  of  the  window  goes
    beyond the right end of the text. This mechanism  is  usually  called  the
    sliding window mechanism. We associate each attempt with the position j in
    the text when the window is positioned on y[j .. j+m-1].

    The Brute Force algorithm locates all occurrences of x in y in time O(mn).
    The many  improvements  of  the  brute  force  method  can  be  classified
    depending on the order they  performed  the  comparisons  between  pattern
    characters and text characters et each attempt. Four categories arise: the
    most natural way to perform the comparisons is from left to  right,  which
    is the reading direction; performing the comparisons from  right  to  left
    generally leads to the best algorithms in practice; the  best  theoretical
    bounds are reached when comparisons are done in a specific order;  finally
    there exist some algorithms for which the order in which  the  comparisons
    are done is not relevant (such is the brute force algorithm).

    <b>From left to right.</b>\n
    Hashing provides a simple method  that  avoids  the  quadratic  number  of
    character comparisons in most  practical  situations,  and  that  runs  in
    linear time  under  reasonable  probabilistic  assumptions.  It  has  been
    introduced by Harrison and later fully analyzed by Karp and Rabin.

    Assuming that the pattern length is no longer than the memory-word size of
    the machine, the Shift Or algorithm is an efficient algorithm to solve the
    exact string-matching problem and it adapts easily  to  a  wide  range  of
    approximate string-matching problems.

    The first linear-time string-matching algorithm is from Morris and  Pratt.
    It has been improved by Knuth, Morris and Pratt. The search behaves like a
    recognition process by automaton, and a character of the text is  compared
    to a character of the pattern no more than logPhi(m+1) (Phi is the  golden
    ratio golden ratio). Hancart proved that this delay of a related algorithm
    discovered by Simon makes  no  more  than  1+log2m  comparisons  per  text
    character. Those three algorithms perform  at  most  2n-1  text  character
    comparisons in the worst case.

    The search with a Deterministic Finite Automaton performs exactly  n  text
    character inspections but it requires an extra  space  in  O(msigma).  The
    Forward Dawg Matching algorithm performs exactly the same number  of  text
    character inspections using the suffix automaton of the pattern.

    The Apostolico-Crochemore algorithm is a simple algorithm  which  performs
    3/2n text character comparisons in the worst case.

    The Not So Naive algorithm is a very simple  algorithm  with  a  quadratic
    worst case time complexity  but  it  requires  a  preprocessing  phase  in
    constant time and space and is slightly sub-linear in the average case.

    <b>From right to left.</b>\n
    The  Boyer-Moore  algorithm  is   considered   as   the   most   efficient
    string-matching algorithm in usual applications. A simplified  version  of
    it (or the entire algorithm) is often implemented in text editors for  the
    "search" and "substitute" commands. Cole proved that the maximum number of
    character comparisons is tightly bounded by 3n after the preprocessing for
    non-periodic patterns. It has a quadratic worst  case  time  for  periodic
    patterns.

    Several  variants  of  the  Boyer-Moore  algorithm  avoid  its   quadratic
    behaviour. The most efficient  solutions  in  term  of  number  of  symbol
    comparisons have been designed by Apostolico and Giancarlo, Crochemore  et
    alii (Turbo BM), and Colussi (Reverse Colussi).

    Empirical results show that the variations of Boyer and Moore's  algorithm
    designed by Sunday (Quick Search) and an algorithm  based  on  the  suffix
    automaton by Crochemore et alii (Reverse Factor and Turbo Reverse  Factor)
    are the most efficient in practice.

    The Zhu and Takaoka and Berry-Ravindran algorithms  are  variants  of  the
    Boyer-Moore algorithm which require an extra space in O(sigma2).

    <b>In a specific order.</b>\n
    The two first linear optimal space string-matching algorithms are  due  to
    Galil-Seiferas and Crochemore-Perrin (Two Way algorithm).  They  partition
    the pattern in two parts, they first search for  the  right  part  of  the
    pattern from left to right and then if no mismatch occurs they search  for
    the left part.

    The algorithms of Colussi and Galil-Giancarlo partition the set of pattern
    positions into two subsets. They first search for the  pattern  characters
    which positions are in the first subset from left to right and then if  no
    mismatch occurs they search for the  remaining  characters  from  left  to
    right. The Colussi algorithm is an improvement over the Knuth-Morris-Pratt
    algorithm and performs at most 3/2n  text  character  comparisons  in  the
    worst case. The Galil-Giancarlo algorithm improves the  Colussi  algorithm
    in one special case  which  enables  it  to  perform  at  most  4/3n  text
    character comparisons in the worst case.

    Sunday's Optimal Mismatch and Maximal Shift algorithms  sort  the  pattern
    positions according their character  frequency  and  their  leading  shift
    respectively.

    Skip Search, KMP Skip Search and Alpha Skip Search algorithms  by  Charras
    (et alii) use buckets to determine starting positions on the  pattern  in  the
    text.

    <b>In any order.</b>\n
    The Horspool algorithm is a variant of the Boyer-Moore algorithm, it  uses
    one of his shift function and  the  order  in  which  the  text  character
    comparisons are performed is irrelevant. This is also  true  for  all  the
    other variants such as the Quick Search of Sunday,  Tuned  Boyer-Moore  of
    Hume and Sunday, the Smith algorithm and the Raita algorithm.

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
class IStringSearch
{
  //! Type for MConceptStringConst constraint checking.
  typedef T_SourceStringType TStringConstCheckType1;
  //! Type for MConceptStringConst constraint checking.
  typedef T_PatternStringType TStringConstCheckType2;
  //! Type for MConceptDepthType constraint checking.
  typedef IStringSearch<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check T_SourceStringType template argument constraint to be a constant string type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptStringConst, TStringConstCheckType1);
  // Check T_PatternStringType template argument constraint to be a constant string type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptStringConst, TStringConstCheckType2);
  // Check IStringSearch interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  //! Default interface protected constructor.
  /*!
      \param a_cIgnoreCaseFlag - Ignore case flag (default is false).
  */
  IStringSearch(const Tbool a_cIgnoreCaseFlag = false);
  //! Interface protected copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IStringSearch interface.
  */
  IStringSearch(const IStringSearch<T_SourceStringType, T_PatternStringType>& a_crInstance);

public:
  //! String type of the search algorithm.
  typedef T_SourceStringType TStringType;
  //! Pattern string type of the search algorithm.
  typedef T_PatternStringType TPatternType;

  //! Interface virtual destructor.
  virtual ~IStringSearch();

  //! Operator: Assign another IStringSearch interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IStringSearch interface.
      \return Reference to the current interface instance.
  */
  IStringSearch<T_SourceStringType, T_PatternStringType>& operator = (const IStringSearch<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another IStringSearch interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IStringSearch interface.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const IStringSearch<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set ignore case flag.
  /*!
      \param a_cIgnoreCaseFlag - Ignore case flag.
      \return true  - if ignore case flag was successfully set. \n
              false - if ignore case flag was not successfully set. \n
  */
  Tbool setIgnoreCaseFlag(const Tbool a_cIgnoreCaseFlag);
  //! Get ignore case flag.
  /*!
      \return Ignore case flag.
  */
  Tbool getIgnoreCaseFlag() const;

  //! Is string searching algorithm initialized?
  /*!
      \return true  - if stream is initialized. \n
              false - if stream is not initialized. \n
  */
  Tbool isInitialized() const;

  //! Initialize string searching algorithm with a pattern string.
  /*!
      The method initializes string searching algorithm with the given pattern
      string. It should be called before performing search operations.

      This  method  automatically  detects  size  of  pattern   string   using
      'strLen()' algorithm or 'getSize()' method.

      \param a_crPattern - Constant reference to the pattern string.
      \return true  - if the string searching algorithm was successfully initialized. \n
              false - if the string searching algorithm was not successfully initialized. \n
  */
  Tbool initialize(const T_PatternStringType& a_crPattern);
  //! Initialize string searching algorithm with a pattern string of given size.
  /*!
      The method initializes string searching algorithm with the given pattern
      string. It should be called before performing search operations.

      \param a_crPattern - Constant reference to the pattern string.
      \param a_cPatternLength - Maximal pattern string length.
      \return true  - if the string searching algorithm was successfully initialized. \n
              false - if the string searching algorithm was not successfully initialized. \n
  */
  Tbool initialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength);
  //! Initialize string searching algorithm with a pattern string of given size starting form the given index.
  /*!
      The method initializes string searching algorithm with the given pattern
      string. It should be called before performing search operations.

      \param a_crPattern - Constant reference to the pattern string.
      \param a_cPatternIndex - Offset index in pattern string.
      \param a_cPatternLength - Maximal pattern string length starting from offset.
      \return true  - if the string searching algorithm was successfully initialized. \n
              false - if the string searching algorithm was not successfully initialized. \n
  */
  Tbool initialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);

  //! Forward search string pattern in the given source string.
  /*!
      \param a_rFoundStart - Reference to the found start index position.
      \param a_rFoundEnd - Reference to the found end index position.
      \param a_crSource - Constant reference to the source string.
      \return true  - if the string pattern was successfully found. \n
              false - if the string pattern was not successfully found. \n
  */
  Tbool findNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource);
  //! Forward search string pattern in the given source string (maximal length version).
  /*!
      \param a_rFoundStart - Reference to the found start index position.
      \param a_rFoundEnd - Reference to the found end index position.
      \param a_crSource - Constant reference to the source string.
      \param a_cSourceLength - Maximal source string length.
      \return true  - if the string pattern was successfully found. \n
              false - if the string pattern was not successfully found. \n
  */
  Tbool findNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceLength);
  //! Forward search string pattern in the given source string (index offset and maximal length version).
  /*!
      \param a_rFoundStart - Reference to the found start index position.
      \param a_rFoundEnd - Reference to the found end index position.
      \param a_crSource - Constant reference to the source string.
      \param a_cSourceIndex - Offset index in source string.
      \param a_cSourceLength - Maximal source string length starting from offset.
      \return true  - if the string pattern was successfully found. \n
              false - if the string pattern was not successfully found. \n
  */
  Tbool findNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);

  //! Backward search string pattern in the given source string.
  /*!
      \param a_rFoundStart - Reference to the found start index position.
      \param a_rFoundEnd - Reference to the found end index position.
      \param a_crSource - Constant reference to the source string.
      \return true  - if the string pattern was successfully found. \n
              false - if the string pattern was not successfully found. \n
  */
  Tbool findPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource);
  //! Backward search string pattern in the given source string (maximal length version).
  /*!
      \param a_rFoundStart - Reference to the found start index position.
      \param a_rFoundEnd - Reference to the found end index position.
      \param a_crSource - Constant reference to the source string.
      \param a_cSourceLength - Maximal source string length.
      \return true  - if the string pattern was successfully found. \n
              false - if the string pattern was not successfully found. \n
  */
  Tbool findPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceLength);
  //! Backward search string pattern in the given source string (index offset and maximal length version).
  /*!
      \param a_rFoundStart - Reference to the found start index position.
      \param a_rFoundEnd - Reference to the found end index position.
      \param a_crSource - Constant reference to the source string.
      \param a_cSourceIndex - Offset index in source string.
      \param a_cSourceLength - Maximal source string length starting from offset.
      \return true  - if the string pattern was successfully found. \n
              false - if the string pattern was not successfully found. \n
  */
  Tbool findPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);

  //! Remove string pattern from the given source string.
  /*!
      \param a_rSource - Reference to the source string.
      \param a_cSourceIndex - Offset index in source string.
      \param a_cSourceLength - Maximal source string length starting from offset.
      \return Result of the operation (success flag, length of removed pattern).
  */
  template <class T_SourceStringClass>
  NUtility::CPair<Tbool, Tuint> remove(T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);

  //! Replace string pattern in the given source string.
  /*!
      \param a_rSource - Reference to the source string.
      \param a_cSourceIndex - Offset index in source string.
      \param a_cSourceLength - Maximal source string length starting from offset.
      \param a_crReplacePattern - Constant reference to the replace pattern string.
      \return Result of the operation (success flag, length of new pattern).
  */
  template <class T_SourceStringClass, typename T_ReplacePatternStringType>
  NUtility::CPair<Tbool, Tuint> replace(T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_ReplacePatternStringType& a_crReplacePattern);
  //! Replace string pattern in the given source string (maximal length version).
  /*!
      \param a_rSource - Reference to the source string.
      \param a_cSourceIndex - Offset index in source string.
      \param a_cSourceLength - Maximal source string length starting from offset.
      \param a_crReplacePattern - Constant reference to the replace pattern string.
      \param a_cReplacePatternLength - Maximal length value of the replace pattern string.
      \return Result of the operation (success flag, length of new pattern).
  */
  template <class T_SourceStringClass, typename T_ReplacePatternStringType>
  NUtility::CPair<Tbool, Tuint> replace(T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternLength);
  //! Replace string pattern in the given source string (index offset and maximal length version).
  /*!
      \param a_rSource - Reference to the source string.
      \param a_cSourceIndex - Offset index in source string.
      \param a_cSourceLength - Maximal source string length starting from offset.
      \param a_crReplacePattern - Constant reference to the replace pattern string.
      \param a_cReplacePatternIndex - Index offset value of the replace pattern string.
      \param a_cReplacePatternLength - Maximal length value of the replace pattern string.
      \return Result of the operation (success flag, length of new pattern).
  */
  template <class T_SourceStringClass, typename T_ReplacePatternStringType>
  NUtility::CPair<Tbool, Tuint> replace(T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternIndex, const Tuint a_cReplacePatternLength);

  //! Close string searching algorithm context.
  /*!
      The method closes string  searching  algorithm  context.  It  should  be
      called after performing search operations.

      \return true  - if the string searching algorithm context was successfully closed. \n
              false - if the string searching algorithm context was not successfully closed. \n
  */
  Tbool close();

  //! Serialize IStringSearch interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IStringSearch interface instances.
  /*!
      \param a_rInstance - Reference to another IStringSearch interface instance.
  */
  void swap(IStringSearch<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  //! Abstract method. Initialization method with safe arguments.
  /*!
      \param a_crPattern - Constant reference to the pattern string.
      \param a_cPatternIndex - Offset index in pattern string.
      \param a_cPatternLength - Pattern string length starting from offset.
      \return true  - if the string searching algorithm was successfully initialized. \n
              false - if the string searching algorithm was not successfully initialized. \n
  */
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength) = 0;
  //! Abstract method. Forward search string pattern in the given source string with safe arguments.
  /*!
      \param a_rFoundStart - Reference to the found start index position.
      \param a_rFoundEnd - Reference to the found end index position.
      \param a_crSource - Constant reference to the source string.
      \param a_cSourceIndex - Offset index in source string.
      \param a_cSourceLength - Source string length starting from offset.
      \return true  - if the string pattern was successfully found. \n
              false - if the string pattern was not successfully found. \n
  */
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength) = 0;
  //! Abstract method. Backward search string pattern in the given source string with safe arguments.
  /*!
      \param a_rFoundStart - Reference to the found start index position.
      \param a_rFoundEnd - Reference to the found end index position.
      \param a_crSource - Constant reference to the source string.
      \param a_cSourceIndex - Offset index in source string.
      \param a_cSourceLength - Source string length starting from offset.
      \return true  - if the string pattern was successfully found. \n
              false - if the string pattern was not successfully found. \n
  */
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength) = 0;
  //! Abstract method. Close string searching algorithm context.
  /*!
      \return true  - if the string searching algorithm context was successfully closed. \n
              false - if the string searching algorithm context was not successfully closed. \n
  */
  virtual Tbool onClose() = 0;

  //! Update replace pattern.
  /*!
      Method is called automatically  form  'replace()'  method  in  order  to
      update replace pattern. Default implementation  does  nothing,  but  the
      behavior can be changed in  order  to  support  regular-expressions-like
      replace patterns.

      \param a_rReplacePattern - Reference to the replace pattern string.
      \return true  - if the string pattern was successfully updated. \n
              false - if the string pattern was not successfully updated. \n
  */
  virtual Tbool updateReplacePattern(NDepth::NString::CString& a_rReplacePattern);

private:
  Tbool m_IsInitialized;                //!< Initialization flag.
  Tbool m_IgnoreCaseFlag;               //!< Ignore case flag.
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
#include <Depth/include/algorithms/string/search/IStringSearch.inl>
/*==========================================================================*/
#endif
