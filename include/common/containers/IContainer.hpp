/*!
 *  \file    IContainer.hpp Base interface for all non constant containers
 *           which extends functionality of constant containers by giving
 *           ability to assign another container and to clear the current
 *           one as well.
 *  \brief   Base non constant container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base non constant container interface.

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
#ifndef __ICONTAINER_HPP__
#define __ICONTAINER_HPP__
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
//! Base non constant container interface.
/*!
    Non constant  container  is  the  base  interface  for  all  non  constant
    containers. It extends functionality  of  constant  containers  by  giving
    ability to assign another container and to clear the current one as well.

    Note that there are no '=' operator defined in this interface, because  of
    their returning types (which have to be same as derived iterator). But  in
    real non constant container implementations it  is  highly  recomended  to
    implement them!

    Each constant container should declare the following types:
    TType           - type of the container items;
    TContainer      - type of the container;
    TIterator       - type of the container non constant iterators.
    TIteratorConst  - type of the container constant iterators.
*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst>
class IContainer
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
  IContainer();

public:
  //! Interface virtual destructor.
  virtual ~IContainer();

  //! Clear container.
  /*!
      Method removes all items from the container and makes it empty.

      \return true  - if container was cleared successfully. \n
              false - if container was not cleared successfully. \n
  */
  virtual Tbool clear() = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/IContainer.inl>
/*==========================================================================*/
#endif
