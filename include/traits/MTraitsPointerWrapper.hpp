/*!
 *  \file    MTraitsPointerWrapper.hpp Traits meta-class that helps to
 *           determine pointer wrapper base type.
 *  \brief   Traits meta-class: pointer wrapper's traits.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.10.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: pointer wrapper's traits.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   10.10.2006 00:12:53

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
#ifndef __MTRAITSPOINTERWRAPPER_HPP__
#define __MTRAITSPOINTERWRAPPER_HPP__
/*==========================================================================*/
#include <Depth/include/base/CPointer.hpp>
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
//! Traits meta-class: pointer wrapper's traits.
/*!
    Traits meta-class helps to determine pointer  wrapper's  attributes.  With
    this traits you can determine base type of the pointer wrapper's object.
*/
template <typename T_Type>
class MTraitsPointerWrapper :
  public MType<T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: pointer wrapper's traits (pointer wrapper specialization).
template <typename T_Type>
class MTraitsPointerWrapper<NBase::CPointer<T_Type> > :
  public MType<typename NBase::CPointer<T_Type>::TValueType>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: pointer wrapper's traits (constant pointer wrapper specialization).
template <typename T_Type>
class MTraitsPointerWrapper<NBase::CPointer<T_Type> const> :
  public MType<typename NBase::CPointer<T_Type>::TValueType>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: pointer wrapper's traits (volatile pointer wrapper specialization).
template <typename T_Type>
class MTraitsPointerWrapper<NBase::CPointer<T_Type> volatile> :
  public MType<typename NBase::CPointer<T_Type>::TValueType>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: pointer wrapper's traits (constant volatile pointer wrapper specialization).
template <typename T_Type>
class MTraitsPointerWrapper<NBase::CPointer<T_Type> const volatile> :
  public MType<typename NBase::CPointer<T_Type>::TValueType>
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
