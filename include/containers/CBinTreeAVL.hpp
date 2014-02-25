/*!
 *  \file    CBinTreeAVL.hpp Template AVL balanced binary tree container
 *           class.
 *  \brief   Template AVL balanced binary tree container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template AVL balanced binary tree container class.

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
#ifndef __CBINTREEAVL_HPP__
#define __CBINTREEAVL_HPP__
/*==========================================================================*/
#include <Depth/include/containers/CBinTree.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template AVL balanced binary tree container class.
/*!
    <b>Overview.</b>\n
    In computer science, an AVL tree is a self-balancing binary  search  tree,
    and the first such data structure to be  invented.  In  an  AVL  tree  the
    heights of the two child subtrees of any  node  differ  by  at  most  one,
    therefore it  is  also  called  height-balanced.  Lookup,  insertion,  and
    deletion all take O(log n) time in  both  the  average  and  worst  cases.
    Additions and deletions may require the tree to be rebalanced  by  one  or
    more tree rotations.

    The AVL tree is named after its two  inventors,  G.M.  Adelson-Velsky  and
    E.M. Landis, who published it in their 1962 paper "An  algorithm  for  the
    organization of information."

    The balance factor of a node is the height of its right subtree minus  the
    height of its left subtree. A node with balance factor  1,  0,  or  -1  is
    considered balanced. A node with any other balance  factor  is  considered
    unbalanced and requires rebalancing the tree. The balance factor is either
    stored directly at each node or computed from the heights of the subtrees.

    While AVL trees are theoretically  quite  sound,  they  are  not  commonly
    implemented due  to  their  high  implementation  complexity  to  keep  it
    balanced,  making  development  less  effective  when  compared  to  self-
    correcting tree structures,  such  as  splay  trees  or  heaps.  They  do,
    however, perform better than e.g. red-black trees. They are widely used in
    academic settings as an instructional data structure.

    <b>Operations.</b>\n
    The basic operations of an AVL tree generally  involve  carrying  out  the
    same algorithms as would be carried out on  an  unbalanced  binary  search
    tree, but preceded or followed by  one  or  more  of  the  so-called  "AVL
    rotations."

    <b>Insertion.</b>\n
    Insertion into an AVL tree may be carried out by inserting the given value
    into the tree as if it were an unbalanced binary  search  tree,  and  then
    retracing one's steps toward the root, rotating about any nodes which have
    become unbalanced during the insertion (see tree rotation). Since at  most
    1.5 times lg n nodes are retraced on the journey back  to  the  root,  and
    each AVL rotation takes constant time,  the  insertion  process  in  total
    takes O(log n) time.

    <b>Deletion.</b>\n
    Deletion from an AVL tree may be carried out by rotating the  node  to  be
    deleted down into a leaf  node,  and  then  pruning  off  that  leaf  node
    directly. Since at most log n nodes are rotated during the  rotation  into
    the leaf, and each AVL rotation takes constant time, the deletion  process
    in total takes O(log n) time.

    Practically, this is a large overhead and complex to  program.  Therefore,
    it's more common to implement a lazy deletion -- leave the deletion target
    in place, flag it as "deleted", and replace it with an  inserted  node  if
    they would occupy the same spot.

    <b>Lookup.</b>\n
    Lookup in an AVL tree is performed exactly  as  in  an  unbalanced  binary
    search tree, and thus takes O(log n) time, since an  AVL  tree  is  always
    kept balanced. No special provisions need to  be  taken,  and  the  tree's
    structure is not modified by lookups. (This is in contrast to  splay  tree
    lookups, which do modify their tree's structure.)

    <b>References.</b>\n
    \li G. Adelson-Velskii and E.M. Landis, "An algorithm for the organization
        of  information."  Doklady  Akademii  Nauk  SSSR,  146:263-266,   1962
        (Russian). English translation by  Myron  J.  Ricci  in  Soviet  Math.
        Doklady, 3:1259-1263, 1962.
    \li Donald Knuth. The Art of Computer Programming, Volume 3:  Sorting  and
        Searching, Third Edition. Addison-Wesley,  1997.  ISBN  0-201-89685-0.
        Pages 458-475 of section 6.2.3: Balanced Trees. Note that Knuth  calls
        AVL trees simply "balanced trees".

    <b>Taken from:</b>\n
    AVL tree from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/AVL_tree
*/
template <typename T_Type, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Type&>, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CBinTreeAVL :
  public CBinTree<T_Type, T_BinaryPredicate, T_Allocator>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator> TDepthCheckType;

  // Check CBinTreeAVL class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container associative key type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TKey TKey;
  //! Container associative value type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TValue TValue;

  //! Container value type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TType TType;
  //! Container type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TContainer TContainer;
  //! Non constant binary tree iterator type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIterator TIterator;
  //! Constant binary tree iterator type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst TIteratorConst;

  //! Container binary predicate type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TLessThanPredicate TLessThanPredicate;
  //! Container allocator type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TAllocator TAllocator;

  //! Default class constructor.
  /*!
      Create an empty AVL balanced binary tree.

      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTreeAVL(T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize AVL balanced binary tree with one item.
  /*!
      Create an empty AVL balanced binary tree, then insert item into it as  a
      root node.

      \param a_crItem - Constant reference to the item to insert.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTreeAVL(const T_Type& a_crItem, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBinTreeAVL class.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTreeAVL(const CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CBinTreeAVL();

  //! Serialize CBinTreeAVL class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBinTreeAVL class instances.
  /*!
      \param a_rInstance - Reference to another CBinTreeAVL class instance.
  */
  void swap(CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>& a_rInstance);

