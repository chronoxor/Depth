/*!
 *  \file    IIteratorInsertTree.hpp Base interface for all iterators that
 *           can insert items into tree-based container.
 *  \brief   Base tree iterator insert interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base tree iterator insert interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common iterators
    VERSION:   1.0
    CREATED:   25.07.2006 20:06:37

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
#ifndef __IITERATORINSERTTREE_HPP__
#define __IITERATORINSERTTREE_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorInsertBackward.hpp>
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
//! Base tree iterator insert interface.
/*!
    Tree iterator is the base insert interface for all tree insert  iterators.
    It gives ability to insert items into tree-based constructions.

    With help of this iterator you are able to:
    - Insert new parrent node.
    - Insert new first/last/previous/next/indexed sibling nodes.
    - Insert new first/last/indexed child nodes.
    - Insert new first/last/previous/next/indexed sibling sub-trees.
    - Insert new first/last/indexed child sub-trees.
    - Flatten child nodes.

    Note that  there  are  no  '==',  '!=',  '='  operators  defined  in  this
    interface, because of their returning types (which  have  to  be  same  as
    derived iterator). But in real tree inserting iterator  implementation  it
    is highly recomended to implement them!

    Each iterator should declare the following types:
    TType      - type of the iterator value;
    TReturn    - return  type   of   the   iterator,  which  is  returned   by
                 'getValueRef()' and 'getValuePtr()' methods;
    TContainer - type of the iterator container.
    TIterator  - itself type of the iterator.
*/
template <class T_Iterator, typename T_Type, typename T_Return, class T_Container>
class IIteratorInsertTree :
  public IIteratorInsertBackward<T_Iterator, T_Type, T_Return, T_Container>
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
  IIteratorInsertTree();

