/*!
 *  \file    CArrayIterator.inl Array non constant iterator definitions. It
 *           gives ability to get and modify array items and to do random
 *           moving through the array items.
 *  \brief   Array non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Array non constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   06.04.2006 20:24:42

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
#ifndef __CARRAYITERATOR_INL__
#define __CARRAYITERATOR_INL__
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
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArrayIterator() :
  NCommon::NIterators::IIterator<CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertRandom<CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveRandom<CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_pContainer(NULL),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArrayIterator(CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>* a_pContainer) :
  NCommon::NIterators::IIterator<CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertRandom<CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveRandom<CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_pContainer(a_pContainer),
  m_Index((a_pContainer != NULL) ? a_pContainer->getSize() : 0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArrayIterator(const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIterator<CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertRandom<CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveRandom<CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_pContainer(NULL),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::~CArrayIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator == (const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator != (const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator < (const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator > (const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator <= (const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator >= (const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator = (const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator += (const Tuint a_cStepCount)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator -= (const Tuint a_cStepCount)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator ++ (int)
{ CALL
  CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator -- (int)
{ CALL
  CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator + (const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator - (const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tsint a_cIndex) const
{ CALL
  return getIndex((Tuint)a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tuint a_cIndex) const
{ CALL
  return getIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getForward() const
{ CALL
  CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getBackward() const
{ CALL
  CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getIndex(const Tuint a_cIndex) const
{ CALL
  CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> it(*this);
  // Perform indexed step and return indexed iterator instance or invalid one.
  return (it.stepIndex(a_cIndex) ? it : CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && (m_Index < m_pContainer->getSize()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>* CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline T_Type& CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_pContainer->m_pData[m_Index];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline T_Type* CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_pContainer->m_pData[m_Index];
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid array iterator."))
  {
    return 0;
  }

  // Get available steps count.
  Tuint steps = NAlgorithms::NCommon::min(a_cStepCount, (m_pContainer->getSize() - m_Index - 1));
  // Step forward by given steps.
  m_Index += steps;
  // Return step count, that we have done.
  return steps;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid array iterator."))
  {
    return 0;
  }

  // Get available steps count.
  Tuint steps = NAlgorithms::NCommon::min(a_cStepCount, m_Index);
  // Step forward by given steps.
  m_Index -= steps;
  // Return step count, that we have done.
  return steps;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::stepIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot do indexed step with the invalid array container."))
  {
    return false;
  }
  // Check index value and the array bounds.
  ASSERT(((a_cIndex < m_pContainer->getSize()) || (a_cIndex == 0)), STR("Cannot do indexed step with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_pContainer->getSize())
  {
    return false;
  }

  m_Index = a_cIndex;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insertForward(const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid array container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new item to the invalid iterator of the non empty array (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  Tbool empty = m_pContainer->isEmpty();

  if (m_pContainer->insertIndex((empty ? 0 : (m_Index + 1)), a_crItem))
  {
    if (empty)
      m_Index = 0;
    else
      ++m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insertNext(const T_Type& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new item into the invalid array iterator."))
  {
    return false;
  }

  return m_pContainer->insertIndex(m_Index + 1, a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insertBackward(const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid array container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new item to the invalid iterator of the non empty array (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  Tbool empty = m_pContainer->isEmpty();

  if (m_pContainer->insertIndex((empty ? 0 : m_Index), a_crItem))
  {
    if (empty)
      m_Index = 0;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insertPrev(const T_Type& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new item into the invalid array iterator."))
  {
    return false;
  }

  if (m_pContainer->insertIndex(m_Index, a_crItem))
  {
    ++m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insertIndex(const Tuint a_cIndex, const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid array container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new item to the invalid iterator of the non empty array (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  Tbool empty = m_pContainer->isEmpty();

  if (m_pContainer->insertIndex(a_cIndex, a_crItem))
  {
    if (empty)
      m_Index = 0;
    else if ((m_Index != m_pContainer->getSize()) && (m_Index >= a_cIndex))
      ++m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeForward()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid array iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index))
  {
    if ((m_Index > 0) && (m_Index == m_pContainer->getSize()))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeForward(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid array iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index, a_rItem))
  {
    if ((m_Index > 0) && (m_Index == m_pContainer->getSize()))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeNext()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid array iterator."))
  {
    return false;
  }
  // Check index value and the array bounds.
  ASSERT(((m_Index + 1) < m_pContainer->getSize()), STR("Cannot remove item from the next forward array position without a corresponding item, from the end array position (index = %u, size = %u).") COMMA (m_Index + 1) COMMA m_pContainer->getSize())
  {
    return false;
  }

  return m_pContainer->removeIndex(m_Index + 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeNext(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid array iterator."))
  {
    return false;
  }
  // Check index value and the array bounds.
  ASSERT(((m_Index + 1) < m_pContainer->getSize()), STR("Cannot remove item from the next forward array position without a corresponding item, from the end array position (index = %u, size = %u).") COMMA (m_Index + 1) COMMA m_pContainer->getSize())
  {
    return false;
  }

  return m_pContainer->removeIndex(m_Index + 1, a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeBackward()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid array iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index))
  {
    if (m_Index > 0)
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeBackward(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid array iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index, a_rItem))
  {
    if (m_Index > 0)
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removePrev()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid array iterator."))
  {
    return false;
  }
  // Check index value and the array bounds.
  ASSERT((m_Index > 0), STR("Cannot remove item from the previous backward array position without a corresponding item, from the begin array position (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index - 1))
  {
    --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removePrev(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid array iterator."))
  {
    return false;
  }
  // Check index value and the array bounds.
  ASSERT((m_Index > 0), STR("Cannot remove item from the previous backward array position without a corresponding item, from the begin array position (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index - 1, a_rItem))
  {
    --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid array iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(a_cIndex))
  {
    if ((m_Index > 0) && (m_Index >= a_cIndex))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeIndex(const Tuint a_cIndex, T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid array iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(a_cIndex, a_rItem))
  {
    if ((m_Index > 0) && (m_Index >= a_cIndex))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::remove(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove items interval from the invalid array iterator."))
  {
    return false;
  }

  // Calculate real count of removing items.
  Tuint size = NAlgorithms::NCommon::min(m_pContainer->getSize() - a_cIndex, a_cSize);

  if (m_pContainer->remove(a_cIndex, a_cSize))
  {
    if ((m_Index > 0) && (m_Index >= a_cIndex))
    {
      if (m_Index >= (a_cIndex + size))
        m_Index -= size;
      else
        m_Index = a_cIndex;
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getSize() const
{ CALL
  return (isValidContainer() ? m_pContainer->getSize() : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::setPosition(const Tuint a_cPosition)
{ CALL
  return stepIndex(a_cPosition);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getPosition() const
{ CALL
  return (isValidContainer() ? m_Index : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::swap(CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pContainer, a_rInstance.m_pContainer);
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
