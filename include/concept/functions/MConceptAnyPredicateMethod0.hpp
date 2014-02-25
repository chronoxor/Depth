/*!
 *  \file    MConceptAnyPredicateMethod0.hpp Template checking conception.
 *           Checks if template argument is an any class predicate method
 *           without arguments.
 *  \brief   Any class predicate method without arguments template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Any class predicate method without arguments template checking conception.

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
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#ifndef __MCONCEPTANYPREDICATEMETHOD0_HPP__
#define __MCONCEPTANYPREDICATEMETHOD0_HPP__
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
class MConceptAnyPredicateMethod0 :
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
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(...)
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)() const
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(...) const
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)() volatile
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(...) volatile
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)() const volatile
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*--------------------------------------------------------------------------*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_DECLARATION                 class T_Class, typename T_Result
#define DEF_TEMPLATE_PARAMETERS                  T_Result (T_Class::*)(...) const volatile
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptAnyPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*==========================================================================*/
#endif
