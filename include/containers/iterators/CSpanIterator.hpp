/*!
 *  \file    CSpanIterator.hpp Span non constant iterator definitions. It
 *           gives ability to get and modify span items.
 *  \brief   Span non constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.09.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Span non constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   13.09.2007 23:00:23

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
#ifndef __CSPANITERATOR_HPP__
#define __CSPANITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorInsertAssociative.hpp>
#include <Depth/include/common/iterators/IIteratorMoveAssociative.hpp>
#include <Depth/include/common/iterators/IIteratorMoveBackward.hpp>
#include <Depth/include/common/iterators/IIteratorRemoveAssociative.hpp>
#include <Depth/include/containers/CSpan.hpp>
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
//! Span non constant iterator class.
/*!
    Span non constant iterator represents span iterations  method.  With  this
    iterator you can perform looking into span items and also modify them.
*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class CSpanIterator :
  public NCommon::NIterators::IIterator<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveAssociative<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveBackward<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorInsertAssociative<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorRemoveAssociative<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
  // Friend class: Span class (CSpan).
  friend class CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>;
  // Friend class: Span constant iterator class (CSpanIteratorConst).
  friend class CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptAssociative constraint checking.
  typedef T_AssociativeContainer<NDetails::CSpanValue<T_Type>, NDetails::FSpanValueComparator<T_Type, T_BinaryPredicate>, T_Allocator> TAssociativeCheckType;
  //! Type for MConceptAssociativeConst constraint checking.
  typedef T_AssociativeContainer<NDetails::CSpanValue<T_Type>, NDetails::FSpanValueComparator<T_Type, T_BinaryPredicate>, T_Allocator> TAssociativeConstCheckType;
  //! Type for MConceptPredicate2 argument constraint checking.
  typedef const T_Type& TPredicate2ArgumentCheckType;
  //! Type for MConceptPredicate2 constraint checking.
  typedef T_BinaryPredicate TPredicate2CheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_AssociativeContainer template argument constraint to be a non constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociative, TAssociativeCheckType);
  // Check T_AssociativeContainer template argument constraint to be a constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociativeConst, TAssociativeConstCheckType);
  // Check T_BinaryPredicate template argument constraint to be a suitable binary predicate.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TPredicate2CheckType, TPredicate2ArgumentCheckType, TPredicate2ArgumentCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CSpanIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator associative key type.
  typedef T_Type TKey;
  //! Iterator associative value type.
  typedef NDetails::CSpanValue<T_Type> TValue;

  //! Iterator value type.
  typedef NDetails::CSpanValue<T_Type> TType;
  //! Iterator return type.
  typedef const NDetails::CSpanValue<T_Type> TReturn;
  //! Iterator container type.
  typedef CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TIterator;

  //! Container's key binary predicate type.
  typedef T_BinaryPredicate TLessThanPredicate;
  //! Base associative container type.
  typedef T_AssociativeContainer<NDetails::CSpanValue<T_Type>, NDetails::FSpanValueComparator<T_Type, T_BinaryPredicate>, T_Allocator> TAssociativeContainer;
  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CSpanIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSpanIterator class.
  */
  CSpanIterator(const CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CSpanIterator();

  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CSpanIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSpanIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CSpanIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSpanIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CSpanIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSpanIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CSpanIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSpanIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CSpanIteratorConst<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSpanIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CSpanIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSpanIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator = (const CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend CSpanIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator> operator + (const CSpanIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend CSpanIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator> operator - (const CSpanIterator<T_OtherType, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Find iterator with given value in span.
  /*!
      \param a_crValue - Constant reference to the searching value.
      \return Iterator with given value or invalid empty iterator.
  */
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> operator [] (const T_Type& a_crValue) const;

  //! Set another CSpanIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSpanIterator class.
  */
  void set(const CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> getBackward() const;

  // IIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& getContainerRef() const;
  virtual CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>* getContainerPtr() const;
  virtual const NDetails::CSpanValue<T_Type>& getValueRef() const;
  virtual const NDetails::CSpanValue<T_Type>* getValuePtr() const;

  // IIteratorMoveAssociative interface overriding methods.
  virtual CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> find(const T_Type& a_crValue) const;

  // IIteratorMoveBackward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);

  // IIteratorInsertAssociative interface overriding methods.
  virtual Tbool insert(const T_Type& a_crItem, const Tbool a_cUpdate = false);
  virtual Tbool insert(const T_Type& a_crItem1, const T_Type& a_crItem2, const Tbool a_cIncludeItem1 = true, const Tbool a_cIncludeItem2 = true, const Tbool a_cUpdate = false);
  virtual Tbool insert(const NDetails::CSpanValue<T_Type>& a_crSpanValue, const Tbool a_cUpdate = false);

  // IIteratorRemoveAssociative interface overriding methods.
  virtual Tbool remove();
  virtual Tbool remove(T_Type& a_rItem1, T_Type& a_rItem2, Tbool& a_rIncludeItem1, Tbool& a_rIncludeItem2);
  virtual Tbool remove(NDetails::CSpanValue<T_Type>& a_rSpanValue);

  //! Serialization load CSpanIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CSpanIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CSpanIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CSpanIterator class instances.
  /*!
      \param a_rInstance - Reference to another CSpanIterator class instance.
  */
  void swap(CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance);

private:
  CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>* m_pContainer;                                                                         //!< Pointer to the iterator container.
  typename T_AssociativeContainer<NDetails::CSpanValue<T_Type>, NDetails::FSpanValueComparator<T_Type, T_BinaryPredicate>, T_Allocator>::TIterator m_Iterator; //!< Base associative container non constant iterator.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CSpanIterator(CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>* a_pContainer);
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
//! Traits meta-class: span non constant iterator's traits specialization.
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> > :
  public MType<NContainers::NIterators::CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator iterator;

  static const Tbool isConst             = false; //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = false; //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = true;  //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = false; //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = false; //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = false; //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = false; //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = true;  //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false; //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = false; //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = false; //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = false; //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = true;  //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false; //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CSpanIterator.inl>
/*==========================================================================*/
#endif
