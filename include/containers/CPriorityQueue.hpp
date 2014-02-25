/*!
 *  \file    CPriorityQueue.hpp Template priority queue container class.
 *  \brief   Template priority queue container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template priority queue container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template structures and containers
    VERSION:   1.0
    CREATED:   07.05.2007 02:29:52

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
#ifndef __CPRIORITYQUEUE_HPP__
#define __CPRIORITYQUEUE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FPriorityComparator.hpp>
#include <Depth/include/common/containers/IDeque.hpp>
#include <Depth/include/common/containers/IDequeConst.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/containers/MConceptAssociative.hpp>
#include <Depth/include/concept/containers/MConceptAssociativeConst.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/containers/CBinTreeRB.hpp>
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
template <typename T_Type, typename T_Priority = Tuint, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Priority&>, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CPriorityQueueIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority = Tuint, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Priority&>, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CPriorityQueueIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template priority queue container class.
/*!
    Priority  queue  helps  to  organize  elements  in  the  queue  by   their
    additionally provided priority values. Elements with the greatest priority
    value will be inserted in the queue begin position,  while  elements  with
    the lowest one will be inserted in the queue end position.

    <b>Overview.</b>\n
    A priority queue  is  an  abstract  data  type  in  computer  programming,
    supporting the following three operations:

    \li Add an element to the queue with an associated priority.
    \li Remove the element from the queue that has the highest  priority,  and
        return it.
    \li Peek  at  the  element  with  highest  priority  without  removing  it
        (optionally).

    The simplest way to implement a priority queue data type  is  to  keep  an
    associative array mapping each priority to a list of  elements  with  that
    rity. If association lists are used to implement  the  associative  array,
    ing an element takes constant time but removing or peeking at the  element
    of highest priority takes linear (O(n)) time, because we must  search  all
    keys for the largest one. If a self-balancing binary search tree is  used,
    all three operations take O(log n) time; this is  a  popular  solution  in
    environments  that  already  provide  balanced  trees  but  nothing   more
    sophisticated. The van Emde Boas  tree,  another  associative  array  data
    structure, can perform all three operations in O(log log n) time, but at a
    space cost for small queues of about O(2m/2), where m  is  the  number  of
    bits in the priority value, which may be prohibitive.

    There are a number of specialized heap data structures that either  supply
    additional operations or outperform the above approaches. The binary  heap
    uses O(log n) time for both operations, but allows peeking at the  element
    of highest priority without removing it in constant time.  Binomial  heaps
    add several more operations,  but  require  O(log  n)  time  for  peeking.
    Fibonacci heaps can insert elements, peek at the maximum priority element,
    and increase an element's priority in amortized constant  time  (deletions
    are still O(log n)).

    The Standard Template Library  (STL),  part  of  the  C++  1998  standard,
    specifies "priority_queue" as one  of  the  STL  container  adapter  class
    templates. Unlike actual STL containers, it does not  allow  iteration  of
    its elements (it strictly adheres to its abstract data  type  definition).
    Java's library contains a PriorityQueue class.

    <b>Applications.</b>\n

    <b>Bandwidth management.</b>\n
    Priority queuing can be used to manage limited resources such as bandwidth  on
    a transmission line from a network router. In the event  of  outgoing  traffic
    queuing due to insufficient bandwidth, all other queues can be halted to  send
    the traffic from the highest priority queue upon arrival.  This  ensures  that
    the prioritized traffic (such as real-time traffic, e.g. a  RTP  stream  of  a
    VoIP connection) is forwarded with the least delay and the least likelihood of
    being rejected due to a queue reaching its maximum capacity. All other traffic
    can be handled when the highest priority queue is empty. Another approach used
    is to send disproportionately more traffic from higher priority queues.

    Usually a limitation (policer) is set to limit the bandwidth that traffic from
    the highest priority queue can take, in order to prevent high priority packets
    from choking off all other traffic. This limit is usually never reached due to
    high lever control instances such as  the  Cisco  Callmanager,  which  can  be
    programmed to inhibit calls which would exceed the programmed bandwidth limit.

    <b>Discrete event simulation.</b>\n
    Another use of a priority queue is to manage the events in  a  discrete  event
    simulation. The events are added to the queue with their simulation time  used
    as the priority. The  execution  of  the  simulation  proceeds  by  repeatedly
    pulling the top of the queue and executing the event thereon.

    <b>Relationship to sorting algorithms.</b>\n
    The semantics of priority  queues  naturally  suggest  a  sorting  method:
    insert  all  the  elements  to  be  sorted  into  a  priority  queue,  and
    sequentially remove them; they will come out  in  sorted  order.  This  is
    actually the procedure used by several sorting algorithms, once the  layer
    of abstraction provided by the priority queue  is  removed.  This  sorting
    method is equivalent to the following sorting algorithms:

    \li Heapsort if the priority queue is implemented with a heap.
    \li Selection sort if the priority queue is implemented with an  unordered
        array.
    \li Insertion sort if the priority queue is implemented  with  an  ordered
        array.

    <b>References.</b>\n
    \li Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford
        Stein. Introduction to  Algorithms,  Second  Edition.  MIT  Press  and
        McGraw-Hill, 2001. ISBN 0-262-03293-7. Section 6.5:  Priority  queues,
        pp.138-142.

    <b>Taken from:</b>\n
    Priority queue from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Priority_queue
*/
template <typename T_Type, typename T_Priority = Tuint, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Priority&>, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CPriorityQueue :
  public NCommon::NContainers::IDeque<CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CPriorityQueueIteratorConst<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NContainers::IDequeConst<CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CPriorityQueueIteratorConst<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
  // Friend class: Priority queue iterator class (CPriorityQueueIterator).
  friend class CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>;
  // Friend class: Constant priority queue iterator class (CPriorityQueueIteratorConst).
  friend class CPriorityQueueIteratorConst<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TTypeConstructibleCheckType;
  //! Type for MConceptConstructible constraint checking.
  typedef T_Priority TPriorityConstructibleCheckType;
  //! Type for MConceptPredicate2 argument constraint checking.
  typedef const T_Priority& TPredicate2ArgumentCheckType;
  //! Type for MConceptPredicate2 constraint checking.
  typedef T_BinaryPredicate TPredicate2CheckType;
  //! Type for MConceptAssociative constraint checking.
  typedef T_AssociativeContainer<NUtility::CPair<T_Type, T_Priority>, NAlgorithms::NFunctions::FPriorityComparator<T_Type, T_Priority, T_BinaryPredicate>, T_Allocator> TAssociativeContainerCheckType;
  //! Type for MConceptAssociativeConst constraint checking.
  typedef T_AssociativeContainer<NUtility::CPair<T_Type, T_Priority>, NAlgorithms::NFunctions::FPriorityComparator<T_Type, T_Priority, T_BinaryPredicate>, T_Allocator> TAssociativeContainerConstCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TTypeConstructibleCheckType);
  // Check T_Priority template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TPriorityConstructibleCheckType);
  // Check T_BinaryPredicate template argument constraint to be a suitable binary predicate.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TPredicate2CheckType, TPredicate2ArgumentCheckType, TPredicate2ArgumentCheckType);
  // Check T_AssociativeContainer template argument constraint to be a non constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociative, TAssociativeContainerCheckType);
  // Check T_AssociativeContainer template argument constraint to be a constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociativeConst, TAssociativeContainerConstCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CPriorityQueue class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef T_Type TValue;
  //! Container priority type.
  typedef T_Priority TPriority;

  //! Container value/priority pair type.
  typedef NUtility::CPair<T_Type, T_Priority> TType;
  //! Container type.
  typedef CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TContainer;
  //! Non constant map iterator type.
  typedef CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TIterator;
  //! Constant map iterator type.
  typedef CPriorityQueueIteratorConst<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TIteratorConst;

  //! Container binary predicate type.
  typedef T_BinaryPredicate TLessThanPredicate;
  //! Base associative container type.
  typedef T_AssociativeContainer<NUtility::CPair<T_Type, T_Priority>, NAlgorithms::NFunctions::FPriorityComparator<T_Type, T_Priority, T_BinaryPredicate>, T_Allocator> TAssociativeContainer;
  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  /*!
      Create an empty priority queue.

      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CPriorityQueue(T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize priority queue with one item with given priority.
  /*!
      Create an empty priority queue, then insert  item  with  given  priority
      into it.

      \param a_crItem - Constant reference to the item to insert.
      \param a_crPriority - Constant reference to the inserting item priority (default is T_Priority()).
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CPriorityQueue(const T_Type& a_crItem, const T_Priority& a_crPriority = T_Priority(), T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize priority queue with one value/priority pair.
  /*!
      Create an empty priority queue, then insert value/priority pair into it.

      \param a_crValuePriorityPair - Constant reference to the value/priority pair to insert.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CPriorityQueue(const NUtility::CPair<T_Type, T_Priority>& a_crValuePriorityPair, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPriorityQueue class.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CPriorityQueue(const CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CPriorityQueue();

  //! Operator: Assign another CPriorityQueue class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPriorityQueue class.
      \return Reference to the current class instance.
  */
  CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator = (const CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Set another CPriorityQueue class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPriorityQueue class.
      \return true  - if another map was successfully set. \n
              false - if another map was not successfully set. \n
  */
  Tbool set(const CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IQueue interface overriding methods.
  virtual Tbool insert(const T_Type& a_crItem, const T_Priority& a_crPriority = T_Priority());
  virtual Tbool insert(const NUtility::CPair<T_Type, T_Priority>& a_crValuePriorityPair);
  virtual Tbool insertFirst(const T_Type& a_crItem, const T_Priority& a_crPriority = T_Priority());
  virtual Tbool insertFirst(const NUtility::CPair<T_Type, T_Priority>& a_crValuePriorityPair);
  virtual Tbool insertLast(const T_Type& a_crItem, const T_Priority& a_crPriority = T_Priority());
  virtual Tbool insertLast(const NUtility::CPair<T_Type, T_Priority>& a_crValuePriorityPair);
  virtual Tbool removeFirst();
  virtual Tbool removeFirst(T_Type& a_rItem);
  virtual Tbool removeFirst(T_Type& a_rItem, T_Priority& a_rPriority);
  virtual Tbool removeFirst(NUtility::CPair<T_Type, T_Priority>& a_rValuePriorityPair);
  virtual Tbool removeLast();
  virtual Tbool removeLast(T_Type& a_rItem);
  virtual Tbool removeLast(T_Type& a_rItem, T_Priority& a_rPriority);
  virtual Tbool removeLast(NUtility::CPair<T_Type, T_Priority>& a_rValuePriorityPair);

  // IQueueConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;

  //! Serialization load CPriorityQueue class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CPriorityQueue class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CPriorityQueue class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CPriorityQueue class instances.
  /*!
      \param a_rInstance - Reference to another CPriorityQueue class instance.
  */
  void swap(CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance);

private:
  T_AssociativeContainer<NUtility::CPair<T_Type, T_Priority>, NAlgorithms::NFunctions::FPriorityComparator<T_Type, T_Priority, T_BinaryPredicate>, T_Allocator> m_AssociativeContainer; //!< Associative container for the priority queue.
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
//! Traits meta-class: priority queue container traits specialization.
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class MTraitsContainer<NContainers::CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> > :
  public MType<NContainers::CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst citerator;

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
#include <Depth/include/containers/iterators/CPriorityQueueIterator.hpp>
#include <Depth/include/containers/iterators/CPriorityQueueIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CPriorityQueue.inl>
/*==========================================================================*/
//! \example example-containers-CPriorityQueue.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CPriorityQueue.cpp
/*==========================================================================*/
#endif
