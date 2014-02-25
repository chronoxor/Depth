/*!
 *  \file    example-application-native.cpp Example of using the native system
 *           entry point with the IApplication interface.
 *  \brief   Example of using the native system entry point with the IApplication interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the native system entry point with the IApplication interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth application examples
    VERSION:   1.0
    CREATED:   13.01.2009 23:39:37

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
    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    // Show all program arguments.
    stdoutput << STR("Program arguments:") << ln;
    for (Tuint i = 0; i < a_crArguments.getSize(); ++i)
      stdoutput << i + 1 << STR(") ") << a_crArguments[i] << ln;
    stdoutput << ln;

    // Show all environment variables.
    stdoutput << STR("Environment variables:") << ln;
    for (Tuint i = 0; i < a_crEnvironment.getSize(); ++i)
      stdoutput << i + 1 << STR(") ") << a_crEnvironment[i] << ln;
    stdoutput << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
};
/*==========================================================================*/
#if (defined(__WINDOWS_MOBILE__))
int wmain(int argc, wchar_t *argv[], wchar_t *envp[])
#else
int main(int argc, char *argv[], char *envp[])
#endif
{ CALL
  CExample application;

  // Run the application wrapper.
  return (int)application.run(argc, argv, envp);
}
/*==========================================================================*/
