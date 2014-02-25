/*!
 *  \file    CArray.hpp Template array container class. Array represents a
 *           random access container.
 *  \brief   Template array container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template array container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   31.03.2006 02:11:31

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
#ifndef __CARRAY_HPP__
#define __CARRAY_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/common/containers/IRandom.hpp>
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
template <typename T_Type, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_CopyPolicy = typename NTraits::MIfThenElse<NTraits::MIsClassOrUnion<T_Type>::yes, NPolicy::CCopyPolicyAssign, NPolicy::CCopyPolicyMemory>::type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CArrayIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_CopyPolicy = typename NTraits::MIfThenElse<NTraits::MIsClassOrUnion<T_Type>::yes, NPolicy::CCopyPolicyAssign, NPolicy::CCopyPolicyMemory>::type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CArrayIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template array container class.
/*!
    Array container represents random access container with  single  allocated
    block of memory. You can insert/remove items into/from any position of the
    array.

    Every array has its own resize policy. It used to dynamically  choose  new
    array size while inserting/removing items into/from the array. This policy
    handles current array size one and returns new array size depends on count
    of allocated items.

    Every array has its own copy policy. It used to  copy  array  items  while
    resizing arrays or cloning array. Copy policy wraps items copying process.

    <b>Overview.</b>\n
    In computer programming, a group of homogeneous  elements  of  a  specific
    data type is known as an array, one of the simplest  data  structures.  An
    array is similar to, but different  from,  a  vector  or  list  (for  one-
    dimensional arrays) or a matrix (for two-dimensional arrays). Arrays  hold
    a series of data elements,  usually  of  the  same  size  and  data  type.
    Individual elements are accessed by  their  position  in  the  array.  The
    position is given by an index, which is also called a subscript. The index
    usually  uses  a  consecutive  range  of  integers,  (as  opposed  to   an
    associative array) but the index can have any ordinal set of values.  Some
    arrays are multi-dimensional, meaning they are indexed by a  fixed  number
    of integers, for example by a tuple of four integers. Generally, one-  and
    two-dimensional arrays are the most common.

    Most  programming  languages  have  a  built-in  array  data  type.   Some
    programming languages (such as APL,  some  versions  of  Fortran,  and  J)
    generalize the available operations and functions  to  work  transparently
    over arrays as well as scalars, providing a higher-level manipulation than
    most other languages, which require loops over all the individual  members
    of the arrays.

    <b>Advantages and disadvantages.</b>\n
    Arrays permit  efficient  (constant-time,  O(1))  random  access  but  not
    efficient for insertion and deletion of elements (which are O(n), where  n
    is the size of the array).  Linked  lists  have  the  opposite  trade-off.
    Consequently, arrays are most appropriate for storing a  fixed  amount  of
    data which will be accessed in an unpredictable fashion, and linked  lists
    are best for a list of  data  which  will  be  accessed  sequentially  and
    updated often with insertions or deletions.

    Another advantage of arrays that has become very important on modern
    architectures is that iterating through an array has good locality of
    reference, and so is much faster than iterating through (say) a linked
    list of the same size, which tends to jump around in memory. However,
    an array can also be accessed in a random way, as is done with large
    hash tables, and in this case this is not a benefit.

    Arrays also are among  the  most  compact  data  structures;  storing  100
    integers in an array takes only 100 times the space required to  store  an
    integer, plus perhaps a few bytes of overhead for the pointer to the array
    (4 on a 32-bit system). Any pointer-based data  structure,  on  the  other
    hand, must keep its pointers somewhere, and these occupy additional space.
    This extra space becomes more significant  as  the  data  elements  become
    smaller. For example, an array of ASCII characters takes up one  byte  per
    character, while on a 32-bit platform, which has 4-byte pointers, a linked
    list requires at least five bytes  per  character.  Conversely,  for  very
    large elements, the space difference becomes a negligible fraction of  the
    total space.

    Because arrays have a fixed size, there are some indexes  which  refer  to
    invalid elements - for example, the index 17 in an array of size  5.  What
    happens when a program attempts to refer to these varies from language  to
    language and platform  to  platform.  For  more  information,  see  bounds
    checking.

    <b>Uses.</b>\n
    Although useful in their own right, arrays also form the basis for several
    more complex data structures, such as heaps, hash tables, and VLists,  and
    can be used to represent strings, stacks and queues. They also play a more
    minor role in many  other  data  structures.  All  of  these  applications
    benefit from the compactness and locality of arrays.

    One of the disadvantages of an array is that it has a single  fixed  size,
    and although its size can be altered in  many  environments,  this  is  an
    expensive operation. Dynamic arrays or growable arrays  are  arrays  which
    automatically  perform  this  resizing  as  late  as  possible,  when  the
    programmer attempts to add an element to the end of the array and there is
    no more space. To average the high cost of resizing over a long period  of
    time (we say it is an amortized cost), they expand by a large amount,  and
    when the programmer attempts to expand the array again, it just uses  more
    of this reserved space.

    In the C programming language, one-dimensional character arrays  are  used
    to store null-terminated strings, so called because the end of the  string
    is indicated with a special reserved character  called  a  null  character
    ('\\0') (see also C string).

    Finally, in some applications where the data are the same or  are  missing
    for most values of the indexes, or for large ranges of indexes,  space  is
    saved by not storing an array at all, but having an associative array with
    integer keys. There are many specialized data structures specifically  for
    this purpose, such as Patricia tries and Judy arrays. Example applications
    include address translation tables and routing tables.

    <b>Indices into arrays.</b>\n
    Although abstractions for arrays in most programming  languages  are  very
    similar, one strong point of contention has  arisen:  the  index  used  to
    refer to the first element. There are three  main  solutions:  zero-based,
    one-based, and n-based arrays, for which the first element has index zero,
    one, or a programmer-specified value, respectively.

    This is mainly a stylistic concern. The zero-based array was made  popular
    by the C programming language, in which the abstraction of array  is  very
    weak, and an index n of an array  is  simply  the  address  of  the  first
    element offset by n units.  Accordingly,  index  0  points  to  the  first
    element of the array. Descendants of C inherit  this  behavior.  One-based
    arrays are based on traditional mathematics notation and simple  counting,
    which begins with one. The last group - n-based - has been made  available
    so the programmer is free to chose the lower bound which  is  best  suited
    for the problem at hand.

    The conflict over the "right"  way  to  do  array  indexing  has  impacted
    programmer culture. When supporters  of  one-based  arrays  decried  zero-
    based arrays as unnatural, saying for example that we start numbered lists
    from 1, supporters of zero-based arrays retaliated by starting  their  own
    lists from zero in their daily lives. This practice can still be observed,
    and is often done for humor.

    In 1982 Edsger W. Dijkstra wrote a document, Why numbering should start at
    zero, putting forth concise reasons why he believed zero-  based  indexing
    into arrays should be the natural default definition.

    An historical reason to prefer zero-based arrays is the so-called "century
    confusion phenomenon". In the year 2000, most people in the world believed
    they were celebrating either the beginning of the 21st century, or the end
    of the 20th century. In fact, they were celebrating neither, because  only
    1,999 years had passed on the anno domini scale. The 21st century did  not
    begin until 2001, due to the fact that the AD system is one-based. This is
    perhaps the greatest example of how the  choice  of  indexing  scheme  can
    cause mass confusion.

    <b>Taken from:</b>\n
    Array from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Array
*/
template <typename T_Type, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_CopyPolicy = typename NTraits::MIfThenElse<NTraits::MIsClassOrUnion<T_Type>::yes, NPolicy::CCopyPolicyAssign, NPolicy::CCopyPolicyMemory>::type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CArray :
  public NCommon::NContainers::IRandom<CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >,
  public NCommon::NContainers::IRandomConst<CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >
{
  // Friend class: Array iterator class (CArrayIterator).
  friend class CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>;
  // Friend class: Constant array iterator class (CArrayIteratorConst).
  friend class CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptIResizePolicy constraint checking.
  typedef T_ResizePolicy TResizePolicyCheckType;
  //! Type for MConceptICopyPolicy constraint checking.
  typedef T_CopyPolicy TCopyPolicyCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_ResizePolicy template argument constraint to be a resize policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIResizePolicy, TResizePolicyCheckType);
  // Check T_CopyPolicy template argument constraint to be a copy policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptICopyPolicy, TCopyPolicyCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CArray class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef T_Type TType;
  //! Container type.
  typedef CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> TContainer;
  //! Non constant array iterator type.
  typedef CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> TIterator;
  //! Constant array iterator type.
  typedef CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> TIteratorConst;

  //! Container resize policy type.
  typedef T_ResizePolicy TResizePolicy;
  //! Container copy policy type.
  typedef T_CopyPolicy TCopyPolicy;
  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Create an empty array with given size.
  /*!
      Constructor allocates buffer for items with given size,  but  it  leaves
      those items initialized only with their default constructors.

      \param a_cSize - Allocated array size (default is 0).
      \param a_cResizeFactor - Array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CArray(const Tuint a_cSize = 0, const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Create an empty array with given size. Initialize all elements with given value.
  /*!
      Constructor  allocates  buffer  for  items  with  given  size.  Then  it
      initialize items with given value.

      \param a_crValue - Initialize value.
      \param a_cSize - Allocated array size.
      \param a_cResizeFactor - Array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CArray(const T_Type& a_crValue, const Tuint a_cSize, const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Create an array from constant array of fixed size.
  /*!
      Constructor creates an array based on  given  constant  array  of  fixed
      size.

      \param a_cpArray - Constant pointer to the array of fixed size.
      \param a_cResizeFactor - Array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  template <Tuint t_Size>
  CArray(const T_Type (&a_cpArray)[t_Size], const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Create an array from buffer with given size.
  /*!
      Constructor creates an array based on given buffer with given size.

      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \param a_cResizeFactor - Array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CArray(const T_Type a_cpBuffer[], const Tuint a_cSize, const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CArray class.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CArray(const CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CArray();

  //! Operator: Assign constant array of fixed size.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return Reference to the current class instance.
  */
  template <Tuint t_Size>
  CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator = (const T_Type (&a_cpArray)[t_Size]);
  //! Operator: Assign another CArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CArray class.
      \return Reference to the current class instance.
  */
  CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator = (const CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);

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
      \see NDepth::NContainers::CArray::getBuffer()
  */
  operator T_Type* ();
  //! Operator: Get constant pointer to the current array's buffer.
  /*!
      \return Constant pointer to the current array's buffer.
      \see NDepth::NContainers::CArray::getBuffer()
  */
  operator const T_Type* () const;

  //! Set an array from constant array of fixed size.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if array was successfully set. \n
              false - if array was not successfully set. \n
  */
  template <Tuint t_Size>
  Tbool set(const T_Type (&a_cpArray)[t_Size]);
  //! Set an array from buffer with given size.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if array was successfully set. \n
              false - if array was not successfully set. \n
  */
  Tbool set(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Set another CArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CArray class.
      \return true  - if another array was successfully set. \n
              false - if another array was not successfully set. \n
  */
  Tbool set(const CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);

  //! Get array free size.
  /*!
      Method returns count of free elements in the array.

      \return Count of free elements in the array.
  */
  Tuint getFreeSize() const;

  //! Get array lower capacity bound value.
  /*!
      Method returns lower bound size value before array reallocation.

      \return Array lower capacity bound value.
  */
  Tuint getLoCapacity() const;
  //! Get array higher capacity bound value.
  /*!
      Method returns higher bound size value before array reallocation.

      \return Array higher capacity bound value.
  */
  Tuint getHiCapacity() const;

  //! Get ponter to the array buffer.
  /*!
      Method returns pointer to the array buffer. Using  of  this  pointer  is
      quite dangerous cause it may lead to memory  errors.  That  is  why  you
      always have to check array bounds while working with this pointer.

      \return Pointer to the array buffer.
  */
  T_Type* getBuffer();
  //! Get constant ponter to the array buffer.
  /*!
      Method returns constant pointer to  the  array  buffer.  Using  of  this
      pointer is quite dangerous cause it may lead to memory errors.  That  is
      why you always have to  check  array  bounds  while  working  with  this
      pointer.

      \return Constant pointer to the array buffer.
  */
  const T_Type* getBuffer() const;

  //! Get array's resize factor value.
  /*!
      \return Current array's policy resize factor value.
  */
  Tuint getResizeFactor() const;

  //! Set array's resize factor.
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

  //! Resize array to the given size.
  /*!
      Method updates array to the given size.

      \param a_cSize - New array size.
      \return true  - if array was successfully resized. \n
              false - if array was not successfully resized. \n
  */
  Tbool resize(const Tuint a_cSize);
  //! Resize array to the given size. Initialize all elements with given value.
  /*!
      Method updates array to the given size.

      \param a_cSize - New array size.
      \param a_crValue - Initialize value.
      \return true  - if array was successfully resized. \n
              false - if array was not successfully resized. \n
  */
  Tbool resize(const Tuint a_cSize, const T_Type& a_crValue);
  //! Resize array by given size.
  /*!
      Method updates array by adding/removing given size.

      \param a_cSize - Additional array size (may be less than 0).
      \return true  - if array was successfully resized. \n
              false - if array was not successfully resized. \n
  */
  Tbool resizeBy(const Tsint a_cSize);
  //! Resize array by given size. Initialize all elements with given value.
  /*!
      Method updates array by adding/removing given size.

      \param a_cSize - Additional array size (may be less than 0).
      \param a_crValue - Initialize value.
      \return true  - if array was successfully resized. \n
              false - if array was not successfully resized. \n
  */
  Tbool resizeBy(const Tsint a_cSize, const T_Type& a_crValue);

  //! Reverse array.
  /*!
      Reverse array items order.
  */
  void reverse();

  //! Serialization load CArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CArray class instances.
  /*!
      \param a_rInstance - Reference to another CArray class instance.
  */
  void swap(CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_rInstance);

private:
  Tuint          m_Size;                //!< Array's size.
  T_Type*        m_pData;               //!< Pointer to array's buffer.
  T_ResizePolicy m_ResizePolicy;        //!< Array's resize policy.
  T_Allocator    m_Allocator;           //!< Memory allocator.
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
//! Traits meta-class: array container traits specialization.
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
class MTraitsContainer<NContainers::CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> > :
  public MType<NContainers::CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst citerator;

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
#include <Depth/include/containers/iterators/CArrayIterator.hpp>
#include <Depth/include/containers/iterators/CArrayIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CArray.inl>
/*==========================================================================*/
//! \example example-containers-CArray.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CArray.cpp
/*==========================================================================*/
#endif
