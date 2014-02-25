/*!
 *  \file    CUnitTestLauncherMobile-WindowsMobile.hpp Windows Mobile unit
 *           test launcher class is an implementation of the unit test
 *           launcher for the Windows Mobile environment.
 *  \brief   Windows Mobile unit test launcher class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Windows Mobile unit test launcher class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   09.03.2009 02:13:41

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
#ifndef __CUNITTESTLAUNCHERMOBILE_WINDOWSMOBILE_HPP__
#define __CUNITTESTLAUNCHERMOBILE_WINDOWSMOBILE_HPP__
/*==========================================================================*/
#include <Depth/include/process/CCriticalSection.hpp>
#include <Depth/include/process/CScopeLocker.hpp>
#include <Depth/include/unit/CUnitTestLauncher.hpp>
/*==========================================================================*/
#if (defined(__WINDOWS__) && defined(__WINDOWS_MOBILE__))
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Windows Mobile unit test launcher class.
/*!
    Windows Mobile unit test launcher class is an implementation of  the  unit
    test launcher adapted for the Windows Mobile environment.

    Windows Mobile unit test launcher does not writes logs. All  warnings  and
    errors are shown using message boxes.
*/
class CUnitTestLauncherMobile :
  public CUnitTestLauncher
{
public:
  //! Initialize unit test suite with a corresponding name and file name.
  /*!
      \param a_crName - Unit test launcher name.
      \param a_crFileName - Unit test launcher file name.
  */
  CUnitTestLauncherMobile(const NString::CString& a_crName, const NString::CString& a_crFileName);

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
  NProcess::CCriticalSection m_ErrorLocker;  //!< Critical section locker for error messages.
  NProcess::CCriticalSection m_OutputLocker; //!< Critical section locker for output messages.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include "CUnitTestLauncherMobile-WindowsMobile.inl"
/*==========================================================================*/
#endif
#endif
