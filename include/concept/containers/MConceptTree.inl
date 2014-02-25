/*!
 *  \file    MConceptTree.inl Template checking conception. Checks if
 *           template argument is a non constant tree container type.
 *  \brief   Non constant tree container template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.10.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant tree container template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Containers conception checking
    VERSION:   1.0
    CREATED:   04.10.2006 03:43:56

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
#ifndef __MCONCEPTTREE_INL__
#define __MCONCEPTTREE_INL__
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
inline MConceptTree<T_Class>::MConceptTree() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptTree<T_Class>::~MConceptTree()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptTree<T_Class>::constraints()
{ CALL
  // Check T_Class template argument constraint to be a non constant container.
  MConstraint::requiresConcept<MConceptContainer<T_Class> >();

  Tbool result;

  // Check for the non constant tree container's types.
  typename T_Class::TType item;

  // Check for the non constant tree container's methods.
  result = m_Container.insertFirstRoot(item);
  result = m_Container.insertLastRoot(item);
  result = m_Container.insertIndexRoot(1, item);
  result = m_Container.insertSubTreeFirstRoot(m_Container);
  result = m_Container.insertSubTreeLastRoot(m_Container);
  result = m_Container.insertSubTreeIndexRoot(1, m_Container);
  result = m_Container.removeFirstRoot();
  result = m_Container.removeFirstRoot(item);
  result = m_Container.removeLastRoot();
  result = m_Container.removeLastRoot(item);
  result = m_Container.removeIndexRoot(1);
  result = m_Container.removeIndexRoot(1, item);
  result = m_Container.subTreeFirstRoot(m_Container, 1);
  result = m_Container.subTreeLastRoot(m_Container, 1);
  result = m_Container.subTreeIndexRoot(1, m_Container, 1, 1);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
