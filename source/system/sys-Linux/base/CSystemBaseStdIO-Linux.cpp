/*!
 *  \file    CSystemBaseStdIO-Linux.cpp Base system class contains common
 *           functionality such as memory routines, math functions, error
 *           handling, standard I/O routines.
 *  \brief   Base system class - Linux OS - standard I/O streams methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Linux OS - standard I/O streams methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   01.09.2008 00:48:20

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
#include <Depth/include/base/CInteger.hpp>
#include <Depth/include/system/CSystemBase.hpp>
/*--------------------------------------------------------------------------*/
#include "../Linux.hpp"
/*==========================================================================*/
#ifndef __CSYSTEMBASESTDIO_LINUX_CPP__
#define __CSYSTEMBASESTDIO_LINUX_CPP__
/*==========================================================================*/
#if (defined(__UNIX__) && defined(__LINUX__))
/*==========================================================================*/
/* LOCAL NAMESPACE DECLARATIONS                                             */
/*==========================================================================*/
namespace {
/*==========================================================================*/
/* LOCAL FUNCTIONS DECLARATIONS & IMPLEMENTATIONS                           */
/*==========================================================================*/
//! Read buffer of bytes from the standard stream.
/*!
    \param a_pHandle - Handle of the standard stream.
    \param a_pBuffer - Pointer to the byte buffer.
    \param a_cSize - Size of buffer (in bytes).
    \return Count of read bytes.
*/
NDepth::NTypes::Tuint stdReadBinary(STDIO_FILE* a_pHandle, NDepth::NTypes::Tptr a_pBuffer, const NDepth::NTypes::Tuint a_cSize)
{ CALL
  // Check if the given buffer is not NULL.
  ASSERT((a_pBuffer != NULL), STR("Cannot read into the buffer which is NULL."))
  {
    return false;
  }

  // Nothing to read.
  if (a_cSize == 0)
    return 0;

  // Read byte buffer.
  NDepth::NTypes::Tuint read = fread(a_pBuffer, 1, a_cSize, a_pHandle);
  if (ferror(a_pHandle) != 0)
  {
    clearerr(a_pHandle);
    WARNING(STR("Cannot read bytes from the standard stream (requested size is %u bytes, read size is %u bytes).") COMMA a_cSize COMMA read);
  }
  return read;
}
/*--------------------------------------------------------------------------*/
//! Write buffer of bytes into the standard stream.
/*!
    \param a_pHandle - Handle of the standard stream.
    \param a_cpBuffer - Constant pointer to the byte buffer.
    \param a_cSize - Size of buffer (in bytes).
    \return Count of written bytes.
*/
NDepth::NTypes::Tuint stdWriteBinary(STDIO_FILE* a_pHandle, NDepth::NTypes::Tcptr a_cpBuffer, const NDepth::NTypes::Tuint a_cSize)
{ CALL
  // Check if the given buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot write from the buffer which is NULL."))
  {
    return false;
  }

  // Nothing to write.
  if (a_cSize == 0)
    return 0;

  // Write byte buffer.
  NDepth::NTypes::Tuint written = fwrite(a_cpBuffer, 1, a_cSize, a_pHandle);
  if (ferror(a_pHandle) != 0)
  {
    clearerr(a_pHandle);
    WARNING(STR("Cannot write bytes into the standard stream (requested size is %u bytes, written size is %u bytes).") COMMA a_cSize COMMA written);
  }
  return written;
}
/*--------------------------------------------------------------------------*/
//! Read buffer of ASCII text from the standard stream.
/*!
    \param a_pHandle - Handle of the standard stream.
    \param a_pBuffer - Pointer to the ASCII text buffer.
    \param a_cSize - Size of ASCII text buffer (in characters).
    \return Count of read characters.
*/
NDepth::NTypes::Tuint stdReadText(STDIO_FILE* a_pHandle, NDepth::NTypes::Tsstr a_pBuffer, const NDepth::NTypes::Tuint a_cSize)
{ CALL
  // Check if the given buffer is not NULL.
  ASSERT((a_pBuffer != NULL), STR("Cannot read into the buffer which is NULL."))
  {
    return false;
  }

  // Nothing to read.
  if (a_cSize == 0)
    return 0;

  // Read ASCII text buffer.
  NDepth::NTypes::Tuint read = fread(a_pBuffer, sizeof(NDepth::NTypes::Tschar), a_cSize, a_pHandle);
  if (ferror(a_pHandle) != 0)
  {
    clearerr(a_pHandle);
    WARNING(STR("Cannot read ASCII text from the standard stream (requested size is %u bytes, read size is %u bytes).") COMMA a_cSize COMMA read);
  }
  return read;
}
/*--------------------------------------------------------------------------*/
//! Read buffer of Unicode text from the standard stream.
/*!
    \param a_pHandle - Handle of the standard stream.
    \param a_pBuffer - Pointer to the Unicode text buffer.
    \param a_cSize - Size of Unicode text buffer (in characters).
    \return Count of read characters.
*/
NDepth::NTypes::Tuint stdReadText(STDIO_FILE* a_pHandle, NDepth::NTypes::Twstr a_pBuffer, const NDepth::NTypes::Tuint a_cSize)
{ CALL
  // Check if the given buffer is not NULL.
  ASSERT((a_pBuffer != NULL), STR("Cannot read into the buffer which is NULL."))
  {
    return false;
  }

  // Nothing to read.
  if (a_cSize == 0)
    return 0;

  NDepth::NTypes::Tuint wc;
  NDepth::NTypes::Tuint result = 0;
  NDepth::NTypes::Tbyte temp_buffer[6] = { 0, 0, 0, 0, 0, 0 };
  NDepth::NTypes::Tbuffer buffer = (NDepth::NTypes::Tbuffer)a_pBuffer;

  // Read Unicode text buffer.
  while (result < a_cSize)
  {
    // Read next UTF-8 character.
    NDepth::NTypes::Tuint read = fread(temp_buffer, 1, 1, a_pHandle);
    if (ferror(a_pHandle) != 0)
    {
      clearerr(a_pHandle);
      WARNING(STR("Cannot read Unicode text from the standard stream (requested size is %u bytes, read size is %u bytes).") COMMA 1 COMMA read);
      break;
    }
    else if (read != 1)
      break;


    // Check if additional bytes should be read.
    NDepth::NTypes::Tbyte c = temp_buffer[0];
    NDepth::NTypes::Tuint length = 0;
    if (c < 0x80)
      length = 1;
    else if (c < 0xC2)
    {
      WARNING(STR("Text from the standard stream contains invalid UTF-8 character (character code is %hU).") COMMA (NDepth::NTypes::Tuint)c);
      break;
    }
    else if (c < 0xE0)
      length = 2;
    else if (c < 0xF0)
      length = 3;
    else if (c < 0xF8)
      length = 4;
    else if (c < 0xFC)
      length = 5;
    else if (c < 0xFE)
      length = 6;
    else
    {
      WARNING(STR("Text from the standard stream contains invalid UTF-8 character (character code is %hU).") COMMA (NDepth::NTypes::Tuint)c);
      break;
    }

    // Read next UTF-8 characters.
    read = fread(temp_buffer + 1, 1, --length, a_pHandle);
    if (ferror(a_pHandle) != 0)
    {
      clearerr(a_pHandle);
      WARNING(STR("Cannot read Unicode text from the standard stream (requested size is %u bytes, read size is %u bytes).") COMMA length COMMA read);
      break;
    }
    else if (read != length)
      break;

    // Calculate Unicode character.
    c = temp_buffer[0];
    if (c < 0x80)
      wc = c;
    else if (c < 0xE0)
    {
      if (!((temp_buffer[1] ^ 0x80) < 0x40))
      {
        WARNING(STR("Text from the standard stream contains invalid UTF-8 sequence."));
        break;
      }
      wc = ((c & 0x1F) << 6) | (temp_buffer[1] ^ 0x80);
    }
    else if (c < 0xF0)
    {
      if (!(((temp_buffer[1] ^ 0x80) < 0x40) && ((temp_buffer[2] ^ 0x80) < 0x40) && ((c >= 0xE1) || (temp_buffer[1] >= 0xA0))))
      {
        WARNING(STR("Text from the standard stream contains invalid UTF-8 sequence."));
        break;
      }
      wc = ((c & 0x0F) << 12) | ((temp_buffer[1] ^ 0x80) << 6) | (temp_buffer[2] ^ 0x80);
    }
    else if (c < 0xF8)
    {
      if (!(((temp_buffer[1] ^ 0x80) < 0x40) && ((temp_buffer[2] ^ 0x80) < 0x40) && ((temp_buffer[3] ^ 0x80) < 0x40) && ((c >= 0xF1) || (temp_buffer[1] >= 0x90))))
      {
        WARNING(STR("Text from the standard stream contains invalid UTF-8 sequence."));
        break;
      }
      wc = ((c & 0x07) << 18) | ((temp_buffer[1] ^ 0x80) << 12) | ((temp_buffer[2] ^ 0x80) << 6) | (temp_buffer[3] ^ 0x80);
    }
    else if (c < 0xFC)
    {
      if (!(((temp_buffer[1] ^ 0x80) < 0x40) && ((temp_buffer[2] ^ 0x80) < 0x40) && ((temp_buffer[3] ^ 0x80) < 0x40) && ((temp_buffer[4] ^ 0x80) < 0x40) && ((c >= 0xF9) || (temp_buffer[1] >= 0x88))))
      {
        WARNING(STR("Text from the standard stream contains invalid UTF-8 sequence."));
        break;
      }
      wc = ((c & 0x03) << 24) | ((temp_buffer[1] ^ 0x80) << 18) | ((temp_buffer[2] ^ 0x80) << 12) | ((temp_buffer[3] ^ 0x80) << 6) | (temp_buffer[4] ^ 0x80);
    }
    else if (c < 0xFE)
    {
      if (!(((temp_buffer[1] ^ 0x80) < 0x40) && ((temp_buffer[2] ^ 0x80) < 0x40) && ((temp_buffer[3] ^ 0x80) < 0x40) && ((temp_buffer[4] ^ 0x80) < 0x40) && ((temp_buffer[5] ^ 0x80) < 0x40) && ((c >= 0xFD) || (temp_buffer[1] >= 0x84))))
      {
        WARNING(STR("Text from the standard stream contains invalid UTF-8 sequence."));
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
      WARNING(STR("Text from the standard stream contains invalid UTF-16 character (character code is %hU).") COMMA wc);
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
/*--------------------------------------------------------------------------*/
//! Write buffer of ASCII text into the standard stream.
/*!
    \param a_pHandle - Handle of the standard stream.
    \param a_cpBuffer - Constant pointer to the ASCII text buffer.
    \param a_cSize - Size of the ASCII buffer (in characters).
    \return Count of written characters.
*/
NDepth::NTypes::Tuint stdWriteText(STDIO_FILE* a_pHandle, NDepth::NTypes::Tcsstr a_cpBuffer, const NDepth::NTypes::Tuint a_cSize)
{ CALL
  // Check if the given buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot write into the buffer which is NULL."))
  {
    return false;
  }

  // Nothing to write.
  if (a_cSize == 0)
    return 0;

  // Write ASCII text buffer.
  NDepth::NTypes::Tuint written = fwrite(a_cpBuffer, sizeof(NDepth::NTypes::Tschar), a_cSize, a_pHandle);
  if (ferror(a_pHandle) != 0)
  {
    clearerr(a_pHandle);
    WARNING(STR("Cannot write ASCII text into the standard stream (requested size is %u bytes, written size is %u bytes).") COMMA a_cSize COMMA written);
  }
  return written;
}
/*--------------------------------------------------------------------------*/
//! Write buffer of Unicode text into the standard stream.
/*!
    \param a_pHandle - Handle of the standard stream.
    \param a_cpBuffer - Constant pointer to the Unicode text buffer.
    \param a_cSize - Size of the Unicode buffer (in characters).
    \return Count of written characters.
*/
NDepth::NTypes::Tuint stdWriteText(STDIO_FILE* a_pHandle, NDepth::NTypes::Tcwstr a_cpBuffer, const NDepth::NTypes::Tuint a_cSize)
{ CALL
  // Check if the given buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot write from the buffer which is NULL."))
  {
    return false;
  }

  // Nothing to write.
  if (a_cSize == 0)
    return 0;

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
    NDepth::NTypes::Tuint written = fwrite(temp_buffer, 1, length, a_pHandle);
    if (ferror(a_pHandle) != 0)
    {
      clearerr(a_pHandle);
      WARNING(STR("Cannot write Unicode text into the standard stream (requested size is %u bytes, written size is %u bytes).") COMMA length COMMA written);
      break;
    }
    else if (written != length)
      break;
    ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
//! Flush standard stream.
/*!
    \param a_pHandle - Handle of the standard stream.
    \return true  - if standard stream was successfully flushed. \n
            false - if standard stream was not successfully flushed. \n
*/
NDepth::NTypes::Tbool stdFlush(STDIO_FILE* a_pHandle)
{ CALL
  if (fflush(a_pHandle) == 0)
    return true;
  else
  {
    WARNING(STR("Cannot flush the standard stream."));
    return false;
  }
}
/*==========================================================================*/
}
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tuint CSystemBase::stdErrorWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdErrorLocker);

  return stdWriteBinary(stderr, a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdErrorWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdErrorLocker);

  return stdWriteText(stderr, a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdErrorWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdErrorLocker);

  return stdWriteText(stderr, a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::stdErrorFlush()
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdErrorLocker);

  return stdFlush(stderr);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdInputReadBinary(Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdInputLocker);

  return stdReadBinary(stdin, a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdInputReadText(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdInputLocker);

  return stdReadText(stdin, a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdInputReadText(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdInputLocker);

  return stdReadText(stdin, a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::stdInputFlush()
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdInputLocker);

  return stdFlush(stdin);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdOutputWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdOutputLocker);

  return stdWriteBinary(stdout, a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdOutputWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdOutputLocker);

  return stdWriteText(stdout, a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdOutputWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdOutputLocker);

  return stdWriteText(stdout, a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::stdOutputFlush()
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdOutputLocker);

  return stdFlush(stdout);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
#endif
