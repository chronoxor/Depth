/*!
 *  \file    CPriorityQueueIterator.inl Priority queue non constant iterator
 *           definitions. It gives ability to get and modify priority queue
 *           items.
 *  \brief   Priority queue non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Priority queue non constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   07.05.2007 23:37:23

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
#ifndef __CPRIORITYQUEUEITERATOR_INL__
#define __CPRIORITYQUEUEITERATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CPriorityQueueIterator() :
  NCommon::NIterators::IIterator<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Priority, T_Type, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Priority, T_Type, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_pContainer(NULL),
  m_Iterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CPriorityQueueIterator(CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>* a_pContainer) :
  NCommon::NIterators::IIterator<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Priority, T_Type, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Priority, T_Type, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_pContainer(a_pContainer),
  m_Iterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CPriorityQueueIterator(const CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIterator<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Priority, T_Type, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Priority, T_Type, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_pContainer(NULL),
  m_Iterator()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::~CPriorityQueueIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator == (const CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Iterator == a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator != (const CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Iterator != a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator = (const CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator ++ (int)
{ CALL
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -- (int)
{ CALL
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> operator + (const CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> operator - (const CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::set(const CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_Iterator = a_crInstance.m_Iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getForward() const
{ CALL
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getBackward() const
{ CALL
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && m_Iterator.isValid());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>* CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline NUtility::CPair<T_Type, T_Priority>& CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getPairRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value/priority pair for invalid iterator leads to the error."));

  return NAlgorithms::NCommon::constCast<NUtility::CPair<T_Type, T_Priority>&, const NUtility::CPair<T_Type, T_Priority>&>(m_Iterator.getValueRef());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline NUtility::CPair<T_Type, T_Priority>* CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getPairPtr() const
{ CALL
  if (isValid())
    return NAlgorithms::NCommon::constCast<NUtility::CPair<T_Type, T_Priority>*, const NUtility::CPair<T_Type, T_Priority>*>(m_Iterator.getValuePtr());
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const T_Priority& CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getPriorityRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator priority value for invalid iterator leads to the error."));

  return m_Iterator.getValueRef().getSecond();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const T_Priority* CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getPriorityPtr() const
{ CALL
  if (isValid() && (m_Iterator.getValuePtr() != NULL))
    return &m_Iterator.getValuePtr()->getSecond();
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline T_Type& CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return (NAlgorithms::NCommon::constCast<NUtility::CPair<T_Type, T_Priority>&, const NUtility::CPair<T_Type, T_Priority>&>(m_Iterator.getValueRef())).getFirst();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline T_Type* CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid() && (m_Iterator.getValuePtr() != NULL))
    return &(NAlgorithms::NCommon::constCast<NUtility::CPair<T_Type, T_Priority>*, const NUtility::CPair<T_Type, T_Priority>*>(m_Iterator.getValuePtr()))->getFirst();
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid priority queue iterator."))
  {
    return 0;
  }

  return m_Iterator.stepBackward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid priority queue iterator."))
  {
    return 0;
  }

  return m_Iterator.stepForward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const T_Type& a_crItem, const T_Priority& a_crPriority/* = T_Priority() */, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new value into the invalid priority queue container."))
  {
    return false;
  }

  return m_Iterator.insert(NUtility::CPair<T_Type, T_Priority>(a_crItem, a_crPriority), a_cUpdate);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const NUtility::CPair<T_Type, T_Priority>& a_crValuePriorityPair, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new value/priority pair into the invalid priority queue container."))
  {
    return false;
  }

  return m_Iterator.insert(a_crValuePriorityPair, a_cUpdate);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::remove()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove value/priority pair from the invalid priority queue iterator."))
  {
    return false;
  }

  return m_Iterator.remove();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::remove(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove value/priority pair from the invalid priority queue iterator."))
  {
    return false;
  }

  NUtility::CPair<T_Type, T_Priority> temp;

  if (m_Iterator.remove(temp))
  {
    a_rItem = temp.getFirst();
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::remove(T_Type& a_rItem, T_Priority& a_rPriority)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove value/priority pair from the invalid priority queue iterator."))
  {
    return false;
  }

  NUtility::CPair<T_Type, T_Priority> temp;

  if (m_Iterator.remove(temp))
  {
    a_rItem = temp.getFirst();
    a_rPriority = temp.getSecond();
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::remove(NUtility::CPair<T_Type, T_Priority>& a_rValuePriorityPair)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove value/priority pair from the invalid priority queue iterator."))
  {
    return false;
  }

  return m_Iterator.remove(a_rValuePriorityPair);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  NUtility::CPair<T_Type, T_Priority> value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
    CHECK(insert(value, true));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::swap(CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pContainer, a_rInstance.m_pContainer);
  NAlgorithms::NCommon::swap(m_Iterator, a_rInstance.m_Iterator);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
