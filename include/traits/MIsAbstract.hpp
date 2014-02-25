/*!
 *  \file    MIsAbstract.hpp Traits meta-class that helps to check if given
 *           type is an abstract type.
 *  \brief   Traits meta-class: abstract type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: abstract type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   13.12.2006 22:10:52

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
#ifndef __MISABSTRACT_HPP__
#define __MISABSTRACT_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MIfThenElse.hpp>
#include <Depth/include/traits/MIsAnd.hpp>
#include <Depth/include/traits/MIsNot.hpp>
#include <Depth/include/traits/MIsClassOrUnion.hpp>
#include <Depth/include/traits/details/MInArrayHelper.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: abstract type checking trait.
/*!
    Traits meta-class checks if template argument is an  abstract  type.  Here
    comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsAbstract<int>::yes                                         false
    MIsAbstract<class>::yes                                       false
    MIsAbstract<abstract class>::yes                              true
*/
template <typename T_Type>
class MIsAbstract :
  public MIfThenElse<MIsAnd<MIsNot<NDetails::MInArrayHelper<T_Type>::yes>::yes, MIsClassOrUnion<T_Type>::yes>::yes, MTypeTrue, MTypeFalse>::type
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
