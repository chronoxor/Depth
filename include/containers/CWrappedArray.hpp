/*!
 *  \file    CWrappedArray.hpp Template wrapped array container class.
 *           Wrapped array represents a fixed-sized random access
 *           container which is built on a existing provided items.
 *  \brief   Template wrapped array container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template wrapped array container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   23.04.2007 21:05:52

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
#ifndef __CWRAPPEDARRAY_HPP__
#define __CWRAPPEDARRAY_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AAddress.hpp>
#include <Depth/include/common/containers/IContainer.hpp>
#include <Depth/include/common/containers/IRandomConst.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/traits/MTraitsContainer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
template <typename T_Type>
class CWrappedArrayIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type>
class CWrappedArrayIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template wrapped array container class.
/*!
    Wrapped array container represents  fixed-sized  random  access  container
    based on  a  existing  provided  items.  You  cannot  insert/remove  items
    into/from the fixed-sized array. But you can freely change values  of  the
    fixed-sized array.

    The wrapped array container is different from the static array  container.
    The wrapped array container does not allocate a new block for  items,  but
    uses an existing items' block which is described with provided pointer  to
    it (or reference for the special case with single item).
*/
template <typename T_Type>
class CWrappedArray :
  public NCommon::NContainers::IContainer<CWrappedArray<T_Type>, T_Type, CWrappedArrayIterator<T_Type>, CWrappedArrayIteratorConst<T_Type> >,
  public NCommon::NContainers::IRandomConst<CWrappedArray<T_Type>, T_Type, CWrappedArrayIterator<T_Type>, CWrappedArrayIteratorConst<T_Type> >
{
  // Friend class: Wrapped array iterator class (CWrappedArrayIterator).
  friend class CWrappedArrayIterator<T_Type>;
  // Friend class: Constant wrapped array iterator class (CWrappedArrayIteratorConst).
  friend class CWrappedArrayIteratorConst<T_Type>;

  //! Type for MConceptDepthType constraint checking.
  typedef CWrappedArray<T_Type> TDepthCheckType;

  // Check CWrappedArray class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef T_Type TType;
  //! Container type.
  typedef CWrappedArray<T_Type> TContainer;
  //! Non constant wrapped array iterator type.
  typedef CWrappedArrayIterator<T_Type> TIterator;
  //! Constant wrapped array iterator type.
  typedef CWrappedArrayIteratorConst<T_Type> TIteratorConst;

  //! Create an empty wrapped array.
  /*!
      Constructor creates an empty wrapped array.
  */
  CWrappedArray();
  //! Create wrapped array from single item.
  /*!
      Constructor creates wrapped array based on given single item.

      \param a_rValue - Initialize value.
  */
  CWrappedArray(T_Type& a_rValue);
  //! Create wrapped array from array of fixed size.
  /*!
      Constructor creates wrapped array based on given array of fixed size.

      \param a_pArray - Pointer to the array of fixed size.
  */
  template <Tuint t_Size>
  CWrappedArray(T_Type (&a_pArray)[t_Size]);
  //! Create wrapped array from buffer with given size.
  /*!
      Constructor creates wrapped array based on given buffer with given size.

      \param a_pBuffer - Pointer to the buffer.
      \param a_cSize - Buffer size.
  */
  CWrappedArray(T_Type a_pBuffer[], const Tuint a_cSize);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CWrappedArray class.
  */
  CWrappedArray(const CWrappedArray<T_Type>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CWrappedArray();

  //! Operator: Assign array of fixed size.
  /*!
      \param a_pArray - Pointer to the array of fixed size.
      \return Reference to the current class instance.
  */
  template <Tuint t_Size>
  CWrappedArray<T_Type>& operator = (T_Type (&a_pArray)[t_Size]);
  //! Operator: Assign another CWrappedArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CWrappedArray class.
      \return Reference to the current class instance.
  */
  CWrappedArray<T_Type>& operator = (const CWrappedArray<T_Type>& a_crInstance);

  //! Operator: Indexing into the array's buffer.
  /*!
      \param a_cIndex - Indexed array position to return.
      \return Reference to array's item under the given index.
  */
  T_Type& operator [] (const Tsint a_cIndex);
  //! Operator: Indexing into the array's buffer.
  /*!
      \param a_cIndex - Indexed array position to return.
      \return Reference to array's item under the given index.
  */
  T_Type& operator [] (const Tuint a_cIndex);
  //! Operator: Indexing into the array's buffer.
  /*!
      \param a_cIndex - Indexed array position to return.
      \return Constant reference to array's item under the given index.
  */
  const T_Type& operator [] (const Tsint a_cIndex) const;
  //! Operator: Indexing into the array's buffer.
  /*!
      \param a_cIndex - Indexed array position to return.
      \return Constant reference to array's item under the given index.
  */
  const T_Type& operator [] (const Tuint a_cIndex) const;

  //! Operator: Get pointer to the current array's buffer.
  /*!
      \return Pointer to the current array's buffer.
      \see NDepth::NContainers::CWrappedArray::getBuffer()
  */
  operator T_Type* ();
  //! Operator: Get constant pointer to the current array's buffer.
  /*!
      \return Constant pointer to the current array's buffer.
      \see NDepth::NContainers::CWrappedArray::getBuffer()
  */
  operator const T_Type* () const;

  //! Set wrapped array from single item.
  /*!
      \param a_rValue - Initialize value.
      \return true  - if wrapped array was successfully set. \n
              false - if wrapped array was not successfully set. \n
  */
  Tbool set(T_Type& a_rValue);
  //! Set wrapped array from array of fixed size.
  /*!
      \param a_pArray - Pointer to the array of fixed size.
      \return true  - if wrapped array was successfully set. \n
              false - if wrapped array was not successfully set. \n
  */
  template <Tuint t_Size>
  Tbool set(T_Type (&a_pArray)[t_Size]);
  //! Set wrapped array from buffer with given size.
  /*!
      \param a_pBuffer - Pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if wrapped array was successfully set. \n
              false - if wrapped array was not successfully set. \n
  */
  Tbool set(T_Type a_pBuffer[], const Tuint a_cSize);
  //! Set another CWrappedArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CWrappedArray class.
      \return true  - if another wrapped array was successfully set. \n
              false - if another wrapped array was not successfully set. \n
  */
  Tbool set(const CWrappedArray<T_Type>& a_crInstance);

  //! Get wrapped array free size.
  /*!
      Method always returns 0, because wrapped array cannot be resized.

      \return Count of free elements in the wrapped array (always 0).
  */
  Tuint getFreeSize() const;

  //! Get wrapped array lower capacity bound value.
  /*!
      Method returns lower bound size value before wrapped array reallocation.
      As wrapped array does not support resizing, this method  always  returns
      0.

      \return Wrapped array lower capacity bound value (always 0).
  */
  Tuint getLoCapacity() const;
  //! Get wrapped array higher capacity bound value.
  /*!
      Method  returns  higher  bound   size   value   before   wrapped   array
      reallocation. As wrapped array does not support  resizing,  this  method
      always returns m_Size.

      \return Wrapped array higher capacity bound value (always m_Size).
  */
  Tuint getHiCapacity() const;

  //! Get ponter to the wrapped array buffer.
  /*!
      Method returns pointer to  the  wrapped  array  buffer.  Using  of  this
      pointer is quite dangerous cause it may lead to memory errors.  That  is
      why you always have to check wrapped array  bounds  while  working  with
      this pointer.

      \return Pointer to the wrapped array buffer.
  */
  T_Type* getBuffer();
  //! Get constant ponter to the wrapped array buffer.
  /*!
      Method returns constant pointer to the wrapped array  buffer.  Using  of
      this pointer is quite dangerous cause it may lead to memory errors. That
      is why you always have to check wrapped array bounds while working  with
      this pointer.

      \return Constant pointer to the wrapped array buffer.
  */
  const T_Type* getBuffer() const;

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IRandomConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;
  virtual TIterator      getItIndex(const Tuint a_cIndex);
  virtual TIteratorConst getItIndex(const Tuint a_cIndex) const;

  //! Reverse wrapped array.
  /*!
      Reverse wrapped array items order.
  */
  void reverse();

  //! Serialization load CWrappedArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CWrappedArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CWrappedArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CWrappedArray class instances.
  /*!
      \param a_rInstance - Reference to another CWrappedArray class instance.
  */
  void swap(CWrappedArray<T_Type>& a_rInstance);

private:
  Tuint   m_Size;                       //!< Wrapped array's size.
  T_Type* m_pData;                      //!< Pointer to wrapped array's buffer.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* CONTAINER TRAITS SPECIALIZATION DECLARATIONS                             */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: wrapped array container traits specialization.
template <typename T_Type>
class MTraitsContainer<NContainers::CWrappedArray<T_Type> > :
  public MType<NContainers::CWrappedArray<T_Type> >
{
public:
  //! Container value type.
  typedef typename NContainers::CWrappedArray<T_Type>::TType value;
  //! Container type.
  typedef typename NContainers::CWrappedArray<T_Type>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CWrappedArray<T_Type>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CWrappedArray<T_Type>::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = false; //!< Is container non constant queue?
  static const Tbool isQueueConst       = true;  //!< Is container constant queue?
  static const Tbool isDeque            = false; //!< Is container non constant deque?
  static const Tbool isDequeConst       = true;  //!< Is container constant deque?
  static const Tbool isRandom           = false; //!< Is container non constant random?
  static const Tbool isRandomConst      = true;  //!< Is container constant random?
  static const Tbool isAssociative      = false; //!< Is container non constant associative?
  static const Tbool isAssociativeConst = false; //!< Is container constant associative?
  static const Tbool isTree             = false; //!< Is container non constant tree?
  static const Tbool isTreeConst        = false; //!< Is container constant tree?
  static const Tbool isGraph            = false; //!< Is container non constant graph?
  static const Tbool isGraphConst       = false; //!< Is container constant graph?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CWrappedArrayIterator.hpp>
#include <Depth/include/containers/iterators/CWrappedArrayIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CWrappedArray.inl>
/*==========================================================================*/
//! \example example-containers-CWrappedArray.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CWrappedArray.cpp
/*==========================================================================*/
#endif
