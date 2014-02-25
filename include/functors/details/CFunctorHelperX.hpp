/*!
 *  \file    CFunctorHelperX.hpp Functor helper class emulates an object that
 *           can be called as a function with 'operator()'.
 *  \brief   General declaration of the functor helper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: General declaration of the functor helper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors details
    VERSION:   1.0
    CREATED:   04.05.2006 21:33:42

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
#ifndef __CFUNCTORHELPERX_HPP__
#define __CFUNCTORHELPERX_HPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NFunctors {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! General functor helper class.
/*!
    Now any functor helper supports only 10 function arguments. This class has
    private constructor, so you cannot  use more than 10  function  arguments.
    It will lead to compiler error if you try.

    Other versions of the same class uses template specialization to implement
    other functor helpers.
*/
template <typename T_Result, typename T_Argument1 = void, typename T_Argument2 = void, typename T_Argument3 = void, typename T_Argument4 = void, typename T_Argument5 = void, typename T_Argument6 = void, typename T_Argument7 = void, typename T_Argument8 = void, typename T_Argument9 = void, typename T_Argument10 = void>
class CFunctorHelper :
  public NDepth::NCommon::IStatic
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
