/*!
 *  \file    CQueueIteratorConst.inl Queue constant iterator definitions. It
 *           gives ability to get queue items and to do forward moving through
 *           the queue nodes.
 *  \brief   Queue constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Queue constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   14.02.2006 21:14:48

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
#ifndef __CQUEUEITERATORCONST_INL__
#define __CQUEUEITERATORCONST_INL__
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
template <typename T_Type, class T_Allocator>
inline CQueueIteratorConst<T_Type, T_Allocator>::CQueueIteratorConst() :
  NCommon::NIterators::IIteratorConst<CQueueIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveForward<CQueueIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  m_cpContainer(NULL),
  m_cpNode(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIteratorConst<T_Type, T_Allocator>::CQueueIteratorConst(const CQueue<T_Type, T_Allocator>* a_cpContainer) :
  NCommon::NIterators::IIteratorConst<CQueueIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveForward<CQueueIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  m_cpContainer(a_cpContainer),
  m_cpNode(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIteratorConst<T_Type, T_Allocator>::CQueueIteratorConst(const CQueueIterator<T_Type, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CQueueIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveForward<CQueueIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  m_cpContainer(NULL),
  m_cpNode(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIteratorConst<T_Type, T_Allocator>::CQueueIteratorConst(const CQueueIteratorConst<T_Type, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CQueueIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveForward<CQueueIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CQueue<T_Type, T_Allocator> >(),
  m_cpContainer(NULL),
  m_cpNode(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIteratorConst<T_Type, T_Allocator>::~CQueueIteratorConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator == (const CQueueIterator<T_Type, T_Allocator>& a_crInstance1, const CQueueIteratorConst<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_pNode == a_crInstance2.m_cpNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator == (const CQueueIteratorConst<T_Type, T_Allocator>& a_crInstance1, const CQueueIterator<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_cpNode == a_crInstance2.m_pNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator == (const CQueueIteratorConst<T_Type, T_Allocator>& a_crInstance1, const CQueueIteratorConst<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_cpNode == a_crInstance2.m_cpNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator != (const CQueueIterator<T_Type, T_Allocator>& a_crInstance1, const CQueueIteratorConst<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_pNode != a_crInstance2.m_cpNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator != (const CQueueIteratorConst<T_Type, T_Allocator>& a_crInstance1, const CQueueIterator<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_cpNode != a_crInstance2.m_pNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator != (const CQueueIteratorConst<T_Type, T_Allocator>& a_crInstance1, const CQueueIteratorConst<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_cpNode != a_crInstance2.m_cpNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIteratorConst<T_Type, T_Allocator>& CQueueIteratorConst<T_Type, T_Allocator>::operator = (const CQueueIterator<T_Type, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIteratorConst<T_Type, T_Allocator>& CQueueIteratorConst<T_Type, T_Allocator>::operator = (const CQueueIteratorConst<T_Type, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIteratorConst<T_Type, T_Allocator>& CQueueIteratorConst<T_Type, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIteratorConst<T_Type, T_Allocator>& CQueueIteratorConst<T_Type, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIteratorConst<T_Type, T_Allocator> CQueueIteratorConst<T_Type, T_Allocator>::operator ++ (int)
{ CALL
  CQueueIteratorConst<T_Type, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIteratorConst<T_Type, T_Allocator> operator + (const CQueueIteratorConst<T_Type, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CQueueIteratorConst<T_Type, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CQueueIteratorConst<T_Type, T_Allocator>::set(const CQueueIterator<T_Type, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_pContainer;
  m_cpNode = a_crInstance.m_pNode;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CQueueIteratorConst<T_Type, T_Allocator>::set(const CQueueIteratorConst<T_Type, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_cpContainer;
  m_cpNode = a_crInstance.m_cpNode;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CQueueIteratorConst<T_Type, T_Allocator> CQueueIteratorConst<T_Type, T_Allocator>::getForward() const
{ CALL
  CQueueIteratorConst<T_Type, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CQueueIteratorConst<T_Type, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueueIteratorConst<T_Type, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && (m_cpNode != NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CQueueIteratorConst<T_Type, T_Allocator>::isValidContainer() const
{ CALL
  return (m_cpContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline const CQueue<T_Type, T_Allocator>& CQueueIteratorConst<T_Type, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline const CQueue<T_Type, T_Allocator>* CQueueIteratorConst<T_Type, T_Allocator>::getContainerPtr() const
{ CALL
  return m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline const T_Type& CQueueIteratorConst<T_Type, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_cpNode->m_Item;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline const T_Type* CQueueIteratorConst<T_Type, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_cpNode->m_Item;
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CQueueIteratorConst<T_Type, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid queue iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while ((m_cpNode->m_pNext != NULL) && (counter > 0))
  {
    m_cpNode = m_cpNode->m_pNext;
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CQueueIteratorConst<T_Type, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Constant iterator value cannot be loaded."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CQueueIteratorConst<T_Type, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CQueueIterator<T_Type, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CQueueIteratorConst<T_Type, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CQueueIteratorConst<T_Type, T_Allocator>::swap(CQueueIteratorConst<T_Type, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_cpContainer, a_rInstance.m_cpContainer);
  NAlgorithms::NCommon::swap(m_cpNode, a_rInstance.m_cpNode);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
