/*!
 *  \file    CSortedArray.hpp Template sorted array container class. Sorted
 *           array represents an associative random access container.
 *  \brief   Template sorted array container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template sorted array container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   29.09.2006 02:02:23

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
#ifndef __CSORTEDARRAY_HPP__
#define __CSORTEDARRAY_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ABFind.hpp>
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
#include <Depth/include/common/containers/IAssociative.hpp>
#include <Depth/include/common/containers/IAssociativeConst.hpp>
#include <Depth/include/common/containers/IRandomConst.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/types/MConceptICopyPolicy.hpp>
#include <Depth/include/concept/types/MConceptIResizePolicy.hpp>
#include <Depth/include/containers/policy/CCopyPolicyAssign.hpp>
#include <Depth/include/containers/policy/CCopyPolicyMemory.hpp>
#include <Depth/include/containers/policy/CResizePolicySquareGrow.hpp>
#include <Depth/include/memory/allocators/CAllocatorMemory.hpp>
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
template <typename T_Type, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Type&>, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_CopyPolicy = typename NTraits::MIfThenElse<NTraits::MIsClassOrUnion<T_Type>::yes, NPolicy::CCopyPolicyAssign, NPolicy::CCopyPolicyMemory>::type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CSortedArrayIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Type&>, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_CopyPolicy = typename NTraits::MIfThenElse<NTraits::MIsClassOrUnion<T_Type>::yes, NPolicy::CCopyPolicyAssign, NPolicy::CCopyPolicyMemory>::type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CSortedArrayIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template sorted array container class.
/*!
    Sorted array container represents associative random access container with
    single allocated block of memory. You can associative insert new item into
    the array. It will keep array in a sorted  state.  You  can  access/remove
    items into/from any position of the array.

    Every sorted array has its own compare binary predicate. It used to choose
    correct place for a new item inserting and associative searching.

    Every sorted array has its own  resize  policy.  It  used  to  dynamically
    choose new sorted array size while inserting/removing items into/from  the
    array. This policy handles current sorted array size one and  returns  new
    sorted array size depends on count of allocated items.

    Every sorted array has its own copy policy. It used to  copy  array  items
    while resizing sorted arrays or cloning sorted array.  Copy  policy  wraps
    items copying process.
*/
template <typename T_Type, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Type&>, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_CopyPolicy = typename NTraits::MIfThenElse<NTraits::MIsClassOrUnion<T_Type>::yes, NPolicy::CCopyPolicyAssign, NPolicy::CCopyPolicyMemory>::type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CSortedArray :
  public NCommon::NContainers::IAssociative<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >,
  public NCommon::NContainers::IAssociativeConst<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >,
  public NCommon::NContainers::IRandomConst<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, const T_Type&, const T_Type&>
{
  // Friend class: Sorted array iterator class (CSortedArrayIterator).
  friend class CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>;
  // Friend class: Constant sorted array iterator class (CSortedArrayIteratorConst).
  friend class CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptPredicate2 argument constraint checking.
  typedef const T_Type& TPredicate2ArgumentCheckType;
  //! Type for MConceptPredicate2 constraint checking.
  typedef T_BinaryPredicate TPredicate2CheckType;
  //! Type for MConceptIResizePolicy constraint checking.
  typedef T_ResizePolicy TResizePolicyCheckType;
  //! Type for MConceptICopyPolicy constraint checking.
  typedef T_CopyPolicy TCopyPolicyCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_BinaryPredicate template argument constraint to be a suitable binary predicate.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TPredicate2CheckType, TPredicate2ArgumentCheckType, TPredicate2ArgumentCheckType);
  // Check T_ResizePolicy template argument constraint to be a resize policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIResizePolicy, TResizePolicyCheckType);
  // Check T_CopyPolicy template argument constraint to be a copy policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptICopyPolicy, TCopyPolicyCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CSortedArray class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container associative key type.
  typedef T_Type TKey;
  //! Container associative value type.
  typedef T_Type TValue;

  //! Container value type.
  typedef T_Type TType;
  //! Container type.
  typedef CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> TContainer;
  //! Non constant sorted array iterator type.
  typedef CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> TIterator;
  //! Constant sorted array iterator type.
  typedef CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> TIteratorConst;

  //! Container binary predicate type.
  typedef T_BinaryPredicate TLessThanPredicate;
  //! Container resize policy type.
  typedef T_ResizePolicy TResizePolicy;
  //! Container copy policy type.
  typedef T_CopyPolicy TCopyPolicy;
  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Create an empty sorted array.
  /*!
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_cResizeFactor - Sorted array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSortedArray(T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Create sorted array with one element.
  /*!
      \param a_crValue - Initialize value.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_cResizeFactor - Sorted array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSortedArray(const T_Type& a_crValue, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Create sorted array from constant array of fixed size.
  /*!
      Constructor creates sorted array based on given constant array of  fixed
      size.

      \param a_cpArray - Constant pointer to the array of fixed size.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_cResizeFactor - Sorted array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  template <Tuint t_Size>
  CSortedArray(const T_Type (&a_cpArray)[t_Size], T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Create a sorted array from buffer with given size.
  /*!
      \param a_cpBuffer - Constant pointer to buffer.
      \param a_cSize - Buffer size.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_cResizeFactor - Sorted array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSortedArray(const T_Type a_cpBuffer[], const Tuint a_cSize, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSortedArray class.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_cResizeFactor - Sorted array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSortedArray(const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CSortedArray();

  //! Operator: Assign constant array of fixed size.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return Reference to the current class instance.
  */
  template <Tuint t_Size>
  CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator = (const T_Type (&a_cpArray)[t_Size]);
  //! Operator: Assign another CSortedArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSortedArray class.
      \return Reference to the current class instance.
  */
  CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator = (const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);

  //! Operator: Insert item into sorted array.
  /*!
      \param a_crItem - Constant reference to the item to insert.
      \return Reference to the current class instance.
  */
  CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator += (const T_Type& a_crItem);
  //! Operator: Insert another sorted array into sorted array.
  /*!
      \param a_crSortedArray - Constant reference to the sorted array to insert.
      \return Reference to the current class instance.
  */
  CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator += (const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crSortedArray);
  //! Operator: Remove item from sorted array.
  /*!
      \param a_crItem - Constant reference to the item to remove.
      \return Reference to the current class instance.
  */
  CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator -= (const T_Type& a_crItem);
  //! Operator: Remove another sorted array from sorted array.
  /*!
      \param a_crSortedArray - Constant reference to the sorted array to remove.
      \return Reference to the current class instance.
  */
  CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator -= (const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crSortedArray);

  //! Operator: Find non constant iterator with given value in sorted array.
  /*!
      \param a_crItem - Constant reference to the searching item.
      \return Non constant iterator with given value or invalid empty iterator.
  */
  TIterator operator [] (const T_Type& a_crItem);
  //! Operator: Find constant iterator with given value in sorted array.
  /*!
      \param a_crItem - Constant reference to the searching item.
      \return Constant iterator with given value or invalid empty iterator.
  */
  TIteratorConst operator [] (const T_Type& a_crItem) const;

  //! Operator: Indexing into the sorted array's buffer.
  /*!
      \param a_cIndex - Indexed sorted array position to return.
      \return Constant reference to sorted array's item under the given index.
  */
  const T_Type& operator [] (const Tsint a_cIndex);
  //! Operator: Indexing into the sorted array's buffer.
  /*!
      \param a_cIndex - Indexed sorted array position to return.
      \return Constant reference to sorted array's item under the given index.
  */
  const T_Type& operator [] (const Tuint a_cIndex);
  //! Operator: Indexing into the sorted array's buffer.
  /*!
      \param a_cIndex - Indexed sorted array position to return.
      \return Constant reference to sorted array's item under the given index.
  */
  const T_Type& operator [] (const Tsint a_cIndex) const;
  //! Operator: Indexing into the sorted array's buffer.
  /*!
      \param a_cIndex - Indexed sorted array position to return.
      \return Constant reference to sorted array's item under the given index.
  */
  const T_Type& operator [] (const Tuint a_cIndex) const;

  //! Operator: Get pointer to the current sorted array's buffer.
  /*!
      \return Constant pointer to the current sorted array's buffer.
      \see NDepth::NContainers::CSortedArray::getBuffer()
  */
  operator const T_Type* ();
  //! Operator: Get constant pointer to the current sorted array's buffer.
  /*!
      \return Constant pointer to the current sorted array's buffer.
      \see NDepth::NContainers::CSortedArray::getBuffer()
  */
  operator const T_Type* () const;

  //! Set a sorted array from constant array of fixed size.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if sorted array was successfully set. \n
              false - if sorted array was not successfully set. \n
  */
  template <Tuint t_Size>
  Tbool set(const T_Type (&a_cpArray)[t_Size]);
  //! Set a sorted array from buffer with given size.
  /*!
      \param a_cpBuffer - Constant pointer to buffer.
      \param a_cSize - Buffer size.
      \return true  - if sorted array was successfully set. \n
              false - if sorted array was not successfully set. \n
  */
  Tbool set(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Set another CSortedArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSortedArray class.
      \return true  - if another sorted array was successfully set. \n
              false - if another sorted array was not successfully set. \n
  */
  Tbool set(const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);

  //! Get sorted array free size.
  /*!
      Method returns count of free elements in sorted array.

      \return Count of free elements in sorted array.
  */
  Tuint getFreeSize() const;

  //! Get sorted array lower capacity bound value.
  /*!
      Method returns lower bound size value before sorted array reallocation.

      \return Sorted array lower capacity bound value.
  */
  Tuint getLoCapacity() const;
  //! Get sorted array higher capacity bound value.
  /*!
      Method returns higher bound size value before sorted array reallocation.

      \return Sorted array higher capacity bound value.
  */
  Tuint getHiCapacity() const;

  //! Get ponter to sorted array buffer.
  /*!
      Method returns pointer to sorted array buffer. Using of this pointer  is
      quite dangerous cause it may lead to memory  errors.  That  is  why  you
      always have to  check  sorted  array  bounds  while  working  with  this
      pointer.

      \return Constant pointer to sorted array buffer.
  */
  const T_Type* getBuffer();
  //! Get constant ponter to sorted array buffer.
  /*!
      Method returns constant pointer to sorted array buffer.  Using  of  this
      pointer is quite dangerous cause it may lead to memory errors.  That  is
      why you always have to check sorted array bounds while working with this
      pointer.

      \return Constant pointer to sorted array buffer.
  */
  const T_Type* getBuffer() const;

  //! Get sorted array's resize factor value.
  /*!
      \return Current sorted array's policy resize factor value.
  */
  Tuint getResizeFactor() const;

  //! Set sorted array's resize factor.
  /*!
      Method sets new policy resize factor. If given resize factor is invalid,
      then policy will use the default value as current resize factor.

      \param a_cResizeFactor - Resize factor.
      \return true  - if resize factor successfully set. \n
              false - if resize factor is invalid. \n
  */
  Tbool setResizeFactor(const Tuint a_cResizeFactor);

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IAccociative interface overriding methods.
  virtual Tbool insert(const T_Type& a_crItem);
  virtual Tbool insert(const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crSortedArray);
  virtual Tbool remove(const T_Type& a_crItem, const Tbool a_cRemoveSame = false);
  virtual Tbool remove(const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crSortedArray, const Tbool a_cRemoveSame = false);

  // IAccociativeConst interface overriding methods.
  virtual Tbool isLessThan(const T_Type& a_crItem1, const T_Type& a_crItem2) const;
  virtual TIterator      find(const T_Type& a_crItem);
  virtual TIteratorConst find(const T_Type& a_crItem) const;

  // IRandomConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;
  virtual TIterator      getItIndex(const Tuint a_cIndex);
  virtual TIteratorConst getItIndex(const Tuint a_cIndex) const;

  //! Remove item from sorted array first position.
  /*!
      Method removes item from sorted array first position.

      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  Tbool removeFirst();
  //! Remove item from sorted array first position.
  /*!
      Method removes item from sorted array first position.

      \param a_rItem - Reference to returned removed item.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  Tbool removeFirst(T_Type& a_rItem);

  //! Remove item from sorted array last position.
  /*!
      Method removes item from sorted array last position.

      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  Tbool removeLast();
  //! Remove item from sorted array last position.
  /*!
      Method removes item from sorted array last position.

      \param a_rItem - Reference to returned removed item.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  Tbool removeLast(T_Type& a_rItem);

  //! Remove item from sorted array indexed position.
  /*!
      Method removes item from sorted array indexed position.

      \param a_cIndex - Indexed sorted array position to remove.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  Tbool removeIndex(const Tuint a_cIndex);
  //! Remove item from sorted array indexed position.
  /*!
      Method removes item from sorted array indexed position.

      \param a_cIndex - Indexed sorted array position to remove.
      \param a_rItem - Reference to returned removed item.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  Tbool removeIndex(const Tuint a_cIndex, T_Type& a_rItem);

  //! Remove items interval from sorted array indexed position.
  /*!
      Method removes items interval from sorted array indexed position.

      \param a_cIndex - Indexed sorted array position to remove.
      \param a_cSize - Size of removed interval.
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  Tbool remove(const Tuint a_cIndex, const Tuint a_cSize);

  //! Serialization load CSortedArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CSortedArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CSortedArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CSortedArray class instances.
  /*!
      \param a_rInstance - Reference to another CSortedArray class instance.
  */
  void swap(CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_rInstance);

private:
  Tuint             m_Size;             //!< Sorted array's size.
  T_Type*           m_pData;            //!< Pointer to sorted array's buffer.
  T_BinaryPredicate m_fLessThan;        //!< Current 'LessThan' binary predicate.
  T_ResizePolicy    m_ResizePolicy;     //!< Sorted array's resize policy.
  T_Allocator       m_Allocator;        //!< Memory allocator.

  //! Resize sorted array to the given size.
  /*!
      For sorted array this method is availiable only for internal usage.

      \param a_cSize - New sorted array size.
      \return true  - if sorted array was successfully resized. \n
              false - if sorted array was not successfully resized. \n
  */
  Tbool resize(const Tuint a_cSize);
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
//! Traits meta-class: sorted array container traits specialization.
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
class MTraitsContainer<NContainers::CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> > :
  public MType<NContainers::CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst citerator;

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
  static const Tbool isAssociative      = true;  //!< Is container non constant associative?
  static const Tbool isAssociativeConst = true;  //!< Is container constant associative?
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
#include <Depth/include/containers/iterators/CSortedArrayIterator.hpp>
#include <Depth/include/containers/iterators/CSortedArrayIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CSortedArray.inl>
/*==========================================================================*/
//! \example example-containers-CSortedArray.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CSortedArray.cpp
/*==========================================================================*/
#endif
