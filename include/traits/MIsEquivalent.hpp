/*!
 *  \file    MIsEquivalent.hpp Traits meta-class that helps to check if two
 *           given types are equivalent.
 *  \brief   Traits meta-class: equivalent types checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: equivalent types checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   12.03.2006 01:26:35

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
#ifndef __MISEQUIVALENT_HPP__
#define __MISEQUIVALENT_HPP__
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
//! Traits meta-class: equivalent types checking trait.
/*!
    Traits meta-class checks if two template arguments are  equivalent  types.
    Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsEquivalent<int, int>::yes                                  true
    MIsEquivalent<const int, const int&>::yes                     true
    MIsEquivalent<int, const int>::yes                            false
*/
template <typename T_Type1, typename T_Type2>
class MIsEquivalent :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: equivalent types checking trait (same specialization).
template <typename T_Type>
class MIsEquivalent<T_Type, T_Type> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: equivalent types checking trait (first reference specialization).
template <typename T_Type>
class MIsEquivalent<T_Type&, T_Type> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: equivalent types checking trait (second reference specialization).
template <typename T_Type>
class MIsEquivalent<T_Type, T_Type&> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: equivalent types checking trait (first constant reference specialization).
template <typename T_Type>
class MIsEquivalent<const T_Type&, const T_Type> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: equivalent types checking trait (second constant reference specialization).
template <typename T_Type>
class MIsEquivalent<const T_Type, const T_Type&> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: equivalent types checking trait (first volatile reference specialization).
template <typename T_Type>
class MIsEquivalent<volatile T_Type&, volatile T_Type> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: equivalent types checking trait (second volatile reference specialization).
template <typename T_Type>
class MIsEquivalent<volatile T_Type, volatile T_Type&> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: equivalent types checking trait (first constant volatile reference specialization).
template <typename T_Type>
class MIsEquivalent<const volatile T_Type&, const volatile T_Type> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: equivalent types checking trait (second constant volatile reference specialization).
template <typename T_Type>
class MIsEquivalent<const volatile T_Type, const volatile T_Type&> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
