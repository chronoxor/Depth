/*!
 *  \file    CRWLock.cpp Reader/Writer lock is a synchronization object
 *           which prevents multiple reading and writing threads access
 *           to the protected code block.
 *  \brief   Reader/Writer lock class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.01.2011
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reader/Writer lock class (source).

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/process/CRWLock.hpp>
#include <Depth/include/system/CSystemBase.hpp>
/*==========================================================================*/
#ifndef __CRWLOCK_CPP__
#define __CRWLOCK_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NProcess {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CRWLock::initialize()
{ CALL
  // Destroy previous system handle of the reader/writer lock.
  if (!destroy())
    return false;

  // Initialize the reader/writer lock with a new system handle.
  m_pHandle = NSystem::CSystemBase::RWLCreate();
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
Tbool CRWLock::destroy()
{ CALL
  if (isInitialized())
  {
    // For main system handle destroy it.
    if (m_IsMainHandle)
      if (!NSystem::CSystemBase::RWLDestroy(m_pHandle))
        return false;

    m_IsMainHandle = false;
    m_pHandle = NULL;
    return true;
  }
  else
    return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRWLock::lockReader()
{ CALL
  // Check if the reader/writer lock is initialized.
  ASSERT(isInitialized(), STR("Cannot reader enter into and lock the uninitialized reader/writer lock."))
  {
    return false;
  }

  return NSystem::CSystemBase::RWLLockReader(m_pHandle);
}
/*--------------------------------------------------------------------------*/
Tbool CRWLock::lockWriter()
{ CALL
  // Check if the reader/writer lock is initialized.
  ASSERT(isInitialized(), STR("Cannot writer enter into and lock the uninitialized reader/writer lock."))
  {
    return false;
  }

  return NSystem::CSystemBase::RWLLockWriter(m_pHandle);
}
/*--------------------------------------------------------------------------*/
Tbool CRWLock::unlockReader()
{ CALL
  // Check if the reader/writer lock is initialized.
  ASSERT(isInitialized(), STR("Cannot reader leave and unlock the uninitialized reader/writer lock."))
  {
    return false;
  }

  return NSystem::CSystemBase::RWLUnlockReader(m_pHandle);
}
/*--------------------------------------------------------------------------*/
Tbool CRWLock::unlockWriter()
{ CALL
  // Check if the reader/writer lock is initialized.
  ASSERT(isInitialized(), STR("Cannot writer leave and unlock the uninitialized reader/writer lock."))
  {
    return false;
  }

  return NSystem::CSystemBase::RWLUnlockWriter(m_pHandle);
}
/*--------------------------------------------------------------------------*/
Tbool CRWLock::tryLockReader()
{ CALL
  // Check if the reader/writer lock is initialized.
  ASSERT(isInitialized(), STR("Cannot try to reader enter into and lock the uninitialized reader/writer lock."))
  {
    return false;
  }

  return NSystem::CSystemBase::RWLTryLockReader(m_pHandle);
}
/*--------------------------------------------------------------------------*/
Tbool CRWLock::tryLockWriter()
{ CALL
  // Check if the reader/writer lock is initialized.
  ASSERT(isInitialized(), STR("Cannot try to writer enter into and lock the uninitialized reader/writer lock."))
  {
    return false;
  }

  return NSystem::CSystemBase::RWLTryLockWriter(m_pHandle);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
