/*!
 *  \file    CStreamStringASCII.inl ASCII string stream class gives ability to
 *           read/write byte sequences from/into the ASCII string.
 *  \brief   ASCII string stream class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: ASCII string stream class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   02.09.2008 02:11:41

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
#ifndef __CSTREAMSTRINGASCII_INL__
#define __CSTREAMSTRINGASCII_INL__
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
inline CStreamStringASCII::CStreamStringASCII(const Tbool a_cTextMode/* = true */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NString::CStringASCII(),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStreamStringASCII::CStreamStringASCII(const Tschar a_cASCIICharacter, const Tbool a_cTextMode/* = true */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NString::CStringASCII(a_cASCIICharacter),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStreamStringASCII::CStreamStringASCII(const Twchar a_cUnicodeCharacter, const Tbool a_cTextMode/* = true */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NString::CStringASCII(a_cUnicodeCharacter),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStreamStringASCII::CStreamStringASCII(Tcsstr a_cpASCIIString, const Tbool a_cTextMode/* = true */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NString::CStringASCII(a_cpASCIIString),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStreamStringASCII::CStreamStringASCII(Tcwstr a_cpUnicodeString, const Tbool a_cTextMode/* = true */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NString::CStringASCII(a_cpUnicodeString),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStreamStringASCII::CStreamStringASCII(Tcsstr a_cpBuffer, const Tuint a_cSize, const Tbool a_cTextMode/* = true */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NString::CStringASCII(a_cpBuffer, a_cSize),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStreamStringASCII::CStreamStringASCII(Tcwstr a_cpBuffer, const Tuint a_cSize, const Tbool a_cTextMode/* = true */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NString::CStringASCII(a_cpBuffer, a_cSize),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStreamStringASCII::CStreamStringASCII(const NString::CSystemString& a_crString, const Tbool a_cTextMode/* = true */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NString::CStringASCII(a_crString),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStreamStringASCII::CStreamStringASCII(const NString::CStringASCII& a_crString, const Tbool a_cTextMode/* = true */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NString::CStringASCII(a_crString),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStreamStringASCII::CStreamStringASCII(const NString::CStringUnicode& a_crString, const Tbool a_cTextMode/* = true */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  NString::CStringASCII(a_crString),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStreamStringASCII::CStreamStringASCII(const CStreamStringASCII& a_crInstance) :
  IStream(a_crInstance),
  IReaderWriter(a_crInstance),
  NCommon::ISeekable(),
  NString::CStringASCII(),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CStreamStringASCII::~CStreamStringASCII()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CStreamStringASCII& CStreamStringASCII::operator = (const CStreamStringASCII& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tuint CStreamStringASCII::getSize() const
{ CALL
  return CStringASCII::getSize();
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamStringASCII::onOpen(const EOpenType a_cOpenType)
{ CALL
  IGNORE_UNUSED(a_cOpenType);

  m_Index = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamStringASCII::onFlush()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamStringASCII::onClose()
{ CALL
  m_Index = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStreamStringASCII::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Close opened ASCII string stream.
  if (isOpened())
    CHECK(close());

  // Clear the current ASCII string stream.
  CHECK(clear());

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CStreamStringASCII")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CStringASCII&)(*this), STR("base")));
    CHECK(a_rArchive.doValue((IReaderWriter&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStreamStringASCII::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CStreamStringASCII")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CStringASCII&)(*this), STR("base")));
    CHECK(a_rArchive.doValue((IReaderWriter&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStreamStringASCII::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void CStreamStringASCII::swap(CStreamStringASCII& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CStringASCII&)(*this), (CStringASCII&)a_rInstance);
  NAlgorithms::NCommon::swap((IReaderWriter&)(*this), (IReaderWriter&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Index, a_rInstance.m_Index);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
