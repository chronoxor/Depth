/*!
 *  \file    OStreamRead.inl Set of the stream read operators are used to
 *           read common values (character, string, boolean, integer, real,
 *           pointer) from the stream.
 *  \brief   Stream read operators (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Stream read operators (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   30.09.2008 01:16:36

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
#ifndef __OSTREAMREAD_INL__
#define __OSTREAMREAD_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NOperators {
/*==========================================================================*/
/* INLINE OPERATOR IMPLEMENTATIONS                                          */
/*==========================================================================*/
inline IReader& operator >> (IReader& a_rReader, Tschar& a_rCharacter)
{ CALL
  a_rReader.read(a_rCharacter);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Twchar& a_rCharacter)
{ CALL
  a_rReader.read(a_rCharacter);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Tsstr& a_rpString)
{ CALL
  a_rReader.read(a_rpString);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Twstr& a_rpString)
{ CALL
  a_rReader.read(a_rpString);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, NString::CStringASCII& a_rString)
{ CALL
  a_rReader.read(a_rString);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, NString::CStringUnicode& a_rString)
{ CALL
  a_rReader.read(a_rString);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, NString::CSystemString& a_rString)
{ CALL
  a_rReader.read(a_rString);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Tbool& a_rBoolean)
{ CALL
  a_rReader.read(a_rBoolean, a_rReader.getCurrentParseFlags());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Tsint08& a_rInteger)
{ CALL
  a_rReader.read(a_rInteger, a_rReader.getCurrentParseFlags());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Tuint08& a_rInteger)
{ CALL
  a_rReader.read(a_rInteger, a_rReader.getCurrentParseFlags());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Tsint16& a_rInteger)
{ CALL
  a_rReader.read(a_rInteger, a_rReader.getCurrentParseFlags());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Tuint16& a_rInteger)
{ CALL
  a_rReader.read(a_rInteger, a_rReader.getCurrentParseFlags());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Tsint32& a_rInteger)
{ CALL
  a_rReader.read(a_rInteger, a_rReader.getCurrentParseFlags());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Tuint32& a_rInteger)
{ CALL
  a_rReader.read(a_rInteger, a_rReader.getCurrentParseFlags());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Tsint64& a_rInteger)
{ CALL
  a_rReader.read(a_rInteger, a_rReader.getCurrentParseFlags());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Tuint64& a_rInteger)
{ CALL
  a_rReader.read(a_rInteger, a_rReader.getCurrentParseFlags());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Tfloat& a_rReal)
{ CALL
  a_rReader.read(a_rReal, a_rReader.getCurrentParseFlags());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Tdouble& a_rReal)
{ CALL
  a_rReader.read(a_rReal, a_rReader.getCurrentParseFlags());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator >> (IReader& a_rReader, Tptr& a_rpPointer)
{ CALL
  a_rReader.read(a_rpPointer, a_rReader.getCurrentParseFlags());
  return a_rReader;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
