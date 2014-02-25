/*!
 *  \file    CDeque.inl Template double ended queue container class. Deque
 *           represents container in which items can be inserted/removed
 *           into/from both container ends.
 *  \brief   Template double ended queue container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template double ended queue container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   15.02.2006 23:32:13

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
#ifndef __CDEQUE_INL__
#define __CDEQUE_INL__
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
inline CDeque<T_Type, T_Allocator>::SDequeNode::SDequeNode(const T_Type& a_crItem) :
  m_Item(a_crItem),
  m_pPrev(NULL),
  m_pNext(NULL)
{ CALL

}
/*==========================================================================*/
template <typename T_Type, class T_Allocator>
inline CDeque<T_Type, T_Allocator>::CDeque(const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IDeque<CDeque<T_Type, T_Allocator>, T_Type, CDequeIterator<T_Type, T_Allocator>, CDequeIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CDeque<T_Type, T_Allocator>, T_Type, CDequeIterator<T_Type, T_Allocator>, CDequeIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pFirst(NULL),
  m_pLast(NULL),
  m_Allocator(a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CDeque<T_Type, T_Allocator>::CDeque(const T_Type& a_crItem, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IDeque<CDeque<T_Type, T_Allocator>, T_Type, CDequeIterator<T_Type, T_Allocator>, CDequeIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CDeque<T_Type, T_Allocator>, T_Type, CDequeIterator<T_Type, T_Allocator>, CDequeIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pFirst(NULL),
  m_pLast(NULL),
  m_Allocator(a_crAllocator)
{ CALL
  insertFirst(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CDeque<T_Type, T_Allocator>::CDeque(const CDeque<T_Type, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IDeque<CDeque<T_Type, T_Allocator>, T_Type, CDequeIterator<T_Type, T_Allocator>, CDequeIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CDeque<T_Type, T_Allocator>, T_Type, CDequeIterator<T_Type, T_Allocator>, CDequeIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pFirst(NULL),
  m_pLast(NULL),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CDeque<T_Type, T_Allocator>::~CDeque()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CDeque<T_Type, T_Allocator>& CDeque<T_Type, T_Allocator>::operator = (const CDeque<T_Type, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CDeque<T_Type, T_Allocator>::set(const CDeque<T_Type, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CDeque class instance."))
  {
    return false;
  }

  SDequeNode* node_dst = NULL;
  const SDequeNode* node_src = a_crInstance.m_pFirst;

  // Clear current deque.
  if (!clear())
    return false;
  // Insert first begin item.
  if (node_src != NULL)
  {
    if (!insertFirst(node_src->m_Item))
      return false;
    node_dst = m_pFirst;
    node_src = node_src->m_pNext;
  }

  // Insert other items.
  while (node_src != NULL)
  {
    SDequeNode* node = m_Allocator.template createOne<SDequeNode>(node_src->m_Item);
    if (node != NULL)
    {
      node->m_pPrev = node_dst;
      node->m_pNext = node_dst->m_pNext;
      node_dst->m_pNext = node;
      m_pLast = node;
    }
    else
    {
      WARNING(STR("Cannot create a new deque node for the inserting into the next deque position (requested size is %u bytes).") COMMA (sizeof(SDequeNode)));
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
inline Tbool CDeque<T_Type, T_Allocator>::clear()
{ CALL
  SDequeNode* node_begin = m_pFirst;
  SDequeNode* node_next = NULL;

  while (node_begin != NULL)
  {
    node_next = node_begin->m_pNext;
    if (m_Allocator.deleteOne(node_begin))
    {
      m_pFirst = node_next;
      if (m_pFirst == NULL)
        m_pLast = NULL;
      else
        m_pFirst->m_pPrev = NULL;
      node_begin = node_next;
      --m_Size;
    }
    else
    {
      WARNING(STR("Cannot remove deque node while clearing the deque (requested size is %u bytes).") COMMA (sizeof(SDequeNode)));
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
inline Tbool CDeque<T_Type, T_Allocator>::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pFirst == NULL) || (m_pLast == NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CDeque<T_Type, T_Allocator>::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CDeque<T_Type, T_Allocator>::insertFirst(const T_Type& a_crItem)
{ CALL
  SDequeNode* node = m_Allocator.template createOne<SDequeNode>(a_crItem);

  if (node != NULL)
  {
    node->m_pPrev = NULL;
    node->m_pNext = m_pFirst;
    if (m_pFirst != NULL)
      m_pFirst->m_pPrev = node;
    m_pFirst = node;
    if (m_pLast == NULL)
      m_pLast = node;
    ++m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new deque node for the inserting into deque begin position (requested size is %u bytes).") COMMA (sizeof(SDequeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CDeque<T_Type, T_Allocator>::insertLast(const T_Type& a_crItem)
{ CALL
  SDequeNode* node = m_Allocator.template createOne<SDequeNode>(a_crItem);

  if (node != NULL)
  {
    node->m_pPrev = m_pLast;
    node->m_pNext = NULL;
    if (m_pFirst == NULL)
      m_pFirst = node;
    if (m_pLast != NULL)
      m_pLast->m_pNext = node;
    m_pLast = node;
    ++m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new deque node for the inserting into deque end position (requested size is %u bytes).") COMMA (sizeof(SDequeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CDeque<T_Type, T_Allocator>::removeFirst()
{ CALL
  // Check if the current deque is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove first item from the empty deque."))
  {
    return false;
  }

  SDequeNode* node_begin = m_pFirst;
  SDequeNode* node_next = m_pFirst->m_pNext;

  if (m_Allocator.deleteOne(node_begin))
  {
    m_pFirst = node_next;
    if (m_pFirst == NULL)
      m_pLast = NULL;
    else
      m_pFirst->m_pPrev = NULL;
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove deque node from the begin of the deque (requested size is %u bytes).") COMMA (sizeof(SDequeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CDeque<T_Type, T_Allocator>::removeFirst(T_Type& a_rItem)
{ CALL
  // Check if the current deque is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove first item from the empty deque."))
  {
    return false;
  }

  SDequeNode* node_begin = m_pFirst;
  SDequeNode* node_next = m_pFirst->m_pNext;

  a_rItem = node_begin->m_Item;
  if (m_Allocator.deleteOne(node_begin))
  {
    m_pFirst = node_next;
    if (m_pFirst == NULL)
      m_pLast = NULL;
    else
      m_pFirst->m_pPrev = NULL;
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove deque node from the begin of the deque (requested size is %u bytes).") COMMA (sizeof(SDequeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CDeque<T_Type, T_Allocator>::removeLast()
{ CALL
  // Check if the current deque is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove last item from the empty deque."))
  {
    return false;
  }

  SDequeNode* node_end = m_pLast;
  SDequeNode* node_prev = m_pLast->m_pPrev;

  if (m_Allocator.deleteOne(node_end))
  {
    m_pLast = node_prev;
    if (m_pLast == NULL)
      m_pFirst = NULL;
    else
      m_pLast->m_pNext = NULL;
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove deque node from the end of the deque (requested size is %u bytes).") COMMA (sizeof(SDequeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CDeque<T_Type, T_Allocator>::removeLast(T_Type& a_rItem)
{ CALL
  // Check if the current deque is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove last item from the empty deque."))
  {
    return false;
  }

  SDequeNode* node_end = m_pLast;
  SDequeNode* node_prev = m_pLast->m_pPrev;

  a_rItem = node_end->m_Item;
  if (m_Allocator.deleteOne(node_end))
  {
    m_pLast = node_prev;
    if (m_pLast == NULL)
      m_pFirst = NULL;
    else
      m_pLast->m_pNext = NULL;
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove deque node from the end of the deque (requested size is %u bytes).") COMMA (sizeof(SDequeNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CDeque<T_Type, T_Allocator>::TIterator CDeque<T_Type, T_Allocator>::getItFirst()
{ CALL
  TIterator it_first;

  // Filling iterator inner structure.
  it_first.m_pContainer = this;
  it_first.m_pNode = m_pFirst;
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CDeque<T_Type, T_Allocator>::TIteratorConst CDeque<T_Type, T_Allocator>::getItFirst() const
{ CALL
  TIteratorConst it_first;

  // Filling iterator inner structure.
  it_first.m_cpContainer = this;
  it_first.m_cpNode = m_pFirst;
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CDeque<T_Type, T_Allocator>::TIterator CDeque<T_Type, T_Allocator>::getItLast()
{ CALL
  TIterator it_last;

  // Filling iterator inner structure.
  it_last.m_pContainer = this;
  it_last.m_pNode = m_pLast;
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CDeque<T_Type, T_Allocator>::TIteratorConst CDeque<T_Type, T_Allocator>::getItLast() const
{ CALL
  TIteratorConst it_last;

  // Filling iterator inner structure.
  it_last.m_cpContainer = this;
  it_last.m_cpNode = m_pLast;
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CDeque<T_Type, T_Allocator>::reverse()
{ CALL
  SDequeNode* node_cur = m_pFirst;
  SDequeNode* node_prev = NULL;
  SDequeNode* node_next = NULL;

  m_pLast = node_cur;
  while (node_cur != NULL)
  {
    node_next = node_cur->m_pNext;
    node_cur->m_pPrev = node_next;
    node_cur->m_pNext = node_prev;
    node_prev = node_cur;
    node_cur = node_next;
  }
  m_pFirst = node_prev;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CDeque<T_Type, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Clear the current deque.
  CHECK(clear());

  // Load the deque header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CDeque<T_Type, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the deque content.
  if (size > 0)
  {
    T_Type item;
    typename CDeque<T_Type, T_Allocator>::SDequeNode* node = NULL;

    // Load deque first item.
    CHECK(a_rArchive.doValue(item, STR("item")));

    // Insert first deque item.
    CHECK(insertLast(item));

    // Insert other items.
    node = m_pFirst;
    while (size-- > 1)
    {
      // Load deque next item.
      CHECK(a_rArchive.doValue(item, STR("item")));

      // Insert next item into the deque.
      typename CDeque<T_Type, T_Allocator>::SDequeNode* new_node = m_Allocator.template createOne<SDequeNode>(item);
      if (new_node != NULL)
      {
        new_node->m_pPrev = node;
        new_node->m_pNext = node->m_pNext;
        node->m_pNext = new_node;
        m_pLast = new_node;
      }
      else
      {
        WARNING(STR("Cannot create a new deque node for the inserting into the next deque position while reading from the reader (requested size is %u bytes).") COMMA (sizeof(SDequeNode)));
        return false;
      }

      ++m_Size;
      node = node->m_pNext;
    }
  }

  // Load the deque end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CDeque<T_Type, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the deque header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CDeque<T_Type, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the deque content.
  if (!isEmpty())
  {
    typename CDeque<T_Type, T_Allocator>::SDequeNode* node = m_pFirst;

    // Save deque items.
    while (node != NULL)
    {
      CHECK(a_rArchive.doValue(node->m_Item, STR("item")));
      node = node->m_pNext;
    }
  }

  // Save the deque end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CDeque<T_Type, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CDeque<T_Type, T_Allocator>::swap(CDeque<T_Type, T_Allocator>& a_rInstance)
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
