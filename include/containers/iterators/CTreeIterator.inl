/*!
 *  \file    CTreeIterator.inl Tree constant iterator definitions. It
 *           gives ability to get and modify tree items.
 *  \brief   Tree non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree non constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   24.06.2006 23:27:45

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
#ifndef __CTREEITERATOR_INL__
#define __CTREEITERATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator>::CTreeIterator() :
  NCommon::NIterators::IIterator<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertTree<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveTree<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  m_pContainer(NULL),
  m_pNode(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator>::CTreeIterator(CTree<T_Type, T_Allocator>* a_pContainer) :
  NCommon::NIterators::IIterator<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertTree<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveTree<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  m_pContainer(a_pContainer),
  m_pNode(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator>::CTreeIterator(const CTreeIterator<T_Type, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIterator<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertTree<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveTree<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  m_pContainer(NULL),
  m_pNode(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator>::~CTreeIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator == (const CTreeIterator<T_Type, T_Allocator>& a_crInstance1, const CTreeIterator<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_pNode == a_crInstance2.m_pNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator != (const CTreeIterator<T_Type, T_Allocator>& a_crInstance1, const CTreeIterator<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_pNode != a_crInstance2.m_pNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator>& CTreeIterator<T_Type, T_Allocator>::operator = (const CTreeIterator<T_Type, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator>& CTreeIterator<T_Type, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator>& CTreeIterator<T_Type, T_Allocator>::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator>& CTreeIterator<T_Type, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator>& CTreeIterator<T_Type, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::operator ++ (int)
{ CALL
  CTreeIterator<T_Type, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::operator -- (int)
{ CALL
  CTreeIterator<T_Type, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> operator + (const CTreeIterator<T_Type, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CTreeIterator<T_Type, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> operator - (const CTreeIterator<T_Type, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CTreeIterator<T_Type, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CTreeIterator<T_Type, T_Allocator>::set(const CTreeIterator<T_Type, T_Allocator>& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_pNode = a_crInstance.m_pNode;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::getForward() const
{ CALL
  CTreeIterator<T_Type, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CTreeIterator<T_Type, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::getBackward() const
{ CALL
  CTreeIterator<T_Type, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CTreeIterator<T_Type, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && (m_pNode != NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTree<T_Type, T_Allocator>& CTreeIterator<T_Type, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTree<T_Type, T_Allocator>* CTreeIterator<T_Type, T_Allocator>::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline T_Type& CTreeIterator<T_Type, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_pNode->m_Item;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline T_Type* CTreeIterator<T_Type, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_pNode->m_Item;
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid tree iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step depth forward by given steps.
  TIterator it_next;
  TIterator it_next_sibling;
  while (counter > 0)
  {
    // Visit all child nodes.
    it_next = getFirstChild();
    if (it_next.isValid())
      set(it_next);
    else
    {
      // Visit all sibling nodes.
      it_next = getNextSibling();
      if (it_next.isValid())
        set(it_next);
      else
      {
        Tbool found = false;
        it_next = getParent();
        while (it_next.isValid())
        {
          it_next_sibling = it_next.getNextSibling();
          if (it_next_sibling.isValid())
          {
            set(it_next_sibling);
            found = true;
            break;
          }
          it_next = it_next.getParent();
        }
        if (!found)
          break;
      }
    }
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid tree iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step depth backward by given steps.
  TIterator it_prev;
  TIterator it_prev_sibling;
  while (counter > 0)
  {
    // Visit all child nodes.
    it_prev = getLastChild();
    if (it_prev.isValid())
      set(it_prev);
    else
    {
      // Visit all sibling nodes.
      it_prev = getPrevSibling();
      if (it_prev.isValid())
        set(it_prev);
      else
      {
        Tbool found = false;
        it_prev = getParent();
        while (it_prev.isValid())
        {
          it_prev_sibling = it_prev.getPrevSibling();
          if (it_prev_sibling.isValid())
          {
            set(it_prev_sibling);
            found = true;
            break;
          }
          it_prev = it_prev.getParent();
        }
        if (!found)
          break;
      }
    }
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::isRoot() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator cannot be the root one."))
  {
    return false;
  }

  return (m_pNode->m_pParent == NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::getRoot() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no root node."))
  {
    return CTreeIterator<T_Type, T_Allocator>(m_pContainer);
  }

  CTreeIterator<T_Type, T_Allocator> it(m_pContainer);

  it.m_pNode = m_pNode;
  while (it.m_pNode->m_pParent != NULL)
    it.m_pNode = it.m_pNode->m_pParent;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::getParent() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no parent node."))
  {
    return CTreeIterator<T_Type, T_Allocator>(m_pContainer);
  }

  CTreeIterator<T_Type, T_Allocator> it(m_pContainer);

  it.m_pNode = m_pNode->m_pParent;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::getSiblingIndex() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 0;
  typename TContainer::STreeNode* temp = m_pNode->m_pPrevSibling;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrevSibling;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::getSiblingsCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 1;
  typename TContainer::STreeNode* temp = m_pNode->m_pPrevSibling;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrevSibling;
  }

  temp = m_pNode->m_pNextSibling;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pNextSibling;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::getPrevSiblingsCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 0;
  typename TContainer::STreeNode* temp = m_pNode->m_pPrevSibling;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrevSibling;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::getNextSiblingsCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 0;
  typename TContainer::STreeNode* temp = m_pNode->m_pNextSibling;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pNextSibling;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::getFirstSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return CTreeIterator<T_Type, T_Allocator>(m_pContainer);
  }

  CTreeIterator<T_Type, T_Allocator> it(m_pContainer);

  it.m_pNode = (m_pNode->m_pParent == NULL) ? m_pContainer->m_pFirstRoot : m_pNode->m_pParent->m_pFirstChild;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::getLastSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return CTreeIterator<T_Type, T_Allocator>(m_pContainer);
  }

  CTreeIterator<T_Type, T_Allocator> it(m_pContainer);

  it.m_pNode = (m_pNode->m_pParent == NULL) ? m_pContainer->m_pLastRoot : m_pNode->m_pParent->m_pLastChild;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::getPrevSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return CTreeIterator<T_Type, T_Allocator>(m_pContainer);
  }

  CTreeIterator<T_Type, T_Allocator> it(m_pContainer);

  it.m_pNode = m_pNode->m_pPrevSibling;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::getNextSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return CTreeIterator<T_Type, T_Allocator>(m_pContainer);
  }

  CTreeIterator<T_Type, T_Allocator> it(m_pContainer);

  it.m_pNode = m_pNode->m_pNextSibling;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::getIndexSibling(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return CTreeIterator<T_Type, T_Allocator>(m_pContainer);
  }

  CTreeIterator<T_Type, T_Allocator> it(m_pContainer);

  // Find first sibling.
  typename TContainer::STreeNode* temp = m_pNode;
  while (temp->m_pPrevSibling != NULL)
    temp = temp->m_pPrevSibling;
  // Indexing into siblings.
  Tuint count = a_cIndex;
  while ((count != 0) && (temp->m_pNextSibling != NULL))
  {
    --count;
    temp = temp->m_pNextSibling;
  }
  it.m_pNode = (count == 0) ? temp : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::getChildCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no child."))
  {
    return 0;
  }

  Tuint index = 0;
  typename TContainer::STreeNode* temp = m_pNode->m_pFirstChild;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pNextSibling;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::getFirstChild() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no child."))
  {
    return CTreeIterator<T_Type, T_Allocator>(m_pContainer);
  }

  CTreeIterator<T_Type, T_Allocator> it(m_pContainer);

  it.m_pNode = m_pNode->m_pFirstChild;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::getLastChild() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no child."))
  {
    return CTreeIterator<T_Type, T_Allocator>(m_pContainer);
  }

  CTreeIterator<T_Type, T_Allocator> it(m_pContainer);

  it.m_pNode = m_pNode->m_pLastChild;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIterator<T_Type, T_Allocator> CTreeIterator<T_Type, T_Allocator>::getIndexChild(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no child."))
  {
    return CTreeIterator<T_Type, T_Allocator>(m_pContainer);
  }

  CTreeIterator<T_Type, T_Allocator> it(m_pContainer);

  // Find indexed child.
  Tuint count = a_cIndex;
  typename TContainer::STreeNode* temp = m_pNode->m_pFirstChild;
  if (temp != NULL)
  {
    // Indexing into child.
    while ((count != 0) && (temp->m_pNextSibling != NULL))
    {
      --count;
      temp = temp->m_pNextSibling;
    }
  }
  it.m_pNode = (count == 0) ? temp : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertForward(const T_Type& a_crItem)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid tree container."))
  {
    return false;
  }
  // Check if the iterator container is empty or iterator is in the valid state.
  ASSERT((m_pContainer->isEmpty() || (m_pNode != NULL)), STR("Cannot insert sibling item to the invalid iterator of the non empty tree."))
  {
    return false;
  }

  typename TContainer::STreeNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::STreeNode>(a_crItem);

  if (node != NULL)
  {
    if (m_pNode == NULL)
    {
      // Link root node.
      TContainer::STreeNode::link(NULL, NULL, NULL, node, node);
      // Insert root node.
      m_pContainer->m_pFirstRoot = node;
      m_pContainer->m_pLastRoot = node;
    }
    else
    {
      // Insert sibling node.
      TContainer::STreeNode::link(m_pNode->m_pParent, m_pNode, m_pNode->m_pNextSibling, node, node);
      // Update tree root structure.
      if (m_pContainer->m_pLastRoot == m_pNode)
        m_pContainer->m_pLastRoot = node;
    }
    // Update iterator.
    m_pNode = node;
    // Update container.
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new tree node for the forward iterator inserting into the tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertNext(const T_Type& a_crItem)
{ CALL
  return insertNextSibling(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertBackward(const T_Type& a_crItem)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid tree container."))
  {
    return false;
  }
  // Check if the iterator container is empty or iterator is in the valid state.
  ASSERT((m_pContainer->isEmpty() || (m_pNode != NULL)), STR("Cannot insert sibling item to the invalid iterator of the non empty tree."))
  {
    return false;
  }

  typename TContainer::STreeNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::STreeNode>(a_crItem);

  if (node != NULL)
  {
    if (m_pNode == NULL)
    {
      // Link root node.
      TContainer::STreeNode::link(NULL, NULL, NULL, node, node);
      // Insert root node.
      m_pContainer->m_pFirstRoot = node;
      m_pContainer->m_pLastRoot = node;
    }
    else
    {
      // Insert sibling node.
      TContainer::STreeNode::link(m_pNode->m_pParent, m_pNode->m_pPrevSibling, m_pNode, node, node);
      // Update tree root structure.
      if (m_pContainer->m_pFirstRoot == m_pNode)
        m_pContainer->m_pFirstRoot = node;
    }
    // Update iterator.
    m_pNode = node;
    // Update container.
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new tree node for the backward iterator inserting into the tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertPrev(const T_Type& a_crItem)
{ CALL
  return insertPrevSibling(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertParent(const T_Type& a_crItem, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert parent item to the invalid tree iterator."))
  {
    return false;
  }

  typename TContainer::STreeNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::STreeNode>(a_crItem);

  if (node != NULL)
  {
    // Insert parent node.
    node->link(m_pNode->m_pParent, m_pNode);
    // Update tree root structure.
    if (m_pContainer->m_pFirstRoot == m_pNode)
      m_pContainer->m_pFirstRoot = node;
    if (m_pContainer->m_pLastRoot == m_pNode)
      m_pContainer->m_pLastRoot = node;
    // Update iterator.
    if (a_cUpdate)
      m_pNode = node;
    // Update container.
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new tree node for the parent iterator inserting into the tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertFirstSibling(const T_Type& a_crItem, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid tree container."))
  {
    return false;
  }

  typename TContainer::STreeNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::STreeNode>(a_crItem);

  if (node != NULL)
  {
    // Insert first tree root node.
    if ((m_pNode == NULL) && m_pContainer->isEmpty())
    {
      // Link root node.
      TContainer::STreeNode::link(NULL, NULL, NULL, node, node);
      // Insert root node.
      m_pContainer->m_pFirstRoot = node;
      m_pContainer->m_pLastRoot = node;
      // Update iterator.
      m_pNode = node;
    }
    else
    {
      typename TContainer::STreeNode* first = ((m_pNode == NULL) ? m_pContainer->m_pFirstRoot : getFirstSibling().m_pNode);
      // Link sibling node.
      TContainer::STreeNode::link(first->m_pParent, NULL, first, node, node);
      // Update tree root structure.
      if (m_pContainer->m_pFirstRoot == first)
        m_pContainer->m_pFirstRoot = node;
      // Update iterator.
      if (a_cUpdate)
        m_pNode = node;
    }
    // Update container.
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new tree node for the first sibling iterator inserting into the tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertLastSibling(const T_Type& a_crItem, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid tree container."))
  {
    return false;
  }

  typename TContainer::STreeNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::STreeNode>(a_crItem);

  if (node != NULL)
  {
    // Insert last tree root node.
    if ((m_pNode == NULL) && m_pContainer->isEmpty())
    {
      // Link root node.
      TContainer::STreeNode::link(NULL, NULL, NULL, node, node);
      // Insert root node.
      m_pContainer->m_pFirstRoot = node;
      m_pContainer->m_pLastRoot = node;
      // Update iterator.
      m_pNode = node;
    }
    else
    {
      typename TContainer::STreeNode* last = ((m_pNode == NULL) ? m_pContainer->m_pLastRoot : getLastSibling().m_pNode);
      // Link sibling node.
      TContainer::STreeNode::link(last->m_pParent, last, NULL, node, node);
      // Update tree root structure.
      if (m_pContainer->m_pLastRoot == last)
        m_pContainer->m_pLastRoot = node;
      // Update iterator.
      if (a_cUpdate)
        m_pNode = node;
    }
    // Update container.
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new tree node for the last sibling iterator inserting into the tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertPrevSibling(const T_Type& a_crItem, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Inserting to the previous sibling position can be made only for the valid tree iterator."))
  {
    return false;
  }

  typename TContainer::STreeNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::STreeNode>(a_crItem);

  if (node != NULL)
  {
    // Insert sibling node.
    TContainer::STreeNode::link(m_pNode->m_pParent, m_pNode->m_pPrevSibling, m_pNode, node, node);
    // Update tree root structure.
    if (m_pContainer->m_pFirstRoot == m_pNode)
      m_pContainer->m_pFirstRoot = node;
    // Update iterator.
    if (a_cUpdate)
      m_pNode = node;
    // Update container.
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new tree node for the previous sibling iterator inserting into the tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertNextSibling(const T_Type& a_crItem, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Inserting to the next sibling position can be made only for the valid tree iterator."))
  {
    return false;
  }

  typename TContainer::STreeNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::STreeNode>(a_crItem);

  if (node != NULL)
  {
    // Link sibling node.
    TContainer::STreeNode::link(m_pNode->m_pParent, m_pNode, m_pNode->m_pNextSibling, node, node);
    // Update tree root structure.
    if (m_pContainer->m_pLastRoot == m_pNode)
      m_pContainer->m_pLastRoot = node;
    // Update iterator.
    if (a_cUpdate)
      m_pNode = node;
    // Update container.
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new tree node for the next sibling iterator inserting into the tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertIndexSibling(const Tuint a_cIndex, const T_Type& a_crItem, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid tree container."))
  {
    return false;
  }

  // Find sibling position to insert.
  Tuint index = 0;
  typename TContainer::STreeNode* sibling = ((m_pNode == NULL) ? m_pContainer->m_pFirstRoot : getFirstSibling().m_pNode);
  if (sibling != NULL)
    while ((index < a_cIndex) && (sibling->m_pNextSibling != NULL))
    {
      ++index;
      sibling = sibling->m_pNextSibling;
    }

  // Detect sibling index out of bounds.
  ASSERT(!(((sibling == NULL) && (a_cIndex > 0)) || ((sibling != NULL) && ((index + 1) < a_cIndex))), STR("Cannot insert sibling item into the tree sibling node with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA index)
  {
    return false;
  }

  typename TContainer::STreeNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::STreeNode>(a_crItem);

  if (node != NULL)
  {
    // Insert sibling node.
    if (sibling == NULL)
    {
      // Link root node.
      TContainer::STreeNode::link(NULL, NULL, NULL, node, node);
      // Insert root node.
      m_pContainer->m_pFirstRoot = node;
      m_pContainer->m_pLastRoot = node;
      // Update iterator.
      m_pNode = node;
    }
    else if (index != a_cIndex)
    {
      // Link sibling node.
      TContainer::STreeNode::link(sibling->m_pParent, sibling, sibling->m_pNextSibling, node, node);
      // Update tree root structure.
      if (m_pContainer->m_pLastRoot == sibling)
        m_pContainer->m_pLastRoot = node;
      // Update iterator.
      if (a_cUpdate)
        m_pNode = node;
    }
    else
    {
      // Link sibling node.
      TContainer::STreeNode::link(sibling->m_pParent, sibling->m_pPrevSibling, sibling, node, node);
      // Update tree root structure.
      if (m_pContainer->m_pFirstRoot == sibling)
        m_pContainer->m_pFirstRoot = node;
      // Update iterator.
      if (a_cUpdate)
        m_pNode = node;
    }
    // Update container.
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new tree node for the indexed sibling iterator inserting into the tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertFirstChild(const T_Type& a_crItem, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert child item to the invalid tree iterator."))
  {
    return false;
  }

  typename TContainer::STreeNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::STreeNode>(a_crItem);

  if (node != NULL)
  {
    // Link child node.
    TContainer::STreeNode::link(m_pNode, NULL, m_pNode->m_pFirstChild, node, node);
    // Update iterator.
    if (a_cUpdate)
      m_pNode = node;
    // Update container.
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new tree node for the first child iterator inserting into the tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertLastChild(const T_Type& a_crItem, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert child item to the invalid tree iterator."))
  {
    return false;
  }

  typename TContainer::STreeNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::STreeNode>(a_crItem);

  if (node != NULL)
  {
    // Link child node.
    TContainer::STreeNode::link(m_pNode, m_pNode->m_pLastChild, NULL, node, node);
    // Update iterator.
    if (a_cUpdate)
      m_pNode = node;
    // Update container.
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new tree node for the last child iterator inserting into the tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertIndexChild(const Tuint a_cIndex, const T_Type& a_crItem, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert child item to the invalid tree iterator."))
  {
    return false;
  }

  // Find child position to insert.
  Tuint index = 0;
  typename TContainer::STreeNode* child = m_pNode->m_pFirstChild;
  if (child != NULL)
    while ((index < a_cIndex) && (child->m_pNextSibling != NULL))
    {
      ++index;
      child = child->m_pNextSibling;
    }

  // Detect child index out of bounds.
  ASSERT(!(((child == NULL) && (a_cIndex > 0)) || ((child != NULL) && ((index + 1) < a_cIndex))), STR("Cannot insert child item into the tree child node with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA index)
  {
    return false;
  }

  typename TContainer::STreeNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::STreeNode>(a_crItem);

  if (node != NULL)
  {
    // Link child node.
    if (child == NULL)
      TContainer::STreeNode::link(m_pNode, NULL, NULL, node, node);
    else if (index != a_cIndex)
      TContainer::STreeNode::link(m_pNode, child, child->m_pNextSibling, node, node);
    else
      TContainer::STreeNode::link(m_pNode, child->m_pPrevSibling, child, node, node);
    // Update iterator.
    if (a_cUpdate)
      m_pNode = node;
    // Update container.
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new tree node for the indexed child iterator inserting into the tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertSubTreeFirstSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a sub-tree into the invalid tree container."))
  {
    return false;
  }

  // Insert empty sub-tree.
  if (a_rSubTree.isEmpty())
    return true;

  // Insert first tree root node.
  if ((m_pNode == NULL) && m_pContainer->isEmpty())
  {
    // Link root sub-tree.
    TContainer::STreeNode::link(NULL, NULL, NULL, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
    // Update tree root structure.
    m_pContainer->m_pFirstRoot = a_rSubTree.m_pFirstRoot;
    m_pContainer->m_pLastRoot = a_rSubTree.m_pLastRoot;
    // Update iterator.
    m_pNode = m_pContainer->m_pFirstRoot;
  }
  else
  {
    typename TContainer::STreeNode* first = ((m_pNode == NULL) ? m_pContainer->m_pFirstRoot : getFirstSibling().m_pNode);
    // Link sibling sub-tree.
    TContainer::STreeNode::link(first->m_pParent, NULL, first, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
    // Update tree root structure.
    if (m_pContainer->m_pFirstRoot == first)
      m_pContainer->m_pFirstRoot = a_rSubTree.m_pFirstRoot;
    // Update iterator.
    if (a_cUpdate)
      m_pNode = a_rSubTree.m_pFirstRoot;
  }
  // Update current container.
  m_pContainer->m_Size += a_rSubTree.m_Size;
  // Update given container.
  a_rSubTree.m_pFirstRoot = NULL;
  a_rSubTree.m_pLastRoot = NULL;
  a_rSubTree.m_Size = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertSubTreeLastSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a sub-tree into the invalid tree container."))
  {
    return false;
  }

  // Insert empty sub-tree.
  if (a_rSubTree.isEmpty())
    return true;

  // Insert last tree root node.
  if ((m_pNode == NULL) && m_pContainer->isEmpty())
  {
    // Link root sub-tree.
    TContainer::STreeNode::link(NULL, NULL, NULL, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
    // Update tree root structure.
    m_pContainer->m_pFirstRoot = a_rSubTree.m_pFirstRoot;
    m_pContainer->m_pLastRoot = a_rSubTree.m_pLastRoot;
    // Update iterator.
    m_pNode = m_pContainer->m_pFirstRoot;
  }
  else
  {
    typename TContainer::STreeNode* last = ((m_pNode == NULL) ? m_pContainer->m_pLastRoot : getLastSibling().m_pNode);
    // Link sibling sub-tree.
    TContainer::STreeNode::link(last->m_pParent, last, NULL, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
    // Update tree root structure.
    if (m_pContainer->m_pLastRoot == last)
      m_pContainer->m_pLastRoot = a_rSubTree.m_pLastRoot;
    // Update iterator.
    if (a_cUpdate)
      m_pNode = a_rSubTree.m_pFirstRoot;
  }
  // Update current container.
  m_pContainer->m_Size += a_rSubTree.m_Size;
  // Update given container.
  a_rSubTree.m_pFirstRoot = NULL;
  a_rSubTree.m_pLastRoot = NULL;
  a_rSubTree.m_Size = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertSubTreePrevSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Inserting to the previous sibling position can be made only for the valid tree iterator."))
  {
    return false;
  }

  // Insert empty sub-tree.
  if (a_rSubTree.isEmpty())
    return true;

  // Link sibling sub-tree.
  TContainer::STreeNode::link(m_pNode->m_pParent, m_pNode->m_pPrevSibling, m_pNode, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
  // Update tree root structure.
  if (m_pContainer->m_pFirstRoot == m_pNode)
    m_pContainer->m_pFirstRoot = a_rSubTree.m_pFirstRoot;
  // Update iterator.
  if (a_cUpdate)
    m_pNode = a_rSubTree.m_pFirstRoot;
  // Update current container.
  m_pContainer->m_Size += a_rSubTree.m_Size;
  // Update given container.
  a_rSubTree.m_pFirstRoot = NULL;
  a_rSubTree.m_pLastRoot = NULL;
  a_rSubTree.m_Size = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertSubTreeNextSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Inserting to the next sibling position can be made only for the valid tree iterator."))
  {
    return false;
  }

  // Insert empty sub-tree.
  if (a_rSubTree.isEmpty())
    return true;

  // Link sibling sub-tree.
  TContainer::STreeNode::link(m_pNode->m_pParent, m_pNode, m_pNode->m_pNextSibling, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
  // Update tree root structure.
  if (m_pContainer->m_pLastRoot == m_pNode)
    m_pContainer->m_pLastRoot = a_rSubTree.m_pLastRoot;
  // Update iterator.
  if (a_cUpdate)
    m_pNode = a_rSubTree.m_pFirstRoot;
  // Update current container.
  m_pContainer->m_Size += a_rSubTree.m_Size;
  // Update given container.
  a_rSubTree.m_pFirstRoot = NULL;
  a_rSubTree.m_pLastRoot = NULL;
  a_rSubTree.m_Size = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertSubTreeIndexSibling(const Tuint a_cIndex, CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a sub-tree into the invalid tree container."))
  {
    return false;
  }

  // Insert empty sub-tree.
  if (a_rSubTree.isEmpty())
    return true;

  // Find sibling position to insert.
  Tuint index = 0;
  typename TContainer::STreeNode* sibling = ((m_pNode == NULL) ? m_pContainer->m_pFirstRoot : getFirstSibling().m_pNode);
  if (sibling != NULL)
    while ((index < a_cIndex) && (sibling->m_pNextSibling != NULL))
    {
      ++index;
      sibling = sibling->m_pNextSibling;
    }

  // Detect sibling index out of bounds.
  ASSERT(!(((sibling == NULL) && (a_cIndex > 0)) || ((sibling != NULL) && ((index + 1) < a_cIndex))), STR("Cannot insert a sub-tree into the tree sibling node with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA index)
  {
    return false;
  }

  // Insert sibling sub-tree.
  if (sibling == NULL)
  {
    // Link root sub-tree.
    TContainer::STreeNode::link(NULL, NULL, NULL, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
    // Update tree root structure.
    m_pContainer->m_pFirstRoot = a_rSubTree.m_pFirstRoot;
    m_pContainer->m_pLastRoot = a_rSubTree.m_pLastRoot;
    // Update iterator.
    m_pNode = m_pContainer->m_pFirstRoot;
  }
  else if (index != a_cIndex)
  {
    // Link sibling sub-tree.
    TContainer::STreeNode::link(sibling->m_pParent, sibling, sibling->m_pNextSibling, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
    // Update tree root structure.
    if (m_pContainer->m_pLastRoot == sibling)
      m_pContainer->m_pLastRoot = a_rSubTree.m_pLastRoot;
    // Update iterator.
    if (a_cUpdate)
      m_pNode = a_rSubTree.m_pFirstRoot;
  }
  else
  {
    // Link sibling sub-tree.
    TContainer::STreeNode::link(sibling->m_pParent, sibling->m_pPrevSibling, sibling, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
    // Update tree root structure.
    if (m_pContainer->m_pFirstRoot == sibling)
      m_pContainer->m_pFirstRoot = a_rSubTree.m_pFirstRoot;
    // Update iterator.
    if (a_cUpdate)
      m_pNode = a_rSubTree.m_pFirstRoot;
  }
  // Update current container.
  m_pContainer->m_Size += a_rSubTree.m_Size;
  // Update given container.
  a_rSubTree.m_pFirstRoot = NULL;
  a_rSubTree.m_pLastRoot = NULL;
  a_rSubTree.m_Size = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertSubTreeFirstChild(CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert first child sub-tree item to the invalid tree iterator."))
  {
    return false;
  }

  // Insert empty sub-tree.
  if (a_rSubTree.isEmpty())
    return true;

  // Link child sub-tree.
  TContainer::STreeNode::link(m_pNode, NULL, m_pNode->m_pFirstChild, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
  // Update iterator.
  if (a_cUpdate)
    m_pNode = a_rSubTree.m_pFirstRoot;
  // Update current container.
  m_pContainer->m_Size += a_rSubTree.m_Size;
  // Update given container.
  a_rSubTree.m_pFirstRoot = NULL;
  a_rSubTree.m_pLastRoot = NULL;
  a_rSubTree.m_Size = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertSubTreeLastChild(CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert last child sub-tree item to the invalid tree iterator."))
  {
    return false;
  }

  // Insert empty sub-tree.
  if (a_rSubTree.isEmpty())
    return true;

  // Link child sub-tree.
  TContainer::STreeNode::link(m_pNode, m_pNode->m_pLastChild, NULL, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
  // Update iterator.
  if (a_cUpdate)
    m_pNode = a_rSubTree.m_pFirstRoot;
  // Update current container.
  m_pContainer->m_Size += a_rSubTree.m_Size;
  // Update given container.
  a_rSubTree.m_pFirstRoot = NULL;
  a_rSubTree.m_pLastRoot = NULL;
  a_rSubTree.m_Size = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::insertSubTreeIndexChild(const Tuint a_cIndex, CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert index child sub-tree item to the invalid tree iterator."))
  {
    return false;
  }

  // Find child position to insert.
  Tuint index = 0;
  typename TContainer::STreeNode* child = m_pNode->m_pFirstChild;
  if (child != NULL)
    while ((index < a_cIndex) && (child->m_pNextSibling != NULL))
    {
      ++index;
      child = child->m_pNextSibling;
    }

  // Detect child index out of bounds.
  ASSERT(!(((child == NULL) && (a_cIndex > 0)) || ((child != NULL) && ((index + 1) < a_cIndex))), STR("Cannot insert child sub-tree into the tree child node with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA index)
  {
    return false;
  }

  // Insert empty sub-tree.
  if (a_rSubTree.isEmpty())
    return true;

  // Link child sub-tree.
  if (child == NULL)
    TContainer::STreeNode::link(m_pNode, NULL, NULL, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
  else if (index != a_cIndex)
    TContainer::STreeNode::link(m_pNode, child, child->m_pNextSibling, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
  else
    TContainer::STreeNode::link(m_pNode, child->m_pPrevSibling, child, a_rSubTree.m_pFirstRoot, a_rSubTree.m_pLastRoot);
  // Update iterator.
  if (a_cUpdate)
    m_pNode = a_rSubTree.m_pFirstRoot;
  // Update current container.
  m_pContainer->m_Size += a_rSubTree.m_Size;
  // Update given container.
  a_rSubTree.m_pFirstRoot = NULL;
  a_rSubTree.m_pLastRoot = NULL;
  a_rSubTree.m_Size = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::flatten(const Tbool a_cChildToRight/* = true */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot flatten child items in the invalid tree iterator."))
  {
    return false;
  }

  // Flatten child items.
  typename TContainer::STreeNode* first_child = m_pNode->m_pFirstChild;
  typename TContainer::STreeNode* last_child = m_pNode->m_pLastChild;
  if ((first_child != NULL) && (last_child != NULL))
  {
    // Clear child links in current tree node.
    m_pNode->m_pFirstChild = NULL;
    m_pNode->m_pLastChild = NULL;
    // Update parent link in child tree nodes.
    typename TContainer::STreeNode* cur_child = first_child;
    while (cur_child != NULL)
    {
      cur_child->m_pParent = m_pNode->m_pParent;
      cur_child = cur_child->m_pNextSibling;
    }
    // Update siblings links in child tree nodes.
    if (a_cChildToRight)
    {
      // Links with the last child node.
      last_child->m_pNextSibling = m_pNode->m_pNextSibling;
      if (last_child->m_pNextSibling != NULL)
        last_child->m_pNextSibling->m_pPrevSibling = last_child;
      // Links with the first child node.
      first_child->m_pPrevSibling = m_pNode;
      m_pNode->m_pNextSibling = first_child;
      // Update child links inside the parent tree node.
      if (m_pNode->m_pParent == NULL)
      {
        if (m_pContainer->m_pLastRoot == m_pNode)
          m_pContainer->m_pLastRoot = last_child;
      }
      else
      {
        if (m_pNode->m_pParent->m_pLastChild == m_pNode)
          m_pNode->m_pParent->m_pLastChild = last_child;
      }
    }
    else
    {
      // Links with the first child node.
      first_child->m_pPrevSibling = m_pNode->m_pPrevSibling;
      if (first_child->m_pPrevSibling != NULL)
        first_child->m_pPrevSibling->m_pNextSibling = first_child;
      // Links with the last child node.
      last_child->m_pNextSibling = m_pNode;
      m_pNode->m_pPrevSibling = last_child;
      // Update child links inside the parent tree node.
      if (m_pNode->m_pParent == NULL)
      {
        if (m_pContainer->m_pFirstRoot == m_pNode)
          m_pContainer->m_pFirstRoot = first_child;
      }
      else
      {
        if (m_pNode->m_pParent->m_pFirstChild == m_pNode)
          m_pNode->m_pParent->m_pFirstChild = first_child;
      }
    }
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeForward()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove sibling item from the invalid tree iterator."))
  {
    return false;
  }

  // Remove all child items from the current node.
  if (!removeAllChild())
    return false;

  // Save current node links.
  typename TContainer::STreeNode* parent = m_pNode->m_pParent;
  typename TContainer::STreeNode* prev = m_pNode->m_pPrevSibling;
  typename TContainer::STreeNode* next = m_pNode->m_pNextSibling;

  if (m_pContainer->m_Allocator.deleteOne(m_pNode))
  {
    // Unlink current node.
    TContainer::STreeNode::unlink(parent, prev, next);
    // Update tree root node.
    if (parent == NULL)
    {
      if (prev == NULL)
        m_pContainer->m_pFirstRoot = next;
      if (next == NULL)
        m_pContainer->m_pLastRoot = prev;
    }
    // Update iterator.
    if (next != NULL)
      m_pNode = next;
    else if (prev != NULL)
      m_pNode = prev;
    else
      m_pNode = parent;
    // Update container.
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove tree node from the current position of the tree iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeForward(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove sibling item from the invalid tree iterator."))
  {
    return false;
  }

  // Remove all child items from the current node.
  if (!removeAllChild())
    return false;

  // Save current node links.
  typename TContainer::STreeNode* parent = m_pNode->m_pParent;
  typename TContainer::STreeNode* prev = m_pNode->m_pPrevSibling;
  typename TContainer::STreeNode* next = m_pNode->m_pNextSibling;

  a_rItem = m_pNode->m_Item;
  if (m_pContainer->m_Allocator.deleteOne(m_pNode))
  {
    // Unlink current node.
    TContainer::STreeNode::unlink(parent, prev, next);
    // Update tree root node.
    if (parent == NULL)
    {
      if (prev == NULL)
        m_pContainer->m_pFirstRoot = next;
      if (next == NULL)
        m_pContainer->m_pLastRoot = prev;
    }
    // Update iterator.
    if (next != NULL)
      m_pNode = next;
    else if (prev != NULL)
      m_pNode = prev;
    else
      m_pNode = parent;
    // Update container.
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove tree node from the current position of the tree iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeNext()
{ CALL
  return removeNextSibling();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeNext(T_Type& a_rItem)
{ CALL
  return removeNextSibling(a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeBackward()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove sibling item from the invalid tree iterator."))
  {
    return false;
  }

  // Remove all child items from the current node.
  if (!removeAllChild())
    return false;

  // Save current node links.
  typename TContainer::STreeNode* parent = m_pNode->m_pParent;
  typename TContainer::STreeNode* prev = m_pNode->m_pPrevSibling;
  typename TContainer::STreeNode* next = m_pNode->m_pNextSibling;

  if (m_pContainer->m_Allocator.deleteOne(m_pNode))
  {
    // Unlink current node.
    TContainer::STreeNode::unlink(parent, prev, next);
    // Update tree root node.
    if (parent == NULL)
    {
      if (prev == NULL)
        m_pContainer->m_pFirstRoot = next;
      if (next == NULL)
        m_pContainer->m_pLastRoot = prev;
    }
    // Update iterator.
    if (prev != NULL)
      m_pNode = prev;
    else if (next != NULL)
      m_pNode = next;
    else
      m_pNode = parent;
    // Update container.
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove tree node from the current position of the tree iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeBackward(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove sibling item from the invalid tree iterator."))
  {
    return false;
  }

  // Remove all child items from the current node.
  if (!removeAllChild())
    return false;

  // Save current node links.
  typename TContainer::STreeNode* parent = m_pNode->m_pParent;
  typename TContainer::STreeNode* prev = m_pNode->m_pPrevSibling;
  typename TContainer::STreeNode* next = m_pNode->m_pNextSibling;

  a_rItem = m_pNode->m_Item;
  if (m_pContainer->m_Allocator.deleteOne(m_pNode))
  {
    // Unlink current node.
    TContainer::STreeNode::unlink(parent, prev, next);
    // Update tree root node.
    if (parent == NULL)
    {
      if (prev == NULL)
        m_pContainer->m_pFirstRoot = next;
      if (next == NULL)
        m_pContainer->m_pLastRoot = prev;
    }
    // Update iterator.
    if (prev != NULL)
      m_pNode = prev;
    else if (next != NULL)
      m_pNode = next;
    else
      m_pNode = parent;
    // Update container.
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove tree node from the current position of the tree iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::STreeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removePrev()
{ CALL
  return removePrevSibling();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removePrev(T_Type& a_rItem)
{ CALL
  return removePrevSibling(a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeFirstSibling()
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove first sibling item from the invalid tree container."))
  {
    return false;
  }
  // Check if the iterator container is not empty.
  ASSERT(!m_pContainer->isEmpty(), STR("Cannot remove first sibling item from the empty tree container."))
  {
    return false;
  }

  // Get first sibling iterator.
  CTreeIterator<T_Type, T_Allocator> it_first((m_pNode == NULL) ? m_pContainer->getItFirstRoot() : getFirstSibling());
  // Get new current iterator position.
  typename TContainer::STreeNode* current = m_pNode;
  if (current == it_first.m_pNode)
  {
    if (it_first.m_pNode->m_pNextSibling != NULL)
      current = it_first.m_pNode->m_pNextSibling;
    else
      current = it_first.m_pNode->m_pParent;
  }
  // Remove from first sibling iterator position.
  if (it_first.removeForward())
  {
    // Update iterator.
    m_pNode = current;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeFirstSibling(T_Type& a_rItem)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove first sibling item from the invalid tree container."))
  {
    return false;
  }
  // Check if the iterator container is not empty.
  ASSERT(!m_pContainer->isEmpty(), STR("Cannot remove first sibling item from the empty tree container."))
  {
    return false;
  }

  // Get first sibling iterator.
  CTreeIterator<T_Type, T_Allocator> it_first((m_pNode == NULL) ? m_pContainer->getItFirstRoot() : getFirstSibling());
  // Get new current iterator position.
  typename TContainer::STreeNode* current = m_pNode;
  if (current == it_first.m_pNode)
  {
    if (it_first.m_pNode->m_pNextSibling != NULL)
      current = it_first.m_pNode->m_pNextSibling;
    else
      current = it_first.m_pNode->m_pParent;
  }
  // Remove from first sibling iterator position.
  if (it_first.removeForward(a_rItem))
  {
    // Update iterator.
    m_pNode = current;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeLastSibling()
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove last sibling item from the invalid tree container."))
  {
    return false;
  }
  // Check if the iterator container is not empty.
  ASSERT(!m_pContainer->isEmpty(), STR("Cannot remove last sibling item from the empty tree container."))
  {
    return false;
  }

  // Get last sibling iterator.
  CTreeIterator<T_Type, T_Allocator> it_last((m_pNode == NULL) ? m_pContainer->getItLastRoot() : getLastSibling());
  // Get new current iterator position.
  typename TContainer::STreeNode* current = m_pNode;
  if (current == it_last.m_pNode)
  {
    if (it_last.m_pNode->m_pPrevSibling != NULL)
      current = it_last.m_pNode->m_pPrevSibling;
    else
      current = it_last.m_pNode->m_pParent;
  }
  // Remove from last sibling iterator position.
  if (it_last.removeBackward())
  {
    // Update iterator.
    m_pNode = current;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeLastSibling(T_Type& a_rItem)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove last sibling item from the invalid tree container."))
  {
    return false;
  }
  // Check if the iterator container is not empty.
  ASSERT(!m_pContainer->isEmpty(), STR("Cannot remove last sibling item from the empty tree container."))
  {
    return false;
  }

  // Get last sibling iterator.
  CTreeIterator<T_Type, T_Allocator> it_last((m_pNode == NULL) ? m_pContainer->getItLastRoot() : getLastSibling());
  // Get new current iterator position.
  typename TContainer::STreeNode* current = m_pNode;
  if (current == it_last.m_pNode)
  {
    if (it_last.m_pNode->m_pPrevSibling != NULL)
      current = it_last.m_pNode->m_pPrevSibling;
    else
      current = it_last.m_pNode->m_pParent;
  }
  // Remove from last sibling iterator position.
  if (it_last.removeBackward(a_rItem))
  {
    // Update iterator.
    m_pNode = current;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removePrevSibling()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove previous sibling item from the invalid tree iterator."))
  {
    return false;
  }
  // Check if the iterator is not the first sibling one.
  ASSERT((m_pNode->m_pPrevSibling != NULL), STR("Cannot remove previous sibling item from the first sibling tree node."))
  {
    return false;
  }

  // Remove from the previous sibling iterator position.
  return getPrevSibling().removeBackward();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removePrevSibling(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove previous sibling item from the invalid tree iterator."))
  {
    return false;
  }
  // Check if the iterator is not the first sibling one.
  ASSERT((m_pNode->m_pPrevSibling != NULL), STR("Cannot remove previous sibling item from the first sibling tree node."))
  {
    return false;
  }

  // Remove from the previous sibling iterator position.
  return getPrevSibling().removeBackward(a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeNextSibling()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove next sibling item from the invalid tree iterator."))
  {
    return false;
  }
  // Check if the iterator is not the last sibling one.
  ASSERT((m_pNode->m_pNextSibling != NULL), STR("Cannot remove next sibling item from the last sibling tree node."))
  {
    return false;
  }

  // Remove from the next sibling iterator position.
  return getNextSibling().removeForward();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeNextSibling(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove next sibling item from the invalid tree iterator."))
  {
    return false;
  }
  // Check if the iterator is not the last sibling one.
  ASSERT((m_pNode->m_pNextSibling != NULL), STR("Cannot remove next sibling item from the last sibling tree node."))
  {
    return false;
  }

  // Remove from the next sibling iterator position.
  return getNextSibling().removeForward(a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeIndexSibling(const Tuint a_cIndex)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove indexed sibling item from the invalid tree container."))
  {
    return false;
  }
  // Check if the iterator container is not empty.
  ASSERT(!m_pContainer->isEmpty(), STR("Cannot remove indexed sibling item from the empty tree container."))
  {
    return false;
  }

  // Get indexed sibling iterator.
  CTreeIterator<T_Type, T_Allocator> it_index((m_pNode == NULL) ? m_pContainer->getItFirstRoot().getIndexSibling(a_cIndex) : getIndexSibling(a_cIndex));

  // Check if the indexed sibling iterator is in the valid state.
  ASSERT(it_index.isValid(), STR("Cannot remove indexed sibling item with the index out of bounds."))
  {
    return false;
  }

  // Get new current iterator position.
  typename TContainer::STreeNode* current = m_pNode;
  if (current == it_index.m_pNode)
  {
    if (it_index.m_pNode->m_pPrevSibling != NULL)
      current = it_index.m_pNode->m_pPrevSibling;
    else if (it_index.m_pNode->m_pNextSibling != NULL)
      current = it_index.m_pNode->m_pNextSibling;
    else
      current = it_index.m_pNode->m_pParent;
  }
  // Remove from indexed sibling iterator position.
  if (it_index.removeForward())
  {
    // Update iterator.
    m_pNode = current;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeIndexSibling(const Tuint a_cIndex, T_Type& a_rItem)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove indexed sibling item from the invalid tree container."))
  {
    return false;
  }
  // Check if the iterator container is not empty.
  ASSERT(!m_pContainer->isEmpty(), STR("Cannot remove indexed sibling item from the empty tree container."))
  {
    return false;
  }

  // Get indexed sibling iterator.
  CTreeIterator<T_Type, T_Allocator> it_index((m_pNode == NULL) ? m_pContainer->getItFirstRoot().getIndexSibling(a_cIndex) : getIndexSibling(a_cIndex));

  // Check if the indexed sibling iterator is in the valid state.
  ASSERT(it_index.isValid(), STR("Cannot remove indexed sibling item with the index out of bounds."))
  {
    return false;
  }

  // Get new current iterator position.
  typename TContainer::STreeNode* current = m_pNode;
  if (current == it_index.m_pNode)
  {
    if (it_index.m_pNode->m_pPrevSibling != NULL)
      current = it_index.m_pNode->m_pPrevSibling;
    else if (it_index.m_pNode->m_pNextSibling != NULL)
      current = it_index.m_pNode->m_pNextSibling;
    else
      current = it_index.m_pNode->m_pParent;
  }
  // Remove from indexed sibling iterator position.
  if (it_index.removeForward(a_rItem))
  {
    // Update iterator.
    m_pNode = current;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeAllSiblings()
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove all sibling items from the invalid tree iterator."))
  {
    return false;
  }

  // Remove all siblings items.
  typename TContainer::STreeNode* parent = (m_pNode == NULL) ? NULL : m_pNode->m_pParent;
  CTreeIterator<T_Type, T_Allocator> sibling((m_pNode == NULL) ? m_pContainer->getItFirstRoot() : getFirstSibling());
  while (sibling.m_pNode != parent)
    if (!sibling.removeForward())
    {
       m_pNode = sibling.m_pNode;
       return false;
    }
  m_pNode = parent;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeFirstChild()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove first child item from the invalid tree iterator."))
  {
    return false;
  }
  // Check if the iterator is has the first child node.
  ASSERT((m_pNode->m_pFirstChild != NULL), STR("Cannot remove first child item from tree node without any child."))
  {
    return false;
  }

  // Remove first child item.
  return getFirstChild().removeForward();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeFirstChild(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove first child item from the invalid tree iterator."))
  {
    return false;
  }
  // Check if the iterator is has the first child node.
  ASSERT((m_pNode->m_pFirstChild != NULL), STR("Cannot remove first child item from tree node without any child."))
  {
    return false;
  }

  // Remove first child item.
  return getFirstChild().removeForward(a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeLastChild()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove last child item from the invalid tree iterator."))
  {
    return false;
  }
  // Check if the iterator is has the last child node.
  ASSERT((m_pNode->m_pLastChild != NULL), STR("Cannot remove last child item from tree node without any child."))
  {
    return false;
  }

  // Remove last child item.
  return getLastChild().removeBackward();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeLastChild(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove last child item from the invalid tree iterator."))
  {
    return false;
  }
  // Check if the iterator is has the last child node.
  ASSERT((m_pNode->m_pLastChild != NULL), STR("Cannot remove last child item from tree node without any child."))
  {
    return false;
  }

  // Remove last child item.
  return getLastChild().removeBackward(a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeIndexChild(const Tuint a_cIndex)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove indexed child item from the invalid tree iterator."))
  {
    return false;
  }

  // Remove indexed child item.
  CTreeIterator<T_Type, T_Allocator> it_child(getIndexChild(a_cIndex));

  // Check if the indexed child iterator is in the valid state.
  ASSERT(it_child.isValid(), STR("Cannot remove indexed child item with the index out of bounds."))
  {
    return false;
  }

  return it_child.removeForward();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeIndexChild(const Tuint a_cIndex, T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove indexed child item from the invalid tree iterator."))
  {
    return false;
  }

  // Remove indexed child item.
  CTreeIterator<T_Type, T_Allocator> it_child(getIndexChild(a_cIndex));

  // Check if the indexed child iterator is in the valid state.
  ASSERT(it_child.isValid(), STR("Cannot remove indexed child item with the index out of bounds."))
  {
    return false;
  }

  return it_child.removeForward(a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::removeAllChild()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove all child items from the invalid tree iterator."))
  {
    return false;
  }

  // Remove all child items.
  if (m_pNode->m_pFirstChild != NULL)
  {
    CTreeIterator<T_Type, T_Allocator> child(getFirstChild());
    while (child.m_pNode != m_pNode)
      if (!child.removeForward())
         return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::subTree(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount, const Tuint a_NextSiblingCount)
{ CALL
  // Extract sub-tree.
  return subTreeEngine(*this, a_rSubTree, a_PrevSiblingCount, a_NextSiblingCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::subTreeForwardSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_NextSiblingCount/* = 0 */)
{ CALL
  // Extract sub-tree.
  return subTreeEngine(*this, a_rSubTree, 0, a_NextSiblingCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::subTreeBackwardSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount/* = 0 */)
{ CALL
  // Extract sub-tree.
  return subTreeEngine(*this, a_rSubTree, a_PrevSiblingCount, 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::subTreeFirstSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_NextSiblingCount/* = 0 */)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot extract first sibling sub-tree from the invalid tree container."))
  {
    a_rSubTree.clear();
    return 0;
  }

  // For empty tree container, just clear the sub-tree.
  if (m_pContainer->isEmpty())
  {
    a_rSubTree.clear();
    return 0;
  }

  // Find first sibling tree iterator.
  CTreeIterator<T_Type, T_Allocator> it_first((m_pNode == NULL) ? m_pContainer->getItFirstRoot() : getFirstSibling());
  // Extract sub-tree.
  return it_first.subTreeEngine(*this, a_rSubTree, 0, a_NextSiblingCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::subTreeLastSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount/* = 0 */)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot extract last sibling sub-tree from the invalid tree container."))
  {
    a_rSubTree.clear();
    return 0;
  }

  // For empty tree container, just clear the sub-tree.
  if (m_pContainer->isEmpty())
  {
    a_rSubTree.clear();
    return 0;
  }

  // Find last sibling tree iterator.
  CTreeIterator<T_Type, T_Allocator> it_last((m_pNode == NULL) ? m_pContainer->getItLastRoot() : getLastSibling());
  // Extract sub-tree.
  return it_last.subTreeEngine(*this, a_rSubTree, a_PrevSiblingCount, 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::subTreePrevSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount/* = 0 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot extract a sub-tree from the invalid tree iterator."))
  {
    a_rSubTree.clear();
    return 0;
  }

  // Extract sub-tree.
  return getPrevSibling().subTreeEngine(*this, a_rSubTree, a_PrevSiblingCount, 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::subTreeNextSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_NextSiblingCount/* = 0 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot extract a sub-tree from the invalid tree iterator."))
  {
    a_rSubTree.clear();
    return 0;
  }

  // Extract sub-tree.
  return getNextSibling().subTreeEngine(*this, a_rSubTree, 0, a_NextSiblingCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::subTreeIndexSibling(const Tuint a_cIndex, CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount/* = 0 */, const Tuint a_NextSiblingCount/* = 0 */)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot extract indexed sibling sub-tree from the invalid tree container."))
  {
    a_rSubTree.clear();
    return 0;
  }

  // For empty tree container, just clear the sub-tree.
  if (m_pContainer->isEmpty())
  {
    a_rSubTree.clear();
    return 0;
  }

  // Find indexed sibling tree iterator.
  CTreeIterator<T_Type, T_Allocator> it_indexed((m_pNode == NULL) ? m_pContainer->getItFirstRoot().getIndexSibling(a_cIndex) : getIndexSibling(a_cIndex));
  // Extract sub-tree.
  return it_indexed.subTreeEngine(*this, a_rSubTree, a_PrevSiblingCount, a_NextSiblingCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::subTreeAllSiblings(CTree<T_Type, T_Allocator>& a_rSubTree)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot extract sibling sub-tree from the invalid tree container."))
  {
    a_rSubTree.clear();
    return false;
  }

  // For empty tree container, just clear the sub-tree.
  if (m_pContainer->isEmpty())
    return a_rSubTree.clear();

  // Find indexed sibling tree iterator.
  CTreeIterator<T_Type, T_Allocator> it((m_pNode == NULL) ? m_pContainer->getItFirstRoot() : getFirstSibling());
  // Extract sub-tree.
  return it.subTreeEngine(*this, a_rSubTree, 0, it.getNextSiblingsCount());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::subTreeFirstChild(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_NextSiblingCount/* = 0 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot extract a sub-tree from the invalid tree iterator."))
  {
    a_rSubTree.clear();
    return 0;
  }

  // For sibling tree node without child, just clear the sub-tree.
  if (getChildCount() == 0)
  {
    a_rSubTree.clear();
    return 0;
  }

  // Extract sub-tree.
  return getFirstChild().subTreeEngine(*this, a_rSubTree, 0, a_NextSiblingCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::subTreeLastChild(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount/* = 0 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot extract a sub-tree from the invalid tree iterator."))
  {
    a_rSubTree.clear();
    return 0;
  }

  // For sibling tree node without child, just clear the sub-tree.
  if (getChildCount() == 0)
  {
    a_rSubTree.clear();
    return 0;
  }

  // Extract sub-tree.
  return getLastChild().subTreeEngine(*this, a_rSubTree, a_PrevSiblingCount, 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::subTreeIndexChild(const Tuint a_cIndex, CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount/* = 0 */, const Tuint a_NextSiblingCount/* = 0 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot extract a sub-tree from the invalid tree iterator."))
  {
    a_rSubTree.clear();
    return 0;
  }

  // Find indexed child tree iterator.
  CTreeIterator<T_Type, T_Allocator> it_child(getIndexChild(a_cIndex));

  // Detect child index out of bounds.
  ASSERT(it_child.isValid(), STR("Cannot extract sub-tree from the indexed child item with the index out of bounds."))
  {
    a_rSubTree.clear();
    return 0;
  }

  // Extract sub-tree.
  return it_child.subTreeEngine(*this, a_rSubTree, a_PrevSiblingCount, a_NextSiblingCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIterator<T_Type, T_Allocator>::subTreeAllChild(CTree<T_Type, T_Allocator>& a_rSubTree)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot extract a sub-tree from the invalid tree iterator."))
  {
    return 0;
  }

  // For sibling tree node without child, just clear the sub-tree.
  Tuint count = getChildCount();
  if (count == 0)
  {
    a_rSubTree.clear();
    return 0;
  }

  // Extract sub-tree.
  return getFirstChild().subTreeEngine(*this, a_rSubTree, 0, count - 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIterator<T_Type, T_Allocator>::subTreeEngine(CTreeIterator<T_Type, T_Allocator>& a_rIterator, CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount/* = 0 */, const Tuint a_NextSiblingCount/* = 0 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot extract a sub-tree from the invalid tree iterator."))
  {
    a_rSubTree.clear();
    return 0;
  }

  // Clear given sub tree.
  if (!a_rSubTree.clear())
    return 0;

  // Find first and last root nodes of extracted tree.
  Tuint size = 0;
  Tuint prev = a_PrevSiblingCount;
  Tuint next = a_NextSiblingCount;
  Tuint count = 1;
  Tbool update = false;
  typename TContainer::STreeNode* parent = m_pNode->m_pParent;
  typename TContainer::STreeNode* first_root = m_pNode;
  typename TContainer::STreeNode* last_root = m_pNode;
  // Update current state.
  size = m_pNode->getAllCount();
  m_pNode->m_pParent = NULL;
  // Check for container update.
  if (m_pNode == a_rIterator.m_pNode)
    update = true;
  // Travel backward.
  while (prev-- > 0)
  {
    // Switch to the previous sibling node.
    if (first_root->m_pPrevSibling != NULL)
      first_root = first_root->m_pPrevSibling;
    else
      break;
    ++count;
    // Increase sub-tree size.
    size += first_root->getAllCount();
    // Clear parent link.
    first_root->m_pParent = NULL;
    // Check for container update.
    if (first_root == a_rIterator.m_pNode)
      update = true;
  }
  // Travel forward.
  while (next-- > 0)
  {
    // Switch to the next sibling node.
    if (last_root->m_pNextSibling != NULL)
      last_root = last_root->m_pNextSibling;
    else
      break;
    ++count;
    // Increase sub-tree size.
    size += last_root->getAllCount();
    // Clear parent link.
    last_root->m_pParent = NULL;
    // Check for container update.
    if (last_root == a_rIterator.m_pNode)
      update = true;
  }

  // Update parent node.
  if (parent == NULL)
  {
    if (m_pContainer->m_pFirstRoot == first_root)
      m_pContainer->m_pFirstRoot = last_root->m_pNextSibling;
    if (m_pContainer->m_pLastRoot == last_root)
      m_pContainer->m_pLastRoot = first_root->m_pPrevSibling;
  }
  else
  {
    if (parent->m_pFirstChild == first_root)
      parent->m_pFirstChild = last_root->m_pNextSibling;
    if (parent->m_pLastChild == last_root)
      parent->m_pLastChild = first_root->m_pPrevSibling;
  }
  // Update sibling nodes.
  if (first_root->m_pPrevSibling != NULL)
    first_root->m_pPrevSibling->m_pNextSibling = last_root->m_pNextSibling;
  if (last_root->m_pNextSibling != NULL)
    last_root->m_pNextSibling->m_pPrevSibling = first_root->m_pPrevSibling;
  first_root->m_pPrevSibling = NULL;
  last_root->m_pNextSibling = NULL;
  // Update current tree.
  m_pContainer->m_Size -= size;
  // Update given sub-tree.
  a_rSubTree.m_pFirstRoot = first_root;
  a_rSubTree.m_pLastRoot = last_root;
  a_rSubTree.m_Size += size;
  // Update current iterator if need.
  if (update)
    a_rIterator.m_pContainer = &a_rSubTree;
  return count;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CTreeIterator<T_Type, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CTreeIterator<T_Type, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CTreeIterator<T_Type, T_Allocator>::swap(CTreeIterator<T_Type, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pContainer, a_rInstance.m_pContainer);
  NAlgorithms::NCommon::swap(m_pNode, a_rInstance.m_pNode);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
