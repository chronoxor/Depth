/*!
 *  \file    CFunctor0.hpp Functor class emulates an object that can be called
 *           as a function with 'operator()'. Version without arguments.
 *  \brief   Functor class without arguments.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor class without arguments.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors
    VERSION:   1.0
    CREATED:   04.05.2006 22:03:43

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
#ifndef __CFUNCTOR0_HPP__
#define __CFUNCTOR0_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/ACast.hpp>
#include <Depth/include/algorithms/common/ASwap.hpp>
#include <Depth/include/concept/functions/MConceptAnyFunction0.hpp>
#include <Depth/include/functors/details/IFunctorX.hpp>
#include <Depth/include/functors/details/CFunctorHelperX.hpp>
#include <Depth/include/traits/functions/MRemoveFunctionPtr0.hpp>
#include <Depth/include/utility/observer/IObserver.hpp>
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
#define DEF_FUNCTOR_ARITY                        0
#define DEF_FUNCTOR_DECLARATION(name)            JOIN(name, DEF_FUNCTOR_ARITY)
#define DEF_TEMPLATE_DECLARATION                 typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result
#define DEF_TEMPLATE_OTHER_DECLARATION           typename T_OtherResult
#define DEF_TEMPLATE_OTHER_PARAMETERS            T_OtherResult
#define DEF_CALL_DECLARATION
#define DEF_CALL_PARAMETERS
/*--------------------------------------------------------------------------*/
#include <Depth/include/functors/details/templates/IFunctor.hpp.tpl>
#include <Depth/include/functors/details/templates/CFunctorHelperFunction.hpp.tpl>
#include <Depth/include/functors/details/templates/CFunctorHelperMethod.hpp.tpl>
#include <Depth/include/functors/details/templates/CFunctorHelperMethodConst.hpp.tpl>
#include <Depth/include/functors/details/templates/CFunctorHelperMethodVolatile.hpp.tpl>
#include <Depth/include/functors/details/templates/CFunctorHelperMethodConstVolatile.hpp.tpl>
#include <Depth/include/functors/details/templates/CFunctorHelperX.hpp.tpl>
/*--------------------------------------------------------------------------*/
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (DEF_CALL_DECLARATION)
#include <Depth/include/functors/details/templates/CFunctorHelper.hpp.tpl>
#undef DEF_TEMPLATE_SPECIALIZATION
/*--------------------------------------------------------------------------*/
#undef DEF_FUNCTOR_ARITY
#undef DEF_FUNCTOR_DECLARATION
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_TEMPLATE_OTHER_DECLARATION
#undef DEF_TEMPLATE_OTHER_PARAMETERS
#undef DEF_CALL_DECLARATION
#undef DEF_CALL_PARAMETERS
/*==========================================================================*/
#include <Depth/include/functors/CFunctorX.hpp>
/*==========================================================================*/
#endif
