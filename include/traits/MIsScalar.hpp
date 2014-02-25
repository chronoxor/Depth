/*!
 *  \file    MIsScalar.hpp Traits meta-class that helps to check if given
 *           type is a scalar type.
 *  \brief   Traits meta-class: scalar type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: scalar type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   13.12.2006 22:23:53

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
#ifndef __MISSCALAR_HPP__
#define __MISSCALAR_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MIfThenElse.hpp>
#include <Depth/include/traits/MIsArithmetic.hpp>
#include <Depth/include/traits/MIsEnum.hpp>
#include <Depth/include/traits/MIsPointer.hpp>
#include <Depth/include/traits/MIsMemberPointerToObject.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: scalar type checking trait.
/*!
    Traits meta-class checks if template argument is a scalar type. This  type
    is valid for: MIsArithmetic, MIsEnum,  MIsPointer  and  MIsPointerToMember
    types. Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsScalar<bool>::yes                                          true
    MIsScalar<char*>::yes                                         true
    MIsScalar<class>::yes                                         false
*/
template <typename T_Type>
class MIsScalar :
  public MIfThenElse<MIsOr<MIsArithmetic<T_Type>::yes, MIsEnum<T_Type>::yes, MIsPointer<T_Type>::yes, MIsMemberPointerToObject<T_Type>::yes>::yes, MTypeTrue, MTypeFalse>::type
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
