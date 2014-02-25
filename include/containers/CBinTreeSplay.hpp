/*!
 *  \file    CBinTreeSplay.hpp Template splay balanced binary tree container
 *           class.
 *  \brief   Template splay balanced binary tree container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template splay balanced binary tree container class.

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
#ifndef __CBINTREESPLAY_HPP__
#define __CBINTREESPLAY_HPP__
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
//! Template splay balanced binary tree container class.
/*!
    <b>Overview.</b>\n
    A splay tree is a self-balancing binary search tree  with  the  additional
    unusual property that recently  accessed  elements  are  quick  to  access
    again. It performs basic operations such as insertion, look-up and removal
    in O(log(n)) amortized time. For many non-uniform sequences of operations,
    splay trees perform better than other search trees, even when the specific
    pattern of the sequence is unknown. The splay tree was invented by  Daniel
    Sleator and Robert Tarjan.

    All normal operations on a binary search tree are combined with one  basic
    operation, called splaying.  Splaying  the  tree  for  a  certain  element
    rearranges the tree so that the element is placed at the root of the tree.
    One way to do this is to first perform a standard binary tree  search  for
    the element in question, and then use tree rotations in a specific fashion
    to bring the element to the top. Alternatively, a bottom-up algorithm  can
    combine the search and the tree reorganization.

    <b>Advantages and disadvantages.</b>\n
    Good performance for a splay tree depends on the fact  that  it  is  self-
    balancing, and indeed self optimising, in that frequently  accessed  nodes
    will move nearer to the root where they can be accessed more quickly. This
    is an advantage for nearly all practical applications, and is particularly
    useful for implementing caches; however it is important to note  that  for
    uniform access, a splay tree's performance will be considerably  (although
    not asymptotically) worse than a somewhat balanced  simple  binary  search
    tree.

    Splay trees also have the  advantage  of  being  considerably  simpler  to
    implement than other self-balancing binary  search  trees,  such  as  red-
    black trees or AVL trees, while their average-case performance is just  as
    efficient. Also, splay trees do not need to store  any  bookkeeping  data,
    thus minimizing memory requirements. However, these other data  structures
    provide worst-case time guarantees, and can be more efficient in  practice
    for uniform access.

    One worst case issue with the  basic  splay  tree  algorithm  is  that  of
    sequentially accessing all the elements of the tree  in  the  sort  order.
    This leaves the tree completely unbalanced (this takes n accesses  -  each
    an O(1) operation). Reaccessing the first item triggers an operation  that
    takes O(n) operations to rebalance the tree  before  returning  the  first
    item. This is a significant delay for that final operation,  although  the
    amortised performance over the entire sequence is actually O(1).  However,
    recent research shows that randomly rebalancing the tree  can  avoid  this
    unbalancing effect  and  give  similar  performance  to  the  other  self-
    balancing algorithms.

    It is possible to create a persistent version of splay trees which  allows
    access to both the  previous  and  new  versions  after  an  update.  This
    requires amortized O(log n) space per update.

    Contrarily to other types of self balancing trees, splay trees  work  well
    with  nodes  containing  identical  keys.  Even   with   identical   keys,
    performance remains amortized O(log n). All tree operations  preserve  the
    order of the identical nodes within the tree, which is a property  similar
    to stable sorting algorithms. A  carefully  designed  find  operation  can
    return the left most or right most node of a given key.

    <b>The splay operation.</b>\n
    When a node x is accessed, a splay operation is performed on x to move  it
    to the root. To perform a splay operation we carry out a sequence of splay
    steps, each of which moves x closer to the  root.  As  long  as  x  has  a
    grandparent, each particular step depends on two factors:
    \li Whether x is the left or right child of its parent node, p,
    \li Whether p is the left or right child of its parent, g (the grandparent
        of x).

    Thus, there are four cases when x has a grandparent. They  fall  into  two
    types of splay steps.

    \image html BinTree-Splay-Zigzag.png "Zig-zag step."
    <b>Zig-zag Step:</b> One zig-zag case is when x is the right  child  of  p
    and p is the left child of g (shown above). p is the new left child of  x,
    g is the new right child of x, and the subtrees A, B, C, and D  of  x,  p,
    and g are rearranged as necessary. The other zig-zag case  is  the  mirror
    image of this, i.e. when x is the left child of p and p is the right child
    of g. Note that a zig-zag step is equivalent to doing a  rotation  on  the
    edge between x and p, then doing a rotation on the edge between x and g.

    \image html BinTree-Splay-Zigzig.png "Zig-zig step."
    <b>Zig-zig Step:</b> One zig-zig case is when x is the left child of p and
    p is the left child of g (shown above). p is the new right child of  x,  g
    is the new right child of p, and the subtrees A, B, C, and D of x, p,  and
    g are rearranged as necessary. The other zig-zig case is the mirror  image
    of this, i.e. when x is the right child of p and p is the right  child  of
    g. Note that zig-zig steps are the only  thing  that  differentiate  splay
    trees from the rotate to root method indroduced by Allen and  Munro  prior
    to the introduction of splay trees.

    \image html BinTree-Splay-Zig.png "Zig step."
    <b>Zig Step:</b> There is also a third kind of splay  step  that  is  done
    when x has a parent p but no grandparent. This is called a zig step and is
    simply a rotation on the edge between x and p. Zig  steps  exist  to  deal
    with the parity issue and will be done only as the last step  in  a  splay
    operation and only when x has odd depth at the beginning of the operation.

    By performing a splay operation  on  the  node  of  interest  after  every
    access, we keep recently accessed nodes near the root and  keep  the  tree
    roughly balanced, so that we achieve the desired amortized time bounds.

    <b>Performance theorems.</b>\n
    There are  several  theorems  and  conjectures  regarding  the  worst-case
    runtime for performing a  sequence  S  of  m  accesses  in  a  splay  tree
    containing n elements.

    \li <b>Balance Theorem:</b> The cost of performing the sequence S is
    \f$O\left(m + (\log n + 1) + n\log(n) \right)\f$. In  other  words,  splay
    trees perform as well as static balanced binary search trees on  sequences
    of at least n accesses.

    \li <b>Static Optimality Theorem:</b>  Let  qi  be  the  number  of  times
    element  i  is  accessed   in   S.   The   cost   of   performing   S   is
    \f$O\left(m+\sum_{i=1}^n q_i\log\frac{m}{q_i}\right)\f$. In  other  words,
    splay trees perform as well as  optimum  static  binary  search  trees  on
    sequences of at least n accesses.

    \li <b>Static Finger Theorem:</b> Let ij be the element  accessed  in  the
    jth access of S and let f be any fixed element (the finger). The  cost  of
    performing   S   is   \f$O\left(m+n\log   n+\sum_{j=1}^m   \log(|i_j-f|+1)
    \right)\f$.

    \li <b>Working Set  Theorem:</b>  Let  t(j)  be  the  number  of  distinct
    elements accessed between access j and the previous time  element  ij  was
    accessed. The cost of performing  S  is  \f$O\left(m+n\log  n+\sum_{j=1}^m
    \log(t(j)+1) \right)\f$.

    \li  <b>Dynamic  Finger  Theorem:</b>  The  cost  of   performing   S   is
    \f$O\left(m+n\log n+\sum_{j=1}^m \log(|i_{j+1}-i_j|+1) \right)\f$.

    \li <b>Scanning Theorem:</b> Also known as the Sequential Access  Theorem.
    Accessing the n elements of a splay tree in  symmetric  order  takes  O(n)
    time, regardles of the initial structure of the splay tree.  The  tightest
    upper bound proven so far is 4.5n.

    <b>Dynamic optimality conjecture.</b>\n
    In addition to the proven performance guarantees for splay trees there  is
    an unproven conjecture of great interest from  the  original  Sleator  and
    Tarjan  paper.  This  conjecture  is  known  as  the  dynamic   optimality
    conjecture and it basically claims that splay trees perform as well as any
    other binary search tree algorithm up to a constant factor.

    \li <b>Dynamic Optimality Conjecture:</b> Let A be any binary search  tree
    algorithm that accesses an element x by traversing the path from the  root
    to x at a cost of d(x) +  1,  and  that  between  accesses  can  make  any
    rotations in the tree at a cost of 1 per rotation. Let A(S)  be  the  cost
    for A to perform the sequence S of accesses. Then the  cost  for  a  splay
    tree to perform the same accesses is O(n + A(S)).

    There is a special case of the dynamic optimality conjecture known as  the
    traversal conjecture that is also unproven.

    \li <b>Traversal Conjecture:</b>   Let  T1  and  T2  be  two  splay  trees
    containing the same elements. Let S be the sequence obtained  by  visiting
    the elements in T2 in preorder (i.e. depth first search order). The  total
    cost of performing the sequence S of acesses on T1 is O(n).

    <b>References.</b>\n
    \li Sleator and R.E. Tarjan. Self-Adjusting Binary Search  Trees.  Journal
        of the ACM 32:3, pages 652-686, 1985.
    \li R. Cole, B. Mishra, J. Schmidt,  A.  Siegel.  On  the  Dynamic  Finger
        Conjecture  for  Splay  Trees.  Part  I:  Splay  Sorting  log  n-Block
        Sequences. SIAM Journal on Computing 30, pages 1-43, 2000.
    \li R. Cole. On the Dynamic Finger Conjecture for Splay  Trees.  Part  II:
        The Proof. SIAM Journal on Computing 30, pages 44-85, 2000.
    \li R.E. Tarjan. Sequential access  in  splay  trees  takes  linear  time.
        Combinatorica 5, pages 367-378, 1985.
    \li Amr Elmasry. On the sequential access theorem and deque conjecture for
        splay trees. Theor. Comput. Sci. 314(3), pages 459-466, 2004.

    <b>Taken from:</b>\n
    Splay tree from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Splay_tree
*/
template <typename T_Type, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Type&>, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CBinTreeSplay :
  public CBinTree<T_Type, T_BinaryPredicate, T_Allocator>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator> TDepthCheckType;

  // Check CBinTreeSplay class constraint to be a real Depth type.
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
      Create an empty splay balanced binary tree.

      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTreeSplay(T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize Splay balanced binary tree with one item.
  /*!
      Create an empty splay balanced binary tree, then insert item into it  as
      a root node.

      \param a_crItem - Constant reference to the item to insert.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTreeSplay(const T_Type& a_crItem, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBinTreeSplay class.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTreeSplay(const CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CBinTreeSplay();

  //! Serialize CBinTreeSplay class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBinTreeSplay class instances.
  /*!
      \param a_rInstance - Reference to another CBinTreeSplay class instance.
  */
  void swap(CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>& a_rInstance);

protected:
  //! Binary tree node structure.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::SBinTreeNode SBinTreeNode;

  // CBinTree class overriding methods.
  virtual SBinTreeNode* findAndBalance(const T_Type& a_crItem) const;
  virtual Tbool removeAndBalance(SBinTreeNode* a_pNode);

private:
  //! Performs splay operation on a given splay balanced binary tree node.
  /*!
      \param a_cpNode - Constant pointer to the splay balanced binary tree node.
      \param a_crItem - Constant reference to the searching item.
      \return Pointer to the found item, or NULL if we did not found given value.
  */
  SBinTreeNode* splay(const SBinTreeNode* a_cpNode, const T_Type& a_crItem) const;

  //! Performs zig operation on a given splay balanced binary tree node.
  /*!
      \param a_cpNode - Constant pointer to the splay balanced binary tree node.
  */
  void zig(const SBinTreeNode* a_cpNode) const;
  //! Performs zag operation on a given splay balanced binary tree node.
  /*!
      \param a_cpNode - Constant pointer to the splay balanced binary tree node.
  */
  void zag(const SBinTreeNode* a_cpNode) const;
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
//! Traits meta-class: splay balanced binary tree container traits specialization.
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
class MTraitsContainer<NContainers::CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator> > :
  public MType<NContainers::CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CBinTreeSplay<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst citerator;

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
#include <Depth/include/containers/CBinTreeSplay.inl>
/*==========================================================================*/
//! \example example-containers-CBinTreeSplay.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CBinTreeSplay.cpp
/*==========================================================================*/
#endif
