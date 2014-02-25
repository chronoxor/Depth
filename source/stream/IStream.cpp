/*!
 *  \file    IStream.cpp Stream is a base interface for all implementations of
 *           stream classes (readers, writers).
 *  \brief   Stream interface (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Stream interface (source).

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/stream/IStream.hpp>
#include <Depth/include/string/CCharacter.hpp>
#include <Depth/include/utility/CEndians.hpp>
/*==========================================================================*/
#ifndef __ISTREAM_CPP__
#define __ISTREAM_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INTERFACE IMPLEMENTATIONS                                                */
/*==========================================================================*/
const Tuint IStream::FORMAT_DEFAULT = IStream::FORMAT_DECIMAL | IStream::FORMAT_LOWER | IStream::FORMAT_RALIGN | IStream::FORMAT_DOT | (NString::CCharacter::isSystemASCII() ? IStream::FORMAT_ASCII : IStream::FORMAT_UNICODE);
const Tuint IStream::FORMAT_PLUS    = 0x00000001;
const Tuint IStream::FORMAT_SPACE   = 0x00000002;
const Tuint IStream::FORMAT_binary  = 0x00000004;
const Tuint IStream::FORMAT_BINARY  = 0x00000008;
const Tuint IStream::FORMAT_octal   = 0x00000010;
const Tuint IStream::FORMAT_OCTAL   = 0x00000020;
const Tuint IStream::FORMAT_DECIMAL = 0x00000040;
const Tuint IStream::FORMAT_hex     = 0x00000080;
const Tuint IStream::FORMAT_HEX     = 0x00000100;
const Tuint IStream::FORMAT_LOWER   = 0x00000200;
const Tuint IStream::FORMAT_UPPER   = 0x00000400;
const Tuint IStream::FORMAT_LALIGN  = 0x00000800;
const Tuint IStream::FORMAT_RALIGN  = 0x00001000;
const Tuint IStream::FORMAT_FILL_0  = 0x00002000;
const Tuint IStream::FORMAT_GROUPS  = 0x00004000;
const Tuint IStream::FORMAT_DOT     = 0x00008000;
const Tuint IStream::FORMAT_exp     = 0x00010000;
const Tuint IStream::FORMAT_EXP     = 0x00020000;
const Tuint IStream::FORMAT_ASCII   = 0x00040000;
const Tuint IStream::FORMAT_UNICODE = 0x00080000;
const Tuint IStream::PARSE_DEFAULT  = (NString::CCharacter::isSystemASCII() ? IStream::PARSE_ASCII : IStream::PARSE_UNICODE);
const Tuint IStream::PARSE_ASCII    = 0x01000000;
const Tuint IStream::PARSE_UNICODE  = 0x02000000;
/*--------------------------------------------------------------------------*/
Tcstr IStream::getLineEndingString() const
{ CALL
  return (getLineEnding() == e_LINE_ENDING_WINDOWS) ? STR("\r\n") : STR("\n");
}
/*--------------------------------------------------------------------------*/
Tcsstr IStream::getLineEndingStringASCII() const
{ CALL
  return (getLineEnding() == e_LINE_ENDING_WINDOWS) ? ASC("\r\n") : ASC("\n");
}
/*--------------------------------------------------------------------------*/
Tcwstr IStream::getLineEndingStringUnicode() const
{ CALL
  return (getLineEnding() == e_LINE_ENDING_WINDOWS) ? UNC("\r\n") : UNC("\n");
}
/*--------------------------------------------------------------------------*/
Tuint IStream::getLineEndingStringSize() const
{ CALL
  return (getLineEnding() == e_LINE_ENDING_WINDOWS) ? 2 : 1;
}
/*--------------------------------------------------------------------------*/
IStream::EByteOrder IStream::getSystemByteOrder()
{ CALL
  return (NUtility::CEndians::isBigEndian() ? e_BYTE_ORDER_BIG_ENDIAN : e_BYTE_ORDER_LITTLE_ENDIAN);
}
/*--------------------------------------------------------------------------*/
IStream::ELineEnding IStream::getSystemLineEnding()
{ CALL
  #if (defined(__WINDOWS__) && !defined(__WINDOWS_MOBILE__))
  return e_LINE_ENDING_WINDOWS;
  #else
  return e_LINE_ENDING_UNIX;
  #endif
}
/*--------------------------------------------------------------------------*/
Tcstr IStream::getSystemLineEndingString()
{ CALL
  return (getSystemLineEnding() == e_LINE_ENDING_WINDOWS) ? STR("\r\n") : STR("\n");
}
/*--------------------------------------------------------------------------*/
Tcsstr IStream::getSystemLineEndingStringASCII()
{ CALL
  return (getSystemLineEnding() == e_LINE_ENDING_WINDOWS) ? ASC("\r\n") : ASC("\n");
}
/*--------------------------------------------------------------------------*/
Tcwstr IStream::getSystemLineEndingStringUnicode()
{ CALL
  return (getSystemLineEnding() == e_LINE_ENDING_WINDOWS) ? UNC("\r\n") : UNC("\n");
}
/*--------------------------------------------------------------------------*/
Tuint IStream::getSystemLineEndingStringSize()
{ CALL
  return (getSystemLineEnding() == e_LINE_ENDING_WINDOWS) ? 2 : 1;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
