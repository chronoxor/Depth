/*!
 *  \file    MIsUnsigned.hpp Traits meta-class that helps to check if given
 *           type is a unsigned integer type.
 *  \brief   Traits meta-class: unsigned integer type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    08.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: unsigned integer type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   08.11.2006 21:02:57

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
#ifndef __MISUNSIGNED_HPP__
#define __MISUNSIGNED_HPP__
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
//! Traits meta-class: unsigned integer type checking trait.
/*!
    Traits meta-class checks if template argument is a unsigned integer  type.
    Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsUnsigned<int>::yes                                         false
    MIsUnsigned<unsigned>::yes                                    true
    MIsUnsigned<const void&>::yes                                 false
*/
template <typename T_Type>
class MIsUnsigned :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (unsigned byte specialization).
template <>
class MIsUnsigned<Tuint08> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (constant unsigned byte specialization).
template <>
class MIsUnsigned<const Tuint08> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (volatile unsigned byte specialization).
template <>
class MIsUnsigned<volatile Tuint08> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (constant volatile unsigned byte specialization).
template <>
class MIsUnsigned<const volatile Tuint08> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (unsigned word specialization).
template <>
class MIsUnsigned<Tuint16> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (constant unsigned word specialization).
template <>
class MIsUnsigned<const Tuint16> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (volatile unsigned word specialization).
template <>
class MIsUnsigned<volatile Tuint16> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (constant volatile unsigned word specialization).
template <>
class MIsUnsigned<const volatile Tuint16> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (unsigned double word specialization).
template <>
class MIsUnsigned<Tuint32> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (constant double unsigned word specialization).
template <>
class MIsUnsigned<const Tuint32> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (volatile double unsigned word specialization).
template <>
class MIsUnsigned<volatile Tuint32> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (constant volatile double unsigned word specialization).
template <>
class MIsUnsigned<const volatile Tuint32> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (unsigned quadra word specialization).
template <>
class MIsUnsigned<Tuint64> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (constant quadra unsigned word specialization).
template <>
class MIsUnsigned<const Tuint64> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (volatile quadra unsigned word specialization).
template <>
class MIsUnsigned<volatile Tuint64> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: unsigned integer type checking trait (constant volatile quadra unsigned word specialization).
template <>
class MIsUnsigned<const volatile Tuint64> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
