/*!
 *  \file    ITreeConst.hpp Base interface for all constant tree based
 *           containers. It gives ability to manipulate the constant tree
 *           container.
 *  \brief   Constant tree container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant tree container interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common containers
    VERSION:   1.0
    CREATED:   20.02.2006 02:12:52

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
#ifndef __ITREECONST_HPP__
#define __ITREECONST_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IContainerConst.hpp>
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
//! Constant tree container interface.
/*!
    Constant tree container is the base interface for all constant tree  based
    containers. It gives ability to manipulate the constant tree container.

    Each constant tree container should declare the following types:
    TType           - type of the tree container items;
    TContainer      - type of the tree container;
    TIteratorConst  - type of the constant tree iterators.

    \see NDepth::NContainers::CTree
*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst>
class ITreeConst :
  public IContainerConst<T_Container, T_Type, T_Iterator, T_IteratorConst>
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
  ITreeConst();

public:
  //! Interface virtual destructor.
  virtual ~ITreeConst();

  //! Get count of nodes in the root list of the current tree.
  /*!
      Method returns count of nodes in the root list of the current tree.

      \return Count of nodes in the root list.
  */
  virtual Tuint getRootCount() const = 0;

  //! Get non constant iterator to the tree container first root item.
  /*!
      Method returns non constant iterator to the tree  container  first  root
      item.

      \return Non constant iterator to the tree container first root item.
  */
  virtual TIterator getItFirstRoot() = 0;
  //! Get constant iterator to the tree container first root item.
  /*!
      Method returns constant iterator to the tree container first root item.

      \return Constant iterator to the tree container first root item.
  */
  virtual TIteratorConst getItFirstRoot() const = 0;

  //! Get non constant iterator to the tree container last root item.
  /*!
      Method returns non constant iterator to the  tree  container  last  root
      item.

      \return Non constant iterator to the tree container last root item.
  */
  virtual TIterator getItLastRoot() = 0;
  //! Get constant iterator to the tree container last root item.
  /*!
      Method returns constant iterator to the tree container last root item.

      \return Constant iterator to the tree container last root item.
  */
  virtual TIteratorConst getItLastRoot() const = 0;

  //! Get non constant iterator to the tree container indexed root item.
  /*!
      Method returns non constant iterator to the tree container indexed  root
      item.

      \param a_cIndex - Index to the tree root node.
      \return Non constant iterator to the tree container indexed root item.
  */
  virtual TIterator getItIndexRoot(const Tuint a_cIndex) = 0;
  //! Get constant iterator to the tree container indexed root item.
  /*!
      Method returns constant iterator to  the  tree  container  indexed  root
     item.

      \param a_cIndex - Index to the tree root node.
      \return Constant iterator to the tree container indexed root item.
  */
  virtual TIteratorConst getItIndexRoot(const Tuint a_cIndex) const = 0;

  //! Get non constant iterator to the tree container leftmost child item.
  /*!
      Method returns non constant iterator  to  the  tree  container  leftmost
      child item.

      \return Non constant iterator to the tree container leftmost child item.
  */
  virtual TIterator getItLeftmostChild() = 0;
  //! Get constant iterator to the tree container leftmost child item.
  /*!
      Method returns constant iterator to the tree  container  leftmost  child
      item.

      \return Constant iterator to the tree container leftmost child item.
  */
  virtual TIteratorConst getItLeftmostChild() const = 0;

  //! Get non constant iterator to the tree container rightmost child item.
  /*!
      Method returns non constant iterator to  the  tree  container  rightmost
      child item.

      \return Non constant iterator to the tree container rightmost child item.
  */
  virtual TIterator getItRightmostChild() = 0;
  //! Get constant iterator to the tree container rightmost child item.
  /*!
      Method returns constant iterator to the tree container  rightmost  child
      item.

      \return Constant iterator to the tree container rightmost child item.
  */
  virtual TIteratorConst getItRightmostChild() const = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/ITreeConst.inl>
/*==========================================================================*/
#endif
