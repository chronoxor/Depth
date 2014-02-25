/*!
 *  \file    CFilterXXE.inl XXE string filter class converts given ASCII
 *           and Unicode strings into the corresponding XXE-encoded
 *           representation.
 *  \brief   XXE string filter class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: XXE string filter class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   11.11.2009 21:42:45

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
#ifndef __CFILTERXXE_INL__
#define __CFILTERXXE_INL__
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
inline CFilterXXE::CFilterXXE(const Tbool a_cIsWriteLineEnding/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<45>(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsWriteLineEnding(a_cIsWriteLineEnding)
{ CALL
  CFilterXXE::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterXXE::CFilterXXE(IReader* a_pReader, const Tbool a_cIsWriteLineEnding/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<45>(a_pReader, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsWriteLineEnding(a_cIsWriteLineEnding)
{ CALL
  CFilterXXE::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterXXE::CFilterXXE(IWriter* a_pWriter, const Tbool a_cIsWriteLineEnding/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<45>(a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsWriteLineEnding(a_cIsWriteLineEnding)
{ CALL
  CFilterXXE::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterXXE::CFilterXXE(IReaderWriter* a_pReaderWriter, const Tbool a_cIsWriteLineEnding/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<45>(a_pReaderWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsWriteLineEnding(a_cIsWriteLineEnding)
{ CALL
  CFilterXXE::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterXXE::CFilterXXE(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cIsWriteLineEnding/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NPack::IFilterFramePack<45>(a_pReader, a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsWriteLineEnding(a_cIsWriteLineEnding)
{ CALL
  CFilterXXE::calculateTables();
}
/*--------------------------------------------------------------------------*/
inline CFilterXXE::CFilterXXE(const CFilterXXE& a_crInstance) :
  IStream(a_crInstance),
  NPack::IFilterFramePack<45>(a_crInstance),
  m_IsWriteLineEnding(a_crInstance.m_IsWriteLineEnding)
{ CALL
  CFilterXXE::calculateTables();
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CFilterXXE::~CFilterXXE()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CFilterXXE& CFilterXXE::operator = (const CFilterXXE& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CFilterXXE::isWriteLineEnding() const
{ CALL
  return m_IsWriteLineEnding;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CFilterXXE::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CFilterXXE")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((NPack::IFilterFramePack<45>&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_IsWriteLineEnding, STR("m_IsWriteLineEnding")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CFilterXXE::swap(CFilterXXE& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((NPack::IFilterFramePack<45>&)(*this), (NPack::IFilterFramePack<45>&)a_rInstance);
  NAlgorithms::NCommon::swap(m_IsWriteLineEnding, a_rInstance.m_IsWriteLineEnding);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
