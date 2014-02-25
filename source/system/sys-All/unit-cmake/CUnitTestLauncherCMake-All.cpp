/*!
 *  \file    CUnitTestLauncherCMake-All.cpp CMake unit test launcher class is
 *           an implementation of the unit test launcher for the CMake/CTest
 *           environment.
 *  \brief   CMake unit test launcher class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: CMake unit test launcher class (source).

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
#include <Depth/include/unit.hpp>
/*--------------------------------------------------------------------------*/
#include "CUnitTestLauncherCMake-All.hpp"
/*==========================================================================*/
#ifndef __CUNITTESTLAUNCHERCMAKE_CPP__
#define __CUNITTESTLAUNCHERCMAKE_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tsint CUnitTestLauncherCMake::main(const NContainers::CStringBuffer<NString::CString>& a_crArguments, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment)
{ CALL
  // Run base unit test launcher implementation.
  EUnitTestResult result = (EUnitTestResult)CUnitTestLauncher::main(a_crArguments, a_crEnvironment);

  // Lock the standard output stream under the multi-threaded environment.
  NProcess::CScopeLocker locker(m_OutputStreamLocker);

  // Inform about the unit tests results.
  switch (result)
  {
    case e_TEST_STOPPED:
    {
      m_OutputStream.write(ASC("!!! - Test execution was stopped!"));
      return NApplication::IApplication::EXIT_WITH_SUCCESS;
    }
    case e_TEST_SUCCESS:
    {
      m_OutputStream.write(ASC("+++ - Test passed successfully!"));
      return NApplication::IApplication::EXIT_WITH_SUCCESS;
    }
    case e_TEST_WARNING:
    {
      m_OutputStream.write(ASC("??? - Test passed with some warnings!"));
      return NApplication::IApplication::EXIT_WITH_WARNING;
    }
    case e_TEST_ERROR:
    {
      m_OutputStream.write(ASC("--- - Test failed with some errors!"));
      return NApplication::IApplication::EXIT_WITH_ERROR;
    }
  }
  return NApplication::IApplication::EXIT_WITH_SUCCESS;
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestLauncherCMake::install()
{ CALL
  // Enable checking for memory leaks.
  if (!enableMemoryChecking())
    return false;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestLauncherCMake::uninstall()
{ CALL
  // Disable checking for memory leaks.
  if (!disableMemoryChecking())
    return false;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestLauncherCMake::onWarning(const NString::CString& a_crMessage)
{ CALL
  // Lock the standard error stream under the multi-threaded environment.
  NProcess::CScopeLocker locker(m_ErrorStreamLocker);

  // Write message into the error stream of the unit test.
  return (m_ErrorStream.write(a_crMessage).getFirst() && m_ErrorStream.write(STR("------------------------------------------------------------------------------")).getFirst() && m_ErrorStream.writeLineEnd().getFirst());
}
/*--------------------------------------------------------------------------*/
Tbool CUnitTestLauncherCMake::onError(const NString::CString& a_crMessage)
{ CALL
  // Lock the standard error stream under the multi-threaded environment.
  NProcess::CScopeLocker locker(m_ErrorStreamLocker);

  // Write message into the error stream of the unit test.
  return (m_ErrorStream.write(a_crMessage).getFirst() && m_ErrorStream.write(STR("------------------------------------------------------------------------------")).getFirst() && m_ErrorStream.writeLineEnd().getFirst());
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
