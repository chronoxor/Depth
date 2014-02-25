/*!
 *  \file    CFilterLineEnd.inl Line end filter class helps to handle line end
 *           characters in the stream.
 *  \brief   Line end filter class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Line end filter class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   17.11.2009 02:04:19

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
#ifndef __CFILTERLINEEND_INL__
#define __CFILTERLINEEND_INL__
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
inline CFilterLineEnd::CFilterLineEnd(const Tuint a_cReadInterval/* = 0 */, const Tuint a_cWriteInterval/* = 76 */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadInterval(a_cReadInterval),
  m_WriteInterval(a_cWriteInterval)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterLineEnd::CFilterLineEnd(IReader* a_pReader, const Tuint a_cReadInterval/* = 0 */, const Tuint a_cWriteInterval/* = 76 */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadInterval(a_cReadInterval),
  m_WriteInterval(a_cWriteInterval)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterLineEnd::CFilterLineEnd(IWriter* a_pWriter, const Tuint a_cReadInterval/* = 0 */, const Tuint a_cWriteInterval/* = 76 */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadInterval(a_cReadInterval),
  m_WriteInterval(a_cWriteInterval)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterLineEnd::CFilterLineEnd(IReaderWriter* a_pReaderWriter, const Tuint a_cReadInterval/* = 0 */, const Tuint a_cWriteInterval/* = 76 */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReaderWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadInterval(a_cReadInterval),
  m_WriteInterval(a_cWriteInterval)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterLineEnd::CFilterLineEnd(IReader* a_pReader, IWriter* a_pWriter, const Tuint a_cReadInterval/* = 0 */, const Tuint a_cWriteInterval/* = 76 */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_ReadInterval(a_cReadInterval),
  m_WriteInterval(a_cWriteInterval)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CFilterLineEnd::CFilterLineEnd(const CFilterLineEnd& a_crInstance) :
  IStream(a_crInstance),
  IFilter(a_crInstance),
  m_ReadInterval(a_crInstance.m_ReadInterval),
  m_WriteInterval(a_crInstance.m_WriteInterval)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CFilterLineEnd::~CFilterLineEnd()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CFilterLineEnd& CFilterLineEnd::operator = (const CFilterLineEnd& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tuint CFilterLineEnd::getReadInterval() const
{ CALL
  return m_ReadInterval;
}
/*--------------------------------------------------------------------------*/
inline Tuint CFilterLineEnd::getWriteInterval() const
{ CALL
  return m_WriteInterval;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CFilterLineEnd::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NText::CFilterLineEnd")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IFilter&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_ReadInterval, STR("m_ReadInterval")));
    CHECK(a_rArchive.doValue(m_WriteInterval, STR("m_WriteInterval")));
    CHECK(a_rArchive.doValue(m_CacheReadInterval, STR("m_CacheReadInterval")));
    CHECK(a_rArchive.doValue(m_CacheWriteInterval, STR("m_CacheWriteInterval")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CFilterLineEnd::swap(CFilterLineEnd& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IFilter&)(*this), (IFilter&)a_rInstance);
  NAlgorithms::NCommon::swap(m_ReadInterval, a_rInstance.m_ReadInterval);
  NAlgorithms::NCommon::swap(m_WriteInterval, a_rInstance.m_WriteInterval);
  NAlgorithms::NCommon::swap(m_CacheReadInterval, a_rInstance.m_CacheReadInterval);
  NAlgorithms::NCommon::swap(m_CacheWriteInterval, a_rInstance.m_CacheWriteInterval);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
