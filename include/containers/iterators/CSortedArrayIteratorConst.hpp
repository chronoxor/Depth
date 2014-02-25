/*!
 *  \file    CSortedArrayIteratorConst.hpp Sorted array constant iterator
 *           definitions. It gives ability to get sorted array items and
 *           to do random moving through the sorted array items.
 *  \brief   Sorted array constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Sorted array constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   30.09.2006 21:42:53

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
#ifndef __CSORTEDARRAYITERATORCONST_HPP__
#define __CSORTEDARRAYITERATORCONST_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/common/ISeekable.hpp>
#include <Depth/include/common/iterators/IIteratorConst.hpp>
#include <Depth/include/common/iterators/IIteratorMoveAssociative.hpp>
#include <Depth/include/common/iterators/IIteratorMoveRandom.hpp>
#include <Depth/include/containers/CSortedArray.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Sorted array constant iterator class.
/*!
    Sorted array constant iterator represents sorted array iterations  method.
    With this iterator you can perform random sorted array moving and  looking
    into sorted array items. Note that you cannot  modify sorted  array  items
    with constant iterator.  In  this  case  use  non  constant  sorted  array
    iterator.

    Serialization: Sorted array constant iterator cannot be loaded.
*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
class CSortedArrayIteratorConst :
  public NCommon::NIterators::IIteratorConst<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveAssociative<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveRandom<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >,
  public NCommon::ISeekable
{
  // Friend class: Sorted array class (CSortedArray).
  friend class CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>;

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
  typedef CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> TDepthCheckType;

  // Check T_BinaryPredicate template argument constraint to be a suitable binary predicate.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TPredicate2CheckType, TPredicate2ArgumentCheckType, TPredicate2ArgumentCheckType);
  // Check T_ResizePolicy template argument constraint to be a resize policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIResizePolicy, TResizePolicyCheckType);
  // Check T_CopyPolicy template argument constraint to be a copy policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptICopyPolicy, TCopyPolicyCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CSortedArrayIteratorConst class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator associative key type.
  typedef T_Type TKey;
  //! Iterator associative value type.
  typedef T_Type TValue;

  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef const T_Type TReturn;
  //! Iterator container type.
  typedef const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> TIterator;

  //! Container binary predicate type.
  typedef T_BinaryPredicate TLessThanPredicate;
  //! Container resize policy type.
  typedef T_ResizePolicy TResizePolicy;
  //! Container copy policy type.
  typedef T_CopyPolicy TCopyPolicy;
  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CSortedArrayIteratorConst();
  //! Initialize with non constant sorted array iterator.
  /*!
      \param a_crInstance - Constant reference to the instance of the CSortedArrayIterator class.
  */
  CSortedArrayIteratorConst(const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSortedArrayIteratorConst class.
  */
  CSortedArrayIteratorConst(const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CSortedArrayIteratorConst();

  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator == (const CSortedArrayIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator == (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator == (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator != (const CSortedArrayIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator != (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator != (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);

  //! Operator: Less than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator < (const CSortedArrayIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator < (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator < (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator > (const CSortedArrayIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator > (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator > (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator <= (const CSortedArrayIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator <= (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator <= (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not more or equal to the given one. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator >= (const CSortedArrayIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not more or equal to the given one. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator >= (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator >= (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another non constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the non constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator = (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);
  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator = (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator> operator + (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator> operator - (const CSortedArrayIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Find iterator with given value in sorted array.
  /*!
      \param a_crItem - Constant reference to the searching item.
      \return Iterator with given value or invalid empty iterator.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator [] (const T_Type& a_crItem) const;

  //! Operator: Get new sorted array's constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed sorted array position to return.
      \return Sorted array's constant iterator under the given index.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator [] (const Tsint a_cIndex) const;
  //! Operator: Get new sorted array's constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed sorted array position to return.
      \return Sorted array's constant iterator under the given index.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator [] (const Tuint a_cIndex) const;

  //! Set CSortedArrayIterator class instance.
  /*!
      \param a_crInstance - Constant reference to instance of the CSortedArrayIterator class.
  */
  void set(const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);
  //! Set another CSortedArrayIteratorConst class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSortedArrayIteratorConst class.
  */
  void set(const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> getBackward() const;
  //! Get indexed iterator.
  /*!
      Method uses 'stepIndex()' iterator method to  get  an  indexed  iterator
      instance. If indexed iteration cannot be  done  method  returns  invalid
      iterator.

      \param a_cIndex - Indexed iterator position to return.
      \return Random iterator under the given index.
  */
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> getIndex(const Tuint a_cIndex) const;

  // IIteratorConst interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& getContainerRef() const;
  virtual const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>* getContainerPtr() const;
  virtual const T_Type& getValueRef() const;
  virtual const T_Type* getValuePtr() const;

  // IIteratorMoveAssociative interface overriding methods.
  virtual CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> find(const T_Type& a_crItem) const;

  // IIteratorMoveRandom interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual Tbool stepIndex(const Tuint a_cIndex);

  // ISeekable interface overriding methods.
  virtual Tuint getSize() const;
  virtual Tbool setPosition(const Tuint a_cPosition);
  virtual Tuint getPosition() const;

  //! Serialization load CSortedArrayIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CSortedArrayIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CSortedArrayIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CSortedArrayIteratorConst class instances.
  /*!
      \param a_rInstance - Reference to another CSortedArrayIteratorConst class instance.
  */
  void swap(CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_rInstance);

private:
  const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>* m_cpContainer; //!< Constant pointer to the iterator container.
  Tuint m_Index;                                                                                           //!< Index of the current sorted array item.

  //! Initialize iterator with the container value.
  /*!
      \param a_cpContainer - Constant pointer to the iterator container value.
  */
  CSortedArrayIteratorConst(const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>* a_cpContainer);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* ITERATOR TRAITS SPECIALIZATION DECLARATIONS                              */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: sorted array constant iterator's traits specialization.
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> > :
  public MType<NContainers::NIterators::CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator iterator;

  static const Tbool isConst             = true;  //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = true;  //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = true;  //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = false; //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = false; //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = false; //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = false; //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = false; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false; //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = false; //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = false; //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = false; //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = false; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false; //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CSortedArrayIteratorConst.inl>
/*==========================================================================*/
#endif
