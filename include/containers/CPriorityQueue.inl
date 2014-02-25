/*!
 *  \file    CPriorityQueue.inl Template priority queue container class.
 *  \brief   Template priority queue container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template priority queue container class (inline).

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
#ifndef __CPRIORITYQUEUE_INL__
#define __CPRIORITYQUEUE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CPriorityQueue(T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IDeque<CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CPriorityQueueIteratorConst<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CPriorityQueueIteratorConst<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_AssociativeContainer(NAlgorithms::NFunctions::FPriorityComparator<T_Type, T_Priority, T_BinaryPredicate>(a_fLessThan), a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CPriorityQueue(const T_Type& a_crItem, const T_Priority& a_crPriority/* = T_Priority() */, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IDeque<CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CPriorityQueueIteratorConst<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CPriorityQueueIteratorConst<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_AssociativeContainer(NUtility::CPair<T_Type, T_Priority>(a_crItem, a_crPriority), NAlgorithms::NFunctions::FPriorityComparator<T_Type, T_Priority, T_BinaryPredicate>(a_fLessThan), a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CPriorityQueue(const NUtility::CPair<T_Type, T_Priority>& a_crValuePriorityPair, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IDeque<CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CPriorityQueueIteratorConst<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CPriorityQueueIteratorConst<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_AssociativeContainer(a_crValuePriorityPair, NAlgorithms::NFunctions::FPriorityComparator<T_Type, T_Priority, T_BinaryPredicate>(a_fLessThan), a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CPriorityQueue(const CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IDeque<CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CPriorityQueueIteratorConst<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CPriorityQueueIteratorConst<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_AssociativeContainer(a_crInstance.m_AssociativeContainer, NAlgorithms::NFunctions::FPriorityComparator<T_Type, T_Priority, T_BinaryPredicate>(a_fLessThan), a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::~CPriorityQueue()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator = (const CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::set(const CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  return m_AssociativeContainer.set(a_crInstance.m_AssociativeContainer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::clear()
{ CALL
  return m_AssociativeContainer.clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::isEmpty() const
{ CALL
  return m_AssociativeContainer.isEmpty();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getSize() const
{ CALL
  return m_AssociativeContainer.getSize();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const T_Type& a_crItem, const T_Priority& a_crPriority/* = T_Priority() */)
{ CALL
  return m_AssociativeContainer.insert(NUtility::CPair<T_Type, T_Priority>(a_crItem, a_crPriority));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const NUtility::CPair<T_Type, T_Priority>& a_crValuePriorityPair)
{ CALL
  return m_AssociativeContainer.insert(a_crValuePriorityPair);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insertFirst(const T_Type& a_crItem, const T_Priority& a_crPriority/* = T_Priority() */)
{ CALL
  return m_AssociativeContainer.insert(NUtility::CPair<T_Type, T_Priority>(a_crItem, a_crPriority));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insertFirst(const NUtility::CPair<T_Type, T_Priority>& a_crValuePriorityPair)
{ CALL
  return m_AssociativeContainer.insert(a_crValuePriorityPair);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insertLast(const T_Type& a_crItem, const T_Priority& a_crPriority/* = T_Priority() */)
{ CALL
  return m_AssociativeContainer.insert(NUtility::CPair<T_Type, T_Priority>(a_crItem, a_crPriority));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insertLast(const NUtility::CPair<T_Type, T_Priority>& a_crValuePriorityPair)
{ CALL
  return m_AssociativeContainer.insert(a_crValuePriorityPair);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::removeFirst()
{ CALL
  typename CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator it(getItFirst());

  return (it.isValid() ? it.remove() : false);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::removeFirst(T_Type& a_rItem)
{ CALL
  typename CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator it(getItFirst());

  return (it.isValid() ? it.remove(a_rItem) : false);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::removeFirst(T_Type& a_rItem, T_Priority& a_rPriority)
{ CALL
  typename CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator it(getItFirst());

  return (it.isValid() ? it.remove(a_rItem, a_rPriority) : false);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::removeFirst(NUtility::CPair<T_Type, T_Priority>& a_rValuePriorityPair)
{ CALL
  typename CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator it(getItFirst());

  return (it.isValid() ? it.remove(a_rValuePriorityPair) : false);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::removeLast()
{ CALL
  typename CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator it(getItLast());

  return (it.isValid() ? it.remove() : false);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::removeLast(T_Type& a_rItem)
{ CALL
  typename CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator it(getItLast());

  return (it.isValid() ? it.remove(a_rItem) : false);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::removeLast(T_Type& a_rItem, T_Priority& a_rPriority)
{ CALL
  typename CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator it(getItLast());

  return (it.isValid() ? it.remove(a_rItem, a_rPriority) : false);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::removeLast(NUtility::CPair<T_Type, T_Priority>& a_rValuePriorityPair)
{ CALL
  typename CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator it(getItLast());

  return (it.isValid() ? it.remove(a_rValuePriorityPair) : false);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getItFirst()
{ CALL
  TIterator first_iterator;

  // Filling iterator inner structure.
  first_iterator.m_pContainer = this;
  first_iterator.m_Iterator = m_AssociativeContainer.getItLast();
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getItFirst() const
{ CALL
  TIteratorConst first_iterator;

  // Filling iterator inner structure.
  first_iterator.m_cpContainer = this;
  first_iterator.m_Iterator = m_AssociativeContainer.getItLast();
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getItLast()
{ CALL
  TIterator last_iterator;

  // Filling iterator inner structure.
  last_iterator.m_pContainer = this;
  last_iterator.m_Iterator = m_AssociativeContainer.getItFirst();
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getItLast() const
{ CALL
  TIteratorConst last_iterator;

  // Filling iterator inner structure.
  last_iterator.m_cpContainer = this;
  last_iterator.m_Iterator = m_AssociativeContainer.getItFirst();
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Clear the current priority queue.
  CHECK(clear());

  // Load the priority queue header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the priority queue content.
  while (size-- > 0)
  {
    NUtility::CPair<T_Type, T_Priority> item;

    // Load next priority queue item.
    CHECK(a_rArchive.doValue(item, STR("item")));
    // Insert next item into the priority queue.
    CHECK(insert(item));
  }

  // Load the priority queue end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the priority queue header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_AssociativeContainer.getSize(), STR("size")));
  CHECK(a_rArchive.body());

  // Save the priority queue content.
  if (!isEmpty())
  {
    TIteratorConst it_first = getItFirst();
    TIteratorConst it_current = it_first;

    // Save all priority queue items.
    while (it_current.isValid())
    {
      // Save next priority queue item.
      CHECK(a_rArchive.doValue(it_current.getPairRef(), STR("item")));
      // Switch to the next priority queue item.
      if ((it_current.stepForward() == 0) || (it_current == it_first))
        break;
    }
  }

  // Save the priority queue end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::swap(CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_AssociativeContainer, a_rInstance.m_AssociativeContainer);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
