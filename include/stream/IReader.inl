/*!
 *  \file    IReader.inl Reader is a base stream interface for all
 *           implementations of stream classes which use byte input (files,
 *           pipes, sockets, etc.).
 *  \brief   Reader interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reader interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   13.08.2008 00:57:40

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
#ifndef __IREADER_INL__
#define __IREADER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline IReader::IReader(const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsOpened(false),
  m_IsEOF(false),
  m_ReadBytesCount(0),
  m_PeekBufferSize(0),
  m_PeekBufferFreeSize(0),
  m_pPeekBuffer(NULL)
{ CALL
  a_cTextMode ? setTextMode() : setBinaryMode();
  setByteOrder(a_cByteOrder);
  setLineEnding(a_cLineEnding);
}
/*--------------------------------------------------------------------------*/
inline IReader::IReader(const IReader& a_crInstance) :
  IStream(a_crInstance),
  m_IsOpened(false),
  m_IsEOF(false),
  m_ReadBytesCount(0),
  m_PeekBufferSize(0),
  m_PeekBufferFreeSize(0),
  m_pPeekBuffer(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline IReader::~IReader()
{ CALL
  // Close opened reader.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline IReader& IReader::operator = (const IReader& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void IReader::setEOF(const Tbool a_cEOF/* = true */)
{ CALL
  m_IsEOF = a_cEOF;
}
/*--------------------------------------------------------------------------*/
inline Tbool IReader::isOpened() const
{ CALL
  return m_IsOpened;
}
/*--------------------------------------------------------------------------*/
inline Tbool IReader::isEOF() const
{ CALL
  return m_IsEOF;
}
/*--------------------------------------------------------------------------*/
inline Tuint IReader::getReadBytesCount() const
{ CALL
  return m_ReadBytesCount;
}
/*--------------------------------------------------------------------------*/
inline Tuint IReader::getPeekBufferSize() const
{ CALL
  return m_PeekBufferSize;
}
/*--------------------------------------------------------------------------*/
inline Tuint IReader::getPeekBufferFreeSize() const
{ CALL
  return m_PeekBufferFreeSize;
}
/*--------------------------------------------------------------------------*/
inline Tbool IReader::onOpen(const EOpenType a_cOpenType)
{ CALL
  IGNORE_UNUSED(a_cOpenType);

  return onOpen();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReadIterator<T_Type> IReader::getItRead()
{ CALL
  CReadIterator<T_Type> it_read;

  // Filling iterator inner structure.
  it_read.m_pContainer = this;
  it_read.m_IsValid = read(it_read.m_Value).getFirst();
  return it_read;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPeekIterator<T_Type> IReader::getItPeek()
{ CALL
  CPeekIterator<T_Type> it_peek;

  // Filling iterator inner structure.
  it_peek.m_pContainer = this;
  it_peek.m_IsValid = peek(it_peek.m_Value).getFirst();
  return it_peek;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPushIterator<T_Type> IReader::getItPush()
{ CALL
  return CPushIterator<T_Type>(this);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IReader::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Clear the current peek buffer of the reader.
  if ((m_PeekBufferSize > 0) && (m_pPeekBuffer != NULL))
  {
    delete [] m_pPeekBuffer;
    m_pPeekBuffer = NULL;
  }

  // Load the reader header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IReader")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IStream&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_IsOpened, STR("m_IsOpened")));
    CHECK(a_rArchive.doValue(m_IsEOF, STR("m_IsEOF")));
    CHECK(a_rArchive.doValue(m_ReadBytesCount, STR("m_ReadBytesCount")));
    CHECK(a_rArchive.doValue(m_PeekBufferSize, STR("m_PeekBufferSize")));
    CHECK(a_rArchive.doValue(m_PeekBufferFreeSize, STR("m_PeekBufferFreeSize")));

    // Try to allocate peek buffer.
    if (m_PeekBufferSize > 0)
    {
      m_pPeekBuffer = newex Tbyte[m_PeekBufferSize];
      if (m_pPeekBuffer == NULL)
      {
        WARNING(STR("Cannot allocate peek buffer for the reader (requested size is %u bytes).") COMMA m_PeekBufferSize);
        return false;
      }

      // Load content of the peek buffer.
      CHECK(a_rArchive.doValue(m_pPeekBuffer, m_PeekBufferSize, STR("m_pPeekBuffer")));
    }

  // Load the byte buffer end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IReader::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the reader header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IReader")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IStream&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_IsOpened, STR("m_IsOpened")));
    CHECK(a_rArchive.doValue(m_IsEOF, STR("m_IsEOF")));
    CHECK(a_rArchive.doValue(m_ReadBytesCount, STR("m_ReadBytesCount")));
    CHECK(a_rArchive.doValue(m_PeekBufferSize, STR("m_PeekBufferSize")));
    CHECK(a_rArchive.doValue(m_PeekBufferFreeSize, STR("m_PeekBufferFreeSize")));

    // Save content of the peek buffer.
    if (m_PeekBufferSize > 0)
    {
      CHECK(a_rArchive.doValue(m_pPeekBuffer, m_PeekBufferSize, STR("m_pPeekBuffer")));
    }

  // Save the reader end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IReader::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void IReader::swap(IReader& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IStream&)(*this), (IStream&)a_rInstance);
  NAlgorithms::NCommon::swap(m_IsOpened, a_rInstance.m_IsOpened);
  NAlgorithms::NCommon::swap(m_IsEOF, a_rInstance.m_IsEOF);
  NAlgorithms::NCommon::swap(m_ReadBytesCount, a_rInstance.m_ReadBytesCount);
  NAlgorithms::NCommon::swap(m_PeekBufferSize, a_rInstance.m_PeekBufferSize);
  NAlgorithms::NCommon::swap(m_PeekBufferFreeSize, a_rInstance.m_PeekBufferFreeSize);
  NAlgorithms::NCommon::swap(m_pPeekBuffer, a_rInstance.m_pPeekBuffer);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
