/*!
 *  \file    CSystemString.cpp System string class provides base string
 *           functionality in the system dependant encoding.
 *  \brief   System string class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.04.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: System string class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String
    VERSION:   1.0
    CREATED:   28.04.2008 23:05:50

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/algorithms/string/buffer/AStrLen.hpp>
#include <Depth/include/memory/CMemory.hpp>
#include <Depth/include/string/CCharacter.hpp>
#include <Depth/include/string/CSystemString.hpp>
#include <Depth/include/string/details/CSystemStringHelper.hpp>
/*==========================================================================*/
#ifndef __CSYSTEMSTRING_CPP__
#define __CSYSTEMSTRING_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
BASE_API const CSystemString CSystemString::EMPTY = CSystemString();
BASE_API Tbuffer CSystemString::ms_pEmptyBuffer = (Tbuffer)"";
/*--------------------------------------------------------------------------*/
BASE_API Tbool operator == (const CSystemString& a_crInstance1, const CSystemString& a_crInstance2)
{ CALL
  if (a_crInstance1.m_Size == a_crInstance2.m_Size)
  {
    for (Tuint i = 0; i < a_crInstance1.m_Size; ++i)
      if (a_crInstance1.m_pBuffer[i] != a_crInstance2.m_pBuffer[i])
        return false;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemString::set(const Tschar a_cASCIICharacter, const Tbool a_cAppendZero/* = false */)
{ CALL
  Tuint length = (a_cAppendZero ? 2 : 1);
  Tuint size = 0;

  Tschar str[2];
  str[0] = a_cASCIICharacter;
  str[1] = ASC('\0');

  // Clear current system string.
  if (!clear())
    return false;

  // Get size of a new system string in bytes.
  if (!NDetails::CSystemStringHelper::ASCIIToSystemCount(str, length, size))
  {
    WARNING(STR("Cannot get required buffer size to convert string from ASCII encoding to system one. Content of the string has to be checked - \"%s\".") COMMA a_cASCIICharacter);
    return false;
  }

  // Create new system string.
  if (size > 0)
  {
    // Allocate required buffer.
    Tbuffer buffer = newex Tbyte[size];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate system string buffer (requested size is %u bytes).") COMMA size);
      return false;
    }

    // Convert characters.
    if (!NDetails::CSystemStringHelper::ASCIIToSystem(buffer, str, length, size))
    {
      delete [] buffer;
      WARNING(STR("Cannot convert string from ASCII encoding to system one. Content of the string has to be checked - \"%s\".") COMMA a_cASCIICharacter);
      return false;
    }

    // Update system string attributes.
    m_Size = size;
    m_pBuffer = buffer;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemString::set(const Twchar a_cUnicodeCharacter, const Tbool a_cAppendZero/* = false */)
{ CALL
  Tuint length = (a_cAppendZero ? 2 : 1);
  Tuint size = 0;

  Twchar str[2];
  str[0] = a_cUnicodeCharacter;
  str[1] = UNC('\0');

  // Clear current system string.
  if (!clear())
    return false;

  // Get size of a new system string in bytes.
  if (!NDetails::CSystemStringHelper::UnicodeToSystemCount(str, length, size))
  {
    WARNING(STR("Cannot get required buffer size to convert string from Unicode encoding to system one. Content of the string has to be checked - \"%w\".") COMMA a_cUnicodeCharacter);
    return false;
  }

  // Create new system string.
  if (size > 0)
  {
    // Allocate required buffer.
    Tbuffer buffer = newex Tbyte[size];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate system string buffer (requested size is %u bytes).") COMMA size);
      return false;
    }

    // Convert characters.
    if (!NDetails::CSystemStringHelper::UnicodeToSystem(buffer, str, length, size))
    {
      delete [] buffer;
      WARNING(STR("Cannot convert string from Unicode encoding to system one. Content of the string has to be checked - \"%w\".") COMMA a_cUnicodeCharacter);
      return false;
    }

    // Update system string attributes.
    m_Size = size;
    m_pBuffer = buffer;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemString::set(Tcsstr a_cpASCIIString, const Tbool a_cAppendZero/* = false */)
{ CALL
  // Check if the given ASCII 'C' string buffer is not NULL.
  ASSERT((a_cpASCIIString != NULL), STR("Cannot set ASCII 'C' string buffer which is NULL."))
  {
    return false;
  }

  Tuint length = NAlgorithms::NString::NBuffer::strLen(a_cpASCIIString) + (a_cAppendZero ? 1 : 0);
  Tuint size = 0;

  // Clear current system string.
  if (!clear())
    return false;

  // Check if the given string is empty.
  if (length == 0)
    return true;

  // Get size of a new system string in bytes.
  if (!NDetails::CSystemStringHelper::ASCIIToSystemCount(a_cpASCIIString, length, size))
  {
    WARNING(STR("Cannot get required buffer size to convert string from ASCII encoding to system one. Content of the string has to be checked - \"%ZS\".") COMMA a_cpASCIIString);
    return false;
  }

  // Create new system string.
  if (size > 0)
  {
    // Allocate required buffer.
    Tbuffer buffer = newex Tbyte[size];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate system string buffer (requested size is %u bytes).") COMMA size);
      return false;
    }

    // Convert characters.
    if (!NDetails::CSystemStringHelper::ASCIIToSystem(buffer, a_cpASCIIString, length, size))
    {
      delete [] buffer;
      WARNING(STR("Cannot convert string from ASCII encoding to system one. Content of the string has to be checked - \"%ZS\".") COMMA a_cpASCIIString);
      return false;
    }

    // Update system string attributes.
    m_Size = size;
    m_pBuffer = buffer;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemString::set(Tcwstr a_cpUnicodeString, const Tbool a_cAppendZero/* = false */)
{ CALL
  // Check if the given Unicode 'C' string buffer is not NULL.
  ASSERT((a_cpUnicodeString != NULL), STR("Cannot set Unicode 'C' string buffer which is NULL."))
  {
    return false;
  }

  Tuint length = NAlgorithms::NString::NBuffer::strLen(a_cpUnicodeString) + (a_cAppendZero ? 1 : 0);
  Tuint size = 0;

  // Clear current system string.
  if (!clear())
    return false;

  // Check if the given string is empty.
  if (length == 0)
    return true;

  // Get size of a new system string in bytes.
  if (!NDetails::CSystemStringHelper::UnicodeToSystemCount(a_cpUnicodeString, length, size))
  {
    WARNING(STR("Cannot get required buffer size to convert string from Unicode encoding to system one. Content of the string has to be checked - \"%ZW\".") COMMA a_cpUnicodeString);
    return false;
  }

  // Create new system string.
  if (size > 0)
  {
    // Allocate required buffer.
    Tbuffer buffer = newex Tbyte[size];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate system string buffer (requested size is %u bytes).") COMMA size);
      return false;
    }

    // Convert characters.
    if (!NDetails::CSystemStringHelper::UnicodeToSystem(buffer, a_cpUnicodeString, length, size))
    {
      delete [] buffer;
      WARNING(STR("Cannot convert string from Unicode encoding to system one. Content of the string has to be checked - \"%ZW\".") COMMA a_cpUnicodeString);
      return false;
    }

    // Update system string attributes.
    m_Size = size;
    m_pBuffer = buffer;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemString::set(Tcbuffer a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the given system string buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot set system string buffer which is NULL."))
  {
    return false;
  }

  // Clear current system string.
  if (!clear())
    return false;

  // Create new system string.
  if (a_cSize > 0)
  {
    // Allocate required buffer.
    Tbuffer buffer = newex Tbyte[a_cSize];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate system string buffer (requested size is %u bytes).") COMMA a_cSize);
      return false;
    }

    // Copy characters.
    NMemory::CMemory::copy(buffer, a_cpBuffer, a_cSize);

    // Update system string attributes.
    m_Size = a_cSize;
    m_pBuffer = buffer;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemString::set(const CSystemString& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CSystemString class instance."))
  {
    return false;
  }

  return set(a_crInstance.m_pBuffer, a_crInstance.m_Size);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemString::clear()
{ CALL
  // Delete string buffer.
  if ((m_pBuffer != NULL) && (m_pBuffer != CSystemString::ms_pEmptyBuffer))
    delete [] m_pBuffer;

  // Update system string attributes.
  m_Size = 0;
  m_pBuffer = CSystemString::ms_pEmptyBuffer;
  return true;
}
/*--------------------------------------------------------------------------*/
CSystemString::TIterator CSystemString::getItFirst()
{ CALL
  TIterator it_first;

  // Filling iterator inner structure.
  it_first.m_pContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
CSystemString::TIteratorConst CSystemString::getItFirst() const
{ CALL
  TIteratorConst it_first;

  // Filling iterator inner structure.
  it_first.m_cpContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
CSystemString::TIterator CSystemString::getItLast()
{ CALL
  TIterator it_last;

  // Filling iterator inner structure.
  it_last.m_pContainer = this;
  it_last.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
CSystemString::TIteratorConst CSystemString::getItLast() const
{ CALL
  TIteratorConst it_last;

  // Filling iterator inner structure.
  it_last.m_cpContainer = this;
  it_last.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
CSystemString::TIterator CSystemString::getItIndex(const Tuint a_cIndex)
{ CALL
  TIterator it_index;

  // Filling iterator inner structure.
  it_index.m_pContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
CSystemString::TIteratorConst CSystemString::getItIndex(const Tuint a_cIndex) const
{ CALL
  TIteratorConst it_index;

  // Filling iterator inner structure.
  it_index.m_cpContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
Tsint CSystemString::compare(const CSystemString& a_crString1, const CSystemString& a_crString2)
{ CALL
  Tuint length1 = a_crString1.getSize();
  Tuint length2 = a_crString2.getSize();

  Tcbuffer buffer1 = a_crString1.getBuffer();
  Tcbuffer buffer2 = a_crString2.getBuffer();
  Tuint length = (length1 < length2) ? length1 : length2;
  Tsint sublength = (Tsint)(length1 - length2);
  Tsint result = 0;

  while ((length > 0) && ((result = (*buffer1++ - *buffer2++)) == 0))
    --length;

  if ((sublength == 0) || (length > 0))
    return result;
  else
    return sublength;
}
/*--------------------------------------------------------------------------*/
Tsint CSystemString::compareIgnoreCase(const CSystemString& a_crString1, const CSystemString& a_crString2)
{ CALL
  Tuint length1 = a_crString1.getSize();
  Tuint length2 = a_crString2.getSize();

  Tcbuffer buffer1 = a_crString1.getBuffer();
  Tcbuffer buffer2 = a_crString2.getBuffer();
  Tuint length = (length1 < length2) ? length1 : length2;
  Tsint sublength = (Tsint)(length1 - length2);
  Tsint result = 0;

  while ((length > 0) && ((result = (CCharacter((Tuint)((Tscharu)(*buffer1++))).toLowerCase() - CCharacter((Tuint)((Tscharu)(*buffer2++))).toLowerCase())) == 0))
    --length;

  if ((sublength == 0) || (length > 0))
    return result;
  else
    return sublength;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemString::getSystemCharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount)
{ CALL
  return NDetails::CSystemStringHelper::getSystemCharsCount(a_cpBuffer, a_cSize, a_rCount);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemString::SystemToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return NDetails::CSystemStringHelper::SystemToUTF8Count(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemString::UTF8ToSystemCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return NDetails::CSystemStringHelper::UTF8ToSystemCount(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemString::SystemToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return NDetails::CSystemStringHelper::SystemToUTF8(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemString::UTF8ToSystem(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return NDetails::CSystemStringHelper::UTF8ToSystem(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
