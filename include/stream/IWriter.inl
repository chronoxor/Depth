/*!
 *  \file    IWriter.inl Writer is a base stream interface for all
 *           implementations of stream classes which use byte output (files,
 *           pipes, sockets, etc.).
 *  \brief   Writer interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Writer interface (inline).

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
#ifndef __IWRITER_INL__
#define __IWRITER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline IWriter::IWriter(const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsOpened(false),
  m_IsEOF(false),
  m_WrittenBytesCount(0)
{ CALL
  a_cTextMode ? setTextMode() : setBinaryMode();
  setByteOrder(a_cByteOrder);
  setLineEnding(a_cLineEnding);
}
/*--------------------------------------------------------------------------*/
inline IWriter::IWriter(const IWriter& a_crInstance) :
  IStream(a_crInstance),
  m_IsOpened(false),
  m_IsEOF(false),
  m_WrittenBytesCount(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline IWriter::~IWriter()
{ CALL
  // Close opened writer.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline IWriter& IWriter::operator = (const IWriter& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void IWriter::setEOF(const Tbool a_cEOF/* = true */)
{ CALL
  m_IsEOF = a_cEOF;
}
/*--------------------------------------------------------------------------*/
inline Tbool IWriter::isOpened() const
{ CALL
  return m_IsOpened;
}
/*--------------------------------------------------------------------------*/
inline Tbool IWriter::isEOF() const
{ CALL
  return m_IsEOF;
}
/*--------------------------------------------------------------------------*/
inline Tuint IWriter::getWrittenBytesCount() const
{ CALL
  return m_WrittenBytesCount;
}
/*--------------------------------------------------------------------------*/
inline Tbool IWriter::onOpen(const EOpenType a_cOpenType)
{ CALL
  IGNORE_UNUSED(a_cOpenType);

  return onOpen();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWriteIterator<T_Type> IWriter::getItWrite()
{ CALL
  return CWriteIterator<T_Type>(this);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IWriter::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IWriter")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IStream&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_IsOpened, STR("m_IsOpened")));
    CHECK(a_rArchive.doValue(m_IsEOF, STR("m_IsEOF")));
    CHECK(a_rArchive.doValue(m_WrittenBytesCount, STR("m_WrittenBytesCount")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void IWriter::swap(IWriter& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IStream&)(*this), (IStream&)a_rInstance);
  NAlgorithms::NCommon::swap(m_IsOpened, a_rInstance.m_IsOpened);
  NAlgorithms::NCommon::swap(m_IsEOF, a_rInstance.m_IsEOF);
  NAlgorithms::NCommon::swap(m_WrittenBytesCount, a_rInstance.m_WrittenBytesCount);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
