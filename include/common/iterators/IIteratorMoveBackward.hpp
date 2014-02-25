/*!
 *  \file    IIteratorMoveBackward.hpp Base interface for all iterators that
 *           can do bi-directional iteration movement.
 *  \brief   Base bi-directional iterator movement interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base bi-directional iterator movement interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common iterators
    VERSION:   1.0
    CREATED:   20.01.2006 22:55:24

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
#ifndef __IITERATORMOVEBACKWARD_HPP__
#define __IITERATORMOVEBACKWARD_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorMoveForward.hpp>
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
//! Base bi-directional iterator movement interface.
/*!
    Backward iterators can do bi-directional movements. It can  be  applicable
    to various kinds of dequeues and bi-directional linked  lists.  To  do  an
    iteration you can use '+', '++', '+=', '-', '--', '-=' operators or direct
    'stepForward()' or 'stepBackward()' method.

    This is only movement  strategy  interface.  To  create  a  real  iterator
    implementation you have to inherit  your  new  iterator  class  both  from
    IIterator (IConstIterator) and from one of the IIteratorMove interfaces.

    Note that there are no '==', '!=', '=', '+', '++', '+=', '-',  '--',  '-='
    operators defined in this interface,  because  of  their  returning  types
    (which have to be same as derived iterator). But in real backward iterator
    implementations it is highly recomended to implement them!

    Each iterator should declare the following types:
    TType      - type of the iterator value;
    TReturn    - return  type   of   the   iterator,  which  is  returned   by
                 'getValueRef()' and 'getValuePtr()' methods;
    TContainer - type of the iterator container.
    TIterator  - itself type of the iterator.
*/
template <class T_Iterator, typename T_Type, typename T_Return, class T_Container>
class IIteratorMoveBackward :
  public IIteratorMoveForward<T_Iterator, T_Type, T_Return, T_Container>
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
  IIteratorMoveBackward();

public:
  //! Interface virtual destructor.
  virtual ~IIteratorMoveBackward();

  //! Do some backward iterations.
  /*!
      This  method  makes  some  backward  iterations  with  current  iterator
      instance and returns number of steps that have been successfully done.

      \param a_cStepCount - Steps count to iteration (default is 1).
      \return Number of iteration steps that current iterator have gone.
  */
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1) = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorMoveBackward.inl>
/*==========================================================================*/
#endif
