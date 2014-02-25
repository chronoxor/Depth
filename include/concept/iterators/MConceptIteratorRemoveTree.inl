/*!
 *  \file    MConceptIteratorRemoveTree.inl Template checking conception.
 *           Checks if template argument is a tree remove iterator type.
 *  \brief   Tree remove iterator template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree remove iterator template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Iterators conception checking
    VERSION:   1.0
    CREATED:   25.07.2006 02:46:27

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
#ifndef __MCONCEPTITERATORREMOVETREE_INL__
#define __MCONCEPTITERATORREMOVETREE_INL__
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
inline MConceptIteratorRemoveTree<T_Class>::MConceptIteratorRemoveTree() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptIteratorRemoveTree<T_Class>::~MConceptIteratorRemoveTree()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptIteratorRemoveTree<T_Class>::constraints()
{ CALL
  // Check T_Class template argument constraint to be a backward remove iterator.
  MConstraint::requiresConcept<MConceptIteratorRemoveBackward<T_Class> >();

  Tbool result;
  Tuint count = 0;
  Tuint uindex = 0;

  // Check for the tree remove iterator types.
  typename T_Class::TIterator it;
  typename T_Class::TContainer container;

  // Check for the tree remove iterator operators.
  it = m_It;

  // Check for the tree remove iterator types.
  typename T_Class::TType item;

  // Check for the tree remove iterator methods.
  result = m_It.removeFirstSibling();
  result = m_It.removeFirstSibling(item);
  result = m_It.removeLastSibling();
  result = m_It.removeLastSibling(item);
  result = m_It.removePrevSibling();
  result = m_It.removePrevSibling(item);
  result = m_It.removeNextSibling();
  result = m_It.removeNextSibling(item);
  result = m_It.removeIndexSibling(uindex);
  result = m_It.removeIndexSibling(uindex, item);
  result = m_It.removeAllSiblings();
  result = m_It.removeFirstChild();
  result = m_It.removeFirstChild(item);
  result = m_It.removeLastChild();
  result = m_It.removeLastChild(item);
  result = m_It.removeIndexChild(uindex);
  result = m_It.removeIndexChild(uindex, item);
  result = m_It.removeAllChild();
  count  = m_It.subTree(container, 1, 1);
  count  = m_It.subTreeForwardSibling(container, 1);
  count  = m_It.subTreeBackwardSibling(container, 1);
  count  = m_It.subTreeFirstSibling(container, 1);
  count  = m_It.subTreeLastSibling(container, 1);
  count  = m_It.subTreePrevSibling(container, 1);
  count  = m_It.subTreeNextSibling(container, 1);
  count  = m_It.subTreeIndexSibling(uindex, container, 1, 1);
  result = m_It.subTreeAllSiblings(container);
  count  = m_It.subTreeFirstChild(container, 1);
  count  = m_It.subTreeLastChild(container, 1);
  count  = m_It.subTreeIndexChild(uindex, container, 1, 1);
  result = m_It.subTreeAllChild(container);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
