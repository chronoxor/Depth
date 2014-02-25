/*!
 *  \file    CFilterFork.inl Fork duplicate filter class simple duplicate
 *           data from another stream/filter and write it into the given
 *           stream.
 *  \brief   Fork duplicate filter class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Fork duplicate filter class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   19.03.2009 21:19:17

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
#ifndef __CFILTERFORK_INL__
#define __CFILTERFORK_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CFilterFork::CFilterFork(IWriter* a_pFork/* = NULL */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_pFork(NULL)
{ CALL
  setFork(a_pFork);
}
/*--------------------------------------------------------------------------*/
inline CFilterFork::CFilterFork(IReader* a_pReader, IWriter* a_pFork/* = NULL */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_pFork(NULL)
{ CALL
  setFork(a_pFork);
}
/*--------------------------------------------------------------------------*/
inline CFilterFork::CFilterFork(IWriter* a_pWriter, IWriter* a_pFork/* = NULL */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_pFork(NULL)
{ CALL
  setFork(a_pFork);
}
/*--------------------------------------------------------------------------*/
inline CFilterFork::CFilterFork(IReaderWriter* a_pReaderWriter, IWriter* a_pFork/* = NULL */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReaderWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_pFork(NULL)
{ CALL
  setFork(a_pFork);
}
/*--------------------------------------------------------------------------*/
inline CFilterFork::CFilterFork(IReader* a_pReader, IWriter* a_pWriter, IWriter* a_pFork/* = NULL */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::e_BYTE_ORDER_UNIVERSAL */, const ELineEnding a_cLineEnding/* = IStream::e_LINE_ENDING_UNIVERSAL */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IFilter(a_pReader, a_pWriter, a_cTextMode, a_cByteOrder, a_cLineEnding),
  m_pFork(NULL)
{ CALL
  setFork(a_pFork);
}
/*--------------------------------------------------------------------------*/
inline CFilterFork::CFilterFork(const CFilterFork& a_crInstance) :
  IStream(a_crInstance),
  IFilter(a_crInstance),
  m_pFork(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CFilterFork::~CFilterFork()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CFilterFork& CFilterFork::operator = (const CFilterFork& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CFilterFork::isForkable() const
{ CALL
  return (m_pFork != NULL);
}
/*--------------------------------------------------------------------------*/
inline Tbool CFilterFork::setFork(IWriter* a_pFork)
{ CALL
  m_pFork = a_pFork;
  return true;
}
/*--------------------------------------------------------------------------*/
inline IWriter* CFilterFork::getFork()
{ CALL
  return m_pFork;
}
/*--------------------------------------------------------------------------*/
inline const IWriter* CFilterFork::getFork() const
{ CALL
  return m_pFork;
}
/*--------------------------------------------------------------------------*/
inline Tuint CFilterFork::onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return a_rReader.readBuffer(a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tuint CFilterFork::onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return a_rReader.readBuffer(a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tuint CFilterFork::onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  return a_rReader.readBuffer(a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tuint CFilterFork::onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return a_rWriter.writeBuffer(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tuint CFilterFork::onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return a_rWriter.writeBuffer(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tuint CFilterFork::onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return a_rWriter.writeBuffer(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CFilterFork::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::CFilterFork")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IFilter&)(*this), STR("base")));
    CHECK(a_rArchive.doPointer(m_pFork, STR("m_pFork")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CFilterFork::swap(CFilterFork& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IFilter&)(*this), (IFilter&)a_rInstance);
  NAlgorithms::NCommon::swap(m_pFork, a_rInstance.m_pFork);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
