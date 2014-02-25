/*!
 *  \file    CDeque.hpp Template double ended queue container class. Deque
 *           represents container in which items can be inserted/removed
 *           into/from both container ends.
 *  \brief   Template double ended queue container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template double ended queue container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   15.02.2006 23:32:13

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
#ifndef __CDEQUE_HPP__
#define __CDEQUE_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IDeque.hpp>
#include <Depth/include/common/containers/IDequeConst.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
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
template <typename T_Type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CDequeIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CDequeIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template double ended queue container class.
/*!
    Deque represents container with double ended  stock  algorithm.  It  means
    that such container works like queue, but items  can  be  inserted/removed
    into/from both container ends (deque begin, deque end).

    \code
                    Begin-<-------- Insert here and there ---->------End
                      |                                               |
                   +-----+ Prev    +-----+ Prev    +-----+ Prev    +-----+
          Prev     |     |<--------|     |<--------|     |<--------|     |    Next
    NULL <---------|  1  |    Next |  2  |    Next |  3  |    Next |  4  |--------> NULL
                   |     |-------->|     |-------->|     |-------->|     |
                   +-----+         +-----+         +-----+         +-----+
                      |                                               |
                      +--->------ Remove from here and there -----<---+
    \endcode

    <b>Overview.</b>\n
    In computer science, a deque (short for  double-ended  queue)  is  a  data
    structure for which elements can be added to or removed from the front  or
    back. This differs from a normal queue, where elements can only  be  added
    to one end and removed from  the  other.  A  deque  maintains  a  slightly
    modified FIFO structure, doing so using each end as both left and right. A
    common implementation of a deque uses a dynamic array, where the  elements
    wrap around the end in a circular buffer. Deques can also  be  implemented
    using a doubly linked list, but that is normally just  referred  to  as  a
    linked list.

    Deque  is  usually  pronounced  deck,  possibly  due  to  the   conceptual
    similarity to a deck of cards, where a card can be dealt from or  returned
    to either the face or patterned side.

    <b>Naming.</b>\n
    Deque is sometimes written dequeue, but this is  generally  not  preferred
    because of dequeue's existing meaning as a verb: "to remove from a queue".
    Nevertheless, several libraries and some writers, such as  Aho,  Hopcroft,
    and Ullman in their textbook Data  Structures  and  Algorithms,  spell  it
    dequeue.

    <b>Complexity.</b>\n
    \li In a doubly-linked list implementation, the  Time  complexity  of  all
        operations is O(1).
    \li In a growing array, the amortized  complexity  of  all  operations  is
        O(1).

    <b>References.</b>\n
    \li Donald Knuth. The Art of Computer Programming, Volume  1:  Fundamental
        Algorithms, Third Edition. Addison-Wesley, 1997.  ISBN  0-201-89683-4.
        Section 2.2.1: Stacks, Queues, and Deques, pp. 238-243.

    <b>Taken from:</b>\n
    Deque from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Deque
*/
template <typename T_Type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CDeque :
  public NCommon::NContainers::IDeque<CDeque<T_Type, T_Allocator>, T_Type, CDequeIterator<T_Type, T_Allocator>, CDequeIteratorConst<T_Type, T_Allocator> >,
  public NCommon::NContainers::IDequeConst<CDeque<T_Type, T_Allocator>, T_Type, CDequeIterator<T_Type, T_Allocator>, CDequeIteratorConst<T_Type, T_Allocator> >
{
  // Friend class: Deque iterator class (CDequeIterator).
  friend class CDequeIterator<T_Type, T_Allocator>;
  // Friend class: Constant deque iterator class (CDequeIteratorConst).
  friend class CDequeIteratorConst<T_Type, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CDeque<T_Type, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CDeque class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef T_Type TType;
  //! Container type.
  typedef CDeque<T_Type, T_Allocator> TContainer;
  //! Non constant deque iterator type.
  typedef CDequeIterator<T_Type, T_Allocator> TIterator;
  //! Constant deque iterator type.
  typedef CDequeIteratorConst<T_Type, T_Allocator> TIteratorConst;

  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  /*!
      Create an empty deque.

      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CDeque(const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize deque with one item.
  /*!
      Create an empty deque, then insert item into it.

      \param a_crItem - Constant reference to the item to insert.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CDeque(const T_Type& a_crItem, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDeque class.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CDeque(const CDeque<T_Type, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CDeque();

  //! Operator: Assign another CDeque class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDeque class.
      \return Reference to the current class instance.
  */
  CDeque<T_Type, T_Allocator>& operator = (const CDeque<T_Type, T_Allocator>& a_crInstance);

  //! Set another CDeque class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDeque class.
      \return true  - if another deque was successfully set. \n
              false - if another deque was not successfully set. \n
  */
  Tbool set(const CDeque<T_Type, T_Allocator>& a_crInstance);

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IDeque interface overriding methods.
  virtual Tbool insertFirst(const T_Type& a_crItem);
  virtual Tbool insertLast(const T_Type& a_crItem);
  virtual Tbool removeFirst();
  virtual Tbool removeFirst(T_Type& a_rItem);
  virtual Tbool removeLast();
  virtual Tbool removeLast(T_Type& a_rItem);

  // IDequeConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;

  //! Reverse deque.
  /*!
      Reverse deque items order.
  */
  void reverse();

  //! Serialization load CDeque class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CDeque class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CDeque class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDeque class instances.
  /*!
      \param a_rInstance - Reference to another CDeque class instance.
  */
  void swap(CDeque<T_Type, T_Allocator>& a_rInstance);

protected:
  struct SDequeNode                     //! Deque node structure.
  {
  public:
    T_Type      m_Item;                 //!< Deque item value.
    SDequeNode* m_pPrev;                //!< Pointer to the previous deque node.
    SDequeNode* m_pNext;                //!< Pointer to the next deque node.

    //! Initialize deque node with the given item.
    /*!
        \param a_crItem - Initialized item.
    */
    SDequeNode(const T_Type& a_crItem);
  };

private:
  Tuint       m_Size;                   //!< Number of items in deque.
  SDequeNode* m_pFirst;                 //!< Pointer to the first deque node.
  SDequeNode* m_pLast;                  //!< Pointer to the last deque node.
  T_Allocator m_Allocator;              //!< Memory allocator.
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
//! Traits meta-class: double ended queue container traits specialization.
template <typename T_Type, class T_Allocator>
class MTraitsContainer<NContainers::CDeque<T_Type, T_Allocator> > :
  public MType<NContainers::CDeque<T_Type, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CDeque<T_Type, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CDeque<T_Type, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CDeque<T_Type, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CDeque<T_Type, T_Allocator>::TIteratorConst citerator;

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
#include <Depth/include/containers/iterators/CDequeIterator.hpp>
#include <Depth/include/containers/iterators/CDequeIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CDeque.inl>
/*==========================================================================*/
//! \example example-containers-CDeque.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CDeque.cpp
/*==========================================================================*/
#endif
