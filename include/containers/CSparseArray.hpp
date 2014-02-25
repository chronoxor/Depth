/*!
 *  \file    CSparseArray.hpp Template sparse array container class. Sparse
 *           array represents a random access container with empty intervals.
 *  \brief   Template sparse array container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.09.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template sparse array container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   28.09.2007 21:37:00

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
#ifndef __CSPARSEARRAY_HPP__
#define __CSPARSEARRAY_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ALowerBound.hpp>
#include <Depth/include/common/containers/IRandom.hpp>
#include <Depth/include/common/containers/IRandomConst.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/containers/MConceptAssociative.hpp>
#include <Depth/include/concept/containers/MConceptAssociativeConst.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/containers/CBinTreeRB.hpp>
#include <Depth/include/containers/details/CSparseValue.hpp>
#include <Depth/include/containers/details/FSparseValueComparator.hpp>
#include <Depth/include/functors/CFunctor2.hpp>
#include <Depth/include/memory/allocators/CAllocatorMemory.hpp>
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
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CSparseArrayIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CSparseArrayIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template space array container class.
/*!
    Sparse array container  represents  random  access  container  with  empty
    intervals.  You  can  insert/remove  items  and  intervals  into/from  any
    position of the space array.

    Example:
    \code
    CSparseArray<Tsint> sparse;

    // Fill the sparse array.
    sparse.fillIndex(1, 1);
    sparse.fillIndex(3, 3);
    sparse.fillIndex(5, 5);
    sparse.fillIndex(7, 7);
    sparse.fillIndex(9, 9);

    // Erase items from the sparse array.
    sparse.eraseIndex(1);
    sparse.eraseIndex(3);
    sparse.eraseIndex(5);
    sparse.eraseIndex(7);
    sparse.eraseIndex(9);
    \endcode
*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CSparseArray :
  public NCommon::NContainers::IRandom<CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NContainers::IRandomConst<CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> >
{
  // Friend class: Array iterator class (CSparseArrayIterator).
  friend class CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>;
  // Friend class: Constant array iterator class (CSparseArrayIteratorConst).
  friend class CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptAssociative constraint checking.
  typedef T_AssociativeContainer<NDetails::CSparseValue<T_Type>, NDetails::FSparseValueComparator<T_Type>, T_Allocator> TAssociativeContainerCheckType;
  //! Type for MConceptAssociativeConst constraint checking.
  typedef T_AssociativeContainer<NDetails::CSparseValue<T_Type>, NDetails::FSparseValueComparator<T_Type>, T_Allocator> TAssociativeContainerConstCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_AssociativeContainer template argument constraint to be a non constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociative, TAssociativeContainerCheckType);
  // Check T_AssociativeContainer template argument constraint to be a constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociativeConst, TAssociativeContainerConstCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CSparseArray class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef T_Type TType;
  //! Container type.
  typedef CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> TContainer;
  //! Non constant array iterator type.
  typedef CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> TIterator;
  //! Constant array iterator type.
  typedef CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> TIteratorConst;

  //! Base associative container type.
  typedef T_AssociativeContainer<NDetails::CSparseValue<T_Type>, NDetails::FSparseValueComparator<T_Type>, T_Allocator> TAssociativeContainer;
  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Create an empty sparse array with given size and index.
  /*!
      Constructor allocates buffer for items with given size,  but  it  leaves
      those items initialized only with their default constructors. The buffer
      is placed into the sparse array with a given index to insert.

      \param a_cIndex - Index to insert (default is 0).
      \param a_cSize - Allocated array size (default is 0).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSparseArray(const Tuint a_cIndex = 0, const Tuint a_cSize = 0, const T_Allocator& a_crAllocator = T_Allocator());
  //! Create an empty sparse array with given size and index. Initialize all elements with given value.
  /*!
      Constructor  allocates  buffer  for  items  with  given  size.  Then  it
      initialize items with given value. The buffer is placed into the  sparse
      array with a given index to insert.

      \param a_cIndex - Index to insert.
      \param a_crValue - Initialize value.
      \param a_cSize - Allocated array size.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSparseArray(const Tuint a_cIndex, const T_Type& a_crValue, const Tuint a_cSize, const T_Allocator& a_crAllocator = T_Allocator());
  //! Create a sparse array from constant array of fixed size and given index.
  /*!
      Constructor creates a sparse array based  on  given  constant  array  of
      fixed size with a given index to insert.

      \param a_cIndex - Index to insert.
      \param a_cpArray - Constant pointer to the array of fixed size.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  template <Tuint t_Size>
  CSparseArray(const Tuint a_cIndex, const T_Type (&a_cpArray)[t_Size], const T_Allocator& a_crAllocator = T_Allocator());
  //! Create a sparse array from buffer with given size and given index.
  /*!
      Constructor creates a sparse array based on given buffer with given size
      with a given index to insert.

      \param a_cIndex - Index to insert.
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSparseArray(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSparseArray class.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSparseArray(const CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CSparseArray();

  //! Operator: Assign constant array of fixed size.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return Reference to the current class instance.
  */
  template <Tuint t_Size>
  CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& operator = (const T_Type (&a_cpArray)[t_Size]);
  //! Operator: Assign another CSparseArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSparseArray class.
      \return Reference to the current class instance.
  */
  CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& operator = (const CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Operator: Indexing into the sparse array's buffer.
  /*!
      \param a_cIndex - Indexed sparse array position to return.
      \return Reference to sparse array's item under the given index.
  */
  T_Type& operator [] (const Tsint a_cIndex);
  //! Operator: Indexing into the sparse array's buffer.
  /*!
      \param a_cIndex - Indexed sparse array position to return.
      \return Reference to sparse array's item under the given index.
  */
  T_Type& operator [] (const Tuint a_cIndex);
  //! Operator: Indexing into the sparse array's buffer.
  /*!
      \param a_cIndex - Indexed sparse array position to return.
      \return Constant reference to sparse array's item under the given index.
  */
  const T_Type& operator [] (const Tsint a_cIndex) const;
  //! Operator: Indexing into the sparse array's buffer.
  /*!
      \param a_cIndex - Indexed sparse array position to return.
      \return Constant reference to sparse array's item under the given index.
  */
  const T_Type& operator [] (const Tuint a_cIndex) const;

  //! Set a sparse array from constant array of fixed size and given index.
  /*!
      \param a_cIndex - Index to insert.
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if sparse array was successfully set. \n
              false - if sparse array was not successfully set. \n
  */
  template <Tuint t_Size>
  Tbool set(const Tuint a_cIndex, const T_Type (&a_cpArray)[t_Size]);
  //! Set a sparse array from buffer with given size and given index.
  /*!
      \param a_cIndex - Index to insert.
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if sparse array was successfully set. \n
              false - if sparse array was not successfully set. \n
  */
  Tbool set(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Set another CSparseArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSparseArray class.
      \return true  - if another sparse array was successfully set. \n
              false - if another sparse array was not successfully set. \n
  */
  Tbool set(const CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Check if given index is valid.
  /*!
      \param a_cIndex - Index to check.
      \return true  - if sparse array has item under the given index. \n
              false - if sparse array doesn't have item under the given index. \n
  */
  Tbool isValidIndex(const Tuint a_cIndex) const;

  //! Get first index of sparse array item.
  /*!
      \return First index of sparse array item.
  */
  Tuint getFirstIndex() const;
  //! Get last index of sparse array item.
  /*!
      \return Last index of sparse array item.
  */
  Tuint getLastIndex() const;

  //! Get count of sparse array intervals.
  /*!
      \return Count of sparse array intervals.
  */
  Tuint getIntervalsCount() const;

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IRandom interface overriding methods.
  virtual Tbool insertFirst(const T_Type& a_crItem);
  virtual Tbool insertLast(const T_Type& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const T_Type& a_crItem);
  virtual Tbool removeFirst();
  virtual Tbool removeFirst(T_Type& a_rItem);
  virtual Tbool removeLast();
  virtual Tbool removeLast(T_Type& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex);
  virtual Tbool removeIndex(const Tuint a_cIndex, T_Type& a_rItem);
  virtual Tbool remove(const Tuint a_cIndex, const Tuint a_cSize);

  // IRandomConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;
  virtual TIterator      getItIndex(const Tuint a_cIndex);
  virtual TIteratorConst getItIndex(const Tuint a_cIndex) const;

  //! Insert a constant array of fixed size into the first sparse array position.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully inserted. \n
              false - if constant array of fixed size was not successfully inserted. \n
  */
  template <Tuint t_Size>
  Tbool insertFirst(const T_Type (&a_cpArray)[t_Size]);
  //! Insert a buffer with given size into the first sparse array position.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully inserted. \n
              false - if buffer with given size was not successfully inserted. \n
  */
  Tbool insertFirst(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Insert a constant array of fixed size into the last sparse array position.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully inserted. \n
              false - if constant array of fixed size was not successfully inserted. \n
  */
  template <Tuint t_Size>
  Tbool insertLast(const T_Type (&a_cpArray)[t_Size]);
  //! Insert a buffer with given size into the last sparse array position.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully inserted. \n
              false - if buffer with given size was not successfully inserted. \n
  */
  Tbool insertLast(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Insert a constant array of fixed size into the indexed sparse array position.
  /*!
      \param a_cIndex - Index to insert.
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully inserted. \n
              false - if constant array of fixed size was not successfully inserted. \n
  */
  template <Tuint t_Size>
  Tbool insertIndex(const Tuint a_cIndex, const T_Type (&a_cpArray)[t_Size]);
  //! Insert a buffer with given size into the indexed sparse array position.
  /*!
      \param a_cIndex - Index to insert.
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully inserted. \n
              false - if buffer with given size was not successfully inserted. \n
  */
  Tbool insertIndex(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize);

  //! Fill sparse array with an item from the first available index.
  /*!
      \param a_crItem - Constant reference to the item.
      \return true  - if the item was successfully filled into the sparse array. \n
              false - if the item was not successfully filled into the sparse array. \n
  */
  Tbool fillFirst(const T_Type& a_crItem);
  //! Fill sparse array with a constant array of fixed size from the first available index.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully filled into the sparse array. \n
              false - if constant array of fixed size was not successfully filled into the sparse array. \n
  */
  template <Tuint t_Size>
  Tbool fillFirst(const T_Type (&a_cpArray)[t_Size]);
  //! Fill sparse array with a buffer with given size from the first available index.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully filled into the sparse array. \n
              false - if buffer with given size was not successfully filled into the sparse array. \n
  */
  Tbool fillFirst(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Fill sparse array with an item from the last available index.
  /*!
      \param a_crItem - Constant reference to the item.
      \return true  - if the item was successfully filled into the sparse array. \n
              false - if the item was not successfully filled into the sparse array. \n
  */
  Tbool fillLast(const T_Type& a_crItem);
  //! Fill sparse array with a constant array of fixed size from the last available index.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully filled into the sparse array. \n
              false - if constant array of fixed size was not successfully filled into the sparse array. \n
  */
  template <Tuint t_Size>
  Tbool fillLast(const T_Type (&a_cpArray)[t_Size]);
  //! Fill sparse array with a buffer with given size from the last available index.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully filled into the sparse array. \n
              false - if buffer with given size was not successfully filled into the sparse array. \n
  */
  Tbool fillLast(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Fill sparse array with an item from the given index.
  /*!
      \param a_cIndex - Index to fill.
      \param a_crItem - Constant reference to the item.
      \return true  - if the item was successfully filled into the sparse array. \n
              false - if the item was not successfully filled into the sparse array. \n
  */
  Tbool fillIndex(const Tuint a_cIndex, const T_Type& a_crItem);
  //! Fill sparse array with a constant array of fixed size from the given index.
  /*!
      \param a_cIndex - Index to fill.
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully filled into the sparse array. \n
              false - if constant array of fixed size was not successfully filled into the sparse array. \n
  */
  template <Tuint t_Size>
  Tbool fillIndex(const Tuint a_cIndex, const T_Type (&a_cpArray)[t_Size]);
  //! Fill sparse array with a buffer with given size from the given index.
  /*!
      \param a_cIndex - Index to fill.
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully filled into the sparse array. \n
              false - if buffer with given size was not successfully filled into the sparse array. \n
  */
  Tbool fillIndex(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize);

  //! Erase first value from sparse array.
  /*!
      \return true  - if first item was successfully erased from sparse array. \n
              false - if first item was not successfully erased from sparse array. \n
  */
  Tbool eraseFirst();
  //! Erase and return first value from sparse array.
  /*!
      \param a_rItem - Reference to the returning item.
      \return true  - if first item was successfully erased from sparse array. \n
              false - if first item was not successfully erased from sparse array. \n
  */
  Tbool eraseFirst(T_Type& a_rItem);
  //! Erase last value from sparse array.
  /*!
      \return true  - if last item was successfully erased from sparse array. \n
              false - if last item was not successfully erased from sparse array. \n
  */
  Tbool eraseLast();
  //! Erase and return last value from sparse array.
  /*!
      \param a_rItem - Reference to the returning item.
      \return true  - if last item was successfully erased from sparse array. \n
              false - if last item was not successfully erased from sparse array. \n
  */
  Tbool eraseLast(T_Type& a_rItem);
  //! Erase value from sparse array by its index.
  /*!
      \param a_cIndex - Index of the removed item.
      \return true  - if an item was successfully erased from sparse array by its index. \n
              false - if an item was not successfully erased from sparse array by its index. \n
  */
  Tbool eraseIndex(const Tuint a_cIndex);
  //! Erase and return value from sparse array by its index.
  /*!
      \param a_cIndex - Index of the removed item.
      \param a_rItem - Reference to the returning item.
      \return true  - if an item was successfully erased from sparse array by its index. \n
              false - if an item was not successfully erased from sparse array by its index. \n
  */
  Tbool eraseIndex(const Tuint a_cIndex, T_Type& a_rItem);
  //! Erase given interval from sparse array.
  /*!
      \param a_cIndex - Index of the removed interval.
      \param a_cSize - Interval size.
      \return true  - if given interval was successfully erased from sparse array. \n
              false - if given interval was not successfully erased from sparse array. \n
  */
  Tbool erase(const Tuint a_cIndex, const Tuint a_cSize);

  //! Serialization load CSparseArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CSparseArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CSparseArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CSparseArray class instances.
  /*!
      \param a_rInstance - Reference to another CSparseArray class instance.
  */
  void swap(CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& a_rInstance);

private:
  Tuint m_Size;                                                                                                                         //!< Sparse array's size.
  T_AssociativeContainer<NDetails::CSparseValue<T_Type>, NDetails::FSparseValueComparator<T_Type>, T_Allocator> m_AssociativeContainer; //!< Associative container for the sparse array.
  T_Allocator m_Allocator;                                                                                                              //!< Memory allocator.

  //! Internal insert engine.
  /*!
      \param a_cIndex - Index to insert.
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \param a_pIterator - Pointer to the returning inserted sparse array value iterator (default is NULL).
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  Tbool insertInternal(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize, TIterator* a_pIterator = NULL);
  //! Internal remove engine.
  /*!
      \param a_cIndex - Index to remove.
      \param a_cSize - Size of removed interval.
      \param a_cCheck - Check if removed item exists.
      \param a_pItem - Pointer to the returning item (default is NULL).
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  Tbool removeInternal(const Tuint a_cIndex, const Tuint a_cSize, const Tbool a_cCheck, T_Type* a_pItem = NULL);
  //! Internal fill engine.
  /*!
      \param a_cIndex - Index to fill.
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if filling was successful. \n
              false - if filling was not successful. \n
  */
  Tbool fillInternal(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Internal erase engine.
  /*!
      \param a_cIndex - Index to erase.
      \param a_cSize - Size of erase interval.
      \param a_cCheck - Check if erased item exists.
      \param a_pItem - Pointer to the returning item (default is NULL).
      \return true  - if erasing was successful. \n
              false - if erasing was not successful. \n
  */
  Tbool eraseInternal(const Tuint a_cIndex, const Tuint a_cSize, const Tbool a_cCheck, T_Type* a_pItem = NULL);

  //! Create a new sparse value based on the given buffer.
  /*!
      \param a_cIndex - Index to insert.
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return New sparse value.
  */
  NDetails::CSparseValue<T_Type> createSparseValue(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Create a new sparse value based based on the given one and the given buffer.
  /*!
      \param a_cpSparseValue - Constant pointer to the given sparse value.
      \param a_cIndex - Index to insert.
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return New sparse value.
  */
  NDetails::CSparseValue<T_Type> createSparseValue(const NDetails::CSparseValue<T_Type>* a_cpSparseValue, const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Create a new sparse value based on the given left and right sparse values.
  /*!
      \param a_cpLeftSparseValue - Constant pointer to the given left sparse value.
      \param a_cLeftIndex - Left index to insert.
      \param a_cpRightSparseValue - Constant pointer to the given right sparse value.
      \param a_cRightIndex - Right index to insert.
      \return New sparse value.
  */
  NDetails::CSparseValue<T_Type> createSparseValue(const NDetails::CSparseValue<T_Type>* a_cpLeftSparseValue, const Tuint a_cLeftIndex, const NDetails::CSparseValue<T_Type>* a_cpRightSparseValue, const Tuint a_cRightIndex);
  //! Create a new sparse value based on the given left and right sparse values and the given buffer.
  /*!
      \param a_cpLeftSparseValue - Constant pointer to the given left sparse value.
      \param a_cLeftIndex - Left index to insert.
      \param a_cpRightSparseValue - Constant pointer to the given right sparse value.
      \param a_cRightIndex - Right index to insert.
      \param a_cIndex - Index to insert.
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return New sparse value.
  */
  NDetails::CSparseValue<T_Type> createSparseValue(const NDetails::CSparseValue<T_Type>* a_cpLeftSparseValue, const Tuint a_cLeftIndex, const NDetails::CSparseValue<T_Type>* a_cpRightSparseValue, const Tuint a_cRightIndex, const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Delete given sparse value.
  /*!
      \param a_cpSparseValue - Constant pointer to the sparse value.
      \return true  - if sparse value was successfully deleted. \n
              false - if sparse value was not successfully deleted. \n
  */
  Tbool deleteSparseValue(const NDetails::CSparseValue<T_Type>* a_cpSparseValue);

  //! Get non constant iterator to the closest sparse array value.
  /*!
      \param a_cIndex - Searching index.
      \param a_cLeft - Left interval flag (default is false).
      \param a_cRight - Right interval flag (default is false).
      \return Iterator to the closest sparse array value.
  */
  TIterator getItClosest(const Tuint a_cIndex, const Tbool a_cLeft = false, const Tbool a_cRight = false);
  //! Get constant iterator to the closest sparse array value.
  /*!
      \param a_cIndex - Searching index.
      \param a_cLeft - Left interval flag (default is false).
      \param a_cRight - Right interval flag (default is false).
      \return Constant iterator to the closest sparse array value.
  */
  TIteratorConst getItClosest(const Tuint a_cIndex, const Tbool a_cLeft = false, const Tbool a_cRight = false) const;
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
//! Traits meta-class: sparse array container traits specialization.
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class MTraitsContainer<NContainers::CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> > :
  public MType<NContainers::CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = true;  //!< Is container non constant queue?
  static const Tbool isQueueConst       = true;  //!< Is container constant queue?
  static const Tbool isDeque            = true;  //!< Is container non constant deque?
  static const Tbool isDequeConst       = true;  //!< Is container constant deque?
  static const Tbool isRandom           = true;  //!< Is container non constant random?
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
#include <Depth/include/containers/iterators/CSparseArrayIterator.hpp>
#include <Depth/include/containers/iterators/CSparseArrayIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CSparseArray.inl>
/*==========================================================================*/
//! \example example-containers-CSparseArray.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CSparseArray.cpp
/*==========================================================================*/
#endif
