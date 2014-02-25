/*!
 *  \file    IIteratorConst.hpp Base interface for all constant iterators. It
 *           gives ability to check for valid state and get container constant
 *           values.
 *  \brief   Base constant iterator interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base constant iterator interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common iterators
    VERSION:   1.0
    CREATED:   20.01.2006 02:08:35

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
#ifndef __IITERATORCONST_HPP__
#define __IITERATORCONST_HPP__
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
//! Base constant iterator interface.
/*!
    Constant iterator is the base interface for  all  constant  iterators.  It
    gives ability to check for valid state of iterator and also  get  constant
    pointer to iterator value or get constant reference.

    For example if you have 'IIteratorConst it', you can check it valid state.
    If 'it->isValid()' is true, then this iterator initialized and can be used
    to get it value (pointer operator, reference operator or from the iterator
    direct methods).

    Note that reference operator and reference direct method are not safe.  If
    iterator is not initialized ('it->isValid()' value is false),  then  using
    is corresponding methods can lead to unpredictable and fatal consequences!
    That is why, if you are using reference methods, you have  to  check  your
    iterator state with 'isValid()' method unless you completely sure that its
    state is valid.

    Note that  there  are  no  '==',  '!=',  '='  operators  defined  in  this
    interface, because of their returning types (which  have  to  be  same  as
    derived iterator). But in real constant  iterator  implementations  it  is
    highly recomended to implement them!

    Each iterator should declare the following types:
    TType      - type of the iterator value;
    TReturn    - return  type   of   the   iterator,  which  is  returned   by
                 'getValueRef()' and 'getValuePtr()' methods;
    TContainer - type of the iterator container.
    TIterator  - itself type of the iterator.
*/
template <class T_Iterator, typename T_Type, typename T_Return, class T_Container>
class IIteratorConst
{
public:
  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef const T_Return TReturn;
  //! Iterator container type.
  typedef const T_Container TContainer;
  //! Iterator itself type.
  typedef T_Iterator TIterator;

protected:
  //! Default interface protected constructor.
  IIteratorConst();

public:
  //! Interface virtual destructor.
  virtual ~IIteratorConst();

  //! Operator: Get constant reference to the value from iterator.
  /*!
      \return Constant reference to the iterator value.
      \see NDepth::NCommon::IIteratorConst::getValueRef()
  */
  TReturn& operator * () const;
  //! Operator: Get constant pointer to the value from iterator.
  /*!
      \return Constant pointer to iterator value.
      \see NDepth::NCommon::IIteratorConst::getValuePtr()
  */
  TReturn* operator -> () const;

  //! Constant iterator valid checking method.
  /*!
      Method checks if constant iterator is initialized and can be used to get
      reference to the value from it.

      \return true  - if constant iterator is valid. \n
              false - if constant iterator is not valid. \n
  */
  virtual Tbool isValid() const = 0;
  //! Iterator container valid checking method.
  /*!
      Method checks if constant iterator container is initialized and  can  be
      used to get reference to it.

      \return true  - if constant iterator container is valid. \n
              false - if constant iterator container is not valid. \n
  */
  virtual Tbool isValidContainer() const = 0;

  //! Get constant reference to the parent container.
  /*!
      Method returns constant reference to the iterator parent container. Note
      that result may be  broken  if  iterator  is  not  initialized.  So  use
      'isValidContainer()' method before to check its valid state.

      \return Constant reference to the iterator parent container.
  */
  virtual TContainer& getContainerRef() const = 0;
  //! Get constant pointer to the parent container.
  /*!
      Method returns constant pointer to the iterator parent  container.  Note
      that result  may  be  NULL  if  iterator  is  not  initialized.  So  use
      'isValidContainer()' method before to check its valid state or use  NULL
      checking  strategy  to  define  iterator  is   not   initialized   state
      alternatively.

      \return Constant pointer to the iterator parent container.
  */
  virtual TContainer* getContainerPtr() const = 0;

  //! Get constant reference to the value from iterator.
  /*!
      Method returns constant reference  to  the  iterator  value.  Note  that
      result may be broken if iterator is not initialized. So use  'isValid()'
      method before to check its valid state.

      \return Constant reference to the iterator value.
  */
  virtual TReturn& getValueRef() const = 0;
  //! Get constant pointer to the value from iterator.
  /*!
      Method returns constant pointer to the iterator value. Note that  result
      may be NULL if iterator is not initialized. So  use  'isValid()'  method
      before to check its valid state or use NULL checking strategy to  define
      iterator is not initialized state alternatively.

      \return Constant pointer to the iterator value.
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
#include <Depth/include/common/iterators/IIteratorConst.inl>
/*==========================================================================*/
#endif