public:
  //! Interface virtual destructor.
  virtual ~IIteratorInsertTree();

  //! Insert tree item into the parent iterator position.
  /*!
      With this method you can directly insert new item into the parent  place
      of the tree iterator. Second flag controls iterator behavior. If it set,
      current iterator position will be updated.

      \param a_crItem - Constant reference to inserted item.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if item was inserted successfully. \n
              false - if item was not inserted successfully. \n
  */
  virtual Tbool insertParent(const TType& a_crItem, const Tbool a_cUpdate = false) = 0;

  //! Insert tree item into the first sibling iterator position.
  /*!
      With this method you can directly insert new  item  into  first  sibling
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position will be updated.

      \param a_crItem - Constant reference to inserted item.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if item was inserted successfully. \n
              false - if item was not inserted successfully. \n
  */
  virtual Tbool insertFirstSibling(const TType& a_crItem, const Tbool a_cUpdate = false) = 0;
  //! Insert tree item into the last sibling iterator position.
  /*!
      With this method you can directly insert  new  item  into  last  sibling
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position will be updated.

      \param a_crItem - Constant reference to inserted item.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if item was inserted successfully. \n
              false - if item was not inserted successfully. \n
  */
  virtual Tbool insertLastSibling(const TType& a_crItem, const Tbool a_cUpdate = false) = 0;
  //! Insert tree item into the previous sibling iterator position.
  /*!
      With this method you can directly insert new item into previous  sibling
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position will be updated.

      \param a_crItem - Constant reference to inserted item.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if item was inserted successfully. \n
              false - if item was not inserted successfully. \n
  */
  virtual Tbool insertPrevSibling(const TType& a_crItem, const Tbool a_cUpdate = false) = 0;
  //! Insert tree item into the next sibling iterator position.
  /*!
      With this method you can directly insert  new  item  into  next  sibling
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position will be updated.

      \param a_crItem - Constant reference to inserted item.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if item was inserted successfully. \n
              false - if item was not inserted successfully. \n
  */
  virtual Tbool insertNextSibling(const TType& a_crItem, const Tbool a_cUpdate = false) = 0;
  //! Insert tree item into the indexed sibling iterator position.
  /*!
      With this method you can directly insert new item into  indexed  sibling
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position will be updated.

      \param a_cIndex - Child index to insert.
      \param a_crItem - Constant reference to inserted item.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if item was inserted successfully. \n
              false - if item was not inserted successfully. \n
  */
  virtual Tbool insertIndexSibling(const Tuint a_cIndex, const TType& a_crItem, const Tbool a_cUpdate = false) = 0;

  //! Insert tree item into the first child iterator position.
  /*!
      With this method you can directly insert new item into the  first  child
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position will be updated.

      \param a_crItem - Constant reference to inserted item.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if item was inserted successfully. \n
              false - if item was not inserted successfully. \n
  */
  virtual Tbool insertFirstChild(const TType& a_crItem, const Tbool a_cUpdate = false) = 0;
  //! Insert tree item into the last child iterator position.
  /*!
      With this method you can directly insert new item into  the  last  child
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position will be updated.

      \param a_crItem - Constant reference to inserted item.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if item was inserted successfully. \n
              false - if item was not inserted successfully. \n
  */
  virtual Tbool insertLastChild(const TType& a_crItem, const Tbool a_cUpdate = false) = 0;
  //! Insert tree item into the indexed child iterator position.
  /*!
      With this method you can directly insert new  item  into  indexed  child
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position will be updated.

      \param a_cIndex - Child index to insert.
      \param a_crItem - Constant reference to inserted item.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if item was inserted successfully. \n
              false - if item was not inserted successfully. \n
  */
  virtual Tbool insertIndexChild(const Tuint a_cIndex, const TType& a_crItem, const Tbool a_cUpdate = false) = 0;

  //! Insert sub-tree into the first sibling iterator position.
  /*!
      With this method you can directly insert  sub-tree  into  first  sibling
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position  will  be  updated.  Note  that  after
      inserting given sub-tree will be empty.

      \param a_rSubTree - Reference to inserted sub-tree.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if sub-tree was inserted successfully. \n
              false - if sub-tree was not inserted successfully. \n
  */
  virtual Tbool insertSubTreeFirstSibling(TContainer& a_rSubTree, const Tbool a_cUpdate = false) = 0;
  //! Insert sub-tree into the last sibling iterator position.
  /*!
      With this method you can directly  insert  sub-tree  into  last  sibling
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position  will  be  updated.  Note  that  after
      inserting given sub-tree will be empty.

      \param a_rSubTree - Reference to inserted sub-tree.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if sub-tree was inserted successfully. \n
              false - if sub-tree was not inserted successfully. \n
  */
  virtual Tbool insertSubTreeLastSibling(TContainer& a_rSubTree, const Tbool a_cUpdate = false) = 0;
  //! Insert sub-tree into the previous sibling iterator position.
  /*!
      With this method you can directly insert sub-tree into previous  sibling
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position  will  be  updated.  Note  that  after
      inserting given sub-tree will be empty.

      \param a_rSubTree - Reference to inserted sub-tree.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if sub-tree was inserted successfully. \n
              false - if sub-tree was not inserted successfully. \n
  */
  virtual Tbool insertSubTreePrevSibling(TContainer& a_rSubTree, const Tbool a_cUpdate = false) = 0;
  //! Insert sub-tree into the next sibling iterator position.
  /*!
      With this method you can directly  insert  sub-tree  into  next  sibling
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position  will  be  updated.  Note  that  after
      inserting given sub-tree will be empty.

      \param a_rSubTree - Reference to inserted sub-tree.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if sub-tree was inserted successfully. \n
              false - if sub-tree was not inserted successfully. \n
  */
  virtual Tbool insertSubTreeNextSibling(TContainer& a_rSubTree, const Tbool a_cUpdate = false) = 0;
  //! Insert sub-tree into the indexed sibling iterator position.
  /*!
      With this method you can directly insert sub-tree into  indexed  sibling
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position  will  be  updated.  Note  that  after
      inserting given sub-tree will be empty.

      \param a_cIndex - Child index to insert.
      \param a_rSubTree - Reference to inserted sub-tree.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if sub-tree was inserted successfully. \n
              false - if sub-tree was not inserted successfully. \n
  */
  virtual Tbool insertSubTreeIndexSibling(const Tuint a_cIndex, TContainer& a_rSubTree, const Tbool a_cUpdate = false) = 0;

  //! Insert sub-tree into the first child iterator position.
  /*!
      With this method you can directly insert sub-tree into the  first  child
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position  will  be  updated.  Note  that  after
      inserting given sub-tree will be empty.

      \param a_rSubTree - Reference to inserted sub-tree.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if sub-tree was inserted successfully. \n
              false - if sub-tree was not inserted successfully. \n
  */
  virtual Tbool insertSubTreeFirstChild(TContainer& a_rSubTree, const Tbool a_cUpdate = false) = 0;
  //! Insert sub-tree into the last child iterator position.
  /*!
      With this method you can directly insert sub-tree into  the  last  child
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position  will  be  updated.  Note  that  after
      inserting given sub-tree will be empty.

      \param a_rSubTree - Reference to inserted sub-tree.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if sub-tree was inserted successfully. \n
              false - if sub-tree was not inserted successfully. \n
  */
  virtual Tbool insertSubTreeLastChild(TContainer& a_rSubTree, const Tbool a_cUpdate = false) = 0;
  //! Insert sub-tree into the indexed child iterator position.
  /*!
      With this method you can directly insert  sub-tree  into  indexed  child
      place of the tree iterator. Second flag controls iterator  behavior.  If
      it set, current iterator position  will  be  updated.  Note  that  after
      inserting given sub-tree will be empty.

      \param a_cIndex - Child index to insert.
      \param a_rSubTree - Reference to inserted sub-tree.
      \param a_cUpdate - Iterator update flag (default is false).
      \return true  - if sub-tree was inserted successfully. \n
              false - if sub-tree was not inserted successfully. \n
  */
  virtual Tbool insertSubTreeIndexChild(const Tuint a_cIndex, TContainer& a_rSubTree, const Tbool a_cUpdate = false) = 0;

  //! Move child items from the current node to the next (previous) sibling items.
  /*!
      Method moves all child items from the current  tree  node  to  the  next
      (previous) position of sibling items.

      \param a_cChildToRight - Flag, that regulates new siblings position to the right of current node (default is true).
      \return true  - if current child nodes were flattened successfully. \n
              false - if current child nodes were not flattened successfully. \n
  */
  virtual Tbool flatten(const Tbool a_cChildToRight = true) = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorInsertTree.inl>
/*==========================================================================*/
#endif
