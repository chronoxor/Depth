/*!
 *  \file    MTraitsFunction8.hpp Traits meta-class that helps to determine
 *           attributes of the function with 8 arguments.
 *  \brief   Traits meta-class: traits of the function with 8 arguments.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: traits of the function with 8 arguments.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   09.11.2006 21:43:13

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
#ifndef __MTRAITSFUNCTION8_HPP__
#define __MTRAITSFUNCTION8_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MType.hpp>
#include <Depth/include/traits/details/MTraitsRoutineX.hpp>
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
#define DEF_FUNCTION_ARITY                       8
#define DEF_TEMPLATE_DECLARATION                 typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8
#define DEF_TEMPLATE_PARAMETERS                  EXPAND(DEF_FUNCTION_ARITY), true, false, false, false, false, void, T_Result, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8)
#include <Depth/include/traits/details/templates/MTraitsFunction.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_TEMPLATE_SPECIALIZATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       8
#define DEF_TEMPLATE_DECLARATION                 typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8
#define DEF_TEMPLATE_PARAMETERS                  EXPAND(DEF_FUNCTION_ARITY), true, false, false, false, true, void, T_Result, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8, ...)
#include <Depth/include/traits/details/templates/MTraitsFunction.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_TEMPLATE_SPECIALIZATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       8
#define DEF_TEMPLATE_DECLARATION                 typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8
#define DEF_TEMPLATE_PARAMETERS                  EXPAND(DEF_FUNCTION_ARITY), true, false, false, false, false, void, T_Result, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (*)(T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8)
#include <Depth/include/traits/details/templates/MTraitsFunction.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_TEMPLATE_SPECIALIZATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       8
#define DEF_TEMPLATE_DECLARATION                 typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8
#define DEF_TEMPLATE_PARAMETERS                  EXPAND(DEF_FUNCTION_ARITY), true, false, false, false, true, void, T_Result, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (*)(T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8, ...)
#include <Depth/include/traits/details/templates/MTraitsFunction.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_TEMPLATE_SPECIALIZATION
/*==========================================================================*/
#endif
