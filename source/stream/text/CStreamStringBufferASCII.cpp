/*!
 *  \file    CStreamStringBufferASCII.cpp ASCII string buffer stream class
 *           gives ability to read/write byte sequences from/into the fixed
 *           ASCII string buffer.
 *  \brief   ASCII string buffer stream class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: ASCII string buffer stream class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   26.09.2008 22:11:22

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
#include <Depth/include/stream/text/CStreamStringBufferASCII.hpp>
#include <Depth/include/string/CCharacter.hpp>
/*==========================================================================*/
#ifndef __CSTREAMSTRINGBUFFERASCII_CPP__
#define __CSTREAMSTRINGBUFFERASCII_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NText {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CStreamStringBufferASCII::set(Tsstr a_pASCIIString)
{ CALL
  // Check if the given ASCII 'C' string buffer is not NULL.
  ASSERT((a_pASCIIString != NULL), STR("Cannot set ASCII 'C' string buffer which is NULL."))
  {
    return false;
  }

  // Close opened ASCII string buffer stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize ASCII string buffer.
  m_pBuffer = a_pASCIIString;
  m_Size = NAlgorithms::NString::NBuffer::strLen(a_pASCIIString);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CStreamStringBufferASCII::set(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the given ASCII buffer is not NULL.
  ASSERT((a_pBuffer != NULL), STR("Cannot set ASCII buffer which is NULL."))
  {
    return false;
  }

  // Close opened ASCII string buffer stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize ASCII string buffer.
  m_pBuffer = a_pBuffer;
  m_Size = a_cSize;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CStreamStringBufferASCII::set(const CStreamStringBufferASCII& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CStreamStringBufferASCII class instance."))
  {
    return false;
  }

  // Close opened ASCII string buffer stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize new reader & writer.
  if (!IReaderWriter::set(a_crInstance))
    return false;

  // Initialize ASCII string buffer.
  m_pBuffer = a_crInstance.m_pBuffer;
  m_Size = a_crInstance.m_Size;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CStreamStringBufferASCII::setPosition(const Tuint a_cPosition)
{ CALL
  // Check if the current stream is opened.
  ASSERT(isOpened(), STR("Cannot set position of the closed ASCII string buffer stream."))
  {
    return false;
  }
  // Check position value and the buffer bounds.
  ASSERT(((a_cPosition < m_Size) || (a_cPosition == 0)), STR("Cannot set position with the out of bounds index (index = %u, size = %u).") COMMA a_cPosition COMMA m_Size)
  {
    return false;
  }

  m_Index = a_cPosition;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringBufferASCII::getPosition() const
{ CALL
  // Check if the current stream is opened.
  ASSERT(isOpened(), STR("Cannot get position of the closed ASCII string buffer stream."))
  {
    return 0;
  }

  return m_Index;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringBufferASCII::onReadBinary(Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onReadText((Tsstr)a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringBufferASCII::onReadText(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Copy ASCII characters from the ASCII string buffer.
  Tuint size = NAlgorithms::NCommon::min(m_Size - m_Index, a_cSize);

  Tuint counter = size;
  Tsstr dst_buffer = a_pBuffer;
  Tcsstr src_buffer = m_pBuffer + m_Index;
  while (counter-- > 0)
    *dst_buffer++ = (Tschar)((Tscharu)(*src_buffer++));

  m_Index += size;
  // Check 'end of file' state.
  if (m_Index >= m_Size)
    IReader::setEOF();
  return size;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringBufferASCII::onReadText(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Copy Unicode characters from the ASCII string buffer.
  Tuint size = NAlgorithms::NCommon::min(m_Size - m_Index, a_cSize);

  Tuint counter = size;
  Twstr dst_buffer = a_pBuffer;
  Tcsstr src_buffer = m_pBuffer + m_Index;
  while (counter-- > 0)
    *dst_buffer++ = (Twchar)((Tscharu)(*src_buffer++));

  m_Index += size;
  // Check 'end of file' state.
  if (m_Index >= m_Size)
    IReader::setEOF();
  return size;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringBufferASCII::onWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return onWriteText((Tcsstr)a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringBufferASCII::onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Copy ASCII characters into the ASCII string buffer.
  Tuint counter = NAlgorithms::NCommon::min(m_Size - m_Index, a_cSize);
  Tsstr dst_buffer = m_pBuffer + m_Index;
  Tcsstr src_buffer = a_cpBuffer;
  while (counter-- > 0)
    *dst_buffer++ = (Tschar)((Tscharu)(*src_buffer++));

  m_Index += a_cSize;
  // Check 'end of file' state.
  if (m_Index >= m_Size)
    IWriter::setEOF();
  return a_cSize;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringBufferASCII::onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if all Unicode characters from the given buffer fits ASCII bounds.
  for (Tuint i = 0; i < a_cSize; ++i)
  {
    ASSERT(NString::CCharacter(a_cpBuffer[i]).isValidASCII(), STR("Cannot write Unicode character which does not fit ASCII bounds (character code is %hU).") COMMA (Tuint)a_cpBuffer[i])
    {
      return 0;
    }
  }

  // Copy Unicode characters into the ASCII string buffer.
  Tuint counter = NAlgorithms::NCommon::min(m_Size - m_Index, a_cSize);
  Tsstr dst_buffer = m_pBuffer + m_Index;
  Tcwstr src_buffer = a_cpBuffer;
  while (counter-- > 0)
    *dst_buffer++ = (Tschar)((Twcharu)(*src_buffer++));

  m_Index += a_cSize;
  // Check 'end of file' state.
  if (m_Index >= m_Size)
    IWriter::setEOF();
  return a_cSize;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
