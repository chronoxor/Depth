/*!
 *  \file    CSpan.hpp Template span container class.
 *  \brief   Template span container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.09.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template span container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template structures and containers
    VERSION:   1.0
    CREATED:   11.09.2007 02:42:52

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
#ifndef __CSPAN_HPP__
#define __CSPAN_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ALowerBound.hpp>
#include <Depth/include/common/containers/IAssociative.hpp>
#include <Depth/include/common/containers/IAssociativeConst.hpp>
#include <Depth/include/common/containers/IDequeConst.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/containers/MConceptAssociative.hpp>
#include <Depth/include/concept/containers/MConceptAssociativeConst.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/containers/CBinTreeRB.hpp>
#include <Depth/include/containers/details/CSpanValue.hpp>
#include <Depth/include/containers/details/FSpanValueComparator.hpp>
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
template <typename T_Type, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Type&>, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CSpanIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Type&>, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CSpanIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template span container class.
/*!
    Span container keeps intervals of values in ordered form. Intervals can be
    closed and opened. Intervals can be inserted/removed  into/from  the  span
    container. Default implementation of the span uses Red-Black  trees  as  a
    sorted container for storing keys/values.

    Example:
    \code
    CSpan<Tsint> span;

    // Fill the span.
    span.insert(0);
    span.insert(1, 20, true, true);
    span.insert(25);
    span.insert(30, 40, false, true);
    span.insert(45);
    span.insert(50, 60, false, false);
    span.insert(65);
    span.insert(70, 80, false, false);
    span.insert(85);

    // Remove items from the span.
    span.remove(0);
    span.remove(10, 35, true, false);
    span.remove(55);
    span.remove(70, 85, true, true);
    span.remove(90);
    span.remove(95, 97, false, true);
    span.remove(101);
    \endcode
*/
template <typename T_Type, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Type&>, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CSpan :
  public NCommon::NContainers::IAssociative<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NContainers::IAssociativeConst<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NContainers::IDequeConst<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
  // Friend class: Span iterator class (CSpanIterator).
  friend class CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>;
  // Friend class: Constant span iterator class (CSpanIteratorConst).
  friend class CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptPredicate2 argument constraint checking.
  typedef const T_Type& TPredicate2ArgumentCheckType;
  //! Type for MConceptPredicate2 constraint checking.
  typedef T_BinaryPredicate TPredicate2CheckType;
  //! Type for MConceptAssociative constraint checking.
  typedef T_AssociativeContainer<NDetails::CSpanValue<T_Type>, NDetails::FSpanValueComparator<T_Type, T_BinaryPredicate>, T_Allocator> TAssociativeContainerCheckType;
  //! Type for MConceptAssociativeConst constraint checking.
  typedef T_AssociativeContainer<NDetails::CSpanValue<T_Type>, NDetails::FSpanValueComparator<T_Type, T_BinaryPredicate>, T_Allocator> TAssociativeContainerConstCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_BinaryPredicate template argument constraint to be a suitable binary predicate.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TPredicate2CheckType, TPredicate2ArgumentCheckType, TPredicate2ArgumentCheckType);
  // Check T_AssociativeContainer template argument constraint to be a non constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociative, TAssociativeContainerCheckType);
  // Check T_AssociativeContainer template argument constraint to be a constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociativeConst, TAssociativeContainerConstCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CSpan class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container associative key type.
  typedef T_Type TKey;
  //! Container associative value type.
  typedef NDetails::CSpanValue<T_Type> TValue;

  //! Container key/value pair type.
  typedef NDetails::CSpanValue<T_Type> TType;
  //! Container type.
  typedef CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TContainer;
  //! Non constant span iterator type.
  typedef CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TIterator;
  //! Constant span iterator type.
  typedef CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TIteratorConst;

  //! Container's key binary predicate type.
  typedef T_BinaryPredicate TLessThanPredicate;
  //! Base associative container type.
  typedef T_AssociativeContainer<NDetails::CSpanValue<T_Type>, NDetails::FSpanValueComparator<T_Type, T_BinaryPredicate>, T_Allocator> TAssociativeContainer;
  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  /*!
      Create an empty span.

      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSpan(T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize span with a single value.
  /*!
      Create an empty span, then insert single value into it.

      \param a_crItem - Constant reference to the single value to insert.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSpan(const T_Type& a_crItem, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize span with an interval.
  /*!
      Create an empty span, then insert interval into it.

      \param a_crItem1 - Constant reference to the first interval value to insert.
      \param a_crItem2 - Constant reference to the second interval value to insert.
      \param a_cIncludeItem1 - Include first interval value flag (default is true).
      \param a_cIncludeItem2 - Include second interval value flag (default is true).
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSpan(const T_Type& a_crItem1, const T_Type& a_crItem2, const Tbool a_cIncludeItem1 = true, const Tbool a_cIncludeItem2 = true, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize span with a span value.
  /*!
      Create an empty span, then insert span value into it.

      \param a_crSpanValue - Constant reference to the span value to insert.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSpan(const NDetails::CSpanValue<T_Type>& a_crSpanValue, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSpan class.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSpan(const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CSpan();

  //! Operator: Assign another CSpan class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSpan class.
      \return Reference to the current class instance.
  */
  CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator = (const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Operator: Insert single value into span.
  /*!
      \param a_crItem - Constant reference to the single value to insert.
      \return Reference to the current class instance.
  */
  CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator += (const T_Type& a_crItem);
  //! Operator: Insert span value into span.
  /*!
      \param a_crSpanValue - Constant reference to the span value to insert.
      \return Reference to the current class instance.
  */
  CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator += (const NDetails::CSpanValue<T_Type>& a_crSpanValue);
  //! Operator: Insert another span into span.
  /*!
      \param a_crSpan - Constant reference to the span to insert.
      \return Reference to the current class instance.
  */
  CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator += (const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crSpan);
  //! Operator: Remove single value from span.
  /*!
      \param a_crItem - Constant reference to the single value to remove.
      \return Reference to the current class instance.
  */
  CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -= (const T_Type& a_crItem);
  //! Operator: Remove span value from span.
  /*!
      \param a_crSpanValue - Constant reference to the span value to remove.
      \return Reference to the current class instance.
  */
  CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -= (const NDetails::CSpanValue<T_Type>& a_crSpanValue);
  //! Operator: Remove another span from span.
  /*!
      \param a_crSpan - Constant reference to the span to remove.
      \return Reference to the current class instance.
  */
  CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -= (const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crSpan);

  //! Operator: Return non constant iterator to the span interval with given value.
  /*!
      \param a_crItem - Constant reference to the searching value.
      \return Non constant iterator with given value or invalid empty iterator.
  */
  TIterator operator [] (const T_Type& a_crItem);
  //! Operator: Return constant iterator to the span interval with given value.
  /*!
      \param a_crItem - Constant reference to the searching value.
      \return Constant iterator with given value or invalid empty iterator.
  */
  TIteratorConst operator [] (const T_Type& a_crItem) const;

  //! Set another CSpan class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSpan class.
      \return true  - if another span was successfully set. \n
              false - if another span was not successfully set. \n
  */
  Tbool set(const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IAccociative interface overriding methods.
  virtual Tbool insert(const T_Type& a_crItem);
  virtual Tbool insert(const T_Type& a_crItem1, const T_Type& a_crItem2, const Tbool a_cIncludeItem1 = true, const Tbool a_cIncludeItem2 = true);
  virtual Tbool insert(const NDetails::CSpanValue<T_Type>& a_crSpanValue);
  virtual Tbool insert(const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crSpan);
  virtual Tbool remove(const T_Type& a_crItem, const Tbool a_cRemoveSame = false);
  virtual Tbool remove(const T_Type& a_crItem1, const T_Type& a_crItem2, const Tbool a_cIncludeItem1 = true, const Tbool a_cIncludeItem2 = true, const Tbool a_cRemoveSame = false);
  virtual Tbool remove(const NDetails::CSpanValue<T_Type>& a_crSpanValue, const Tbool a_cRemoveSame = false);
  virtual Tbool remove(const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crSpan, const Tbool a_cRemoveSame = false);

  // IAccociativeConst interface overriding methods.
  virtual Tbool isLessThan(const T_Type& a_crItem1, const T_Type& a_crItem2) const;
  virtual TIterator      find(const T_Type& a_crItem);
  virtual TIteratorConst find(const T_Type& a_crItem) const;

  // IDequeConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;

  //! Serialization load CSpan class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CSpan class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CSpan class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CSpan class instances.
  /*!
      \param a_rInstance - Reference to another CSpan class instance.
  */
  void swap(CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance);

private:
  T_AssociativeContainer<NDetails::CSpanValue<T_Type>, NDetails::FSpanValueComparator<T_Type, T_BinaryPredicate>, T_Allocator> m_AssociativeContainer; //!< Associative container for the span.

  //! Internal insert engine.
  /*!
      \param a_crSpanValue - Constant reference to the span value to insert.
      \param a_pIterator - Pointer to the returning inserted span value iterator (default is NULL).
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  Tbool insertInternal(const NDetails::CSpanValue<T_Type>& a_crSpanValue, TIterator* a_pIterator = NULL);

  //! Get non constant iterator to the closest span value.
  /*!
      \param a_crValue - Constant reference to the single value.
      \param a_cLeft - Left interval flag (default is false).
      \param a_cRight - Right interval flag (default is false).
      \return Iterator to the closest span value.
  */
  TIterator getItClosest(const T_Type& a_crValue, const Tbool a_cLeft = false, const Tbool a_cRight = false);
  //! Get constant iterator to the closest span value.
  /*!
      \param a_crValue - Constant reference to the single value.
      \param a_cLeft - Left interval flag (default is false).
      \param a_cRight - Right interval flag (default is false).
      \return Constant iterator to the closest span value.
  */
  TIteratorConst getItClosest(const T_Type& a_crValue, const Tbool a_cLeft = false, const Tbool a_cRight = false) const;
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
//! Traits meta-class: span container traits specialization.
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class MTraitsContainer<NContainers::CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> > :
  public MType<NContainers::CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst citerator;

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
  static const Tbool isRandomConst      = false; //!< Is container constant random?
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
#include <Depth/include/containers/iterators/CSpanIterator.hpp>
#include <Depth/include/containers/iterators/CSpanIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CSpan.inl>
/*==========================================================================*/
//! \example example-containers-CSpan.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CSpan.cpp
/*==========================================================================*/
#endif
