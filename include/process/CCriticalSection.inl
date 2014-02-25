/*!
 *  \file    CCriticalSection.inl Critical section is a synchronization object
 *           which prevents multiple thread access to the protected code block.
 *  \brief   Critical section class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Critical section class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Process
    VERSION:   1.0
    CREATED:   14.06.2007 21:42:33

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
#ifndef __CCRITICALSECTION_INL__
#define __CCRITICALSECTION_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NProcess {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CCriticalSection::CCriticalSection(const Tbool a_cInitialize/* = false */) :
  m_IsMainHandle(false),
  m_pHandle(NULL)
{ CALL
  // Initialize critical section if necessary.
  if (a_cInitialize)
    initialize();
}
/*--------------------------------------------------------------------------*/
inline CCriticalSection::CCriticalSection(const CCriticalSection& a_crInstance) :
  m_IsMainHandle(false),
  m_pHandle(a_crInstance.m_pHandle)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CCriticalSection::~CCriticalSection()
{ CALL
  destroy();
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CCriticalSection& a_crInstance1, const CCriticalSection& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pHandle == a_crInstance2.m_pHandle);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CCriticalSection& a_crInstance1, const CCriticalSection& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pHandle != a_crInstance2.m_pHandle);
}
/*--------------------------------------------------------------------------*/
inline CCriticalSection& CCriticalSection::operator = (const CCriticalSection& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CCriticalSection::set(const CCriticalSection& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CCriticalSection class instance."))
  {
    return false;
  }

  // Destroy previous system handle of the critical section.
  if (!destroy())
    return false;

  // Initialize critical section fields.
  m_IsMainHandle = false;
  m_pHandle = a_crInstance.m_pHandle;
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tptr CCriticalSection::getHandle()
{ CALL
  return m_pHandle;
}
/*--------------------------------------------------------------------------*/
inline Tcptr CCriticalSection::getHandle() const
{ CALL
  return m_pHandle;
}
/*--------------------------------------------------------------------------*/
inline Tbool CCriticalSection::isInitialized() const
{ CALL
  return (m_pHandle != NULL);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CCriticalSection::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Critical section cannot be serialized."));
  return false;
}
/*--------------------------------------------------------------------------*/
inline void CCriticalSection::swap(CCriticalSection& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_IsMainHandle, a_rInstance.m_IsMainHandle);
  NAlgorithms::NCommon::swap(m_pHandle, a_rInstance.m_pHandle);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
