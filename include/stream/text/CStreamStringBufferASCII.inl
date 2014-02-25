/*!
 *  \file    CStreamStringBufferASCII.inl ASCII string buffer stream class
 *           gives ability to read/write byte sequences from/into the fixed
 *           ASCII string buffer.
 *  \brief   ASCII string buffer stream class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: ASCII string buffer stream class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   26.09.2008 22:11:22

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
#ifndef __CSTREAMSTRINGBUFFERASCII_INL__
#define __CSTREAMSTRINGBUFFERASCII_INL__
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
inline CStreamStringBufferASCII::CStreamStringBufferASCII(const Tbool a_cTextMode/* = true */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  m_pBuffer(NULL),
  m_Size(0),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStreamStringBufferASCII::CStreamStringBufferASCII(Tsstr a_pASCIIString, const Tbool a_cTextMode/* = true */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  m_pBuffer(NULL),
  m_Size(0),
  m_Index(0)
{ CALL
  set(a_pASCIIString);
}
/*--------------------------------------------------------------------------*/
inline CStreamStringBufferASCII::CStreamStringBufferASCII(Tsstr a_pBuffer, const Tuint a_cSize, const Tbool a_cTextMode/* = true */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  NCommon::ISeekable(),
  m_pBuffer(NULL),
  m_Size(0),
  m_Index(0)
{ CALL
  set(a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline CStreamStringBufferASCII::CStreamStringBufferASCII(const CStreamStringBufferASCII& a_crInstance) :
  IStream(a_crInstance),
  IReaderWriter(a_crInstance),
  NCommon::ISeekable(),
  m_pBuffer(NULL),
  m_Size(0),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CStreamStringBufferASCII::~CStreamStringBufferASCII()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CStreamStringBufferASCII& CStreamStringBufferASCII::operator = (Tsstr a_pASCIIString)
{ CALL
  set(a_pASCIIString);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStreamStringBufferASCII& CStreamStringBufferASCII::operator = (const CStreamStringBufferASCII& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tuint CStreamStringBufferASCII::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamStringBufferASCII::onOpen(const EOpenType a_cOpenType)
{ CALL
  IGNORE_UNUSED(a_cOpenType);

  m_Index = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamStringBufferASCII::onFlush()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamStringBufferASCII::onClose()
{ CALL
  m_Index = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStreamStringBufferASCII::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Close opened ASCII string stream.
  if (isOpened())
    CHECK(close());

  Tuint size = 0;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CStreamStringBufferASCII")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

    CHECK(a_rArchive.doValue((IReaderWriter&)(*this), STR("base")));

    if (size > 0)
    {
      // Allocate memory for the ASCII string buffer.
      Tsstr new_buffer = newex Tschar[size];
      if (new_buffer == NULL)
      {
        WARNING(STR("Cannot allocate ASCII string buffer (requested size is %u bytes).") COMMA (size * sizeof(Tschar)));
        return false;
      }

      // Load ASCII string buffer content.
      if (!a_rArchive.doValue(new_buffer, size, STR("m_pBuffer")))
      {
        delete [] new_buffer;
        return false;
      }

      // Update ASCII string buffer stream.
      m_pBuffer = new_buffer;
      m_Size = size;
    }

  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStreamStringBufferASCII::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CStreamStringBufferASCII")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
  CHECK(a_rArchive.body());

    CHECK(a_rArchive.doValue((IReaderWriter&)(*this), STR("base")));

    if (m_Size > 0)
    {
      CHECK(a_rArchive.doValue(m_pBuffer, m_Size, STR("m_pBuffer")));
    }

  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStreamStringBufferASCII::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void CStreamStringBufferASCII::swap(CStreamStringBufferASCII& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IReaderWriter&)(*this), (IReaderWriter&)a_rInstance);
  NAlgorithms::NCommon::swap(m_pBuffer, a_rInstance.m_pBuffer);
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
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
