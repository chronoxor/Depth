/*!
 *  \file    CTree.inl Template tree container class. Tree represents
 *           container that can keep items in a tree-based form.
 *  \brief   Template tree container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template tree container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   20.06.2006 00:43:58

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
#ifndef __CTREE_INL__
#define __CTREE_INL__
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
inline CTree<T_Type, T_Allocator>::STreeNode::STreeNode(const T_Type& a_crItem) :
  m_Item(a_crItem),
  m_pParent(NULL),
  m_pPrevSibling(NULL),
  m_pNextSibling(NULL),
  m_pFirstChild(NULL),
  m_pLastChild(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTree<T_Type, T_Allocator>::STreeNode::getAllCount() const
{ CALL
  Tuint result = 1;
  STreeNode* child = m_pFirstChild;
  while (child != NULL)
  {
    result += child->getAllCount();
    child = child->m_pNextSibling;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTree<T_Type, T_Allocator>::STreeNode::getChildCount() const
{ CALL
  Tuint result = 0;
  STreeNode* child = m_pFirstChild;
  while (child != NULL)
  {
    ++result;
    child = child->m_pNextSibling;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CTree<T_Type, T_Allocator>::STreeNode::link(STreeNode* a_pParent, STreeNode* a_pChild)
{ CALL
  // Update parent node.
  m_pParent = a_pParent;
  if (a_pParent != NULL)
  {
    if (a_pParent->m_pFirstChild == a_pChild)
      a_pParent->m_pFirstChild = this;
    if (a_pParent->m_pLastChild == a_pChild)
      a_pParent->m_pLastChild = this;
  }
  // Update sibling nodes.
  if (a_pChild != NULL)
  {
    if (a_pChild->m_pPrevSibling != NULL)
      a_pChild->m_pPrevSibling->m_pNextSibling = this;
    if (a_pChild->m_pNextSibling != NULL)
      a_pChild->m_pNextSibling->m_pPrevSibling = this;
    m_pPrevSibling = a_pChild->m_pPrevSibling;
    m_pNextSibling = a_pChild->m_pNextSibling;
    a_pChild->m_pPrevSibling = NULL;
    a_pChild->m_pNextSibling = NULL;
  }
  // Update child node.
  m_pFirstChild = a_pChild;
  m_pLastChild = a_pChild;
  if (a_pChild != NULL)
    a_pChild->m_pParent = this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CTree<T_Type, T_Allocator>::STreeNode::link(STreeNode* a_pParent, STreeNode* a_pPrevSibling, STreeNode* a_pNextSibling, STreeNode* a_pNewFirstSibling, STreeNode* a_pNewLastSibling)
{ CALL
  // Update parent node.
  STreeNode* sibling = a_pNewFirstSibling;
  while (sibling != NULL)
  {
    sibling->m_pParent = a_pParent;
    if (sibling != a_pNewLastSibling)
      sibling = sibling->m_pNextSibling;
    else
      break;
  }
  if (a_pParent != NULL)
  {
    if (a_pPrevSibling == NULL)
      a_pParent->m_pFirstChild = a_pNewFirstSibling;
    if (a_pNextSibling == NULL)
      a_pParent->m_pLastChild = a_pNewLastSibling;
  }
  // Update previous sibling node.
  if (a_pNewFirstSibling != NULL)
    a_pNewFirstSibling->m_pPrevSibling = a_pPrevSibling;
  if (a_pPrevSibling != NULL)
    a_pPrevSibling->m_pNextSibling = a_pNewFirstSibling;
  // Update next sibling node.
  if (a_pNewLastSibling != NULL)
    a_pNewLastSibling->m_pNextSibling = a_pNextSibling;
  if (a_pNextSibling != NULL)
    a_pNextSibling->m_pPrevSibling = a_pNewLastSibling;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CTree<T_Type, T_Allocator>::STreeNode::unlink(STreeNode* a_pParent, STreeNode* a_pPrevSibling, STreeNode* a_pNextSibling)
{ CALL
  // Update parent node.
  if (a_pParent != NULL)
  {
    if (a_pPrevSibling == NULL)
      a_pParent->m_pFirstChild = a_pNextSibling;
    if (a_pNextSibling == NULL)
      a_pParent->m_pLastChild = a_pPrevSibling;
  }
  // Update previous sibling node.
  if (a_pPrevSibling != NULL)
    a_pPrevSibling->m_pNextSibling = a_pNextSibling;
  // Update next sibling node.
  if (a_pNextSibling != NULL)
    a_pNextSibling->m_pPrevSibling = a_pPrevSibling;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::STreeNode::copy(CTree<T_Type, T_Allocator>* a_pTree, STreeNode* a_pDstNode, const STreeNode* a_cpSrcNode)
{ CALL
  // Filling iterator inner structure.
  TIterator iterator;
  iterator.m_pContainer = a_pTree;
  iterator.m_pNode = a_pDstNode;

  // Copy all child items.
  const STreeNode* child = a_cpSrcNode->m_pFirstChild;
  while (child != NULL)
  {
    // Insert new tree root node.
    if (!iterator.insertLastChild(child->m_Item))
      return false;
    // Copy child nodes.
    if (!STreeNode::copy(a_pTree, iterator.m_pNode->m_pLastChild, child))
      return false;
    // Switch to the next sibling node.
    child = child->m_pNextSibling;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CTree<T_Type, T_Allocator>::STreeNode::load(T_Archive& a_rArchive, CTree<T_Type, T_Allocator>* a_pTree, STreeNode* a_pParentNode)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the given tree is valid.
  ASSERT((a_pTree != NULL), STR("Cannot load invalid tree container."))
  {
    return false;
  }

  T_Type item;
  Tuint child = 0;

  // Load the tree node header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("node")));
    CHECK(a_rArchive.doProperty(child, STR("child")));
  CHECK(a_rArchive.body());

  // Load tree node item value.
  CHECK(a_rArchive.doValue(item, STR("item")));

  // Insert current tree node.
  TIterator iterator;
  if (a_pParentNode == NULL)
  {
    iterator = a_pTree->getItLastRoot();
    CHECK(iterator.insertLastSibling(item, true));
  }
  else
  {
    // Filling iterator inner structure.
    iterator.m_pContainer = a_pTree;
    iterator.m_pNode = a_pParentNode;
    // Insert new sibling node.
    CHECK(iterator.insertLastChild(item, true));
  }

  // Load the tree node childs.
  while (child-- > 0)
  {
    // Load root sibling item.
    CHECK(STreeNode::load(a_rArchive, a_pTree, iterator.m_pNode));
  }

  // Load the tree node end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CTree<T_Type, T_Allocator>::STreeNode::save(T_Archive& a_rArchive, const CTree<T_Type, T_Allocator>* a_cpTree, const STreeNode* a_cpNode)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the given tree is valid.
  ASSERT((a_cpTree != NULL), STR("Cannot save invalid tree container."))
  {
    return false;
  }
  // Check if the given tree node is valid.
  ASSERT((a_cpNode != NULL), STR("Cannot save invalid tree node."))
  {
    return false;
  }

  Tuint child = a_cpNode->getChildCount();

  // Save the tree node header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("node")));
    CHECK(a_rArchive.doProperty(child, STR("child")));
  CHECK(a_rArchive.body());

  // Save tree node item value.
  CHECK(a_rArchive.doValue(a_cpNode->m_Item, STR("item")));

  // Filling iterator inner structure.
  TIteratorConst iterator;
  iterator.m_cpContainer = a_cpTree;
  iterator.m_cpNode = a_cpNode->m_pFirstChild;

  // Save child items.
  while (iterator.m_cpNode != NULL)
  {
    // Save child item.
    CHECK(STreeNode::save(a_rArchive, a_cpTree, iterator.m_cpNode));
    // Switch to the next child item.
    iterator.m_cpNode = iterator.m_cpNode->m_pNextSibling;
  }

  // Save the tree node end.
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
template <typename T_Type, class T_Allocator>
inline CTree<T_Type, T_Allocator>::CTree(const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::ITree<CTree<T_Type, T_Allocator>, T_Type,  CTreeIterator<T_Type, T_Allocator>, CTreeIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::ITreeConst<CTree<T_Type, T_Allocator>, T_Type,  CTreeIterator<T_Type, T_Allocator>, CTreeIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pFirstRoot(NULL),
  m_pLastRoot(NULL),
  m_Allocator(a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTree<T_Type, T_Allocator>::CTree(const T_Type& a_crItem, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::ITree<CTree<T_Type, T_Allocator>, T_Type,  CTreeIterator<T_Type, T_Allocator>, CTreeIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::ITreeConst<CTree<T_Type, T_Allocator>, T_Type,  CTreeIterator<T_Type, T_Allocator>, CTreeIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pFirstRoot(NULL),
  m_pLastRoot(NULL),
  m_Allocator(a_crAllocator)
{ CALL
  insertFirstRoot(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTree<T_Type, T_Allocator>::CTree(const CTree<T_Type, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::ITree<CTree<T_Type, T_Allocator>, T_Type,  CTreeIterator<T_Type, T_Allocator>, CTreeIteratorConst<T_Type, T_Allocator> >(),
  NCommon::NContainers::ITreeConst<CTree<T_Type, T_Allocator>, T_Type,  CTreeIterator<T_Type, T_Allocator>, CTreeIteratorConst<T_Type, T_Allocator> >(),
  m_Size(0),
  m_pFirstRoot(NULL),
  m_pLastRoot(NULL),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTree<T_Type, T_Allocator>::~CTree()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CTree<T_Type, T_Allocator>& CTree<T_Type, T_Allocator>::operator = (const CTree<T_Type, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::set(const CTree<T_Type, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CTree class instance."))
  {
    return false;
  }

  // Clear current tree.
  if (!clear())
    return false;

  TIterator iterator = getItFirstRoot();
  const STreeNode* root = a_crInstance.m_pFirstRoot;

  // Copy all root items.
  while (root != NULL)
  {
    // Insert new tree root node.
    if (!iterator.insertForward(root->m_Item))
      return false;
    // Copy child nodes.
    if (!STreeNode::copy(this, iterator.m_pNode, root))
      return false;
    // Switch to the next sibling node.
    root = root->m_pNextSibling;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::clear()
{ CALL
  // Remove all tree root nodes.
  return getItFirstRoot().removeAllSiblings();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pFirstRoot == NULL) || (m_pLastRoot == NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTree<T_Type, T_Allocator>::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::insertFirstRoot(const T_Type& a_crItem)
{ CALL
  return getItFirstRoot().insertFirstSibling(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::insertLastRoot(const T_Type& a_crItem)
{ CALL
  return getItLastRoot().insertLastSibling(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::insertIndexRoot(const Tuint a_cIndex, const T_Type& a_crItem)
{ CALL
  return getItFirstRoot().insertIndexSibling(a_cIndex, a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::insertSubTreeFirstRoot(CTree<T_Type, T_Allocator>& a_rSubTree)
{ CALL
  return getItFirstRoot().insertSubTreeFirstSibling(a_rSubTree);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::insertSubTreeLastRoot(CTree<T_Type, T_Allocator>& a_rSubTree)
{ CALL
  return getItLastRoot().insertSubTreeLastSibling(a_rSubTree);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::insertSubTreeIndexRoot(const Tuint a_cIndex, CTree<T_Type, T_Allocator>& a_rSubTree)
{ CALL
  return getItFirstRoot().insertSubTreeIndexSibling(a_cIndex, a_rSubTree);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::removeFirstRoot()
{ CALL
  return getItFirstRoot().removeForward();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::removeFirstRoot(T_Type& a_rItem)
{ CALL
  return getItFirstRoot().removeForward(a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::removeLastRoot()
{ CALL
  return getItLastRoot().removeBackward();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::removeLastRoot(T_Type& a_rItem)
{ CALL
  return getItLastRoot().removeBackward(a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::removeIndexRoot(const Tuint a_cIndex)
{ CALL
  return getItFirstRoot().removeIndexSibling(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CTree<T_Type, T_Allocator>::removeIndexRoot(const Tuint a_cIndex, T_Type& a_rItem)
{ CALL
  return getItFirstRoot().removeIndexSibling(a_cIndex, a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTree<T_Type, T_Allocator>::subTreeFirstRoot(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_NextSiblingCount/* = 0 */)
{ CALL
  return getItFirstRoot().subTreeForwardSibling(a_rSubTree, a_NextSiblingCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTree<T_Type, T_Allocator>::subTreeLastRoot(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount/* = 0 */)
{ CALL
  return getItLastRoot().subTreeBackwardSibling(a_rSubTree, a_PrevSiblingCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTree<T_Type, T_Allocator>::subTreeIndexRoot(const Tuint a_cIndex, CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount/* = 0 */, const Tuint a_NextSiblingCount/* = 0 */)
{ CALL
  return getItFirstRoot().subTreeIndexSibling(a_cIndex, a_rSubTree, a_PrevSiblingCount, a_NextSiblingCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CTree<T_Type, T_Allocator>::getRootCount() const
{ CALL
  return (isEmpty() ? 0 : getItFirstRoot().getSiblingsCount());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CTree<T_Type, T_Allocator>::TIterator CTree<T_Type, T_Allocator>::getItFirstRoot()
{ CALL
  TIterator it_first_root;

  // Filling iterator inner structure.
  it_first_root.m_pContainer = this;
  it_first_root.m_pNode = m_pFirstRoot;
  return it_first_root;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CTree<T_Type, T_Allocator>::TIteratorConst CTree<T_Type, T_Allocator>::getItFirstRoot() const
{ CALL
  TIteratorConst it_first_root;

  // Filling iterator inner structure.
  it_first_root.m_cpContainer = this;
  it_first_root.m_cpNode = m_pFirstRoot;
  return it_first_root;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CTree<T_Type, T_Allocator>::TIterator CTree<T_Type, T_Allocator>::getItLastRoot()
{ CALL
  TIterator it_last_root;

  // Filling iterator inner structure.
  it_last_root.m_pContainer = this;
  it_last_root.m_pNode = m_pLastRoot;
  return it_last_root;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CTree<T_Type, T_Allocator>::TIteratorConst CTree<T_Type, T_Allocator>::getItLastRoot() const
{ CALL
  TIteratorConst it_last_root;

  // Filling iterator inner structure.
  it_last_root.m_cpContainer = this;
  it_last_root.m_cpNode = m_pLastRoot;
  return it_last_root;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CTree<T_Type, T_Allocator>::TIterator CTree<T_Type, T_Allocator>::getItIndexRoot(const Tuint a_cIndex)
{ CALL
  Tuint count = a_cIndex + 1;
  TIterator it_index_root;

  // Find indexed root node.
  STreeNode* index = m_pFirstRoot;
  if (index != NULL)
    while ((--count > 0) && (index->m_pNextSibling != NULL))
      index = index->m_pNextSibling;
  // Filling iterator inner structure.
  it_index_root.m_pContainer = this;
  it_index_root.m_pNode = ((count > 0) ? NULL : index);
  return it_index_root;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CTree<T_Type, T_Allocator>::TIteratorConst CTree<T_Type, T_Allocator>::getItIndexRoot(const Tuint a_cIndex) const
{ CALL
  Tuint count = a_cIndex + 1;
  TIteratorConst it_index_root;

  // Find indexed root node.
  const STreeNode* index = m_pFirstRoot;
  if (index != NULL)
    while ((--count > 0) && (index->m_pNextSibling != NULL))
      index = index->m_pNextSibling;
  // Filling iterator inner structure.
  it_index_root.m_cpContainer = this;
  it_index_root.m_cpNode = ((count > 0) ? NULL : index);
  return it_index_root;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CTree<T_Type, T_Allocator>::TIterator CTree<T_Type, T_Allocator>::getItLeftmostChild()
{ CALL
  TIterator it_leftmost_child;

  // Find tree's leftmost child node.
  STreeNode* begin = m_pFirstRoot;
  if (begin != NULL)
    while (begin->m_pFirstChild != NULL)
      begin = begin->m_pFirstChild;
  // Filling iterator inner structure.
  it_leftmost_child.m_pContainer = this;
  it_leftmost_child.m_pNode = begin;
  return it_leftmost_child;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CTree<T_Type, T_Allocator>::TIteratorConst CTree<T_Type, T_Allocator>::getItLeftmostChild() const
{ CALL
  TIteratorConst it_leftmost_child;

  // Find tree's leftmost child node.
  const STreeNode* begin = m_pFirstRoot;
  if (begin != NULL)
    while (begin->m_pFirstChild != NULL)
      begin = begin->m_pFirstChild;
  // Filling iterator inner structure.
  it_leftmost_child.m_cpContainer = this;
  it_leftmost_child.m_cpNode = begin;
  return it_leftmost_child;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CTree<T_Type, T_Allocator>::TIterator CTree<T_Type, T_Allocator>::getItRightmostChild()
{ CALL
  TIterator it_rightmost_child;

  // Find tree's rightmost child node.
  STreeNode* end = m_pLastRoot;
  if (end != NULL)
    while (end->m_pLastChild != NULL)
      end = end->m_pLastChild;
  // Filling iterator inner structure.
  it_rightmost_child.m_pContainer = this;
  it_rightmost_child.m_pNode = end;
  return it_rightmost_child;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline typename CTree<T_Type, T_Allocator>::TIteratorConst CTree<T_Type, T_Allocator>::getItRightmostChild() const
{ CALL
  TIteratorConst it_rightmost_child;

  // Find tree's rightmost child node.
  const STreeNode* end = m_pLastRoot;
  if (end != NULL)
    while (end->m_pLastChild != NULL)
      end = end->m_pLastChild;
  // Filling iterator inner structure.
  it_rightmost_child.m_cpContainer = this;
  it_rightmost_child.m_cpNode = end;
  return it_rightmost_child;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CTree<T_Type, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;
  Tuint roots = 0;

  // Clear the current tree.
  CHECK(clear());

  // Load the tree header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CTree<T_Type, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
    CHECK(a_rArchive.doProperty(roots, STR("roots")));
  CHECK(a_rArchive.body());

  // Load the tree content.
  if (size > 0)
  {
    // Load root siblings items.
    while (roots-- > 0)
    {
      // Load root sibling item.
      CHECK(STreeNode::load(a_rArchive, this, NULL));
    }
  }

  // Load the tree end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CTree<T_Type, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the tree header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CTree<T_Type, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
    CHECK(a_rArchive.doProperty(getRootCount(), STR("roots")));
  CHECK(a_rArchive.body());

  // Save the tree content.
  if (!isEmpty())
  {
    TIteratorConst iterator = getItFirstRoot();

    // Save root siblings items.
    while (iterator.m_cpNode != NULL)
    {
      // Save root sibling item.
      CHECK(STreeNode::save(a_rArchive, this, iterator.m_cpNode));
      // Switch to the next root sibling item.
      iterator.m_cpNode = iterator.m_cpNode->m_pNextSibling;
    }
  }

  // Save the tree end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CTree<T_Type, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CTree<T_Type, T_Allocator>::swap(CTree<T_Type, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
  NAlgorithms::NCommon::swap(m_pFirstRoot, a_rInstance.m_pFirstRoot);
  NAlgorithms::NCommon::swap(m_pLastRoot, a_rInstance.m_pLastRoot);
  NAlgorithms::NCommon::swap(m_Allocator, a_rInstance.m_Allocator);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
