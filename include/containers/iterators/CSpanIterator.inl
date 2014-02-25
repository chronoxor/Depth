/*!
 *  \file    CSpanIterator.inl Span non constant iterator definitions. It
 *           gives ability to get and modify span items.
 *  \brief   Span non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.09.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Span non constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   13.09.2007 23:00:23

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
#ifndef __CSPANITERATOR_INL__
#define __CSPANITERATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CSpanIterator() :
  NCommon::NIterators::IIterator<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_pContainer(NULL),
  m_Iterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CSpanIterator(CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>* a_pContainer) :
  NCommon::NIterators::IIterator<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_pContainer(a_pContainer),
  m_Iterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::CSpanIterator(const CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIterator<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Type, NDetails::CSpanValue<T_Type>, NDetails::CSpanValue<T_Type>, const NDetails::CSpanValue<T_Type>, CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_pContainer(NULL),
  m_Iterator()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::~CSpanIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator == (const CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Iterator == a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator != (const CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Iterator != a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator = (const CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator ++ (int)
{ CALL
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -- (int)
{ CALL
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> operator + (const CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> operator - (const CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::operator [] (const T_Type& a_crValue) const
{ CALL
  return find(a_crValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::set(const CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_Iterator = a_crInstance.m_Iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getForward() const
{ CALL
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getBackward() const
{ CALL
  CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && m_Iterator.isValid());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpan<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>* CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const NDetails::CSpanValue<T_Type>& CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_Iterator.getValueRef();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const NDetails::CSpanValue<T_Type>* CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return m_Iterator.getValuePtr();
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::find(const T_Type& a_crValue) const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Cannot find given value in the span with the invalid iterator container."));

  return m_pContainer->find(a_crValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid span iterator."))
  {
    return 0;
  }

  return m_Iterator.stepForward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid span iterator."))
  {
    return 0;
  }

  return m_Iterator.stepBackward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const T_Type& a_crItem, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new single value into the invalid span container."))
  {
    return false;
  }

  return m_pContainer->insertInternal(NDetails::CSpanValue<T_Type>(a_crItem), (a_cUpdate ? this : NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const T_Type& a_crItem1, const T_Type& a_crItem2, const Tbool a_cIncludeItem1/* = true */, const Tbool a_cIncludeItem2/* = true */, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new interval into the invalid span container."))
  {
    return false;
  }

  return m_pContainer->insertInternal(NDetails::CSpanValue<T_Type>(a_crItem1, a_crItem2, a_cIncludeItem1, a_cIncludeItem2), (a_cUpdate ? this : NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::insert(const NDetails::CSpanValue<T_Type>& a_crSpanValue, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new span value into the invalid span container."))
  {
    return false;
  }

  return m_pContainer->insertInternal(a_crSpanValue, (a_cUpdate ? this : NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::remove()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove span value from the invalid span iterator."))
  {
    return false;
  }

  return m_Iterator.remove();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::remove(T_Type& a_rItem1, T_Type& a_rItem2, Tbool& a_rIncludeItem1, Tbool& a_rIncludeItem2)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove span value from the invalid span iterator."))
  {
    return false;
  }

  NDetails::CSpanValue<T_Type> temp;

  if (m_Iterator.remove(temp))
  {
    a_rItem1 = temp.getFirst();
    a_rItem2 = temp.getSecond();
    a_rIncludeItem1 = temp.isIncludeFirst();
    a_rIncludeItem2 = temp.isIncludeSecond();
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::remove(NDetails::CSpanValue<T_Type>& a_rSpanValue)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove span value from the invalid span iterator."))
  {
    return false;
  }

  return m_Iterator.remove(a_rSpanValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  NDetails::CSpanValue<T_Type> value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
    CHECK(insert(value, true));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::swap(CSpanIterator<T_Type, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pContainer, a_rInstance.m_pContainer);
  NAlgorithms::NCommon::swap(m_Iterator, a_rInstance.m_Iterator);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
