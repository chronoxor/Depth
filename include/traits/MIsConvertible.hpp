/*!
 *  \file    MIsConvertible.hpp Traits meta-class that helps to check if two
 *           types are convertible classes.
 *  \brief   Traits meta-class: convertible types checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: convertible types checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   15.12.2006 21:50:38

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
#ifndef __MISCONVERTIBLE_HPP__
#define __MISCONVERTIBLE_HPP__
/*==========================================================================*/
#include <Depth/include/traits/details/MIsConvertibleHelper.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: convertible types checking trait.
/*!
    Traits meta-class checks if template arguments are convertible  types.  It
    means that their lvalues can be convertible or destination type  is  void.
    Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsConvertible<char, int>::yes                                true
    MIsConvertible<int, int>::yes                                 true
    MIsConvertible<int, void>::yes                                true
    MIsConvertible<base, derived>::yes                            false
    MIsConvertible<derived, base>::yes                            true
*/
template <class T_Source, class T_Destination>
class MIsConvertible :
  public MIfThenElse<NDetails::MIsConvertibleHelper<T_Source, T_Destination>::yes, MTypeTrue, MTypeFalse>::type
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
//! \example example-traits-MIsConvertible.cpp
/*--------------------------------------------------------------------------*/
//! \test test-traits-MIsConvertible.cpp
/*==========================================================================*/
#endif
