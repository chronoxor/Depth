/*!
 *  \file    IDeque.hpp Base interface for all non constant deque based
 *           containers. It gives ability to manipulate with the non
 *           constant deque container.
 *  \brief   Non constant deque container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant deque container interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common containers
    VERSION:   1.0
    CREATED:   20.02.2006 03:55:04

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
#ifndef __IDEQUE_HPP__
#define __IDEQUE_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IQueue.hpp>
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
//! Non constant deque container interface.
/*!
    Non constant deque container is the base interface for  all  non  constant
    deque based containers. It gives ability to manipulate  the  non  constant
    deque container.

    Each non constant deque container should declare the following types:
    TType           - type of the deque container items;
    TContainer      - type of the deque container;
    TIterator       - type of the deque container non constant iterators.
    TIteratorConst  - type of the deque container constant iterators.

    \see NDepth::NContainers::CDeque
    \see NDepth::NContainers::CListDL
*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst>
class IDeque :
  public IQueue<T_Container, T_Type, T_Iterator, T_IteratorConst>
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
  IDeque();

public:
  //! Interface virtual destructor.
  virtual ~IDeque();

  //! Insert item into the queue container first position.
  /*!
      Method inserts item into  the  queue  container  first  position.  After
      inserting the item becomes the queue container first item.

      \param a_crItem - Constant reference to the item to insert.
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insertFirst(const TType& a_crItem) = 0;

  //! Remove item from the queue container last position.
  /*!
      Method removes item from the queue container last position. This  method
      does not save removed item.

      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeLast() = 0;
  //! Remove item from the queue container last position.
  /*!
      Method removes item from the queue container last position. This  method
      saves removed item into the given argument.

      \param a_rItem - Reference to the returned removed item.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeLast(TType& a_rItem) = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/IDeque.inl>
/*==========================================================================*/
#endif
