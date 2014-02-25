/*!
 *  \file    MGetXSigned.hpp Traits meta-class that helps to get the inverted
 *           sign equivalent of the given type.
 *  \brief   Traits meta-class: get the inverted sign equivalent of the given type.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: get the inverted sign equivalent of the given type.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   03.04.2009 02:34:19

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
#ifndef __MGETXSIGNED_HPP__
#define __MGETXSIGNED_HPP__
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
//! Traits meta-class: get the inverted sign equivalent of the given type. General declaration for types without requested extent.
/*!
    Traits meta-class helps to get the inverted sign equivalent of  the  given
    type. Here comes some examples of using this trait:

    Expression:                                                  Result value:
    MGetXSigned<bool>::type                                      bool
    MGetXSigned<signed int>::type                                unsigned int
    MGetXSigned<unsigned int>::type                              signed int
*/
template <typename T_Type>
class MGetXSigned :
  public MType<T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Signed byte specialization.
template <>
class MGetXSigned<Tsint08> :
  public MType<Tuint08>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Unsigned byte specialization.
template <>
class MGetXSigned<Tuint08> :
  public MType<Tsint08>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Signed word specialization.
template <>
class MGetXSigned<Tsint16> :
  public MType<Tuint16>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Unsigned word specialization.
template <>
class MGetXSigned<Tuint16> :
  public MType<Tsint16>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Signed double word specialization.
template <>
class MGetXSigned<Tsint32> :
  public MType<Tuint32>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Unsigned double word specialization.
template <>
class MGetXSigned<Tuint32> :
  public MType<Tsint32>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Signed quadra word specialization.
template <>
class MGetXSigned<Tsint64> :
  public MType<Tuint64>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Unsigned quadra word specialization.
template <>
class MGetXSigned<Tuint64> :
  public MType<Tsint64>
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
