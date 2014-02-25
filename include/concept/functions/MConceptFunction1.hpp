/*!
 *  \file    MConceptFunction1.hpp Template checking conception. Checks if
 *           template argument is a function with 1 argument.
 *  \brief   Function with 1 argument template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Function with 1 argument template checking conception.

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
#ifndef __MCONCEPTFUNCTION1_HPP__
#define __MCONCEPTFUNCTION1_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept3.hpp>
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
//! Function template checking conception meta-class (function with 1 argument).
/*!
    This conception helps to constrain template  argument  to  be  a  function
    with 1 argument.
*/
template <typename T_Function, typename T_Result, typename T_Argument1>
class MConceptFunction1 :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptFunction1();
  //! Meta-class protected destructor.
  virtual ~MConceptFunction1();

private:
  typename NTraits::MTraitsConcept<T_Function>::attribute  m_fFunction; //!< Function.
  typename NTraits::MTraitsConcept<T_Result>::attribute    m_Result;    //!< Function result value.
  typename NTraits::MTraitsConcept<T_Argument1>::attribute m_Argument1; //!< The 1'st function argument.
};
/*--------------------------------------------------------------------------*/
//! Function template checking conception meta-class (empty return function with 1 argument).
/*!
    This conception helps to  constrain  template  argument  to  be  an  empty
    return function with 1 argument.
*/
template <typename T_Function, typename T_Argument1>
class MConceptFunction1<T_Function, void, T_Argument1> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptFunction1();
  //! Meta-class protected destructor.
  virtual ~MConceptFunction1();

private:
  typename NTraits::MTraitsConcept<T_Function>::attribute  m_fFunction; //!< Function.
  typename NTraits::MTraitsConcept<T_Argument1>::attribute m_Argument1; //!< The 1'st function argument.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#define DEF_FUNCTION_ARITY                       1
#define DEF_TEMPLATE_FULL_DECLARATION            typename T_Function, typename T_Result, typename T_Argument1
#define DEF_TEMPLATE_FULL_PARAMETERS             T_Function, T_Result, T_Argument1
#define DEF_TEMPLATE_EMPTY_DECLARATION           typename T_Function, typename T_Argument1
#define DEF_TEMPLATE_EMPTY_PARAMETERS            T_Function, void, T_Argument1
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptFunction.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_FULL_DECLARATION
#undef DEF_TEMPLATE_FULL_PARAMETERS
#undef DEF_TEMPLATE_EMPTY_DECLARATION
#undef DEF_TEMPLATE_EMPTY_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*==========================================================================*/
#include <Depth/include/concept/functions/MConceptFunction1.inl>
/*==========================================================================*/
#endif
