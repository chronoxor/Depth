/*!
 *  \file    CStringSearchMorrisPratt.hpp Morris-Pratt (sub)string searching
 *           algorithm.
 *  \brief   Morris-Pratt (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Morris-Pratt (sub)string searching algorithm class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   14.01.2010 03:08:06

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
#ifndef __CSTRINGSEARCHMORRISPRATT_HPP__
#define __CSTRINGSEARCHMORRISPRATT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/search/IStringSearch.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/containers/CArray.hpp>
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
//! Morris-Pratt (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li performs the comparisons from left to right;
    \li preprocessing phase in O(m) space and time complexity;
    \li searching phase  in  O(n+m)  time  complexity  (independent  from  the
        alphabet size);
    \li performs at most 2n-1 information gathered during the scan of the text;
    \li delay bounded by m.

    <b>Description.</b>\n
    The design of the Morris-Pratt algorithm follows a tight analysis  of  the
    Brute Force algorithm, and especially on the way this  latter  wastes  the
    information gathered during the scan of the text.

    Let us look more closely at the brute force algorithm. It is  possible  to
    improve the length of the shifts and simultaneously remember some portions
    of the text  that  match  the  pattern.  This  saves  comparisons  between
    characters of the pattern and characters  of  the  text  and  consequently
    increases the speed of the search.

    Consider an attempt at a left position j on y, that is when the window  is
    positioned on the text  factor  y[j  ..  j+m-1].  Assume  that  the  first
    mismatch occurs between x[i] and y[i+j] with 0 < i < m. Then, x[0..i-1]  =
    y[j .. i+j-1] = u and a = x[i] neq y[i+j]=b.

    When shifting, it is reasonable to expect that a prefix v of  the  pattern
    matches some suffix of the portion u of the text. The longest such  prefix
    v is called the border of u (it occurs at both ends of u). This introduces
    the notation: let mpNext[i] be the length of the longest border of x[0  ..
    i-1] for 0 < i leq m. Then, after a  shift,  the  comparisons  can  resume
    between  characters  c=x[mpNext[i]]  and  y[i+j]=b  without  missing   any
    occurrence of x in y, and avoiding a backtrack on the  text  (see  picture
    below). The value of mpNext[0] is set to -1.

    \image html Morris-Pratt.png "Shift in the Morris-Pratt algorithm (v border of u)."

    The table mpNext can be  computed  in  O(m)  space  and  time  before  the
    searching phase, applying the same  searching  algorithm  to  the  pattern
    itself, as if x=y.

    Then the searching phase can be done  in  O(m+n)  time.  The  Morris-Pratt
    algorithm performs at most 2n-1  text  character  comparisons  during  the
    searching phase. The delay (maximal number of  comparisons  for  a  single
    text character) is bounded by m.

    <b>References.</b>\n
    \li EXACT STRING MATCHING ALGORITHMS. Animation in Java. Christian Charras
        - Thierry Lecroq. Laboratoire d'Informatique de Rouen.  Universite  de
        Rouen. Faculte des Sciences et des Techniques. 76821 Mont-Saint-Aignan
        Cedex. FRANCE
    \li AHO, A.V., HOPCROFT, J.E., ULLMAN, J.D., 1974, The design and analysis
        of  computer  algorithms,  2nd  Edition,  Chapter  9,  pp.   317--361,
        Addison-Wesley Publishing Company.
    \li BEAUQUIER,  D.,  BERSTEL,   J.,   CHRETIENNE,   P.,   1992,   Elements
        d'algorithmique, Chapter 10, pp 337-377, Masson, Paris.
    \li CROCHEMORE, M., 1997.  Off-line  serial  exact  string  searching,  in
        Pattern Matching Algorithms, ed. A. Apostolico and Z.  Galil,  Chapter
        1, pp 1-53, Oxford University Press.
    \li HANCART, C., 1992, Une analyse en moyenne de l'algorithme de Morris et
        Pratt  et  de  ses  raffinements,  in   Theorie   des   Automates   et
        Applications, Actes des 2e Journees Franco-Belges, D. Krob ed., Rouen,
        France, 1991, PUR 176, Rouen, France, 99-110.
    \li HANCART, C., 1993. Analyse  exacte  et  en  moyenne  d'algorithmes  de
        recherche d'un motif dans un texte, Ph. D. Thesis, University Paris 7,
        France.
    \li MORRIS  (Jr)  J.H.,  PRATT  V.R.,  1970,   A  linear  pattern-matching
        algorithm, Technical Report 40, University of California, Berkeley.

    <b>Taken from:</b>\n
    EXACT STRING MATCHING ALGORITHMS. Animation in Java.
    http://www-igm.univ-mlv.fr/~lecroq/string/index.html
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType>
class CStringSearchMorrisPratt :
  public IStringSearch<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchMorrisPratt interface constraint to be a real Depth type.
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
  CStringSearchMorrisPratt(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchMorrisPratt class.
  */
  CStringSearchMorrisPratt(const CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchMorrisPratt();

  //! Operator: Assign another CStringSearchMorrisPratt class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchMorrisPratt class.
      \return Reference to the current class instance.
  */
  CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchMorrisPratt class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchMorrisPratt class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchMorrisPratt class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchMorrisPratt class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchMorrisPratt class instance.
  */
  void swap(CStringSearchMorrisPratt<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onClose();

protected:
  NDepth::NString::CString m_Pattern;   //!< Search algorithm pattern.
  NContainers::CArray<Tuint> m_NextF;   //!< Forward pattern shift values.
  NContainers::CArray<Tuint> m_NextB;   //!< Backward pattern shift values.
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
#include <Depth/include/algorithms/string/search/CStringSearchMorrisPratt.inl>
/*==========================================================================*/
#endif
