/*!
 *  \file    CPtrMaster.inl Master smart pointer class. Creating the smart
 *           pointer creates object instance, copying smart pointer cloning
 *           the object, deleting smart pointer deletes the object.
 *  \brief   Master smart pointer class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Master smart pointer class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   23.05.2006 02:07:52

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
#ifndef __CPTRMASTER_INL__
#define __CPTRMASTER_INL__
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
inline CPtrMaster<T_Type>::CPtrMaster() :
  NCommon::IPtr<T_Type>(NULL)
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer = newex T_Type();

  if (NCommon::IPtr<T_Type>::m_pPointer != NULL)
  {
    // Notify about a new object creation.
    // onCreate(NCommon::IPtr<T_Type>::m_pPointer);
    // Add new reference to the new object.
    // onAddReference(NCommon::IPtr<T_Type>::m_pPointer);
  }
  else
    WARNING(STR("Cannot create an object instance with the default constructor (requested size is %u bytes).") COMMA (sizeof(T_Type)));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPtrMaster<T_Type>::CPtrMaster(const T_Type& a_crObject) :
  NCommon::IPtr<T_Type>(NULL)
{ CALL
  set(a_crObject);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPtrMaster<T_Type>::CPtrMaster(const CPtrMaster<T_Type>& a_crInstance) :
  NCommon::IPtr<T_Type>(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPtrMaster<T_Type>::~CPtrMaster()
{ CALL
  release();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPtrMaster<T_Type>& CPtrMaster<T_Type>::operator = (const T_Type& a_crObject)
{ CALL
  set(a_crObject);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPtrMaster<T_Type>& CPtrMaster<T_Type>::operator = (const CPtrMaster<T_Type>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPtrMaster<T_Type>::set(const T_Type& a_crObject)
{ CALL
  if (!release())
    return false;

  NCommon::IPtr<T_Type>::m_pPointer = newex T_Type(a_crObject);
  if (NCommon::IPtr<T_Type>::m_pPointer != NULL)
  {
    // Notify about a new object creation.
    // onCreate(NCommon::IPtr<T_Type>::m_pPointer);
    // Add new reference to the new object.
    // onAddReference(NCommon::IPtr<T_Type>::m_pPointer);
    return true;
  }
  else
  {
    WARNING(STR("Cannot create an object instance with the copy constructor (requested size is %u bytes).") COMMA (sizeof(T_Type)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPtrMaster<T_Type>::set(const CPtrMaster<T_Type>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CPtrMaster class instance."))
  {
    return false;
  }

  if (!release())
    return false;

  if (a_crInstance.isNULL())
  {
    NCommon::IPtr<T_Type>::m_pPointer = newex T_Type();
    if (NCommon::IPtr<T_Type>::m_pPointer != NULL)
    {
      // Notify about a new object creation.
      // onCreate(NCommon::IPtr<T_Type>::m_pPointer);
      // Add new reference to the new object.
      // onAddReference(NCommon::IPtr<T_Type>::m_pPointer);
      return true;
    }
    else
    {
      WARNING(STR("Cannot create an object instance with the default constructor (requested size is %u bytes).") COMMA (sizeof(T_Type)));
      return false;
     }
  }
  else
  {
    NCommon::IPtr<T_Type>::m_pPointer = newex T_Type(*a_crInstance.m_pPointer);
    if (NCommon::IPtr<T_Type>::m_pPointer != NULL)
    {
      // Notify about a new object creation.
      // onCreate(NCommon::IPtr<T_Type>::m_pPointer);
      // Add new reference to the new object.
      // onAddReference(NCommon::IPtr<T_Type>::m_pPointer);
      return true;
    }
    else
    {
      WARNING(STR("Cannot create an object instance with the copy constructor (requested size is %u bytes).") COMMA (sizeof(T_Type)));
      return false;
    }
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPtrMaster<T_Type>::release()
{ CALL
  if (!NCommon::IPtr<T_Type>::isNULL())
  {
    // Remove reference from current object.
    // onRemoveReference(NCommon::IPtr<T_Type>::m_pPointer);
    // Notify about current object destroying.
    // onDestroy(NCommon::IPtr<T_Type>::m_pPointer);

    // Delete object instance.
    delete NCommon::IPtr<T_Type>::m_pPointer;
    NCommon::IPtr<T_Type>::m_pPointer = NULL;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CPtrMaster<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Master smart pointer instance cannot be serialized."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPtrMaster<T_Type>::swap(CPtrMaster<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((NCommon::IPtr<T_Type>&)(*this), (NCommon::IPtr<T_Type>&)(a_rInstance));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
