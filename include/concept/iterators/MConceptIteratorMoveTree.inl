/*!
 *  \file    MConceptIteratorMoveTree.inl Template checking conception.
 *           Checks if template argument is a tree move iterator type.
 *  \brief   Tree move iterator template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree move iterator template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Iterators conception checking
    VERSION:   1.0
    CREATED:   25.07.2006 02:43:08

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
#ifndef __MCONCEPTITERATORMOVETREE_INL__
#define __MCONCEPTITERATORMOVETREE_INL__
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
inline MConceptIteratorMoveTree<T_Class>::MConceptIteratorMoveTree() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptIteratorMoveTree<T_Class>::~MConceptIteratorMoveTree()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptIteratorMoveTree<T_Class>::constraints()
{ CALL
  // Check T_Class template argument constraint to be a backward move iterator.
  MConstraint::requiresConcept<MConceptIteratorMoveBackward<T_Class> >();

  Tbool result;
  Tuint index = 0;
  Tuint count = 0;

  // Check for the forward move iterator types.
  typename T_Class::TIterator it;

  // Check for the forward move iterator methods.
  result = m_It.isRoot();
  it = m_It.getRoot();
  it = m_It.getParent();
  index = m_It.getSiblingIndex();
  count = m_It.getSiblingsCount();
  count = m_It.getPrevSiblingsCount();
  count = m_It.getNextSiblingsCount();
  it = m_It.getFirstSibling();
  it = m_It.getLastSibling();
  it = m_It.getPrevSibling();
  it = m_It.getNextSibling();
  it = m_It.getIndexSibling(index);
  count = m_It.getChildCount();
  it = m_It.getFirstChild();
  it = m_It.getLastChild();
  it = m_It.getIndexChild(index);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
