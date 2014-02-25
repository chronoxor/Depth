/*!
 *  \file    CFilterUTF.inl UTF string filter class converts given ASCII and
 *           Unicode strings into the UTF equivalents.
 *  \brief   UTF string filter class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.10.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: UTF string filter class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   26.10.2009 23:23:33

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
#ifndef __CFILTERUTF_INL__
#define __CFILTERUTF_INL__
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
inline CFilterUTF::CFilterUTF(const EUTFType a_cUTFType/* = e_AUTODETECT */, const Tbool a_cIsBOMUsed/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_CacheSize(0),
  m_IsBOMUsed(a_cIsBOMUsed),
  m_UTFType(a_cUTFType)
{ CALL
  m_Cache[0] = m_Cache[1] = m_Cache[2] = m_Cache[3] = 0;
}
/*--------------------------------------------------------------------------*/
inline CFilterUTF::CFilterUTF(IReader* a_pReader, const EUTFType a_cUTFType/* = e_AUTODETECT */, const Tbool a_cIsBOMUsed/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_CacheSize(0),
  m_IsBOMUsed(a_cIsBOMUsed),
  m_UTFType(a_cUTFType)
{ CALL
  m_Cache[0] = m_Cache[1] = m_Cache[2] = m_Cache[3] = 0;
}
/*--------------------------------------------------------------------------*/
inline CFilterUTF::CFilterUTF(IWriter* a_pWriter, const EUTFType a_cUTFType/* = e_AUTODETECT */, const Tbool a_cIsBOMUsed/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_CacheSize(0),
  m_IsBOMUsed(a_cIsBOMUsed),
  m_UTFType(a_cUTFType)
{ CALL
  m_Cache[0] = m_Cache[1] = m_Cache[2] = m_Cache[3] = 0;
}
/*--------------------------------------------------------------------------*/
inline CFilterUTF::CFilterUTF(IReaderWriter* a_pReaderWriter, const EUTFType a_cUTFType/* = e_AUTODETECT */, const Tbool a_cIsBOMUsed/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReaderWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_CacheSize(0),
  m_IsBOMUsed(a_cIsBOMUsed),
  m_UTFType(a_cUTFType)
{ CALL
  m_Cache[0] = m_Cache[1] = m_Cache[2] = m_Cache[3] = 0;
}
/*--------------------------------------------------------------------------*/
inline CFilterUTF::CFilterUTF(IReader* a_pReader, IWriter* a_pWriter, const EUTFType a_cUTFType/* = e_AUTODETECT */, const Tbool a_cIsBOMUsed/* = true */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_CacheSize(0),
  m_IsBOMUsed(a_cIsBOMUsed),
  m_UTFType(a_cUTFType)
{ CALL
  m_Cache[0] = m_Cache[1] = m_Cache[2] = m_Cache[3] = 0;
}
/*--------------------------------------------------------------------------*/
inline CFilterUTF::CFilterUTF(const CFilterUTF& a_crInstance) :
  IStream(a_crInstance),
  IFilter(a_crInstance),
  m_CacheSize(0),
  m_IsBOMUsed(true),
  m_UTFType(e_AUTODETECT)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CFilterUTF::~CFilterUTF()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CFilterUTF& CFilterUTF::operator = (const CFilterUTF& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CFilterUTF::EUTFType CFilterUTF::getUTFType() const
{ CALL
  return m_UTFType;
}
/*--------------------------------------------------------------------------*/
inline Tbool CFilterUTF::isBOMUsed() const
{ CALL
  return m_IsBOMUsed;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CFilterUTF::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CFilterUTF")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IFilter&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_Cache, m_CacheSize, STR("m_Cache")));
    CHECK(a_rArchive.doValue(m_CacheSize, STR("m_CacheSize")));
    CHECK(a_rArchive.doValue(m_IsBOMUsed, STR("m_IsBOMUsed")));
    CHECK(a_rArchive.doValue(m_UTFType, STR("m_UTFType")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CFilterUTF::swap(CFilterUTF& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IFilter&)(*this), (IFilter&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Cache, a_rInstance.m_Cache, 4);
  NAlgorithms::NCommon::swap(m_CacheSize, a_rInstance.m_CacheSize);
  NAlgorithms::NCommon::swap(m_IsBOMUsed, a_rInstance.m_IsBOMUsed);
  NAlgorithms::NCommon::swap(m_UTFType, a_rInstance.m_UTFType);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
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
inline Tbool load(T_Archive& a_rArchive, NStream::NText::CFilterUTF::EUTFType& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CFilterUTF::EUTFType")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set UTF type value.
  switch (value)
  {
    case 0:
      a_rInstance = NStream::NText::CFilterUTF::e_AUTODETECT;
      break;
    case 1:
      a_rInstance = NStream::NText::CFilterUTF::e_UTF8;
      break;
    case 2:
      a_rInstance = NStream::NText::CFilterUTF::e_UTF16BE;
      break;
    case 3:
      a_rInstance = NStream::NText::CFilterUTF::e_UTF16LE;
      break;
    case 4:
      a_rInstance = NStream::NText::CFilterUTF::e_UTF32BE;
      break;
    case 5:
      a_rInstance = NStream::NText::CFilterUTF::e_UTF32LE;
      break;
    default:
      WARNING(STR("Cannot load invalid UTF type value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool save(T_Archive& a_rArchive, const NStream::NText::CFilterUTF::EUTFType& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get UTF type value.
  switch (a_crInstance)
  {
    case NStream::NText::CFilterUTF::e_AUTODETECT:
      value = 0;
      break;
    case NStream::NText::CFilterUTF::e_UTF8:
      value = 1;
      break;
    case NStream::NText::CFilterUTF::e_UTF16BE:
      value = 2;
      break;
    case NStream::NText::CFilterUTF::e_UTF16LE:
      value = 3;
      break;
    case NStream::NText::CFilterUTF::e_UTF32BE:
      value = 4;
      break;
    case NStream::NText::CFilterUTF::e_UTF32LE:
      value = 5;
      break;
    default:
      WARNING(STR("Cannot save invalid UTF type value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CFilterUTF::EUTFType")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool serialize(T_Archive& a_rArchive, NStream::NText::CFilterUTF::EUTFType& a_rInstance)
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
