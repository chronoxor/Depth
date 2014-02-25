/*!
 *  \file    MRemoveFunctionPtr0.hpp Traits meta-class that helps to
 *           remove pointer qualifier to the function template parameter.
 *           Version without arguments.
 *  \brief   Traits meta-class: remove function pointer qualifier. Version without arguments.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: remove function pointer qualifier. Version without arguments.

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
#ifndef __MREMOVEFUNCTIONPTR0_HPP__
#define __MREMOVEFUNCTIONPTR0_HPP__
/*==========================================================================*/
#include <Depth/include/traits/details/MRemoveFunctionPtrX.hpp>
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 typename T_Result
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (*)()
#define DEF_TEMPLATE_TRAITS                      T_Result ()
#include <Depth/include/traits/details/templates/MRemoveFunctionPtr.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_SPECIALIZATION
#undef DEF_TEMPLATE_TRAITS
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 typename T_Result
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (*)(...)
#define DEF_TEMPLATE_TRAITS                      T_Result (...)
#include <Depth/include/traits/details/templates/MRemoveFunctionPtr.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_SPECIALIZATION
#undef DEF_TEMPLATE_TRAITS
/*==========================================================================*/
#endif
