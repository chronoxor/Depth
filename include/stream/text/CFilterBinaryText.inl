/*!
 *  \file    CFilterBinaryText.inl Binary/Text filter class converts ASCII
 *           and Unicode strings into binary byte stream and vice-versa.
 *  \brief   Binary/Text converter filter class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Binary/Text converter filter class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   03.11.2009 21:16:04

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
#ifndef __CFILTERBINARYTEXT_INL__
#define __CFILTERBINARYTEXT_INL__
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
inline CFilterBinaryText::CFilterBinaryText(const Tbool a_cIsReadASCII/* = NConstants::CConstants::isASCII */, const Tbool a_cIsWriteASCII/* = NConstants::CConstants::isASCII */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsReadASCII(a_cIsReadASCII),
  m_IsWriteASCII(a_cIsWriteASCII)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterBinaryText::CFilterBinaryText(IReader* a_pReader, const Tbool a_cIsReadASCII/* = NConstants::CConstants::isASCII */, const Tbool a_cIsWriteASCII/* = NConstants::CConstants::isASCII */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsReadASCII(a_cIsReadASCII),
  m_IsWriteASCII(a_cIsWriteASCII)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterBinaryText::CFilterBinaryText(IWriter* a_pWriter, const Tbool a_cIsReadASCII/* = NConstants::CConstants::isASCII */, const Tbool a_cIsWriteASCII/* = NConstants::CConstants::isASCII */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsReadASCII(a_cIsReadASCII),
  m_IsWriteASCII(a_cIsWriteASCII)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterBinaryText::CFilterBinaryText(IReaderWriter* a_pReaderWriter, const Tbool a_cIsReadASCII/* = NConstants::CConstants::isASCII */, const Tbool a_cIsWriteASCII/* = NConstants::CConstants::isASCII */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReaderWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsReadASCII(a_cIsReadASCII),
  m_IsWriteASCII(a_cIsWriteASCII)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterBinaryText::CFilterBinaryText(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cIsReadASCII/* = NConstants::CConstants::isASCII */, const Tbool a_cIsWriteASCII/* = NConstants::CConstants::isASCII */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsReadASCII(a_cIsReadASCII),
  m_IsWriteASCII(a_cIsWriteASCII)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterBinaryText::CFilterBinaryText(const CFilterBinaryText& a_crInstance) :
  IStream(a_crInstance),
  IFilter(a_crInstance),
  m_IsReadASCII(a_crInstance.m_IsReadASCII),
  m_IsWriteASCII(a_crInstance.m_IsWriteASCII)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CFilterBinaryText::~CFilterBinaryText()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CFilterBinaryText& CFilterBinaryText::operator = (const CFilterBinaryText& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CFilterBinaryText::isReadASCII() const
{ CALL
  return m_IsReadASCII;
}
/*--------------------------------------------------------------------------*/
inline Tbool CFilterBinaryText::isReadUnicode() const
{ CALL
  return !m_IsReadASCII;
}
/*--------------------------------------------------------------------------*/
inline Tbool CFilterBinaryText::isWriteASCII() const
{ CALL
  return m_IsWriteASCII;
}
/*--------------------------------------------------------------------------*/
inline Tbool CFilterBinaryText::isWriteUnicode() const
{ CALL
  return !m_IsWriteASCII;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CFilterBinaryText::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CFilterBinaryText")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IFilter&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_IsReadASCII, STR("m_IsReadASCII")));
    CHECK(a_rArchive.doValue(m_IsWriteASCII, STR("m_IsWriteASCII")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CFilterBinaryText::swap(CFilterBinaryText& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IFilter&)(*this), (IFilter&)a_rInstance);
  NAlgorithms::NCommon::swap(m_IsReadASCII, a_rInstance.m_IsReadASCII);
  NAlgorithms::NCommon::swap(m_IsWriteASCII, a_rInstance.m_IsWriteASCII);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
