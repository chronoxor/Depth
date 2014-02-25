/*!
 *  \file    CSystemBaseCriticalSection-Windows.cpp Base system class
 *           contains common functionality such as memory routines, math
 *           functions, error handling, standard I/O routines.
 *  \brief   Base system class - Windows OS - critical section's methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Windows OS - critical section's methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   12.06.2007 02:26:48

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
#ifndef __CSYSTEMBASECRITICALSECTION_WINDOWS_CPP__
#define __CSYSTEMBASECRITICALSECTION_WINDOWS_CPP__
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
Tptr CSystemBase::criticalSectionCreate()
{ CALL
  // Allocate memory for a new critical section.
  LPCRITICAL_SECTION cs = (LPCRITICAL_SECTION)CSystemBase::memoryAllocate(sizeof(CRITICAL_SECTION));
  // Initialize the critical section.
  if (cs != NULL)
  {
    // Initialize the critical section with a default spin count 4000.
    if (InitializeCriticalSectionEx(cs, 4000, 0) == FALSE)
    {
      WARNING(STR("Cannot initialize a new critical section with a spin count."));
      CSystemBase::memoryFree(cs);
      cs = NULL;
    }
  }
  return cs;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::criticalSectionDestroy(const Tptr a_cpCSHandle)
{ CALL
  // Destroy the non empty critical section.
  LPCRITICAL_SECTION cs = (LPCRITICAL_SECTION)a_cpCSHandle;
  if (cs != NULL)
  {
    DeleteCriticalSection(cs);
    return CSystemBase::memoryFree(cs);
  }
  else
    return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::criticalSectionLock(const Tptr a_cpCSHandle)
{ CALL
  // Lock the non empty critical section.
  LPCRITICAL_SECTION cs = (LPCRITICAL_SECTION)a_cpCSHandle;
  if (cs != NULL)
  {
    EnterCriticalSection(cs);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::criticalSectionUnlock(const Tptr a_cpCSHandle)
{ CALL
  // Unlock the non empty critical section.
  LPCRITICAL_SECTION cs = (LPCRITICAL_SECTION)a_cpCSHandle;
  if (cs != NULL)
  {
    LeaveCriticalSection(cs);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::criticalSectionTryLock(const Tptr a_cpCSHandle)
{ CALL
  // Try to lock the non empty critical section.
  LPCRITICAL_SECTION cs = (LPCRITICAL_SECTION)a_cpCSHandle;
  if (cs != NULL)
    return (TryEnterCriticalSection(cs) != FALSE);
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
