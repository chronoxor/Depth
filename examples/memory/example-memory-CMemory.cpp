/*!
 *  \file    example-memory-CMemory.cpp Example of using the CMemory class.
 *  \brief   Example of using the CMemory class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CMemory class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth memory examples
    VERSION:   1.0
    CREATED:   28.06.2007 02:02:17

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
// Common headers.
#include <Depth/include/application/IApplication.hpp>
#include <Depth/include/stream/CStreamStdOutput.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/memory/CMemory.hpp>
#include <Depth/include/memory/managers/CMemoryManagerSystem.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NMemory;
/*==========================================================================*/
class MyMemoryManager :
  public CMemoryManagerSystem
{
protected:
  virtual Tptr allocate(const Tuint a_cSize)
  { CALL
    Tptr pointer = CMemoryManagerSystem::allocate(a_cSize);

    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CMemoryManagerSystem::allocate()") << ln;
    return pointer;
  }

  virtual Tptr reallocate(Tptr a_pPointer, const Tuint a_cSize)
  { CALL
    Tptr pointer = CMemoryManagerSystem::reallocate(a_pPointer, a_cSize);

    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CMemoryManagerSystem::reallocate()") << ln;
    return pointer;
  }

  virtual Tbool free(Tptr a_pPointer)
  { CALL
    Tbool result = CMemoryManagerSystem::free(a_pPointer);

    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CMemoryManagerSystem::free()") << ln;
    return result;
  }
};
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    IMemoryManager* old_manager = NULL;
    IMemoryManager* new_manager = newex MyMemoryManager();

    // Get old memory manager.
    old_manager = CMemory::getMemoryManager();

    // Set new memory manager.
    CMemory::setMemoryManager(new_manager);

    // Allocate block of memory.
    Tptr block = CMemory::allocate(100);

    // Reallocate block of memory.
    block = CMemory::reallocate(block, 1000);

    // Free block of memory.
    CMemory::free(block);

    // Restore old memory manager.
    CMemory::setMemoryManager(old_manager);
    // Delete new memory manager.
    delete new_manager;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
