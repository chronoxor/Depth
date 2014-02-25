/*!
 *  \file    CStringASCII.cpp ASCII string class provides base string
 *           functionality in the ASCII encoding.
 *  \brief   ASCII string class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: ASCII string class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String
    VERSION:   1.0
    CREATED:   02.08.2008 23:53:28

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
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/algorithms/string/buffer/AStrLen.hpp>
#include <Depth/include/memory/CMemory.hpp>
#include <Depth/include/string/CCharacter.hpp>
#include <Depth/include/string/CStringASCII.hpp>
#include <Depth/include/string/details/CSystemStringHelper.hpp>
/*==========================================================================*/
#ifndef __CSTRINGASCII_CPP__
#define __CSTRINGASCII_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
BASE_API const CStringASCII CStringASCII::EMPTY = CStringASCII();
/*--------------------------------------------------------------------------*/
BASE_API Tbool operator == (const CStringASCII& a_crInstance1, const CStringASCII& a_crInstance2)
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
Tbool CStringASCII::set(const Tschar a_cASCIICharacter, const Tbool a_cAppendZero/* = false */)
{ CALL
  // Clear current ASCII string.
  if (!clear())
    return false;

  // Resize ASCII string to fit the given ASCII character.
  if (resize(a_cAppendZero ? 2 : 1))
  {
    // Copy ASCII character.
    m_pBuffer[0] = a_cASCIICharacter;
    if (a_cAppendZero)
      m_pBuffer[1] = ASC('\0');
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::set(const Twchar a_cUnicodeCharacter, const Tbool a_cAppendZero/* = false */)
{ CALL
  // Check if Unicode character fits ASCII bounds.
  ASSERT(NString::CCharacter(a_cUnicodeCharacter).isValidASCII(), STR("Cannot set Unicode character which does not fit ASCII bounds (character code is %hU).") COMMA (Tuint)a_cUnicodeCharacter)
  {
    return false;
  }

  // Clear current ASCII string.
  if (!clear())
    return false;

  // Resize ASCII string to fit the given Unicode character.
  if (resize(a_cAppendZero ? 2 : 1))
  {
    // Copy Unicode character.
    m_pBuffer[0] = (Tschar)((Twcharu)a_cUnicodeCharacter);
    if (a_cAppendZero)
      m_pBuffer[1] = ASC('\0');
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::set(Tcsstr a_cpASCIIString, const Tbool a_cAppendZero/* = false */)
{ CALL
  // Check if the given ASCII 'C' string buffer is not NULL.
  ASSERT((a_cpASCIIString != NULL), STR("Cannot set ASCII 'C' string buffer which is NULL."))
  {
    return false;
  }

  Tuint length = NAlgorithms::NString::NBuffer::strLen(a_cpASCIIString) + (a_cAppendZero ? 1 : 0);

  // Clear current ASCII string.
  if (!clear())
    return false;

  // Resize ASCII string to fit the given ASCII buffer.
  if (resize(length))
  {
    // Copy ASCII buffer.
    for (Tuint i = 0; i < length; ++i)
      m_pBuffer[i] = a_cpASCIIString[i];
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::set(Tcwstr a_cpUnicodeString, const Tbool a_cAppendZero/* = false */)
{ CALL
  // Check if the given Unicode 'C' string buffer is not NULL.
  ASSERT((a_cpUnicodeString != NULL), STR("Cannot set Unicode 'C' string buffer which is NULL."))
  {
    return false;
  }

  Tuint length = NAlgorithms::NString::NBuffer::strLen(a_cpUnicodeString) + (a_cAppendZero ? 1 : 0);

  // Check if all Unicode characters from the given buffer fits ASCII bounds.
  for (Tuint i = 0; i < length; ++i)
  {
    ASSERT(NString::CCharacter(a_cpUnicodeString[i]).isValidASCII(), STR("Cannot insert Unicode character which does not fit ASCII bounds (character code is %hU).") COMMA (Tuint)a_cpUnicodeString[i])
    {
      return false;
    }
  }

  // Clear current ASCII string.
  if (!clear())
    return false;

  // Resize ASCII string to fit the given Unicode buffer.
  if (resize(length))
  {
    // Copy Unicode buffer.
    for (Tuint i = 0; i < length; ++i)
      m_pBuffer[i] = (Tschar)((Twcharu)a_cpUnicodeString[i]);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::set(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the given ASCII string buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot set ASCII string buffer which is NULL."))
  {
    return false;
  }

  // Clear current ASCII string.
  if (!clear())
    return false;

  // Resize ASCII string to fit the given ASCII buffer.
  if (resize(a_cSize))
  {
    // Copy ASCII buffer.
    for (Tuint i = 0; i < a_cSize; ++i)
      m_pBuffer[i] = a_cpBuffer[i];
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::set(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the given Unicode string buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot set Unicode string buffer which is NULL."))
  {
    return false;
  }

  // Check if all Unicode characters from the given buffer fits ASCII bounds.
  for (Tuint i = 0; i < a_cSize; ++i)
  {
    ASSERT(NString::CCharacter(a_cpBuffer[i]).isValidASCII(), STR("Cannot insert Unicode character which does not fit ASCII bounds (character code is %hU).") COMMA (Tuint)a_cpBuffer[i])
    {
      return false;
    }
  }

  // Clear current ASCII string.
  if (!clear())
    return false;

  // Resize ASCII string to fit the given Unicode buffer.
  if (resize(a_cSize))
  {
    // Copy ASCII buffer.
    for (Tuint i = 0; i < a_cSize; ++i)
      m_pBuffer[i] = (Tschar)((Twcharu)a_cpBuffer[i]);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::set(const CSystemString& a_crInstance)
{ CALL
  Tuint count = 0;
  Tuint size = 0;

  // Clear current ASCII string.
  if (!clear())
    return false;

  // Get count of system string characters.
  if (!NDetails::CSystemStringHelper::getSystemCharsCount(a_crInstance.m_pBuffer, a_crInstance.m_Size, count))
  {
    WARNING(STR("Cannot get count of system string characters in the given system string. Content of the system string has to be checked."));
    return false;
  }

  // Get size of same string in ASCII encoding in bytes.
  if (!NDetails::CSystemStringHelper::SystemToASCIICount(a_crInstance.m_pBuffer, count, size))
  {
    WARNING(STR("Cannot get required buffer size to convert string from system encoding to ASCII one. Content of the system string has to be checked."));
    return false;
  }

  // Save the system string content.
  if (size > 0)
  {
    // Allocate required buffer.
    Tuint bound = size + (size >> 1);
    Tbuffer buffer = newex Tbyte[bound];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate ASCII string buffer (requested size is %u bytes).") COMMA bound);
      return false;
    }

    // Convert system string in ASCII encoding.
    if (!NDetails::CSystemStringHelper::SystemToASCII(buffer, a_crInstance.m_pBuffer, count, size))
    {
      delete [] buffer;
      WARNING(STR("Cannot convert string from system encoding to ASCII one. Content of the system string has to be checked."));
      return false;
    }

    // Update ASCII string parameters.
    m_pBuffer = (Tsstr)buffer;
    m_Size = count;
    m_HiCapacity = bound;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::set(const CStringASCII& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CStringASCII class instance."))
  {
    return false;
  }

  // Clear current ASCII string.
  if (!clear())
    return false;

  // Resize ASCII string to fit the given ASCII buffer.
  if (resize(a_crInstance.m_Size))
  {
    // Copy ASCII buffer.
    for (Tuint i = 0; i < a_crInstance.m_Size; ++i)
      m_pBuffer[i] = a_crInstance.m_pBuffer[i];
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::set(const CStringUnicode& a_crInstance)
{ CALL
  // Check if all Unicode characters from the given buffer fits ASCII bounds.
  for (Tuint i = 0; i < a_crInstance.m_Size; ++i)
  {
    ASSERT(NString::CCharacter(a_crInstance.m_pBuffer[i]).isValidASCII(), STR("Cannot insert Unicode character which does not fit ASCII bounds (character code is %hU).") COMMA (Tuint)a_crInstance.m_pBuffer[i])
    {
      return false;
    }
  }

  // Clear current ASCII string.
  if (!clear())
    return false;

  // Resize ASCII string to fit the given Unicode buffer.
  if (resize(a_crInstance.m_Size))
  {
    // Copy Unicode buffer.
    for (Tuint i = 0; i < a_crInstance.m_Size; ++i)
      m_pBuffer[i] = (Tschar)((Twcharu)a_crInstance.m_pBuffer[i]);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::getSystemString(CSystemString& a_rSystemString, const Tbool a_cAppendZero/* = false */) const
{ CALL
  // Clear system string content.
  if (!a_rSystemString.clear())
    return false;

  Tbool add_zero = (a_cAppendZero && (isEmpty() || (m_pBuffer[m_Size - 1] != ASC('\0'))));
  Tuint count = m_Size + (add_zero ? 1 : 0);
  Tuint size = m_Size * sizeof(Tschar);

  // Load the system string content.
  if (size > 0)
  {
    // Get size of same string in system encoding in bytes.
    Tuint str_size = 0;
    if (add_zero)
    {
      Tschar zero = ASC('\0');
      Tuint zero_size;
      if (!NDetails::CSystemStringHelper::ASCIIToSystemCount(m_pBuffer, count - 1, str_size) || !NDetails::CSystemStringHelper::ASCIIToSystemCount(&zero, 1, zero_size))
      {
        WARNING(STR("Cannot get required buffer size to convert string from ASCII encoding to system one. Content of the ASCII string has to be checked."));
        return false;
      }
      str_size += zero_size;
    }
    else
    {
      if (!NDetails::CSystemStringHelper::ASCIIToSystemCount(m_pBuffer, count, str_size))
      {
        WARNING(STR("Cannot get required buffer size to convert string from ASCII encoding to system one. Content of the ASCII string has to be checked."));
        return false;
      }
    }

    // Allocate required buffer in system encoding.
    Tbuffer str_buffer = newex Tbyte[str_size];
    if (str_buffer == NULL)
    {
      WARNING(STR("Cannot allocate system string buffer (requested size is %u bytes).") COMMA str_size);
      return false;
    }

    // Convert system string from ASCII encoding.
    if (add_zero)
    {
      Tschar zero = ASC('\0');
      Tuint zero_size;
      if (!NDetails::CSystemStringHelper::ASCIIToSystem(str_buffer, m_pBuffer, count - 1, str_size) || !NDetails::CSystemStringHelper::ASCIIToSystem(str_buffer + str_size, &zero, 1, zero_size))
      {
        delete [] str_buffer;
        WARNING(STR("Cannot convert string from ASCII encoding to system one. Content of the ASCII string has to be checked."));
        return false;
      }
      str_size += zero_size;
    }
    else
    {
      if (!NDetails::CSystemStringHelper::ASCIIToSystem(str_buffer, m_pBuffer, count, str_size))
      {
        delete [] str_buffer;
        WARNING(STR("Cannot convert string from ASCII encoding to system one. Content of the ASCII string has to be checked."));
        return false;
      }
    }

    // Update system string attributes.
    a_rSystemString.m_Size = str_size;
    a_rSystemString.m_pBuffer = str_buffer;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
CStringASCII CStringASCII::getLeft(const Tuint a_cSize) const
{ CALL
  return CStringASCII(m_pBuffer, NAlgorithms::NCommon::min(m_Size, a_cSize));
}
/*--------------------------------------------------------------------------*/
CStringASCII CStringASCII::getRight(const Tuint a_cSize) const
{ CALL
  return CStringASCII(m_pBuffer + ((m_Size > a_cSize) ? (m_Size - a_cSize) : 0), NAlgorithms::NCommon::min(m_Size, a_cSize));
}
/*--------------------------------------------------------------------------*/
CStringASCII CStringASCII::getMiddle(const Tuint a_cIndex, const Tuint a_cSize) const
{ CALL
  // Check index value and the ASCII string bounds.
  ASSERT((a_cIndex <= m_Size), STR("Cannot get middle sub-string from the ASCII string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return CStringASCII::EMPTY;
  }

  return CStringASCII(m_pBuffer + a_cIndex, NAlgorithms::NCommon::min(m_Size - a_cIndex, a_cSize));
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::clear()
{ CALL
  // Delete string buffer.
  if (m_pBuffer != NULL)
    delete [] m_pBuffer;

  // Update string attributes.
  m_Size = 0;
  m_HiCapacity = 0;
  m_pBuffer = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
void CStringASCII::reverse()
{ CALL
  Tsstr left = m_pBuffer;
  Tsstr right = m_pBuffer + m_Size - 1;

  while (left < right)
    NAlgorithms::NCommon::swap(*(left++), *(right--));
}
/*--------------------------------------------------------------------------*/
void CStringASCII::toLowerCase()
{ CALL
  Tuint delta = (ASC('a') - ASC('A'));
  Tuint size = m_Size;
  Tsstr buffer = m_pBuffer;

  while (size-- > 0)
  {
    if ((*buffer >= ASC('A')) && (*buffer <= ASC('Z')))
      *buffer = (Tschar)(*buffer + delta);
    ++buffer;
  }
}
/*--------------------------------------------------------------------------*/
void CStringASCII::toUpperCase()
{ CALL
  Tuint delta = (ASC('a') - ASC('A'));
  Tuint size = m_Size;
  Tsstr buffer = m_pBuffer;

  while (size-- > 0)
  {
    if ((*buffer >= ASC('a')) && (*buffer <= ASC('z')))
      *buffer = (Tschar)(*buffer - delta);
    ++buffer;
  }
}
/*--------------------------------------------------------------------------*/
void CStringASCII::toTitleCase()
{ CALL
  toUpperCase();
}
/*--------------------------------------------------------------------------*/
void CStringASCII::toToggleCase()
{ CALL
  Tuint delta = (ASC('a') - ASC('A'));
  Tuint size = m_Size;
  Tsstr buffer = m_pBuffer;

  while (size-- > 0)
  {
    if ((*buffer >= ASC('A')) && (*buffer <= ASC('Z')))
      *buffer = (Tschar)(*buffer + delta);
    else if ((*buffer >= ASC('a')) && (*buffer <= ASC('z')))
      *buffer = (Tschar)(*buffer - delta);
    ++buffer;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::resize(const Tuint a_cSize, const Tschar a_cValue/* = ASC('\0') */)
{ CALL
  // Clear ASCII string if necessary.
  if (a_cSize == 0)
    return clear();
  // Check if we need buffer reallocation.
  Tuint old_bound = getHiCapacity();
  Tuint new_bound = ((a_cSize >= getLoCapacity()) && (a_cSize <= getHiCapacity())) ? old_bound : (a_cSize + (a_cSize >> 1));
  if ((m_pBuffer == NULL) || (old_bound != new_bound))
  {
    // Create a new ASCII string buffer.
    Tuint old_size = m_Size;
    Tuint new_size = new_bound;
    Tsstr old_buffer = m_pBuffer;
    Tsstr new_buffer = newex Tschar[new_size];
    if (new_buffer != NULL)
    {
      Tuint copy_size = NAlgorithms::NCommon::min(old_size, a_cSize);
      // Copy string characters from the old buffer into the new one.
      NMemory::CMemory::copy(new_buffer, old_buffer, copy_size * sizeof(Tschar));
      // Fill the rest characters with given value.
      NMemory::CMemory::fill(new_buffer + copy_size, (a_cSize - copy_size) * sizeof(Tschar), &a_cValue, sizeof(Tschar));
      // Fill the free characters with 0.
      NMemory::CMemory::fill(new_buffer + a_cSize, (new_size - a_cSize) * sizeof(Tschar), 0);
      // Update ASCII string parameters.
      m_pBuffer = new_buffer;
      m_Size = a_cSize;
      m_HiCapacity = new_bound;

      // Delete old ASCII string buffer.
      if (old_buffer != NULL)
        delete [] old_buffer;
    }
    else
    {
      WARNING(STR("Cannot allocate new string buffer while resizing the ASCII string (requested size is %u bytes).") COMMA (sizeof(Tschar) * new_size));
      return false;
    }
  }
  else
  {
    // Create or destroy ASCII string characters.
    if (m_Size < a_cSize)
      NMemory::CMemory::fill(m_pBuffer + m_Size, (a_cSize - m_Size) * sizeof(Tschar), &a_cValue, sizeof(Tschar));
    else if (m_Size > a_cSize)
      NMemory::CMemory::fill(m_pBuffer + a_cSize, (m_Size - a_cSize) * sizeof(Tschar), 0);
    // Update string size.
    m_Size = a_cSize;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::insertIndex(const Tuint a_cIndex, const Tschar& a_crItem)
{ CALL
  // Check index value and the ASCII string bounds.
  ASSERT((a_cIndex <= m_Size), STR("Cannot insert a new character into the ASCII string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Resize ASCII string to insert character.
  if (resize(m_Size + 1))
  {
    // Shift part of ASCII string to the right.
    NMemory::CMemory::move(m_pBuffer + a_cIndex + 1, m_pBuffer + a_cIndex, (m_Size - a_cIndex - 1) * sizeof(Tschar));
    // Copy character into place under the index.
    m_pBuffer[a_cIndex] = a_crItem;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::insertIndex(const Tuint a_cIndex, const CStringASCII& a_crItem)
{ CALL
  // Check index value and the ASCII string bounds.
  ASSERT((a_cIndex <= m_Size), STR("Cannot insert a new sub-string into the ASCII string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Check for empty sub-string.
  if (a_crItem.isEmpty())
    return true;

  // Resize ASCII string to insert sub-string.
  if (resize(m_Size + a_crItem.getSize()))
  {
    // Shift part of ASCII string to the right.
    NMemory::CMemory::move(m_pBuffer + a_cIndex + a_crItem.getSize(), m_pBuffer + a_cIndex, (m_Size - a_cIndex - a_crItem.getSize()) * sizeof(Tschar));
    // Copy sub-string into place under the index.
    NMemory::CMemory::copy(m_pBuffer + a_cIndex, a_crItem.getBuffer(), a_crItem.getSize() * sizeof(Tschar));
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::removeIndex(const Tuint a_cIndex)
{ CALL
  // Check index value and the ASCII string bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove character from the ASCII string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Shift part of ASCII string to the left.
  NMemory::CMemory::move(m_pBuffer + a_cIndex, m_pBuffer + a_cIndex + 1, (m_Size - a_cIndex - 1) * sizeof(Tschar));
  // Resize ASCII string to remove one character.
  return resize(m_Size - 1);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::removeIndex(const Tuint a_cIndex, Tschar& a_rItem)
{ CALL
  // Check index value and the ASCII string bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove character from the ASCII string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Copy character from the place under the index.
  a_rItem = m_pBuffer[a_cIndex];
  // Shift part of ASCII string to the left.
  NMemory::CMemory::move(m_pBuffer + a_cIndex, m_pBuffer + a_cIndex + 1, (m_Size - a_cIndex - 1) * sizeof(Tschar));
  // Resize ASCII string to remove one character.
  return resize(m_Size - 1);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::removeIndex(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  // Check index value and the ASCII string bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove sub-string from the ASCII string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Check for empty sub-string.
  if (a_cSize == 0)
    return true;

  Tuint size = NAlgorithms::NCommon::min(m_Size - a_cIndex, a_cSize);
  // Shift part of ASCII string to the left.
  NMemory::CMemory::move(m_pBuffer + a_cIndex, m_pBuffer + a_cIndex + size, (m_Size - a_cIndex - size) * sizeof(Tschar));
  // Resize ASCII string to remove sub-string.
  return resize(m_Size - size);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::removeIndex(const Tuint a_cIndex, const Tuint a_cSize, CStringASCII& a_rItem)
{ CALL
  // Check index value and the ASCII string bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove sub-string from the ASCII string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Check for empty sub-string.
  if (a_cSize == 0)
  {
    a_rItem.clear();
    return true;
  }

  Tuint size = NAlgorithms::NCommon::min(m_Size - a_cIndex, a_cSize);
  // Copy sub-string from the place under the index.
  a_rItem.clear();
  a_rItem.set(m_pBuffer + a_cIndex, size);
  // Shift part of ASCII string to the left.
  NMemory::CMemory::move(m_pBuffer + a_cIndex, m_pBuffer + a_cIndex + size, (m_Size - a_cIndex - size) * sizeof(Tschar));
  // Resize ASCII string to remove sub-string.
  return resize(m_Size - size);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::insertCEnd()
{ CALL
  // If current ASCII string is not empty.
  if (!isEmpty())
  {
    // If we have no ASC('\0') at the end of the ASCII string.
    if (m_pBuffer[m_Size - 1] != ASC('\0'))
    {
      // Add one character place for the ASC('\0').
      if (resizeBy(1))
      {
        // Write ASC('\0') at the end of the ASCII string.
        m_pBuffer[m_Size - 1] = ASC('\0');
        return true;
      }
      else
        return false;
    }
    else
      return true;
  }
  else
    return set(ASC('\0'));
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::removeCEnd()
{ CALL
  // If current ASCII string is not empty.
  if (!isEmpty())
  {
    // If we have ASC('\0') at the end of the ASCII string.
    if (m_pBuffer[m_Size - 1] == ASC('\0'))
    {
      // Remove one character place from the end of the ASCII string.
      return (resizeBy(-1));
    }
    else
      return false;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
CStringASCII::TIterator CStringASCII::getItFirst()
{ CALL
  TIterator it_first;

  // Filling iterator inner structure.
  it_first.m_pContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
CStringASCII::TIteratorConst CStringASCII::getItFirst() const
{ CALL
  TIteratorConst it_first;

  // Filling iterator inner structure.
  it_first.m_cpContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
CStringASCII::TIterator CStringASCII::getItLast()
{ CALL
  TIterator it_last;

  // Filling iterator inner structure.
  it_last.m_pContainer = this;
  it_last.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
CStringASCII::TIteratorConst CStringASCII::getItLast() const
{ CALL
  TIteratorConst it_last;

  // Filling iterator inner structure.
  it_last.m_cpContainer = this;
  it_last.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
CStringASCII::TIterator CStringASCII::getItIndex(const Tuint a_cIndex)
{ CALL
  TIterator it_index;

  // Filling iterator inner structure.
  it_index.m_pContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
CStringASCII::TIteratorConst CStringASCII::getItIndex(const Tuint a_cIndex) const
{ CALL
  TIteratorConst it_index;

  // Filling iterator inner structure.
  it_index.m_cpContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
Tsint CStringASCII::compare(const CStringASCII& a_crString1, const CStringASCII& a_crString2)
{ CALL
  Tuint length1 = a_crString1.getSize();
  Tuint length2 = a_crString2.getSize();

  Tcsstr buffer1 = a_crString1.getBuffer();
  Tcsstr buffer2 = a_crString2.getBuffer();
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
Tsint CStringASCII::compareIgnoreCase(const CStringASCII& a_crString1, const CStringASCII& a_crString2)
{ CALL
  Tuint length1 = a_crString1.getSize();
  Tuint length2 = a_crString2.getSize();

  Tcsstr buffer1 = a_crString1.getBuffer();
  Tcsstr buffer2 = a_crString2.getBuffer();
  Tuint length = (length1 < length2) ? length1 : length2;
  Tsint sublength = (Tsint)(length1 - length2);
  Tsint result = 0;

  while ((length > 0) && ((result = (CCharacter(*buffer1++).toLowerCase() - CCharacter(*buffer2++).toLowerCase())) == 0))
    --length;

  if ((sublength == 0) || (length > 0))
    return result;
  else
    return sublength;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::getASCIICharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount)
{ CALL
  return NDetails::CSystemStringHelper::getASCIICharsCount(a_cpBuffer, a_cSize, a_rCount);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::ASCIIToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return NDetails::CSystemStringHelper::ASCIIToUTF8Count(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::UTF8ToASCIICount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return NDetails::CSystemStringHelper::UTF8ToASCIICount(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::ASCIIToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return NDetails::CSystemStringHelper::ASCIIToUTF8(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCII::UTF8ToASCII(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return NDetails::CSystemStringHelper::UTF8ToASCII(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
