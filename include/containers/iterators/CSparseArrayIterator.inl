/*!
 *  \file    CSparseArrayIterator.inl Sparce array non constant iterator
 *           definitions. It gives ability to get and modify sparse array
 *           items and to do random moving through the sparse array items.
 *  \brief   Sparce array non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.10.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Sparce array non constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   02.10.2007 20:42:15

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
#ifndef __CSPARSEARRAYITERATOR_INL__
#define __CSPARSEARRAYITERATOR_INL__
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
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::CSparseArrayIterator() :
  NCommon::NIterators::IIterator<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertRandom<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveRandom<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::ISeekable(),
  m_pContainer(NULL),
  m_Iterator(),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::CSparseArrayIterator(CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>* a_pContainer) :
  NCommon::NIterators::IIterator<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertRandom<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveRandom<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::ISeekable(),
  m_pContainer(a_pContainer),
  m_Iterator((a_pContainer != NULL) ? a_pContainer->getItLast() : typename TAssociativeContainer::TIterator()),
  m_Index((a_pContainer != NULL) ? a_pContainer->getLastIndex() : 0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::CSparseArrayIterator(const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIterator<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertRandom<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveRandom<CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::ISeekable(),
  m_pContainer(NULL),
  m_Iterator(),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::~CSparseArrayIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator == (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator != (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator < (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator > (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator <= (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator >= (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::operator = (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::operator += (const Tuint a_cStepCount)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::operator -= (const Tuint a_cStepCount)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::operator ++ (int)
{ CALL
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::operator -- (int)
{ CALL
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> operator + (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> operator - (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::operator [] (const Tsint a_cIndex) const
{ CALL
  return getIndex((Tuint)a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::operator [] (const Tuint a_cIndex) const
{ CALL
  return getIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::set(const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_Iterator = a_crInstance.m_Iterator;
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::getForward() const
{ CALL
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::getBackward() const
{ CALL
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::getIndex(const Tuint a_cIndex) const
{ CALL
  CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator> it(*this);
  // Perform indexed step and return indexed iterator instance or invalid one.
  return (it.stepIndex(a_cIndex) ? it : CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::TAssociativeContainer::TIterator CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::getSparse() const
{ CALL
  return m_Iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && m_Iterator.isValid());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>* CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline T_Type& CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return NAlgorithms::NCommon::constCast<T_Type&, const T_Type&>(m_Iterator.getValueRef()[m_Index]);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline T_Type* CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return NAlgorithms::NCommon::constCast<T_Type*, const T_Type*>(&m_Iterator.getValueRef()[m_Index]);
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid sparse array iterator."))
  {
    return 0;
  }

  Tuint delta = 0;
  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while (counter > 0)
  {
    delta = NAlgorithms::NCommon::min(counter, m_Iterator.getValueRef().getSecondIndex() - m_Index);
    // Step inside current interval.
    if (delta > 0)
    {
      m_Index += delta;
      counter -= delta;
    }
    // Step inside new interval.
    if (counter > 0)
    {
      if (m_Iterator.stepForward() == 0)
        break;
      m_Index = m_Iterator.getValueRef().getFirstIndex();
      --counter;
    }
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid sparse array iterator."))
  {
    return 0;
  }

  Tuint delta = 0;
  Tuint counter = a_cStepCount;
  // Try to step backward by given steps.
  while (counter > 0)
  {
    delta = NAlgorithms::NCommon::min(counter, m_Index - m_Iterator.getValueRef().getFirstIndex());
    // Step inside current interval.
    if (delta > 0)
    {
      m_Index -= delta;
      counter -= delta;
    }
    // Step inside new interval.
    if (counter > 0)
    {
      if (m_Iterator.stepBackward() == 0)
        break;
      m_Index = m_Iterator.getValueRef().getSecondIndex();
      --counter;
    }
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::stepIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot do indexed step with the invalid sparse array container."))
  {
    return false;
  }

  TIterator it = m_pContainer->getItIndex(a_cIndex);

  // Check index value and the array bounds.
  ASSERT(it.isValid(), STR("Cannot do indexed step with the out of bounds index (index = %u).") COMMA a_cIndex)
  {
    return false;
  }

  m_Iterator = it.m_Iterator;
  m_Index = it.m_Index;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertForward(const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid sparse array container."))
  {
    return false;
  }

  return m_pContainer->insertInternal((isValid() ? (m_Index + 1) : m_Index), &a_crItem, 1, this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertForward(const T_Type (&a_cpArray)[t_Size])
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new interval into the invalid sparse array container."))
  {
    return false;
  }

  return m_pContainer->insertInternal((isValid() ? (m_Index + 1) : m_Index), a_cpArray, t_Size, this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertForward(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new interval into the invalid sparse array container."))
  {
    return false;
  }

  return m_pContainer->insertInternal((isValid() ? (m_Index + 1) : m_Index), a_cpBuffer, a_cSize, this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertNext(const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->insertInternal(m_Index + 1, &a_crItem, 1))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertNext(const T_Type (&a_cpArray)[t_Size])
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new interval into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->insertInternal(m_Index + 1, a_cpArray, t_Size))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertNext(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new interval into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->insertInternal(m_Index + 1, a_cpBuffer, a_cSize))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertBackward(const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid sparse array container."))
  {
    return false;
  }

  return m_pContainer->insertInternal(m_Index, &a_crItem, 1, this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertBackward(const T_Type (&a_cpArray)[t_Size])
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new interval into the invalid sparse array container."))
  {
    return false;
  }

  return m_pContainer->insertInternal(m_Index, a_cpArray, t_Size, this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertBackward(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new interval into the invalid sparse array container."))
  {
    return false;
  }

  return m_pContainer->insertInternal(m_Index, a_cpBuffer, a_cSize, this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertPrev(const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->insertInternal(m_Index, &a_crItem, 1))
  {
    ++m_Index;
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertPrev(const T_Type (&a_cpArray)[t_Size])
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new interval into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->insertInternal(m_Index, a_cpArray, t_Size))
  {
    m_Index += t_Size;
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertPrev(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new interval into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->insertInternal(m_Index, a_cpBuffer, a_cSize))
  {
    m_Index += a_cSize;
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertIndex(const Tuint a_cIndex, const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->insertInternal(a_cIndex, &a_crItem, 1))
  {
    if (m_Index >= a_cIndex)
      ++m_Index;
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertIndex(const Tuint a_cIndex, const T_Type (&a_cpArray)[t_Size])
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new interval into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->insertInternal(a_cIndex, a_cpArray, t_Size))
  {
    if (m_Index >= a_cIndex)
      m_Index += t_Size;
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::insertIndex(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new interval into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->insertInternal(a_cIndex, a_cpBuffer, a_cSize))
  {
    if (m_Index >= a_cIndex)
      m_Index += a_cSize;
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::removeForward()
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->removeInternal(m_Index, 1, true))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::removeForward(T_Type& a_rItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->removeInternal(m_Index, 1, true, &a_rItem))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::removeNext()
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->removeInternal(m_Index +  1, 1, true))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::removeNext(T_Type& a_rItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->removeInternal(m_Index +  1, 1, true, &a_rItem))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::removeBackward()
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->removeInternal(m_Index, 1, true))
  {
    if (m_Index > 0)
      --m_Index;
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::removeBackward(T_Type& a_rItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->removeInternal(m_Index, 1, true, &a_rItem))
  {
    if (m_Index > 0)
      --m_Index;
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::removePrev()
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove item from the invalid sparse array container."))
  {
    return false;
  }
  // Check if the current iterator position is not the first one.
  ASSERT((m_Index > 0), STR("Cannot remove item from the previous backward position of 0 one."))
  {
    return false;
  }

  if (m_pContainer->removeInternal(m_Index - 1, 1, true))
  {
    --m_Index;
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::removePrev(T_Type& a_rItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove item from the invalid sparse array container."))
  {
    return false;
  }
  // Check if the current iterator position is not the first one.
  ASSERT((m_Index > 0), STR("Cannot remove item from the previous backward position of 0 one."))
  {
    return false;
  }

  if (m_pContainer->removeInternal(m_Index - 1, 1, true, &a_rItem))
  {
    --m_Index;
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::removeIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->removeInternal(a_cIndex, 1, true))
  {
    if ((m_Index > 0) && (m_Index >= a_cIndex))
      --m_Index;
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::removeIndex(const Tuint a_cIndex, T_Type& a_rItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->removeInternal(a_cIndex, 1, true, &a_rItem))
  {
    if ((m_Index > 0) && (m_Index >= a_cIndex))
      --m_Index;
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::remove(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot remove items interval from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->removeInternal(a_cIndex, a_cSize, false))
  {
    if ((m_Index > 0) && (m_Index >= a_cIndex))
    {
      if (m_Index >= (a_cIndex + a_cSize))
        m_Index -= a_cSize;
      else
        m_Index = a_cIndex;
    }
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillForward(const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot fill a new item into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->fillInternal(m_Index, &a_crItem, 1))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillForward(const T_Type (&a_cpArray)[t_Size])
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot fill a new interval into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->fillInternal(m_Index, a_cpArray, t_Size))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillForward(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot fill a new interval into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->fillInternal(m_Index, a_cpBuffer, a_cSize))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillNext(const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot fill a new item into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->fillInternal(m_Index + 1, &a_crItem, 1))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillNext(const T_Type (&a_cpArray)[t_Size])
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot fill a new interval into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->fillInternal(m_Index + 1, a_cpArray, t_Size))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillNext(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot fill a new interval into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->fillInternal(m_Index + 1, a_cpBuffer, a_cSize))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillBackward(const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot fill a new item into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->fillInternal(m_Index, &a_crItem, 1))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillBackward(const T_Type (&a_cpArray)[t_Size])
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot fill a new interval into the invalid sparse array container."))
  {
    return false;
  }
  // Check if the constant array size is suitable for filling.
  ASSERT((m_Index >= t_Size), STR("Filled constant array size (%u) is greater than the current position (%d) of the sparse array iterator.") COMMA t_Size COMMA m_Index)
  {
    return false;
  }

  if (m_pContainer->filInternal(m_Index - t_Size, a_cpArray, t_Size))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillBackward(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot fill a new interval into the invalid sparse array container."))
  {
    return false;
  }
  // Check if the buffer size is suitable for filling.
  ASSERT((m_Index >= a_cSize), STR("Filled buffer size (%u) is greater than the current position (%d) of the sparse array iterator.") COMMA a_cSize COMMA m_Index)
  {
    return false;
  }

  if (m_pContainer->filInternal(m_Index - a_cSize, a_cpBuffer, a_cSize))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillPrev(const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot fill a new item into the invalid sparse array container."))
  {
    return false;
  }
  // Check if the current iterator position is not the first one.
  ASSERT((m_Index > 0), STR("Cannot fill a new item into the previous backward position of 0 one."))
  {
    return false;
  }

  if (m_pContainer->fillInternal(m_Index - 1, &a_crItem, 1))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillPrev(const T_Type (&a_cpArray)[t_Size])
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot fill a new interval into the invalid sparse array container."))
  {
    return false;
  }
  // Check if the current iterator position is not the first one.
  ASSERT((m_Index > 0), STR("Cannot fill a new interval into the previous backward position of 0 one."))
  {
    return false;
  }
  // Check if the constant array size is suitable for filling.
  ASSERT(((m_Index - 1) >= t_Size), STR("Filled constant array size (%u) is greater than the previous backward position (%d) of the sparse array iterator.") COMMA t_Size COMMA (m_Index - 1))
  {
    return false;
  }

  if (m_pContainer->fillInternal(m_Index - t_Size - 1, a_cpArray, t_Size))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillPrev(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot fill a new interval into the invalid sparse array container."))
  {
    return false;
  }
  // Check if the current iterator position is not the first one.
  ASSERT((m_Index > 0), STR("Cannot fill a new interval into the previous backward position of 0 one."))
  {
    return false;
  }
  // Check if the buffer size is suitable for filling.
  ASSERT(((m_Index - 1) >= a_cSize), STR("Filled buffer size (%u) is greater than the previous backward position (%d) of the sparse array iterator.") COMMA a_cSize COMMA (m_Index - 1))
  {
    return false;
  }

  if (m_pContainer->fillInternal(m_Index - a_cSize - 1, a_cpBuffer, a_cSize))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillIndex(const Tuint a_cIndex, const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->fillInternal(a_cIndex, &a_crItem, 1))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillIndex(const Tuint a_cIndex, const T_Type (&a_cpArray)[t_Size])
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new interval into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->fillInternal(a_cIndex, a_cpArray, t_Size))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::fillIndex(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new interval into the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->fillInternal(a_cIndex, a_cpBuffer, a_cSize))
  {
    *this = m_pContainer->getItIndex(m_Index);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::eraseForward()
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot erase item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->eraseInternal(m_Index, 1, true))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::eraseForward(T_Type& a_rItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot erase item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->eraseInternal(m_Index, 1, true, &a_rItem))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::eraseNext()
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot erase item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->eraseInternal(m_Index +  1, 1, true))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::eraseNext(T_Type& a_rItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot erase item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->eraseInternal(m_Index +  1, 1, true, &a_rItem))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::eraseBackward()
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot erase item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->eraseInternal(m_Index, 1, true))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::eraseBackward(T_Type& a_rItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot erase item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->eraseInternal(m_Index, 1, true, &a_rItem))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::erasePrev()
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot erase item from the invalid sparse array container."))
  {
    return false;
  }
  // Check if the current iterator position is not the first one.
  ASSERT((m_Index > 0), STR("Cannot erase item from the previous backward position of 0 one."))
  {
    return false;
  }

  if (m_pContainer->eraseInternal(m_Index - 1, 1, true))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::erasePrev(T_Type& a_rItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot erase item from the invalid sparse array container."))
  {
    return false;
  }
  // Check if the current iterator position is not the first one.
  ASSERT((m_Index > 0), STR("Cannot erase item from the previous backward position of 0 one."))
  {
    return false;
  }

  if (m_pContainer->eraseInternal(m_Index - 1, 1, true, &a_rItem))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::eraseIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot erase item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->eraseInternal(a_cIndex, 1, true))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::eraseIndex(const Tuint a_cIndex, T_Type& a_rItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot erase item from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->eraseInternal(a_cIndex, 1, true, &a_rItem))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::erase(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot erase items interval from the invalid sparse array container."))
  {
    return false;
  }

  if (m_pContainer->eraseInternal(a_cIndex, a_cSize, false))
  {
    *this = m_pContainer->getItIndex(m_Index);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, true, false);
    if (!isValid())
      *this = m_pContainer->getItClosest(m_Index, false, true);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::getSize() const
{ CALL
  return (isValidContainer() ? m_pContainer->getLastIndex() : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::setPosition(const Tuint a_cPosition)
{ CALL
  return stepIndex(a_cPosition);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::getPosition() const
{ CALL
  return m_Index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>::swap(CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pContainer, a_rInstance.m_pContainer);
  NAlgorithms::NCommon::swap(m_Iterator, a_rInstance.m_Iterator);
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
