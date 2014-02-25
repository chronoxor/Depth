/*!
 *  \file    CWrappedItemIteratorConst.inl Wrapped item constant iterator
 *           definitions. It gives ability to get wrapped item and
 *           to do random moving through the single wrapped item.
 *  \brief   Wrapped item constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Wrapped item constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   06.05.2009 03:44:57

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
#ifndef __CWRAPPEDITEMITERATORCONST_INL__
#define __CWRAPPEDITEMITERATORCONST_INL__
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
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type>::CWrappedItemIteratorConst() :
  NCommon::NIterators::IIteratorConst<CWrappedItemIteratorConst<T_Type>, T_Type, T_Type, T_Type>(),
  NCommon::NIterators::IIteratorMoveRandom<CWrappedItemIteratorConst<T_Type>, T_Type, T_Type, T_Type>(),
  NCommon::ISeekable(),
  m_cpValue(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type>::CWrappedItemIteratorConst(const T_Type& a_crValue) :
  NCommon::NIterators::IIteratorConst<CWrappedItemIteratorConst<T_Type>, T_Type, T_Type, T_Type>(),
  NCommon::NIterators::IIteratorMoveRandom<CWrappedItemIteratorConst<T_Type>, T_Type, T_Type, T_Type>(),
  NCommon::ISeekable(),
  m_cpValue(NULL)
{ CALL
  set(a_crValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type>::CWrappedItemIteratorConst(const CWrappedItemIteratorConst<T_Type>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CWrappedItemIteratorConst<T_Type>, T_Type, T_Type, T_Type>(),
  NCommon::NIterators::IIteratorMoveRandom<CWrappedItemIteratorConst<T_Type>, T_Type, T_Type, T_Type>(),
  NCommon::ISeekable(),
  m_cpValue(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type>::~CWrappedItemIteratorConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator == (const CWrappedItemIteratorConst<T_Type>& a_crInstance1, const CWrappedItemIteratorConst<T_Type>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_cpValue == a_crInstance2.m_cpValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator != (const CWrappedItemIteratorConst<T_Type>& a_crInstance1, const CWrappedItemIteratorConst<T_Type>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_cpValue != a_crInstance2.m_cpValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator < (const CWrappedItemIteratorConst<T_Type>& a_crInstance1, const CWrappedItemIteratorConst<T_Type>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_cpValue == a_crInstance2.m_cpValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator > (const CWrappedItemIteratorConst<T_Type>& a_crInstance1, const CWrappedItemIteratorConst<T_Type>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_cpValue == a_crInstance2.m_cpValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator <= (const CWrappedItemIteratorConst<T_Type>& a_crInstance1, const CWrappedItemIteratorConst<T_Type>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_cpValue == a_crInstance2.m_cpValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator >= (const CWrappedItemIteratorConst<T_Type>& a_crInstance1, const CWrappedItemIteratorConst<T_Type>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_cpValue == a_crInstance2.m_cpValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type>& CWrappedItemIteratorConst<T_Type>::operator = (const T_Type& a_crValue)
{ CALL
  set(a_crValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type>& CWrappedItemIteratorConst<T_Type>::operator = (const CWrappedItemIteratorConst<T_Type>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type>& CWrappedItemIteratorConst<T_Type>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type>& CWrappedItemIteratorConst<T_Type>::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type>& CWrappedItemIteratorConst<T_Type>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type>& CWrappedItemIteratorConst<T_Type>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type> CWrappedItemIteratorConst<T_Type>::operator ++ (int)
{ CALL
  CWrappedItemIteratorConst<T_Type> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type> CWrappedItemIteratorConst<T_Type>::operator -- (int)
{ CALL
  CWrappedItemIteratorConst<T_Type> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type> operator + (const CWrappedItemIteratorConst<T_Type>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CWrappedItemIteratorConst<T_Type> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type> operator - (const CWrappedItemIteratorConst<T_Type>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CWrappedItemIteratorConst<T_Type> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type> CWrappedItemIteratorConst<T_Type>::operator [] (const Tsint a_cIndex) const
{ CALL
  return getIndex((Tuint)a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type> CWrappedItemIteratorConst<T_Type>::operator [] (const Tuint a_cIndex) const
{ CALL
  return getIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CWrappedItemIteratorConst<T_Type>::set(const T_Type& a_crValue)
{ CALL
  m_cpValue = NAlgorithms::NCommon::address(a_crValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CWrappedItemIteratorConst<T_Type>::set(const CWrappedItemIteratorConst<T_Type>& a_crInstance)
{ CALL
  m_cpValue = a_crInstance.m_cpValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type> CWrappedItemIteratorConst<T_Type>::getForward() const
{ CALL
  CWrappedItemIteratorConst<T_Type> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CWrappedItemIteratorConst<T_Type>());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type> CWrappedItemIteratorConst<T_Type>::getBackward() const
{ CALL
  CWrappedItemIteratorConst<T_Type> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CWrappedItemIteratorConst<T_Type>());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedItemIteratorConst<T_Type> CWrappedItemIteratorConst<T_Type>::getIndex(const Tuint a_cIndex) const
{ CALL
  CWrappedItemIteratorConst<T_Type> it(*this);
  // Perform indexed step and return indexed iterator instance or invalid one.
  return (it.stepIndex(a_cIndex) ? it : CWrappedItemIteratorConst<T_Type>());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CWrappedItemIteratorConst<T_Type>::isValid() const
{ CALL
  return isValidContainer();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CWrappedItemIteratorConst<T_Type>::isValidContainer() const
{ CALL
  return (m_cpValue != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type& CWrappedItemIteratorConst<T_Type>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_cpValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type* CWrappedItemIteratorConst<T_Type>::getContainerPtr() const
{ CALL
  return m_cpValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type& CWrappedItemIteratorConst<T_Type>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return *m_cpValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type* CWrappedItemIteratorConst<T_Type>::getValuePtr() const
{ CALL
  if (isValid())
    return m_cpValue;
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CWrappedItemIteratorConst<T_Type>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid wrapped item iterator."))
  {
    return 0;
  }

  // Return step count, that we have done.
  return 0;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CWrappedItemIteratorConst<T_Type>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid wrapped item iterator."))
  {
    return 0;
  }

  // Return step count, that we have done.
  return 0;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CWrappedItemIteratorConst<T_Type>::stepIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot do indexed step with the invalid wrapped item container."))
  {
    return false;
  }
  // Check index value and the item bounds.
  ASSERT((a_cIndex == 0), STR("Cannot do indexed step with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA 1)
  {
    return false;
  }

  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CWrappedItemIteratorConst<T_Type>::getSize() const
{ CALL
  return (isValidContainer() ? 1 : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CWrappedItemIteratorConst<T_Type>::setPosition(const Tuint a_cPosition)
{ CALL
  return stepIndex(a_cPosition);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CWrappedItemIteratorConst<T_Type>::getPosition() const
{ CALL
  return 0;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CWrappedItemIteratorConst<T_Type>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Constant iterator value cannot be loaded."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CWrappedItemIteratorConst<T_Type>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CWrappedItemIterator<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CWrappedItemIteratorConst<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CWrappedItemIteratorConst<T_Type>::swap(CWrappedItemIteratorConst<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_cpValue, a_rInstance.m_cpValue);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
