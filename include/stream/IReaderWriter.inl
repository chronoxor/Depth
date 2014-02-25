/*!
 *  \file    IReaderWriter.inl Reader & Writer is a base stream interface for
 *           all implementations of stream classes which use byte input and
 *           output at the same time.
 *  \brief   Reader & Writer interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reader & Writer interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   15.08.2008 22:43:09

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
#ifndef __IREADERWRITER_INL__
#define __IREADERWRITER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline IReaderWriter::IReaderWriter(const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReader(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IWriter(a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IReaderWriter::IReaderWriter(const IReaderWriter& a_crInstance) :
  IStream(a_crInstance),
  IReader(a_crInstance),
  IWriter(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline IReaderWriter::~IReaderWriter()
{ CALL
  // Close opened reader & writer.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline IReaderWriter& IReaderWriter::operator = (const IReaderWriter& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool IReaderWriter::isOpened() const
{ CALL
  return (IReader::isOpened() || IWriter::isOpened());
}
/*--------------------------------------------------------------------------*/
inline Tbool IReaderWriter::isOpenedRead() const
{ CALL
  return IReader::isOpened();
}
/*--------------------------------------------------------------------------*/
inline Tbool IReaderWriter::isOpenedWrite() const
{ CALL
  return IWriter::isOpened();
}
/*--------------------------------------------------------------------------*/
inline Tbool IReaderWriter::isOpenedReadWrite() const
{ CALL
  return (IReader::isOpened() && IWriter::isOpened());
}
/*--------------------------------------------------------------------------*/
inline Tbool IReaderWriter::isEOF() const
{ CALL
  return (IReader::isEOF() || IWriter::isEOF());
}
/*--------------------------------------------------------------------------*/
inline Tbool IReaderWriter::isEOFRead() const
{ CALL
  return IReader::isEOF();
}
/*--------------------------------------------------------------------------*/
inline Tbool IReaderWriter::isEOFWrite() const
{ CALL
  return IWriter::isEOF();
}
/*--------------------------------------------------------------------------*/
inline Tbool IReaderWriter::isEOFReadWrite() const
{ CALL
  return (IReader::isEOF() && IWriter::isEOF());
}
/*--------------------------------------------------------------------------*/
inline Tbool IReaderWriter::openRead()
{ CALL
  return open(IStream::e_OPEN_READ);
}
/*--------------------------------------------------------------------------*/
inline Tbool IReaderWriter::openWrite()
{ CALL
  return open(IStream::e_OPEN_WRITE);
}
/*--------------------------------------------------------------------------*/
inline Tbool IReaderWriter::openReadWrite()
{ CALL
  return open(IStream::e_OPEN_READWRITE);
}
/*--------------------------------------------------------------------------*/
inline Tbool IReaderWriter::onOpen()
{ CALL
  return false;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IReaderWriter::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IReaderWriter")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IStream&)(*this), STR("base")));
    CHECK(a_rArchive.doValue((IReader&)(*this), STR("base")));
    CHECK(a_rArchive.doValue((IWriter&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void IReaderWriter::swap(IReaderWriter& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IStream&)(*this), (IStream&)a_rInstance);
  NAlgorithms::NCommon::swap((IReader&)(*this), (IReader&)a_rInstance);
  NAlgorithms::NCommon::swap((IWriter&)(*this), (IWriter&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
