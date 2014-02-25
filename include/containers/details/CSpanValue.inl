/*!
 *  \file    CSpanValue.inl Template single span value class. Span value
 *           represents open/close interval of values, which is kept inside
 *           CSpan container.
 *  \brief   Span value class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.09.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Span value class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers details
    VERSION:   1.0
    CREATED:   12.09.2007 22:42:08

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
#ifndef __CSPANVALUE_INL__
#define __CSPANVALUE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type>
inline CSpanValue<T_Type>::CSpanValue() :
  m_First(),
  m_Second(),
  m_IsIncludeFirst(true),
  m_IsIncludeSecond(true)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CSpanValue<T_Type>::CSpanValue(const T_Type& a_crValue) :
  m_First(a_crValue),
  m_Second(a_crValue),
  m_IsIncludeFirst(true),
  m_IsIncludeSecond(true)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CSpanValue<T_Type>::CSpanValue(const T_Type& a_crFirstValue, const T_Type& a_crSecondValue, const Tbool a_cIncludeFirstValue/* = true */, const Tbool a_cIncludeSecondValue/* = true*/) :
  m_First(a_crFirstValue),
  m_Second(a_crSecondValue),
  m_IsIncludeFirst(a_cIncludeFirstValue),
  m_IsIncludeSecond(a_cIncludeSecondValue)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CSpanValue<T_Type>::CSpanValue(const CSpanValue<T_OtherType>& a_crInstance) :
  m_First((T_Type)a_crInstance.getFirst()),
  m_Second((T_Type)a_crInstance.getSecond()),
  m_IsIncludeFirst(a_crInstance.isIncludeFirst()),
  m_IsIncludeSecond(a_crInstance.isIncludeSecond())
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CSpanValue<T_Type>::~CSpanValue()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CSpanValue<T_Type>& CSpanValue<T_Type>::operator = (const CSpanValue<T_OtherType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CSpanValue<T_Type>::set(const T_Type& a_crValue)
{ CALL
  m_First = a_crValue;
  m_Second = a_crValue;
  m_IsIncludeFirst = true;
  m_IsIncludeSecond = true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CSpanValue<T_Type>::set(const T_Type& a_crFirstValue, const T_Type& a_crSecondValue, const Tbool a_cIncludeFirstValue/* = true */, const Tbool a_cIncludeSecondValue/* = true*/)
{ CALL
  m_First = a_crFirstValue;
  m_Second = a_crSecondValue;
  m_IsIncludeFirst = a_cIncludeFirstValue;
  m_IsIncludeSecond = a_cIncludeSecondValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void CSpanValue<T_Type>::set(const CSpanValue<T_OtherType>& a_crInstance)
{ CALL
  m_First = (T_Type)a_crInstance.getFirst();
  m_Second = (T_Type)a_crInstance.getSecond();
  m_IsIncludeFirst = a_crInstance.isIncludeFirst();
  m_IsIncludeSecond = a_crInstance.isIncludeSecond();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type& CSpanValue<T_Type>::getFirst()
{ CALL
  return m_First;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type& CSpanValue<T_Type>::getFirst() const
{ CALL
  return m_First;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type& CSpanValue<T_Type>::getSecond()
{ CALL
  return m_Second;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type& CSpanValue<T_Type>::getSecond() const
{ CALL
  return m_Second;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CSpanValue<T_Type>::isIncludeFirst() const
{ CALL
  return m_IsIncludeFirst;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CSpanValue<T_Type>::isIncludeSecond() const
{ CALL
  return m_IsIncludeSecond;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CSpanValue<T_Type>::includeFirst()
{ CALL
  m_IsIncludeFirst = true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CSpanValue<T_Type>::includeSecond()
{ CALL
  m_IsIncludeSecond = true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CSpanValue<T_Type>::excludeFirst()
{ CALL
  m_IsIncludeFirst = false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CSpanValue<T_Type>::excludeSecond()
{ CALL
  m_IsIncludeSecond = false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CSpanValue<T_Type>::reverse()
{ CALL
  NAlgorithms::NCommon::swap(m_First, m_Second);
  NAlgorithms::NCommon::swap(m_IsIncludeFirst, m_IsIncludeSecond);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CSpanValue<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NDetails::CSpanValue<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_First, STR("m_First")));
    CHECK(a_rArchive.doValue(m_Second, STR("m_Second")));
    CHECK(a_rArchive.doValue(m_IsIncludeFirst, STR("m_IsIncludeFirst")));
    CHECK(a_rArchive.doValue(m_IsIncludeSecond, STR("m_IsIncludeSecond")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CSpanValue<T_Type>::swap(CSpanValue<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_First, a_rInstance.m_First);
  NAlgorithms::NCommon::swap(m_Second, a_rInstance.m_Second);
  NAlgorithms::NCommon::swap(m_IsIncludeFirst, a_rInstance.m_IsIncludeFirst);
  NAlgorithms::NCommon::swap(m_IsIncludeSecond, a_rInstance.m_IsIncludeSecond);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
