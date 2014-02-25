/*!
 *  \file    ISharedLibrary-Windows.cpp Shared library interface provides OS
 *           independent functionality to handle shared libraries
 *           load/unload procedures.
 *  \brief   Shared library interface - Windows OS (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.05.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Shared library interface - Windows OS (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   02.05.2008 23:33:35

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
#include <Depth/include/shared/ISharedLibrary.hpp>
/*--------------------------------------------------------------------------*/
#include "../Windows.hpp"
/*==========================================================================*/
#include "shared.hpp"
/*==========================================================================*/
#ifndef __ISHAREDLIBRARY_WINDOWS_CPP__
#define __ISHAREDLIBRARY_WINDOWS_CPP__
/*==========================================================================*/
#if (defined(__WINDOWS__) || defined(__CYGWIN__))
/*==========================================================================*/
/* LOCAL NAMESPACE DECLARATIONS                                             */
/*==========================================================================*/
namespace {
/*==========================================================================*/
/* LOCAL VARIABLES DECLARATIONS                                             */
/*==========================================================================*/
//! Pointer to the current instance of the shared library.
NDepth::NShared::ISharedLibrary* loc_pSharedLibrary = 0;
/*==========================================================================*/
}
/*==========================================================================*/
/* DYNAMIC-LINK LIBRARY LOADING/UNLOADING                                   */
/*==========================================================================*/
//! Windows system layer dynamic-link library entry point function.
/*!
    This function will be automatically called under Windows platform when the
    current library instance is loading into process  or  unloading  from  the
    process. Here  comes  the  calling  of  a  system  installing/uninstalling
    methods to  initialize  or  release  all  system  dependant  routines  and
    resourses.

    \param hinstDLL - Handle to the DLL module.
    \param fdwReason - Indicates why the DLL entry-point function is being
           called.
    \param lpReserved - If fdwReason is DLL_PROCESS_ATTACH, lpvReserved is
           NULL for dynamic loads and non-NULL for static loads.
    \return TRUE  - if system was installed successfully. \n
            FALSE - if system was not installed successfully. \n
*/
extern "C" BOOL WINAPI DllMain(HANDLE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{ CALL
  IGNORE_UNUSED(hinstDLL);
  IGNORE_UNUSED(lpReserved);

  // Perform actions based on the reason for calling.
  switch (fdwReason)
  {
    // Initialize once for each new process.
    case DLL_PROCESS_ATTACH:
    {
      // Allocate new shared library.
      loc_pSharedLibrary = (SHARED_LIBRARY_CLASS*)HeapAlloc(GetProcessHeap(), 0, sizeof(SHARED_LIBRARY_CLASS));
      if (loc_pSharedLibrary == 0)
      {
        WARNING(STR("DLL loading: Cannot allocate the current shared library."));
        return FALSE;
      }

      // Create new shared library.
      cntr (loc_pSharedLibrary) SHARED_LIBRARY_CLASS();

      // Load shared library.
      if (!loc_pSharedLibrary->onLoad())
      {
        WARNING(STR("DLL loading: Cannot load the current shared library."));

        loc_pSharedLibrary->~ISharedLibrary();
        HeapFree(GetProcessHeap(), 0, loc_pSharedLibrary);
        loc_pSharedLibrary = 0;
        return FALSE;
      }

      break;
    }
    // Do thread-specific initialization.
    case DLL_THREAD_ATTACH:
    {
      break;
    }
    // Do thread-specific cleanup.
    case DLL_THREAD_DETACH:
    {
      break;
    }
    // Perform any necessary cleanup.
    case DLL_PROCESS_DETACH:
    {
      if (loc_pSharedLibrary == 0)
      {
        WARNING(STR("DLL unloading: Cannot unload the current shared library, which was non loaded properly."));
        return FALSE;
      }

      // Unload shared library.
      NDepth::NTypes::Tbool result = loc_pSharedLibrary->onUnload();
      if (!result)
        WARNING(STR("DLL unloading: Cannot unload the current shared library."));

      // Destroy shared library instance.
      loc_pSharedLibrary->~ISharedLibrary();
      if (HeapFree(GetProcessHeap(), 0, loc_pSharedLibrary) == FALSE)
        WARNING(STR("DLL unloading: Cannot destroy the current shared library."));
      loc_pSharedLibrary = 0;

      if (!result)
        return FALSE;

      break;
    }
  }

  // Successful DLL_PROCESS_ATTACH.
  return TRUE;
}
/*==========================================================================*/
#endif
#endif
