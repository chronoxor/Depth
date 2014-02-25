/*!
 *  \file    IExchangeWriter.cpp Exchange stream writer is a base interface
 *           for all implementations of exchange stream classes which use
 *           interprocess communication byte output (files, pipes, sockets,
 *           etc.).
 *  \brief   Exchange writer interface (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Exchange writer interface (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   26.03.2009 22:22:34

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
#include <Depth/include/stream/IExchangeWriter.hpp>
/*==========================================================================*/
#ifndef __IEXCHANGEWRITER_CPP__
#define __IEXCHANGEWRITER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INTERFACE IMPLEMENTATIONS                                                */
/*==========================================================================*/
Tbool IExchangeWriter::set(const IExchangeWriter& a_crInstance)
{ CALL
  // Check if the given interface instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same IExchangeWriter interface instance."))
  {
    return false;
  }

  // Close opened exchange writer.
  if (isOpened())
    if (!close())
      return false;

  // Initialize new exchange stream.
  IExchangeStream::set(a_crInstance);

  // Initialize new writer.
  return IWriter::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tbool IExchangeWriter::setExchange(const Tbool a_cIsExchange)
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
Tbool IExchangeWriter::onOpen()
{ CALL
  // Check if the current writer is an exchange one.
  ASSERT(isExchange(), STR("Open method of the exchange writer should be called only in the exchange mode."))
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

  // Initialize writer for output.
  IWriter::m_IsOpened = true;
  IWriter::m_IsEOF = false;
  IWriter::m_WrittenBytesCount = 0;

  // Write header of the exchange stream.
  if (result && !IWriter::write(exchangeGetVersion()).getFirst())
    result = false;
  if (result && !IWriter::write(exchangeIsBigEndian()).getFirst())
    result = false;
  if (result && !IWriter::write(exchangeGetSCharSize()).getFirst())
    result = false;
  if (result && !IWriter::write(exchangeGetWCharSize()).getFirst())
    result = false;
  if (result && !IWriter::write(exchangeGetSIntSize()).getFirst())
    result = false;
  if (result && !IWriter::write(exchangeGetUIntSize()).getFirst())
    result = false;
  if (result && !IWriter::write(exchangeGetPtrSize()).getFirst())
    result = false;
  if (result && !IWriter::write(exchangeIsRealFloat()).getFirst())
    result = false;

  // Restore parameters of the current exchange stream.
  (is_text_mode ? IStream::setTextMode() : IStream::setBinaryMode());
  IStream::setByteOrder(order);

  return result;
}
/*--------------------------------------------------------------------------*/
Tuint IExchangeWriter::onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current writer is an exchange one.
  ASSERT(isExchange(), STR("ASCII text write method of the exchange writer should be called only in the exchange mode."))
  {
    return 0;
  }

  return onWriteBinary(a_cpBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
Tuint IExchangeWriter::onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current writer is an exchange one.
  ASSERT(isExchange(), STR("Unicode text write method of the exchange writer should be called only in the exchange mode."))
  {
    return 0;
  }

  NDepth::NTypes::Tuint wc;
  NDepth::NTypes::Tuint result = 0;
  NDepth::NTypes::Tbyte temp_buffer[6] = { 0, 0, 0, 0, 0, 0 };
  NDepth::NTypes::Tcbuffer buffer = (NDepth::NTypes::Tcbuffer)a_cpBuffer;

  // Write Unicode text buffer.
  while (result < a_cSize)
  {
    // Convert from the source buffer.
    #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
    #if defined(__BIG_ENDIAN__)
    if ((buffer[0] >= 0xD8) && (buffer[0] < 0xE0))
    {
      WARNING(STR("Text from the buffer contains invalid Unicode character (character code is %hU).") COMMA (NDepth::NTypes::Tuint)buffer[0]);
      break;
    }
    wc = (buffer[0] << 8) + buffer[1];
    #else
    if ((buffer[1] >= 0xD8) && (buffer[1] < 0xE0))
    {
      WARNING(STR("Text from the buffer contains invalid Unicode character (character code is %hU).") COMMA (NDepth::NTypes::Tuint)buffer[1]);
      break;
    }
    wc = buffer[0] + (buffer[1] << 8);
    #endif
    buffer += 2;
    #else
    #if defined(__BIG_ENDIAN__)
    wc = (buffer[0] << 24) + (buffer[1] << 16) + (buffer[2] << 8) + buffer[3];
    #else
    wc = buffer[0] + (buffer[1] << 8) + (buffer[2] << 16) + (buffer[3] << 24);
    #endif
    buffer += 4;
    #endif

    // Convert into the UTF-8 and write.
    NDepth::NTypes::Tuint length = 0;
    if (wc < 0x80)
      length = 1;
    else if (wc < 0x800)
      length = 2;
    else if (wc < 0x10000)
      length = 3;
    else if (wc < 0x200000)
      length = 4;
    else if (wc < 0x4000000)
      length = 5;
    else if (wc <= 0x7FFFFFFF)
      length = 6;
    else
    {
      WARNING(STR("Text from the buffer contains invalid UTF-8 character (character code is %hU).") COMMA wc);
      break;
    }

    switch (length)
    {
      case 6: temp_buffer[5] = (NDepth::NTypes::Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x4000000;
      case 5: temp_buffer[4] = (NDepth::NTypes::Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x200000;
      case 4: temp_buffer[3] = (NDepth::NTypes::Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x10000;
      case 3: temp_buffer[2] = (NDepth::NTypes::Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x800;
      case 2: temp_buffer[1] = (NDepth::NTypes::Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0xC0;
      case 1: temp_buffer[0] = (NDepth::NTypes::Tbyte)(wc);
    }

    // Write next UTF-8 characters.
    if (onWriteBinary(temp_buffer, length) != length)
      break;

    ++result;
  }
  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
