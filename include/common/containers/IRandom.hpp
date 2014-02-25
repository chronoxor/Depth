/*!
 *  \file    IRandom.hpp Base interface for all non constant random
 *           accessible containers. It gives ability to manipulate
 *           with the non constant random accessible container.
 *  \brief   Non constant random accessible container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant random accessible container interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common containers
    VERSION:   1.0
    CREATED:   20.02.2006 23:19:42

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
#ifndef __IRANDOM_HPP__
#define __IRANDOM_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IDeque.hpp>
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
//! Non constant random accessible container interface.
/*!
    Non constant random accessible container is the base interface for all non
    constant random accessible containers. It gives ability to manipulate  the
    non constant random accessible container.

    Each non constant random accessible container should declare the following
    types:
    TType           - type of the random accessible container items;
    TContainer      - type of the random accessible container;
    TIterator       - type of the random  accessible  container  non  constant
                      iterators.
    TIteratorConst  - type   of   the  random  accessible  container  constant
                      iterators.

    \see NDepth::NContainers::CArray
    \see NDepth::NContainers::CBitArray
    \see NDepth::NContainers::CSortedArray
*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst>
class IRandom :
  public IDeque<T_Container, T_Type, T_Iterator, T_IteratorConst>
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
  IRandom();

public:
  //! Interface virtual destructor.
  virtual ~IRandom();

  //! Insert item into the random accessible container indexed position.
  /*!
      Method  inserts  item  into  the  random  accessible  container  indexed
      position.

      \param a_cIndex - Indexed position to insert.
      \param a_crItem - Constant reference to the item to insert.
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insertIndex(const Tuint a_cIndex, const TType& a_crItem) = 0;

  //! Remove item from the random accessible container indexed position.
  /*!
      Method  removes  item  from  the  random  accessible  container  indexed
      position.

      \param a_cIndex - Indexed position to remove.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeIndex(const Tuint a_cIndex) = 0;
  //! Remove item from the random accessible container indexed position.
  /*!
      Method  removes  item  from  the  random  accessible  container  indexed
      position.

      \param a_cIndex - Indexed position to remove.
      \param a_rItem - Reference to returned removed item.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeIndex(const Tuint a_cIndex, TType& a_rItem) = 0;

  //! Remove items interval from the random accessible container indexed position.
  /*!
      Method removes items  interval  from  the  random  accessible  container
      indexed position.

      \param a_cIndex - Indexed position to remove.
      \param a_cSize - Size of removed interval.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool remove(const Tuint a_cIndex, const Tuint a_cSize) = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/IRandom.inl>
/*==========================================================================*/
#endif
