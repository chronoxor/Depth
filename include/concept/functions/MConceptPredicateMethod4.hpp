/*!
 *  \file    MConceptPredicateMethod4.hpp Template checking conception.
 *           Checks if template argument is a class predicate method
 *           with 4 arguments.
 *  \brief   Class predicate method with 4 arguments template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Class predicate method with 4 arguments template checking conception.

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
#ifndef __MCONCEPTPREDICATEMETHOD4_HPP__
#define __MCONCEPTPREDICATEMETHOD4_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept6.hpp>
#include <Depth/include/concept/details/MConceptPredicateMethodX.hpp>
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
//! Class predicate method template checking conception meta-class (predicate method with 4 arguments).
/*!
    This conception helps  to  constrain  template  argument  to  be  a  class
    predicate method with 4 arguments.
*/
template <typename T_PredicateMethod, class T_Class, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4>
class MConceptPredicateMethod4 :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptPredicateMethod4();
  //! Meta-class protected destructor.
  virtual ~MConceptPredicateMethod4();

private:
  typename NTraits::MTraitsConcept<T_Class>::attribute           m_Class;           //!< Class instance.
  typename NTraits::MTraitsConcept<T_PredicateMethod>::attribute m_PredicateMethod; //!< Class predicate method.
  typename NTraits::MTraitsConcept<T_Argument1>::attribute       m_Argument1;       //!< The 1'st predicate method argument.
  typename NTraits::MTraitsConcept<T_Argument2>::attribute       m_Argument2;       //!< The 2'nd predicate method argument.
  typename NTraits::MTraitsConcept<T_Argument3>::attribute       m_Argument3;       //!< The 3'rd predicate method argument.
  typename NTraits::MTraitsConcept<T_Argument4>::attribute       m_Argument4;       //!< The 4'th predicate method argument.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#define DEF_FUNCTION_ARITY                       4
#define DEF_TEMPLATE_DECLARATION                 typename T_PredicateMethod, class T_Class, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4
#define DEF_TEMPLATE_PARAMETERS                  T_PredicateMethod, T_Class, T_Argument1, T_Argument2, T_Argument3, T_Argument4
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptPredicateMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*==========================================================================*/
#include <Depth/include/concept/functions/MConceptPredicateMethod4.inl>
/*==========================================================================*/
#endif
