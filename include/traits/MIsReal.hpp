/*!
 *  \file    MIsReal.hpp Traits meta-class that helps to check if given
 *           type is a real type.
 *  \brief   Traits meta-class: real type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: real type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   10.03.2006 23:26:31

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
#ifndef __MISREAL_HPP__
#define __MISREAL_HPP__
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
//! Traits meta-class: real type checking trait.
/*!
    Traits meta-class checks if template argument is a real type.  Here  comes
    some examples of using this trait:

    Expression:                                                   Result type:
    MIsReal<int>::yes                                             false
    MIsReal<float>::yes                                           true
    MIsReal<double>::yes                                          true
*/
template <typename T_Type>
class MIsReal :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: real type checking trait (float specialization).
template <>
class MIsReal<Tfloat> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: real type checking trait (constant float specialization).
template <>
class MIsReal<const Tfloat> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: real type checking trait (volatile float specialization).
template <>
class MIsReal<volatile Tfloat> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: real type checking trait (constant volatile float specialization).
template <>
class MIsReal<const volatile Tfloat> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: real type checking trait (double specialization).
template <>
class MIsReal<Tdouble> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: real type checking trait (constant double specialization).
template <>
class MIsReal<const Tdouble> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: real type checking trait (volatile double specialization).
template <>
class MIsReal<volatile Tdouble> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: real type checking trait (constant volatile double specialization).
template <>
class MIsReal<const volatile Tdouble> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
