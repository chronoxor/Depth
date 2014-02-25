/*!
 *  \file    IPtr.inl Interface for all smart pointer implementations.
 *  \brief   Smart pointer interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Smart pointer interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common
    VERSION:   1.0
    CREATED:   19.05.2006 21:33:47

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
#ifndef __IPTR_INL__
#define __IPTR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_Type>
inline IPtr<T_Type>::IPtr(T_Type* a_pPointer/* = NULL */) :
  m_pPointer(a_pPointer)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline IPtr<T_Type>::IPtr(const IPtr<T_Type>& a_crInstance) :
  m_pPointer(a_crInstance.m_pPointer)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline IPtr<T_Type>::~IPtr()
{ CALL
  m_pPointer = NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator == (const IPtr<T_Type>& a_crInstance, const T_Type* a_cpPointer)
{ CALL
  return (a_crInstance.m_pPointer == a_cpPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator == (const IPtr<T_Type>& a_crInstance1, const IPtr<T_Type>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pPointer == a_crInstance2.m_pPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator == (const T_Type* a_cpPointer, const IPtr<T_Type>& a_crInstance)
{ CALL
  return (a_cpPointer == a_crInstance.m_pPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator != (const IPtr<T_Type>& a_crInstance, const T_Type* a_cpPointer)
{ CALL
  return (a_crInstance.m_pPointer != a_cpPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator != (const IPtr<T_Type>& a_crInstance1, const IPtr<T_Type>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pPointer != a_crInstance2.m_pPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator != (const T_Type* a_cpPointer, const IPtr<T_Type>& a_crInstance)
{ CALL
  return (a_cpPointer != a_crInstance.m_pPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator < (const IPtr<T_Type>& a_crInstance, const T_Type* a_cpPointer)
{ CALL
  return (a_crInstance.m_pValue < a_cpPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator < (const IPtr<T_Type>& a_crInstance1, const IPtr<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pValue < a_crInstance2.m_pValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator < (const T_Type* a_cpPointer, const IPtr<T_Type>& a_crInstance)
{ CALL
  return (a_cpPointer < a_crInstance.m_pValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator > (const IPtr<T_Type>& a_crInstance, const T_Type* a_cpPointer)
{ CALL
  return (a_crInstance.m_pValue > a_cpPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator > (const IPtr<T_Type>& a_crInstance1, const IPtr<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pValue > a_crInstance2.m_pValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator > (const T_Type* a_cpPointer, const IPtr<T_Type>& a_crInstance)
{ CALL
  return (a_cpPointer > a_crInstance.m_pValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator <= (const IPtr<T_Type>& a_crInstance, const T_Type* a_cpPointer)
{ CALL
  return (a_crInstance.m_pValue <= a_cpPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator <= (const IPtr<T_Type>& a_crInstance1, const IPtr<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pValue <= a_crInstance2.m_pValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator <= (const T_Type* a_cpPointer, const IPtr<T_Type>& a_crInstance)
{ CALL
  return (a_cpPointer <= a_crInstance.m_pValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator >= (const IPtr<T_Type>& a_crInstance, const T_Type* a_cpPointer)
{ CALL
  return (a_crInstance.m_pValue >= a_cpPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator >= (const IPtr<T_Type>& a_crInstance1, const IPtr<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pValue >= a_crInstance2.m_pValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator >= (const T_Type* a_cpPointer, const IPtr<T_Type>& a_crInstance)
{ CALL
  return (a_cpPointer >= a_crInstance.m_pValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline IPtr<T_Type>& IPtr<T_Type>::operator = (T_Type* a_pPointer)
{ CALL
  set(a_pPointer);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline IPtr<T_Type>& IPtr<T_Type>::operator = (const IPtr<T_Type>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline IPtr<T_Type>::operator T_Type* ()
{ CALL
  return getValuePtr();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline IPtr<T_Type>::operator const T_Type* () const
{ CALL
  return getValuePtr();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type& IPtr<T_Type>::operator * ()
{ CALL
  return getValueRef();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type& IPtr<T_Type>::operator * () const
{ CALL
  return getValueRef();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* IPtr<T_Type>::operator -> ()
{ CALL
  return getValuePtr();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type* IPtr<T_Type>::operator -> () const
{ CALL
  return getValuePtr();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline IPtr<T_Type>::operator Tbool () const
{ CALL
  return !isNULL();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool IPtr<T_Type>::operator ! () const
{ CALL
  return isNULL();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool IPtr<T_Type>::isNULL() const
{ CALL
  return (m_pPointer == NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type& IPtr<T_Type>::getValueRef()
{ CALL
  // Verify the pointer not to be NULL.
  VERIFY(!isNULL(), STR("Taking reference to the NULL pointer leads to the error."));

  return *m_pPointer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type& IPtr<T_Type>::getValueRef() const
{ CALL
  // Verify the pointer not to be NULL.
  VERIFY(!isNULL(), STR("Taking reference to the NULL pointer leads to the error."));

  return *m_pPointer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* IPtr<T_Type>::getValuePtr()
{ CALL
  return m_pPointer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type* IPtr<T_Type>::getValuePtr() const
{ CALL
  return m_pPointer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void IPtr<T_Type>::set(T_Type* a_pPointer)
{ CALL
  m_pPointer = a_pPointer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void IPtr<T_Type>::set(const IPtr<T_Type>& a_crInstance)
{ CALL
  m_pPointer = a_crInstance.m_pPointer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool IPtr<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NCommon::IPtr<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doPointer(m_pPointer, STR("m_pPointer")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void IPtr<T_Type>::swap(IPtr<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pPointer, a_rInstance.m_pPointer);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
