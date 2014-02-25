/*!
 *  \file    CUnitTestLauncher.hpp Unit test launcher is a base class for
 *           different launchers. Base implementation of the unit test
 *           launcher simple launches all registered tests in the current
 *           unit test suite.
 *  \brief   Unit test launcher class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test launcher class.

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
#ifndef __CUNITTESTLAUNCHER_HPP__
#define __CUNITTESTLAUNCHER_HPP__
/*==========================================================================*/
#include <Depth/include/unit.hpp>
#include <Depth/include/serialization.hpp>
#include <Depth/include/application/IApplication.hpp>
#include <Depth/include/process/CRWLock.hpp>
#include <Depth/include/process/CScopeReader.hpp>
#include <Depth/include/process/CScopeWriter.hpp>
#include <Depth/include/string/CString.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
class CUnitTest;
class CUnitTestSuite;
/*==========================================================================*/
/* ENUMERATIONS DECLARATIONS                                                */
/*==========================================================================*/
enum EUnitTestResult                    //! Unit test result values.
{
  e_TEST_STOPPED,                       //!< Unit test execution was stopped.
  e_TEST_SUCCESS,                       //!< Unit test passed successfully.
  e_TEST_WARNING,                       //!< Unit test passed with some warnings.
  e_TEST_ERROR                          //!< Unit test passed with some errors.
};
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Unit test launcher class.
/*!
    Unit  test  launcher  class  manages  unit  test  running  process.   Base
    implementation of the unit test launcher simple  launches  all  registered
    tests in the current unit test suite.

    Inherited classes can override 'install()'/'uninstall()' methods in  order
    to  change  initialization/deinitialization  functionality.  It  is   also
    possible to override 'test()' method in order  to  change  test  execution
    process.

    During the test execution different  notifications  could  be  handled  in
    order to inform about test execution process.
*/
class UNITTEST_API CUnitTestLauncher :
  public NApplication::IApplication
{
  // Friend class: Unit test class (CUnitTest).
  friend class CUnitTest;
  // Friend class: Unit test suite class (CUnitTestSuite).
  friend class CUnitTestSuite;
  // Friend function: Unit test is need stop helper function.
  friend Tbool NDetails::unitTestIsNeedStop();
  // Friend function: Unit test logging helper function (ASCII version).
  friend void NDetails::unitTestLog(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcsstr a_cpMessage, ...);
  // Friend function: Unit test logging helper function (Unicode version).
  friend void NDetails::unitTestLog(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcwstr a_cpMessage, ...);
  // Friend function: Unit test logging helper function. Fixed string version. (ASCII version).
  friend void NDetails::unitTestLogFixed(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcsstr a_cpMessage);
  // Friend function: Unit test logging helper function. Fixed string version. (Unicode version).
  friend void NDetails::unitTestLogFixed(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcwstr a_cpMessage);
  // Friend function: Unit test error helper function (ASCII version).
  friend void NDetails::unitTestError(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcsstr a_cpMessage, ...);
  // Friend function: Unit test error helper function (Unicode version).
  friend void NDetails::unitTestError(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcwstr a_cpMessage, ...);
  // Friend function: Unit test error helper function. Fixed string version. (ASCII version).
  friend void NDetails::unitTestErrorFixed(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcsstr a_cpMessage);
  // Friend function: Unit test error helper function. Fixed string version. (Unicode version).
  friend void NDetails::unitTestErrorFixed(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcwstr a_cpMessage);
  // Friend function: Unit test warning helper function (ASCII version).
  friend void NDetails::unitTestWarning(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcsstr a_cpMessage, ...);
  // Friend function: Unit test warning helper function (Unicode version).
  friend void NDetails::unitTestWarning(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcwstr a_cpMessage, ...);
  // Friend function: Unit test warning helper function. Fixed string version. (ASCII version).
  friend void NDetails::unitTestWarningFixed(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcsstr a_cpMessage);
  // Friend function: Unit test warning helper function. Fixed string version. (Unicode version).
  friend void NDetails::unitTestWarningFixed(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcwstr a_cpMessage);

public:
  //! Default class constructor. Initialize unit test launcher with a corresponding name and file name.
  /*!
      \param a_crName - Unit test launcher name (default is NDepth::NUnitTest::CUnitTestSuite).
      \param a_crFileName - Unit test launcher file name (default is FILE).
  */
  CUnitTestLauncher(const NString::CString& a_crName = STR("NDepth::NUnitTest::CUnitTestLauncher"), const NString::CString& a_crFileName = FILE);
  //! Class destructor.
 ~CUnitTestLauncher();

  //! Get name of the current unit test launcher.
  /*!
      \return Constant reference to the name of the current unit test launcher.
  */
  const NString::CString& getName() const;
  //! Get file name of the current unit test launcher.
  /*!
      \return Constant reference to the file name of the current unit test launcher.
  */
  const NString::CString& getFileName() const;
  //! Get current result of the unit test launcher.
  /*!
      \return Current result of the unit test launcher.
  */
  EUnitTestResult getUnitTestResult() const;

  //! Is instance of the unit test launcher created?
  /*!
      \return true  - if the unit test launcher instance was created. \n
              false - if the unit test launcher instance was not created. \n
  */
  static Tbool isCreated();
  //! Is unit test launcher launched?
  /*!
      \return true  - if the unit test launcher instance is launched. \n
              false - if the unit test launcher instance is not launched. \n
  */
  static Tbool isLaunched();

  //! Get reference to the current unit test launcher instance.
  /*!
      Method returns reference to the current  unit  test  launcher  instance.
      Note that result may  be  broken  if  the  current  unit  test  launcher
      instance is not created. So use 'isCreated()' method before to check its
      valid state.

      \return Reference to the current unit test launcher instance.
  */
  static CUnitTestLauncher& getCurrentRef();
  //! Get pointer to the current unit test launcher instance.
  /*!
      Method returns pointer to the current unit test launcher instance.  Note
      that result may be NULL if the current unit test  launcher  instance  is
      not created. So use 'isCreated()' method before to check its valid state
      or use NULL checking strategy to define unit test launcher  instance  is
      not created state alternatively.

      \return Pointer to the current unit test launcher instance.
  */
  static CUnitTestLauncher* getCurrentPtr();

protected:
  //! Install unit test launcher.
  /*!
      Default implementation of the method does nothing. But you can  override
      it in  order  to  perform  specific  initialization  of  the  unit  test
      launcher.

      \return true  - if unit test launcher was successfully installed. \n
              false - if unit test launcher was not successfully installed. \n
  */
  virtual Tbool install();
  //! Uninstall unit test launcher.
  /*!
      Default implementation of the method does nothing. But you can  override
      it in order to  perform  specific  deinitialization  of  the  unit  test
      launcher.

      \return true  - if unit test launcher was successfully uninstalled. \n
              false - if unit test launcher was not successfully uninstalled. \n
  */
  virtual Tbool uninstall();
  //! Launch all registered unit tests in the current test suite.
  /*!
      Default implementation of the method  simple  launches  registered  unit
      tests in the current test suite. But you can override  it  in  order  to
      perform specific launching of the unit tests.

      \return Composite unit tests result.
  */
  virtual EUnitTestResult test();

  //! Entry point of the unit test launcher.
  /*!
      \param a_crArguments - Constant reference to the string buffer with program arguments.
      \param a_crEnvironment - Constant reference to the string buffer with environment variables.
      \return Result of the execution which is provided to the system.
  */
  virtual Tsint main(const NContainers::CStringBuffer<NString::CString>& a_crArguments, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment);

  /*------------------------------------------------------------------------*/
  /* FEATURES METHODS                                                       */
  /*------------------------------------------------------------------------*/
  //! Is memory checking is enabled.
  /*!
      \return true  - if memory leaks detection is enabled. \n
              false - if memory leaks detection is not enabled. \n
  */
  Tbool isMemoryCheckingEnabled();
  //! Enable checking for memory leaks.
  /*!
      This method enables  memory  GC  engine  and  stores  current  count  of
      allocated memory blocks and their sizes. During  the  memory  management
      operations GC engine tracks memory blocks.  Therefore  when  the  method
      'disableMemoryChecking()' is invoked  it  will  compare  current  memory
      blocks and their sizes with the previous ones and inform the  unit  test
      launcher if memory leaks were detected.

      \return true  - if memory leaks detection was successfully enabled. \n
              false - if memory leaks detection was not successfully enabled. \n
  */
  Tbool enableMemoryChecking();
  //! Disable checking for memory leaks.
  /*!
      This method disables memory GC  engine  and  compare  current  count  of
      allocated memory blocks and their  sizes  with  the  previous  ones.  If
      required it informs the unit test launcher about detected memory leaks.

      \param a_cGenerateError - Generate error flag (default is true).
      \return true  - if memory leaks detection was successfully disable. \n
              false - if memory leaks detection was not successfully disable. \n
  */
  Tbool disableMemoryChecking(const Tbool a_cGenerateError = true);

  /*------------------------------------------------------------------------*/
  /* NOTIFICATION METHODS                                                   */
  /*------------------------------------------------------------------------*/
  //! Logging message notification.
  /*!
      Notification is received when unit test  inserts  message  in  the  log.
      Default implementation of the method just ignores the message.

      Logging message has the following format:
        Log:\n
        Function\n
        FileName line X\n\n
        Message\n\n

      \param a_crMessage - Constant reference to the message string.
      \return true  - if the message was successfully inserted into the log. \n
              false - if the message was not successfully inserted into the log. \n
  */
  virtual Tbool onLog(const NString::CString& a_crMessage);
  //! Warning message notification.
  /*!
      Notification is received when unit test writes warning message.  Default
      implementation of the method just ignores the message.

      Warning message has the following format:
        Warning:\n
        Function\n
        FileName line X\n\n
        Message\n\n

      \param a_crMessage - Constant reference to the message string.
      \return true  - if the message was successfully written. \n
              false - if the message was not successfully written. \n
  */
  virtual Tbool onWarning(const NString::CString& a_crMessage);
  //! Error message notification.
  /*!
      Notification is received when unit test writes  error  message.  Default
      implementation of the method just ignores the message.

      Error message has the following format:
        Error:\n
        Function\n
        FileName line X\n\n
        Message\n\n

      \param a_crMessage - Constant reference to the message string.
      \return true  - if the message was successfully written. \n
              false - if the message was not successfully written. \n
  */
  virtual Tbool onError(const NString::CString& a_crMessage);

  //! Before unit test launcher install notification.
  /*!
      Notification is received when unit test launcher  is  near  to  install.
      Default implementation of the method does nothing, but the method  could
      be overridden to perform  additional  actions  or  to  cancel  the  test
      execution.

      \param a_crUnitTestLauncher - Constant reference to the current unit test launcher.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onBeforeLauncherInstall(const CUnitTestLauncher& a_crUnitTestLauncher);
  //! After unit test launcher install notification.
  /*!
      Notification is received when unit test launcher  successfully  finished
      installation process. Default implementation of the method does nothing,
      but the method could be overridden to perform  additional  post  install
      actions or to cancel the test execution.

      \param a_crUnitTestLauncher - Constant reference to the current unit test launcher.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onAfterLauncherInstall(const CUnitTestLauncher& a_crUnitTestLauncher);
  //! Before unit test launcher uninstall notification.
  /*!
      Notification is received when unit test launcher is near  to  uninstall.
      Default implementation of the method does nothing, but the method  could
      be overridden to perform  additional  actions  or  to  cancel  the  test
      execution.

      \param a_crUnitTestLauncher - Constant reference to the current unit test launcher.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onBeforeLauncherUninstall(const CUnitTestLauncher& a_crUnitTestLauncher);
  //! After unit test launcher uninstall notification.
  /*!
      Notification is received when unit test launcher  successfully  finished
      uninstallation  process.  Default  implementation  of  the  method  does
      nothing, but the method could be overridden to perform  additional  post
      install actions or to cancel the test execution.

      \param a_crUnitTestLauncher - Constant reference to the current unit test launcher.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onAfterLauncherUninstall(const CUnitTestLauncher& a_crUnitTestLauncher);
  //! Before unit test launcher launch notification.
  /*!
      Notification is received when unit test  launcher  is  near  to  launch.
      Default implementation of the method does nothing, but the method  could
      be overridden to perform  additional  actions  or  to  cancel  the  test
      execution.

      \param a_crUnitTestLauncher - Constant reference to the current unit test launcher.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onBeforeLauncherLaunch(const CUnitTestLauncher& a_crUnitTestLauncher);
  //! After unit test launcher launch notification.
  /*!
      Notification is received when unit test launcher  successfully  finished
      launch process. Default implementation of the method does  nothing,  but
      the method could  be  overridden  to  perform  additional  post  install
      actions or to cancel the test execution.

      \param a_crUnitTestLauncher - Constant reference to the current unit test launcher.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onAfterLauncherLaunch(const CUnitTestLauncher& a_crUnitTestLauncher);

  //! Before unit test suite install notification.
  /*!
      Notification is received when  unit  test  suite  is  near  to  install.
      Default implementation of the method does nothing, but the method  could
      be overridden to perform  additional  actions  or  to  cancel  the  test
      execution.

      \param a_crUnitTestSuite - Constant reference to the current unit test suite.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onBeforeSuiteInstall(const CUnitTestSuite& a_crUnitTestSuite);
  //! After unit test suite install notification.
  /*!
      Notification is received when  unit  test  suite  successfully  finished
      installation process. Default implementation of the method does nothing,
      but the method could be overridden to perform  additional  post  install
      actions or to cancel the test execution.

      \param a_crUnitTestSuite - Constant reference to the current unit test suite.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onAfterSuiteInstall(const CUnitTestSuite& a_crUnitTestSuite);
  //! Before unit test suite uninstall notification.
  /*!
      Notification is received when unit test  suite  is  near  to  uninstall.
      Default implementation of the method does nothing, but the method  could
      be overridden to perform  additional  actions  or  to  cancel  the  test
      execution.

      \param a_crUnitTestSuite - Constant reference to the current unit test suite.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onBeforeSuiteUninstall(const CUnitTestSuite& a_crUnitTestSuite);
  //! After unit test suite uninstall notification.
  /*!
      Notification is received when  unit  test  suite  successfully  finished
      uninstallation  process.  Default  implementation  of  the  method  does
      nothing, but the method could be overridden to perform  additional  post
      install actions or to cancel the test execution.

      \param a_crUnitTestSuite - Constant reference to the current unit test suite.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onAfterSuiteUninstall(const CUnitTestSuite& a_crUnitTestSuite);
  //! Before unit test suite launch notification.
  /*!
      Notification is received when unit test suite is near to launch. Default
      implementation of the method does  nothing,  but  the  method  could  be
      overridden  to  perform  additional  actions  or  to  cancel  the   test
      execution.

      \param a_crUnitTestSuite - Constant reference to the current unit test suite.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onBeforeSuiteLaunch(const CUnitTestSuite& a_crUnitTestSuite);
  //! After unit test suite launch notification.
  /*!
      Notification is received when  unit  test  suite  successfully  finished
      launch process. Default implementation of the method does  nothing,  but
      the method could  be  overridden  to  perform  additional  post  install
      actions or to cancel the test execution.

      \param a_crUnitTestSuite - Constant reference to the current unit test suite.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onAfterSuiteLaunch(const CUnitTestSuite& a_crUnitTestSuite);

  //! Before unit test install notification.
  /*!
      Notification is received when unit test  is  near  to  install.  Default
      implementation of the method does  nothing,  but  the  method  could  be
      overridden  to  perform  additional  actions  or  to  cancel  the   test
      execution.

      \param a_crUnitTest - Constant reference to the current unit test.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onBeforeTestInstall(const CUnitTest& a_crUnitTest);
  //! After unit test install notification.
  /*!
      Notification  is  received  when   unit   test   successfully   finished
      installation process. Default implementation of the method does nothing,
      but the method could be overridden to perform  additional  post  install
      actions or to cancel the test execution.

      \param a_crUnitTest - Constant reference to the current unit test.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onAfterTestInstall(const CUnitTest& a_crUnitTest);
  //! Before unit test uninstall notification.
  /*!
      Notification is received when unit test is near  to  uninstall.  Default
      implementation of the method does  nothing,  but  the  method  could  be
      overridden  to  perform  additional  actions  or  to  cancel  the   test
      execution.

      \param a_crUnitTest - Constant reference to the current unit test.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onBeforeTestUninstall(const CUnitTest& a_crUnitTest);
  //! After unit test uninstall notification.
  /*!
      Notification  is  received  when   unit   test   successfully   finished
      uninstallation  process.  Default  implementation  of  the  method  does
      nothing, but the method could be overridden to perform  additional  post
      install actions or to cancel the test execution.

      \param a_crUnitTest - Constant reference to the current unit test.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onAfterTestUninstall(const CUnitTest& a_crUnitTest);
  //! Before unit test launch notification.
  /*!
      Notification is received when unit  test  is  near  to  launch.  Default
      implementation of the method does  nothing,  but  the  method  could  be
      overridden  to  perform  additional  actions  or  to  cancel  the   test
      execution.

      \param a_crUnitTest - Constant reference to the current unit test.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onBeforeTestLaunch(const CUnitTest& a_crUnitTest);
  //! After unit test launch notification.
  /*!
      Notification is received when unit  test  successfully  finished  launch
      process. Default implementation of the  method  does  nothing,  but  the
      method could be overridden to perform additional post install actions or
      to cancel the test execution.

      \param a_crUnitTest - Constant reference to the current unit test.
      \return true  - if the unit test process should be continued. \n
              false - if the unit test process should be stopped. \n
  */
  virtual Tbool onAfterTestLaunch(const CUnitTest& a_crUnitTest);

private:
  NString::CString m_Name;                //!< Unit test launcher name.
  NString::CString m_FileName;            //!< Unit test launcher file name.
  EUnitTestResult m_UnitTestResult;       //!< Unit test launcher result.

  // Synchronization object.
  NProcess::CRWLock m_Locker;             //!< Unit test launcher reader/writer locker.

  // Memory checking.
  Tbool m_IsMemoryCheckingEnabled;        //!< Is memory checking is enabled.
  Tuint m_OldAllocBlocks;                 //!< Previous count of allocated memory blocks.
  Tuint m_OldAllocSize;                   //!< Previous count of allocated memory size.

  static Tbool ms_IsLaunched;             //!< Is unit test launcher launched?
  static Tbool ms_IsInstanceCreated;      //!< Is unit test launcher instance created?
  static CUnitTestLauncher* ms_pInstance; //!< Pointer to the current instance of the unit test launcher.

  //! Initialize default unit test launcher instance.
  /*!
      \param a_cUnitTestFlag - Unit test dummy flag.
  */
  CUnitTestLauncher(const Tbool a_cUnitTestFlag);

  //! Set current result of the unit test launcher.
  /*!
      This method is invoked from the internals of the unit test  library  and
      forces to set new current result of the unit test. It cannot be  invoked
      manually.

      \param a_cUnitTestResult - New current result of the unit test.
      \param a_cForceSet - Foce set flag (default is false).
  */
  void setUnitTestResult(const EUnitTestResult a_cUnitTestResult, const Tbool a_cForceSet = false);

  //! Create default instance of the CUnitTestLauncher.
  /*!
      \return true  - if instance of the CUnitTestLauncher was successfully created. \n
              false - if instance of the CUnitTestLauncher was not successfully created. \n
  */
  static Tbool CreateDefaultInstance();
  //! Destroy default instance of the CUnitTestLauncher.
  /*!
      \return true  - if instance of the CUnitTestLauncher was successfully destroyed. \n
              false - if instance of the CUnitTestLauncher was not successfully destroyed. \n
  */
  static Tbool DestroyDefaultInstance();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* SERIALIZATION FUNCTION DECLARATIONS                                      */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
//! Serialization load unit test result enumeration.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized unit test result enumeration instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NUnitTest::EUnitTestResult& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save unit test result enumeration.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized unit test result enumeration instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NUnitTest::EUnitTestResult& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize unit test result enumeration.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized unit test result enumeration instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NUnitTest::EUnitTestResult& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/unit/CUnitTest.hpp>
#include <Depth/include/unit/CUnitTestSuite.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/unit/CUnitTestLauncher.inl>
/*==========================================================================*/
//! \example example-unit-CUnitTestLauncher.cpp
/*--------------------------------------------------------------------------*/
//! \test test-unit-CUnitTestLauncher.cpp
/*==========================================================================*/
#endif
