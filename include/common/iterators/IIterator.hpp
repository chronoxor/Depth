/*!
 *  \file    IIterator.hpp Base interface for all non constant iterators. It
 *           gives ability to check for valid state and get container values.
 *  \brief   Base non constant iterator interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base non constant iterator interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common iterators
    VERSION:   1.0
    CREATED:   20.01.2006 20:34:13

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
#ifndef __IITERATOR_HPP__
#define __IITERATOR_HPP__
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
//! Base non constant iterator interface.
/*!
    Non  constant  iterator  is  the  base  interface  for  all  non  constant
    iterators. It gives ability to check for valid state of iterator and  also
    get non constant pointer to iterator value or get non constant reference.

    For example if you have 'IIterator it', you can check it valid  state.  If
    'it->isValid()' is true, then this iterator initialized and can be used to
    get it value (pointer operator, reference operator or  from  the  iterator
    direct methods).

    Note that reference operator and reference direct method are not safe.  If
    iterator is not initialized ('it->isValid()' value is false),  then  using
    is corresponding methods can lead to unpredictable and fatal consequences!
    That is why, if you are using reference methods, you have  to  check  your
    iterator state with 'isValid()' method unless you completely sure that its
    state is valid.

    Note that  there  are  no  '==',  '!=',  '='  operators  defined  in  this
    interface, because of their returning types (which  have  to  be  same  as
    derived iterator). But in real non constant iterator implementations it is
    highly recomended to implement them!

    Each iterator should declare the following types:
    TType      - type of the iterator value;
    TReturn    - return  type   of   the   iterator,  which  is  returned   by
                 'getValueRef()' and 'getValuePtr()' methods;
    TContainer - type of the iterator container.
    TIterator  - itself type of the iterator.
*/
template <class T_Iterator, typename T_Type, typename T_Return, class T_Container>
class IIterator
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
  IIterator();

public:
  //! Interface virtual destructor.
  virtual ~IIterator();

  //! Operator: Get non constant reference to the value from iterator.
  /*!
      \return Non constant reference to the iterator value.
      \see NDepth::NCommon::IIterator::getValueRef()
  */
  TReturn& operator * () const;
  //! Operator: Get non constant pointer to the value from iterator.
  /*!
      \return Non constant pointer to the iterator value.
      \see NDepth::NCommon::IIterator::getValuePtr()
  */
  TReturn* operator -> () const;

  //! Non constant iterator valid checking method.
  /*!
      Method checks if non constant iterator is initialized and can be used to
      get reference to the value from it.

      \return true  - if non constant iterator is valid. \n
              false - if non constant iterator is not valid. \n
  */
  virtual Tbool isValid() const = 0;
  //! Iterator container valid checking method.
  /*!
      Method checks if non constant iterator container is initialized and  can
      be used to get reference to it.

      \return true  - if non constant iterator container is valid. \n
              false - if non constant iterator container is not valid. \n
  */
  virtual Tbool isValidContainer() const = 0;

  //! Get non constant reference to the parent container.
  /*!
      Method returns non constant reference to the iterator parent  container.
      Note that result may be broken if iterator is not  initialized.  So  use
      'isValidContainer()' method before to check its valid state.

      \return Non constant reference to the iterator parent container.
  */
  virtual TContainer& getContainerRef() const = 0;
  //! Get non constant pointer to the parent container.
  /*!
      Method returns non constant pointer to iterator parent  container.  Note
      that result  may  be  NULL  if  iterator  is  not  initialized.  So  use
      'isValidContainer()' method before to check its valid state or use  NULL
      checking  strategy  to  define  iterator  is   not   initialized   state
      alternatively.

      \return Non constant pointer to the iterator parent container.
  */
  virtual TContainer* getContainerPtr() const = 0;

  //! Get non constant reference to the value from iterator.
  /*!
      Method returns non constant reference to the iterator value.  Note  that
      result may be broken if iterator is not initialized. So use  'isValid()'
      method before to check its valid state.

      \return Non constant reference to the iterator value.
  */
  virtual TReturn& getValueRef() const = 0;
  //! Get non constant pointer to the value from iterator.
  /*!
      Method returns non constant pointer to the  iterator  value.  Note  that
      result may be NULL if iterator is not initialized.  So  use  'isValid()'
      method before to check its valid state or use NULL checking strategy  to
      define iterator is not initialized state alternatively.

      \return Non constant pointer to the iterator value.
  */
  virtual TReturn* getValuePtr() const = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/iterators/IIterator.inl>
/*==========================================================================*/
#endif
