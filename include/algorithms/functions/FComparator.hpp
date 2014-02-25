/*!
 *  \file    FComparator.hpp Comparator function class.
 *  \brief   Comparator function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparator function class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   20.07.2006 23:15:27

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
#ifndef __FCOMPARATOR_HPP__
#define __FCOMPARATOR_HPP__
/*==========================================================================*/
#include <Depth/include/concept/operators/MConceptBoolEqual.hpp>
#include <Depth/include/concept/operators/MConceptBoolLessThan.hpp>
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
//! Comparator function class.
/*!
    This class implements function object which  performs  compare  operation.
    Comparator function returns value less than 0 if X < Y, value 0  if  X  is
    equal to Y, value greater than 0 if X > Y.
*/
template <typename T_Argument1, typename T_Argument2 = T_Argument1>
class FComparator
{
  //! First argument type for the MConceptOperatorBoolEqual constraint checking.
  typedef T_Argument1 TArgument1BoolEqualCheckType;
  //! Second argument type for the MConceptOperatorBoolEqual constraint checking.
  typedef T_Argument2 TArgument2BoolEqualCheckType;
  //! First argument type for the MConceptOperatorBoolLessThan constraint checking.
  typedef T_Argument1 TArgument1BoolLessThanCheckType;
  //! Second argument type for the MConceptOperatorBoolLessThan constraint checking.
  typedef T_Argument2 TArgument2BoolLessThanCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef FComparator<T_Argument1, T_Argument2> TDepthCheckType;

  // Check template arguments constraint to be comparable with equal operator.
  REQUIRES_CONCEPT2(NConcept::NOperators, MConceptBoolEqual, TArgument1BoolEqualCheckType, TArgument2BoolEqualCheckType);
  // Check template arguments constraint to be comparable with less then operator.
  REQUIRES_CONCEPT2(NConcept::NOperators, MConceptBoolLessThan, TArgument1BoolLessThanCheckType, TArgument2BoolLessThanCheckType);
  // Check FComparator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Function return type.
  typedef Tsint TReturn;
  //! Function first argument type.
  typedef T_Argument1 TArgument1;
  //! Function second argument type.
  typedef T_Argument2 TArgument2;

  //! Operator: Call function.
  /*!
      \param a_Argument1 - First function argument.
      \param a_Argument2 - Second function argument.
      \return Function return value.
  */
  Tsint operator () (T_Argument1 a_Argument1, T_Argument2 a_Argument2) const;

  //! Serialize FComparator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two FComparator class instances.
  /*!
      \param a_rInstance - Reference to another FComparator class instance.
  */
  void swap(FComparator<T_Argument1, T_Argument2>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FComparator.inl>
/*==========================================================================*/
#endif
