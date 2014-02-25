/*!
 *  \file    MConceptIteratorInsertTree.inl Template checking conception.
 *           Checks if template argument is a tree insert iterator type.
 *  \brief   Tree insert iterator template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree insert iterator template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Iterators conception checking
    VERSION:   1.0
    CREATED:   25.07.2006 02:28:58

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
#ifndef __MCONCEPTITERATORINSERTTREE_INL__
#define __MCONCEPTITERATORINSERTTREE_INL__
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
inline MConceptIteratorInsertTree<T_Class>::MConceptIteratorInsertTree() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptIteratorInsertTree<T_Class>::~MConceptIteratorInsertTree()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptIteratorInsertTree<T_Class>::constraints()
{ CALL
  // Check T_Class template argument constraint to be a backward insert iterator.
  MConstraint::requiresConcept<MConceptIteratorInsertBackward<T_Class> >();

  Tbool result;
  Tuint uindex = 0;

  // Check for the tree insert iterator types.
  typename T_Class::TIterator it;
  typename T_Class::TContainer container;

  // Check for the tree insert iterator operators.
  it = m_It;

  // Check for the tree insert iterator types.
  typename T_Class::TType item;

  // Check for the tree insert iterator methods.
  result = m_It.insertParent(item, true);
  result = m_It.insertFirstSibling(item, true);
  result = m_It.insertLastSibling(item, true);
  result = m_It.insertPrevSibling(item, true);
  result = m_It.insertNextSibling(item, true);
  result = m_It.insertIndexSibling(uindex, item, true);
  result = m_It.insertFirstChild(item, true);
  result = m_It.insertLastChild(item, true);
  result = m_It.insertIndexChild(uindex, item, true);
  result = m_It.insertSubTreeFirstSibling(container, true);
  result = m_It.insertSubTreeLastSibling(container, true);
  result = m_It.insertSubTreePrevSibling(container, true);
  result = m_It.insertSubTreeNextSibling(container, true);
  result = m_It.insertSubTreeIndexSibling(uindex, container, true);
  result = m_It.insertSubTreeFirstChild(container, true);
  result = m_It.insertSubTreeLastChild(container, true);
  result = m_It.insertSubTreeIndexChild(uindex, container, true);
  result = m_It.flatten(true);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
