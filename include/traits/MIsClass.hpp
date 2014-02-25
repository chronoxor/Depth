/*!
 *  \file    MIsClass.hpp Traits meta-class that helps to check if given type
 *           is a class type.
 *  \brief   Traits meta-class: class type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: class type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   13.03.2006 22:24:17

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
#ifndef __MISCLASS_HPP__
#define __MISCLASS_HPP__
/*==========================================================================*/
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
//! Traits meta-class: class type checking trait.
/*!
    Traits meta-class checks if template argument is a class type.  Note  that
    currently we cannot separate  class  and  union  types!  Here  comes  some
    examples of using this trait:

    Expression:                                                   Result type:
    MIsClass<int>::yes                                            false
    MIsClass<class>::yes                                          true
    MIsClass<union>::yes                                          true
    MIsClass<const void&>::yes                                    false
*/
template <typename T_Type>
class MIsClass :
  public MIfThenElse<MIsClassOrUnion<T_Type>::yes, MTypeTrue, MTypeFalse>::type
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
