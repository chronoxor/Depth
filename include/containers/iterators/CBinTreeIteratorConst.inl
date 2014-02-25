/*!
 *  \file    CBinTreeIteratorConst.inl Binary tree constant iterator
 *           definitions. It gives ability to get binary tree items.
 *  \brief   Binary tree constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Binary tree constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   31.07.2006 23:48:27

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
#ifndef __CBINTREEITERATORCONST_INL__
#define __CBINTREEITERATORCONST_INL__
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
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeIteratorConst() :
  NCommon::NIterators::IIteratorConst<CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, const CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, const CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, const CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  m_cpContainer(NULL),
  m_cpNode(NULL),
  m_cpItem(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeIteratorConst(const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>* a_cpContainer) :
  NCommon::NIterators::IIteratorConst<CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, const CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, const CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, const CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  m_cpContainer(a_cpContainer),
  m_cpNode(NULL),
  m_cpItem(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeIteratorConst(const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, const CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, const CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, const CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  m_cpContainer(NULL),
  m_cpNode(NULL),
  m_cpItem(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeIteratorConst(const CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, const CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, const CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, const T_Type, const CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >(),
  m_cpContainer(NULL),
  m_cpNode(NULL),
  m_cpItem(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::~CBinTreeIteratorConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool operator == (const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance1, const CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_pNode == a_crInstance2.m_cpNode) && (a_crInstance1.m_pItem == a_crInstance2.m_cpItem));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool operator == (const CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance1, const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_cpNode == a_crInstance2.m_pNode) && (a_crInstance1.m_cpItem == a_crInstance2.m_pItem));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool operator == (const CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance1, const CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_cpNode == a_crInstance2.m_cpNode) && (a_crInstance1.m_cpItem == a_crInstance2.m_cpItem));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool operator != (const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance1, const CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_pNode != a_crInstance2.m_cpNode) || (a_crInstance1.m_pItem != a_crInstance2.m_cpItem));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool operator != (const CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance1, const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_cpNode != a_crInstance2.m_pNode) || (a_crInstance1.m_cpItem != a_crInstance2.m_pItem));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool operator != (const CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance1, const CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_cpNode != a_crInstance2.m_cpNode) || (a_crInstance1.m_cpItem != a_crInstance2.m_cpItem));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::operator = (const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::operator = (const CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::operator ++ (int)
{ CALL
  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::operator -- (int)
{ CALL
  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> operator + (const CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> operator - (const CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::operator [] (const T_Type& a_crItem) const
{ CALL
  return find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::set(const CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_pContainer;
  m_cpNode = a_crInstance.m_pNode;
  m_cpItem = a_crInstance.m_pItem;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::set(const CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_cpContainer;
  m_cpNode = a_crInstance.m_cpNode;
  m_cpItem = a_crInstance.m_cpItem;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getForward() const
{ CALL
  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getBackward() const
{ CALL
  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && (m_cpNode != NULL) && (m_cpItem != NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::isValidContainer() const
{ CALL
  return (m_cpContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>* CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getContainerPtr() const
{ CALL
  return m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline const T_Type& CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_cpItem->m_Item;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline const T_Type* CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_cpItem->m_Item;
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::find(const T_Type& a_crItem) const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Cannot find given item in the binary tree with the invalid iterator container."));

  return m_cpContainer->find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
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
    if (m_cpItem->m_pNext != NULL)
    {
      m_cpItem = m_cpItem->m_pNext;
      found = true;
    }
    else if (m_cpNode->m_pRight != NULL)
    {
      m_cpNode = m_cpNode->m_pRight;
      while (m_cpNode->m_pLeft != NULL)
        m_cpNode = m_cpNode->m_pLeft;
      m_cpItem = m_cpNode->m_pFirstItem;
      found = true;
    }
    else
    {
      const typename TContainer::SBinTreeNode* prev = m_cpNode;
      const typename TContainer::SBinTreeNode* next = m_cpNode->m_pParent;
      while (next != NULL)
      {
        if (next->m_pLeft == prev)
        {
          m_cpNode = next;
          m_cpItem = m_cpNode->m_pFirstItem;
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
inline Tuint CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
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
    if (m_cpItem->m_pPrev != NULL)
    {
      m_cpItem = m_cpItem->m_pPrev;
      found = true;
    }
    else if (m_cpNode->m_pLeft != NULL)
    {
      m_cpNode = m_cpNode->m_pLeft;
      while (m_cpNode->m_pRight != NULL)
        m_cpNode = m_cpNode->m_pRight;
      m_cpItem = m_cpNode->m_pLastItem;
      found = true;
    }
    else
    {
      const typename TContainer::SBinTreeNode* prev = m_cpNode;
      const typename TContainer::SBinTreeNode* next = m_cpNode->m_pParent;
      while (next != NULL)
      {
        if (next->m_pRight == prev)
        {
          m_cpNode = next;
          m_cpItem = m_cpNode->m_pLastItem;
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
inline Tbool CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::isRoot() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator cannot be the root."))
  {
    return false;
  }

  return (m_cpNode->m_pParent == NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getRoot() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no root node."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  it.m_cpNode = m_cpNode;
  while (it.m_cpNode->m_pParent != NULL)
    it.m_cpNode = it.m_cpNode->m_pParent;
  it.m_cpItem = ((it.m_cpNode != NULL) ? it.m_cpNode->m_pFirstItem : NULL);
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getParent() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no parent node."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  it.m_cpNode = m_cpNode->m_pParent;
  it.m_cpItem = ((it.m_cpNode != NULL) ? it.m_cpNode->m_pFirstItem : NULL);
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getSiblingIndex() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 0;
  const typename TContainer::SBinTreeNode* temp_node = m_cpNode;
  const typename TContainer::SBinTreeItem* temp_item = m_cpItem->m_pPrev;
  // Travel backward through current node items.
  while (temp_item != NULL)
  {
    ++index;
    temp_item = temp_item->m_pPrev;
  }
  // Try to travel through left node items.
  if ((m_cpNode->m_pParent != NULL) && (m_cpNode->m_pParent->m_pLeft != NULL) && (m_cpNode->m_pParent->m_pLeft != m_cpNode))
  {
    temp_node = m_cpNode->m_pParent->m_pLeft;
    temp_item = m_cpNode->m_pParent->m_pLeft->m_pLastItem;
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
inline Tuint CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getSiblingsCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 1;
  const typename TContainer::SBinTreeNode* temp_node = m_cpNode;
  const typename TContainer::SBinTreeItem* temp_item = m_cpItem->m_pPrev;
  // Travel backward through current node items.
  while (temp_item != NULL)
  {
    ++index;
    temp_item = temp_item->m_pPrev;
  }
  // Try to travel through left node items.
  if ((m_cpNode->m_pParent != NULL) && (m_cpNode->m_pParent->m_pLeft != NULL) && (m_cpNode->m_pParent->m_pLeft != m_cpNode))
  {
    temp_node = m_cpNode->m_pParent->m_pLeft;
    temp_item = m_cpNode->m_pParent->m_pLeft->m_pLastItem;
    while (temp_item != NULL)
    {
      ++index;
      temp_item = temp_item->m_pPrev;
    }
  }
  // Travel forward through current node items.
  temp_node = m_cpNode;
  temp_item = m_cpItem->m_pNext;
  while (temp_item != NULL)
  {
    ++index;
    temp_item = temp_item->m_pNext;
  }
  // Try to travel through right node items.
  if ((m_cpNode->m_pParent != NULL) && (m_cpNode->m_pParent->m_pRight != NULL) && (m_cpNode->m_pParent->m_pRight != m_cpNode))
  {
    temp_node = m_cpNode->m_pParent->m_pRight;
    temp_item = m_cpNode->m_pParent->m_pRight->m_pFirstItem;
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
inline Tuint CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getPrevSiblingsCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 0;
  const typename TContainer::SBinTreeNode* temp_node = m_cpNode;
  const typename TContainer::SBinTreeItem* temp_item = m_cpItem->m_pPrev;
  // Travel backward through current node items.
  while (temp_item != NULL)
  {
    ++index;
    temp_item = temp_item->m_pPrev;
  }
  // Try to travel through left node items.
  if ((m_cpNode->m_pParent != NULL) && (m_cpNode->m_pParent->m_pLeft != NULL) && (m_cpNode->m_pParent->m_pLeft != m_cpNode))
  {
    temp_node = m_cpNode->m_pParent->m_pLeft;
    temp_item = m_cpNode->m_pParent->m_pLeft->m_pLastItem;
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
inline Tuint CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getNextSiblingsCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 0;
  const typename TContainer::SBinTreeNode* temp_node = m_cpNode;
  const typename TContainer::SBinTreeItem* temp_item = m_cpItem->m_pNext;
  // Travel forward through current node items.
  while (temp_item != NULL)
  {
    ++index;
    temp_item = temp_item->m_pNext;
  }
  // Try to travel through right node items.
  if ((m_cpNode->m_pParent != NULL) && (m_cpNode->m_pParent->m_pRight != NULL) && (m_cpNode->m_pParent->m_pRight != m_cpNode))
  {
    temp_node = m_cpNode->m_pParent->m_pRight;
    temp_item = m_cpNode->m_pParent->m_pRight->m_pFirstItem;
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
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getFirstSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  if ((m_cpNode->m_pParent != NULL) && (m_cpNode->m_pParent->m_pLeft != NULL) && (m_cpNode->m_pParent->m_pLeft != m_cpNode))
  {
    it.m_cpNode = m_cpNode->m_pParent->m_pLeft;
    it.m_cpItem = m_cpNode->m_pParent->m_pLeft->m_pFirstItem;
  }
  else
  {
    it.m_cpNode = m_cpNode;
    it.m_cpItem = m_cpNode->m_pFirstItem;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getLastSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  if ((m_cpNode->m_pParent != NULL) && (m_cpNode->m_pParent->m_pRight != NULL) && (m_cpNode->m_pParent->m_pRight != m_cpNode))
  {
    it.m_cpNode = m_cpNode->m_pParent->m_pRight;
    it.m_cpItem = m_cpNode->m_pParent->m_pRight->m_pLastItem;
  }
  else
  {
    it.m_cpNode = m_cpNode;
    it.m_cpItem = m_cpNode->m_pLastItem;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getPrevSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  if (m_cpItem->m_pPrev != NULL)
  {
    it.m_cpNode = m_cpNode;
    it.m_cpItem = m_cpItem->m_pPrev;
  }
  else
  {
    if ((m_cpNode->m_pParent != NULL) && (m_cpNode->m_pParent->m_pLeft != NULL) && (m_cpNode->m_pParent->m_pLeft != m_cpNode))
    {
      it.m_cpNode = m_cpNode->m_pParent->m_pLeft;
      it.m_cpItem = m_cpNode->m_pParent->m_pLeft->m_pLastItem;
    }
    else
    {
      it.m_cpNode = NULL;
      it.m_cpItem = NULL;
    }
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getNextSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  if (m_cpItem->m_pNext != NULL)
  {
    it.m_cpNode = m_cpNode;
    it.m_cpItem = m_cpItem->m_pNext;
  }
  else
  {
    if ((m_cpNode->m_pParent != NULL) && (m_cpNode->m_pParent->m_pRight != NULL) && (m_cpNode->m_pParent->m_pRight != m_cpNode))
    {
      it.m_cpNode = m_cpNode->m_pParent->m_pRight;
      it.m_cpItem = m_cpNode->m_pParent->m_pRight->m_pFirstItem;
    }
    else
    {
      it.m_cpNode = NULL;
      it.m_cpItem = NULL;
    }
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getIndexSibling(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no siblings."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  // Find first sibling.
  const typename TContainer::SBinTreeNode* temp_node = m_cpNode;
  const typename TContainer::SBinTreeItem* temp_item = m_cpNode->m_pFirstItem;
  if ((m_cpNode->m_pParent != NULL) && (m_cpNode->m_pParent->m_pLeft != NULL) && (m_cpNode->m_pParent->m_pLeft != m_cpNode))
  {
    temp_node = m_cpNode->m_pParent->m_pLeft;
    temp_item = m_cpNode->m_pParent->m_pLeft->m_pFirstItem;
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
  it.m_cpNode = (count == 0) ? temp_node : NULL;
  it.m_cpItem = (count == 0) ? temp_item : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getChildCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no child."))
  {
    return 0;
  }

  Tuint index = 0;
  const typename TContainer::SBinTreeNode* temp_node = (m_cpNode->m_pLeft != NULL) ? m_cpNode->m_pLeft : m_cpNode->m_pRight;
  const typename TContainer::SBinTreeItem* temp_item = (temp_node != NULL) ? temp_node->m_pFirstItem : NULL;
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
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getFirstChild() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no child."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  if ((m_cpNode->m_pLeft != NULL) || (m_cpNode->m_pRight != NULL))
  {
    it.m_cpNode = (m_cpNode->m_pLeft != NULL) ? m_cpNode->m_pLeft : m_cpNode->m_pRight;
    it.m_cpItem = it.m_cpNode->m_pFirstItem;
  }
  else
  {
    it.m_cpNode = NULL;
    it.m_cpItem = NULL;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getLastChild() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no child."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  if ((m_cpNode->m_pLeft != NULL) || (m_cpNode->m_pRight != NULL))
  {
    it.m_cpNode = (m_cpNode->m_pRight != NULL) ? m_cpNode->m_pRight : m_cpNode->m_pLeft;
    it.m_cpItem = it.m_cpNode->m_pLastItem;
  }
  else
  {
    it.m_cpNode = NULL;
    it.m_cpItem = NULL;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getIndexChild(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no child."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  Tuint count = a_cIndex;
  const typename TContainer::SBinTreeNode* temp_node = (m_cpNode->m_pLeft != NULL) ? m_cpNode->m_pLeft : m_cpNode->m_pRight;
  const typename TContainer::SBinTreeItem* temp_item = (temp_node != NULL) ? temp_node->m_pFirstItem : NULL;
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
  it.m_cpNode = (count == 0) ? temp_node : NULL;
  it.m_cpItem = (count == 0) ? temp_item : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getSameIndex() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return 0;
  }

  Tuint index = 0;
  const typename TContainer::SBinTreeItem* temp = m_cpItem->m_pPrev;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrev;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getSameCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return 0;
  }

  Tuint index = 1;
  const typename TContainer::SBinTreeItem* temp = m_cpItem->m_pPrev;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrev;
  }

  temp = m_cpItem->m_pNext;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pNext;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getPrevSameCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return 0;
  }

  Tuint index = 0;
  const typename TContainer::SBinTreeItem* temp = m_cpItem->m_pPrev;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrev;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getNextSameCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return 0;
  }

  Tuint index = 0;
  const typename TContainer::SBinTreeItem* temp = m_cpItem->m_pNext;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pNext;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getFirstSame() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot get first same iterator from the invalid binary tree iterator."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  it.m_cpNode = m_cpNode;
  it.m_cpItem = it.m_cpNode->m_pFirstItem;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getLastSame() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot get last same iterator from the invalid binary tree iterator."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  it.m_cpNode = m_cpNode;
  it.m_cpItem = it.m_cpNode->m_pLastItem;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getPrevSame() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  it.m_cpNode = m_cpNode;
  it.m_cpItem = m_cpItem->m_pPrev;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getNextSame() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  it.m_cpNode = m_cpNode;
  it.m_cpItem = m_cpItem->m_pNext;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getIndexSame(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no same nodes."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  // Find first same item.
  const typename TContainer::SBinTreeItem* temp = m_cpItem;
  while (temp->m_pPrev != NULL)
    temp = temp->m_pPrev;
  // Indexing into same items.
  Tuint count = a_cIndex;
  while ((count != 0) && (temp->m_pNext != NULL))
  {
    --count;
    temp = temp->m_pNext;
  }
  it.m_cpNode = m_cpNode;
  it.m_cpItem = (count == 0) ? temp : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getLeftChildCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no left child."))
  {
    return 0;
  }

  Tuint index = 0;
  const typename TContainer::SBinTreeItem* temp = ((m_cpNode->m_pLeft != NULL) ? m_cpNode->m_pLeft->m_pFirstItem : NULL);
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pNext;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getLeftChildFirst() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no left child."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  if (m_cpNode->m_pLeft != NULL)
  {
    it.m_cpNode = m_cpNode->m_pLeft;
    it.m_cpItem = it.m_cpNode->m_pFirstItem;
  }
  else
  {
    it.m_cpNode = NULL;
    it.m_cpItem = NULL;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getLeftChildLast() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no left child."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  if (m_cpNode->m_pLeft != NULL)
  {
    it.m_cpNode = m_cpNode->m_pLeft;
    it.m_cpItem = it.m_cpNode->m_pLastItem;
  }
  else
  {
    it.m_cpNode = NULL;
    it.m_cpItem = NULL;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getIndexLeftChild(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no left child."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  Tuint count = a_cIndex;
  const typename TContainer::SBinTreeItem* item = NULL;
  const typename TContainer::SBinTreeNode* node = m_cpNode->m_pLeft;
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
  it.m_cpNode = node;
  it.m_cpItem = (count == 0) ? item : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getRightChildCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no right child."))
  {
    return 0;
  }

  Tuint index = 0;
  const typename TContainer::SBinTreeItem* temp = ((m_cpNode->m_pRight != NULL) ? m_cpNode->m_pRight->m_pLastItem : NULL);
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrev;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getRightChildFirst() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no right child."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  if (m_cpNode->m_pRight != NULL)
  {
    it.m_cpNode = m_cpNode->m_pRight;
    it.m_cpItem = it.m_cpNode->m_pFirstItem;
  }
  else
  {
    it.m_cpNode = NULL;
    it.m_cpItem = NULL;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getRightChildLast() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no right child."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  if (m_cpNode->m_pRight != NULL)
  {
    it.m_cpNode = m_cpNode->m_pRight;
    it.m_cpItem = it.m_cpNode->m_pLastItem;
  }
  else
  {
    it.m_cpNode = NULL;
    it.m_cpItem = NULL;
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::getIndexRightChild(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid binary tree iterator has no right child."))
  {
    return CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>(m_cpContainer);
  }

  CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> it(m_cpContainer);

  Tuint count = a_cIndex;
  const typename TContainer::SBinTreeItem* item = NULL;
  const typename TContainer::SBinTreeNode* node = m_cpNode->m_pRight;
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
  it.m_cpNode = node;
  it.m_cpItem = (count == 0) ? item : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
template <class T_Archive>
inline Tbool CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Constant iterator value cannot be loaded."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
template <class T_Archive>
inline Tbool CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::save(T_Archive& a_rArchive) const
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
inline Tbool CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>::swap(CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_cpContainer, a_rInstance.m_cpContainer);
  NAlgorithms::NCommon::swap(m_cpNode, a_rInstance.m_cpNode);
  NAlgorithms::NCommon::swap(m_cpItem, a_rInstance.m_cpItem);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
