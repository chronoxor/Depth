/*!
 *  \file    CPair.inl Pair template class represents data structure which
 *           contains two fields: first (key), second (value).
 *  \brief   Pair template class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Pair template class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   03.03.2006 20:33:27

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
#ifndef __CPAIR_INL__
#define __CPAIR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_FirstType, typename T_SecondType>
inline CPair<T_FirstType, T_SecondType>::CPair() :
  m_First(),
  m_Second()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline CPair<T_FirstType, T_SecondType>::CPair(const T_FirstType& a_crFirstValue, const T_SecondType& a_crSecondValue) :
  m_First(a_crFirstValue),
  m_Second(a_crSecondValue)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
template <typename T_OtherFirstType, typename T_OtherSecondType>
inline CPair<T_FirstType, T_SecondType>::CPair(const CPair<T_OtherFirstType, T_OtherSecondType>& a_crInstance) :
  m_First((T_FirstType)a_crInstance.getFirst()),
  m_Second((T_SecondType)a_crInstance.getSecond())
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline CPair<T_FirstType, T_SecondType>::~CPair()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
template <typename T_OtherFirstType, typename T_OtherSecondType>
inline CPair<T_FirstType, T_SecondType>& CPair<T_FirstType, T_SecondType>::operator = (const CPair<T_OtherFirstType, T_OtherSecondType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline void CPair<T_FirstType, T_SecondType>::set(const T_FirstType& a_crFirstValue, const T_SecondType& a_crSecondValue)
{ CALL
  m_First = a_crFirstValue;
  m_Second = a_crSecondValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
template <typename T_OtherFirstType, typename T_OtherSecondType>
inline void CPair<T_FirstType, T_SecondType>::set(const CPair<T_OtherFirstType, T_OtherSecondType>& a_crInstance)
{ CALL
  m_First = (T_FirstType)a_crInstance.getFirst();
  m_Second = (T_SecondType)a_crInstance.getSecond();
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline T_FirstType& CPair<T_FirstType, T_SecondType>::getFirst()
{ CALL
  return m_First;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline const T_FirstType& CPair<T_FirstType, T_SecondType>::getFirst() const
{ CALL
  return m_First;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline T_SecondType& CPair<T_FirstType, T_SecondType>::getSecond()
{ CALL
  return m_Second;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline const T_SecondType& CPair<T_FirstType, T_SecondType>::getSecond() const
{ CALL
  return m_Second;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
template <class T_Archive>
inline Tbool CPair<T_FirstType, T_SecondType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUtility::CPair<T_FirstType, T_SecondType>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_First, STR("m_First")));
    CHECK(a_rArchive.doValue(m_Second, STR("m_Second")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline void CPair<T_FirstType, T_SecondType>::swap(CPair<T_FirstType, T_SecondType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_First, a_rInstance.m_First);
  NAlgorithms::NCommon::swap(m_Second, a_rInstance.m_Second);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
