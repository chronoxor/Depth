/*!
 *  \file    MTraitsFunction.hpp.tpl Traits meta-class that helps to
 *           determine function attributes such as count of arguments,
 *           their types and return type. General declaration of specialized
 *           function's traits.
 *  \brief   Traits meta-class: specialized function's traits (template header).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: specialized function's traits (template header).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits details (templates)
    VERSION:   1.0
    CREATED:   09.11.2006 21:34:53

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
//! Traits meta-class: specialized function's traits with DEF_FUNCTION_ARITY arguments.
/*!
    This class specialize function's traits with DEF_FUNCTION_ARITY arguments.
*/
template <DEF_TEMPLATE_DECLARATION>
class MTraitsFunction<DEF_TEMPLATE_SPECIALIZATION> :
  public MType<DEF_TEMPLATE_SPECIALIZATION>
{
public:
  static const Tsint arity      = NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::arity;      //!< Count of class function arguments.
  static const Tbool isFunction = NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::isFunction; //!< Non class function flag.
  static const Tbool isMethod   = NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::isMethod;   //!< Class function flag.
  static const Tbool isConst    = NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::isConst;    //!< Constant class function flag.
  static const Tbool isVolatile = NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::isVolatile; //!< Volatile class function flag.
  static const Tbool isVariable = NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::isVariable; //!< Variable function arguments flag.

  //! Parent class type.
  typedef typename NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::parent parent;
  //! Class function result type.
  typedef typename NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::result result;
  //! Class function 1'st argument type.
  typedef typename NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::arg1 arg1;
  //! Class function 2'nd argument type.
  typedef typename NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::arg2 arg2;
  //! Class function 3'rd argument type.
  typedef typename NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::arg3 arg3;
  //! Class function 4'th argument type.
  typedef typename NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::arg4 arg4;
  //! Class function 5'th argument type.
  typedef typename NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::arg5 arg5;
  //! Class function 6'th argument type.
  typedef typename NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::arg6 arg6;
  //! Class function 7'th argument type.
  typedef typename NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::arg7 arg7;
  //! Class function 8'th argument type.
  typedef typename NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::arg8 arg8;
  //! Class function 9'th argument type.
  typedef typename NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::arg9 arg9;
  //! Class function 10'th argument type.
  typedef typename NDetails::MFunctionHelper<DEF_TEMPLATE_PARAMETERS>::arg10 arg10;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
