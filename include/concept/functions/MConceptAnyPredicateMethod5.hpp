/*!
 *  \file    MConceptAnyPredicateMethod5.hpp Template checking conception.
 *           Checks if template argument is an any class predicate method
 *           with 5 arguments.
 *  \brief   Any class predicate method with 5 arguments template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Any class predicate method with 5 arguments template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functions conception checking
    VERSION:   1.0
    CREATED:   26.04.2006 22:36:42

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
#ifndef __MCONCEPTANYPREDICATEMETHOD5_HPP__
#define __MCONCEPTANYPREDICATEMETHOD5_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept1.hpp>
#include <Depth/include/concept/details/MConceptAnyPredicateMethodX.hpp>
#include <Depth/include/concept/base/MConceptBool.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NFunctions {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! General meta-class for any predicate method template checking conception.
/*!
    Other versions of the same class uses template specialization to implement
    checking algorithm.
*/
template <typename T_PredicateMethod>
class MConceptAnyPredicateMethod5 :
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
#define DEF_FUNCTION_ARITY                       5
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5)
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       5
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, ...)
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       5
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5) const
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       5
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, ...) const
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       5
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5) volatile
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       5
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, ...) volatile
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       5
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5) const volatile
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       5
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, ...) const volatile
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*==========================================================================*/
#endif
