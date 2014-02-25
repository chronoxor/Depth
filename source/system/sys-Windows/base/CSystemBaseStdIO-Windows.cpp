/*!
 *  \file    CSystemBaseStdIO-Windows.cpp Base system class contains common
 *           functionality such as memory routines, math functions, error
 *           handling, standard I/O routines.
 *  \brief   Base system class - Windows OS - standard I/O streams methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Windows OS - standard I/O streams methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   22.08.2008 22:09:50

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
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/base/CInteger.hpp>
#include <Depth/include/system/CSystemBase.hpp>
/*--------------------------------------------------------------------------*/
#include "../Windows.hpp"
/*==========================================================================*/
#ifndef __CSYSTEMBASESTDIO_WINDOWS_CPP__
#define __CSYSTEMBASESTDIO_WINDOWS_CPP__
/*==========================================================================*/
#if ((defined(__WINDOWS__) && !defined(__WINDOWS_MOBILE__)) || (defined(__UNIX__) && defined(__CYGWIN__)))
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
NDepth::NTypes::Tuint stdReadBinary(HANDLE a_pHandle, NDepth::NTypes::Tptr a_pBuffer, const NDepth::NTypes::Tuint a_cSize)
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
  DWORD chunk = 0;
  DWORD chunk_read = 0;
  NDepth::NTypes::Tuint read = 0;
  NDepth::NTypes::Tbuffer buffer = (NDepth::NTypes::Tbuffer)a_pBuffer;
  do
  {
    chunk = (DWORD)NDepth::NAlgorithms::NCommon::min(a_cSize - read, (NDepth::NTypes::Tuint)NDepth::NBase::CUnsignedInteger32::getMax());
    if (ReadFile(a_pHandle, buffer, chunk, &chunk_read, NULL) == FALSE)
    {
      WARNING(STR("Cannot read bytes from the standard stream (requested size is %u bytes, read size is %u bytes).") COMMA (NDepth::NTypes::Tuint)chunk COMMA (NDepth::NTypes::Tuint)chunk_read);
      break;
    }
    read += chunk_read;
    buffer += chunk_read;
  } while (read < a_cSize);
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
NDepth::NTypes::Tuint stdWriteBinary(HANDLE a_pHandle, NDepth::NTypes::Tcptr a_cpBuffer, const NDepth::NTypes::Tuint a_cSize)
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
  DWORD chunk = 0;
  DWORD chunk_written = 0;
  NDepth::NTypes::Tuint written = 0;
  NDepth::NTypes::Tcbuffer buffer = (NDepth::NTypes::Tcbuffer)a_cpBuffer;
  do
  {
    chunk = (DWORD)NDepth::NAlgorithms::NCommon::min(a_cSize - written, (NDepth::NTypes::Tuint)NDepth::NBase::CUnsignedInteger32::getMax());
    if (WriteFile(a_pHandle, buffer, chunk, &chunk_written, NULL) == FALSE)
    {
      WARNING(STR("Cannot write bytes into the standard stream (requested size is %u bytes, written size is %u bytes).") COMMA (NDepth::NTypes::Tuint)chunk COMMA (NDepth::NTypes::Tuint)chunk_written);
      break;
    }
    written += chunk_written;
    buffer += chunk_written;
  } while (written < a_cSize);
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
NDepth::NTypes::Tuint stdReadText(HANDLE a_pHandle, NDepth::NTypes::Tsstr a_pBuffer, const NDepth::NTypes::Tuint a_cSize)
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
  DWORD chunk = 0;
  DWORD chunk_read = 0;
  NDepth::NTypes::Tuint read = 0;
  NDepth::NTypes::Tsstr buffer = a_pBuffer;
  do
  {
    chunk = (DWORD)NDepth::NAlgorithms::NCommon::min(a_cSize - read, (NDepth::NTypes::Tuint)NDepth::NBase::CUnsignedInteger32::getMax());
    if (GetFileType(a_pHandle) == FILE_TYPE_CHAR)
    {
      if (ReadConsoleA(a_pHandle, buffer, chunk, &chunk_read, NULL) == FALSE)
      {
        WARNING(STR("Cannot read ASCII text from the standard stream (requested size is %u bytes, read size is %u bytes).") COMMA (NDepth::NTypes::Tuint)chunk COMMA (NDepth::NTypes::Tuint)chunk_read);
        break;
      }
    }
    else
    {
      if (ReadFile(a_pHandle, buffer, chunk, &chunk_read, NULL) == FALSE)
      {
        WARNING(STR("Cannot read ASCII text from the standard stream (requested size is %u bytes, read size is %u bytes).") COMMA (NDepth::NTypes::Tuint)chunk COMMA (NDepth::NTypes::Tuint)chunk_read);
        break;
      }
    }
    read += chunk_read;
    buffer += chunk_read;
  } while (read < a_cSize);
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
NDepth::NTypes::Tuint stdReadText(HANDLE a_pHandle, NDepth::NTypes::Twstr a_pBuffer, const NDepth::NTypes::Tuint a_cSize)
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
  NDepth::NTypes::Tbyte temp_buffer[4] = { 0, 0, 0, 0 };
  NDepth::NTypes::Tbuffer buffer = (NDepth::NTypes::Tbuffer)a_pBuffer;

  // Read Unicode text buffer.
  while (result < a_cSize)
  {
    // Read next UTF-16 character.
    DWORD read = 0;
    if (GetFileType(a_pHandle) == FILE_TYPE_CHAR)
    {
      if (ReadConsoleW(a_pHandle, temp_buffer, 1, &read, NULL) == FALSE)
      {
        WARNING(STR("Cannot read Unicode text from the standard stream (requested size is %u bytes, read size is %u bytes).") COMMA 2 COMMA (NDepth::NTypes::Tuint)(read << 1));
        break;
      }
      else if (read != 1)
        break;
    }
    else
    {
      if (ReadFile(a_pHandle, temp_buffer, 2, &read, NULL) == FALSE)
      {
        WARNING(STR("Cannot read Unicode text from the standard stream (requested size is %u bytes, read size is %u bytes).") COMMA 2 COMMA (NDepth::NTypes::Tuint)read);
        break;
      }
      else if (read != 2)
        break;
    }

    // Check if additional bytes should be read.
    #if defined(__BIG_ENDIAN__)
    wc = (temp_buffer[0] << 8) + temp_buffer[1];
    #else
    wc = temp_buffer[0] + (temp_buffer[1] << 8);
    #endif
    if ((wc >= 0xD800) && (wc < 0xDC00))
    {
      // Read next UTF-16 character.
      DWORD read = 0;
      if (GetFileType(a_pHandle) == FILE_TYPE_CHAR)
      {
        WARNING(STR("Text from the standard stream contains invalid UTF-16 character (character code is %hU).") COMMA wc);
        break;
      }
      else
      {
        if (ReadFile(a_pHandle, temp_buffer + 2, 2, &read, NULL) == FALSE)
        {
          WARNING(STR("Cannot read Unicode text from the standard stream (requested size is %u bytes, read size is %u bytes).") COMMA 2 COMMA (NDepth::NTypes::Tuint)read);
          break;
        }
        else if (read != 2)
          break;
      }

      // Check UTF-16 extended bytes.
      #if defined(__BIG_ENDIAN__)
      NDepth::NTypes::Tuint wc_temp = (temp_buffer[2] << 8) + temp_buffer[3];
      #else
      NDepth::NTypes::Tuint wc_temp = temp_buffer[2] + (temp_buffer[3] << 8);
      #endif
      if (!((wc_temp >= 0xDC00) && (wc_temp < 0xE000)))
      {
        WARNING(STR("Text from the standard stream contains invalid UTF-16 character (character code is %hU).") COMMA wc_temp);
        break;
      }

      // Calculate Unicode character.
      wc = 0x10000 + ((wc - 0xD800) << 10) + (wc_temp - 0xDC00);
    }
    else if ((wc >= 0xDC00) && (wc < 0xE000))
    {
      WARNING(STR("Text from the standard stream contains invalid UTF-16 character (character code is %hU).") COMMA wc);
      break;
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
NDepth::NTypes::Tuint stdWriteText(HANDLE a_pHandle, NDepth::NTypes::Tcsstr a_cpBuffer, const NDepth::NTypes::Tuint a_cSize)
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
  DWORD chunk = 0;
  DWORD chunk_written = 0;
  NDepth::NTypes::Tuint written = 0;
  NDepth::NTypes::Tcsstr buffer = a_cpBuffer;
  do
  {
    chunk = (DWORD)NDepth::NAlgorithms::NCommon::min(a_cSize - written, (NDepth::NTypes::Tuint)NDepth::NBase::CUnsignedInteger32::getMax());
    if (GetFileType(a_pHandle) == FILE_TYPE_CHAR)
    {
      if (WriteConsoleA(a_pHandle, buffer, chunk, &chunk_written, NULL) == FALSE)
      {
        WARNING(STR("Cannot write ASCII text into the standard stream (requested size is %u bytes, written size is %u bytes).") COMMA (NDepth::NTypes::Tuint)chunk COMMA (NDepth::NTypes::Tuint)chunk_written);
        break;
      }
    }
    else
    {
      if (WriteFile(a_pHandle, buffer, chunk, &chunk_written, NULL) == FALSE)
      {
        WARNING(STR("Cannot write ASCII text into the standard stream (requested size is %u bytes, written size is %u bytes).") COMMA (NDepth::NTypes::Tuint)chunk COMMA (NDepth::NTypes::Tuint)chunk_written);
        break;
      }
    }
    written += chunk_written;
    buffer += chunk_written;
  } while (written < a_cSize);
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
NDepth::NTypes::Tuint stdWriteText(HANDLE a_pHandle, NDepth::NTypes::Tcwstr a_cpBuffer, const NDepth::NTypes::Tuint a_cSize)
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
  NDepth::NTypes::Tbyte temp_buffer[4] = { 0, 0, 0, 0 };
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

    // Convert into the UTF-16 and write.
    NDepth::NTypes::Tuint length = 0;
    if ((wc >= 0xD800) && (wc < 0xE000))
    {
      WARNING(STR("Text from the buffer contains invalid UTF-16 character (character code is %hU).") COMMA wc);
      break;
    }
    else if (wc < 0x10000)
    {
      #if defined(__BIG_ENDIAN__)
      temp_buffer[0] = (NDepth::NTypes::Tbyte)(wc >> 8);
      temp_buffer[1] = (NDepth::NTypes::Tbyte)(wc);
      #else
      temp_buffer[0] = (NDepth::NTypes::Tbyte)(wc);
      temp_buffer[1] = (NDepth::NTypes::Tbyte)(wc >> 8);
      #endif
      length = 2;
    }
    else if (wc < 0x110000)
    {
      NDepth::NTypes::Tuint wc1 = 0xD800 + ((wc - 0x10000) >> 10);
      NDepth::NTypes::Tuint wc2 = 0xDC00 + ((wc - 0x10000) & 0X3FF);
      #if defined(__BIG_ENDIAN__)
      temp_buffer[0] = (NDepth::NTypes::Tbyte)(wc1 >> 8);
      temp_buffer[1] = (NDepth::NTypes::Tbyte)(wc1);
      temp_buffer[2] = (NDepth::NTypes::Tbyte)(wc2 >> 8);
      temp_buffer[3] = (NDepth::NTypes::Tbyte)(wc2);
      #else
      temp_buffer[0] = (NDepth::NTypes::Tbyte)(wc1);
      temp_buffer[1] = (NDepth::NTypes::Tbyte)(wc1 >> 8);
      temp_buffer[2] = (NDepth::NTypes::Tbyte)(wc2);
      temp_buffer[3] = (NDepth::NTypes::Tbyte)(wc2 >> 8);
      #endif
      length = 4;
    }

    // Write next UTF-16 character.
    DWORD written = 0;
    if (GetFileType(a_pHandle) == FILE_TYPE_CHAR)
    {
      if (WriteConsoleW(a_pHandle, temp_buffer, 1, &written, NULL) == FALSE)
      {
        WARNING(STR("Cannot write Unicode text into the standard stream (requested size is %u bytes, written size is %u bytes).") COMMA 2 COMMA (NDepth::NTypes::Tuint)(written << 1));
        break;
      }
      else if (written != 1)
        break;
    }
    else
    {
      if (WriteFile(a_pHandle, temp_buffer, (DWORD)length, &written, NULL) == FALSE)
      {
        WARNING(STR("Cannot write Unicode text into the standard stream (requested size is %u bytes, written size is %u bytes).") COMMA length COMMA (NDepth::NTypes::Tuint)written);
        break;
      }
      else if (written != (DWORD)length)
        break;
    }
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
NDepth::NTypes::Tbool stdFlush(HANDLE a_pHandle)
{ CALL
  if (GetFileType(a_pHandle) != FILE_TYPE_CHAR)
  {
    if (FlushFileBuffers(a_pHandle) != FALSE)
      return true;
    else
    {
      WARNING(STR("Cannot flush the standard stream."));
      return false;
    }
  }
  return true;
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

  return stdWriteBinary(GetStdHandle(STD_ERROR_HANDLE), a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdErrorWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdErrorLocker);

  return stdWriteText(GetStdHandle(STD_ERROR_HANDLE), a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdErrorWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdErrorLocker);

  return stdWriteText(GetStdHandle(STD_ERROR_HANDLE), a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::stdErrorFlush()
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdErrorLocker);

  return stdFlush(GetStdHandle(STD_ERROR_HANDLE));
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdInputReadBinary(Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdInputLocker);

  return stdReadBinary(GetStdHandle(STD_INPUT_HANDLE), a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdInputReadText(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdInputLocker);

  return stdReadText(GetStdHandle(STD_INPUT_HANDLE), a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdInputReadText(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdInputLocker);

  return stdReadText(GetStdHandle(STD_INPUT_HANDLE), a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::stdInputFlush()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdOutputWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdOutputLocker);

  return stdWriteBinary(GetStdHandle(STD_OUTPUT_HANDLE), a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdOutputWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdOutputLocker);

  return stdWriteText(GetStdHandle(STD_OUTPUT_HANDLE), a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdOutputWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdOutputLocker);

  return stdWriteText(GetStdHandle(STD_OUTPUT_HANDLE), a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::stdOutputFlush()
{ CALL
  NProcess::CScopeLocker locker(CSystemBase::ms_StdOutputLocker);

  return stdFlush(GetStdHandle(STD_OUTPUT_HANDLE));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
#endif
