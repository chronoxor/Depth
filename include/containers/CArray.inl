/*!
 *  \file    CArray.inl Template array container class. Array represents a
 *           random access container.
 *  \brief   Template array container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template array container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   31.03.2006 02:11:31

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
#ifndef __CARRAY_INL__
#define __CARRAY_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArray(const Tuint a_cSize/* = 0 */, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  m_Size(0),
  m_pData(NULL),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL
  resize(a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArray(const T_Type& a_crValue, const Tuint a_cSize, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  m_Size(0),
  m_pData(NULL),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL
  resize(a_cSize, a_crValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <Tuint t_Size>
inline CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArray(const T_Type (&a_cpArray)[t_Size], const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  m_Size(0),
  m_pData(NULL),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_cpArray);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArray(const T_Type a_cpBuffer[], const Tuint a_cSize, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  m_Size(0),
  m_pData(NULL),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArray(const CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CArrayIterator<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  m_Size(0),
  m_pData(NULL),
  m_ResizePolicy(),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::~CArray()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <Tuint t_Size>
inline CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator = (const T_Type (&a_cpArray)[t_Size])
{ CALL
  set(a_cpArray);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator = (const CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline T_Type& CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tsint a_cIndex)
{ CALL
  // Verify index value and the array bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline T_Type& CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tuint a_cIndex)
{ CALL
  // Verify index value and the array bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const T_Type& CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tsint a_cIndex) const
{ CALL
  // Verify index value and the array bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const T_Type& CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tuint a_cIndex) const
{ CALL
  // Verify index value and the array bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator T_Type* ()
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator const T_Type* () const
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <Tuint t_Size>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const T_Type (&a_cpArray)[t_Size])
{ CALL
  return set(a_cpArray, t_Size);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Clear current array.
  if (!clear())
    return false;

  // Resize array to fit the given one.
  if (resize(a_cSize))
  {
    // Copy array's buffer.
    T_CopyPolicy::copy(m_pData, a_cpBuffer, a_cSize);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CArray class instance."))
  {
    return false;
  }

  // Copy resize policy.
  m_ResizePolicy.set(a_crInstance.m_ResizePolicy);
  // Copy array's buffer.
  return set(a_crInstance.m_pData, a_crInstance.m_Size);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getFreeSize() const
{ CALL
  return (getHiCapacity() - getSize());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getLoCapacity() const
{ CALL
  return m_ResizePolicy.getLoCapacity();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getHiCapacity() const
{ CALL
  return m_ResizePolicy.getHiCapacity();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline T_Type* CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getBuffer()
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const T_Type* CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getBuffer() const
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getResizeFactor() const
{ CALL
  return m_ResizePolicy.getResizeFactor();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::setResizeFactor(const Tuint a_cResizeFactor)
{ CALL
  return m_ResizePolicy.setResizeFactor(a_cResizeFactor);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::clear()
{ CALL
  // Delete memory buffer.
  if (m_pData != NULL)
  {
    // Destroy array's items.
    if (!m_Allocator.destroyMany(m_pData, m_Size))
    {
      WARNING(STR("Cannot destroy array's items while clearing the array (requested size is %u bytes).") COMMA (sizeof(T_Type) * m_Size));
      return false;
    }
    // Free array's buffer.
    if (!m_Allocator.freeMany(m_pData, m_ResizePolicy.getHiCapacity()))
    {
      WARNING(STR("Cannot free array's buffer while clearing the array (requested size is %u bytes).") COMMA (sizeof(T_Type) * m_ResizePolicy.getHiCapacity()));
      return false;
    }
  }

  // Update array's attributes.
  m_Size = 0;
  m_pData = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pData == NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insertFirst(const T_Type& a_crItem)
{ CALL
  return insertIndex(0, a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insertLast(const T_Type& a_crItem)
{ CALL
  return insertIndex(getSize(), a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insertIndex(const Tuint a_cIndex, const T_Type& a_crItem)
{ CALL
  // Check index value and the array bounds.
  ASSERT((a_cIndex <= m_Size), STR("Cannot insert a new item into the array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Resize array to insert one item.
  if (resize(m_Size + 1))
  {
    // Shift part of array to the right.
    T_CopyPolicy::move(m_pData + a_cIndex + 1, m_pData + a_cIndex, m_Size - a_cIndex - 1);
    // Copy item into place under the index.
    m_pData[a_cIndex] = a_crItem;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeFirst()
{ CALL
  return removeIndex(0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeFirst(T_Type& a_rItem)
{ CALL
  return removeIndex(0, a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeLast()
{ CALL
  return removeIndex(getSize() - 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeLast(T_Type& a_rItem)
{ CALL
  return removeIndex(getSize() - 1, a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeIndex(const Tuint a_cIndex)
{ CALL
  // Check index value and the array bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove item from the array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Shift part of array to the left.
  T_CopyPolicy::move(m_pData + a_cIndex, m_pData + a_cIndex + 1, m_Size - a_cIndex - 1);
  // Resize array to remove one item.
  return resize(m_Size - 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeIndex(const Tuint a_cIndex, T_Type& a_rItem)
{ CALL
  // Check index value and the array bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove item from the array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Copy item from place under the index.
  a_rItem = m_pData[a_cIndex];
  // Shift part of array to the left.
  T_CopyPolicy::move(m_pData + a_cIndex, m_pData + a_cIndex + 1, m_Size - a_cIndex - 1);
  // Resize array to remove one item.
  return resize(m_Size - 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::remove(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  // Check index value and the array bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove items interval from the array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  Tuint size = NAlgorithms::NCommon::min(m_Size - a_cIndex, a_cSize);
  // Shift part of array to the left.
  T_CopyPolicy::move(m_pData + a_cIndex, m_pData + a_cIndex + size, m_Size - a_cIndex - size);
  // Resize array to remove items interval.
  return resize(m_Size - size);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItFirst()
{ CALL
  TIterator it_first;

  // Filling iterator inner structure.
  it_first.m_pContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItFirst() const
{ CALL
  TIteratorConst it_first;

  // Filling iterator inner structure.
  it_first.m_cpContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItLast()
{ CALL
  TIterator it_last;

  // Filling iterator inner structure.
  it_last.m_pContainer = this;
  it_last.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItLast() const
{ CALL
  TIteratorConst it_last;

  // Filling iterator inner structure.
  it_last.m_cpContainer = this;
  it_last.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItIndex(const Tuint a_cIndex)
{ CALL
  TIterator it_index;

  // Filling iterator inner structure.
  it_index.m_pContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItIndex(const Tuint a_cIndex) const
{ CALL
  TIteratorConst it_index;

  // Filling iterator inner structure.
  it_index.m_cpContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::resize(const Tuint a_cSize)
{ CALL
  return resize(a_cSize, T_Type());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::resize(const Tuint a_cSize, const T_Type& a_crValue)
{ CALL
  // Clear array if necessary.
  if (a_cSize == 0)
    return clear();
  // Check if we need buffer reallocation.
  Tuint old_bound = m_ResizePolicy.getHiCapacity();
  Tuint new_bound = m_ResizePolicy.resize(a_cSize);
  if ((m_pData == NULL) || (old_bound != new_bound))
  {
    // Create a new array buffer.
    Tuint old_size = m_Size;
    Tuint new_size = m_ResizePolicy.getHiCapacity();
    T_Type* old_buffer = m_pData;
    T_Type* new_buffer = m_Allocator.template allocateMany<T_Type>(new_size);
    if (new_buffer != NULL)
    {
      // Initialize array's buffer.
      m_Allocator.template initializeMany<T_Type>(new_buffer, a_cSize, a_crValue);
      // Copy array's items from old buffer into the new one.
      T_CopyPolicy::copy(new_buffer, old_buffer, NAlgorithms::NCommon::min(m_Size, a_cSize));
      // Update array's parameters.
      m_pData = new_buffer;
      m_Size = a_cSize;

      if (old_buffer != NULL)
      {
        // Destroy old array's items.
        if (!m_Allocator.destroyMany(old_buffer, old_size))
        {
          WARNING(STR("Cannot destroy old array's items while resizing the array (requested size is %u bytes).") COMMA (sizeof(T_Type) * old_size));
          return false;
        }
        // Free old array's buffer.
        if (!m_Allocator.freeMany(old_buffer, old_bound))
        {
          WARNING(STR("Cannot free old array's buffer while resizing the array (requested size is %u bytes).") COMMA (sizeof(T_Type) * old_bound));
          return false;
        }
      }
    }
    else
    {
      // Restore array's resize policy.
      m_ResizePolicy.resize(m_Size);
      WARNING(STR("Cannot allocate new array's buffer while resizing the array (requested size is %u bytes).") COMMA (sizeof(T_Type) * new_size));
      return false;
    }
  }
  else
  {
    // Create or destroy array items.
    if (m_Size < a_cSize)
      m_Allocator.template initializeMany<T_Type>(m_pData + m_Size, a_cSize - m_Size, a_crValue);
    else if (m_Size > a_cSize)
    {
      if (!m_Allocator.destroyMany(m_pData + a_cSize, m_Size - a_cSize))
      {
        WARNING(STR("Cannot destroy some array's items while resizing the array (requested size is %u bytes).") COMMA (sizeof(T_Type) * (m_Size - a_cSize)));
        return false;
      }
    }
    // Update array's size.
    m_Size = a_cSize;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::resizeBy(const Tsint a_cSize)
{ CALL
  return resize((((a_cSize < 0) && (m_Size < (Tuint)-a_cSize)) ? 0 : (m_Size + a_cSize)));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::resizeBy(const Tsint a_cSize, const T_Type& a_crValue)
{ CALL
  return resize((((a_cSize < 0) && (m_Size < (Tuint)-a_cSize)) ? 0 : (m_Size + a_cSize)), a_crValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::reverse()
{ CALL
  T_Type* left = m_pData;
  T_Type* right = m_pData + m_Size - 1;

  while (left < right)
    NAlgorithms::NCommon::swap(*(left++), *(right--));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Clear the current array.
  CHECK(clear());

  // Load the array header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the array resize policy.
  CHECK(a_rArchive.doValue(m_ResizePolicy, STR("m_ResizePolicy")));

  // Try to resize the array.
  CHECK(resize(size));

  // Load the array content.
  if (size > 0)
  {
    CHECK(a_rArchive.doValue(m_pData, size, STR("m_pData")));
  }

  // Load the array end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the array header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the array resize policy.
  CHECK(a_rArchive.doValue(m_ResizePolicy, STR("m_ResizePolicy")));

  // Save the array content.
  if (!isEmpty())
  {
    CHECK(a_rArchive.doValue(m_pData, m_Size, STR("m_pData")));
  }

  // Save the array end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>::swap(CArray<T_Type, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
  NAlgorithms::NCommon::swap(m_pData, a_rInstance.m_pData);
  NAlgorithms::NCommon::swap(m_ResizePolicy, a_rInstance.m_ResizePolicy);
  NAlgorithms::NCommon::swap(m_Allocator, a_rInstance.m_Allocator);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
