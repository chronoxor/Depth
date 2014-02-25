/*!
 *  \file    CRWLock.inl Reader/Writer lock is a synchronization object
 *           which prevents multiple reading and writing threads access
 *           to the protected code block.
 *  \brief   Reader/Writer lock class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.01.2011
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reader/Writer lock class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Process
    VERSION:   1.0
    CREATED:   21.01.2011 20:28:50

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
#ifndef __CRWLOCK_INL__
#define __CRWLOCK_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NProcess {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CRWLock::CRWLock(const Tbool a_cInitialize/* = false */) :
  m_IsMainHandle(false),
  m_pHandle(NULL)
{ CALL
  // Initialize reader/writer lock if necessary.
  if (a_cInitialize)
    initialize();
}
/*--------------------------------------------------------------------------*/
inline CRWLock::CRWLock(const CRWLock& a_crInstance) :
  m_IsMainHandle(false),
  m_pHandle(a_crInstance.m_pHandle)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CRWLock::~CRWLock()
{ CALL
  destroy();
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CRWLock& a_crInstance1, const CRWLock& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pHandle == a_crInstance2.m_pHandle);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CRWLock& a_crInstance1, const CRWLock& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pHandle != a_crInstance2.m_pHandle);
}
/*--------------------------------------------------------------------------*/
inline CRWLock& CRWLock::operator = (const CRWLock& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CRWLock::set(const CRWLock& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRWLock class instance."))
  {
    return false;
  }

  // Destroy previous system handle of the reader/writer lock.
  if (!destroy())
    return false;

  // Initialize reader/writer lock fields.
  m_IsMainHandle = false;
  m_pHandle = a_crInstance.m_pHandle;
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tptr CRWLock::getHandle()
{ CALL
  return m_pHandle;
}
/*--------------------------------------------------------------------------*/
inline Tcptr CRWLock::getHandle() const
{ CALL
  return m_pHandle;
}
/*--------------------------------------------------------------------------*/
inline Tbool CRWLock::isInitialized() const
{ CALL
  return (m_pHandle != NULL);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CRWLock::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Reader/Writer lock cannot be serialized."));
  return false;
}
/*--------------------------------------------------------------------------*/
inline void CRWLock::swap(CRWLock& a_rInstance)
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
