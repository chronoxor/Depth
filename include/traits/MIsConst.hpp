/*!
 *  \file    MIsConst.hpp Traits meta-class that helps to check if given
 *           type has 'const' qualifier.
 *  \brief   Traits meta-class: 'const' qualifier appearance trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: 'const' qualifier appearance trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   10.03.2006 00:32:49

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
#ifndef __MISCONST_HPP__
#define __MISCONST_HPP__
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
//! Traits meta-class: 'const' qualifier appearance trait.
/*!
    Traits meta-class checks for appearance  of  'const'  qualifier  in  given
    type. Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsConst<int>::yes                                            false
    MIsConst<const int>::yes                                      true
    MIsConst<const volatile int&>::yes                            false
    MIsConst<const int* const>::yes                               true
*/
template <typename T_Type>
class MIsConst :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (constant specialization).
template <typename T_Type>
class MIsConst<const T_Type> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (constant volatile specialization).
template <typename T_Type>
class MIsConst<const volatile T_Type> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (constant array specialization).
template <typename T_Type>
class MIsConst<const T_Type[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (constant volatile array specialization).
template <typename T_Type>
class MIsConst<const volatile T_Type[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (indexed constant array specialization).
template <typename T_Type, Tuint t_N>
class MIsConst<const T_Type[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (indexed constant volatile array specialization).
template <typename T_Type, Tuint t_N>
class MIsConst<const volatile T_Type[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (reference specialization).
template <typename T_Type>
class MIsConst<T_Type&> :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (pointer specialization).
template <typename T_Type>
class MIsConst<T_Type*> :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (constant pointer specialization).
template <typename T_Type>
class MIsConst<T_Type* const> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (constant volatile pointer specialization).
template <typename T_Type>
class MIsConst<T_Type* const volatile> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
