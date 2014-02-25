/*!
 *  \file    CSortedArrayIterator.inl Sorted array non constant iterator
 *           definitions. It gives ability to get and modify sorted array
 *           items and to do random moving through the sorted array items.
 *  \brief   Sorted array non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Sorted array non constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   30.09.2006 21:05:36

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
#ifndef __CSORTEDARRAYITERATOR_INL__
#define __CSORTEDARRAYITERATOR_INL__
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
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CSortedArrayIterator() :
  NCommon::NIterators::IIterator<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveRandom<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_pContainer(NULL),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CSortedArrayIterator(CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>* a_pContainer) :
  NCommon::NIterators::IIterator<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveRandom<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_pContainer(a_pContainer),
  m_Index((a_pContainer != NULL) ? a_pContainer->getSize() : 0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CSortedArrayIterator(const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIterator<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertAssociative<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveAssociative<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveRandom<CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, const T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_pContainer(NULL),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::~CSortedArrayIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator == (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator != (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator < (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator > (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator <= (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator >= (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator = (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator += (const Tuint a_cStepCount)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator -= (const Tuint a_cStepCount)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator ++ (int)
{ CALL
  CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator -- (int)
{ CALL
  CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator + (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator - (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const T_Type& a_crItem) const
{ CALL
  return find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tsint a_cIndex) const
{ CALL
  return getIndex((Tuint)a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tuint a_cIndex) const
{ CALL
  return getIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getForward() const
{ CALL
  CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getBackward() const
{ CALL
  CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getIndex(const Tuint a_cIndex) const
{ CALL
  CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> it(*this);
  // Perform indexed step and return indexed iterator instance or invalid one.
  return (it.stepIndex(a_cIndex) ? it : CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && (m_Index < m_pContainer->getSize()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>* CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const T_Type& CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_pContainer->m_pData[m_Index];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const T_Type* CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_pContainer->m_pData[m_Index];
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::find(const T_Type& a_crItem) const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Cannot find given item in the sorted array with the invalid iterator container."));

  return m_pContainer->find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid sorted array iterator."))
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
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid sorted array iterator."))
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
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::stepIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot do indexed step with the invalid sorted array container."))
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
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::insert(const T_Type& a_crItem, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid sorted array container."))
  {
    return false;
  }

  Tuint index = 0;
  CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> it = NAlgorithms::NIterators::upperBoundNext(m_pContainer->getItFirst(), a_crItem, m_pContainer->m_fLessThan);

  // Get insert index.
  if (it.isValid())
  {
    index = it.m_Index;
    if (m_pContainer->isLessThan(it.getValueRef(), a_crItem))
      ++index;
  }

  // Resize sorted array to insert one item.
  if (m_pContainer->resize(m_pContainer->m_Size + 1))
  {
    // Shift part of sorted array to the right.
    T_CopyPolicy::move(m_pContainer->m_pData + index + 1, m_pContainer->m_pData + index, m_pContainer->m_Size - index - 1);
    // Copy item into place under the index.
    m_pContainer->m_pData[index] = a_crItem;
    // Update iterator if need.
    if (a_cUpdate)
      m_Index = index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::remove()
{ CALL
  return removeBackward();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::remove(T_Type& a_rItem)
{ CALL
  return removeBackward(a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeForward()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid sorted array iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index))
  {
    if ((m_Index > 0) && (m_Index == m_pContainer->getSize()))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeForward(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid sorted array iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index, a_rItem))
  {
    if ((m_Index > 0) && (m_Index == m_pContainer->getSize()))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeNext()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid sorted array iterator."))
  {
    return false;
  }
  // Check index value and the sorted array bounds.
  ASSERT(((m_Index + 1) < m_pContainer->getSize()), STR("Cannot remove item from the next forward sorted array position without a corresponding item, from the end sorted array position (index = %u, size = %u).") COMMA (m_Index + 1) COMMA m_pContainer->getSize())
  {
    return false;
  }

  return m_pContainer->removeIndex(m_Index + 1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeNext(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid sorted array iterator."))
  {
    return false;
  }
  // Check index value and the sorted array bounds.
  ASSERT(((m_Index + 1) < m_pContainer->getSize()), STR("Cannot remove item from the next forward sorted array position without a corresponding item, from the end sorted array position (index = %u, size = %u).") COMMA (m_Index + 1) COMMA m_pContainer->getSize())
  {
    return false;
  }

  return m_pContainer->removeIndex(m_Index + 1, a_rItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeBackward()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid sorted array iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index))
  {
    if (m_Index > 0)
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeBackward(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid sorted array iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index, a_rItem))
  {
    if (m_Index > 0)
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removePrev()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid sorted array iterator."))
  {
    return false;
  }
  // Check index value and the sorted array bounds.
  ASSERT((m_Index > 0), STR("Cannot remove item from the previous backward sorted array position without a corresponding item, from the begin sorted array position (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index - 1))
  {
    --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removePrev(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid sorted array iterator."))
  {
    return false;
  }
  // Check index value and the sorted array bounds.
  ASSERT((m_Index > 0), STR("Cannot remove item from the previous backward sorted array position without a corresponding item, from the begin sorted array position (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index - 1, a_rItem))
  {
    --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid sorted array iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(a_cIndex))
  {
    if ((m_Index > 0) && (m_Index >= a_cIndex))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::removeIndex(const Tuint a_cIndex, T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid sorted array iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(a_cIndex, a_rItem))
  {
    if ((m_Index > 0) && (m_Index >= a_cIndex))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::remove(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove items interval from the invalid sorted array iterator."))
  {
    return false;
  }

  // Calculate real count of removing items.
  Tuint size = NAlgorithms::NCommon::min(m_pContainer->getSize() - a_cIndex, a_cSize);

  if (m_pContainer->remove(a_cIndex, a_cSize))
  {
    if ((m_Index > 0) && (m_Index >= a_cIndex))
    {
      if (m_Index >= (a_cIndex + size))
        m_Index -= size;
      else
        m_Index = a_cIndex;
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getSize() const
{ CALL
  return (isValidContainer() ? m_pContainer->getSize() : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::setPosition(const Tuint a_cPosition)
{ CALL
  return stepIndex(a_cPosition);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getPosition() const
{ CALL
  return (isValidContainer() ? m_Index : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  T_Type value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
    CHECK(insert(value, true));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::swap(CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_rInstance)
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
