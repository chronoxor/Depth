/*!
 *  \file    CSystemBaseStdIO-WindowsMobile.cpp Base system class contains
 *           common functionality such as memory routines, math functions,
 *           error handling, standard I/O routines.
 *  \brief   Base system class - Windows Mobile OS - standard I/O streams methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Windows Mobile OS - standard I/O streams methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   26.08.2008 01:13:50

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
#include "../WindowsMobile.hpp"
/*==========================================================================*/
#ifndef __CSYSTEMBASESTDIO_WINDOWSMOBILE_CPP__
#define __CSYSTEMBASESTDIO_WINDOWSMOBILE_CPP__
/*==========================================================================*/
#if (defined(__WINDOWS__) && defined(__WINDOWS_MOBILE__))
/*==========================================================================*/
#include <stdio.h>
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
  NDepth::NTypes::Tuint ch;
  NDepth::NTypes::Tuint read = 0;
  NDepth::NTypes::Tsstr buffer = a_pBuffer;
  while (read < a_cSize)
  {
    ch = (NDepth::NTypes::Tuint)fgetc(a_pHandle);
    if (ferror(a_pHandle) != 0)
    {
      clearerr(a_pHandle);
      WARNING(STR("Cannot read ASCII text from the standard stream (requested size is %u bytes, read size is %u bytes).") COMMA a_cSize COMMA read);
      break;
    }
    else if (feof(a_pHandle) == 0)
    {
      *buffer = (NDepth::NTypes::Tschar)ch;
      ++buffer;
      ++read;
    }
    else
      break;
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

  NDepth::NTypes::Tuint ch;
  NDepth::NTypes::Tuint read = 0;
  NDepth::NTypes::Twstr buffer = a_pBuffer;
  while (read < a_cSize)
  {
    ch = (NDepth::NTypes::Tuint)fgetwc(a_pHandle);
    if (ferror(a_pHandle) != 0)
    {
      clearerr(a_pHandle);
      WARNING(STR("Cannot read Unicode text from the standard stream (requested size is %u bytes, read size is %u bytes).") COMMA a_cSize COMMA read);
      break;
    }
    else if (feof(a_pHandle) == 0)
    {
      *buffer = (NDepth::NTypes::Twchar)ch;
      ++buffer;
      ++read;
    }
    else
      break;
  }
  return read;
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
  NDepth::NTypes::Tuint ch;
  NDepth::NTypes::Tuint written = 0;
  NDepth::NTypes::Tcsstr buffer = a_cpBuffer;
  while (written < a_cSize)
  {
    ch = (NDepth::NTypes::Tuint)(*buffer);
    if ((fputc((int)ch, a_pHandle) != (int)ch) || (ferror(a_pHandle) != 0))
    {
      clearerr(a_pHandle);
      WARNING(STR("Cannot write ASCII text into the standard stream (requested size is %u bytes, written size is %u bytes).") COMMA a_cSize COMMA written);
      break;
    }
    else if (feof(a_pHandle) == 0)
    {
      ++buffer;
      ++written;
    }
    else
      break;
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

  // Write Unicode text buffer.
  NDepth::NTypes::Tuint ch;
  NDepth::NTypes::Tuint written = 0;
  NDepth::NTypes::Tcwstr buffer = a_cpBuffer;
  while (written < a_cSize)
  {
    ch = (NDepth::NTypes::Tuint)(*buffer);
    if ((fputc((int)ch, a_pHandle) != (int)ch) || (ferror(a_pHandle) != 0))
    {
      clearerr(a_pHandle);
      WARNING(STR("Cannot write Unicode text into the standard stream (requested size is %u bytes, written size is %u bytes).") COMMA a_cSize COMMA written);
      break;
    }
    else if (feof(a_pHandle) == 0)
    {
      ++buffer;
      ++written;
    }
    else
      break;
  }
  return written;
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
