/*!
 *  \file    IReaderWriter.cpp Reader & Writer is a base stream interface for
 *           all implementations of stream classes which use byte input and
 *           output at the same time.
 *  \brief   Reader & Writer interface (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reader & Writer interface (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   15.08.2008 22:43:09

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
#include <Depth/include/stream/IReaderWriter.hpp>
#include <Depth/include/stream/details/CStreamHelper.hpp>
/*==========================================================================*/
#ifndef __IREADERWRITER_CPP__
#define __IREADERWRITER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INTERFACE IMPLEMENTATIONS                                                */
/*==========================================================================*/
Tbool IReaderWriter::set(const IReaderWriter& a_crInstance)
{ CALL
  // Check if the given interface instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same IReaderWriter interface instance."))
  {
    return false;
  }

  // Close opened reader & writer.
  if (isOpened())
    if (!close())
      return false;

  // Initialize new reader & writer.
  IStream::set(a_crInstance);

  // Reset reader & writer parameters.
  IReader::m_IsOpened = false;
  IReader::m_IsEOF = false;
  IReader::m_ReadBytesCount = 0;
  IWriter::m_IsOpened = false;
  IWriter::m_IsEOF = false;
  IWriter::m_WrittenBytesCount = 0;

  // Set reader & writer peek buffer size.
  setPeekBufferSize(a_crInstance.m_PeekBufferSize);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool IReaderWriter::open(const EOpenType a_cOpenType)
{ CALL
  // Check if the current reader & writer is not opened.
  ASSERT(!isOpened(), STR("Cannot open the reader & writer which is already opened."))
  {
    return false;
  }

  // Open the reader & writer and initialize its parameters.
  if (onOpen(a_cOpenType))
  {
    // Initialize reader.
    if ((a_cOpenType == IStream::e_OPEN_READ) || (a_cOpenType == IStream::e_OPEN_READWRITE))
    {
      // Set default format values.
      setDefaultFormat();
      // Set default parse values.
      setDefaultParse();

      IReader::m_IsOpened = true;
      IReader::m_IsEOF = false;
      IReader::m_ReadBytesCount = 0;

      // Allocate peek buffer.
      if (IReader::m_PeekBufferSize > 0)
      {
        IReader::m_pPeekBuffer = newex Tbyte[IReader::m_PeekBufferSize];
        if (IReader::m_pPeekBuffer == NULL)
        {
          WARNING(STR("Cannot allocate peek buffer for the reader (requested size is %u bytes).") COMMA IReader::m_PeekBufferSize);
          return false;
        }
      }
    }

    // Initialize writer.
    if ((a_cOpenType == IStream::e_OPEN_WRITE) || (a_cOpenType == IStream::e_OPEN_READWRITE))
    {
      // Set default format values.
      setDefaultFormat();
      // Set default parse values.
      setDefaultParse();

      IWriter::m_IsOpened = true;
      IWriter::m_IsEOF = false;
      IWriter::m_WrittenBytesCount = 0;
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool IReaderWriter::flush()
{ CALL
  // Check if the current reader & writer is opened.
  ASSERT(isOpened(), STR("Cannot flush the closed reader & writer."))
  {
    return false;
  }

  return onFlush();
}
/*--------------------------------------------------------------------------*/
Tbool IReaderWriter::close()
{ CALL
  // Check if the current reader & writer is opened.
  ASSERT(isOpened(), STR("Cannot close the reader & writer which is already closed."))
  {
    return false;
  }

  // Flush reader & writer before close.
  if (!isAutoFlush() && !flush())
    return false;

  // Close the reader & writer and reset its parameters.
  if (onClose())
  {
    // Reset reader's parameters.
    if (IReader::isOpened())
    {
      IReader::m_IsOpened = false;
      IReader::m_IsEOF = false;
      IReader::m_ReadBytesCount = 0;

      // Free peek buffer.
      if ((IReader::m_PeekBufferSize > 0) && (IReader::m_pPeekBuffer != NULL))
      {
        delete [] IReader::m_pPeekBuffer;
        IReader::m_pPeekBuffer = NULL;
      }
    }

    // Reset writer's parameters.
    if (IWriter::isOpened())
    {
      IWriter::m_IsOpened = false;
      IWriter::m_IsEOF = false;
      IWriter::m_WrittenBytesCount = 0;
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
