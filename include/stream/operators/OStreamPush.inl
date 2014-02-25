/*!
 *  \file    OStreamPush.inl Set of the stream push operators are used to
 *           push common values (character, string, boolean, integer, real,
 *           pointer) into the stream.
 *  \brief   Stream push operators (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Stream push operators (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   01.10.2008 03:58:22

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
#ifndef __OSTREAMPUSH_INL__
#define __OSTREAMPUSH_INL__
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
inline IReader& operator < (IReader& a_rReader, const Tschar a_cCharacter)
{ CALL
  a_rReader.push(a_cCharacter);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const Twchar a_cCharacter)
{ CALL
  a_rReader.push(a_cCharacter);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, Tcsstr a_cpString)
{ CALL
  a_rReader.push(a_cpString);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, Tcwstr a_cpString)
{ CALL
  a_rReader.push(a_cpString);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const NString::CStringASCII& a_crString)
{ CALL
  a_rReader.push(a_crString);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const NString::CStringUnicode& a_crString)
{ CALL
  a_rReader.push(a_crString);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const NString::CSystemString& a_crString)
{ CALL
  a_rReader.push(a_crString);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const Tbool a_cBoolean)
{ CALL
  a_rReader.push(a_cBoolean, a_rReader.getCurrentFormatFlags(), a_rReader.getCurrentWidth());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const Tsint08 a_cInteger)
{ CALL
  a_rReader.push(a_cInteger, a_rReader.getCurrentFormatFlags(), a_rReader.getCurrentRadix(), a_rReader.getCurrentWidth());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const Tuint08 a_cInteger)
{ CALL
  a_rReader.push(a_cInteger, a_rReader.getCurrentFormatFlags(), a_rReader.getCurrentRadix(), a_rReader.getCurrentWidth());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const Tsint16 a_cInteger)
{ CALL
  a_rReader.push(a_cInteger, a_rReader.getCurrentFormatFlags(), a_rReader.getCurrentRadix(), a_rReader.getCurrentWidth());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const Tuint16 a_cInteger)
{ CALL
  a_rReader.push(a_cInteger, a_rReader.getCurrentFormatFlags(), a_rReader.getCurrentRadix(), a_rReader.getCurrentWidth());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const Tsint32 a_cInteger)
{ CALL
  a_rReader.push(a_cInteger, a_rReader.getCurrentFormatFlags(), a_rReader.getCurrentRadix(), a_rReader.getCurrentWidth());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const Tuint32 a_cInteger)
{ CALL
  a_rReader.push(a_cInteger, a_rReader.getCurrentFormatFlags(), a_rReader.getCurrentRadix(), a_rReader.getCurrentWidth());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const Tsint64 a_cInteger)
{ CALL
  a_rReader.push(a_cInteger, a_rReader.getCurrentFormatFlags(), a_rReader.getCurrentRadix(), a_rReader.getCurrentWidth());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const Tuint64 a_cInteger)
{ CALL
  a_rReader.push(a_cInteger, a_rReader.getCurrentFormatFlags(), a_rReader.getCurrentRadix(), a_rReader.getCurrentWidth());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const Tfloat a_cReal)
{ CALL
  a_rReader.push(a_cReal, a_rReader.getCurrentFormatFlags(), a_rReader.getCurrentPrecision(), a_rReader.getCurrentWidth());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, const Tdouble a_cReal)
{ CALL
  a_rReader.push(a_cReal, a_rReader.getCurrentFormatFlags(), a_rReader.getCurrentPrecision(), a_rReader.getCurrentWidth());
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline IReader& operator < (IReader& a_rReader, Tcptr a_cpPointer)
{ CALL
  a_rReader.push(a_cpPointer, a_rReader.getCurrentFormatFlags(), a_rReader.getCurrentWidth());
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
