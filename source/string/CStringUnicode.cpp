/*!
 *  \file    CStringUnicode.cpp Unicode string class provides base string
 *           functionality in the Unicode encoding.
 *  \brief   Unicode string class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode string class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String
    VERSION:   1.0
    CREATED:   02.08.2008 21:36:34

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
#include <Depth/include/string/CStringUnicode.hpp>
#include <Depth/include/string/details/CSystemStringHelper.hpp>
/*==========================================================================*/
#ifndef __CSTRINGUNICODE_CPP__
#define __CSTRINGUNICODE_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
BASE_API const CStringUnicode CStringUnicode::EMPTY = CStringUnicode();
/*--------------------------------------------------------------------------*/
BASE_API Tbool operator == (const CStringUnicode& a_crInstance1, const CStringUnicode& a_crInstance2)
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
Tbool CStringUnicode::set(const Tschar a_cASCIICharacter, const Tbool a_cAppendZero/* = false */)
{ CALL
  // Clear current Unicode string.
  if (!clear())
    return false;

  // Resize Unicode string to fit the given ASCII character.
  if (resize(a_cAppendZero ? 2 : 1))
  {
    // Copy ASCII character.
    m_pBuffer[0] = (Twchar)((Tscharu)a_cASCIICharacter);
    if (a_cAppendZero)
      m_pBuffer[1] = UNC('\0');
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::set(const Twchar a_cUnicodeCharacter, const Tbool a_cAppendZero/* = false */)
{ CALL
  // Clear current Unicode string.
  if (!clear())
    return false;

  // Resize Unicode string to fit the given Unicode character.
  if (resize(a_cAppendZero ? 2 : 1))
  {
    // Copy Unicode character.
    m_pBuffer[0] = a_cUnicodeCharacter;
    if (a_cAppendZero)
      m_pBuffer[1] = UNC('\0');
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::set(Tcsstr a_cpASCIIString, const Tbool a_cAppendZero/* = false */)
{ CALL
  // Check if the given ASCII 'C' string buffer is not NULL.
  ASSERT((a_cpASCIIString != NULL), STR("Cannot set ASCII 'C' string buffer which is NULL."))
  {
    return false;
  }

  Tuint length = NAlgorithms::NString::NBuffer::strLen(a_cpASCIIString) + (a_cAppendZero ? 1 : 0);

  // Clear current Unicode string.
  if (!clear())
    return false;

  // Resize Unicode string to fit the given ASCII buffer.
  if (resize(length))
  {
    // Copy ASCII buffer.
    for (Tuint i = 0; i < length; ++i)
      m_pBuffer[i] = (Twchar)((Tscharu)a_cpASCIIString[i]);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::set(Tcwstr a_cpUnicodeString, const Tbool a_cAppendZero/* = false */)
{ CALL
  // Check if the given Unicode 'C' string buffer is not NULL.
  ASSERT((a_cpUnicodeString != NULL), STR("Cannot set Unicode 'C' string buffer which is NULL."))
  {
    return false;
  }

  Tuint length = NAlgorithms::NString::NBuffer::strLen(a_cpUnicodeString) + (a_cAppendZero ? 1 : 0);

  // Clear current Unicode string.
  if (!clear())
    return false;

  // Resize Unicode string to fit the given Unicode buffer.
  if (resize(length))
  {
    // Copy Unicode buffer.
    for (Tuint i = 0; i < length; ++i)
      m_pBuffer[i] = a_cpUnicodeString[i];
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::set(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the given ASCII string buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot set ASCII string buffer which is NULL."))
  {
    return false;
  }

  // Clear current Unicode string.
  if (!clear())
    return false;

  // Resize Unicode string to fit the given ASCII buffer.
  if (resize(a_cSize))
  {
    // Copy Unicode buffer.
    for (Tuint i = 0; i < a_cSize; ++i)
      m_pBuffer[i] = (Twchar)((Tscharu)a_cpBuffer[i]);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::set(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the given Unicode string buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot set Unicode string buffer which is NULL."))
  {
    return false;
  }

  // Clear current Unicode string.
  if (!clear())
    return false;

  // Resize Unicode string to fit the given Unicode buffer.
  if (resize(a_cSize))
  {
    // Copy Unicode buffer.
    for (Tuint i = 0; i < a_cSize; ++i)
      m_pBuffer[i] = a_cpBuffer[i];
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::set(const CSystemString& a_crInstance)
{ CALL
  Tuint count = 0;
  Tuint size = 0;

  // Clear current Unicode string.
  if (!clear())
    return false;

  // Get count of system string characters.
  if (!NDetails::CSystemStringHelper::getSystemCharsCount(a_crInstance.m_pBuffer, a_crInstance.m_Size, count))
  {
    WARNING(STR("Cannot get count of system string characters in the given system string. Content of the system string has to be checked."));
    return false;
  }

  // Get size of same string in Unicode encoding in bytes.
  if (!NDetails::CSystemStringHelper::SystemToUnicodeCount(a_crInstance.m_pBuffer, count, size))
  {
    WARNING(STR("Cannot get required buffer size to convert string from system encoding to Unicode one. Content of the system string has to be checked."));
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
      WARNING(STR("Cannot allocate Unicode string buffer (requested size is %u bytes).") COMMA bound);
      return false;
    }

    // Convert system string in Unicode encoding.
    if (!NDetails::CSystemStringHelper::SystemToUnicode(buffer, a_crInstance.m_pBuffer, count, size))
    {
      delete [] buffer;
      WARNING(STR("Cannot convert string from system encoding to Unicode one. Content of the system string has to be checked."));
      return false;
    }

    // Update Unicode string parameters.
    m_pBuffer = (Twstr)buffer;
    m_Size = count;
    m_HiCapacity = bound;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::set(const CStringASCII& a_crInstance)
{ CALL
  // Clear current Unicode string.
  if (!clear())
    return false;

  // Resize Unicode string to fit the given ASCII buffer.
  if (resize(a_crInstance.m_Size))
  {
    // Copy ASCII buffer.
    for (Tuint i = 0; i < a_crInstance.m_Size; ++i)
      m_pBuffer[i] = (Twchar)((Tscharu)a_crInstance.m_pBuffer[i]);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::set(const CStringUnicode& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CStringUnicode class instance."))
  {
    return false;
  }

  // Clear current Unicode string.
  if (!clear())
    return false;

  // Resize Unicode string to fit the given Unicode buffer.
  if (resize(a_crInstance.m_Size))
  {
    // Copy Unicode buffer.
    for (Tuint i = 0; i < a_crInstance.m_Size; ++i)
      m_pBuffer[i] = a_crInstance.m_pBuffer[i];
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::getSystemString(CSystemString& a_rSystemString, const Tbool a_cAppendZero/* = false */) const
{ CALL
  // Clear system string content.
  if (!a_rSystemString.clear())
    return false;

  Tbool add_zero = (a_cAppendZero && (isEmpty() || (m_pBuffer[m_Size - 1] != UNC('\0'))));
  Tuint count = m_Size + (add_zero ? 1 : 0);
  Tuint size = m_Size * sizeof(Twchar);

  // Load the system string content.
  if (size > 0)
  {
    // Get size of same string in system encoding in bytes.
    Tuint str_size = 0;
    if (add_zero)
    {
      Tschar zero = UNC('\0');
      Tuint zero_size;
      if (!NDetails::CSystemStringHelper::UnicodeToSystemCount(m_pBuffer, count - 1, str_size) || !NDetails::CSystemStringHelper::UnicodeToSystemCount(&zero, 1, zero_size))
      {
        WARNING(STR("Cannot get required buffer size to convert string from Unicode encoding to system one. Content of the Unicode string has to be checked."));
        return false;
      }
      str_size += zero_size;
    }
    else
    {
      if (!NDetails::CSystemStringHelper::UnicodeToSystemCount(m_pBuffer, count, str_size))
      {
        WARNING(STR("Cannot get required buffer size to convert string from Unicode encoding to system one. Content of the Unicode string has to be checked."));
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

    // Convert system string from Unicode encoding.
    if (add_zero)
    {
      Tschar zero = UNC('\0');
      Tuint zero_size;
      if (!NDetails::CSystemStringHelper::UnicodeToSystem(str_buffer, m_pBuffer, count - 1, str_size) || !NDetails::CSystemStringHelper::UnicodeToSystem(str_buffer + str_size, &zero, 1, zero_size))
      {
        delete [] str_buffer;
        WARNING(STR("Cannot convert string from Unicode encoding to system one. Content of the Unicode string has to be checked."));
        return false;
      }
      str_size += zero_size;
    }
    else
    {
      if (!NDetails::CSystemStringHelper::UnicodeToSystem(str_buffer, m_pBuffer, count, str_size))
      {
        delete [] str_buffer;
        WARNING(STR("Cannot convert string from Unicode encoding to system one. Content of the Unicode string has to be checked."));
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
CStringUnicode CStringUnicode::getLeft(const Tuint a_cSize) const
{ CALL
  return CStringUnicode(m_pBuffer, NAlgorithms::NCommon::min(m_Size, a_cSize));
}
/*--------------------------------------------------------------------------*/
CStringUnicode CStringUnicode::getRight(const Tuint a_cSize) const
{ CALL
  return CStringUnicode(m_pBuffer + ((m_Size > a_cSize) ? (m_Size - a_cSize) : 0), NAlgorithms::NCommon::min(m_Size, a_cSize));
}
/*--------------------------------------------------------------------------*/
CStringUnicode CStringUnicode::getMiddle(const Tuint a_cIndex, const Tuint a_cSize) const
{ CALL
  // Check index value and the Unicode string bounds.
  ASSERT((a_cIndex <= m_Size), STR("Cannot get middle sub-string from the Unicode string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return CStringUnicode::EMPTY;
  }

  return CStringUnicode(m_pBuffer + a_cIndex, NAlgorithms::NCommon::min(m_Size - a_cIndex, a_cSize));
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::clear()
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
void CStringUnicode::reverse()
{ CALL
  Twstr left = m_pBuffer;
  Twstr right = m_pBuffer + m_Size - 1;

  while (left < right)
    NAlgorithms::NCommon::swap(*(left++), *(right--));
}
/*--------------------------------------------------------------------------*/
void CStringUnicode::toLowerCase()
{ CALL
  Tuint size = m_Size;
  Twstr buffer = m_pBuffer;

  while (size-- > 0)
  {
    *buffer = CCharacter(*buffer).toLowerCase();
    ++buffer;
  }
}
/*--------------------------------------------------------------------------*/
void CStringUnicode::toUpperCase()
{ CALL
  Tuint size = m_Size;
  Twstr buffer = m_pBuffer;

  while (size-- > 0)
  {
    *buffer = CCharacter(*buffer).toUpperCase();
    ++buffer;
  }
}
/*--------------------------------------------------------------------------*/
void CStringUnicode::toTitleCase()
{ CALL
  Tuint size = m_Size;
  Twstr buffer = m_pBuffer;

  while (size-- > 0)
  {
    *buffer = CCharacter(*buffer).toTitleCase();
    ++buffer;
  }
}
/*--------------------------------------------------------------------------*/
void CStringUnicode::toToggleCase()
{ CALL
  Tuint size = m_Size;
  Twstr buffer = m_pBuffer;

  while (size-- > 0)
  {
    *buffer = CCharacter(*buffer).toToggleCase();
    ++buffer;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::resize(const Tuint a_cSize, const Twchar a_cValue/* = UNC('\0') */)
{ CALL
  // Clear Unicode string if necessary.
  if (a_cSize == 0)
    return clear();
  // Check if we need buffer reallocation.
  Tuint old_bound = getHiCapacity();
  Tuint new_bound = ((a_cSize >= getLoCapacity()) && (a_cSize <= getHiCapacity())) ? old_bound : (a_cSize + (a_cSize >> 1));
  if ((m_pBuffer == NULL) || (old_bound != new_bound))
  {
    // Create a new Unicode string buffer.
    Tuint old_size = m_Size;
    Tuint new_size = new_bound;
    Twstr old_buffer = m_pBuffer;
    Twstr new_buffer = newex Twchar[new_size];
    if (new_buffer != NULL)
    {
      Tuint copy_size = NAlgorithms::NCommon::min(old_size, a_cSize);
      // Copy string characters from the old buffer into the new one.
      NMemory::CMemory::copy(new_buffer, old_buffer, copy_size * sizeof(Twchar));
      // Fill the rest characters with given value.
      NMemory::CMemory::fill(new_buffer + copy_size, (a_cSize - copy_size) * sizeof(Twchar), &a_cValue, sizeof(Twchar));
      // Fill the free characters with 0.
      NMemory::CMemory::fill(new_buffer + a_cSize, (new_size - a_cSize) * sizeof(Twchar), 0);
      // Update Unicode string parameters.
      m_pBuffer = new_buffer;
      m_Size = a_cSize;
      m_HiCapacity = new_bound;

      // Delete old Unicode string buffer.
      if (old_buffer != NULL)
        delete [] old_buffer;
    }
    else
    {
      WARNING(STR("Cannot allocate new string buffer while resizing the Unicode string (requested size is %u bytes).") COMMA (sizeof(Twchar) * new_size));
      return false;
    }
  }
  else
  {
    // Create or destroy Unicode string characters.
    if (m_Size < a_cSize)
      NMemory::CMemory::fill(m_pBuffer + m_Size, (a_cSize - m_Size) * sizeof(Twchar), &a_cValue, sizeof(Twchar));
    else if (m_Size > a_cSize)
      NMemory::CMemory::fill(m_pBuffer + a_cSize, (m_Size - a_cSize) * sizeof(Twchar), 0);
    // Update string size.
    m_Size = a_cSize;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::insertIndex(const Tuint a_cIndex, const Twchar& a_crItem)
{ CALL
  // Check index value and the Unicode string bounds.
  ASSERT((a_cIndex <= m_Size), STR("Cannot insert a new character into the Unicode string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Resize Unicode string to insert character.
  if (resize(m_Size + 1))
  {
    // Shift part of Unicode string to the right.
    NMemory::CMemory::move(m_pBuffer + a_cIndex + 1, m_pBuffer + a_cIndex, (m_Size - a_cIndex - 1) * sizeof(Twchar));
    // Copy character into place under the index.
    m_pBuffer[a_cIndex] = a_crItem;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::insertIndex(const Tuint a_cIndex, const CStringUnicode& a_crItem)
{ CALL
  // Check index value and the Unicode string bounds.
  ASSERT((a_cIndex <= m_Size), STR("Cannot insert a new sub-string into the Unicode string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Check for empty sub-string.
  if (a_crItem.isEmpty())
    return true;

  // Resize Unicode string to insert sub-string.
  if (resize(m_Size + a_crItem.getSize()))
  {
    // Shift part of Unicode string to the right.
    NMemory::CMemory::move(m_pBuffer + a_cIndex + a_crItem.getSize(), m_pBuffer + a_cIndex, (m_Size - a_cIndex - a_crItem.getSize()) * sizeof(Twchar));
    // Copy sub-string into place under the index.
    NMemory::CMemory::copy(m_pBuffer + a_cIndex, a_crItem.getBuffer(), a_crItem.getSize() * sizeof(Twchar));
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::removeIndex(const Tuint a_cIndex)
{ CALL
  // Check index value and the Unicode string bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove character from the Unicode string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Shift part of Unicode string to the left.
  NMemory::CMemory::move(m_pBuffer + a_cIndex, m_pBuffer + a_cIndex + 1, (m_Size - a_cIndex - 1) * sizeof(Twchar));
  // Resize Unicode string to remove one character.
  return resize(m_Size - 1);
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::removeIndex(const Tuint a_cIndex, Twchar& a_rItem)
{ CALL
  // Check index value and the Unicode string bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove character from the Unicode string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Copy character from the place under the index.
  a_rItem = m_pBuffer[a_cIndex];
  // Shift part of Unicode string to the left.
  NMemory::CMemory::move(m_pBuffer + a_cIndex, m_pBuffer + a_cIndex + 1, (m_Size - a_cIndex - 1) * sizeof(Twchar));
  // Resize Unicode string to remove one character.
  return resize(m_Size - 1);
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::removeIndex(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  // Check index value and the Unicode string bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove sub-string from the Unicode string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Check for empty sub-string.
  if (a_cSize == 0)
    return true;

  Tuint size = NAlgorithms::NCommon::min(m_Size - a_cIndex, a_cSize);
  // Shift part of Unicode string to the left.
  NMemory::CMemory::move(m_pBuffer + a_cIndex, m_pBuffer + a_cIndex + size, (m_Size - a_cIndex - size) * sizeof(Twchar));
  // Resize Unicode string to remove sub-string.
  return resize(m_Size - size);
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::removeIndex(const Tuint a_cIndex, const Tuint a_cSize, CStringUnicode& a_rItem)
{ CALL
  // Check index value and the Unicode string bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove sub-string from the Unicode string with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
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
  // Shift part of Unicode string to the left.
  NMemory::CMemory::move(m_pBuffer + a_cIndex, m_pBuffer + a_cIndex + size, (m_Size - a_cIndex - size) * sizeof(Twchar));
  // Resize Unicode string to remove sub-string.
  return resize(m_Size - size);
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::insertCEnd()
{ CALL
  // If current Unicode string is not empty.
  if (!isEmpty())
  {
    // If we have no UNC('\0') at the end of the Unicode string.
    if (m_pBuffer[m_Size - 1] != UNC('\0'))
    {
      // Add one character place for the UNC('\0').
      if (resizeBy(1))
      {
        // Write UNC('\0') at the end of the Unicode string.
        m_pBuffer[m_Size - 1] = UNC('\0');
        return true;
      }
      else
        return false;
    }
    else
      return true;
  }
  else
    return set(UNC('\0'));
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::removeCEnd()
{ CALL
  // If current Unicode string is not empty.
  if (!isEmpty())
  {
    // If we have UNC('\0') at the end of the Unicode string.
    if (m_pBuffer[m_Size - 1] == UNC('\0'))
    {
      // Remove one character place from the end of the Unicode string.
      return (resizeBy(-1));
    }
    else
      return false;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
CStringUnicode::TIterator CStringUnicode::getItFirst()
{ CALL
  TIterator it_first;

  // Filling iterator inner structure.
  it_first.m_pContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
CStringUnicode::TIteratorConst CStringUnicode::getItFirst() const
{ CALL
  TIteratorConst it_first;

  // Filling iterator inner structure.
  it_first.m_cpContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
CStringUnicode::TIterator CStringUnicode::getItLast()
{ CALL
  TIterator it_last;

  // Filling iterator inner structure.
  it_last.m_pContainer = this;
  it_last.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
CStringUnicode::TIteratorConst CStringUnicode::getItLast() const
{ CALL
  TIteratorConst it_last;

  // Filling iterator inner structure.
  it_last.m_cpContainer = this;
  it_last.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
CStringUnicode::TIterator CStringUnicode::getItIndex(const Tuint a_cIndex)
{ CALL
  TIterator it_index;

  // Filling iterator inner structure.
  it_index.m_pContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
CStringUnicode::TIteratorConst CStringUnicode::getItIndex(const Tuint a_cIndex) const
{ CALL
  TIteratorConst it_index;

  // Filling iterator inner structure.
  it_index.m_cpContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
Tsint CStringUnicode::compare(const CStringUnicode& a_crString1, const CStringUnicode& a_crString2)
{ CALL
  Tuint length1 = a_crString1.getSize();
  Tuint length2 = a_crString2.getSize();

  Tcwstr buffer1 = a_crString1.getBuffer();
  Tcwstr buffer2 = a_crString2.getBuffer();
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
Tsint CStringUnicode::compareIgnoreCase(const CStringUnicode& a_crString1, const CStringUnicode& a_crString2)
{ CALL
  Tuint length1 = a_crString1.getSize();
  Tuint length2 = a_crString2.getSize();

  Tcwstr buffer1 = a_crString1.getBuffer();
  Tcwstr buffer2 = a_crString2.getBuffer();
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
Tbool CStringUnicode::getUnicodeCharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount)
{ CALL
  return NDetails::CSystemStringHelper::getUnicodeCharsCount(a_cpBuffer, a_cSize, a_rCount);
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::UnicodeToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return NDetails::CSystemStringHelper::UnicodeToUTF8Count(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::UTF8ToUnicodeCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return NDetails::CSystemStringHelper::UTF8ToUnicodeCount(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::UnicodeToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return NDetails::CSystemStringHelper::UnicodeToUTF8(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
Tbool CStringUnicode::UTF8ToUnicode(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return NDetails::CSystemStringHelper::UTF8ToUnicode(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
