/*!
 *  \file    CTreeIteratorConst.inl Tree constant iterator definitions. It
 *           gives ability to get tree items.
 *  \brief   Tree constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   23.06.2006 22:43:27

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
#ifndef __CTREEITERATORCONST_INL__
#define __CTREEITERATORCONST_INL__
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
inline CTreeIteratorConst<T_Type, T_Allocator>::CTreeIteratorConst() :
  NCommon::NIterators::IIteratorConst<CTreeIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CTreeIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  m_cpContainer(NULL),
  m_cpNode(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator>::CTreeIteratorConst(const CTree<T_Type, T_Allocator>* a_cpContainer) :
  NCommon::NIterators::IIteratorConst<CTreeIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CTreeIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  m_cpContainer(a_cpContainer),
  m_cpNode(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator>::CTreeIteratorConst(const CTreeIterator<T_Type, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CTreeIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CTreeIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  m_cpContainer(NULL),
  m_cpNode(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator>::CTreeIteratorConst(const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CTreeIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveTree<CTreeIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >(),
  m_cpContainer(NULL),
  m_cpNode(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator>::~CTreeIteratorConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator == (const CTreeIterator<T_Type, T_Allocator>& a_crInstance1, const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_pNode == a_crInstance2.m_cpNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator == (const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance1, const CTreeIterator<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_cpNode == a_crInstance2.m_pNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator == (const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance1, const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_cpNode == a_crInstance2.m_cpNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator != (const CTreeIterator<T_Type, T_Allocator>& a_crInstance1, const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_pNode != a_crInstance2.m_cpNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator != (const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance1, const CTreeIterator<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_cpNode != a_crInstance2.m_pNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator != (const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance1, const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_cpNode != a_crInstance2.m_cpNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator>& CTreeIteratorConst<T_Type, T_Allocator>::operator = (const CTreeIterator<T_Type, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator>& CTreeIteratorConst<T_Type, T_Allocator>::operator = (const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator>& CTreeIteratorConst<T_Type, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator>& CTreeIteratorConst<T_Type, T_Allocator>::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator>& CTreeIteratorConst<T_Type, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator>& CTreeIteratorConst<T_Type, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::operator ++ (int)
{ CALL
  CTreeIteratorConst<T_Type, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::operator -- (int)
{ CALL
  CTreeIteratorConst<T_Type, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> operator + (const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CTreeIteratorConst<T_Type, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> operator - (const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CTreeIteratorConst<T_Type, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CTreeIteratorConst<T_Type, T_Allocator>::set(const CTreeIterator<T_Type, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_pContainer;
  m_cpNode = a_crInstance.m_pNode;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CTreeIteratorConst<T_Type, T_Allocator>::set(const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_cpContainer;
  m_cpNode = a_crInstance.m_cpNode;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::getForward() const
{ CALL
  CTreeIteratorConst<T_Type, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CTreeIteratorConst<T_Type, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::getBackward() const
{ CALL
  CTreeIteratorConst<T_Type, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CTreeIteratorConst<T_Type, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIteratorConst<T_Type, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && (m_cpNode != NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTreeIteratorConst<T_Type, T_Allocator>::isValidContainer() const
{ CALL
  return (m_cpContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline const CTree<T_Type, T_Allocator>& CTreeIteratorConst<T_Type, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline const CTree<T_Type, T_Allocator>* CTreeIteratorConst<T_Type, T_Allocator>::getContainerPtr() const
{ CALL
  return m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline const T_Type& CTreeIteratorConst<T_Type, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_cpNode->m_Item;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline const T_Type* CTreeIteratorConst<T_Type, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_cpNode->m_Item;
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIteratorConst<T_Type, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
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
inline Tuint CTreeIteratorConst<T_Type, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
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
inline Tbool CTreeIteratorConst<T_Type, T_Allocator>::isRoot() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator cannot be the root one."))
  {
    return false;
  }

  return (m_cpNode->m_pParent == NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::getRoot() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no root node."))
  {
    return CTreeIteratorConst<T_Type, T_Allocator>(m_cpContainer);
  }

  CTreeIteratorConst<T_Type, T_Allocator> it(m_cpContainer);

  it.m_cpNode = m_cpNode;
  while (it.m_cpNode->m_pParent != NULL)
    it.m_cpNode = it.m_cpNode->m_pParent;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::getParent() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no parent node."))
  {
    return CTreeIteratorConst<T_Type, T_Allocator>(m_cpContainer);
  }

  CTreeIteratorConst<T_Type, T_Allocator> it(m_cpContainer);

  it.m_cpNode = m_cpNode->m_pParent;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIteratorConst<T_Type, T_Allocator>::getSiblingIndex() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 0;
  const typename TContainer::STreeNode* temp = m_cpNode->m_pPrevSibling;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrevSibling;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIteratorConst<T_Type, T_Allocator>::getSiblingsCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 1;
  const typename TContainer::STreeNode* temp = m_cpNode->m_pPrevSibling;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrevSibling;
  }

  temp = m_cpNode->m_pNextSibling;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pNextSibling;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIteratorConst<T_Type, T_Allocator>::getPrevSiblingsCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 0;
  const typename TContainer::STreeNode* temp = m_cpNode->m_pPrevSibling;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pPrevSibling;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIteratorConst<T_Type, T_Allocator>::getNextSiblingsCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return 0;
  }

  Tuint index = 0;
  const typename TContainer::STreeNode* temp = m_cpNode->m_pNextSibling;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pNextSibling;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::getFirstSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return CTreeIteratorConst<T_Type, T_Allocator>(m_cpContainer);
  }

  CTreeIteratorConst<T_Type, T_Allocator> it(m_cpContainer);

  // Find first sibling.
  const typename TContainer::STreeNode* temp = m_cpNode;
  while (temp->m_pPrevSibling != NULL)
    temp = temp->m_pPrevSibling;
  it.m_cpNode = temp;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::getLastSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return CTreeIteratorConst<T_Type, T_Allocator>(m_cpContainer);
  }

  CTreeIteratorConst<T_Type, T_Allocator> it(m_cpContainer);

  // Find last sibling.
  const typename TContainer::STreeNode* temp = m_cpNode;
  while (temp->m_pNextSibling != NULL)
    temp = temp->m_pNextSibling;
  it.m_cpNode = temp;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::getPrevSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return CTreeIteratorConst<T_Type, T_Allocator>(m_cpContainer);
  }

  CTreeIteratorConst<T_Type, T_Allocator> it(m_cpContainer);

  it.m_cpNode = m_cpNode->m_pPrevSibling;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::getNextSibling() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return CTreeIteratorConst<T_Type, T_Allocator>(m_cpContainer);
  }

  CTreeIteratorConst<T_Type, T_Allocator> it(m_cpContainer);

  it.m_cpNode = m_cpNode->m_pNextSibling;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::getIndexSibling(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no siblings."))
  {
    return CTreeIteratorConst<T_Type, T_Allocator>(m_cpContainer);
  }

  CTreeIteratorConst<T_Type, T_Allocator> it(m_cpContainer);

  // Find first sibling.
  const typename TContainer::STreeNode* temp = m_cpNode;
  while (temp->m_pPrevSibling != NULL)
    temp = temp->m_pPrevSibling;
  // Indexing into siblings.
  Tuint count = a_cIndex;
  while ((count != 0) && (temp->m_pNextSibling != NULL))
  {
    --count;
    temp = temp->m_pNextSibling;
  }
  it.m_cpNode = (count == 0) ? temp : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTreeIteratorConst<T_Type, T_Allocator>::getChildCount() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no child."))
  {
    return 0;
  }

  Tuint index = 0;
  const typename TContainer::STreeNode* temp = m_cpNode->m_pFirstChild;
  while (temp != NULL)
  {
    ++index;
    temp = temp->m_pNextSibling;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::getFirstChild() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no child."))
  {
    return CTreeIteratorConst<T_Type, T_Allocator>(m_cpContainer);
  }

  CTreeIteratorConst<T_Type, T_Allocator> it(m_cpContainer);

  it.m_cpNode = m_cpNode->m_pFirstChild;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::getLastChild() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no child."))
  {
    return CTreeIteratorConst<T_Type, T_Allocator>(m_cpContainer);
  }

  CTreeIteratorConst<T_Type, T_Allocator> it(m_cpContainer);

  it.m_cpNode = m_cpNode->m_pLastChild;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTreeIteratorConst<T_Type, T_Allocator> CTreeIteratorConst<T_Type, T_Allocator>::getIndexChild(const Tuint a_cIndex) const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The invalid tree iterator has no child."))
  {
    return CTreeIteratorConst<T_Type, T_Allocator>(m_cpContainer);
  }

  CTreeIteratorConst<T_Type, T_Allocator> it(m_cpContainer);

  // Find indexed child.
  Tuint count = a_cIndex;
  const typename TContainer::STreeNode* temp = m_cpNode->m_pFirstChild;
  if (temp != NULL)
  {
    // Indexing into child.
    while ((count != 0) && (temp->m_pNextSibling != NULL))
    {
      --count;
      temp = temp->m_pNextSibling;
    }
  }
  it.m_cpNode = (count == 0) ? temp : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CTreeIteratorConst<T_Type, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Constant iterator value cannot be loaded."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CTreeIteratorConst<T_Type, T_Allocator>::save(T_Archive& a_rArchive) const
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
template <class T_Archive>
inline Tbool CTreeIteratorConst<T_Type, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CTreeIteratorConst<T_Type, T_Allocator>::swap(CTreeIteratorConst<T_Type, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_cpContainer, a_rInstance.m_cpContainer);
  NAlgorithms::NCommon::swap(m_cpNode, a_rInstance.m_cpNode);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
