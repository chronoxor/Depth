/*!
 *  \file    CStringBuffer.inl Template string buffer container class. String
 *           buffer represents a random access container which stores stings.
 *  \brief   Template string buffer container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template string buffer container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   07.04.2009 03:55:51

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
#ifndef __CSTRINGBUFFER_INL__
#define __CSTRINGBUFFER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::CStringBuffer(const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>, T_Type, CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>, CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>, T_Type, CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>, CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> >(),
  m_StringArray(0, a_cResizeFactor, a_crAllocator),
  m_Allocator(a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
template <Tuint t_Size>
inline CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::CStringBuffer(const T_Type (&a_cpArray)[t_Size], const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>, T_Type, CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>, CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>, T_Type, CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>, CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> >(),
  m_StringArray(0, a_cResizeFactor, a_crAllocator),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_cpArray);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::CStringBuffer(const T_Type a_cpBuffer[], const Tuint a_cSize, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>, T_Type, CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>, CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>, T_Type, CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>, CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> >(),
  m_StringArray(0, a_cResizeFactor, a_crAllocator),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::CStringBuffer(const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IRandom<CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>, T_Type, CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>, CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> >(),
  NCommon::NContainers::IRandomConst<CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>, T_Type, CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>, CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> >(),
  m_StringArray(0, a_crInstance.getResizeFactor(), a_crAllocator),
  m_Allocator(a_crAllocator)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::~CStringBuffer()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
template <Tuint t_Size>
inline CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::operator = (const T_Type (&a_cpArray)[t_Size])
{ CALL
  set(a_cpArray);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::operator = (const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline T_Type& CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::operator [] (const Tsint a_cIndex)
{ CALL
  // Verify index value and the string buffer bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < getSize())), STR("Cannot access to the string buffer's item with the out of bounds index."));

  return *m_StringArray[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline T_Type& CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::operator [] (const Tuint a_cIndex)
{ CALL
  // Verify index value and the string buffer bounds.
  VERIFY((!isEmpty() && (a_cIndex < getSize())), STR("Cannot access to the string buffer's item with the out of bounds index."));

  return *m_StringArray[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline const T_Type& CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::operator [] (const Tsint a_cIndex) const
{ CALL
  // Verify index value and the string buffer bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < getSize())), STR("Cannot access to the string buffer's item with the out of bounds index."));

  return *m_StringArray[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline const T_Type& CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::operator [] (const Tuint a_cIndex) const
{ CALL
  // Verify index value and the string buffer bounds.
  VERIFY((!isEmpty() && (a_cIndex < getSize())), STR("Cannot access to the string buffer's item with the out of bounds index."));

  return *m_StringArray[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
template <Tuint t_Size>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::set(const T_Type (&a_cpArray)[t_Size])
{ CALL
  return set(a_cpArray, t_Size);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::set(const T_Type a_cpBuffer[], const Tuint a_cSize)
{ CALL
  // Clear current string buffer.
  if (!clear())
    return false;

  // Resize string buffer to fit the given one.
  if (m_StringArray.resize(a_cSize))
  {
    for (Tuint i = 0; i < a_cSize; ++i)
    {
      if (!NDetails::CStringBufferHelper<NTraits::MIsClassOrUnion<T_Type>::yes>::copy(m_StringArray[i], a_cpBuffer[i], m_Allocator))
        return false;
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::set(const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CStringBuffer class instance."))
  {
    return false;
  }

  // Clear current string buffer.
  if (!clear())
    return false;

  // Copy resize factor.
  if (!m_StringArray.setResizeFactor(a_crInstance.m_StringArray.getResizeFactor()))
    return false;

  // Resize string buffer to fit the given one.
  if (m_StringArray.resize(a_crInstance.m_StringArray.getSize()))
  {
    for (Tuint i = 0; i < a_crInstance.m_StringArray.getSize(); ++i)
    {
      if (!NDetails::CStringBufferHelper<NTraits::MIsClassOrUnion<T_Type>::yes>::copy(m_StringArray[i], *a_crInstance.m_StringArray[i], m_Allocator))
        return false;
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tuint CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::getFreeSize() const
{ CALL
  return m_StringArray.getFreeSize();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tuint CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::getLoCapacity() const
{ CALL
  return m_StringArray.getLoCapacity();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tuint CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::getHiCapacity() const
{ CALL
  return m_StringArray.getHiCapacity();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tuint CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::getResizeFactor() const
{ CALL
  return m_StringArray.getResizeFactor();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::setResizeFactor(const Tuint a_cResizeFactor)
{ CALL
  return m_StringArray.setResizeFactor(a_cResizeFactor);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::clear()
{ CALL
  // Destroy strings.
  for (Tuint i = 0; i < getSize(); ++i)
    if (!destroy(m_StringArray.getBuffer()[i]))
      return false;

  // Clear string buffer.
  return m_StringArray.clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::isEmpty() const
{ CALL
  return ((m_StringArray.getSize() == 0) || (m_StringArray.getBuffer() == NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tuint CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::getSize() const
{ CALL
  return m_StringArray.getSize();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::insertFirst(const T_Type& a_crItem)
{ CALL
  return insertIndex(0, a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::insertLast(const T_Type& a_crItem)
{ CALL
  return insertIndex(getSize(), a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::insertIndex(const Tuint a_cIndex, const T_Type& a_crItem)
{ CALL
  // Check index value and the string buffer bounds.
  ASSERT((a_cIndex <= getSize()), STR("Cannot insert a new string item into the string buffer with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA getSize())
  {
    return false;
  }

  // Make a clone of the string.
  typename NTraits::MAddPointer<T_Type>::type item = NULL;
  if (!NDetails::CStringBufferHelper<NTraits::MIsClassOrUnion<T_Type>::yes>::copy(item, a_crItem, m_Allocator))
    return false;

  // Try to insert a new string into the string buffer.
  if (!m_StringArray.insertIndex(a_cIndex, item))
  {
    destroy(item);
    return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::removeFirst()
{ CALL
  return removeIndex(0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::removeFirst(T_Type& a_rItem)
{ CALL
  return removeIndex(0, a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::removeLast()
{ CALL
  return removeIndex(getSize() - 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::removeLast(T_Type& a_rItem)
{ CALL
  return removeIndex(getSize() - 1, a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::removeIndex(const Tuint a_cIndex)
{ CALL
  // Check index value and the string buffer bounds.
  ASSERT((!isEmpty() && (a_cIndex < getSize())), STR("Cannot remove string item from the string buffer with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA getSize())
  {
    return false;
  }

  // Destroy removed string.
  if (!destroy(m_StringArray[a_cIndex]))
    return false;

  // Remove string form the buffer.
  return m_StringArray.removeIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::removeIndex(const Tuint a_cIndex, T_Type& a_rItem)
{ CALL
  // Check index value and the string buffer bounds.
  ASSERT((!isEmpty() && (a_cIndex < getSize())), STR("Cannot remove string item from the string buffer with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA getSize())
  {
    return false;
  }

  // Move removed string.
  if (!move(a_rItem, m_StringArray[a_cIndex]))
    return false;

  // Remove string form the buffer.
  return m_StringArray.removeIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::remove(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  // Check index value and the string buffer bounds.
  ASSERT((!isEmpty() && (a_cIndex < getSize())), STR("Cannot remove string items interval from the string buffer with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA getSize())
  {
    return false;
  }

  // Destroy removed strings.
  for (Tuint i = 0; i < a_cSize; ++i)
    if (!destroy(m_StringArray[a_cIndex + i]))
      return false;

  // Remove string form the buffer.
  return m_StringArray.remove(a_cIndex, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline typename CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::TIterator CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::getItFirst()
{ CALL
  TIterator it_first;

  // Filling iterator inner structure.
  it_first.m_pContainer = this;
  it_first.m_Iterator = m_StringArray.getItFirst();
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline typename CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::TIteratorConst CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::getItFirst() const
{ CALL
  TIteratorConst it_first;

  // Filling iterator inner structure.
  it_first.m_cpContainer = this;
  it_first.m_Iterator = m_StringArray.getItFirst();
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline typename CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::TIterator CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::getItLast()
{ CALL
  TIterator it_last;

  // Filling iterator inner structure.
  it_last.m_pContainer = this;
  it_last.m_Iterator = m_StringArray.getItLast();
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline typename CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::TIteratorConst CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::getItLast() const
{ CALL
  TIteratorConst it_last;

  // Filling iterator inner structure.
  it_last.m_cpContainer = this;
  it_last.m_Iterator = m_StringArray.getItLast();
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline typename CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::TIterator CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::getItIndex(const Tuint a_cIndex)
{ CALL
  TIterator it_index;

  // Filling iterator inner structure.
  it_index.m_pContainer = this;
  it_index.m_Iterator = m_StringArray.getItIndex(a_cIndex);
  return it_index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline typename CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::TIteratorConst CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::getItIndex(const Tuint a_cIndex) const
{ CALL
  TIteratorConst it_index;

  // Filling iterator inner structure.
  it_index.m_cpContainer = this;
  it_index.m_Iterator = m_StringArray.getItIndex(a_cIndex);
  return it_index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::move(T_Type& a_rDestination, typename NTraits::MAddPointer<T_Type>::type& a_rpSource)
{ CALL
  a_rDestination = *a_rpSource;
  return destroy(a_rpSource);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::destroy(typename NTraits::MAddPointer<T_Type>::type& a_rpSource)
{ CALL
  if (NTraits::MIsClassOrUnion<T_Type>::yes)
  {
    if (!m_Allocator.deleteOne(a_rpSource))
    {
      WARNING(STR("Cannot remove string of the string buffer (requested size is %u bytes).") COMMA (sizeof(T_Type)));
      return false;
    }
  }
  else
  {
    typename NTraits::MIfThenElse<NTraits::MIsClassOrUnion<T_Type>::yes, void*, T_Type>::type value = *a_rpSource;
    if (!m_Allocator.freeMany(value, 1))
    {
      WARNING(STR("Cannot remove string of the string buffer (requested size is %u bytes).") COMMA (sizeof(T_Type)));
      return false;
    }
    if (!m_Allocator.deleteOne(a_rpSource))
    {
      WARNING(STR("Cannot remove string pointer of the string buffer (requested size is %u bytes).") COMMA (sizeof(T_Type)));
      return false;
    }
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline void CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::reverse()
{ CALL
  m_StringArray.reverse();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;
  Tuint resize_factor = 0;

  // Clear the current string buffer.
  CHECK(clear());

  // Load the string buffer header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
    CHECK(a_rArchive.doProperty(resize_factor, STR("ResizeFactor")));
  CHECK(a_rArchive.body());

  // Set the string buffer resize factor.
  CHECK(m_StringArray.setResizeFactor(resize_factor));

  // Load the string buffer content.
  if (size > 0)
  {
    Tuint index = 0;

    // Insert string items.
    while (size-- > 0)
    {
      T_Type item;

      // Load next string item.
      CHECK(a_rArchive.doValue(item, STR("item[%u]") COMMA (index)));
      // Insert next string item into the string buffer.
      CHECK(insertLast(item));
      ++index;
    }
  }

  // Load the string buffer end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the string buffer header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>")));
    CHECK(a_rArchive.doProperty(getSize(), STR("size")));
    CHECK(a_rArchive.doProperty(getResizeFactor(), STR("ResizeFactor")));
  CHECK(a_rArchive.body());

  // Save the string buffer content.
  if (!isEmpty())
  {
    Tuint index = 0;

    // Save all string items.
    while (index < getSize())
    {
      // Save next string item.
      CHECK(a_rArchive.doValue(*m_StringArray[index], STR("item[%u]") COMMA (index)));
      ++index;
    }
  }

  // Save the string buffer end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline void CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>::swap(CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_StringArray, a_rInstance.m_StringArray);
  NAlgorithms::NCommon::swap(m_Allocator, a_rInstance.m_Allocator);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
