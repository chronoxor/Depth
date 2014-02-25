/*!
 *  \file    IWriter.cpp Writer is a base stream interface for all
 *           implementations of stream classes which use byte output (files,
 *           pipes, sockets, etc.).
 *  \brief   Writer interface (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Writer interface (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   13.08.2008 03:18:33

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
#include <Depth/include/algorithms/string/buffer/AStrLen.hpp>
#include <Depth/include/stream/IWriter.hpp>
#include <Depth/include/stream/details/CStreamHelper.hpp>
/*==========================================================================*/
#ifndef __IWRITER_CPP__
#define __IWRITER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INTERFACE IMPLEMENTATIONS                                                */
/*==========================================================================*/
Tbool IWriter::set(const IWriter& a_crInstance)
{ CALL
  // Check if the given interface instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same IWriter interface instance."))
  {
    return false;
  }

  // Close opened writer.
  if (isOpened())
    if (!close())
      return false;

  // Initialize new writer.
  IStream::set(a_crInstance);

  // Reset writer's parameters.
  m_IsOpened = false;
  m_IsEOF = false;
  m_WrittenBytesCount = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool IWriter::open()
{ CALL
  // Check if the current writer is not opened.
  ASSERT(!isOpened(), STR("Cannot open the writer which is already opened."))
  {
    return false;
  }

  // Open the writer and initialize its parameters.
  if (onOpen(e_OPEN_WRITE))
  {
    // Set default format values.
    setDefaultFormat();
    // Set default parse values.
    setDefaultParse();

    m_IsOpened = true;
    m_IsEOF = false;
    m_WrittenBytesCount = 0;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tuint IWriter::writeBuffer(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current writer is opened.
  ASSERT(isOpened(), STR("Cannot write the buffer into the closed writer."))
  {
    return 0;
  }
  // Check if the current writer is opened in binary mode.
  ASSERT(isBinaryMode(), STR("Cannot write the buffer into the writer opened in the text mode."))
  {
    return 0;
  }

  // Nothing to write.
  if (a_cSize == 0)
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot write from the buffer which is NULL."))
  {
    return 0;
  }

  // Write the given buffer into the writer.
  Tuint counter = onWriteBinary(a_cpBuffer, a_cSize);
  m_WrittenBytesCount += counter;

  // Auto-flush writer.
  if (isAutoFlush())
    flush();

  return counter;
}
/*--------------------------------------------------------------------------*/
Tuint IWriter::writeBuffer(Tcptr a_cpBuffer, const Tuint a_cSingleSize, const Tuint a_cCount)
{ CALL
  // Check if the current writer is opened.
  ASSERT(isOpened(), STR("Cannot write the buffer into the closed writer."))
  {
    return 0;
  }
  // Check if the current writer is opened in binary mode.
  ASSERT(isBinaryMode(), STR("Cannot write the buffer into the writer opened in the text mode."))
  {
    return 0;
  }

  // Nothing to write.
  if ((a_cSingleSize == 0) || (a_cCount == 0))
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot write from the buffer which is NULL."))
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

      // Write all items.
      while (counter-- > 0)
      {
        Tuint local_counter = a_cSingleSize;
        Tcbuffer local_buffer = buffer + a_cSingleSize - 1;

        // Write single item.
        while (local_counter-- > 0)
          if (writeBuffer((Tcptr)local_buffer--, 1) != 1)
            return result + a_cSingleSize - local_counter - 1;

        result += a_cSingleSize;
        buffer += a_cSingleSize;
      }
    }
    return result;
  }
  else
    return writeBuffer(a_cpBuffer, a_cSingleSize * a_cCount);
}
/*--------------------------------------------------------------------------*/
Tuint IWriter::writeBuffer(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current writer is opened.
  ASSERT(isOpened(), STR("Cannot write the buffer into the closed writer."))
  {
    return 0;
  }
  // Check if the current writer is opened in text mode.
  ASSERT(isTextMode(), STR("Cannot write the buffer into the writer opened in the binary mode."))
  {
    return 0;
  }

  // Nothing to write.
  if (a_cSize == 0)
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot write from the buffer which is NULL."))
  {
    return 0;
  }

  // Write the given string buffer into the writer.
  Tuint counter;
  Tsstr strbuffer = (Tsstr)a_cpBuffer;
  #if defined(__BIG_ENDIAN__)
  if ((getByteOrder() == e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Tschar) > 1))
  #else
  if ((getByteOrder() != e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Tschar) > 1))
  #endif
  {
    // Write all items.
    Tschar character;
    counter = a_cSize;
    while (counter > 0)
    {
      NMemory::CMemory::copyReverse(&character, strbuffer, sizeof(Tschar));
      if (onWriteText(&character, 1) == 1)
      {
        ++strbuffer;
        --counter;
        m_WrittenBytesCount += sizeof(Tschar);
      }
      else
        break;
    }
    counter = a_cSize - counter;
  }
  else
  {
    counter = onWriteText(strbuffer, a_cSize);
    m_WrittenBytesCount += counter * sizeof(Tschar);
  }

  // Auto-flush writer.
  if (isAutoFlush())
    flush();

  return counter;
}
/*--------------------------------------------------------------------------*/
Tuint IWriter::writeBuffer(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Check if the current writer is opened.
  ASSERT(isOpened(), STR("Cannot write the buffer into the closed writer."))
  {
    return 0;
  }
  // Check if the current writer is opened in text mode.
  ASSERT(isTextMode(), STR("Cannot write the buffer into the writer opened in the binary mode."))
  {
    return 0;
  }

  // Nothing to write.
  if (a_cSize == 0)
    return 0;

  // Check if the given buffer is not NULL.
  ASSERT((a_cpBuffer != NULL), STR("Cannot write from the buffer which is NULL."))
  {
    return 0;
  }

  // Write the given string buffer into the writer.
  Tuint counter;
  Twstr strbuffer = (Twstr)a_cpBuffer;
  #if defined(__BIG_ENDIAN__)
  if ((getByteOrder() == e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Twchar) > 1))
  #else
  if ((getByteOrder() != e_BYTE_ORDER_LITTLE_ENDIAN) && (sizeof(Twchar) > 1))
  #endif
  {
    // Write all items.
    Twchar character;
    counter = a_cSize;
    while (counter > 0)
    {
      NMemory::CMemory::copyReverse(&character, strbuffer, sizeof(Twchar));
      if (onWriteText(&character, 1) == 1)
      {
        ++strbuffer;
        --counter;
        m_WrittenBytesCount += sizeof(Twchar);
      }
      else
        break;
    }
    counter = a_cSize - counter;
  }
  else
  {
    counter = onWriteText(strbuffer, a_cSize);
    m_WrittenBytesCount += counter * sizeof(Twchar);
  }

  // Auto-flush writer.
  if (isAutoFlush())
    flush();

  return counter;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tschar a_cCharacter)
{ CALL
  return NDetails::CStreamHelper::outputChar(*this, a_cCharacter);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Twchar a_cCharacter)
{ CALL
  return NDetails::CStreamHelper::outputChar(*this, a_cCharacter);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tcsstr a_cpString)
{ CALL
  return NDetails::CStreamHelper::outputString(*this, a_cpString);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tcwstr a_cpString)
{ CALL
  return NDetails::CStreamHelper::outputString(*this, a_cpString);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const NString::CStringASCII& a_crString)
{ CALL
  return NDetails::CStreamHelper::outputString(*this, a_crString);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const NString::CStringUnicode& a_crString)
{ CALL
  return NDetails::CStreamHelper::outputString(*this, a_crString);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const NString::CSystemString& a_crString)
{ CALL
  return NDetails::CStreamHelper::outputString(*this, a_crString);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tbool a_cBoolean, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputBool(*this, a_cBoolean, a_cFormatFlags, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tsint08 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tuint08 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tsint16 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tuint16 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tsint32 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tuint32 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tsint64 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tuint64 a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputInteger(*this, a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tfloat a_cReal, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cPrecision/* = 6 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputReal(*this, a_cReal, a_cFormatFlags, a_cPrecision, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(const Tdouble a_cReal, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cPrecision/* = 6 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputReal(*this, a_cReal, a_cFormatFlags, a_cPrecision, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::write(Tcptr a_cpPointer, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cWidth/* = 0 */)
{ CALL
  return NDetails::CStreamHelper::outputPointer(*this, a_cpPointer, a_cFormatFlags, a_cWidth);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::writeFormat(const Tcsstr a_cpFormatString, ...)
{ CALL
  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = writeFormatVarList(a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::writeFormatVarList(const Tcsstr a_cpFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::outputFormat(*this, a_cpFormatString, NAlgorithms::NString::NBuffer::strLen(a_cpFormatString), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::writeFormat(const Tcwstr a_cpFormatString, ...)
{ CALL
  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = writeFormatVarList(a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::writeFormatVarList(const Tcwstr a_cpFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::outputFormat(*this, a_cpFormatString, NAlgorithms::NString::NBuffer::strLen(a_cpFormatString), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::writeFormat(const NString::CStringASCII* a_cpFormatString, ...)
{ CALL
  // Check the given format string not to be NULL.
  ASSERT((a_cpFormatString != NULL), STR("Format string cannot be NULL."))
  {
    return NUtility::CPair<Tbool, Tuint>(false, 0);
  }

  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = writeFormatVarList(*a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::writeFormatVarList(const NString::CStringASCII& a_crFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::outputFormat(*this, a_crFormatString.getBuffer(), a_crFormatString.getSize(), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::writeFormat(const NString::CStringUnicode* a_cpFormatString, ...)
{ CALL
  // Check the given format string not to be NULL.
  ASSERT((a_cpFormatString != NULL), STR("Format string cannot be NULL."))
  {
    return NUtility::CPair<Tbool, Tuint>(false, 0);
  }

  va_list variable_list;

  va_start(variable_list, a_cpFormatString);
  NUtility::CPair<Tbool, Tuint> result = writeFormatVarList(*a_cpFormatString, variable_list);
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::writeFormatVarList(const NString::CStringUnicode& a_crFormatString, va_list a_VariableList)
{ CALL
  return NDetails::CStreamHelper::outputFormat(*this, a_crFormatString.getBuffer(), a_crFormatString.getSize(), a_VariableList);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::writeLineEnd()
{ CALL
  if (IStream::getCurrentFormatFlags() & IStream::FORMAT_ASCII)
    return write(getLineEndingStringASCII());
  else
    return write(getLineEndingStringUnicode());
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Tbool, Tuint> IWriter::writeLineEnd(const Tbool a_cIsASCII)
{ CALL
  if (a_cIsASCII)
    return write(getLineEndingStringASCII());
  else
    return write(getLineEndingStringUnicode());
}
/*--------------------------------------------------------------------------*/
Tbool IWriter::flush()
{ CALL
  // Check if the current writer is opened.
  ASSERT(isOpened(), STR("Cannot flush the closed writer."))
  {
    return false;
  }

  return onFlush();
}
/*--------------------------------------------------------------------------*/
Tbool IWriter::close()
{ CALL
  // Check if the current writer is opened.
  ASSERT(isOpened(), STR("Cannot close the writer which is already closed."))
  {
    return false;
  }

  // Flush writer before close.
  if (!isAutoFlush() && !flush())
    return false;

  // Close the writer and reset its parameters.
  if (onClose())
  {
    m_IsOpened = false;
    m_IsEOF = false;
    m_WrittenBytesCount = 0;
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
