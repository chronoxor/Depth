/*!
 *  \file    CQueue.inl Template queue container class. Queue represents
 *           container that can implement FIFO (first in - first out)
 *           algorithm.
 *  \brief   Template queue container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template queue container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   13.02.2006 00:06:37

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
#ifndef __CQUEUE_INL__
#define __CQUEUE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type, class T_Allocator>
inline CQueue<T_Type, T_Allocator>::SQueueNode::SQueueNode(const T_Type& a_crItem) :
  m_Item(a_crItem),
  m_pNext(NULL)
{ CALL

}
/*==========================================================================*/
template <typename T_Type, class T_Allocator>
inline CQueue<T_Type, T_Allocator>::CQueue(const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IQueue<CQueue<T_Type, T_Allocator>, T_Type, CQueueIterator<T_Type, T_Allocator>, CQueueIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::IQueueConst<CQueue<T_Type, T_Allocator>, T_Type, CQueueIterator<T_Type, T_Allocator>, CQueueIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pFirst(NULL),
  m_pLast(NULL),
  m_Allocator(a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueue<T_Type, T_Allocator>::CQueue(const T_Type& a_crItem, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IQueue<CQueue<T_Type, T_Allocator>, T_Type, CQueueIterator<T_Type, T_Allocator>, CQueueIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::IQueueConst<CQueue<T_Type, T_Allocator>, T_Type, CQueueIterator<T_Type, T_Allocator>, CQueueIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pFirst(NULL),
  m_pLast(NULL),
  m_Allocator(a_crAllocator)
{ CALL
  insertLast(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueue<T_Type, T_Allocator>::CQueue(const CQueue<T_Type, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IQueue<CQueue<T_Type, T_Allocator>, T_Type, CQueueIterator<T_Type, T_Allocator>, CQueueIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::IQueueConst<CQueue<T_Type, T_Allocator>, T_Type, CQueueIterator<T_Type, T_Allocator>, CQueueIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pFirst(NULL),
  m_pLast(NULL),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueue<T_Type, T_Allocator>::~CQueue()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueue<T_Type, T_Allocator>& CQueue<T_Type, T_Allocator>::operator = (const CQueue<T_Type, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueue<T_Type, T_Allocator>::set(const CQueue<T_Type, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CQueue class instance."))
  {
    return false;
  }

  SQueueNode* node_dst = NULL;
  const SQueueNode* node_src = a_crInstance.m_pFirst;

  // Clear current queue.
  if (!clear())
    return false;
  // Insert first begin item.
  if (node_src != NULL)
  {
    if (!insertLast(node_src->m_Item))
      return false;
    node_dst = m_pFirst;
    node_src = node_src->m_pNext;
  }

  // Insert other items.
  while (node_src != NULL)
  {
    SQueueNode* node = m_Allocator.template createOne<SQueueNode>(node_src->m_Item);
    if (node != NULL)
    {
      node->m_pNext = node_dst->m_pNext;
      node_dst->m_pNext = node;
      m_pLast = node;
    }
    else
    {
      WARNING(STR("Cannot create a new queue node for the inserting into the next queue position (requested size is %u bytes).") COMMA (sizeof(SQueueNode)));
      return false;
    }

    ++m_Size;
    node_dst = node_dst->m_pNext;
    node_src = node_src->m_pNext;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueue<T_Type, T_Allocator>::clear()
{ CALL
  SQueueNode* node_begin = m_pFirst;
  SQueueNode* node_next = NULL;

  while (node_begin != NULL)
  {
    node_next = node_begin->m_pNext;
    if (m_Allocator.deleteOne(node_begin))
    {
      m_pFirst = node_next;
      if (m_pFirst == NULL)
        m_pLast = NULL;
      node_begin = node_next;
      --m_Size;
    }
    else
    {
      WARNING(STR("Cannot remove queue node while clearing the queue (requested size is %u bytes).") COMMA (sizeof(SQueueNode)));
      return false;
    }
  }

  m_Size = 0;
  m_pFirst = NULL;
  m_pLast = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueue<T_Type, T_Allocator>::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pFirst == NULL) || (m_pLast == NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CQueue<T_Type, T_Allocator>::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueue<T_Type, T_Allocator>::insertLast(const T_Type& a_crItem)
{ CALL
  SQueueNode* node = m_Allocator.template createOne<SQueueNode>(a_crItem);

  if (node != NULL)
  {
    node->m_pNext = NULL;
    if (m_pLast != NULL)
      m_pLast->m_pNext = node;
    m_pLast = node;
    if (m_pFirst == NULL)
      m_pFirst = node;
    ++m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new queue node for the inserting into the queue (requested size is %u bytes).") COMMA (sizeof(SQueueNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueue<T_Type, T_Allocator>::removeFirst()
{ CALL
  // Check if the current queue is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove first item from the queue."))
  {
    return false;
  }

  SQueueNode* node_begin = m_pFirst;
  SQueueNode* node_next = m_pFirst->m_pNext;

  if (m_Allocator.deleteOne(node_begin))
  {
    m_pFirst = node_next;
    if (m_pFirst == NULL)
      m_pLast = NULL;
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove queue node from the begin of the queue (requested size is %u bytes).") COMMA (sizeof(SQueueNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueue<T_Type, T_Allocator>::removeFirst(T_Type& a_rItem)
{ CALL
  // Check if the current queue is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove first item from the queue."))
  {
    return false;
  }

  SQueueNode* node_begin = m_pFirst;
  SQueueNode* node_next = m_pFirst->m_pNext;

  a_rItem = node_begin->m_Item;
  if (m_Allocator.deleteOne(node_begin))
  {
    m_pFirst = node_next;
    if (m_pFirst == NULL)
      m_pLast = NULL;
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove queue node from the begin of the queue (requested size is %u bytes).") COMMA (sizeof(SQueueNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CQueue<T_Type, T_Allocator>::TIterator CQueue<T_Type, T_Allocator>::getItFirst()
{ CALL
  TIterator it_first;

  // Filling iterator inner structure.
  it_first.m_pContainer = this;
  it_first.m_pNode = m_pFirst;
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CQueue<T_Type, T_Allocator>::TIteratorConst CQueue<T_Type, T_Allocator>::getItFirst() const
{ CALL
  TIteratorConst it_first;

  // Filling iterator inner structure.
  it_first.m_cpContainer = this;
  it_first.m_cpNode = m_pFirst;
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CQueue<T_Type, T_Allocator>::TIterator CQueue<T_Type, T_Allocator>::getItLast()
{ CALL
  TIterator it_last;

  // Filling iterator inner structure.
  it_last.m_pContainer = this;
  it_last.m_pNode = m_pLast;
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CQueue<T_Type, T_Allocator>::TIteratorConst CQueue<T_Type, T_Allocator>::getItLast() const
{ CALL
  TIteratorConst it_last;

  // Filling iterator inner structure.
  it_last.m_cpContainer = this;
  it_last.m_cpNode = m_pLast;
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CQueue<T_Type, T_Allocator>::reverse()
{ CALL
  SQueueNode* node_cur = m_pFirst;
  SQueueNode* node_prev = NULL;
  SQueueNode* node_next = NULL;

  m_pLast = node_cur;
  while (node_cur != NULL)
  {
    node_next = node_cur->m_pNext;
    node_cur->m_pNext = node_prev;
    node_prev = node_cur;
    node_cur = node_next;
  }
  m_pFirst = node_prev;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CQueue<T_Type, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Clear the current queue.
  CHECK(clear());

  // Load the queue header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CQueue<T_Type, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the queue content.
  if (size > 0)
  {
    T_Type item;
    typename CQueue<T_Type, T_Allocator>::SQueueNode* node = NULL;

    // Load queue first item.
    CHECK(a_rArchive.doValue(item, STR("item")));

    // Insert first queue item.
    CHECK(insertLast(item));

    // Insert other items.
    node = m_pFirst;
    while (size-- > 1)
    {
      // Load queue next item.
      CHECK(a_rArchive.doValue(item, STR("item")));

      // Insert next item into the queue.
      typename CQueue<T_Type, T_Allocator>::SQueueNode* new_node = m_Allocator.template createOne<SQueueNode>(item);
      if (new_node != NULL)
      {
        new_node->m_pNext = node->m_pNext;
        node->m_pNext = new_node;
        m_pLast = new_node;
      }
      else
      {
        WARNING(STR("Cannot create a new queue node for the inserting into the next queue position while reading from the reader (requested size is %u bytes).") COMMA (sizeof(SQueueNode)));
        return false;
      }

      ++m_Size;
      node = node->m_pNext;
    }
  }

  // Load the queue end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CQueue<T_Type, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the queue header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CQueue<T_Type, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the queue content.
  if (!isEmpty())
  {
    typename CQueue<T_Type, T_Allocator>::SQueueNode* node = m_pFirst;

    // Save queue items.
    while (node != NULL)
    {
      CHECK(a_rArchive.doValue(node->m_Item, STR("item")));
      node = node->m_pNext;
    }
  }

  // Save the queue end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CQueue<T_Type, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CQueue<T_Type, T_Allocator>::swap(CQueue<T_Type, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
  NAlgorithms::NCommon::swap(m_pFirst, a_rInstance.m_pFirst);
  NAlgorithms::NCommon::swap(m_pLast, a_rInstance.m_pLast);
  NAlgorithms::NCommon::swap(m_Allocator, a_rInstance.m_Allocator);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
