/*!
 *  \file    IIteratorRemoveRandom.hpp Base interface for all iterators that
 *           can remove item from random container position.
 *  \brief   Base random iterator remove interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base random iterator remove interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common iterators
    VERSION:   1.0
    CREATED:   05.04.2006 22:14:53

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
#ifndef __IITERATORREMOVERANDOM_HPP__
#define __IITERATORREMOVERANDOM_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorRemoveBackward.hpp>
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
//! Base random iterator remove interface.
/*!
    Random remove iterators implements delete  ability  to  remove  item  from
    random container position. It can be applicable to the  various  kinds  of
    arrays and buffers. To remove item you can use 'removeIndex()' method.

    This is only deleting  strategy  interface.  To  create  a  real  iterator
    implementation you have to inherit  your  new  iterator  class  both  from
    IIterator  (IConstIterator)  and  from  one  of  the  IIterator  removeing
    interfaces.

    Note that  there  are  no  '==',  '!=',  '='  operators  defined  in  this
    interface, because of their returning types (which  have  to  be  same  as
    derived iterator). But in real random  deleting  iterator  implementations
    it is highly recomended to implement them!

    Each iterator should declare the following types:
    TType      - type of the iterator value;
    TReturn    - return  type   of   the   iterator,  which  is  returned   by
                 'getValueRef()' and 'getValuePtr()' methods;
    TContainer - type of the iterator container.
    TIterator  - itself type of the iterator.
*/
template <class T_Iterator, typename T_Type, typename T_Return, class T_Container>
class IIteratorRemoveRandom :
  public IIteratorRemoveBackward<T_Iterator, T_Type, T_Return, T_Container>
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
  IIteratorRemoveRandom();

public:
  //! Interface virtual destructor.
  virtual ~IIteratorRemoveRandom();

  //! Remove item from the random (indexed) container position.
  /*!
      With this method you can directly  remove  item  from  random  container
      position.

      \param a_cIndex - Indexed container position to remove.
      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeIndex(const Tuint a_cIndex) = 0;
  //! Remove item from the random (indexed) container position.
  /*!
      With this method you can directly remove item from random container
      position. This version of the method also returns removed item.

      \param a_cIndex - Indexed container position to remove.
      \param a_rItem - Reference to returning removed item.
      \return true  - if item was removed successfully. \n
              false - if item was not removed successfully. \n
  */
  virtual Tbool removeIndex(const Tuint a_cIndex, TType& a_rItem) = 0;

  //! Remove items interval from the random (indexed) container position.
  /*!
      With this method you can directly  remove  items  interval  from  random
      container position.

      \param a_cIndex - Indexed container position to remove.
      \param a_cSize - Size of removed interval.
      \return true  - if items was removed successfully. \n
              false - if items was not removed successfully. \n
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
#include <Depth/include/common/iterators/IIteratorRemoveRandom.inl>
/*==========================================================================*/
#endif
