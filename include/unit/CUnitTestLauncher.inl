/*!
 *  \file    CUnitTestLauncher.inl Unit test launcher is a base class for
 *           different launchers. Base implementation of the unit test
 *           launcher simple launches all registered tests in the current
 *           unit test suite.
 *  \brief   Unit test launcher class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test launcher class (inline).

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
#ifndef __CUNITTESTLAUNCHER_INL__
#define __CUNITTESTLAUNCHER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CUnitTestLauncher::~CUnitTestLauncher()
{ CALL
  CUnitTestLauncher::ms_pInstance = NULL;
}
/*--------------------------------------------------------------------------*/
inline const NString::CString& CUnitTestLauncher::getName() const
{ CALL
  return m_Name;
}
/*--------------------------------------------------------------------------*/
inline const NString::CString& CUnitTestLauncher::getFileName() const
{ CALL
  return m_FileName;
}
/*--------------------------------------------------------------------------*/
inline EUnitTestResult CUnitTestLauncher::getUnitTestResult() const
{ CALL
  // Shared lock the current instance of the unit test launcher under the multi-threaded environment.
  NProcess::CScopeReader rlocker((NProcess::CRWLock&)m_Locker);

  return m_UnitTestResult;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::isCreated()
{ CALL
  return (CUnitTestLauncher::ms_pInstance != NULL);
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::isLaunched()
{ CALL
  return CUnitTestLauncher::ms_IsLaunched;
}
/*--------------------------------------------------------------------------*/
inline CUnitTestLauncher& CUnitTestLauncher::getCurrentRef()
{ CALL
  // Verify that the current unit test launcher instance is created.
  VERIFY(CUnitTestLauncher::isCreated(), STR("Taking reference to the unit test launcher instance which is not created leads to the error."));

  return *CUnitTestLauncher::ms_pInstance;
}
/*--------------------------------------------------------------------------*/
inline CUnitTestLauncher* CUnitTestLauncher::getCurrentPtr()
{ CALL
  return CUnitTestLauncher::ms_pInstance;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::install()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::uninstall()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::isMemoryCheckingEnabled()
{ CALL
  // Shared lock the current instance of the unit test launcher under the multi-threaded environment.
  NProcess::CScopeReader rlocker(m_Locker);

  return m_IsMemoryCheckingEnabled;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onLog(const NString::CString& a_crMessage)
{ CALL
  IGNORE_UNUSED(a_crMessage);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onWarning(const NString::CString& a_crMessage)
{ CALL
  IGNORE_UNUSED(a_crMessage);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onError(const NString::CString& a_crMessage)
{ CALL
  IGNORE_UNUSED(a_crMessage);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onBeforeLauncherInstall(const CUnitTestLauncher& a_crUnitTestLauncher)
{ CALL
  IGNORE_UNUSED(a_crUnitTestLauncher);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onAfterLauncherInstall(const CUnitTestLauncher& a_crUnitTestLauncher)
{ CALL
  IGNORE_UNUSED(a_crUnitTestLauncher);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onBeforeLauncherUninstall(const CUnitTestLauncher& a_crUnitTestLauncher)
{ CALL
  IGNORE_UNUSED(a_crUnitTestLauncher);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onAfterLauncherUninstall(const CUnitTestLauncher& a_crUnitTestLauncher)
{ CALL
  IGNORE_UNUSED(a_crUnitTestLauncher);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onBeforeLauncherLaunch(const CUnitTestLauncher& a_crUnitTestLauncher)
{ CALL
  IGNORE_UNUSED(a_crUnitTestLauncher);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onAfterLauncherLaunch(const CUnitTestLauncher& a_crUnitTestLauncher)
{ CALL
  IGNORE_UNUSED(a_crUnitTestLauncher);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onBeforeSuiteInstall(const CUnitTestSuite& a_crUnitTestSuite)
{ CALL
  IGNORE_UNUSED(a_crUnitTestSuite);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onAfterSuiteInstall(const CUnitTestSuite& a_crUnitTestSuite)
{ CALL
  IGNORE_UNUSED(a_crUnitTestSuite);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onBeforeSuiteUninstall(const CUnitTestSuite& a_crUnitTestSuite)
{ CALL
  IGNORE_UNUSED(a_crUnitTestSuite);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onAfterSuiteUninstall(const CUnitTestSuite& a_crUnitTestSuite)
{ CALL
  IGNORE_UNUSED(a_crUnitTestSuite);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onBeforeSuiteLaunch(const CUnitTestSuite& a_crUnitTestSuite)
{ CALL
  IGNORE_UNUSED(a_crUnitTestSuite);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onAfterSuiteLaunch(const CUnitTestSuite& a_crUnitTestSuite)
{ CALL
  IGNORE_UNUSED(a_crUnitTestSuite);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onBeforeTestInstall(const CUnitTest& a_crUnitTest)
{ CALL
  IGNORE_UNUSED(a_crUnitTest);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onAfterTestInstall(const CUnitTest& a_crUnitTest)
{ CALL
  IGNORE_UNUSED(a_crUnitTest);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onBeforeTestUninstall(const CUnitTest& a_crUnitTest)
{ CALL
  IGNORE_UNUSED(a_crUnitTest);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onAfterTestUninstall(const CUnitTest& a_crUnitTest)
{ CALL
  IGNORE_UNUSED(a_crUnitTest);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onBeforeTestLaunch(const CUnitTest& a_crUnitTest)
{ CALL
  IGNORE_UNUSED(a_crUnitTest);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestLauncher::onAfterTestLaunch(const CUnitTest& a_crUnitTest)
{ CALL
  IGNORE_UNUSED(a_crUnitTest);

  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool load(T_Archive& a_rArchive, NUnitTest::EUnitTestResult& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUnitTest::EUnitTestResult")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set unit test result value.
  switch (value)
  {
    case 0:
      a_rInstance = NUnitTest::e_TEST_STOPPED;
      break;
    case 1:
      a_rInstance = NUnitTest::e_TEST_SUCCESS;
      break;
    case 2:
      a_rInstance = NUnitTest::e_TEST_WARNING;
      break;
    case 3:
      a_rInstance = NUnitTest::e_TEST_ERROR;
      break;
    default:
      WARNING(STR("Cannot load invalid unit test result value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool save(T_Archive& a_rArchive, const NUnitTest::EUnitTestResult& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get unit test result value.
  switch (a_crInstance)
  {
    case NUnitTest::e_TEST_STOPPED:
      value = 0;
      break;
    case NUnitTest::e_TEST_SUCCESS:
      value = 1;
      break;
    case NUnitTest::e_TEST_WARNING:
      value = 2;
      break;
    case NUnitTest::e_TEST_ERROR:
      value = 3;
      break;
    default:
      WARNING(STR("Cannot save invalid unit test result value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUnitTest::EUnitTestResult")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool serialize(T_Archive& a_rArchive, NUnitTest::EUnitTestResult& a_rInstance)
{ CALL
  // Split 'serialize()' free function into 'load()' and 'save()' ones.
  return serializeSplitFunction(a_rArchive, a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
