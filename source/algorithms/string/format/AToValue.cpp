/*!
 *  \file    AToValue.cpp Contains set of algorithms for converting strings
 *           into boolean, integer, real values.
 *  \brief   Algorithms for converting strings into values (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithms for converting strings into values (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String format algorithms
    VERSION:   1.0
    CREATED:   29.09.2008 23:55:34

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
#include <Depth/include/algorithms/string/format/AToValue.hpp>
#include <Depth/include/stream/text/CStreamString.hpp>
/*==========================================================================*/
#ifndef __AFROMSTRING_CPP__
#define __AFROMSTRING_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NFormat {
/*==========================================================================*/
/* ALGORITHM IMPLEMENTATIONS                                                */
/*==========================================================================*/
BASE_API Tbool toBool(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tbool result = false;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tsint toSigned(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tsint result = 0;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint toUnsigned(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tuint result = 0;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tsint08 toSigned08(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tsint08 result = 0;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint08 toUnsigned08(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tuint08 result = 0;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tsint16 toSigned16(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tsint16 result = 0;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint16 toUnsigned16(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tuint16 result = 0;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tsint32 toSigned32(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tsint32 result = 0;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint32 toUnsigned32(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tuint32 result = 0;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tsint64 toSigned64(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tsint64 result = 0;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint64 toUnsigned64(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tuint64 result = 0;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tfloat toFloat(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tfloat result = 0.0;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tdouble toDouble(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tdouble result = 0.0;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Treal toReal(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Treal result = 0.0;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tptr toPointer(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags/* = NStream::IStream::PARSE_DEFAULT */)
{ CALL
  Tptr result = NULL;
  NStream::NText::CStreamString stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  if (!stream.read(result, a_cParseFlags).getFirst())
    return result;
  if (!stream.close())
    return result;

  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
