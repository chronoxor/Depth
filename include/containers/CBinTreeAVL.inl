/*!
 *  \file    CBinTreeAVL.inl Template AVL balanced binary tree container
 *           class.
 *  \brief   Template AVL balanced binary tree container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template AVL balanced binary tree container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   29.08.2006 20:34:33

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
#ifndef __CBINTREEAVL_INL__
#define __CBINTREEAVL_INL__
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
inline CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeAVL(T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>(a_fLessThan, a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeAVL(const T_Type& a_crItem, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>(a_fLessThan, a_crAllocator)
{ CALL
  insert(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeAVL(const CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>(a_fLessThan, a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::~CBinTreeAVL()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::insertAndBalance(SBinTreeNode* a_pNode)
{ CALL
  setBalance(*a_pNode, 0);
  while (a_pNode->m_pParent != NULL)
  {
    // Rule 1.
    if (((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pLeft == a_pNode)) && (getBalance(*a_pNode->m_pParent) == 0))
    {
      setBalance(*a_pNode->m_pParent, -1);
      a_pNode = a_pNode->m_pParent;
      continue;
    }
    if (((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pRight == a_pNode)) && (getBalance(*a_pNode->m_pParent) == 0))
    {
      setBalance(*a_pNode->m_pParent, 1);
      a_pNode = a_pNode->m_pParent;
      continue;
    }
    // Rule 2.
    if (((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pLeft == a_pNode)) && (getBalance(*a_pNode->m_pParent) == 1))
    {
      setBalance(*a_pNode->m_pParent, 0);
      break;
    }
    if (((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pRight == a_pNode)) && (getBalance(*a_pNode->m_pParent) == -1))
    {
      setBalance(*a_pNode->m_pParent, 0);
      break;
    }
    // Rule 3.
    if (((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pLeft == a_pNode)) && (getBalance(*a_pNode->m_pParent) == -1))
    {
      if (getBalance(*a_pNode) == 1)
        rotateTwiceLeft(a_pNode->m_pParent);
      else
        rotateRight(a_pNode->m_pParent);
      break;
    }
    if (((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pRight == a_pNode)) && (getBalance(*a_pNode->m_pParent) == 1))
    {
      if (getBalance(*a_pNode) == -1)
        rotateTwiceRight(a_pNode->m_pParent);
      else
        rotateLeft(a_pNode->m_pParent);
      break;
    }
  }
  // Correct AVL balanced binary tree root.
  while (CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode()->m_pParent != NULL)
    CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode()->m_pParent;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::removeAndBalance(SBinTreeNode* a_pNode)
{ CALL
  SBinTreeNode* a;
  SBinTreeNode* b;
  SBinTreeNode* start;

  // If we want to delete the root item, we have to do some extra operation the preserve some pointers...
  if (a_pNode->m_pParent == NULL)
  {
    // The root is the only one node in the tree.
    if ((a_pNode->m_pLeft == NULL) && (a_pNode->m_pRight == NULL))
    {
      CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = NULL;
      return true;
    }
  }
  // Start node for the restructuration.
  start = NULL;
  // Removed node has no children.
  if ((a_pNode->m_pLeft == NULL) && (a_pNode->m_pRight == NULL))
  {
    if (a_pNode->m_pParent->m_pLeft == a_pNode)
      a_pNode->m_pParent->m_pLeft=NULL;
    else
      a_pNode->m_pParent->m_pRight=NULL;
    start = a_pNode->m_pParent;
    a_pNode = NULL;
  }
  // Removed node has only right son.
  if ((a_pNode != NULL) && (a_pNode->m_pLeft == NULL) && (a_pNode->m_pRight != NULL))
  {
    a = a_pNode->m_pRight;
    if (a_pNode->m_pParent == NULL)
      CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = a;
    SBinTreeNode::swap(a_pNode, a);
    NAlgorithms::NCommon::swap(a_pNode, a);
    a_pNode->m_pRight = NULL;
    start = a_pNode;
  }
  // Removed node has only left son.
  if ((a_pNode != NULL) && (a_pNode->m_pLeft != NULL) && (a_pNode->m_pRight == NULL))
  {
    a = a_pNode->m_pLeft;
    if (a_pNode->m_pParent == NULL)
      CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = a;
    SBinTreeNode::swap(a_pNode, a);
    NAlgorithms::NCommon::swap(a_pNode, a);
    a_pNode->m_pLeft = NULL;
    start = a_pNode;
  }
  // Removed node has both sons.
  if ((a_pNode != NULL) && (a_pNode->m_pLeft != NULL) && (a_pNode->m_pRight != NULL))
  {
    a = a_pNode->m_pLeft;
    while (a->m_pRight != NULL)
      a = a->m_pRight;
    b = a->m_pLeft;

    if (a_pNode->m_pParent == NULL)
      CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = a;
    SBinTreeNode::swap(a_pNode, a);
    NAlgorithms::NCommon::swap(a_pNode, a);

    if (b != NULL)
    {
      if (a->m_pParent == NULL)
        CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = b;
      SBinTreeNode::swap(a, b);
      NAlgorithms::NCommon::swap(a, b);
      a->m_pLeft = NULL;
      start = a;
    }
    else
    {
      if (a->m_pParent->m_pLeft == a)
        a->m_pParent->m_pLeft = NULL;
      else
        a->m_pParent->m_pRight = NULL;
      start = a->m_pParent;
    }
  }
  // Unlink given node.
  unlink(start);
  // Correct AVL balanced binary tree root.
  while (CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode()->m_pParent != NULL)
    CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode()->m_pParent;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::unlink(SBinTreeNode* a_pNode)
{ CALL
  // Rule 1.
  if ((getBalance(*a_pNode) == 0) && (a_pNode->m_pLeft == NULL))
  {
    setBalance(*a_pNode, 1);
    return;
  }
  if ((getBalance(*a_pNode) == 0) && (a_pNode->m_pRight == NULL))
  {
    setBalance(*a_pNode, -1);
    return;
  }
  // Rule 2.
  if ((getBalance(*a_pNode) == -1) && (a_pNode->m_pLeft == NULL))
    setBalance(*a_pNode, 0);
  if ((getBalance(*a_pNode) == 1) && (a_pNode->m_pRight == NULL))
    setBalance(*a_pNode, 0);
  // Rule 3.
  if ((getBalance(*a_pNode) == -1) && (a_pNode->m_pRight == NULL))
  {
    if (getBalance(*a_pNode->m_pLeft) == 1)
      rotateTwiceLeft(a_pNode);
    else
      rotateRight(a_pNode);
    a_pNode = a_pNode->m_pParent;
    if (getBalance(*a_pNode) == 1)
      return;
  }
  if ((getBalance(*a_pNode) == 1) && (a_pNode->m_pLeft == NULL))
  {
    if (getBalance(*a_pNode->m_pRight) == -1)
      rotateTwiceRight(a_pNode);
    else
      rotateLeft(a_pNode);
    a_pNode = a_pNode->m_pParent;
    if (getBalance(*a_pNode) == -1)
      return;
  }
  while (a_pNode->m_pParent != NULL)
  {
    // Rule 1.
    if (((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pLeft == a_pNode)) && (getBalance(*a_pNode->m_pParent) == 0))
    {
      setBalance(*a_pNode->m_pParent, 1);
      break;
    }
    if (((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pRight == a_pNode)) && (getBalance(*a_pNode->m_pParent) == 0))
    {
      setBalance(*a_pNode->m_pParent, -1);
      break;
    }
    // Rule 2.
    if (((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pLeft == a_pNode)) && (getBalance(*a_pNode->m_pParent) == -1))
    {
      setBalance(*a_pNode->m_pParent, 0);
      a_pNode = a_pNode->m_pParent;
      continue;
    }
    if (((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pRight == a_pNode)) && (getBalance(*a_pNode->m_pParent) == 1))
    {
      setBalance(*a_pNode->m_pParent, 0);
      a_pNode = a_pNode->m_pParent;
      continue;
    }
    // Rule 3.
    if (((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pRight == a_pNode)) && (getBalance(*a_pNode->m_pParent) == -1))
    {
      if (getBalance(*a_pNode->m_pParent->m_pLeft) == 1)
        rotateTwiceLeft(a_pNode->m_pParent);
      else
        rotateRight(a_pNode->m_pParent);
      a_pNode = a_pNode->m_pParent->m_pParent;
      if (getBalance(*a_pNode) == 1)
        return;
      continue;
    }
    if (((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pLeft == a_pNode)) && (getBalance(*a_pNode->m_pParent) == 1))
    {
      if (getBalance(*a_pNode->m_pParent->m_pRight) == -1)
        rotateTwiceRight(a_pNode->m_pParent);
      else
        rotateLeft(a_pNode->m_pParent);
      a_pNode = a_pNode->m_pParent->m_pParent;
      if (getBalance(*a_pNode) == -1)
        return;
      continue;
    }
    // Never appears...
    break;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::setBalance(SBinTreeNode& a_rNode, const Tsint a_cBalance)
{ CALL
  if (a_cBalance == 0)
    a_rNode.m_pData = (Tptr)0;
  else if (a_cBalance == -1)
    a_rNode.m_pData = (Tptr)-1;
  else
    a_rNode.m_pData = (Tptr)1;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tsint CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::getBalance(const SBinTreeNode& a_crNode)
{ CALL
  if (a_crNode.m_pData == (Tptr)0)
    return 0;
  else if (a_crNode.m_pData == (Tptr)-1)
    return -1;
  else
    return 1;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::rotateLeft(SBinTreeNode* a_pNode)
{ CALL
  if (a_pNode->m_pRight == NULL)
    return;

  SBinTreeNode* node = a_pNode->m_pRight;


  if (a_pNode->m_pParent != NULL)
  {
    if ((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pLeft == a_pNode))
      a_pNode->m_pParent->m_pLeft = node;
    else
      a_pNode->m_pParent->m_pRight = node;
    node->m_pParent = a_pNode->m_pParent;
  }
  else
    node->m_pParent = NULL;
  a_pNode->m_pRight = node->m_pLeft;
  node->m_pLeft = a_pNode;
  a_pNode->m_pParent = node;
  if (a_pNode->m_pRight != NULL)
    a_pNode->m_pRight->m_pParent = a_pNode;
  if (getBalance(*node) == 0)
  {
    setBalance(*a_pNode, 1);
    setBalance(*node, -1);
  }
  else
  {
    setBalance(*a_pNode, 0);
    setBalance(*node, 0);
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::rotateRight(SBinTreeNode* a_pNode)
{ CALL
  if (a_pNode->m_pLeft == NULL)
    return;

  SBinTreeNode* node = a_pNode->m_pLeft;

  if (a_pNode->m_pParent != NULL)
  {
    if ((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pLeft == a_pNode))
      a_pNode->m_pParent->m_pLeft = node;
    else
      a_pNode->m_pParent->m_pRight = node;
    node->m_pParent = a_pNode->m_pParent;
  }
  else
    node->m_pParent = NULL;
  a_pNode->m_pLeft = node->m_pRight;
  node->m_pRight = a_pNode;
  a_pNode->m_pParent = node;
  if (a_pNode->m_pLeft != NULL)
    a_pNode->m_pLeft->m_pParent = a_pNode;
  if (getBalance(*node) == 0)
  {
    setBalance(*a_pNode, -1);
    setBalance(*node, 1);
  }
  else
  {
    setBalance(*a_pNode, 0);
    setBalance(*node, 0);
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::rotateTwiceLeft(SBinTreeNode* a_pNode)
{ CALL
  if ((a_pNode->m_pLeft == NULL) || (a_pNode->m_pLeft->m_pRight == NULL))
    return;

  SBinTreeNode* node = a_pNode->m_pLeft;
  SBinTreeNode* node_next = a_pNode->m_pLeft->m_pRight;


  if (a_pNode->m_pParent != NULL)
  {
    if ((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pLeft == a_pNode))
      a_pNode->m_pParent->m_pLeft = node_next;
    else
      a_pNode->m_pParent->m_pRight = node_next;
  }
  node->m_pRight = node_next->m_pLeft;
  a_pNode->m_pLeft = node_next->m_pRight;
  node_next->m_pLeft = node;
  node_next->m_pRight = a_pNode;
  node_next->m_pParent = a_pNode->m_pParent;
  a_pNode->m_pParent = node_next;
  node->m_pParent = node_next;
  if (node->m_pRight != NULL)
    node->m_pRight->m_pParent = node;
  if (a_pNode->m_pLeft != NULL)
    a_pNode->m_pLeft->m_pParent = a_pNode;
  switch (getBalance(*node_next))
  {
    case -1:
    {
     setBalance(*a_pNode, 1);
     setBalance(*node, 0);
     break;
    }
    case 0:
    {
     setBalance(*a_pNode, 0);
     setBalance(*node, 0);
     break;
    }
    case 1:
    {
     setBalance(*a_pNode, 0);
     setBalance(*node, -1);
     break;
    }
  }
  setBalance(*node_next, 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::rotateTwiceRight(SBinTreeNode* a_pNode)
{ CALL
  if ((a_pNode->m_pRight == NULL) || (a_pNode->m_pRight->m_pLeft == NULL))
    return;

  SBinTreeNode* node = a_pNode->m_pRight;
  SBinTreeNode* node_next = a_pNode->m_pRight->m_pLeft;

  if (a_pNode->m_pParent != NULL)
  {
    if ((a_pNode->m_pParent != NULL) && (a_pNode->m_pParent->m_pLeft == a_pNode))
      a_pNode->m_pParent->m_pLeft = node_next;
    else
      a_pNode->m_pParent->m_pRight = node_next;
  }
  a_pNode->m_pRight = node_next->m_pLeft;
  node->m_pLeft = node_next->m_pRight;
  node_next->m_pLeft = a_pNode;
  node_next->m_pRight = node;
  node_next->m_pParent = a_pNode->m_pParent;
  a_pNode->m_pParent = node_next;
  node->m_pParent = node_next;
  if (a_pNode->m_pRight != NULL)
    a_pNode->m_pRight->m_pParent = a_pNode;
  if (node->m_pLeft != NULL)
    node->m_pLeft->m_pParent = node;
  switch (getBalance(*node_next))
  {
    case -1:
    {
     setBalance(*a_pNode, 0);
     setBalance(*node, 1);
     break;
    }
    case 0:
    {
     setBalance(*a_pNode, 0);
     setBalance(*node, 0);
     break;
    }
    case 1:
    {
     setBalance(*a_pNode, -1);
     setBalance(*node, 0);
     break;
    }
  }
  setBalance(*node_next, 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
template <class T_Archive>
inline Tbool CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CBinTree<T_Type, T_BinaryPredicate, T_Allocator>&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::swap(CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CBinTree<T_Type, T_BinaryPredicate, T_Allocator>&)(*this), (CBinTree<T_Type, T_BinaryPredicate, T_Allocator>&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
