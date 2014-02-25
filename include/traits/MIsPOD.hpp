/*!
 *  \file    MIsPOD.hpp Traits meta-class that helps to check if given type
 *           is a plane old data (POD) type.
 *  \brief   Traits meta-class: plane old data (POD) type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: plane old data (POD) type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   13.12.2006 22:37:25

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
#ifndef __MISPOD_HPP__
#define __MISPOD_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MIfThenElse.hpp>
#include <Depth/include/traits/MIsScalar.hpp>
#include <Depth/include/traits/MIsVoid.hpp>
#include <Depth/include/traits/MRemoveAllBounds.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: plane old data (POD) type checking trait.
/*!
    Traits meta-class checks if template argument is a plane  old  data  (POD)
    type. This type is valid for: MIsVoid, MIsScalar<MRemoveAllBounds>  types.
    Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsPOD<bool>::yes                                             true
    MIsPOD<char*>::yes                                            true
    MIsPOD<abstract class>::yes                                   false
*/
template <typename T_Type>
class MIsPOD :
  public MIfThenElse<MIsOr<MIsVoid<T_Type>::yes, MIsScalar<typename MRemoveAllBounds<T_Type>::type>::yes>::yes, MTypeTrue, MTypeFalse>::type
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
