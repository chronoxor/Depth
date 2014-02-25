/*!
 *  \file    CFilterLineEnd.cpp Line end filter class helps to handle line end
 *           characters in the stream.
 *  \brief   Line end filter class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Line end filter class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   17.11.2009 02:04:19

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
#include <Depth/include/stream/text/CFilterLineEnd.hpp>
/*==========================================================================*/
#ifndef __CFILTERLINEEND_CPP__
#define __CFILTERLINEEND_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NText {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CFilterLineEnd::set(const CFilterLineEnd& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CFilterLineEnd class instance."))
  {
    return false;
  }

  // Initialize base filter class.
  if (!IFilter::set(a_crInstance))
    return false;

  // Initialize line end flags.
  m_ReadInterval = a_crInstance.m_ReadInterval;
  m_WriteInterval = a_crInstance.m_WriteInterval;
  m_CacheReadInterval = a_crInstance.m_CacheReadInterval;
  m_CacheWriteInterval = a_crInstance.m_CacheWriteInterval;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterLineEnd::onOpen(const EOpenType a_cOpenType)
{ CALL
  // Try to open base filter.
  if (!IFilter::onOpen(a_cOpenType))
    return false;

  // Clear cache.
  m_CacheReadInterval = m_ReadInterval;
  m_CacheWriteInterval = m_WriteInterval;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterLineEnd::onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  Tuint result = 0;
  Tuint count = a_cSize;
  Tbuffer dst = (Tbuffer)a_pBuffer;

  while (count > 0)
  {
    // Read cache character form the given reader.
    Tbyte cache;
    if (!a_rReader.read(cache).getFirst())
      return result;

    // Check for new line symbols.
    if ((cache == (Tbyte)(ASC('\r'))) || (cache == (Tbyte)(ASC('\n'))))
    {
      // Check line end interval.
      if (m_ReadInterval > 0)
      {
        if ((m_CacheReadInterval != 0) && (m_CacheReadInterval != m_ReadInterval))
        {
          WARNING(STR("Line end check was not successfully complete (remain interval = %u).") COMMA m_CacheReadInterval);
          return result;
        }
        m_CacheReadInterval = m_ReadInterval;
      }
      continue;
    }
    else
    {
      // Check line end interval.
      if (m_ReadInterval > 0)
      {
        if (m_CacheReadInterval == 0)
        {
          WARNING(STR("Line end check was not successfully complete (remain interval = %u).") COMMA m_CacheReadInterval);
          return result;
        }
        --m_CacheReadInterval;
      }
      *dst++ = cache;
      ++result;
      --count;
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterLineEnd::onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  Tuint result = 0;
  Tuint count = a_cSize;
  Tsstr dst = (Tsstr)a_pBuffer;

  while (count > 0)
  {
    // Read cache character form the given reader.
    Tschar cache;
    if (!a_rReader.read(cache).getFirst())
      return result;

    // Check for new line symbols.
    if ((cache == ASC('\r')) || (cache == ASC('\n')))
    {
      // Check line end interval.
      if (m_ReadInterval > 0)
      {
        if ((m_CacheReadInterval != 0) && (m_CacheReadInterval != m_ReadInterval))
        {
          WARNING(STR("Line end check was not successfully complete (remain interval = %u).") COMMA m_CacheReadInterval);
          return result;
        }
        m_CacheReadInterval = m_ReadInterval;
      }
      continue;
    }
    else
    {
      // Check line end interval.
      if (m_ReadInterval > 0)
      {
        if (m_CacheReadInterval == 0)
        {
          WARNING(STR("Line end check was not successfully complete (remain interval = %u).") COMMA m_CacheReadInterval);
          return result;
        }
        --m_CacheReadInterval;
      }
      *dst++ = cache;
      ++result;
      --count;
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterLineEnd::onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  Tuint result = 0;
  Tuint count = a_cSize;
  Twstr dst = (Twstr)a_pBuffer;

  while (count > 0)
  {
    // Read cache character form the given reader.
    Twchar cache;
    if (!a_rReader.read(cache).getFirst())
      return result;

    // Check for new line symbols.
    if ((cache == UNC('\r')) || (cache == UNC('\n')))
    {
      // Check line end interval.
      if (m_ReadInterval > 0)
      {
        if ((m_CacheReadInterval != 0) && (m_CacheReadInterval != m_ReadInterval))
        {
          WARNING(STR("Line end check was not successfully complete (remain interval = %u).") COMMA m_CacheReadInterval);
          return result;
        }
        m_CacheReadInterval = m_ReadInterval;
      }
      continue;
    }
    else
    {
      // Check line end interval.
      if (m_ReadInterval > 0)
      {
        if (m_CacheReadInterval == 0)
        {
          WARNING(STR("Line end check was not successfully complete (remain interval = %u).") COMMA m_CacheReadInterval);
          return result;
        }
        --m_CacheReadInterval;
      }
      *dst++ = cache;
      ++result;
      --count;
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterLineEnd::onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  if (m_WriteInterval > 0)
  {
    Tuint result = 0;
    Tuint count = a_cSize;
    Tcbuffer src = (Tcbuffer)a_cpBuffer;

    while (count > 0)
    {
      Tuint size = NAlgorithms::NCommon::min(m_CacheWriteInterval, count);
      Tuint written = a_rWriter.writeBuffer(src, size);
      m_CacheWriteInterval -= written;
      result += written;
      count -= written;
      src += written;

      // Check for the end of stream.
      if (written != size)
        break;

      // Write line end.
      if (m_CacheWriteInterval == 0)
      {
        if (IStream::getCurrentFormatFlags() & IStream::FORMAT_ASCII)
          a_rWriter.write(getLineEndingStringASCII());
        else
          a_rWriter.write(getLineEndingStringUnicode());
        m_CacheWriteInterval = m_WriteInterval;
      }
    }
    return result;
  }
  else
    return a_rWriter.writeBuffer(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterLineEnd::onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  if (m_WriteInterval > 0)
  {
    Tuint result = 0;
    Tuint count = a_cSize;
    Tcsstr src = (Tcsstr)a_cpBuffer;

    while (count > 0)
    {
      Tuint size = NAlgorithms::NCommon::min(m_CacheWriteInterval, count);
      Tuint written = a_rWriter.writeBuffer(src, size);
      m_CacheWriteInterval -= written;
      result += written;
      count -= written;
      src += written;

      // Check for the end of stream.
      if (written != size)
        break;

      // Write line end.
      if (m_CacheWriteInterval == 0)
      {
        if (IStream::getCurrentFormatFlags() & IStream::FORMAT_ASCII)
          a_rWriter.write(getLineEndingStringASCII());
        else
          a_rWriter.write(getLineEndingStringUnicode());
        m_CacheWriteInterval = m_WriteInterval;
      }
    }
    return result;
  }
  else
    return a_rWriter.writeBuffer(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterLineEnd::onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  if (m_WriteInterval > 0)
  {
    Tuint result = 0;
    Tuint count = a_cSize;
    Tcwstr src = (Tcwstr)a_cpBuffer;

    while (count > 0)
    {
      Tuint size = NAlgorithms::NCommon::min(m_CacheWriteInterval, count);
      Tuint written = a_rWriter.writeBuffer(src, size);
      m_CacheWriteInterval -= written;
      result += written;
      count -= written;
      src += written;

      // Check for the end of stream.
      if (written != size)
        break;

      // Write line end.
      if (m_CacheWriteInterval == 0)
      {
        if (IStream::getCurrentFormatFlags() & IStream::FORMAT_ASCII)
          a_rWriter.write(getLineEndingStringASCII());
        else
          a_rWriter.write(getLineEndingStringUnicode());
        m_CacheWriteInterval = m_WriteInterval;
      }
    }
    return result;
  }
  else
    return a_rWriter.writeBuffer(a_cpBuffer, a_cSize);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
