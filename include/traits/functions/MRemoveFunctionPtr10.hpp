/*!
 *  \file    MRemoveFunctionPtr10.hpp Traits meta-class that helps to
 *           remove pointer qualifier to the function template parameter.
 *           Version with 10 arguments.
 *  \brief   Traits meta-class: remove function pointer qualifier. Version with 10 arguments.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: remove function pointer qualifier. Version with 10 arguments.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functions traits
    VERSION:   1.0
    CREATED:   27.11.2006 21:28:54

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
#ifndef __MREMOVEFUNCTIONPTR10_HPP__
#define __MREMOVEFUNCTIONPTR10_HPP__
/*==========================================================================*/
#include <Depth/include/traits/details/MRemoveFunctionPtrX.hpp>
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
#define DEF_FUNCTION_ARITY                       10
#define DEF_TEMPLATE_DECLARATION                 typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9, typename T_Argument10
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (*)(T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8, T_Argument9, T_Argument10)
#define DEF_TEMPLATE_TRAITS                      T_Result (T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8, T_Argument9, T_Argument10)
#include <Depth/include/traits/details/templates/MRemoveFunctionPtr.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_SPECIALIZATION
#undef DEF_TEMPLATE_TRAITS
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       10
#define DEF_TEMPLATE_DECLARATION                 typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9, typename T_Argument10
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (*)(T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8, T_Argument9, T_Argument10, ...)
#define DEF_TEMPLATE_TRAITS                      T_Result (T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8, T_Argument9, T_Argument10, ...)
#include <Depth/include/traits/details/templates/MRemoveFunctionPtr.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_SPECIALIZATION
#undef DEF_TEMPLATE_TRAITS
/*==========================================================================*/
#endif
