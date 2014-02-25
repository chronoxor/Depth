/*!
 *  \file    CStreamStringUnicode.cpp Unicode string stream class gives
 *           ability to read/write byte sequences from/into the Unicode
 *           string.
 *  \brief   Unicode string stream class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode string stream class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   02.09.2008 02:57:37

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
#include <Depth/include/stream/text/CStreamStringUnicode.hpp>
#include <Depth/include/string/CCharacter.hpp>
/*==========================================================================*/
#ifndef __CSTREAMSTRINGUNICODE_CPP__
#define __CSTREAMSTRINGUNICODE_CPP__
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
Tbool CStreamStringUnicode::set(const CStreamStringUnicode& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CStreamStringUnicode class instance."))
  {
    return false;
  }

  // Close opened Unicode string stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize new reader & writer.
  if (!IReaderWriter::set(a_crInstance))
    return false;

  // Initialize Unicode string.
  return CStringUnicode::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tbool CStreamStringUnicode::setPosition(const Tuint a_cPosition)
{ CALL
  // Check if the current stream is opened.
  ASSERT(isOpened(), STR("Cannot set position of the closed Unicode string stream."))
  {
    return false;
  }
  // Check position value and the buffer bounds.
  ASSERT(((a_cPosition < CStringUnicode::getSize()) || (a_cPosition == 0)), STR("Cannot set position with the out of bounds index (index = %u, size = %u).") COMMA a_cPosition COMMA CStringUnicode::getSize())
  {
    return false;
  }

  m_Index = a_cPosition;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringUnicode::getPosition() const
{ CALL
  // Check if the current stream is opened.
  ASSERT(isOpened(), STR("Cannot get position of the closed Unicode string stream."))
  {
    return 0;
  }

  return m_Index;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringUnicode::onReadBinary(Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onReadText((Tsstr)a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringUnicode::onReadText(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Copy Unicode characters from the Unicode string.
  Tuint size = NAlgorithms::NCommon::min(CStringUnicode::getSize() - m_Index, a_cSize);

  Tuint counter = size;
  Tsstr dst_buffer = a_pBuffer;
  Tcwstr src_buffer = CStringUnicode::getBuffer() + m_Index;
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
  if (m_Index >= CStringUnicode::getSize())
    IReader::setEOF();
  return size;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringUnicode::onReadText(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Copy Unicode characters from the Unicode string.
  Tuint size = NAlgorithms::NCommon::min(CStringUnicode::getSize() - m_Index, a_cSize);

  Tuint counter = size;
  Twstr dst_buffer = a_pBuffer;
  Tcwstr src_buffer = CStringUnicode::getBuffer() + m_Index;
  while (counter-- > 0)
    *dst_buffer++ = (Twchar)((Twcharu)(*src_buffer++));

  m_Index += size;
  // Check 'end of file' state.
  if (m_Index >= CStringUnicode::getSize())
    IReader::setEOF();
  return size;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringUnicode::onWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return onWriteText((Tcsstr)a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringUnicode::onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check it we need to resize the Unicode string.
  if (a_cSize > (CStringUnicode::getSize() - m_Index))
    if (!CStringUnicode::resize(a_cSize + m_Index))
      return 0;

  // Shift part of the Unicode string to the right.
  NMemory::CMemory::move(CStringUnicode::getBuffer() + m_Index + a_cSize, CStringUnicode::getBuffer() + m_Index, (CStringUnicode::getSize() - m_Index - a_cSize) * sizeof(Twchar));

  // Copy Unicode characters into the Unicode string.
  Tuint counter = a_cSize;
  Twstr dst_buffer = CStringUnicode::getBuffer() + m_Index;
  Tcsstr src_buffer = a_cpBuffer;
  while (counter-- > 0)
    *dst_buffer++ = (Twchar)((Tscharu)(*src_buffer++));

  m_Index += a_cSize;
  return a_cSize;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringUnicode::onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check it we need to resize the Unicode string.
  if (a_cSize > (CStringUnicode::getSize() - m_Index))
    if (!CStringUnicode::resize(a_cSize + m_Index))
      return 0;

  // Shift part of the Unicode string to the right.
  NMemory::CMemory::move(CStringUnicode::getBuffer() + m_Index + a_cSize, CStringUnicode::getBuffer() + m_Index, (CStringUnicode::getSize() - m_Index - a_cSize) * sizeof(Twchar));

  // Copy Unicode characters into the Unicode string.
  Tuint counter = a_cSize;
  Twstr dst_buffer = CStringUnicode::getBuffer() + m_Index;
  Tcwstr src_buffer = a_cpBuffer;
  while (counter-- > 0)
    *dst_buffer++ = (Twchar)((Twcharu)(*src_buffer++));

  m_Index += a_cSize;
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
