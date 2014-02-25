/*!
 *  \file    CSparseArray.inl Template sparse array container class. Sparse
 *           array represents a random access container with empty intervals.
 *  \brief   Template sparse array container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.09.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template sparse array container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   28.09.2007 21:37:00

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
#ifndef __CSPARSEARRAY_INL__
#define __CSPARSEARRAY_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::CSparseArray(const Tuint a_cIndex/* = 0 */, const Tuint a_cSize/* = 0 */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> >(),
  m_Size(0),
  m_AssociativeContainer(NDetails::FSparseValueComparator<T_Type>(), a_crAllocator),
  m_Allocator(a_crAllocator)
{ CALL
  T_Type value;
  Tuint size = a_cSize;
  while (size-- > 0)
    insertIndex(a_cIndex, value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::CSparseArray(const Tuint a_cIndex, const T_Type& a_crValue, const Tuint a_cSize, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> >(),
  m_Size(0),
  m_AssociativeContainer(NDetails::FSparseValueComparator<T_Type>(), a_crAllocator),
  m_Allocator(a_crAllocator)
{ CALL
  Tuint size = a_cSize;
  while (size-- > 0)
    insertIndex(a_cIndex, a_crValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::CSparseArray(const Tuint a_cIndex, const T_Type (&a_cpArray)[t_Size], const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> >(),
  m_Size(0),
  m_AssociativeContainer(NDetails::FSparseValueComparator<T_Type>(), a_crAllocator),
  m_Allocator(a_crAllocator)
{ CALL
  insertIndex(a_cIndex, a_cpArray);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::CSparseArray(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> >(),
  m_Size(0),
  m_AssociativeContainer(NDetails::FSparseValueComparator<T_Type>(), a_crAllocator),
  m_Allocator(a_crAllocator)
{ CALL
  insertIndex(a_cIndex, a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::CSparseArray(const CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>, CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> >(),
  m_Size(0),
  m_AssociativeContainer(NDetails::FSparseValueComparator<T_Type>(), a_crAllocator),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::~CSparseArray()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::operator = (const T_Type (&a_cpArray)[t_Size])
{ CALL
  set(0, a_cpArray);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::operator = (const CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline T_Type& CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::operator [] (const Tsint a_cIndex)
{ CALL
  TIterator it = getItIndex(a_cIndex);

  // Verify index value and the sparse array bounds.
  VERIFY(it.isValid(), STR("Cannot access to the sparse array's item with the out of bounds index."));

  return it.getValueRef();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline T_Type& CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::operator [] (const Tuint a_cIndex)
{ CALL
  TIterator it = getItIndex(a_cIndex);

  // Verify index value and the sparse array bounds.
  VERIFY(it.isValid(), STR("Cannot access to the sparse array's item with the out of bounds index."));

  return it.getValueRef();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const T_Type& CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::operator [] (const Tsint a_cIndex) const
{ CALL
  TIteratorConst it = getItIndex(a_cIndex);

  // Verify index value and the sparse array bounds.
  VERIFY(it.isValid(), STR("Cannot access to the sparse array's item with the out of bounds index."));

  return it.getValueRef();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const T_Type& CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::operator [] (const Tuint a_cIndex) const
{ CALL
  TIteratorConst it = getItIndex(a_cIndex);

  // Verify index value and the sparse array bounds.
  VERIFY(it.isValid(), STR("Cannot access to the sparse array's item with the out of bounds index."));

  return it.getValueRef();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::set(const Tuint a_cIndex, const T_Type (&a_cpArray)[t_Size])
{ CALL
  // Clear current sparse array.
  if (!clear())
    return false;

  return insertIndex(a_cIndex, a_cpArray);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::set(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Clear current sparse array.
  if (!clear())
    return false;

  return insertIndex(a_cIndex, a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::set(const CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CSparseArray class instance."))
  {
    return false;
  }

  // Clear current sparse array.
  if (!clear())
    return false;

  // Save the sparse array content.
  if (!a_crInstance.isEmpty())
  {
    typename TAssociativeContainer::TIteratorConst it_first = a_crInstance.m_AssociativeContainer.getItFirst();
    typename TAssociativeContainer::TIteratorConst it_current = it_first;

    // Save all sparse array intervals.
    while (it_current.isValid())
    {
      // Insert sparse array interval.
      if (!insertInternal(it_current.getValueRef().getFirstIndex(), it_current.getValueRef().getBuffer(), it_current.getValueRef().getLength()))
        return false;

      // Switch to the next sparse array interval.
      if ((it_current.stepForward() == 0) || (it_current == it_first))
        break;
    }
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::isValidIndex(const Tuint a_cIndex) const
{ CALL
  return (getItIndex(a_cIndex).isValid());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::getFirstIndex() const
{ CALL
  typename TAssociativeContainer::TIteratorConst it = m_AssociativeContainer.getItFirst();

  return (it.isValid() ? it.getValueRef().getFirstIndex() : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::getLastIndex() const
{ CALL
  typename TAssociativeContainer::TIteratorConst it = m_AssociativeContainer.getItLast();

  return (it.isValid() ? it.getValueRef().getSecondIndex() : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::getIntervalsCount() const
{ CALL
  return m_AssociativeContainer.getSize();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::clear()
{ CALL
  typename TAssociativeContainer::TIterator it = m_AssociativeContainer.getItFirst();
  while (it.isValid())
  {
    NDetails::CSparseValue<T_Type> temp = it.getValueRef();

    // Remove current sparse from container.
    if (!it.remove())
      return false;
    // Delete current sparse value.
    if (!deleteSparseValue(&temp))
      return false;
    m_Size -= temp.getSecondIndex() - temp.getFirstIndex() + 1;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::isEmpty() const
{ CALL
  return (m_AssociativeContainer.isEmpty() && (m_Size == 0));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::insertFirst(const T_Type& a_crItem)
{ CALL
  return insertInternal(getFirstIndex(), &a_crItem, 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::insertFirst(const T_Type (&a_cpArray)[t_Size])
{ CALL
  return insertInternal(getFirstIndex(), a_cpArray, t_Size);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::insertFirst(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  return insertInternal(getFirstIndex(), a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::insertLast(const T_Type& a_crItem)
{ CALL
  return insertInternal((isEmpty() ? 0 : (getLastIndex() + 1)), &a_crItem, 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::insertLast(const T_Type (&a_cpArray)[t_Size])
{ CALL
  return insertInternal((isEmpty() ? 0 : (getLastIndex() + 1)), a_cpArray, t_Size);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::insertLast(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  return insertInternal((isEmpty() ? 0 : (getLastIndex() + 1)), a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::insertIndex(const Tuint a_cIndex, const T_Type& a_crItem)
{ CALL
  return insertInternal(a_cIndex, &a_crItem, 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::insertIndex(const Tuint a_cIndex, const T_Type (&a_cpArray)[t_Size])
{ CALL
  return insertInternal(a_cIndex, a_cpArray, t_Size);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::insertIndex(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  return insertInternal(a_cIndex, a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::insertInternal(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize, TIterator* a_pIterator/* = NULL */)
{ CALL
  // Check buffer size.
  if (a_cSize == 0)
    return true;

  // Get left sparse array iterator.
  TIterator it_left = getItClosest(a_cIndex, true, false);
  // Get right sparse array iterator.
  TIterator it_right = it_left;
  if (!it_right.isValid())
    it_left = it_right = getItFirst();
  else if ((it_right == getItLast()) || (it_right.stepForward() == 0))
    it_right = TIterator();

  // Insert into the existent interval.
  if (it_left.isValid() && (((a_cIndex >= it_left.m_Iterator.getValueRef().getFirstIndex()) && (a_cIndex <= it_left.m_Iterator.getValueRef().getSecondIndex())) || (a_cIndex == (it_left.m_Iterator.getValueRef().getSecondIndex() + 1))))
  {
    it_left.m_Index = a_cIndex;
    // Create new sparse array value.
    NDetails::CSparseValue<T_Type> value = createSparseValue(it_left.m_Iterator.getValuePtr(), a_cIndex, a_cpBuffer, a_cSize);
    if (value.getBuffer() == NULL)
      return false;
    // Delete old left sparse value.
    if (!deleteSparseValue(it_left.m_Iterator.getValuePtr()))
    {
      deleteSparseValue(&value);
      return false;
    }
    // Update left sparse array value.
    NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>&, const NDetails::CSparseValue<T_Type>&>(it_left.m_Iterator.getValueRef()).set(value);
    m_Size += a_cSize;
    // Update sparse array indexes.
    TIterator it = it_right;
    while (it.m_Iterator.isValid())
    {
      NDetails::CSparseValue<T_Type>& temp = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>&, const NDetails::CSparseValue<T_Type>&>(it.m_Iterator.getValueRef());
      temp.set(temp.getFirstIndex() + a_cSize, temp.getSecondIndex() + a_cSize, temp.getBuffer());
      if ((it.m_Iterator == m_AssociativeContainer.getItLast()) || (it.m_Iterator.stepForward() == 0))
        break;
    }
    // Update result iterator.
    if (a_pIterator != NULL)
    {
      a_pIterator->m_pContainer = this;
      a_pIterator->m_Iterator = it_left.m_Iterator;
      a_pIterator->m_Index = a_cIndex;
    }
    return true;
  }
  else
  {
    // Create new sparse array value.
    NDetails::CSparseValue<T_Type> value = createSparseValue(a_cIndex, a_cpBuffer, a_cSize);
    if (value.getBuffer() == NULL)
      return false;
    // Update sparse array indexes.
    TIterator it = it_right;
    while (it.m_Iterator.isValid())
    {
      NDetails::CSparseValue<T_Type>& temp = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>&, const NDetails::CSparseValue<T_Type>&>(it.m_Iterator.getValueRef());
      temp.set(temp.getFirstIndex() + a_cSize, temp.getSecondIndex() + a_cSize, temp.getBuffer());
      if ((it.m_Iterator == m_AssociativeContainer.getItLast()) || (it.m_Iterator.stepForward() == 0))
        break;
    }
    // Insert new sparse value.
    if (!m_AssociativeContainer.insert(value))
    {
      deleteSparseValue(&value);
      return false;
    }
    m_Size += a_cSize;
    // Update result iterator.
    if (a_pIterator != NULL)
    {
      a_pIterator->m_pContainer = this;
      a_pIterator->m_Iterator = getItIndex(a_cIndex).m_Iterator;
      a_pIterator->m_Index = a_cIndex;
    }
    return true;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::removeFirst()
{ CALL
  return removeInternal(getFirstIndex(), 1, true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::removeFirst(T_Type& a_rItem)
{ CALL
  return removeInternal(getFirstIndex(), 1, true, &a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::removeLast()
{ CALL
  return removeInternal(getLastIndex(), 1, true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::removeLast(T_Type& a_rItem)
{ CALL
  return removeInternal(getLastIndex(), 1, true, &a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::removeIndex(const Tuint a_cIndex)
{ CALL
  return removeInternal(a_cIndex, 1, true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::removeIndex(const Tuint a_cIndex, T_Type& a_rItem)
{ CALL
  return removeInternal(a_cIndex, 1, true, &a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::remove(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  return removeInternal(a_cIndex, a_cSize, false);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::removeInternal(const Tuint a_cIndex, const Tuint a_cSize, const Tbool a_cCheck, T_Type* a_pItem/* = NULL */)
{ CALL
  // Check buffer size.
  if (a_cSize == 0)
    return true;

  Tuint first_index = a_cIndex;
  Tuint last_index = a_cIndex + a_cSize - 1;

  // Get left & right sparse array iterator.
  TIterator it_left = getItClosest(first_index);
  TIterator it_right = getItClosest(last_index);

  // Check for existence of value with given index.
  ASSERT((!a_cCheck || it_left.isValid()), STR("Item with given index must exist in the sparse array."))
  {
    return false;
  }

  // Store value with given index.
  if (it_left.isValid() && (a_pItem != NULL))
    *a_pItem = it_left.m_Iterator.getValueRef()[a_cIndex];

  // Get previous & next sparse array iterator.
  TIterator it_prev = getItClosest(first_index, true, false);
  TIterator it_next = getItClosest(last_index, false, true);
  // Update previous sparse array iterator.
  if (it_left.isValid() && it_prev.isValid() && (it_left.m_Iterator == it_prev.m_Iterator))
  {
    if ((it_prev.m_Iterator != m_AssociativeContainer.getItFirst()) && (it_prev.m_Iterator.stepBackward() > 0) && it_prev.m_Iterator.isValid())
      it_prev.m_Index = it_prev.m_Iterator.getValueRef().getSecondIndex();
    else
      it_prev = TIterator();
  }
  // Update next sparse array iterator.
  if (it_right.isValid() && it_next.isValid() && (it_right.m_Iterator == it_next.m_Iterator))
  {
    if ((it_next.m_Iterator != m_AssociativeContainer.getItLast()) && (it_next.m_Iterator.stepForward() > 0) && it_next.m_Iterator.isValid())
      it_next.m_Index = it_next.m_Iterator.getValueRef().getFirstIndex();
    else
      it_next = TIterator();
  }

  Tbool join_left = false;
  Tbool join_right = false;
  NDetails::CSparseValue<T_Type>* left_value = NULL;
  NDetails::CSparseValue<T_Type>* right_value = NULL;
  Tuint left_index = first_index;
  Tuint right_index = last_index;
  // Prepare left sparse value.
  if (it_left.isValid() && (it_left.m_Iterator.getValueRef().getFirstIndex() != first_index))
  {
    left_value = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>*, const NDetails::CSparseValue<T_Type>*>(it_left.m_Iterator.getValuePtr());
    left_index = first_index - 1;
  }
  if (!it_left.isValid() && it_prev.isValid() && ((it_prev.m_Iterator.getValueRef().getSecondIndex() + 1) == first_index))
  {
    join_left = true;
    left_value = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>*, const NDetails::CSparseValue<T_Type>*>(it_prev.m_Iterator.getValuePtr());
    left_index = first_index - 1;
  }
  // Prepare right sparse value.
  if (it_right.isValid() && (it_right.m_Iterator.getValueRef().getSecondIndex() != last_index))
  {
    right_value = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>*, const NDetails::CSparseValue<T_Type>*>(it_right.m_Iterator.getValuePtr());
    right_index = last_index + 1;
  }
  if (!it_right.isValid() && it_next.isValid() && ((it_next.m_Iterator.getValueRef().getFirstIndex() - 1) == last_index))
  {
    join_right = true;
    right_value = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>*, const NDetails::CSparseValue<T_Type>*>(it_next.m_Iterator.getValuePtr());
    right_index = last_index + 1;
  }
  // Correct sparse value.
  if ((left_value != NULL) && (right_value == NULL) && join_left)
  {
    left_value = NULL;
    left_index = first_index;
  }
  if ((left_value == NULL) && (right_value != NULL) && join_right)
  {
    right_value = NULL;
    right_index = last_index;
  }

  // Create new sparse array value.
  NDetails::CSparseValue<T_Type> value = createSparseValue(left_value, left_index, right_value, right_index);
  if ((value.getLength() > 0) && (value.getBuffer() == NULL))
    return false;

  // Find remove intervals.
  typename TAssociativeContainer::TIterator it_remove1;
  typename TAssociativeContainer::TIterator it_remove2;
  // Find left remove iterator.
  if (it_left.isValid())
    it_remove1 = it_left.m_Iterator;
  else
    if (left_value != NULL)
      it_remove1 = it_prev.m_Iterator;
    else
    {
      if (it_prev.isValid())
      {
        typename TAssociativeContainer::TIterator it_temp = it_prev.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItLast()) && (it_temp.stepForward() > 0))
          it_remove1 = it_temp;
      }
    }
  // Find right remove iterator.
  if (it_right.isValid())
    it_remove2 = it_right.m_Iterator;
  else
    if (right_value != NULL)
      it_remove2 = it_next.m_Iterator;
    else
    {
      if (it_next.isValid())
      {
        typename TAssociativeContainer::TIterator it_temp = it_next.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItFirst()) && (it_temp.stepBackward() > 0))
          it_remove2 = it_temp;
      }
    }

  // Find first iterator to update.
  typename TAssociativeContainer::TIterator it_update;
  if (it_remove2.isValid())
  {
    typename TAssociativeContainer::TIterator it_temp = it_remove2;
    if ((it_temp != m_AssociativeContainer.getItLast()) && (it_temp.stepForward() > 0))
      it_update = it_temp;
  }
  if (!it_left.isValid() && (it_next.m_Iterator == m_AssociativeContainer.getItFirst()))
    it_update = m_AssociativeContainer.getItFirst();

  // Remove iterators.
  if (it_remove1.isValid() || it_remove2.isValid() || (!it_left.isValid() && !it_prev.isValid() && !it_right.isValid() && !it_next.isValid()))
  {
    // Update remove iterators.
    if (!it_remove1.isValid())
      it_remove1 = m_AssociativeContainer.getItFirst();
    if (!it_remove2.isValid())
      it_remove2 = m_AssociativeContainer.getItLast();
    // Remove unnecessary span values.
    if (it_remove1.isValid() && it_remove2.isValid() && ((it_remove1 == it_remove2) || (it_remove1.getValueRef().getSecondIndex() < it_remove2.getValueRef().getFirstIndex())))
    {
      typename TAssociativeContainer::TIterator it_delete;
      typename TAssociativeContainer::TIterator it_temp = it_remove1;
      Tbool stop = false;
      while (!stop)
      {
        it_delete = it_temp;
        if ((it_temp == it_remove2) || (it_temp.stepForward() == 0))
          stop = true;
        NDetails::CSparseValue<T_Type> temp = it_delete.getValueRef();
        // Remove current sparse from container.
        if (!it_delete.remove())
        {
          deleteSparseValue(&temp);
          deleteSparseValue(&value);
          return false;
        }
        // Delete current sparse value.
        if (!deleteSparseValue(&temp))
        {
          deleteSparseValue(&value);
          return false;
        }
        m_Size -= temp.getSecondIndex() - temp.getFirstIndex() + 1;
      }
      if (value.getLength() > 0)
      {
        // Insert new sparse value.
        if (!m_AssociativeContainer.insert(value))
        {
          deleteSparseValue(&value);
          return false;
        }
        m_Size += value.getLength();
      }
    }
  }

  // Update sparse array indexes.
  while (it_update.isValid())
  {
    NDetails::CSparseValue<T_Type>& temp = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>&, const NDetails::CSparseValue<T_Type>&>(it_update.getValueRef());
    temp.set(temp.getFirstIndex() - a_cSize, temp.getSecondIndex() - a_cSize, temp.getBuffer());
    if ((it_update == m_AssociativeContainer.getItLast()) || (it_update.stepForward() == 0))
      break;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::fillFirst(const T_Type& a_crItem)
{ CALL
  return fillInternal(((getFirstIndex() > 0) ? (getFirstIndex() - 1) : 0), &a_crItem, 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::fillFirst(const T_Type (&a_cpArray)[t_Size])
{ CALL
  return fillInternal(((getFirstIndex() > 0) ? (getFirstIndex() - 1) : 0), a_cpArray, t_Size);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::fillFirst(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  return fillInternal(((getFirstIndex() > 0) ? (getFirstIndex() - 1) : 0), a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::fillLast(const T_Type& a_crItem)
{ CALL
  return fillInternal((isEmpty() ? 0 : (getLastIndex() + 1)), &a_crItem, 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::fillLast(const T_Type (&a_cpArray)[t_Size])
{ CALL
  return fillInternal((isEmpty() ? 0 : (getLastIndex() + 1)), a_cpArray, t_Size);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::fillLast(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  return fillInternal((isEmpty() ? 0 : (getLastIndex() + 1)), a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::fillIndex(const Tuint a_cIndex, const T_Type& a_crItem)
{ CALL
  return fillInternal(a_cIndex, &a_crItem, 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::fillIndex(const Tuint a_cIndex, const T_Type (&a_cpArray)[t_Size])
{ CALL
  return fillInternal(a_cIndex, a_cpArray, t_Size);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::fillIndex(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  return fillInternal(a_cIndex, a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::fillInternal(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Check buffer size.
  if (a_cSize == 0)
    return true;

  Tuint first_index = a_cIndex;
  Tuint last_index = a_cIndex + a_cSize - 1;

  // Get left & right sparse array iterator.
  TIterator it_left = getItClosest(first_index);
  TIterator it_right = getItClosest(last_index);

  // Get previous & next sparse array iterator.
  TIterator it_prev = getItClosest(first_index, true, false);
  TIterator it_next = getItClosest(last_index, false, true);
  // Update previous sparse array iterator.
  if (it_left.isValid() && it_prev.isValid() && (it_left.m_Iterator == it_prev.m_Iterator))
  {
    if ((it_prev.m_Iterator != m_AssociativeContainer.getItFirst()) && (it_prev.m_Iterator.stepBackward() > 0) && it_prev.m_Iterator.isValid())
      it_prev.m_Index = it_prev.m_Iterator.getValueRef().getSecondIndex();
    else
      it_prev = TIterator();
  }
  // Update next sparse array iterator.
  if (it_right.isValid() && it_next.isValid() && (it_right.m_Iterator == it_next.m_Iterator))
  {
    if ((it_next.m_Iterator != m_AssociativeContainer.getItLast()) && (it_next.m_Iterator.stepForward() > 0) && it_next.m_Iterator.isValid())
      it_next.m_Index = it_next.m_Iterator.getValueRef().getFirstIndex();
    else
      it_next = TIterator();
  }

  Tbool join_left = false;
  Tbool join_right = false;
  NDetails::CSparseValue<T_Type>* left_value = NULL;
  NDetails::CSparseValue<T_Type>* right_value = NULL;
  Tuint left_index = first_index;
  Tuint right_index = last_index;
  // Prepare left sparse value.
  if (it_left.isValid() && (it_left.m_Iterator.getValueRef().getFirstIndex() != first_index))
  {
    left_value = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>*, const NDetails::CSparseValue<T_Type>*>(it_left.m_Iterator.getValuePtr());
    left_index = first_index - 1;
  }
  if (!it_left.isValid() && it_prev.isValid() && ((it_prev.m_Iterator.getValueRef().getSecondIndex() + 1) == first_index))
  {
    join_left = true;
    left_value = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>*, const NDetails::CSparseValue<T_Type>*>(it_prev.m_Iterator.getValuePtr());
    left_index = first_index - 1;
  }
  // Prepare right sparse value.
  if (it_right.isValid() && (it_right.m_Iterator.getValueRef().getSecondIndex() != last_index))
  {
    right_value = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>*, const NDetails::CSparseValue<T_Type>*>(it_right.m_Iterator.getValuePtr());
    right_index = last_index + 1;
  }
  if (!it_right.isValid() && it_next.isValid() && ((it_next.m_Iterator.getValueRef().getFirstIndex() - 1) == last_index))
  {
    join_right = true;
    right_value = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>*, const NDetails::CSparseValue<T_Type>*>(it_next.m_Iterator.getValuePtr());
    right_index = last_index + 1;
  }

  // Create new sparse array value.
  NDetails::CSparseValue<T_Type> value = createSparseValue(left_value, left_index, right_value, right_index, a_cIndex, a_cpBuffer, a_cSize);
  if ((value.getLength() > 0) && (value.getBuffer() == NULL))
    return false;

  // Find remove intervals.
  typename TAssociativeContainer::TIterator it_remove1;
  typename TAssociativeContainer::TIterator it_remove2;
  // Find left remove iterator.
  if (it_left.isValid())
    it_remove1 = it_left.m_Iterator;
  else
    if (left_value != NULL)
      it_remove1 = it_prev.m_Iterator;
    else
    {
      if (it_prev.isValid())
      {
        typename TAssociativeContainer::TIterator it_temp = it_prev.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItLast()) && (it_temp.stepForward() > 0))
          it_remove1 = it_temp;
      }
    }
  // Find right remove iterator.
  if (it_right.isValid())
    it_remove2 = it_right.m_Iterator;
  else
    if (right_value != NULL)
      it_remove2 = it_next.m_Iterator;
    else
    {
      if (it_next.isValid())
      {
        typename TAssociativeContainer::TIterator it_temp = it_next.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItFirst()) && (it_temp.stepBackward() > 0))
          it_remove2 = it_temp;
      }
    }

  // Remove iterators.
  if ((!it_remove1.isValid() && it_remove2.isValid()) || (it_remove1.isValid() && !it_remove2.isValid()) || (it_remove1.isValid() && it_remove2.isValid() && ((it_remove1 == it_remove2) || (it_remove1.getValueRef().getSecondIndex() < it_remove2.getValueRef().getFirstIndex()))) || (!isEmpty() && !it_left.isValid() && !it_prev.isValid() && !it_right.isValid() && !it_next.isValid()))
  {
    // Update remove iterators.
    if (!it_remove1.isValid())
      it_remove1 = m_AssociativeContainer.getItFirst();
    if (!it_remove2.isValid())
      it_remove2 = m_AssociativeContainer.getItLast();
    // Remove unnecessary span values.
    if (it_remove1.isValid() && it_remove2.isValid())
    {
      if (it_remove1 != it_remove2)
      {
        typename TAssociativeContainer::TIterator it_delete;
        typename TAssociativeContainer::TIterator it_temp = it_remove1;
        // Step forward for one item.
        if (it_temp.stepForward() > 0)
        {
          Tbool stop = false;
          while (!stop)
          {
            it_delete = it_temp;
            if ((it_temp == it_remove2) || (it_temp.stepForward() == 0))
              stop = true;
            NDetails::CSparseValue<T_Type> temp = it_delete.getValueRef();
            // Remove current sparse from container.
            if (!it_delete.remove())
            {
              deleteSparseValue(&temp);
              deleteSparseValue(&value);
              return false;
            }
            // Delete current sparse value.
            if (!deleteSparseValue(&temp))
            {
              deleteSparseValue(&value);
              return false;
            }
            m_Size -= temp.getSecondIndex() - temp.getFirstIndex() + 1;
          }
        }
      }
      // Update sparse value by inserting new interval.
      m_Size -= it_remove1.getValueRef().getLength();
      if (!deleteSparseValue(it_remove1.getValuePtr()))
      {
        deleteSparseValue(&value);
        return false;
      }
      (NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>&, const NDetails::CSparseValue<T_Type>&>(it_remove1.getValueRef())).set(value);
      m_Size += it_remove1.getValueRef().getLength();
    }
  }
  else
  {
    // Insert new interval.
    if (!m_AssociativeContainer.insert(value))
    {
      deleteSparseValue(&value);
      return false;
    }
    m_Size += value.getLength();
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::eraseFirst()
{ CALL
  return eraseInternal(getFirstIndex(), 1, true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::eraseFirst(T_Type& a_rItem)
{ CALL
  return eraseInternal(getFirstIndex(), 1, true, &a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::eraseLast()
{ CALL
  return eraseInternal(getLastIndex(), 1, true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::eraseLast(T_Type& a_rItem)
{ CALL
  return eraseInternal(getLastIndex(), 1, true, &a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::eraseIndex(const Tuint a_cIndex)
{ CALL
  return eraseInternal(a_cIndex, 1, true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::eraseIndex(const Tuint a_cIndex, T_Type& a_rItem)
{ CALL
  return eraseInternal(a_cIndex, 1, true, &a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::erase(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  return eraseInternal(a_cIndex, a_cSize, false);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::eraseInternal(const Tuint a_cIndex, const Tuint a_cSize, const Tbool a_cCheck, T_Type* a_pItem/* = NULL */)
{ CALL
  // Check buffer size.
  if (a_cSize == 0)
    return true;

  Tuint first_index = a_cIndex;
  Tuint last_index = a_cIndex + a_cSize - 1;

  // Get left & right sparse array iterator.
  TIterator it_left = getItClosest(first_index);
  TIterator it_right = getItClosest(last_index);

  // Check for existence of value with given index.
  ASSERT((!a_cCheck || it_left.isValid()), STR("Item with given index must exist in the sparse array."))
  {
    return false;
  }

  // Store value with given index.
  if (it_left.isValid() && (a_pItem != NULL))
    *a_pItem = it_left.m_Iterator.getValueRef()[a_cIndex];

  // Get previous & next sparse array iterator.
  TIterator it_prev = getItClosest(first_index, true, false);
  TIterator it_next = getItClosest(last_index, false, true);
  // Update previous sparse array iterator.
  if (it_left.isValid() && it_prev.isValid() && (it_left.m_Iterator == it_prev.m_Iterator))
  {
    if ((it_prev.m_Iterator != m_AssociativeContainer.getItFirst()) && (it_prev.m_Iterator.stepBackward() > 0) && it_prev.m_Iterator.isValid())
      it_prev.m_Index = it_prev.m_Iterator.getValueRef().getSecondIndex();
    else
      it_prev = TIterator();
  }
  // Update next sparse array iterator.
  if (it_right.isValid() && it_next.isValid() && (it_right.m_Iterator == it_next.m_Iterator))
  {
    if ((it_next.m_Iterator != m_AssociativeContainer.getItLast()) && (it_next.m_Iterator.stepForward() > 0) && it_next.m_Iterator.isValid())
      it_next.m_Index = it_next.m_Iterator.getValueRef().getFirstIndex();
    else
      it_next = TIterator();
  }

  NDetails::CSparseValue<T_Type>* temp_value = NULL;
  NDetails::CSparseValue<T_Type>* left_value = NULL;
  NDetails::CSparseValue<T_Type>* right_value = NULL;
  Tuint left_index = first_index;
  Tuint right_index = last_index;
  // Prepare left sparse value.
  if (it_left.isValid() && (it_left.m_Iterator.getValueRef().getFirstIndex() != first_index))
  {
    left_value = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>*, const NDetails::CSparseValue<T_Type>*>(it_left.m_Iterator.getValuePtr());
    left_index = first_index - 1;
  }
  // Prepare right sparse value.
  if (it_right.isValid() && (it_right.m_Iterator.getValueRef().getSecondIndex() != last_index))
  {
    right_value = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>*, const NDetails::CSparseValue<T_Type>*>(it_right.m_Iterator.getValuePtr());
    right_index = last_index + 1;
  }

  // Create left sparse array value.
  NDetails::CSparseValue<T_Type> left_span_value = createSparseValue(left_value, left_index, temp_value, left_index);
  if ((left_span_value.getLength() > 0) && (left_span_value.getBuffer() == NULL))
    return false;
  // Create right sparse array value.
  NDetails::CSparseValue<T_Type> right_span_value = createSparseValue(temp_value, right_index, right_value, right_index);
  if ((right_span_value.getLength() > 0) && (right_span_value.getBuffer() == NULL))
    return false;

  // Find remove intervals.
  typename TAssociativeContainer::TIterator it_remove1;
  typename TAssociativeContainer::TIterator it_remove2;
  // Find left remove iterator.
  if (it_left.isValid())
    it_remove1 = it_left.m_Iterator;
  else
    if (left_value != NULL)
      it_remove1 = it_prev.m_Iterator;
    else
    {
      if (it_prev.isValid())
      {
        typename TAssociativeContainer::TIterator it_temp = it_prev.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItLast()) && (it_temp.stepForward() > 0))
          it_remove1 = it_temp;
      }
    }
  // Find right remove iterator.
  if (it_right.isValid())
    it_remove2 = it_right.m_Iterator;
  else
    if (right_value != NULL)
      it_remove2 = it_next.m_Iterator;
    else
    {
      if (it_next.isValid())
      {
        typename TAssociativeContainer::TIterator it_temp = it_next.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItFirst()) && (it_temp.stepBackward() > 0))
          it_remove2 = it_temp;
      }
    }

  // Remove iterators.
  if (it_remove1.isValid() || it_remove2.isValid() || (!it_left.isValid() && !it_prev.isValid() && !it_right.isValid() && !it_next.isValid()))
  {
    // Update remove iterators.
    if (!it_remove1.isValid())
      it_remove1 = m_AssociativeContainer.getItFirst();
    if (!it_remove2.isValid())
      it_remove2 = m_AssociativeContainer.getItLast();
    // Remove unnecessary span values.
    if (it_remove1.isValid() && it_remove2.isValid() && ((it_remove1 == it_remove2) || (it_remove1.getValueRef().getSecondIndex() < it_remove2.getValueRef().getFirstIndex())))
    {
      typename TAssociativeContainer::TIterator it_delete;
      typename TAssociativeContainer::TIterator it_temp = it_remove1;
      Tbool stop = false;
      while (!stop)
      {
        it_delete = it_temp;
        if ((it_temp == it_remove2) || (it_temp.stepForward() == 0))
          stop = true;
        NDetails::CSparseValue<T_Type> temp = it_delete.getValueRef();
        // Remove current sparse from container.
        if (!it_delete.remove())
        {
          deleteSparseValue(&temp);
          deleteSparseValue(&left_span_value);
          deleteSparseValue(&right_span_value);
          return false;
        }
        // Delete current sparse value.
        if (!deleteSparseValue(&temp))
        {
          deleteSparseValue(&left_span_value);
          deleteSparseValue(&right_span_value);
          return false;
        }
        m_Size -= temp.getSecondIndex() - temp.getFirstIndex() + 1;
      }
      if (left_span_value.getLength() > 0)
      {
        // Insert left sparse value.
        if (!m_AssociativeContainer.insert(left_span_value))
        {
          deleteSparseValue(&left_span_value);
          deleteSparseValue(&right_span_value);
          return false;
        }
        m_Size += left_span_value.getLength();
      }
      if (right_span_value.getLength() > 0)
      {
        // Insert right sparse value.
        if (!m_AssociativeContainer.insert(right_span_value))
        {
          deleteSparseValue(&right_span_value);
          return false;
        }
        m_Size += right_span_value.getLength();
      }
    }
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::TIterator CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::getItFirst()
{ CALL
  TIterator first_iterator;

  // Filling iterator inner structure.
  first_iterator.m_pContainer = this;
  first_iterator.m_Iterator = m_AssociativeContainer.getItFirst();
  first_iterator.m_Index = (first_iterator.m_Iterator.isValid() ? first_iterator.m_Iterator.getValueRef().getFirstIndex() : 0);
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::TIteratorConst CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::getItFirst() const
{ CALL
  TIteratorConst first_iterator;

  // Filling iterator inner structure.
  first_iterator.m_cpContainer = this;
  first_iterator.m_Iterator = m_AssociativeContainer.getItFirst();
  first_iterator.m_Index = (first_iterator.m_Iterator.isValid() ? first_iterator.m_Iterator.getValueRef().getFirstIndex() : 0);
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::TIterator CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::getItLast()
{ CALL
  TIterator last_iterator;

  // Filling iterator inner structure.
  last_iterator.m_pContainer = this;
  last_iterator.m_Iterator = m_AssociativeContainer.getItLast();
  last_iterator.m_Index = (last_iterator.m_Iterator.isValid() ? last_iterator.m_Iterator.getValueRef().getSecondIndex() : 0);
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::TIteratorConst CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::getItLast() const
{ CALL
  TIteratorConst last_iterator;

  // Filling iterator inner structure.
  last_iterator.m_cpContainer = this;
  last_iterator.m_Iterator = m_AssociativeContainer.getItLast();
  last_iterator.m_Index = (last_iterator.m_Iterator.isValid() ? last_iterator.m_Iterator.getValueRef().getSecondIndex() : 0);
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::TIterator CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::getItIndex(const Tuint a_cIndex)
{ CALL
  return getItClosest(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::TIteratorConst CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::getItIndex(const Tuint a_cIndex) const
{ CALL
  return getItClosest(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::TIterator CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::getItClosest(const Tuint a_cIndex, const Tbool a_cLeft/* = false */, const Tbool a_cRight/* = false */)
{ CALL
  // Check for valid sparse array value bounds.
  ASSERT(!(a_cLeft && a_cRight), STR("Closest sparse array value can be found only for left or right bound."))
  {
    return TIterator();
  }

  TIterator it;

  // Filling iterator inner structure.
  it.m_pContainer = this;
  it.m_Index = a_cIndex;
  it.m_Iterator = NAlgorithms::NContainers::lowerBound(m_AssociativeContainer, NDetails::CSparseValue<T_Type>(a_cIndex, a_cIndex, NULL), NFunctors::CFunctor<Tbool (const NDetails::CSparseValue<T_Type>&, const NDetails::CSparseValue<T_Type>&)>(m_AssociativeContainer, &TAssociativeContainer::isLessThan));
  if (!it.m_Iterator.isValid())
    it.m_Iterator = m_AssociativeContainer.getItLast();
  // Update iterator bounds.
  if (it.m_Iterator.isValid())
  {
    // Special check for a single value.
    if (!a_cLeft && !a_cRight)
    {
      if (a_cIndex < it.m_Iterator.getValueRef().getFirstIndex())
      {
        // Check previous sparse array value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if (it_temp == m_AssociativeContainer.getItFirst() || (it_temp.stepBackward() == 0) || (it_temp.getValueRef().getSecondIndex() < a_cIndex))
          it.m_Iterator = typename TAssociativeContainer::TIterator();
        else
          it.m_Iterator = it_temp;
      }
      else if (it.m_Iterator.getValueRef().getSecondIndex() < a_cIndex)
      {
        // Check next sparse array value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if ((it_temp == m_AssociativeContainer.getItLast()) || (it_temp.stepForward() == 0) || (a_cIndex < it_temp.getValueRef().getFirstIndex()))
          it.m_Iterator = typename TAssociativeContainer::TIterator();
        else
          it.m_Iterator = it_temp;
      }
      it.m_Index = a_cIndex;
    }
    // Special check for a left bound sparse array value.
    if (a_cLeft)
    {
      if (a_cIndex < it.m_Iterator.getValueRef().getFirstIndex())
      {
        // Check previous sparse array value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if (it_temp == m_AssociativeContainer.getItFirst() || (it_temp.stepBackward() == 0))
          it.m_Iterator = typename TAssociativeContainer::TIterator();
        else
          it.m_Iterator = it_temp;
      }
      else
      {
        // Check previous sparse array value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItFirst()) && (it_temp.stepBackward() > 0))
          if (a_cIndex == it_temp.getValueRef().getSecondIndex())
            it.m_Iterator = it_temp;
      }
      it.m_Index = (it.m_Iterator.isValid() ? it.m_Iterator.getValueRef().getSecondIndex() : 0);
    }
    // Special check for a right bound sparse array value.
    if (a_cRight)
    {
      if (it.m_Iterator.getValueRef().getSecondIndex() < a_cIndex)
      {
        // Check next sparse array value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if ((it_temp == m_AssociativeContainer.getItLast()) || (it_temp.stepForward() == 0))
          it.m_Iterator = typename TAssociativeContainer::TIterator();
        else
          it.m_Iterator = it_temp;
      }
      else if (a_cIndex < it.m_Iterator.getValueRef().getFirstIndex())
      {
        // Check previous sparse array value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItFirst()) && (it_temp.stepBackward() > 0))
          if (a_cIndex <= it_temp.getValueRef().getSecondIndex())
            it.m_Iterator = it_temp;
      }
      it.m_Index = (it.m_Iterator.isValid() ? it.m_Iterator.getValueRef().getFirstIndex() : 0);
    }
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::TIteratorConst CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::getItClosest(const Tuint a_cIndex, const Tbool a_cLeft/* = false */, const Tbool a_cRight/* = false */) const
{ CALL
  // Check for valid sparse array value bounds.
  ASSERT(!(a_cLeft && a_cRight), STR("Closest sparse array value can be found only for left or right bound."))
  {
    return TIteratorConst();
  }

  TIteratorConst it;

  // Filling iterator inner structure.
  it.m_cpContainer = this;
  it.m_Index = a_cIndex;
  it.m_Iterator = NAlgorithms::NContainers::lowerBound(m_AssociativeContainer, NDetails::CSparseValue<T_Type>(a_cIndex, a_cIndex, NULL), NFunctors::CFunctor<Tbool (const NDetails::CSparseValue<T_Type>&, const NDetails::CSparseValue<T_Type>&)>(m_AssociativeContainer, &TAssociativeContainer::isLessThan));
  if (!it.m_Iterator.isValid())
    it.m_Iterator = m_AssociativeContainer.getItLast();
  // Update iterator bounds.
  if (it.m_Iterator.isValid())
  {
    // Special check for a single value.
    if (!a_cLeft && !a_cRight)
    {
      if (a_cIndex < it.m_Iterator.getValueRef().getFirstIndex())
      {
        // Check previous sparse array value.
        typename TAssociativeContainer::TIteratorConst it_temp = it.m_Iterator;
        if (it_temp == m_AssociativeContainer.getItFirst() || (it_temp.stepBackward() == 0) || (it_temp.getValueRef().getSecondIndex() < a_cIndex))
          it.m_Iterator = typename TAssociativeContainer::TIteratorConst();
        else
          it.m_Iterator = it_temp;
      }
      else if (it.m_Iterator.getValueRef().getSecondIndex() < a_cIndex)
      {
        // Check next sparse array value.
        typename TAssociativeContainer::TIteratorConst it_temp = it.m_Iterator;
        if ((it_temp == m_AssociativeContainer.getItLast()) || (it_temp.stepForward() == 0) || (a_cIndex < it_temp.getValueRef().getFirstIndex()))
          it.m_Iterator = typename TAssociativeContainer::TIteratorConst();
        else
          it.m_Iterator = it_temp;
      }
      it.m_Index = a_cIndex;
    }
    // Special check for a left bound sparse array value.
    if (a_cLeft)
    {
      if (a_cIndex < it.m_Iterator.getValueRef().getFirstIndex())
      {
        // Check previous sparse array value.
        typename TAssociativeContainer::TIteratorConst it_temp = it.m_Iterator;
        if (it_temp == m_AssociativeContainer.getItFirst() || (it_temp.stepBackward() == 0))
          it.m_Iterator = typename TAssociativeContainer::TIteratorConst();
        else
          it.m_Iterator = it_temp;
      }
      else
      {
        // Check previous sparse array value.
        typename TAssociativeContainer::TIteratorConst it_temp = it.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItFirst()) && (it_temp.stepBackward() > 0))
          if (a_cIndex == it_temp.getValueRef().getSecondIndex())
            it.m_Iterator = it_temp;
      }
      it.m_Index = (it.m_Iterator.isValid() ? it.m_Iterator.getValueRef().getSecondIndex() : 0);
    }
    // Special check for a right bound sparse array value.
    if (a_cRight)
    {
      if (it.m_Iterator.getValueRef().getSecondIndex() < a_cIndex)
      {
        // Check next sparse array value.
        typename TAssociativeContainer::TIteratorConst it_temp = it.m_Iterator;
        if ((it_temp == m_AssociativeContainer.getItLast()) || (it_temp.stepForward() == 0))
          it.m_Iterator = typename TAssociativeContainer::TIteratorConst();
        else
          it.m_Iterator = it_temp;
      }
      else if (a_cIndex < it.m_Iterator.getValueRef().getFirstIndex())
      {
        // Check previous sparse array value.
        typename TAssociativeContainer::TIteratorConst it_temp = it.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItFirst()) && (it_temp.stepBackward() > 0))
          if (a_cIndex <= it_temp.getValueRef().getSecondIndex())
            it.m_Iterator = it_temp;
      }
      it.m_Index = (it.m_Iterator.isValid() ? it.m_Iterator.getValueRef().getFirstIndex() : 0);
    }
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline NDetails::CSparseValue<T_Type> CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::createSparseValue(const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  NDetails::CSparseValue<T_Type> result(a_cIndex, a_cIndex + a_cSize - 1, NULL);
  result.set(result.getFirstIndex(), result.getSecondIndex(), m_Allocator.template createMany<T_Type>(result.getSecondIndex() - result.getFirstIndex() + 1));
  if (result.getBuffer() != NULL)
  {
    if (a_cpBuffer != NULL)
    {
      for (Tuint i = 0; i < a_cSize; ++i)
        result[i + a_cIndex] = a_cpBuffer[i];
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline NDetails::CSparseValue<T_Type> CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::createSparseValue(const NDetails::CSparseValue<T_Type>* a_cpSparseValue, const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Check for sparse array value pointer.
  ASSERT((a_cpSparseValue != NULL), STR("Pointer to the base sparse array value should not be NULL."))
  {
    return NDetails::CSparseValue<T_Type>();
  }
  // Check for valid sparse array value.
  ASSERT(a_cpSparseValue->isValid(), STR("Base sparse array value should be valid."))
  {
    return NDetails::CSparseValue<T_Type>();
  }

  NDetails::CSparseValue<T_Type> result(a_cpSparseValue->getFirstIndex(), a_cpSparseValue->getSecondIndex() + a_cSize, NULL);
  result.set(result.getFirstIndex(), result.getSecondIndex(), m_Allocator.template createMany<T_Type>(result.getSecondIndex() - result.getFirstIndex() + 1));
  if (result.getBuffer() != NULL)
  {
    for (Tuint i = result.getFirstIndex(); i < a_cIndex; ++i)
      result[i] = (*a_cpSparseValue)[i];
    if (a_cpBuffer != NULL)
    {
      for (Tuint i = 0; i < a_cSize; ++i)
        result[i + a_cIndex] = a_cpBuffer[i];
    }
    for (Tuint i = a_cIndex; i <= a_cpSparseValue->getSecondIndex(); ++i)
      result[i + a_cSize] = (*a_cpSparseValue)[i];
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline NDetails::CSparseValue<T_Type> CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::createSparseValue(const NDetails::CSparseValue<T_Type>* a_cpLeftSparseValue, const Tuint a_cLeftIndex, const NDetails::CSparseValue<T_Type>* a_cpRightSparseValue, const Tuint a_cRightIndex)
{ CALL
  Tuint length = 0;
  Tuint size = a_cRightIndex - a_cLeftIndex;
  Tuint first_index = 0;
  Tuint last_index = 0;

  // Setup first index.
  if (a_cpLeftSparseValue != NULL)
  {
    first_index = a_cpLeftSparseValue->getFirstIndex();
    if (a_cpRightSparseValue == NULL)
    {
      size = a_cLeftIndex - a_cpLeftSparseValue->getFirstIndex() + 1;
      last_index = a_cLeftIndex;
    }
    length += a_cLeftIndex - a_cpLeftSparseValue->getFirstIndex() + 1;
  }
  // Setup last index.
  if (a_cpRightSparseValue != NULL)
  {
    if (a_cpLeftSparseValue == NULL)
    {
      size = a_cRightIndex - a_cLeftIndex + 1;
      first_index = a_cRightIndex - size + 1;
    }
    last_index = a_cpRightSparseValue->getSecondIndex() - size + 1;
    length += a_cpRightSparseValue->getSecondIndex() - a_cRightIndex + 1;
  }

  // Check length of a new sparse value.
  if (length == 0)
    return NDetails::CSparseValue<T_Type>();

  // Create sparse value.
  NDetails::CSparseValue<T_Type> result(first_index, last_index, NULL);
  result.set(result.getFirstIndex(), result.getSecondIndex(), m_Allocator.template createMany<T_Type>(result.getSecondIndex() - result.getFirstIndex() + 1));
  if (result.getBuffer() != NULL)
  {
    if (a_cpLeftSparseValue != NULL)
    {
      for (Tuint i = a_cpLeftSparseValue->getFirstIndex(); i <= a_cLeftIndex; ++i)
        result[i] = (*a_cpLeftSparseValue)[i];
    }
    if (a_cpRightSparseValue != NULL)
    {
      for (Tuint i = a_cRightIndex; i <= a_cpRightSparseValue->getSecondIndex(); ++i)
        result[i - size + 1] = (*a_cpRightSparseValue)[i];
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline NDetails::CSparseValue<T_Type> CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::createSparseValue(const NDetails::CSparseValue<T_Type>* a_cpLeftSparseValue, const Tuint a_cLeftIndex, const NDetails::CSparseValue<T_Type>* a_cpRightSparseValue, const Tuint a_cRightIndex, const Tuint a_cIndex, const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  Tuint first_index = (a_cpLeftSparseValue != NULL) ? a_cpLeftSparseValue->getFirstIndex() : a_cIndex;
  Tuint last_index = (a_cpRightSparseValue != NULL) ? a_cpRightSparseValue->getSecondIndex() : (a_cIndex + a_cSize - 1);

  // Create sparse value.
  NDetails::CSparseValue<T_Type> result(first_index, last_index, NULL);
  result.set(result.getFirstIndex(), result.getSecondIndex(), m_Allocator.template createMany<T_Type>(result.getSecondIndex() - result.getFirstIndex() + 1));
  if (result.getBuffer() != NULL)
  {
    if (a_cpLeftSparseValue != NULL)
    {
      for (Tuint i = a_cpLeftSparseValue->getFirstIndex(); i <= a_cLeftIndex; ++i)
        result[i] = (*a_cpLeftSparseValue)[i];
    }
    if (a_cpBuffer != NULL)
    {
      for (Tuint i = 0; i < a_cSize; ++i)
        result[i + a_cIndex] = a_cpBuffer[i];
    }
    if (a_cpRightSparseValue != NULL)
    {
      for (Tuint i = a_cRightIndex; i <= a_cpRightSparseValue->getSecondIndex(); ++i)
        result[i] = (*a_cpRightSparseValue)[i];
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::deleteSparseValue(const NDetails::CSparseValue<T_Type>* a_cpSparseValue)
{ CALL
  // Check for sparse array value pointer.
  ASSERT((a_cpSparseValue != NULL), STR("Pointer to the deleted sparse array value should not be NULL."))
  {
    return false;
  }
  // Check for valid sparse array value.
  ASSERT(a_cpSparseValue->isValid(), STR("Deleting sparse array value should be valid."))
  {
    return false;
  }

  // Delete sparse value interval.
  NDetails::CSparseValue<T_Type>* temp = NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>*, const NDetails::CSparseValue<T_Type>*>(a_cpSparseValue);
  T_Type* buffer = temp->getBuffer();
  Tuint length = temp->getLength();
  if (!m_Allocator.deleteMany(buffer, length))
  {
    WARNING(STR("Cannot delete sparse array buffer (requested size is %u bytes).") COMMA (sizeof(T_Type) * length));
    return false;
  }
  temp->set(temp->getFirstIndex(), temp->getSecondIndex(), NULL);
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;
  Tuint intervals = 0;

  // Clear the current sparse array.
  CHECK(clear());

  // Load the sparse array header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
    CHECK(a_rArchive.doProperty(intervals, STR("intervals")));
  CHECK(a_rArchive.body());

  // Load the sparse array intervals.
  while (intervals-- > 0)
  {
    Tuint interval = 0;
    Tuint offset = 0;

    // Load next sparse array interval size.
    CHECK(a_rArchive.doValue(interval, STR("interval")));
    // Load next sparse array interval offset.
    CHECK(a_rArchive.doValue(offset, STR("offset")));
    // Insert sparse array interval.
    CHECK(insertInternal(offset, NULL, interval));
    // Load next sparse array interval items.
    TIterator it = getItIndex(offset);
    while (interval-- > 0)
    {
      // Load next sparse array item.
      CHECK(a_rArchive.doValue(NAlgorithms::NCommon::constCast<NDetails::CSparseValue<T_Type>&, const NDetails::CSparseValue<T_Type>&>(it.m_Iterator.getValueRef())[offset], STR("item[%u]") COMMA (offset)));
      ++offset;
    }
  }

  // Load the sparse array end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the sparse array header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
    CHECK(a_rArchive.doProperty(m_AssociativeContainer.getSize(), STR("intervals")));
  CHECK(a_rArchive.body());

  // Save the sparse array content.
  if (!isEmpty())
  {
    typename TAssociativeContainer::TIteratorConst it_first = m_AssociativeContainer.getItFirst();
    typename TAssociativeContainer::TIteratorConst it_current = it_first;

    // Save all sparse array intervals.
    while (it_current.isValid())
    {
      Tuint index;
      Tuint interval = it_current.getValueRef().getLength();
      Tuint offset = it_current.getValueRef().getFirstIndex();

      // Save next sparse array interval size.
      CHECK(a_rArchive.doValue(interval, STR("interval")));
      // Save next sparse array interval offset.
      CHECK(a_rArchive.doValue(offset, STR("offset")));
      // Save next sparse array interval items.
      index = offset;
      while (index < (interval + offset))
      {
        CHECK(a_rArchive.doValue(it_current.getValueRef()[index], STR("item[%u]") COMMA (index)));
        ++index;
      }
      // Switch to the next sparse array interval.
      if ((it_current.stepForward() == 0) || (it_current == it_first))
        break;
    }
  }

  // Save the sparse array end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>::swap(CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
  NAlgorithms::NCommon::swap(m_AssociativeContainer, a_rInstance.m_AssociativeContainer);
  NAlgorithms::NCommon::swap(m_Allocator, a_rInstance.m_Allocator);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
