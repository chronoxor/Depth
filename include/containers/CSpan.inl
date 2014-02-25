/*!
 *  \file    CSpan.inl Template span container class.
 *  \brief   Template span container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.09.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template span container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template structures and containers
    VERSION:   1.0
    CREATED:   11.09.2007 02:42:52

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
#ifndef __CSPAN_INL__
#define __CSPAN_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CSpan(T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_AssociativeContainer(NDetails::FSpanValueComparator<T_Type, T_BinaryPredicate>(a_fLessThan), a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CSpan(const T_Type& a_crItem, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_AssociativeContainer(NDetails::FSpanValueComparator<T_Type, T_BinaryPredicate>(a_fLessThan), a_crAllocator)
{ CALL
  insert(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CSpan(const T_Type& a_crItem1, const T_Type& a_crItem2, const Tbool a_cIncludeItem1/* = true */, const Tbool a_cIncludeItem2/* = true */, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_AssociativeContainer(NDetails::FSpanValueComparator<T_Type, T_BinaryPredicate>(a_fLessThan), a_crAllocator)
{ CALL
  insert(a_crItem1, a_crItem2, a_cIncludeItem1, a_cIncludeItem2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CSpan(const NDetails::CSpanValue<T_Type>& a_crSpanValue, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_AssociativeContainer(NDetails::FSpanValueComparator<T_Type, T_BinaryPredicate>(a_fLessThan), a_crAllocator)
{ CALL
  insert(a_crSpanValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CSpan(const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan/* = T_BinaryPredicate() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  NCommon::NContainers::IAssociative<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IAssociativeConst<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NContainers::IDequeConst<CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, CSpanIteratorConst<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_AssociativeContainer(a_crInstance.m_AssociativeContainer, NDetails::FSpanValueComparator<T_Type, T_BinaryPredicate>(a_fLessThan), a_crAllocator)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::~CSpan()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator = (const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator += (const T_Type& a_crItem)
{ CALL
  insert(a_crItem);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator += (const NDetails::CSpanValue<T_Type>& a_crSpanValue)
{ CALL
  insert(a_crSpanValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator += (const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crSpan)
{ CALL
  insert(a_crSpan);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -= (const T_Type& a_crItem)
{ CALL
  remove(a_crItem);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -= (const NDetails::CSpanValue<T_Type>& a_crSpanValue)
{ CALL
  remove(a_crSpanValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -= (const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crSpan)
{ CALL
  remove(a_crSpan);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator [] (const T_Type& a_crItem)
{ CALL
  return find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator [] (const T_Type& a_crItem) const
{ CALL
  return find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::set(const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  return m_AssociativeContainer.set(a_crInstance.m_AssociativeContainer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::clear()
{ CALL
  return m_AssociativeContainer.clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::isEmpty() const
{ CALL
  return m_AssociativeContainer.isEmpty();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getSize() const
{ CALL
  return m_AssociativeContainer.getSize();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const T_Type& a_crItem)
{ CALL
  return insertInternal(NDetails::CSpanValue<T_Type>(a_crItem));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const T_Type& a_crItem1, const T_Type& a_crItem2, const Tbool a_cIncludeItem1/* = true */, const Tbool a_cIncludeItem2/* = true */)
{ CALL
  return insertInternal(NDetails::CSpanValue<T_Type>(a_crItem1, a_crItem2, a_cIncludeItem1, a_cIncludeItem2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const NDetails::CSpanValue<T_Type>& a_crSpanValue)
{ CALL
  return insertInternal(a_crSpanValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crSpan)
{ CALL
  TIteratorConst it_first = a_crSpan.getItFirst();
  TIteratorConst it_current = it_first;

  if (it_current.isValid())
  {
    do
    {
      if (!insert(it_current.getValueRef()))
        return false;
    } while ((it_current.stepForward() > 0) && (it_current != it_first));
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insertInternal(const NDetails::CSpanValue<T_Type>& a_crSpanValue, TIterator* a_pIterator/* = NULL */)
{ CALL
  NDetails::CSpanValue<T_Type> value(a_crSpanValue);
  typename TAssociativeContainer::TIterator it_remove1;
  typename TAssociativeContainer::TIterator it_remove2;
  Tbool remove = false;

  // Validate span value.
  if (isLessThan(value.getSecond(), value.getFirst()))
    value.reverse();

  // Insert single value.
  if (!isLessThan(value.getFirst(), value.getSecond()) && !isLessThan(value.getSecond(), value.getFirst()))
  {
    if (value.isIncludeFirst() || value.isIncludeSecond())
    {
      value.includeFirst();
      value.includeSecond();
    }
    else
      return true;

    // Get closest span value iterator.
    TIterator it = getItClosest(value.getFirst());

    // Check span iterator.
    if (it.isValid())
    {
      Tbool insert = false;
      if (!it.m_Iterator.getValueRef().isIncludeFirst() && !isLessThan(it.m_Iterator.getValueRef().getFirst(), value.getFirst()) && !isLessThan(value.getFirst(), it.m_Iterator.getValueRef().getFirst()))
      {
        (NAlgorithms::NCommon::constCast<NDetails::CSpanValue<T_Type>&, const NDetails::CSpanValue<T_Type>&>(it.m_Iterator.getValueRef())).includeFirst();
        // Get previous span value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItFirst()) && (it_temp.stepBackward() > 0) && it_temp.isValid())
        {
          if (!isLessThan(it_temp.getValueRef().getSecond(), value.getFirst()) && !isLessThan(value.getFirst(), it_temp.getValueRef().getSecond()))
          {
            insert = true;
            remove = true;
            value.set(it_temp.getValueRef().getFirst(), it.m_Iterator.getValueRef().getSecond(), it_temp.getValueRef().isIncludeFirst(), it.m_Iterator.getValueRef().isIncludeSecond());
            it_remove1 = it_temp;
            it_remove2 = it.m_Iterator;
          }
        }
      }
      if (!it.m_Iterator.getValueRef().isIncludeSecond() && !isLessThan(it.m_Iterator.getValueRef().getSecond(), value.getFirst()) && !isLessThan(value.getFirst(), it.m_Iterator.getValueRef().getSecond()))
      {
        (NAlgorithms::NCommon::constCast<NDetails::CSpanValue<T_Type>&, const NDetails::CSpanValue<T_Type>&>(it.m_Iterator.getValueRef())).includeSecond();
        // Get next span value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItLast()) && (it_temp.stepForward() > 0) && it_temp.isValid())
        {
          if (!isLessThan(it_temp.getValueRef().getFirst(), value.getFirst()) && !isLessThan(value.getFirst(), it_temp.getValueRef().getFirst()))
          {
            insert = true;
            remove = true;
            value.set(it.m_Iterator.getValueRef().getFirst(), it_temp.getValueRef().getSecond(), it.m_Iterator.getValueRef().isIncludeFirst(), it_temp.getValueRef().isIncludeSecond());
            it_remove1 = it.m_Iterator;
            it_remove2 = it_temp;
          }
        }
      }
      if (!insert)
        return true;
    }
  }
  else
  {
    // Setup left span bound.
    TIterator it_left = getItClosest(value.getFirst(), true, false);
    if (it_left.m_Iterator.isValid() && !isLessThan(it_left.m_Iterator.getValueRef().getSecond(), value.getFirst()))
    {
      if (isLessThan(value.getFirst(), it_left.m_Iterator.getValueRef().getSecond()) || value.isIncludeFirst() || it_left.m_Iterator.getValueRef().isIncludeSecond())
      {
        remove = true;
        it_remove1 = it_left.m_Iterator;
        if (it_left.m_Iterator.getValueRef().isIncludeFirst() || (value.isIncludeFirst() && !isLessThan(it_left.m_Iterator.getValueRef().getFirst(), value.getFirst()) && !isLessThan(value.getFirst(), it_left.m_Iterator.getValueRef().getFirst())))
          value.includeFirst();
        else
          value.excludeFirst();
        value.getFirst() = it_left.m_Iterator.getValueRef().getFirst();
      }
    }
    // Setup right span bound.
    TIterator it_right = getItClosest(value.getSecond(), false, true);
    if (it_right.m_Iterator.isValid() && !isLessThan(value.getSecond(), it_right.m_Iterator.getValueRef().getFirst()))
    {
      if (isLessThan(it_right.m_Iterator.getValueRef().getFirst(), value.getSecond()) || value.isIncludeSecond() || it_right.m_Iterator.getValueRef().isIncludeFirst())
      {
        remove = true;
        it_remove2 = it_right.m_Iterator;
        if (it_right.m_Iterator.getValueRef().isIncludeSecond() || (value.isIncludeSecond() && !isLessThan(it_right.m_Iterator.getValueRef().getSecond(), value.getSecond()) && !isLessThan(value.getSecond(), it_right.m_Iterator.getValueRef().getSecond())))
          value.includeSecond();
        else
          value.excludeSecond();
        value.getSecond() = it_right.m_Iterator.getValueRef().getSecond();
      }
    }
    // Get left next iterator.
    typename TAssociativeContainer::TIterator it_left_next = it_left.m_Iterator;
    if (!it_left_next.isValid() || (it_left_next == m_AssociativeContainer.getItLast()) || (it_left_next.stepForward() == 0))
      it_left_next = typename TAssociativeContainer::TIterator();
    // Get right previous iterator.
    typename TAssociativeContainer::TIterator it_right_prev = it_right.m_Iterator;
    if (!it_right_prev.isValid() || (it_right_prev == m_AssociativeContainer.getItFirst()) || (it_right_prev.stepBackward() == 0))
      it_right_prev = typename TAssociativeContainer::TIterator();
    // Special check for whole span.
    if (!it_left.m_Iterator.isValid() && !it_right.m_Iterator.isValid())
    {
      remove = true;
      it_remove1 = m_AssociativeContainer.getItFirst();
      it_remove2 = m_AssociativeContainer.getItLast();
    }
    // Special check for right open span part.
    if (it_left.m_Iterator.isValid() && it_left_next.isValid() && !it_right.m_Iterator.isValid())
    {
      remove = true;
      if (!it_remove1.isValid())
        it_remove1 = it_left_next;
      it_remove2 = m_AssociativeContainer.getItLast();
    }
    // Special check for left open span part.
    if (it_right.m_Iterator.isValid() && it_right_prev.isValid() && !it_left.m_Iterator.isValid())
    {
      remove = true;
      it_remove1 = m_AssociativeContainer.getItFirst();
      if (!it_remove2.isValid())
        it_remove2 = it_right_prev;
    }
    // Final searching for the remove bounds.
    if (it_left.m_Iterator.isValid() && it_right.m_Iterator.isValid())
    {
      if (!it_remove1.isValid())
      {
        it_remove1 = it_left.m_Iterator;
        if (it_left_next.isValid() && (!value.isIncludeFirst() || isLessThan(it_left.m_Iterator.getValueRef().getSecond(), value.getFirst())))
          it_remove1 = it_left_next;
      }
      if (!it_remove2.isValid())
      {
        it_remove2 = it_right.m_Iterator;
        if (it_right_prev.isValid() && (!value.isIncludeSecond() || isLessThan(value.getSecond(), it_right.m_Iterator.getValueRef().getFirst())))
          it_remove2 = it_right_prev;
      }
      if (it_remove1.isValid() && it_remove2.isValid() && (it_left.m_Iterator != it_right_prev) && (it_right.m_Iterator != it_left_next))
        remove = true;
    }
  }

  // Remove span values.
  if (remove)
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
            if (!it_delete.remove())
              return false;
          }
        }
      }
      // Update span value by inserting new interval.
      (NAlgorithms::NCommon::constCast<NDetails::CSpanValue<T_Type>&, const NDetails::CSpanValue<T_Type>&>(it_remove1.getValueRef())).set(value);
      // Update returned iterator.
      if (a_pIterator != NULL)
        a_pIterator->m_Iterator = it_remove1;
      return true;
    }
  }

  // Simple insert new span value.
  if (a_pIterator != NULL)
    return a_pIterator->m_Iterator.insert(value, true);
  else
    return m_AssociativeContainer.insert(value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::remove(const T_Type& a_crItem, const Tbool a_cRemoveSame/* = false */)
{ CALL
  return remove(NDetails::CSpanValue<T_Type>(a_crItem), a_cRemoveSame);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::remove(const T_Type& a_crItem1, const T_Type& a_crItem2, const Tbool a_cIncludeItem1/* = true */, const Tbool a_cIncludeItem2/* = true */, const Tbool a_cRemoveSame/* = false */)
{ CALL
  return remove(NDetails::CSpanValue<T_Type>(a_crItem1, a_crItem2, a_cIncludeItem1, a_cIncludeItem2), a_cRemoveSame);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::remove(const NDetails::CSpanValue<T_Type>& a_crSpanValue, const Tbool a_cRemoveSame/* = false */)
{ CALL
  IGNORE_UNUSED(a_cRemoveSame);

  NDetails::CSpanValue<T_Type> value(a_crSpanValue);
  NDetails::CSpanValue<T_Type> value1;
  NDetails::CSpanValue<T_Type> value2;
  typename TAssociativeContainer::TIterator it_remove1;
  typename TAssociativeContainer::TIterator it_remove2;
  Tbool insert1 = false;
  Tbool insert2 = false;
  Tbool remove = false;

  // Validate span value.
  if (isLessThan(value.getSecond(), value.getFirst()))
    value.reverse();

  // Insert single value.
  if (!isLessThan(value.getFirst(), value.getSecond()) && !isLessThan(value.getSecond(), value.getFirst()))
  {
    if (value.isIncludeFirst() || value.isIncludeSecond())
    {
      value.includeFirst();
      value.includeSecond();
    }
    else
      return true;

    // Get closest span value iterator.
    TIterator it = getItClosest(value.getFirst());

    // Check span iterator.
    if (it.isValid())
    {
      // Check first span value.
      if (!isLessThan(it.m_Iterator.getValueRef().getFirst(), value.getFirst()) && !isLessThan(value.getFirst(), it.m_Iterator.getValueRef().getFirst()))
      {
        // Remove single span value.
        if (!isLessThan(it.m_Iterator.getValueRef().getFirst(), it.m_Iterator.getValueRef().getSecond()) && !isLessThan(it.m_Iterator.getValueRef().getSecond(), it.m_Iterator.getValueRef().getFirst()))
        {
          if (!it.remove())
            return false;
        }
        else
          (NAlgorithms::NCommon::constCast<NDetails::CSpanValue<T_Type>&, const NDetails::CSpanValue<T_Type>&>(it.m_Iterator.getValueRef())).excludeFirst();
        return true;
      }
      // Check second span value.
      if (!isLessThan(it.m_Iterator.getValueRef().getSecond(), value.getFirst()) && !isLessThan(value.getFirst(), it.m_Iterator.getValueRef().getSecond()))
      {
        // Remove single span value.
        if (!isLessThan(it.m_Iterator.getValueRef().getFirst(), it.m_Iterator.getValueRef().getSecond()) && !isLessThan(it.m_Iterator.getValueRef().getSecond(), it.m_Iterator.getValueRef().getFirst()))
        {
          if (!it.remove())
            return false;
        }
        else
          (NAlgorithms::NCommon::constCast<NDetails::CSpanValue<T_Type>&, const NDetails::CSpanValue<T_Type>&>(it.m_Iterator.getValueRef())).excludeSecond();
        return true;
      }
      // Update remove and insert settings.
      remove = true;
      it_remove1 = it.m_Iterator;
      it_remove2 = it.m_Iterator;
      insert1 = true;
      insert2 = true;
      value1.set(it.m_Iterator.getValueRef().getFirst(), value.getFirst(), it.m_Iterator.getValueRef().isIncludeFirst(), !value.isIncludeFirst());
      value2.set(value.getSecond(), it.m_Iterator.getValueRef().getSecond(), !value.isIncludeSecond(), it.m_Iterator.getValueRef().isIncludeSecond());
    }
  }
  else
  {
    // Setup left span bound.
    TIterator it_left = getItClosest(value.getFirst(), true, false);
    if (it_left.m_Iterator.isValid() && !isLessThan(it_left.m_Iterator.getValueRef().getSecond(), value.getFirst()))
    {
      if (isLessThan(value.getFirst(), it_left.m_Iterator.getValueRef().getSecond()) || (value.isIncludeFirst() && it_left.m_Iterator.getValueRef().isIncludeSecond()))
      {
        // Update remove settings.
        remove = true;
        it_remove1 = it_left.m_Iterator;
        // Update insert settings.
        if ((it_left.m_Iterator.getValueRef().isIncludeFirst() && !value.isIncludeFirst()) || (isLessThan(it_left.m_Iterator.getValueRef().getFirst(), value.getFirst()) || isLessThan(value.getFirst(), it_left.m_Iterator.getValueRef().getFirst())))
        {
          insert1 = true;
          value1.set(it_left.m_Iterator.getValueRef().getFirst(), value.getFirst(), it_left.m_Iterator.getValueRef().isIncludeFirst(), !value.isIncludeFirst());
          if (!isLessThan(value1.getFirst(), value1.getSecond()) && !isLessThan(value1.getSecond(), value1.getFirst()))
          {
            value1.includeFirst();
            value1.includeSecond();
          }
        }
      }
    }
    // Setup right span bound.
    TIterator it_right = getItClosest(value.getSecond(), false, true);
    if (it_right.m_Iterator.isValid() && !isLessThan(value.getSecond(), it_right.m_Iterator.getValueRef().getFirst()))
    {
      if (isLessThan(it_right.m_Iterator.getValueRef().getFirst(), value.getSecond()) || (value.isIncludeSecond() && it_right.m_Iterator.getValueRef().isIncludeFirst()))
      {
        // Update remove settings.
        remove = true;
        it_remove2 = it_right.m_Iterator;
        // Update insert settings.
        if ((it_right.m_Iterator.getValueRef().isIncludeSecond() && !value.isIncludeSecond()) || (isLessThan(it_right.m_Iterator.getValueRef().getSecond(), value.getSecond()) || isLessThan(value.getSecond(), it_right.m_Iterator.getValueRef().getSecond())))
        {
          insert2 = true;
          value2.set(value.getSecond(), it_right.m_Iterator.getValueRef().getSecond(), !value.isIncludeSecond(), it_right.m_Iterator.getValueRef().isIncludeSecond());
          if (!isLessThan(value2.getFirst(), value2.getSecond()) && !isLessThan(value2.getSecond(), value2.getFirst()))
          {
            value2.includeFirst();
            value2.includeSecond();
          }
        }
      }
    }
    // Get left next iterator.
    typename TAssociativeContainer::TIterator it_left_next = it_left.m_Iterator;
    if (!it_left_next.isValid() || (it_left_next == m_AssociativeContainer.getItLast()) || (it_left_next.stepForward() == 0))
      it_left_next = typename TAssociativeContainer::TIterator();
    // Get right previous iterator.
    typename TAssociativeContainer::TIterator it_right_prev = it_right.m_Iterator;
    if (!it_right_prev.isValid() || (it_right_prev == m_AssociativeContainer.getItFirst()) || (it_right_prev.stepBackward() == 0))
      it_right_prev = typename TAssociativeContainer::TIterator();
    // Special check for whole span.
    if (!it_left.m_Iterator.isValid() && !it_right.m_Iterator.isValid())
    {
      remove = true;
      it_remove1 = m_AssociativeContainer.getItFirst();
      it_remove2 = m_AssociativeContainer.getItLast();
    }
    // Special check for right open span part.
    if (it_left.m_Iterator.isValid() && it_left_next.isValid() && !it_right.m_Iterator.isValid())
    {
      remove = true;
      if (!it_remove1.isValid())
        it_remove1 = it_left_next;
      it_remove2 = m_AssociativeContainer.getItLast();
    }
    // Special check for left open span part.
    if (it_right.m_Iterator.isValid() && it_right_prev.isValid() && !it_left.m_Iterator.isValid())
    {
      remove = true;
      it_remove1 = m_AssociativeContainer.getItFirst();
      if (!it_remove2.isValid())
        it_remove2 = it_right_prev;
    }
    // Final searching for the remove bounds.
    if (it_left.m_Iterator.isValid() && it_right.m_Iterator.isValid())
    {
      if (!it_remove1.isValid())
      {
        it_remove1 = it_left.m_Iterator;
        if (it_left_next.isValid() && (!value.isIncludeFirst() || isLessThan(it_left.m_Iterator.getValueRef().getSecond(), value.getFirst())))
          it_remove1 = it_left_next;
      }
      if (!it_remove2.isValid())
      {
        it_remove2 = it_right.m_Iterator;
        if (it_right_prev.isValid() && (!value.isIncludeSecond() || isLessThan(value.getSecond(), it_right.m_Iterator.getValueRef().getFirst())))
          it_remove2 = it_right_prev;
      }
      if (it_remove1.isValid() && it_remove2.isValid() && (it_left.m_Iterator != it_right_prev) && (it_right.m_Iterator != it_left_next))
        remove = true;
    }
  }

  // Remove span values.
  if (remove)
  {
    // Update remove iterators.
    if (!it_remove1.isValid())
      it_remove1 = m_AssociativeContainer.getItFirst();
    if (!it_remove2.isValid())
      it_remove2 = m_AssociativeContainer.getItLast();
    // Remove unnecessary span values.
    if (it_remove1.isValid() && it_remove2.isValid())
    {
      typename TAssociativeContainer::TIterator it_delete;
      typename TAssociativeContainer::TIterator it_temp = it_remove1;
      Tbool stop = false;
      while (!stop)
      {
        it_delete = it_temp;
        if ((it_temp == it_remove2) || (it_temp.stepForward() == 0))
          stop = true;
        if (!it_delete.remove())
          return false;
      }
    }
  }

  // Insert span values.
  if (insert1)
    if (!m_AssociativeContainer.insert(value1))
      return false;
  if (insert2)
    if (!m_AssociativeContainer.insert(value2))
      return false;

  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::remove(const CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crSpan, const Tbool a_cRemoveSame/* = false */)
{ CALL
  TIteratorConst it_first = a_crSpan.getItFirst();
  TIteratorConst it_current = it_first;

  if (it_current.isValid())
  {
    do
    {
      if (!remove(it_current.getValueRef(), a_cRemoveSame))
        return false;
    } while ((it_current.stepForward() > 0) && (it_current != it_first));
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::isLessThan(const T_Type& a_crItem1, const T_Type& a_crItem2) const
{ CALL
  NDetails::CSpanValue<T_Type> value1(a_crItem1);
  NDetails::CSpanValue<T_Type> value2(a_crItem2);

  return m_AssociativeContainer.isLessThan(value1, value2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::find(const T_Type& a_crItem)
{ CALL
  TIterator find_iterator = getItClosest(a_crItem);

  // Check span iterator.
  if (find_iterator.isValid())
  {
    if (!find_iterator.m_Iterator.getValueRef().isIncludeFirst() && !isLessThan(find_iterator.m_Iterator.getValueRef().getFirst(), a_crItem) && !isLessThan(a_crItem, find_iterator.m_Iterator.getValueRef().getFirst()))
      find_iterator.m_Iterator = typename TAssociativeContainer::TIterator();
    if (!find_iterator.m_Iterator.getValueRef().isIncludeSecond() && !isLessThan(find_iterator.m_Iterator.getValueRef().getSecond(), a_crItem) && !isLessThan(a_crItem, find_iterator.m_Iterator.getValueRef().getSecond()))
      find_iterator.m_Iterator = typename TAssociativeContainer::TIterator();
  }
  return find_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::find(const T_Type& a_crItem) const
{ CALL
  TIteratorConst find_iterator = getItClosest(a_crItem);

  // Check span iterator.
  if (find_iterator.isValid())
  {
    if (!find_iterator.m_Iterator.getValueRef().isIncludeFirst() && !isLessThan(find_iterator.m_Iterator.getValueRef().getFirst(), a_crItem) && !isLessThan(a_crItem, find_iterator.m_Iterator.getValueRef().getFirst()))
      find_iterator.m_Iterator = typename TAssociativeContainer::TIteratorConst();
    if (!find_iterator.m_Iterator.getValueRef().isIncludeSecond() && !isLessThan(find_iterator.m_Iterator.getValueRef().getSecond(), a_crItem) && !isLessThan(a_crItem, find_iterator.m_Iterator.getValueRef().getSecond()))
      find_iterator.m_Iterator = typename TAssociativeContainer::TIteratorConst();
  }
  return find_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getItFirst()
{ CALL
  TIterator first_iterator;

  // Filling iterator inner structure.
  first_iterator.m_pContainer = this;
  first_iterator.m_Iterator = m_AssociativeContainer.getItFirst();
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getItFirst() const
{ CALL
  TIteratorConst first_iterator;

  // Filling iterator inner structure.
  first_iterator.m_cpContainer = this;
  first_iterator.m_Iterator = m_AssociativeContainer.getItFirst();
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getItLast()
{ CALL
  TIterator last_iterator;

  // Filling iterator inner structure.
  last_iterator.m_pContainer = this;
  last_iterator.m_Iterator = m_AssociativeContainer.getItLast();
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getItLast() const
{ CALL
  TIteratorConst last_iterator;

  // Filling iterator inner structure.
  last_iterator.m_cpContainer = this;
  last_iterator.m_Iterator = m_AssociativeContainer.getItLast();
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getItClosest(const T_Type& a_crValue, const Tbool a_cLeft/* = false */, const Tbool a_cRight/* = false */)
{ CALL
  // Check for valid span value bounds.
  ASSERT(!(a_cLeft && a_cRight), STR("Closest span value can be found only for left or right bound."))
  {
    return TIterator();
  }

  TIterator it;

  // Filling iterator inner structure.
  it.m_pContainer = this;
  it.m_Iterator = NAlgorithms::NContainers::lowerBound(m_AssociativeContainer, NDetails::CSpanValue<T_Type>(a_crValue), NFunctors::CFunctor<Tbool (const NDetails::CSpanValue<T_Type>&, const NDetails::CSpanValue<T_Type>&)>(m_AssociativeContainer, &TAssociativeContainer::isLessThan));
  if (!it.m_Iterator.isValid())
    it.m_Iterator = m_AssociativeContainer.getItLast();
  // Update iterator bounds.
  if (it.m_Iterator.isValid())
  {
    // Special check for a single value.
    if (!a_cLeft && !a_cRight)
    {
      if (isLessThan(a_crValue, it.m_Iterator.getValueRef().getFirst()))
      {
        // Check previous span value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if (it_temp == m_AssociativeContainer.getItFirst() || (it_temp.stepBackward() == 0) || isLessThan(it_temp.getValueRef().getSecond(), a_crValue))
          it.m_Iterator = typename TAssociativeContainer::TIterator();
        else
          it.m_Iterator = it_temp;
      }
      else if (isLessThan(it.m_Iterator.getValueRef().getSecond(), a_crValue))
      {
        // Check next span value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if ((it_temp == m_AssociativeContainer.getItLast()) || (it_temp.stepForward() == 0) || isLessThan(a_crValue, it_temp.getValueRef().getFirst()))
          it.m_Iterator = typename TAssociativeContainer::TIterator();
        else
          it.m_Iterator = it_temp;
      }
    }
    // Special check for a left bound span value.
    if (a_cLeft)
    {
      if (isLessThan(a_crValue, it.m_Iterator.getValueRef().getFirst()))
      {
        // Check previous span value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if (it_temp == m_AssociativeContainer.getItFirst() || (it_temp.stepBackward() == 0))
          it.m_Iterator = typename TAssociativeContainer::TIterator();
        else
          it.m_Iterator = it_temp;
      }
      else
      {
        // Check previous span value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItFirst()) && (it_temp.stepBackward() > 0))
          if (!isLessThan(a_crValue, it_temp.getValueRef().getSecond()) && !isLessThan(it_temp.getValueRef().getSecond(), a_crValue))
            it.m_Iterator = it_temp;
      }
    }
    // Special check for a right bound span value.
    if (a_cRight)
    {
      if (isLessThan(it.m_Iterator.getValueRef().getSecond(), a_crValue))
      {
        // Check next span value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if ((it_temp == m_AssociativeContainer.getItLast()) || (it_temp.stepForward() == 0))
          it.m_Iterator = typename TAssociativeContainer::TIterator();
        else
          it.m_Iterator = it_temp;
      }
      else if (isLessThan(a_crValue, it.m_Iterator.getValueRef().getFirst()))
      {
        // Check previous span value.
        typename TAssociativeContainer::TIterator it_temp = it.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItFirst()) && (it_temp.stepBackward() > 0))
          if (!isLessThan(it_temp.getValueRef().getSecond(), a_crValue))
            it.m_Iterator = it_temp;
      }
    }
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getItClosest(const T_Type& a_crValue, const Tbool a_cLeft/* = false */, const Tbool a_cRight/* = false */) const
{ CALL
  // Check for valid span value bounds.
  ASSERT(!(a_cLeft && a_cRight), STR("Closest span value can be found only for left or right bound."))
  {
    return TIteratorConst();
  }

  TIteratorConst it;

  // Filling iterator inner structure.
  it.m_cpContainer = this;
  it.m_Iterator = NAlgorithms::NContainers::lowerBound(m_AssociativeContainer, NDetails::CSpanValue<T_Type>(a_crValue), NFunctors::CFunctor<Tbool (const NDetails::CSpanValue<T_Type>&, const NDetails::CSpanValue<T_Type>&)>(m_AssociativeContainer, &TAssociativeContainer::isLessThan));
  if (!it.m_Iterator.isValid())
    it.m_Iterator = m_AssociativeContainer.getItLast();
  // Update iterator bounds.
  if (it.m_Iterator.isValid())
  {
    // Special check for a single value.
    if (!a_cLeft && !a_cRight)
    {
      if (isLessThan(a_crValue, it.m_Iterator.getValueRef().getFirst()))
      {
        // Check previous span value.
        typename TAssociativeContainer::TIteratorConst it_temp = it.m_Iterator;
        if (it_temp == m_AssociativeContainer.getItFirst() || (it_temp.stepBackward() == 0) || isLessThan(it_temp.getValueRef().getSecond(), a_crValue))
          it.m_Iterator = typename TAssociativeContainer::TIteratorConst();
        else
          it.m_Iterator = it_temp;
      }
      else if (isLessThan(it.m_Iterator.getValueRef().getSecond(), a_crValue))
      {
        // Check next span value.
        typename TAssociativeContainer::TIteratorConst it_temp = it.m_Iterator;
        if ((it_temp == m_AssociativeContainer.getItLast()) || (it_temp.stepForward() == 0) || isLessThan(a_crValue, it_temp.getValueRef().getFirst()))
          it.m_Iterator = typename TAssociativeContainer::TIteratorConst();
        else
          it.m_Iterator = it_temp;
      }
    }
    // Special check for a left bound span value.
    if (a_cLeft)
    {
      if (isLessThan(a_crValue, it.m_Iterator.getValueRef().getFirst()))
      {
        // Check previous span value.
        typename TAssociativeContainer::TIteratorConst it_temp = it.m_Iterator;
        if (it_temp == m_AssociativeContainer.getItFirst() || (it_temp.stepBackward() == 0))
          it.m_Iterator = typename TAssociativeContainer::TIteratorConst();
        else
          it.m_Iterator = it_temp;
      }
      else
      {
        // Check previous span value.
        typename TAssociativeContainer::TIteratorConst it_temp = it.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItFirst()) && (it_temp.stepBackward() > 0))
          if (!isLessThan(a_crValue, it_temp.getValueRef().getSecond()) && !isLessThan(it_temp.getValueRef().getSecond(), a_crValue))
            it.m_Iterator = it_temp;
      }
    }
    // Special check for a right bound span value.
    if (a_cRight)
    {
      if (isLessThan(it.m_Iterator.getValueRef().getSecond(), a_crValue))
      {
        // Check next span value.
        typename TAssociativeContainer::TIteratorConst it_temp = it.m_Iterator;
        if ((it_temp == m_AssociativeContainer.getItLast()) || (it_temp.stepForward() == 0))
          it.m_Iterator = typename TAssociativeContainer::TIteratorConst();
        else
          it.m_Iterator = it_temp;
      }
      else if (isLessThan(a_crValue, it.m_Iterator.getValueRef().getFirst()))
      {
        // Check previous span value.
        typename TAssociativeContainer::TIteratorConst it_temp = it.m_Iterator;
        if ((it_temp != m_AssociativeContainer.getItFirst()) && (it_temp.stepBackward() > 0))
          if (!isLessThan(it_temp.getValueRef().getSecond(), a_crValue))
            it.m_Iterator = it_temp;
      }
    }
  }
  return it;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Clear the current span.
  CHECK(clear());

  // Load the span header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the span content.
  while (size-- > 0)
  {
    NDetails::CSpanValue<T_Type> item;

    // Load next span item.
    CHECK(a_rArchive.doValue(item, STR("item")));
    // Insert next item into the span.
    CHECK(insert(item));
  }

  // Load the span end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the span header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>")));
    CHECK(a_rArchive.doProperty(m_AssociativeContainer.getSize(), STR("size")));
  CHECK(a_rArchive.body());

  // Save the span content.
  if (!isEmpty())
  {
    TIteratorConst it_first = getItFirst();
    TIteratorConst it_current = it_first;

    // Save all span items.
    while (it_current.isValid())
    {
      // Save next span item.
      CHECK(a_rArchive.doValue(it_current.getValueRef(), STR("item")));
      // Switch to the next span item.
      if ((it_current.stepForward() == 0) || (it_current == it_first))
        break;
    }
  }

  // Save the span end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::swap(CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_AssociativeContainer, a_rInstance.m_AssociativeContainer);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
