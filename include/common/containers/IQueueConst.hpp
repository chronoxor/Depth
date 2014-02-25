/*!
 *  \file    IQueueConst.hpp Base interface for all constant queue based
 *           containers. It gives ability to manipulate the constant queue
 *           container.
 *  \brief   Constant queue container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant queue container interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common containers
    VERSION:   1.0
    CREATED:   20.02.2006 03:44:27

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
#ifndef __IQUEUECONST_HPP__
#define __IQUEUECONST_HPP__
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
//! Constant queue container interface.
/*!
    Constant queue container is the base  interface  for  all  constant  queue
    based containers. It  gives  ability  to  manipulate  the  constant  queue
    container.

    Each constant queue container should declare the following types:
    TType           - type of the queue container items;
    TContainer      - type of the queue container;
    TIteratorConst  - type of the constant queue iterators.

    \see NDepth::NContainers::CQueue
    \see NDepth::NContainers::CListSL
*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst>
class IQueueConst :
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
  IQueueConst();

public:
  //! Interface virtual destructor.
  virtual ~IQueueConst();

  //! Get non constant iterator to the queue container first item.
  /*!
      Method returns non constant iterator to the queue container first item.

      \return Non constant iterator to the queue container first item.
  */
  virtual TIterator getItFirst() = 0;
  //! Get constant iterator to the queue container first item.
  /*!
      Method returns constant iterator to the queue container first item.

      \return Constant iterator to the queue container first item.
  */
  virtual TIteratorConst getItFirst() const = 0;

  //! Get non constant iterator to the queue container last item.
  /*!
      Method returns non constant iterator to the queue container last item.

      \return Non constant iterator to the queue container last item.
  */
  virtual TIterator getItLast() = 0;
  //! Get constant iterator to the queue container last item.
  /*!
      Method returns constant iterator to the queue container last item.

      \return Constant iterator to the queue container last item.
  */
  virtual TIteratorConst getItLast() const = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/IQueueConst.inl>
/*==========================================================================*/
#endif
