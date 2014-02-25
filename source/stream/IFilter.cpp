/*!
 *  \file    IFilter.cpp Filter stream interface is a base interface for
 *           all implementations of stream filter classes which are used
 *           to perform additional data manipulation during input/output
 *           operations (e.g. buffering, encoding / decoding, inflating /
 *           deflating, etc.).
 *  \brief   Filter interface (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Filter interface (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   18.03.2009 02:49:24

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
#include <Depth/include/stream/IFilter.hpp>
/*==========================================================================*/
#ifndef __IFILTER_CPP__
#define __IFILTER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INTERFACE IMPLEMENTATIONS                                                */
/*==========================================================================*/
Tbool IFilter::set(const IFilter& a_crInstance)
{ CALL
  // Check if the given interface instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same IFilter interface instance."))
  {
    return false;
  }

  // Initialize new reader & writer.
  if (!IReaderWriter::set(a_crInstance))
    return false;

  // Set reader and writer.
  return (setReader(a_crInstance.m_pReader) && setWriter(a_crInstance.m_pWriter));
}
/*--------------------------------------------------------------------------*/
Tbool IFilter::setReader(IReader* a_pReader)
{ CALL
  if (a_pReader != NULL)
  {
    m_pReader = a_pReader;
    IReader::m_IsOpened = m_pReader->m_IsOpened;
    IReader::m_IsEOF = m_pReader->m_IsEOF;
    IReader::m_ReadBytesCount = 0;

    // Create peek buffer for opened reader.
    if (IReader::m_IsOpened)
    {
      // Allocate peek buffer.
      if (IReader::m_PeekBufferSize > 0)
      {
        IReader::m_pPeekBuffer = newex Tbyte[IReader::m_PeekBufferSize];
        if (IReader::m_pPeekBuffer == NULL)
        {
          WARNING(STR("Cannot allocate peek buffer for the filter (requested size is %u bytes).") COMMA IReader::m_PeekBufferSize);
          return false;
        }
      }
    }
  }
  else
  {
    m_pReader = NULL;
    IReader::m_IsOpened = false;
    IReader::m_IsEOF = false;
    IReader::m_ReadBytesCount = 0;
    IReader::m_PeekBufferSize = 0;
    IReader::m_PeekBufferFreeSize = 0;
    IReader::m_pPeekBuffer = NULL;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool IFilter::setWriter(IWriter* a_pWriter)
{ CALL
  if (a_pWriter != NULL)
  {
    m_pWriter = a_pWriter;
    IWriter::m_IsOpened = m_pWriter->m_IsOpened;
    IWriter::m_IsEOF = m_pWriter->m_IsEOF;
    IWriter::m_WrittenBytesCount = 0;
  }
  else
  {
    m_pWriter = NULL;
    IWriter::m_IsOpened = false;
    IWriter::m_IsEOF = false;
    IWriter::m_WrittenBytesCount = 0;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool IFilter::onOpen(const EOpenType a_cOpenType)
{ CALL
  // Check if filter is connected with reader.
  ASSERT(((a_cOpenType == IStream::e_OPEN_WRITE) || (m_pReader != NULL)), STR("Cannot open filter for input which is not connected to the valid reader."))
  {
    return false;
  }
  // Check if filter is connected with writer.
  ASSERT(((a_cOpenType == IStream::e_OPEN_READ) || (m_pWriter != NULL)), STR("Cannot open filter for output which is not connected to the valid writer."))
  {
    return false;
  }

  Tbool result = true;
  if ((a_cOpenType != IStream::e_OPEN_WRITE) && !m_pReader->isOpened())
    result &= m_pReader->open();
  if ((a_cOpenType != IStream::e_OPEN_READ) && !m_pWriter->isOpened())
    result &= m_pWriter->open();
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint IFilter::onReadBinary(Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is connected and opened.
  ASSERT(((m_pReader != NULL) && m_pReader->isOpened()), STR("Cannot read the buffer from the disconnected or closed reader."))
  {
    return 0;
  }

  Tuint result = onFilterReadBinary(*m_pReader, a_pBuffer, a_cSize);
  IReader::setEOF(m_pReader->isEOF());
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint IFilter::onReadText(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is connected and opened.
  ASSERT(((m_pReader != NULL) && m_pReader->isOpened()), STR("Cannot read the buffer from the disconnected or closed reader."))
  {
    return 0;
  }

  Tuint result = onFilterReadText(*m_pReader, a_pBuffer, a_cSize);
  IReader::setEOF(m_pReader->isEOF());
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint IFilter::onReadText(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current reader is connected and opened.
  ASSERT(((m_pReader != NULL) && m_pReader->isOpened()), STR("Cannot read the buffer from the disconnected or closed reader."))
  {
    return 0;
  }

  Tuint result = onFilterReadText(*m_pReader, a_pBuffer, a_cSize);
  IReader::setEOF(m_pReader->isEOF());
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint IFilter::onWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current writer is connected and opened.
  ASSERT(((m_pWriter != NULL) && m_pWriter->isOpened()), STR("Cannot write the buffer into the disconnected or closed writer."))
  {
    return 0;
  }

  Tuint result = onFilterWriteBinary(*m_pWriter, a_cpBuffer, a_cSize);
  IWriter::setEOF(m_pWriter->isEOF());
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint IFilter::onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current writer is connected and opened.
  ASSERT(((m_pWriter != NULL) && m_pWriter->isOpened()), STR("Cannot write the buffer into the disconnected or closed writer."))
  {
    return 0;
  }

  Tuint result = onFilterWriteText(*m_pWriter, a_cpBuffer, a_cSize);
  IWriter::setEOF(m_pWriter->isEOF());
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint IFilter::onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current writer is connected and opened.
  ASSERT(((m_pWriter != NULL) && m_pWriter->isOpened()), STR("Cannot write the buffer into the disconnected or closed writer."))
  {
    return 0;
  }

  Tuint result = onFilterWriteText(*m_pWriter, a_cpBuffer, a_cSize);
  IWriter::setEOF(m_pWriter->isEOF());
  return result;
}
/*--------------------------------------------------------------------------*/
Tbool IFilter::onFlush()
{ CALL
  Tbool result = true;
  if ((m_pReader != NULL) && m_pReader->isOpened())
  {
    result &= m_pReader->flush();
    IReader::setEOF(m_pReader->isEOF());
  }
  if ((m_pWriter != NULL) && m_pWriter->isOpened())
  {
    result &= m_pWriter->flush();
    IWriter::setEOF(m_pWriter->isEOF());
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tbool IFilter::onClose()
{ CALL
  Tbool result = true;
  if ((m_pReader != NULL) && m_pReader->isOpened())
    result &= m_pReader->close();
  if ((m_pWriter != NULL) && m_pWriter->isOpened())
    result &= m_pWriter->close();
  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
