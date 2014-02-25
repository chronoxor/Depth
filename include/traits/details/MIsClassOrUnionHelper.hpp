/*!
 *  \file    MIsClassOrUnionHelper.hpp Traits helper meta-class that helps to
 *           check if given type is class or union type.
 *  \brief   Traits helper meta-class: class or union type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits helper meta-class: class or union type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits details
    VERSION:   1.0
    CREATED:   12.12.2006 22:18:36

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
#ifndef __MISCLASSORUNIONHELPER_HPP__
#define __MISCLASSORUNIONHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits helper meta-class: class or union type checking trait.
/*!
    Traits helper meta-class checks if template argument  is  union  or  class
    type.
*/
template <typename T_Type>
class MIsClassOrUnionHelper :
  public NDepth::NCommon::IStatic
{
  //! One byte structure type.
  struct SOneByteStruct { Tbyte m_Value; };
  //! Two byte structure type.
  struct STwoByteStruct { Tbyte m_Value[2]; };

  //! Union and class type checker.
  template <typename T_OtherType>
  static SOneByteStruct ClassOrUnionChecker(Tsint T_OtherType::*);
  //! Non union and class type checker.
  template <typename>
  static STwoByteStruct& ClassOrUnionChecker(...);

public:
  static const Tbool yes = (sizeof(ClassOrUnionChecker<T_Type>(0)) == sizeof(SOneByteStruct));
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
