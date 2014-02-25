/*!
 *  \file    CSystemBaseRWLock-WindowsMobile.cpp Base system class contains
 *           common functionality such as memory routines, math functions,
 *           error handling, standard I/O routines.
 *  \brief   Base system class - Windows Mobile OS - reader/writer lock methods (source).
 *  \author  wj32
 *  \version 1.0
 *  \date    20.01.2011
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Windows Mobile OS - reader/writer lock methods (source).

    AUTHOR:    wj32
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   20.01.2011 19:48:42

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
#include <Depth/include/system/CSystemBase.hpp>
/*--------------------------------------------------------------------------*/
#include "../WindowsMobile.hpp"
/*==========================================================================*/
#ifndef __CSYSTEMBASERWLOCK_WINDOWSMOBILE_CPP__
#define __CSYSTEMBASERWLOCK_WINDOWSMOBILE_CPP__
/*==========================================================================*/
#if (defined(__WINDOWS__) && defined(__WINDOWS_MOBILE__))
/*==========================================================================*/
/* LOCAL NAMESPACE DECLARATIONS                                             */
/*==========================================================================*/
namespace {
/*==========================================================================*/
/* LOCAL STRUCTURES DECLARATIONS                                            */
/*==========================================================================*/
//! System reader/writer lock object.
/*!
    System reader/writer lock object  contains  all  required  information  to
    create and manipulate with system reader/writer lock handle.
*/
struct SSystemRWLock
{
  volatile LONG m_vValue;               //!< Reader/Writer lock state.
  HANDLE m_WakeEventForReaders;         //!< Synchronization semaphore for readers.
  HANDLE m_WakeEventForWriters;         //!< Synchronization semaphore for writers.

  // Lock owned: 1 bit.
  static const LONG LockOwned = 0x1;
  // Exclusive waking: 1 bit.
  static const LONG LockExclusiveWaking = 0x2;
  // Shared owners count: 10 bits.
  static const LONG LockSharedOwnersShift = 2;
  static const LONG LockSharedOwnersMask = 0x3ff;
  static const LONG LockSharedOwnersIncrement = 0x4; // 2 ^ 2
  // Shared waiters count: 10 bits.
  static const LONG LockSharedWaitersShift = 12;
  static const LONG LockSharedWaitersMask = 0x3ff;
  static const LONG LockSharedWaitersIncrement = 0x1000; // 2 ^ 12
  // Exclusive waiters count: 10 bits.
  static const LONG LockExclusiveWaitersShift = 22;
  static const LONG LockExclusiveWaitersMask = 0x3ff;
  static const LONG LockExclusiveWaitersIncrement = 0x400000; // 2 ^ 22

  // Default spin count.
  static const LONG SpinCount = 4000;

