/*!
 *  \file    CBitArray.inl Template bit array container class. Bit array forms
 *           a compact data structure for random access to the bit field.
 *  \brief   Bit array container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Bit array container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   05.06.2006 22:31:48

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
#ifndef __CBITARRAY_INL__
#define __CBITARRAY_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArray(const Tuint a_cSize/* = 0 */, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>, const NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  m_Size(0),
  m_pData(NULL),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL
  resize(a_cSize);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArray(const Tbool a_cValue, const Tuint a_cSize, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>, const NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  m_Size(0),
  m_pData(NULL),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL
  resize(a_cSize, a_cValue);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <Tuint t_Size>
inline CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArray(const Tbool (&a_cpArray)[t_Size], const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>, const NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  m_Size(0),
  m_pData(NULL),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_cpArray);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArray(const Tbool a_cpBuffer[], const Tuint a_cSize, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>, const NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  m_Size(0),
  m_pData(NULL),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArray(Tcbuffer a_cpBuffer, const Tuint a_cSize, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>, const NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  m_Size(0),
  m_pData(NULL),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CArray(const CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, Tbool, CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>, NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>, const NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  m_Size(0),
  m_pData(NULL),
  m_ResizePolicy(),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::~CArray()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <Tuint t_Size>
inline CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator = (const Tbool (&a_cpArray)[t_Size])
{ CALL
  set(a_cpArray);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator = (const CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tsint a_cIndex)
{ CALL
  // Verify index value and the array bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the bit array's item with the out of bounds index."));

  return NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>(m_pData + (a_cIndex >> 3), ((Tuint)1 << (a_cIndex & 7)));
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tuint a_cIndex)
{ CALL
  // Verify index value and the array bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the bit array's item with the out of bounds index."));

  return NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>(m_pData + (a_cIndex >> 3), ((Tuint)1 << (a_cIndex & 7)));
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tsint a_cIndex) const
{ CALL
  // Verify index value and the array bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the bit array's item with the out of bounds index."));

  return NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>(m_pData + (a_cIndex >> 3), ((Tuint)1 << (a_cIndex & 7)));
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator> CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tuint a_cIndex) const
{ CALL
  // Verify index value and the array bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the bit array's item with the out of bounds index."));

  return NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>(m_pData + (a_cIndex >> 3), ((Tuint)1 << (a_cIndex & 7)));
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator Tbuffer ()
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator Tcbuffer () const
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <Tuint t_Size>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const Tbool (&a_cpArray)[t_Size])
{ CALL
  return set(a_cpArray, t_Size);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const Tbool a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Clear current bit array.
  if (!clear())
    return false;

  // Resize bit array to fit the given one.
  if (resize(a_cSize))
  {
    // Copy bit array's buffer.
    for (Tuint i = 0; i < a_cSize; ++i)
    {
      if (!setBit(i, a_cpBuffer[i]))
        return false;
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(Tcbuffer a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Clear current bit array.
  if (!clear())
    return false;

  // Resize bit array to fit the given one.
  if (resize(a_cSize))
  {
    // Copy bit array's buffer.
    T_CopyPolicy::copy(m_pData, a_cpBuffer, ((a_cSize >> 3) + ((a_cSize & 7) ? 1 : 0)));
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CArray<Tbool> class instance."))
  {
    return false;
  }

  // Copy resize policy.
  m_ResizePolicy.set(a_crInstance.m_ResizePolicy);
  // Copy array's buffer.
  return set(a_crInstance.m_pData, a_crInstance.m_Size);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getFreeSize() const
{ CALL
  return (getHiCapacity() - getSize());
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getLoCapacity() const
{ CALL
  return m_ResizePolicy.getLoCapacity();
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getHiCapacity() const
{ CALL
  return m_ResizePolicy.getHiCapacity();
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbuffer CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getBuffer()
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tcbuffer CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getBuffer() const
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getResizeFactor() const
{ CALL
  return m_ResizePolicy.getResizeFactor();
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::setResizeFactor(const Tuint a_cResizeFactor)
{ CALL
  return m_ResizePolicy.setResizeFactor(a_cResizeFactor);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getBit(const Tuint a_cIndex) const
{ CALL
  // Check index value and the array bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot get a bit from the bit array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  return !!(m_pData[(a_cIndex >> 3)] & ((Tuint)1 << (a_cIndex & 7)));
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::setBit(const Tuint a_cIndex, const Tbool a_cValue)
{ CALL
  // Check index value and the array bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot set a bit in the bit array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  if (a_cValue)
    m_pData[(a_cIndex >> 3)] |= ((Tuint)1 << (a_cIndex & 7));
  else
    m_pData[(a_cIndex >> 3)] &= ~((Tuint)1 << (a_cIndex & 7));
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::flipBit(const Tuint a_cIndex)
{ CALL
  // Check index value and the array bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot flip a bit in the bit array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  m_pData[(a_cIndex >> 3)] ^= ((Tuint)1 << (a_cIndex & 7));
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::clear()
{ CALL
  // Delete memory buffer.
  if (m_pData != NULL)
  {
    // Destroy bit array's items.
    Tuint byte_size = ((m_Size >> 3) + ((m_Size & 7) ? 1 : 0));
    if (!m_Allocator.destroyMany(m_pData, byte_size))
    {
      WARNING(STR("Cannot destroy bit array's items while clearing the bit array (requested size is %u bytes).") COMMA byte_size);
      return false;
    }
    // Free array's buffer.
    Tuint byte_hi_capacity = ((m_ResizePolicy.getHiCapacity() >> 3) + ((m_ResizePolicy.getHiCapacity() & 7) ? 1 : 0));
    if (!m_Allocator.freeMany(m_pData, byte_hi_capacity))
    {
      WARNING(STR("Cannot free bit array's buffer while clearing the bit array (requested size is %u bytes).") COMMA byte_hi_capacity);
      return false;
    }
  }

  // Update bit array's attributes.
  m_Size = 0;
  m_pData = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pData == NULL));
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insertFirst(const Tbool& a_crItem)
{ CALL
  return insertIndex(0, a_crItem);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insertLast(const Tbool& a_crItem)
{ CALL
  return insertIndex(getSize(), a_crItem);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insertIndex(const Tuint a_cIndex, const Tbool& a_crItem)
{ CALL
  // Check index value and the array bounds.
  ASSERT((a_cIndex <= m_Size), STR("Cannot insert a new bit in the bit array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Resize bit array to insert one item.
  if (resize(m_Size + 1))
  {
    // Shift part of bit array to the right.
    if (a_cIndex < (m_Size - 1))
    {
      Tbool temp;
      for (Tuint i = (m_Size - 1); i > a_cIndex; --i)
      {
        temp = getBit(i - 1);
        setBit(i, temp);
      }
    }
    // Copy item into place under the index.
    setBit(a_cIndex, a_crItem);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeFirst()
{ CALL
  return removeIndex(0);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeFirst(Tbool& a_rItem)
{ CALL
  return removeIndex(0, a_rItem);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeLast()
{ CALL
  // Check if array is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove the last item from the empty bit array."))
  {
    return false;
  }

  return removeIndex(getSize() - 1);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeLast(Tbool& a_rItem)
{ CALL
  // Check if array is not empty.
  ASSERT(!isEmpty(), STR("Cannot remove the last item from the empty bit array."))
  {
    return false;
  }

  return removeIndex(getSize() - 1, a_rItem);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeIndex(const Tuint a_cIndex)
{ CALL
  // Check index value and the array bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove a bit from the bit array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Shift part of array to the left.
  Tbool temp;
  for (Tuint i = a_cIndex; i < (m_Size - 1); ++i)
  {
    temp = getBit(i + 1);
    setBit(i, temp);
  }
  // Resize array to remove one item.
  return resize(m_Size - 1);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeIndex(const Tuint a_cIndex, Tbool& a_rItem)
{ CALL
  // Check index value and the array bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove a bit from the bit array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Copy item from place under the index.
  a_rItem = getBit(a_cIndex);
  // Shift part of array to the left.
  Tbool temp;
  for (Tuint i = a_cIndex; i < (m_Size - 1); ++i)
  {
    temp = getBit(i + 1);
    setBit(i, temp);
  }
  // Resize array to remove one item.
  return resize(m_Size - 1);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::remove(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  // Check index value and the array bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove items interval from the bit array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  Tuint size = NAlgorithms::NCommon::min(m_Size - a_cIndex, a_cSize);
  // Shift part of array to the left.
  Tbool temp;
  for (Tuint i = a_cIndex; i < (m_Size - size); ++i)
  {
    temp = getBit(i + size);
    setBit(i, temp);
  }
  // Resize array to remove items interval.
  return resize(m_Size - size);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItFirst()
{ CALL
  TIterator it_first;

  // Filling iterator inner structure.
  it_first.m_pContainer = this;
  it_first.m_mReference.m_pBytePtr = m_pData;
  it_first.m_mReference.m_BitMask = 1;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItFirst() const
{ CALL
  TIteratorConst it_first;

  // Filling iterator inner structure.
  it_first.m_cpContainer = this;
  it_first.m_Reference.m_pBytePtr = m_pData;
  it_first.m_Reference.m_BitMask = 1;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItLast()
{ CALL
  TIterator it_last;

  // Filling iterator inner structure.
  Tuint index = ((m_Size > 0) ? (m_Size - 1) : 0);
  it_last.m_pContainer = this;
  it_last.m_mReference.m_pBytePtr = m_pData + (index >> 3);
  it_last.m_mReference.m_BitMask = ((Tuint)1 << (index & 7));
  it_last.m_Index = index;
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItLast() const
{ CALL
  TIteratorConst it_last;

  // Filling iterator inner structure.
  Tuint index = ((m_Size > 0) ? (m_Size - 1) : 0);
  it_last.m_cpContainer = this;
  it_last.m_Reference.m_pBytePtr = m_pData + (index >> 3);
  it_last.m_Reference.m_BitMask = ((Tuint)1 << (index & 7));
  it_last.m_Index = index;
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItIndex(const Tuint a_cIndex)
{ CALL
  TIterator it_index;

  // Filling iterator inner structure.
  it_index.m_pContainer = this;
  it_index.m_mReference.m_pBytePtr = m_pData + (a_cIndex >> 3);
  it_index.m_mReference.m_BitMask = ((Tuint)1 << (a_cIndex & 7));
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItIndex(const Tuint a_cIndex) const
{ CALL
  TIteratorConst it_index;

  // Filling iterator inner structure.
  it_index.m_cpContainer = this;
  it_index.m_Reference.m_pBytePtr = m_pData + (a_cIndex >> 3);
  it_index.m_Reference.m_BitMask = ((Tuint)1 << (a_cIndex & 7));
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::resize(const Tuint a_cSize)
{ CALL
  return resize(a_cSize, false);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::resize(const Tuint a_cSize, const Tbool a_cValue)
{ CALL
  // Clear bit array if necessary.
  if (a_cSize == 0)
    return clear();
  // Check if we need buffer reallocation.
  Tuint byte_old_bound = ((m_ResizePolicy.getHiCapacity() >> 3) + ((m_ResizePolicy.getHiCapacity() & 7) ? 1 : 0));
  Tuint byte_new_bound = m_ResizePolicy.resize(a_cSize);
  byte_new_bound = ((byte_new_bound >> 3) + ((byte_new_bound & 7) ? 1 : 0));
  if ((m_pData == NULL) || (byte_old_bound != byte_new_bound))
  {
    // Create a new array buffer.
    Tuint byte_hi_capacity = ((m_ResizePolicy.getHiCapacity() >> 3) + ((m_ResizePolicy.getHiCapacity() & 7) ? 1 : 0));
    Tbuffer old_buffer = m_pData;
    Tbuffer new_buffer = m_Allocator.template allocateMany<Tbyte>(byte_hi_capacity);
    if (new_buffer != NULL)
    {
      // Initialize array's buffer.
      Tuint byte_new_size = ((a_cSize >> 3) + ((a_cSize & 7) ? 1 : 0));
      Tuint byte_old_size = ((m_Size >> 3) + ((m_Size & 7) ? 1 : 0));
      m_Allocator.template initializeMany<Tbyte, const Tbyte>(new_buffer, byte_new_size, ((a_cValue) ? 0xFF : 0));
      // Copy array's items from old buffer into the new one.
      T_CopyPolicy::copy(new_buffer, old_buffer, NAlgorithms::NCommon::min(byte_old_size, byte_new_size));
      // Update last byte in old bit array's buffer.
      if (a_cSize > m_Size)
      {
        Tuint mod = (m_Size & 7);
        if ((mod != 0) && (byte_old_size > 0))
        {
          Tuint mask = (((Tuint)1 << mod) - 1);
          if (a_cValue)
            new_buffer[byte_old_size - 1] |= ~mask;
          else
            new_buffer[byte_old_size - 1] &= mask;
        }
      }
      // Update array's parameters.
      m_pData = new_buffer;
      m_Size = a_cSize;

      if (old_buffer != NULL)
      {
        // Destroy old array's items.
        if (!m_Allocator.destroyMany(old_buffer, byte_old_size))
        {
          WARNING(STR("Cannot destroy old bit array's items while resizing the bit array (requested size is %u bytes).") COMMA byte_old_size);
          return false;
        }
        // Free old array's buffer.
        if (!m_Allocator.freeMany(old_buffer, byte_old_bound))
        {
          WARNING(STR("Cannot free old bit array's buffer while resizing the bit array (requested size is %u bytes).") COMMA byte_old_bound);
          return false;
        }
      }
    }
    else
    {
      // Restore array's resize policy.
      m_ResizePolicy.resize(m_Size);
      WARNING(STR("Cannot allocate new bit array's buffer while resizing the bit array (requested size is %u bytes).") COMMA byte_hi_capacity);
      return false;
    }
  }
  else
  {
    // Create or destroy array items.
    if (m_Size < a_cSize)
    {
      Tuint byte_new_size = ((a_cSize >> 3) + ((a_cSize & 7) ? 1 : 0));
      Tuint byte_old_size = ((m_Size >> 3) + ((m_Size & 7) ? 1 : 0));
      if ((byte_new_size - byte_old_size) > 0)
        m_Allocator.template initializeMany<Tbyte, const Tbyte>(m_pData + byte_old_size, byte_new_size - byte_old_size, ((a_cValue) ? 0xFF : 0));
      else
      {
        Tuint mod = (m_Size & 7);
        if ((mod != 0) && (byte_old_size > 0))
        {
          Tuint mask = (((Tuint)1 << mod) - 1);
          if (a_cValue)
            m_pData[byte_old_size - 1] |= ~mask;
          else
            m_pData[byte_old_size - 1] &= mask;
        }
      }
    }
    else if (m_Size > a_cSize)
    {
      Tuint byte_new_size = ((a_cSize >> 3) + ((a_cSize & 7) ? 1 : 0));
      Tuint byte_old_size = ((m_Size >> 3) + ((m_Size & 7) ? 1 : 0));
      if ((byte_old_size - byte_new_size) > 0)
      {
        if (!m_Allocator.destroyMany(m_pData + byte_new_size, byte_old_size - byte_new_size))
        {
          WARNING(STR("Cannot destroy some bit array's items while resizing the bit array (requested size is %u bytes).") COMMA (sizeof(Tbool) * (byte_old_size - byte_new_size)));
          return false;
        }
      }
    }
    // Update array's size.
    m_Size = a_cSize;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::resizeBy(const Tsint a_cSize)
{ CALL
  return resize((((a_cSize < 0) && (m_Size < (Tuint)-a_cSize)) ? 0 : (m_Size + a_cSize)));
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::resizeBy(const Tsint a_cSize, const Tbool a_cValue)
{ CALL
  return resize((((a_cSize < 0) && (m_Size < (Tuint)-a_cSize)) ? 0 : (m_Size + a_cSize)), a_cValue);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::reverse()
{ CALL
  Tuint left_index = 0;
  Tuint right_index = m_Size - 1;

  while (left_index < right_index)
  {
    Tbool left_value = getBit(left_index);
    Tbool right_value = getBit(right_index);
    setBit(left_index, right_value);
    setBit(right_index, left_value);
    ++left_index;
    --right_index;
  }
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Clear the current bit array.
  CHECK(clear());

  // Load the bit array header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the bit array resize policy.
  CHECK(a_rArchive.doValue(m_ResizePolicy, STR("m_ResizePolicy")));

  // Try to resize the bit array.
  CHECK(resize(size));

  // Load the bit array content.
  if (size > 0)
  {
    Tuint index = 0;

    // Insert bit array items.
    while (size-- > 0)
    {
      Tbool item;

      // Load next bit array item.
      CHECK(a_rArchive.doValue(item, STR("item[%u]") COMMA (index)));
      // Set next array item into the current index.
      CHECK(setBit(index, item));
      ++index;
    }
  }

  // Load the array end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the bit array header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the bit array resize policy.
  CHECK(a_rArchive.doValue(m_ResizePolicy, STR("m_ResizePolicy")));

  // Save the bit array content.
  if (!isEmpty())
  {
    Tuint index = 0;

    // Save all bit array items.
    while (index < m_Size)
    {
      // Save next bit array item.
      CHECK(a_rArchive.doValue(getBit(index), STR("item[%u]") COMMA (index)));
      ++index;
    }
  }

  // Save the bit array end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>::swap(CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_rInstance)
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
