/*!
 *  \file    CBinTree.hpp Template non balanced binary tree container class.
 *  \brief   Template non balanced binary tree container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template non balanced binary tree container class.

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
#ifndef __CBINTREE_HPP__
#define __CBINTREE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/ACast.hpp>
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
#include <Depth/include/common/containers/IAssociative.hpp>
#include <Depth/include/common/containers/IAssociativeConst.hpp>
#include <Depth/include/common/containers/IDequeConst.hpp>
#include <Depth/include/common/containers/ITreeConst.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/memory/allocators/CAllocatorMemory.hpp>
#include <Depth/include/traits/MTraitsContainer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Type&>, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CBinTreeIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Type&>, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CBinTreeIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template non balanced binary tree container class.
/*!
    Binary trees are the good structures for associative searching. They  keep
    items in sort order, so each of item can be found in a short time.

    <b>Overview.</b>\n
    In computer science, a binary search tree (BST) is a binary tree which has
    the following properties:
    \li Each node has a value.
    \li A total order is defined on these values.
    \li The left subtree of a node contains only values less than or equal  to
        the node's value.
    \li The right subtree of a node contains only values greater than or equal
        to the node's value.

    \image html BinTree.png "Binary tree."
    The major advantage of binary search trees is  that  the  related  sorting
    algorithms and search algorithms such as in-order traversal  can  be  very
    efficient.

    Binary search trees are a fundamental data  structure  used  to  construct
    more abstract data structures such as  sets,  multisets,  and  associative
    arrays.

    If a BST allows duplicate values, then it represents a multiset. This kind
    of tree uses non-strict inequalities. Everything in the left subtree of  a
    node is strictly less than the value of the node, but  everything  in  the
    right subtree is either greater than or equal to the value of the node.

    If a BST does not allow duplicate values, then the tree represents  a  set
    with unique values, like the mathematical  set.  Trees  without  duplicate
    values use strict inequalities, meaning that the left subtree  of  a  node
    only contains nodes with values that are less than the value of the  node,
    and the right subtree only contains values that are greater.

    The choice of storing equal values in the right subtree only is arbitrary;
    the left would work just as well. One can also permit non-strict  equality
    in both sides. This allows a tree containing many duplicate values  to  be
    balanced better, but it makes searching more complex.

    Most operations on a binary search tree take time directly proportional to
    the tree's height, so it is desirable to keep the height  small.  Ordinary
    binary search trees have the primary disadvantage  that  they  can  attain
    very large heights in rather ordinary situations, such as  when  the  keys
    are inserted in order. The result is a data structure similar to a  linked
    list, making all operations on the tree expensive. If we know all the data
    ahead of time, we can keep the height small on average by adding values in
    a random order, but we do not always have  this  luxury,  particularly  in
    online algorithms.

    Self-balancing   binary   trees   solve   this   problem   by   performing
    transformations on the tree (such as tree  rotations)  at  key  times,  in
    order to reduce the height. Although a certain overhead is involved, it is
    justified in the long run by drastically  decreasing  the  time  of  later
    operations.

    The height must always be at least the ceiling of log n, since  there  are
    at most 2k nodes on the kth level; a complete  or  full  binary  tree  has
    exactly this many levels.  Balanced  BSTs  are  not  always  so  precisely
    balanced, since it can be expensive to keep a tree at  minimum  height  at
    all times; instead, they keep the height within a constant factor of  this
    lower bound.

    Times for various operations in terms of number of nodes in the tree n:
    \li Lookup - O(log n)
    \li Insertion -  O(log n)
    \li Removal -  O(log n)
    \li In-order iteration over all elements - O(n)

    For some implementations these times are worst-case, while for others they
    are amortized.

    <b>Applications.</b>\n
    Self-balancing binary search trees  can  be  used  in  a  natural  way  to
    construct associative arrays; key-value pairs are simply inserted with  an
    ordering based on the key alone. In  this  capacity,  self-balancing  BSTs
    have a number of advantages and disadvantages over their main  competitor,
    hash tables. Lookup is somewhat complicated in the case where the same key
    can be used multiple times.

    Many algorithms can exploit self-balancing BSTs  to  achieve  good  worst-
    case bounds with very little effort. For example, if binary tree  sort  is
    done with a BST, we have  a  very  simple-to-describe  yet  asymptotically
    optimal O(n log n) sorting  algorithm  (although  such  an  algorithm  has
    practical disadvantages  due  to  bad  cache  behavior).  Similarly,  many
    algorithms in computational geometry exploit variations on self- balancing
    BSTs to solve problems such as the line segment intersection  problem  and
    the point location problem efficiently.

    Self-balancing BSTs are a flexible data structure, in that  it's  easy  to
    extend them to efficiently record additional information  or  perform  new
    operations. For example, one can  record  the  number  of  nodes  in  each
    subtree having a certain property, allowing one to  count  the  number  of
    nodes in a certain key range with that property in O(log  n)  time.  These
    extensions can be used, for example, to optimize database queries or other
    list-processing algorithms.

    <b>References.</b>\n
    \li Donald Knuth. The Art of Computer Programming, Volume 3:  Sorting  and
        Searching, Third Edition. Addison-Wesley,  1997.  ISBN  0-201-89685-0.
        Section 6.2.3: Balanced Trees, pp.458-481.

    <b>Taken from:</b>\n
    Binary search tree from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Binary_search_tree
*/
template <typename T_Type, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Type&>, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CBinTree :
  public NCommon::NContainers::IAssociative<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >,
  public NCommon::NContainers::IAssociativeConst<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, T_Type, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >,
  public NCommon::NContainers::IDequeConst<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >,
  public NCommon::NContainers::ITreeConst<CBinTree<T_Type, T_BinaryPredicate, T_Allocator>, T_Type, CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>, CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> >
{
  // Friend class: Binary tree iterator class (CBinTreeIterator).
  friend class CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator>;
  // Friend class: Constant binary tree iterator class (CBinTreeIteratorConst).
  friend class CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptPredicate2 argument constraint checking.
  typedef const T_Type& TPredicate2ArgumentCheckType;
  //! Type for MConceptPredicate2 constraint checking.
  typedef T_BinaryPredicate TPredicate2CheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CBinTree<T_Type, T_BinaryPredicate, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_BinaryPredicate template argument constraint to be a suitable binary predicate.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TPredicate2CheckType, TPredicate2ArgumentCheckType, TPredicate2ArgumentCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CBinTree class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container associative key type.
  typedef T_Type TKey;
  //! Container associative value type.
  typedef T_Type TValue;

  //! Container value type.
  typedef T_Type TType;
  //! Container type.
  typedef CBinTree<T_Type, T_BinaryPredicate, T_Allocator> TContainer;
  //! Non constant binary tree iterator type.
  typedef CBinTreeIterator<T_Type, T_BinaryPredicate, T_Allocator> TIterator;
  //! Constant binary tree iterator type.
  typedef CBinTreeIteratorConst<T_Type, T_BinaryPredicate, T_Allocator> TIteratorConst;

  //! Container binary predicate type.
  typedef T_BinaryPredicate TLessThanPredicate;
  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  /*!
      Create an empty binary tree.

      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTree(T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize binary tree with one item.
  /*!
      Create an empty binary tree, then insert item into it as a root node.

      \param a_crItem - Constant reference to the item to insert.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTree(const T_Type& a_crItem, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBinTree class.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTree(const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CBinTree();

  //! Operator: Assign another CBinTree class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBinTree class.
      \return Reference to the current class instance.
  */
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& operator = (const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance);

  //! Operator: Insert item into binary tree.
  /*!
      \param a_crItem - Constant reference to the item to insert.
      \return Reference to the current class instance.
  */
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& operator += (const T_Type& a_crItem);
  //! Operator: Insert another binary tree into binary tree.
  /*!
      \param a_crBinTree - Constant reference to the binary tree to insert.
      \return Reference to the current class instance.
  */
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& operator += (const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crBinTree);
  //! Operator: Remove item from binary tree.
  /*!
      \param a_crItem - Constant reference to the item to remove.
      \return Reference to the current class instance.
  */
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& operator -= (const T_Type& a_crItem);
  //! Operator: Remove another binary tree from binary tree.
  /*!
      \param a_crBinTree - Constant reference to the binary tree to remove.
      \return Reference to the current class instance.
  */
  CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& operator -= (const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crBinTree);

  //! Operator: Find non constant iterator with given value in binary tree.
  /*!
      \param a_crItem - Constant reference to the searching item.
      \return Non constant iterator with given value or invalid empty iterator.
  */
  TIterator operator [] (const T_Type& a_crItem);
  //! Operator: Find constant iterator with given value in binary tree.
  /*!
      \param a_crItem - Constant reference to the searching item.
      \return Constant iterator with given value or invalid empty iterator.
  */
  TIteratorConst operator [] (const T_Type& a_crItem) const;

  //! Set another CBinTree class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBinTree class.
      \return true  - if another binary tree was successfully set. \n
              false - if another binary tree was not successfully set. \n
  */
  Tbool set(const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance);

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IAccociative interface overriding methods.
  virtual Tbool insert(const T_Type& a_crItem);
  virtual Tbool insert(const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crBinTree);
  virtual Tbool remove(const T_Type& a_crItem, const Tbool a_cRemoveSame = false);
  virtual Tbool remove(const CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_crBinTree, const Tbool a_cRemoveSame = false);

  // IAccociativeConst interface overriding methods.
  virtual Tbool isLessThan(const T_Type& a_crItem1, const T_Type& a_crItem2) const;
  virtual TIterator      find(const T_Type& a_crItem);
  virtual TIteratorConst find(const T_Type& a_crItem) const;

  // IDequeConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;

  // ITreeConst interface overriding methods.
  virtual Tuint getRootCount() const;
  virtual TIterator      getItFirstRoot();
  virtual TIteratorConst getItFirstRoot() const;
  virtual TIterator      getItLastRoot();
  virtual TIteratorConst getItLastRoot() const;
  virtual TIterator      getItIndexRoot(const Tuint a_cIndex);
  virtual TIteratorConst getItIndexRoot(const Tuint a_cIndex) const;
  virtual TIterator      getItLeftmostChild();
  virtual TIteratorConst getItLeftmostChild() const;
  virtual TIterator      getItRightmostChild();
  virtual TIteratorConst getItRightmostChild() const;

  //! Serialization load CBinTree class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CBinTree class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CBinTree class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBinTree class instances.
  /*!
      \param a_rInstance - Reference to another CBinTree class instance.
  */
  void swap(CBinTree<T_Type, T_BinaryPredicate, T_Allocator>& a_rInstance);

protected:
  struct SBinTreeItem;                  //! Binary tree item structure.
  struct SBinTreeNode;                  //! Binary tree node structure.

  struct SBinTreeItem                   //! Binary tree item structure.
  {
  public:
    T_Type        m_Item;               //!< Binary tree item value.
    SBinTreeNode* m_pParent;            //!< Pointer to the parent binary tree node.
    SBinTreeItem* m_pPrev;              //!< Pointer to the previous tree item.
    SBinTreeItem* m_pNext;              //!< Pointer to the next tree item.

    //! Initialize binary tree node with the given item.
    /*!
        \param a_crItem - Initialized item.
    */
    SBinTreeItem(const T_Type& a_crItem);
  };

  struct SBinTreeNode                   //! Binary tree node structure.
  {
  public:
    SBinTreeItem* m_pFirstItem;         //!< Pointer to the binary tree first item.
    SBinTreeItem* m_pLastItem;          //!< Pointer to the binary tree last item.
    SBinTreeNode* m_pParent;            //!< Pointer to the parent binary tree node.
    SBinTreeNode* m_pLeft;              //!< Pointer to the left binary tree node.
    SBinTreeNode* m_pRight;             //!< Pointer to the right binary tree node.
    Tptr          m_pData;              //!< Pointer to the additional data.

    //! Initialize class constructor.
    /*!
        \param a_pItem - Pointer to the initialized item.
    */
    SBinTreeNode(SBinTreeItem* a_pItem);

    //! Swap two binary tree nodes.
    /*!
        \param a_pNode1 - Pointer to the first binary tree node.
        \param a_pNode2 - Pointer to the second binary tree node.
    */
    static void swap(SBinTreeNode* a_pNode1, SBinTreeNode* a_pNode2);
  };

  //! Balance binary tree after searching for a given binary tree item.
  /*!
      This method balance binary tree after searching new  binary  tree  item.
      For non balanced binary tree this method just search for a given  binary
      tree item, but in other binary trees it may be useful to  keep  tree  in
      balanced state.

      \param a_crItem - Constant reference to the searching item.
      \return Pointer to the found item, or NULL if we did not found given value.
  */
  virtual SBinTreeNode* findAndBalance(const T_Type& a_crItem) const;
  //! Balance binary tree after inserting new binary tree node.
  /*!
      This method balance binary tree after inserting new  binary  tree  node.
      For non balanced binary tree this method  does  nothing,  but  in  other
      binary trees it may be useful to keep tree in balanced state.

      Note that given binary tree node has already  linked  with  binary  tree
      structore.

      \param a_pNode - Pointer to the new inserted binary tree node.
      \return true  - if binary tree was balanced successfully. \n
              false - if binary tree was not balanced successfully. \n
  */
  virtual Tbool insertAndBalance(SBinTreeNode* a_pNode);
  //! Remove given binary tree node and then balance binary tree.
  /*!
      This method removes given node from binary tree and balance it. For  non
      balanced binary tree this method only removes given node, but  in  other
      binary trees it may be useful to keep tree in balanced state.

      Note that given binary tree node has already  linked  with  binary  tree
      structore.

      \param a_pNode - Pointer to the removed binary tree node.
      \return true  - if operation completed successfully. \n
              false - if operation did not completed successfully. \n
  */
  virtual Tbool removeAndBalance(SBinTreeNode* a_pNode);

  //! Get binary tree root node pointer.
  /*!
      \return Reference to the binary tree root node pointer.
  */
  SBinTreeNode*& getRootNode();
  //! Get binary tree root node pointer.
  /*!
      \return Reference to the binary tree root node pointer.
  */
  SBinTreeNode* const& getRootNode() const;

private:
  Tuint             m_Size;             //!< Number of items in binary tree.
  SBinTreeNode*     m_pRoot;            //!< Pointer to the binary tree root node.
  T_BinaryPredicate m_fLessThan;        //!< Current 'LessThan' binary predicate.
  T_Allocator       m_Allocator;        //!< Memory allocator.
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
//! Traits meta-class: non balanced binary tree container traits specialization.
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
class MTraitsContainer<NContainers::CBinTree<T_Type, T_BinaryPredicate, T_Allocator> > :
  public MType<NContainers::CBinTree<T_Type, T_BinaryPredicate, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst citerator;

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
#include <Depth/include/containers/iterators/CBinTreeIterator.hpp>
#include <Depth/include/containers/iterators/CBinTreeIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CBinTree.inl>
/*==========================================================================*/
//! \example example-containers-CBinTree.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CBinTree.cpp
/*==========================================================================*/
#endif
