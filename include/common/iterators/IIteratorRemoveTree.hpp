/*!
 *  \file    IIteratorRemoveTree.hpp Base interface for all iterators that
 *           can remove items from tree-based container.
 *  \brief   Base tree iterator insert interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base tree iterator remove interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common iterators
    VERSION:   1.0
    CREATED:   25.07.2006 23:09:26

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
#ifndef __IITERATORREMOVETREE_HPP__
#define __IITERATORREMOVETREE_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorRemoveBackward.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Base tree iterator remove interface.
/*!
    Tree iterator is the base remove interface for all tree remove  iterators.
    It gives ability to remove items from tree-based constructions.

    With help of this iterator you are able to:
    - Remove current/first/last/previous/next/indexed/all sibling nodes.
    - Remove first/last/indexed/all child nodes.
    - Extract sub-tree from current node.

    Note that  there  are  no  '==',  '!=',  '='  operators  defined  in  this
    interface, because of their returning types (which  have  to  be  same  as
    derived iterator). But in real tree removing iterator implementation it is
    highly recomended to implement them!

    Each iterator should declare the following types:
    TType      - type of the iterator value;
    TReturn    - return  type   of   the   iterator,  which  is  returned   by
                 'getValueRef()' and 'getValuePtr()' methods;
    TContainer - type of the iterator container.
    TIterator  - itself type of the iterator.
*/
template <class T_Iterator, typename T_Type, typename T_Return, class T_Container>
class IIteratorRemoveTree :
  public IIteratorRemoveBackward<T_Iterator, T_Type, T_Return, T_Container>
{
public:
  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef T_Return TReturn;
  //! Iterator container type.
  typedef T_Container TContainer;
  //! Iterator itself type.
  typedef T_Iterator TIterator;

protected:
  //! Default interface protected constructor.
  IIteratorRemoveTree();

public:
  //! Interface virtual destructor.
  virtual ~IIteratorRemoveTree();

  //! Remove tree item from the first sibling iterator position.
  /*!
      With this method you can directly remove item  from  the  first  sibling
      place of the tree iterator. If current iterator position equals  to  the
      first sibling iterator position, then current iterator position will  be
      changed to the next sibling position, or to the parent one (if there are
      no next sibling position).

      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeFirstSibling() = 0;
  //! Remove tree item from the first sibling iterator position.
  /*!
      With this method you can directly remove item  from  the  first  sibling
      place of the tree iterator. If current iterator position equals  to  the
      first sibling iterator position, then current iterator position will  be
      changed to the next sibling position, or to the parent one (if there are
      no next sibling position).

      \param a_rItem - Reference to returning removed item.
      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeFirstSibling(TType& a_rItem) = 0;
  //! Remove tree item from the last sibling iterator position.
  /*!
      With this method you can directly remove  item  from  the  last  sibling
      place of the tree iterator. If current iterator position equals  to  the
      last sibling iterator position, then current iterator position  will  be
      changed to the previous sibling position, or to the parent one (if there
      are no previous sibling position).

      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeLastSibling() = 0;
  //! Remove tree item from the last sibling iterator position.
  /*!
      With this method you can directly remove  item  from  the  last  sibling
      place of the tree iterator. If current iterator position equals  to  the
      first sibling iterator position, then current iterator position will  be
      changed to the previous sibling position, or to the parent one (if there
      are no previous sibling position).

      \param a_rItem - Reference to returning removed item.
      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeLastSibling(TType& a_rItem) = 0;
  //! Remove tree item from the previous sibling iterator position.
  /*!
      With this method you can directly  remove  item  from  previous  sibling
      place of the tree iterator.

      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removePrevSibling() = 0;
  //! Remove tree item from the previous sibling iterator position.
  /*!
      With this method you can directly  remove  item  from  previous  sibling
      place of the tree iterator.

      \param a_rItem - Reference to returning removed item.
      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removePrevSibling(TType& a_rItem) = 0;
  //! Remove tree item from the next sibling iterator position.
  /*!
      With this method you can directly remove item from next sibling place of
      the tree iterator.

      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeNextSibling() = 0;
  //! Remove tree item from the next sibling iterator position.
  /*!
      With this method you can directly remove item from next sibling place of
      the tree iterator.

      \param a_rItem - Reference to returning removed item.
      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeNextSibling(TType& a_rItem) = 0;
  //! Remove tree item from the indexed sibling iterator position.
  /*!
      With this method you can directly remove item from indexed sibling place
      of the tree iterator. If current iterator position equals to the indexed
      sibling iterator  position,  then  current  iterator  position  will  be
      changed to the previous sibling position, or to the parent one (if there
      are no previous sibling position).

      \param a_cIndex - Child index to insert.
      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeIndexSibling(const Tuint a_cIndex) = 0;
  //! Remove tree item from the indexed sibling iterator position.
  /*!
      With this method you can directly remove item from indexed sibling place
      of the tree iterator. If current iterator position equals to the indexed
      sibling iterator  position,  then  current  iterator  position  will  be
      changed to the previous sibling position, or to the parent one (if there
      are no previous sibling position).

      \param a_cIndex - Child index to insert.
      \param a_rItem - Reference to returning removed item.
      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeIndexSibling(const Tuint a_cIndex, TType& a_rItem) = 0;

  //! Remove all sibling items from the current iterator position.
  /*!
      With this method you can directly remove  all  sibling  items  from  the
      current place of the tree iterator. After it current  iterator  position
      will point to the parent tree item.

      \return true  - if all sibling items was removed successfully. \n
              false - if all sibling items was not removed successfully. \n
  */
  virtual Tbool removeAllSiblings() = 0;

  //! Remove tree item from the first child iterator position.
  /*!
      With this method you can directly remove item from the first child place
      of the tree iterator.

      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeFirstChild() = 0;
  //! Remove tree item from the first child iterator position.
  /*!
      With this method you can directly remove item from the first child place
      of the tree iterator.

      \param a_rItem - Reference to returning removed item.
      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeFirstChild(TType& a_rItem) = 0;
  //! Remove tree item from the last child iterator position.
  /*!
      With this method you can directly remove item from the last child  place
      of the tree iterator.

      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeLastChild() = 0;
  //! Remove tree item from the last child iterator position.
  /*!
      With this method you can directly remove item from the last child  place
      of the tree iterator.

      \param a_rItem - Reference to returning removed item.
      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeLastChild(TType& a_rItem) = 0;
  //! Remove tree item from the indexed child iterator position.
  /*!
      With this method you can directly remove item from indexed  child  place
      of the tree iterator.

      \param a_cIndex - Child index to insert.
      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeIndexChild(const Tuint a_cIndex) = 0;
  //! Remove tree item from the indexed child iterator position.
  /*!
      With this method you can directly remove item from indexed  child  place
      of the tree iterator.

      \param a_cIndex - Child index to insert.
      \param a_rItem - Reference to returning removed item.
      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeIndexChild(const Tuint a_cIndex, TType& a_rItem) = 0;

  //! Remove all child items the from the current iterator position.
  /*!
      With this method you can  directly  remove  all  child  items  from  the
      current place of the tree iterator.

      \return true  - if all child items was removed successfully. \n
              false - if all child items was not removed successfully. \n
  */
  virtual Tbool removeAllChild() = 0;

  //! Extract sub-tree from the current sibling position.
  /*!
      Method extracts sub-tree from  the  current  sibling  position  and  its
      previous and next siblings. Corresponding tree nodes  will  be  unlinked
      from current tree and will be linked to  the  given  tree  as  its  root
      nodes. If given tree is not empty, it will  be  cleared.  Note  that  if
      current iterator points to the one of the extracted siblings it will  be
      owned by extracted sub-tree after sub-tree extracting.

      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_PrevSiblingCount - Count of previous siblings to extract (default is 0).
      \param a_NextSiblingCount - Count of next siblings to extract (default is 0).
      \return Count of extracted siblings.
  */
  virtual Tuint subTree(TContainer& a_rSubTree, const Tuint a_PrevSiblingCount = 0, const Tuint a_NextSiblingCount = 0) = 0;

  //! Extract sub-tree from the current and forward sibling position.
  /*!
      Method extracts sub-tree from the current sibling position and its  next
      siblings. Corresponding tree nodes will be unlinked  from  current  tree
      and will be linked to the given tree as its root nodes. If given tree is
      not empty, it will be cleared. Note that current iterator will be  owned
      by extracted sub-tree after sub-tree extracting.

      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_NextSiblingCount - Count of next siblings to extract (default is 0).
      \return Count of extracted next siblings.
  */
  virtual Tuint subTreeForwardSibling(TContainer& a_rSubTree, const Tuint a_NextSiblingCount = 0) = 0;
  //! Extract sub-tree from the current and backward sibling position.
  /*!
      Method extracts sub-tree from  the  current  sibling  position  and  its
      previous siblings.  Corresponding  tree  nodes  will  be  unlinked  from
      current tree and will be linked to the given tree as its root nodes.  If
      given tree is not empty, it will be cleared. Note that current  iterator
      will be owned by extracted sub-tree after sub-tree extracting.

      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_PrevSiblingCount - Count of previous siblings to extract (default is 0).
      \return Count of extracted previous siblings.
  */
  virtual Tuint subTreeBackwardSibling(TContainer& a_rSubTree, const Tuint a_PrevSiblingCount = 0) = 0;

  //! Extract sub-tree from the first sibling position.
  /*!
      Method extracts sub-tree from the first sibling position  and  its  next
      siblings. Corresponding tree nodes will be unlinked  from  current  tree
      and will be linked to the given tree as its root nodes. If given tree is
      not empty, it will be cleared. Note that if current iterator  points  to
      the one of the extracted siblings it will be owned by extracted sub-tree
      after sub-tree extracting.

      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_NextSiblingCount - Count of next siblings to extract (default is 0).
      \return Count of extracted next siblings with the first one.
  */
  virtual Tuint subTreeFirstSibling(TContainer& a_rSubTree, const Tuint a_NextSiblingCount = 0) = 0;
  //! Extract sub-tree from the last sibling position.
  /*!
      Method extracts sub-tree from the last sibling position and its previous
      siblings. Corresponding tree nodes will be unlinked  from  current  tree
      and will be linked to the given tree as its root nodes. If given tree is
      not empty, it will be cleared. Note that if current iterator  points  to
      the one of the extracted siblings it will be owned by extracted sub-tree
      after sub-tree extracting.

      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_PrevSiblingCount - Count of previous siblings to extract (default is 0).
      \return Count of extracted previous siblings with the last one.
  */
  virtual Tuint subTreeLastSibling(TContainer& a_rSubTree, const Tuint a_PrevSiblingCount = 0) = 0;

  //! Extract sub-tree from the previous sibling position.
  /*!
      Method extracts sub-tree from the  previous  sibling  position  and  its
      previous siblings.  Corresponding  tree  nodes  will  be  unlinked  from
      current tree and will be linked to the given tree as its root nodes.  If
      given tree is not empty, it  will  be  cleared.

      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_PrevSiblingCount - Count of previous siblings to extract (default is 0).
      \return Count of extracted previous siblings.
  */
  virtual Tuint subTreePrevSibling(TContainer& a_rSubTree, const Tuint a_PrevSiblingCount = 0) = 0;
  //! Extract sub-tree from the next sibling position.
  /*!
      Method extracts sub-tree from the previous sibling position and its next
      siblings. Corresponding tree nodes will be unlinked  from  current  tree
      and will be linked to the given tree as its root nodes. If given tree is
      not empty, it will be cleared.

      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_NextSiblingCount - Count of next siblings to extract (default is 0).
      \return Count of extracted next siblings.
  */
  virtual Tuint subTreeNextSibling(TContainer& a_rSubTree, const Tuint a_NextSiblingCount = 0) = 0;

  //! Extract sub-tree from the indexed sibling position.
  /*!
      Method extracts sub-tree from  the  indexed  sibling  position  and  its
      previous and next siblings. Corresponding tree nodes  will  be  unlinked
      from current tree and will be linked to  the  given  tree  as  its  root
      nodes. If given tree is not empty, it will  be  cleared.  Note  that  if
      current iterator points to the one of the extracted siblings it will  be
      owned by extracted sub-tree after sub-tree extracting.

      \param a_cIndex - Sibling index to extract.
      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_PrevSiblingCount - Count of previous siblings to extract (default is 0).
      \param a_NextSiblingCount - Count of next siblings to extract (default is 0).
      \return Count of extracted siblings.
  */
  virtual Tuint subTreeIndexSibling(const Tuint a_cIndex, TContainer& a_rSubTree, const Tuint a_PrevSiblingCount = 0, const Tuint a_NextSiblingCount = 0) = 0;

  //! Extract sub-tree from the all siblings.
  /*!
      Method extracts sub-tree from the all siblings of the current  iterator.
      Corresponding tree nodes will be unlinked from current tree and will  be
      linked to the given tree as its root nodes. If given tree is not  empty,
      it will be  cleared.  Note  that  current  iterator  will  be  owned  by
      extracted sub-tree after sub-tree extracting.

      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \return true  - if sub-tree was extracted successfully. \n
              false - if sub-tree was not extracted successfully. \n
  */
  virtual Tbool subTreeAllSiblings(TContainer& a_rSubTree) = 0;

  //! Extract sub-tree from the first child position.
  /*!
      Method extracts sub-tree from the first  child  position  and  its  next
      child siblings. Corresponding tree nodes will be unlinked  from  current
      tree and will be linked to the given tree as its root  nodes.  If  given
      tree is not empty, it will be cleared.

      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_NextSiblingCount - Count of next child siblings to extract (default is 0).
      \return Count of extracted next child siblings with the first child one.
  */
  virtual Tuint subTreeFirstChild(TContainer& a_rSubTree, const Tuint a_NextSiblingCount = 0) = 0;
  //! Extract sub-tree from the last child position.
  /*!
      Method extracts sub-tree from the last child position and  its  previous
      child siblings. Corresponding tree nodes will be unlinked  from  current
      tree and will be linked to the given tree as its root  nodes.  If  given
      tree is not empty, it will be cleared.

      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_PrevSiblingCount - Count of previous child siblings to extract (default is 0).
      \return Count of extracted previous child siblings with the last child one.
  */
  virtual Tuint subTreeLastChild(TContainer& a_rSubTree, const Tuint a_PrevSiblingCount = 0) = 0;

  //! Extract sub-tree from the indexed child position.
  /*!
      Method extracts  sub-tree  from  the  indexed  child  position  and  its
      previous and next child  siblings.  Corresponding  tree  nodes  will  be
      unlinked from current tree and will be linked to the given tree  as  its
      root nodes. If given tree is not empty, it will be cleared.

      \param a_cIndex - Child index to extract.
      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_PrevSiblingCount - Count of previous child siblings to extract (default is 0).
      \param a_NextSiblingCount - Count of next child siblings to extract (default is 0).
      \return Count of extracted child siblings.
  */
  virtual Tuint subTreeIndexChild(const Tuint a_cIndex, TContainer& a_rSubTree, const Tuint a_PrevSiblingCount = 0, const Tuint a_NextSiblingCount = 0) = 0;

  //! Extract sub-tree from the all child.
  /*!
      Method extracts sub-tree from the all child  of  the  current  iterator.
      Corresponding tree nodes will be unlinked from current tree and will  be
      linked to the given tree as its root nodes. If given tree is not  empty,
      it will be  cleared.

      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \return true  - if sub-tree was extracted successfully. \n
              false - if sub-tree was not extracted successfully. \n
  */
  virtual Tbool subTreeAllChild(TContainer& a_rSubTree) = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorRemoveTree.inl>
/*==========================================================================*/
#endif
