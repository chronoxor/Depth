/*!
 *  \file    example-unit-CUnitTestLauncher.cpp Example of using the
 *           CUnitTestLauncher class.
 *  \brief   Example of using the CUnitTestLauncher class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CUnitTestLauncher class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth unit test examples
    VERSION:   1.0
    CREATED:   17.01.2009 23:48:30

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
#include <Depth/include/stream/CStreamStdOutput.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NContainers;
using namespace NDepth::NString;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NStream;
/*==========================================================================*/
class CExampleUnitTestLauncher :
  public CUnitTestLauncher
{
public:
  // Initialize unit test launcher with a corresponding name and file name.
  CExampleUnitTestLauncher(const CString& a_crName, const CString& a_crFileName) : CUnitTestLauncher(a_crName, a_crFileName) { CALL }

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
} the_ExampleUnitTestLauncher(STR("CExampleUnitTestLauncher"), FILE);
/*--------------------------------------------------------------------------*/
class CExampleUnitTestSuite :
  public CUnitTestSuite
{
public:
  Tsint m_X;
  Tsint m_Y;

  // Initialize unit test suite with a corresponding name and file name.
  CExampleUnitTestSuite(const CString& a_crName, const CString& a_crFileName) : CUnitTestSuite(a_crName, a_crFileName) { CALL }

protected:
  // Install unit test suite.
  Tbool install()
  { CALL
    m_X = 1;
    m_Y = 10;
    return true;
  }

  // Uninstall unit test suite.
  Tbool uninstall()
  { CALL
    m_X = 2;
    m_Y = 20;
    return true;
  }
} the_ExampleUnitTestSuite(STR("CExampleUnitTestSuite"), FILE);
/*--------------------------------------------------------------------------*/
class CExampleUnitTest1 :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ACCEPT;
  }
} the_ExampleUnitTest1;
/*--------------------------------------------------------------------------*/
class CExampleUnitTest2 :
  public CUnitTest
{
public:
  // Initialize unit test with a corresponding name and file name.
  CExampleUnitTest2(const CString& a_crName, const CString& a_crFileName) : CUnitTest(a_crName, a_crFileName) { CALL }

protected:
  // Install unit test.
  Tbool install()
  { CALL
    m_Z = the_ExampleUnitTestSuite.m_X + the_ExampleUnitTestSuite.m_Y + 100;
    return true;
  }

  // Uninstall unit test.
  Tbool uninstall()
  { CALL
    m_Z = the_ExampleUnitTestSuite.m_X + the_ExampleUnitTestSuite.m_Y + 200;
    return true;
  }

  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT_EQUAL(m_Z, 111);
    UT_ACCEPT;
  }

private:
  Tsint m_Z;
} the_ExampleUnitTest2(STR("CExampleUnitTest2"), FILE);
/*==========================================================================*/
