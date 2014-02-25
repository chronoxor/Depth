/*!
 *  \file    IStackConst.hpp Base interface for all constant stack based
 *           containers. It gives ability to manipulate the constant stack
 *           container.
 *  \brief   Constant stack container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant stack container interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common containers
    VERSION:   1.0
    CREATED:   19.02.2006 20:44:29

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
#ifndef __ISTACKCONST_HPP__
#define __ISTACKCONST_HPP__
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
//! Constant stack container interface.
/*!
    Constant stack container is the base  interface  for  all  constant  stack
    based containers. It  gives  ability  to  manipulate  the  constant  stack
    container.

    Each constant stack container should declare the following types:
    TType           - type of the stack container items;
    TContainer      - type of the stack container;
    TIteratorConst  - type of the constant stack iterators.

    \see NDepth::NContainers::CStack
*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst>
class IStackConst :
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
  IStackConst();

public:
  //! Interface virtual destructor.
  virtual ~IStackConst();

  //! Get non constant iterator to the stack container top item.
  /*!
      Method returns non constant iterator to the stack container top item.

      \return Non constant iterator to the stack container top item.
  */
  virtual TIterator getItTop() = 0;
  //! Get constant iterator to the stack container top item.
  /*!
      Method returns constant iterator to the stack container top item.

      \return Constant iterator to the stack container top item.
  */
  virtual TIteratorConst getItTop() const = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/IStackConst.inl>
/*==========================================================================*/
#endif
