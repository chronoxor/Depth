/*!
 *  \file    CListSC.inl Template single circled list container class. Single
 *           circled list represents one-directed ring container.
 *  \brief   Template single circled list container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template single circled list container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   17.02.2006 21:20:28

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
#ifndef __CLISTSC_INL__
#define __CLISTSC_INL__
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
inline CListSC<T_Type, T_Allocator>::SListSCNode::SListSCNode(const T_Type& a_crItem) :
  m_Item(a_crItem),
  m_pNext(NULL)
{ CALL

}
/*==========================================================================*/
template <typename T_Type, class T_Allocator>
inline CListSC<T_Type, T_Allocator>::CListSC(const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::ICircleSingleLinked<CListSC<T_Type, T_Allocator>, T_Type, CListSCIterator<T_Type, T_Allocator>, CListSCIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::ICircleSingleLinkedConst<CListSC<T_Type, T_Allocator>, T_Type, CListSCIterator<T_Type, T_Allocator>, CListSCIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pCurrent(NULL),
  m_Allocator(a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListSC<T_Type, T_Allocator>::CListSC(const T_Type& a_crItem, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::ICircleSingleLinked<CListSC<T_Type, T_Allocator>, T_Type, CListSCIterator<T_Type, T_Allocator>, CListSCIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::ICircleSingleLinkedConst<CListSC<T_Type, T_Allocator>, T_Type, CListSCIterator<T_Type, T_Allocator>, CListSCIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pCurrent(NULL),
  m_Allocator(a_crAllocator)
{ CALL
  insertCurrent(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListSC<T_Type, T_Allocator>::CListSC(const CListSC<T_Type, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::ICircleSingleLinked<CListSC<T_Type, T_Allocator>, T_Type, CListSCIterator<T_Type, T_Allocator>, CListSCIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::ICircleSingleLinkedConst<CListSC<T_Type, T_Allocator>, T_Type, CListSCIterator<T_Type, T_Allocator>, CListSCIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pCurrent(NULL),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListSC<T_Type, T_Allocator>::~CListSC()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListSC<T_Type, T_Allocator>& CListSC<T_Type, T_Allocator>::operator = (const CListSC<T_Type, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListSC<T_Type, T_Allocator>::set(const CListSC<T_Type, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CListSC class instance."))
  {
    return false;
  }

  SListSCNode* node_dst = NULL;
  const SListSCNode* node_src = a_crInstance.m_pCurrent;
  const SListSCNode* node_cur = a_crInstance.m_pCurrent;

  // Clear current single circled list.
  if (!clear())
    return false;
  // Insert first begin item.
  if (node_src != NULL)
  {
    if (!insertCurrent(node_src->m_Item))
      return false;
    node_dst = m_pCurrent;
    node_src = node_src->m_pNext;
  }

  // Insert other items.
  while (node_src != node_cur)
  {
    SListSCNode* node = m_Allocator.template createOne<SListSCNode>(node_src->m_Item);
    if (node != NULL)
    {
      node->m_pNext = node_dst->m_pNext;
      node_dst->m_pNext = node;
    }
    else
    {
      WARNING(STR("Cannot create a new single circled list node for the inserting into the next single circled list position (requested size is %u bytes).") COMMA (sizeof(SListSCNode)));
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
inline Tbool CListSC<T_Type, T_Allocator>::clear()
{ CALL
  SListSCNode* node_current = m_pCurrent;
  SListSCNode* node_delete = NULL;
  SListSCNode* node_next = NULL;
  SListSCNode* node_next_next = NULL;

  while (node_current != NULL)
  {
    node_next = node_current->m_pNext;
    node_next_next = node_next->m_pNext;
    node_delete = node_next;
    if (m_Allocator.deleteOne(node_delete))
    {
      if (node_next == node_next_next)
        m_pCurrent = NULL;
      else
        m_pCurrent->m_pNext = node_next_next;
      node_current = m_pCurrent;
      --m_Size;
    }
    else
    {
      WARNING(STR("Cannot remove single circled list node while clearing the single circled list (requested size is %u bytes).") COMMA (sizeof(SListSCNode)));
      return false;
    }
  }

  m_Size = 0;
  m_pCurrent = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListSC<T_Type, T_Allocator>::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pCurrent == NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CListSC<T_Type, T_Allocator>::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListSC<T_Type, T_Allocator>::insertCurrent(const T_Type& a_crItem)
{ CALL
  // Check if the current single circled list is empty.
  ASSERT(isEmpty(), STR("Inserting to the single circled list can be made only for the empty single circled list."))
  {
    return false;
  }

  SListSCNode* node = m_Allocator.template createOne<SListSCNode>(a_crItem);

  if (node != NULL)
  {
    node->m_pNext = node;
    m_pCurrent = node;
    ++m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new single circled list node for the inserting into the single circled list current position (requested size is %u bytes).") COMMA (sizeof(SListSCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListSC<T_Type, T_Allocator>::insertNext(const T_Type& a_crItem)
{ CALL
  SListSCNode* node = m_Allocator.template createOne<SListSCNode>(a_crItem);

  if (node != NULL)
  {
    if (m_pCurrent == NULL)
    {
      node->m_pNext = node;
      m_pCurrent = node;
    }
    else
    {
      node->m_pNext = m_pCurrent->m_pNext;
      m_pCurrent->m_pNext = node;
    }
    ++m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new single circled list node for the inserting into the single circled list next position (requested size is %u bytes).") COMMA (sizeof(SListSCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListSC<T_Type, T_Allocator>::removeCurrent()
{ CALL
  // Check if the current single circled list has only one element.
  ASSERT(((m_pCurrent != NULL) && (m_pCurrent->m_pNext == m_pCurrent)), STR("Cannot remove current item from the empty single circled list or from the same list with more than one items."))
  {
    return false;
  }

  if (m_Allocator.deleteOne(m_pCurrent))
  {
    m_pCurrent = NULL;
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove single circled list node from the current position of the single circled list (requested size is %u bytes).") COMMA (sizeof(SListSCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListSC<T_Type, T_Allocator>::removeCurrent(T_Type& a_rItem)
{ CALL
  // Check if the current single circled list has only one element.
  ASSERT(((m_pCurrent != NULL) && (m_pCurrent->m_pNext == m_pCurrent)), STR("Cannot remove current item from the empty single circled list or from the same list with more than one items."))
  {
    return false;
  }

  a_rItem = m_pCurrent->m_Item;
  if (m_Allocator.deleteOne(m_pCurrent))
  {
    m_pCurrent = NULL;
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove single circled list node from the current position of the single circled list (requested size is %u bytes).") COMMA (sizeof(SListSCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListSC<T_Type, T_Allocator>::removeNext()
{ CALL
  // Check if the current single circled list is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove next item from the empty single circled list."))
  {
    return false;
  }

  SListSCNode* node = m_pCurrent->m_pNext;
  SListSCNode* node_next = m_pCurrent->m_pNext;
  SListSCNode* node_next_next = m_pCurrent->m_pNext->m_pNext;

  if (m_Allocator.deleteOne(node))
  {
    if (m_pCurrent == node_next)
      m_pCurrent = NULL;
    else
      m_pCurrent->m_pNext = node_next_next;
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove single circled list node from the next position of the single circled list (requested size is %u bytes).") COMMA (sizeof(SListSCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListSC<T_Type, T_Allocator>::removeNext(T_Type& a_rItem)
{ CALL
  // Check if the current single circled list is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove next item from the empty single circled list."))
  {
    return false;
  }

  SListSCNode* node = m_pCurrent->m_pNext;
  SListSCNode* node_next = m_pCurrent->m_pNext;
  SListSCNode* node_next_next = m_pCurrent->m_pNext->m_pNext;

  a_rItem = m_pCurrent->m_pNext->m_Item;
  if (m_Allocator.deleteOne(node))
  {
    if (m_pCurrent == node_next)
      m_pCurrent = NULL;
    else
      m_pCurrent->m_pNext = node_next_next;
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove single circled list node from the next position of the single circled list (requested size is %u bytes).") COMMA (sizeof(SListSCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CListSC<T_Type, T_Allocator>::stepForward(const Tuint a_cStepCount)
{ CALL
  // Check if the current single circled list is not empty.
  ASSERT(!isEmpty(), STR("Cannot step forward with the empty single circled list."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while (counter > 0)
  {
    m_pCurrent = m_pCurrent->m_pNext;
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CListSC<T_Type, T_Allocator>::TIterator CListSC<T_Type, T_Allocator>::getItCurrent()
{ CALL
  TIterator it_current;

  // Filling iterator inner structure.
  it_current.m_pContainer = this;
  it_current.m_pNode = m_pCurrent;
  return it_current;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CListSC<T_Type, T_Allocator>::TIteratorConst CListSC<T_Type, T_Allocator>::getItCurrent() const
{ CALL
  TIteratorConst it_current;

  // Filling iterator inner structure.
  it_current.m_cpContainer = this;
  it_current.m_cpNode = m_pCurrent;
  return it_current;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CListSC<T_Type, T_Allocator>::TIterator CListSC<T_Type, T_Allocator>::getItNext()
{ CALL
  TIterator it_next;

  // Filling iterator inner structure.
  it_next.m_pContainer = this;
  it_next.m_pNode = ((m_pCurrent != NULL) ? m_pCurrent->m_pNext : NULL);
  return it_next;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CListSC<T_Type, T_Allocator>::TIteratorConst CListSC<T_Type, T_Allocator>::getItNext() const
{ CALL
  TIteratorConst it_next;

  // Filling iterator inner structure.
  it_next.m_cpContainer = this;
  it_next.m_cpNode = ((m_pCurrent != NULL) ? m_pCurrent->m_pNext : NULL);
  return it_next;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CListSC<T_Type, T_Allocator>::reverse()
{ CALL
  if (m_pCurrent != NULL)
  {
    SListSCNode* node_prev = NULL;
    SListSCNode* node_current = m_pCurrent;
    SListSCNode* node_next = m_pCurrent->m_pNext;

    do
    {
      node_current->m_pNext = node_prev;
      node_prev = node_current;
      node_current = node_next;
      node_next = node_next->m_pNext;
    } while (node_current != m_pCurrent);
    m_pCurrent->m_pNext = node_prev;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CListSC<T_Type, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Clear the current single circled list.
  CHECK(clear());

  // Load the single circled list header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CListSC<T_Type, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the single circled list content.
  if (size > 0)
  {
    T_Type item;
    typename CListSC<T_Type, T_Allocator>::SListSCNode* node = NULL;

    // Load single circled list first item.
    CHECK(a_rArchive.doValue(item, STR("item")));

    // Insert first single circled list item.
    CHECK(insertCurrent(item));

    // Insert other items.
    node = m_pCurrent;
    while (size-- > 1)
    {
      // Load single circled list next item.
      CHECK(a_rArchive.doValue(item, STR("item")));

      // Insert next item into the single circled list.
      typename CListSC<T_Type, T_Allocator>::SListSCNode* new_node = m_Allocator.template createOne<SListSCNode>(item);
      if (new_node != NULL)
      {
        new_node->m_pNext = node->m_pNext;
        node->m_pNext = new_node;
      }
      else
      {
        WARNING(STR("Cannot create a new single circled list node for the inserting into the next single circled list position while reading from the reader (requested size is %u bytes).") COMMA (sizeof(SListSCNode)));
        return false;
      }

      ++m_Size;
      node = node->m_pNext;
    }
  }

  // Load the single circled list end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CListSC<T_Type, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the single circled list header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CListSC<T_Type, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the single circled list content.
  if (!isEmpty())
  {
    typename CListSC<T_Type, T_Allocator>::SListSCNode* node = m_pCurrent;

    // Save the first single circled list item.
    CHECK(a_rArchive.doValue(node->m_Item, STR("item")));

    // Save other single circled list items.
    node = node->m_pNext;
    while (node != m_pCurrent)
    {
      CHECK(a_rArchive.doValue(node->m_Item, STR("item")));
      node = node->m_pNext;
    }
  }

  // Save the single circled list end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CListSC<T_Type, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CListSC<T_Type, T_Allocator>::swap(CListSC<T_Type, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
  NAlgorithms::NCommon::swap(m_pCurrent, a_rInstance.m_pCurrent);
  NAlgorithms::NCommon::swap(m_Allocator, a_rInstance.m_Allocator);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
