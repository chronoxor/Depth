/*!
 *  \file    MRemovePointer.hpp Traits meta-class that helps to remove
 *           pointer qualifier from template parameter.
 *  \brief   Traits meta-class: removes pointer qualifier.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: removes pointer qualifier.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   09.03.2006 00:15:43

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
#ifndef __MREMOVEPOINTER_HPP__
#define __MREMOVEPOINTER_HPP__
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
//! Traits meta-class: removes pointer qualifier.
/*!
    Traits meta-class removes  pointer  qualifier  from  given  type  and  put
    transformed type to the result meta-class type. Here comes  some  examples
    of transformations:

    Expression:                                                   Result type:
    MRemovePointer<int>::type                                     int
    MRemovePointer<int const*>::type                              int const
    MRemovePointer<int const**>::type                             int const*
    MRemovePointer<int const&>::type                              int const&
    MRemovePointer<int const*&>::type                             int const*&
*/
template <typename T_Type>
class MRemovePointer :
  public MType<T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: removes pointer qualifier (pointer specialization).
template <typename T_Type>
class MRemovePointer<T_Type*> :
  public MType<T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: removes pointer qualifier (constant pointer specialization).
template <typename T_Type>
class MRemovePointer<T_Type* const> :
  public MType<T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: removes pointer qualifier (volatile pointer specialization).
template <typename T_Type>
class MRemovePointer<T_Type* volatile> :
  public MType<T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: removes pointer qualifier (constant volatile pointer specialization).
template <typename T_Type>
class MRemovePointer<T_Type* const volatile> :
  public MType<T_Type>
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
