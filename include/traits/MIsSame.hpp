/*!
 *  \file    MIsSame.hpp Traits meta-class that helps to check if two given
 *           types are equal.
 *  \brief   Traits meta-class: same types checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: same types checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   12.03.2006 01:26:35

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
#ifndef __MISSAMETYPES_HPP__
#define __MISSAMETYPES_HPP__
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
//! Traits meta-class: same types checking trait.
/*!
    Traits meta-class checks if two template arguments are  same  types.  Here
    comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsSame<int, int>::yes                                        true
    MIsSame<int, const int>::yes                                  false
*/
template <typename T_Type1, typename T_Type2>
class MIsSame :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: same types checking trait (same specialization).
template <typename T_Type>
class MIsSame<T_Type, T_Type> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
