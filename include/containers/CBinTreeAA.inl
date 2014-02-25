/*!
 *  \file    CBinTreeAA.inl Template A.Andersson balanced binary tree
 *           container class.
 *  \brief   Template A.Andersson balanced binary tree container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template A.Andersson balanced binary tree container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   31.08.2006 22:51:48

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
#ifndef __CBINTREEAA_INL__
#define __CBINTREEAA_INL__
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
inline CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeAA(T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>(a_fLessThan, a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeAA(const T_Type& a_crItem, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>(a_fLessThan, a_crAllocator)
{ CALL
  insert(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::CBinTreeAA(const CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>(a_fLessThan, a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::~CBinTreeAA()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::insertAndBalance(SBinTreeNode* a_pNode)
{ CALL
  setLevel(*a_pNode, 1);
  while (a_pNode->m_pParent != NULL)
  {
    a_pNode = a_pNode->m_pParent;
    if (getLevel(*a_pNode) != ((a_pNode->m_pLeft != NULL) ? (getLevel(*a_pNode->m_pLeft) + 1) : 1))
    {
      skew(a_pNode);
      if ((a_pNode->m_pRight == NULL) || (getLevel(*a_pNode) != getLevel(*a_pNode->m_pRight)))
        a_pNode = a_pNode->m_pParent;
    }

    if (!split(a_pNode->m_pParent))
      break;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::removeAndBalance(SBinTreeNode* a_pNode)
{ CALL
  SBinTreeNode* node = a_pNode;
  SBinTreeNode* temp;

  if (a_pNode->m_pLeft != NULL)
  {
    node = a_pNode->m_pLeft;
    while (node->m_pRight != NULL)
      node = node->m_pRight;
  }
  else if (a_pNode->m_pRight != NULL)
    node = a_pNode->m_pRight;

  temp = ((node->m_pParent == a_pNode) ? node : node->m_pParent);
  if (node->m_pParent != NULL)
  {
    if (node->m_pParent->m_pLeft == node)
      node->m_pParent->m_pLeft = NULL;
    else
      node->m_pParent->m_pRight = NULL;
  }
  else
    CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = NULL;

  if (a_pNode != node)
  {
    if (a_pNode->m_pParent != NULL)
    {
      if (a_pNode->m_pParent->m_pLeft == a_pNode)
        a_pNode->m_pParent->m_pLeft = node;
      else
        a_pNode->m_pParent->m_pRight = node;
    }
    else
      CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = node;
    node->m_pParent = a_pNode->m_pParent;
    if (a_pNode->m_pLeft != NULL)
      a_pNode->m_pLeft->m_pParent = node;
    node->m_pLeft = a_pNode->m_pLeft;
    if (a_pNode->m_pRight != NULL)
      a_pNode->m_pRight->m_pParent = node;
    node->m_pRight = a_pNode->m_pRight;
    // Copy levels
    setLevel(*node, getLevel(*a_pNode));
  }

  while (temp != NULL)
  {
    if (getLevel(*temp) > ((temp->m_pLeft != NULL) ? (getLevel(*temp->m_pLeft) + 1) : 1))
    {
      setLevel(*temp, (getLevel(*temp) - 1));
      if (split(temp))
      {
        if (split(temp))
          skew(temp->m_pParent->m_pParent);
        break;
      }
    }
    else if (getLevel(*temp) <= ((temp->m_pRight != NULL) ? (getLevel(*temp->m_pRight) + 1) : 1))
      break;
    else
    {
      skew(temp);
      if (getLevel(*temp) > getLevel(*temp->m_pParent))
      {
        skew(temp);
        split(temp->m_pParent->m_pParent);
        break;
      }
      temp = temp->m_pParent;
    }
    temp = temp->m_pParent;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::skew(SBinTreeNode* a_pNode)
{ CALL
  if (a_pNode == NULL)
    return;

  SBinTreeNode* node = a_pNode->m_pLeft;

  if (a_pNode->m_pParent != NULL)
  {
    if (a_pNode->m_pParent->m_pLeft == a_pNode)
      a_pNode->m_pParent->m_pLeft = node;
    else
      a_pNode->m_pParent->m_pRight = node;
  }
  else
    CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = node;
  node->m_pParent = a_pNode->m_pParent;
  a_pNode->m_pParent = node;

  a_pNode->m_pLeft = node->m_pRight;
  if (a_pNode->m_pLeft != NULL)
    a_pNode->m_pLeft->m_pParent = a_pNode;
  node->m_pRight = a_pNode;

  setLevel(*a_pNode, ((a_pNode->m_pLeft != NULL) ? (getLevel(*a_pNode->m_pLeft) + 1) : 1));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tbool CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::split(SBinTreeNode* a_pNode)
{ CALL
  if (a_pNode == NULL)
    return false;

  SBinTreeNode* node = a_pNode->m_pRight;

  if ((node != NULL) && (node->m_pRight != NULL) && (getLevel(*node->m_pRight) == getLevel(*a_pNode)))
  {
    if (a_pNode->m_pParent != NULL)
    {
      if (a_pNode->m_pParent->m_pLeft == a_pNode)
        a_pNode->m_pParent->m_pLeft = node;
      else
        a_pNode->m_pParent->m_pRight = node;
    }
    else
      CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::getRootNode() = node;
    node->m_pParent = a_pNode->m_pParent;
    a_pNode->m_pParent = node;

    a_pNode->m_pRight = node->m_pLeft;
    if (a_pNode->m_pRight != NULL)
      a_pNode->m_pRight->m_pParent = a_pNode;
    node->m_pLeft = a_pNode;
    setLevel(*node, (getLevel(*a_pNode) + 1));
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::setLevel(SBinTreeNode& a_rNode, const Tuint a_cLevel)
{ CALL
  a_rNode.m_pData = (Tptr)a_cLevel;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline Tuint CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::getLevel(const SBinTreeNode& a_crNode)
{ CALL
  return (Tuint)a_crNode.m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
template <class T_Archive>
inline Tbool CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CBinTree<T_Type, T_BinaryPredicate, T_Allocator>&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
inline void CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::swap(CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CBinTree<T_Type, T_BinaryPredicate, T_Allocator>&)(*this), (CBinTree<T_Type, T_BinaryPredicate, T_Allocator>&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
