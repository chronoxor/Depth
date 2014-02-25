/*!
 *  \file    CStringSearchKnuthMorrisPratt.hpp Knuth-Morris-Pratt (sub)string
 *           searching algorithm.
 *  \brief   Knuth-Morris-Pratt (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Knuth-Morris-Pratt (sub)string searching algorithm class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   14.01.2010 02:12:25

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
#ifndef __CSTRINGSEARCHKNUTHMORRISPRATT_HPP__
#define __CSTRINGSEARCHKNUTHMORRISPRATT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/search/CStringSearchMorrisPratt.hpp>
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
//! Knuth-Morris-Pratt (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li performs the comparisons from left to right;
    \li preprocessing phase in O(m) space and time complexity;
    \li searching phase  in  O(n+m)  time  complexity  (independent  from  the
        alphabet size);
    \li delay  bounded  by  logPhi(m)  where   Phi   is   the   golden   ratio
        ( Phi = (1 + sqrt(5)) / 2 ).

    <b>Description.</b>\n
    The design of the Knuth-Morris-Pratt algorithm follows a tight analysis of
    the  Morris  and  Pratt  algorithm.  Let  us  look  more  closely  at  the
    Morris-Pratt algorithm. It is  possible  to  improve  the  length  of  the
    shifts.

    Consider an attempt at a left position j, that is when the the  window  is
    positioned on the text  factor  y[j  ..  j+m-1].  Assume  that  the  first
    mismatch occurs between x[i] and y[i+j] with 0 < i < m. Then, x[0 ..  i-1]
    = y[j .. i+j-1] =u and a = x[i] neq y[i+j]=b.

    When shifting, it is reasonable to expect that a prefix v of  the  pattern
    matches some suffix of the portion u of the text. Moreover, if we want  to
    avoid another immediate mismatch, the character following the prefix v  in
    the pattern must be different from a. The longest such prefix v is  called
    the tagged border of u (it occurs at both ends of u followed by  different
    characters in x).

    This introduces the notation: let kmpNext[i] be the length of the  longest
    border of x[0 .. i-1] followed by a character c different from x[i] and -1
    if no such tagged border exits, for 0 < i leq m. Then, after a shift,  the
    comparisons can resume between characters x[kmpNext[i]] and y[i+j] without
    missing any occurrence of x in y, and avoiding a  backtrack  on  the  text
    (see picture below). The value of kmpNext[0] is set to -1.

    \image html Morris-Pratt.png "Shift in the Knuth-Morris-Pratt algorithm (v border of u and c neq b)."

    The table kmpNext can be computed  in  O(m)  space  and  time  before  the
    searching phase, applying the same  searching  algorithm  to  the  pattern
    itself, as if x=y.

    The   searching   phase   can   be   performed   in   O(m+n)   time.   The
    Knuth-Morris-Pratt  algorithm  performs  at  most  2n-1   text   character
    comparisons during the searching  phase.  The  delay  (maximal  number  of
    comparisons for a single text character) is bounded by logPhi(m) where Phi
    is the golden ratio ( Phi = (1 + sqrt(5)) / 2 ).

    <b>References.</b>\n
    \li EXACT STRING MATCHING ALGORITHMS. Animation in Java. Christian Charras
        - Thierry Lecroq. Laboratoire d'Informatique de Rouen.  Universite  de
        Rouen. Faculte des Sciences et des Techniques. 76821 Mont-Saint-Aignan
        Cedex. FRANCE
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
    \li BEAUQUIER,  D.,   BERSTEL,  J.,   CHRETIENNE,   P.,   1992,   Elements
        d'algorithmique, Chapter 10, pp 337-377, Masson, Paris.
    \li CORMEN, T.H., LEISERSON, C.E., RIVEST,  R.L.,  1990.  Introduction  to
        Algorithms, Chapter 34, pp 853-885, MIT Press.
    \li CROCHEMORE, M., 1997.  Off-line  serial  exact  string  searching,  in
        Pattern Matching Algorithms, ed. A. Apostolico and Z.  Galil,  Chapter
        1, pp 1-53, Oxford University Press.
    \li CROCHEMORE, M., HANCART, C., 1999, Pattern  Matching  in  Strings,  in
        Algorithms and Theory  of  Computation  Handbook,  M.J.  Atallah  ed.,
        Chapter 11, pp 11-1--11-28, CRC Press Inc., Boca Raton, FL.
    \li CROCHEMORE,  M.,  LECROQ,  T.,  1996,  Pattern   matching   and   text
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
    \li HANCART, C., 1992, Une analyse en moyenne de l'algorithme de Morris et
        Pratt  et  de  ses  raffinements,  in   Theorie   des   Automates   et
        Applications, Actes des 2e Journees Franco-Belges, D. Krob ed., Rouen,
        France, 1991, PUR 176, Rouen, France, 99-110.
    \li HANCART, C., 1993. Analyse  exacte  et  en  moyenne  d'algorithmes  de
        recherche d'un motif dans un texte, Ph. D. Thesis, University Paris 7,
        France.
    \li KNUTH D.E., MORRIS (Jr) J.H., PRATT V.R., 1977, Fast pattern  matching
        in strings, SIAM Journal on Computing 6(1):323-350.
    \li SEDGEWICK,  R.,  1988,   Algorithms,   Chapter   19,    pp.   277-292,
        Addison-Wesley Publishing Company.
    \li SEDGEWICK, R., 1988,  Algorithms  in  C,  Chapter  19,  Addison-Wesley
        Publishing Company.
    \li SEDGEWICK, R., FLAJOLET, P., 1996, An Introduction to the Analysis  of
        Algorithms, Chapter ?, pp. ??-??, Addison-Wesley Publishing Company.
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
class CStringSearchKnuthMorrisPratt :
  public CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchKnuthMorrisPratt interface constraint to be a real Depth type.
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
  CStringSearchKnuthMorrisPratt(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchKnuthMorrisPratt class.
  */
  CStringSearchKnuthMorrisPratt(const CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchKnuthMorrisPratt();

  //! Operator: Assign another CStringSearchKnuthMorrisPratt class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchKnuthMorrisPratt class.
      \return Reference to the current class instance.
  */
  CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchKnuthMorrisPratt class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchKnuthMorrisPratt class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchKnuthMorrisPratt class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchKnuthMorrisPratt class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchKnuthMorrisPratt class instance.
  */
  void swap(CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
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
#include <Depth/include/algorithms/string/search/CStringSearchKnuthMorrisPratt.inl>
/*==========================================================================*/
#endif
