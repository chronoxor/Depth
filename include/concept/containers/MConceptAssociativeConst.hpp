/*!
 *  \file    MConceptAssociativeConst.hpp Template checking conception.
 *           Checks if template argument is a constant associative
 *           container type (inline).
 *  \brief   Constant associative container template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant associative container template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Containers conception checking
    VERSION:   1.0
    CREATED:   23.09.2006 22:48:26

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
#ifndef __MCONCEPTCONSTASSOCIATIVE_HPP__
#define __MCONCEPTCONSTASSOCIATIVE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/containers/MConceptContainerConst.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Constant associative container template checking conception meta-class.
/*!
    This conception helps to constrain template  argument  to  be  a  constant
    associative container.
*/
template <class T_Class>
class MConceptAssociativeConst :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptAssociativeConst();
  //! Meta-class protected destructor.
  virtual ~MConceptAssociativeConst();

private:
  typename NTraits::MTraitsConcept<T_Class>::attribute       m_Container;  //!< Constant associative container value.
  typename NTraits::MTraitsConcept<const T_Class>::attribute m_cContainer; //!< Constant associative container constant value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/containers/MConceptAssociativeConst.inl>
/*==========================================================================*/
#endif
