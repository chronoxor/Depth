/*!
 *  \file    IStack.hpp Base interface for all non constant stack based
 *           containers. It gives ability to manipulate with the non
 *           constant stack container.
 *  \brief   Non constant stack container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant stack container interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common containers
    VERSION:   1.0
    CREATED:   19.02.2006 20:02:26

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
#ifndef __ISTACK_HPP__
#define __ISTACK_HPP__
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
//! Non constant stack container interface.
/*!
    Non constant stack container is the base interface for  all  non  constant
    stack based containers. It gives ability to manipulate  the  non  constant
    stack container.

    Each non constant stack container should declare the following types:
    TType           - type of the stack container items;
    TContainer      - type of the stack container;
    TIterator       - type of the stack container non constant iterators.
    TIteratorConst  - type of the stack container constant iterators.

    \see NDepth::NContainers::CStack
*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst>
class IStack :
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
  IStack();

public:
  //! Interface virtual destructor.
  virtual ~IStack();

  //! Insert item into the top of the stack container.
  /*!
      Method inserts item into the top of the stack container. After inserting
      the item becomes the stack container top item.

      \param a_crItem - Constant reference to the item to insert.
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insertTop(const TType& a_crItem) = 0;

  //! Remove item from the top of the stack container.
  /*!
      Method removes item from the top of the  stack  container.  This  method
      does not save removed item.

      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeTop() = 0;
  //! Remove item from the top of the stack container.
  /*!
      Method removes item from the top of the  stack  container.  This  method
      saves removed item into the given argument.

      \param a_rItem - Reference to the returned removed item.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeTop(TType& a_rItem) = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/IStack.inl>
/*==========================================================================*/
#endif
