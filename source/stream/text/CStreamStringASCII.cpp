/*!
 *  \file    CStreamStringASCII.cpp ASCII string stream class gives ability to
 *           read/write byte sequences from/into the ASCII string.
 *  \brief   ASCII string stream class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: ASCII string stream class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   02.09.2008 02:11:41

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
#include <Depth/include/stream/text/CStreamStringASCII.hpp>
#include <Depth/include/string/CCharacter.hpp>
/*==========================================================================*/
#ifndef __CSTREAMSTRINGASCII_CPP__
#define __CSTREAMSTRINGASCII_CPP__
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
Tbool CStreamStringASCII::set(const CStreamStringASCII& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CStreamStringASCII class instance."))
  {
    return false;
  }

  // Close opened ASCII string stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize new reader & writer.
  if (!IReaderWriter::set(a_crInstance))
    return false;

  // Initialize ASCII string.
  return CStringASCII::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tbool CStreamStringASCII::setPosition(const Tuint a_cPosition)
{ CALL
  // Check if the current stream is opened.
  ASSERT(isOpened(), STR("Cannot set position of the closed ASCII string stream."))
  {
    return false;
  }
  // Check position value and the buffer bounds.
  ASSERT(((a_cPosition < CStringASCII::getSize()) || (a_cPosition == 0)), STR("Cannot set position with the out of bounds index (index = %u, size = %u).") COMMA a_cPosition COMMA CStringASCII::getSize())
  {
    return false;
  }

  m_Index = a_cPosition;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringASCII::getPosition() const
{ CALL
  // Check if the current stream is opened.
  ASSERT(isOpened(), STR("Cannot get position of the closed ASCII string stream."))
  {
    return 0;
  }

  return m_Index;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringASCII::onReadBinary(Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onReadText((Tsstr)a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringASCII::onReadText(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Copy ASCII characters from the ASCII string.
  Tuint size = NAlgorithms::NCommon::min(CStringASCII::getSize() - m_Index, a_cSize);

  Tuint counter = size;
  Tsstr dst_buffer = a_pBuffer;
  Tcsstr src_buffer = CStringASCII::getBuffer() + m_Index;
  while (counter-- > 0)
    *dst_buffer++ = (Tschar)((Tscharu)(*src_buffer++));

  m_Index += size;
  // Check 'end of file' state.
  if (m_Index >= CStringASCII::getSize())
    IReader::setEOF();
  return size;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringASCII::onReadText(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Copy Unicode characters from the ASCII string.
  Tuint size = NAlgorithms::NCommon::min(CStringASCII::getSize() - m_Index, a_cSize);

  Tuint counter = size;
  Twstr dst_buffer = a_pBuffer;
  Tcsstr src_buffer = CStringASCII::getBuffer() + m_Index;
  while (counter-- > 0)
    *dst_buffer++ = (Twchar)((Tscharu)(*src_buffer++));

  m_Index += size;
  // Check 'end of file' state.
  if (m_Index >= CStringASCII::getSize())
    IReader::setEOF();
  return size;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringASCII::onWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return onWriteText((Tcsstr)a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringASCII::onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check it we need to resize the ASCII string.
  if (a_cSize > (CStringASCII::getSize() - m_Index))
    if (!CStringASCII::resize(a_cSize + m_Index))
      return 0;

  // Shift part of the ASCII string to the right.
  NMemory::CMemory::move(CStringASCII::getBuffer() + m_Index + a_cSize, CStringASCII::getBuffer() + m_Index, (CStringASCII::getSize() - m_Index - a_cSize) * sizeof(Tschar));

  // Copy ASCII characters into the ASCII string.
  Tuint counter = a_cSize;
  Tsstr dst_buffer = CStringASCII::getBuffer() + m_Index;
  Tcsstr src_buffer = a_cpBuffer;
  while (counter-- > 0)
    *dst_buffer++ = (Tschar)((Tscharu)(*src_buffer++));

  m_Index += a_cSize;
  return a_cSize;
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStringASCII::onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if all Unicode characters from the given buffer fits ASCII bounds.
  for (Tuint i = 0; i < a_cSize; ++i)
  {
    ASSERT(NString::CCharacter(a_cpBuffer[i]).isValidASCII(), STR("Cannot write Unicode character which does not fit ASCII bounds (character code is %hU).") COMMA (Tuint)a_cpBuffer[i])
    {
      return 0;
    }
  }

  // Check it we need to resize the ASCII string.
  if (a_cSize > (CStringASCII::getSize() - m_Index))
    if (!CStringASCII::resize(a_cSize + m_Index))
      return 0;

  // Shift part of the ASCII string to the right.
  NMemory::CMemory::move(CStringASCII::getBuffer() + m_Index + a_cSize, CStringASCII::getBuffer() + m_Index, (CStringASCII::getSize() - m_Index - a_cSize) * sizeof(Tschar));

  // Copy Unicode characters into the ASCII string.
  Tuint counter = a_cSize;
  Tsstr dst_buffer = CStringASCII::getBuffer() + m_Index;
  Tcwstr src_buffer = a_cpBuffer;
  while (counter-- > 0)
    *dst_buffer++ = (Tschar)((Twcharu)(*src_buffer++));

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
