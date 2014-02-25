/*!
 *  \file    CScopeLocker.cpp Scope locker is a synchronization object which
 *           prevents multiple thread access to the set of protected code
 *           blocks.
 *  \brief   Scope Locker class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Scope locker class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Process
    VERSION:   1.0
    CREATED:   20.06.2007 22:17:42

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
#include <Depth/include/process/CScopeLocker.hpp>
/*==========================================================================*/
#ifndef __CSCOPELOCKER_CPP__
#define __CSCOPELOCKER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NProcess {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CScopeLocker::CScopeLocker(CCriticalSection& a_crCriticalSection, const Tbool a_cLock/* = true */) :
  m_IsLocked(false),
  m_rCriticalSection(a_crCriticalSection)
{ CALL
  // Initialize critical section.
  if (!m_rCriticalSection.isInitialized())
    if (!m_rCriticalSection.initialize())
      return;

  // Lock the scope locker only if necessary.
  if (a_cLock)
    lock();
}
/*--------------------------------------------------------------------------*/
CScopeLocker::~CScopeLocker()
{ CALL
  // Unlock the scope locker.
  if (isLocked())
    unlock();
}
/*--------------------------------------------------------------------------*/
Tbool CScopeLocker::lock()
{ CALL
  // Check if the scope locker critical section is initialized.
  ASSERT(m_rCriticalSection.isInitialized(), STR("Cannot lock the scope locker with uninitialized critical section."))
  {
    return false;
  }

  // Check if scope locker is unlocked.
  ASSERT(!isLocked(), STR("Cannot twice lock the scope locker."))
  {
    return false;
  }

  // Lock the scope locker.
  m_IsLocked = m_rCriticalSection.lock();
  return m_IsLocked;
}
/*--------------------------------------------------------------------------*/
Tbool CScopeLocker::unlock()
{ CALL
  // Check if the scope locker critical section is initialized.
  ASSERT(m_rCriticalSection.isInitialized(), STR("Cannot unlock the scope locker with uninitialized critical section."))
  {
    return false;
  }

  // Check if scope locker is locked.
  ASSERT(isLocked(), STR("Cannot unlock the scope locker that was not locked before."))
  {
    return false;
  }

  // Unlock the scope locker.
  m_IsLocked = !m_rCriticalSection.unlock();
  return !m_IsLocked;
}
/*--------------------------------------------------------------------------*/
Tbool CScopeLocker::tryLock()
{ CALL
  // Check if the scope locker critical section is initialized.
  ASSERT(m_rCriticalSection.isInitialized(), STR("Cannot try lock the scope locker with uninitialized critical section."))
  {
    return false;
  }

  // Quick test for the locking state.
  if (isLocked())
    return false;

  m_IsLocked = m_rCriticalSection.tryLock();
  return m_IsLocked;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
