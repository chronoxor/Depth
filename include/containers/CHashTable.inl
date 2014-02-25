/*!
 *  \file    CHashTable.inl Template hash table container base class.
 *  \brief   Template hash table container base class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template hash table container base class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template structures and containers
    VERSION:   1.0
    CREATED:   11.06.2008 02:11:16

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
#ifndef __CHASHTABLE_INL__
#define __CHASHTABLE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode::SHashTableNode(const T_Key& a_crKey, const T_Value& a_crValue) :
  m_KeyValuePair(a_crKey, a_crValue)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode::SHashTableNode(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair) :
  m_KeyValuePair(a_crKeyValuePair)
{ CALL

}
/*==========================================================================*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::CHashTable(const Treal a_cGrowFactor/* = CONSTR(0.75) */, T_KeyHashFunction a_fHashFunction/* = T_KeyHashFunction() */, T_KeyBinaryPredicate a_fLessThan/* = T_KeyBinaryPredicate() */, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, CHashTableIteratorConst<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, CHashTableIteratorConst<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, NUtility::CPair<T_Key, T_Value>, CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, CHashTableIteratorConst<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >(),
  m_Size(0),
  m_FreeSize(0),
  m_FullSize(0),
  m_GrowFactor(a_cGrowFactor),
  m_fHashFunction(a_fHashFunction),
  m_fLessThan(a_fLessThan),
  m_ResizePolicy(a_cResizeFactor),
  m_Allocator(a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::~CHashTable()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator = (const CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator += (const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair)
{ CALL
  insert(a_crKeyValuePair);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator += (const CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crHashTable)
{ CALL
  insert(a_crHashTable);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator -= (const T_Key& a_crKey)
{ CALL
  remove(a_crKey);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator -= (const CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crHashTable)
{ CALL
  remove(a_crHashTable);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIterator CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator [] (const T_Key& a_crKey)
{ CALL
  TIterator it = find(a_crKey);
  if (!it.isValid())
    it.insert(a_crKey, T_Value(), true);
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIteratorConst CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::operator [] (const T_Key& a_crKey) const
{ CALL
  return find(a_crKey);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::set(const CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CHashTable class instance."))
  {
    return false;
  }

  // Clear current hash table.
  if (!clear())
    return false;

  // Save the hash table content.
  if (!a_crInstance.isEmpty())
  {
    TIteratorConst it_first = a_crInstance.getItFirst();
    TIteratorConst it_current = it_first;

    // Save all hash table values.
    while (it_current.isValid())
    {
      if (!insert(it_current.getPairRef()))
        return false;

      // Switch to the next hash table value.
      if ((it_current.stepForward() == 0) || (it_current == it_first))
        break;
    }
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tuint CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getHash(const T_Key& a_crKey) const
{ CALL
  return m_fHashFunction(a_crKey);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tuint CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getHashIndex(const T_Key& a_crKey) const
{ CALL
  return ((m_ResizePolicy.getHiCapacity() == 0) ? 0 : m_fHashFunction(a_crKey) % m_ResizePolicy.getHiCapacity());
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tuint CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getFreeSize() const
{ CALL
  return m_FreeSize;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tuint CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getFullSize() const
{ CALL
  return m_FullSize;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Treal CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getGrowFactor() const
{ CALL
  return m_GrowFactor;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tuint CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getResizeFactor() const
{ CALL
  return m_ResizePolicy.getResizeFactor();
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::setGrowFactor(const Treal a_cGrowFactor)
{ CALL
  // Check hash table grow factor to be in the (0.0, 1.0) interval.
  ASSERT(((a_cGrowFactor > 0.0) && (a_cGrowFactor < 1.0)), STR("Hash table grow factor should be great than 0.0 and less than 1.0 (GrowFactor = %r).") COMMA a_cGrowFactor)
  {
    return false;
  }

  m_GrowFactor = a_cGrowFactor;

  // Check if the hash table recalculation is required.
  Tuint new_size = (Tuint)NMath::CMath::ceil((m_FullSize - m_FreeSize) / m_GrowFactor);
  if (new_size > m_FullSize)
    return resize(new_size);
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::setResizeFactor(const Tuint a_cResizeFactor)
{ CALL
  return m_ResizePolicy.setResizeFactor(a_cResizeFactor);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::isEmpty() const
{ CALL
  return (m_Size == 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tuint CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::insert(const T_Key& a_crKey, const T_Value& a_crValue)
{ CALL
  return insertInternal(NUtility::CPair<T_Key, T_Value>(a_crKey, a_crValue), NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::insert(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair)
{ CALL
  return insertInternal(a_crKeyValuePair, NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::insert(const CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crHashTable)
{ CALL
  TIteratorConst it(a_crHashTable.getItFirst());
  if (it.isValid())
  {
    do
    {
      if (!insert(it.getPairRef()))
        return false;
    } while (it.stepForward() > 0);
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::remove(const T_Key& a_crKey, const Tbool a_cRemoveSame/* = false */)
{ CALL
  TIterator it(find(a_crKey));
  if (it.isValid())
    return removeInternal(it, a_cRemoveSame);
  else
    return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::remove(const CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crHashTable, const Tbool a_cRemoveSame/* = false */)
{ CALL
  TIteratorConst it(a_crHashTable.getItFirst());
  if (it.isValid())
  {
    do
    {
      if (!remove(it.getKeyRef(), a_cRemoveSame))
        return false;
    } while (it.stepForward() > 0);
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::resizeBy(const Tsint a_cSize)
{ CALL
  return resize((((a_cSize < 0) && (m_FullSize < (Tuint)-a_cSize)) ? 0 : (m_Size + a_cSize)));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::isLessThan(const T_Key& a_crKey1, const T_Key& a_crKey2) const
{ CALL
  return m_fLessThan(a_crKey1, a_crKey2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Clear the current hash table.
  CHECK(clear());

  // Load the hash table header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the map content.
  while (size-- > 0)
  {
    NUtility::CPair<T_Key, T_Value> item;

    // Load next hash table item.
    CHECK(a_rArchive.doValue(item, STR("item")));
    // Insert next item into the hash table.
    CHECK(insert(item));
  }

  // Load the hash table end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the hash table header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
  CHECK(a_rArchive.body());

  // Save hash table content.
  if (!isEmpty())
  {
    TIteratorConst it_first = getItFirst();
    TIteratorConst it_current = it_first;

    // Save all hash table items.
    while (it_current.isValid())
    {
      // Save next hash table item.
      CHECK(a_rArchive.doValue(it_current.getPairRef(), STR("item")));
      // Switch to the next hash table item.
      if ((it_current.stepForward() == 0) || (it_current == it_first))
        break;
    }
  }

  // Save the hash table end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline void CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::swap(CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
  NAlgorithms::NCommon::swap(m_FreeSize, a_rInstance.m_FreeSize);
  NAlgorithms::NCommon::swap(m_FullSize, a_rInstance.m_FullSize);
  NAlgorithms::NCommon::swap(m_GrowFactor, a_rInstance.m_GrowFactor);
  NAlgorithms::NCommon::swap(m_fHashFunction, a_rInstance.m_fHashFunction);
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
