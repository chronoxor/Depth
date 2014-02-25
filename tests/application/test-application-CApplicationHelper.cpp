/*!
 *  \file    test-application-CApplicationHelper.cpp Testing of the
 *           CApplicationHelper class.
 *  \brief   Testing of the CApplicationHelper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CApplicationHelper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth application tests
    VERSION:   1.0
    CREATED:   13.01.2009 23:56:59

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
#include <Depth/include/unit/CUnitTestLauncher.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/application/IApplication.hpp>
#include <Depth/include/application/details/CApplicationHelper.hpp>
#include <Depth/include/stream/CStreamStdOutput.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NApplication;
using namespace NDepth::NApplication::NDetails;
using namespace NDepth::NContainers;
using namespace NDepth::NString;
using namespace NDepth::NStream;
/*==========================================================================*/
class CApplicationUnitTestLauncher :
  public CUnitTestLauncher
{
protected:
  // Install unit test launcher.
  Tbool install()
  { CALL
    // Enable checking for memory leaks.
    enableMemoryChecking();
    return true;
  }

  // Uninstall unit test launcher.
  Tbool uninstall()
  { CALL
    // Disable checking for memory leaks.
    disableMemoryChecking();
    return true;
  }

  // Entry point of the unit test launcher.
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    // Run base unit test launcher implementation.
    EUnitTestResult result = (EUnitTestResult)CUnitTestLauncher::main(a_crArguments, a_crEnvironment);

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    // Inform about the unit tests results.
    switch (result)
    {
      case e_TEST_STOPPED:
      {
        stdoutput.write(ASC("!!! - Test execution was stopped!"));
        return IApplication::EXIT_WITH_SUCCESS;
      }
      case e_TEST_SUCCESS:
      {
        stdoutput.write(ASC("+++ - Test passed successfully!"));
        return IApplication::EXIT_WITH_SUCCESS;
      }
      case e_TEST_WARNING:
      {
        stdoutput.write(ASC("??? - Test passed with some warnings!"));
        return IApplication::EXIT_WITH_WARNING;
      }
      case e_TEST_ERROR:
      {
        stdoutput.write(ASC("--- - Test failed with some errors!"));
        return IApplication::EXIT_WITH_ERROR;
      }
    }
    return IApplication::EXIT_WITH_SUCCESS;
  }
};
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT(IApplication::isCreated());
    UT_ASSERT(IApplication::isRunning());
    UT_ASSERT_MORE(IApplication::getCurrentRef().getArguments().getSize(), 0);
    UT_ASSERT_EQUAL(IApplication::getCurrentRef().getArguments()[CONSTU(1)], CString(STR("test")));
    UT_ASSERT_EQUAL(IApplication::getCurrentRef().getArguments()[CONSTU(2)], CString(STR("test\\test")));
    UT_ASSERT_EQUAL(IApplication::getCurrentRef().getArguments()[CONSTU(3)], CString(STR("test\\\\test")));
    UT_ASSERT_EQUAL(IApplication::getCurrentRef().getArguments()[CONSTU(4)], CString(STR("test\"test")));
    UT_ASSERT_EQUAL(IApplication::getCurrentRef().getArguments()[CONSTU(5)], CString(STR("test'test")));
    UT_ASSERT_EQUAL(IApplication::getCurrentRef().getArguments()[CONSTU(6)], CString(STR("test test")));
    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
#if (defined(__WINDOWS_MOBILE__))
int wmain(int argc, wchar_t *argv[], wchar_t *envp[])
#else
int main(int argc, char *argv[], char *envp[])
#endif
{ CALL
  CApplicationUnitTestLauncher application;

  // Parse program arguments and environment variables.
  CStringBuffer<CString> arguments;
  CStringBuffer<CString> environment;
  CApplicationHelper::parseProgramArguments(arguments, argc, argv);
  CApplicationHelper::parseEnvironmentVariables(environment, envp);

  // Run the application wrapper.
  return (int)application.run(arguments, environment);
}
/*==========================================================================*/
