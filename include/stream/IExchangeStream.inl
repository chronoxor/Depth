/*!
 *  \file    IExchangeStream.inl Exchange stream is a base interface for all
 *           implementations of interprocess communication stream classes
 *           (files, pipes, sockets, etc.).
 *  \brief   Exchange stream interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Exchange stream interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   24.03.2009 21:59:39

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
#ifndef __IEXCHANGESTREAM_INL__
#define __IEXCHANGESTREAM_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline IExchangeStream::IExchangeStream(const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */, const Tbool a_cIsExchange/* = false */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_IsExchange(a_cIsExchange),
  m_Version(1),
  m_SCharSize(sizeof(Tschar)),
  m_WCharSize(sizeof(Twchar)),
  m_SIntSize(sizeof(Tsint)),
  m_UIntSize(sizeof(Tuint)),
  m_PtrSize(sizeof(Tptr)),
  m_IsRealFloat(CConstants::isRealFloat)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IExchangeStream::IExchangeStream(const IExchangeStream& a_crInstance) :
  IStream(a_crInstance),
  m_IsExchange(a_crInstance.m_IsExchange),
  m_Version(a_crInstance.m_Version),
  m_SCharSize(a_crInstance.m_SCharSize),
  m_WCharSize(a_crInstance.m_WCharSize),
  m_SIntSize(a_crInstance.m_SIntSize),
  m_UIntSize(a_crInstance.m_UIntSize),
  m_PtrSize(a_crInstance.m_PtrSize),
  m_IsRealFloat(a_crInstance.m_IsRealFloat)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IExchangeStream::~IExchangeStream()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IExchangeStream& IExchangeStream::operator = (const IExchangeStream& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool IExchangeStream::isExchange() const
{ CALL
  return m_IsExchange;
}
/*--------------------------------------------------------------------------*/
inline Tuint IExchangeStream::exchangeGetVersion() const
{ CALL
  return m_Version;
}
/*--------------------------------------------------------------------------*/
inline Tbool IExchangeStream::exchangeIsBigEndian() const
{ CALL
  return (IStream::getByteOrder() != IStream::e_BYTE_ORDER_LITTLE_ENDIAN);
}
/*--------------------------------------------------------------------------*/
inline Tbool IExchangeStream::exchangeIsLittleEndian() const
{ CALL
  return (IStream::getByteOrder() == IStream::e_BYTE_ORDER_LITTLE_ENDIAN);
}
/*--------------------------------------------------------------------------*/
inline Tuint IExchangeStream::exchangeGetSCharSize() const
{ CALL
  return m_SCharSize;
}
/*--------------------------------------------------------------------------*/
inline Tuint IExchangeStream::exchangeGetWCharSize() const
{ CALL
  return m_WCharSize;
}
/*--------------------------------------------------------------------------*/
inline Tuint IExchangeStream::exchangeGetSIntSize() const
{ CALL
  return m_SIntSize;
}
/*--------------------------------------------------------------------------*/
inline Tuint IExchangeStream::exchangeGetUIntSize() const
{ CALL
  return m_UIntSize;
}
/*--------------------------------------------------------------------------*/
inline Tuint IExchangeStream::exchangeGetPtrSize() const
{ CALL
  return m_PtrSize;
}
/*--------------------------------------------------------------------------*/
inline Tbool IExchangeStream::exchangeIsRealFloat() const
{ CALL
  return m_IsRealFloat;
}
/*--------------------------------------------------------------------------*/
inline Tbool IExchangeStream::exchangeIsRealDouble() const
{ CALL
  return !m_IsRealFloat;
}
/*--------------------------------------------------------------------------*/
inline Tuint IExchangeStream::internalGetSCharSize() const
{ CALL
  return (m_IsExchange ? m_SCharSize : IStream::internalGetSCharSize());
}
/*--------------------------------------------------------------------------*/
inline Tuint IExchangeStream::internalGetWCharSize() const
{ CALL
  return (m_IsExchange ? m_WCharSize : IStream::internalGetWCharSize());
}
/*--------------------------------------------------------------------------*/
inline Tuint IExchangeStream::internalGetSIntSize() const
{ CALL
  return (m_IsExchange ? m_SIntSize : IStream::internalGetSIntSize());
}
/*--------------------------------------------------------------------------*/
inline Tuint IExchangeStream::internalGetUIntSize() const
{ CALL
  return (m_IsExchange ? m_UIntSize : IStream::internalGetUIntSize());
}
/*--------------------------------------------------------------------------*/
inline Tuint IExchangeStream::internalGetPtrSize() const
{ CALL
  return (m_IsExchange ? m_PtrSize : IStream::internalGetPtrSize());
}
/*--------------------------------------------------------------------------*/
inline Tbool IExchangeStream::internalIsRealFloat() const
{ CALL
  return (m_IsExchange ? m_IsRealFloat : IStream::internalIsRealFloat());
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IExchangeStream::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::IExchangeStream")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IStream&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_IsExchange, STR("m_IsExchange")));
    CHECK(a_rArchive.doValue(m_Version, STR("m_Version")));
    CHECK(a_rArchive.doValue(m_SCharSize, STR("m_SCharSize")));
    CHECK(a_rArchive.doValue(m_WCharSize, STR("m_WCharSize")));
    CHECK(a_rArchive.doValue(m_SIntSize, STR("m_SIntSize")));
    CHECK(a_rArchive.doValue(m_UIntSize, STR("m_UIntSize")));
    CHECK(a_rArchive.doValue(m_PtrSize, STR("m_PtrSize")));
    CHECK(a_rArchive.doValue(m_IsRealFloat, STR("m_IsRealFloat")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void IExchangeStream::swap(IExchangeStream& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IStream&)(*this), (IStream&)a_rInstance);
  NAlgorithms::NCommon::swap(m_IsExchange, a_rInstance.m_IsExchange);
  NAlgorithms::NCommon::swap(m_Version, a_rInstance.m_Version);
  NAlgorithms::NCommon::swap(m_SCharSize, a_rInstance.m_SCharSize);
  NAlgorithms::NCommon::swap(m_WCharSize, a_rInstance.m_WCharSize);
  NAlgorithms::NCommon::swap(m_SIntSize, a_rInstance.m_SIntSize);
  NAlgorithms::NCommon::swap(m_UIntSize, a_rInstance.m_UIntSize);
  NAlgorithms::NCommon::swap(m_PtrSize, a_rInstance.m_PtrSize);
  NAlgorithms::NCommon::swap(m_IsRealFloat, a_rInstance.m_IsRealFloat);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
