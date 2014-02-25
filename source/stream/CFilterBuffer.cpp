/*!
 *  \file    CFilterBuffer.cpp Buffer filter class accumulates data from
 *           another stream/filter in the dynamic or static buffer until
 *           flush is not called.
 *  \brief   Buffer filter class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Buffer filter class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   20.03.2009 21:38:33

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
#include <Depth/include/stream/CFilterBuffer.hpp>
/*==========================================================================*/
#ifndef __CFILTERBUFFER_CPP__
#define __CFILTERBUFFER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CFilterBuffer::set(const CFilterBuffer& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CFilterBuffer class instance."))
  {
    return false;
  }

  // Initialize base filter interface.
  if (!IFilter::set(a_crInstance))
    return false;

  // Reset sizes of the buffers.
  m_ReadBufferIndex = 0;
  m_ReadBufferSize = 0;
  m_ReadBufferType = 0;
  m_WriteBufferIndex = 0;
  m_WriteBufferSize = 0;
  m_WriteBufferType = 0;

  // Initialize read and write buffers.
  if (!m_ReadBuffer.set(a_crInstance.m_ReadBuffer) || !m_WriteBuffer.set(a_crInstance.m_WriteBuffer))
    return false;

  // Restore sizes of the buffers.
  m_ReadBufferIndex = a_crInstance.m_ReadBufferIndex;
  m_ReadBufferSize = a_crInstance.m_ReadBufferSize;
  m_ReadBufferType = a_crInstance.m_ReadBufferType;
  m_WriteBufferIndex = a_crInstance.m_WriteBufferIndex;
  m_WriteBufferSize = a_crInstance.m_WriteBufferSize;
  m_WriteBufferType = a_crInstance.m_WriteBufferType;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBuffer::setReadBuffer(const Tuint a_cSize, const Tbool a_cStatic)
{ CALL
  // Check if the current reader is disconnected or not opened.
  ASSERT(((getReader() == NULL) || !getReader()->isOpened()), STR("Cannot set read buffer parameters for opened reader."))
  {
    return false;
  }

  return m_ReadBuffer.set(a_cSize, a_cStatic);
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBuffer::setWriteBuffer(const Tuint a_cSize, const Tbool a_cStatic)
{ CALL
  // Check if the current writer is disconnected or not opened.
  ASSERT(((getWriter() == NULL) || !getWriter()->isOpened()), STR("Cannot set write buffer parameters for opened writer."))
  {
    return false;
  }

  return m_WriteBuffer.set(a_cSize, a_cStatic);
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBuffer::onOpen(const EOpenType a_cOpenType)
{ CALL
  // Try to open base filter.
  if (!IFilter::onOpen(a_cOpenType))
    return false;

  // Reset sizes of the buffers.
  m_ReadBufferIndex = 0;
  m_ReadBufferSize = 0;
  m_ReadBufferType = 0;
  m_WriteBufferIndex = 0;
  m_WriteBufferSize = 0;
  m_WriteBufferType = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBuffer::onFlush()
{ CALL
  // Check if write buffer has some data...
  if (m_WriteBufferSize > 0)
  {
    // Write remain data from the write buffer.
    if ((getWriter() !=NULL) && (getWriter()->isOpened()))
    {
      Tuint result = 0;
      switch (m_WriteBufferType)
      {
        case 1:
        {
          // Flush bytes buffer.
          result = getWriter()->writeBuffer(m_WriteBuffer.getBuffer() + m_WriteBufferIndex, m_WriteBufferSize);
          break;
        }
        case 2:
        {
          // Flush characters buffer.
          result = getWriter()->writeBuffer((Tcsstr)(m_WriteBuffer.getBuffer() + m_WriteBufferIndex), m_WriteBufferSize / sizeof(Tschar)) * sizeof(Tschar);
          break;
        }
        case 3:
        {
          // Flush wide characters buffer.
          result = getWriter()->writeBuffer((Tcwstr)(m_WriteBuffer.getBuffer() + m_WriteBufferIndex), m_WriteBufferSize / sizeof(Twchar)) * sizeof(Twchar);
          break;
        }
        default:
          break;
      }
      m_WriteBufferIndex += result;
      m_WriteBufferSize -= result;
      if (m_WriteBufferSize > 0)
        return false;
    }

    // Resize the dynamic write buffer.
    m_WriteBufferIndex = 0;
    m_WriteBufferSize = 0;
    m_WriteBufferType = 0;
    if (m_WriteBuffer.isDynamic())
      if (!m_WriteBuffer.resize(0))
        return false;
  }

  // Try to flush base filter.
  return IFilter::onFlush();
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBuffer::onClose()
{ CALL
  // Resize the dynamic read buffer.
  m_ReadBufferIndex = 0;
  m_ReadBufferSize = 0;
  m_ReadBufferType = 0;
  if (m_ReadBuffer.isDynamic())
    if (!m_ReadBuffer.resize(0))
      return false;

  // Resize the dynamic write buffer.
  m_WriteBufferIndex = 0;
  m_WriteBufferSize = 0;
  m_WriteBufferType = 0;
  if (m_WriteBuffer.isDynamic())
    if (!m_WriteBuffer.resize(0))
      return false;

  // Try to close base filter.
  return IFilter::onClose();
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBuffer::onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the read buffer type is valid.
  ASSERT(((m_ReadBufferType == 0) || (m_ReadBufferType == 1)), STR("Mixing binary input with ASCII text or Unicode text input may harm result data."));

  // Update type of the read buffer.
  m_ReadBufferType = 1;

  if (IStream::isAutoFlush() || (!m_ReadBuffer.isDynamic() && (m_ReadBuffer.getSize() == 0)))
    return a_rReader.readBuffer(a_pBuffer, a_cSize);
  else
  {
    // Firstly, try to fill read buffer.
    if (m_ReadBufferSize == 0)
    {
      m_ReadBufferIndex = 0;
      m_ReadBufferSize = 0;
      if (!fillReadBuffer())
        return 0;
    }

    Tbuffer buffer = (Tbuffer)a_pBuffer;
    Tuint size = a_cSize;

    // Secondary, read data from the buffer.
    Tuint copy_size = NAlgorithms::NCommon::min(m_ReadBufferSize, size);
    if (copy_size > 0)
    {
      // Copy bytes from the read buffer into the given one.
      NMemory::CMemory::copy(buffer, m_ReadBuffer.getBuffer(), copy_size);
      buffer += copy_size;
      size -= copy_size;

      // Update read buffer parameters.
      m_ReadBufferIndex += copy_size;
      m_ReadBufferSize -= copy_size;
    }

    // Thirdly, read remain data directly.
    if (size > 0)
    {
      if (size < m_ReadBuffer.getSize())
        size -= onFilterReadBinary(a_rReader, buffer, size);
      else
        size -= a_rReader.readBuffer(buffer, size);
      if (size > 0)
        return a_cSize - size;
    }
    return a_cSize;
  }
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBuffer::onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the read buffer type is valid.
  ASSERT(((m_ReadBufferType == 0) || (m_ReadBufferType == 2)), STR("Mixing ASCII text input with binary or Unicode text input may harm result data."));

  // Update type of the read buffer.
  m_ReadBufferType = 2;

  if (IStream::isAutoFlush() || (!m_ReadBuffer.isDynamic() && (m_ReadBuffer.getSize() < sizeof(Tschar))))
    return a_rReader.readBuffer(a_pBuffer, a_cSize);
  else
  {
    // Firstly, try to fill read buffer.
    if (m_ReadBufferSize == 0)
    {
      m_ReadBufferIndex = 0;
      m_ReadBufferSize = 0;
      if (!fillReadBuffer())
        return 0;
    }

    Tbuffer buffer = (Tbuffer)a_pBuffer;
    Tuint size = a_cSize * sizeof(Tschar);

    // Secondary, read data from the buffer.
    Tuint copy_size = (NAlgorithms::NCommon::min(m_ReadBufferSize, size) / sizeof(Tschar)) * sizeof(Tschar);
    if (copy_size > 0)
    {
      // Copy bytes from the read buffer into the given one.
      NMemory::CMemory::copy(buffer, m_ReadBuffer.getBuffer(), copy_size);
      buffer += copy_size;
      size -= copy_size;

      // Update read buffer parameters.
      m_ReadBufferIndex += copy_size;
      m_ReadBufferSize -= copy_size;
    }

    // Thirdly, read remain data directly.
    if (size > 0)
    {
      if (size < m_ReadBuffer.getSize())
        size -= onFilterReadText(a_rReader, (Tsstr)buffer, size / sizeof(Tschar)) * sizeof(Tschar);
      else
        size -= a_rReader.readBuffer((Tsstr)buffer, size / sizeof(Tschar)) * sizeof(Tschar);
      if (size > 0)
        return a_cSize - (size / sizeof(Tschar));
    }
    return a_cSize;
  }
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBuffer::onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Check if the read buffer type is valid.
  ASSERT(((m_ReadBufferType == 0) || (m_ReadBufferType == 3)), STR("Mixing Unicode text input with binary or ASCII text input may harm result data."));

  // Update type of the read buffer.
  m_ReadBufferType = 3;

  if (IStream::isAutoFlush() || (!m_ReadBuffer.isDynamic() && (m_ReadBuffer.getSize() < sizeof(Twchar))))
    return a_rReader.readBuffer(a_pBuffer, a_cSize);
  else
  {
    // Firstly, try to fill read buffer.
    if (m_ReadBufferSize == 0)
    {
      m_ReadBufferIndex = 0;
      m_ReadBufferSize = 0;
      if (!fillReadBuffer())
        return 0;
    }

    Tbuffer buffer = (Tbuffer)a_pBuffer;
    Tuint size = a_cSize * sizeof(Twchar);

    // Secondary, read data from the buffer.
    Tuint copy_size = (NAlgorithms::NCommon::min(m_ReadBufferSize, size) / sizeof(Twchar)) * sizeof(Twchar);
    if (copy_size > 0)
    {
      // Copy bytes from the read buffer into the given one.
      NMemory::CMemory::copy(buffer, m_ReadBuffer.getBuffer(), copy_size);
      buffer += copy_size;
      size -= copy_size;

      // Update read buffer parameters.
      m_ReadBufferIndex += copy_size;
      m_ReadBufferSize -= copy_size;
    }

    // Thirdly, read remain data directly.
    if (size > 0)
    {
      if (size < m_ReadBuffer.getSize())
        size -= onFilterReadText(a_rReader, (Twstr)buffer, size / sizeof(Twchar)) * sizeof(Twchar);
      else
        size -= a_rReader.readBuffer((Twstr)buffer, size / sizeof(Twchar)) * sizeof(Twchar);
      if (size > 0)
        return a_cSize - (size / sizeof(Twchar));
    }
    return a_cSize;
  }
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBuffer::onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the write buffer type is valid.
  ASSERT(((m_WriteBufferType == 0) || (m_WriteBufferType == 1)), STR("Mixing binary output with ASCII text or Unicode text output may harm result data."));

  // Update type of the write buffer.
  m_WriteBufferType = 1;

  if (IStream::isAutoFlush() || (!m_WriteBuffer.isDynamic() && (m_WriteBuffer.getSize() == 0)))
    return a_rWriter.writeBuffer(a_cpBuffer, a_cSize);
  else
  {
    Tcbuffer buffer = (Tcbuffer)a_cpBuffer;
    Tuint size = a_cSize;

    // Firstly, fill the write buffer.
    Tuint copy_size = m_WriteBuffer.isDynamic() ? a_cSize : NAlgorithms::NCommon::min(m_WriteBuffer.getSize() - m_WriteBufferIndex - m_WriteBufferSize, size);
    if (copy_size > 0)
    {
      // Resize dynamic write buffer.
      if (m_WriteBuffer.isDynamic())
      {
        if (!m_WriteBuffer.resizeBy(copy_size))
          return a_cSize - size;
      }

      // Copy bytes from the given buffer into the write one.
      NMemory::CMemory::copy(m_WriteBuffer.getBuffer() + m_WriteBufferIndex + m_WriteBufferSize, buffer, copy_size);
      buffer += copy_size;
      size -= copy_size;

      // Update write buffer parameters.
      m_WriteBufferSize += copy_size;
    }

    // Secondary, write whole buffer into the writer.
    if (size > 0)
    {
      Tuint result = a_rWriter.writeBuffer(m_WriteBuffer.getBuffer() + m_WriteBufferIndex, m_WriteBufferSize);
      m_WriteBufferIndex += result;
      m_WriteBufferSize -= result;
      if (m_WriteBufferSize > 0)
        return a_cSize - size;

      // Reset write buffer parameters.
      m_WriteBufferIndex = 0;
      m_WriteBufferSize = 0;

      // Write remain data which is multiply by write buffer size.
      Tuint write_size = m_WriteBuffer.getSize() * (size / m_WriteBuffer.getSize());
      if (write_size > 0)
      {
        result = a_rWriter.writeBuffer(buffer, write_size);
        buffer += result;
        size -= result;
      }

      // Finally, store remain data in the write buffer.
      if (size > 0)
      {
        // Copy bytes from the given buffer into the write one.
        NMemory::CMemory::copy(m_WriteBuffer.getBuffer() + m_WriteBufferIndex, buffer, size);

        // Update write buffer parameters.
        m_WriteBufferSize += size;

        // Finishing writing.
        buffer += size;
        size = 0;
      }
    }
    return a_cSize - size;
  }
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBuffer::onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the write buffer type is valid.
  ASSERT(((m_WriteBufferType == 0) || (m_WriteBufferType == 2)), STR("Mixing ASCII text output with binary or Unicode text output may harm result data."));

  // Update type of the write buffer.
  m_WriteBufferType = 2;

  if (IStream::isAutoFlush() || (!m_WriteBuffer.isDynamic() && (m_WriteBuffer.getSize() < sizeof(Tschar))))
    return a_rWriter.writeBuffer(a_cpBuffer, a_cSize);
  else
  {
    Tcbuffer buffer = (Tcbuffer)a_cpBuffer;
    Tuint size = a_cSize * sizeof(Tschar);

    // Firstly, fill the write buffer.
    Tuint copy_size = m_WriteBuffer.isDynamic() ? (a_cSize * sizeof(Tschar)) : ((NAlgorithms::NCommon::min(m_WriteBuffer.getSize() - m_WriteBufferIndex - m_WriteBufferSize, size) / sizeof(Tschar) * sizeof(Tschar)));
    if (copy_size > 0)
    {
      // Resize dynamic write buffer.
      if (m_WriteBuffer.isDynamic())
      {
        if (!m_WriteBuffer.resizeBy(copy_size))
          return a_cSize - (size / sizeof(Tschar));
      }

      // Copy bytes from the given buffer into the write one.
      NMemory::CMemory::copy(m_WriteBuffer.getBuffer() + m_WriteBufferIndex + m_WriteBufferSize, buffer, copy_size);
      buffer += copy_size;
      size -= copy_size;

      // Update write buffer parameters.
      m_WriteBufferSize += copy_size;
    }

    // Secondary, write whole buffer into the writer.
    if (size > 0)
    {
      Tuint result = a_rWriter.writeBuffer((Tcsstr)(m_WriteBuffer.getBuffer() + m_WriteBufferIndex), m_WriteBufferSize / sizeof(Tschar)) * sizeof(Tschar);
      m_WriteBufferIndex += result;
      m_WriteBufferSize -= result;
      if (m_WriteBufferSize > 0)
        return a_cSize - (size / sizeof(Tschar));

      // Reset write buffer parameters.
      m_WriteBufferIndex = 0;
      m_WriteBufferSize = 0;

      // Write remain data which is multiply by write buffer size.
      Tuint buffer_size = (m_WriteBuffer.getSize() / sizeof(Tschar)) * sizeof(Tschar);
      Tuint write_size = buffer_size * (size / buffer_size);
      if (write_size > 0)
      {
        result = a_rWriter.writeBuffer((Tcsstr)buffer, write_size / sizeof(Tschar)) * sizeof(Tschar);
        buffer += result;
        size -= result;
      }

      // Finally, store remain data in the write buffer.
      if (size > 0)
      {
        // Copy bytes from the given buffer into the write one.
        NMemory::CMemory::copy(m_WriteBuffer.getBuffer() + m_WriteBufferIndex, buffer, size);

        // Update write buffer parameters.
        m_WriteBufferSize += size;

        // Finishing writing.
        buffer += size;
        size = 0;
      }
    }
    return a_cSize - (size / sizeof(Tschar));
  }
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBuffer::onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the write buffer type is valid.
  ASSERT(((m_WriteBufferType == 0) || (m_WriteBufferType == 3)), STR("Mixing Unicode text output with binary or ASCII text output may harm result data."));

  // Update type of the write buffer.
  m_WriteBufferType = 3;

  if (IStream::isAutoFlush() || (!m_WriteBuffer.isDynamic() && (m_WriteBuffer.getSize() < sizeof(Twchar))))
    return a_rWriter.writeBuffer(a_cpBuffer, a_cSize);
  else
  {
    Tcbuffer buffer = (Tcbuffer)a_cpBuffer;
    Tuint size = a_cSize * sizeof(Twchar);

    // Firstly, fill the write buffer.
    Tuint copy_size = m_WriteBuffer.isDynamic() ? (a_cSize * sizeof(Twchar)) : ((NAlgorithms::NCommon::min(m_WriteBuffer.getSize() - m_WriteBufferIndex - m_WriteBufferSize, size) / sizeof(Twchar) * sizeof(Twchar)));
    if (copy_size > 0)
    {
      // Resize dynamic write buffer.
      if (m_WriteBuffer.isDynamic())
      {
        if (!m_WriteBuffer.resizeBy(copy_size))
          return a_cSize - (size / sizeof(Twchar));
      }

      // Copy bytes from the given buffer into the write one.
      NMemory::CMemory::copy(m_WriteBuffer.getBuffer() + m_WriteBufferIndex + m_WriteBufferSize, buffer, copy_size);
      buffer += copy_size;
      size -= copy_size;

      // Update write buffer parameters.
      m_WriteBufferSize += copy_size;
    }

    // Secondary, write whole buffer into the writer.
    if (size > 0)
    {
      Tuint result = a_rWriter.writeBuffer((Tcwstr)(m_WriteBuffer.getBuffer() + m_WriteBufferIndex), m_WriteBufferSize / sizeof(Twchar)) * sizeof(Twchar);
      m_WriteBufferIndex += result;
      m_WriteBufferSize -= result;
      if (m_WriteBufferSize > 0)
        return a_cSize - (size / sizeof(Twchar));

      // Reset write buffer parameters.
      m_WriteBufferIndex = 0;
      m_WriteBufferSize = 0;

      // Write remain data which is multiply by write buffer size.
      Tuint buffer_size = (m_WriteBuffer.getSize() / sizeof(Twchar)) * sizeof(Twchar);
      Tuint write_size = buffer_size * (size / buffer_size);
      if (write_size > 0)
      {
        result = a_rWriter.writeBuffer((Tcwstr)buffer, write_size / sizeof(Twchar)) * sizeof(Twchar);
        buffer += result;
        size -= result;
      }

      // Finally, store remain data in the write buffer.
      if (size > 0)
      {
        // Copy bytes from the given buffer into the write one.
        NMemory::CMemory::copy(m_WriteBuffer.getBuffer() + m_WriteBufferIndex, buffer, size);

        // Update write buffer parameters.
        m_WriteBufferSize += size;

        // Finishing writing.
        buffer += size;
        size = 0;
      }
    }
    return a_cSize - (size / sizeof(Twchar));
  }
}
/*--------------------------------------------------------------------------*/
Tbool CFilterBuffer::fillReadBuffer(const Tuint a_cChunkSize/* = 1024 */)
{ CALL
  // Check if the given chunk size is valid.
  ASSERT((a_cChunkSize > 0), STR("Chunk size should be greater than 0."))
  {
    return false;
  }
  // Check if the read buffer type is defined.
  ASSERT((m_ReadBufferType != 0), STR("Cannot fill read buffer with undefined read type."))
  {
    return false;
  }
  // Check if the given read buffer is empty.
  ASSERT(((m_ReadBufferIndex == 0) && (m_ReadBufferSize == 0)), STR("Cannot fill read buffer which is not empty."))
  {
    return false;
  }

  // Try to fill read buffer...
  if ((getReader() !=NULL) && (getReader()->isOpened()))
  {
    if (m_ReadBuffer.isStatic())
    {
      // Try to read static buffer of given size.
      switch (m_ReadBufferType)
      {
        case 1:
        {
          m_ReadBufferSize = getReader()->readBuffer(m_ReadBuffer.getBuffer(), m_ReadBuffer.getSize());
          break;
        }
        case 2:
        {
          m_ReadBufferSize = getReader()->readBuffer((Tsstr)m_ReadBuffer.getBuffer(), m_ReadBuffer.getSize() / sizeof(Tschar)) * sizeof(Tschar);
          break;
        }
        case 3:
        {
          m_ReadBufferSize = getReader()->readBuffer((Twstr)m_ReadBuffer.getBuffer(), m_ReadBuffer.getSize() / sizeof(Twchar)) * sizeof(Twchar);
          break;
        }
        default:
          break;
      }
    }
    else
    {
      // Try to read dynamic buffer with separate chunks until we can read.
      while (m_ReadBuffer.resizeBy(a_cChunkSize))
      {
        Tuint result = 0;
        switch (m_ReadBufferType)
        {
          case 1:
          {
            result = getReader()->readBuffer(m_ReadBuffer.getBuffer() + m_ReadBufferSize, a_cChunkSize);
            break;
          }
          case 2:
          {
            result = getReader()->readBuffer((Tsstr)(m_ReadBuffer.getBuffer() + m_ReadBufferSize), a_cChunkSize / sizeof(Tschar)) * sizeof(Tschar);
            break;
          }
          case 3:
          {
            result = getReader()->readBuffer((Twstr)(m_ReadBuffer.getBuffer() + m_ReadBufferSize), a_cChunkSize / sizeof(Twchar)) * sizeof(Twchar);
            break;
          }
          default:
            break;
        }
        m_ReadBufferSize += result;
        if (result != a_cChunkSize)
          break;
      }
    }
  }
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
