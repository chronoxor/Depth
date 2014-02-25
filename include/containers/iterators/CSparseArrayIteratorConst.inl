/*!
 *  \file    CSparseArrayIteratorConst.inl Sparse array constant iterator
 *           definitions. It gives ability to get sparse array items and
 *           to do random moving through the sparse array items.
 *  \brief   Sparse array constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.10.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Sparse array constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   02.10.2007 20:43:37

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
#ifndef __CSPARSEARRAYITERATORCONST_INL__
#define __CSPARSEARRAYITERATORCONST_INL__
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
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::CSparseArrayIteratorConst() :
  NCommon::NIterators::IIteratorConst<CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::ISeekable(),
  m_cpContainer(NULL),
  m_Iterator(),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::CSparseArrayIteratorConst(const CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>* a_cpContainer) :
  NCommon::NIterators::IIteratorConst<CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::ISeekable(),
  m_cpContainer(a_cpContainer),
  m_Iterator((a_cpContainer != NULL) ? a_cpContainer->getItLast() : typename TAssociativeContainer::TIteratorConst()),
  m_Index((a_cpContainer != NULL) ? a_cpContainer->getLastIndex() : 0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::CSparseArrayIteratorConst(const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::ISeekable(),
  m_cpContainer(NULL),
  m_Iterator(),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::CSparseArrayIteratorConst(const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>, T_Type, T_Type, CSparseArray<T_Type, T_AssociativeContainer, T_Allocator> >(),
  NCommon::ISeekable(),
  m_cpContainer(NULL),
  m_Iterator(),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::~CSparseArrayIteratorConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator == (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator == (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator == (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator != (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator != (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator != (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator < (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator < (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator < (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator > (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator > (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator > (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator <= (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator <= (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator <= (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator >= (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator >= (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator >= (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::operator = (const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::operator = (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::operator ++ (int)
{ CALL
  CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::operator -- (int)
{ CALL
  CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> operator + (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> operator - (const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::operator [] (const Tsint a_cIndex) const
{ CALL
  return getIndex((Tuint)a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::operator [] (const Tuint a_cIndex) const
{ CALL
  return getIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::set(const CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_pContainer;
  m_Iterator = a_crInstance.m_Iterator;
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::set(const CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_cpContainer;
  m_Iterator = a_crInstance.m_Iterator;
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::getForward() const
{ CALL
  CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::getBackward() const
{ CALL
  CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::getIndex(const Tuint a_cIndex) const
{ CALL
  CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator> it(*this);
  // Perform indexed step and return indexed iterator instance or invalid one.
  return (it.stepIndex(a_cIndex) ? it : CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline typename CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::TAssociativeContainer::TIteratorConst CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::getSparse() const
{ CALL
  return m_Iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && m_Iterator.isValid());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::isValidContainer() const
{ CALL
  return (m_cpContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>& CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const CSparseArray<T_Type, T_AssociativeContainer, T_Allocator>* CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::getContainerPtr() const
{ CALL
  return m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const T_Type& CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_Iterator.getValueRef()[m_Index];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const T_Type* CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_Iterator.getValueRef()[m_Index];
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid sparse array iterator."))
  {
    return 0;
  }

  Tuint delta = 0;
  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while (counter > 0)
  {
    delta = NAlgorithms::NCommon::min(counter, m_Iterator.getValueRef().getSecondIndex() - m_Index);
    // Step inside current interval.
    if (delta > 0)
    {
      m_Index += delta;
      counter -= delta;
    }
    // Step inside new interval.
    if (counter > 0)
    {
      if (m_Iterator.stepForward() == 0)
        break;
      m_Index = m_Iterator.getValueRef().getFirstIndex();
      --counter;
    }
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid sparse array iterator."))
  {
    return 0;
  }

  Tuint delta = 0;
  Tuint counter = a_cStepCount;
  // Try to step backward by given steps.
  while (counter > 0)
  {
    delta = NAlgorithms::NCommon::min(counter, m_Index - m_Iterator.getValueRef().getFirstIndex());
    // Step inside current interval.
    if (delta > 0)
    {
      m_Index -= delta;
      counter -= delta;
    }
    // Step inside new interval.
    if (counter > 0)
    {
      if (m_Iterator.stepBackward() == 0)
        break;
      m_Index = m_Iterator.getValueRef().getSecondIndex();
      --counter;
    }
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::stepIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot do indexed step with the invalid sparse array container."))
  {
    return false;
  }

  TIterator it = m_cpContainer->getItIndex(a_cIndex);

  // Check index value and the array bounds.
  ASSERT(it.isValid(), STR("Cannot do indexed step with the out of bounds index (index = %u).") COMMA a_cIndex)
  {
    return false;
  }

  m_Iterator = it.m_Iterator;
  m_Index = it.m_Index;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::getSize() const
{ CALL
  return (isValidContainer() ? m_cpContainer->getLastIndex() : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::setPosition(const Tuint a_cPosition)
{ CALL
  return stepIndex(a_cPosition);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::getPosition() const
{ CALL
  return m_Index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Constant iterator value cannot be loaded."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CSparseArrayIterator<T_Type, T_AssociativeContainer, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>::swap(CSparseArrayIteratorConst<T_Type, T_AssociativeContainer, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_cpContainer, a_rInstance.m_cpContainer);
  NAlgorithms::NCommon::swap(m_Iterator, a_rInstance.m_Iterator);
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
