/*!
 *  \file    IIteratorInsertForward.hpp Base interface for all iterators that
 *           can insert items into forward place of current interator.
 *  \brief   Base forward iterator insert interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base forward iterator insert interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common iterators
    VERSION:   1.0
    CREATED:   20.01.2006 21:33:24

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
#ifndef __IITERATORINSERTFORWARD_HPP__
#define __IITERATORINSERTFORWARD_HPP__
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
//! Base forward iterator insert interface.
/*!
    Forward insert iterators implements insert ability  to  insert  new  items
    into forward place of current iterator position. It can be  applicable  to
    various kinds of stacks, queues and one direction linked lists. To  do  an
    insertion you can use 'insertForward()' method.

    This is only inserting strategy  interface.  To  create  a  real  iterator
    implementation you have to inherit  your  new  iterator  class  both  from
    IIterator  (IConstIterator)  and  from  one  of  the  IIterator  inserting
    interfaces.

    Note that  there  are  no  '==',  '!=',  '='  operators  defined  in  this
    interface, because of their returning types (which  have  to  be  same  as
    derived iterator). But in real forward inserting iterator  implementations
    it is highly recomended to implement them!

    Each iterator should declare the following types:
    TType      - type of the iterator value;
    TReturn    - return  type   of   the   iterator,  which  is  returned   by
                 'getValueRef()' and 'getValuePtr()' methods;
    TContainer - type of the iterator container.
    TIterator  - itself type of the iterator.
*/
template <class T_Iterator, typename T_Type, typename T_Return, class T_Container>
class IIteratorInsertForward
{
public:
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
  IIteratorInsertForward();

public:
  //! Interface virtual destructor.
  virtual ~IIteratorInsertForward();

  //! Insert item into the current iterator position, then old position shifts forward.
  /*!
      With this method you can directly insert new item into the current place
      of the iterator. After it old iterator position shifts forward.

      \param a_crItem - Constant reference to inserted item.
      \return true  - if item was inserted successfully. \n
              false - if item was not inserted successfully. \n
  */
  virtual Tbool insertBackward(const TType& a_crItem) = 0;

  //! Insert item into the next forward position of the current iterator.
  /*!
      With this method you can directly insert  new  item  into  next  forward
      place of the iterator. After it old iterator position stays unchanged.

      \param a_crItem - Constant reference to inserted item.
      \return true  - if item was inserted successfully. \n
              false - if item was not inserted successfully. \n
  */
  virtual Tbool insertNext(const TType& a_crItem) = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorInsertForward.inl>
/*==========================================================================*/
#endif
