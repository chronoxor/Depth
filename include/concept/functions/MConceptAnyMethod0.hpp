/*!
 *  \file    MConceptAnyMethod0.hpp Template checking conception. Checks if
 *           template argument is an any class method without arguments.
 *  \brief   Any class method without arguments template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Any class method without arguments template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functions conception checking
    VERSION:   1.0
    CREATED:   26.04.2006 22:24:53

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
#ifndef __MCONCEPTANYMETHOD0_HPP__
#define __MCONCEPTANYMETHOD0_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept1.hpp>
#include <Depth/include/concept/details/MConceptAnyMethodX.hpp>
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
//! General meta-class for any class method template checking conception.
/*!
    Other versions of the same class uses template specialization to implement
    checking algorithm.
*/
template <typename T_Method>
class MConceptAnyMethod0 :
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
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)()
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(...)
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)() const
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(...) const
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)() volatile
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(...) volatile
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)() const volatile
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(...) const volatile
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*==========================================================================*/
#endif
