/*!
 *  \file    MIsString.hpp Traits meta-class that helps to check if given
 *           type is a mutable string type.
 *  \brief   Traits meta-class: mutable string type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: mutable string type checking trait.

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
#ifndef __MISSTRING_HPP__
#define __MISSTRING_HPP__
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
//! Traits meta-class: mutable string type checking trait.
/*!
    Traits meta-class checks if template argument is a  mutable  string  type.
    Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsString<int>::yes                                           false
    MIsString<char*>::yes                                         true
    MIsString<const wchar_t*>::yes                                false
*/
template <typename T_Type>
class MIsString :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: mutable string type checking trait (single byte string specialization).
template <>
class MIsString<Tschar*> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: mutable string type checking trait (volatile single byte string specialization).
template <>
class MIsString<volatile Tschar*> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: mutable string type checking trait (single byte string array specialization).
template <>
class MIsString<Tschar[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: mutable string type checking trait (volatile single byte string array specialization).
template <>
class MIsString<volatile Tschar[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: mutable string type checking trait (single byte fixed-size string array specialization).
template <Tuint t_N>
class MIsString<Tschar[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: mutable string type checking trait (volatile single byte fixed-size string array specialization).
template <Tuint t_N>
class MIsString<volatile Tschar[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: mutable string type checking trait (wide string specialization).
template <>
class MIsString<Twchar*> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: mutable string type checking trait (volatile wide string specialization).
template <>
class MIsString<volatile Twchar*> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: mutable string type checking trait (wide string array specialization).
template <>
class MIsString<Twchar[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: mutable string type checking trait (volatile wide string array specialization).
template <>
class MIsString<volatile Twchar[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: mutable string type checking trait (wide fixed-size string array specialization).
template <Tuint t_N>
class MIsString<Twchar[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: mutable string type checking trait (volatile wide fixed-size string array specialization).
template <Tuint t_N>
class MIsString<volatile Twchar[t_N]> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
