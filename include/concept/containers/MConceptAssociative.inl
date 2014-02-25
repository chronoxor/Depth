/*!
 *  \file    MConceptAssociative.inl Template checking conception. Checks if
 *           template argument is a non constant associative container type.
 *  \brief   Non constant associative container template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant associative container template checking conception (inline).

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
#ifndef __MCONCEPTASSOCIATIVE_INL__
#define __MCONCEPTASSOCIATIVE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <class T_Class>
inline MConceptAssociative<T_Class>::MConceptAssociative() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptAssociative<T_Class>::~MConceptAssociative()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptAssociative<T_Class>::constraints()
{ CALL
  // Check T_Class template argument constraint to be a non constant container.
  MConstraint::requiresConcept<MConceptContainer<T_Class> >();

  Tbool result;

  // Check for the constant associative container's types.
  typename T_Class::TKey key;
  typename T_Class::TValue value;
  typename T_Class::TType item;

  // Check for the non constant associative container's operators.
  m_Container += item;
  m_Container += m_Container;
  m_Container -= key;
  m_Container -= m_Container;

  // Check for the non constant associative container's methods.
  result = m_Container.insert(item);
  result = m_Container.insert(m_Container);
  result = m_Container.remove(key, true);
  result = m_Container.remove(m_Container, true);

  IGNORE_UNUSED(value);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