  // Exclusive mask.
  static const LONG ExclusiveMask = LockExclusiveWaking | (LockExclusiveWaitersMask << LockExclusiveWaitersShift);
};
/*==========================================================================*/
}
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tptr CSystemBase::RWLCreate()
{ CALL
  // Allocate memory for a new reader/writer lock.
  SSystemRWLock* rwl = (SSystemRWLock*)CSystemBase::memoryAllocate(sizeof(SSystemRWLock));
  // Initialize the reader/writer lock.
  if (rwl != NULL)
  {
    rwl->m_vValue = 0;
    rwl->m_WakeEventForReaders = NULL;
    rwl->m_WakeEventForWriters = NULL;

    // Initialize the synchronization semaphore for readers.
    rwl->m_WakeEventForReaders = CreateSemaphore(NULL, 0, LONG_MAX, NULL);
    if (rwl->m_WakeEventForReaders == NULL)
    {
      WARNING(STR("Cannot initialize the synchronization semaphore for reader/writer lock readers."));
      RWLDestroy(rwl);
      return NULL;
    }

    // Initialize the synchronization semaphore for writers.
    rwl->m_WakeEventForWriters = CreateSemaphore(NULL, 0, LONG_MAX, NULL);
    if (rwl->m_WakeEventForWriters == NULL)
    {
      WARNING(STR("Cannot initialize the synchronization semaphore for reader/writer lock writers."));
      RWLDestroy(rwl);
      return NULL;
    }
  }
  return rwl;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLDestroy(const Tptr a_cpRWLHandle)
{ CALL
  // Destroy the non empty reader/writer lock.
  SSystemRWLock* rwl = (SSystemRWLock*)a_cpRWLHandle;
  if (rwl != NULL)
  {
    // Destroy the synchronization semaphore for readers.
    if (rwl->m_WakeEventForReaders != NULL)
    {
      if (CloseHandle(rwl->m_WakeEventForReaders) == FALSE)
      {
        WARNING(STR("Cannot destroy the synchronization semaphore for reader/writer lock readers."));
        return false;
      }
    }

    // Destroy the synchronization semaphore for writers.
    if (rwl->m_WakeEventForWriters != NULL)
    {
      if (CloseHandle(rwl->m_WakeEventForWriters) == FALSE)
      {
        WARNING(STR("Cannot destroy the synchronization semaphore for reader/writer lock writers."));
        return false;
      }
    }

    rwl->m_vValue = 0;
    rwl->m_WakeEventForReaders = NULL;
    rwl->m_WakeEventForWriters = NULL;

    return CSystemBase::memoryFree(rwl);
  }
  else
    return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLLockReader(const Tptr a_cpRWLHandle)
{ CALL
  // Reader lock the non empty reader/writer lock.
  SSystemRWLock* rwl = (SSystemRWLock*)a_cpRWLHandle;
  if (rwl != NULL)
  {
    // Acquires the lock in shared mode, blocking if necessary.
    // Exclusive acquires are given precedence over shared acquires.
    Tuint i = 0;
    while (true)
    {
      LONG value = rwl->m_vValue;

      // Case 1: lock not owned AND no exclusive waiter is waking up AND
      // there are no shared owners AND there are no exclusive waiters
      if ((value & (SSystemRWLock::LockOwned | (SSystemRWLock::LockSharedOwnersMask << SSystemRWLock::LockSharedOwnersShift) | SSystemRWLock::ExclusiveMask)) == 0)
      {
        if (InterlockedCompareExchange(&rwl->m_vValue, value + SSystemRWLock::LockOwned + SSystemRWLock::LockSharedOwnersIncrement, value) == value)
          break;
      }
      // Case 2: lock is owned AND no exclusive waiter is waking up AND
      // there are shared owners AND there are no exclusive waiters
      else if ((value & SSystemRWLock::LockOwned) != 0 && ((value >> SSystemRWLock::LockSharedOwnersShift) & SSystemRWLock::LockSharedOwnersMask) != 0 && (value & SSystemRWLock::ExclusiveMask) == 0)
      {
        if (InterlockedCompareExchange(&rwl->m_vValue, value + SSystemRWLock::LockSharedOwnersIncrement, value ) == value)
          break;
      }
      // Other cases.
      else if (i >= SSystemRWLock::SpinCount)
      {
        if (InterlockedCompareExchange(&rwl->m_vValue, value + SSystemRWLock::LockSharedWaitersIncrement, value) == value)
        {
          // Go to sleep.
          WaitForSingleObject(rwl->m_WakeEventForReaders, INFINITE);
          // Go back and try again.
          continue;
        }
      }
      i++;
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLLockWriter(const Tptr a_cpRWLHandle)
{ CALL
  // Writer lock the non empty reader/writer lock.
  SSystemRWLock* rwl = (SSystemRWLock*)a_cpRWLHandle;
  if (rwl != NULL)
  {
    // Acquires the lock in exclusive mode, blocking if necessary.
    // Exclusive acquires are given precedence over shared acquires.
    Tuint i = 0;
    while (true)
    {
      LONG value = rwl->m_vValue;

      // Case 1: lock not owned AND an exclusive waiter is not waking up.
      // Here we don't have to check if there are exclusive waiters, because
      // if there are the lock would be owned, and we are checking that anyway.
      if ((value & (SSystemRWLock::LockOwned | SSystemRWLock::LockExclusiveWaking)) == 0)
      {
        if (InterlockedCompareExchange(&rwl->m_vValue, value + SSystemRWLock::LockOwned, value) == value)
          break;
      }
      // Case 2: lock owned OR lock not owned and an exclusive waiter is waking up.
      // The second case means an exclusive waiter has just been woken up and is
      // going to acquire the lock. We have to go to sleep to make sure we don't
      // steal the lock.
      else if (i >= SSystemRWLock::SpinCount)
      {
        if (InterlockedCompareExchange(&rwl->m_vValue, value + SSystemRWLock::LockExclusiveWaitersIncrement, value) == value)
        {
          // Go to sleep.
          WaitForSingleObject(rwl->m_WakeEventForWriters, INFINITE);

          // Acquire the lock.
          // At this point *no one* should be able to steal the lock from us.
          do
          {
            value = rwl->m_vValue;
          } while (InterlockedCompareExchange(&rwl->m_vValue, value + SSystemRWLock::LockOwned - SSystemRWLock::LockExclusiveWaking, value) != value);

          break;
        }
      }
      i++;
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLUnlockReader(const Tptr a_cpRWLHandle)
{ CALL
  // Reader unlock the non empty reader/writer lock.
  SSystemRWLock* rwl = (SSystemRWLock*)a_cpRWLHandle;
  if (rwl != NULL)
  {
    // Releases the lock in shared mode.
    while (true)
    {
      LONG value = rwl->m_vValue;
      LONG sharedOwners = (value >> SSystemRWLock::LockSharedOwnersShift) & SSystemRWLock::LockSharedOwnersMask;

      // Case 1: there are multiple shared owners.
      if (sharedOwners > 1)
      {
        if (InterlockedCompareExchange(&rwl->m_vValue, value - SSystemRWLock::LockSharedOwnersIncrement, value) == value)
          break;
      }
      // Case 2: we are the last shared owner AND there are exclusive waiters.
      else if (((value >> SSystemRWLock::LockExclusiveWaitersShift) & SSystemRWLock::LockExclusiveWaitersMask) != 0)
      {
        if (InterlockedCompareExchange(&rwl->m_vValue, value - SSystemRWLock::LockOwned + SSystemRWLock::LockExclusiveWaking - SSystemRWLock::LockSharedOwnersIncrement - SSystemRWLock::LockExclusiveWaitersIncrement, value) == value)
        {
          ReleaseSemaphore(rwl->m_WakeEventForWriters, 1, NULL);
          break;
        }
      }
      // Case 3: we are the last shared owner AND there are no exclusive waiters.
      else
      {
        if (InterlockedCompareExchange(&rwl->m_vValue, value - SSystemRWLock::LockOwned - SSystemRWLock::LockSharedOwnersIncrement, value) == value)
          break;
      }
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLUnlockWriter(const Tptr a_cpRWLHandle)
{ CALL
  // Writer unlock the non empty reader/writer lock.
  SSystemRWLock* rwl = (SSystemRWLock*)a_cpRWLHandle;
  if (rwl != NULL)
  {
    // Releases the lock in exclusive mode.
    while (true)
    {
      LONG value = rwl->m_vValue;

      // Case 1: if we have exclusive waiters, release one.
      if (((value >> SSystemRWLock::LockExclusiveWaitersShift) & SSystemRWLock::LockExclusiveWaitersMask) != 0)
      {
        if (InterlockedCompareExchange(&rwl->m_vValue, value - SSystemRWLock::LockOwned + SSystemRWLock::LockExclusiveWaking - SSystemRWLock::LockExclusiveWaitersIncrement, value) == value)
        {
          ReleaseSemaphore(rwl->m_WakeEventForWriters, 1, NULL);
          break;
        }
      }
      // Case 2: if we have shared waiters, release all of them.
      else
      {
        LONG sharedWaiters = (value >> SSystemRWLock::LockSharedWaitersShift) & SSystemRWLock::LockSharedWaitersMask;

        if (InterlockedCompareExchange(&rwl->m_vValue, value & ~(SSystemRWLock::LockOwned | (SSystemRWLock::LockSharedWaitersMask << SSystemRWLock::LockSharedWaitersShift)), value) == value)
        {
          if (sharedWaiters != 0)
            ReleaseSemaphore(rwl->m_WakeEventForReaders, sharedWaiters, NULL);
          break;
        }
      }
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLTryLockReader(const Tptr a_cpRWLHandle)
{ CALL
  // Try to reader lock the non empty reader/writer lock.
  SSystemRWLock* rwl = (SSystemRWLock*)a_cpRWLHandle;
  if (rwl != NULL)
  {
    LONG value = rwl->m_vValue;

    if ((value & SSystemRWLock::ExclusiveMask) != 0)
      return false;

    if ((value & SSystemRWLock::LockOwned) == 0)
      return InterlockedCompareExchange(&rwl->m_vValue, value + SSystemRWLock::LockOwned + SSystemRWLock::LockSharedOwnersIncrement, value) == value;
    else if (((value >> SSystemRWLock::LockSharedOwnersShift) & SSystemRWLock::LockSharedOwnersMask) != 0)
      return InterlockedCompareExchange(&rwl->m_vValue, value + SSystemRWLock::LockSharedOwnersIncrement, value) == value;
    else
      return false;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLTryLockWriter(const Tptr a_cpRWLHandle)
{ CALL
  // Try to writer lock the non empty reader/writer lock.
  SSystemRWLock* rwl = (SSystemRWLock*)a_cpRWLHandle;
  if (rwl != NULL)
  {
    LONG value = rwl->m_vValue;

    if ((value & (SSystemRWLock::LockOwned | SSystemRWLock::LockExclusiveWaking)) != 0)
      return false;

    return InterlockedCompareExchange(&rwl->m_vValue, value + SSystemRWLock::LockOwned, value) == value;
  }
  else
    return false;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
#endif
