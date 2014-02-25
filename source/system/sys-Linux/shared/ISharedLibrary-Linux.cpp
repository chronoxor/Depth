/*!
 *  \file    ISharedLibrary-Linux.cpp Shared library interface provides OS
 *           independent functionality to handle shared libraries
 *           load/unload procedures.
 *  \brief   Shared library interface - Linux OS (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Shared library interface - Linux OS (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   28.08.2008 02:42:48

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
#include "../Linux.hpp"
/*==========================================================================*/
#include "shared.hpp"
/*==========================================================================*/
#ifndef __ISHAREDLIBRARY_LINUX_CPP__
#define __ISHAREDLIBRARY_LINUX_CPP__
/*==========================================================================*/
#if (defined(__UNIX__) && defined(__LINUX__))
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
//! Linux system layer dynamic-link library loading.
/*!
    This function will be automatically called under Linux platform  when  the
    current library instance is loading into process. Here comes  the  calling
    of a system installing method to initialize all system dependant  routines
    and resourses.
*/
extern "C" void __attribute__ ((constructor)) JOIN(SHARED_LIBRARY_NAME, _init)(void)
{ CALL
  // Allocate new shared library.
  loc_pSharedLibrary = (SHARED_LIBRARY_CLASS*)malloc(sizeof(SHARED_LIBRARY_CLASS));
  if (loc_pSharedLibrary == 0)
  {
    WARNING(STR("DLL loading: Cannot allocate the current shared library."));
    exit(-1);
  }

  // Create new shared library.
  cntr (loc_pSharedLibrary) SHARED_LIBRARY_CLASS();

  // Load shared library.
  if (!loc_pSharedLibrary->onLoad())
  {
    WARNING(STR("DLL loading: Cannot load the current shared library."));

    loc_pSharedLibrary->~ISharedLibrary();
    free(loc_pSharedLibrary);
    loc_pSharedLibrary = 0;
    exit(-1);
  }
}
/*--------------------------------------------------------------------------*/
//! Linux system layer dynamic-link library unloading.
/*!
    This function will be automatically called under Linux platform  when  the
    current library instance is unloading from the  process.  Here  comes  the
    calling of a system uninstalling method to release  all  system  dependant
    routines and resourses.
*/
extern "C" void __attribute__ ((destructor)) JOIN(SHARED_LIBRARY_NAME, _fini)(void)
{ CALL
  if (loc_pSharedLibrary == 0)
  {
    WARNING(STR("DLL unloading: Cannot unload the current shared library, which was non loaded properly."));
    exit(-1);
  }

  // Unload shared library.
  NDepth::NTypes::Tbool result = loc_pSharedLibrary->onUnload();

  // Destroy shared library instance.
  loc_pSharedLibrary->~ISharedLibrary();
  free(loc_pSharedLibrary);
  loc_pSharedLibrary = 0;

  if (!result)
  {
    WARNING(STR("DLL unloading: Cannot unload the current shared library."));
    exit(-1);
  }
}
/*==========================================================================*/
#endif
#endif
