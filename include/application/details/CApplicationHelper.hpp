/*!
 *  \file    CApplicationHelper.hpp Application helper class contains utility
 *           functionality to work with program arguments.
 *  \brief   Application helper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Application helper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Application details
    VERSION:   1.0
    CREATED:   10.01.2009 23:07:22

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
#ifndef __CAPPLICATIONHELPER_HPP__
#define __CAPPLICATIONHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/application.hpp>
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/containers/CStringBuffer.hpp>
#include <Depth/include/string/CString.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NApplication {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Application helper class.
/*!
    Application helper class contains utility methods  for  program  arguments
    converting.
*/
class APPLICATION_API CApplicationHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Compose program arguments string from ANSI C/C++ program arguments in ASCII encoding.
  /*!
      \param a_rArgumentsString - Reference to the program arguments string.
      \param argc - Count of program arguments.
      \param argv - String buffer of program arguments.
      \return true  - if the program arguments string was successfully composed. \n
              false - if the program arguments string was not successfully composed. \n
  */
  static Tbool composeProgramArguments(NString::CString& a_rArgumentsString, Tsint argc, Tschar *argv[]);
  //! Compose program arguments string from ANSI C/C++ program arguments in Unicode encoding.
  /*!
      \param a_rArgumentsString - Reference to the program arguments string.
      \param argc - Count of program arguments.
      \param argv - String buffer of program arguments.
      \return true  - if the program arguments string was successfully composed. \n
              false - if the program arguments string was not successfully composed. \n
  */
  static Tbool composeProgramArguments(NString::CString& a_rArgumentsString, Tsint argc, Twchar *argv[]);
  //! Compose program arguments string from the program arguments string buffer.
  /*!
      \param a_rArgumentsString - Reference to the program arguments string.
      \param a_crArguments - Constant reference to the string buffer with program arguments.
      \return true  - if the program arguments string was successfully composed. \n
              false - if the program arguments string was not successfully composed. \n
  */
  static Tbool composeProgramArguments(NString::CString& a_rArgumentsString, const NContainers::CStringBuffer<NString::CString>& a_crArguments);

  //! Compose environment arguments string from ANSI C/C++ environment variables in ASCII encoding.
  /*!
      \param a_rEnvironmentString - Reference to the environment variables string.
      \param envp - String buffer of environment variables.
      \return true  - if the environment variables string was successfully composed. \n
              false - if the environment variables string was not successfully composed. \n
  */
  static Tbool composeEnvironmentVariables(NString::CString& a_rEnvironmentString, Tschar *envp[]);
  //! Compose environment arguments string from ANSI C/C++ environment variables in Unicode encoding.
  /*!
      \param a_rEnvironmentString - Reference to the environment variables string.
      \param envp - String buffer of environment variables.
      \return true  - if the environment variables string was successfully composed. \n
              false - if the environment variables string was not successfully composed. \n
  */
  static Tbool composeEnvironmentVariables(NString::CString& a_rEnvironmentString, Twchar *envp[]);
  //! Compose environment variables string from the environment variables string buffer.
  /*!
      \param a_rEnvironmentString - Reference to the environment variables string.
      \param a_crEnvironment - Constant reference to the string buffer with environment variables.
      \return true  - if the environment variables string was successfully composed. \n
              false - if the environment variables string was not successfully composed. \n
  */
  static Tbool composeEnvironmentVariables(NString::CString& a_rEnvironmentString, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment);

  //! Parse ANSI C/C++ program arguments in ASCII encoding and fill the given string buffer.
  /*!
      \param a_rArguments - Reference to the string buffer with program arguments.
      \param argc - Count of program arguments.
      \param argv - String buffer of program arguments.
      \return true  - if the program arguments were successfully parsed. \n
              false - if the program arguments were not successfully parsed. \n
  */
  static Tbool parseProgramArguments(NContainers::CStringBuffer<NString::CString>& a_rArguments, Tsint argc, Tschar *argv[]);
  //! Parse ANSI C/C++ program arguments in Unicode encoding and fill the given string buffer.
  /*!
      \param a_rArguments - Reference to the string buffer with program arguments.
      \param argc - Count of program arguments.
      \param argv - String buffer of program arguments.
      \return true  - if the program arguments were successfully parsed. \n
              false - if the program arguments were not successfully parsed. \n
  */
  static Tbool parseProgramArguments(NContainers::CStringBuffer<NString::CString>& a_rArguments, Tsint argc, Twchar *argv[]);
  //! Parse program arguments from arguments string and fill the given string buffer.
  /*!
      \param a_rArguments - Reference to the string buffer with program arguments.
      \param a_crArgumentsString - Constant reference to the program arguments string.
      \return true  - if the program arguments were successfully parsed. \n
              false - if the program arguments were not successfully parsed. \n
  */
  static Tbool parseProgramArguments(NContainers::CStringBuffer<NString::CString>& a_rArguments, const NString::CString& a_crArgumentsString);

  //! Parse ANSI C/C++ environment variables in ASCII encoding and fill the given string buffer.
  /*!
      \param a_rEnvironment - Reference to the string buffer with environment variables.
      \param envp - String buffer of environment variables.
      \return true  - if the environment variables were successfully parsed. \n
              false - if the environment variables were not successfully parsed. \n
  */
  static Tbool parseEnvironmentVariables(NContainers::CStringBuffer<NString::CString>& a_rEnvironment, Tschar *envp[]);
  //! Parse ANSI C/C++ environment variables in Unicode encoding and fill the given string buffer.
  /*!
      \param a_rEnvironment - Reference to the string buffer with environment variables.
      \param envp - String buffer of environment variables.
      \return true  - if the environment variables were successfully parsed. \n
              false - if the environment variables were not successfully parsed. \n
  */
  static Tbool parseEnvironmentVariables(NContainers::CStringBuffer<NString::CString>& a_rEnvironment, Twchar *envp[]);
  //! Parse ANSI C/C++ environment variables from environment variables string and fill the given string buffer.
  /*!
      \param a_rEnvironment - Reference to the string buffer with environment variables.
      \param a_crEnvironmentString - Constant reference to the environment variables string.
      \return true  - if the environment variables were successfully parsed. \n
              false - if the environment variables were not successfully parsed. \n
  */
  static Tbool parseEnvironmentVariables(NContainers::CStringBuffer<NString::CString>& a_rEnvironment, const NString::CString& a_crEnvironmentString);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
//! \example example-application-CApplicationHelper.cpp
/*--------------------------------------------------------------------------*/
//! \test test-application-CApplicationHelper.cpp
/*==========================================================================*/
#endif
