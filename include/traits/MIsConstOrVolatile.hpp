/*!
 *  \file    MIsConstOrVolatile.hpp Traits meta-class that helps to check if
 *           given type has 'const' or 'volatile' qualifier.
 *  \brief   Traits meta-class: 'const' or 'volatile' qualifier appearance trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: 'const' or 'volatile' qualifier appearance trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   10.03.2006 00:43:21

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
#ifndef __MISCONSTORVOLATILE_HPP__
#define __MISCONSTORVOLATILE_HPP__
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
//! Traits meta-class: 'const' or 'volatile' qualifier appearance trait.
/*!
    Traits meta-class checks for appearance of 'const' or 'volatile' qualifier
    in given type. Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsConstOrVolatile<int>::yes                                  false
    MIsConstOrVolatile<const int>::yes                            true
    MIsConstOrVolatile<volatile int>::yes                         true
    MIsConstOrVolatile<const volatile int&>::yes                  false
    MIsConstOrVolatile<const int* const>::yes                     true
    MIsConstOrVolatile<const int* const volatile>::yes            true
*/
template <typename T_Type>
class MIsConstOrVolatile :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (constant specialization).
template <typename T_Type>
class MIsConstOrVolatile<const T_Type> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (volatile specialization).
template <typename T_Type>
class MIsConstOrVolatile<volatile T_Type> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (constant volatile specialization).
template <typename T_Type>
class MIsConstOrVolatile<const volatile T_Type> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (constant array specialization).
template <typename T_Type>
class MIsConstOrVolatile<const T_Type[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (volatile array specialization).
template <typename T_Type>
class MIsConstOrVolatile<volatile T_Type[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (constant volatile array specialization).
template <typename T_Type>
class MIsConstOrVolatile<const volatile T_Type[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (indexed constant array specialization).
template <typename T_Type, Tuint t_N>
class MIsConstOrVolatile<const T_Type[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (indexed volatile array specialization).
template <typename T_Type, Tuint t_N>
class MIsConstOrVolatile<volatile T_Type[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (indexed constant volatile array specialization).
template <typename T_Type, Tuint t_N>
class MIsConstOrVolatile<const volatile T_Type[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (reference specialization).
template <typename T_Type>
class MIsConstOrVolatile<T_Type&> :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (pointer specialization).
template <typename T_Type>
class MIsConstOrVolatile<T_Type*> :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (constant pointer specialization).
template <typename T_Type>
class MIsConstOrVolatile<T_Type* const> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (volatile pointer specialization).
template <typename T_Type>
class MIsConstOrVolatile<T_Type* volatile> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: both 'const' and 'volatile' qualifiers appearance trait (constant volatile pointer specialization).
template <typename T_Type>
class MIsConstOrVolatile<T_Type* const volatile> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
