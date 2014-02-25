/*!
 *  \file    IIteratorMoveAssociative.hpp Base interface for all iterators
 *           that can do associative iteration movement.
 *  \brief   Base associative iterator movement interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base associative iterator movement interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common iterators
    VERSION:   1.0
    CREATED:   29.07.2006 00:04:27

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
#ifndef __IITERATORMOVEASSOCIATIVE_HPP__
#define __IITERATORMOVEASSOCIATIVE_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Base associative iterator movement interface.
/*!
    Associative iterator is the base movement interface  for  all  associative
    movement  iterators.  It  gives  ability  to   explore   associative-based
    constructions.

    Note that there are no '==', '!=', '=', '[]'  operators  defined  in  this
    interface, because of their returning types (which  have  to  be  same  as
    derived iterator). But in real associative moving iterator  implementation
    it is highly recomended to implement them!

    Each associative iterator should declare the following types:
    TKey       - type of the associative iterator key;
    TValue     - type of the associative iterator values;
    TType      - type of the iterator value;
    TReturn    - return  type   of   the   iterator,  which  is  returned   by
                 'getValueRef()' and 'getValuePtr()' methods;
    TContainer - type of the iterator container.
    TIterator  - itself type of the iterator.
*/
template <class T_Iterator, typename T_Key, typename T_Value, typename T_Type, typename T_Return, class T_Container>
class IIteratorMoveAssociative
{
public:
  //! Associative iterator key type.
  typedef T_Key TKey;
  //! Associative iterator value type.
  typedef T_Value TValue;

  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef T_Return TReturn;
  //! Iterator container type.
  typedef T_Container TContainer;
  //! Iterator itself type.
  typedef T_Iterator TIterator;

protected:
  //! Default interface protected constructor.
  IIteratorMoveAssociative();

public:
  //! Interface virtual destructor.
  virtual ~IIteratorMoveAssociative();

  //! Find iterator with the given key in the associative container.
  /*!
      Method tries to find iterator with the  given  key  in  the  associative
      container. If such iterator exists, method will  return  it.  Otherwise,
      method returns invalid empty iterator.

      \param a_crKey - Constant reference to the searching key.
      \return Associative iterator with the given key or invalid empty iterator.
  */
  virtual TIterator find(const TKey& a_crKey) const = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorMoveAssociative.inl>
/*==========================================================================*/
#endif
