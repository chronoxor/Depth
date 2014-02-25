/*!
 *  \file    CQueue.hpp Template queue container class. Queue represents
 *           container that can implement FIFO (first in - first out)
 *           algorithm.
 *  \brief   Template queue container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template queue container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   13.02.2006 00:06:37

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
#ifndef __CQUEUE_HPP__
#define __CQUEUE_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IQueue.hpp>
#include <Depth/include/common/containers/IQueueConst.hpp>
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
class CQueueIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CQueueIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template queue container class.
/*!
    Queue represents  container  with  FIFO  (first  in  -  first  out)  stock
    algorithm. For example, you insert item A into queue. Then you insert item
    B into queue. There is an item A at the begin of the queue and there is an
    item B at the end of the queue. After removing item A, there  will  be  an
    item B at the begin of the queue.

    \code
     Begin                          Insert here --->--End
       |                                               |
    +-----+         +-----+         +-----+         +-----+
    |     |    Next |     |    Next |     |    Next |     |    Next
    |  1  |-------->|  2  |-------->|  3  |-------->|  4  |--------> NULL
    |     |         |     |         |     |         |     |
    +-----+         +-----+         +-----+         +-----+
       |
       +--->--- Remove from here
    \endcode

    <b>Overview.</b>\n
    In providing services  in  computer  science,  transport,  and  operations
    research a queue is a buffer where various entities such as data, objects,
    persons, or events are stored and waiting to be processed. The  most  well
    known operation of  the  queue  is  the  First-In-First-Out  (FIFO)  queue
    process - In a FIFO queue, the first element in  the  queue  will  be  the
    first one out; this is equivalent to  the  requirement  that  whenever  an
    element is added, all elements that were added before have to  be  removed
    before the new element can be invoked.

    There are two basic  operations  associated  with  a  queue:  enqueue  and
    dequeue. Enqueue means adding a new item to the rear of  the  queue  while
    dequeue refers to removing the front item from queue  and  returns  it  in
    item.

    Theoretically, one characteristic of a queue is that it does  not  have  a
    specific capacity. Regardless of how many elements are already  contained,
    a new element can always be added. It can also be empty,  at  which  point
    removing an element will be impossible until a new element has been  added
    again.

    A practical implementation of a queue of course does  have  some  capacity
    limit, that depends on the concrete situation it is used in.  For  a  data
    structure the executing computer will eventually run out of  memory,  thus
    limiting the queue size. Queue overflow results  from  trying  to  add  an
    element onto a full queue and  queue  underflow  happens  when  trying  to
    remove an element from an empty queue.

    <b>Scheduling and buffering queues.</b>
    A queue is natural data structure for  a  system  to  serve  the  incoming
    requests. Most of the process scheduling or disk scheduling algorithms  in
    operating systems use queues. Computer hardware  like  a  processor  or  a
    network card also maintain buffers in the  form  of  queues  for  incoming
    resource requests. A stack like data structure causes  starvation  of  the
    first requests, and is not applicable in such cases. A mailbox or port  to
    save messages to communicate between two users or processes in a system is
    essentially a queue like structure.

    <b>Search space exploration.</b>
    Like stacks, queues can be used to remember the search space that needs to
    be explored at one point of time in traversing algorithms.  Breadth  first
    search of a graph uses a queue to remember the nodes yet to be visited.

    <b>References.</b>\n
    \li Donald Knuth. The Art of Computer Programming, Volume  1:  Fundamental
        Algorithms, Third Edition. Addison-Wesley, 1997.  ISBN  0-201-89683-4.
        Section 2.2.1: Stacks, Queues, and Deques, pp. 238-243.
    \li Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford
        Stein. Introduction to  Algorithms,  Second  Edition.  MIT  Press  and
        McGraw-Hill,  2001.  ISBN  0-262-03293-7.  Section  10.1:  Stacks  and
        queues, pp.200-204.

    <b>Taken from:</b>\n
    Stack from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Queue
*/
template <typename T_Type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CQueue :
  public NCommon::NContainers::IQueue<CQueue<T_Type, T_Allocator>, T_Type, CQueueIterator<T_Type, T_Allocator>, CQueueIteratorConst<T_Type, T_Allocator> >,
  public NCommon::NContainers::IQueueConst<CQueue<T_Type, T_Allocator>, T_Type, CQueueIterator<T_Type, T_Allocator>, CQueueIteratorConst<T_Type, T_Allocator> >
{
  // Friend class: Queue iterator class (CQueueIterator).
  friend class CQueueIterator<T_Type, T_Allocator>;
  // Friend class: Constant queue iterator class (CQueueIteratorConst).
  friend class CQueueIteratorConst<T_Type, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CQueue<T_Type, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CQueue class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef T_Type TType;
  //! Container type.
  typedef CQueue<T_Type, T_Allocator> TContainer;
  //! Non constant queue iterator type.
  typedef CQueueIterator<T_Type, T_Allocator> TIterator;
  //! Constant queue iterator type.
  typedef CQueueIteratorConst<T_Type, T_Allocator> TIteratorConst;

  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  /*!
      Create an empty queue.

      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CQueue(const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize queue with one item.
  /*!
      Create an empty queue, then insert item into it.

      \param a_crItem - Constant reference to the item to insert.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CQueue(const T_Type& a_crItem, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CQueue class.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CQueue(const CQueue<T_Type, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CQueue();

  //! Operator: Assign another CQueue class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CQueue class.
      \return Reference to the current class instance.
  */
  CQueue<T_Type, T_Allocator>& operator = (const CQueue<T_Type, T_Allocator>& a_crInstance);

  //! Set another CQueue class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CQueue class.
      \return true  - if another queue was successfully set. \n
              false - if another queue was not successfully set. \n
  */
  Tbool set(const CQueue<T_Type, T_Allocator>& a_crInstance);

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IQueue interface overriding methods.
  virtual Tbool insertLast(const T_Type& a_crItem);
  virtual Tbool removeFirst();
  virtual Tbool removeFirst(T_Type& a_rItem);

  // IQueueConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;

  //! Reverse queue.
  /*!
      Reverse queue items order.
  */
  void reverse();

  //! Serialization load CQueue class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CQueue class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CQueue class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CQueue class instances.
  /*!
      \param a_rInstance - Reference to another CQueue class instance.
  */
  void swap(CQueue<T_Type, T_Allocator>& a_rInstance);

protected:
  struct SQueueNode                     //! Queue node structure.
  {
  public:
    T_Type      m_Item;                 //!< Queue item value.
    SQueueNode* m_pNext;                //!< Pointer to the next queue node.

    //! Initialize queue node with the given item.
    /*!
        \param a_crItem - Initialized item.
    */
    SQueueNode(const T_Type& a_crItem);
  };

private:
  Tuint       m_Size;                   //!< Number of items in queue.
  SQueueNode* m_pFirst;                 //!< Pointer to the first queue node.
  SQueueNode* m_pLast;                  //!< Pointer to the last queue node.
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
//! Traits meta-class: queue container traits specialization.
template <typename T_Type, class T_Allocator>
class MTraitsContainer<NContainers::CQueue<T_Type, T_Allocator> > :
  public MType<NContainers::CQueue<T_Type, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CQueue<T_Type, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CQueue<T_Type, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CQueue<T_Type, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CQueue<T_Type, T_Allocator>::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = true;  //!< Is container non constant queue?
  static const Tbool isQueueConst       = true;  //!< Is container constant queue?
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
#include <Depth/include/containers/iterators/CQueueIterator.hpp>
#include <Depth/include/containers/iterators/CQueueIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CQueue.inl>
/*==========================================================================*/
//! \example example-containers-CQueue.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CQueue.cpp
/*==========================================================================*/
#endif
