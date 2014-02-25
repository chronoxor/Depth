/*!
 *  \file    CBinTree.inl Template non balanced binary tree container class.
 *  \brief   Template non balanced binary tree container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template non balanced binary tree container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   31.07.2006 20:31:28

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
#ifndef __CBINTREE_INL__
#define __CBINTREE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::SBinTreeItem::SBinTreeItem(const T_Type& a_crItem) :
  m_Item(a_crItem),
  m_pParent(NULL),
  m_pPrev(NULL),
  m_pNext(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::SBinTreeNode::SBinTreeNode(SBinTreeItem* a_pItem) :
  m_pFirstItem(a_pItem),
  m_pLastItem(a_pItem),
  m_pParent(NULL),
  m_pLeft(NULL),
  m_pRight(NULL),
  m_pData(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::SBinTreeNode::swap(SBinTreeNode* a_pNode1, SBinTreeNode* a_pNode2)
{ CALL
  SBinTreeNode* first_parent = a_pNode1->m_pParent;
  SBinTreeNode* first_left = a_pNode1->m_pLeft;
  SBinTreeNode* first_right = a_pNode1->m_pRight;
  SBinTreeNode* second_parent = a_pNode2->m_pParent;
  SBinTreeNode* second_left = a_pNode2->m_pLeft;
  SBinTreeNode* second_right = a_pNode2->m_pRight;
  Tbool first_is_left = ((first_parent != NULL) && (first_parent->m_pLeft == a_pNode1));
  Tbool second_is_left = ((second_parent != NULL) && (second_parent->m_pLeft == a_pNode2));

  // Update first node links.
  if (first_parent != NULL)
  {
    if (first_is_left)
      first_parent->m_pLeft = a_pNode2;
    else
      first_parent->m_pRight = a_pNode2;
  }
  if (first_left != NULL)
    first_left->m_pParent = a_pNode2;
  if (first_right != NULL)
    first_right->m_pParent = a_pNode2;
  // Update second node links.
  if (second_parent != NULL)
  {
    if (second_is_left)
      second_parent->m_pLeft = a_pNode1;
    else
      second_parent->m_pRight = a_pNode1;
  }
  if (second_left != NULL)
    second_left->m_pParent = a_pNode1;
  if (second_right != NULL)
    second_right->m_pParent = a_pNode1;
  // Swap node attributes.
  NAlgorithms::NCommon::swap(a_pNode1->m_pParent, a_pNode2->m_pParent);
  NAlgorithms::NCommon::swap(a_pNode1->m_pLeft, a_pNode2->m_pLeft);
  NAlgorithms::NCommon::swap(a_pNode1->m_pRight, a_pNode2->m_pRight);
  NAlgorithms::NCommon::swap(a_pNode1->m_pData, a_pNode2->m_pData);
}
/*==========================================================================*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::CBinTree(T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NContainers::ITreeConst<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >(),
  m_Size(0),
  m_pRoot(NULL),
  m_fLessThan(a_fLessThan),
  m_Allocator(a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::CBinTree(const T_Type& a_crItem, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NContainers::ITreeConst<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >(),
  m_Size(0),
  m_pRoot(NULL),
  m_fLessThan(a_fLessThan),
  m_Allocator(a_crAllocator)
{ CALL
  insert(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::CBinTree(const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >(),
  NCommon::NContainers::ITreeConst<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >(),
  m_Size(0),
  m_pRoot(NULL),
  m_fLessThan(a_fLessThan),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::~CBinTree()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::operator = (const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::operator += (const T_Type& a_crItem)
{ CALL
  insert(a_crItem);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::operator += (const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crBinTree)
{ CALL
  insert(a_crBinTree);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::operator -= (const T_Type& a_crItem)
{ CALL
  remove(a_crItem);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::operator -= (const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crBinTree)
{ CALL
  remove(a_crBinTree);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIterator CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::operator [] (const T_Type& a_crItem)
{ CALL
  return find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::operator [] (const T_Type& a_crItem) const
{ CALL
  return find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::set(const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CBinTree class instance."))
  {
    return false;
  }

  // Clear current tree.
  if (!clear())
    return false;

  TIteratorConst iterator = a_crInstance.getItFirst();

  // Copy all binary tree items.
  while (iterator.isValid())
  {
    // Copy next binary tree item.
    if (!insert(iterator.getValueRef()))
      return false;
    // Switch to the next binary tree item.
    if (iterator.stepForward() == 0)
      break;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::clear()
{ CALL
  if (isEmpty())
    return true;
  else
  {
    TIterator it(getItFirst());
    while (it.isValid())
      if (!it.remove())
        return false;
    return true;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pRoot == NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::insert(const T_Type& a_crItem)
{ CALL
  return getItFirstRoot().insert(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::insert(const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crBinTree)
{ CALL
  TIteratorConst it(a_crBinTree.getItFirst());
  if (it.isValid())
  {
    do
    {
      if (!insert(it.getValueRef()))
        return false;
    } while (it.stepForward() > 0);
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::remove(const T_Type& a_crItem, const Tbool a_cRemoveSame/* = false */)
{ CALL
  TIterator it(find(a_crItem));
  if (it.isValid())
  {
    if (a_cRemoveSame)
    {
      do
      {
        if (!it.remove())
          return false;
        if (it.isValid())
        {
          if (isLessThan(it.getValueRef(), a_crItem))
          {
            if (it.stepForward() != 1)
              break;
          }
          if (isLessThan(a_crItem, it.getValueRef()))
            break;
        }
      } while (it.isValid());
      return true;
    }
    else
      return it.remove();
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::remove(const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crBinTree, const Tbool a_cRemoveSame/* = false */)
{ CALL
  TIterator temp;
  TIteratorConst it(a_crBinTree.getItFirst());
  if (it.isValid())
  {
    do
    {
      temp = find(it.getValueRef());
      if (temp.isValid())
      {
        if (a_cRemoveSame)
        {
          do
          {
            if (!temp.remove())
              return false;
            if (temp.isValid())
            {
              if (isLessThan(temp.getValueRef(), it.getValueRef()))
              {
                if (temp.stepForward() != 1)
                  break;
              }
              if (isLessThan(it.getValueRef(), temp.getValueRef()))
                break;
            }
          } while (temp.isValid());
        }
        else
        {
          if (!temp.remove())
            return false;
        }
      }
    } while (it.stepForward() > 0);
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::isLessThan(const T_Type& a_crItem1, const T_Type& a_crItem2) const
{ CALL
  return m_fLessThan(a_crItem1, a_crItem2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIterator CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::find(const T_Type& a_crItem)
{ CALL
  TIterator it;

  // Filling iterator inner structure.
  it.m_pContainer = this;
  it.m_pNode = findAndBalance(a_crItem);
  it.m_pItem = (it.m_pNode != NULL) ? it.m_pNode->m_pFirstItem : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::find(const T_Type& a_crItem) const
{ CALL
  TIteratorConst it;

  // Filling iterator inner structure.
  it.m_cpContainer = this;
  it.m_cpNode = findAndBalance(a_crItem);
  it.m_cpItem = (it.m_cpNode != NULL) ? it.m_cpNode->m_pFirstItem : NULL;
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIterator CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItFirst()
{ CALL
  TIterator first_iterator;

  // Find binary tree's begin node.
  SBinTreeNode* begin = m_pRoot;
  if (begin != NULL)
    while (begin->m_pLeft != NULL)
      begin = begin->m_pLeft;
  // Filling iterator inner structure.
  first_iterator.m_pContainer = this;
  first_iterator.m_pNode = begin;
  first_iterator.m_pItem = (begin != NULL) ? begin->m_pFirstItem : NULL;
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItFirst() const
{ CALL
  TIteratorConst first_iterator;

  // Find binary tree's begin node.
  const SBinTreeNode* begin = m_pRoot;
  if (begin != NULL)
    while (begin->m_pLeft != NULL)
      begin = begin->m_pLeft;
  // Filling iterator inner structure.
  first_iterator.m_cpContainer = this;
  first_iterator.m_cpNode = begin;
  first_iterator.m_cpItem = (begin != NULL) ? begin->m_pFirstItem : NULL;
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIterator CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItLast()
{ CALL
  TIterator last_iterator;

  // Find binary tree's end node.
  SBinTreeNode* end = m_pRoot;
  if (end != NULL)
    while (end->m_pRight != NULL)
      end = end->m_pRight;
  // Filling iterator inner structure.
  last_iterator.m_pContainer = this;
  last_iterator.m_pNode = end;
  last_iterator.m_pItem = (end != NULL) ? end->m_pLastItem : NULL;
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItLast() const
{ CALL
  TIteratorConst last_iterator;

  // Find binary tree's end node.
  const SBinTreeNode* end = m_pRoot;
  if (end != NULL)
    while (end->m_pRight != NULL)
      end = end->m_pRight;
  // Filling iterator inner structure.
  last_iterator.m_cpContainer = this;
  last_iterator.m_cpNode = end;
  last_iterator.m_cpItem = (end != NULL) ? end->m_pLastItem : NULL;
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootCount() const
{ CALL
  return (isEmpty() ? 0 : getItFirstRoot().getSiblingsCount());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIterator CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItFirstRoot()
{ CALL
  TIterator first_root_iterator;

  // Filling iterator inner structure.
  first_root_iterator.m_pContainer = this;
  first_root_iterator.m_pNode = m_pRoot;
  first_root_iterator.m_pItem = (m_pRoot != NULL) ? m_pRoot->m_pFirstItem : NULL;
  return first_root_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItFirstRoot() const
{ CALL
  TIteratorConst first_root_iterator;

  // Filling iterator inner structure.
  first_root_iterator.m_cpContainer = this;
  first_root_iterator.m_cpNode = m_pRoot;
  first_root_iterator.m_cpItem = (m_pRoot != NULL) ? m_pRoot->m_pFirstItem : NULL;
  return first_root_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIterator CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItLastRoot()
{ CALL
  TIterator last_root_iterator;

  // Filling iterator inner structure.
  last_root_iterator.m_pContainer = this;
  last_root_iterator.m_pNode = m_pRoot;
  last_root_iterator.m_pItem = (m_pRoot != NULL) ? m_pRoot->m_pLastItem : NULL;
  return last_root_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItLastRoot() const
{ CALL
  TIteratorConst last_root_iterator;

  // Filling iterator inner structure.
  last_root_iterator.m_cpContainer = this;
  last_root_iterator.m_cpNode = m_pRoot;
  last_root_iterator.m_cpItem = (m_pRoot != NULL) ? m_pRoot->m_pLastItem : NULL;
  return last_root_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIterator CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItIndexRoot(const Tuint a_cIndex)
{ CALL
  Tuint count = a_cIndex + 1;
  TIterator it_index_root;

  // Find indexed root node.
  SBinTreeNode* node = m_pRoot;
  SBinTreeItem* item = (m_pRoot != NULL) ? m_pRoot->m_pFirstItem : NULL;
  if (item != NULL)
    while ((--count > 0) && (item->m_pNext != NULL))
      item = item->m_pNext;
  // Filling iterator inner structure.
  it_index_root.m_pContainer = this;
  it_index_root.m_pNode = ((count > 0) ? NULL : node);
  it_index_root.m_pItem = ((count > 0) ? NULL : item);
  return it_index_root;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItIndexRoot(const Tuint a_cIndex) const
{ CALL
  Tuint count = a_cIndex + 1;
  TIteratorConst it_index_root;

  // Find indexed root node.
  const SBinTreeNode* node = m_pRoot;
  const SBinTreeItem* item = (m_pRoot != NULL) ? m_pRoot->m_pFirstItem : NULL;
  if (item != NULL)
    while ((--count > 0) && (item->m_pNext != NULL))
      item = item->m_pNext;
  // Filling iterator inner structure.
  it_index_root.m_cpContainer = this;
  it_index_root.m_cpNode = ((count > 0) ? NULL : node);
  it_index_root.m_cpItem = ((count > 0) ? NULL : item);
  return it_index_root;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIterator CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItLeftmostChild()
{ CALL
  return getItFirst();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItLeftmostChild() const
{ CALL
  return getItFirst();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIterator CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItRightmostChild()
{ CALL
  return getItLast();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getItRightmostChild() const
{ CALL
  return getItLast();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::SBinTreeNode* CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::findAndBalance(const T_Type& a_crItem) const
{ CALL
  SBinTreeNode* node = NAlgorithms::NCommon::constCast<SBinTreeNode*>(m_pRoot);

  // Perform binary tree search from root node.
  while ((node != NULL) && (node->m_pFirstItem != NULL))
  {
    // Choose next search step.
    if (!isLessThan(node->m_pFirstItem->m_Item, a_crItem))
    {
      if (!isLessThan(a_crItem, node->m_pFirstItem->m_Item))
        return node;
      // Next posible node is the left child.
      node = node->m_pLeft;
    }
    else
    {
      // Next posible node is the right child.
      node = node->m_pRight;
    }
  }
  // If we found nothing, than return NULL.
  return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::insertAndBalance(SBinTreeNode* a_pNode)
{ CALL
  IGNORE_UNUSED(a_pNode);

  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::removeAndBalance(SBinTreeNode* a_pNode)
{ CALL
  // Binary tree node without left child.
  if (a_pNode->m_pLeft == NULL)
  {
    if (a_pNode->m_pParent != NULL)
    {
      if (a_pNode->m_pParent->m_pLeft == a_pNode)
        a_pNode->m_pParent->m_pLeft = a_pNode->m_pRight;
      else
        a_pNode->m_pParent->m_pRight = a_pNode->m_pRight;
    }
    else
      m_pRoot = a_pNode->m_pRight;
    if (a_pNode->m_pRight != NULL)
      a_pNode->m_pRight->m_pParent = a_pNode->m_pParent;
    return true;
  }
  // Binary tree node without right child.
  if (a_pNode->m_pRight == NULL)
  {
    if (a_pNode->m_pParent != NULL)
    {
     if (a_pNode->m_pParent->m_pLeft == a_pNode)
      a_pNode->m_pParent->m_pLeft = a_pNode->m_pLeft;
     else
      a_pNode->m_pParent->m_pRight = a_pNode->m_pLeft;
    }
    else
     m_pRoot = a_pNode->m_pLeft;
    if (a_pNode->m_pLeft != NULL)
     a_pNode->m_pLeft->m_pParent = a_pNode->m_pParent;
    return true;
  }
  // Binary tree node with left and right child.
  if (a_pNode->m_pParent != NULL)
  {
    if (a_pNode->m_pParent->m_pLeft == a_pNode)
     a_pNode->m_pParent->m_pLeft = a_pNode->m_pLeft;
    else
     a_pNode->m_pParent->m_pRight = a_pNode->m_pLeft;
  }
  else
   m_pRoot = a_pNode->m_pLeft;
  // Find new base node.
  SBinTreeNode* temp = a_pNode->m_pLeft;
  while (temp->m_pRight != NULL)
    temp = temp->m_pRight;
  temp->m_pRight = a_pNode->m_pRight;
  a_pNode->m_pRight->m_pParent = temp;
  a_pNode->m_pLeft->m_pParent = a_pNode->m_pParent;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::SBinTreeNode*& CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode()
{ CALL
  return m_pRoot;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::SBinTreeNode* const& CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() const
{ CALL
  return m_pRoot;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
template <class T_Archive>
inline Tbool CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Clear the current binary tree.
  CHECK(clear());

  // Load the binary tree header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CBinTree<T_Type, T_BinaryPredicate, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the binary tree 'LessThan' binary predicate.
  CHECK(a_rArchive.doValue(m_fLessThan, STR("m_fLessThan")));

  // Load the binary tree content.
  while (size-- > 0)
  {
    T_Type item;

    // Load next binary tree item.
    CHECK(a_rArchive.doValue(item, STR("item")));
    // Insert next item into the binary tree.
    CHECK(insert(item));
  }

  // Load the binary tree end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
template <class T_Archive>
inline Tbool CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the binary tree header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CBinTree<T_Type, T_BinaryPredicate, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the binary tree 'LessThan' binary predicate.
  CHECK(a_rArchive.doValue(m_fLessThan, STR("m_fLessThan")));

  // Save the binary tree content.
  if (!isEmpty())
  {
    TIteratorConst iterator = getItFirst();

    // Save all binary tree items.
    while (iterator.isValid())
    {
      // Save next binary tree item.
      CHECK(a_rArchive.doValue(iterator.getValueRef(), STR("item")));
      // Switch to the next binary tree item.
      if (iterator.stepForward() == 0)
        break;
    }
  }

  // Save the binary tree end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
template <class T_Archive>
inline Tbool CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::swap(CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
  NAlgorithms::NCommon::swap(m_pRoot, a_rInstance.m_pRoot);
  NAlgorithms::NCommon::swap(m_fLessThan, a_rInstance.m_fLessThan);
  NAlgorithms::NCommon::swap(m_Allocator, a_rInstance.m_Allocator);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
