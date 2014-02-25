/*!
 *  \file    CFilterUTF16.inl UTF-16 string filter class converts given ASCII
 *           and Unicode strings into the UTF-16 equivalents.
 *  \brief   UTF-16 string filter class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: UTF-16 string filter class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   02.11.2009 02:09:38

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
#ifndef __CFILTERUTF16_INL__
#define __CFILTERUTF16_INL__
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
inline CFilterUTF16::CFilterUTF16(const Tbool a_cIsBigEndian/* = NConstants::CConstants::isBigEndian */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsBigEndian(a_cIsBigEndian)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterUTF16::CFilterUTF16(IReader* a_pReader, const Tbool a_cIsBigEndian/* = NConstants::CConstants::isBigEndian */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsBigEndian(a_cIsBigEndian)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterUTF16::CFilterUTF16(IWriter* a_pWriter, const Tbool a_cIsBigEndian/* = NConstants::CConstants::isBigEndian */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsBigEndian(a_cIsBigEndian)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterUTF16::CFilterUTF16(IReaderWriter* a_pReaderWriter, const Tbool a_cIsBigEndian/* = NConstants::CConstants::isBigEndian */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReaderWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsBigEndian(a_cIsBigEndian)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterUTF16::CFilterUTF16(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cIsBigEndian/* = NConstants::CConstants::isBigEndian */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsBigEndian(a_cIsBigEndian)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterUTF16::CFilterUTF16(const CFilterUTF16& a_crInstance) :
  IStream(a_crInstance),
  IFilter(a_crInstance),
  m_IsBigEndian(a_crInstance.m_IsBigEndian)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CFilterUTF16::~CFilterUTF16()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CFilterUTF16& CFilterUTF16::operator = (const CFilterUTF16& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CFilterUTF16::isBigEndian() const
{ CALL
  return m_IsBigEndian;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CFilterUTF16::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CFilterUTF16")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IFilter&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_IsBigEndian, STR("m_IsBigEndian")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CFilterUTF16::swap(CFilterUTF16& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IFilter&)(*this), (IFilter&)a_rInstance);
  NAlgorithms::NCommon::swap(m_IsBigEndian, a_rInstance.m_IsBigEndian);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
