/*!
 *  \file    MTraitsRoutineX.hpp Traits meta-class that helps to determine
 *           function attributes such as count of arguments, their types and
 *           return type. General function's traits declaration.
 *  \brief   Traits meta-class: general function's traits.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: general function's traits.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits details
    VERSION:   1.0
    CREATED:   09.11.2006 21:40:32

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
#ifndef __MTRAITSROUTINEX_HPP__
#define __MTRAITSROUTINEX_HPP__
/*==========================================================================*/
#include <Depth/include/traits/details/MFunctionHelper.hpp>
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
//! Traits meta-class: general function's traits.
/*!
    Traits meta-class helps to determine function attributes such as count  of
    arguments, their types and return type. Here comes some examples of  using
    this trait:

    Expression:                                                   Result type:
    MTraitsFunction<int (char, float)>::type                      int (char, float)
    MTraitsFunction<int (char, float)>::isFunction                true
    MTraitsFunction<int (char, float)>::isMethod                  false
    MTraitsFunction<int (char, float)>::isConst                   false
    MTraitsFunction<int (char, float)>::isVolatile                false
    MTraitsFunction<int (char, float)>::isVariable                false
    MTraitsFunction<int (char, float)>::parent                    void
    MTraitsFunction<int (char, float)>::arity                     2
    MTraitsFunction<int (char, float)>::result                    int
    MTraitsFunction<int (char, float)>::arg1                      char
    MTraitsFunction<int (char, float)>::arg2                      float

    MTraitsFunction<int (*)(char, float, ...)>::type              int (*)(char, float)
    MTraitsFunction<int (*)(char, float, ...)>::isFunction        true
    MTraitsFunction<int (*)(char, float, ...)>::isMethod          false
    MTraitsFunction<int (*)(char, float, ...)>::isConst           false
    MTraitsFunction<int (*)(char, float, ...)>::isVolatile        false
    MTraitsFunction<int (*)(char, float, ...)>::isVariable        true
    MTraitsFunction<int (*)(char, float, ...)>::parent            void
    MTraitsFunction<int (*)(char, float, ...)>::arity             2
    MTraitsFunction<int (*)(char, float, ...)>::result            int
    MTraitsFunction<int (*)(char, float, ...)>::arg1              char
    MTraitsFunction<int (*)(char, float, ...)>::arg2              float

    MTraitsFunction<int (test::*)(char, float) const>::type       int (test::*)(char, float) const
    MTraitsFunction<int (test::*)(char, float) const>::isFunction false
    MTraitsFunction<int (test::*)(char, float) const>::isMethod   true
    MTraitsFunction<int (test::*)(char, float) const>::isConst    true
    MTraitsFunction<int (test::*)(char, float) const>::isVolatile false
    MTraitsFunction<int (test::*)(char, float) const>::isVariable false
    MTraitsFunction<int (test::*)(char, float) const>::parent     test
    MTraitsFunction<int (test::*)(char, float) const>::arity      2
    MTraitsFunction<int (test::*)(char, float) const>::result     int
    MTraitsFunction<int (test::*)(char, float) const>::arg1       char
    MTraitsFunction<int (test::*)(char, float) const>::arg2       float
*/
template <typename T_Type>
class MTraitsFunction :
  public NDepth::NCommon::IStatic
{
public:
  static const Tsint arity      = 0;     //!< Count of class function arguments.
  static const Tbool isFunction = false; //!< Non class function flag.
  static const Tbool isMethod   = false; //!< Class function flag.
  static const Tbool isConst    = false; //!< Constant class function flag.
  static const Tbool isVolatile = false; //!< Volatile class function flag.
  static const Tbool isVariable = false; //!< Variable function arguments flag.

  //! Parent class type.
  typedef void parent;
  //! Class function result type.
  typedef void result;
  //! Class function 1'st argument type.
  typedef void arg1;
  //! Class function 2'nd argument type.
  typedef void arg2;
  //! Class function 3'rd argument type.
  typedef void arg3;
  //! Class function 4'th argument type.
  typedef void arg4;
  //! Class function 5'th argument type.
  typedef void arg5;
  //! Class function 6'th argument type.
  typedef void arg6;
  //! Class function 7'th argument type.
  typedef void arg7;
  //! Class function 8'th argument type.
  typedef void arg8;
  //! Class function 9'th argument type.
  typedef void arg9;
  //! Class function 10'th argument type.
  typedef void arg10;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
