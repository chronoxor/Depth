/*!
 *  \file    MConceptAssign.hpp Template checking conception. Checks if
 *           template argument can be used with assign operator.
 *  \brief   Assignable template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Assignable template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Class conception checking
    VERSION:   1.0
    CREATED:   15.01.2006 23:25:14

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
#ifndef __MCONCEPTASSIGN_HPP__
#define __MCONCEPTASSIGN_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept1.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NClass {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Assignable template checking conception meta-class.
/*!
    This  conception  checks  if  template  argument  type  used  with  assign
    operator.
*/
template <typename T_Type>
class MConceptAssign :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

  //! Method for checking constant values.
  /*!
      \param a_crX - Constant reference to checking value.
  */
  void constraintsConst(const T_Type& a_crX);

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptAssign();
  //! Meta-class protected destructor.
  virtual ~MConceptAssign();

private:
  typename NTraits::MTraitsConcept<T_Type>::attribute m_X; //!< Default assignable value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/class/MConceptAssign.inl>
/*==========================================================================*/
#endif
