/*!
 *  \file    CFilterBase85.inl Base85 string filter class converts given ASCII
 *           and Unicode strings into the corresponding hexadecimal
 *           representation.
 *  \brief   Base85 string filter class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base85 string filter class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   16.11.2009 20:42:08

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
#ifndef __CFILTERBASE85_INL__
#define __CFILTERBASE85_INL__
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
inline CFilterBase85::CFilterBase85(const Tbool a_cIsWriteSuffixes/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<4>(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsWriteSuffixes(a_cIsWriteSuffixes)
{ CALL
  CFilterBase85::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterBase85::CFilterBase85(IReader* a_pReader, const Tbool a_cIsWriteSuffixes/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<4>(a_pReader, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsWriteSuffixes(a_cIsWriteSuffixes)
{ CALL
  CFilterBase85::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterBase85::CFilterBase85(IWriter* a_pWriter, const Tbool a_cIsWriteSuffixes/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<4>(a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsWriteSuffixes(a_cIsWriteSuffixes)
{ CALL
  CFilterBase85::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterBase85::CFilterBase85(IReaderWriter* a_pReaderWriter, const Tbool a_cIsWriteSuffixes/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<4>(a_pReaderWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsWriteSuffixes(a_cIsWriteSuffixes)
{ CALL
  CFilterBase85::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterBase85::CFilterBase85(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cIsWriteSuffixes/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<4>(a_pReader, a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsWriteSuffixes(a_cIsWriteSuffixes)
{ CALL
  CFilterBase85::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterBase85::CFilterBase85(const CFilterBase85& a_crInstance) :
  IStream(a_crInstance),
  NPack::IFilterFramePack<4>(a_crInstance),
  m_IsWriteSuffixes(a_crInstance.m_IsWriteSuffixes)
{ CALL
  CFilterBase85::calculateTables();
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CFilterBase85::~CFilterBase85()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CFilterBase85& CFilterBase85::operator = (const CFilterBase85& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CFilterBase85::isWriteSuffixes() const
{ CALL
  return m_IsWriteSuffixes;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CFilterBase85::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CFilterBase85")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((NPack::IFilterFramePack<4>&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_IsWriteSuffixes, STR("m_IsWriteSuffixes")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CFilterBase85::swap(CFilterBase85& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((NPack::IFilterFramePack<4>&)(*this), (NPack::IFilterFramePack<4>&)a_rInstance);
  NAlgorithms::NCommon::swap(m_IsWriteSuffixes, a_rInstance.m_IsWriteSuffixes);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
