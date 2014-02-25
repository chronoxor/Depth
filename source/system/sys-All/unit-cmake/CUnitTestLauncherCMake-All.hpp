/*!
 *  \file    CUnitTestLauncherCMake-All.hpp CMake unit test launcher class is
 *           an implementation of the unit test launcher for the CMake/CTest
 *           environment.
 *  \brief   CMake unit test launcher class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: CMake unit test launcher class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   16.01.2009 03:33:31

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
#ifndef __CUNITTESTLAUNCHERCMAKE_HPP__
#define __CUNITTESTLAUNCHERCMAKE_HPP__
/*==========================================================================*/
#include <Depth/include/process/CCriticalSection.hpp>
#include <Depth/include/process/CScopeLocker.hpp>
#include <Depth/include/stream/CStreamStdError.hpp>
#include <Depth/include/stream/CStreamStdOutput.hpp>
#include <Depth/include/unit/CUnitTestLauncher.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! CMake unit test launcher class.
/*!
    CMake unit test launcher class is  an  implementation  of  the  unit  test
    launcher adapted for the CMake/CTest environment.

    CMake unit test launcher does not writes logs. All warnings and errors are
    shown using standard error stream of the current process. After unit  test
    is launched it writes the following  messages  into  the  standard  output
    stream of the current process:

    \li !!! - Test execution was stopped!
    \li +++ - Test passed successfully!
    \li ??? - Test passed with some warnings!
    \li --- - Test failed with some errors!
*/
class CUnitTestLauncherCMake :
  public CUnitTestLauncher
{
public:
  //! Initialize unit test suite with a corresponding name and file name.
  /*!
      \param a_crName - Unit test launcher name.
      \param a_crFileName - Unit test launcher file name.
  */
  CUnitTestLauncherCMake(const NString::CString& a_crName, const NString::CString& a_crFileName);

protected:
  //! Install unit test launcher.
  /*!
      Method enables the following unit test launched features:
      \li Memory leaks detection.

      \return true  - if unit test launcher was successfully installed. \n
              false - if unit test launcher was not successfully installed. \n
  */
  virtual Tbool install();
  //! Uninstall unit test launcher.
  /*!
      Method disables the following unit test launched features:
      \li Memory leaks detection.

      \return true  - if unit test launcher was successfully uninstalled. \n
              false - if unit test launcher was not successfully uninstalled. \n
  */
  virtual Tbool uninstall();
  //! Entry point of the unit test launcher.
  /*!
      \param a_crArguments - Constant reference to the string buffer with program arguments.
      \param a_crEnvironment - Constant reference to the string buffer with environment variables.
      \return Result of the execution which is provided to the system.
  */
  virtual Tsint main(const NContainers::CStringBuffer<NString::CString>& a_crArguments, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment);

  /*------------------------------------------------------------------------*/
  /* NOTIFICATION METHODS                                                   */
  /*------------------------------------------------------------------------*/
  //! Warning message notification.
  /*!
      Notification is received when unit test writes warning message.  Default
      implementation of the method writes warning message  into  the  standard
      error stream of the process.

      \param a_crMessage - Constant reference to the message string.
      \return true  - if the message was successfully written. \n
              false - if the message was not successfully written. \n
  */
  virtual Tbool onWarning(const NString::CString& a_crMessage);
  //! Error message notification.
  /*!
      Notification is received when unit test writes  error  message.  Default
      implementation of the method writes  error  message  into  the  standard
      error stream of the process.

      \param a_crMessage - Constant reference to the message string.
      \return true  - if the message was successfully written. \n
              false - if the message was not successfully written. \n
  */
  virtual Tbool onError(const NString::CString& a_crMessage);

private:
  NStream::CStreamStdError   m_ErrorStream;        //!< Use standard error stream as a unit test error stream.
  NProcess::CCriticalSection m_ErrorStreamLocker;  //!< Critical section locker for the standard error stream.

  NStream::CStreamStdOutput  m_OutputStream;       //!< Use standard output stream as a unit test output stream.
  NProcess::CCriticalSection m_OutputStreamLocker; //!< Critical section locker for the standard output stream.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include "CUnitTestLauncherCMake-All.inl"
/*==========================================================================*/
#endif
