/*!
 *  \file    MConceptIteratorNonConst.inl Template checking conception. Checks
 *           if template argument is a non constant iterator type.
 *  \brief   Non constant iterator template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant iterator template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Iterators conception checking
    VERSION:   1.0
    CREATED:   16.02.2006 02:49:26

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
#ifndef __MCONCEPTITERATORNONCONST_INL__
#define __MCONCEPTITERATORNONCONST_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <class T_Class>
inline MConceptIteratorNonConst<T_Class>::MConceptIteratorNonConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptIteratorNonConst<T_Class>::~MConceptIteratorNonConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptIteratorNonConst<T_Class>::constraints()
{ CALL
  Tbool result;

  // Check for the non constant iterator types.
  typename T_Class::TIterator it;

  // Check for the constant iterator operators.
  it = m_It;

  // Check for the non constant iterator methods.
  result = m_It.isValid();
  result = m_It.isValidContainer();
  typename T_Class::TContainer& container_ref = m_It.getContainerRef();
  typename T_Class::TContainer* container_ptr = m_It.getContainerPtr();
  typename T_Class::TReturn& value_ref = m_It.getValueRef();
  typename T_Class::TReturn* value_ptr = m_It.getValuePtr();

  IGNORE_UNUSED(container_ref);
  IGNORE_UNUSED(container_ptr);
  IGNORE_UNUSED(value_ref);
  IGNORE_UNUSED(value_ptr);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
