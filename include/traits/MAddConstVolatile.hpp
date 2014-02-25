/*!
 *  \file    MAddConstVolatile.hpp Traits meta-class that helps to add both
 *           'const' and 'volatile' qualifiers to template parameter.
 *  \brief   Traits meta-class: adds both 'const' and 'volatile' qualifiers.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: adds both 'const' and 'volatile' qualifiers.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   09.03.2006 00:43:11

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
#ifndef __MADDCONSTVOLATILE_HPP__
#define __MADDCONSTVOLATILE_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: adds both 'const' and 'volatile' qualifiers.
/*!
    Traits meta-class adds both 'const' and  'volatile'  qualifiers  to  given
    type and put transformed type to the result meta-class  type.  Here  comes
    some examples of transformations:

    Expression:                                            Result type:
    MAddConstVolatile<int>::type                           int const volatile
    MAddConstVolatile<int&>::type                          int&
    MAddConstVolatile<int*>::type                          int* const volatile
    MAddConstVolatile<int const>::type                     int const volatile
    MAddConstVolatile<int volatile>::type                  int const volatile
    MAddConstVolatile<int const volatile>::type            int const volatile
*/
template <typename T_Type>
class MAddConstVolatile :
  public MType<const volatile T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: adds both 'const' and 'volatile' qualifiers (reference specialization).
template <typename T_Type>
class MAddConstVolatile<T_Type&> :
  public MType<T_Type&>
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
