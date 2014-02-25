/*!
 *  \file    IRandomConst.hpp Base interface for all constant random
 *           accessible containers. It gives ability to manipulate the
 *           constant random accessible container.
 *  \brief   Constant random accessible container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant random accessible container interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common containers
    VERSION:   1.0
    CREATED:   20.02.2006 23:26:53

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
#ifndef __IRANDOMCONST_HPP__
#define __IRANDOMCONST_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IDequeConst.hpp>
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
//! Constant random accessible container interface.
/*!
    Constant random  accessible  container  is  the  base  interface  for  all
    constant random accessible containers. It gives ability to manipulate  the
    constant random accessible container.

    Each constant random accessible container  should  declare  the  following
    types:
    TType           - type of the random accessible container items;
    TContainer      - type of the random accessible container;
    TIteratorConst  - type of the constant random accessible iterators.

    \see NDepth::NContainers::CArray
    \see NDepth::NContainers::CBitArray
    \see NDepth::NContainers::CSortedArray
*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst, typename T_Return = T_Type&, typename T_ReturnConst = const T_Type&>
class IRandomConst :
  public IDequeConst<T_Container, T_Type, T_Iterator, T_IteratorConst>
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
  IRandomConst();

public:
  //! Interface virtual destructor.
  virtual ~IRandomConst();

  //! Operator: Indexing into the random accessible container.
  /*!
      \param a_cIndex - Indexed position to return.
      \return Reference to the item under the given index.
  */
  virtual T_Return operator [] (const Tsint a_cIndex) = 0;
  //! Operator: Indexing into the random accessible container.
  /*!
      \param a_cIndex - Indexed position to return.
      \return Reference to the item under the given index.
  */
  virtual T_Return operator [] (const Tuint a_cIndex) = 0;

  //! Operator: Indexing into the random accessible container.
  /*!
      \param a_cIndex - Indexed position to return.
      \return Constant reference to the item under the given index.
  */
  virtual T_ReturnConst operator [] (const Tsint a_cIndex) const = 0;
  //! Operator: Indexing into the random accessible container.
  /*!
      \param a_cIndex - Indexed position to return.
      \return Constant reference to the item under the given index.
  */
  virtual T_ReturnConst operator [] (const Tuint a_cIndex) const = 0;

  //! Get non constant iterator to the random accessible container's indexed item.
  /*!
      \param a_cIndex - Indexed position to return.
      \return Non constant iterator to the indexed item.
  */
  virtual TIterator getItIndex(const Tuint a_cIndex) = 0;
  //! Get constant iterator to the random accessible container's indexed item.
  /*!
      \param a_cIndex - Indexed position to return.
      \return Constant iterator to the indexed item.
  */
  virtual TIteratorConst getItIndex(const Tuint a_cIndex) const = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/IRandomConst.inl>
/*==========================================================================*/
#endif
