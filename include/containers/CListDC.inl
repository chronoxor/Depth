/*!
 *  \file    CListDC.inl Template double circled list container class. Double
 *           circled list represents bi-directed ring container.
 *  \brief   Template double circled list container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template double circled list container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   25.02.2006 02:06:26

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
#ifndef __CLISTDC_INL__
#define __CLISTDC_INL__
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
inline CListDC<T_Type, T_Allocator>::SListDCNode::SListDCNode(const T_Type& a_crItem) :
  m_Item(a_crItem),
  m_pPrev(NULL),
  m_pNext(NULL)
{ CALL

}
/*==========================================================================*/
template <typename T_Type, class T_Allocator>
inline CListDC<T_Type, T_Allocator>::CListDC(const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::ICircleDoubleLinked<CListDC<T_Type, T_Allocator>, T_Type, CListDCIterator<T_Type, T_Allocator>, CListDCIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::ICircleDoubleLinkedConst<CListDC<T_Type, T_Allocator>, T_Type, CListDCIterator<T_Type, T_Allocator>, CListDCIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pCurrent(NULL),
  m_Allocator(a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDC<T_Type, T_Allocator>::CListDC(const T_Type& a_crItem, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::ICircleDoubleLinked<CListDC<T_Type, T_Allocator>, T_Type, CListDCIterator<T_Type, T_Allocator>, CListDCIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::ICircleDoubleLinkedConst<CListDC<T_Type, T_Allocator>, T_Type, CListDCIterator<T_Type, T_Allocator>, CListDCIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pCurrent(NULL),
  m_Allocator(a_crAllocator)
{ CALL
  insertCurrentForward(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDC<T_Type, T_Allocator>::CListDC(const CListDC<T_Type, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::ICircleDoubleLinked<CListDC<T_Type, T_Allocator>, T_Type, CListDCIterator<T_Type, T_Allocator>, CListDCIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::ICircleDoubleLinkedConst<CListDC<T_Type, T_Allocator>, T_Type, CListDCIterator<T_Type, T_Allocator>, CListDCIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pCurrent(NULL),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDC<T_Type, T_Allocator>::~CListDC()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDC<T_Type, T_Allocator>& CListDC<T_Type, T_Allocator>::operator = (const CListDC<T_Type, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::set(const CListDC<T_Type, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CListDC class instance."))
  {
    return false;
  }

  SListDCNode* node_dst = NULL;
  const SListDCNode* node_src = a_crInstance.m_pCurrent;
  const SListDCNode* node_cur = a_crInstance.m_pCurrent;

  // Clear current double circled list.
  if (!clear())
    return false;
  // Insert first begin item.
  if (node_src != NULL)
  {
    if (!insertCurrentForward(node_src->m_Item))
      return false;
    node_dst = m_pCurrent;
    node_src = node_src->m_pNext;
  }

  // Insert other items.
  while (node_src != node_cur)
  {
    SListDCNode* node = m_Allocator.template createOne<SListDCNode>(node_src->m_Item);
    if (node != NULL)
    {
      node->m_pPrev = node_dst;
      node->m_pNext = node_dst->m_pNext;
      node->m_pPrev->m_pNext = node;
      node->m_pNext->m_pPrev = node;
    }
    else
    {
      WARNING(STR("Cannot create a new double circled list node for the inserting into the next double circled list position (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
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
inline Tbool CListDC<T_Type, T_Allocator>::clear()
{ CALL
  SListDCNode* node_current = m_pCurrent;
  SListDCNode* node_delete = NULL;
  SListDCNode* node_next = NULL;
  SListDCNode* node_next_next = NULL;

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
      {
        node_current->m_pNext = node_next_next;
        node_next_next->m_pPrev = node_current;
      }
      node_current = m_pCurrent;
      --m_Size;
    }
    else
    {
      WARNING(STR("Cannot remove double circled list node while clearing the double circled list (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
      return false;
    }
  }

  m_Size = 0;
  m_pCurrent = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pCurrent == NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CListDC<T_Type, T_Allocator>::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::insertCurrentForward(const T_Type& a_crItem)
{ CALL
  SListDCNode* node = m_Allocator.template createOne<SListDCNode>(a_crItem);

  if (node != NULL)
  {
    if (m_pCurrent == NULL)
    {
      node->m_pPrev = node;
      node->m_pNext = node;
    }
    else
    {
      node->m_pPrev = m_pCurrent->m_pPrev;
      node->m_pNext = m_pCurrent;
      node->m_pPrev->m_pNext = node;
      node->m_pNext->m_pPrev = node;
    }
    m_pCurrent = node;
    ++m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new double circled list node for the forward inserting into the double circled list current position (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::insertCurrentBackward(const T_Type& a_crItem)
{ CALL
  SListDCNode* node = m_Allocator.template createOne<SListDCNode>(a_crItem);

  if (node != NULL)
  {
    if (m_pCurrent == NULL)
    {
      node->m_pPrev = node;
      node->m_pNext = node;
    }
    else
    {
      node->m_pPrev = m_pCurrent;
      node->m_pNext = m_pCurrent->m_pNext;
      node->m_pPrev->m_pNext = node;
      node->m_pNext->m_pPrev = node;
    }
    m_pCurrent = node;
    ++m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new double circled list node for the backward inserting into the double circled list current position (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::insertNext(const T_Type& a_crItem)
{ CALL
  SListDCNode* node = m_Allocator.template createOne<SListDCNode>(a_crItem);

  if (node != NULL)
  {
    if (m_pCurrent == NULL)
    {
      node->m_pPrev = node;
      node->m_pNext = node;
      m_pCurrent = node;
    }
    else
    {
      node->m_pPrev = m_pCurrent;
      node->m_pNext = m_pCurrent->m_pNext;
      node->m_pPrev->m_pNext = node;
      node->m_pNext->m_pPrev = node;
    }
    ++m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new double circled list node for the inserting into the double circled list next position (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::insertPrev(const T_Type& a_crItem)
{ CALL
  SListDCNode* node = m_Allocator.template createOne<SListDCNode>(a_crItem);

  if (node != NULL)
  {
    if (m_pCurrent == NULL)
    {
      node->m_pPrev = node;
      node->m_pNext = node;
      m_pCurrent = node;
    }
    else
    {
      node->m_pPrev = m_pCurrent->m_pPrev;
      node->m_pNext = m_pCurrent;
      node->m_pPrev->m_pNext = node;
      node->m_pNext->m_pPrev = node;
    }
    ++m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new double circled list node for the inserting into the double circled list previous position (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::removeCurrentForward()
{ CALL
  // Check if the current double circled list is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove current item from the double circled list."))
  {
    return false;
  }

  SListDCNode* node_current = m_pCurrent;
  SListDCNode* node_prev = m_pCurrent->m_pPrev;
  SListDCNode* node_next = m_pCurrent->m_pNext;

  if (m_Allocator.deleteOne(node_current))
  {
    if (node_next == m_pCurrent)
    {
      m_pCurrent = NULL;
    }
    else
    {
      node_prev->m_pNext = node_next;
      node_next->m_pPrev = node_prev;
      m_pCurrent = node_next;
    }
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double circled list node from the current position of the double circled list (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::removeCurrentForward(T_Type& a_rItem)
{ CALL
  // Check if the current double circled list is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove current item from the double circled list."))
  {
    return false;
  }

  SListDCNode* node_current = m_pCurrent;
  SListDCNode* node_prev = m_pCurrent->m_pPrev;
  SListDCNode* node_next = m_pCurrent->m_pNext;

  a_rItem = node_current->m_Item;
  if (m_Allocator.deleteOne(node_current))
  {
    if (node_next == m_pCurrent)
    {
      m_pCurrent = NULL;
    }
    else
    {
      node_prev->m_pNext = node_next;
      node_next->m_pPrev = node_prev;
      m_pCurrent = node_next;
    }
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double circled list node from the current position of the double circled list (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::removeCurrentBackward()
{ CALL
  // Check if the current double circled list is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove current item from the double circled list."))
  {
    return false;
  }

  SListDCNode* node_current = m_pCurrent;
  SListDCNode* node_prev = m_pCurrent->m_pPrev;
  SListDCNode* node_next = m_pCurrent->m_pNext;

  if (m_Allocator.deleteOne(node_current))
  {
    if (node_next == m_pCurrent)
    {
      m_pCurrent = NULL;
    }
    else
    {
      node_prev->m_pNext = node_next;
      node_next->m_pPrev = node_prev;
      m_pCurrent = node_prev;
    }
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double circled list node from the current position of the double circled list (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::removeCurrentBackward(T_Type& a_rItem)
{ CALL
  // Check if the current double circled list is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove current item from the double circled list."))
  {
    return false;
  }

  SListDCNode* node_current = m_pCurrent;
  SListDCNode* node_prev = m_pCurrent->m_pPrev;
  SListDCNode* node_next = m_pCurrent->m_pNext;

  a_rItem = node_current->m_Item;
  if (m_Allocator.deleteOne(node_current))
  {
    if (node_next == m_pCurrent)
    {
      m_pCurrent = NULL;
    }
    else
    {
      node_prev->m_pNext = node_next;
      node_next->m_pPrev = node_prev;
      m_pCurrent = node_prev;
    }
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double circled list node from the current position of the double circled list (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::removeNext()
{ CALL
  // Check if the current double circled list is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove next item from the double circled list."))
  {
    return false;
  }

  SListDCNode* node = m_pCurrent->m_pNext;
  SListDCNode* node_next = m_pCurrent->m_pNext;
  SListDCNode* node_next_next = m_pCurrent->m_pNext->m_pNext;

  if (m_Allocator.deleteOne(node))
  {
    if (m_pCurrent == node_next)
      m_pCurrent = NULL;
    else
    {
      m_pCurrent->m_pNext = node_next_next;
      node_next_next->m_pPrev = m_pCurrent;
    }
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double circled list node from the next position of the double circled list (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::removeNext(T_Type& a_rItem)
{ CALL
  // Check if the current double circled list is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove next item from the double circled list."))
  {
    return false;
  }

  SListDCNode* node = m_pCurrent->m_pNext;
  SListDCNode* node_next = m_pCurrent->m_pNext;
  SListDCNode* node_next_next = m_pCurrent->m_pNext->m_pNext;

  a_rItem = m_pCurrent->m_pNext->m_Item;
  if (m_Allocator.deleteOne(node))
  {
    if (m_pCurrent == node_next)
      m_pCurrent = NULL;
    else
    {
      m_pCurrent->m_pNext = node_next_next;
      node_next_next->m_pPrev = m_pCurrent;
    }
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double circled list node from the next position of the double circled list (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::removePrev()
{ CALL
  // Check if the current double circled list is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove previous item from the double circled list."))
  {
    return false;
  }

  SListDCNode* node = m_pCurrent->m_pPrev;
  SListDCNode* node_prev = m_pCurrent->m_pPrev;
  SListDCNode* node_prev_prev = m_pCurrent->m_pPrev->m_pPrev;

  if (m_Allocator.deleteOne(node))
  {
    if (m_pCurrent == node_prev)
      m_pCurrent = NULL;
    else
    {
      m_pCurrent->m_pPrev = node_prev_prev;
      node_prev_prev->m_pNext = m_pCurrent;
    }
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double circled list node from the previous position of the double circled list (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDC<T_Type, T_Allocator>::removePrev(T_Type& a_rItem)
{ CALL
  // Check if the current double circled list is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove previous item from the double circled list."))
  {
    return false;
  }

  SListDCNode* node = m_pCurrent->m_pPrev;
  SListDCNode* node_prev = m_pCurrent->m_pPrev;
  SListDCNode* node_prev_prev = m_pCurrent->m_pPrev->m_pPrev;

  a_rItem = m_pCurrent->m_pPrev->m_Item;
  if (m_Allocator.deleteOne(node))
  {
    if (m_pCurrent == node_prev)
      m_pCurrent = NULL;
    else
    {
      m_pCurrent->m_pPrev = node_prev_prev;
      node_prev_prev->m_pNext = m_pCurrent;
    }
    --m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double circled list node from the previous position of the double circled list (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CListDC<T_Type, T_Allocator>::stepForward(const Tuint a_cStepCount)
{ CALL
  // Check if the current double circled list is not empty.
  ASSERT(!isEmpty(), STR("Cannot step forward with the empty double circled list."))
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
inline Tuint CListDC<T_Type, T_Allocator>::stepBackward(const Tuint a_cStepCount)
{ CALL
  // Check if the current double circled list is not empty.
  ASSERT(!isEmpty(), STR("Cannot step backward with the empty double circled list."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step backward by given steps.
  while (counter > 0)
  {
    m_pCurrent = m_pCurrent->m_pPrev;
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CListDC<T_Type, T_Allocator>::TIterator CListDC<T_Type, T_Allocator>::getItCurrent()
{ CALL
  TIterator it_current;

  // Filling iterator inner structure.
  it_current.m_pContainer = this;
  it_current.m_pNode = m_pCurrent;
  return it_current;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CListDC<T_Type, T_Allocator>::TIteratorConst CListDC<T_Type, T_Allocator>::getItCurrent() const
{ CALL
  TIteratorConst it_current;

  // Filling iterator inner structure.
  it_current.m_cpContainer = this;
  it_current.m_cpNode = m_pCurrent;
  return it_current;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CListDC<T_Type, T_Allocator>::TIterator CListDC<T_Type, T_Allocator>::getItNext()
{ CALL
  TIterator it_next;

  // Filling iterator inner structure.
  it_next.m_pContainer = this;
  it_next.m_pNode = ((m_pCurrent != NULL) ? m_pCurrent->m_pNext : NULL);
  return it_next;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CListDC<T_Type, T_Allocator>::TIteratorConst CListDC<T_Type, T_Allocator>::getItNext() const
{ CALL
  TIteratorConst it_next;

  // Filling iterator inner structure.
  it_next.m_cpContainer = this;
  it_next.m_cpNode = ((m_pCurrent != NULL) ? m_pCurrent->m_pNext : NULL);
  return it_next;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CListDC<T_Type, T_Allocator>::TIterator CListDC<T_Type, T_Allocator>::getItPrev()
{ CALL
  TIterator it_prev;

  // Filling iterator inner structure.
  it_prev.m_pContainer = this;
  it_prev.m_pNode = ((m_pCurrent != NULL) ? m_pCurrent->m_pPrev : NULL);
  return it_prev;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CListDC<T_Type, T_Allocator>::TIteratorConst CListDC<T_Type, T_Allocator>::getItPrev() const
{ CALL
  TIteratorConst it_prev;

  // Filling iterator inner structure.
  it_prev.m_cpContainer = this;
  it_prev.m_cpNode = ((m_pCurrent != NULL) ? m_pCurrent->m_pPrev : NULL);
  return it_prev;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CListDC<T_Type, T_Allocator>::reverse()
{ CALL
  if (m_pCurrent != NULL)
  {
    SListDCNode* node_prev = m_pCurrent->m_pPrev;
    SListDCNode* node_current = m_pCurrent;
    SListDCNode* node_next = m_pCurrent->m_pNext;

    do
    {
      node_current->m_pPrev = node_next;
      node_current->m_pNext = node_prev;
      node_prev = node_current;
      node_current = node_next;
      node_next = node_next->m_pNext;
    } while (node_current != m_pCurrent);
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CListDC<T_Type, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Clear the current double circled list.
  CHECK(clear());

  // Load the double circled list header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CListDC<T_Type, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the double circled list content.
  if (size > 0)
  {
    T_Type item;
    typename CListDC<T_Type, T_Allocator>::SListDCNode* node = NULL;

    // Load double circled list first item.
    CHECK(a_rArchive.doValue(item, STR("item")));

    // Insert first double circled list item.
    CHECK(insertCurrentForward(item));

    // Insert other items.
    node = m_pCurrent;
    while (size-- > 1)
    {
      // Load double circled list next item.
      CHECK(a_rArchive.doValue(item, STR("item")));

      // Insert next item into the double circled list.
      typename CListDC<T_Type, T_Allocator>::SListDCNode* new_node = m_Allocator.template createOne<SListDCNode>(item);
      if (new_node != NULL)
      {
        new_node->m_pPrev = node;
        new_node->m_pNext = node->m_pNext;
        new_node->m_pPrev->m_pNext = new_node;
        new_node->m_pNext->m_pPrev = new_node;
      }
      else
      {
        WARNING(STR("Cannot create a new double circled list node for the inserting into the next double circled list position while reading from the reader (requested size is %u bytes).") COMMA (sizeof(SListDCNode)));
        return false;
      }

      ++m_Size;
      node = node->m_pNext;
    }
  }

  // Load the double circled list end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CListDC<T_Type, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the double circled list header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CListDC<T_Type, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the double circled list content.
  if (!isEmpty())
  {
    typename CListDC<T_Type, T_Allocator>::SListDCNode* node = m_pCurrent;

    // Save the first double circled list item.
    CHECK(a_rArchive.doValue(node->m_Item, STR("item")));

    // Save other double circled list items.
    node = node->m_pNext;
    while (node != m_pCurrent)
    {
      CHECK(a_rArchive.doValue(node->m_Item, STR("item")));
      node = node->m_pNext;
    }
  }

  // Save the double circled list end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CListDC<T_Type, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CListDC<T_Type, T_Allocator>::swap(CListDC<T_Type, T_Allocator>& a_rInstance)
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
