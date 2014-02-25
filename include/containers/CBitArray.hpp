/*!
 *  \file    CBitArray.hpp Template bit array container class. Bit array forms
 *           a compact data structure for random access to the bit field.
 *  \brief   Bit array container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Bit array container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   05.06.2006 22:31:48

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
#ifndef __CBITARRAY_HPP__
#define __CBITARRAY_HPP__
/*==========================================================================*/
#include <Depth/include/containers/details/CBitArrayReference.hpp>
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
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
class CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>;
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
class CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Bit array container class (boolean array specialization).
/*!
    Bit array container represents compact  random  access  container  to  bit
    field. You can insert/remove bits into/from any position of the field.

    Every bit array has its own resize policy. It used to  dynamically  choose
    new bit array size while inserting/removing bits into/from the bit  array.
    This policy handles current bit array size one and returns new  bit  array
    size depends on count of array's bits.

    Every bit array has its own copy policy. It used to  copy  array's  buffer
    while resizing bit arrays or cloning bit array. Copy policy  wraps  buffer
    copying process.

    <b>Overview.</b>\n
    A bit array (or bitmap, in some cases) is an array  data  structure  which
    compactly stores individual bits (boolean values). It implements a  simple
    set data structure storing a subset of {1,2,...,n}  and  is  effective  at
    exploiting  bit-level  parallelism  in  hardware  to  perform   operations
    quickly. A typical bit array stores kw bits, where w is the number of bits
    in the unit of storage, such as a byte or word, and k is some integer.  If
    the number of bits to be stored does not divide w, some  space  is  wasted
    due to internal fragmentation.

    <b>Basic operations.</b>\n
    Although most machines are not able to address individual bits in  memory,
    nor have instructions to manipulate single bits, each bit in a word can be
    singled out and manipulated using bitwise operations. In particular:
    \li OR can be used to set a bit to one:
        11101010 OR 00000100 = 11101110
    \li AND and NOT can be used to set a bit to zero:
        11101010 AND (NOT 00000010) = 11101000
    \li AND together with zero-testing can be used to determine if  a  bit  is
        set:
        11101010 AND 00010010 = 00000010
    \li XOR can be used to invert or toggle a bit:
        11101010 XOR 00000100 = 11101110

    To obtain the bit mask needed for these operations, we can use a bit shift
    operator to shift the number 1 to the left by the  appropriate  number  of
    places.

    We can view a bit array  as  a  subset  of  {1,2,...,n},  where  a  1  bit
    indicates a number in the set and a 0 bit a number not in  the  set.  This
    set data structure uses about n/w words of space, where w is the number of
    bits in each machine word. Whether the least significant bit or  the  most
    significant bit indicates the smallest-index number is largely irrelevant,
    but the former tends to be preferred.

    <b>Advantages and disadvantages.</b>\n
    Bit arrays, despite their simplicity, have a number of  marked  advantages
    over other data structures for the same problems:
    \li They are extremely compact; few other  data  structures  can  store  n
        independent pieces of data in n/w words.
    \li They allow small arrays of bits to be stored and  manipulated  in  the
        register set for long periods of time with no memory accesses.
    \li Because of their  ability  to  exploit  bit-level  parallelism,  limit
        memory access, and  maximally  utilize  the  data  cache,  they  often
        outperform many other data structures on  practical  data  sets,  even
        those which are more efficient asymptotically.

    However, bit arrays aren't the solution to everything. In particular:
    \li They are wasteful set data structures for sparse sets (those with  few
        elements compared to their range) in both time  and  space.  For  such
        applications, Judy arrays, tries, or  even  Bloom  filters  should  be
        considered instead.
    \li Accessing individual  elements  can  be  expensive  and  difficult  to
        express in some languages.  If  random  access  is  more  common  than
        sequential and the array is relatively small,  a  byte  array  may  be
        preferable on a machine with byte addressing. A word  array,  however,
        is  probably  not  justified  due  to  the  huge  space  overhead  and
        additional cache misses it causes, unless the machine  only  has  word
        addressing.

    <b>Applications.</b>\n
    Because of their compactness, bit arrays have a number of applications  in
    areas where space or efficiency is at a premium. Most commonly,  they  are
    used to represent a simple group of boolean flags or an  ordered  sequence
    of boolean values.

    We mentioned above that bit arrays are used for priority queues, where the
    bit at index k is set if and  only  if  k  is  in  the  queue;  this  data
    structure is used, for example, by the Linux kernel, and benefits strongly
    from a find-first-zero operation in hardware.

    Bit arrays can be used for the allocation of memory  pages,  inodes,  disk
    sectors, etc. In such cases, the term bitmap may be  used.  However,  this
    term is frequently used to refer to raster images, which may use  multiple
    bits per pixel.

    Another application of bit arrays is the Bloom filter, a probabilistic set
    data structure that can store large sets in a small space in exchange  for
    a small probability of error. It is also possible to  build  probabilistic
    hash tables based on bit arrays that  accept  either  false  positives  or
    false negatives.

    Bit arrays and the operations on them are also important for  constructing
    succinct data structures, which use close to the minimum  possible  space.
    In this context, operations like finding the nth 1  bit  or  counting  the
    number of 1 bits up to a certain position become important.

    Bit arrays  are  also  a  useful  abstraction  for  examining  streams  of
    compressed data, which often contain  elements  that  occupy  portions  of
    bytes or are not byte-aligned. For example, the compressed Huffman  coding
    representation of a single 8-bit character can be anywhere from 1  to  255
    bits long.

    <b>Language support.</b>\n
    The C programming language's bitfields, pseudo-objects  found  in  structs
    with size equal to some number of bits, are in fact small bit arrays; they
    are limited  in  that  they  cannot  span  words.  Although  they  give  a
    convenient syntax, the bits are still accessed using bitwise operators  on
    most machines, and they can only be defined statically  (like  C's  static
    arrays, their sizes are fixed at compile-time). It is also a common  idiom
    for C programmers to use words as small bit arrays and access bits of them
    using bit operators.

    In C++, although individual bools typically occupy a byte,  the  STL  type
    vector<bool> is a partial specialization  which  packs  bits  into  words.
    Another unique STL class, bitset, creates a vector  of  bits  fixed  at  a
    particular size at compile-time, and which in  its  interface  and  syntax
    more resembles the idiomatic use of words as bit sets by C programmers. It
    also has some additional power, such as the ability to  efficiently  count
    the number of bits that are set.

    In Java, the class java.util.BitSet creates a  bit  array  which  is  then
    manipulated with functions named after bitwise  operators  familiar  to  C
    programmers. Unlike the bitset in C++, the Java BitSet expands dynamically
    if a bit is set at an index beyond the current size of the bit vector.

    The .NET Framework supplies a BitArray collection class. It stores boolean
    values, supports random access and  bitwise  operators,  can  be  iterated
    over, and its Length property can be changed to grow or truncate it.

    Although Standard ML has no support for bit arrays,  Standard  ML  of  New
    Jersey has an extension, the BitArray structure, in its SML/NJ Library. It
    is not fixed in size and  supports  set  operations  and  bit  operations,
    including, unusually, shift operations.

    <b>Taken from:</b>\n
    Bit array from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Bit_array
*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
class CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> :
  public NCommon::NContainers::IRandom<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> >,
  public NCommon::NContainers::IRandomConst<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>, const NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> >
{
  // Friend class: Bit array iterator class (CArrayIterator).
  friend class CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>;
  // Friend class: Constant bit array iterator class (CArrayIteratorConst).
  friend class CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>;

  //! Type for MConceptIResizePolicy constraint checking.
  typedef T_ResizePolicy TResizePolicyCheckType;
  //! Type for MConceptICopyPolicy constraint checking.
  typedef T_CopyPolicy TCopyPolicyCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> TDepthCheckType;

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
  typedef Tbool TType;
  //! Container type.
  typedef CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> TContainer;
  //! Non constant array iterator type.
  typedef CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> TIterator;
  //! Constant array iterator type.
  typedef CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> TIteratorConst;

  //! Container resize policy type.
  typedef T_ResizePolicy TResizePolicy;
  //! Container copy policy type.
  typedef T_CopyPolicy TCopyPolicy;
  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Create an empty bit array with given size in bits.
  /*!
      Constructor allocates buffer for bits with given size in bits.

      \param a_cSize - Allocated bit array size in bits (default is 0).
      \param a_cResizeFactor - Bit array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CArray(const Tuint a_cSize = 0, const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Create an empty bit array with given size in bits. Initialize all elements with given value.
  /*!
      Constructor allocates buffer for items with given size in bits.
      Then it initialize items with 'true' or 'false'.

      \param a_cValue - Initialize value.
      \param a_cSize - Allocated bit array size in bits.
      \param a_cResizeFactor - Bit array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CArray(const Tbool a_cValue, const Tuint a_cSize, const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Create bit array from constant boolean values array of fixed size.
  /*!
      Constructor creates bit array based on  given  constant  boolean  values
      array of fixed size.

      \param a_cpArray - Constant pointer to the boolean values array of fixed size.
      \param a_cResizeFactor - Array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  template <Tuint t_Size>
  CArray(const Tbool (&a_cpArray)[t_Size], const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Create bit array from the constant boolean values buffer with given size.
  /*!
      Constructor creates bit array based on given boolean values buffer  with
      given size.

      \param a_cpBuffer - Constant pointer to the boolean value buffer.
      \param a_cSize - Buffer size.
      \param a_cResizeFactor - Bit array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CArray(const Tbool a_cpBuffer[], const Tuint a_cSize, const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Create bit array from bit buffer with given size in bits.
  /*!
      Constructor creates bit array based on given buffer with given size  (in
      bits).

      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size in bits.
      \param a_cResizeFactor - Bit array resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CArray(Tcbuffer a_cpBuffer, const Tuint a_cSize, const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CArray class.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CArray(const CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CArray();

  //! Operator: Assign constant boolean values array of fixed size.
  /*!
      \param a_cpArray - Constant pointer to the boolean values array of fixed size.
      \return Reference to the current class instance.
  */
  template <Tuint t_Size>
  CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator = (const Tbool (&a_cpArray)[t_Size]);
  //! Operator: Assign another CArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CArray class.
      \return Reference to the current class instance.
  */
  CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator = (const CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);

  //! Operator: Indexing into the bit array's buffer.
  /*!
      \param a_cIndex - Indexed bit array position to return.
      \return Reference to bit array's item under the given index.
  */
  NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> operator [] (const Tsint a_cIndex);
  //! Operator: Indexing into the bit array's buffer.
  /*!
      \param a_cIndex - Indexed bit array position to return.
      \return Reference to bit array's item under the given index.
  */
  NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> operator [] (const Tuint a_cIndex);
  //! Operator: Indexing into the bit array's buffer.
  /*!
      \param a_cIndex - Indexed bit array position to return.
      \return Constant reference to bit array's item under the given index.
  */
  const NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> operator [] (const Tsint a_cIndex) const;
  //! Operator: Indexing into the bit array's buffer.
  /*!
      \param a_cIndex - Indexed bit array position to return.
      \return Constant reference to bit array's item under the given index.
  */
  const NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> operator [] (const Tuint a_cIndex) const;

  //! Operator: Get pointer to the current bit array's buffer.
  /*!
      \return Pointer to the current bit array's buffer.
      \see NDepth::NContainers::CArray::getBuffer()
  */
  operator Tbuffer ();
  //! Operator: Get constant pointer to the current bit array's buffer.
  /*!
      \return Constant pointer to the current bit array's buffer.
      \see NDepth::NContainers::CArray::getBuffer()
  */
  operator Tcbuffer () const;

  //! Set bit array from constant boolean values array of fixed size.
  /*!
      \param a_cpArray - Constant pointer to the boolean values array of fixed size.
      \return true  - if bit array was successfully set. \n
              false - if bit array was not successfully set. \n
  */
  template <Tuint t_Size>
  Tbool set(const Tbool (&a_cpArray)[t_Size]);
  //! Set bit array from the constant boolean values buffer with given size.
  /*!
      \param a_cpBuffer - Constant pointer to the boolean value buffer.
      \param a_cSize - Buffer size.
      \return true  - if bit array was successfully set. \n
              false - if bit array was not successfully set. \n
  */
  Tbool set(const Tbool a_cpBuffer[], const Tuint a_cSize);
  //! Set bit array from buffer with given size in bits.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size in bits.
      \return true  - if bit array was successfully set. \n
              false - if bit array was not successfully set. \n
  */
  Tbool set(Tcbuffer a_cpBuffer, const Tuint a_cSize);
  //! Set another CArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CArray class.
      \return true  - if another bit array was successfully set. \n
              false - if another bit array was not successfully set. \n
  */
  Tbool set(const CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);

  //! Get bit array free size in bits.
  /*!
      Method returns count of free bits is bit array.

      \return Count of free bits in bit array.
  */
  Tuint getFreeSize() const;

  //! Get bit array lower capacity bound value.
  /*!
      Method returns lower bound size value before bit array reallocation.

      \return Bit array lower capacity bound value.
  */
  Tuint getLoCapacity() const;
  //! Get bit array higher capacity bound value.
  /*!
      Method returns higher bound size value before bit array reallocation.

      \return Bit array higher capacity bound value.
  */
  Tuint getHiCapacity() const;

  //! Get ponter to bit array buffer.
  /*!
      Method returns pointer to bit array buffer. Using  of  this  pointer  is
      quite dangerous cause it may lead to memory  errors.  That  is  why  you
      always have to check bit array bounds while working with this pointer.

      \return Pointer to bit array buffer.
  */
  Tbuffer getBuffer();
  //! Get constant ponter to bit array buffer.
  /*!
      Method returns constant pointer to  bit  array  buffer.  Using  of  this
      pointer is quite dangerous cause it may lead to memory errors.  That  is
      why you always have to check bit array bounds while  working  with  this
      pointer.

      \return Constant pointer to bit array buffer.
  */
  Tcbuffer getBuffer() const;

  //! Get bit array's resize factor value.
  /*!
      \return Current bit array's policy resize factor value.
  */
  Tuint getResizeFactor() const;

  //! Set bit array's resize factor.
  /*!
      Method sets new policy resize factor. If given resize factor is invalid,
      then policy will use the default value as current resize factor.

      \param a_cResizeFactor - Resize factor.
      \return true  - if resize factor successfully set. \n
              false - if resize factor is invalid. \n
  */
  Tbool setResizeFactor(const Tuint a_cResizeFactor);

  //! Get bit value under given index in bit array.
  /*!
      \param a_cIndex - Indexed bit array position to get.
      \return Bit value under given index in bit array.
  */
  Tbool getBit(const Tuint a_cIndex) const;
  //! Set bit value under given index in bit array.
  /*!
      \param a_cIndex - Indexed bit array position to set.
      \param a_cValue - Value of the bit to set (default is true).
      \return true  - if bit value was successfully set. \n
              false - if bit value was not successfully set. \n
  */
  Tbool setBit(const Tuint a_cIndex, const Tbool a_cValue);
  //! Flip bit value to opposite under given index in bit array.
  /*!
      \param a_cIndex - Indexed bit array position to flip.
      \return true  - if bit value was successfully flipped. \n
              false - if bit value was not successfully flipped. \n
  */
  Tbool flipBit(const Tuint a_cIndex);

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IRandom interface overriding methods.
  virtual Tbool insertFirst(const Tbool& a_crItem);
  virtual Tbool insertLast(const Tbool& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const Tbool& a_crItem);
  virtual Tbool removeFirst();
  virtual Tbool removeFirst(Tbool& a_rItem);
  virtual Tbool removeLast();
  virtual Tbool removeLast(Tbool& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex);
  virtual Tbool removeIndex(const Tuint a_cIndex, Tbool& a_rItem);
  virtual Tbool remove(const Tuint a_cIndex, const Tuint a_cSize);

  // IRandomConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;
  virtual TIterator      getItIndex(const Tuint a_cIndex);
  virtual TIteratorConst getItIndex(const Tuint a_cIndex) const;

  //! Resize bit array to the given size in bits.
  /*!
      Method updates bit array to the given size in bits.

      \param a_cSize - New bit array size in bits.
      \return true  - if bit array was successfully resized. \n
              false - if bit array was not successfully resized. \n
  */
  Tbool resize(const Tuint a_cSize);
  //! Resize bit array to the given size in bits. Initialize all elements with given value.
  /*!
      Method updates bit array to the given size.

      \param a_cSize - New bit array size.
      \param a_cValue - Initialize value.
      \return true  - if bit array was successfully resized. \n
              false - if bit array was not successfully resized. \n
  */
  Tbool resize(const Tuint a_cSize, const Tbool a_cValue);
  //! Resize bit array by given size in bits.
  /*!
      Method updates bit array by adding/removing given size in bits.

      \param a_cSize - Additional array size in bits (may be less than 0).
      \return true  - if bit array was successfully resized. \n
              false - if bit array was not successfully resized. \n
  */
  Tbool resizeBy(const Tsint a_cSize);
  //! Resize bit array by given size in bits. Initialize all elements with given value.
  /*!
      Method updates bit array by adding/removing given size in bits.

      \param a_cSize - Additional bit array size in bits (may be less than 0).
      \param a_cValue - Initialize value.
      \return true  - if bit array was successfully resized. \n
              false - if bit array was not successfully resized. \n
  */
  Tbool resizeBy(const Tsint a_cSize, const Tbool a_cValue);

  //! Reverse bit array.
  /*!
      Reverse bit array items order.
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
  void swap(CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_rInstance);

private:
  Tuint          m_Size;                //!< Bit array's size.
  Tbuffer        m_pData;               //!< Pointer to bit array's buffer.
  T_ResizePolicy m_ResizePolicy;        //!< Bit array's resize policy.
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
//! Traits meta-class: bit array container traits specialization.
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
class MTraitsContainer<NContainers::CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> > :
  public MType<NContainers::CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst citerator;

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
#include <Depth/include/containers/iterators/CBitArrayIterator.hpp>
#include <Depth/include/containers/iterators/CBitArrayIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CBitArray.inl>
/*==========================================================================*/
//! \example example-containers-CBitArray.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CBitArray.cpp
/*==========================================================================*/
#endif
