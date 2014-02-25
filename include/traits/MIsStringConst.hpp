/*!
 *  \file    MIsStringConst.hpp Traits meta-class that helps to check if given
 *           type is a constant string type.
 *  \brief   Traits meta-class: constant string type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: constant string type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   28.03.2008 02:14:53

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
#ifndef __MISSTRINGCONST_HPP__
#define __MISSTRINGCONST_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MIfThenElse.hpp>
#include <Depth/include/traits/MIsString.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: constant string type checking trait.
/*!
    Traits meta-class checks if template argument is a constant  string  type.
    Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsString<int>::yes                                           false
    MIsString<char*>::yes                                         true
    MIsString<const wchar_t*>::yes                                true
*/
template <typename T_Type>
class MIsStringConst :
  public MIfThenElse<MIsString<T_Type>::yes, MTypeTrue, MTypeFalse>::type
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant string type checking trait (constant single byte string specialization).
template <>
class MIsStringConst<const Tschar*> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant string type checking trait (constant volatile single byte string specialization).
template <>
class MIsStringConst<const volatile Tschar*> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant string type checking trait (constant single byte string array specialization).
template <>
class MIsStringConst<const Tschar[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant string type checking trait (constant volatile single byte string array specialization).
template <>
class MIsStringConst<const volatile Tschar[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant string type checking trait (constant single byte fixed-size string array specialization).
template <Tuint t_N>
class MIsStringConst<const Tschar[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant string type checking trait (constant volatile single byte fixed-size string array specialization).
template <Tuint t_N>
class MIsStringConst<const volatile Tschar[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant string type checking trait (constant wide string specialization).
template <>
class MIsStringConst<const Twchar*> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant string type checking trait (constant volatile wide string specialization).
template <>
class MIsStringConst<const volatile Twchar*> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant string type checking trait (constant wide string array specialization).
template <>
class MIsStringConst<const Twchar[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant string type checking trait (constant volatile wide string array specialization).
template <>
class MIsStringConst<const volatile Twchar[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant string type checking trait (constant wide fixed-size string array specialization).
template <Tuint t_N>
class MIsStringConst<const Twchar[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant string type checking trait (constant volatile wide fixed-size string array specialization).
template <Tuint t_N>
class MIsStringConst<const volatile Twchar[t_N]> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
