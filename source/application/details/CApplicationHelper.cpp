/*!
 *  \file    CApplicationHelper.cpp Application helper class contains utility
 *           functionality to work with program arguments.
 *  \brief   Application helper class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Application helper class (source).

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
#include <Depth/include/application.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/application/details/CApplicationHelper.hpp>
#include <Depth/include/string/CCharacter.hpp>
/*==========================================================================*/
#ifndef __CAPPLICATIONHELPER_CPP__
#define __CAPPLICATIONHELPER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NApplication {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CApplicationHelper::composeProgramArguments(NString::CString& a_rArgumentsString, Tsint argc, Tschar *argv[])
{ CALL
  // Check if the system program arguments buffer length is valid.
  ASSERT((argc >= 0), STR("System program arguments buffer length is invalid (argc = %i).") COMMA argc)
  {
    return false;
  }
  // Check if the system program arguments buffer is NULL.
  ASSERT((argv != NULL), STR("System program arguments buffer is NULL."))
  {
    return false;
  }

  // Clear program arguments string.
  if (!a_rArgumentsString.clear())
    return false;

  // Insert all program arguments into the string.
  for (Tsint i = 0; i < argc; ++i)
  {
    if (!a_rArgumentsString.insertLast(NString::CSystemString(argv[i])))
      return false;
    if (!a_rArgumentsString.insertLast(STR(' ')))
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CApplicationHelper::composeProgramArguments(NString::CString& a_rArgumentsString, Tsint argc, Twchar *argv[])
{ CALL
  // Check if the system program arguments buffer length is valid.
  ASSERT((argc >= 0), STR("System program arguments buffer length is invalid (argc = %i).") COMMA argc)
  {
    return false;
  }
  // Check if the system program arguments buffer is NULL.
  ASSERT((argv != NULL), STR("System program arguments buffer is NULL."))
  {
    return false;
  }

  // Clear program arguments string.
  if (!a_rArgumentsString.clear())
    return false;

  // Insert all program arguments into the string.
  for (Tsint i = 0; i < argc; ++i)
  {
    if (!a_rArgumentsString.insertLast(NString::CSystemString(argv[i])))
      return false;
    if (!a_rArgumentsString.insertLast(STR(' ')))
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CApplicationHelper::composeProgramArguments(NString::CString& a_rArgumentsString, const NContainers::CStringBuffer<NString::CString>& a_crArguments)
{ CALL
  // Clear program arguments string.
  if (!a_rArgumentsString.clear())
    return false;

  // Insert all program arguments into the string.
  for (Tuint i = 0; i < a_crArguments.getSize(); ++i)
  {
    if (!a_rArgumentsString.insertLast(a_crArguments[i]))
      return false;
    if (!a_rArgumentsString.insertLast(STR(' ')))
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CApplicationHelper::composeEnvironmentVariables(NString::CString& a_rEnvironmentString, Tschar *envp[])
{ CALL
  // Check if the system environment variables buffer is NULL.
  ASSERT((envp != NULL), STR("System environment variables buffer is NULL."))
  {
    return false;
  }

  // Clear environment arguments string.
  if (!a_rEnvironmentString.clear())
    return false;

  // Calculate count of the environment variables.
  Tuint envc = 0;
  Tschar** temp_envp = envp;
  while (*temp_envp++ != NULL)
    envc++;

  // Insert all environment arguments into the string.
  for (Tuint i = 0; i < envc; ++i)
  {
    if (!a_rEnvironmentString.insertLast(NString::CSystemString(envp[i])))
      return false;
    if (!a_rEnvironmentString.insertLast(STR('\0')))
      return false;
  }

  // Insert last character.
  if (!a_rEnvironmentString.insertLast(STR('\0')))
    return false;

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CApplicationHelper::composeEnvironmentVariables(NString::CString& a_rEnvironmentString, Twchar *envp[])
{ CALL
  // Check if the system environment variables buffer is NULL.
  ASSERT((envp != NULL), STR("System environment variables buffer is NULL."))
  {
    return false;
  }

  // Clear environment arguments string.
  if (!a_rEnvironmentString.clear())
    return false;

  // Calculate count of the environment variables.
  Tuint envc = 0;
  Twchar** temp_envp = envp;
  while (*temp_envp++ != NULL)
    envc++;

  // Insert all environment arguments into the string.
  for (Tuint i = 0; i < envc; ++i)
  {
    if (!a_rEnvironmentString.insertLast(NString::CSystemString(envp[i])))
      return false;
    if (!a_rEnvironmentString.insertLast(STR('\0')))
      return false;
  }

  // Insert last character.
  if (!a_rEnvironmentString.insertLast(STR('\0')))
    return false;

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CApplicationHelper::composeEnvironmentVariables(NString::CString& a_rEnvironmentString, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment)
{ CALL
  // Clear environment arguments string.
  if (!a_rEnvironmentString.clear())
    return false;

  // Insert all environment arguments into the string.
  for (Tuint i = 0; i < a_crEnvironment.getSize(); ++i)
  {
    if (!a_rEnvironmentString.insertLast(a_crEnvironment[i]))
      return false;
    if (!a_rEnvironmentString.insertLast(STR('\0')))
      return false;
  }

  // Insert last character.
  if (!a_rEnvironmentString.insertLast(STR('\0')))
    return false;

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CApplicationHelper::parseProgramArguments(NContainers::CStringBuffer<NString::CString>& a_rArguments, Tsint argc, Tschar *argv[])
{ CALL
  // Check if the system program arguments buffer length is valid.
  ASSERT((argc >= 0), STR("System program arguments buffer length is invalid (argc = %i).") COMMA argc)
  {
    return false;
  }
  // Check if the system program arguments buffer is NULL.
  ASSERT((argv != NULL), STR("System program arguments buffer is NULL."))
  {
    return false;
  }

  // Clear old program arguments.
  if (!a_rArguments.clear())
    return false;

  // Setup program arguments string buffer.
  for (Tsint i = 0; i < argc; ++i)
    if (!a_rArguments.insertLast(NString::CSystemString(argv[i])))
      return false;

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CApplicationHelper::parseProgramArguments(NContainers::CStringBuffer<NString::CString>& a_rArguments, Tsint argc, Twchar *argv[])
{ CALL
  // Check if the system program arguments buffer length is valid.
  ASSERT((argc >= 0), STR("System program arguments buffer length is invalid (argc = %i).") COMMA argc)
  {
    return false;
  }
  // Check if the system program arguments buffer is NULL.
  ASSERT((argv != NULL), STR("System program arguments buffer is NULL."))
  {
    return false;
  }

  // Clear old program arguments.
  if (!a_rArguments.clear())
    return false;

  // Setup program arguments string buffer.
  for (Tsint i = 0; i < argc; ++i)
    if (!a_rArguments.insertLast(NString::CSystemString(argv[i])))
      return false;

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CApplicationHelper::parseProgramArguments(NContainers::CStringBuffer<NString::CString>& a_rArguments, const NString::CString& a_crArgumentsString)
{ CALL
  // Clear old program arguments.
  if (!a_rArguments.clear())
    return false;

  // Itarate through all program arguments string in order to parse single argument strings.
  Tuint index = 0;
  Tuint length = a_crArgumentsString.getSize();
  Tcstr buffer = a_crArgumentsString.getBuffer();
  while ((*buffer != STR('\0')) && (index < length))
  {
    // Skip space characters.
    while (NString::CCharacter(*buffer).isSpace())
    {
      ++index;
      ++buffer;
    }

    // Parse single argument.
    if ((*buffer != STR('\0')) && (index < length))
    {
      Tchar quote = STR('\0');
      NString::CString temp;

      // Check for " or ' quote.
      if ((*buffer == STR('\"')) || (*buffer == STR('\'')))
      {
        quote = *buffer;
        ++index;
        ++buffer;
      }

      // Parse remaining part of the program argument.
      while ((*buffer != STR('\0')) && (index < length))
      {
        // Check for a close quote character.
        if (quote != STR('\0'))
        {
          if (*buffer == quote)
          {
            ++index;
            ++buffer;
            if (NString::CCharacter(*buffer).isSpace())
              break;
            quote = 0;
          }
        }

        // Check for a escape character.
        if (*buffer == STR('\\'))
        {
          if ((index + 1) < length)
          {
            ++index;
            ++buffer;
            if ((*buffer != STR('\"')) && (*buffer != STR('\'')))
            {
              --index;
              --buffer;
            }
          }
        }
        else
        {
          if (quote == STR('\0'))
          {
            if ((*buffer == STR('\"')) || (*buffer == STR('\'')))
            {
              quote = *buffer;
              ++index;
              ++buffer;
              continue;
            }
            else if (NString::CCharacter(*buffer).isSpace())
              break;
          }
        }
        // Collect program argument characters.
        if (*buffer != STR('\0') && (index < length))
        {
          if (!temp.insertLast(*buffer))
            return false;
          ++index;
          ++buffer;
        }
      }

      // Insert new program argument.
      if (!a_rArguments.insertLast(NString::CSystemString((Tcbuffer)temp.getBuffer(), (temp.getSize() * sizeof(Tchar)))))
        return false;

      // Move to the next character.
      if ((*buffer != STR('\0')) && (index < length))
      {
        ++index;
        ++buffer;
      }
    }
  }

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CApplicationHelper::parseEnvironmentVariables(NContainers::CStringBuffer<NString::CString>& a_rEnvironment, Tschar *envp[])
{ CALL
  // Check if the system environment variables buffer is NULL.
  ASSERT((envp != NULL), STR("System environment variables buffer is NULL."))
  {
    return false;
  }

  // Clear old environment variables.
  if (!a_rEnvironment.clear())
    return false;

  // Calculate count of the environment variables.
  Tuint envc = 0;
  Tschar** temp_envp = envp;
  while (*temp_envp++ != NULL)
    envc++;

  // Setup environment variables string buffer.
  for (Tuint i = 0; i < envc; ++i)
    if (!a_rEnvironment.insertLast(NString::CSystemString(envp[i])))
      return false;

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CApplicationHelper::parseEnvironmentVariables(NContainers::CStringBuffer<NString::CString>& a_rEnvironment, Twchar *envp[])
{ CALL
  // Check if the system environment variables buffer is NULL.
  ASSERT((envp != NULL), STR("System environment variables buffer is NULL."))
  {
    return false;
  }

  // Clear old environment variables.
  if (!a_rEnvironment.clear())
    return false;

  // Calculate count of the environment variables.
  Tuint envc = 0;
  Twchar** temp_envp = envp;
  while (*temp_envp++ != NULL)
    envc++;

  // Setup environment variables string buffer.
  for (Tuint i = 0; i < envc; ++i)
    if (!a_rEnvironment.insertLast(NString::CSystemString(envp[i])))
      return false;

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CApplicationHelper::parseEnvironmentVariables(NContainers::CStringBuffer<NString::CString>& a_rEnvironment, const NString::CString& a_crEnvironmentString)
{ CALL
  // Clear old environment variables.
  if (!a_rEnvironment.clear())
    return false;

  // Calculate count of the environment variables.
  Tbool good = false;
  Tuint envc = 0;
  Tuint length = a_crEnvironmentString.getSize();
  for (Tuint i = 0; i < length; ++i)
  {
    if (a_crEnvironmentString[i] == STR('\0'))
    {
      if (((i + 1) < length) && (a_crEnvironmentString[i + 1] == STR('\0')))
      {
        good = true;
        if (length > 2)
          ++envc;
        break;
      }
      else
        ++envc;
    }
  }
  if (!good)
  {
    WARNING(STR("Environment string is not valid '\\0' delimited string with '\\0\\0' on the end."));
    return false;
  }

  // Setup environment variables string buffer.
  Tuint index = 0;
  Tcstr str = a_crEnvironmentString.getBuffer();
  for (Tuint i = 0; i < length; ++i)
  {
    if (a_crEnvironmentString[i] == STR('\0'))
    {
      if (!a_rEnvironment.insertLast(NString::CSystemString(str)))
        return false;
      else
        ++index;

      str = a_crEnvironmentString.getBuffer() + (((i + 1) < length) ? (i + 1) : i);

      if (((i + 1) < length) && (a_crEnvironmentString[i + 1] == STR('\0')))
        break;
    }
  }

  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
