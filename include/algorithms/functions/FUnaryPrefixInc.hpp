/*!
 *  \file    FUnaryPrefixInc.hpp Unary prefix '++' operator function class.
 *  \brief   Unary prefix '++' operator function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unary prefix '++' operator function class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   20.07.2006 03:01:34

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
#ifndef __FUNARYPREFIXINC_HPP__
#define __FUNARYPREFIXINC_HPP__
/*==========================================================================*/
#include <Depth/include/concept/operators/MConceptUnaryPrefixInc.hpp>
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
//! Unary prefix '++' operator function class.
/*!
    This class implements function object which  performs  unary  prefix  '++'
    operation.
*/
template <typename T_Return, typename T_Argument = T_Return>
class FUnaryPrefixInc
{
  //! Return type for the MConceptOperatorPrefixInc constraint checking.
  typedef T_Return TReturnCheckType;
  //! Argument type for the MConceptOperatorPrefixInc constraint checking.
  typedef T_Argument TArgumentCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef FUnaryPrefixInc<T_Return, T_Argument> TDepthCheckType;

  // Check template arguments constraint to be applicable to the current function object class.
  REQUIRES_CONCEPT2(NConcept::NOperators, MConceptUnaryPrefixInc, TReturnCheckType, TArgumentCheckType);
  // Check FUnaryPrefixInc class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Function return type.
  typedef T_Return TReturn;
  //! Function argument type.
  typedef T_Argument TArgument;

  //! Operator: Call function.
  /*!
      \param a_Argument - Function argument.
      \return Function return value.
  */
  T_Return operator () (T_Argument a_Argument) const;

  //! Serialize FUnaryPrefixInc class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two FUnaryPrefixInc class instances.
  /*!
      \param a_rInstance - Reference to another FUnaryPrefixInc class instance.
  */
  void swap(FUnaryPrefixInc<T_Return, T_Argument>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FUnaryPrefixInc.inl>
/*==========================================================================*/
#endif
