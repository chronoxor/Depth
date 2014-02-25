/*!
 *  \file    CSortedArray.inl Template sorted array container class. Sorted
 *           array represents an associative random access container.
 *  \brief   Template sorted array container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template sorted array container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   29.09.2006 02:02:23

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
#ifndef __CSORTEDARRAY_INL__
#define __CSORTEDARRAY_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CSortedArray(T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, const T_Type&, const T_Type&>(),
  m_Size(0),
  m_pData(NULL),
  m_fLessThan(a_fLessThan),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CSortedArray(const T_Type& a_crValue, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, const T_Type&, const T_Type&>(),
  m_Size(0),
  m_pData(NULL),
  m_fLessThan(a_fLessThan),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL
  insert(a_crValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <Tuint t_Size>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CSortedArray(const T_Type (&a_cpArray)[t_Size], T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, const T_Type&, const T_Type&>(),
  m_Size(0),
  m_pData(NULL),
  m_fLessThan(a_fLessThan),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_cpArray);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CSortedArray(const T_Type a_cpBuffer[], const Tuint a_cSize, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, const T_Type&, const T_Type&>(),
  m_Size(0),
  m_pData(NULL),
  m_fLessThan(a_fLessThan),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CSortedArray(const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, const T_Type&, const T_Type&>(),
  m_Size(0),
  m_pData(NULL),
  m_fLessThan(a_fLessThan),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::~CSortedArray()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <Tuint t_Size>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator = (const T_Type (&a_cpArray)[t_Size])
{ CALL
  set(a_cpArray);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator = (const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator += (const T_Type& a_crItem)
{ CALL
  insert(a_crItem);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator += (const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crSortedArray)
{ CALL
  insert(a_crSortedArray);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator -= (const T_Type& a_crItem)
{ CALL
  remove(a_crItem);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator -= (const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crSortedArray)
{ CALL
  remove(a_crSortedArray);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const T_Type& a_crItem)
{ CALL
  return find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const T_Type& a_crItem) const
{ CALL
  return find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const T_Type& CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tsint a_cIndex)
{ CALL
  // Verify index value and the array bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the sorted array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const T_Type& CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tuint a_cIndex)
{ CALL
  // Verify index value and the array bounds.
  VERIFY((!isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the sorted array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const T_Type& CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tsint a_cIndex) const
{ CALL
  // Verify index value and the array bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the sorted array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const T_Type& CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tuint a_cIndex) const
{ CALL
  // Verify index value and the array bounds.
  VERIFY((!isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the sorted array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator const T_Type* ()
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator const T_Type* () const
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <Tuint t_Size>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const T_Type (&a_cpArray)[t_Size])
{ CALL
  return set(a_cpArray, t_Size);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Clear current sorted array.
  if (!clear())
    return false;

  // Copy array's buffer.
  for (Tuint i = 0; i < a_cSize; ++i)
  {
    if (!insert(a_cpBuffer[i]))
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CSortedArray class instance."))
  {
    return false;
  }

  // Clear current sorted array.
  if (!clear())
    return false;

  // Resize sorted array to fit the given one.
  if (resize(a_crInstance.m_Size))
  {
    // Copy array's buffer.
    T_CopyPolicy::copy(m_pData, a_crInstance.m_pData, a_crInstance.m_Size);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getFreeSize() const
{ CALL
  return (getHiCapacity() - getSize());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getLoCapacity() const
{ CALL
  return m_ResizePolicy.getLoCapacity();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getHiCapacity() const
{ CALL
  return m_ResizePolicy.getHiCapacity();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const T_Type* CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getBuffer()
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const T_Type* CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getBuffer() const
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getResizeFactor() const
{ CALL
  return m_ResizePolicy.getResizeFactor();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::setResizeFactor(const Tuint a_cResizeFactor)
{ CALL
  return m_ResizePolicy.setResizeFactor(a_cResizeFactor);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::clear()
{ CALL
  // Delete memory buffer.
  if (m_pData != NULL)
  {
    // Destroy sorted array's items.
    if (!m_Allocator.destroyMany(m_pData, m_Size))
    {
      WARNING(STR("Cannot destroy sorted array's items while clearing the sorted array (requested size is %u bytes).") COMMA (sizeof(T_Type) * m_Size));
      return false;
    }
    // Free sorted array's buffer.
    if (!m_Allocator.freeMany(m_pData, m_ResizePolicy.getHiCapacity()))
    {
      WARNING(STR("Cannot free sorted array's buffer while clearing the sorted array (requested size is %u bytes).") COMMA (sizeof(T_Type) * m_ResizePolicy.getHiCapacity()));
      return false;
    }
  }

  // Update sorted array's attributes.
  m_Size = 0;
  m_pData = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pData == NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insert(const T_Type& a_crItem)
{ CALL
  return getItFirst().insert(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insert(const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crSortedArray)
{ CALL
  TIteratorConst it(a_crSortedArray.getItFirst());
  if (it.isValid())
  {
    do
    {
      if (!insert(it.getValueRef()))
        return false;
    } while (it.stepForward() > 0);
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::remove(const T_Type& a_crItem, const Tbool a_cRemoveSame/* = false */)
{ CALL
  TIterator it(find(a_crItem));
  if (it.isValid())
  {
    if (a_cRemoveSame)
    {
      do
      {
        if (!it.remove())
          return false;
        if (it.isValid())
        {
          if (isLessThan(it.getValueRef(), a_crItem))
          {
            if (it.stepForward() != 1)
              break;
          }
          if (isLessThan(a_crItem, it.getValueRef()))
            break;
        }
      } while (it.isValid());
      return true;
    }
    else
      return it.remove();
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::remove(const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crSortedArray, const Tbool a_cRemoveSame/* = false */)
{ CALL
  TIterator temp;
  TIteratorConst it(a_crSortedArray.getItFirst());
  if (it.isValid())
  {
    do
    {
      temp = find(it.getValueRef());
      if (temp.isValid())
      {
        if (a_cRemoveSame)
        {
          do
          {
            if (!temp.remove())
              return false;
            if (temp.isValid())
            {
              if (isLessThan(temp.getValueRef(), it.getValueRef()))
              {
                if (temp.stepForward() != 1)
                  break;
              }
              if (isLessThan(it.getValueRef(), temp.getValueRef()))
                break;
            }
          } while (temp.isValid());
        }
        else
        {
          if (!temp.remove())
            return false;
        }
      }
    } while (it.stepForward() > 0);
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::isLessThan(const T_Type& a_crItem1, const T_Type& a_crItem2) const
{ CALL
  return m_fLessThan(a_crItem1, a_crItem2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::find(const T_Type& a_crItem)
{ CALL
  return NAlgorithms::NContainers::bfind(*this, a_crItem, m_fLessThan);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::find(const T_Type& a_crItem) const
{ CALL
  return NAlgorithms::NContainers::bfind(*this, a_crItem, m_fLessThan);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItFirst()
{ CALL
  TIterator first_iterator;

  // Filling iterator inner structure.
  first_iterator.m_pContainer = this;
  first_iterator.m_Index = 0;
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItFirst() const
{ CALL
  TIteratorConst first_iterator;

  // Filling iterator inner structure.
  first_iterator.m_cpContainer = this;
  first_iterator.m_Index = 0;
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItLast()
{ CALL
  TIterator last_iterator;

  // Filling iterator inner structure.
  last_iterator.m_pContainer = this;
  last_iterator.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItLast() const
{ CALL
  TIteratorConst last_iterator;

  // Filling iterator inner structure.
  last_iterator.m_cpContainer = this;
  last_iterator.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIterator CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItIndex(const Tuint a_cIndex)
{ CALL
  TIterator index_iterator;

  // Filling iterator inner structure.
  index_iterator.m_pContainer = this;
  index_iterator.m_Index = a_cIndex;
  return index_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline typename CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::TIteratorConst CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getItIndex(const Tuint a_cIndex) const
{ CALL
  TIteratorConst index_iterator;

  // Filling iterator inner structure.
  index_iterator.m_cpContainer = this;
  index_iterator.m_Index = a_cIndex;
  return index_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeFirst()
{ CALL
  return remove(0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeFirst(T_Type& a_rItem)
{ CALL
  return remove(0, a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeLast()
{ CALL
  return remove(getSize() - 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeLast(T_Type& a_rItem)
{ CALL
  return remove(getSize() - 1, a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeIndex(const Tuint a_cIndex)
{ CALL
  // Check index value and the sorted array bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove item from the sorted array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Shift part of sorted array to the left.
  T_CopyPolicy::move(m_pData + a_cIndex, m_pData + a_cIndex + 1, m_Size - a_cIndex - 1);
  // Resize sorted array to remove one item.
  return resize(m_Size - 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeIndex(const Tuint a_cIndex, T_Type& a_rItem)
{ CALL
  // Check index value and the sorted array bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove item from the sorted array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Copy item from place under the index.
  a_rItem = m_pData[a_cIndex];
  // Shift part of sorted array to the left.
  T_CopyPolicy::move(m_pData + a_cIndex, m_pData + a_cIndex + 1, m_Size - a_cIndex - 1);
  // Resize sorted array to remove one item.
  return resize(m_Size - 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::remove(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  // Check index value and the array bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove items interval from the sorted array with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  Tuint size = NAlgorithms::NCommon::min(m_Size - a_cIndex, a_cSize);
  // Shift part of sorted array to the left.
  T_CopyPolicy::move(m_pData + a_cIndex, m_pData + a_cIndex + size, m_Size - a_cIndex - size);
  // Resize sorted array to remove items interval.
  return resize(m_Size - size);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::resize(const Tuint a_cSize)
{ CALL
  // Clear sorted array if necessary.
  if (a_cSize == 0)
    return clear();
  // Check if we need buffer reallocation.
  Tuint old_bound = m_ResizePolicy.getHiCapacity();
  Tuint new_bound = m_ResizePolicy.resize(a_cSize);
  if ((m_pData == NULL) || (old_bound != new_bound))
  {
    // Create a new sorted array buffer.
    Tuint old_size = m_Size;
    Tuint new_size = m_ResizePolicy.getHiCapacity();
    T_Type* old_buffer = m_pData;
    T_Type* new_buffer = m_Allocator.template allocateMany<T_Type>(new_size);
    if (new_buffer != NULL)
    {
      // Initialize sorted array's buffer.
      m_Allocator.template initializeMany<T_Type>(new_buffer, a_cSize, T_Type());
      // Copy sorted array's items from old buffer into the new one.
      T_CopyPolicy::copy(new_buffer, old_buffer, NAlgorithms::NCommon::min(m_Size, a_cSize));
      // Update sorted array's parameters.
      m_pData = new_buffer;
      m_Size = a_cSize;

      if (old_buffer != NULL)
      {
        // Destroy old sorted array's items.
        if (!m_Allocator.destroyMany(old_buffer, old_size))
        {
          WARNING(STR("Cannot destroy old sorted array's items while resizing the sorted array (requested size is %u bytes).") COMMA (sizeof(T_Type) * old_size));
          return false;
        }
        // Free old sorted array's buffer.
        if (!m_Allocator.freeMany(old_buffer, old_bound))
        {
          WARNING(STR("Cannot free old sorted array's buffer while resizing the sorted array (requested size is %u bytes).") COMMA (sizeof(T_Type) * old_bound));
          return false;
        }
      }
    }
    else
    {
      // Restore sorted array's resize policy.
      m_ResizePolicy.resize(m_Size);
      WARNING(STR("Cannot allocate new sorted array's buffer while resizing the sorted array (requested size is %u bytes).") COMMA (sizeof(T_Type) * new_size));
      return false;
    }
  }
  else
  {
    // Create or destroy sorted array items.
    if (m_Size < a_cSize)
      m_Allocator.template initializeMany<T_Type>(m_pData + m_Size, a_cSize - m_Size, T_Type());
    else if (m_Size > a_cSize)
      if (!m_Allocator.destroyMany(m_pData + a_cSize, m_Size - a_cSize))
      {
        WARNING(STR("Cannot destroy some sorted array's items while resizing the sorted array (requested size is %u bytes).") COMMA (sizeof(T_Type) * (m_Size - a_cSize)));
        return false;
      }
    // Update sorted array's size.
    m_Size = a_cSize;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Clear the current sorted array.
  CHECK(clear());

  // Load the sorted array header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the sorted array 'LessThan' binary predicate.
  CHECK(a_rArchive.doValue(m_fLessThan, STR("m_fLessThan")));
  // Load the sorted array resize policy.
  CHECK(a_rArchive.doValue(m_ResizePolicy, STR("m_ResizePolicy")));

  // Load the sorted array content.
  if (size > 0)
  {
    Tuint index = 0;

    // Insert sorted array items.
    while (size-- > 0)
    {
      T_Type item;

      // Load next sorted array item.
      CHECK(a_rArchive.doValue(item, STR("item[%u]") COMMA (index)));
      // Insert next item into the sorted array.
      CHECK(insert(item));
      ++index;
    }
  }

  // Load the sorted array end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the sorted array header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the sorted array 'LessThan' binary predicate.
  CHECK(a_rArchive.doValue(m_fLessThan, STR("m_fLessThan")));
  // Save the sorted array resize policy.
  CHECK(a_rArchive.doValue(m_ResizePolicy, STR("m_ResizePolicy")));

  // Save the sorted array content.
  if (!isEmpty())
  {
    Tuint index = 0;

    // Save all sorted array items.
    while (index < m_Size)
    {
      // Save next sorted array item.
      CHECK(a_rArchive.doValue(m_pData[index], STR("item[%u]") COMMA (index)));
      ++index;
    }
  }

  // Save the sorted array end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::swap(CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
  NAlgorithms::NCommon::swap(m_pData, a_rInstance.m_pData);
  NAlgorithms::NCommon::swap(m_fLessThan, a_rInstance.m_fLessThan);
  NAlgorithms::NCommon::swap(m_ResizePolicy, a_rInstance.m_ResizePolicy);
  NAlgorithms::NCommon::swap(m_Allocator, a_rInstance.m_Allocator);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
