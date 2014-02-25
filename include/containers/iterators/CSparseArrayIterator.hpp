/*!
 *  \file    CSparseArrayIterator.hpp Sparce array non constant iterator
 *           definitions. It gives ability to get and modify sparse array
 *           items and to do random moving through the sparse array items.
 *  \brief   Sparce array non constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.10.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Sparce array non constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   02.10.2007 20:42:15

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
#ifndef __CSPARSEARRAYITERATOR_HPP__
#define __CSPARSEARRAYITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/common/ISeekable.hpp>
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorInsertRandom.hpp>
#include <Depth/include/common/iterators/IIteratorMoveRandom.hpp>
#include <Depth/include/common/iterators/IIteratorRemoveRandom.hpp>
#include <Depth/include/containers/CSparseArray.hpp>
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
//! Sparce array non constant iterator class.
/*!
    Sparce array non constant  iterator  represents  sparse  array  iterations
    method. With this iterator you can perform  random  moving  and  modifying
    sparse array items.
*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class CSparseArrayIterator :
  public NCommon::NIterators::IIterator<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveRandom<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorInsertRandom<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorRemoveRandom<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >,
  public NCommon::ISeekable
{
  // Friend class: Sparce array class (CSparseArray).
  friend class CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>;
  // Friend class: Sparce array constant iterator class (CSparseArrayIteratorConst).
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
  typedef CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_AssociativeContainer template argument constraint to be an non constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociative, TAssociativeContainerCheckType);
  // Check T_AssociativeContainer template argument constraint to be an constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociativeConst, TAssociativeContainerConstCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CSparseArrayIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef T_Type TReturn;
  //! Iterator container type.
  typedef CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> TIterator;

  //! Base associative container type.
  typedef T_AssociativeContainer<NDetails::CSparseValue<T_Type>, NDetails::FSparseValueComparator<T_Type>, T_Allocator> TAssociativeContainer;
  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CSparseArrayIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSparseArrayIterator class.
  */
  CSparseArrayIterator(const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CSparseArrayIterator();

  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIteratorConst<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CSparseArrayIteratorConst<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIteratorConst<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CSparseArrayIteratorConst<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);

  //! Operator: Less than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator < (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIteratorConst<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator < (const CSparseArrayIteratorConst<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator < (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: More than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator > (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIteratorConst<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: More than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator > (const CSparseArrayIteratorConst<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: More than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator > (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator <= (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIteratorConst<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator <= (const CSparseArrayIteratorConst<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator <= (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator >= (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIteratorConst<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator >= (const CSparseArrayIteratorConst<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator >= (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another iterator class instance.
  /*!
      \param a_crInstance - Another instance of the iterator class.
      \return Reference to the current iterator class instance.
  */
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& operator = (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator> operator + (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator> operator - (const CSparseArrayIterator<T_OtherType, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Get new sparse array's non constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed sparse array position to return.
      \return Sparse array's non constant iterator under the given index.
  */
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> operator [] (const Tsint a_cIndex) const;
  //! Operator: Get new sparse array's non constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed sparse array position to return.
      \return Sparse array's non constant iterator under the given index.
  */
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> operator [] (const Tuint a_cIndex) const;

  //! Set another CSparseArrayIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSparseArrayIterator class.
  */
  void set(const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> getBackward() const;
  //! Get indexed iterator.
  /*!
      Method uses 'stepIndex()' iterator method to  get  an  indexed  iterator
      instance. If indexed iteration cannot be  done  method  returns  invalid
      iterator.

      \param a_cIndex - Indexed iterator position to return.
      \return Random iterator under the given index.
  */
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> getIndex(const Tuint a_cIndex) const;

  //! Get continuous sparse value iterator.
  /*!
      \return Continuous sparse value iterator.
  */
  typename TAssociativeContainer::TIterator getSparse() const;

  // IIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& getContainerRef() const;
  virtual CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>* getContainerPtr() const;
  virtual T_Type& getValueRef() const;
  virtual T_Type* getValuePtr() const;

  // IIteratorMoveRandom interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual Tbool stepIndex(const Tuint a_cIndex);

  // IIteratorInsertRandom interface overriding methods.
  virtual Tbool insertForward(const T_Type& a_crItem);
  virtual Tbool insertNext(const T_Type& a_crItem);
  virtual Tbool insertBackward(const T_Type& a_crItem);
  virtual Tbool insertPrev(const T_Type& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const T_Type& a_crItem);

  // IIteratorRemoveRandom interface overriding methods.
  virtual Tbool removeForward();
  virtual Tbool removeForward(T_Type& a_rItem);
  virtual Tbool removeNext();
  virtual Tbool removeNext(T_Type& a_rItem);
  virtual Tbool removeBackward();
  virtual Tbool removeBackward(T_Type& a_rItem);
  virtual Tbool removePrev();
  virtual Tbool removePrev(T_Type& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex);
  virtual Tbool removeIndex(const Tuint a_cIndex, T_Type& a_rItem);
  virtual Tbool remove(const Tuint a_cIndex, const Tuint a_cSize);

  // ISeekable interface overriding methods.
  virtual Tuint getSize() const;
  virtual Tbool setPosition(const Tuint a_cPosition);
  virtual Tuint getPosition() const;

  //! Insert constant array of fixed size into the current iterator position, then old position shifts forward.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully inserted. \n
              false - if constant array of fixed size was not successfully inserted. \n
  */
  template <Tuint t_Size>
  Tbool insertForward(const T_Type (&a_cpArray)[t_Size]);
  //! Insert buffer with given size into the current iterator position, then old position shifts forward.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully inserted. \n
              false - if buffer with given size was not successfully inserted. \n
  */
  Tbool insertForward(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Insert constant array of fixed size into the next forward iterator position.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully inserted. \n
              false - if constant array of fixed size was not successfully inserted. \n
  */
  template <Tuint t_Size>
  Tbool insertNext(const T_Type (&a_cpArray)[t_Size]);
  //! Insert buffer with given size into the next forward iterator position.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully inserted. \n
              false - if buffer with given size was not successfully inserted. \n
  */
  Tbool insertNext(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Insert constant array of fixed size into the current iterator position, then old position shifts backward.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully inserted. \n
              false - if constant array of fixed size was not successfully inserted. \n
  */
  template <Tuint t_Size>
  Tbool insertBackward(const T_Type (&a_cpArray)[t_Size]);
  //! Insert buffer with given size into the current iterator position, then old position shifts backward.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully inserted. \n
              false - if buffer with given size was not successfully inserted. \n
  */
  Tbool insertBackward(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Insert constant array of fixed size into the previous backward iterator position.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully inserted. \n
              false - if constant array of fixed size was not successfully inserted. \n
  */
  template <Tuint t_Size>
  Tbool insertPrev(const T_Type (&a_cpArray)[t_Size]);
  //! Insert buffer with given size into the previous backward iterator position.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully inserted. \n
              false - if buffer with given size was not successfully inserted. \n
  */
  Tbool insertPrev(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Insert constant array of fixed size into the indexed iterator position.
  /*!
      \param a_cIndex - Index to insert.
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully inserted. \n
              false - if constant array of fixed size was not successfully inserted. \n
  */
  template <Tuint t_Size>
  Tbool insertIndex(const Tuint a_cIndex, const T_Type (&a_cpArray)[t_Size]);
  //! Insert buffer with given size into the indexed iterator position.
  /*!
      \param a_cIndex - Index to insert.
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully inserted. \n
              false - if buffer with given size was not successfully inserted. \n
  */
  Tbool insertIndex(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize);

  //! Fill sparse array with an item into the forward iterator position.
  /*!
      \param a_crItem - Constant reference to the item to fill.
      \return true  - if the item was successfully filled into the sparse array. \n
              false - if the item was not successfully filled into the sparse array. \n
  */
  Tbool fillForward(const T_Type& a_crItem);
  //! Fill sparse array with constant array of fixed size into the forward iterator position.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully filled into the sparse array. \n
              false - if constant array of fixed size was not successfully filled into the sparse array. \n
  */
  template <Tuint t_Size>
  Tbool fillForward(const T_Type (&a_cpArray)[t_Size]);
  //! Fill sparse array with buffer with given size into the forward iterator position.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully filled into the sparse array. \n
              false - if buffer with given size was not successfully filled into the sparse array. \n
  */
  Tbool fillForward(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Fill sparse array with an item into the next forward iterator position.
  /*!
      \param a_crItem - Constant reference to the item to fill.
      \return true  - if the item was successfully filled into the sparse array. \n
              false - if the item was not successfully filled into the sparse array. \n
  */
  Tbool fillNext(const T_Type& a_crItem);
  //! Fill sparse array with constant array of fixed size into the next forward iterator position.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully filled into the sparse array. \n
              false - if constant array of fixed size was not successfully filled into the sparse array. \n
  */
  template <Tuint t_Size>
  Tbool fillNext(const T_Type (&a_cpArray)[t_Size]);
  //! Fill sparse array with buffer with given size into the next forward iterator position.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully filled into the sparse array. \n
              false - if buffer with given size was not successfully filled into the sparse array. \n
  */
  Tbool fillNext(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Fill sparse array with an item into the backward iterator position.
  /*!
      \param a_crItem - Constant reference to the item to fill.
      \return true  - if the item was successfully filled into the sparse array. \n
              false - if the item was not successfully filled into the sparse array. \n
  */
  Tbool fillBackward(const T_Type& a_crItem);
  //! Fill sparse array with constant array of fixed size into the backward iterator position.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully filled into the sparse array. \n
              false - if constant array of fixed size was not successfully filled into the sparse array. \n
  */
  template <Tuint t_Size>
  Tbool fillBackward(const T_Type (&a_cpArray)[t_Size]);
  //! Fill sparse array with buffer with given size into the backward iterator position.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully filled into the sparse array. \n
              false - if buffer with given size was not successfully filled into the sparse array. \n
  */
  Tbool fillBackward(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Fill sparse array with an item into the previous backward iterator position.
  /*!
      \param a_crItem - Constant reference to the item to fill.
      \return true  - if the item was successfully filled into the sparse array. \n
              false - if the item was not successfully filled into the sparse array. \n
  */
  Tbool fillPrev(const T_Type& a_crItem);
  //! Fill sparse array with constant array of fixed size into the previous backward iterator position.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully filled into the sparse array. \n
              false - if constant array of fixed size was not successfully filled into the sparse array. \n
  */
  template <Tuint t_Size>
  Tbool fillPrev(const T_Type (&a_cpArray)[t_Size]);
  //! Fill sparse array with buffer with given size into the previous backward iterator position.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully filled into the sparse array. \n
              false - if buffer with given size was not successfully filled into the sparse array. \n
  */
  Tbool fillPrev(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Fill sparse array with an item into the indexed iterator position.
  /*!
      \param a_cIndex - Index to fill.
      \param a_crItem - Constant reference to the item to fill.
      \return true  - if the item was successfully filled into the sparse array. \n
              false - if the item was not successfully filled into the sparse array. \n
  */
  Tbool fillIndex(const Tuint a_cIndex, const T_Type& a_crItem);
  //! Fill sparse array with constant array of fixed size into the indexed iterator position.
  /*!
      \param a_cIndex - Index to fill.
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if constant array of fixed size was successfully filled into the sparse array. \n
              false - if constant array of fixed size was not successfully filled into the sparse array. \n
  */
  template <Tuint t_Size>
  Tbool fillIndex(const Tuint a_cIndex, const T_Type (&a_cpArray)[t_Size]);
  //! Fill sparse array with buffer with given size into the indexed iterator position.
  /*!
      \param a_cIndex - Index to fill.
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if buffer with given size was successfully filled into the sparse array. \n
              false - if buffer with given size was not successfully filled into the sparse array. \n
  */
  Tbool fillIndex(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize);

  //! Erase item from the current iterator position and move iterator forward.
  /*!
      \return true  - if item was erased successfully. \n
              false - if item was not erased successfully. \n
  */
  Tbool eraseForward();
  //! Erase item from the current iterator position and move iterator forward.
  /*!
      \param a_rItem - Reference to returning erased item.
      \return true  - if item was erased successfully. \n
              false - if item was not erased successfully. \n
  */
  Tbool eraseForward(T_Type& a_rItem);
  //! Erase item from the next forward iterator position.
  /*!
      \return true  - if item was erased successfully. \n
              false - if item was not erased successfully. \n
  */
  Tbool eraseNext();
  //! Erase item from the next forward iterator position.
  /*!
      \param a_rItem - Reference to returning erased item.
      \return true  - if item was erased successfully. \n
              false - if item was not erased successfully. \n
  */
  Tbool eraseNext(T_Type& a_rItem);
  //! Erase item from the current iterator position and move iterator backward.
  /*!
      \return true  - if item was erased successfully. \n
              false - if item was not erased successfully. \n
  */
  Tbool eraseBackward();
  //! Erase item from the current iterator position and move iterator backward.
  /*!
      \param a_rItem - Reference to returning erased item.
      \return true  - if item was erased successfully. \n
              false - if item was not erased successfully. \n
  */
  Tbool eraseBackward(T_Type& a_rItem);
  //! Erase item from the previous backward iterator position.
  /*!
      \return true  - if item was erased successfully. \n
              false - if item was not erased successfully. \n
  */
  Tbool erasePrev();
  //! Erase item from the previous backward iterator position.
  /*!
      \param a_rItem - Reference to returning erased item.
      \return true  - if item was erased successfully. \n
              false - if item was not erased successfully. \n
  */
  Tbool erasePrev(T_Type& a_rItem);
  //! Erase item from the random (indexed) container position.
  /*!
      \param a_cIndex - Indexed container position to erase.
      \return true  - if item was erased successfully. \n
              false - if item was not erased successfully. \n
  */
  Tbool eraseIndex(const Tuint a_cIndex);
  //! Erase item from the random (indexed) container position.
  /*!
      \param a_cIndex - Indexed container position to erase.
      \param a_rItem - Reference to returning erased item.
      \return true  - if item was erased successfully. \n
              false - if item was not erased successfully. \n
  */
  Tbool eraseIndex(const Tuint a_cIndex, T_Type& a_rItem);
  //! Erase items interval from the random (indexed) container position.
  /*!
      \param a_cIndex - Indexed container position to erase.
      \param a_cSize - Size of erased interval.
      \return true  - if items were erased successfully. \n
              false - if items were not erased successfully. \n
  */
  Tbool erase(const Tuint a_cIndex, const Tuint a_cSize);

  //! Serialize CSparseArrayIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CSparseArrayIterator class instances.
  /*!
      \param a_rInstance - Reference to another CSparseArrayIterator class instance.
  */
  void swap(CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_rInstance);

private:
  CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>* m_pContainer;                                                                      //!< Pointer to the iterator container.
  typename T_AssociativeContainer<NDetails::CSparseValue<T_Type>, NDetails::FSparseValueComparator<T_Type>, T_Allocator>::TIterator m_Iterator; //!< Base associative container non constant iterator.
  Tuint m_Index;                                                                                                                                //!< Index of the current sparse array item.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CSparseArrayIterator(CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>* a_pContainer);
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
//! Traits meta-class: sparse array non constant iterator's traits specialization.
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> > :
  public MType<NContainers::NIterators::CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::TIterator iterator;

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
#include <Depth/include/containers/iterators/CSparseArrayIterator.inl>
/*==========================================================================*/
#endif
