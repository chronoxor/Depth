/*!
 *  \file    CBuffer.cpp Byte buffer container class provides random access
 *           to the static/dynamic byte buffer.
 *  \brief   Byte buffer container class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Byte buffer container class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   20.08.2008 23:35:51

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
#include <Depth/include/memory/CMemory.hpp>
#include <Depth/include/utility/CBuffer.hpp>
/*==========================================================================*/
#ifndef __CBUFFER_CPP__
#define __CBUFFER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CBuffer::set(const Tuint a_cSize, const Tbool a_cStatic/* = false */)
{ CALL
  // Clear current byte buffer.
  if (!clear())
    return false;

  // Set the dynamic and local flags.
  m_IsDynamic = !a_cStatic;
  m_IsLocal = true;

  // Resize byte buffer.
  return resize(a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CBuffer::set(Tcbuffer a_cpBuffer, const Tuint a_cSize, const Tbool a_cStatic/* = false */)
{ CALL
  // Check if the given byte buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot set byte buffer which is NULL."))
  {
    return false;
  }

  // Clear current byte buffer.
  if (!clear())
    return false;

  // Set the dynamic and local flags.
  m_IsDynamic = !a_cStatic;
  m_IsLocal = true;

  // Resize byte buffer to fit the given buffer.
  if (resize(a_cSize))
  {
    // Copy byte buffer.
    NMemory::CMemory::copy(m_pBuffer, a_cpBuffer, a_cSize);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CBuffer::set(Tbuffer a_pBuffer, const Tuint a_cSize, const Tbool a_cStatic/* = true */)
{ CALL
  // Check if the given byte buffer is not NULL.
  ASSERT((a_pBuffer != NULL), STR("Cannot set byte buffer which is NULL."))
  {
    return false;
  }

  // Clear current byte buffer.
  if (!clear())
    return false;

  // Set the dynamic and local flags.
  m_IsDynamic = !a_cStatic;
  m_IsLocal = !a_cStatic;

  if (isLocal())
  {
    // Resize byte buffer to fit the given buffer.
    if (resize(a_cSize))
    {
      // Copy byte buffer.
      NMemory::CMemory::copy(m_pBuffer, a_pBuffer, a_cSize);
      return true;
    }
    else
      return false;
  }
  else
  {
    // Set static byte buffer.
    m_Size = a_cSize;
    m_HiCapacity = a_cSize;
    m_pBuffer = a_pBuffer;
    return true;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CBuffer::set(const CBuffer& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CBuffer class instance."))
  {
    return false;
  }

  // Clear current byte buffer.
  if (!clear())
    return false;

  // Set the dynamic and local flags.
  m_IsDynamic = a_crInstance.m_IsDynamic;
  m_IsLocal = a_crInstance.m_IsLocal;

  if (isLocal())
  {
    // Resize byte buffer to fit the given buffer.
    if (resize(a_crInstance.m_Size))
    {
      // Copy byte buffer.
      NMemory::CMemory::copy(m_pBuffer, a_crInstance.m_pBuffer, a_crInstance.m_Size);
      return true;
    }
    else
      return false;
  }
  else
  {
    // Set static byte buffer.
    m_Size = a_crInstance.m_Size;
    m_HiCapacity = a_crInstance.m_HiCapacity;
    m_pBuffer = a_crInstance.m_pBuffer;
    return true;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CBuffer::clear()
{ CALL
  if (isLocal())
  {
    // Delete byte buffer.
    if (m_pBuffer != NULL)
      delete [] m_pBuffer;
  }

  // Update byte buffer attributes.
  m_Size = 0;
  m_HiCapacity = 0;
  m_pBuffer = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CBuffer::resize(const Tuint a_cSize, const Tbyte a_cValue/* = 0 */)
{ CALL
  // Check if the byte buffer is local.
  ASSERT(isLocal(), STR("Cannot resize static byte buffer."))
  {
    return false;
  }

  // Clear byte buffer if necessary.
  if (a_cSize == 0)
    return clear();
  // Check if we need buffer reallocation.
  Tuint old_bound = getHiCapacity();
  Tuint new_bound = ((a_cSize >= getLoCapacity()) && (a_cSize <= getHiCapacity())) ? old_bound : (a_cSize + (a_cSize >> 1));
  if ((m_pBuffer == NULL) || (old_bound != new_bound))
  {
    // Create a new byte buffer.
    Tuint old_size = m_Size;
    Tuint new_size = new_bound;
    Tbuffer old_buffer = m_pBuffer;
    Tbuffer new_buffer = newex Tbyte[new_size];
    if (new_buffer != NULL)
    {
      Tuint copy_size = NAlgorithms::NCommon::min(old_size, a_cSize);
      // Copy bytes from the old buffer into the new one.
      NMemory::CMemory::copy(new_buffer, old_buffer, copy_size);
      // Fill the rest bytes with given value.
      NMemory::CMemory::fill(new_buffer + copy_size, a_cSize - copy_size, a_cValue);
      // Fill the free bytes with 0.
      NMemory::CMemory::fill(new_buffer + a_cSize, new_size - a_cSize, 0);
      // Update byte buffer parameters.
      m_pBuffer = new_buffer;
      m_Size = a_cSize;
      m_HiCapacity = new_bound;

      // Delete old byte buffer.
      if (old_buffer != NULL)
        delete [] old_buffer;
    }
    else
    {
      WARNING(STR("Cannot allocate new buffer while resizing the byte buffer (requested size is %u bytes).") COMMA new_size);
      return false;
    }
  }
  else
  {
    // Create or destroy buffer's bytes.
    if (m_Size < a_cSize)
      NMemory::CMemory::fill(m_pBuffer + m_Size, a_cSize - m_Size, a_cValue);
    else if (m_Size > a_cSize)
      NMemory::CMemory::fill(m_pBuffer + a_cSize, m_Size - a_cSize, 0);
    // Update byte buffer size.
    m_Size = a_cSize;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CBuffer::insertIndex(const Tuint a_cIndex, const Tbyte& a_crItem)
{ CALL
  // Check if the byte buffer is dynamic.
  ASSERT(isDynamic(), STR("Cannot insert a new byte into the static byte buffer."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT((a_cIndex <= m_Size), STR("Cannot insert a new byte into the byte buffer with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Resize byte buffer to insert byte.
  if (resize(m_Size + 1))
  {
    // Shift part of byte buffer to the right.
    NMemory::CMemory::move(m_pBuffer + a_cIndex + 1, m_pBuffer + a_cIndex, m_Size - a_cIndex - 1);
    // Copy byte into place under the index.
    m_pBuffer[a_cIndex] = a_crItem;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CBuffer::insertIndex(const Tuint a_cIndex, const CBuffer& a_crItem)
{ CALL
  // Check if the byte buffer is dynamic.
  ASSERT(isDynamic(), STR("Cannot insert a new buffer into the static byte buffer."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT((a_cIndex <= m_Size), STR("Cannot insert a new buffer into the byte buffer with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Check for empty byte buffer.
  if (a_crItem.isEmpty())
    return true;

  // Resize byte buffer to insert buffer.
  if (resize(m_Size + a_crItem.getSize()))
  {
    // Shift part of byte buffer to the right.
    NMemory::CMemory::move(m_pBuffer + a_cIndex + a_crItem.getSize(), m_pBuffer + a_cIndex, m_Size - a_cIndex - a_crItem.getSize());
    // Copy buffer into place under the index.
    NMemory::CMemory::copy(m_pBuffer + a_cIndex, a_crItem.getBuffer(), a_crItem.getSize());
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CBuffer::removeIndex(const Tuint a_cIndex)
{ CALL
  // Check if the byte buffer is dynamic.
  ASSERT(isDynamic(), STR("Cannot remove byte from the static byte buffer."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove byte from the byte buffer with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Shift part of byte buffer to the left.
  NMemory::CMemory::move(m_pBuffer + a_cIndex, m_pBuffer + a_cIndex + 1, m_Size - a_cIndex - 1);
  // Resize byte buffer to remove one byte.
  return resize(m_Size - 1);
}
/*--------------------------------------------------------------------------*/
Tbool CBuffer::removeIndex(const Tuint a_cIndex, Tbyte& a_rItem)
{ CALL
  // Check if the byte buffer is dynamic.
  ASSERT(isDynamic(), STR("Cannot remove byte from the static byte buffer."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove byte from the byte buffer with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Copy byte from the place under the index.
  a_rItem = m_pBuffer[a_cIndex];
  // Shift part of byte buffer to the left.
  NMemory::CMemory::move(m_pBuffer + a_cIndex, m_pBuffer + a_cIndex + 1, m_Size - a_cIndex - 1);
  // Resize byte buffer to remove one byte.
  return resize(m_Size - 1);
}
/*--------------------------------------------------------------------------*/
Tbool CBuffer::removeIndex(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  // Check if the byte buffer is dynamic.
  ASSERT(isDynamic(), STR("Cannot remove buffer from the static byte buffer."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove buffer from the byte buffer with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Check for empty byte buffer.
  if (a_cSize == 0)
    return true;

  Tuint size = NAlgorithms::NCommon::min(m_Size - a_cIndex, a_cSize);
  // Shift part of byte buffer to the left.
  NMemory::CMemory::move(m_pBuffer + a_cIndex, m_pBuffer + a_cIndex + size, m_Size - a_cIndex - size);
  // Resize byte buffer to remove buffer.
  return resize(m_Size - size);
}
/*--------------------------------------------------------------------------*/
Tbool CBuffer::removeIndex(const Tuint a_cIndex, const Tuint a_cSize, CBuffer& a_rItem)
{ CALL
  // Check if the byte buffer is dynamic.
  ASSERT(isDynamic(), STR("Cannot remove buffer from the static byte buffer."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot remove buffer from the byte buffer with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_Size)
  {
    return false;
  }

  // Check for empty byte buffer.
  if (a_cSize == 0)
  {
    a_rItem.clear();
    return true;
  }

  Tuint size = NAlgorithms::NCommon::min(m_Size - a_cIndex, a_cSize);
  // Copy buffer from the place under the index.
  a_rItem.clear();
  a_rItem.set(m_pBuffer + a_cIndex, size, false);
  // Shift part of byte buffer to the left.
  NMemory::CMemory::move(m_pBuffer + a_cIndex, m_pBuffer + a_cIndex + size, m_Size - a_cIndex - size);
  // Resize byte buffer to remove buffer.
  return resize(m_Size - size);
}
/*--------------------------------------------------------------------------*/
CBuffer::TIterator CBuffer::getItFirst()
{ CALL
  TIterator it_first;

  // Filling iterator inner structure.
  it_first.m_pContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
CBuffer::TIteratorConst CBuffer::getItFirst() const
{ CALL
  TIteratorConst it_first;

  // Filling iterator inner structure.
  it_first.m_cpContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
CBuffer::TIterator CBuffer::getItLast()
{ CALL
  TIterator it_last;

  // Filling iterator inner structure.
  it_last.m_pContainer = this;
  it_last.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
CBuffer::TIteratorConst CBuffer::getItLast() const
{ CALL
  TIteratorConst it_last;

  // Filling iterator inner structure.
  it_last.m_cpContainer = this;
  it_last.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
CBuffer::TIterator CBuffer::getItIndex(const Tuint a_cIndex)
{ CALL
  TIterator it_index;

  // Filling iterator inner structure.
  it_index.m_pContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
CBuffer::TIteratorConst CBuffer::getItIndex(const Tuint a_cIndex) const
{ CALL
  TIteratorConst it_index;

  // Filling iterator inner structure.
  it_index.m_cpContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
