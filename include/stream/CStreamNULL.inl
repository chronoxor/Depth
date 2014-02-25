/*!
 *  \file    CStreamNULL.inl NULL stream class gives ability to read zero
 *           buffer of any size and to write buffer to the nowhere.
 *  \brief   NULL stream class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: NULL stream class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   16.08.2008 00:50:42

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
#ifndef __CSTREAMNULL_INL__
#define __CSTREAMNULL_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CStreamNULL::CStreamNULL(const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReaderWriter(a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStreamNULL::CStreamNULL(const CStreamNULL& a_crInstance) :
  IStream(a_crInstance),
  IReaderWriter(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CStreamNULL::~CStreamNULL()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CStreamNULL& CStreamNULL::operator = (const CStreamNULL& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamNULL::onOpen(const EOpenType a_cOpenType)
{ CALL
  IGNORE_UNUSED(a_cOpenType);

  return true;
}
/*--------------------------------------------------------------------------*/
inline Tuint CStreamNULL::onReadText(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onReadBinary(a_pBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
inline Tuint CStreamNULL::onReadText(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return onReadBinary(a_pBuffer, a_cSize * sizeof(Twchar)) / sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
inline Tuint CStreamNULL::onWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_cpBuffer);

  return a_cSize;
}
/*--------------------------------------------------------------------------*/
inline Tuint CStreamNULL::onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return onWriteBinary(a_cpBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
inline Tuint CStreamNULL::onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return onWriteBinary(a_cpBuffer, a_cSize * sizeof(Twchar)) / sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamNULL::onFlush()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamNULL::onClose()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStreamNULL::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::CStreamNULL")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IReaderWriter&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CStreamNULL::swap(CStreamNULL& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IReaderWriter&)(*this), (IReaderWriter&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
