/*!
 *  \file    CReference.inl Reference template class emulates references
 *           thorough the class wrapper.
 *  \brief   Reference template wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reference template wrapper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   30.07.2006 22:07:26

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
#ifndef __CREFERENCE_INL__
#define __CREFERENCE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type>
inline CReference<T_Type>::CReference() :
  m_pValue(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReference<T_Type>::CReference(T_Type& a_rValue) :
  m_pValue(NAlgorithms::NCommon::address(a_rValue))
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CReference<T_Type>::CReference(const CReference<T_OtherType>& a_crInstance) :
  m_pValue(a_crInstance.m_pValue)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReference<T_Type>::~CReference()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator == (const CReference<T_Type>& a_crInstance, const T_Type& a_crValue)
{ CALL
  return (a_crInstance.m_pValue == NAlgorithms::NCommon::address(a_crValue));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator == (const CReference<T_Type>& a_crInstance1, const CReference<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pValue == a_crInstance2.m_pValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator == (const T_Type& a_crValue, const CReference<T_Type>& a_crInstance)
{ CALL
  return (NAlgorithms::NCommon::address(a_crValue) == a_crInstance.m_pValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator != (const CReference<T_Type>& a_crInstance, const T_Type& a_crValue)
{ CALL
  return (a_crInstance.m_pValue != NAlgorithms::NCommon::address(a_crValue));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator != (const CReference<T_Type>& a_crInstance1, const CReference<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pValue != a_crInstance2.m_pValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator != (const T_Type& a_crValue, const CReference<T_Type>& a_crInstance)
{ CALL
  return (NAlgorithms::NCommon::address(a_crValue) != a_crInstance.m_pValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReference<T_Type>& CReference<T_Type>::operator = (T_Type& a_rValue)
{ CALL
  set(a_rValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CReference<T_Type>& CReference<T_Type>::operator = (const CReference<T_OtherType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReference<T_Type>::operator T_Type& ()
{ CALL
  return getValueRef();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReference<T_Type>::operator const T_Type& () const
{ CALL
  return getValueRef();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CReference<T_Type>::set(T_Type& a_rValue)
{ CALL
  m_pValue = NAlgorithms::NCommon::address(a_rValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void CReference<T_Type>::set(const CReference<T_OtherType>& a_crInstance)
{ CALL
  m_pValue = a_crInstance.m_pValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CReference<T_Type>::isValid() const
{ CALL
  return (m_pValue != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CReference<T_Type>::clear()
{ CALL
  m_pValue = NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type& CReference<T_Type>::getValueRef()
{ CALL
  // Verify the reference to be the valid one.
  VERIFY(isValid(), STR("Taking invalid reference leads to the error."));

  return *m_pValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type& CReference<T_Type>::getValueRef() const
{ CALL
  // Verify the reference to be the valid one.
  VERIFY(isValid(), STR("Taking invalid reference leads to the error."));

  return *m_pValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CReference<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NBase::CReference<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doPointer(m_pValue, STR("m_pValue")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CReference<T_Type>::swap(CReference<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pValue, a_rInstance.m_pValue);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
