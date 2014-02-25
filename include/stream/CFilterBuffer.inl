/*!
 *  \file    CFilterBuffer.inl Buffer filter class accumulates data from
 *           another stream/filter in the dynamic or static buffer until
 *           flush is not called.
 *  \brief   Buffer filter class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Buffer filter class (inline).

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
#ifndef __CFILTERBUFFER_INL__
#define __CFILTERBUFFER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CFilterBuffer::CFilterBuffer(const Tuint a_cSize/* = 0 */, const Tbool a_cStatic/* = false */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadBuffer(a_cSize, a_cStatic),
  m_ReadBufferIndex(0),
  m_ReadBufferSize(0),
  m_ReadBufferType(0),
  m_WriteBuffer(a_cSize, a_cStatic),
  m_WriteBufferIndex(0),
  m_WriteBufferSize(0),
  m_WriteBufferType(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterBuffer::CFilterBuffer(IReader* a_pReader, const Tuint a_cSize/* = 0 */, const Tbool a_cStatic/* = false */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadBuffer(a_cSize, a_cStatic),
  m_ReadBufferIndex(0),
  m_ReadBufferSize(0),
  m_ReadBufferType(0),
  m_WriteBuffer(a_cSize, a_cStatic),
  m_WriteBufferIndex(0),
  m_WriteBufferSize(0),
  m_WriteBufferType(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterBuffer::CFilterBuffer(IWriter* a_pWriter, const Tuint a_cSize/* = 0 */, const Tbool a_cStatic/* = false */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadBuffer(a_cSize, a_cStatic),
  m_ReadBufferIndex(0),
  m_ReadBufferSize(0),
  m_ReadBufferType(0),
  m_WriteBuffer(a_cSize, a_cStatic),
  m_WriteBufferIndex(0),
  m_WriteBufferSize(0),
  m_WriteBufferType(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterBuffer::CFilterBuffer(IReaderWriter* a_pReaderWriter, const Tuint a_cSize/* = 0 */, const Tbool a_cStatic/* = false */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReaderWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadBuffer(a_cSize, a_cStatic),
  m_ReadBufferIndex(0),
  m_ReadBufferSize(0),
  m_ReadBufferType(0),
  m_WriteBuffer(a_cSize, a_cStatic),
  m_WriteBufferIndex(0),
  m_WriteBufferSize(0),
  m_WriteBufferType(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterBuffer::CFilterBuffer(IReader* a_pReader, IWriter* a_pWriter, const Tuint a_cSize/* = 0 */, const Tbool a_cStatic/* = false */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadBuffer(a_cSize, a_cStatic),
  m_ReadBufferIndex(0),
  m_ReadBufferSize(0),
  m_ReadBufferType(0),
  m_WriteBuffer(a_cSize, a_cStatic),
  m_WriteBufferIndex(0),
  m_WriteBufferSize(0),
  m_WriteBufferType(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterBuffer::CFilterBuffer(const CFilterBuffer& a_crInstance) :
  IStream(a_crInstance),
  IFilter(a_crInstance),
  m_ReadBuffer(),
  m_ReadBufferIndex(0),
  m_ReadBufferSize(0),
  m_ReadBufferType(0),
  m_WriteBuffer(),
  m_WriteBufferIndex(0),
  m_WriteBufferSize(0),
  m_WriteBufferType(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CFilterBuffer::~CFilterBuffer()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CFilterBuffer& CFilterBuffer::operator = (const CFilterBuffer& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CFilterBuffer::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::CFilterBuffer")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_ReadBuffer, STR("m_ReadBuffer")));
    CHECK(a_rArchive.doValue((IFilter&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_ReadBufferIndex, STR("m_ReadBufferIndex")));
    CHECK(a_rArchive.doValue(m_ReadBufferSize, STR("m_ReadBufferSize")));
    CHECK(a_rArchive.doValue(m_ReadBufferType, STR("m_ReadBufferType")));
    CHECK(a_rArchive.doValue(m_WriteBuffer, STR("m_WriteBuffer")));
    CHECK(a_rArchive.doValue(m_WriteBufferIndex, STR("m_WriteBufferIndex")));
    CHECK(a_rArchive.doValue(m_WriteBufferSize, STR("m_WriteBufferSize")));
    CHECK(a_rArchive.doValue(m_WriteBufferType, STR("m_WriteBufferType")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CFilterBuffer::swap(CFilterBuffer& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IFilter&)(*this), (IFilter&)a_rInstance);
  NAlgorithms::NCommon::swap(m_ReadBuffer, a_rInstance.m_ReadBuffer);
  NAlgorithms::NCommon::swap(m_ReadBufferIndex, a_rInstance.m_ReadBufferIndex);
  NAlgorithms::NCommon::swap(m_ReadBufferSize, a_rInstance.m_ReadBufferSize);
  NAlgorithms::NCommon::swap(m_ReadBufferType, a_rInstance.m_ReadBufferType);
  NAlgorithms::NCommon::swap(m_WriteBuffer, a_rInstance.m_WriteBuffer);
  NAlgorithms::NCommon::swap(m_WriteBufferIndex, a_rInstance.m_WriteBufferIndex);
  NAlgorithms::NCommon::swap(m_WriteBufferSize, a_rInstance.m_WriteBufferSize);
  NAlgorithms::NCommon::swap(m_WriteBufferType, a_rInstance.m_WriteBufferType);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
