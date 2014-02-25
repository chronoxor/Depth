/*!
 *  \file    IFilter.inl Filter stream interface is a base interface for
 *           all implementations of stream filter classes which are used
 *           to perform additional data manipulation during input/output
 *           operations (e.g. buffering, encoding / decoding, inflating /
 *           deflating, etc.).
 *  \brief   Filter interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Filter interface (inline).

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
#ifndef __IFILTER_INL__
#define __IFILTER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline IFilter::IFilter(const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_pReader(NULL),
  m_pWriter(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IFilter::IFilter(IReader* a_pReader, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_pReader(NULL),
  m_pWriter(NULL)
{ CALL
  setReader(a_pReader);
}
/*--------------------------------------------------------------------------*/
inline IFilter::IFilter(IWriter* a_pWriter, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_pReader(NULL),
  m_pWriter(NULL)
{ CALL
  setWriter(a_pWriter);
}
/*--------------------------------------------------------------------------*/
inline IFilter::IFilter(IReaderWriter* a_pReaderWriter, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_pReader(NULL),
  m_pWriter(NULL)
{ CALL
  setReaderWriter(a_pReaderWriter);
}
/*--------------------------------------------------------------------------*/
inline IFilter::IFilter(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_pReader(NULL),
  m_pWriter(NULL)
{ CALL
  setReader(a_pReader);
  setWriter(a_pWriter);
}
/*--------------------------------------------------------------------------*/
inline IFilter::IFilter(const IFilter& a_crInstance) :
  IStream(a_crInstance),
  IReaderWriter(a_crInstance),
  m_pReader(NULL),
  m_pWriter(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline IFilter::~IFilter()
{ CALL
  // Close opened reader & writer.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline IFilter& IFilter::operator = (const IFilter& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool IFilter::isReadable() const
{ CALL
  return (m_pReader != NULL);
}
/*--------------------------------------------------------------------------*/
inline Tbool IFilter::isWritable() const
{ CALL
  return (m_pWriter != NULL);
}
/*--------------------------------------------------------------------------*/
inline Tbool IFilter::setReaderWriter(IReaderWriter* a_pReaderWriter)
{ CALL
  return (setReader(a_pReaderWriter) && setWriter(a_pReaderWriter));
}
/*--------------------------------------------------------------------------*/
inline Tbool IFilter::setReaderWriter(IReader* a_pReader, IWriter* a_pWriter)
{ CALL
  return (setReader(a_pReader) && setWriter(a_pWriter));
}
/*--------------------------------------------------------------------------*/
inline IReader* IFilter::getReader()
{ CALL
  return m_pReader;
}
/*--------------------------------------------------------------------------*/
inline const IReader* IFilter::getReader() const
{ CALL
  return m_pReader;
}
/*--------------------------------------------------------------------------*/
inline IWriter* IFilter::getWriter()
{ CALL
  return m_pWriter;
}
/*--------------------------------------------------------------------------*/
inline const IWriter* IFilter::getWriter() const
{ CALL
  return m_pWriter;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IFilter::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IFilter")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IReaderWriter&)(*this), STR("base")));
    CHECK(a_rArchive.doPointer(m_pReader, STR("m_pReader")));
    CHECK(a_rArchive.doPointer(m_pWriter, STR("m_pWriter")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void IFilter::swap(IFilter& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IReaderWriter&)(*this), (IReaderWriter&)a_rInstance);
  NAlgorithms::NCommon::swap(m_pReader, a_rInstance.m_pReader);
  NAlgorithms::NCommon::swap(m_pWriter, a_rInstance.m_pWriter);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
