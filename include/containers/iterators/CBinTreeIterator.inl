/*!
 *  \file    CBinTreeIterator.inl Binary tree non constant iterator
 *           definitions. It gives ability to get and modify binary
 *           tree items.
 *  \brief   Binary tree non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Binary tree non constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   31.07.2006 21:18:38

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
#ifndef __CBINTREEITERATOR_INL__
#define __CBINTREEITERATOR_INL__
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
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeIterator() :
  NCommon::NIterators::IIterator<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  m_pContainer(NULL),
  m_pNode(NULL),
  m_pItem(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeIterator(CBinTree<T_Type, T_BinaryPredicate, T_Allocator>* a_pContainer) :
  NCommon::NIterators::IIterator<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  m_pContainer(a_pContainer),
  m_pNode(NULL),
  m_pItem(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeIterator(const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIterator<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  m_pContainer(NULL),
  m_pNode(NULL),
  m_pItem(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::~CBinTreeIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool operator == (const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance1, const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_pNode == a_crInstance2.m_pNode) && (a_crInstance1.m_pItem == a_crInstance2.m_pItem));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool operator != (const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance1, const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_pNode != a_crInstance2.m_pNode) || (a_crInstance1.m_pItem != a_crInstance2.m_pItem));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::operator = (const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::operator ++ (int)
{ CALL
  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::operator -- (int)
{ CALL
  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> operator + (const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> operator - (const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::operator [] (const T_Type& a_crItem) const
{ CALL
  return find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::set(const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_pNode = a_crInstance.m_pNode;
  m_pItem = a_crInstance.m_pItem;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getForward() const
{ CALL
  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getBackward() const
{ CALL
  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && (m_pNode != NULL) && (m_pItem != NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTree<T_Type, T_BinaryPredicate, T_Allocator>* CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline const T_Type& CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_pItem->m_Item;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline const T_Type* CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_pItem->m_Item;
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::find(const T_Type& a_crItem) const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Cannot find given item in the binary tree with the invalid iterator container."));

  return m_pContainer->find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid binary tree iterator."))
  {
    return 0;
  }

  Tbool found;
  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while (counter > 0)
  {
    found = false;
    if (m_pItem->m_pNext != NULL)
    {
      m_pItem = m_pItem->m_pNext;
      found = true;
    }
    else if (m_pNode->m_pRight != NULL)
    {
      m_pNode = m_pNode->m_pRight;
      while (m_pNode->m_pLeft != NULL)
        m_pNode = m_pNode->m_pLeft;
      m_pItem = m_pNode->m_pFirstItem;
      found = true;
    }
    else
    {
      typename TContainer::SBinTreeNode* prev = m_pNode;
      typename TContainer::SBinTreeNode* next = m_pNode->m_pParent;
      while (next != NULL)
      {
        if (next->m_pLeft == prev)
        {
          m_pNode = next;
          m_pItem = m_pNode->m_pFirstItem;
          found = true;
          break;
        }
        prev = next;
        next = next->m_pParent;
      }
    }
    if (found)
      --counter;
    else
      break;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid binary tree iterator."))
  {
    return 0;
  }

  Tbool found;
  Tuint counter = a_cStepCount;
  // Try to step backward by given steps.
  while (counter > 0)
  {
    found = false;
    if (m_pItem->m_pPrev != NULL)
    {
      m_pItem = m_pItem->m_pPrev;
      found = true;
    }
    else if (m_pNode->m_pLeft != NULL)
    {
      m_pNode = m_pNode->m_pLeft;
      while (m_pNode->m_pRight != NULL)
        m_pNode = m_pNode->m_pRight;
      m_pItem = m_pNode->m_pLastItem;
      found = true;
    }
    else
    {
      typename TContainer::SBinTreeNode* prev = m_pNode;
      typename TContainer::SBinTreeNode* next = m_pNode->m_pParent;
      while (next != NULL)
      {
        if (next->m_pRight == prev)
        {
          m_pNode = next;
          m_pItem = m_pNode->m_pLastItem;
          found = true;
          break;
        }
        prev = next;
        next = next->m_pParent;
      }
    }
    if (found)
      --counter;
    else
      break;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::isRoot() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator cannot be the root."))
  {
    return false;
  }

  return (m_pNode->m_pParent == NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getRoot() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no root node."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  it.m_pNode = m_pNode;
  while (it.m_pNode->m_pParent != NULL)
    it.m_pNode = it.m_pNode->m_pParent;
  it.m_pItem = ((it.m_pNode != NULL) ? it.m_pNode->m_pFirstItem : NULL);
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getParent() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no parent node."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  it.m_pNode = m_pNode->m_pParent;
  it.m_pItem = ((it.m_pNode != NULL) ? it.m_pNode->m_pFirstItem : NULL);
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getSiblingIndex() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 0;
  typename TContainer::SBinTreeNode* temp_node = m_pNode;
  typename TContainer::SBinTreeItem* temp_item = m_pItem->m_pPrev;
  // Travel backward through current node items.
  while (temp_item != NULL)
  {
    ++index;
    temp_item = temp_item->m_pPrev;
  }
  // Try to travel through left node items.
  if ((m_pNode->m_pParent != NULL) && (m_pNode->m_pParent->m_pLeft != NULL) && (m_pNode->m_pParent->m_pLeft != m_pNode))
  {
    temp_node = m_pNode->m_pParent->m_pLeft;
    temp_item = m_pNode->m_pParent->m_pLeft->m_pLastItem;
    while (temp_item != NULL)
    {
      ++index;
      temp_item = temp_item->m_pPrev;
    }
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getSiblingsCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 1;
  typename TContainer::SBinTreeNode* temp_node = m_pNode;
  typename TContainer::SBinTreeItem* temp_item = m_pItem->m_pPrev;
  // Travel backward through current node items.
  while (temp_item != NULL)
  {
    ++index;
    temp_item = temp_item->m_pPrev;
  }
  // Try to travel through left node items.
  if ((m_pNode->m_pParent != NULL) && (m_pNode->m_pParent->m_pLeft != NULL) && (m_pNode->m_pParent->m_pLeft != m_pNode))
  {
    temp_node = m_pNode->m_pParent->m_pLeft;
    temp_item = m_pNode->m_pParent->m_pLeft->m_pLastItem;
    while (temp_item != NULL)
    {
      ++index;
      temp_item = temp_item->m_pPrev;
    }
  }
  // Travel forward through current node items.
  temp_node = m_pNode;
  temp_item = m_pItem->m_pNext;
  while (temp_item != NULL)
  {
    ++index;
    temp_item = temp_item->m_pNext;
  }
  // Try to travel through right node items.
  if ((m_pNode->m_pParent != NULL) && (m_pNode->m_pParent->m_pRight != NULL) && (m_pNode->m_pParent->m_pRight != m_pNode))
  {
    temp_node = m_pNode->m_pParent->m_pRight;
    temp_item = m_pNode->m_pParent->m_pRight->m_pFirstItem;
    while (temp_item != NULL)
    {
      ++index;
      temp_item = temp_item->m_pNext;
    }
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getPrevSiblingsCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 0;
  typename TContainer::SBinTreeNode* temp_node = m_pNode;
  typename TContainer::SBinTreeItem* temp_item = m_pItem->m_pPrev;
  // Travel backward through current node items.
  while (temp_item != NULL)
  {
    ++index;
    temp_item = temp_item->m_pPrev;
  }
  // Try to travel through left node items.
  if ((m_pNode->m_pParent != NULL) && (m_pNode->m_pParent->m_pLeft != NULL) && (m_pNode->m_pParent->m_pLeft != m_pNode))
  {
    temp_node = m_pNode->m_pParent->m_pLeft;
    temp_item = m_pNode->m_pParent->m_pLeft->m_pLastItem;
    while (temp_item != NULL)
    {
      ++index;
      temp_item = temp_item->m_pPrev;
    }
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getNextSiblingsCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 0;
  typename TContainer::SBinTreeNode* temp_node = m_pNode;
  typename TContainer::SBinTreeItem* temp_item = m_pItem->m_pNext;
  // Travel forward through current node items.
  while (temp_item != NULL)
  {
    ++index;
    temp_item = temp_item->m_pNext;
  }
  // Try to travel through right node items.
  if ((m_pNode->m_pParent != NULL) && (m_pNode->m_pParent->m_pRight != NULL) && (m_pNode->m_pParent->m_pRight != m_pNode))
  {
    temp_node = m_pNode->m_pParent->m_pRight;
    temp_item = m_pNode->m_pParent->m_pRight->m_pFirstItem;
    while (temp_item != NULL)
    {
      ++index;
      temp_item = temp_item->m_pNext;
    }
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getFirstSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  if ((m_pNode->m_pParent != NULL) && (m_pNode->m_pParent->m_pLeft != NULL) && (m_pNode->m_pParent->m_pLeft != m_pNode))
  {
    it.m_pNode = m_pNode->m_pParent->m_pLeft;
    it.m_pItem = m_pNode->m_pParent->m_pLeft->m_pFirstItem;
  }
  else
  {
    it.m_pNode = m_pNode;
    it.m_pItem = m_pNode->m_pFirstItem;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getLastSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  if ((m_pNode->m_pParent != NULL) && (m_pNode->m_pParent->m_pRight != NULL) && (m_pNode->m_pParent->m_pRight != m_pNode))
  {
    it.m_pNode = m_pNode->m_pParent->m_pRight;
    it.m_pItem = m_pNode->m_pParent->m_pRight->m_pLastItem;
  }
  else
  {
    it.m_pNode = m_pNode;
    it.m_pItem = m_pNode->m_pLastItem;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getPrevSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  if (m_pItem->m_pPrev != NULL)
  {
    it.m_pNode = m_pNode;
    it.m_pItem = m_pItem->m_pPrev;
  }
  else
  {
    if ((m_pNode->m_pParent != NULL) && (m_pNode->m_pParent->m_pLeft != NULL) && (m_pNode->m_pParent->m_pLeft != m_pNode))
    {
      it.m_pNode = m_pNode->m_pParent->m_pLeft;
      it.m_pItem = m_pNode->m_pParent->m_pLeft->m_pLastItem;
    }
    else
    {
      it.m_pNode = NULL;
      it.m_pItem = NULL;
    }
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getNextSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  if (m_pItem->m_pNext != NULL)
  {
    it.m_pNode = m_pNode;
    it.m_pItem = m_pItem->m_pNext;
  }
  else
  {
    if ((m_pNode->m_pParent != NULL) && (m_pNode->m_pParent->m_pRight != NULL) && (m_pNode->m_pParent->m_pRight != m_pNode))
    {
      it.m_pNode = m_pNode->m_pParent->m_pRight;
      it.m_pItem = m_pNode->m_pParent->m_pRight->m_pFirstItem;
    }
    else
    {
      it.m_pNode = NULL;
      it.m_pItem = NULL;
    }
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getIndexSibling(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  // Find first sibling.
  typename TContainer::SBinTreeNode* temp_node = m_pNode;
  typename TContainer::SBinTreeItem* temp_item = m_pNode->m_pFirstItem;
  if ((m_pNode->m_pParent != NULL) && (m_pNode->m_pParent->m_pLeft != NULL) && (m_pNode->m_pParent->m_pLeft != m_pNode))
  {
    temp_node = m_pNode->m_pParent->m_pLeft;
    temp_item = m_pNode->m_pParent->m_pLeft->m_pFirstItem;
  }
  // Indexing into siblings.
  Tuint count = a_cIndex;
  while (count != 0)
  {
    if (temp_item->m_pNext != NULL)
      temp_item = temp_item->m_pNext;
    else if ((temp_node->m_pParent != NULL) && (temp_node->m_pParent->m_pRight != NULL) && (temp_node->m_pParent->m_pRight != temp_node))
    {
      temp_node = temp_node->m_pParent->m_pRight;
      temp_item = temp_node->m_pParent->m_pRight->m_pFirstItem;
    }
    else
      break;
    --count;
  }
  it.m_pNode = (count == 0) ? temp_node : NULL;
  it.m_pItem = (count == 0) ? temp_item : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getChildCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no child."))
  {
    return 0;
  }

  Tuint index = 0;
  typename TContainer::SBinTreeNode* temp_node = (m_pNode->m_pLeft != NULL) ? m_pNode->m_pLeft : m_pNode->m_pRight;
  typename TContainer::SBinTreeItem* temp_item = (temp_node != NULL) ? temp_node->m_pFirstItem : NULL;
  // Travel forward through current child nodes.
  while (temp_item != NULL)
  {
    ++index;
    temp_item = temp_item->m_pNext;
  }
  // Try to travel through right child nodes.
  if ((temp_node != NULL) && (temp_node->m_pParent != NULL) && (temp_node->m_pParent->m_pRight != NULL) && (temp_node->m_pParent->m_pRight != temp_node))
  {
    temp_node = temp_node->m_pParent->m_pRight;
    temp_item = temp_node->m_pParent->m_pRight->m_pFirstItem;
    while (temp_item != NULL)
    {
      ++index;
      temp_item = temp_item->m_pNext;
    }
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getFirstChild() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no child."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  if ((m_pNode->m_pLeft != NULL) || (m_pNode->m_pRight != NULL))
  {
    it.m_pNode = (m_pNode->m_pLeft != NULL) ? m_pNode->m_pLeft : m_pNode->m_pRight;
    it.m_pItem = it.m_pNode->m_pFirstItem;
  }
  else
  {
    it.m_pNode = NULL;
    it.m_pItem = NULL;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getLastChild() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no child."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  if ((m_pNode->m_pLeft != NULL) || (m_pNode->m_pRight != NULL))
  {
    it.m_pNode = (m_pNode->m_pRight != NULL) ? m_pNode->m_pRight : m_pNode->m_pLeft;
    it.m_pItem = it.m_pNode->m_pLastItem;
  }
  else
  {
    it.m_pNode = NULL;
    it.m_pItem = NULL;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getIndexChild(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no child."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  Tuint count = a_cIndex;
  typename TContainer::SBinTreeNode* temp_node = (m_pNode->m_pLeft != NULL) ? m_pNode->m_pLeft : m_pNode->m_pRight;
  typename TContainer::SBinTreeItem* temp_item = (temp_node != NULL) ? temp_node->m_pFirstItem : NULL;
  if ((temp_node != NULL) && (temp_item != NULL))
  {
    // Indexing into child.
    while (count != 0)
    {
      if (temp_item->m_pNext != NULL)
        temp_item = temp_item->m_pNext;
      else if ((temp_node->m_pParent != NULL) && (temp_node->m_pParent->m_pRight != NULL) && (temp_node->m_pParent->m_pRight != temp_node))
      {
        temp_node = temp_node->m_pParent->m_pRight;
        temp_item = temp_node->m_pParent->m_pRight->m_pFirstItem;
      }
      else
        break;
      --count;
    }
  }
  it.m_pNode = (count == 0) ? temp_node : NULL;
  it.m_pItem = (count == 0) ? temp_item : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getSameIndex() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return 0;
  }

  Tuint index = 0;
  typename TContainer::SBinTreeItem* temp = m_pItem->m_pPrev;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrev;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getSameCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return 0;
  }

  Tuint index = 1;
  typename TContainer::SBinTreeItem* temp = m_pItem->m_pPrev;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrev;
  }

  temp = m_pItem->m_pNext;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pNext;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getPrevSameCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return 0;
  }

  Tuint index = 0;
  typename TContainer::SBinTreeItem* temp = m_pItem->m_pPrev;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrev;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getNextSameCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return 0;
  }

  Tuint index = 0;
  typename TContainer::SBinTreeItem* temp = m_pItem->m_pNext;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pNext;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getFirstSame() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot get first same iterator from the invalid binary tree iterator."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  it.m_pNode = m_pNode;
  it.m_pItem = it.m_pNode->m_pFirstItem;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getLastSame() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot get last same iterator from the invalid binary tree iterator."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  it.m_pNode = m_pNode;
  it.m_pItem = it.m_pNode->m_pLastItem;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getPrevSame() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  it.m_pNode = m_pNode;
  it.m_pItem = m_pItem->m_pPrev;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getNextSame() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  it.m_pNode = m_pNode;
  it.m_pItem = m_pItem->m_pNext;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getIndexSame(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  // Find first same item.
  typename TContainer::SBinTreeItem* temp = m_pItem;
  while (temp->m_pPrev != NULL)
    temp = temp->m_pPrev;
  // Indexing into same items.
  Tuint count = a_cIndex;
  while ((count != 0) && (temp->m_pNext != NULL))
  {
    --count;
    temp = temp->m_pNext;
  }
  it.m_pNode = m_pNode;
  it.m_pItem = (count == 0) ? temp : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getLeftChildCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no left child."))
  {
    return 0;
  }

  Tuint index = 0;
  typename TContainer::SBinTreeItem* temp = ((m_pNode->m_pLeft != NULL) ? m_pNode->m_pLeft->m_pFirstItem : NULL);
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pNext;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getLeftChildFirst() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no left child."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  if (m_pNode->m_pLeft != NULL)
  {
    it.m_pNode = m_pNode->m_pLeft;
    it.m_pItem = it.m_pNode->m_pFirstItem;
  }
  else
  {
    it.m_pNode = NULL;
    it.m_pItem = NULL;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getLeftChildLast() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no left child."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  if (m_pNode->m_pLeft != NULL)
  {
    it.m_pNode = m_pNode->m_pLeft;
    it.m_pItem = it.m_pNode->m_pLastItem;
  }
  else
  {
    it.m_pNode = NULL;
    it.m_pItem = NULL;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getIndexLeftChild(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no left child."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  Tuint count = a_cIndex;
  typename TContainer::SBinTreeItem* item = NULL;
  typename TContainer::SBinTreeNode* node = m_pNode->m_pLeft;
  if (node != NULL)
  {
    item = node->m_pFirstItem;
    // Indexing into child items.
    while ((count != 0) && (item->m_pNext != NULL))
    {
      --count;
      item = item->m_pNext;
    }
  }
  it.m_pNode = node;
  it.m_pItem = (count == 0) ? item : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getRightChildCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no right child."))
  {
    return 0;
  }

  Tuint index = 0;
  typename TContainer::SBinTreeItem* temp = ((m_pNode->m_pRight != NULL) ? m_pNode->m_pRight->m_pLastItem : NULL);
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrev;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getRightChildFirst() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no right child."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  if (m_pNode->m_pRight != NULL)
  {
    it.m_pNode = m_pNode->m_pRight;
    it.m_pItem = it.m_pNode->m_pFirstItem;
  }
  else
  {
    it.m_pNode = NULL;
    it.m_pItem = NULL;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getRightChildLast() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no right child."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  if (m_pNode->m_pRight != NULL)
  {
    it.m_pNode = m_pNode->m_pRight;
    it.m_pItem = it.m_pNode->m_pLastItem;
  }
  else
  {
    it.m_pNode = NULL;
    it.m_pItem = NULL;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::getIndexRightChild(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no right child."))
  {
    return CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>(m_pContainer);
  }

  CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it(m_pContainer);

  Tuint count = a_cIndex;
  typename TContainer::SBinTreeItem* item = NULL;
  typename TContainer::SBinTreeNode* node = m_pNode->m_pRight;
  if (node != NULL)
  {
    item = node->m_pFirstItem;
    // Indexing into child items.
    while ((count != 0) && (item->m_pNext != NULL))
    {
      --count;
      item = item->m_pNext;
    }
  }
  it.m_pNode = node;
  it.m_pItem = (count == 0) ? item : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::insert(const T_Type& a_crItem, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid binary tree container."))
  {
    return false;
  }

  Tbool left = false;
  typename TContainer::SBinTreeNode* parent = m_pContainer->m_pRoot;
  // Find parent node to insert a new one.
  while (parent != NULL)
  {
    if (m_pContainer->isLessThan(a_crItem, parent->m_pFirstItem->m_Item))
      left = true;
    else if (m_pContainer->isLessThan(parent->m_pFirstItem->m_Item, a_crItem))
      left = false;
    else
    {
      // Create a new binary tree item.
      typename TContainer::SBinTreeItem* item = m_pContainer->m_Allocator.template createOne<typename TContainer::SBinTreeItem>(a_crItem);
      if (item == NULL)
      {
        WARNING(STR("Cannot create a new binary tree item for the inserting into the binary tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SBinTreeItem)));
        return false;
      }
      // Link item with current binary tree node.
      item->m_pParent = parent;
      item->m_pPrev = parent->m_pLastItem;
      parent->m_pLastItem->m_pNext = item;
      parent->m_pLastItem = item;
      // Update iterator.
      if (a_cUpdate)
      {
        m_pNode = parent;
        m_pItem = item;
      }
      // Update container.
      ++m_pContainer->m_Size;
      return true;
    }
    if (left)
    {
      if (parent->m_pLeft != NULL)
        parent = parent->m_pLeft;
      else
        break;
    }
    else
    {
      if (parent->m_pRight != NULL)
        parent = parent->m_pRight;
      else
        break;
    }
  }
  // Create a new binary tree item.
  typename TContainer::SBinTreeItem* item = m_pContainer->m_Allocator.template createOne<typename TContainer::SBinTreeItem>(a_crItem);
  if (item == NULL)
  {
    WARNING(STR("Cannot create a new binary tree item for the inserting into the binary tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SBinTreeItem)));
    return false;
  }
  // Create a new binary tree node.
  typename TContainer::SBinTreeNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::SBinTreeNode>(item);
  if (node == NULL)
  {
    WARNING(STR("Cannot create a new binary tree node for the inserting into the binary tree (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SBinTreeNode)));
    // Delete binary tree item.
    if (!m_pContainer->m_Allocator.deleteOne(item))
      WARNING(STR("Cannot remove a new binary tree item while aborting of the inserting process (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SBinTreeItem)));
    return false;
  }
  // Link binary tree item with node.
  item->m_pParent = node;
  // Insert a new binary tree node into container.
  node->m_pParent = parent;
  if (parent == NULL)
    m_pContainer->m_pRoot = node;
  else
  {
    if (left)
      parent->m_pLeft = node;
    else
      parent->m_pRight = node;
  }
  // Try to balance binary tree.
  if (m_pContainer->insertAndBalance(node))
  {
    // Update iterator.
    if (a_cUpdate)
    {
      m_pNode = node;
      m_pItem = item;
    }
    // Update container.
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    // Unlink node from binary tree.
    if (parent == NULL)
      m_pContainer->m_pRoot = NULL;
    else
    {
      if (left)
        parent->m_pLeft = NULL;
      else
        parent->m_pRight = NULL;
    }
    // Delete binary tree node.
    if (!m_pContainer->m_Allocator.deleteOne(node))
      WARNING(STR("Cannot remove a new binary tree node while aborting of the inserting process (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SBinTreeNode)));
    // Delete binary tree item.
    if (!m_pContainer->m_Allocator.deleteOne(item))
      WARNING(STR("Cannot remove a new binary tree item while aborting of the inserting process (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SBinTreeItem)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::remove()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid binary tree iterator."))
  {
    return false;
  }

  // Remove one item from binary tree node.
  if ((m_pItem->m_pPrev != NULL) || (m_pItem->m_pNext != NULL))
  {
    typename TContainer::SBinTreeItem* prev_item = m_pItem->m_pPrev;
    typename TContainer::SBinTreeItem* next_item = m_pItem->m_pNext;
    if (m_pContainer->m_Allocator.deleteOne(m_pItem))
    {
      // Update current binary tree node.
      if (prev_item == NULL)
        m_pNode->m_pFirstItem = next_item;
      else
        prev_item->m_pNext = next_item;
      if (next_item == NULL)
        m_pNode->m_pLastItem = prev_item;
      else
        next_item->m_pPrev = prev_item;
      // Update iterator.
      m_pItem = (prev_item != NULL) ? prev_item : next_item;
      // Update container.
      --m_pContainer->m_Size;
      return true;
    }
    else
    {
      WARNING(STR("Cannot remove item from the current binary tree node (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SBinTreeItem)));
      return false;
    }
  }
  // Remove current node from binary tree.
  else
  {
    // Get next iterator position.
    CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it_next(*this);
    if (it_next.stepBackward() != 1)
      if (it_next.stepForward() != 1)
      {
        it_next.m_pNode = NULL;
        it_next.m_pItem = NULL;
      }
    // Try to rebalance binary tree before removing current node.
    if (m_pContainer->removeAndBalance(m_pNode))
    {
      // Update container.
      --m_pContainer->m_Size;
      // Remove current binary tree item.
      if (!m_pContainer->m_Allocator.deleteOne(m_pItem))
      {
        WARNING(STR("Cannot remove item from the current binary tree node (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SBinTreeItem)));
        return false;
      }
      // Remove current binary tree node.
      if (!m_pContainer->m_Allocator.deleteOne(m_pNode))
      {
        WARNING(STR("Cannot remove current binary tree node (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SBinTreeNode)));
        return false;
      }
      // Update iterator.
      m_pNode = it_next.m_pNode;
      m_pItem = it_next.m_pItem;
      return true;
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::remove(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid binary tree iterator."))
  {
    return false;
  }

  a_rItem = m_pItem->m_Item;
  // Remove one item from binary tree node.
  if ((m_pItem->m_pPrev != NULL) || (m_pItem->m_pNext != NULL))
  {
    typename TContainer::SBinTreeItem* prev_item = m_pItem->m_pPrev;
    typename TContainer::SBinTreeItem* next_item = m_pItem->m_pNext;
    if (m_pContainer->m_Allocator.deleteOne(m_pItem))
    {
      // Update current binary tree node.
      if (prev_item == NULL)
        m_pNode->m_pFirstItem = next_item;
      else
        prev_item->m_pNext = next_item;
      if (next_item == NULL)
        m_pNode->m_pLastItem = prev_item;
      else
        next_item->m_pPrev = prev_item;
      // Update iterator.
      m_pItem = (prev_item != NULL) ? prev_item : next_item;
      // Update container.
      --m_pContainer->m_Size;
      return true;
    }
    else
    {
      WARNING(STR("Cannot remove item from the current binary tree node (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SBinTreeItem)));
      return false;
    }
  }
  // Remove current node from binary tree.
  else
  {
    // Get next iterator position.
    CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> it_next(*this);
    if (it_next.stepBackward() != 1)
      if (it_next.stepForward() != 1)
      {
        it_next.m_pNode = NULL;
        it_next.m_pItem = NULL;
      }
    // Try to rebalance binary tree before removing current node.
    if (m_pContainer->removeAndBalance(m_pNode))
    {
      // Update container.
      --m_pContainer->m_Size;
      // Remove current binary tree item.
      if (!m_pContainer->m_Allocator.deleteOne(m_pItem))
      {
        WARNING(STR("Cannot remove item from the current binary tree node (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SBinTreeItem)));
        return false;
      }
      // Remove current binary tree node.
      if (!m_pContainer->m_Allocator.deleteOne(m_pNode))
      {
        WARNING(STR("Cannot remove current binary tree node (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SBinTreeNode)));
        return false;
      }
      // Update iterator.
      m_pNode = it_next.m_pNode;
      m_pItem = it_next.m_pItem;
      return true;
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
template <class T_Archive>
inline Tbool CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  T_Type value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
    CHECK(insert(value, true));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
template <class T_Archive>
inline Tbool CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
template <class T_Archive>
inline Tbool CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>::swap(CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pContainer, a_rInstance.m_pContainer);
  NAlgorithms::NCommon::swap(m_pNode, a_rInstance.m_pNode);
  NAlgorithms::NCommon::swap(m_pItem, a_rInstance.m_pItem);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
