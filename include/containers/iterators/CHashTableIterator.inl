/*!
 *  \file    CHashTableIterator.inl Hash table non constant iterator
 *           definitions. It gives ability to get and modify hash table items.
 *  \brief   Hash table non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Hash table non constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   12.06.2008 23:55:07

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
#ifndef __CHASHTABLEITERATOR_INL__
#define __CHASHTABLEITERATOR_INL__
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
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::CHashTableIterator() :
  NCommon::NIterators::IIterator<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  m_pContainer(NULL),
  m_pNode(NULL),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::CHashTableIterator(CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>* a_pContainer) :
  NCommon::NIterators::IIterator<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  m_pContainer(a_pContainer),
  m_pNode(NULL),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::CHashTableIterator(const CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIterator<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  m_pContainer(NULL),
  m_pNode(NULL),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::~CHashTableIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool operator == (const CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance1, const CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_pNode == a_crInstance2.m_pNode) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool operator != (const CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance1, const CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_pNode != a_crInstance2.m_pNode) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator = (const CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator ++ (int)
{ CALL
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator -- (int)
{ CALL
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> operator + (const CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> operator - (const CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator [] (const T_Key& a_crKey) const
{ CALL
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> it = find(a_crKey);
  if (!it.isValid())
    it.insert(a_crKey, T_Value(), true);
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline void CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::set(const CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_pNode = a_crInstance.m_pNode;
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getForward() const
{ CALL
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getBackward() const
{ CALL
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && (m_pNode != NULL) && (m_Index < m_pContainer->m_ResizePolicy.getHiCapacity()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>* CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline NUtility::CPair<T_Key, T_Value>& CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getPairRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator key/value pair for invalid iterator leads to the error."));

  return m_pNode->m_KeyValuePair;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline NUtility::CPair<T_Key, T_Value>* CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getPairPtr() const
{ CALL
  if (isValid())
    return &m_pNode->m_KeyValuePair;
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline const T_Key& CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getKeyRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator key for invalid iterator leads to the error."));

  return m_pNode->m_KeyValuePair.getFirst();
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline const T_Key* CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getKeyPtr() const
{ CALL
  if (isValid())
    return &m_pNode->m_KeyValuePair.getFirst();
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline T_Value& CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_pNode->m_KeyValuePair.getSecond();
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline T_Value* CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_pNode->m_KeyValuePair.getSecond();
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::find(const T_Key& a_crKey) const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Cannot find given key in the hash table with the invalid iterator container."));

  return m_pContainer->find(a_crKey);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tuint CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  return m_pContainer->stepForward(*this, a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tuint CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  return m_pContainer->stepBackward(*this, a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::insert(const T_Key& a_crKey, const T_Value& a_crValue, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new key and value into the invalid hash table container."))
  {
    return false;
  }

  return (find(a_crKey).isValid() ? false : m_pContainer->insertInternal(NUtility::CPair<T_Key, T_Value>(a_crKey, a_crValue), (a_cUpdate ? this : NULL)));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::insert(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new key/value pair into the invalid hash table container."))
  {
    return false;
  }

  return (find(a_crKeyValuePair.getFirst()).isValid() ? false : m_pContainer->insertInternal(a_crKeyValuePair, (a_cUpdate ? this : NULL)));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::remove()
{ CALL
  return m_pContainer->removeInternal(*this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::remove(T_Value& a_rValue)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove key/value pair from the invalid hash table iterator."))
  {
    return false;
  }

  a_rValue = m_pNode->m_KeyValuePair.getSecond();
  return m_pContainer->removeInternal(*this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::remove(T_Key& a_rKey, T_Value& a_rValue)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove key/value pair from the invalid hash table iterator."))
  {
    return false;
  }

  a_rKey = m_pNode->m_KeyValuePair.getFirst();
  a_rValue = m_pNode->m_KeyValuePair.getSecond();
  return m_pContainer->removeInternal(*this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::remove(NUtility::CPair<T_Key, T_Value>& a_rKeyValuePair)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove key/value pair from the invalid hash table iterator."))
  {
    return false;
  }

  a_rKeyValuePair = m_pNode->m_KeyValuePair;
  return m_pContainer->removeInternal(*this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  NUtility::CPair<T_Key, T_Value> value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
    CHECK(insert(value, true));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline void CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::swap(CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pContainer, a_rInstance.m_pContainer);
  NAlgorithms::NCommon::swap(m_pNode, a_rInstance.m_pNode);
  NAlgorithms::NCommon::swap(m_Index, a_rInstance.m_Index);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
