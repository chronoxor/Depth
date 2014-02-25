/*!
 *  \file    MIfThenElse.hpp Traits meta-class that helps to choose appropriate
 *           type depends on boolean expression.
 *  \brief   Traits meta-class: if-then-else trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: if-then-else trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   10.03.2006 02:04:23

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
#ifndef __MIfThenElse_HPP__
#define __MIfThenElse_HPP__
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
//! Traits meta-class: if-then-else trait.
/*!
    Traits meta-class chooses appropriate type depends on boolean  expression.
    Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIfThenElse<true, int, double>::type                          int
    MIfThenElse<flase,int&, const char*>::type                    const char*
*/
template <Tbool t_Expression, typename T_Type1, typename T_Type2>
class MIfThenElse :
  public MType<void>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: if-then-else trait ('true' specialization).
template <typename T_Type1, typename T_Type2>
class MIfThenElse<true, T_Type1, T_Type2> :
  public MType<T_Type1>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: if-then-else trait ('false' specialization).
template <typename T_Type1, typename T_Type2>
class MIfThenElse<false, T_Type1, T_Type2> :
  public MType<T_Type2>
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
