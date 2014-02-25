/*!
 *  \file    CBitArrayIterator.hpp Bit array non constant iterator definitions.
 *           It gives ability to get and modify bit array items and to do
 *           random moving through the bit array items.
 *  \brief   Bit array non constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Bit array non constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   09.06.2006 23:23:37

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
#ifndef __CBITARRAYITERATOR_HPP__
#define __CBITARRAYITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/common/ISeekable.hpp>
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorInsertRandom.hpp>
#include <Depth/include/common/iterators/IIteratorMoveRandom.hpp>
#include <Depth/include/common/iterators/IIteratorRemoveRandom.hpp>
#include <Depth/include/containers/CBitArray.hpp>
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
//! Bit array non constant iterator class (boolean array specialization).
/*!
    Bit array non constant iterator represents bit  array  iterations  method.
    With this iterator you can perform random moving and modifying  bit  array
    items.
*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
class CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> :
  public NCommon::NIterators::IIterator<CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveRandom<CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> >,
  public NCommon::NIterators::IIteratorInsertRandom<CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> >,
  public NCommon::NIterators::IIteratorRemoveRandom<CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> >,
  public NCommon::ISeekable
{
  // Friend class: Bit array class (CArray<Tbool>).
  friend class CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>;
  // Friend class: Bit array constant iterator class (CArrayIteratorConst<Tbool>).
  friend class CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>;

  //! Type for MConceptIResizePolicy constraint checking.
  typedef T_ResizePolicy TResizePolicyCheckType;
  //! Type for MConceptICopyPolicy constraint checking.
  typedef T_CopyPolicy TCopyPolicyCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> TDepthCheckType;

  // Check T_ResizePolicy template argument constraint to be a resize policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIResizePolicy, TResizePolicyCheckType);
  // Check T_CopyPolicy template argument constraint to be a copy policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptICopyPolicy, TCopyPolicyCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CArrayIterator<Tbool> class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef Tbool TType;
  //! Iterator return type.
  typedef NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> TReturn;
  //! Iterator container type.
  typedef CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> TIterator;

  //! Container resize policy type.
  typedef T_ResizePolicy TResizePolicy;
  //! Container copy policy type.
  typedef T_CopyPolicy TCopyPolicy;
  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CArrayIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CArrayIterator<Tbool> class.
  */
  CArrayIterator(const CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CArrayIterator();

  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator == (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIteratorConst<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator == (const CArrayIteratorConst<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator == (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator != (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIteratorConst<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator != (const CArrayIteratorConst<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator != (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);

  //! Operator: Less than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator < (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIteratorConst<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator < (const CArrayIteratorConst<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator < (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator > (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIteratorConst<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator > (const CArrayIteratorConst<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator > (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator <= (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIteratorConst<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator <= (const CArrayIteratorConst<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator <= (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator >= (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIteratorConst<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator >= (const CArrayIteratorConst<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator >= (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another iterator class instance.
  /*!
      \param a_crInstance - Another instance of the iterator class.
      \return Reference to the current iterator class instance.
  */
  CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator = (const CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator> operator + (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator> operator - (const CArrayIterator<Tbool, T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Get new bit array's non constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed bit array position to return.
      \return Bit array's non constant iterator under the given index.
  */
  CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator [] (const Tsint a_cIndex) const;
  //! Operator: Get new bit array's non constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed bit array position to return.
      \return Bit array's non constant iterator under the given index.
  */
  CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator [] (const Tuint a_cIndex) const;

  //! Set another CArrayIteratorConst<Tbool> class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CArrayIteratorConst<Tbool> class.
  */
  void set(const CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> getBackward() const;
  //! Get indexed iterator.
  /*!
      Method uses 'stepIndex()' iterator method to  get  an  indexed  iterator
      instance. If indexed iteration cannot be  done  method  returns  invalid
      iterator.

      \param a_cIndex - Indexed iterator position to return.
      \return Random iterator under the given index.
  */
  CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> getIndex(const Tuint a_cIndex) const;

  // IIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& getContainerRef() const;
  virtual CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>* getContainerPtr() const;
  virtual NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& getValueRef() const;
  virtual NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>* getValuePtr() const;

  // IIteratorMoveRandom interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual Tbool stepIndex(const Tuint a_cIndex);

  // IIteratorInsertRandom interface overriding methods.
  virtual Tbool insertForward(const Tbool& a_crItem);
  virtual Tbool insertNext(const Tbool& a_crItem);
  virtual Tbool insertBackward(const Tbool& a_crItem);
  virtual Tbool insertPrev(const Tbool& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const Tbool& a_crItem);

  // IIteratorRemoveRandom interface overriding methods.
  virtual Tbool removeForward();
  virtual Tbool removeForward(Tbool& a_rItem);
  virtual Tbool removeNext();
  virtual Tbool removeNext(Tbool& a_rItem);
  virtual Tbool removeBackward();
  virtual Tbool removeBackward(Tbool& a_rItem);
  virtual Tbool removePrev();
  virtual Tbool removePrev(Tbool& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex);
  virtual Tbool removeIndex(const Tuint a_cIndex, Tbool& a_rItem);
  virtual Tbool remove(const Tuint a_cIndex, const Tuint a_cSize);

  // ISeekable interface overriding methods.
  virtual Tuint getSize() const;
  virtual Tbool setPosition(const Tuint a_cPosition);
  virtual Tuint getPosition() const;

  //! Serialization load CArrayIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CArrayIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CArrayIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CArrayIterator class instances.
  /*!
      \param a_rInstance - Reference to another CArrayIterator class instance.
  */
  void swap(CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_rInstance);

private:
  CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>* m_pContainer;                       //!< Pointer to the iterator container.
  mutable NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> m_mReference; //!< Bit array reference.
  Tuint m_Index;                                                                                //!< Index of the current bit array item.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CArrayIterator(CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>* a_pContainer);
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
//! Traits meta-class: array non constant iterator's traits specialization.
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> > :
  public MType<NContainers::NIterators::CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator iterator;

  static const Tbool isConst             = false; //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = true;  //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = false; //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = false; //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = true;  //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = true;  //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = true;  //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = false; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false; //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = true;  //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = true;  //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = true;  //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = false; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false; //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CBitArrayIterator.inl>
/*==========================================================================*/
#endif
