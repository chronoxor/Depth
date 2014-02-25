/*!
 *  \file    ITree.hpp Base interface for all non constant tree based
 *           containers. It gives ability to manipulate with the non
 *           constant tree container.
 *  \brief   Non constant tree container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant tree container interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common containers
    VERSION:   1.0
    CREATED:   20.02.2006 02:08:36

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
#ifndef __ITREE_HPP__
#define __ITREE_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IContainer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Non constant tree container interface.
/*!
    Non constant tree container is the base interface  for  all  non  constant
    tree based containers. It gives ability to  manipulate  the  non  constant
    tree container.

    Each non constant tree container should declare the following types:
    TType           - type of the tree container items;
    TContainer      - type of the tree container;
    TIterator       - type of the tree container non constant iterators.
    TIteratorConst  - type of the tree container constant iterators.

    \see NDepth::NContainers::CTree
*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst>
class ITree :
  public IContainer<T_Container, T_Type, T_Iterator, T_IteratorConst>
{
public:
  //! Container items type.
  typedef T_Type TType;
  //! Container type.
  typedef T_Container TContainer;
  //! Non constant iterator type.
  typedef T_Iterator TIterator;
  //! Constant iterator type.
  typedef T_IteratorConst TIteratorConst;

protected:
  //! Default interface protected constructor.
  ITree();

public:
  //! Interface virtual destructor.
  virtual ~ITree();

  //! Insert new item into the tree container first root position.
  /*!
      Method inserts new item into the tree  container  first  root  position.
      After inserting the item becomes the tree container first root item.

      \param a_crItem - Constant reference to the item to insert.
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insertFirstRoot(const TType& a_crItem) = 0;
  //! Insert new item into the tree container last root position.
  /*!
      Method inserts new item into the  tree  container  last  root  position.
      After inserting the item becomes the tree container last root item.

      \param a_crItem - Constant reference to the item to insert.
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insertLastRoot(const TType& a_crItem) = 0;
  //! Insert new item into the tree container indexed root position.
  /*!
      Method inserts new item into the tree container indexed root position.

      \param a_cIndex - Index to the tree root node.
      \param a_crItem - Constant reference to the item to insert.
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insertIndexRoot(const Tuint a_cIndex, const TType& a_crItem) = 0;

  //! Insert sub-tree into the tree container first root position.
  /*!
      Method inserts sub-tree into the tree  container  first  root  position.
      Note that after inserting given sub-tree will be empty.

      \param a_rSubTree - Reference to inserted sub-tree.
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insertSubTreeFirstRoot(TContainer& a_rSubTree) = 0;
  //! Insert sub-tree into the tree container last root position.
  /*!
      Method inserts sub-tree into the tree container last root position. Note
      that after inserting given sub-tree will be empty.

      \param a_rSubTree - Reference to inserted sub-tree.
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insertSubTreeLastRoot(TContainer& a_rSubTree) = 0;
  //! Insert sub-tree into the tree container indexed root position.
  /*!
      Method inserts sub-tree into the tree container indexed  root  position.
      Note that after inserting given sub-tree will be empty.

      \param a_cIndex - Index to the tree root node.
      \param a_rSubTree - Reference to inserted sub-tree.
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insertSubTreeIndexRoot(const Tuint a_cIndex, TContainer& a_rSubTree) = 0;

  //! Remove item from the tree container first root position.
  /*!
      Method removes item from the tree container first  root  position.  This
      method does not save removed item.

      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeFirstRoot() = 0;
  //! Remove item from the tree container first root position.
  /*!
      Method removes item from the tree container first  root  position.  This
      method saves removed item into the given argument.

      \param a_rItem - Reference to the returned removed item.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeFirstRoot(TType& a_rItem) = 0;

  //! Remove item from the tree container last root position.
  /*!
      Method removes item from the tree container  last  root  position.  This
      method does not save removed item.

      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeLastRoot() = 0;
  //! Remove item from the tree container last root position.
  /*!
      Method removes item from the tree container  last  root  position.  This
      method saves removed item into the given argument.

      \param a_rItem - Reference to the returned removed item.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeLastRoot(TType& a_rItem) = 0;

  //! Remove item from the tree container indexed root position.
  /*!
      Method removes item from the tree container indexed root position.  This
      method does not save removed item.

      \param a_cIndex - Index to the tree root node.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeIndexRoot(const Tuint a_cIndex) = 0;
  //! Remove item from the tree container indexed root position.
  /*!
      Method removes item from the tree container indexed root position.  This
      method saves removed item into the given argument.

      \param a_cIndex - Index to the tree root node.
      \param a_rItem - Reference to the returned removed item.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeIndexRoot(const Tuint a_cIndex, TType& a_rItem) = 0;

  //! Extract sub-tree from the first tree position.
  /*!
      Method extracts sub-tree from the  first  tree  position  and  its  next
      siblings. Corresponding tree nodes will be unlinked  from  current  tree
      and will be linked to the given tree as its root nodes. If given tree is
      not empty, it will be cleared.

      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_NextSiblingCount - Count of next siblings to extract (default is 0).
      \return Count of extracted next siblings with the first one.
  */
  virtual Tuint subTreeFirstRoot(TContainer& a_rSubTree, const Tuint a_NextSiblingCount = 0) = 0;
  //! Extract sub-tree from the last tree position.
  /*!
      Method extracts sub-tree from the last tree position  and  its  previous
      siblings. Corresponding tree nodes will be unlinked  from  current  tree
      and will be linked to the given tree as its root nodes. If given tree is
      not empty, it will be cleared.

      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_PrevSiblingCount - Count of previous siblings to extract (default is 0).
      \return Count of extracted previous siblings with the last one.
  */
  virtual Tuint subTreeLastRoot(TContainer& a_rSubTree, const Tuint a_PrevSiblingCount = 0) = 0;
  //! Extract sub-tree from the indexed tree position.
  /*!
      Method extracts sub-tree from the indexed tree position and its previous
      and next siblings.  Corresponding  tree  nodes  will  be  unlinked  from
      current tree and will be linked to the given tree as its root nodes.  If
      given tree is not empty, it will be cleared.

      \param a_cIndex - Index to the tree root node.
      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_PrevSiblingCount - Count of previous siblings to extract (default is 0).
      \param a_NextSiblingCount - Count of next siblings to extract (default is 0).
      \return Count of extracted siblings.
  */
  virtual Tuint subTreeIndexRoot(const Tuint a_cIndex, TContainer& a_rSubTree, const Tuint a_PrevSiblingCount = 0, const Tuint a_NextSiblingCount = 0) = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/ITree.inl>
/*==========================================================================*/
#endif
