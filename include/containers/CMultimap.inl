/*!
 *  \file    CMultimap.inl Template multimap container class.
 *  \brief   Template multimap container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template multimap container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template structures and containers
    VERSION:   1.0
    CREATED:   29.09.2006 02:28:36

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
#ifndef __CMULTIMAP_INL__
#define __CMULTIMAP_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::CMultimap(T_KeyBinaryPredicate a_fLessThan/* = T_KeyBinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Key, T_Value>, CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_AssociativeContainer(NAlgorithms::NFunctions::FMapComparator<T_Key, T_Value, T_KeyBinaryPredicate>(a_fLessThan), a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::CMultimap(const T_Key& a_crKey, const T_Value& a_crValue, T_KeyBinaryPredicate a_fLessThan/* = T_KeyBinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Key, T_Value>, CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_AssociativeContainer(NUtility::CPair<T_Key, T_Value>(a_crKey, a_crValue), NAlgorithms::NFunctions::FMapComparator<T_Key, T_Value, T_KeyBinaryPredicate>(a_fLessThan), a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::CMultimap(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair, T_KeyBinaryPredicate a_fLessThan/* = T_KeyBinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Key, T_Value>, CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_AssociativeContainer(a_crKeyValuePair, NAlgorithms::NFunctions::FMapComparator<T_Key, T_Value, T_KeyBinaryPredicate>(a_fLessThan), a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::CMultimap(const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance, T_KeyBinaryPredicate a_fLessThan/* = T_KeyBinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Key, T_Value>, CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_AssociativeContainer(a_crInstance.m_AssociativeContainer, NAlgorithms::NFunctions::FMapComparator<T_Key, T_Value, T_KeyBinaryPredicate>(a_fLessThan), a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::~CMultimap()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator = (const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator += (const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair)
{ CALL
  insert(a_crKeyValuePair);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator += (const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crMultimap)
{ CALL
  insert(a_crMultimap);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -= (const T_Key& a_crKey)
{ CALL
  remove(a_crKey);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -= (const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crMultimap)
{ CALL
  remove(a_crMultimap);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator [] (const T_Key& a_crKey)
{ CALL
  return find(a_crKey);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator [] (const T_Key& a_crKey) const
{ CALL
  return find(a_crKey);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::set(const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  return m_AssociativeContainer.set(a_crInstance.m_AssociativeContainer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::clear()
{ CALL
  return m_AssociativeContainer.clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::isEmpty() const
{ CALL
  return m_AssociativeContainer.isEmpty();
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getSize() const
{ CALL
  return m_AssociativeContainer.getSize();
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const T_Key& a_crKey, const T_Value& a_crValue)
{ CALL
  return m_AssociativeContainer.insert(NUtility::CPair<T_Key, T_Value>(a_crKey, a_crValue));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair)
{ CALL
  return m_AssociativeContainer.insert(a_crKeyValuePair);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crMultimap)
{ CALL
  typename CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst it_first = a_crMultimap.getItFirst();
  typename CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst it_current = it_first;

  if (it_current.isValid())
  {
    do
    {
      if (!insert(it_current.getPairRef()))
        return false;
    } while ((it_current.stepForward() > 0) && (it_current != it_first));
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::remove(const T_Key& a_crKey, const Tbool a_cRemoveSame/* = false */)
{ CALL
  typename CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator it(find(a_crKey));

  return (it.isValid() ? m_AssociativeContainer.remove(it.getPairRef(), a_cRemoveSame) : false);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::remove(const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crMultimap, const Tbool a_cRemoveSame/* = false */)
{ CALL
  return m_AssociativeContainer.remove(a_crMultimap.m_AssociativeContainer, a_cRemoveSame);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::isLessThan(const T_Key& a_crKey1, const T_Key& a_crKey2) const
{ CALL
  NUtility::CPair<T_Key, T_Value> key1(a_crKey1, T_Value());
  NUtility::CPair<T_Key, T_Value> key2(a_crKey2, T_Value());

  return m_AssociativeContainer.isLessThan(key1, key2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::find(const T_Key& a_crKey)
{ CALL
  TIterator find_iterator;

  // Filling iterator inner structure.
  find_iterator.m_pContainer = this;
  find_iterator.m_Iterator = m_AssociativeContainer.find(NUtility::CPair<T_Key, T_Value>(a_crKey, T_Value()));
  return find_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::find(const T_Key& a_crKey) const
{ CALL
  TIteratorConst find_iterator;

  // Filling iterator inner structure.
  find_iterator.m_cpContainer = this;
  find_iterator.m_Iterator = m_AssociativeContainer.find(NUtility::CPair<T_Key, T_Value>(a_crKey, T_Value()));
  return find_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getItFirst()
{ CALL
  TIterator first_iterator;

  // Filling iterator inner structure.
  first_iterator.m_pContainer = this;
  first_iterator.m_Iterator = m_AssociativeContainer.getItFirst();
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getItFirst() const
{ CALL
  TIteratorConst first_iterator;

  // Filling iterator inner structure.
  first_iterator.m_cpContainer = this;
  first_iterator.m_Iterator = m_AssociativeContainer.getItFirst();
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getItLast()
{ CALL
  TIterator last_iterator;

  // Filling iterator inner structure.
  last_iterator.m_pContainer = this;
  last_iterator.m_Iterator = m_AssociativeContainer.getItLast();
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getItLast() const
{ CALL
  TIteratorConst last_iterator;

  // Filling iterator inner structure.
  last_iterator.m_cpContainer = this;
  last_iterator.m_Iterator = m_AssociativeContainer.getItLast();
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Clear the current multimap.
  CHECK(clear());

  // Load the multimap header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the multimap content.
  while (size-- > 0)
  {
    NUtility::CPair<T_Key, T_Value> item;

    // Load next multimap item.
    CHECK(a_rArchive.doValue(item, STR("item")));
    // Insert next item into the multimap.
    CHECK(insert(item));
  }

  // Load the multimap end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the multimap header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_AssociativeContainer.getSize(), STR("size")));
  CHECK(a_rArchive.body());

  // Save the multimap content.
  if (!isEmpty())
  {
    TIteratorConst it_first = getItFirst();
    TIteratorConst it_current = it_first;

    // Save all multimap items.
    while (it_current.isValid())
    {
      // Save next multimap item.
      CHECK(a_rArchive.doValue(it_current.getPairRef(), STR("item")));
      // Switch to the next multimap item.
      if ((it_current.stepForward() == 0) || (it_current == it_first))
        break;
    }
  }

  // Save the multimap end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::swap(CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_AssociativeContainer, a_rInstance.m_AssociativeContainer);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
