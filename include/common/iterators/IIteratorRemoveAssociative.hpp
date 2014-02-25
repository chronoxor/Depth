/*!
 *  \file    IIteratorRemoveAssociative.hpp Base interface for all iterators
 *           that can remove items from associative-based container.
 *  \brief   Base associative iterator insert interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base associative iterator remove interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common iterators
    VERSION:   1.0
    CREATED:   28.07.2006 23:58:31

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
#ifndef __IITERATORREMOVEASSOCIATIVE_HPP__
#define __IITERATORREMOVEASSOCIATIVE_HPP__
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
//! Base associative iterator remove interface.
/*!
    Associative iterator is the base  remove  interface  for  all  associative
    remove iterators. It gives ability to remove items from  associative-based
    constructions.

    Note that  there  are  no  '==',  '!=',  '='  operators  defined  in  this
    interface, because of their returning types (which  have  to  be  same  as
    derived   iterator).   But   in   real   associative   removing   iterator
    implementation it is highly recomended to implement them!

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
class IIteratorRemoveAssociative
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
  IIteratorRemoveAssociative();

public:
  //! Interface virtual destructor.
  virtual ~IIteratorRemoveAssociative();

  //! Remove item from the current associative iterator position.
  /*!
      With this method you can directly remove item from current place of  the
      associative iterator. If current iterator position equals to the current
      iterator position, then current iterator position will be changed to the
      previous position.

      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool remove() = 0;
  //! Remove item from the current associative iterator position.
  /*!
      With this method you can directly remove item from current place of  the
      associative iterator. If current iterator position equals to the current
      iterator position, then current iterator position will be changed to the
      previous position.

      \param a_rItem - Reference to returning removed item.
      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool remove(TType& a_rItem) = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorRemoveAssociative.inl>
/*==========================================================================*/
#endif
