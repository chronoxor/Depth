/*!
 *  \file    CStringBufferIteratorConst.hpp String buffer constant iterator
 *           definitions. It gives ability to get string buffer items and
 *           to do random moving through the string buffer items.
 *  \brief   String buffer constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: String buffer constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   07.04.2009 23:43:06

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
#ifndef __CSTRINGBUFFERITERATORCONST_HPP__
#define __CSTRINGBUFFERITERATORCONST_HPP__
/*==========================================================================*/
#include <Depth/include/containers/iterators/CArrayIteratorConst.hpp>
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
//! String buffer constant iterator class.
/*!
    String  buffer  constant  iterator  represents  string  buffer  iterations
    method. With this iterator you can perform random string buffer moving and
    looking into string buffer items.  Note  that  you  cannot  modify  string
    buffer items with constant iterator. In this case use non constant  string
    buffer iterator.

    Serialization: String buffer constant iterator cannot be loaded.
*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
class CStringBufferIteratorConst :
  public NCommon::NIterators::IIteratorConst<CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>, T_Type, T_Type, CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveRandom<CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>, T_Type, T_Type, CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> >,
  public NCommon::ISeekable
{
  // Friend class: String buffer class (CStringBuffer).
  friend class CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>;

  //! Type for MConceptIResizePolicy constraint checking.
  typedef T_ResizePolicy TResizePolicyCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> TDepthCheckType;

  // Check T_ResizePolicy template argument constraint to be a resize policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIResizePolicy, TResizePolicyCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CStringBufferIteratorConst class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef const T_Type TReturn;
  //! Iterator container type.
  typedef const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> TIterator;

  //! Container resize policy type.
  typedef T_ResizePolicy TResizePolicy;
  //! Container copy policy type.
  typedef NPolicy::CCopyPolicyMemory TCopyPolicy;
  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CStringBufferIteratorConst();
  //! Initialize with non constant string buffer iterator.
  /*!
      \param a_crInstance - Constant reference to the instance of the CStringBufferIterator class.
  */
  CStringBufferIteratorConst(const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringBufferIteratorConst class.
  */
  CStringBufferIteratorConst(const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringBufferIteratorConst();

  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator == (const CStringBufferIterator<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator == (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIterator<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator == (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator != (const CStringBufferIterator<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator != (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIterator<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator != (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);

  //! Operator: Less than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator < (const CStringBufferIterator<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator < (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIterator<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator < (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator > (const CStringBufferIterator<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator > (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIterator<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator > (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator <= (const CStringBufferIterator<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator <= (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIterator<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator <= (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not more or equal to the given one. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator >= (const CStringBufferIterator<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not more or equal to the given one. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator >= (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIterator<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator >= (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another non constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the non constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& operator = (const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance);
  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& operator = (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator> operator + (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, class T_OtherResizePolicy, class T_OtherAllocator>
  friend CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator> operator - (const CStringBufferIteratorConst<T_OtherType, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Get new string buffer's constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed string buffer position to return.
      \return String buffer's constant iterator under the given index.
  */
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> operator [] (const Tsint a_cIndex) const;
  //! Operator: Get new string buffer's constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed string buffer position to return.
      \return String buffer's constant iterator under the given index.
  */
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> operator [] (const Tuint a_cIndex) const;

  //! Set CStringBufferIterator class instance.
  /*!
      \param a_crInstance - Constant reference to instance of the CStringBufferIterator class.
  */
  void set(const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance);
  //! Set another CStringBufferIteratorConst class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringBufferIteratorConst class.
  */
  void set(const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> getBackward() const;
  //! Get indexed iterator.
  /*!
      Method uses 'stepIndex()' iterator method to  get  an  indexed  iterator
      instance. If indexed iteration cannot be  done  method  returns  invalid
      iterator.

      \param a_cIndex - Indexed iterator position to return.
      \return Random iterator under the given index.
  */
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> getIndex(const Tuint a_cIndex) const;

  // IIteratorConst interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& getContainerRef() const;
  virtual const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>* getContainerPtr() const;
  virtual const T_Type& getValueRef() const;
  virtual const T_Type* getValuePtr() const;

  // IIteratorMoveRandom interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual Tbool stepIndex(const Tuint a_cIndex);

  // ISeekable interface overriding methods.
  virtual Tuint getSize() const;
  virtual Tbool setPosition(const Tuint a_cPosition);
  virtual Tuint getPosition() const;

  //! Serialization load CStringBufferIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CStringBufferIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CStringBufferIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringBufferIteratorConst class instances.
  /*!
      \param a_rInstance - Reference to another CStringBufferIteratorConst class instance.
  */
  void swap(CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_rInstance);

private:
  const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>* m_cpContainer;                                                                 //!< Constant pointer to the iterator container.
  typename CArray<typename NTraits::MAddPointer<T_Type>::type, T_ResizePolicy, NPolicy::CCopyPolicyMemory, T_Allocator>::TIteratorConst m_Iterator; //!< Base array container constant iterator.

  //! Initialize iterator with the container value.
  /*!
      \param a_cpContainer - Constant pointer to the iterator container value.
  */
  CStringBufferIteratorConst(const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>* a_cpContainer);
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
//! Traits meta-class: string buffer constant iterator's traits specialization.
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> > :
  public MType<NContainers::NIterators::CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::TIterator iterator;

  static const Tbool isConst             = true;  //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = true;  //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = false; //!< Is iterator supports associative moving?
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
#include <Depth/include/containers/iterators/CStringBufferIteratorConst.inl>
/*==========================================================================*/
#endif
