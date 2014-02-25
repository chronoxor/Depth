/*!
 *  \file    CTree.hpp Template tree container class. Tree represents
 *           container that can keep items in a tree-based form.
 *  \brief   Template tree container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template tree container class.

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
#ifndef __CTREE_HPP__
#define __CTREE_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/ITree.hpp>
#include <Depth/include/common/containers/ITreeConst.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
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
template <typename T_Type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CTreeIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CTreeIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template tree container class.
/*!
    Tree container keeps items in a tree form. Each item contains links to the
    parent item, to the sibling item list and to the child item list.

    Each tree node contain links to other nodes,  so  this  complex  structure
    represented as a tree.

    To modify tree you should use tree iterators. Each of tree iterator  gives
    ability to insert or remove items (nodes) from tree. Also with the help of
    the iterators you can perform different tree traverses.

    There are several kinds of tree iterators which differs by their traversal
    algorithms:
    \li parent node iteration;
    \li sibling node iteration;
    \li child node iteration;
    \li bread-first iteration;
    \li depth-first iteration;
    \li fixed-depth iteration.

    Default tree iterators use depth-first iteration method.

    <b>Overview.</b>\n
    \image html Tree.png "Tree."
    In computer science, a tree is a widely-used computer data structure  that
    emulates a tree structure with a set of linked nodes. It is a special case
    of a graph. Each node has zero or more child nodes, which are below it  in
    the tree (by convention in computer science, trees grow down - not  up  as
    they do in nature). A node that has a child is called the  child's  parent
    node. A child has at most one parent; The topmost node in a tree is called
    the root node. Being the  topmost  node,  the  root  node  will  not  have
    parents. Nodes at the bottom most level of the tree are called leaf nodes.
    Since they are at the bottom most level, they will not have any children.

    In graph theory, a tree is a connected acyclic graph.  A  rooted  tree  is
    such a graph with a vertex singled out as the root. In this case, any  two
    vertices connected by an edge  inherit  a  parent-child  relationship.  An
    acyclic graph with multiple connected components or a set of rooted  trees
    is sometimes called a forest.

    Stepping through the items of a tree, by means of the connections  between
    parents and children, is called walking the tree, and the action is a walk
    of the tree. Often, an operation might be performed when a pointer arrives
    at a particular node. A walk in which each parent node is traversed before
    its children is called a pre-order walk; a walk in which the children  are
    traversed before their  respective  parents  are  traversed  is  called  a
    post-order walk.  See  tree  traversal  for  a  discussion  of  pre-order,
    in-order and post-order traversal.

    Common operations on trees are:
    \li Enumerating all the items;
    \li Searching for an item;
    \li Adding a new item at a certain position on the tree;
    \li Deleting an item;
    \li Removing a whole section of a tree (called pruning);
    \li Adding a whole section to a tree (called grafting);
    \li Finding the root for any node.

    Common uses for trees are to:
    \li Manipulate hierarchical data;
    \li Make information easy to search (see also: tree search algorithm);
    \li Manipulate sorted lists of data.

    <b>References.</b>\n
    \li Donald Knuth. The Art of Computer Programming: Fundamental Algorithms,
        Third Edition. Addison-Wesley, 1997. ISBN 0-201-89683-4 . Section 2.3:
        Trees, pp.308-423.
    \li Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford
        Stein. Introduction to  Algorithms,  Second  Edition.  MIT  Press  and
        McGraw-Hill, 2001. ISBN 0-262-03293-7  .  Section  10.4:  Representing
        rooted  trees,  pp.214-217.  Chapters  12-14  (Binary  Search   Trees,
        Red-Black Trees, Augmenting Data Structures), pp.253-320.

    <b>Taken from:</b>\n
    Tree (data structure) from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Tree_data_structure
*/
template <typename T_Type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CTree :
  public NCommon::NContainers::ITree<CTree<T_Type, T_Allocator>, T_Type, CTreeIterator<T_Type, T_Allocator>, CTreeIteratorConst<T_Type, T_Allocator> >,
  public NCommon::NContainers::ITreeConst<CTree<T_Type, T_Allocator>, T_Type, CTreeIterator<T_Type, T_Allocator>, CTreeIteratorConst<T_Type, T_Allocator> >
{
  // Friend class: Tree iterator class (CTreeIterator).
  friend class CTreeIterator<T_Type, T_Allocator>;
  // Friend class: Constant tree iterator class (CTreeIteratorConst).
  friend class CTreeIteratorConst<T_Type, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CTree<T_Type, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CTree class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef T_Type TType;
  //! Container type.
  typedef CTree<T_Type, T_Allocator> TContainer;
  //! Non constant tree iterator type.
  typedef CTreeIterator<T_Type, T_Allocator> TIterator;
  //! Constant tree iterator type.
  typedef CTreeIteratorConst<T_Type, T_Allocator> TIteratorConst;

  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  /*!
      Create an empty tree.

      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CTree(const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize tree with one item.
  /*!
      Create an empty tree, then insert item into it as a root node.

      \param a_crItem - Constant reference to the item to insert.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CTree(const T_Type& a_crItem, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTree class.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CTree(const CTree<T_Type, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CTree();

  //! Operator: Assign another CTree class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTree class.
      \return Reference to the current class instance.
  */
  CTree<T_Type, T_Allocator>& operator = (const CTree<T_Type, T_Allocator>& a_crInstance);

  //! Set another CTree class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTree class.
      \return true  - if another tree was successfully set. \n
              false - if another tree was not successfully set. \n
  */
  Tbool set(const CTree<T_Type, T_Allocator>& a_crInstance);

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // ITree interface overriding methods.
  virtual Tbool insertFirstRoot(const T_Type& a_crItem);
  virtual Tbool insertLastRoot(const T_Type& a_crItem);
  virtual Tbool insertIndexRoot(const Tuint a_cIndex, const T_Type& a_crItem);
  virtual Tbool insertSubTreeFirstRoot(CTree<T_Type, T_Allocator>& a_rSubTree);
  virtual Tbool insertSubTreeLastRoot(CTree<T_Type, T_Allocator>& a_rSubTree);
  virtual Tbool insertSubTreeIndexRoot(const Tuint a_cIndex, CTree<T_Type, T_Allocator>& a_rSubTree);
  virtual Tbool removeFirstRoot();
  virtual Tbool removeFirstRoot(T_Type& a_rItem);
  virtual Tbool removeLastRoot();
  virtual Tbool removeLastRoot(T_Type& a_rItem);
  virtual Tbool removeIndexRoot(const Tuint a_cIndex);
  virtual Tbool removeIndexRoot(const Tuint a_cIndex, T_Type& a_rItem);
  virtual Tuint subTreeFirstRoot(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_NextSiblingCount = 0);
  virtual Tuint subTreeLastRoot(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount = 0);
  virtual Tuint subTreeIndexRoot(const Tuint a_cIndex, CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount = 0, const Tuint a_NextSiblingCount = 0);

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

  //! Serialization load CTree class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CTree class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CTree class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTree class instances.
  /*!
      \param a_rInstance - Reference to another CTree class instance.
  */
  void swap(CTree<T_Type, T_Allocator>& a_rInstance);

protected:
  struct STreeNode                      //! Tree node structure.
  {
  public:
    T_Type m_Item;                      //!< Tree item value.
    STreeNode* m_pParent;               //!< Pointer to the parent tree node.
    STreeNode* m_pPrevSibling;          //!< Pointer to the previous sibling tree node.
    STreeNode* m_pNextSibling;          //!< Pointer to the next sibling tree node.
    STreeNode* m_pFirstChild;           //!< Pointer to the first child tree node.
    STreeNode* m_pLastChild;            //!< Pointer to the last child tree node.

    //! Initialize tree node with the given item.
    /*!
        \param a_crItem - Initialized item.
    */
    STreeNode(const T_Type& a_crItem);

    //! Get count of all tree nodes in the current one.
    /*!
        This method calculates full count of tree nodes, which  are  contained
        by the current node. This count also includes current node.

        \return Count of all nodes, which are contained by the current node.
    */
    Tuint getAllCount() const;
    //! Get count of child tree nodes in the current one.
    /*!
        This method calculates count of child tree nodes, which are  contained
        by the current node.

        \return Count of child nodes, which are contained by the current node.
    */
    Tuint getChildCount() const;

    //! Link new node with given parent and child node.
    /*!
        This method helps to insert new parent node. It links this  node  with
        old parent node and its child. Current  node  will  be  inserted  just
        between parent node and child one.

        \param a_pParent - Pointer to the parent node.
        \param a_pChild - Pointer to the child node.
    */
    void link(STreeNode* a_pParent, STreeNode* a_pChild);

    //! Link nodes in tree structure.
    /*!
        This method helps to insert new sibling nodes.  It  links  this  nodes
        with old parent node and  two  sibling  nodes.  Given  nodes  will  be
        inserted just between two sibling nodes and will be connected  to  the
        parent node.

        \param a_pParent - Pointer to the parent node.
        \param a_pPrevSibling - Pointer to the previous sibling node.
        \param a_pNextSibling - Pointer to the next sibling node.
        \param a_pNewFirstSibling - Pointer to the new first sibling node.
        \param a_pNewLastSibling - Pointer to the new last sibling node.
    */
    static void link(STreeNode* a_pParent, STreeNode* a_pPrevSibling, STreeNode* a_pNextSibling, STreeNode* a_pNewFirstSibling, STreeNode* a_pNewLastSibling);
    //! Unlink nodes from tree structure.
    /*!
        This method helps to remove  sibling  nodes.  It  restore  links  with
        previous and next sibling nodes and update parent links.

        \param a_pParent - Pointer to the parent node.
        \param a_pPrevSibling - Pointer to the previous sibling node.
        \param a_pNextSibling - Pointer to the next sibling node.
    */
    static void unlink(STreeNode* a_pParent, STreeNode* a_pPrevSibling, STreeNode* a_pNextSibling);

    //! Copy child nodes from source tree to destination one.
    /*!
        This method recursively copies all child nodes from source  tree  node
        to the destination one.

        \param a_pTree - Pointer to the instance of the CTree class.
        \param a_pDstNode - Pointer to the destination tree node.
        \param a_cpSrcNode - Constant pointer to the source tree node.
        \return true  - if copy operation completed successfully. \n
                false - if copy operation did not completed successfully. \n
    */
    static Tbool copy(CTree<T_Type, T_Allocator>* a_pTree, STreeNode* a_pDstNode, const STreeNode* a_cpSrcNode);

    //! Serialization load CTree class instance.
    /*!
        This method recursively loads all child nodes from tree node from  the
        archive.

        \param a_rArchive - Reference to the serialization archive.
        \param a_pTree - Pointer to the instance of the CTree class.
        \param a_pParentNode - Pointer to the parent tree node.
        \return true  - if serialization has been successfully done. \n
                false - if serialization has not been successfully done. \n
    */
    template <class T_Archive>
    static Tbool load(T_Archive& a_rArchive, CTree<T_Type, T_Allocator>* a_pTree, STreeNode* a_pParentNode);
    //! Serialization save CTree class instance.
    /*!
        This method recursively saves all child nodes from tree node into  the
        archive.

        \param a_rArchive - Reference to the serialization archive.
        \param a_cpTree - Constant pointer to the instance of the CTree class.
        \param a_cpNode - Constant pointer to the tree node.
        \return true  - if serialization has been successfully done. \n
                false - if serialization has not been successfully done. \n
    */
    template <class T_Archive>
    static Tbool save(T_Archive& a_rArchive, const CTree<T_Type, T_Allocator>* a_cpTree, const STreeNode* a_cpNode);
  };

private:
  Tuint       m_Size;                   //!< Number of items in tree.
  STreeNode*  m_pFirstRoot;             //!< Pointer to the first tree root node.
  STreeNode*  m_pLastRoot;              //!< Pointer to the last tree root node.
  T_Allocator m_Allocator;              //!< Memory allocator.
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
//! Traits meta-class: tree container traits specialization.
template <typename T_Type, class T_Allocator>
class MTraitsContainer<NContainers::CTree<T_Type, T_Allocator> > :
  public MType<NContainers::CTree<T_Type, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CTree<T_Type, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CTree<T_Type, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CTree<T_Type, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CTree<T_Type, T_Allocator>::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = false; //!< Is container non constant queue?
  static const Tbool isQueueConst       = false; //!< Is container constant queue?
  static const Tbool isDeque            = false; //!< Is container non constant deque?
  static const Tbool isDequeConst       = false; //!< Is container constant deque?
  static const Tbool isRandom           = false; //!< Is container non constant random?
  static const Tbool isRandomConst      = false; //!< Is container constant random?
  static const Tbool isAssociative      = false; //!< Is container non constant associative?
  static const Tbool isAssociativeConst = false; //!< Is container constant associative?
  static const Tbool isTree             = true;  //!< Is container non constant tree?
  static const Tbool isTreeConst        = true;  //!< Is container constant tree?
  static const Tbool isGraph            = false; //!< Is container non constant graph?
  static const Tbool isGraphConst       = false; //!< Is container constant graph?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CTreeIterator.hpp>
#include <Depth/include/containers/iterators/CTreeIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CTree.inl>
/*==========================================================================*/
//! \example example-containers-CTree.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CTree.cpp
/*==========================================================================*/
#endif
