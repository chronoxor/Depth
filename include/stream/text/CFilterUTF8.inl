/*!
 *  \file    CFilterUTF8.inl UTF-8 string filter class converts given ASCII
 *           and Unicode strings into the UTF-8 equivalents.
 *  \brief   UTF-8 string filter class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: UTF-8 string filter class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   02.11.2009 03:37:38

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
#ifndef __CFILTERUTF8_INL__
#define __CFILTERUTF8_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NText {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CFilterUTF8::CFilterUTF8(const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterUTF8::CFilterUTF8(IReader* a_pReader, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterUTF8::CFilterUTF8(IWriter* a_pWriter, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterUTF8::CFilterUTF8(IReaderWriter* a_pReaderWriter, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReaderWriter, a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterUTF8::CFilterUTF8(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterUTF8::CFilterUTF8(const CFilterUTF8& a_crInstance) :
  IStream(a_crInstance),
  IFilter(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CFilterUTF8::~CFilterUTF8()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CFilterUTF8& CFilterUTF8::operator = (const CFilterUTF8& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CFilterUTF8::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CFilterUTF8")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IFilter&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CFilterUTF8::swap(CFilterUTF8& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IFilter&)(*this), (IFilter&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
