/*!
 *  \file    IReader.cpp Reader is a base stream interface for all
 *           implementations of stream classes which use byte input (files,
 *           pipes, sockets, etc.).
 *  \brief   Reader interface (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reader interface (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   13.08.2008 00:57:40

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
#include <Depth/include/stream/IReader.hpp>
#include <Depth/include/stream/details/CStreamHelper.hpp>
/*==========================================================================*/
#ifndef __IREADER_CPP__
#define __IREADER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INTERFACE IMPLEMENTATIONS                                                */
/*==========================================================================*/
Tbool IReader::set(const IReader& a_crInstance)
{ CALL
  // Check if the given interface instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same IReader interface instance."))
  {
    return false;
  }

  // Close opened reader.
  if (isOpened())
    if (!close())
      return false;

  // Initialize new reader.
  IStream::set(a_crInstance);

  // Reset reader's parameters.
  m_IsOpened = false;
  m_IsEOF = false;
  m_ReadBytesCount = 0;

  // Set reader's peek buffer size.
  setPeekBufferSize(a_crInstance.m_PeekBufferSize);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool IReader::setPeekBufferSize(const Tuint a_cPeekBufferSize)
{ CALL
  // Check if the current reader is not opened.
  ASSERT(!isOpened(), STR("Cannot set peek buffer size for opened reader."))
  {
    return false;
  }

  m_PeekBufferSize = a_cPeekBufferSize;
  m_PeekBufferFreeSize = a_cPeekBufferSize;
  m_pPeekBuffer = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool IReader::open()
{ CALL
  // Check if the current writer is not opened.
  ASSERT(!isOpened(), STR("Cannot open the writer which is already opened."))
  {
    return false;
  }

  // Open the reader and initialize its parameters.
  if (onOpen(e_OPEN_READ))
  {
    // Set default format values.
    setDefaultFormat();
    // Set default parse values.
    setDefaultParse();

    m_IsOpened = true;
    m_IsEOF = false;
    m_ReadBytesCount = 0;

    // Allocate peek buffer.
    if (m_PeekBufferSize > 0)
    {
      m_pPeekBuffer = newex Tbyte[m_PeekBufferSize];
      if (m_pPeekBuffer == NULL)
      {
        WARNING(STR("Cannot allocate peek buffer for the reader (requested size is %u bytes).") COMMA m_PeekBufferSize);
        return false;
      }
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tuint IReader::readBuffer(Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot read the buffer from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in binary mode.
  ASSERT(isBinaryMode(), STR("Cannot read the buffer from the reader opened in the text mode."))
  {
    return 0;
  }

  // Nothing to read.
  if (a_cSize == 0)
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_pBuffer != NULL), STR("Cannot read into the buffer which is NULL."))
  {
    return 0;
  }

  Tuint size;
  Tuint counter = a_cSize;
  Tbuffer buffer = (Tbuffer)a_pBuffer;

  // Read the given buffer from the peek buffer.
  Tuint peek_current_size = (((m_PeekBufferSize > 0) && (m_pPeekBuffer != NULL)) ? (m_PeekBufferSize - m_PeekBufferFreeSize) : 0);
  if (peek_current_size > 0)
  {
    size = NAlgorithms::NCommon::min(counter, peek_current_size);

    // Copy bytes from the peek buffer.
    NMemory::CMemory::copy(buffer, m_pPeekBuffer, size);

    // Update reader parameters.
    m_ReadBytesCount += size;
    counter -= size;
    buffer += size;

    // Move remain peek buffer bytes.
    NMemory::CMemory::move(m_pPeekBuffer, m_pPeekBuffer + size, peek_current_size - size);
    m_PeekBufferFreeSize += size;
  }

  // Nothing to read.
  if (counter == 0)
    return a_cSize;

  // Read the given buffer from the reader.
  size = onReadBinary(buffer, counter);
  m_ReadBytesCount += size;
  counter -= size;

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return a_cSize - counter;
}
/*--------------------------------------------------------------------------*/
Tuint IReader::readBuffer(Tptr a_pBuffer, const Tuint a_cSingleSize, const Tuint a_cCount)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot read the buffer from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in binary mode.
  ASSERT(isBinaryMode(), STR("Cannot read the buffer from the reader opened in the text mode."))
  {
    return 0;
  }

  // Nothing to read.
  if ((a_cSingleSize == 0) || (a_cCount == 0))
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_pBuffer != NULL), STR("Cannot read into the buffer which is NULL."))
  {
    return 0;
  }

  #if defined(__BIG_ENDIAN__)
  if ((getByteOrder() == e_BYTE_ORDER_LITTLE_ENDIAN) && (a_cSingleSize > 1))
  #else
  if ((getByteOrder() != e_BYTE_ORDER_LITTLE_ENDIAN) && (a_cSingleSize > 1))
  #endif
  {
    Tuint result = 0;

    if (a_cCount > 0)
    {
      Tuint counter = a_cCount;
      Tbuffer buffer = (Tbuffer)a_pBuffer;

      // Read all items.
      while (counter-- > 0)
      {
        Tuint local_counter = a_cSingleSize;
        Tbuffer local_buffer = buffer + a_cSingleSize - 1;

        // Read single item.
        while (local_counter-- > 0)
          if (readBuffer((Tptr)local_buffer--, 1) != 1)
            return result + a_cSingleSize - local_counter - 1;

        result += a_cSingleSize;
        buffer += a_cSingleSize;
      }
    }
    return result;
  }
  else
    return readBuffer(a_pBuffer, a_cSingleSize * a_cCount);
}
/*--------------------------------------------------------------------------*/
Tuint IReader::readBuffer(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot read the buffer from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in text mode.
  ASSERT(isTextMode(), STR("Cannot read the buffer from the reader opened in the binary mode."))
  {
    return 0;
  }

  // Nothing to read.
  if (a_cSize == 0)
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_pBuffer != NULL), STR("Cannot read into the buffer which is NULL."))
  {
    return 0;
  }

  Tuint size;
  Tuint counter = a_cSize * sizeof(Tschar);
  Tbuffer buffer = (Tbuffer)a_pBuffer;

  // Read the given buffer from the peek buffer.
  Tuint peek_current_size = (((m_PeekBufferSize > 0) && (m_pPeekBuffer != NULL)) ? (m_PeekBufferSize - m_PeekBufferFreeSize) : 0);
  Tuint peek_current_size_corrected = (peek_current_size / sizeof(Tschar)) * sizeof(Tschar);
  if ((peek_current_size > 0) && (peek_current_size_corrected > 0))
  {
    size = NAlgorithms::NCommon::min(counter, peek_current_size_corrected);

    // Copy bytes from the peek buffer.
    #if defined(__BIG_ENDIAN__)
    if ((getByteOrder() == e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Tschar) > 1))
    #else
    if ((getByteOrder() != e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Tschar) > 1))
    #endif
    {
      Tuint counter = size / sizeof(Tschar);
      Tbuffer dst_buffer = buffer;
      Tbuffer src_buffer = m_pPeekBuffer;

      // Copy all items.
      while (counter-- > 0)
      {
        NMemory::CMemory::copyReverse(dst_buffer, src_buffer, sizeof(Tschar));
        dst_buffer += sizeof(Tschar);
        src_buffer += sizeof(Tschar);
      }
    }
    else
      NMemory::CMemory::copy(buffer, m_pPeekBuffer, size);

    // Update reader parameters.
    m_ReadBytesCount += size;
    counter -= size;
    buffer += size;

    // Move remain peek buffer bytes.
    NMemory::CMemory::move(m_pPeekBuffer, m_pPeekBuffer + size, peek_current_size - size);
    m_PeekBufferFreeSize += size;
  }

  // Nothing to read.
  if (counter == 0)
    return a_cSize;

  // Read the given string buffer from the reader.
  Tsstr strbuffer = (Tsstr)buffer;
  #if defined(__BIG_ENDIAN__)
  if ((getByteOrder() == e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Tschar) > 1))
  #else
  if ((getByteOrder() != e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Tschar) > 1))
  #endif
  {
    // Read all items.
    Tschar character;
    while (counter > 0)
    {
      if (onReadText(&character, 1) == 1)
      {
        NMemory::CMemory::copyReverse(strbuffer, &character, sizeof(Tschar));
        ++strbuffer;
        m_ReadBytesCount += sizeof(Tschar);
        counter -= sizeof(Tschar);
      }
      else
        break;
    }
  }
  else
  {
    size = onReadText(strbuffer, counter / sizeof(Tschar)) * sizeof(Tschar);
    m_ReadBytesCount += size;
    counter -= size;
  }

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return a_cSize - (counter / sizeof(Tschar));
}
/*--------------------------------------------------------------------------*/
Tuint IReader::readBuffer(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot read the buffer from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in text mode.
  ASSERT(isTextMode(), STR("Cannot read the buffer from the reader opened in the binary mode."))
  {
    return 0;
  }

  // Nothing to read.
  if (a_cSize == 0)
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_pBuffer != NULL), STR("Cannot read into the buffer which is NULL."))
  {
    return 0;
  }

  Tuint size;
  Tuint counter = a_cSize * sizeof(Twchar);
  Tbuffer buffer = (Tbuffer)a_pBuffer;

  // Read the given buffer from the peek buffer.
  Tuint peek_current_size = (((m_PeekBufferSize > 0) && (m_pPeekBuffer != NULL)) ? (m_PeekBufferSize - m_PeekBufferFreeSize) : 0);
  Tuint peek_current_size_corrected = (peek_current_size / sizeof(Twchar)) * sizeof(Twchar);
  if ((peek_current_size > 0) && (peek_current_size_corrected > 0))
  {
    size = NAlgorithms::NCommon::min(counter, peek_current_size_corrected);

    // Copy bytes from the peek buffer.
    #if defined(__BIG_ENDIAN__)
    if ((getByteOrder() == e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Twchar) > 1))
    #else
    if ((getByteOrder() != e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Twchar) > 1))
    #endif
    {
      Tuint counter = size / sizeof(Twchar);
      Tbuffer dst_buffer = buffer;
      Tbuffer src_buffer = m_pPeekBuffer;

      // Copy all items.
      while (counter-- > 0)
      {
        NMemory::CMemory::copyReverse(dst_buffer, src_buffer, sizeof(Twchar));
        dst_buffer += sizeof(Twchar);
        src_buffer += sizeof(Twchar);
      }
    }
    else
      NMemory::CMemory::copy(buffer, m_pPeekBuffer, size);

    // Update reader parameters.
    m_ReadBytesCount += size;
    counter -= size;
    buffer += size;

    // Move remain peek buffer bytes.
    NMemory::CMemory::move(m_pPeekBuffer, m_pPeekBuffer + size, peek_current_size - size);
    m_PeekBufferFreeSize += size;
  }

  // Nothing to read.
  if (counter == 0)
    return a_cSize;

  // Read the given string buffer from the reader.
  Twstr strbuffer = (Twstr)buffer;
  #if defined(__BIG_ENDIAN__)
  if ((getByteOrder() == e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Twchar) > 1))
  #else
  if ((getByteOrder() != e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Twchar) > 1))
  #endif
  {
    // Read all items.
    Twchar character;
    while (counter > 0)
    {
      if (onReadText(&character, 1) == 1)
      {
        NMemory::CMemory::copyReverse(strbuffer, &character, sizeof(Twchar));
        ++strbuffer;
        m_ReadBytesCount += sizeof(Twchar);
        counter -= sizeof(Twchar);
      }
      else
        break;
    }
  }
  else
  {
    size = onReadText(strbuffer, counter / sizeof(Twchar)) * sizeof(Twchar);
    m_ReadBytesCount += size;
    counter -= size;
  }

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return a_cSize - (counter / sizeof(Twchar));
}
/*--------------------------------------------------------------------------*/
Tuint IReader::readSkipBytes(const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot read and skip from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in binary mode.
  ASSERT(isBinaryMode(), STR("Cannot read and skip bytes from the reader opened in the text mode."))
  {
    return 0;
  }

  // Nothing to read and skip.
  if (a_cSize == 0)
    return 0;

  Tuint size;
  Tuint counter = a_cSize;

  // Read the given buffer from the peek buffer.
  Tuint peek_current_size = (((m_PeekBufferSize > 0) && (m_pPeekBuffer != NULL)) ? (m_PeekBufferSize - m_PeekBufferFreeSize) : 0);
  if (peek_current_size > 0)
  {
    size = NAlgorithms::NCommon::min(counter, peek_current_size);

    // Update reader parameters.
    m_ReadBytesCount += size;
    counter -= size;

    // Move remain peek buffer bytes.
    NMemory::CMemory::move(m_pPeekBuffer, m_pPeekBuffer + size, peek_current_size - size);
    m_PeekBufferFreeSize += size;
  }

  // Nothing to read and skip.
  if (counter == 0)
    return a_cSize;

  // Read and skip the given buffer from the reader.
  static const Tuint buffer_size = 1024;
  static Tbyte buffer[buffer_size];
  while (counter > 0)
  {
    size = NAlgorithms::NCommon::min(counter, buffer_size);
    size = onReadBinary(buffer, size);
    m_ReadBytesCount += size;
    counter -= size;
  }

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return a_cSize - counter;
}
/*--------------------------------------------------------------------------*/
Tuint IReader::readSkipASCII(const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot read and skip from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in text mode.
  ASSERT(isTextMode(), STR("Cannot read and skip ASCII characters from the reader opened in the text mode."))
  {
    return 0;
  }

  // Nothing to read and skip.
  if (a_cSize == 0)
    return 0;

  Tuint size;
  Tuint counter = a_cSize * sizeof(Tschar);

  // Read the given buffer from the peek buffer.
  Tuint peek_current_size = (((m_PeekBufferSize > 0) && (m_pPeekBuffer != NULL)) ? (m_PeekBufferSize - m_PeekBufferFreeSize) : 0);
  Tuint peek_current_size_corrected = (peek_current_size / sizeof(Tschar)) * sizeof(Tschar);
  if ((peek_current_size > 0) && (peek_current_size_corrected > 0))
  {
    size = NAlgorithms::NCommon::min(counter, peek_current_size_corrected);

    // Update reader parameters.
    m_ReadBytesCount += size;
    counter -= size;

    // Move remain peek buffer bytes.
    NMemory::CMemory::move(m_pPeekBuffer, m_pPeekBuffer + size, peek_current_size - size);
    m_PeekBufferFreeSize += size;
  }

  // Nothing to read and skip.
  if (counter == 0)
    return a_cSize;

  // Read and skip the given buffer from the reader.
  static const Tuint buffer_size = 1024;
  static Tbyte buffer[buffer_size];
  while (counter > 0)
  {
    size = NAlgorithms::NCommon::min(counter, buffer_size);
    size = onReadText((Tsstr)buffer, size / sizeof(Tschar));
    m_ReadBytesCount += size;
    counter -= size;
  }

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return a_cSize - (counter / sizeof(Tschar));
}
/*--------------------------------------------------------------------------*/
Tuint IReader::readSkipUnicode(const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot read and skip from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in text mode.
  ASSERT(isTextMode(), STR("Cannot read and skip Unicode characters from the reader opened in the text mode."))
  {
    return 0;
  }

  // Nothing to read and skip.
  if (a_cSize == 0)
    return 0;

  Tuint size;
  Tuint counter = a_cSize * sizeof(Twchar);

  // Read the given buffer from the peek buffer.
  Tuint peek_current_size = (((m_PeekBufferSize > 0) && (m_pPeekBuffer != NULL)) ? (m_PeekBufferSize - m_PeekBufferFreeSize) : 0);
  Tuint peek_current_size_corrected = (peek_current_size / sizeof(Twchar)) * sizeof(Twchar);
  if ((peek_current_size > 0) && (peek_current_size_corrected > 0))
  {
    size = NAlgorithms::NCommon::min(counter, peek_current_size_corrected);

    // Update reader parameters.
    m_ReadBytesCount += size;
    counter -= size;

    // Move remain peek buffer bytes.
    NMemory::CMemory::move(m_pPeekBuffer, m_pPeekBuffer + size, peek_current_size - size);
    m_PeekBufferFreeSize += size;
  }

  // Nothing to read and skip.
  if (counter == 0)
    return a_cSize;

  // Read and skip the given buffer from the reader.
  static const Tuint buffer_size = 1024;
  static Tbyte buffer[buffer_size];
  while (counter > 0)
  {
    size = NAlgorithms::NCommon::min(counter, buffer_size);
    size = onReadText((Tsstr)buffer, size / sizeof(Twchar));
    m_ReadBytesCount += size;
    counter -= size;
  }

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return a_cSize - (counter / sizeof(Twchar));
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tschar& a_rCharacter)
{ CALL
  return NDetails::CStreamHelper::inputChar(false, *this, a_rCharacter);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Twchar& a_rCharacter)
{ CALL
  return NDetails::CStreamHelper::inputChar(false, *this, a_rCharacter);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tsstr& a_rpString, const Tuint a_cSize/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::inputString(false, *this, a_rpString, a_cSize);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Twstr& a_rpString, const Tuint a_cSize/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::inputString(false, *this, a_rpString, a_cSize);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(NString::CStringASCII& a_rString, const Tuint a_cSize/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::inputString(false, *this, a_rString, a_cSize);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(NString::CStringUnicode& a_rString, const Tuint a_cSize/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::inputString(false, *this, a_rString, a_cSize);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(NString::CSystemString& a_rString, const Tuint a_cSize/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::inputString(false, *this, a_rString, a_cSize);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tbool& a_rBoolean, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputBool(false, *this, a_rBoolean, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tsint08& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(false, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tuint08& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(false, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tsint16& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(false, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tuint16& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(false, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tsint32& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(false, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tuint32& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(false, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tsint64& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(false, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tuint64& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(false, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tfloat& a_rReal, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputReal(false, *this, a_rReal, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tdouble& a_rReal, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputReal(false, *this, a_rReal, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::read(Tptr& a_rpPointer, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputPointer(false, *this, a_rpPointer, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::readFormat(const Tcsstr a_cpFormatString, ...)
{ CALL
  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = readFormatVarList(a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::readFormatVarList(const Tcsstr a_cpFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::inputFormat(false, *this, a_cpFormatString, NAlgorithms::NString::NBuffer::strLen(a_cpFormatString), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::readFormat(const Tcwstr a_cpFormatString, ...)
{ CALL
  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = readFormatVarList(a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::readFormatVarList(const Tcwstr a_cpFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::inputFormat(false, *this, a_cpFormatString, NAlgorithms::NString::NBuffer::strLen(a_cpFormatString), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::readFormat(const NString::CStringASCII* a_cpFormatString, ...)
{ CALL
  // Check the given format string not to be NULL.
  ASSERT((a_cpFormatString != NULL), STR("Format string cannot be NULL."))
  {
    return NUtility::CPair<Tbool, Tuint>(false, 0);
  }

  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = readFormatVarList(*a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::readFormatVarList(const NString::CStringASCII& a_crFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::inputFormat(false, *this, a_crFormatString.getBuffer(), a_crFormatString.getSize(), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::readFormat(const NString::CStringUnicode* a_cpFormatString, ...)
{ CALL
  // Check the given format string not to be NULL.
  ASSERT((a_cpFormatString != NULL), STR("Format string cannot be NULL."))
  {
    return NUtility::CPair<Tbool, Tuint>(false, 0);
  }

  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = readFormatVarList(*a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::readFormatVarList(const NString::CStringUnicode& a_crFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::inputFormat(false, *this, a_crFormatString.getBuffer(), a_crFormatString.getSize(), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::readLineEnd()
{ CALL
  if (IStream::getCurrentParseFlags() & IStream::PARSE_ASCII)
    return NDetails::CStreamHelper::inputLineEndASCII(false, *this);
  else
    return NDetails::CStreamHelper::inputLineEndUnicode(false, *this);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::readLineEnd(const Tbool a_cIsASCII)
{ CALL
  if (a_cIsASCII)
    return NDetails::CStreamHelper::inputLineEndASCII(false, *this);
  else
    return NDetails::CStreamHelper::inputLineEndUnicode(false, *this);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::readToLineEnd()
{ CALL
  if (IStream::getCurrentParseFlags() & IStream::PARSE_ASCII)
    return NDetails::CStreamHelper::inputToLineEndASCII(false, *this);
  else
    return NDetails::CStreamHelper::inputToLineEndUnicode(false, *this);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::readToLineEnd(const Tbool a_cIsASCII)
{ CALL
  if (a_cIsASCII)
    return NDetails::CStreamHelper::inputToLineEndASCII(false, *this);
  else
    return NDetails::CStreamHelper::inputToLineEndUnicode(false, *this);
}
/*--------------------------------------------------------------------------*/
Tuint IReader::peekBuffer(Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot peek the buffer from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in binary mode.
  ASSERT(isBinaryMode(), STR("Cannot peek the buffer from the reader opened in the text mode."))
  {
    return 0;
  }

  // Nothing to peek.
  if (a_cSize == 0)
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_pBuffer != NULL), STR("Cannot peek into the buffer which is NULL."))
  {
    return 0;
  }

  // Nowhere to peek.
  if ((m_PeekBufferSize == 0) || (m_PeekBufferFreeSize == 0) || (m_pPeekBuffer == NULL))
    return 0;

  Tuint size = NAlgorithms::NCommon::min(a_cSize, m_PeekBufferFreeSize);
  Tuint peek_current_size = m_PeekBufferSize - m_PeekBufferFreeSize;

  // Read bytes from the reader into the peek buffer.
  size = onReadBinary(m_pPeekBuffer + peek_current_size, size);
  m_PeekBufferFreeSize -= size;

  // Copy bytes from the peek buffer.
  NMemory::CMemory::copy(a_pBuffer, m_pPeekBuffer + peek_current_size, size);

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return size;
}
/*--------------------------------------------------------------------------*/
Tuint IReader::peekBuffer(Tptr a_pBuffer, const Tuint a_cSingleSize, const Tuint a_cCount)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot peek the buffer from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in binary mode.
  ASSERT(isBinaryMode(), STR("Cannot peek the buffer from the reader opened in the text mode."))
  {
    return 0;
  }

  // Nothing to peek.
  if ((a_cSingleSize == 0) || (a_cCount == 0))
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_pBuffer != NULL), STR("Cannot peek into the buffer which is NULL."))
  {
    return 0;
  }

  #if defined(__BIG_ENDIAN__)
  if ((getByteOrder() == e_BYTE_ORDER_LITTLE_ENDIAN) && (a_cSingleSize > 1))
  #else
  if ((getByteOrder() != e_BYTE_ORDER_LITTLE_ENDIAN) && (a_cSingleSize > 1))
  #endif
  {
    Tuint result = 0;

    if (a_cCount > 0)
    {
      Tuint counter = a_cCount;
      Tbuffer buffer = (Tbuffer)a_pBuffer;

      // Peek all items.
      while (counter-- > 0)
      {
        Tuint local_counter = a_cSingleSize;
        Tbuffer local_buffer = buffer + a_cSingleSize - 1;

        // Peek single item.
        while (local_counter-- > 0)
          if (peekBuffer((Tptr)local_buffer--, 1) != 1)
            return result + a_cSingleSize - local_counter - 1;

        result += a_cSingleSize;
        buffer += a_cSingleSize;
      }
    }
    return result;
  }
  else
    return peekBuffer(a_pBuffer, a_cSingleSize * a_cCount);
}
/*--------------------------------------------------------------------------*/
Tuint IReader::peekBuffer(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot peek the buffer from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in text mode.
  ASSERT(isTextMode(), STR("Cannot peek the buffer from the reader opened in the binary mode."))
  {
    return 0;
  }

  // Nothing to peek.
  if (a_cSize == 0)
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_pBuffer != NULL), STR("Cannot peek into the buffer which is NULL."))
  {
    return 0;
  }

  // Nowhere to peek.
  if ((m_PeekBufferSize == 0) || (m_PeekBufferFreeSize < sizeof(Tschar)) || (m_pPeekBuffer == NULL))
    return 0;

  Tuint size = NAlgorithms::NCommon::min(a_cSize, m_PeekBufferFreeSize / sizeof(Tschar)) * sizeof(Tschar);
  Tuint peek_current_size = m_PeekBufferSize - m_PeekBufferFreeSize;

  // Read bytes from the reader into the peek buffer.
  size = onReadText((Tsstr)(m_pPeekBuffer + peek_current_size), size / sizeof(Tschar)) * sizeof(Tschar);
  m_PeekBufferFreeSize -= size;

  // Copy bytes from the peek buffer.
  #if defined(__BIG_ENDIAN__)
  if ((getByteOrder() == e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Tschar) > 1))
  #else
  if ((getByteOrder() != e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Tschar) > 1))
  #endif
  {
    Tuint counter = size / sizeof(Tschar);
    Tsstr dst_buffer = a_pBuffer;
    Tbuffer src_buffer = m_pPeekBuffer + peek_current_size;

    // Copy all items.
    while (counter-- > 0)
    {
      NMemory::CMemory::copyReverse(dst_buffer, src_buffer, sizeof(Tschar));
      dst_buffer += sizeof(Tschar);
      src_buffer += sizeof(Tschar);
    }
  }
  else
    NMemory::CMemory::copy(a_pBuffer, m_pPeekBuffer + peek_current_size, size);

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return size / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
Tuint IReader::peekBuffer(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot peek the buffer from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in text mode.
  ASSERT(isTextMode(), STR("Cannot peek the buffer from the reader opened in the binary mode."))
  {
    return 0;
  }

  // Nothing to peek.
  if (a_cSize == 0)
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_pBuffer != NULL), STR("Cannot peek into the buffer which is NULL."))
  {
    return 0;
  }

  // Nowhere to peek.
  if ((m_PeekBufferSize == 0) || (m_PeekBufferFreeSize < sizeof(Twchar)) || (m_pPeekBuffer == NULL))
    return 0;

  Tuint size = NAlgorithms::NCommon::min(a_cSize, m_PeekBufferFreeSize / sizeof(Twchar)) * sizeof(Twchar);
  Tuint peek_current_size = m_PeekBufferSize - m_PeekBufferFreeSize;

  // Read bytes from the reader into the peek buffer.
  size = onReadText((Twstr)(m_pPeekBuffer + peek_current_size), size / sizeof(Twchar)) * sizeof(Twchar);
  m_PeekBufferFreeSize -= size;

  // Copy bytes from the peek buffer.
  #if defined(__BIG_ENDIAN__)
  if ((getByteOrder() == e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Tschar) > 1))
  #else
  if ((getByteOrder() != e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Tschar) > 1))
  #endif
  {
    Tuint counter = size / sizeof(Twchar);
    Twstr dst_buffer = a_pBuffer;
    Tbuffer src_buffer = m_pPeekBuffer + peek_current_size;

    // Copy all items.
    while (counter-- > 0)
    {
      NMemory::CMemory::copyReverse(dst_buffer, src_buffer, sizeof(Twchar));
      dst_buffer += sizeof(Twchar);
      src_buffer += sizeof(Twchar);
    }
  }
  else
    NMemory::CMemory::copy(a_pBuffer, m_pPeekBuffer + peek_current_size, size);

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return size / sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
Tuint IReader::peekSkipBytes(const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot peek and skip buffer from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in binary mode.
  ASSERT(isBinaryMode(), STR("Cannot peek and skip bytes from the reader opened in the text mode."))
  {
    return 0;
  }

  // Nothing to peek and skip.
  if (a_cSize == 0)
    return 0;

  // Nowhere to peek and skip.
  if ((m_PeekBufferSize == 0) || (m_PeekBufferFreeSize == 0) || (m_pPeekBuffer == NULL))
    return 0;

  Tuint size = NAlgorithms::NCommon::min(a_cSize, m_PeekBufferFreeSize);
  Tuint peek_current_size = m_PeekBufferSize - m_PeekBufferFreeSize;

  // Read bytes from the reader into the peek buffer.
  size = onReadBinary(m_pPeekBuffer + peek_current_size, size);
  m_PeekBufferFreeSize -= size;

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return a_cSize - size;
}
/*--------------------------------------------------------------------------*/
Tuint IReader::peekSkipASCII(const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot peek and skip buffer from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in binary mode.
  ASSERT(isTextMode(), STR("Cannot peek and skip ASCII characters from the reader opened in the text mode."))
  {
    return 0;
  }

  // Nothing to peek and skip.
  if (a_cSize == 0)
    return 0;

  // Nowhere to peek and skip.
  if ((m_PeekBufferSize == 0) || (m_PeekBufferFreeSize < sizeof(Tschar)) || (m_pPeekBuffer == NULL))
    return 0;

  Tuint size = NAlgorithms::NCommon::min(a_cSize, m_PeekBufferFreeSize / sizeof(Tschar)) * sizeof(Tschar);
  Tuint peek_current_size = m_PeekBufferSize - m_PeekBufferFreeSize;

  // Read bytes from the reader into the peek buffer.
  size = onReadText((Tsstr)(m_pPeekBuffer + peek_current_size), size / sizeof(Tschar)) * sizeof(Tschar);
  m_PeekBufferFreeSize -= size;

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return a_cSize - (size / sizeof(Tschar));
}
/*--------------------------------------------------------------------------*/
Tuint IReader::peekSkipUnicode(const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot peek and skip buffer from the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in binary mode.
  ASSERT(isTextMode(), STR("Cannot peek and skip Unicode characters from the reader opened in the text mode."))
  {
    return 0;
  }

  // Nothing to peek and skip.
  if (a_cSize == 0)
    return 0;

  // Nowhere to peek and skip.
  if ((m_PeekBufferSize == 0) || (m_PeekBufferFreeSize < sizeof(Twchar)) || (m_pPeekBuffer == NULL))
    return 0;

  Tuint size = NAlgorithms::NCommon::min(a_cSize, m_PeekBufferFreeSize / sizeof(Twchar)) * sizeof(Twchar);
  Tuint peek_current_size = m_PeekBufferSize - m_PeekBufferFreeSize;

  // Read bytes from the reader into the peek buffer.
  size = onReadText((Twstr)(m_pPeekBuffer + peek_current_size), size / sizeof(Twchar)) * sizeof(Twchar);
  m_PeekBufferFreeSize -= size;

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return a_cSize - (size / sizeof(Twchar));
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tschar& a_rCharacter)
{ CALL
  return NDetails::CStreamHelper::inputChar(true, *this, a_rCharacter);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Twchar& a_rCharacter)
{ CALL
  return NDetails::CStreamHelper::inputChar(true, *this, a_rCharacter);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tsstr& a_rpString, const Tuint a_cSize/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::inputString(true, *this, a_rpString, a_cSize);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Twstr& a_rpString, const Tuint a_cSize/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::inputString(true, *this, a_rpString, a_cSize);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(NString::CStringASCII& a_rString, const Tuint a_cSize/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::inputString(true, *this, a_rString, a_cSize);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(NString::CStringUnicode& a_rString, const Tuint a_cSize/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::inputString(true, *this, a_rString, a_cSize);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(NString::CSystemString& a_rString, const Tuint a_cSize/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::inputString(true, *this, a_rString, a_cSize);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tbool& a_rBoolean, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputBool(true, *this, a_rBoolean, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tsint08& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(true, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tuint08& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(true, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tsint16& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(true, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tuint16& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(true, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tsint32& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(true, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tuint32& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(true, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tsint64& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(true, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tuint64& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputInteger(true, *this, a_rInteger, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tfloat& a_rReal, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputReal(true, *this, a_rReal, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tdouble& a_rReal, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputReal(true, *this, a_rReal, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peek(Tptr& a_rpPointer, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  return NDetails::CStreamHelper::inputPointer(true, *this, a_rpPointer, a_cParseFlags);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peekFormat(const Tcsstr a_cpFormatString, ...)
{ CALL
  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = peekFormatVarList(a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peekFormatVarList(const Tcsstr a_cpFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::inputFormat(true, *this, a_cpFormatString, NAlgorithms::NString::NBuffer::strLen(a_cpFormatString), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peekFormat(const Tcwstr a_cpFormatString, ...)
{ CALL
  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = peekFormatVarList(a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peekFormatVarList(const Tcwstr a_cpFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::inputFormat(true, *this, a_cpFormatString, NAlgorithms::NString::NBuffer::strLen(a_cpFormatString), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peekFormat(const NString::CStringASCII* a_cpFormatString, ...)
{ CALL
  // Check the given format string not to be NULL.
  ASSERT((a_cpFormatString != NULL), STR("Format string cannot be NULL."))
  {
    return NUtility::CPair<Tbool, Tuint>(false, 0);
  }

  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = peekFormatVarList(*a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peekFormatVarList(const NString::CStringASCII& a_crFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::inputFormat(true, *this, a_crFormatString.getBuffer(), a_crFormatString.getSize(), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peekFormat(const NString::CStringUnicode* a_cpFormatString, ...)
{ CALL
  // Check the given format string not to be NULL.
  ASSERT((a_cpFormatString != NULL), STR("Format string cannot be NULL."))
  {
    return NUtility::CPair<Tbool, Tuint>(false, 0);
  }

  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = peekFormatVarList(*a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peekFormatVarList(const NString::CStringUnicode& a_crFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::inputFormat(true, *this, a_crFormatString.getBuffer(), a_crFormatString.getSize(), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peekLineEnd()
{ CALL
  if (IStream::getCurrentParseFlags() & IStream::PARSE_ASCII)
    return NDetails::CStreamHelper::inputLineEndASCII(true, *this);
  else
    return NDetails::CStreamHelper::inputLineEndUnicode(true, *this);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peekLineEnd(const Tbool a_cIsASCII)
{ CALL
  if (a_cIsASCII)
    return NDetails::CStreamHelper::inputLineEndASCII(true, *this);
  else
    return NDetails::CStreamHelper::inputLineEndUnicode(true, *this);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peekToLineEnd()
{ CALL
  if (IStream::getCurrentParseFlags() & IStream::PARSE_ASCII)
    return NDetails::CStreamHelper::inputToLineEndASCII(true, *this);
  else
    return NDetails::CStreamHelper::inputToLineEndUnicode(true, *this);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::peekToLineEnd(const Tbool a_cIsASCII)
{ CALL
  if (a_cIsASCII)
    return NDetails::CStreamHelper::inputToLineEndASCII(true, *this);
  else
    return NDetails::CStreamHelper::inputToLineEndUnicode(true, *this);
}
/*--------------------------------------------------------------------------*/
Tuint IReader::pushBuffer(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot push the buffer into the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in binary mode.
  ASSERT(isBinaryMode(), STR("Cannot push the buffer into the reader opened in the text mode."))
  {
    return 0;
  }

  // Nothing to push.
  if (a_cSize == 0)
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot push from the buffer which is NULL."))
  {
    return 0;
  }

  // Nowhere to push.
  if ((m_PeekBufferSize == 0) || (m_PeekBufferFreeSize == 0) || (m_pPeekBuffer == NULL))
    return 0;

  Tuint size = NAlgorithms::NCommon::min(a_cSize, m_PeekBufferFreeSize);
  Tuint size_move = NAlgorithms::NCommon::min(size, (m_PeekBufferSize - m_PeekBufferFreeSize));

  // Move remain peek buffer bytes.
  NMemory::CMemory::move(m_pPeekBuffer + size, m_pPeekBuffer, size_move);

  // Copy bytes from the given buffer.
  NMemory::CMemory::copy(m_pPeekBuffer, a_cpBuffer, size);
  m_PeekBufferFreeSize -= size;

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return size;
}
/*--------------------------------------------------------------------------*/
Tuint IReader::pushBuffer(Tcptr a_cpBuffer, const Tuint a_cSingleSize, const Tuint a_cCount)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot push the buffer into the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in binary mode.
  ASSERT(isBinaryMode(), STR("Cannot push the buffer into the reader opened in the text mode."))
  {
    return 0;
  }

  // Nothing to push.
  if ((a_cSingleSize == 0) || (a_cCount == 0))
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot push from the buffer which is NULL."))
  {
    return 0;
  }

  #if defined(__BIG_ENDIAN__)
  if ((getByteOrder() == e_BYTE_ORDER_LITTLE_ENDIAN) && (a_cSingleSize > 1))
  #else
  if ((getByteOrder() != e_BYTE_ORDER_LITTLE_ENDIAN) && (a_cSingleSize > 1))
  #endif
  {
    Tuint result = 0;

    if (a_cCount > 0)
    {
      Tuint counter = a_cCount;
      Tcbuffer buffer = (Tcbuffer)a_cpBuffer;

      // Push all items.
      while (counter-- > 0)
      {
        Tuint local_counter = a_cSingleSize;
        Tcbuffer local_buffer = buffer + a_cSingleSize - 1;

        // Push single item.
        while (local_counter-- > 0)
          if (pushBuffer((Tcptr)local_buffer--, 1) != 1)
            return result + a_cSingleSize - local_counter - 1;

        result += a_cSingleSize;
        buffer += a_cSingleSize;
      }
    }
    return result;
  }
  else
    return pushBuffer(a_cpBuffer, a_cSingleSize * a_cCount);
}
/*--------------------------------------------------------------------------*/
Tuint IReader::pushBuffer(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot push the buffer into the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in text mode.
  ASSERT(isTextMode(), STR("Cannot push the buffer into the reader opened in the binary mode."))
  {
    return 0;
  }

  // Nothing to push.
  if (a_cSize == 0)
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot push from the buffer which is NULL."))
  {
    return 0;
  }

  // Nowhere to push.
  if ((m_PeekBufferSize == 0) || (m_PeekBufferFreeSize < sizeof(Tschar)) || (m_pPeekBuffer == NULL))
    return 0;

  Tuint size = NAlgorithms::NCommon::min(a_cSize * sizeof(Tschar), m_PeekBufferFreeSize);
  Tuint size_move = NAlgorithms::NCommon::min(size, (m_PeekBufferSize - m_PeekBufferFreeSize));

  // Move remain peek buffer bytes.
  NMemory::CMemory::move(m_pPeekBuffer + size, m_pPeekBuffer, size_move);

  // Copy bytes from the given buffer.
  #if defined(__BIG_ENDIAN__)
  if ((getByteOrder() == e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Tschar) > 1))
  #else
  if ((getByteOrder() != e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Tschar) > 1))
  #endif
  {
    Tuint counter = size / sizeof(Tschar);
    Tbuffer dst_buffer = m_pPeekBuffer;
    Tcsstr src_buffer = a_cpBuffer;

    // Copy all items.
    while (counter-- > 0)
    {
      NMemory::CMemory::copyReverse(dst_buffer, src_buffer, sizeof(Tschar));
      dst_buffer += sizeof(Tschar);
      src_buffer += sizeof(Tschar);
    }
  }
  else
    NMemory::CMemory::copy(m_pPeekBuffer, a_cpBuffer, size);
  m_PeekBufferFreeSize -= size;

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return size / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
Tuint IReader::pushBuffer(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot push the buffer into the closed reader."))
  {
    return 0;
  }
  // Check if the current reader is opened in text mode.
  ASSERT(isTextMode(), STR("Cannot push the buffer into the reader opened in the binary mode."))
  {
    return 0;
  }

  // Nothing to push.
  if (a_cSize == 0)
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot push from the buffer which is NULL."))
  {
    return 0;
  }

  // Nowhere to push.
  if ((m_PeekBufferSize == 0) || (m_PeekBufferFreeSize < sizeof(Twchar)) || (m_pPeekBuffer == NULL))
    return 0;

  Tuint size = NAlgorithms::NCommon::min(a_cSize * sizeof(Twchar), m_PeekBufferFreeSize);
  Tuint size_move = NAlgorithms::NCommon::min(size, (m_PeekBufferSize - m_PeekBufferFreeSize));

  // Move remain peek buffer bytes.
  NMemory::CMemory::move(m_pPeekBuffer + size, m_pPeekBuffer, size_move);

  // Copy bytes from the given buffer.
  #if defined(__BIG_ENDIAN__)
  if ((getByteOrder() == e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Twchar) > 1))
  #else
  if ((getByteOrder() != e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Twchar) > 1))
  #endif
  {
    Tuint counter = size / sizeof(Twchar);
    Tbuffer dst_buffer = m_pPeekBuffer;
    Tcwstr src_buffer = a_cpBuffer;

    // Copy all items.
    while (counter-- > 0)
    {
      NMemory::CMemory::copyReverse(dst_buffer, src_buffer, sizeof(Twchar));
      dst_buffer += sizeof(Twchar);
      src_buffer += sizeof(Twchar);
    }
  }
  else
    NMemory::CMemory::copy(m_pPeekBuffer, a_cpBuffer, size);
  m_PeekBufferFreeSize -= size;

  // Auto-flush reader.
  if (isAutoFlush())
    flush();

  return size / sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tschar a_cCharacter)
{ CALL
  return NDetails::CStreamHelper::outputChar(*this, a_cCharacter);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Twchar a_cCharacter)
{ CALL
  return NDetails::CStreamHelper::outputChar(*this, a_cCharacter);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tcsstr a_cpString)
{ CALL
  return NDetails::CStreamHelper::outputString(*this, a_cpString);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tcwstr a_cpString)
{ CALL
  return NDetails::CStreamHelper::outputString(*this, a_cpString);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const NString::CStringASCII& a_crString)
{ CALL
  return NDetails::CStreamHelper::outputString(*this, a_crString);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const NString::CStringUnicode& a_crString)
{ CALL
  return NDetails::CStreamHelper::outputString(*this, a_crString);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const NString::CSystemString& a_crString)
{ CALL
  return NDetails::CStreamHelper::outputString(*this, a_crString);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tbool a_cBoolean, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputBool(*this, a_cBoolean, a_cFormatFlags, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tsint08 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tuint08 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tsint16 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tuint16 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tsint32 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tuint32 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tsint64 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tuint64 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tfloat a_cReal, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cPrecision/* = 6 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputReal(*this, a_cReal, a_cFormatFlags, a_cPrecision, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(const Tdouble a_cReal, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cPrecision/* = 6 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputReal(*this, a_cReal, a_cFormatFlags, a_cPrecision, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::push(Tcptr a_cpPointer, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputPointer(*this, a_cpPointer, a_cFormatFlags, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::pushFormat(const Tcsstr a_cpFormatString, ...)
{ CALL
  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = pushFormatVarList(a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::pushFormatVarList(const Tcsstr a_cpFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::outputFormat(*this, a_cpFormatString, NAlgorithms::NString::NBuffer::strLen(a_cpFormatString), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::pushFormat(const Tcwstr a_cpFormatString, ...)
{ CALL
  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = pushFormatVarList(a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::pushFormatVarList(const Tcwstr a_cpFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::outputFormat(*this, a_cpFormatString, NAlgorithms::NString::NBuffer::strLen(a_cpFormatString), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::pushFormat(const NString::CStringASCII* a_cpFormatString, ...)
{ CALL
  // Check the given format string not to be NULL.
  ASSERT((a_cpFormatString != NULL), STR("Format string cannot be NULL."))
  {
    return NUtility::CPair<Tbool, Tuint>(false, 0);
  }

  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = pushFormatVarList(*a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::pushFormatVarList(const NString::CStringASCII& a_crFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::outputFormat(*this, a_crFormatString.getBuffer(), a_crFormatString.getSize(), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::pushFormat(const NString::CStringUnicode* a_cpFormatString, ...)
{ CALL
  // Check the given format string not to be NULL.
  ASSERT((a_cpFormatString != NULL), STR("Format string cannot be NULL."))
  {
    return NUtility::CPair<Tbool, Tuint>(false, 0);
  }

  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = pushFormatVarList(*a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::pushFormatVarList(const NString::CStringUnicode& a_crFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::outputFormat(*this, a_crFormatString.getBuffer(), a_crFormatString.getSize(), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::pushLineEnd()
{ CALL
  if (IStream::getCurrentFormatFlags() & IStream::FORMAT_ASCII)
    return push(getLineEndingStringASCII());
  else
    return push(getLineEndingStringUnicode());
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IReader::pushLineEnd(const Tbool a_cIsASCII)
{ CALL
  if (a_cIsASCII)
    return push(getLineEndingStringASCII());
  else
    return push(getLineEndingStringUnicode());
}
/*--------------------------------------------------------------------------*/
Tbool IReader::flush()
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot flush the closed reader."))
  {
    return false;
  }

  return onFlush();
}
/*--------------------------------------------------------------------------*/
Tbool IReader::close()
{ CALL
  // Check if the current reader is opened.
  ASSERT(isOpened(), STR("Cannot close the reader which is already closed."))
  {
    return false;
  }

  // Flush reader before close.
  if (!isAutoFlush() && !flush())
    return false;

  // Close the reader and reset its parameters.
  if (onClose())
  {
    m_IsOpened = false;
    m_IsEOF = false;
    m_ReadBytesCount = 0;

    // Free peek buffer.
    if ((m_PeekBufferSize > 0) && (m_pPeekBuffer != NULL))
    {
      delete [] m_pPeekBuffer;
      m_pPeekBuffer = NULL;
    }
    return true;
  }
  else
    return false;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
