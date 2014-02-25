/*!
 *  \file    CUnitTestLauncherMobile-WindowsMobile.cpp Windows Mobile unit
 *           test launcher class is an implementation of the unit test
 *           launcher for the Windows Mobile environment.
 *  \brief   Windows Mobile unit test launcher class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Windows Mobile unit test launcher class (source).

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
#include <Depth/include/unit.hpp>
/*--------------------------------------------------------------------------*/
#include "CUnitTestLauncherMobile-WindowsMobile.hpp"
/*--------------------------------------------------------------------------*/
#include "../WindowsMobile.hpp"
/*==========================================================================*/
#ifndef __CUNITTESTLAUNCHERCMAKE_WINDOWSMOBILE_CPP__
#define __CUNITTESTLAUNCHERCMAKE_WINDOWSMOBILE_CPP__
/*==========================================================================*/
#if (defined(__WINDOWS__) && defined(__WINDOWS_MOBILE__))
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tsint CUnitTestLauncherMobile::main(const NContainers::CStringBuffer<NString::CString>& a_crArguments, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment)
{ CALL
  // Run base unit test launcher implementation.
  EUnitTestResult result = (EUnitTestResult)CUnitTestLauncher::main(a_crArguments, a_crEnvironment);

  // Lock the output messages under the multi-threaded environment.
  NProcess::CScopeLocker locker(m_OutputLocker);

  // Inform about the unit tests results.
  switch (result)
  {
    case e_TEST_STOPPED:
    {
      MessageBox(NULL, UNC("Test execution was stopped!"), UNC("Depth test result"), MB_OK | MB_ICONSTOP);
      return NApplication::IApplication::EXIT_WITH_SUCCESS;
    }
    case e_TEST_SUCCESS:
    {
      MessageBox(NULL, UNC("Test passed successfully!"), UNC("Depth test result"), MB_OK | MB_ICONINFORMATION);
      return NApplication::IApplication::EXIT_WITH_SUCCESS;
    }
    case e_TEST_WARNING:
    {
      MessageBox(NULL, UNC("Test passed with some warnings!"), UNC("Depth test result"), MB_OK | MB_ICONWARNING);
      return NApplication::IApplication::EXIT_WITH_WARNING;
    }
    case e_TEST_ERROR:
    {
      MessageBox(NULL, UNC("Test failed with some errors!"), UNC("Depth test result"), MB_OK | MB_ICONERROR);
      return NApplication::IApplication::EXIT_WITH_ERROR;
    }
  }
  return NApplication::IApplication::EXIT_WITH_SUCCESS;
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestLauncherMobile::install()
{ CALL
  // Enable checking for memory leaks.
  if (!enableMemoryChecking())
    return false;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestLauncherMobile::uninstall()
{ CALL
  // Disable checking for memory leaks.
  if (!disableMemoryChecking())
    return false;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestLauncherMobile::onWarning(const NString::CString& a_crMessage)
{ CALL
  // Prepare string in system encoding.
  NString::CSystemString message;
  if (!a_crMessage.getSystemString(message, true))
    return false;

  // Lock the error messages under the multi-threaded environment.
  NProcess::CScopeLocker locker(m_ErrorLocker);

  // Write message into the error stream of the unit test.
  MessageBox(NULL, (LPCWSTR)message.getBuffer(), UNC("Depth test warning"), MB_OK | MB_ICONWARNING);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestLauncherMobile::onError(const NString::CString& a_crMessage)
{ CALL
  // Prepare string in system encoding.
  NString::CSystemString message;
  if (!a_crMessage.getSystemString(message, true))
    return false;

  // Lock the error messages under the multi-threaded environment.
  NProcess::CScopeLocker locker(m_ErrorLocker);

  // Write message into the error stream of the unit test.
  MessageBox(NULL, (LPCWSTR)message.getBuffer(), UNC("Depth test error"), MB_OK | MB_ICONERROR);
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
#endif
