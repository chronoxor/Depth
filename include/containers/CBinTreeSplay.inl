/*!
 *  \file    CBinTreeSplay.inl Template splay balanced binary tree container
 *           class.
 *  \brief   Template splay balanced binary tree container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template splay balanced binary tree container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   02.09.2006 21:24:57

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
#ifndef __CBINTREESPLAY_INL__
#define __CBINTREESPLAY_INL__
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
inline CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeSplay(T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>(a_fLessThan, a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeSplay(const T_Type& a_crItem, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>(a_fLessThan, a_crAllocator)
{ CALL
  insert(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeSplay(const CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>(a_fLessThan, a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::~CBinTreeSplay()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::SBinTreeNode* CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::findAndBalance(const T_Type& a_crItem) const
{ CALL
  return splay(CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode(), a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::removeAndBalance(SBinTreeNode* a_pNode)
{ CALL
  SBinTreeNode* node = splay(CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode(), a_pNode->m_pFirstItem->m_Item);
  SBinTreeNode* temp;

  if (node->m_pLeft != NULL)
  {
    if (node->m_pRight != NULL)
    {
      splay(node->m_pLeft, node->m_pFirstItem->m_Item);
      // Get root node.
      node = CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode();
      // Insert right node to the left node.
      temp = node->m_pLeft;
      while (temp != NULL)
      {
        if (isLessThan(node->m_pRight->m_pFirstItem->m_Item, temp->m_pFirstItem->m_Item))
        {
          if (temp->m_pLeft == NULL)
          {
            temp->m_pLeft = node->m_pRight;
            node->m_pRight->m_pParent = temp;
            break;
          }
          else
            temp = temp->m_pLeft;
        }
        else
        {
          if (temp->m_pRight == NULL)
          {
            temp->m_pRight = node->m_pRight;
            node->m_pRight->m_pParent = temp;
            break;
          }
          else
            temp = temp->m_pRight;
        }
      }
    }
    CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = node->m_pLeft;
    if (node->m_pLeft != NULL)
      node->m_pLeft->m_pParent = NULL;
  }
  else
  {
    CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = node->m_pRight;
    if (node->m_pRight != NULL)
      node->m_pRight->m_pParent = NULL;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline typename CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::SBinTreeNode* CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::splay(const SBinTreeNode* a_cpNode, const T_Type& a_crItem) const
{ CALL
  if (a_cpNode == NULL)
    return NULL;

  if (isLessThan(a_cpNode->m_pFirstItem->m_Item, a_crItem))
  {
     if (a_cpNode->m_pRight != NULL)
     {
       splay(a_cpNode->m_pRight, a_crItem);
       zig(a_cpNode);
       return NAlgorithms::NCommon::constCast<SBinTreeNode*>(CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode());
     }
     else
       return NULL;
  }
  else if (isLessThan(a_crItem, a_cpNode->m_pFirstItem->m_Item))
  {
     if (a_cpNode->m_pLeft != NULL)
     {
       splay(a_cpNode->m_pLeft, a_crItem);
       zag(a_cpNode);
       return NAlgorithms::NCommon::constCast<SBinTreeNode*>(CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode());
     }
     else
       return NULL;
  }
  else
    return NAlgorithms::NCommon::constCast<SBinTreeNode*>(a_cpNode);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::zig(const SBinTreeNode* a_cpNode) const
{ CALL
  SBinTreeNode* node = NAlgorithms::NCommon::constCast<SBinTreeNode*>(a_cpNode);
  SBinTreeNode* temp = node->m_pRight;

  if (node->m_pParent == NULL)
    NAlgorithms::NCommon::constCast<SBinTreeNode*&, SBinTreeNode* const&>(CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode()) = temp;
  SBinTreeNode::swap(node, temp);
  NAlgorithms::NCommon::swap(node, temp);

  temp = node->m_pRight->m_pRight;
  node->m_pRight->m_pRight = node->m_pRight->m_pLeft;
  if (node->m_pRight->m_pLeft != NULL)
    node->m_pRight->m_pLeft->m_pParent = node->m_pRight;
  node->m_pRight->m_pLeft = node->m_pLeft;
  if (node->m_pLeft != NULL)
    node->m_pLeft->m_pParent = node->m_pRight;
  node->m_pLeft = node->m_pRight;
  if (node->m_pRight != NULL)
    node->m_pRight->m_pParent = node;
  node->m_pRight = temp;
  if (temp != NULL)
    temp->m_pParent = node;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::zag(const SBinTreeNode* a_cpNode) const
{ CALL
  SBinTreeNode* node = NAlgorithms::NCommon::constCast<SBinTreeNode*>(a_cpNode);
  SBinTreeNode* temp = node->m_pLeft;

  if (node->m_pParent == NULL)
    NAlgorithms::NCommon::constCast<SBinTreeNode*&, SBinTreeNode* const&>(CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode()) = temp;
  SBinTreeNode::swap(node, temp);
  NAlgorithms::NCommon::swap(node, temp);

  temp = node->m_pLeft->m_pLeft;
  node->m_pLeft->m_pLeft = node->m_pLeft->m_pRight;
  if (node->m_pLeft->m_pRight != NULL)
    node->m_pLeft->m_pRight->m_pParent = node->m_pLeft;
  node->m_pLeft->m_pRight = node->m_pRight;
  if (node->m_pRight != NULL)
    node->m_pRight->m_pParent = node->m_pLeft;
  node->m_pRight = node->m_pLeft;
  if (node->m_pLeft != NULL)
    node->m_pLeft->m_pParent = node;
  node->m_pLeft = temp;
  if (temp != NULL)
    temp->m_pParent = node;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
template <class T_Archive>
inline Tbool CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CBinTree<T_Type, T_BinaryPredicate, T_Allocator>&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::swap(CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CBinTree<T_Type, T_BinaryPredicate, T_Allocator>&)(*this), (CBinTree<T_Type, T_BinaryPredicate, T_Allocator>&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
