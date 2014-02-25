/*!
 *  \file    AReference.hpp Contains general template implementation of the
 *           reference wrapper algorithm.
 *  \brief   Reference wrapper algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reference wrapper algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms
    VERSION:   1.0
    CREATED:   19.07.2006 02:19:24

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
#ifndef __AREFERENCE_HPP__
#define __AREFERENCE_HPP__
/*==========================================================================*/
#include <Depth/include/base/CReference.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Get reference wrapper to the given object.
/*!
    This algorithm constructs and  returns  reference  wrapper  to  the  given
    object. This may be useful for passing references  to  function  templates
    (algorithms) that would usually take copies of their arguments.

    \param a_rX - Reference to the wrapping object.
    \return Reference wrapper for the given object.
*/
template <typename T_Type>
NBase::CReference<T_Type> ref(T_Type& a_rX);
/*--------------------------------------------------------------------------*/
//! Algorithm: Get constant reference wrapper to the given object.
/*!
    This algorithm constructs and returns constant reference  wrapper  to  the
    given object. This may  be  useful  for  passing  references  to  function
    templates (algorithms) that would usually take copies of their arguments.

    \param a_crX - Constant reference to the wrapping object.
    \return Constant reference wrapper for the given object.
*/
template <typename T_Type>
const NBase::CReference<const T_Type> cref(const T_Type& a_crX);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/common/AReference.inl>
/*==========================================================================*/
#endif
