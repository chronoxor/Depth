/*!
 *  \file    CFilterBase64.inl Base64 string filter class converts given ASCII
 *           and Unicode strings into the corresponding hexadecimal
 *           representation.
 *  \brief   Base64 string filter class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base64 string filter class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   16.11.2009 02:50:23

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
#ifndef __CFILTERBASE64_INL__
#define __CFILTERBASE64_INL__
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
inline CFilterBase64::CFilterBase64(const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<3>(a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL
  CFilterBase64::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterBase64::CFilterBase64(IReader* a_pReader, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<3>(a_pReader, a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL
  CFilterBase64::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterBase64::CFilterBase64(IWriter* a_pWriter, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<3>(a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL
  CFilterBase64::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterBase64::CFilterBase64(IReaderWriter* a_pReaderWriter, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<3>(a_pReaderWriter, a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL
  CFilterBase64::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterBase64::CFilterBase64(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<3>(a_pReader, a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL
  CFilterBase64::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterBase64::CFilterBase64(const CFilterBase64& a_crInstance) :
  IStream(a_crInstance),
  NPack::IFilterFramePack<3>(a_crInstance)
{ CALL
  CFilterBase64::calculateTables();
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CFilterBase64::~CFilterBase64()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CFilterBase64& CFilterBase64::operator = (const CFilterBase64& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CFilterBase64::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CFilterBase64")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((NPack::IFilterFramePack<3>&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CFilterBase64::swap(CFilterBase64& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((NPack::IFilterFramePack<3>&)(*this), (NPack::IFilterFramePack<3>&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
