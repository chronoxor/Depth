/*!
 *  \file    FHashInteger.hpp Hash integer function class.
 *  \brief   Hash integer function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Hash integer function class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   17.02.2010 02:10:12

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
#ifndef __FHASHINTEGER_HPP__
#define __FHASHINTEGER_HPP__
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptInteger.hpp>
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
//! Hash integer function class.
/*!
    This class implements hash integer function  object  which  performs  hash
    operation for the given integer and returns hash value which is  equvalent
    to the given integer value.
*/
template <typename T_Argument>
class FHashInteger
{
  //! Argument type for the MConceptInteger constraint checking.
  typedef T_Argument TIntegerCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef FHashInteger<T_Argument> TDepthCheckType;

  // Check T_Argument template argument constraint to be an integer type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptInteger, TIntegerCheckType);
  // Check FHashInteger class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Function return type.
  typedef Tuint TReturn;
  //! Function argument type.
  typedef T_Argument TArgument;

  //! Default class constructor.
  FHashInteger();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the FHashInteger class.
  */
  FHashInteger(const FHashInteger<T_Argument>& a_crInstance);

  //! Operator: Call function.
  /*!
      \param a_crArgument - Function argument.
      \return Function return value.
  */
  Tuint operator () (const T_Argument& a_crArgument) const;

  //! Serialize FHashInteger class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two FHashInteger class instances.
  /*!
      \param a_rInstance - Reference to another FHashInteger class instance.
  */
  void swap(FHashInteger<T_Argument>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FHashInteger.inl>
/*==========================================================================*/
#endif