protected:
  //! Binary tree node structure.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::SBinTreeNode SBinTreeNode;

  // CBinTree class overriding methods.
  virtual Tbool insertAndBalance(SBinTreeNode* a_pNode);
  virtual Tbool removeAndBalance(SBinTreeNode* a_pNode);

private:
  //! Unlink AVL balanced binary tree node.
  /*!
      \param a_pNode - Pointer to the AVL balanced binary tree node.
  */
  static void unlink(SBinTreeNode* a_pNode);

  //! Set balance value for the given AVL balanced binary tree node.
  /*!
      \param a_rNode - Reference to the AVL balanced binary tree node.
      \param a_cBalance - Balance value.
  */
  static void setBalance(SBinTreeNode& a_rNode, const Tsint a_cBalance);
  //! Get balance value of the AVL balanced binary tree node.
  /*!
      \param a_crNode - Constant reference to the AVL balanced binary tree node.
      \return Balance value of the AVL balanced binary tree node.
  */
  static Tsint getBalance(const SBinTreeNode& a_crNode);

  //! Rotate AVL balanced binary tree node to the left.
  /*!
      \param a_pNode - Pointer to the AVL balanced binary tree node.
  */
  static void rotateLeft(SBinTreeNode* a_pNode);
  //! Rotate AVL balanced binary tree node to the right.
  /*!
      \param a_pNode - Pointer to the AVL balanced binary tree node.
  */
  static void rotateRight(SBinTreeNode* a_pNode);

  //! Twice rotate AVL balanced binary tree node to the left.
  /*!
      \param a_pNode - Pointer to the AVL balanced binary tree node.
  */
  static void rotateTwiceLeft(SBinTreeNode* a_pNode);
  //! Twicw rotate AVL balanced binary tree node to the right.
  /*!
      \param a_pNode - Pointer to the AVL balanced binary tree node.
  */
  static void rotateTwiceRight(SBinTreeNode* a_pNode);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* CONTAINER TRAITS SPECIALIZATION DECLARATIONS                             */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: AVL balanced binary tree container traits specialization.
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
class MTraitsContainer<NContainers::CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator> > :
  public MType<NContainers::CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CBinTreeAVL<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = false; //!< Is container non constant queue?
  static const Tbool isQueueConst       = true;  //!< Is container constant queue?
  static const Tbool isDeque            = false; //!< Is container non constant deque?
  static const Tbool isDequeConst       = true;  //!< Is container constant deque?
  static const Tbool isRandom           = false; //!< Is container non constant random?
  static const Tbool isRandomConst      = false; //!< Is container constant random?
  static const Tbool isAssociative      = true;  //!< Is container non constant associative?
  static const Tbool isAssociativeConst = true;  //!< Is container constant associative?
  static const Tbool isTree             = false; //!< Is container non constant tree?
  static const Tbool isTreeConst        = true;  //!< Is container constant tree?
  static const Tbool isGraph            = false; //!< Is container non constant graph?
  static const Tbool isGraphConst       = false; //!< Is container constant graph?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/CBinTreeAVL.inl>
/*==========================================================================*/
//! \example example-containers-CBinTreeAVL.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CBinTreeAVL.cpp
/*==========================================================================*/
#endif
