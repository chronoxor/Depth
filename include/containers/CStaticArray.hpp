/*!
 *  \file    CStaticArray.hpp Template static array container class. Static
 *           array represents a fixed-sized random access container.
 *  \brief   Template static array container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template static array container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   05.09.2006 20:25:46

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
#ifndef __CSTATICARRAY_HPP__
#define __CSTATICARRAY_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/common/containers/IRandomConst.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/types/MConceptICopyPolicy.hpp>
#include <Depth/include/containers/policy/CCopyPolicyAssign.hpp>
#include <Depth/include/containers/policy/CCopyPolicyMemory.hpp>
#include <Depth/include/traits/MIsClassOrUnion.hpp>
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
template <typename T_Type, Tuint t_Size, class T_CopyPolicy = typename NTraits::MIfThenElse<NTraits::MIsClassOrUnion<T_Type>::yes, NPolicy::CCopyPolicyAssign, NPolicy::CCopyPolicyMemory>::type>
class CStaticArrayIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy = typename NTraits::MIfThenElse<NTraits::MIsClassOrUnion<T_Type>::yes, NPolicy::CCopyPolicyAssign, NPolicy::CCopyPolicyMemory>::type>
class CStaticArrayIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template static array container class.
/*!
    Static array container represents fixed-sized random access container with
    single allocated block of memory. You cannot insert/remove items into/from
    the fixed-sized array. But you can freely change values of the fixed-sized
    array.

    Every array has its own copy policy. It used to  copy  array  items  while
    resizing arrays or cloning array. Copy policy wraps items copying process.
*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy = typename NTraits::MIfThenElse<NTraits::MIsClassOrUnion<T_Type>::yes, NPolicy::CCopyPolicyAssign, NPolicy::CCopyPolicyMemory>::type>
class CStaticArray :
  public NCommon::NContainers::IRandomConst<CStaticArray<T_Type, t_Size, T_CopyPolicy>, T_Type, CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>, CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> >
{
  // Friend class: Static array iterator class (CStaticArrayIterator).
  friend class CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>;
  // Friend class: Constant static array iterator class (CStaticArrayIteratorConst).
  friend class CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptICopyPolicy constraint checking.
  typedef T_CopyPolicy TCopyPolicyCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CStaticArray<T_Type, t_Size, T_CopyPolicy> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_CopyPolicy template argument constraint to be a copy policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptICopyPolicy, TCopyPolicyCheckType);
  // Check CStaticArray class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef T_Type TType;
  //! Container type.
  typedef CStaticArray<T_Type, t_Size, T_CopyPolicy> TContainer;
  //! Non constant static array iterator type.
  typedef CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> TIterator;
  //! Constant static array iterator type.
  typedef CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> TIteratorConst;

  //! Container copy policy type.
  typedef T_CopyPolicy TCopyPolicy;

  //! Create an empty static array.
  /*!
      Constructor allocates buffer  for  items,  but  it  leaves  those  items
      initialized only with their default constructors.
  */
  CStaticArray();
  //! Create an empty static array. Initialize all elements with given value.
  /*!
      Constructor allocates buffer for items. Then it initializes items with
      given value.

      \param a_crValue - Initialize value.
  */
  CStaticArray(const T_Type& a_crValue);
  //! Create static array from array of fixed size.
  /*!
      Constructor creates static array based on given array of fixed size.

      \param a_cpArray - Constant pointer to the array of fixed size.
  */
  template <Tuint t_OtherSize>
  CStaticArray(const T_Type (&a_cpArray)[t_OtherSize]);
  //! Create static array from buffer with given size.
  /*!
      Constructor creates static array based on given buffer with given size.

      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size (default is t_Size).
  */
  CStaticArray(const T_Type a_cpBuffer[], const Tuint a_cSize = t_Size);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStaticArray class.
  */
  CStaticArray(const CStaticArray<T_Type, t_Size, T_CopyPolicy>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStaticArray();

  //! Operator: Assign constant array of fixed size.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return Reference to the current class instance.
  */
  template <Tuint t_OtherSize>
  CStaticArray<T_Type, t_Size, T_CopyPolicy>& operator = (const T_Type (&a_cpArray)[t_OtherSize]);
  //! Operator: Assign another CStaticArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStaticArray class.
      \return Reference to the current class instance.
  */
  CStaticArray<T_Type, t_Size, T_CopyPolicy>& operator = (const CStaticArray<T_Type, t_Size, T_CopyPolicy>& a_crInstance);

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
      \see NDepth::NContainers::CStaticArray::getBuffer()
  */
  operator T_Type* ();
  //! Operator: Get constant pointer to the current array's buffer.
  /*!
      \return Constant pointer to the current array's buffer.
      \see NDepth::NContainers::CStaticArray::getBuffer()
  */
  operator const T_Type* () const;

  //! Set static array filled with a given value.
  /*!
      \param a_crValue - Initialize value.
      \return true  - if static array was successfully set. \n
              false - if static array was not successfully set. \n
  */
  Tbool set(const T_Type& a_crValue);
  //! Set static array from constant array of fixed size.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if static array was successfully set. \n
              false - if static array was not successfully set. \n
  */
  template <Tuint t_OtherSize>
  Tbool set(const T_Type (&a_cpArray)[t_OtherSize]);
  //! Set static array from buffer with given size.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size (default is t_Size).
      \return true  - if static array was successfully set. \n
              false - if static array was not successfully set. \n
  */
  Tbool set(const T_Type a_cpBuffer[], const Tuint a_cSize = t_Size);
  //! Set another CStaticArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStaticArray class.
      \return true  - if another static array was successfully set. \n
              false - if another static array was not successfully set. \n
  */
  Tbool set(const CStaticArray<T_Type, t_Size, T_CopyPolicy>& a_crInstance);

  //! Get static array free size.
  /*!
      Method always returns 0, because static array cannot be resized.

      \return Count of free elements in the static array (always 0).
  */
  Tuint getFreeSize() const;

  //! Get static array lower capacity bound value.
  /*!
      Method returns lower bound size value before static array  reallocation.
      As static array does not support resizing, this method always returns 0.

      \return Static array lower capacity bound value (always 0).
  */
  Tuint getLoCapacity() const;
  //! Get static array higher capacity bound value.
  /*!
      Method returns higher bound size value before static array reallocation.
      As static array does not support resizing, this  method  always  returns
      t_Size.

      \return Static array higher capacity bound value (always t_Size).
  */
  Tuint getHiCapacity() const;

  //! Get ponter to the static array buffer.
  /*!
      Method returns pointer to the static array buffer. Using of this pointer
      is quite dangerous cause it may lead to memory errors. That is  why  you
      always have to  check  static  array  bounds  while  working  with  this
      pointer.

      \return Pointer to the static array buffer.
  */
  T_Type* getBuffer();
  //! Get constant ponter to the static array buffer.
  /*!
      Method returns constant pointer to the static  array  buffer.  Using  of
      this pointer is quite dangerous cause it may lead to memory errors. That
      is why you always have to check static array bounds while  working  with
      this pointer.

      \return Constant pointer to the static array buffer.
  */
  const T_Type* getBuffer() const;

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

  //! Reverse static array.
  /*!
      Reverse static array items order.
  */
  void reverse();

  //! Serialization load CStaticArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CStaticArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CStaticArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStaticArray class instances.
  /*!
      \param a_rInstance - Reference to another CStaticArray class instance.
  */
  void swap(CStaticArray<T_Type, t_Size, T_CopyPolicy>& a_rInstance);

private:
  T_Type m_pData[t_Size];               //!< Pointer to static array's buffer.
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
//! Traits meta-class: static array container traits specialization.
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
class MTraitsContainer<NContainers::CStaticArray<T_Type, t_Size, T_CopyPolicy> > :
  public MType<NContainers::CStaticArray<T_Type, t_Size, T_CopyPolicy> >
{
public:
  //! Container value type.
  typedef typename NContainers::CStaticArray<T_Type, t_Size, T_CopyPolicy>::TType value;
  //! Container type.
  typedef typename NContainers::CStaticArray<T_Type, t_Size, T_CopyPolicy>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CStaticArray<T_Type, t_Size, T_CopyPolicy>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CStaticArray<T_Type, t_Size, T_CopyPolicy>::TIteratorConst citerator;

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
#include <Depth/include/containers/iterators/CStaticArrayIterator.hpp>
#include <Depth/include/containers/iterators/CStaticArrayIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CStaticArray.inl>
/*==========================================================================*/
//! \example example-containers-CStaticArray.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CStaticArray.cpp
/*==========================================================================*/
#endif
