/*!
 *  \file    FBoolNotEqualZero.hpp Boolean not equal to zero function class.
 *  \brief   Boolean not equal to zero function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Boolean not equal to zero function class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   20.07.2006 03:33:28

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
#ifndef __FBOOLNOTEQUALZERO_HPP__
#define __FBOOLNOTEQUALZERO_HPP__
/*==========================================================================*/
#include <Depth/include/concept/operators/MConceptBoolNotEqual.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NFunctions {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Boolean not equal to zero function class.
/*!
    This class implements function object which performs  not  equal  to  zero
    predicate operation.
*/
template <typename T_Argument>
class FBoolNotEqualZero
{
  //! First argument type for the MConceptOperatorBoolNotEqual constraint checking.
  typedef T_Argument TArgument1CheckType;
  //! Second argument type for the MConceptOperatorBoolNotEqual constraint checking.
  typedef Tsint TArgument2CheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef FBoolNotEqualZero<T_Argument> TDepthCheckType;

  // Check template arguments constraint to be applicable to the current function object class.
  REQUIRES_CONCEPT2(NConcept::NOperators, MConceptBoolNotEqual, TArgument1CheckType, TArgument2CheckType);
  // Check FBoolNotEqualZero class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Function return type.
  typedef Tbool TReturn;
  //! Function argument type.
  typedef T_Argument TArgument;

  //! Operator: Call function.
  /*!
      \param a_Argument - Function argument.
      \return Function return value.
  */
  Tbool operator () (T_Argument a_Argument) const;

  //! Serialize FBoolNotEqualZero class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two FBoolNotEqualZero class instances.
  /*!
      \param a_rInstance - Reference to another FBoolNotEqualZero class instance.
  */
  void swap(FBoolNotEqualZero<T_Argument>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolNotEqualZero.inl>
/*==========================================================================*/
#endif
