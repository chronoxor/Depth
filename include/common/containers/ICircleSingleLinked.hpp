/*!
 *  \file    ICircleSingleLinked.hpp Base interface for all non constant
 *           circle single linked list based containers. It gives ability
 *           to manipulate with the non constant circle single linked list
 *           container.
 *  \brief   Non constant circle single linked list container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant circle single linked list container interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common containers
    VERSION:   1.0
    CREATED:   20.02.2006 02:11:26

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
#ifndef __ICIRCLESINGLELINKED_HPP__
#define __ICIRCLESINGLELINKED_HPP__
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
//! Non constant circle single linked list container interface.
/*!
    Non constant circle single linked list container is the base interface for
    all non constant circle single linked  list  based  containers.  It  gives
    ability  to  manipulate  the  non  constant  circle  single  linked   list
    container.

    Each non constant circle single linked list container should  declare  the
    following types:
    TType           - type of the circle single linked list container items;
    TContainer      - type of the circle single linked list container;
    TIterator       - type of the circle  single  linked  list  container  non
                      constant iterators.
    TIteratorConst  - type of the circle single linked list container constant
                      iterators.

    \see NDepth::NContainers::CListSC
*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst>
class ICircleSingleLinked :
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
  ICircleSingleLinked();

public:
  //! Interface virtual destructor.
  virtual ~ICircleSingleLinked();

  //! Insert item into the current position of the circle single linked list.
  /*!
      Method works only with the empty list. It inserts item into the  current
      circle single linked list position. If list is not empty, method  fails,
      because it cannot connect two single linked nodes.

      \param a_crItem - Constant reference to the item to insert.
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insertCurrent(const TType& a_crItem) = 0;
  //! Insert item into the next to the current position of the circle single linked list.
  /*!
      Method works only with non empty list. It inserts item into the next  to
      current circle single linked list position. If  list  is  empty,  method
      fails, because there is no current position.

      \param a_crItem - Constant reference to the item to insert.
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insertNext(const TType& a_crItem) = 0;

  //! Remove item from current position of the circle single linked list.
  /*!
      Method works only with one element list. It removes  item  from  current
      circle single linked list position. If list has more than  one  element,
      method fails, because it cannot connect two single  linked  nodes.  This
      method does not save removed item.

      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeCurrent() = 0;
  //! Remove item from current position of the circle single linked list.
  /*!
      Method works only with one element list. It removes  item  from  current
      circle single linked list position. If list has more than  one  element,
      method fails, because it cannot connect two single  linked  nodes.  This
      method saves removed item into the given argument.

      \param a_rItem - Reference to the returned removed item.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeCurrent(TType& a_rItem) = 0;

  //! Remove item from next to the current position of the circle single linked list.
  /*!
      Method works only with list with more than one element. It removes  item
      from the next to the current circle single linked list position. If list
      has elements number less than one, method fails,  because  there  is  no
      next to the current position. This method does not save removed item.

      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeNext() = 0;
  //! Remove item from next to the current position of the circle single linked list.
  /*!
      Method works only with list with more than one element. It removes  item
      from the next to the current circle single linked list position. If list
      has elements number less than one, method fails,  because  there  is  no
      next to the current position. This method saves removed item into  given
      argument.

      \param a_rItem - Reference to the returned removed item.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeNext(TType& a_rItem) = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/ICircleSingleLinked.inl>
/*==========================================================================*/
#endif
