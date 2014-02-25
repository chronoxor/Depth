/*!
 *  \file    MIsConstAndVolatile.hpp Traits meta-class that helps to check if
 *           given type has both 'const' and 'volatile' qualifiers.
 *  \brief   Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   10.03.2006 00:38:42

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
#ifndef __MISCONSTANDVOLATILE_HPP__
#define __MISCONSTANDVOLATILE_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MTypeTrue.hpp>
#include <Depth/include/traits/MTypeFalse.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait.
/*!
    Traits meta-class checks for appearance of  both  'const'  and  'volatile'
    qualifiers in given type. Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsConstAndVolatile<int>::yes                                 false
    MIsConstAndVolatile<const volatile int>::yes                  true
    MIsConstAndVolatile<const volatile int&>::yes                 false
    MIsConstAndVolatile<const int* const>::yes                    false
    MIsConstAndVolatile<const int* const volatile>::yes           true
*/
template <typename T_Type>
class MIsConstAndVolatile :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (constant volatile specialization).
template <typename T_Type>
class MIsConstAndVolatile<const volatile T_Type> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (constant volatile array specialization).
template <typename T_Type>
class MIsConstAndVolatile<const volatile T_Type[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (indexed constant volatile array specialization).
template <typename T_Type, Tuint t_N>
class MIsConstAndVolatile<const volatile T_Type[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (reference specialization).
template <typename T_Type>
class MIsConstAndVolatile<T_Type&> :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (pointer specialization).
template <typename T_Type>
class MIsConstAndVolatile<T_Type*> :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (constant volatile pointer specialization).
template <typename T_Type>
class MIsConstAndVolatile<T_Type* const volatile> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
