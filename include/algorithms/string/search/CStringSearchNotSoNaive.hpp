/*!
 *  \file    CStringSearchNotSoNaive.hpp Not So Naive (sub)string searching
 *           algorithm.
 *  \brief   Not So Naive (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Not So Naive (sub)string searching algorithm class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   15.01.2010 03:48:42

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
#ifndef __CSTRINGSEARCHNOTSONAIVE_HPP__
#define __CSTRINGSEARCHNOTSONAIVE_HPP__
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
//! Not So Naive (sub)string searching algorithm class.
/*!
    <b>Main features.</b>\n
    \li preprocessing phase in constant time and space;
    \li searching phase in O(nm) time complexity;
    \li slightly (by coefficient) sub-linear in the average case.

    <b>Description.</b>\n
    During the searching phase of the Not So  Naive  algorithm  the  character
    comparisons are made with the pattern positions in the following order  1,
    2, ... , m-2, m-1, 0.

    For each attempt where the window is positioned on the text factor y[j  ..
    j+m-1]: if x[0]=x[1]  and  x[1]  neq  y[j+1]  of  if  x[0]  neq  x[1]  and
    x[1]=y[j+1] the pattern is shifted by  2  positions  at  the  end  of  the
    attempt and by 1 otherwise.

    Thus the preprocessing phase can be done in constant time and  space.  The
    searching phase of the Not So Naive algorithm has a quadratic  worst  case
    but it is slightly (by coefficient) sub-linear in the average case.

    <b>References.</b>\n
    \li EXACT STRING MATCHING ALGORITHMS. Animation in Java. Christian Charras
        - Thierry Lecroq. Laboratoire d'Informatique de Rouen.  Universite  de
        Rouen. Faculte des Sciences et des Techniques. 76821 Mont-Saint-Aignan
        Cedex. FRANCE
    \li CARDON, A., CHARRAS, C., 1996, Introduction a l'algorithmique et a  la
        programmation, Chapter 9, pp 254-279, Ellipses.
    \li HANCART C., 1992, Une analyse en moyenne de l'algorithme de Morris  et
        Pratt  et  de  ses  raffinements,  in   Theorie   des   Automates   et
        Applications, Actes des 2e Journees Franco-Belges, D. Krob ed., Rouen,
        France, 1991, PUR 176, Rouen, France, 99-110.
    \li HANCART, C., 1993. Analyse  exacte  et  en  moyenne  d'algorithmes  de
        recherche d'un motif dans un texte, Ph. D. Thesis, University Paris 7,
        France.

    <b>Taken from:</b>\n
    EXACT STRING MATCHING ALGORITHMS. Animation in Java.
    http://www-igm.univ-mlv.fr/~lecroq/string/index.html
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType>
class CStringSearchNotSoNaive :
  public IStringSearch<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType> TDepthCheckType;

  // Check CStringSearchNotSoNaive interface constraint to be a real Depth type.
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
  CStringSearchNotSoNaive(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchNotSoNaive class.
  */
  CStringSearchNotSoNaive(const CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchNotSoNaive();

  //! Operator: Assign another CStringSearchNotSoNaive class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchNotSoNaive class.
      \return Reference to the current class instance.
  */
  CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>& operator = (const CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Set another CStringSearchNotSoNaive class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchNotSoNaive class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>& a_crInstance);

  //! Serialize CStringSearchNotSoNaive class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchNotSoNaive class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchNotSoNaive class instance.
  */
  void swap(CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onClose();

private:
  NDepth::NString::CString m_Pattern;   //!< Search algorithm pattern.
  Tuint m_EllF;                         //!< Forward ell value.
  Tuint m_EllB;                         //!< Backward ell value.
  Tuint m_KF;                           //!< Forward K value.
  Tuint m_KB;                           //!< Backward K value.
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
#include <Depth/include/algorithms/string/search/CStringSearchNotSoNaive.inl>
/*==========================================================================*/
#endif
