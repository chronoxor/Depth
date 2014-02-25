/*!
 *  \file    MIsInteger.hpp Traits meta-class that helps to check if given
 *           type is a integer type.
 *  \brief   Traits meta-class: integer type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: integer type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   10.03.2006 23:17:13

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
#ifndef __MISINTEGER_HPP__
#define __MISINTEGER_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MIfThenElse.hpp>
#include <Depth/include/traits/MIsOr.hpp>
#include <Depth/include/traits/MIsSigned.hpp>
#include <Depth/include/traits/MIsUnsigned.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: integer type checking trait.
/*!
    Traits meta-class checks if template argument is a integer type. This type
    is valid for: MIsSigned and MIsUnsigned types. Here comes some examples of
    using this trait:

    Expression:                                                   Result type:
    MIsInteger<int>::yes                                          true
    MIsInteger<void>::yes                                         false
    MIsInteger<const void&>::yes                                  false
*/
template <typename T_Type>
class MIsInteger :
  public MIfThenElse<MIsOr<MIsSigned<T_Type>::yes, MIsUnsigned<T_Type>::yes>::yes, MTypeTrue, MTypeFalse>::type
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
