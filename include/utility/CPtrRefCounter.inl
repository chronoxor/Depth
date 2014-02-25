/*!
 *  \file    CPtrRefCounter.inl Reference counter smart pointer class.
 *           Reference counter smart pointer holds object and reference
 *           count to this object.
 *  \brief   Reference counter smart pointer class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reference counter smart pointer class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   26.05.2006 03:59:24

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
#ifndef __CPTRSHARED_INL__
#define __CPTRSHARED_INL__
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
inline CPtrRefCounter<T_Type>::CPtrRefCounter(T_Type* a_pPointer/*  = NULL */, const Tbool a_cIsArrayPointer/* = false */) :
  NCommon::IPtr<T_Type>(NULL),
  m_IsArrayPointer(false),
  m_pRefCounter(NULL)
{ CALL
  set(a_pPointer, a_cIsArrayPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <Tuint t_Size>
inline CPtrRefCounter<T_Type>::CPtrRefCounter(T_Type (&a_pArray)[t_Size]) :
  NCommon::IPtr<T_Type>(NULL),
  m_IsArrayPointer(false),
  m_pRefCounter(NULL)
{ CALL
  set(a_pArray);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPtrRefCounter<T_Type>::CPtrRefCounter(const CPtrRefCounter<T_Type>& a_crInstance) :
  NCommon::IPtr<T_Type>(NULL),
  m_IsArrayPointer(false),
  m_pRefCounter(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPtrRefCounter<T_Type>::~CPtrRefCounter()
{ CALL
  release();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPtrRefCounter<T_Type>& CPtrRefCounter<T_Type>::operator = (T_Type* a_pPointer)
{ CALL
  set(a_pPointer);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <Tuint t_Size>
inline CPtrRefCounter<T_Type>& CPtrRefCounter<T_Type>::operator = (T_Type (&a_pArray)[t_Size])
{ CALL
  set(a_pArray);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPtrRefCounter<T_Type>& CPtrRefCounter<T_Type>::operator = (const CPtrRefCounter<T_Type>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPtrRefCounter<T_Type>::set(T_Type* a_pPointer, const Tbool a_cIsArrayPointer/* = false */)
{ CALL
  // Release old pointer.
  if (!release())
    return false;

  if (a_pPointer != NULL)
  {
    // Initialize reference counter.
    m_pRefCounter = newex Tuint(0);
    if (m_pRefCounter != NULL)
      ++(*m_pRefCounter);
    else
    {
      WARNING(STR("Cannot create a new reference counter (requested size is %u bytes).") COMMA (sizeof(Tuint)));
      return false;
    }

    // Initialize pointer value.
    m_IsArrayPointer = a_cIsArrayPointer;
    NCommon::IPtr<T_Type>::m_pPointer = a_pPointer;

    // Notify about a new object assigning.
    // onAssign(NCommon::IPtr<T_Type>::m_pPointer);
    // Add new reference to the new object.
    // onAddReference(NCommon::IPtr<T_Type>::m_pPointer);
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <Tuint t_Size>
inline Tbool CPtrRefCounter<T_Type>::set(T_Type (&a_pArray)[t_Size])
{ CALL
  return set(a_pArray, true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPtrRefCounter<T_Type>::set(const CPtrRefCounter<T_Type>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CPtrRefCounter class instance."))
  {
    return false;
  }

  // Release old pointer.
  if (!release())
    return false;

  // Initialize pointer value.
  m_IsArrayPointer = a_crInstance.m_IsArrayPointer;
  NCommon::IPtr<T_Type>::m_pPointer = a_crInstance.m_pPointer;

  // Initialize reference counter.
  if (!NCommon::IPtr<T_Type>::isNULL())
  {
    // Notify about a new object creation.
    // onAssign(NCommon::IPtr<T_Type>::m_pPointer);

    // Update reference counter.
    if (a_crInstance.m_pRefCounter != NULL)
    {
      // Use reference counter from other smart pointer.
      m_pRefCounter = a_crInstance.m_pRefCounter;
      ++(*m_pRefCounter);

      // Add new reference to the new object.
      // onAddReference(NCommon::IPtr<T_Type>::m_pPointer);
    }
    else
    {
      // Create new reference counter.
      m_pRefCounter = newex Tuint(0);
      if (m_pRefCounter != NULL)
      {
        ++(*m_pRefCounter);

        // Add new reference to the new object.
        // onAddReference(NCommon::IPtr<T_Type>::m_pPointer);
      }
      else
      {
        WARNING(STR("Cannot create a new reference counter (requested size is %u bytes).") COMMA (sizeof(Tuint)));
        return false;
      }
    }
  }
  else
    m_pRefCounter = NULL;

  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPtrRefCounter<T_Type>::isArrayPointer() const
{ CALL
  return m_IsArrayPointer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CPtrRefCounter<T_Type>::getRefCount() const
{ CALL
  return ((m_pRefCounter == NULL) ? 0 : *m_pRefCounter);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPtrRefCounter<T_Type>::release()
{ CALL
  if (!NCommon::IPtr<T_Type>::isNULL() && (m_pRefCounter != NULL))
  {
    // Remove reference from current object.
    // onRemoveReference(NCommon::IPtr<T_Type>::m_pPointer);

    // Remove one reference from smart pointer.
    if (--(*m_pRefCounter) == 0)
    {
      // Notify about current object destroying.
      // onDestroy(NCommon::IPtr<T_Type>::m_pPointer);

      // Delete object instance.
      if (isArrayPointer())
        delete [] NCommon::IPtr<T_Type>::m_pPointer;
      else
        delete NCommon::IPtr<T_Type>::m_pPointer;
      NCommon::IPtr<T_Type>::m_pPointer = NULL;
      // Delete reference counter.
      delete m_pRefCounter;
      m_pRefCounter = NULL;
    }
    else
    {
      // Notify about current object releasing.
      // onRelease(NCommon::IPtr<T_Type>::m_pPointer);
    }

    // Clear smart pointer parameters.
    NCommon::IPtr<T_Type>::m_pPointer = NULL;
    m_pRefCounter = NULL;
    return true;
  }
  else if (m_pRefCounter != NULL)
  {
    // Remove broken reference counter.
    delete m_pRefCounter;
    m_pRefCounter = NULL;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CPtrRefCounter<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Reference counter smart pointer instance cannot be serialized."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPtrRefCounter<T_Type>::swap(CPtrRefCounter<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((NCommon::IPtr<T_Type>&)(*this), (NCommon::IPtr<T_Type>&)(a_rInstance));
  NAlgorithms::NCommon::swap(m_IsArrayPointer, a_rInstance.m_IsArrayPointer);
  NAlgorithms::NCommon::swap(m_pRefCounter, a_rInstance.m_pRefCounter);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
