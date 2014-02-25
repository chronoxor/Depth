/*!
 *  \file    CQueueIterator.inl Queue non constant iterator definitions. It
 *           gives ability to get and modify queue items and to do forward
 *           moving through the queue nodes.
 *  \brief   Queue non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Queue non constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   14.02.2006 21:19:26

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
#ifndef __CQUEUEITERATOR_INL__
#define __CQUEUEITERATOR_INL__
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
inline CQueueIterator<T_Type, T_Allocator>::CQueueIterator() :
  NCommon::NIterators::IIterator<CQueueIterator<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveForward<CQueueIterator<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertForward<CQueueIterator<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveForward<CQueueIterator<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  m_pContainer(NULL),
  m_pNode(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIterator<T_Type, T_Allocator>::CQueueIterator(CQueue<T_Type, T_Allocator>* a_pContainer) :
  NCommon::NIterators::IIterator<CQueueIterator<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveForward<CQueueIterator<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertForward<CQueueIterator<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveForward<CQueueIterator<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  m_pContainer(a_pContainer),
  m_pNode(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIterator<T_Type, T_Allocator>::CQueueIterator(const CQueueIterator<T_Type, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIterator<CQueueIterator<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveForward<CQueueIterator<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertForward<CQueueIterator<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveForward<CQueueIterator<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  m_pContainer(NULL),
  m_pNode(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIterator<T_Type, T_Allocator>::~CQueueIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator == (const CQueueIterator<T_Type, T_Allocator>& a_crInstance1, const CQueueIterator<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_pNode == a_crInstance2.m_pNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator != (const CQueueIterator<T_Type, T_Allocator>& a_crInstance1, const CQueueIterator<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_pNode != a_crInstance2.m_pNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIterator<T_Type, T_Allocator>& CQueueIterator<T_Type, T_Allocator>::operator = (const CQueueIterator<T_Type, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIterator<T_Type, T_Allocator>& CQueueIterator<T_Type, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIterator<T_Type, T_Allocator>& CQueueIterator<T_Type, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIterator<T_Type, T_Allocator> CQueueIterator<T_Type, T_Allocator>::operator ++ (int)
{ CALL
  CQueueIterator<T_Type, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIterator<T_Type, T_Allocator> operator + (const CQueueIterator<T_Type, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CQueueIterator<T_Type, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CQueueIterator<T_Type, T_Allocator>::set(const CQueueIterator<T_Type, T_Allocator>& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_pNode = a_crInstance.m_pNode;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIterator<T_Type, T_Allocator> CQueueIterator<T_Type, T_Allocator>::getForward() const
{ CALL
  CQueueIterator<T_Type, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CQueueIterator<T_Type, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueueIterator<T_Type, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && (m_pNode != NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueueIterator<T_Type, T_Allocator>::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueue<T_Type, T_Allocator>& CQueueIterator<T_Type, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueue<T_Type, T_Allocator>* CQueueIterator<T_Type, T_Allocator>::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline T_Type& CQueueIterator<T_Type, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_pNode->m_Item;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline T_Type* CQueueIterator<T_Type, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_pNode->m_Item;
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CQueueIterator<T_Type, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid queue iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while ((m_pNode->m_pNext != NULL) && (counter > 0))
  {
    m_pNode = m_pNode->m_pNext;
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueueIterator<T_Type, T_Allocator>::insertBackward(const T_Type& a_crItem)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid queue container."))
  {
    return false;
  }
  // Check if the current iterator position is begin or end one.
  ASSERT(((m_pNode == m_pContainer->m_pFirst) || (m_pNode == m_pContainer->m_pLast)), STR("Inserting to the current queue position can be made only for the queue begin or end position."))
  {
    return false;
  }

  typename TContainer::SQueueNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::SQueueNode>(a_crItem);

  if (node != NULL)
  {
    if (m_pNode == m_pContainer->m_pFirst)
    {
      node->m_pNext = m_pNode;
      m_pNode = node;
      m_pContainer->m_pFirst = m_pNode;
      if (m_pContainer->m_pLast == NULL)
        m_pContainer->m_pLast = m_pNode;
    }
    else
    {
      node->m_pNext = NULL;
      m_pNode = node;
      m_pContainer->m_pLast = m_pNode;
      if (m_pContainer->m_pFirst == NULL)
        m_pContainer->m_pFirst = m_pNode;
    }
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new queue node for the backward iterator inserting into the queue (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SQueueNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueueIterator<T_Type, T_Allocator>::insertNext(const T_Type& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new item to the next forward queue position of the invalid iterator."))
  {
    return false;
  }

  typename TContainer::SQueueNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::SQueueNode>(a_crItem);

  if (node != NULL)
  {
    node->m_pNext = m_pNode->m_pNext;
    m_pNode->m_pNext = node;
    if (m_pContainer->m_pLast == m_pNode)
      m_pContainer->m_pLast = node;
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new queue node for the next forward iterator inserting into the queue (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SQueueNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueueIterator<T_Type, T_Allocator>::removeForward()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid queue iterator."))
  {
    return false;
  }
  // Check if the current iterator position is the first one.
  ASSERT((m_pNode == m_pContainer->m_pFirst), STR("Removing from the current queue position can be made only for the queue begin position."))
  {
    return false;
  }

  typename TContainer::SQueueNode* node_cur = m_pNode;
  typename TContainer::SQueueNode* node_next = m_pNode->m_pNext;

  if (m_pContainer->m_Allocator.deleteOne(node_cur))
  {
    m_pNode = node_next;
    m_pContainer->m_pFirst = m_pNode;
    if (m_pContainer->m_pFirst == NULL)
      m_pContainer->m_pLast = NULL;
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove queue node from the current position of the queue iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SQueueNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueueIterator<T_Type, T_Allocator>::removeForward(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid queue iterator."))
  {
    return false;
  }
  // Check if the current iterator position is the first one.
  ASSERT((m_pNode == m_pContainer->m_pFirst), STR("Removing from the current queue position can be made only for the queue begin position."))
  {
    return false;
  }

  typename TContainer::SQueueNode* node_cur = m_pNode;
  typename TContainer::SQueueNode* node_next = m_pNode->m_pNext;

  a_rItem = node_cur->m_Item;
  if (m_pContainer->m_Allocator.deleteOne(node_cur))
  {
    m_pNode = node_next;
    m_pContainer->m_pFirst = m_pNode;
    if (m_pContainer->m_pFirst == NULL)
      m_pContainer->m_pLast = NULL;
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove queue node from the current position of the queue iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SQueueNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueueIterator<T_Type, T_Allocator>::removeNext()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove next item from the invalid queue iterator."))
  {
    return false;
  }
  // Check if the current iterator position is not the last one.
  ASSERT((m_pNode != m_pContainer->m_pLast), STR("Removing from the next forward queue position without a corresponding item (from the end queue position)."))
  {
    return false;
  }

  typename TContainer::SQueueNode* node_cur = m_pNode->m_pNext;
  typename TContainer::SQueueNode* node_next = m_pNode->m_pNext->m_pNext;

  if (m_pContainer->m_Allocator.deleteOne(node_cur))
  {
    m_pNode->m_pNext = node_next;
    if (node_next == NULL)
      m_pContainer->m_pLast = m_pNode;
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove queue node from the next forward position of the queue iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SQueueNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueueIterator<T_Type, T_Allocator>::removeNext(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove next item from the invalid queue iterator."))
  {
    return false;
  }
  // Check if the current iterator position is not the last one.
  ASSERT((m_pNode != m_pContainer->m_pLast), STR("Removing from the next forward queue position without a corresponding item (from the end queue position)."))
  {
    return false;
  }

  typename TContainer::SQueueNode* node_cur = m_pNode->m_pNext;
  typename TContainer::SQueueNode* node_next = m_pNode->m_pNext->m_pNext;

  a_rItem = node_cur->m_Item;
  if (m_pContainer->m_Allocator.deleteOne(node_cur))
  {
    m_pNode->m_pNext = node_next;
    if (node_next == NULL)
      m_pContainer->m_pLast = m_pNode;
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove queue node from the next forward position of the queue iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SQueueNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CQueueIterator<T_Type, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CQueueIterator<T_Type, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CQueueIterator<T_Type, T_Allocator>::swap(CQueueIterator<T_Type, T_Allocator>& a_rInstance)
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
