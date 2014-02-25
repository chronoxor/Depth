/*!
 *  \file    MConceptReal.hpp Template checking conception. Checks if
 *           template argument is real number type.
 *  \brief   Real number template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Real number template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base types conception checking
    VERSION:   1.0
    CREATED:   15.01.2006 22:36:15

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
#ifndef __MCONCEPTREAL_HPP__
#define __MCONCEPTREAL_HPP__
/*==========================================================================*/
#include <Depth/include/concept/class/MConceptConstructible.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Real number template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a real number.
*/
template <typename T_Type>
class MConceptReal :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptReal();
  //! Meta-class protected destructor.
  virtual ~MConceptReal();

private:
  typename NTraits::MTraitsConcept<T_Type>::attribute m_X; //!< First real number value.
  typename NTraits::MTraitsConcept<T_Type>::attribute m_Y; //!< Second real number value.
};
/*--------------------------------------------------------------------------*/
//! Float number template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a float number.
*/
template <>
class MConceptReal<Tfloat> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptReal();
  //! Meta-class protected destructor.
  virtual ~MConceptReal();
};
/*--------------------------------------------------------------------------*/
//! Double number template checking conception meta-class.
/*!
    This conception helps to  constrain  template  argument  to  be  a  double
    number.
*/
template <>
class MConceptReal<Tdouble> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptReal();
  //! Meta-class protected destructor.
  virtual ~MConceptReal();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptReal.inl>
/*==========================================================================*/
#endif
