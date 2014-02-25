/*!
 *  \file    CScopeWriter.cpp Scope writer is a synchronization object which
 *           allows single writer thread access to the set of protected
 *           code blocks in the exclusive mode.
 *  \brief   Scope writer class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.01.2011
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Scope writer class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Process
    VERSION:   1.0
    CREATED:   24.01.2011 19:12:52

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
#include <Depth/include/process/CScopeWriter.hpp>
/*==========================================================================*/
#ifndef __CSCOPEWRITER_CPP__
#define __CSCOPEWRITER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NProcess {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CScopeWriter::CScopeWriter(CRWLock& a_crRWLock, const Tbool a_cLock/* = true */) :
  m_IsLocked(false),
  m_rRWLock(a_crRWLock)
{ CALL
  // Initialize reader/writer lock.
  if (!m_rRWLock.isInitialized())
    if (!m_rRWLock.initialize())
      return;

  // Lock the scope writer only if necessary.
  if (a_cLock)
    lock();
}
/*--------------------------------------------------------------------------*/
CScopeWriter::~CScopeWriter()
{ CALL
  // Unlock the scope writer.
  if (isLocked())
    unlock();
}
/*--------------------------------------------------------------------------*/
Tbool CScopeWriter::lock()
{ CALL
  // Check if the scope reader/writer lock is initialized.
  ASSERT(m_rRWLock.isInitialized(), STR("Cannot lock the scope writer with uninitialized reader/writer lock."))
  {
    return false;
  }

  // Check if scope writer is unlocked.
  ASSERT(!isLocked(), STR("Cannot twice lock the scope writer."))
  {
    return false;
  }

  // Lock the scope writer.
  m_IsLocked = m_rRWLock.lockWriter();
  return m_IsLocked;
}
/*--------------------------------------------------------------------------*/
Tbool CScopeWriter::unlock()
{ CALL
  // Check if the scope reader/writer lock is initialized.
  ASSERT(m_rRWLock.isInitialized(), STR("Cannot unlock the scope writer with uninitialized reader/writer lock."))
  {
    return false;
  }

  // Check if scope writer is locked.
  ASSERT(isLocked(), STR("Cannot unlock the scope writer that was not locked before."))
  {
    return false;
  }

  // Unlock the scope writer.
  m_IsLocked = !m_rRWLock.unlockWriter();
  return !m_IsLocked;
}
/*--------------------------------------------------------------------------*/
Tbool CScopeWriter::tryLock()
{ CALL
  // Check if the scope reader/writer lock is initialized.
  ASSERT(m_rRWLock.isInitialized(), STR("Cannot try lock the scope writer with uninitialized reader/writer lock."))
  {
    return false;
  }

  // Quick test for the locking state.
  if (isLocked())
    return false;

  m_IsLocked = m_rRWLock.tryLockWriter();
  return m_IsLocked;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
