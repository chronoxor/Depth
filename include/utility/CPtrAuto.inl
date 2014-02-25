/*!
 *  \file    CPtrAuto.inl Auto smart pointer class. It holds pointer to the
 *           fixed object until it stays inside the visibility scope (until
 *           its destructor is not called).
 *  \brief   Auto smart pointer class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Auto smart pointer class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   22.05.2006 20:30:42

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
#ifndef __CPTRAUTO_INL__
#define __CPTRAUTO_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type>
inline CPtrAuto<T_Type>::CPtrAuto(T_Type* a_pPointer/*  = NULL */, const Tbool a_cIsArrayPointer/* = false */) :
  NCommon::IPtr<T_Type>(NULL),
  m_IsArrayPointer(false)
{ CALL
  set(a_pPointer, a_cIsArrayPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <Tuint t_Size>
inline CPtrAuto<T_Type>::CPtrAuto(T_Type (&a_pArray)[t_Size]) :
  NCommon::IPtr<T_Type>(NULL),
  m_IsArrayPointer(false)
{ CALL
  set(a_pArray);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPtrAuto<T_Type>::CPtrAuto(CPtrAuto<T_Type>& a_rInstance) :
  NCommon::IPtr<T_Type>(NULL),
  m_IsArrayPointer(false)
{ CALL
  set(a_rInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPtrAuto<T_Type>::~CPtrAuto()
{ CALL
  if (!NCommon::IPtr<T_Type>::isNULL())
  {
    // Remove reference from current object.
    // onRemoveReference(NCommon::IPtr<T_Type>::m_pPointer);
    // Notify about current object destroying.
    // onDestroy(NCommon::IPtr<T_Type>::m_pPointer);

    // Delete object instance.
    if (isArrayPointer())
      delete [] NCommon::IPtr<T_Type>::m_pPointer;
    else
      delete NCommon::IPtr<T_Type>::m_pPointer;
    NCommon::IPtr<T_Type>::m_pPointer = NULL;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPtrAuto<T_Type>& CPtrAuto<T_Type>::operator = (T_Type* a_pPointer)
{ CALL
  set(a_pPointer, false);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <Tuint t_Size>
inline CPtrAuto<T_Type>& CPtrAuto<T_Type>::operator = (T_Type (&a_pArray)[t_Size])
{ CALL
  set(a_pArray);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPtrAuto<T_Type>& CPtrAuto<T_Type>::operator = (CPtrAuto<T_Type>& a_rInstance)
{ CALL
  set(a_rInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPtrAuto<T_Type>::set(T_Type* a_pPointer, const Tbool a_cIsArrayPointer/* = false */)
{ CALL
  if (!NCommon::IPtr<T_Type>::isNULL())
  {
    if (a_pPointer != NCommon::IPtr<T_Type>::m_pPointer)
    {
      // Remove reference from current object.
      // onRemoveReference(NCommon::IPtr<T_Type>::m_pPointer);
      // Notify about current object destroying.
      // onDestroy(NCommon::IPtr<T_Type>::m_pPointer);

      // Delete object instance.
      if (isArrayPointer())
        delete [] NCommon::IPtr<T_Type>::m_pPointer;
      else
        delete NCommon::IPtr<T_Type>::m_pPointer;
      NCommon::IPtr<T_Type>::m_pPointer = NULL;
    }
  }

  // Initialize pointer value.
  m_IsArrayPointer = a_cIsArrayPointer;
  NCommon::IPtr<T_Type>::m_pPointer = a_pPointer;
  if (!NCommon::IPtr<T_Type>::isNULL())
  {
    // Notify about a new object assign.
    // onAssign(NCommon::IPtr<T_Type>::m_pPointer);
    // Add new reference to the new object.
    // onAddReference(NCommon::IPtr<T_Type>::m_pPointer);
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <Tuint t_Size>
inline Tbool CPtrAuto<T_Type>::set(T_Type (&a_pArray)[t_Size])
{ CALL
  return set(a_pArray, true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPtrAuto<T_Type>::set(CPtrAuto<T_Type>& a_rInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_rInstance != this), STR("Setting the same CPtrAuto class instance."))
  {
    return false;
  }

  if (set(a_rInstance.m_pPointer, a_rInstance.m_IsArrayPointer))
  {
    a_rInstance.release();
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPtrAuto<T_Type>::isArrayPointer() const
{ CALL
  return m_IsArrayPointer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* CPtrAuto<T_Type>::release()
{ CALL
  T_Type* temp = NCommon::IPtr<T_Type>::m_pPointer;

  if (!NCommon::IPtr<T_Type>::isNULL())
  {
    // Remove reference from current object.
    // onRemoveReference(NCommon::IPtr<T_Type>::m_pPointer);
    // Notify about current object releasing.
    // onRelease(NCommon::IPtr<T_Type>::m_pPointer);
  }

  // Release current pointer to object.
  m_IsArrayPointer = false;
  NCommon::IPtr<T_Type>::m_pPointer = NULL;
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CPtrAuto<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Auto smart pointer instance cannot be serialized."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPtrAuto<T_Type>::swap(CPtrAuto<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((NCommon::IPtr<T_Type>&)(*this), (NCommon::IPtr<T_Type>&)(a_rInstance));
  NAlgorithms::NCommon::swap(m_IsArrayPointer, a_rInstance.m_IsArrayPointer);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
