/*!
 *  \file    CRandomBufferReal.inl Random real numbers buffer container class.
 *  \brief   Random real numbers buffer container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Random real numbers buffer container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 00:04:55

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
#ifndef __CRANDOMBUFFERREAL_INL__
#define __CRANDOMBUFFERREAL_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::CRandomBufferReal(const T_RandomGenerator& a_crRandomGenerator/* = T_RandomGenerator() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  T_RandomGenerator(a_crRandomGenerator),
  NCommon::NContainers::IContainer<CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>, Treal, CRandomBufferRealIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>, CRandomBufferRealIteratorConst<T_RandomGenerator, T_DequeContainer, T_Allocator> >(),
  NCommon::NContainers::ICircleDoubleLinkedConst<CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>, Treal, CRandomBufferRealIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>, CRandomBufferRealIteratorConst<T_RandomGenerator, T_DequeContainer, T_Allocator> >(),
  m_DequeContainer(a_crAllocator),
  m_ItIndex()
{ CALL
  m_ItIndex = m_DequeContainer.getItFirst();
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::CRandomBufferReal(const CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  T_RandomGenerator(a_crInstance),
  NCommon::NContainers::IContainer<CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>, Treal, CRandomBufferRealIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>, CRandomBufferRealIteratorConst<T_RandomGenerator, T_DequeContainer, T_Allocator> >(),
  NCommon::NContainers::ICircleDoubleLinkedConst<CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>, Treal, CRandomBufferRealIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>, CRandomBufferRealIteratorConst<T_RandomGenerator, T_DequeContainer, T_Allocator> >(),
  m_DequeContainer(a_crInstance.m_DequeContainer, a_crAllocator),
  m_ItIndex()
{ CALL
  setIteratorByIndex(a_crInstance.getIndexByIterator());
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::~CRandomBufferReal()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>& CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::operator = (const CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline Tbool CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::set(const CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomBufferReal class instance."))
  {
    return false;
  }

  if (m_DequeContainer.set(a_crInstance.m_DequeContainer))
    return setIteratorByIndex(a_crInstance.getIndexByIterator());
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline Tbool CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::clear()
{ CALL
  return m_DequeContainer.clear();
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline Tbool CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::isEmpty() const
{ CALL
  return m_DequeContainer.isEmpty();
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline Tuint CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::getSize() const
{ CALL
  return m_DequeContainer.getSize();
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline Tuint CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  Tuint counter = a_cStepCount - (!m_ItIndex.isValid() ? 0 : m_ItIndex.stepForward(a_cStepCount));
  // Try to step forward by given steps.
  while (counter > 0)
  {
    if (!m_DequeContainer.insertLast(T_RandomGenerator::randomReal()))
      break;
    m_ItIndex = m_DequeContainer.getItLast();
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline Tuint CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  Tuint counter = a_cStepCount - (!m_ItIndex.isValid() ? 0 : m_ItIndex.stepBackward(a_cStepCount));
  // Try to step backward by given steps.
  while (counter > 0)
  {
    if (!m_DequeContainer.insertFirst(T_RandomGenerator::randomReal()))
      break;
    m_ItIndex = m_DequeContainer.getItFirst();
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline Treal CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::randomRealCurrent()
{ CALL
  if (m_ItIndex.isValid())
    return m_ItIndex.getValueRef();
  else
  {
    if (!m_DequeContainer.insertLast(T_RandomGenerator::randomReal()))
      return 0;
    m_ItIndex = m_DequeContainer.getItLast();
    return m_ItIndex.isValid() ? m_ItIndex.getValueRef() : 0;
  }
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline Treal CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::randomRealNext()
{ CALL
  if (stepForward() == 0)
    return 0;
  return randomRealCurrent();
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline Treal CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::randomRealPrev()
{ CALL
  Treal result = randomRealCurrent();
  stepBackward();
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline Tuint CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::getIndexByIterator() const
{ CALL
  typename TDequeContainer::TIteratorConst it_first = m_DequeContainer.getItFirst();
  typename TDequeContainer::TIteratorConst it_current = m_ItIndex;

  if (!it_first.isValid || !it_current.isValid())
    return 0;

  Tuint index = 0;
  while (it_first.isValid())
  {
    // Compare iterators.
    if (it_first == it_current)
      return index;

    // Switch to the next random numbers buffer item.
    if ((it_first.stepForward() == 0) || (it_first == m_DequeContainer.getItFirst()))
      break;

    // Increment index.
    ++index;
  }
  return index;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline Tbool CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::setIteratorByIndex(const Tuint a_cIndex) const
{ CALL
  typename TDequeContainer::TIteratorConst it_first = m_DequeContainer.getItFirst();

  if (!it_first.isValid)
  {
    m_ItIndex = it_first;
    return false;
  }

  Tuint index = 0;
  while (it_first.isValid())
  {
    // Compare indexes.
    if (index == a_cIndex)
    {
      m_ItIndex = it_first;
      return true;
    }

    // Switch to the next random numbers buffer item.
    if ((it_first.stepForward() == 0) || (it_first == m_DequeContainer.getItFirst()))
      break;

    // Increment index.
    ++index;
  }
  WARNING(STR("Cannot find deque iterator with the given index (index = %u).") COMMA a_cIndex);
  m_ItIndex = typename TDequeContainer::TIterator();
  return false;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline typename CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::TIterator CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::getItCurrent()
{ CALL
  TIterator current_iterator;

  // Filling iterator inner structure.
  current_iterator.m_pContainer = this;
  current_iterator.m_Iterator = m_ItIndex;
  // Create new current random number value.
  if (!current_iterator.m_Iterator.isValid())
  {
    if (m_DequeContainer.insertLast(T_RandomGenerator::randomReal()))
    {
      m_ItIndex = m_DequeContainer.getItLast();
      current_iterator.m_Iterator = m_DequeContainer.getItLast();
    }
    else
      current_iterator.m_Iterator = typename TDequeContainer::TIterator();
  }
  return current_iterator;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline typename CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::TIteratorConst CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::getItCurrent() const
{ CALL
  TIteratorConst current_iterator;

  // Filling iterator inner structure.
  current_iterator.m_cpContainer = this;
  current_iterator.m_Iterator = m_ItIndex;
  return current_iterator;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline typename CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::TIterator CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::getItNext()
{ CALL
  TIterator next_iterator;

  // Filling iterator inner structure.
  next_iterator.m_pContainer = this;
  next_iterator.m_Iterator = m_ItIndex;
  // Create new next random number value.
  if (!next_iterator.m_Iterator.isValid() || (next_iterator.m_Iterator.stepForward() == 0))
  {
    if (m_DequeContainer.insertLast(T_RandomGenerator::randomReal()))
    {
      if (!m_ItIndex.isValid())
        m_ItIndex = m_DequeContainer.getItLast();
      next_iterator.m_Iterator = m_DequeContainer.getItLast();
    }
    else
      next_iterator.m_Iterator = typename TDequeContainer::TIterator();
  }
  return next_iterator;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline typename CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::TIteratorConst CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::getItNext() const
{ CALL
  TIteratorConst next_iterator;

  // Filling iterator inner structure.
  next_iterator.m_cpContainer = this;
  next_iterator.m_Iterator = m_ItIndex;
  // Move to the next random number value.
  if (next_iterator.m_Iterator.isValid() && (next_iterator.m_Iterator.stepForward() == 0))
    next_iterator.m_Iterator = typename TDequeContainer::TIterator();
  return next_iterator;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline typename CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::TIterator CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::getItPrev()
{ CALL
  TIterator prev_iterator;

  // Filling iterator inner structure.
  prev_iterator.m_pContainer = this;
  prev_iterator.m_Iterator = m_ItIndex;
  // Create new previous random number value.
  if (!prev_iterator.m_Iterator.isValid() || (prev_iterator.m_Iterator.stepBackward() == 0))
  {
    if (m_DequeContainer.insertFirst(T_RandomGenerator::randomReal()))
    {
      if (!m_ItIndex.isValid())
        m_ItIndex = m_DequeContainer.getItFirst();
      prev_iterator.m_Iterator = m_DequeContainer.getItFirst();
    }
    else
      prev_iterator.m_Iterator = typename TDequeContainer::TIterator();
  }
  return prev_iterator;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline typename CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::TIteratorConst CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::getItPrev() const
{ CALL
  TIteratorConst prev_iterator;

  // Filling iterator inner structure.
  prev_iterator.m_cpContainer = this;
  prev_iterator.m_Iterator = m_ItIndex;
  // Move to the previous random number value.
  if (prev_iterator.m_Iterator.isValid() && (prev_iterator.m_Iterator.stepBackward() == 0))
    prev_iterator.m_Iterator = typename TDequeContainer::TIterator();
  return prev_iterator;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;
  Tuint index = 0;

  // Clear the current random numbers buffer.
  CHECK(clear());

  // Load the random numbers buffer header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NRandom::CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
    CHECK(a_rArchive.doProperty(index, STR("index")));
  CHECK(a_rArchive.body());

  // Load base random generator.
  CHECK(a_rArchive.doValue((T_RandomGenerator&)(*this), STR("base")));

  // Load the random numbers buffer content.
  while (size-- > 0)
  {
    Treal item;

    // Load next random numbers buffer item.
    CHECK(a_rArchive.doValue(item, STR("item")));
    // Insert next item into the random numbers buffer.
    CHECK(m_DequeContainer.insertLast(item));
  }

  // Restore random numbers buffer index iterator.
  CHECK(setIteratorByIndex(index));

  // Load the random numbers buffer end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the random numbers buffer header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NRandom::CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_DequeContainer.getSize(), STR("size")));
    CHECK(a_rArchive.doProperty(getIndexByIterator(), STR("index")));
  CHECK(a_rArchive.body());

  // Save base random generator.
  CHECK(a_rArchive.doValue((T_RandomGenerator&)(*this), STR("base")));

  // Save the random numbers buffer content.
  if (!isEmpty())
  {
    typename TDequeContainer::TIterator it_first = m_DequeContainer.getItFirst();
    typename TDequeContainer::TIterator it_current = it_first;

    // Save all random numbers buffer items.
    while (it_current.isValid())
    {
      // Save next random numbers buffer item.
      CHECK(a_rArchive.doValue(it_current.getValueRef(), STR("item")));
      // Switch to the next random numbers buffer item.
      if ((it_current.stepForward() == 0) || (it_current == it_first))
        break;
    }
  }

  // Save the random numbers buffer end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
inline void CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>::swap(CRandomBufferReal<T_RandomGenerator, T_DequeContainer, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((T_RandomGenerator&)(*this), (T_RandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_DequeContainer, a_rInstance.m_DequeContainer);
  NAlgorithms::NCommon::swap(m_ItIndex, a_rInstance.m_ItIndex);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
