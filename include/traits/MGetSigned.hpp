/*!
 *  \file    MGetSigned.hpp Traits meta-class that helps to get the signed
 *           equivalent of the given type.
 *  \brief   Traits meta-class: get the signed equivalent of the given type.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: get the signed equivalent of the given type.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   03.04.2009 02:26:25

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
#ifndef __MGETSIGNED_HPP__
#define __MGETSIGNED_HPP__
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
//! Traits meta-class: get the signed equivalent of the given type. General declaration for types without requested extent.
/*!
    Traits meta-class helps to get the signed equivalent of  the  given  type.
    Here comes some examples of using this trait:

    Expression:                                                  Result value:
    MGetSigned<bool>::type                                       bool
    MGetSigned<signed int>::type                                 signed int
    MGetSigned<unsigned int>::type                               signed int
*/
template <typename T_Type>
class MGetSigned :
  public MType<T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Unsigned byte specialization.
template <>
class MGetSigned<Tuint08> :
  public MType<Tsint08>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Unsigned word specialization.
template <>
class MGetSigned<Tuint16> :
  public MType<Tsint16>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Unsigned double word specialization.
template <>
class MGetSigned<Tuint32> :
  public MType<Tsint32>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: get the signed equivalent of the given type. Unsigned quadra word specialization.
template <>
class MGetSigned<Tuint64> :
  public MType<Tsint64>
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
