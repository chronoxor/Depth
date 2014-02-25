/*!
 *  \file    MIsBaseOf.hpp Traits meta-class that helps to check if given
 *           types are base and derived classes.
 *  \brief   Traits meta-class: base class of derived checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: base class of derived checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   15.12.2006 02:57:36

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
#ifndef __MISBASEOF_HPP__
#define __MISBASEOF_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MIsAnd.hpp>
#include <Depth/include/traits/MIsOr.hpp>
#include <Depth/include/traits/MIsSame.hpp>
#include <Depth/include/traits/MIsClassOrUnion.hpp>
#include <Depth/include/traits/details/MIsBaseOfHelper.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: base class of derived checking trait.
/*!
    Traits meta-class checks  if  template  arguments  are  base  and  derived
    classes. Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsBaseOf<char, int>::yes                                     false
    MIsBaseOf<int, int>::yes                                      true
    MIsBaseOf<class, class>::yes                                  true
    MIsBaseOf<base, nonderived>::yes                              false
    MIsBaseOf<base, derived>::yes                                 true
*/
template <class T_Base, class T_Derived>
class MIsBaseOf :
  public MIfThenElse<MIsOr<MIsSame<T_Base, T_Derived>::yes, MIsAnd<MIsClassOrUnion<T_Base>::yes, MIsClassOrUnion<T_Derived>::yes, NDetails::MIsBaseOfHelper<T_Base, T_Derived>::yes>::yes>::yes, MTypeTrue, MTypeFalse>::type
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
//! \example example-traits-MIsBaseOf.cpp
/*--------------------------------------------------------------------------*/
//! \test test-traits-MIsBaseOf.cpp
/*==========================================================================*/
#endif
