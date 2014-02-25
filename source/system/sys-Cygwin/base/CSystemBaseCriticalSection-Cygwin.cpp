/*!
 *  \file    CSystemBaseCriticalSection-Cygwin.cpp Base system class contains
 *           common functionality such as memory routines, math functions,
 *           error handling, standard I/O routines.
 *  \brief   Base system class - Cygwin OS - critical section's methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Cygwin OS - critical section's methods (source).

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
#include "../Cygwin.hpp"
/*==========================================================================*/
#ifndef __CSYSTEMBASECRITICALSECTION_CYGWIN_CPP__
#define __CSYSTEMBASECRITICALSECTION_CYGWIN_CPP__
/*==========================================================================*/
#if (defined(__UNIX__) && defined(__CYGWIN__))
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
  pthread_mutex_t* cs = (pthread_mutex_t*)CSystemBase::memoryAllocate(sizeof(pthread_mutex_t));
  // Initialize the critical section.
  if (cs != NULL)
  {
    // Initialize mutex.
    if (pthread_mutex_init(cs, NULL) != 0)
    {
      WARNING(STR("Cannot create a new mutex for the critical section."));
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
  pthread_mutex_t* cs = (pthread_mutex_t*)a_cpCSHandle;
  if (cs != NULL)
  {
    // Destroy the mutex.
    if (pthread_mutex_destroy(cs) != 0)
    {
      WARNING(STR("Cannot destroy the mutex of the critical section."));
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
  pthread_mutex_t* cs = (pthread_mutex_t*)a_cpCSHandle;
  if (cs != NULL)
  {
    // Lock the mutex.
    if (pthread_mutex_lock(cs) != 0)
    {
      WARNING(STR("Cannot lock the critical section with a mutex handle - %p.") COMMA cs);
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
  pthread_mutex_t* cs = (pthread_mutex_t*)a_cpCSHandle;
  if (cs != NULL)
  {
    // Unlock the mutex.
    if (pthread_mutex_unlock(cs) != 0)
    {
      WARNING(STR("Cannot unlock the critical section with a mutex handle - %p.") COMMA cs);
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
  pthread_mutex_t* cs = (pthread_mutex_t*)a_cpCSHandle;
  if (cs != NULL)
    return (pthread_mutex_trylock(cs) == 0);
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
