/*!
 *  \file    IExchangeReader.cpp Exchange stream reader is a base interface
 *           for all implementations of exchange stream classes which use
 *           interprocess communication byte input (files, pipes, sockets,
 *           etc.).
 *  \brief   Exchange reader interface (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Exchange reader interface (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   26.03.2009 22:03:02

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
#include <Depth/include/stream/IExchangeReader.hpp>
/*==========================================================================*/
#ifndef __IEXCHANGEREADER_CPP__
#define __IEXCHANGEREADER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INTERFACE IMPLEMENTATIONS                                                */
/*==========================================================================*/
Tbool IExchangeReader::set(const IExchangeReader& a_crInstance)
{ CALL
  // Check if the given interface instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same IExchangeReader interface instance."))
  {
    return false;
  }

  // Close opened exchange reader.
  if (isOpened())
    if (!close())
      return false;

  // Initialize new exchange stream.
  IExchangeStream::set(a_crInstance);

  // Initialize new reader.
  return IReader::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tbool IExchangeReader::setExchange(const Tbool a_cIsExchange)
{ CALL
  // Check if the current exchange stream not is opened.
  ASSERT(!isOpened(), STR("Cannot set exchange flag of the opened stream."))
  {
    return false;
  }

  m_IsExchange = a_cIsExchange;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool IExchangeReader::onOpen()
{ CALL
  // Check if the current reader is an exchange one.
  ASSERT(isExchange(), STR("Open method of the exchange reader should be called only in the exchange mode."))
  {
    return false;
  }

  Tbool result = true;

  // Store parameters of the current exchange stream.
  Tbool is_text_mode = IStream::isTextMode();
  EByteOrder order = IStream::getByteOrder();

  // Temporary set new parameters of the current exchange stream.
  IStream::setBinaryMode();
  IStream::setByteOrder(IStream::e_BYTE_ORDER_UNIVERSAL);

  // Initialize reader for input.
  IReader::m_IsOpened = true;
  IReader::m_IsEOF = false;
  IReader::m_ReadBytesCount = 0;

  // Read header of the exchange stream.
  Tuint version = 0;
  if (result && IReader::read(version).getFirst())
    m_Version = version;
  else
    result = false;

  Tbool is_big_endian = false;
  if (result && IReader::read(is_big_endian).getFirst())
    IStream::setByteOrder(is_big_endian ? IStream::e_BYTE_ORDER_BIG_ENDIAN : IStream::e_BYTE_ORDER_LITTLE_ENDIAN);
  else
    result = false;

  Tuint schar_size = 0;
  if (result && IReader::read(schar_size).getFirst())
    m_SCharSize = schar_size;
  else
    result = false;

  Tuint wchar_size = 0;
  if (result && IReader::read(wchar_size).getFirst())
    m_WCharSize = wchar_size;
  else
    result = false;

  Tuint sint_size = 0;
  if (result && IReader::read(sint_size).getFirst())
    m_SIntSize = sint_size;
  else
    result = false;

  Tuint uint_size = 0;
  if (result && IReader::read(uint_size).getFirst())
    m_UIntSize = uint_size;
  else
    result = false;

  Tuint ptr_size = 0;
  if (result && IReader::read(ptr_size).getFirst())
    m_PtrSize = ptr_size;
  else
    result = false;

  Tbool is_real_float = 0;
  if (result && IReader::read(is_real_float).getFirst())
    m_IsRealFloat = is_real_float;
  else
    result = false;

  // Restore parameters of the current exchange stream.
  (is_text_mode ? IStream::setTextMode() : IStream::setBinaryMode());
  IStream::setByteOrder(order);

  return result;
}
/*--------------------------------------------------------------------------*/
Tuint IExchangeReader::onReadText(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is an exchange one.
  ASSERT(isExchange(), STR("ASCII text read method of the exchange reader should be called only in the exchange mode."))
  {
    return 0;
  }

  return onReadBinary(a_pBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
Tuint IExchangeReader::onReadText(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is an exchange one.
  ASSERT(isExchange(), STR("Unicode text read method of the exchange reader should be called only in the exchange mode."))
  {
    return 0;
  }

  NDepth::NTypes::Tuint wc;
  NDepth::NTypes::Tuint result = 0;
  NDepth::NTypes::Tbyte temp_buffer[6] = { 0, 0, 0, 0, 0, 0 };
  NDepth::NTypes::Tbuffer buffer = (NDepth::NTypes::Tbuffer)a_pBuffer;

  // Read Unicode text buffer.
  while (result < a_cSize)
  {
    // Read next UTF-8 character.
    if (onReadBinary(temp_buffer, 1) != 1)
      break;

    // Check if additional bytes should be read.
    NDepth::NTypes::Tbyte c = temp_buffer[0];
    NDepth::NTypes::Tuint length = 0;
    if (c < 0x80)
      length = 0;
    else if (c < 0xC2)
    {
      WARNING(STR("Text from the exchange stream contains invalid UTF-8 character (character code is %hU).") COMMA (NDepth::NTypes::Tuint)c);
      break;
    }
    else if (c < 0xE0)
      length = 1;
    else if (c < 0xF0)
      length = 2;
    else if (c < 0xF8)
      length = 3;
    else if (c < 0xFC)
      length = 4;
    else if (c < 0xFE)
      length = 5;
    else
    {
      WARNING(STR("Text from the exchange stream contains invalid UTF-8 character (character code is %hU).") COMMA (NDepth::NTypes::Tuint)c);
      break;
    }

    // Read next UTF-8 characters.
    if (onReadBinary(temp_buffer + 1, length) != length)
      break;

    // Calculate Unicode character.
    c = temp_buffer[0];
    if (c < 0x80)
      wc = c;
    else if (c < 0xE0)
    {
      if (!((temp_buffer[1] ^ 0x80) < 0x40))
      {
        WARNING(STR("Text from the exchange stream contains invalid UTF-8 sequence."));
        break;
      }
      wc = ((c & 0x1F) << 6) | (temp_buffer[1] ^ 0x80);
    }
    else if (c < 0xF0)
    {
      if (!(((temp_buffer[1] ^ 0x80) < 0x40) && ((temp_buffer[2] ^ 0x80) < 0x40) && ((c >= 0xE1) || (temp_buffer[1] >= 0xA0))))
      {
        WARNING(STR("Text from the exchange stream contains invalid UTF-8 sequence."));
        break;
      }
      wc = ((c & 0x0F) << 12) | ((temp_buffer[1] ^ 0x80) << 6) | (temp_buffer[2] ^ 0x80);
    }
    else if (c < 0xF8)
    {
      if (!(((temp_buffer[1] ^ 0x80) < 0x40) && ((temp_buffer[2] ^ 0x80) < 0x40) && ((temp_buffer[3] ^ 0x80) < 0x40) && ((c >= 0xF1) || (temp_buffer[1] >= 0x90))))
      {
        WARNING(STR("Text from the exchange stream contains invalid UTF-8 sequence."));
        break;
      }
      wc = ((c & 0x07) << 18) | ((temp_buffer[1] ^ 0x80) << 12) | ((temp_buffer[2] ^ 0x80) << 6) | (temp_buffer[3] ^ 0x80);
    }
    else if (c < 0xFC)
    {
      if (!(((temp_buffer[1] ^ 0x80) < 0x40) && ((temp_buffer[2] ^ 0x80) < 0x40) && ((temp_buffer[3] ^ 0x80) < 0x40) && ((temp_buffer[4] ^ 0x80) < 0x40) && ((c >= 0xF9) || (temp_buffer[1] >= 0x88))))
      {
        WARNING(STR("Text from the exchange stream contains invalid UTF-8 sequence."));
        break;
      }
      wc = ((c & 0x03) << 24) | ((temp_buffer[1] ^ 0x80) << 18) | ((temp_buffer[2] ^ 0x80) << 12) | ((temp_buffer[3] ^ 0x80) << 6) | (temp_buffer[4] ^ 0x80);
    }
    else if (c < 0xFE)
    {
      if (!(((temp_buffer[1] ^ 0x80) < 0x40) && ((temp_buffer[2] ^ 0x80) < 0x40) && ((temp_buffer[3] ^ 0x80) < 0x40) && ((temp_buffer[4] ^ 0x80) < 0x40) && ((temp_buffer[5] ^ 0x80) < 0x40) && ((c >= 0xFD) || (temp_buffer[1] >= 0x84))))
      {
        WARNING(STR("Text from the exchange stream contains invalid UTF-8 sequence."));
        break;
      }
      wc = ((c & 0x01) << 30) | ((temp_buffer[1] ^ 0x80) << 24) | ((temp_buffer[2] ^ 0x80) << 18) | ((temp_buffer[3] ^ 0x80) << 12) | ((temp_buffer[4] ^ 0x80) << 6) | (temp_buffer[5] ^ 0x80);
    }

    // Convert into the destination buffer.
    #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
    if ((wc < 0x10000) && !((wc >= 0xD800) && (wc < 0xE000)))
    {
      #if defined(__BIG_ENDIAN__)
      *buffer++ = (NDepth::NTypes::Tbyte)(wc >> 8);
      *buffer++ = (NDepth::NTypes::Tbyte)(wc);
      #else
      *buffer++ = (NDepth::NTypes::Tbyte)(wc);
      *buffer++ = (NDepth::NTypes::Tbyte)(wc >> 8);
      #endif
      ++result;
    }
    else
    {
      WARNING(STR("Text from the exchange stream contains invalid UTF-16 character (character code is %hU).") COMMA wc);
      break;
    }
    #else
    #if defined(__BIG_ENDIAN__)
    *buffer++ = (NDepth::NTypes::Tbyte)(wc >> 24);
    *buffer++ = (NDepth::NTypes::Tbyte)(wc >> 16);
    *buffer++ = (NDepth::NTypes::Tbyte)(wc >> 8);
    *buffer++ = (NDepth::NTypes::Tbyte)(wc);
    #else
    *buffer++ = (NDepth::NTypes::Tbyte)(wc);
    *buffer++ = (NDepth::NTypes::Tbyte)(wc >> 8);
    *buffer++ = (NDepth::NTypes::Tbyte)(wc >> 16);
    *buffer++ = (NDepth::NTypes::Tbyte)(wc >> 24);
    #endif
    ++result;
    #endif
  }
  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
