/*!
 *  \file    CStreamBuffer.cpp Byte buffer stream class gives ability to
 *           read/write byte sequences from/into the static or dynamic
 *           byte buffer.
 *  \brief   Byte buffer stream class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Byte buffer stream class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   20.08.2008 20:58:46

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
#include <Depth/include/stream/CStreamBuffer.hpp>
/*==========================================================================*/
#ifndef __CSTREAMBUFFER_CPP__
#define __CSTREAMBUFFER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CStreamBuffer::set(const Tuint a_cSize, const Tbool a_cStatic/* = false */)
{ CALL
  // Close opened buffer stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize byte buffer.
  m_Index = 0;
  return CBuffer::set(a_cSize, a_cStatic);
}
/*--------------------------------------------------------------------------*/
Tbool CStreamBuffer::set(Tcbuffer a_cpBuffer, const Tuint a_cSize, const Tbool a_cStatic/* = false */)
{ CALL
  // Close opened buffer stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize byte buffer.
  m_Index = 0;
  return CBuffer::set(a_cpBuffer, a_cSize, a_cStatic);
}
/*--------------------------------------------------------------------------*/
Tbool CStreamBuffer::set(Tbuffer a_pBuffer, const Tuint a_cSize, const Tbool a_cStatic/* = true */)
{ CALL
  // Close opened buffer stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize byte buffer.
  return CBuffer::set(a_pBuffer, a_cSize, a_cStatic);
}
/*--------------------------------------------------------------------------*/
Tbool CStreamBuffer::set(const NUtility::CBuffer& a_crBuffer)
{ CALL
  // Close opened buffer stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize byte buffer.
  return CBuffer::set(a_crBuffer);
}
/*--------------------------------------------------------------------------*/
Tbool CStreamBuffer::set(const CStreamBuffer& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CStreamBuffer class instance."))
  {
    return false;
  }

  // Close opened buffer stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize base reader & writer interface.
  if (!IReaderWriter::set(a_crInstance))
    return false;

  // Initialize byte buffer.
  return CBuffer::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tbool CStreamBuffer::setPosition(const Tuint a_cPosition)
{ CALL
  // Check if the current stream is opened.
  ASSERT(isOpened(), STR("Cannot set position of the closed buffer stream."))
  {
    return false;
  }
  // Check position value and the buffer bounds.
  ASSERT(((a_cPosition < CBuffer::getSize()) || (a_cPosition == 0)), STR("Cannot set position with the out of bounds index (index = %u, size = %u).") COMMA a_cPosition COMMA CBuffer::getSize())
  {
    return false;
  }

  m_Index = a_cPosition;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamBuffer::getPosition() const
{ CALL
  // Check if the current stream is opened.
  ASSERT(isOpened(), STR("Cannot get position of the closed buffer stream."))
  {
    return 0;
  }

  return m_Index;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamBuffer::onReadBinary(Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Copy bytes from the byte buffer.
  Tuint size = NAlgorithms::NCommon::min(CBuffer::getSize() - m_Index, a_cSize);
  NMemory::CMemory::copy(a_pBuffer, CBuffer::getBuffer() + m_Index, size);
  m_Index += size;
  // Check 'end of file' state.
  if (m_Index >= CBuffer::getSize())
    IReader::setEOF();
  return size;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamBuffer::onWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  if (CBuffer::isDynamic())
  {
    // Check it we need to resize the byte buffer.
    if (a_cSize > (CBuffer::getSize() - m_Index))
      if (!CBuffer::resize(a_cSize + m_Index))
        return 0;

    // Shift part of byte buffer to the right.
    NMemory::CMemory::move(CBuffer::getBuffer() + m_Index + a_cSize, CBuffer::getBuffer() + m_Index, CBuffer::getSize() - m_Index - a_cSize);
    // Copy bytes into the byte buffer.
    NMemory::CMemory::copy(CBuffer::getBuffer() + m_Index, a_cpBuffer, a_cSize);
    m_Index += a_cSize;
    return a_cSize;
  }
  else
  {
    // Copy bytes into the byte buffer.
    Tuint size = NAlgorithms::NCommon::min(CBuffer::getSize() - m_Index, a_cSize);
    NMemory::CMemory::copy(CBuffer::getBuffer() + m_Index, a_cpBuffer, size);
    m_Index += size;
    // Check 'end of file' state.
    if (m_Index >= CBuffer::getSize())
      IWriter::setEOF();
    return size;
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
