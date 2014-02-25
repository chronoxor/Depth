/*!
 *  \file    CSystemBaseCriticalSection-Unix.cpp Base system class contains
 *           common functionality such as memory routines, math functions,
 *           error handling, standard I/O routines.
 *  \brief   Base system class - Unix OS - critical section's methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Unix OS - critical section's methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   12.06.2007 02:25:23

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
#include "../Unix.hpp"
/*==========================================================================*/
#ifndef __CSYSTEMBASECRITICALSECTION_UNIX_CPP__
#define __CSYSTEMBASECRITICALSECTION_UNIX_CPP__
/*==========================================================================*/
#if (defined(__UNIX__) && !defined(__CYGWIN__))
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tptr CSystemBase::criticalSectionCreate()
{ CALL
  // Allocate memory for a new critical section.
  pthread_spinlock_t* cs = (pthread_spinlock_t*)CSystemBase::memoryAllocate(sizeof(pthread_spinlock_t));
  // Initialize the critical section.
  if (cs != NULL)
  {
    // Initialize spin lock.
    if (pthread_spin_init(cs, PTHREAD_PROCESS_PRIVATE) != 0)
    {
      WARNING(STR("Cannot create a new spin lock for the critical section."));
      CSystemBase::memoryFree(cs);
      return NULL;
    }
  }
  return cs;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::criticalSectionDestroy(const Tptr a_cpCSHandle)
{ CALL
  // Destroy the non empty critical section.
  pthread_spinlock_t* cs = (pthread_spinlock_t*)a_cpCSHandle;
  if (cs != NULL)
  {
    // Destroy the spin lock.
    if (pthread_spin_destroy(cs) != 0)
    {
      WARNING(STR("Cannot destroy the spin lock of the critical section."));
      return false;
    }

    return CSystemBase::memoryFree(cs);
  }
  else
    return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::criticalSectionLock(const Tptr a_cpCSHandle)
{ CALL
  // Lock the non empty critical section.
  pthread_spinlock_t* cs = (pthread_spinlock_t*)a_cpCSHandle;
  if (cs != NULL)
  {
    // Spin lock.
    if (pthread_spin_lock(cs) != 0)
    {
      WARNING(STR("Cannot lock the critical section with a spin lock handle - %p.") COMMA cs);
      return false;
    }
    else
      return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::criticalSectionUnlock(const Tptr a_cpCSHandle)
{ CALL
  // Unlock the non empty critical section.
  pthread_spinlock_t* cs = (pthread_spinlock_t*)a_cpCSHandle;
  if (cs != NULL)
  {
    // Spin unlock.
    if (pthread_spin_unlock(cs) != 0)
    {
      WARNING(STR("Cannot unlock the critical section with a spin lock handle - %p.") COMMA cs);
      return false;
    }
    else
      return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::criticalSectionTryLock(const Tptr a_cpCSHandle)
{ CALL
  // Try to lock the non empty critical section.
  pthread_spinlock_t* cs = (pthread_spinlock_t*)a_cpCSHandle;
  if (cs != NULL)
    return (pthread_spin_trylock(cs) == 0);
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
