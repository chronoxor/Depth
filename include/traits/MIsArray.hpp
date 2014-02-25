/*!
 *  \file    MIsArray.hpp Traits meta-class that helps to check if given
 *           type is a array type.
 *  \brief   Traits meta-class: array type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: array type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   10.03.2006 22:39:25

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
#ifndef __MISARRAY_HPP__
#define __MISARRAY_HPP__
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
//! Traits meta-class: array type checking trait.
/*!
    Traits meta-class checks if template argument is a array type. Here  comes
    some examples of using this trait:

    Expression:                                                   Result type:
    MIsArray<int>::yes                                            false
    MIsArray<volatile void[]>::yes                                true
    MIsArray<const int[4][5]>::yes                                true
*/
template <typename T_Type>
class MIsArray :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: array type checking trait (array specialization).
template <typename T_Type>
class MIsArray<T_Type[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: array type checking trait (constant array specialization).
template <typename T_Type>
class MIsArray<const T_Type[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: array type checking trait (volatile array specialization).
template <typename T_Type>
class MIsArray<volatile T_Type[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: array type checking trait (constant volatile array specialization).
template <typename T_Type>
class MIsArray<const volatile T_Type[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: array type checking trait (indexed array specialization).
template <typename T_Type, Tuint t_N>
class MIsArray<T_Type[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: array type checking trait (constant indexed array specialization).
template <typename T_Type, Tuint t_N>
class MIsArray<const T_Type[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: array type checking trait (volatile indexed array specialization).
template <typename T_Type, Tuint t_N>
class MIsArray<volatile T_Type[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: array type checking trait (constant volatile indexed array specialization).
template <typename T_Type, Tuint t_N>
class MIsArray<const volatile T_Type[t_N]> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
