/*!
 *  \file    IAssociativeConst.hpp Base interface for all constant
 *           associative containers. It gives ability to manipulate
 *           the constant associative container.
 *  \brief   Constant associative container interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant associative container interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common containers
    VERSION:   1.0
    CREATED:   20.02.2006 22:53:47

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
#ifndef __IASSOCIATIVECONST_HPP__
#define __IASSOCIATIVECONST_HPP__
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
//! Constant associative container interface.
/*!
    Constant associative container is the  base  interface  for  all  constant
    associative containers.  It  gives  ability  to  manipulate  the  constant
    associative container.

    Each constant associative container should declare the following types:
    TKey            - type of the associative container key;
    TValue          - type of the associative container values;
    TType           - type of the associative container items;
    TContainer      - type of the associative container;
    TIteratorConst  - type of the constant associative iterators.

    \see NDepth::NContainers::CBinaryTree
    \see NDepth::NContainers::CMap
    \see NDepth::NContainers::CSet
    \see NDepth::NContainers::CMultimap
    \see NDepth::NContainers::CMultiset
    \see NDepth::NContainers::CSortedArray
*/
template <class T_Container, typename T_Key, typename T_Value, typename T_Type, class T_Iterator, class T_IteratorConst>
class IAssociativeConst :
  public IContainerConst<T_Container, T_Type, T_Iterator, T_IteratorConst>
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
  IAssociativeConst();

public:
  //! Interface virtual destructor.
  virtual ~IAssociativeConst();

  //! Operator: Find non constant iterator with the given key in the associative container.
  /*!
      \param a_crKey - Constant reference to the searching key.
      \return Non constant iterator with the given key or invalid empty iterator.
  */
  virtual TIterator operator [] (const TKey& a_crKey) = 0;
  //! Operator: Find constant iterator with the given key in the associative container.
  /*!
      \param a_crKey - Constant reference to the searching key.
      \return Constant iterator with the given key or invalid empty iterator.
  */
  virtual TIteratorConst operator [] (const TKey& a_crKey) const = 0;

  //! Is first given associative container key is less than second one?
  /*!
      This method use the current associative container  'LessThan'  predicate
      to compare two keys.

      \param a_crKey1 - Constant reference to the first comparing key.
      \param a_crKey2 - Constant reference to the second comparing key.
      \return true  - if first given associative container key is less than second one. \n
              false - if first given associative container key is not less than second one. \n
  */
  virtual Tbool isLessThan(const TKey& a_crKey1, const TKey& a_crKey2) const = 0;

  //! Find non constant iterator with the given key in the associative container.
  /*!
      Method tries to find non constant iterator with the  given  key  in  the
      associative container. If such iterator exists, method will  return  it.
      Otherwise, method returns invalid empty associative container iterator.

      \param a_crKey - Constant reference to the searching key.
      \return Non constant iterator with the given key or invalid empty iterator.
  */
  virtual TIterator find(const TKey& a_crKey) = 0;
  //! Find constant iterator with the given key in the associative container.
  /*!
      Method tries to find  constant  iterator  with  the  given  key  in  the
      associative container. If such iterator exists, method will  return  it.
      Otherwise, method returns invalid empty associative container iterator.

      \param a_crKey - Constant reference to the searching key.
      \return Constant iterator with the given key or invalid empty iterator.
  */
  virtual TIteratorConst find(const TKey& a_crKey) const = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/containers/IAssociativeConst.inl>
/*==========================================================================*/
#endif
