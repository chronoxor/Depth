/*!
 *  \file    CBinTreeRB.hpp Template red-black balanced binary tree container
 *           class.
 *  \brief   Template red-black balanced binary tree container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template red-balck balanced binary tree container class.

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
#ifndef __CBINTREERB_HPP__
#define __CBINTREERB_HPP__
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
//! Template red-black balanced binary tree container class.
/*!
    <b>Overview.</b>\n
    A red-black tree is a type of self-balancing binary search  tree,  a  data
    structure  used  in  computer  science,  typically   used   to   implement
    associative arrays. The original structure was invented in 1972 by  Rudolf
    Bayer who called them "symmetric binary B-trees", but acquired its  modern
    name in a paper in 1978 by Leo J.  Guibas  and  Robert  Sedgewick.  It  is
    complex, but has good worst-case running time for its  operations  and  is
    efficient in practice: it can search, insert, and delete in O(log n) time,
    where n is the number of elements in the tree.

    <b>Background and terminology.</b>\n
    A red-black tree is a special type of binary tree, which  is  a  structure
    used in computer science to organize pieces of comparable  data,  such  as
    numbers. Each piece of data is stored in a node. One of the  nodes  always
    functions as our starting place, and is not the child of any node; we call
    this the root node or root. It has up to two "children",  other  nodes  to
    which it connects. Each of these children can have up to two  children  of
    its own, and so on. The root node thus has a path  connecting  it  to  any
    other node in the tree.

    If a node has no children, we call it a leaf node, since intuitively it is
    at the periphery of the tree. A subtree is the portion of  the  tree  that
    can be reached from a certain  node,  considered  as  a  tree  itself.  In
    red-black trees, the leaves are assumed to be null, that is, they  do  not
    contain any data.

    As red-black  trees  are  also  binary  search  trees,  they  satisfy  the
    constraint that every node contains a value less  than  or  equal  to  all
    nodes in its right subtree, and greater than or equal to all nodes in  its
    left subtree. This makes it quick to search the tree for  a  given  value,
    and allows efficient in-order traversal of elements.

    <b>Uses and advantages.</b>\n
    Red-black trees, along with AVL trees, offer the best possible  worst-case
    guarantees for insertion time, deletion time, and search  time.  Not  only
    does this make  them  valuable  in  time-sensitive  applications  such  as
    real-time applications, but it makes  them  valuable  building  blocks  in
    other data structures which provide worst-case  guarantees;  for  example,
    many data structures used  in  computational  geometry  can  be  based  on
    red-black trees.

    Red-black trees are also particularly valuable in functional  programming,
    where they are one of the most common persistent data structures, used  to
    construct associative arrays and sets which can retain  previous  versions
    after mutations. The persistent version of red-black trees requires  O(log
    n) space for each insertion or deletion, in addition to time.

    Red-black trees are an isometry of 2-3-4 trees. In other words, for  every
    2-3-4 tree, there exists at least one red-black tree with data elements in
    the same order. The insertion and deletion operations on 2-3-4  trees  are
    also equivalent to color-flipping and rotations in red-black  trees.  This
    makes 2-3-4 trees an important tool for  understanding  the  logic  behind
    red-black trees,  and  this  is  why  many  introductory  algorithm  texts
    introduce 2-3-4 trees just before red-black trees, even though 2-3-4 trees
    are not often used in practice.

    <b>Properties.</b>\n
    \image html BinTree-Red-Black.png "Red-Black binary tree."
    A red-black tree is a binary search tree  where  each  node  has  a  color
    attribute, the value of which is either red or black. In addition  to  the
    ordinary  requirements  imposed  on  binary  search  trees,  we  make  the
    following additional requirements of any valid red-black tree:

    \li 1. A node is either red or black.
    \li 2. The root is black.
    \li 3. All leaves are black. (This includes the NIL children)
    \li 4. Both children of every red node are black.  (i.e.  Every  red  node
           must have a black parent.)
    \li 5. All paths from any given node to its leaf nodes  contain  the  same
           number of black nodes.

    These constraints enforce a critical property of red-black trees: that the
    longest possible path from the root to a leaf is no  more  than  twice  as
    long as the shortest possible path. The result is that the tree is roughly
    balanced. Since operations such as inserting, deleting, and finding values
    requires worst-case time proportional to the  height  of  the  tree,  this
    theoretical upper bound  on  the  height  allows  red-black  trees  to  be
    efficient in the worst-case, unlike ordinary binary search trees.

    To see why these properties guarantee this, it suffices to  note  that  no
    path can have two red nodes in a row, due  to  property  4.  The  shortest
    possible  path  has  all  black  nodes,  and  the  longest  possible  path
    alternates between red and black nodes. Since all maximal paths  have  the
    same number of black nodes, by property 5, this shows that no path is more
    than twice as long as any other path.

    In many presentations of tree data structures, it is possible for  a  node
    to have only one child, and leaf nodes contain data.  It  is  possible  to
    present red-black trees in this paradigm, but it changes  several  of  the
    properties and complicates  the  algorithms.  For  this  reason,  in  this
    article we use "nil leaves" or "null leaves", which contain  no  data  and
    merely serve to indicate where the tree ends, as shown above. These  nodes
    are often omitted  in  drawings,  resulting  in  a  tree  which  seems  to
    contradict the above principles, but which in fact does not. A consequence
    of this is that all internal (non-leaf) nodes have two children,  although
    one or more of those children may be a null leaf.

    Some explain a red-black tree as a binary search tree whose edges, instead
    of nodes, are colored in  red  or  black,  but  this  does  not  make  any
    difference. The color of a node in  our  terminology  corresponds  to  the
    color of the edge connecting the node to its parent, except that the  root
    node  is  always  black  in  our  terminology  (property  2)  whereas  the
    corresponding edge does not exist.

    <b>Operations.</b>\n
    Read-only operations on a red-black  tree  require  no  modification  from
    those used for binary search trees, because  every  red-black  tree  is  a
    specialization of a simple binary  search  tree.  However,  the  immediate
    result of an  insertion  or  removal  may  violate  the  properties  of  a
    red-black tree. Restoring the red-black properties requires a small number
    (O(log n) or amortized O(1)) of color changes (which  are  very  quick  in
    practice) and no more than  three  tree  rotations  (two  for  insertion).
    Although insert and delete operations are complicated, their times  remain
    O(log n).

    <b>Proof of asymptotic bounds.</b>\n

    A red black  tree  which  contains  n  internal  nodes  has  a  height  of
    O(log(n)).

    Definitions:

    \li h(v) = height of subtree rooted at node v
    \li bh(v) = the number of black nodes (not counting v if it is black) from
        v to any leaf in the subtree (called the black-height).

    <b>Lemma:</b> A subtree rooted at node v has at least 2bh(v) ? 1  internal
    nodes.

    Proof of Lemma (by induction height):

    Basis: h(v) = 0

    If v has a height of zero then it must be nil, therefore bh(v) = 0. So:

    \f$2^{bh(v)} - 1 = 20 - 1 = 1 - 1 = 0\f$

    Inductive Hypothesis: v such that  h(v)  =  k,  has  \f$2^{bh(v)}  -  1\f$
    internal nodes implies that v' such that h(v') = k+1 has  \f$2^{bh(v')}  -
    1\f$ internal nodes.

    Since v' has h(v') > 0 it is an internal node. As such it has two children
    which have a black-height of  either  bh(v')  or  bh(v')-1  (depending  on
    whether v' is red or black). By the inductive hypothesis each child has at
    least \f$2^{bh(v)} - 1 - 1\f$ internal nodes, so v' has:

    \f[2^{bh(v)} - 1 - 1 + 2^{bh(v')} - 1 - 1 + 1 = 2^{bh(v')} - 1\f]

    internal nodes.

    Using this lemma  we  can  now  show  that  the  height  of  the  tree  is
    logarithmic. Since at least half of the nodes on any path from the root to
    a leaf are black (property 4 of a red black tree), the  black-  height  of
    the root is at least \f$h(root) \over 2\f$. By the lemma we get:

    \f[n \geq 2^{{h(root) \over 2}} - 1 \leftrightarrow  \;  \log{(n+1)}  \geq
    {h(root) \over 2} \leftrightarrow \; h(root) \leq 2\log{(n+1)}\f]

    Therefore the height of the root is O(log(n)).

    <b>References.</b>\n
    \li Mathworld: Red-Black Tree
    \li San Diego State University: CS 660: Red-Black  tree  notes,  by  Roger
        Whitney
    \li Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford
        Stein. Introduction to  Algorithms,  Second  Edition.  MIT  Press  and
        McGraw-Hill, 2001. ISBN 0-262-03293-7 . Chapter 13:  Red-Black  Trees,
        pp.273-301.

    <b>Taken from:</b>\n
    Red-black tree from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Red-black_tree
*/
template <typename T_Type, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Type&>, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CBinTreeRB :
  public CBinTree<T_Type, T_BinaryPredicate, T_Allocator>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator> TDepthCheckType;

  // Check CBinTreeRB class constraint to be a real Depth type.
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
      Create an empty red-black balanced binary tree.

      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTreeRB(T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize red-black balanced binary tree with one item.
  /*!
      Create an empty red-black balanced binary tree, then insert item into it
      as a root node.

      \param a_crItem - Constant reference to the item to insert.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTreeRB(const T_Type& a_crItem, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBinTreeRB class.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTreeRB(const CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CBinTreeRB();

  //! Serialize CBinTreeRB class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBinTreeRB class instances.
  /*!
      \param a_rInstance - Reference to another CBinTreeRB class instance.
  */
  void swap(CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>& a_rInstance);

protected:
  //! Binary tree node structure.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::SBinTreeNode SBinTreeNode;

  // CBinTree class overriding methods.
  virtual Tbool insertAndBalance(SBinTreeNode* a_pNode);
  virtual Tbool removeAndBalance(SBinTreeNode* a_pNode);

private:
  //! Unlink red-black balanced binary tree node.
  /*!
      \param a_pNode - Pointer to the red-black balanced binary tree node.
      \param a_pParentNode - Pointer to the parent red-black balanced binary tree node.
  */
  void unlink(SBinTreeNode* a_pNode, SBinTreeNode* a_pParentNode);

  //! Rotate red-black balanced binary tree node to the left.
  /*!
      \param a_pNode - Pointer to the red-black balanced binary tree node.
  */
  void rotateLeft(SBinTreeNode* a_pNode);
  //! Rotate red-black balanced binary tree node to the right.
  /*!
      \param a_pNode - Pointer to the red-black balanced binary tree node.
  */
  void rotateRight(SBinTreeNode* a_pNode);

  //! Check if given red-black balanced binary tree node has black color.
  /*!
      \param a_crNode - Constant reference to the red-black balanced binary tree node.
      \return true  - if red-black balanced binary tree node has black color. \n
              false - if red-black balanced binary tree node has red color. \n
  */
  static Tbool isBlack(const SBinTreeNode& a_crNode);
  //! Check if given red-black balanced binary tree node has red color.
  /*!
      \param a_crNode - Constant reference to the red-black balanced binary tree node.
      \return true  - if red-black balanced binary tree node has red color. \n
              false - if red-black balanced binary tree node has black color. \n
  */
  static Tbool isRed(const SBinTreeNode& a_crNode);

  //! Set black color for given red-black balanced binary tree node.
  /*!
      \param a_rNode - Reference to the red-black balanced binary tree node.
  */
  static void setBlack(SBinTreeNode& a_rNode);
  //! Set red color for given red-black balanced binary tree node.
  /*!
      \param a_rNode - Reference to the red-black balanced binary tree node.
  */
  static void setRed(SBinTreeNode& a_rNode);
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
//! Traits meta-class: red-black balanced binary tree container traits specialization.
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
class MTraitsContainer<NContainers::CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator> > :
  public MType<NContainers::CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CBinTreeRB<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst citerator;

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
#include <Depth/include/containers/CBinTreeRB.inl>
/*==========================================================================*/
//! \example example-containers-CBinTreeRB.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CBinTreeRB.cpp
/*==========================================================================*/
#endif
