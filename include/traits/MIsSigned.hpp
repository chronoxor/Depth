/*!
 *  \file    MIsSigned.hpp Traits meta-class that helps to check if given
 *           type is a signed integer type.
 *  \brief   Traits meta-class: signed integer type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    08.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: signed integer type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   08.11.2006 20:59:42

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
#ifndef __MISSIGNED_HPP__
#define __MISSIGNED_HPP__
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
//! Traits meta-class: signed integer type checking trait.
/*!
    Traits meta-class checks if template argument is a  signed  integer  type.
    Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsSigned<int>::yes                                           true
    MIsSigned<unsigned>::yes                                      false
    MIsSigned<const void&>::yes                                   false
*/
template <typename T_Type>
class MIsSigned :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (signed byte specialization).
template <>
class MIsSigned<Tsint08> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (constant signed byte specialization).
template <>
class MIsSigned<const Tsint08> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (volatile signed byte specialization).
template <>
class MIsSigned<volatile Tsint08> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (constant volatile signed byte specialization).
template <>
class MIsSigned<const volatile Tsint08> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (signed word specialization).
template <>
class MIsSigned<Tsint16> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (constant signed word specialization).
template <>
class MIsSigned<const Tsint16> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (volatile signed word specialization).
template <>
class MIsSigned<volatile Tsint16> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (constant volatile signed word specialization).
template <>
class MIsSigned<const volatile Tsint16> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (signed double word specialization).
template <>
class MIsSigned<Tsint32> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (constant double signed word specialization).
template <>
class MIsSigned<const Tsint32> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (volatile double signed word specialization).
template <>
class MIsSigned<volatile Tsint32> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (constant volatile double signed word specialization).
template <>
class MIsSigned<const volatile Tsint32> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (signed quadra word specialization).
template <>
class MIsSigned<Tsint64> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (constant quadra signed word specialization).
template <>
class MIsSigned<const Tsint64> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (volatile quadra signed word specialization).
template <>
class MIsSigned<volatile Tsint64> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: signed integer type checking trait (constant volatile quadra signed word specialization).
template <>
class MIsSigned<const volatile Tsint64> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
