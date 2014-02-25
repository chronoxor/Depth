/*!
 *  \file    CMultimapIteratorConst.inl Multimap constant iterator
 *           definitions. It gives ability to get multimap items.
 *  \brief   Multimap constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Multimap constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   28.09.2006 02:54:27

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
#ifndef __CMULTIMAPITERATORCONST_INL__
#define __CMULTIMAPITERATORCONST_INL__
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
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::CMultimapIteratorConst() :
  NCommon::NIterators::IIteratorConst<CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, const T_Value, const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, T_Key, const T_Value, const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, const T_Value, const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_cpContainer(NULL),
  m_Iterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::CMultimapIteratorConst(const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>* a_cpContainer) :
  NCommon::NIterators::IIteratorConst<CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, const T_Value, const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, T_Key, const T_Value, const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, const T_Value, const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_cpContainer(a_cpContainer),
  m_Iterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::CMultimapIteratorConst(const CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, const T_Value, const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, T_Key, const T_Value, const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, const T_Value, const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_cpContainer(NULL),
  m_Iterator()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::CMultimapIteratorConst(const CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, const T_Value, const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, T_Key, const T_Value, const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, const T_Value, const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >(),
  m_cpContainer(NULL),
  m_Iterator()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::~CMultimapIteratorConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator == (const CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Iterator == a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator == (const CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Iterator == a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator == (const CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Iterator == a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator != (const CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_Iterator != a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator != (const CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Iterator != a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool operator != (const CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance1, const CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_Iterator != a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator = (const CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator = (const CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator ++ (int)
{ CALL
  CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator -- (int)
{ CALL
  CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> operator + (const CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> operator - (const CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::operator [] (const T_Key& a_crKey) const
{ CALL
  return find(a_crKey);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::set(const CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_pContainer;
  m_Iterator = a_crInstance.m_Iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::set(const CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_cpContainer;
  m_Iterator = a_crInstance.m_Iterator;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getForward() const
{ CALL
  CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getBackward() const
{ CALL
  CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && m_Iterator.isValid());
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tbool CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::isValidContainer() const
{ CALL
  return (m_cpContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const CMultimap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>* CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getContainerPtr() const
{ CALL
  return m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const NUtility::CPair<T_Key, T_Value>& CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getPairRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator key/value pair for invalid iterator leads to the error."));

  return m_Iterator.getValueRef();
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const NUtility::CPair<T_Key, T_Value>* CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getPairPtr() const
{ CALL
  if (isValid())
    return m_Iterator.getValuePtr();
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const T_Key& CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getKeyRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator key for invalid iterator leads to the error."));

  return m_Iterator.getValueRef().getFirst();
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const T_Key* CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getKeyPtr() const
{ CALL
  if (isValid() && (m_Iterator.getValuePtr() != NULL))
    return &m_Iterator.getValuePtr()->getFirst();
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const T_Value& CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_Iterator.getValueRef().getSecond();
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline const T_Value* CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid() && (m_Iterator.getValuePtr() != NULL))
    return &m_Iterator.getValuePtr()->getSecond();
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::find(const T_Key& a_crKey) const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Cannot find given key in the multimap with the invalid iterator container."));

  return m_cpContainer->find(a_crKey);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid multimap iterator."))
  {
    return 0;
  }

  return m_Iterator.stepForward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline Tuint CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid multimap iterator."))
  {
    return 0;
  }

  return m_Iterator.stepBackward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Constant iterator value cannot be loaded."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CMultimapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getPairRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
template <class T_Archive>
inline Tbool CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
inline void CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::swap(CMultimapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance)
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
