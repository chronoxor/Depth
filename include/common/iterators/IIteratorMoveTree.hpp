/*!
 *  \file    IIteratorMoveTree.hpp Base interface for all iterators that
 *           can do tree iteration movement.
 *  \brief   Base tree iterator movement interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base tree iterator movement interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common iterators
    VERSION:   1.0
    CREATED:   19.06.2006 23:56:37

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
#ifndef __IITERATORMOVETREE_HPP__
#define __IITERATORMOVETREE_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorMoveBackward.hpp>
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
//! Base tree iterator movement interface.
/*!
    Tree iterator is  the  base  movement  interface  for  all  tree  movement
    iterators. It gives ability to explore tree-based constructions.

    With help of this iterator you are able to:
    - Do previous/next sibling movement.
    - Check if current tree node is root one.
    - Get parrent node of the current one.
    - Get count of sibling nodes.
    - Get first, last, previous, next and indexed sibling tree node.
    - Get count of child nodes.
    - Get first, last and indexed child tree node.

    Note that  there  are  no  '==',  '!=',  '='  operators  defined  in  this
    interface, because of their returning types (which  have  to  be  same  as
    derived iterator). But in real tree moving  iterator  implementation it is
    highly recomended to implement them!

    Each iterator should declare the following types:
    TType      - type of the iterator value;
    TReturn    - return  type   of   the   iterator,  which  is  returned   by
                 'getValueRef()' and 'getValuePtr()' methods;
    TContainer - type of the iterator container.
    TIterator  - itself type of the iterator.
*/
template <class T_Iterator, typename T_Type, typename T_Return, class T_Container>
class IIteratorMoveTree :
  public IIteratorMoveBackward<T_Iterator, T_Type, T_Return, T_Container>
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
  IIteratorMoveTree();

public:
  //! Interface virtual destructor.
  virtual ~IIteratorMoveTree();

  //! Is current iterator points to the tree root node?
  /*!
      This method checks if current iterator points to the tree root node. Any
      root node has no parent one. So corresponding iterator to parent node of
      the root one will be invalid.

      \return true  - if current iterator points to the tree root node. \n
              false - if current iterator does not point to the tree root node. \n
  */
  virtual Tbool isRoot() const = 0;
  //! Get iterator to the root tree node.
  /*!
      If current node is  not  root,  method  returns  iterator  to  the  root
      (topmost parent) tree node. Otherwise, method returns current iterator.

      \return Iterator to the root tree node.
  */
  virtual TIterator getRoot() const = 0;
  //! Get iterator to the parent tree node.
  /*!
      If current node is not root, method returns iterator to the parent  tree
      node. Otherwise, method returns invalid empty iterator.

      \return Iterator to the parent tree node.
  */
  virtual TIterator getParent() const = 0;

  //! Get current sibling index.
  /*!
      Method returns index of the current node in sibling list.

      \return Current sibling index.
  */
  virtual Tuint getSiblingIndex() const = 0;
  //! Get count of nodes in sibling list of the current tree node.
  /*!
      Method returns count of nodes in sibling list of the current tree node.

      \return Count of nodes in sibling list.
  */
  virtual Tuint getSiblingsCount() const = 0;
  //! Get count of previous nodes to the current one in sibling list.
  /*!
      Method returns count of previous nodes to the  current  one  in  sibling
      list.

      \return Count of previous nodes to the current one in sibling list.
  */
  virtual Tuint getPrevSiblingsCount() const = 0;
  //! Get count of next nodes to the current one in sibling list.
  /*!
      Method returns count of next nodes to the current one in sibling list.

      \return Count of next nodes to the current one in sibling list.
  */
  virtual Tuint getNextSiblingsCount() const = 0;
  //! Get iterator to the first sibling node linked to the current tree node.
  /*!
      Method returns iterator to the first sibling node linked to the  current
      tree node. Otherwise, method returns invalid empty iterator.

      \return Iterator to the first sibling node linked to the current tree node.
  */
  virtual TIterator getFirstSibling() const = 0;
  //! Get iterator to the last sibling node linked to the current tree node.
  /*!
      Method returns iterator to the last sibling node linked to  the  current
      tree node. Otherwise, method returns invalid empty iterator.

      \return Iterator to the last sibling node linked to the current tree node.
  */
  virtual TIterator getLastSibling() const = 0;
  //! Get iterator to the previous sibling node linked to the current tree node.
  /*!
      Method returns iterator to the  previous  sibling  node  linked  to  the
      current tree node. Otherwise, method returns invalid empty iterator.

      \return Iterator to the previous sibling node linked to the current tree node.
  */
  virtual TIterator getPrevSibling() const = 0;
  //! Get iterator to the next sibling node linked to the current tree node.
  /*!
      Method returns iterator to the next sibling node linked to  the  current
      tree node. Otherwise, method returns invalid empty iterator.

      \return Iterator to the next sibling node linked to the current tree node.
  */
  virtual TIterator getNextSibling() const = 0;
  //! Get iterator to the indexed sibling node linked to the current tree node.
  /*!
      Method returns iterator to  the  indexed  sibling  node  linked  to  the
      current tree node. Otherwise, method returns invalid empty iterator.

      \param a_cIndex - Index to the sibling node.
      \return Iterator to the indexed sibling node linked to the current tree node.
  */
  virtual TIterator getIndexSibling(const Tuint a_cIndex) const = 0;

  //! Get count of child nodes linked to the current tree node.
  /*!
      Method returns count of child nodes linked to the current tree node.

      \return Count of child nodes linked to the current tree node.
  */
  virtual Tuint getChildCount() const = 0;
  //! Get iterator to the first child node linked to the current tree node.
  /*!
      If current node has child nodes, method returns iterator  to  the  first
      child node linked to the current tree node.  Otherwise,  method  returns
      invalid empty iterator.

      \return Iterator to the first child node linked to the current tree node.
  */
  virtual TIterator getFirstChild() const = 0;
  //! Get iterator to the last child node linked to the current tree node.
  /*!
      If current node has child nodes, method returns  iterator  to  the  last
      child node linked to the current tree node.  Otherwise,  method  returns
      invalid empty iterator.

      \return Iterator to the last child node linked to the current tree node.
  */
  virtual TIterator getLastChild() const = 0;
  //! Get iterator to the indexed child node linked to the current tree node.
  /*!
      If current node has child nodes, method returns iterator to the  indexed
      child node linked to the current tree node.  Otherwise,  method  returns
      invalid empty iterator.

      \param a_cIndex - Index to the child node.
      \return Iterator to the indexed child node linked to the current tree node.
  */
  virtual TIterator getIndexChild(const Tuint a_cIndex) const = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorMoveTree.inl>
/*==========================================================================*/
#endif
