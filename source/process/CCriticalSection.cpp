/*!
 *  \file    CCriticalSection.cpp Critical section is a synchronization object
 *           which prevents multiple thread access to the protected code block.
 *  \brief   Critical section class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Critical section class (source).

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/process/CCriticalSection.hpp>
#include <Depth/include/system/CSystemBase.hpp>
/*==========================================================================*/
#ifndef __CCRITICALSECTION_CPP__
#define __CCRITICALSECTION_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NProcess {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CCriticalSection::initialize()
{ CALL
  // Destroy previous system handle of the critical section.
  if (!destroy())
    return false;

  // Initialize the critical section with a new system handle.
  m_pHandle = NSystem::CSystemBase::criticalSectionCreate();
  if (m_pHandle != NULL)
  {
    m_IsMainHandle = true;
    return true;
  }
  else
  {
    m_IsMainHandle = false;
    return false;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CCriticalSection::destroy()
{ CALL
  if (isInitialized())
  {
    // For main system handle destroy it.
    if (m_IsMainHandle)
      if (!NSystem::CSystemBase::criticalSectionDestroy(m_pHandle))
        return false;

    m_IsMainHandle = false;
    m_pHandle = NULL;
    return true;
  }
  else
    return true;
}
/*--------------------------------------------------------------------------*/
Tbool CCriticalSection::lock()
{ CALL
  // Check if the critical section is initialized.
  ASSERT(isInitialized(), STR("Cannot enter into and lock the uninitialized critical section."))
  {
    return false;
  }

  return NSystem::CSystemBase::criticalSectionLock(m_pHandle);
}
/*--------------------------------------------------------------------------*/
Tbool CCriticalSection::unlock()
{ CALL
  // Check if the critical section is initialized.
  ASSERT(isInitialized(), STR("Cannot leave and unlock the uninitialized critical section."))
  {
    return false;
  }

  return NSystem::CSystemBase::criticalSectionUnlock(m_pHandle);
}
/*--------------------------------------------------------------------------*/
Tbool CCriticalSection::tryLock()
{ CALL
  // Check if the critical section is initialized.
  ASSERT(isInitialized(), STR("Cannot try to enter into and lock the uninitialized critical section."))
  {
    return false;
  }

  return NSystem::CSystemBase::criticalSectionTryLock(m_pHandle);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
