/*!
 *  \file    MConceptAssignCopy.hpp Template checking conception. Checks if
 *           template argument has both assign operator and copy constructor.
 *  \brief   Assignable and copyable template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Assignable and copyable template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Class conception checking
    VERSION:   1.0
    CREATED:   16.01.2006 00:56:25

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
#ifndef __MCONCEPTASSIGNCOPY_HPP__
#define __MCONCEPTASSIGNCOPY_HPP__
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
//! Assignable and copyable template checking conception meta-class.
/*!
    This conception checks if template argument type has assign  operator  and
    copy constructor.
*/
template <typename T_Type>
class MConceptAssignCopy :
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
  MConceptAssignCopy();
  //! Meta-class protected destructor.
  virtual ~MConceptAssignCopy();

private:
  typename NTraits::MTraitsConcept<T_Type>::attribute m_X; //!< Default assignable and copyable value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/class/MConceptAssignCopy.inl>
/*==========================================================================*/
#endif
