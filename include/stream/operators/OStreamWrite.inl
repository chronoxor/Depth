/*!
 *  \file    OStreamWrite.inl Set of the stream write operators are used to
 *           write common values (character, string, boolean, integer, real,
 *           pointer) into the stream.
 *  \brief   Stream write operators (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Stream write operators (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   01.10.2008 03:20:14

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
#ifndef __OSTREAMWRITE_INL__
#define __OSTREAMWRITE_INL__
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
inline IWriter& operator << (IWriter& a_rWriter, const Tschar a_cCharacter)
{ CALL
  a_rWriter.write(a_cCharacter);
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const Twchar a_cCharacter)
{ CALL
  a_rWriter.write(a_cCharacter);
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, Tcsstr a_cpString)
{ CALL
  a_rWriter.write(a_cpString);
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, Tcwstr a_cpString)
{ CALL
  a_rWriter.write(a_cpString);
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const NString::CStringASCII& a_crString)
{ CALL
  a_rWriter.write(a_crString);
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const NString::CStringUnicode& a_crString)
{ CALL
  a_rWriter.write(a_crString);
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const NString::CSystemString& a_crString)
{ CALL
  a_rWriter.write(a_crString);
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const Tbool a_cBoolean)
{ CALL
  a_rWriter.write(a_cBoolean, a_rWriter.getCurrentFormatFlags(), a_rWriter.getCurrentWidth());
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const Tsint08 a_cInteger)
{ CALL
  a_rWriter.write(a_cInteger, a_rWriter.getCurrentFormatFlags(), a_rWriter.getCurrentRadix(), a_rWriter.getCurrentWidth());
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const Tuint08 a_cInteger)
{ CALL
  a_rWriter.write(a_cInteger, a_rWriter.getCurrentFormatFlags(), a_rWriter.getCurrentRadix(), a_rWriter.getCurrentWidth());
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const Tsint16 a_cInteger)
{ CALL
  a_rWriter.write(a_cInteger, a_rWriter.getCurrentFormatFlags(), a_rWriter.getCurrentRadix(), a_rWriter.getCurrentWidth());
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const Tuint16 a_cInteger)
{ CALL
  a_rWriter.write(a_cInteger, a_rWriter.getCurrentFormatFlags(), a_rWriter.getCurrentRadix(), a_rWriter.getCurrentWidth());
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const Tsint32 a_cInteger)
{ CALL
  a_rWriter.write(a_cInteger, a_rWriter.getCurrentFormatFlags(), a_rWriter.getCurrentRadix(), a_rWriter.getCurrentWidth());
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const Tuint32 a_cInteger)
{ CALL
  a_rWriter.write(a_cInteger, a_rWriter.getCurrentFormatFlags(), a_rWriter.getCurrentRadix(), a_rWriter.getCurrentWidth());
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const Tsint64 a_cInteger)
{ CALL
  a_rWriter.write(a_cInteger, a_rWriter.getCurrentFormatFlags(), a_rWriter.getCurrentRadix(), a_rWriter.getCurrentWidth());
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const Tuint64 a_cInteger)
{ CALL
  a_rWriter.write(a_cInteger, a_rWriter.getCurrentFormatFlags(), a_rWriter.getCurrentRadix(), a_rWriter.getCurrentWidth());
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const Tfloat a_cReal)
{ CALL
  a_rWriter.write(a_cReal, a_rWriter.getCurrentFormatFlags(), a_rWriter.getCurrentPrecision(), a_rWriter.getCurrentWidth());
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, const Tdouble a_cReal)
{ CALL
  a_rWriter.write(a_cReal, a_rWriter.getCurrentFormatFlags(), a_rWriter.getCurrentPrecision(), a_rWriter.getCurrentWidth());
  return a_rWriter;
}
/*--------------------------------------------------------------------------*/
inline IWriter& operator << (IWriter& a_rWriter, Tcptr a_cpPointer)
{ CALL
  a_rWriter.write(a_cpPointer, a_rWriter.getCurrentFormatFlags(), a_rWriter.getCurrentWidth());
  return a_rWriter;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
