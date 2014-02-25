/*!
 *  \file    IAssociative.hpp Base interface for all non constant associative
 *           containers. It gives ability to manipulate with the non constant
 *           associative container.
 *  \brief   Non constant associative container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant associative container interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common containers
    VERSION:   1.0
    CREATED:   20.02.2006 22:50:27

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
#ifndef __IASSOCIATIVE_HPP__
#define __IASSOCIATIVE_HPP__
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
//! Non constant associative container interface.
/*!
    Non constant associative container is  the  base  interface  for  all  non
    constant associative containers. It gives ability to  manipulate  the  non
    constant associative container.

    Each non constant  associative  container  should  declare  the  following
    types:
    TKey            - type of the associative container key;
    TValue          - type of the associative container values;
    TType           - type of the associative container items;
    TContainer      - type of the associative container;
    TIterator       - type  of   the   associative   container   non  constant
                      iterators.
    TIteratorConst  - type of the associative container constant iterators.

    \see NDepth::NContainers::CBinaryTree
    \see NDepth::NContainers::CMap
    \see NDepth::NContainers::CSet
    \see NDepth::NContainers::CMultimap
    \see NDepth::NContainers::CMultiset
    \see NDepth::NContainers::CSortedArray
*/
template <class T_Container, typename T_Key, typename T_Value, typename T_Type, class T_Iterator, class T_IteratorConst>
class IAssociative :
  public IContainer<T_Container, T_Type, T_Iterator, T_IteratorConst>
{
public:
  //! Associative container key type.
  typedef T_Key TKey;
  //! Associative container value type.
  typedef T_Value TValue;

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
  IAssociative();

public:
  //! Interface virtual destructor.
  virtual ~IAssociative();

  //! Operator: Insert item into the associative container.
  /*!
      \param a_crItem - Constant reference to the item to insert.
      \return Reference to the current associative container class instance.
  */
  virtual TContainer& operator += (const TType& a_crItem) = 0;
  //! Operator: Insert another associative container into the associative container.
  /*!
      \param a_crContainer - Constant reference to the associative container to insert.
      \return Reference to the current associative container class instance.
  */
  virtual TContainer& operator += (const TContainer& a_crContainer) = 0;
  //! Operator: Remove item with the given key from the associative container.
  /*!
      \param a_crKey - Constant reference to the key to remove.
      \return Reference to the current associative container class instance.
  */
  virtual TContainer& operator -= (const TKey& a_crKey) = 0;
  //! Operator: Remove another associative container from the associative container.
  /*!
      \param a_crContainer - Constant reference to the associative container to remove.
      \return Reference to the current associative container class instance.
  */
  virtual TContainer& operator -= (const TContainer& a_crContainer) = 0;

  //! Insert item into the associative container.
  /*!
      \param a_crItem - Constant reference to the item to insert.
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insert(const TType& a_crItem) = 0;
  //! Insert another associative container into the associative container.
  /*!
      \param a_crContainer - Constant reference to the associative container to insert.
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insert(const TContainer& a_crContainer) = 0;

  //! Remove item with the given key from the associative container.
  /*!
      \param a_crKey - Constant reference to the key to remove.
      \param a_cRemoveSame - Remove all same items flag (default is false).
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool remove(const TKey& a_crKey, const Tbool a_cRemoveSame = false) = 0;
  //! Remove another associative container from the associative container.
  /*!
      \param a_crContainer - Constant reference to the associative container to remove.
      \param a_cRemoveSame - Remove all same items flag (default is false).
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool remove(const TContainer& a_crContainer, const Tbool a_cRemoveSame = false) = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/IAssociative.inl>
/*==========================================================================*/
#endif
