/*!
 *  \file    MConceptMethod0.hpp Template checking conception. Checks if
 *           template argument is a class method without arguments.
 *  \brief   Class method without arguments template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Class method without arguments template checking conception.

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
#ifndef __MCONCEPTMETHOD0_HPP__
#define __MCONCEPTMETHOD0_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept3.hpp>
#include <Depth/include/concept/details/MConceptMethodX.hpp>
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
//! Class method conception meta-class (method without arguments).
/*!
    This conception helps to  constrain  template  argument  to  be  a  method
    without arguments.
*/
template <typename T_Method, class T_Class, typename T_Result>
class MConceptMethod0 :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptMethod0();
  //! Meta-class protected destructor.
  virtual ~MConceptMethod0();

private:
  typename NTraits::MTraitsConcept<T_Class>::attribute  m_Class;  //!< Class instance.
  typename NTraits::MTraitsConcept<T_Method>::attribute m_Method; //!< Class method.
  typename NTraits::MTraitsConcept<T_Result>::attribute m_Result; //!< Class method result value.
};
/*--------------------------------------------------------------------------*/
//! Class method conception meta-class (empty return method without arguments).
/*!
    This conception helps to constrain template argument to be an empty return
    method without arguments.
*/
template <typename T_Method, class T_Class>
class MConceptMethod0<T_Method, T_Class, void> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptMethod0();
  //! Meta-class protected destructor.
  virtual ~MConceptMethod0();

private:
  typename NTraits::MTraitsConcept<T_Class>::attribute  m_Class;  //!< Class instance.
  typename NTraits::MTraitsConcept<T_Method>::attribute m_Method; //!< Class method.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#define DEF_FUNCTION_ARITY                       0
#define DEF_TEMPLATE_FULL_DECLARATION            typename T_Method, class T_Class, typename T_Result
#define DEF_TEMPLATE_FULL_PARAMETERS             T_Method, T_Class, T_Result
#define DEF_TEMPLATE_EMPTY_DECLARATION           typename T_Method, class T_Class
#define DEF_TEMPLATE_EMPTY_PARAMETERS            T_Method, T_Class, void
#define DEF_CONCEPT_DECLARATION(conception)      JOIN(conception, DEF_FUNCTION_ARITY)
#include <Depth/include/concept/details/templates/MConceptMethod.hpp.tpl>
#undef DEF_FUNCTION_ARITY
#undef DEF_TEMPLATE_FULL_DECLARATION
#undef DEF_TEMPLATE_FULL_PARAMETERS
#undef DEF_TEMPLATE_EMPTY_DECLARATION
#undef DEF_TEMPLATE_EMPTY_PARAMETERS
#undef DEF_CONCEPT_DECLARATION
/*==========================================================================*/
#include <Depth/include/concept/functions/MConceptMethod0.inl>
/*==========================================================================*/
#endif
