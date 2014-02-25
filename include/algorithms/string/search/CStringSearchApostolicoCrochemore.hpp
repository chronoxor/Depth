/*!
 *  \file    CStringSearchApostolicoCrochemore.hpp Apostolico-Crochemore
 *           (sub)string searching algorithm.
 *  \brief   Apostolico-Crochemore (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Apostolico-Crochemore (sub)string searching algorithm class.

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
#ifndef __CSTRINGSEARCHAPOSTOLICOCROCHEMORE_HPP__
#define __CSTRINGSEARCHAPOSTOLICOCROCHEMORE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/search/CStringSearchKnuthMorrisPratt.hpp>
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
//! Apostolico-Crochemore (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li preprocessing phase in O(m) time and space complexity;
    \li searching phase in O(n) time complexity;
    \li performs 3/2*n text character comparisons in the worst case.

    <b>Description.</b>\n
    The Apostolico-Crochemore uses the kmpNext shift table (see chapter Knuth,
    Morris and Pratt algorithm) to compute the shifts.

    Let ell=0 if x is a power of a single character (x=cm with c in Sigma) and
    ell be equal to the position of the first character of  x  different  from
    x[0] otherwise (x=aellbu for a, b in Sigma, u in  Sigma*  and  a  neq  b).
    During each attempt the comparisons are made with pattern positions in the
    following order: ell, ell+1, ... , m-2, m-1, 0, 1, ... , ell-1.

    During the searching phase we consider triple of the form (i, j, k) where:
    \li the window is positioned on the text factor y[j .. j+m-1];
    \li 0 leq k leq ell and x[0 .. k-1]=y[j .. j+k-1];
    \li ell leq i < m and x[ell .. i-1]=y[j+ell .. i+j-1].

    The initial triple is (ell,0,0).

    \image html Apostolico-Crochemore.png "At each attempt of the Apostolico-Crochemore algorithm we consider a triple (i,j,k)."

    We now explain how to compute the  next  triple  after  (i,j,k)  has  been
    computed.

    Three cases arise depending on the value of i:
    \li i = ell. If x[i] = y[i+j] then the next triple is (i+1, j, k). If x[i]
        neq y[i+j] then the next triple is (ell, j+1, max{0, k-1}).
    \li ell < i < m. If x[i] = y[i+j] then the next triple is (i+1, j, k).  If
        x[i] neq y[i+j] then  two  cases  arise  depending  on  the  value  of
        kmpNext[i]: 1) kmpNext[i] leq ell:  then  the  next  triple  is  (ell,
        i+j-kmpNext[i], max{0, kmpNext[i]}); 2) kmpNext[i]  >  ell:  then  the
        next triple is (kmpNext[i], i+j-kmpNext[i], ell).

    \li i = m. If k < ell and x[k]=y[j+k] then the next triple is (i, j, k+1).
        Otherwise either k < ell and x[k] neq y[j+k], or k=ell.  If  k=ell  an
        occurrence of x is reported. In both cases the next triple is computed
        in the same manner as in the case where ell < i < m.

    The preprocessing phase consists in computing the table  kmpNext  and  the
    integer ell. It can be done in O(m) space and time. The searching phase is
    in  O(n)  time  complexity  and  furthermore   the   Apostolico-Crochemore
    algorithm performs at most 3/2n text character comparisons  in  the  worst
    case.

    <b>References.</b>\n
    \li EXACT STRING MATCHING ALGORITHMS. Animation in Java. Christian Charras
        - Thierry Lecroq. Laboratoire d'Informatique de Rouen.  Universite  de
        Rouen. Faculte des Sciences et des Techniques. 76821 Mont-Saint-Aignan
        Cedex. FRANCE
    \li APOSTOLICO A.,  CROCHEMORE  M.,  1991,  Optimal  canonization  of  all
        substrings of a string, Information and Computation 95(1):76-95.
    \li HANCART, C., 1993. Analyse  exacte  et  en  moyenne  d'algorithmes  de
        recherche d'un motif dans un texte, Ph. D. Thesis, University Paris 7, France.

    <b>Taken from:</b>\n
    EXACT STRING MATCHING ALGORITHMS. Animation in Java.
    http://www-igm.univ-mlv.fr/~lecroq/string/index.html
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType>
class CStringSearchApostolicoCrochemore :
  public CStringSearchKnuthMorrisPratt<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchApostolicoCrochemore interface constraint to be a real Depth type.
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
  CStringSearchApostolicoCrochemore(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchApostolicoCrochemore class.
  */
  CStringSearchApostolicoCrochemore(const CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchApostolicoCrochemore();

  //! Operator: Assign another CStringSearchApostolicoCrochemore class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchApostolicoCrochemore class.
      \return Reference to the current class instance.
  */
  CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchApostolicoCrochemore class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchApostolicoCrochemore class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchApostolicoCrochemore class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchApostolicoCrochemore class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchApostolicoCrochemore class instance.
  */
  void swap(CStringSearchApostolicoCrochemore<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);

private:
  Tuint m_EllF;                          //!< Forward ell value.
  Tuint m_EllB;                          //!< Backward ell value.
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
#include <Depth/include/algorithms/string/search/CStringSearchApostolicoCrochemore.inl>
/*==========================================================================*/
#endif
