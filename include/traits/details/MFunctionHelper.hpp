/*!
 *  \file    MFunctionHelper.hpp Traits helper meta-class that helps to
 *           determine function attributes such as count of arguments,
 *           their types and return type. Declares general function traits
 *           attributes.
 *  \brief   Traits helper meta-class: general function's traits.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits helper meta-class: general function's traits.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits details
    VERSION:   1.0
    CREATED:   09.11.2006 20:51:59

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
#ifndef __MFUNCTIONHELPER_HPP__
#define __MFUNCTIONHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits helper meta-class: general function's traits.
/*!
    Traits helper meta-class helps to determine function  attributes  such  as
    count of arguments, their types and return type. It is a general  function
    traits helper meta-class.
*/
template <Tsint t_Arity, Tbool t_IsFunction, Tbool t_IsMethod, Tbool t_IsConst, Tbool t_IsVolatile, Tbool t_IsVariable, typename T_Class, typename T_Result, typename T_Argument1 = void, typename T_Argument2 = void, typename T_Argument3 = void, typename T_Argument4 = void, typename T_Argument5 = void, typename T_Argument6 = void, typename T_Argument7 = void, typename T_Argument8 = void, typename T_Argument9 = void, typename T_Argument10 = void>
class MFunctionHelper :
  public NDepth::NCommon::IStatic
{
public:
  static const Tsint arity      = t_Arity;      //!< Count of class function arguments.
  static const Tbool isFunction = t_IsFunction; //!< Non class function flag.
  static const Tbool isMethod   = t_IsMethod;   //!< Class function flag.
  static const Tbool isConst    = t_IsConst;    //!< Constant class function flag.
  static const Tbool isVolatile = t_IsVolatile; //!< Volatile class function flag.
  static const Tbool isVariable = t_IsVariable; //!< Variable function arguments flag.

  //! Parent class type.
  typedef T_Class parent;
  //! Class function result type.
  typedef T_Result result;
  //! Class function 1'st argument type.
  typedef T_Argument1 arg1;
  //! Class function 2'nd argument type.
  typedef T_Argument2 arg2;
  //! Class function 3'rd argument type.
  typedef T_Argument3 arg3;
  //! Class function 4'th argument type.
  typedef T_Argument4 arg4;
  //! Class function 5'th argument type.
  typedef T_Argument5 arg5;
  //! Class function 6'th argument type.
  typedef T_Argument6 arg6;
  //! Class function 7'th argument type.
  typedef T_Argument7 arg7;
  //! Class function 8'th argument type.
  typedef T_Argument8 arg8;
  //! Class function 9'th argument type.
  typedef T_Argument9 arg9;
  //! Class function 10'th argument type.
  typedef T_Argument10 arg10;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
