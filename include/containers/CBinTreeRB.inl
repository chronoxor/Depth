/*!
 *  \file    CBinTreeRB.inl Template red-black balanced binary tree container
 *           class.
 *  \brief   Template red-black balanced binary tree container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template red-back balanced binary tree container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   29.08.2006 00:00:26

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
#ifndef __CBINTREERB_INL__
#define __CBINTREERB_INL__
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
inline CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeRB(T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>(a_fLessThan, a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeRB(const T_Type& a_crItem, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>(a_fLessThan, a_crAllocator)
{ CALL
  insert(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeRB(const CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>(a_fLessThan, a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::~CBinTreeRB()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::insertAndBalance(SBinTreeNode* a_pNode)
{ CALL
  // Set red color for new red-black balanced binary tree node.
  setRed(*a_pNode);
  // Check red-black properties.
  while ((a_pNode->m_pParent != NULL) && isRed(*a_pNode->m_pParent))
  {
    // We have a violation.
    if (a_pNode->m_pParent == a_pNode->m_pParent->m_pParent->m_pLeft)
    {
      SBinTreeNode* uncle = a_pNode->m_pParent->m_pParent->m_pRight;
      if ((uncle != NULL) && isRed(*uncle))
      {
        // Uncle is red.
        setBlack(*a_pNode->m_pParent);
        setBlack(*uncle);
        setRed(*a_pNode->m_pParent->m_pParent);
        a_pNode = a_pNode->m_pParent->m_pParent;
      }
      else
      {
        // Uncle is back.
        if (a_pNode == a_pNode->m_pParent->m_pRight)
        {
          // Make node a left child.
          a_pNode = a_pNode->m_pParent;
          rotateLeft(a_pNode);
        }
        // Recolor and rotate.
        setBlack(*a_pNode->m_pParent);
        setRed(*a_pNode->m_pParent->m_pParent);
        rotateRight(a_pNode->m_pParent->m_pParent);
      }
    }
    else
    {
      // Mirror image of above code.
      SBinTreeNode* uncle = a_pNode->m_pParent->m_pParent->m_pLeft;
      if ((uncle != NULL) && isRed(*uncle))
      {
        // Uncle is red.
        setBlack(*a_pNode->m_pParent);
        setBlack(*uncle);
        setRed(*a_pNode->m_pParent->m_pParent);
        a_pNode = a_pNode->m_pParent->m_pParent;
      }
      else
      {
        // Uncle is black.
        if (a_pNode == a_pNode->m_pParent->m_pLeft)
        {
          a_pNode = a_pNode->m_pParent;
          rotateRight(a_pNode);
        }
        setBlack(*a_pNode->m_pParent);
        setRed(*a_pNode->m_pParent->m_pParent);
        rotateLeft(a_pNode->m_pParent->m_pParent);
      }
    }
  }
  setBlack(*CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::removeAndBalance(SBinTreeNode* a_pNode)
{ CALL
  SBinTreeNode* x;
  SBinTreeNode* y;

  if ((a_pNode->m_pLeft == NULL) || (a_pNode->m_pRight == NULL))
  {
    // y has a NULL node as a child.
    y = a_pNode;
  }
  else
  {
    // Find tree successor with a NULL node as a child.
    y = a_pNode->m_pRight;
    while (y->m_pLeft != NULL)
      y = y->m_pLeft;
  }
  // Swap two nodes.
  if (y != a_pNode)
  {
    if (a_pNode->m_pParent == NULL)
      CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = y;
    SBinTreeNode::swap(a_pNode, y);
    NAlgorithms::NCommon::swap(a_pNode, y);
  }
  // x is y's only child.
  if (y->m_pLeft != NULL)
    x = y->m_pLeft;
  else
    x = y->m_pRight;
  // Remove y from the parent chain.
  if (x != NULL)
    x->m_pParent = y->m_pParent;
  if (y->m_pParent != NULL)
  {
    if (y == y->m_pParent->m_pLeft)
      y->m_pParent->m_pLeft = x;
    else
      y->m_pParent->m_pRight = x;
  }
  else
    CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = x;
  // Unlink given node.
  if (isBlack(*y))
    unlink(x, y->m_pParent);
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::unlink(SBinTreeNode* a_pNode, SBinTreeNode* a_pParentNode)
{ CALL
  SBinTreeNode* w;

  while ((a_pParentNode != NULL) && ((a_pNode == NULL) || isBlack(*a_pNode)))
  {
    if (a_pNode == a_pParentNode->m_pLeft)
    {
      w = a_pParentNode->m_pRight;
      if ((w != NULL) && isRed(*w))
      {
        setBlack(*w);
        setRed(*a_pParentNode);
        rotateLeft(a_pParentNode);
        w = a_pParentNode->m_pRight;
      }
      if (((w->m_pLeft == NULL) || isBlack(*w->m_pLeft)) && ((w->m_pRight == NULL) || isBlack(*w->m_pRight)))
      {
        setRed(*w);
        a_pNode = a_pParentNode;
        a_pParentNode = a_pParentNode->m_pParent;
      }
      else
      {
        if ((w->m_pRight == NULL) || isBlack(*w->m_pRight))
        {
          setBlack(*w->m_pLeft);
          setRed(*w);
          rotateRight(w);
          w = a_pParentNode->m_pRight;
        }
        // Copy red-black color information.
        if (isBlack(*a_pParentNode))
          setBlack(*w);
        else
          setRed(*w);
        setBlack(*a_pParentNode);
        setBlack(*w->m_pRight);
        rotateLeft(a_pParentNode);
        a_pNode = CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode();
        a_pParentNode = NULL;
      }
    }
    else
    {
      w = a_pParentNode->m_pLeft;
      if ((w != NULL) && isRed(*w))
      {
        setBlack(*w);
        setRed(*a_pParentNode);
        rotateRight(a_pParentNode);
        w = a_pParentNode->m_pLeft;
      }
      if (((w->m_pLeft == NULL) || isBlack(*w->m_pLeft)) && ((w->m_pRight == NULL) || isBlack(*w->m_pRight)))
      {
        setRed(*w);
        a_pNode = a_pParentNode;
        a_pParentNode = a_pParentNode->m_pParent;
      }
      else
      {
        if ((w->m_pLeft == NULL) || isBlack(*w->m_pLeft))
        {
          setBlack(*w->m_pRight);
          setRed(*w);
          rotateLeft(w);
          w = a_pParentNode->m_pLeft;
        }
        // Copy red-black color information.
        if (isBlack(*a_pParentNode))
          setBlack(*w);
        else
          setRed(*w);
        setBlack(*a_pParentNode);
        setBlack(*w->m_pLeft);
        rotateRight(a_pParentNode);
        a_pNode = CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode();
        a_pParentNode = NULL;
      }
    }
  }
  if (a_pNode != NULL)
    setBlack(*a_pNode);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::rotateLeft(SBinTreeNode* a_pNode)
{ CALL
  SBinTreeNode* current = a_pNode->m_pRight;

  // Establish node->right link.
  a_pNode->m_pRight = current->m_pLeft;
  if (current->m_pLeft != NULL)
    current->m_pLeft->m_pParent = a_pNode;
  // Establish current->parent link.
  current->m_pParent = a_pNode->m_pParent;
  if (a_pNode->m_pParent != NULL)
  {
    if (a_pNode == a_pNode->m_pParent->m_pLeft)
      a_pNode->m_pParent->m_pLeft = current;
    else
      a_pNode->m_pParent->m_pRight = current;
  }
  else
    CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = current;
  // Link node and current.
  current->m_pLeft = a_pNode;
  a_pNode->m_pParent = current;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::rotateRight(SBinTreeNode* a_pNode)
{ CALL
  SBinTreeNode* current = a_pNode->m_pLeft;

  // Establish node->right link.
  a_pNode->m_pLeft = current->m_pRight;
  if (current->m_pRight != NULL)
   current->m_pRight->m_pParent = a_pNode;
  // Establish current->parent link.
  current->m_pParent = a_pNode->m_pParent;
  if (a_pNode->m_pParent != NULL)
  {
    if (a_pNode == a_pNode->m_pParent->m_pRight)
      a_pNode->m_pParent->m_pRight = current;
    else
      a_pNode->m_pParent->m_pLeft = current;
  }
  else
    CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = current;
  // Link node and current.
  current->m_pRight = a_pNode;
  a_pNode->m_pParent = current;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::isBlack(const SBinTreeNode& a_crNode)
{ CALL
  return (a_crNode.m_pData == (Tptr)0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::isRed(const SBinTreeNode& a_crNode)
{ CALL
  return (a_crNode.m_pData != (Tptr)0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::setBlack(SBinTreeNode& a_rNode)
{ CALL
  a_rNode.m_pData = (Tptr)0;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::setRed(SBinTreeNode& a_rNode)
{ CALL
  a_rNode.m_pData = (Tptr)1;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
template <class T_Archive>
inline Tbool CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CBinTree<T_Type, T_BinaryPredicate, T_Allocator>&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::swap(CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CBinTree<T_Type, T_BinaryPredicate, T_Allocator>&)(*this), (CBinTree<T_Type, T_BinaryPredicate, T_Allocator>&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
