/*!
 *  \file    MConceptFunction2.hpp Template checking conception. Checks if
 *           template argument is a function with 2 arguments.
 *  \brief   Function with 2 arguments template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Function with 2 arguments template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functions conception checking
    VERSION:   1.0
    CREATED:   26.04.2006 02:03:32

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
#ifndef __MCONCEPTFUNCTION2_HPP__
#define __MCONCEPTFUNCTION2_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept4.hpp>
#include <Depth/include/concept/details/MConceptFunctionX.hpp>
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
//! Function template checking conception meta-class (function with 2 arguments).
/*!
    This conception helps to constrain template  argument  to  be  a  function
    with 2 arguments.
*/
template <typename T_Function, typename T_Result, typename T_Argument1, typename T_Argument2>
class MConceptFunction2 :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptFunction2();
  //! Meta-class protected destructor.
  virtual ~MConceptFunction2();

private:
  typename NTraits::MTraitsConcept<T_Function>::attribute  m_fFunction; //!< Function.
  typename NTraits::MTraitsConcept<T_Result>::attribute    m_Result;    //!< Function result value.
  typename NTraits::MTraitsConcept<T_Argument1>::attribute m_Argument1; //!< The 1'st function argument.
  typename NTraits::MTraitsConcept<T_Argument2>::attribute m_Argument2; //!< The 2'nd function argument.
};
/*--------------------------------------------------------------------------*/
//! Function template checking conception meta-class (empty return function with 2 arguments).
/*!
    This conception helps to  constrain  template  argument  to  be  an  empty
    return function with 2 arguments.
*/
template <typename T_Function, typename T_Argument1, typename T_Argument2>
class MConceptFunction2<T_Function, void, T_Argument1, T_Argument2> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptFunction2();
  //! Meta-class protected destructor.
  virtual ~MConceptFunction2();

private:
  typename NTraits::MTraitsConcept<T_Function>::attribute  m_fFunction; //!< Function.
  typename NTraits::MTraitsConcept<T_Argument1>::attribute m_Argument1; //!< The 1'st function argument.
  typename NTraits::MTraitsConcept<T_Argument2>::attribute m_Argument2; //!< The 2'nd function argument.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#define DEF_FUNCTION_ARITY                       2
#define DEF_TEMPLATE_FULL_DECLARATION            typename T_Function, typename T_Result, typename T_Argument1, typename T_Argument2
#define DEF_TEMPLATE_FULL_PARAMETERS             T_Function, T_Result, T_Argument1, T_Argument2
#define DEF_TEMPLATE_EMPTY_DECLARATION           typename T_Function, typename T_Argument1, typename T_Argument2
#define DEF_TEMPLATE_EMPTY_PARAMETERS            T_Function, void, T_Argument1, T_Argument2
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptFunction.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_FULL_DECLARATION
#undef DEF_TEMPLATE_FULL_PARAMETERS
#undef DEF_TEMPLATE_EMPTY_DECLARATION
#undef DEF_TEMPLATE_EMPTY_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*==========================================================================*/
#include <Depth/include/concept/functions/MConceptFunction2.inl>
/*==========================================================================*/
#endif