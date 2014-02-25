/*!
 *  \file    CStringSearchOneOf.hpp One Of (sub)string searching algorithm.
 *  \brief   One Of (sub)string searching algorithm class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: One Of (sub)string searching algorithm class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   15.02.2010 02:47:58

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
#ifndef __CSTRINGSEARCHONEOF_HPP__
#define __CSTRINGSEARCHONEOF_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/search/CStringSearchNotSoNaive.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/containers/CArray.hpp>
#include <Depth/include/containers/CStringBuffer.hpp>
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
//! One Of (sub)string searching algorithm class.
/*!
    One Of (sub)string searching  algorithm  uses  provided  through  template
    another (sub)string searching algorithm to search for one of the  multiple
    provided patterns.
*/
template <typename T_SourceStringType, typename T_PatternStringType = T_SourceStringType, class T_StringSearchAlgorithm = CStringSearchNotSoNaive<T_SourceStringType, T_PatternStringType> >
class CStringSearchOneOf :
  public IStringSearch<T_SourceStringType, T_PatternStringType>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm> TDepthCheckType;

  // Check CStringSearchOneOf interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! String type of the search algorithm.
  typedef T_SourceStringType TStringType;
  //! Pattern string type of the search algorithm.
  typedef T_PatternStringType TPatternType;
  //! Base (sub)string searching algorithm.
  typedef T_StringSearchAlgorithm TStringSearchAlgorithm;

  //! Default class constructor.
  /*!
      \param a_cIgnoreCaseFlag - Ignore case flag (default is false).
  */
  CStringSearchOneOf(const Tbool a_cIgnoreCaseFlag = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchOneOf class.
  */
  CStringSearchOneOf(const CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringSearchOneOf();

  //! Operator: Assign another CStringSearchOneOf class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchOneOf class.
      \return Reference to the current class instance.
  */
  CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>& operator = (const CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>& a_crInstance);

  //! Set another CStringSearchOneOf class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringSearchOneOf class.
      \return true  - if string algorithm was successfully set. \n
              false - if string algorithm was not successfully set. \n
  */
  Tbool set(const CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>& a_crInstance);

  //! Get non constant reference to the patterns string buffer.
  /*!
      \return Non constant reference to the patterns string buffer.
  */
  NContainers::CStringBuffer<NDepth::NString::CString>& getPatterns();
  //! Get constant reference to the patterns string buffer.
  /*!
      \return Constant reference to the patterns string buffer.
  */
  const NContainers::CStringBuffer<NDepth::NString::CString>& getPatterns() const;

  //! Serialize CStringSearchOneOf class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringSearchOneOf class instances.
  /*!
      \param a_rInstance - Reference to another CStringSearchOneOf class instance.
  */
  void swap(CStringSearchOneOf<T_SourceStringType, T_PatternStringType, T_StringSearchAlgorithm>& a_rInstance);

protected:
  // IStringSearch interface overriding methods.
  virtual Tbool onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
  virtual Tbool onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
  virtual Tbool onClose();

private:
  NContainers::CStringBuffer<NDepth::NString::CString> m_StringBuffer; //!< String buffer with patterns.
  NContainers::CArray<T_StringSearchAlgorithm> m_StringSearchers;      //!< String searchers array.
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
#include <Depth/include/algorithms/string/search/CStringSearchOneOf.inl>
/*==========================================================================*/
#endif
