/*!
 *  \file    CStringBuffer.hpp Template string buffer container class. String
 *           buffer represents a random access container which stores stings.
 *  \brief   Template string buffer container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template string buffer container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   07.04.2009 03:55:51

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
#ifndef __CSTRINGBUFFER_HPP__
#define __CSTRINGBUFFER_HPP__
/*==========================================================================*/
#include <Depth/include/containers/CArray.hpp>
#include <Depth/include/containers/details/CStringBufferHelper.hpp>
#include <Depth/include/traits/MIfThenElse.hpp>
#include <Depth/include/traits/MAddPointer.hpp>
#include <Depth/include/traits/MRemovePointer.hpp>
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
template <typename T_Type, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CStringBufferIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CStringBufferIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template string buffer container class.
/*!
    String buffer container represents random access  container  which  stores
    strings. You can insert/remove string items into/from any position of  the
    string buffer.

    Every string buffer has its own resize  policy.  It  used  to  dynamically
    choose new buffer size while inserting/removing string items into/from the
    buffer. This policy handles current string buffer size one and returns new
    buffer size depends on count of allocated string items.

    \see NDepth::NContainers::CArray
*/
template <typename T_Type, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CStringBuffer :
  public NCommon::NContainers::IRandom<CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>, T_Type, CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>, CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> >,
  public NCommon::NContainers::IRandomConst<CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>, T_Type, CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>, CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> >
{
  // Friend class: String buffer iterator class (CStringBufferIterator).
  friend class CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>;
  // Friend class: Constant string buffer iterator class (CStringBufferIteratorConst).
  friend class CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptIResizePolicy constraint checking.
  typedef T_ResizePolicy TResizePolicyCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_ResizePolicy template argument constraint to be a resize policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIResizePolicy, TResizePolicyCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CStringBuffer class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef T_Type TType;
  //! Container type.
  typedef CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> TContainer;
  //! Non constant string buffer iterator type.
  typedef CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator> TIterator;
  //! Constant string buffer iterator type.
  typedef CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> TIteratorConst;

  //! Container resize policy type.
  typedef T_ResizePolicy TResizePolicy;
  //! Container copy policy type.
  typedef NPolicy::CCopyPolicyMemory TCopyPolicy;
  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Create an empty string buffer.
  /*!
      \param a_cResizeFactor - String buffer resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CStringBuffer(const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Create a string buffer from constant string array of fixed size.
  /*!
      Constructor creates a string buffer based on given constant string array
      of fixed size.

      \param a_cpArray - Constant pointer to the string array of fixed size.
      \param a_cResizeFactor - String buffer resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  template <Tuint t_Size>
  CStringBuffer(const T_Type (&a_cpArray)[t_Size], const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Create a string buffer from buffer with given size.
  /*!
      Constructor creates a string buffer based on given string buffer with given size.

      \param a_cpBuffer - Constant pointer to the string buffer.
      \param a_cSize - String buffer size.
      \param a_cResizeFactor - String buffer resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CStringBuffer(const T_Type a_cpBuffer[], const Tuint a_cSize, const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringBuffer class.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CStringBuffer(const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CStringBuffer();

  //! Operator: Assign constant string array of fixed size.
  /*!
      \param a_cpArray - Constant pointer to the string array of fixed size.
      \return Reference to the current class instance.
  */
  template <Tuint t_Size>
  CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& operator = (const T_Type (&a_cpArray)[t_Size]);
  //! Operator: Assign another CStringBuffer class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringBuffer class.
      \return Reference to the current class instance.
  */
  CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& operator = (const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance);

  //! Operator: Indexing into the string buffer.
  /*!
      \param a_cIndex - Indexed string buffer position to return.
      \return Reference to string buffer's item under the given index.
  */
  T_Type& operator [] (const Tsint a_cIndex);
  //! Operator: Indexing into the string buffer.
  /*!
      \param a_cIndex - Indexed string buffer position to return.
      \return Reference to string buffer's item under the given index.
  */
  T_Type& operator [] (const Tuint a_cIndex);
  //! Operator: Indexing into the string buffer.
  /*!
      \param a_cIndex - Indexed string buffer position to return.
      \return Constant reference to string buffer's item under the given index.
  */
  const T_Type& operator [] (const Tsint a_cIndex) const;
  //! Operator: Indexing into the string buffer.
  /*!
      \param a_cIndex - Indexed string buffer position to return.
      \return Constant reference to string buffer's item under the given index.
  */
  const T_Type& operator [] (const Tuint a_cIndex) const;

  //! Set a string buffer from constant string array of fixed size.
  /*!
      \param a_cpArray - Constant pointer to the string array of fixed size.
      \return true  - if string buffer was successfully set. \n
              false - if string buffer was not successfully set. \n
  */
  template <Tuint t_Size>
  Tbool set(const T_Type (&a_cpArray)[t_Size]);
  //! Set a string buffer from string buffer with given size.
  /*!
      \param a_cpBuffer - Constant pointer to the string buffer.
      \param a_cSize - String buffer size.
      \return true  - if string buffer was successfully set. \n
              false - if string buffer was not successfully set. \n
  */
  Tbool set(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Set another CStringBuffer class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringBuffer class.
      \return true  - if another string buffer was successfully set. \n
              false - if another string buffer was not successfully set. \n
  */
  Tbool set(const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance);

  //! Get string buffer free size.
  /*!
      Method returns count of free elements in the string buffer.

      \return Count of free elements in the string buffer.
  */
  Tuint getFreeSize() const;

  //! Get string buffer lower capacity bound value.
  /*!
      Method returns lower bound size value before string buffer reallocation.

      \return String buffer lower capacity bound value.
  */
  Tuint getLoCapacity() const;
  //! Get string buffer higher capacity bound value.
  /*!
      Method returns higher bound size value before string buffer reallocation.

      \return String buffer higher capacity bound value.
  */
  Tuint getHiCapacity() const;

  //! Get string buffer's resize factor value.
  /*!
      \return Current string buffer's policy resize factor value.
  */
  Tuint getResizeFactor() const;

  //! Set string buffer's resize factor.
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

  //! Reverse string buffer.
  /*!
      Reverse string buffer items order.
  */
  void reverse();

  //! Serialization load CStringBuffer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CStringBuffer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CStringBuffer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringBuffer class instances.
  /*!
      \param a_rInstance - Reference to another CStringBuffer class instance.
  */
  void swap(CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& a_rInstance);

private:
  CArray<typename NTraits::MAddPointer<T_Type>::type, T_ResizePolicy, NPolicy::CCopyPolicyMemory, T_Allocator> m_StringArray; //!< Array container for the string buffer.
  T_Allocator m_Allocator;              //!< Memory allocator.

  //! Move one string to another.
  /*!
      \param a_rDestination - Reference to the destination string.
      \param a_rpSource - Reference to the pointer to the source string.
      \return true  - if move operation successfully finished. \n
              false - if move operation failed. \n
  */
  Tbool move(T_Type& a_rDestination, typename NTraits::MAddPointer<T_Type>::type& a_rpSource);
  //! Destroy string.
  /*!
      \param a_rpSource - Reference to the pointer to the source string.
      \return true  - if destroy operation successfully finished. \n
              false - if destroy operation failed. \n
  */
  Tbool destroy(typename NTraits::MAddPointer<T_Type>::type& a_rpSource);
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
//! Traits meta-class: string buffer container traits specialization.
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
class MTraitsContainer<NContainers::CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> > :
  public MType<NContainers::CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::TIteratorConst citerator;

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
#include <Depth/include/containers/iterators/CStringBufferIterator.hpp>
#include <Depth/include/containers/iterators/CStringBufferIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CStringBuffer.inl>
/*==========================================================================*/
//! \example example-containers-CStringBuffer.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CStringBuffer.cpp
/*==========================================================================*/
#endif
