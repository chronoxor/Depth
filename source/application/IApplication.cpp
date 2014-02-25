/*!
 *  \file    IApplication.cpp Application interface provides OS independent
 *           functionality to handle application startup.
 *  \brief   Application interface (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Application interface (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Application
    VERSION:   1.0
    CREATED:   10.01.2009 03:53:49

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
#include <Depth/include/application.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/application/IApplication.hpp>
/*==========================================================================*/
#ifndef __IAPPLICATION_CPP__
#define __IAPPLICATION_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NApplication {
/*==========================================================================*/
/* INTERFACE IMPLEMENTATIONS                                                */
/*==========================================================================*/
APPLICATION_API const Tsint IApplication::EXIT_WITH_SUCCESS = 0;
APPLICATION_API const Tsint IApplication::EXIT_WITH_WARNING = 1;
APPLICATION_API const Tsint IApplication::EXIT_WITH_ERROR = -1;
/*--------------------------------------------------------------------------*/
APPLICATION_API Tbool IApplication::ms_IsRunning = false;
APPLICATION_API IApplication* IApplication::ms_pInstance = NULL;
APPLICATION_API NContainers::CStringBuffer<NString::CString> IApplication::ms_Arguments;
APPLICATION_API NContainers::CStringBuffer<NString::CString> IApplication::ms_Environment;
/*--------------------------------------------------------------------------*/
Tsint IApplication::run()
{ CALL
  // Check if the current application is not already running.
  ASSERT(!IApplication::isRunning(), STR("Current application is already running. Cannot run application twice."))
  {
    return IApplication::EXIT_WITH_ERROR;
  }

  // Call application entry point.
  IApplication::ms_IsRunning = true;
  Tsint result = main(IApplication::ms_Arguments, IApplication::ms_Environment);
  IApplication::ms_IsRunning = false;
  return result;
}
/*--------------------------------------------------------------------------*/
Tsint IApplication::run(Tsint argc, Tschar *argv[], Tschar *envp[]/* = NULL */)
{ CALL
  // Check if the current application is not already running.
  ASSERT(!IApplication::isRunning(), STR("Current application is already running. Cannot run application twice."))
  {
    return IApplication::EXIT_WITH_ERROR;
  }

  // Parse new program arguments.
  if (!parse(argc, argv, envp))
    return IApplication::EXIT_WITH_ERROR;
  // Call application entry point.
  IApplication::ms_IsRunning = true;
  Tsint result = main(IApplication::ms_Arguments, IApplication::ms_Environment);
  IApplication::ms_IsRunning = false;
  return result;
}
/*--------------------------------------------------------------------------*/
Tsint IApplication::run(Tsint argc, Twchar *argv[], Twchar *envp[]/* = NULL */)
{ CALL
  // Check if the current application is not already running.
  ASSERT(!IApplication::isRunning(), STR("Current application is already running. Cannot run application twice."))
  {
    return IApplication::EXIT_WITH_ERROR;
  }

  // Parse new program arguments.
  if (!parse(argc, argv, envp))
    return IApplication::EXIT_WITH_ERROR;
  // Call application entry point.
  IApplication::ms_IsRunning = true;
  Tsint result = main(IApplication::ms_Arguments, IApplication::ms_Environment);
  IApplication::ms_IsRunning = false;
  return result;
}
/*--------------------------------------------------------------------------*/
Tsint IApplication::run(const NContainers::CStringBuffer<NString::CString>& a_crArguments, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment)
{ CALL
  // Check if the current application is not already running.
  ASSERT(!IApplication::isRunning(), STR("Current application is already running. Cannot run application twice."))
  {
    return IApplication::EXIT_WITH_ERROR;
  }

  // Set new program arguments.
  if (!IApplication::ms_Arguments.set(a_crArguments) || !IApplication::ms_Environment.set(a_crEnvironment))
    return IApplication::EXIT_WITH_ERROR;
  // Call application entry point.
  IApplication::ms_IsRunning = true;
  Tsint result = main(IApplication::ms_Arguments, IApplication::ms_Environment);
  IApplication::ms_IsRunning = false;
  return result;
}
/*--------------------------------------------------------------------------*/
Tbool IApplication::parse(Tsint argc, Tschar *argv[], Tschar *envp[]/* = NULL */)
{ CALL
  // Setup program arguments string buffer.
  if (!NDetails::CApplicationHelper::parseProgramArguments(IApplication::ms_Arguments, argc, argv))
    return false;

  // Setup environment variables string buffer.
  if (envp != NULL)
  {
    if (!NDetails::CApplicationHelper::parseEnvironmentVariables(IApplication::ms_Environment, envp))
      return false;
  }
  else
  {
    // Clear old environment variables string buffer.
    if (!IApplication::ms_Arguments.clear() || !IApplication::ms_Environment.clear())
      return false;
  }

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool IApplication::parse(Tsint argc, Twchar *argv[], Twchar *envp[]/* = NULL */)
{ CALL
  // Setup program arguments string buffer.
  if (!NDetails::CApplicationHelper::parseProgramArguments(IApplication::ms_Arguments, argc, argv))
    return false;

  // Setup environment variables string buffer.
  if (envp != NULL)
  {
    if (!NDetails::CApplicationHelper::parseEnvironmentVariables(IApplication::ms_Environment, envp))
      return false;
  }
  else
  {
    // Clear old environment variables string buffer.
    if (!IApplication::ms_Arguments.clear() || !IApplication::ms_Environment.clear())
      return false;
  }

  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
