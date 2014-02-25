/*!
 *  \file    ICircleDoubleLinkedConst.hpp Base interface for all constant
 *           circle double linked list based containers. It gives ability
 *           to manipulate the constant circle double linked list container.
 *  \brief   Constant circle double linked list container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant circle double linked list container interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common containers
    VERSION:   1.0
    CREATED:   20.02.2006 02:29:32

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
#ifndef __ICIRCLEDOUBLELISTLINKED_HPP__
#define __ICIRCLEDOUBLELISTLINKED_HPP__
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
//! Constant circle double linked list container interface.
/*!
    Constant circle double linked list container is the base interface for all
    constant circle double linked list based containers. It gives  ability  to
    manipulate the constant circle double linked list container.

    Each constant circle double  linked  list  container  should  declare  the
    following types:
    TType           - type of the circle double linked list container items;
    TContainer      - type of the circle double linked list container;
    TIteratorConst  - type  of  the  constant  circle   double   linked   list
                      iterators.

    \see NDepth::NContainers::CListDC
*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst>
class ICircleDoubleLinkedConst :
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
  ICircleDoubleLinkedConst();

public:
  //! Interface virtual destructor.
  virtual ~ICircleDoubleLinkedConst();

  //! Moves current circle double linked list pointer to the next forward position.
  /*!
      This method makes some next forward steps with the current circle double
      linked  list  pointer  and  returns  number  of  steps  that  have  been
      successfully done.

      \param a_cStepCount - Steps count to iteration (default is 1).
      \return Number of iteration steps that current pointer have gone.
  */
  virtual Tuint stepForward(const Tuint a_cStepCount = 1) = 0;
  //! Moves current circle double linked list pointer to the previous backward position.
  /*!
      This method makes some previous backward steps with the  current  circle
      double linked list pointer and returns number of steps  that  have  been
      successfully done.

      \param a_cStepCount - Steps count to iteration (default is 1).
      \return Number of iteration steps that current pointer have gone.
  */
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1) = 0;

  //! Get non constant iterator to the circle double linked list current item.
  /*!
      Method returns non constant iterator to the circle  double  linked  list
      current item.

      \return Non constant iterator to the circle double linked list current item.
  */
  virtual TIterator getItCurrent() = 0;
  //! Get constant iterator to the circle double linked list current item.
  /*!
      Method returns constant  iterator  to  the  circle  double  linked  list
      current item.

      \return Constant iterator to the circle double linked list current item.
  */
  virtual TIteratorConst getItCurrent() const = 0;

  //! Get non constant iterator to the circle double linked list next item.
  /*!
      Method returns non constant iterator to the circle  double  linked  list
      next item.

      \return Non constant iterator to the circle double linked list next item.
  */
  virtual TIterator getItNext() = 0;
  //! Get constant iterator to the circle double linked list next item.
  /*!
      Method returns constant iterator to the circle double linked  list  next
      item.

      \return Constant iterator to the circle double linked list next item.
  */
  virtual TIteratorConst getItNext() const = 0;

  //! Get non constant iterator to the circle double linked list previous item.
  /*!
      Method returns non constant iterator to the circle  double  linked  list
      previous item.

      \return Non constant iterator to the circle double linked list previous item.
  */
  virtual TIterator getItPrev() = 0;
  //! Get constant iterator to the circle double linked list previous item.
  /*!
      Method returns constant  iterator  to  the  circle  double  linked  list
      previous item.

      \return Constant iterator to the circle double linked list previous item.
  */
  virtual TIteratorConst getItPrev() const = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/ICircleDoubleLinkedConst.inl>
/*==========================================================================*/
#endif
