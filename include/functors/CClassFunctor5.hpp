/*!
 *  \file    CClassFunctor5.hpp Class functor class emulates an object that
 *           can be called as a class method with 'operator()'. Version
 *           with 5 arguments.
 *  \brief   Class functor class with 5 arguments.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Class functor class with 5 arguments.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors
    VERSION:   1.0
    CREATED:   10.05.2006 03:04:31

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
#ifndef __CCLASSFUNCTOR5_HPP__
#define __CCLASSFUNCTOR5_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/ACast.hpp>
#include <Depth/include/algorithms/common/ASwap.hpp>
#include <Depth/include/concept/functions/MConceptAnyMethod5.hpp>
#include <Depth/include/functors/details/IClassFunctorX.hpp>
#include <Depth/include/functors/details/IClassFunctorConstX.hpp>
#include <Depth/include/functors/details/IClassFunctorVolatileX.hpp>
#include <Depth/include/functors/details/IClassFunctorConstVolatileX.hpp>
#include <Depth/include/functors/details/CClassFunctorHelperX.hpp>
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
#define DEF_FUNCTOR_ARITY                        5
#define DEF_FUNCTOR_DECLARATION(name)            JOIN(name, DEF_FUNCTOR_ARITY)
#define DEF_TEMPLATE_DECLARATION                 typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5
#define DEF_TEMPLATE_PARAMETERS                  T_Result, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5
#define DEF_TEMPLATE_OTHER_DECLARATION           typename T_OtherResult, typename T_OtherArgument1, typename T_OtherArgument2, typename T_OtherArgument3, typename T_OtherArgument4, typename T_OtherArgument5
#define DEF_TEMPLATE_OTHER_PARAMETERS            T_OtherResult, T_OtherArgument1, T_OtherArgument2, T_OtherArgument3, T_OtherArgument4, T_OtherArgument5
#define DEF_CALL_DECLARATION                     T_Argument1 a_Argument1, T_Argument2 a_Argument2, T_Argument3 a_Argument3, T_Argument4 a_Argument4, T_Argument5 a_Argument5
#define DEF_CALL_PARAMETERS                      a_Argument1, a_Argument2, a_Argument3, a_Argument4, a_Argument5
#define DEF_CALL_COMMA                           ,
/*--------------------------------------------------------------------------*/
#include <Depth/include/functors/details/templates/IClassFunctor.hpp.tpl>
#include <Depth/include/functors/details/templates/IClassFunctorConst.hpp.tpl>
#include <Depth/include/functors/details/templates/IClassFunctorVolatile.hpp.tpl>
#include <Depth/include/functors/details/templates/IClassFunctorConstVolatile.hpp.tpl>
#include <Depth/include/functors/details/templates/CClassFunctorHelperMethod.hpp.tpl>
#include <Depth/include/functors/details/templates/CClassFunctorHelperMethodConst.hpp.tpl>
#include <Depth/include/functors/details/templates/CClassFunctorHelperMethodVolatile.hpp.tpl>
#include <Depth/include/functors/details/templates/CClassFunctorHelperMethodConstVolatile.hpp.tpl>
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTOR_TYPE                         e_METHOD
#define DEF_FUNCTOR_SPECIALIZATION               CClassFunctorHelperMethod
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (T_Class::*)(DEF_CALL_DECLARATION)
#define DEF_TEMPLATE_OTHER_SPECIALIZATION        T_OtherResult (T_OtherClass::*)(DEF_CALL_DECLARATION)
#include <Depth/include/functors/details/templates/CClassFunctorHelper.hpp.tpl>
#undef DEF_FUNCTOR_TYPE
#undef DEF_FUNCTOR_SPECIALIZATION
#undef DEF_TEMPLATE_SPECIALIZATION
#undef DEF_TEMPLATE_OTHER_SPECIALIZATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTOR_TYPE                         e_METHOD_CONST
#define DEF_FUNCTOR_SPECIALIZATION               CClassFunctorHelperMethodConst
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (T_Class::*)(DEF_CALL_DECLARATION) const
#define DEF_TEMPLATE_OTHER_SPECIALIZATION        T_OtherResult (T_OtherClass::*)(DEF_CALL_DECLARATION) const
#include <Depth/include/functors/details/templates/CClassFunctorHelper.hpp.tpl>
#undef DEF_FUNCTOR_TYPE
#undef DEF_FUNCTOR_SPECIALIZATION
#undef DEF_TEMPLATE_SPECIALIZATION
#undef DEF_TEMPLATE_OTHER_SPECIALIZATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTOR_TYPE                         e_METHOD_VOLATILE
#define DEF_FUNCTOR_SPECIALIZATION               CClassFunctorHelperMethodVolatile
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (T_Class::*)(DEF_CALL_DECLARATION) volatile
#define DEF_TEMPLATE_OTHER_SPECIALIZATION        T_OtherResult (T_OtherClass::*)(DEF_CALL_DECLARATION) volatile
#include <Depth/include/functors/details/templates/CClassFunctorHelper.hpp.tpl>
#undef DEF_FUNCTOR_TYPE
#undef DEF_FUNCTOR_SPECIALIZATION
#undef DEF_TEMPLATE_SPECIALIZATION
#undef DEF_TEMPLATE_OTHER_SPECIALIZATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTOR_TYPE                         e_METHOD_CONST_VOLATILE
#define DEF_FUNCTOR_SPECIALIZATION               CClassFunctorHelperMethodConstVolatile
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (T_Class::*)(DEF_CALL_DECLARATION) const volatile
#define DEF_TEMPLATE_OTHER_SPECIALIZATION        T_OtherResult (T_OtherClass::*)(DEF_CALL_DECLARATION) const volatile
#include <Depth/include/functors/details/templates/CClassFunctorHelper.hpp.tpl>
#undef DEF_FUNCTOR_TYPE
#undef DEF_FUNCTOR_SPECIALIZATION
#undef DEF_TEMPLATE_SPECIALIZATION
#undef DEF_TEMPLATE_OTHER_SPECIALIZATION
/*--------------------------------------------------------------------------*/
#undef DEF_FUNCTOR_ARITY
#undef DEF_FUNCTOR_DECLARATION
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_TEMPLATE_OTHER_DECLARATION
#undef DEF_TEMPLATE_OTHER_PARAMETERS
#undef DEF_CALL_DECLARATION
#undef DEF_CALL_PARAMETERS
#undef DEF_CALL_COMMA
/*==========================================================================*/
#include <Depth/include/functors/CClassFunctorX.hpp>
/*==========================================================================*/
#endif
