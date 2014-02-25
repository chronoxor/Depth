/*!
 *  \file    CRandomBufferReal.hpp Random real numbers buffer container class.
 *  \brief   Random real numbers buffer container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Random real numbers buffer container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 00:04:55

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
#ifndef __CRANDOMBUFFERREAL_HPP__
#define __CRANDOMBUFFERREAL_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/ICircleDoubleLinkedConst.hpp>
#include <Depth/include/common/containers/IContainer.hpp>
#include <Depth/include/concept/containers/MConceptDeque.hpp>
#include <Depth/include/concept/containers/MConceptDequeConst.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/containers/CDeque.hpp>
#include <Depth/include/random/CRandomGenerator.hpp>
#include <Depth/include/traits/MTraitsContainer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator = CRandomGenerator, template <typename, class> class T_DequeContainer = NContainers::CDeque, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CRandomBufferRealIterator;
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator = CRandomGenerator, template <typename, class> class T_DequeContainer = NContainers::CDeque, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CRandomBufferRealIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Random real numbers buffer container class.
/*!
    Random real numbers buffer container class  is  used  to  store  generated
    random numbers into the real numbers buffer and  provide  the  possibility
    for backward receiving/generation of the random real numbers.  It  extends
    provided  random  number  generator   with   buffering,   forward/backward
    navigation and iterator functionality.

    For example 4 random numbers were  generated  in  forward  direction  with
    'randomRealNext()' method: 25.7, 632.2, 748.5,  32.8.  Then  direction  is
    changed and  8  random  numbers  were  generated  with  'randomRealPrev()'
    method: 32.8, 748.5, 632.2, 25.7, 843.1, 42,7, 931.4.  The  idea  is  that
    only last 4 numbers were generated and the first 4 ones  were  taken  from
    the buffer.
*/
template <class T_RandomGenerator = CRandomGenerator, template <typename, class> class T_DequeContainer = NContainers::CDeque, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CRandomBufferReal :
  public T_RandomGenerator,
  public NCommon::NContainers::IContainer<CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>, Treal, CRandomBufferRealIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>, CRandomBufferRealIteratorConst<T_RandomGenerator, T_DequeContainer, T_Allocator> >,
  public NCommon::NContainers::ICircleDoubleLinkedConst<CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>, Treal, CRandomBufferRealIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>, CRandomBufferRealIteratorConst<T_RandomGenerator, T_DequeContainer, T_Allocator> >
{
  // Friend class: Random real numbers buffer iterator class (CRandomBufferRealIterator).
  friend class CRandomBufferRealIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>;
  // Friend class: Constant random real numbers buffer iterator class (CRandomBufferRealIteratorConst).
  friend class CRandomBufferRealIteratorConst<T_RandomGenerator, T_DequeContainer, T_Allocator>;

  //! Type for MConceptDeque constraint checking.
  typedef T_DequeContainer<Treal, T_Allocator> TDequeContainerCheckType;
  //! Type for MConceptDequeConst constraint checking.
  typedef T_DequeContainer<Treal, T_Allocator> TDequeContainerConstCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator> TDepthCheckType;

  // Check T_DequeContainer template argument constraint to be a non constant deque container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptDeque, TDequeContainerCheckType);
  // Check T_DequeContainer template argument constraint to be a constant deque container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptDequeConst, TDequeContainerConstCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CRandomBufferReal class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef Treal TType;
  //! Container type.
  typedef CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator> TContainer;
  //! Non constant random real numbers buffer iterator type.
  typedef CRandomBufferRealIterator<T_RandomGenerator, T_DequeContainer, T_Allocator> TIterator;
  //! Constant random real numbers buffer iterator type.
  typedef CRandomBufferRealIteratorConst<T_RandomGenerator, T_DequeContainer, T_Allocator> TIteratorConst;

  //! Base deque container type.
  typedef T_DequeContainer<Treal, T_Allocator> TDequeContainer;
  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  /*!
      \param a_crRandomGenerator - Constant reference to the instance of the random number generator (default is T_RandomGenerator()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CRandomBufferReal(const T_RandomGenerator& a_crRandomGenerator = T_RandomGenerator(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomBufferReal class.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CRandomBufferReal(const CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CRandomBufferReal();

  //! Operator: Assign another CRandomBufferReal class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomBufferReal class.
      \return Reference to the current class instance.
  */
  CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>& operator = (const CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>& a_crInstance);

  //! Set another CRandomBufferReal class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomBufferReal class.
      \return true  - if another random real numbers buffer was successfully set. \n
              false - if another random real numbers buffer was not successfully set. \n
  */
  Tbool set(const CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>& a_crInstance);

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // ICircleDoubleLinkedConst interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual TIterator      getItCurrent();
  virtual TIteratorConst getItCurrent() const;
  virtual TIterator      getItNext();
  virtual TIteratorConst getItNext() const;
  virtual TIterator      getItPrev();
  virtual TIteratorConst getItPrev() const;

  //! Get current real random number.
  /*!
      If the current real random number  is  available  in  the  buffer,  then
      return it. Otherwise the method generates new random value  as  an  real
      number, puts it into the buffer and  then  returns  it.  Note  that  the
      returned real number is in the [0.0, 1.0] interval.

      \return Current real random value.
  */
  Treal randomRealCurrent();
  //! Get next real random number.
  /*!
      If the next real random number is available in the buffer,  then  return
      it. Otherwise the method generates new random value as an  real  number,
      puts it into the buffer and then returns it. Note that the returned real
      number is in the [0.0, 1.0] interval.

      \return Next real random value.
  */
  Treal randomRealNext();
  //! Get previous real random number.
  /*!
      If the previous real random number is  available  in  the  buffer,  then
      return it. Otherwise the method generates new random value  as  an  real
      number, puts it into the buffer and  then  returns  it.  Note  that  the
      returned real number is in the [0.0, 1.0] interval.

      \return Previous real random value.
  */
  Treal randomRealPrev();

  //! Serialization load CRandomBufferReal class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CRandomBufferReal class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CRandomBufferReal class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomBufferReal class instances.
  /*!
      \param a_rInstance - Reference to another CRandomBufferReal class instance.
  */
  void swap(CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>& a_rInstance);

private:
  T_DequeContainer<Treal, T_Allocator> m_DequeContainer;              //!< Deque container for the random real numbers buffer.
  typename T_DequeContainer<Treal, T_Allocator>::TIterator m_ItIndex; //!< Current buffer index iterator.

  //! Get index of the current buffer index iterator.
  /*!
      \return Index of the current buffer index iterator.
  */
  Tuint getIndexByIterator() const;
  //! Set iterator of the current random numbers buffer with the given index.
  /*!
      \param a_cIndex - Index value.
      \return true  - if iterator was successfully found and set. \n
              false - if iterator was not successfully found and set. \n
  */
  Tbool setIteratorByIndex(const Tuint a_cIndex) const;
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
//! Traits meta-class: random real numbers buffer container traits specialization.
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
class MTraitsContainer<NRandom::CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator> > :
  public MType<NRandom::CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NRandom::CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::TType value;
  //! Container type.
  typedef typename NRandom::CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NRandom::CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NRandom::CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = true;  //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = false; //!< Is container non constant queue?
  static const Tbool isQueueConst       = false; //!< Is container constant queue?
  static const Tbool isDeque            = false; //!< Is container non constant deque?
  static const Tbool isDequeConst       = false; //!< Is container constant deque?
  static const Tbool isRandom           = false; //!< Is container non constant random?
  static const Tbool isRandomConst      = false; //!< Is container constant random?
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
#include <Depth/include/random/iterators/CRandomBufferRealIterator.hpp>
#include <Depth/include/random/iterators/CRandomBufferRealIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/random/CRandomBufferReal.inl>
/*==========================================================================*/
//! \example example-random-CRandomBufferReal.cpp
/*--------------------------------------------------------------------------*/
//! \test test-random-CRandomBufferReal.cpp
/*==========================================================================*/
#endif
