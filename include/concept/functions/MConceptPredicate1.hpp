/*!
 *  \file    MConceptPredicate1.hpp Template checking conception. Checks if
 *           template argument is a predicate with 1 argument.
 *  \brief   Predicate with 1 argument template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Predicate with 1 argument template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functions conception checking
    VERSION:   1.0
    CREATED:   26.04.2006 20:47:53

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
#ifndef __MCONCEPTPREDICATE1_HPP__
#define __MCONCEPTPREDICATE1_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept2.hpp>
#include <Depth/include/concept/details/MConceptPredicateX.hpp>
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
//! Predicate template checking conception meta-class (predicate with 1 argument).
/*!
    This conception helps to constrain template argument  to  be  a  predicate
    with 1 argument.
*/
template <typename T_Predicate, typename T_Argument1>
class MConceptPredicate1 :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptPredicate1();
  //! Meta-class protected destructor.
  virtual ~MConceptPredicate1();

private:
  typename NTraits::MTraitsConcept<T_Predicate>::attribute m_fPredicate; //!< Predicate function.
  typename NTraits::MTraitsConcept<T_Argument1>::attribute m_Argument1;  //!< The 1'st predicate argument.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#define DEF_FUNCTION_ARITY                       1
#define DEF_TEMPLATE_DECLARATION                 typename T_Predicate, typename T_Argument1
#define DEF_TEMPLATE_PARAMETERS                  T_Predicate, T_Argument1
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptPredicate.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*==========================================================================*/
#include <Depth/include/concept/functions/MConceptPredicate1.inl>
/*==========================================================================*/
#endif
