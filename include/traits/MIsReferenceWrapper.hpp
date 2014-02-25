/*!
 *  \file    MIsReferenceWrapper.hpp Traits meta-class that helps to check if
 *           given type is a reference wrapper type.
 *  \brief   Traits meta-class: reference wrapper type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: reference wrapper type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   19.07.2006 02:03:26

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
#ifndef __MISREFERENCEWRAPPER_HPP__
#define __MISREFERENCEWRAPPER_HPP__
/*==========================================================================*/
#include <Depth/include/base/CReference.hpp>
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
//! Traits meta-class: reference wrapper type checking trait.
/*!
    Traits meta-class checks if template argument is a  reference  type.  Here
    comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsReferenceWrapper<int>::yes                                 false
    MIsReferenceWrapper<CReferenceWrapper<int> const>::yes        true
*/
template <typename T_Type>
class MIsReferenceWrapper :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: reference wrapper type checking trait (reference wrapper specialization).
template <typename T_Type>
class MIsReferenceWrapper<NBase::CReference<T_Type> > :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: reference wrapper type checking trait (constant reference wrapper specialization).
template <typename T_Type>
class MIsReferenceWrapper<NBase::CReference<T_Type> const> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: reference wrapper type checking trait (volatile reference wrapper specialization).
template <typename T_Type>
class MIsReferenceWrapper<NBase::CReference<T_Type> volatile> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: reference wrapper type checking trait (constant volatile reference wrapper specialization).
template <typename T_Type>
class MIsReferenceWrapper<NBase::CReference<T_Type> const volatile> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
