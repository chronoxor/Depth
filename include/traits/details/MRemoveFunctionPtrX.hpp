/*!
 *  \file    MRemoveFunctionPtrX.hpp General declaration of the traits
 *           meta-class that helps to remove pointer qualifier from the
 *           function template parameter.
 *  \brief   Traits meta-class: general declaration of the remove function pointer qualifier.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: general declaration of the remove function pointer qualifier.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits details
    VERSION:   1.0
    CREATED:   27.11.2006 21:05:32

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
#ifndef __MREMOVEFUNCTIONPTRX_HPP__
#define __MREMOVEFUNCTIONPTRX_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
namespace NFunctions {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: general declaration of the remove function pointer qualifier.
/*!
    Now any remove  function  pointer  qualifier  supports  only  10  function
    arguments. This class has private constructor, so you cannot use more than
    10 function arguments. It will lead to compiler error if you try.
*/
template <typename T_Type>
class MRemoveFunctionPtr :
  public MType<T_Type>
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
