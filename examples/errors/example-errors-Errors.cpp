/*!
 *  \file    example-errors-Errors.cpp Example of using the Depth errors
 *           handling.
 *  \brief   Example of using the Depth errors handling.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the Depth errors handling.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth errors examples
    VERSION:   1.0
    CREATED:   03.01.2007 02:57:39

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
#include <Depth/include/errors.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    Tbool ok = true;
    Tbool failed = false;

    // Check simple 'true' assertion.
    ASSERT(ok, STR("Never appears!"));

    // Check 'true' assertion with action.
    ASSERT(ok, STR("Never appears!"))
    {
      stdoutput << STR("Never will be printed!") << ln;
    }

    // Check 'true' assertion with both actions.
    ASSERT(ok, STR("Never appears!"))
    {
      stdoutput << STR("Never will be printed!") << ln;
    }
    else
    {
      stdoutput << STR("Always will be printed!") << ln;
    }

    // Check simple 'false' assertion.
    ASSERT(failed, STR("Always appears!"));

    // Check 'false' assertion with action.
    ASSERT(failed, STR("Always appears!"))
    {
      stdoutput << STR("Always will be printed!") << ln;
    }

    // Check 'false' assertion with both actions.
    ASSERT(failed, STR("Always appears!"))
    {
      stdoutput << STR("Always will be printed!") << ln;
    }
    else
    {
      stdoutput << STR("Never will be printed!") << ln;
    }

    // Check NULL pointer assumption with additional action.
    Tstr ptr = NULL;
    ASSUME((ptr != NULL), STR("Pointer is NULL!"))
    {
      stdoutput << STR("Trying to allocate buffer!") << ln;
      ptr = newex Tchar[256];
    }

    // Print simple warning.
    WARNING(STR("Simple warning"));
    // Print warning with argument.
    WARNING(STR("Warning with argument: %u") COMMA 100);

    // Verify the pointer value.
    VERIFY((ptr != NULL), STR("Critical error: pointer is NULL!"));

    // Generate error.
    ERROR(STR("Critical error!"));

    // Show static error.
    // STATIC_ERROR(STR("Static error message!"));
    // Show static warning.
    // STATIC_WARNING(STR("Static warning message!"));

    // Static assertion: true
    STATIC_ASSERT((sizeof(int) <= sizeof(long)), STR("'int' is less or equal than 'long'"));
    // Static assertion: flase
    // STATIC_ASSERT((sizeof(int) > sizeof(long)), STR("'int' is not more than 'long'"));

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
