/*!
 *  \file    CStaticArrayIterator.inl Static array non constant iterator
 *           definitions. It gives ability to get and modify static array
 *           items and to do random moving through the static array items.
 *  \brief   Static array non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static array non constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   05.09.2006 23:05:57

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
#ifndef __CSTATICARRAYITERATOR_INL__
#define __CSTATICARRAYITERATOR_INL__
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
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::CStaticArrayIterator() :
  NCommon::NIterators::IIterator<CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>, T_Type, T_Type, CStaticArray<T_Type, t_Size, T_CopyPolicy> >(),
  NCommon::NIterators::IIteratorMoveRandom<CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>, T_Type, T_Type, CStaticArray<T_Type, t_Size, T_CopyPolicy> >(),
  NCommon::ISeekable(),
  m_pContainer(NULL),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::CStaticArrayIterator(CStaticArray<T_Type, t_Size, T_CopyPolicy>* a_pContainer) :
  NCommon::NIterators::IIterator<CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>, T_Type, T_Type, CStaticArray<T_Type, t_Size, T_CopyPolicy> >(),
  NCommon::NIterators::IIteratorMoveRandom<CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>, T_Type, T_Type, CStaticArray<T_Type, t_Size, T_CopyPolicy> >(),
  NCommon::ISeekable(),
  m_pContainer(a_pContainer),
  m_Index((a_pContainer != NULL) ? a_pContainer->getSize() : 0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::CStaticArrayIterator(const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance) :
  NCommon::NIterators::IIterator<CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>, T_Type, T_Type, CStaticArray<T_Type, t_Size, T_CopyPolicy> >(),
  NCommon::NIterators::IIteratorMoveRandom<CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>, T_Type, T_Type, CStaticArray<T_Type, t_Size, T_CopyPolicy> >(),
  NCommon::ISeekable(),
  m_pContainer(NULL),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::~CStaticArrayIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool operator == (const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance1, const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool operator != (const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance1, const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool operator < (const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance1, const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool operator > (const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance1, const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool operator <= (const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance1, const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool operator >= (const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance1, const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::operator = (const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::operator += (const Tuint a_cStepCount)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::operator -= (const Tuint a_cStepCount)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::operator ++ (int)
{ CALL
  CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::operator -- (int)
{ CALL
  CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> operator + (const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> operator - (const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::operator [] (const Tsint a_cIndex) const
{ CALL
  return getIndex((Tuint)a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::operator [] (const Tuint a_cIndex) const
{ CALL
  return getIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline void CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::set(const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::getForward() const
{ CALL
  CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::getBackward() const
{ CALL
  CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::getIndex(const Tuint a_cIndex) const
{ CALL
  CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy> it(*this);
  // Perform indexed step and return indexed iterator instance or invalid one.
  return (it.stepIndex(a_cIndex) ? it : CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::isValid() const
{ CALL
  return (isValidContainer() && (m_Index < m_pContainer->getSize()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArray<T_Type, t_Size, T_CopyPolicy>& CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline CStaticArray<T_Type, t_Size, T_CopyPolicy>* CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline T_Type& CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_pContainer->m_pData[m_Index];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline T_Type* CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_pContainer->m_pData[m_Index];
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tuint CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid static array iterator."))
  {
    return 0;
  }

  // Get available steps count.
  Tuint steps = NAlgorithms::NCommon::min(a_cStepCount, (m_pContainer->getSize() - m_Index - 1));
  // Step forward by given steps.
  m_Index += steps;
  // Return step count, that we have done.
  return steps;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tuint CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid static array iterator."))
  {
    return 0;
  }

  // Get available steps count.
  Tuint steps = NAlgorithms::NCommon::min(a_cStepCount, m_Index);
  // Step forward by given steps.
  m_Index -= steps;
  // Return step count, that we have done.
  return steps;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::stepIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot do indexed step with the invalid static array container."))
  {
    return false;
  }
  // Check index value and the array bounds.
  ASSERT(((a_cIndex < m_pContainer->getSize()) || (a_cIndex == 0)), STR("Cannot do indexed step with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_pContainer->getSize())
  {
    return false;
  }

  m_Index = a_cIndex;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tuint CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::getSize() const
{ CALL
  return (isValidContainer() ? m_pContainer->getSize() : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tbool CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::setPosition(const Tuint a_cPosition)
{ CALL
  return stepIndex(a_cPosition);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline Tuint CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::getPosition() const
{ CALL
  return (isValidContainer() ? m_Index : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
template <class T_Archive>
inline Tbool CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
inline void CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>::swap(CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pContainer, a_rInstance.m_pContainer);
  NAlgorithms::NCommon::swap(m_Index, a_rInstance.m_Index);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
