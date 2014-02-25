/*!
 *  \file    MIsEnum.hpp Traits meta-class that helps to check if given type
 *           is a enumeration type.
 *  \brief   Traits meta-class: enumeration type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: enumeration type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   13.03.2006 21:34:37

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
#ifndef __MISENUM_HPP__
#define __MISENUM_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MIsArray.hpp>
#include <Depth/include/traits/MIsFunction.hpp>
#include <Depth/include/traits/MIsFundamental.hpp>
#include <Depth/include/traits/MIsMemberPointerToObject.hpp>
#include <Depth/include/traits/MIsPointer.hpp>
#include <Depth/include/traits/MIsReference.hpp>
#include <Depth/include/traits/MIsClassOrUnion.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: enumeration type checking trait.
/*!
    Traits meta-class checks if template argument is a enumeration type.  Here
    comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsEnum<int>::yes                                             false
    MIsEnum<enum>::yes                                            true
    MIsEnum<const void&>::yes                                     false
*/
template <typename T_Type>
class MIsEnum :
  public MIfThenElse<MIsNot<MIsOr<MIsFundamental<T_Type>::yes, MIsArray<T_Type>::yes, MIsPointer<T_Type>::yes, MIsReference<T_Type>::yes, MIsFunction<T_Type>::yes, MIsMemberPointerToObject<T_Type>::yes, MIsClassOrUnion<T_Type>::yes>::yes>::yes, MTypeTrue, MTypeFalse>::type
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
