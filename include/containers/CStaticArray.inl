/*!
 *  \file    CStaticArray.inl Template static array container class. Static
 *           array represents a fixed-sized random access container.
 *  \brief   Template static array container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template static array container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   05.09.2006 20:25:46

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
#ifndef __CSTATICARRAY_INL__
#define __CSTATICARRAY_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArray<T_Type, t_Size, T_CopyPolicy>::CStaticArray() :
  NCommon::NContainers::IRandomConst<CStaticArray<T_Type, t_Size, T_CopyPolicy>, T_Type, CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>, CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> >(),
  m_pData()
{ CALL
  set(T_Type());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArray<T_Type, t_Size, T_CopyPolicy>::CStaticArray(const T_Type& a_crValue) :
  NCommon::NContainers::IRandomConst<CStaticArray<T_Type, t_Size, T_CopyPolicy>, T_Type, CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>, CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> >(),
  m_pData()
{ CALL
  set(a_crValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
template <Tuint t_OtherSize>
inline CStaticArray<T_Type, t_Size, T_CopyPolicy>::CStaticArray(const T_Type (&a_cpArray)[t_OtherSize]) :
  NCommon::NContainers::IRandomConst<CStaticArray<T_Type, t_Size, T_CopyPolicy>, T_Type, CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>, CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> >(),
  m_pData()
{ CALL
  set(a_cpArray);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArray<T_Type, t_Size, T_CopyPolicy>::CStaticArray(const T_Type a_cpBuffer[], const Tuint a_cSize/* = t_Size */) :
  NCommon::NContainers::IRandomConst<CStaticArray<T_Type, t_Size, T_CopyPolicy>, T_Type, CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>, CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> >(),
  m_pData()
{ CALL
  set(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArray<T_Type, t_Size, T_CopyPolicy>::CStaticArray(const CStaticArray<T_Type, t_Size, T_CopyPolicy>& a_crInstance) :
  NCommon::NContainers::IRandomConst<CStaticArray<T_Type, t_Size, T_CopyPolicy>, T_Type, CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>, CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> >(),
  m_pData()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArray<T_Type, t_Size, T_CopyPolicy>::~CStaticArray()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
template <Tuint t_OtherSize>
inline CStaticArray<T_Type, t_Size, T_CopyPolicy>& CStaticArray<T_Type, t_Size, T_CopyPolicy>::operator = (const T_Type (&a_cpArray)[t_OtherSize])
{ CALL
  set(a_cpArray);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArray<T_Type, t_Size, T_CopyPolicy>& CStaticArray<T_Type, t_Size, T_CopyPolicy>::operator = (const CStaticArray<T_Type, t_Size, T_CopyPolicy>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline T_Type& CStaticArray<T_Type, t_Size, T_CopyPolicy>::operator [] (const Tsint a_cIndex)
{ CALL
  // Verify index value and the array bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < t_Size)), STR("Cannot access to the static array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline T_Type& CStaticArray<T_Type, t_Size, T_CopyPolicy>::operator [] (const Tuint a_cIndex)
{ CALL
  // Verify index value and the array bounds.
  VERIFY((!isEmpty() && (a_cIndex < t_Size)), STR("Cannot access to the static array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline const T_Type& CStaticArray<T_Type, t_Size, T_CopyPolicy>::operator [] (const Tsint a_cIndex) const
{ CALL
  // Verify index value and the array bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < t_Size)), STR("Cannot access to the static array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline const T_Type& CStaticArray<T_Type, t_Size, T_CopyPolicy>::operator [] (const Tuint a_cIndex) const
{ CALL
  // Verify index value and the array bounds.
  VERIFY((!isEmpty() && (a_cIndex < t_Size)), STR("Cannot access to the static array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArray<T_Type, t_Size, T_CopyPolicy>::operator T_Type* ()
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArray<T_Type, t_Size, T_CopyPolicy>::operator const T_Type* () const
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool CStaticArray<T_Type, t_Size, T_CopyPolicy>::set(const T_Type& a_crValue)
{ CALL
  for (Tuint i = 0; i < t_Size; ++i)
    m_pData[i] = a_crValue;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
template <Tuint t_OtherSize>
inline Tbool CStaticArray<T_Type, t_Size, T_CopyPolicy>::set(const T_Type (&a_cpArray)[t_OtherSize])
{ CALL
  // Copy array's buffer.
  T_CopyPolicy::copy(m_pData, a_cpArray, NAlgorithms::NCommon::min(t_Size, t_OtherSize));
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool CStaticArray<T_Type, t_Size, T_CopyPolicy>::set(const T_Type a_cpBuffer[], const Tuint a_cSize/* = t_Size */)
{ CALL
  // Copy array's buffer.
  T_CopyPolicy::copy(m_pData, a_cpBuffer, NAlgorithms::NCommon::min(t_Size, a_cSize));
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool CStaticArray<T_Type, t_Size, T_CopyPolicy>::set(const CStaticArray<T_Type, t_Size, T_CopyPolicy>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CStaticArray class instance."))
  {
    return false;
  }

  // Copy static array's buffer.
  return set(a_crInstance.m_pData);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tuint CStaticArray<T_Type, t_Size, T_CopyPolicy>::getFreeSize() const
{ CALL
  return (getHiCapacity() - getSize());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tuint CStaticArray<T_Type, t_Size, T_CopyPolicy>::getLoCapacity() const
{ CALL
  return 0;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tuint CStaticArray<T_Type, t_Size, T_CopyPolicy>::getHiCapacity() const
{ CALL
  return t_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline T_Type* CStaticArray<T_Type, t_Size, T_CopyPolicy>::getBuffer()
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline const T_Type* CStaticArray<T_Type, t_Size, T_CopyPolicy>::getBuffer() const
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool CStaticArray<T_Type, t_Size, T_CopyPolicy>::isEmpty() const
{ CALL
  return (t_Size == 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tuint CStaticArray<T_Type, t_Size, T_CopyPolicy>::getSize() const
{ CALL
  return t_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline typename CStaticArray<T_Type, t_Size, T_CopyPolicy>::TIterator CStaticArray<T_Type, t_Size, T_CopyPolicy>::getItFirst()
{ CALL
  TIterator it_first;

  // Filling iterator inner structure.
  it_first.m_pContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline typename CStaticArray<T_Type, t_Size, T_CopyPolicy>::TIteratorConst CStaticArray<T_Type, t_Size, T_CopyPolicy>::getItFirst() const
{ CALL
  TIteratorConst it_first;

  // Filling iterator inner structure.
  it_first.m_cpContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline typename CStaticArray<T_Type, t_Size, T_CopyPolicy>::TIterator CStaticArray<T_Type, t_Size, T_CopyPolicy>::getItLast()
{ CALL
  TIterator it_last;

  // Filling iterator inner structure.
  it_last.m_pContainer = this;
  it_last.m_Index = ((t_Size > 0) ? (t_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline typename CStaticArray<T_Type, t_Size, T_CopyPolicy>::TIteratorConst CStaticArray<T_Type, t_Size, T_CopyPolicy>::getItLast() const
{ CALL
  TIteratorConst it_last;

  // Filling iterator inner structure.
  it_last.m_cpContainer = this;
  it_last.m_Index = ((t_Size > 0) ? (t_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline typename CStaticArray<T_Type, t_Size, T_CopyPolicy>::TIterator CStaticArray<T_Type, t_Size, T_CopyPolicy>::getItIndex(const Tuint a_cIndex)
{ CALL
  TIterator it_index;

  // Filling iterator inner structure.
  it_index.m_pContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline typename CStaticArray<T_Type, t_Size, T_CopyPolicy>::TIteratorConst CStaticArray<T_Type, t_Size, T_CopyPolicy>::getItIndex(const Tuint a_cIndex) const
{ CALL
  TIteratorConst it_index;

  // Filling iterator inner structure.
  it_index.m_cpContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline void CStaticArray<T_Type, t_Size, T_CopyPolicy>::reverse()
{ CALL
  T_Type* left = m_pData;
  T_Type* right = m_pData + t_Size - 1;

  while (left < right)
    NAlgorithms::NCommon::swap(*(left++), *(right--));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
template <class T_Archive>
inline Tbool CStaticArray<T_Type, t_Size, T_CopyPolicy>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = t_Size;

  // Load the static array header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CStaticArray<T_Type, t_Size, T_CopyPolicy>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Check if the loaded static array size is equal the current one.
  ASSERT((size == t_Size), STR("Cannot load CStaticArray class instance with different size (size = %u, t_Size = %u).") COMMA size COMMA t_Size)
  {
    return false;
  }

  // Load the static array content.
  if (size > 0)
  {
    CHECK(a_rArchive.doValue(m_pData, size, STR("m_pData")));
  }

  // Load the static array end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
template <class T_Archive>
inline Tbool CStaticArray<T_Type, t_Size, T_CopyPolicy>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = t_Size;

  // Save the static array header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CStaticArray<T_Type, t_Size, T_CopyPolicy>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the static array content.
  if (!isEmpty())
  {
    CHECK(a_rArchive.doValue(m_pData, size, STR("m_pData")));
  }

  // Save the static array end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
template <class T_Archive>
inline Tbool CStaticArray<T_Type, t_Size, T_CopyPolicy>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline void CStaticArray<T_Type, t_Size, T_CopyPolicy>::swap(CStaticArray<T_Type, t_Size, T_CopyPolicy>& a_rInstance)
{ CALL
  Tuint index = 0;
  while (index < t_Size)
  {
    NAlgorithms::NCommon::swap(m_pData[index], a_rInstance.m_pData[index]);
    ++index;
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
