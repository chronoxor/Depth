/*!
 *  \file    CStreamStdInput.inl Standard input stream class gives ability to
 *           read buffer from the 'stdin' system stream.
 *  \brief   Standard input stream class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Standard input stream class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   25.08.2008 21:23:11

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
#ifndef __CSTREAMSTDINPUT_INL__
#define __CSTREAMSTDINPUT_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CStreamStdInput::CStreamStdInput(const Tbool a_cForceOpen/* = false */, const Tbool a_cTextMode/* = false */, const EByteOrder a_cByteOrder/* = IStream::getSystemByteOrder() */, const ELineEnding a_cLineEnding/* = IStream::getSystemLineEnding() */) :
  IStream(a_cTextMode, a_cByteOrder, a_cLineEnding),
  IReader(a_cTextMode, a_cByteOrder, a_cLineEnding)
{ CALL
  // Force open stream if need.
  if (a_cForceOpen)
    open();
}
/*--------------------------------------------------------------------------*/
inline CStreamStdInput::CStreamStdInput(const CStreamStdInput& a_crInstance) :
  IStream(a_crInstance),
  IReader(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CStreamStdInput::~CStreamStdInput()
{ CALL
  // Close opened stream.
  if (isOpened())
    close();
}
/*--------------------------------------------------------------------------*/
inline CStreamStdInput& CStreamStdInput::operator = (const CStreamStdInput& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamStdInput::onOpen()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStreamStdInput::onClose()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStreamStdInput::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::CStreamStdInput")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IReader&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CStreamStdInput::swap(CStreamStdInput& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IReader&)(*this), (IReader&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
