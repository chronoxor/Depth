/*!
 *  \file    CStringBufferIteratorConst.inl String buffer constant iterator
 *           definitions. It gives ability to get string buffer items and
 *           to do random moving through the string buffer items.
 *  \brief   String buffer constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: String buffer constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   07.04.2009 23:43:06

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
#ifndef __CSTRINGBUFFERITERATORCONST_INL__
#define __CSTRINGBUFFERITERATORCONST_INL__
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
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::CStringBufferIteratorConst() :
  NCommon::NIterators::IIteratorConst<CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>, T_Type, T_Type, CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>, T_Type, T_Type, CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_cpContainer(NULL),
  m_Iterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::CStringBufferIteratorConst(const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>* a_cpContainer) :
  NCommon::NIterators::IIteratorConst<CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>, T_Type, T_Type, CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>, T_Type, T_Type, CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_cpContainer(a_cpContainer),
  m_Iterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::CStringBufferIteratorConst(const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>, T_Type, T_Type, CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>, T_Type, T_Type, CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_cpContainer(NULL),
  m_Iterator()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::CStringBufferIteratorConst(const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>, T_Type, T_Type, CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>, T_Type, T_Type, CStringBuffer<T_Type, T_ResizePolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_cpContainer(NULL),
  m_Iterator()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::~CStringBufferIteratorConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator == (const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Iterator == a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator == (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Iterator == a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator == (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Iterator == a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator != (const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_Iterator != a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator != (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Iterator != a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator != (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_Iterator != a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator < (const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Iterator < a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator < (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Iterator < a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator < (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Iterator < a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator > (const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Iterator > a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator > (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Iterator > a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator > (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Iterator > a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator <= (const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Iterator <= a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator <= (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Iterator <= a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator <= (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Iterator <= a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator >= (const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Iterator >= a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator >= (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Iterator >= a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool operator >= (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance1, const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Iterator >= a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::operator = (const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::operator = (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::operator ++ (int)
{ CALL
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::operator -- (int)
{ CALL
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> operator + (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> operator - (const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::operator [] (const Tsint a_cIndex) const
{ CALL
  return getIndex((Tuint)a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::operator [] (const Tuint a_cIndex) const
{ CALL
  return getIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline void CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::set(const CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_pContainer;
  m_Iterator = a_crInstance.m_Iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline void CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::set(const CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_cpContainer;
  m_Iterator = a_crInstance.m_Iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::getForward() const
{ CALL
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::getBackward() const
{ CALL
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::getIndex(const Tuint a_cIndex) const
{ CALL
  CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator> it(*this);
  // Perform indexed step and return indexed iterator instance or invalid one.
  return (it.stepIndex(a_cIndex) ? it : CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && m_Iterator.isValid());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::isValidContainer() const
{ CALL
  return (m_cpContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>& CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline const CStringBuffer<T_Type, T_ResizePolicy, T_Allocator>* CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::getContainerPtr() const
{ CALL
  return m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline const T_Type& CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return *m_cpContainer->m_StringArray.getBuffer()[m_Iterator.getPosition()];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline const T_Type* CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return m_cpContainer->m_StringArray.getBuffer()[m_Iterator.getPosition()];
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tuint CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid string buffer iterator."))
  {
    return 0;
  }

  return m_Iterator.stepForward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tuint CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid string buffer iterator."))
  {
    return 0;
  }

  return m_Iterator.stepBackward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::stepIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot do indexed step with the invalid string buffer container."))
  {
    return false;
  }
  // Check index value and the string buffer bounds.
  ASSERT(((a_cIndex < m_cpContainer->getSize()) || (a_cIndex == 0)), STR("Cannot do indexed step with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_cpContainer->getSize())
  {
    return false;
  }

  return m_Iterator.stepIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tuint CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::getSize() const
{ CALL
  return (isValidContainer() ? m_cpContainer->getSize() : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tbool CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::setPosition(const Tuint a_cPosition)
{ CALL
  return stepIndex(a_cPosition);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline Tuint CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::getPosition() const
{ CALL
  return m_Iterator.getPosition();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Constant iterator value cannot be loaded."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CStringBufferIterator<T_Type, T_ResizePolicy, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_ResizePolicy, class T_Allocator>
inline void CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>::swap(CStringBufferIteratorConst<T_Type, T_ResizePolicy, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_cpContainer, a_rInstance.m_cpContainer);
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
