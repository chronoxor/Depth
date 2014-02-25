/*!
 *  \file    CUnitTestLauncher.cpp Unit test launcher is a base class for
 *           different launchers. Base implementation of the unit test
 *           launcher simple launches all registered tests in the current
 *           unit test suite.
 *  \brief   Unit test launcher class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test launcher class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unit test
    VERSION:   1.0
    CREATED:   15.01.2009 02:53:28

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
#include <Depth/include/algorithms/string/format/AFormat.hpp>
#include <Depth/include/memory/CMemory.hpp>
#include <Depth/include/unit/CUnitTestLauncher.hpp>
/*==========================================================================*/
#ifndef __CUNITTESTLAUNCHER_CPP__
#define __CUNITTESTLAUNCHER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
UNITTEST_API Tbool CUnitTestLauncher::ms_IsLaunched = false;
UNITTEST_API Tbool CUnitTestLauncher::ms_IsInstanceCreated = false;
UNITTEST_API CUnitTestLauncher* CUnitTestLauncher::ms_pInstance = NULL;
/*--------------------------------------------------------------------------*/
CUnitTestLauncher::CUnitTestLauncher(const Tbool a_cUnitTestFlag) :
  NApplication::IApplication(true),
  m_Name(STR("NDepth::NUnitTest::CUnitTestLauncher")),
  m_FileName(FILE),
  m_UnitTestResult(e_TEST_SUCCESS),
  m_Locker(true),
  m_IsMemoryCheckingEnabled(false),
  m_OldAllocBlocks(0),
  m_OldAllocSize(0)
{ CALL
  IGNORE_UNUSED(a_cUnitTestFlag);

  // Verify that unit test launcher is not created.
  VERIFY(!CUnitTestLauncher::isCreated(), STR("Unit test launcher has been already created somewhere else."));

  IApplication::ms_pInstance = this;
  CUnitTestLauncher::ms_pInstance = this;
}
/*--------------------------------------------------------------------------*/
CUnitTestLauncher::CUnitTestLauncher(const NString::CString& a_crName/* = STR("NDepth::NUnitTest::CUnitTestLauncher") */, const NString::CString& a_crFileName/* = FILE */) :
  NApplication::IApplication(true),
  m_Name(a_crName),
  m_FileName(a_crFileName),
  m_UnitTestResult(e_TEST_SUCCESS),
  m_Locker(true),
  m_IsMemoryCheckingEnabled(false),
  m_OldAllocBlocks(0),
  m_OldAllocSize(0)
{ CALL
  // Verify that no default unit test launcher is created.
  VERIFY(!CUnitTestLauncher::isCreated() || CUnitTestLauncher::ms_IsInstanceCreated, STR("Unit test launcher has been already created somewhere else."));

  // If there default instance of unit test launcher is created, then destroy it and initialize the current one.
  if (CUnitTestLauncher::isCreated() && CUnitTestLauncher::ms_IsInstanceCreated)
  {
    // Destroy default unit test launcher.
    CUnitTestLauncher::DestroyDefaultInstance();
  }

  IApplication::ms_pInstance = this;
  CUnitTestLauncher::ms_pInstance = this;
}
/*--------------------------------------------------------------------------*/
EUnitTestResult CUnitTestLauncher::test()
{ CALL
  // Check if the current unit test suite is created.
  ASSERT(CUnitTestSuite::isCreated(), STR("Cannot perform unit testing without created instance of the unit test suite."))
  {
    return e_TEST_STOPPED;
  }

  UT_LOG("Installing unit test suite: %X (%X)" COMMA &CUnitTestSuite::ms_pInstance->getName() COMMA &CUnitTestSuite::ms_pInstance->getFileName());

  // Install the unit test suite.
  if (onBeforeSuiteInstall(*CUnitTestSuite::ms_pInstance) && CUnitTestSuite::ms_pInstance->install() && onAfterSuiteInstall(*CUnitTestSuite::ms_pInstance) && onBeforeSuiteLaunch(*CUnitTestSuite::ms_pInstance))
  {
    UT_LOG("Launching unit test suite: %X (%X)" COMMA &CUnitTestSuite::ms_pInstance->getName() COMMA &CUnitTestSuite::ms_pInstance->getFileName());

    CUnitTestSuite::ms_IsLaunched = true;
    setUnitTestResult(CUnitTestSuite::ms_pInstance->test());
    CUnitTestSuite::ms_IsLaunched = false;

    UT_LOG("Uninstalling unit test suite: %X (%X)" COMMA &CUnitTestSuite::ms_pInstance->getName() COMMA &CUnitTestSuite::ms_pInstance->getFileName());

    // Uninstall the unit test suite.
    if (!onAfterSuiteLaunch(*CUnitTestSuite::ms_pInstance) || !onBeforeSuiteUninstall(*CUnitTestSuite::ms_pInstance) || !CUnitTestSuite::ms_pInstance->uninstall() || !onAfterSuiteUninstall(*CUnitTestSuite::ms_pInstance))
      setUnitTestResult(e_TEST_STOPPED);
  }
  else
    setUnitTestResult(e_TEST_STOPPED);

  return getUnitTestResult();
}
/*--------------------------------------------------------------------------*/
Tsint CUnitTestLauncher::main(const NContainers::CStringBuffer<NString::CString>& a_crArguments, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment)
{ CALL
  IGNORE_UNUSED(a_crArguments);
  IGNORE_UNUSED(a_crEnvironment);

  // Check if the current unit test launcher is created.
  ASSERT(CUnitTestLauncher::isCreated(), STR("Cannot perform unit testing without created instance of the unit test launcher."))
  {
    return e_TEST_STOPPED;
  }

  // Force test result to be successive.
  setUnitTestResult(e_TEST_SUCCESS, true);

  UT_LOG("Installing unit test launcher: %X (%X)" COMMA &CUnitTestLauncher::ms_pInstance->getName() COMMA &CUnitTestLauncher::ms_pInstance->getFileName());

  // Install the unit test launcher.
  if (onBeforeLauncherInstall(*CUnitTestLauncher::ms_pInstance) && CUnitTestLauncher::ms_pInstance->install() && onAfterLauncherInstall(*CUnitTestLauncher::ms_pInstance) && onBeforeLauncherLaunch(*CUnitTestLauncher::ms_pInstance))
  {
    UT_LOG("Launching unit test launcher: %X (%X)" COMMA &CUnitTestLauncher::ms_pInstance->getName() COMMA &CUnitTestLauncher::ms_pInstance->getFileName());

    CUnitTestLauncher::ms_IsLaunched = true;
    CUnitTestLauncher::ms_pInstance->setUnitTestResult(CUnitTestLauncher::ms_pInstance->test());
    CUnitTestLauncher::ms_IsLaunched = false;

    UT_LOG("Uninstalling unit test launcher: %X (%X)" COMMA &CUnitTestLauncher::ms_pInstance->getName() COMMA &CUnitTestLauncher::ms_pInstance->getFileName());

    // Uninstall the unit test launcher.
    if (!onAfterLauncherLaunch(*CUnitTestLauncher::ms_pInstance) || !onBeforeLauncherUninstall(*CUnitTestLauncher::ms_pInstance) || !CUnitTestLauncher::ms_pInstance->uninstall() || !onAfterLauncherUninstall(*CUnitTestLauncher::ms_pInstance))
      CUnitTestLauncher::ms_pInstance->setUnitTestResult(e_TEST_STOPPED);
  }
  else
    CUnitTestLauncher::ms_pInstance->setUnitTestResult(e_TEST_STOPPED);

  EUnitTestResult result = CUnitTestLauncher::ms_pInstance->getUnitTestResult();

  // Destroy default unit test suite instance.
  CUnitTestSuite::DestroyDefaultInstance();

  // Destroy default unit test launcher instance.
  CUnitTestLauncher::DestroyDefaultInstance();

  return result;
}
/*--------------------------------------------------------------------------*/
void CUnitTestLauncher::setUnitTestResult(const EUnitTestResult a_cUnitTestResult, const Tbool a_cForceSet/* = false */)
{ CALL
  // Exclusive lock the current instance of the unit test launcher under the multi-threaded environment.
  NProcess::CScopeWriter wlocker(m_Locker);

  // Update unit test launcher result value.
  if ((a_cForceSet) || (m_UnitTestResult == e_TEST_SUCCESS))
    m_UnitTestResult = a_cUnitTestResult;
  else if ((m_UnitTestResult == e_TEST_WARNING) && ((a_cUnitTestResult == e_TEST_ERROR) || (a_cUnitTestResult == e_TEST_STOPPED)))
    m_UnitTestResult = a_cUnitTestResult;
  else if ((m_UnitTestResult == e_TEST_ERROR) && (a_cUnitTestResult == e_TEST_STOPPED))
    m_UnitTestResult = a_cUnitTestResult;
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestLauncher::CreateDefaultInstance()
{ CALL
  // Check if the current unit test launcher is not already created.
  ASSERT(!CUnitTestLauncher::isCreated(), STR("Current unit test launcher is already created. Cannot create unit test launcher twice."))
  {
    return false;
  }

  // Create default unit tests launcher instance.
  CUnitTestLauncher::ms_pInstance = newex CUnitTestLauncher(true);
  if (CUnitTestLauncher::ms_pInstance == NULL)
  {
    WARNING(STR("Cannot allocate memory buffer for the unit test launcher (requested size is %u bytes).") COMMA (sizeof(CUnitTestLauncher)));
    return false;
  }

  CUnitTestLauncher::ms_IsInstanceCreated = true;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestLauncher::DestroyDefaultInstance()
{ CALL
  if (CUnitTestLauncher::ms_IsInstanceCreated)
  {
    delete CUnitTestLauncher::ms_pInstance;
    CUnitTestLauncher::ms_IsInstanceCreated = false;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestLauncher::enableMemoryChecking()
{ CALL
  // Check if the memory checking is not enabled.
  ASSERT(!isMemoryCheckingEnabled(), STR("Memory checking is already enabled."))
  {
    setUnitTestResult(e_TEST_STOPPED);
    return false;
  }

  Tbool result = true;
  {
    // Exclusive lock the current instance of the unit test launcher under the multi-threaded environment.
    NProcess::CScopeWriter wlocker(m_Locker);

    // Enable memory GC engine.
    if (NMemory::CMemory::enableGC())
    {
      // Store current memory information.
      m_OldAllocBlocks = NMemory::CMemory::getGCAllocatedBlocks();
      m_OldAllocSize = NMemory::CMemory::getGCAllocatedSize();
      m_IsMemoryCheckingEnabled = true;
    }
    else
      result = false;
  }

  // Check the result value.
  if (result)
    return true;
  else
  {
    setUnitTestResult(e_TEST_STOPPED);
    return false;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestLauncher::disableMemoryChecking(const Tbool a_cGenerateError/* = true */)
{ CALL
  // Check if the memory checking is enabled.
  ASSERT(isMemoryCheckingEnabled(), STR("Memory checking is not enabled."))
  {
    setUnitTestResult(e_TEST_STOPPED);
    return false;
  }

  Tbool result = true;
  {
    // Exclusive lock the current instance of the unit test launcher under the multi-threaded environment.
    NProcess::CScopeWriter wlocker(m_Locker);

    // Check the memory state after test.
    Tuint new_alloc_blocks = NMemory::CMemory::getGCAllocatedBlocks();
    Tuint new_alloc_size = NMemory::CMemory::getGCAllocatedSize();

    // Inform about memory leaks.
    if ((m_OldAllocBlocks != new_alloc_blocks) || (m_OldAllocSize != new_alloc_size))
    {
      // Prepare error string.
      NString::CString message = NAlgorithms::NString::NFormat::format(STR("Memory leak detected! Allocated memory blocks: was %u, now %u. Allocated memory size: was %u bytes, now %u bytes."), m_OldAllocBlocks, new_alloc_blocks, m_OldAllocSize, new_alloc_size);

      // Output information into the unit test logging engine.
      NDepth::NUnitTest::NDetails::unitTestLog(FUNCTION_SIGNATURE, FILE, LINE, message);

      // Output information into the unit test error engine.
      if (a_cGenerateError)
        NDepth::NUnitTest::NDetails::unitTestError(FUNCTION_SIGNATURE, FILE, LINE, message);
    }

    if (!NMemory::CMemory::disableGC())
      result = false;
  }

  // Check the result value.
  if (result)
    return true;
  else
  {
    setUnitTestResult(e_TEST_STOPPED);
    return false;
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
