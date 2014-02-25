/*!
 *  \file    CStreamBuffer.inl Byte buffer stream class gives ability to
 *           read/write byte sequences from/into the static or dynamic
 *           byte buffer.
 *  \brief   Byte buffer stream class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Byte buffer stream class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   20.08.2008 20:58:46

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
#ifndef __CSTREAMBUFFER_INL__
#define __CSTREAMBUFFER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CStreamBuffer::CStreamBuffer(const Tuint a_cSize/* = 0 */, const Tbool a_cStatic/* = false */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NUtility::CBuffer(),
  m_Index(0)
{ CALL
  set(a_cSize, a_cStatic);
}
/*--------------------------------------------------------------------------*/
inline CStreamBuffer::CStreamBuffer(Tcbuffer a_cpBuffer, const Tuint a_cSize, const Tbool a_cStatic/* = false */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NUtility::CBuffer(),
  m_Index(0)
{ CALL
  set(a_cpBuffer, a_cSize, a_cStatic);
}
/*--------------------------------------------------------------------------*/
inline CStreamBuffer::CStreamBuffer(Tbuffer a_pBuffer, const Tuint a_cSize, const Tbool a_cStatic/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NUtility::CBuffer(),
  m_Index(0)
{ CALL
  set(a_pBuffer, a_cSize, a_cStatic);
}
/*--------------------------------------------------------------------------*/
inline CStreamBuffer::CStreamBuffer(const NUtility::CBuffer& a_crBuffer, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NUtility::CBuffer(),
  m_Index(0)
{ CALL
  set(a_crBuffer);
}
/*--------------------------------------------------------------------------*/
inline CStreamBuffer::CStreamBuffer(const CStreamBuffer& a_crInstance) :
  IStream(a_crInstance),
  IReaderWriter(a_crInstance),
  NCommon::ISeekable(),
  NUtility::CBuffer(),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CStreamBuffer::~CStreamBuffer()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CStreamBuffer& CStreamBuffer::operator = (const NUtility::CBuffer& a_crBuffer)
{ CALL
  set(a_crBuffer);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStreamBuffer& CStreamBuffer::operator = (const CStreamBuffer& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tuint CStreamBuffer::getSize() const
{ CALL
  return CBuffer::getSize();
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamBuffer::onOpen(const EOpenType a_cOpenType)
{ CALL
  IGNORE_UNUSED(a_cOpenType);

  m_Index = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tuint CStreamBuffer::onReadText(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onReadBinary(a_pBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
inline Tuint CStreamBuffer::onReadText(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onReadBinary(a_pBuffer, a_cSize * sizeof(Twchar)) / sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
inline Tuint CStreamBuffer::onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return onWriteBinary(a_cpBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
inline Tuint CStreamBuffer::onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return onWriteBinary(a_cpBuffer, a_cSize * sizeof(Twchar)) / sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamBuffer::onFlush()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamBuffer::onClose()
{ CALL
  m_Index = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStreamBuffer::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Close opened buffer stream.
  if (isOpened())
    CHECK(close());

  // Clear the current buffer stream.
  CHECK(clear());

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::CStreamBuffer")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CBuffer&)(*this), STR("base")));
    CHECK(a_rArchive.doValue((IReaderWriter&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStreamBuffer::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::CStreamBuffer")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CBuffer&)(*this), STR("base")));
    CHECK(a_rArchive.doValue((IReaderWriter&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStreamBuffer::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void CStreamBuffer::swap(CStreamBuffer& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CBuffer&)(*this), (CBuffer&)a_rInstance);
  NAlgorithms::NCommon::swap((IReaderWriter&)(*this), (IReaderWriter&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Index, a_rInstance.m_Index);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
