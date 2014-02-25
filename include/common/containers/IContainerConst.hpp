/*!
 *  \file    IContainerConst.hpp Base interface for all constant containers.
 *           It gives ability to receive container's size and emptiness state.
 *  \brief   Base constant container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base constant container interface.

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
#ifndef __ICONTAINERCONST_HPP__
#define __ICONTAINERCONST_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
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
//! Base constant container interface.
/*!
    Constant container is the base interface for all constant  containers.  It
    gives ability to receive container's size and emptiness state.

    Each constant container should declare the following types:
    TType           - type of the container items;
    TContainer      - type of the container;
    TIteratorConst  - type of the container constant iterators.
*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst>
class IContainerConst
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
  IContainerConst();

public:
  //! Interface virtual destructor.
  virtual ~IContainerConst();

  //! Is container empty?
  /*!
      \return true  - if container is empty. \n
              false - if container is not empty. \n
  */
  virtual Tbool isEmpty() const = 0;

  //! Get container size.
  /*!
      Method returns count of elements in the container.

      \return Count of elements in the container.
  */
  virtual Tuint getSize() const = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/IContainerConst.inl>
/*==========================================================================*/
#endif
