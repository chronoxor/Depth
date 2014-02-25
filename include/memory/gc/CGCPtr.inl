/*!
 *  \file    CGCPtr.inl GC smart pointer template class contains memory
 *           allocated information and helps to manage allocated memory
 *           blocks during the GC operation.
 *  \brief   GC smart pointer template class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: GC smart pointer template class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory garbage collection
    VERSION:   1.0
    CREATED:   24.06.2007 21:38:37

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
#ifndef __CGCPTR_INL__
#define __CGCPTR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NGC {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type>
template <typename T_OtherType>
inline void CGCPtr<T_Type>::SDestructorWrapper<T_OtherType>::destroy(Tptr a_pObjectPointer)
{ CALL
  NAlgorithms::NCommon::staticCast<T_OtherType*>(a_pObjectPointer)->~T_OtherType();
}
/*==========================================================================*/
template <typename T_Type>
inline CGCPtr<T_Type>::CGCPtr(T_Type* a_pPointer/* = NULL */) :
  NCommon::IPtr<T_Type>(NULL)
{ CALL
  // Register GC smart pointer instance in the GC engine.
  CMemory::registerGCPointer(this);
  set(a_pPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CGCPtr<T_Type>::CGCPtr(const CGCPtr<T_OtherType>& a_crInstance) :
  NCommon::IPtr<T_Type>(NULL)
{ CALL
  // Register GC smart pointer instance in the GC engine.
  CMemory::registerGCPointer(this);
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CGCPtr<T_Type>::~CGCPtr()
{ CALL
  // Unregister GC smart pointer instance in the GC engine.
  CMemory::unregisterGCPointer(this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CGCPtr<T_Type>& CGCPtr<T_Type>::operator = (T_Type* a_pPointer)
{ CALL
  set(a_pPointer);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CGCPtr<T_Type>& CGCPtr<T_Type>::operator = (const CGCPtr<T_OtherType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CGCPtr<T_Type>::set(T_Type* a_pPointer)
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer = a_pPointer;
  // Update GC smart pointer instance in the GC engine.
  update();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void CGCPtr<T_Type>::set(const CGCPtr<T_OtherType>& a_crInstance)
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer = NAlgorithms::NCommon::constCast<T_OtherType*>(a_crInstance.getValuePtr());
  // Update GC smart pointer instance in the GC engine.
  update();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CGCPtr<T_Type>::update()
{ CALL
  CMemory::updateGCPointer(this, NCommon::IPtr<T_Type>::m_pPointer, SDestructorWrapper<T_Type>::destroy);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CGCPtr<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NMemory::NGC::CGCPtr<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((NCommon::IPtr<T_Type>&)(*this), STR("base")));
  CHECK(a_rArchive.end());

  // Update GC smart pointer instance in the GC engine.
  update();
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CGCPtr<T_Type>::swap(CGCPtr<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((NCommon::IPtr<T_Type>&)(*this), (NCommon::IPtr<T_Type>&)(a_rInstance));
  // Update GC smart pointer instance in the GC engine.
  update();
  a_rInstance.update();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
