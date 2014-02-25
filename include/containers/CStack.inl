/*!
 *  \file    CStack.inl Template stack container class. Stack represents
 *           container that can implement LIFO (last in - first out)
 *           algorithm.
 *  \brief   Template stack container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template stack container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   05.02.2006 22:53:45

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
#ifndef __CSTACK_INL__
#define __CSTACK_INL__
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
inline CStack<T_Type, T_Allocator>::SStackNode::SStackNode(const T_Type& a_crItem) :
  m_Item(a_crItem),
  m_pNext(NULL)
{ CALL

}
/*==========================================================================*/
template <typename T_Type, class T_Allocator>
inline CStack<T_Type, T_Allocator>::CStack(const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IStack<CStack<T_Type, T_Allocator>, T_Type,  CStackIterator<T_Type, T_Allocator>, CStackIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::IStackConst<CStack<T_Type, T_Allocator>, T_Type,  CStackIterator<T_Type, T_Allocator>, CStackIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pTop(NULL),
  m_Allocator(a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CStack<T_Type, T_Allocator>::CStack(const T_Type& a_crItem, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IStack<CStack<T_Type, T_Allocator>, T_Type,  CStackIterator<T_Type, T_Allocator>, CStackIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::IStackConst<CStack<T_Type, T_Allocator>, T_Type,  CStackIterator<T_Type, T_Allocator>, CStackIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pTop(NULL),
  m_Allocator(a_crAllocator)
{ CALL
  insertTop(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CStack<T_Type, T_Allocator>::CStack(const CStack<T_Type, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IStack<CStack<T_Type, T_Allocator>, T_Type,  CStackIterator<T_Type, T_Allocator>, CStackIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::IStackConst<CStack<T_Type, T_Allocator>, T_Type,  CStackIterator<T_Type, T_Allocator>, CStackIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pTop(NULL),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CStack<T_Type, T_Allocator>::~CStack()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CStack<T_Type, T_Allocator>& CStack<T_Type, T_Allocator>::operator = (const CStack<T_Type, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CStack<T_Type, T_Allocator>::set(const CStack<T_Type, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CStack class instance."))
  {
    return false;
  }

  SStackNode* node_dst = NULL;
  const SStackNode* node_src = a_crInstance.m_pTop;

  // Clear the current stack.
  if (!clear())
    return false;

  // Insert first top item.
  if (node_src != NULL)
  {
    if (!insertTop(node_src->m_Item))
      return false;
    node_dst = m_pTop;
    node_src = node_src->m_pNext;
  }

  // Insert other items.
  while (node_src != NULL)
  {
    SStackNode* node = m_Allocator.template createOne<SStackNode>(node_src->m_Item);
    if (node != NULL)
    {
      node->m_pNext = node_dst->m_pNext;
      node_dst->m_pNext = node;
    }
    else
    {
      WARNING(STR("Cannot create a new stack node for the inserting into the next stack position (requested size is %u bytes).") COMMA (sizeof(SStackNode)));
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
inline Tbool CStack<T_Type, T_Allocator>::clear()
{ CALL
  SStackNode* node_top = m_pTop;
  SStackNode* node_next = NULL;

  while (node_top != NULL)
  {
    node_next = node_top->m_pNext;
    if (m_Allocator.deleteOne(node_top))
    {
      m_pTop = node_next;
      node_top = node_next;
      --m_Size;
    }
    else
    {
      WARNING(STR("Cannot remove stack node while clearing the stack (requested size is %u bytes).") COMMA (sizeof(SStackNode)));
      return false;
    }
  }

  m_Size = 0;
  m_pTop = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CStack<T_Type, T_Allocator>::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pTop == NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CStack<T_Type, T_Allocator>::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CStack<T_Type, T_Allocator>::insertTop(const T_Type& a_crItem)
{ CALL
  SStackNode* node = m_Allocator.template createOne<SStackNode>(a_crItem);

  if (node != NULL)
  {
    node->m_pNext = m_pTop;
    m_pTop = node;
    ++m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new stack node for the inserting the into stack (requested size is %u bytes).") COMMA (sizeof(SStackNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CStack<T_Type, T_Allocator>::removeTop()
{ CALL
  // Check if the current stack is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove top item from the empty stack."))
  {
    return false;
  }

  SStackNode* node_top = m_pTop;
  SStackNode* node_next = m_pTop->m_pNext;

  if (m_Allocator.deleteOne(node_top))
  {
    m_pTop = node_next;
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove stack node from the top of the stack (requested size is %u bytes).") COMMA (sizeof(SStackNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CStack<T_Type, T_Allocator>::removeTop(T_Type& a_rItem)
{ CALL
  // Check if the current stack is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove top item from the empty stack."))
  {
    return false;
  }

  SStackNode* node_top = m_pTop;
  SStackNode* node_next = m_pTop->m_pNext;

  a_rItem = node_top->m_Item;
  if (m_Allocator.deleteOne(node_top))
  {
    m_pTop = node_next;
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove stack node from the top of the stack (requested size is %u bytes).") COMMA (sizeof(SStackNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CStack<T_Type, T_Allocator>::TIterator CStack<T_Type, T_Allocator>::getItTop()
{ CALL
  TIterator it_top;

  // Filling iterator inner structure.
  it_top.m_pContainer = this;
  it_top.m_pNode = m_pTop;
  return it_top;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CStack<T_Type, T_Allocator>::TIteratorConst CStack<T_Type, T_Allocator>::getItTop() const
{ CALL
  TIteratorConst it_top;

  // Filling iterator inner structure.
  it_top.m_cpContainer = this;
  it_top.m_cpNode = m_pTop;
  return it_top;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CStack<T_Type, T_Allocator>::reverse()
{ CALL
  SStackNode* node_cur = m_pTop;
  SStackNode* node_prev = NULL;
  SStackNode* node_next = NULL;

  while (node_cur != NULL)
  {
    node_next = node_cur->m_pNext;
    node_cur->m_pNext = node_prev;
    node_prev = node_cur;
    node_cur = node_next;
  }
  m_pTop = node_prev;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CStack<T_Type, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Clear the current stack.
  CHECK(clear());

  // Load the stack header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CStack<T_Type, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the stack content.
  if (size > 0)
  {
    T_Type item;
    typename CStack<T_Type, T_Allocator>::SStackNode* node = NULL;

    // Load stack first item.
    CHECK(a_rArchive.doValue(item, STR("item")));

    // Insert first top item.
    CHECK(insertTop(item));

    // Insert other items.
    node = m_pTop;
    while (size-- > 1)
    {
      // Load stack next item.
      CHECK(a_rArchive.doValue(item, STR("item")));

      // Insert next item into the stack.
      typename CStack<T_Type, T_Allocator>::SStackNode* new_node = m_Allocator.template createOne<SStackNode>(item);
      if (new_node != NULL)
      {
        new_node->m_pNext = node->m_pNext;
        node->m_pNext = new_node;
      }
      else
      {
        WARNING(STR("Cannot create a new stack node for the inserting into the next stack position while reading from the reader (requested size is %u bytes).") COMMA (sizeof(SStackNode)));
        return false;
      }

      ++m_Size;
      node = node->m_pNext;
    }
  }

  // Load the stack end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CStack<T_Type, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the stack header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CStack<T_Type, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the stack content.
  if (!isEmpty())
  {
    typename CStack<T_Type, T_Allocator>::SStackNode* node = m_pTop;

    // Save stack items.
    while (node != NULL)
    {
      CHECK(a_rArchive.doValue(node->m_Item, STR("item")));
      node = node->m_pNext;
    }
  }

  // Save the stack end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CStack<T_Type, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CStack<T_Type, T_Allocator>::swap(CStack<T_Type, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
  NAlgorithms::NCommon::swap(m_pTop, a_rInstance.m_pTop);
  NAlgorithms::NCommon::swap(m_Allocator, a_rInstance.m_Allocator);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
