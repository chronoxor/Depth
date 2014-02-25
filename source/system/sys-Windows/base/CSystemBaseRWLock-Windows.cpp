/*!
 *  \file    CSystemBaseRWLock-Windows.cpp Base system class contains
 *           common functionality such as memory routines, math functions,
 *           error handling, standard I/O routines.
 *  \brief   Base system class - Windows OS - reader/writer lock methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.01.2011
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Windows OS - reader/writer lock methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
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
#include "../Windows.hpp"
/*==========================================================================*/
#ifndef __CSYSTEMBASERWLOCK_WINDOWS_CPP__
#define __CSYSTEMBASERWLOCK_WINDOWS_CPP__
/*==========================================================================*/
#if (defined(__WINDOWS__) && !defined(__WINDOWS_MOBILE__))
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
  PSRWLOCK srwl = (PSRWLOCK)CSystemBase::memoryAllocate(sizeof(SRWLOCK));
  // Initialize the reader/writer lock.
  if (srwl != NULL)
  {
    // Initialize the slim reader/writer lock.
    InitializeSRWLock(srwl);
  }
  return srwl;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLDestroy(const Tptr a_cpRWLHandle)
{ CALL
  // Destroy the non empty reader/writer lock.
  PSRWLOCK srwl = (PSRWLOCK)a_cpRWLHandle;
  if (srwl != NULL)
  {
    // For the slim reader/writer lock we don't need any destroy operation.
    return CSystemBase::memoryFree(srwl);
  }
  else
    return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLLockReader(const Tptr a_cpRWLHandle)
{ CALL
  // Reader lock the non empty reader/writer lock.
  PSRWLOCK srwl = (PSRWLOCK)a_cpRWLHandle;
  if (srwl != NULL)
  {
    // Acquire shared lock for the current slim reader/writer lock.
    AcquireSRWLockShared(srwl); 
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLLockWriter(const Tptr a_cpRWLHandle)
{ CALL
  // Writer lock the non empty slim reader/writer lock.
  PSRWLOCK srwl = (PSRWLOCK)a_cpRWLHandle;
  if (srwl != NULL)
  {
    // Acquire exclusive lock for the current slim reader/writer lock.
    AcquireSRWLockExclusive(srwl); 
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLUnlockReader(const Tptr a_cpRWLHandle)
{ CALL
  // Reader unlock the non empty reader/writer lock.
  PSRWLOCK srwl = (PSRWLOCK)a_cpRWLHandle;
  if (srwl != NULL)
  {
    // Release shared lock for the current slim reader/writer lock.
    ReleaseSRWLockShared(srwl); 
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLUnlockWriter(const Tptr a_cpRWLHandle)
{ CALL
  // Writer unlock the non empty reader/writer lock.
  PSRWLOCK srwl = (PSRWLOCK)a_cpRWLHandle;
  if (srwl != NULL)
  {
    // Release exclusive lock for the current slim reader/writer lock.
    ReleaseSRWLockExclusive(srwl); 
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLTryLockReader(const Tptr a_cpRWLHandle)
{ CALL
  // Try to reader lock the non empty reader/writer lock.
  PSRWLOCK srwl = (PSRWLOCK)a_cpRWLHandle;
  if (srwl != NULL)
  {
    // Try to acquire shared lock for the current slim reader/writer lock.
    return TryAcquireSRWLockShared(srwl); 
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLTryLockWriter(const Tptr a_cpRWLHandle)
{ CALL
  // Try to writer lock the non empty reader/writer lock.
  PSRWLOCK srwl = (PSRWLOCK)a_cpRWLHandle;
  if (srwl != NULL)
  {
    // Try to acquire exclusive lock for the current slim reader/writer lock.
    return TryAcquireSRWLockExclusive(srwl); 
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
