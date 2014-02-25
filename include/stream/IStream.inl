/*!
 *  \file    IStream.inl Stream is a base interface for all implementations of
 *           stream classes (readers, writers).
 *  \brief   Stream interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Stream interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   12.08.2008 23:53:13

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
#ifndef __ISTREAM_INL__
#define __ISTREAM_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline IStream::IStream(const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = e_LINE_ENDING_UNIVERSAL */) :
  m_IsAutoFlush(false),
  m_IsTextMode(a_cTextMode),
  m_ByteOrder(a_cByteOrder),
  m_LineEnding(a_cLineEnding)
{ CALL
  setDefaultFormat();
  setDefaultParse();
}
/*--------------------------------------------------------------------------*/
inline IStream::IStream(const IStream& a_crInstance) :
  m_IsAutoFlush(false),
  m_IsTextMode(a_crInstance.m_IsTextMode),
  m_ByteOrder(a_crInstance.m_ByteOrder),
  m_LineEnding(a_crInstance.m_LineEnding),
  m_FormatFlags(a_crInstance.m_FormatFlags),
  m_ParseFlags(a_crInstance.m_ParseFlags),
  m_Precision(a_crInstance.m_Precision),
  m_Width(a_crInstance.m_Width),
  m_Radix(a_crInstance.m_Radix)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IStream::~IStream()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IStream& IStream::operator = (const IStream& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void IStream::set(const IStream& a_crInstance)
{ CALL
  m_IsAutoFlush = a_crInstance.m_IsAutoFlush;
  m_IsTextMode = a_crInstance.m_IsTextMode;
  m_ByteOrder = a_crInstance.m_ByteOrder;
  m_LineEnding = a_crInstance.m_LineEnding;
  m_FormatFlags = a_crInstance.m_FormatFlags;
  m_ParseFlags = a_crInstance.m_ParseFlags;
  m_Precision = a_crInstance.m_Precision;
  m_Width = a_crInstance.m_Width;
  m_Radix = a_crInstance.m_Radix;
}
/*--------------------------------------------------------------------------*/
inline Tbool IStream::isAutoFlush() const
{ CALL
  return m_IsAutoFlush;
}
/*--------------------------------------------------------------------------*/
inline void IStream::setAutoFlush(const Tbool a_cAutoFlush)
{ CALL
  m_IsAutoFlush = a_cAutoFlush;
}
/*--------------------------------------------------------------------------*/
inline Tbool IStream::isBinaryMode() const
{ CALL
  return !m_IsTextMode;
}
/*--------------------------------------------------------------------------*/
inline Tbool IStream::isTextMode() const
{ CALL
  return m_IsTextMode;
}
/*--------------------------------------------------------------------------*/
inline void IStream::setBinaryMode()
{ CALL
  m_IsTextMode = false;
}
/*--------------------------------------------------------------------------*/
inline void IStream::setTextMode()
{ CALL
  m_IsTextMode = true;
}
/*--------------------------------------------------------------------------*/
inline void IStream::setByteOrder(const EByteOrder a_cByteOrder)
{ CALL
  m_ByteOrder = a_cByteOrder;
}
/*--------------------------------------------------------------------------*/
inline IStream::EByteOrder IStream::getByteOrder() const
{ CALL
  return m_ByteOrder;
}
/*--------------------------------------------------------------------------*/
inline void IStream::setLineEnding(const ELineEnding a_cLineEnding)
{ CALL
  m_LineEnding = a_cLineEnding;
}
/*--------------------------------------------------------------------------*/
inline IStream::ELineEnding IStream::getLineEnding() const
{ CALL
  return m_LineEnding;
}
/*--------------------------------------------------------------------------*/
inline void IStream::setCurrentFormatFlags(const Tuint a_cFormatFlags)
{ CALL
  m_FormatFlags = a_cFormatFlags;
}
/*--------------------------------------------------------------------------*/
inline Tuint IStream::getCurrentFormatFlags() const
{ CALL
  return m_FormatFlags;
}
/*--------------------------------------------------------------------------*/
inline void IStream::setCurrentParseFlags(const Tuint a_cParseFlags)
{ CALL
  m_ParseFlags = a_cParseFlags;
}
/*--------------------------------------------------------------------------*/
inline Tuint IStream::getCurrentParseFlags() const
{ CALL
  return m_ParseFlags;
}
/*--------------------------------------------------------------------------*/
inline void IStream::setCurrentPrecision(const Tuint a_cPrecision)
{ CALL
  m_Precision = a_cPrecision;
}
/*--------------------------------------------------------------------------*/
inline Tuint IStream::getCurrentPrecision() const
{ CALL
  return m_Precision;
}
/*--------------------------------------------------------------------------*/
inline void IStream::setCurrentWidth(const Tuint a_cWidth)
{ CALL
  m_Width = a_cWidth;
}
/*--------------------------------------------------------------------------*/
inline Tuint IStream::getCurrentWidth() const
{ CALL
  return m_Width;
}
/*--------------------------------------------------------------------------*/
inline void IStream::setCurrentRadix(const Tuint a_cRadix)
{ CALL
  m_Radix = a_cRadix;
}
/*--------------------------------------------------------------------------*/
inline Tuint IStream::getCurrentRadix() const
{ CALL
  return m_Radix;
}
/*--------------------------------------------------------------------------*/
inline void IStream::setDefaultFormat()
{ CALL
  m_FormatFlags = FORMAT_DEFAULT;
  m_Precision = 6;
  m_Width = 0;
  m_Radix = 0;
}
/*--------------------------------------------------------------------------*/
inline void IStream::setDefaultParse()
{ CALL
  m_ParseFlags = PARSE_DEFAULT;
}
/*--------------------------------------------------------------------------*/
inline Tuint IStream::internalGetSCharSize() const
{ CALL
  return sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
inline Tuint IStream::internalGetWCharSize() const
{ CALL
  return sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
inline Tuint IStream::internalGetSIntSize() const
{ CALL
  return sizeof(Tsint);
}
/*--------------------------------------------------------------------------*/
inline Tuint IStream::internalGetUIntSize() const
{ CALL
  return sizeof(Tuint);
}
/*--------------------------------------------------------------------------*/
inline Tuint IStream::internalGetPtrSize() const
{ CALL
  return sizeof(Tptr);
}
/*--------------------------------------------------------------------------*/
inline Tbool IStream::internalIsRealFloat() const
{ CALL
  return CConstants::isRealFloat;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IStream::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IStream")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_IsAutoFlush, STR("m_IsAutoFlush")));
    CHECK(a_rArchive.doValue(m_IsTextMode, STR("m_IsTextMode")));
    CHECK(a_rArchive.doValue(m_ByteOrder, STR("m_ByteOrder")));
    CHECK(a_rArchive.doValue(m_LineEnding, STR("m_LineEnding")));
    CHECK(a_rArchive.doValue(m_FormatFlags, STR("m_FormatFlags")));
    CHECK(a_rArchive.doValue(m_ParseFlags, STR("m_ParseFlags")));
    CHECK(a_rArchive.doValue(m_Precision, STR("m_Precision")));
    CHECK(a_rArchive.doValue(m_Width, STR("m_Width")));
    CHECK(a_rArchive.doValue(m_Radix, STR("m_Radix")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void IStream::swap(IStream& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_IsAutoFlush, a_rInstance.m_IsAutoFlush);
  NAlgorithms::NCommon::swap(m_IsTextMode, a_rInstance.m_IsTextMode);
  NAlgorithms::NCommon::swap(m_ByteOrder, a_rInstance.m_ByteOrder);
  NAlgorithms::NCommon::swap(m_LineEnding, a_rInstance.m_LineEnding);
  NAlgorithms::NCommon::swap(m_FormatFlags, a_rInstance.m_FormatFlags);
  NAlgorithms::NCommon::swap(m_ParseFlags, a_rInstance.m_ParseFlags);
  NAlgorithms::NCommon::swap(m_Precision, a_rInstance.m_Precision);
  NAlgorithms::NCommon::swap(m_Width, a_rInstance.m_Width);
  NAlgorithms::NCommon::swap(m_Radix, a_rInstance.m_Radix);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NStream::IStream::EByteOrder& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IStream::EByteOrder")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set stream byte order value.
  switch (value)
  {
    case 0:
      a_rInstance = NStream::IStream::e_BYTE_ORDER_UNIVERSAL;
      break;
    case 1:
      a_rInstance = NStream::IStream::e_BYTE_ORDER_BIG_ENDIAN;
      break;
    case 2:
      a_rInstance = NStream::IStream::e_BYTE_ORDER_LITTLE_ENDIAN;
      break;
    default:
      WARNING(STR("Cannot load invalid stream byte order value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NStream::IStream::EByteOrder& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get stream byte order value.
  switch (a_crInstance)
  {
    case NStream::IStream::e_BYTE_ORDER_UNIVERSAL:
      value = 0;
      break;
    case NStream::IStream::e_BYTE_ORDER_BIG_ENDIAN:
      value = 1;
      break;
    case NStream::IStream::e_BYTE_ORDER_LITTLE_ENDIAN:
      value = 2;
      break;
    default:
      WARNING(STR("Cannot save invalid stream byte order value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IStream::EByteOrder")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NStream::IStream::EByteOrder& a_rInstance)
{ CALL
  // Split 'serialize()' free function into 'load()' and 'save()' ones.
  return serializeSplitFunction(a_rArchive, a_rInstance);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NStream::IStream::ELineEnding& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IStream::ELineEnding")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set stream line ending value.
  switch (value)
  {
    case 0:
      a_rInstance = NStream::IStream::e_LINE_ENDING_UNIVERSAL;
      break;
    case 1:
      a_rInstance = NStream::IStream::e_LINE_ENDING_UNIX;
      break;
    case 2:
      a_rInstance = NStream::IStream::e_LINE_ENDING_WINDOWS;
      break;
    default:
      WARNING(STR("Cannot load invalid stream line ending value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NStream::IStream::ELineEnding& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get stream line ending value.
  switch (a_crInstance)
  {
    case NStream::IStream::e_LINE_ENDING_UNIVERSAL:
      value = 0;
      break;
    case NStream::IStream::e_LINE_ENDING_UNIX:
      value = 1;
      break;
    case NStream::IStream::e_LINE_ENDING_WINDOWS:
      value = 2;
      break;
    default:
      WARNING(STR("Cannot save invalid stream line ending value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IStream::ELineEnding")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NStream::IStream::ELineEnding& a_rInstance)
{ CALL
  // Split 'serialize()' free function into 'load()' and 'save()' ones.
  return serializeSplitFunction(a_rArchive, a_rInstance);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NStream::IStream::EOpenType& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IStream::EOpenType")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set stream open type value.
  switch (value)
  {
    case 0:
      a_rInstance = NStream::IStream::e_OPEN_READ;
      break;
    case 1:
      a_rInstance = NStream::IStream::e_OPEN_WRITE;
      break;
    case 2:
      a_rInstance = NStream::IStream::e_OPEN_READWRITE;
      break;
    default:
      WARNING(STR("Cannot load invalid stream open type value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NStream::IStream::EOpenType& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get stream open type value.
  switch (a_crInstance)
  {
    case NStream::IStream::e_OPEN_READ:
      value = 0;
      break;
    case NStream::IStream::e_OPEN_WRITE:
      value = 1;
      break;
    case NStream::IStream::e_OPEN_READWRITE:
      value = 2;
      break;
    default:
      WARNING(STR("Cannot save invalid stream open type value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IStream::EOpenType")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NStream::IStream::EOpenType& a_rInstance)
{ CALL
  // Split 'serialize()' free function into 'load()' and 'save()' ones.
  return serializeSplitFunction(a_rArchive, a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
