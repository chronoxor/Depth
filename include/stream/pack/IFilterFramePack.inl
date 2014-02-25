/*!
 *  \file    IFilterFramePack.inl Frame packing filter stream interface is a
 *           base interface for all implementations of stream frame packing
 *           filter classes which are used to perform data pack operations
 *           using read and write frame buffering operations.
 *  \brief   Frame packing filter interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Frame packing filter interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   10.11.2009 03:39:25

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
#ifndef __IFILTERFRAMEPACK_INL__
#define __IFILTERFRAMEPACK_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NPack {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::IFilterFramePack(const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadFrameSize(0),
  m_WriteFrameSize(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::IFilterFramePack(IReader* a_pReader, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadFrameSize(0),
  m_WriteFrameSize(0)
{ CALL
  setReader(a_pReader);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::IFilterFramePack(IWriter* a_pWriter, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadFrameSize(0),
  m_WriteFrameSize(0)
{ CALL
  setWriter(a_pWriter);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::IFilterFramePack(IReaderWriter* a_pReaderWriter, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadFrameSize(0),
  m_WriteFrameSize(0)
{ CALL
  setReaderWriter(a_pReaderWriter);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::IFilterFramePack(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadFrameSize(0),
  m_WriteFrameSize(0)
{ CALL
  setReader(a_pReader);
  setWriter(a_pWriter);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::IFilterFramePack(const IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>& a_crInstance) :
  IStream(a_crInstance),
  IFilter(a_crInstance),
  m_ReadFrameSize(0),
  m_WriteFrameSize(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::~IFilterFramePack()
{ CALL
  // Close opened reader & writer.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>& IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::operator = (const IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tbool IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::set(const IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>& a_crInstance)
{ CALL
  // Check if the given interface instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same IFilterFramePack interface instance."))
  {
    return false;
  }

  // Initialize base filter.
  if (!IFilter::set(a_crInstance))
    return false;

  // Set input/output pack frames.
  m_ReadFrameSize = a_crInstance.m_ReadFrameSize;
  m_WriteFrameSize = a_crInstance.m_WriteFrameSize;
  NMemory::CMemory::copy(m_ReadFrame, a_crInstance.m_ReadFrame, t_ReadFrameSize);
  NMemory::CMemory::copy(m_WriteFrame, a_crInstance.m_WriteFrame, t_WriteFrameSize);
  return true;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tuint IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::getReadFrameSize() const
{ CALL
  return m_ReadFrameSize;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tuint IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::getWriteFrameSize() const
{ CALL
  return m_WriteFrameSize;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tuint IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::getReadFrameFreeSize() const
{ CALL
  return t_ReadFrameSize - m_ReadFrameSize;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tuint IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::getWriteFrameFreeSize() const
{ CALL
  return t_WriteFrameSize - m_WriteFrameSize;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tuint IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::getReadFrameFullSize() const
{ CALL
  return t_ReadFrameSize;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tuint IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::getWriteFrameFullSize() const
{ CALL
  return t_WriteFrameSize;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tbuffer IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::getReadFrame()
{ CALL
  return m_ReadFrame;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tcbuffer IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::getReadFrame() const
{ CALL
  return m_WriteFrame;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tbuffer IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::getWriteFrame()
{ CALL
  return m_ReadFrame;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tcbuffer IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::getWriteFrame() const
{ CALL
  return m_WriteFrame;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tbool IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::onOpen(const EOpenType a_cOpenType)
{ CALL
  // Try to open base filter.
  if (!IFilter::onOpen(a_cOpenType))
    return false;

  // Reset read and write buffers.
  m_ReadFrameSize = 0;
  m_WriteFrameSize = 0;
  NMemory::CMemory::zero(m_ReadFrame, t_ReadFrameSize);
  NMemory::CMemory::zero(m_WriteFrame, t_WriteFrameSize);

  // Perform frame pack filter read initialization.
  if ((getReader() !=NULL) && (getReader()->isOpened()))
  {
    if (!onOpenReadFrame(*getReader(), m_ReadFrame, m_ReadFrameSize, t_ReadFrameSize))
      return false;
  }

  // Perform frame pack filter write initialization.
  if ((getWriter() !=NULL) && (getWriter()->isOpened()))
  {
    if (!onOpenWriteFrame(*getWriter(), m_WriteFrame, m_WriteFrameSize, t_WriteFrameSize))
      return false;
  }

  return true;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tbool IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::onClose()
{ CALL
  // Perform frame pack filter read deinitialization.
  if ((getReader() !=NULL) && (getReader()->isOpened()))
  {
    if (!onCloseReadFrame(*getReader(), m_ReadFrame, m_ReadFrameSize, t_ReadFrameSize))
      return false;
  }

  // Perform frame pack filter write deinitialization.
  if ((getWriter() !=NULL) && (getWriter()->isOpened()))
  {
    if (!onCloseWriteFrame(*getWriter(), m_WriteFrame, m_WriteFrameSize, t_WriteFrameSize))
      return false;
  }

  // Reset read and write buffers.
  m_ReadFrameSize = 0;
  m_WriteFrameSize = 0;
  NMemory::CMemory::zero(m_ReadFrame, t_ReadFrameSize);
  NMemory::CMemory::zero(m_WriteFrame, t_WriteFrameSize);

  // Try to close base filter.
  return IFilter::onClose();
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tuint IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  Tuint result = 0;
  Tuint count = a_cSize;
  Tbuffer dst = (Tbuffer)a_pBuffer;

  while (count > 0)
  {
    // Fill destination byte buffer directly from read frame buffer.
    if (m_ReadFrameSize > 0)
    {
      Tuint size = NAlgorithms::NCommon::min(m_ReadFrameSize, count);
      NMemory::CMemory::copy(dst, m_ReadFrame, size);
      result += size;
      count -= size;
      dst += size;

      // Shift read frame buffer.
      size = NAlgorithms::NCommon::min(m_ReadFrameSize, size);
      NMemory::CMemory::move(m_ReadFrame, m_ReadFrame + size, m_ReadFrameSize - size);
      m_ReadFrameSize -= size;

      // Check for stop reading.
      if (count == 0)
        break;
    }

    // Unpack data from reader into the read frame buffer.
    Tuint temp = m_ReadFrameSize;
    if (!onPackReadFrame(a_rReader, m_ReadFrame, m_ReadFrameSize, t_ReadFrameSize))
      break;
    if (temp >= m_ReadFrameSize)
      break;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tuint IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onFilterReadBinary(a_rReader, (Tptr)a_pBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tuint IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onFilterReadBinary(a_rReader, (Tptr)a_pBuffer, a_cSize * sizeof(Twchar)) / sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tuint IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  Tuint result = 0;
  Tuint count = a_cSize;
  Tcbuffer src = (Tcbuffer)a_cpBuffer;

  while (count > 0)
  {
    // Fill write frame buffer.
    if (m_WriteFrameSize < t_WriteFrameSize)
    {
      Tuint size = NAlgorithms::NCommon::min(t_WriteFrameSize - m_WriteFrameSize, count);
      NMemory::CMemory::copy(m_WriteFrame + m_WriteFrameSize, src, size);
      m_WriteFrameSize += size;
      result += size;
      count -= size;
      src += size;

      // Check for stop writing.
      if (count == 0)
        break;
    }

    // Pack data into writer from the write frame buffer.
    Tuint temp = m_WriteFrameSize;
    if (!onPackWriteFrame(a_rWriter, m_WriteFrame, m_WriteFrameSize, t_WriteFrameSize))
      break;
    if (temp <= m_WriteFrameSize)
      break;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tuint IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return onFilterWriteBinary(a_rWriter, (Tcptr)a_cpBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline Tuint IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return onFilterWriteBinary(a_rWriter, (Tcptr)a_cpBuffer, a_cSize * sizeof(Twchar)) / sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
template <class T_Archive>
inline Tbool IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NPack::IFilterFramePack")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IFilter&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_ReadFrameSize, STR("m_ReadFrameSize")));
    CHECK(a_rArchive.doValue(m_WriteFrameSize, STR("m_WriteFrameSize")));
    CHECK(a_rArchive.doValue(m_ReadFrame, t_ReadFrameSize, STR("m_ReadFrame")));
    CHECK(a_rArchive.doValue(m_WriteFrame, t_ReadFrameSize, STR("m_WriteFrame")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize>
inline void IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>::swap(IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IFilter&)(*this), (IFilter&)a_rInstance);
  NAlgorithms::NCommon::swap(m_ReadFrameSize, a_rInstance.m_ReadFrameSize);
  NAlgorithms::NCommon::swap(m_WriteFrameSize, a_rInstance.m_WriteFrameSize);
  NAlgorithms::NCommon::swap(m_ReadFrame, a_rInstance.m_ReadFrame, t_ReadFrameSize);
  NAlgorithms::NCommon::swap(m_WriteFrame, a_rInstance.m_WriteFrame, t_WriteFrameSize);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
