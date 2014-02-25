/*!
 *  \file    CUnitTestSuite.cpp Unit test suite collects all unit tests
 *           and allows to launch them with a unit test launcher. Base
 *           implementation of the unit test suite simple launches all
 *           registered tests in the suite.
 *  \brief   Unit test suite class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test suite class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unit test
    VERSION:   1.0
    CREATED:   15.01.2009 23:09:21

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

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
#include <Depth/include/unit.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/unit/CUnitTestSuite.hpp>
/*==========================================================================*/
#ifndef __CUNITTESTSUITE_CPP__
#define __CUNITTESTSUITE_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
UNITTEST_API Tbool CUnitTestSuite::ms_IsLaunched = false;
UNITTEST_API Tbool CUnitTestSuite::ms_IsInstanceCreated = false;
UNITTEST_API CUnitTestSuite* CUnitTestSuite::ms_pInstance = NULL;
/*--------------------------------------------------------------------------*/
CUnitTestSuite::CUnitTestSuite(const Tbool a_cUnitTestFlag) :
  m_Name(STR("NDepth::NUnitTest::CUnitTestSuite")),
  m_FileName(FILE)
{ CALL
  IGNORE_UNUSED(a_cUnitTestFlag);

  // Verify that unit test suite is not created.
  VERIFY(!CUnitTestSuite::isCreated(), STR("Unit test suite has been already created somewhere else."));

  // If there no instance of unit test launcher is created, then create default one.
  if (!CUnitTestLauncher::isCreated())
    CUnitTestLauncher::CreateDefaultInstance();

  CUnitTestSuite::ms_pInstance = this;
}
/*--------------------------------------------------------------------------*/
CUnitTestSuite::CUnitTestSuite(const NString::CString& a_crName/* = STR("NDepth::NUnitTest::CUnitTestSuite") */, const NString::CString& a_crFileName/* = FILE */) :
  m_Name(a_crName),
  m_FileName(a_crFileName)
{ CALL
  // Verify that no default unit test suite is created.
  VERIFY(!CUnitTestSuite::isCreated() || CUnitTestSuite::ms_IsInstanceCreated, STR("Unit test suite has been already created somewhere else."));

  // If there no instance of unit test launcher is created, then create default one.
  if (!CUnitTestLauncher::isCreated())
    CUnitTestLauncher::CreateDefaultInstance();

  // If there default instance of unit test suit is created, then destroy it and initialize the current one.
  if (CUnitTestSuite::isCreated() && CUnitTestSuite::ms_IsInstanceCreated)
  {
    // Swap unit tests list.
    NAlgorithms::NCommon::swap(m_TestList, CUnitTestSuite::ms_pInstance->m_TestList);
    // Destroy default unit test suit.
    CUnitTestSuite::DestroyDefaultInstance();
  }

  CUnitTestSuite::ms_pInstance = this;
}
/*--------------------------------------------------------------------------*/
EUnitTestResult CUnitTestSuite::test()
{ CALL
  // Go through all unit tests...
  NContainers::CListSL<CUnitTest*>::TIterator it(m_TestList.getItFirst());
  if (it.isValid())
  {
    do
    {
      CUnitTest* unit_test = it.getValueRef();

      UT_LOG("Installing unit test: %X (%X)" COMMA &unit_test->getName() COMMA &unit_test->getFileName());

      // Install the unit test.
      if (CUnitTestLauncher::ms_pInstance->onBeforeTestInstall(*unit_test) && unit_test->install() && CUnitTestLauncher::ms_pInstance->onAfterTestInstall(*unit_test) && CUnitTestLauncher::ms_pInstance->onBeforeTestLaunch(*unit_test))
      {
        UT_LOG("Launching unit test: %X (%X)" COMMA &unit_test->getName() COMMA &unit_test->getFileName());

        // Reset unit test timeout.
        unit_test->m_Timeout = NTime::CTimeStamp::getSystemTimeStamp();

        // Launch unit test.
        CUnitTestLauncher::ms_pInstance->setUnitTestResult(unit_test->test());

        UT_LOG("Uninstalling unit test: %X (%X)" COMMA &unit_test->getName() COMMA &unit_test->getFileName());

        // Uninstall the unit test.
        if (!CUnitTestLauncher::ms_pInstance->onAfterTestLaunch(*unit_test) || !CUnitTestLauncher::ms_pInstance->onBeforeTestUninstall(*unit_test) || !unit_test->uninstall() || !CUnitTestLauncher::ms_pInstance->onAfterTestUninstall(*unit_test))
          CUnitTestLauncher::ms_pInstance->setUnitTestResult(e_TEST_STOPPED);
      }
      else
        CUnitTestLauncher::ms_pInstance->setUnitTestResult(e_TEST_STOPPED);
    } while ((CUnitTestLauncher::ms_pInstance->getUnitTestResult() != e_TEST_STOPPED) && (it.stepForward() > 0));
  }

  return CUnitTestLauncher::ms_pInstance->getUnitTestResult();
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestSuite::CreateDefaultInstance()
{ CALL
  // Check if the current unit test suite is not already created.
  ASSERT(!CUnitTestSuite::isCreated(), STR("Current unit test suite is already created. Cannot create unit test suite twice."))
  {
    return false;
  }

  // Create default unit tests suite instance.
  CUnitTestSuite::ms_pInstance = newex CUnitTestSuite(true);
  if (CUnitTestSuite::ms_pInstance == NULL)
  {
    WARNING(STR("Cannot allocate memory buffer for the unit test suite (requested size is %u bytes).") COMMA (sizeof(CUnitTestSuite)));
    return false;
  }

  CUnitTestSuite::ms_IsInstanceCreated = true;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestSuite::DestroyDefaultInstance()
{ CALL
  if (CUnitTestSuite::ms_IsInstanceCreated)
  {
    delete CUnitTestSuite::ms_pInstance;
    CUnitTestSuite::ms_IsInstanceCreated = false;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestSuite::RegisterUnitTest(CUnitTest* a_pUnitTest)
{ CALL
  // Check if the current unit test suite is created.
  ASSERT(CUnitTestSuite::isCreated(), STR("Cannot register unit test because unit test suite was not created."))
  {
    return false;
  }

  // Insert unit test into the list of the current unit test suite.
  return CUnitTestSuite::ms_pInstance->m_TestList.insertLast(a_pUnitTest);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
