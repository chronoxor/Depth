/*!
 *  \file    IExchangeReaderWriter.inl Exchange stream reader & writer
 *           is a base interface for all implementations of exchange
 *           stream classes which use interprocess communication byte
 *           input and output (files, pipes, sockets, etc.).
 *  \brief   Exchange reader & writer interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Exchange reader & writer interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   30.03.2009 02:36:19

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
#ifndef __IEXCHANGEREADERWRITER_INL__
#define __IEXCHANGEREADERWRITER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline IExchangeReaderWriter::IExchangeReaderWriter(const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */, const Tbool a_cIsExchange/* = false */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IExchangeStream(a_cTextMode, a_cByteOrder, a_cLineEnding, a_cIsExchange),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IExchangeReaderWriter::IExchangeReaderWriter(const IExchangeReaderWriter& a_crInstance) :
  IStream(a_crInstance),
  IExchangeStream(a_crInstance),
  IReaderWriter(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline IExchangeReaderWriter::~IExchangeReaderWriter()
{ CALL
  // Close opened exchange reader & writer.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline IExchangeReaderWriter& IExchangeReaderWriter::operator = (const IExchangeReaderWriter& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IExchangeReaderWriter::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IExchangeReaderWriter")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IExchangeStream&)(*this), STR("base")));
    CHECK(a_rArchive.doValue((IReaderWriter&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void IExchangeReaderWriter::swap(IExchangeReaderWriter& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IExchangeStream&)(*this), (IExchangeStream&)a_rInstance);
  NAlgorithms::NCommon::swap((IReaderWriter&)(*this), (IReaderWriter&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
