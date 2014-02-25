/*!
 *  \file    MGetUnsigned.hpp Traits meta-class that helps to get the unsigned
 *           equivalent of the given type.
 *  \brief   Traits meta-class: get the unsigned equivalent of the given type.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: get the unsigned equivalent of the given type.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   03.04.2009 02:32:02

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
#ifndef __MGETUNSIGNED_HPP__
#define __MGETUNSIGNED_HPP__
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
//! Traits meta-class: get the unsigned equivalent of the given type. General declaration for types without requested extent.
/*!
    Traits meta-class helps to get the unsigned equivalent of the given  type.
    Here comes some examples of using this trait:

    Expression:                                                  Result value:
    MGetUnsigned<bool>::type                                     bool
    MGetUnsigned<signed int>::type                               unsigned int
    MGetUnsigned<unsigned int>::type                             unsigned int
*/
template <typename T_Type>
class MGetUnsigned :
  public MType<T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Signed byte specialization.
template <>
class MGetUnsigned<Tsint08> :
  public MType<Tuint08>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Signed word specialization.
template <>
class MGetUnsigned<Tsint16> :
  public MType<Tuint16>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Signed double word specialization.
template <>
class MGetUnsigned<Tsint32> :
  public MType<Tuint32>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Signed quadra word specialization.
template <>
class MGetUnsigned<Tsint64> :
  public MType<Tuint64>
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
