/*!
 *  \file    CStreamStringBufferUnicodeConst.cpp Constant Unicode string
 *           buffer stream class gives ability to read byte sequences from
 *           the fixed Unicode string buffer.
 *  \brief   Constant Unicode string buffer stream class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant Unicode string buffer stream class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   26.09.2008 00:04:17

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
#include <Depth/include/stream/text/CStreamStringBufferUnicodeConst.hpp>
#include <Depth/include/string/CCharacter.hpp>
/*==========================================================================*/
#ifndef __CSTREAMSTRINGBUFFERUNICODECONST_CPP__
#define __CSTREAMSTRINGBUFFERUNICODECONST_CPP__
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
Tbool CStreamStringBufferUnicodeConst::set(Tcwstr a_cpUnicodeString)
{ CALL
  // Check if the given Unicode 'C' string buffer is not NULL.
  ASSERT((a_cpUnicodeString != NULL), STR("Cannot set Unicode 'C' string buffer which is NULL."))
  {
    return false;
  }

  // Close opened constant Unicode string buffer stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize constant Unicode string buffer.
  m_cpBuffer = a_cpUnicodeString;
  m_Size = NAlgorithms::NString::NBuffer::strLen(a_cpUnicodeString);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CStreamStringBufferUnicodeConst::set(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the given Unicode buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot set Unicode buffer which is NULL."))
  {
    return false;
  }

  // Close opened constant Unicode string buffer stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize constant Unicode string buffer.
  m_cpBuffer = a_cpBuffer;
  m_Size = a_cSize;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CStreamStringBufferUnicodeConst::set(const CStreamStringBufferUnicodeConst& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CStreamStringBufferUnicodeConst class instance."))
  {
    return false;
  }

  // Close opened constant Unicode string buffer stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize new reader.
  if (!IReader::set(a_crInstance))
    return false;

  // Initialize constant Unicode string buffer.
  m_cpBuffer = a_crInstance.m_cpBuffer;
  m_Size = a_crInstance.m_Size;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CStreamStringBufferUnicodeConst::setPosition(const Tuint a_cPosition)
{ CALL
  // Check if the current stream is opened.
  ASSERT(isOpened(), STR("Cannot set position of the closed constant Unicode string buffer stream."))
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
Tuint CStreamStringBufferUnicodeConst::getPosition() const
{ CALL
  // Check if the current stream is opened.
  ASSERT(isOpened(), STR("Cannot get position of the closed constant Unicode string buffer stream."))
  {
    return 0;
  }

  return m_Index;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringBufferUnicodeConst::onReadBinary(Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onReadText((Tsstr)a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringBufferUnicodeConst::onReadText(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Copy Unicode characters from the constant Unicode string buffer.
  Tuint size = NAlgorithms::NCommon::min(m_Size - m_Index, a_cSize);

  Tuint counter = size;
  Tsstr dst_buffer = a_pBuffer;
  Tcwstr src_buffer = m_cpBuffer + m_Index;
  while (counter-- > 0)
  {
    ASSERT(NString::CCharacter(*src_buffer).isValidASCII(), STR("Cannot read Unicode character which does not fit ASCII bounds (character code is %hU).") COMMA (Tuint)(*src_buffer))
    {
      return 0;
    }

    *dst_buffer++ = (Tschar)((Twcharu)(*src_buffer++));
  }

  m_Index += size;
  // Check 'end of file' state.
  if (m_Index >= m_Size)
    IReader::setEOF();
  return size;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringBufferUnicodeConst::onReadText(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Copy Unicode characters from the constant Unicode string buffer.
  Tuint size = NAlgorithms::NCommon::min(m_Size - m_Index, a_cSize);

  Tuint counter = size;
  Twstr dst_buffer = a_pBuffer;
  Tcwstr src_buffer = m_cpBuffer + m_Index;
  while (counter-- > 0)
    *dst_buffer++ = (Twchar)((Twcharu)(*src_buffer++));

  m_Index += size;
  // Check 'end of file' state.
  if (m_Index >= m_Size)
    IReader::setEOF();
  return size;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
