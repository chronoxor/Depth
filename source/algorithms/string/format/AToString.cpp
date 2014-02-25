/*!
 *  \file    AToString.cpp Contains set of algorithms for converting boolean,
 *           integer, real values into strings.
 *  \brief   Algorithms for converting values into strings (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithms for converting values into strings (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String format algorithms
    VERSION:   1.0
    CREATED:   29.09.2008 21:51:50

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
#include <Depth/include/algorithms/string/format/AToString.hpp>
#include <Depth/include/stream/text/CStreamString.hpp>
/*==========================================================================*/
#ifndef __ATOSTRING_CPP__
#define __ATOSTRING_CPP__
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
BASE_API NDepth::NString::CString toString(const Tbool a_cBoolean, const Tuint a_cFormatFlags/* = NStream::IStream::FORMAT_DEFAULT */, const Tuint a_cWidth/* = 0 */)
{ CALL
  NStream::NText::CStreamString stream;

  if (!stream.open(NStream::IStream::e_OPEN_WRITE))
    return NDepth::NString::CString::EMPTY;
  if (!stream.write(a_cBoolean, a_cFormatFlags, a_cWidth).getFirst())
    return NDepth::NString::CString::EMPTY;
  if (!stream.close())
    return NDepth::NString::CString::EMPTY;

  return stream;
}
/*--------------------------------------------------------------------------*/
BASE_API NDepth::NString::CString toString(const Tsint08 a_cInteger, const Tuint a_cFormatFlags/* = NStream::IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  NStream::NText::CStreamString stream;

  if (!stream.open(NStream::IStream::e_OPEN_WRITE))
    return NDepth::NString::CString::EMPTY;
  if (!stream.write(a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth).getFirst())
    return NDepth::NString::CString::EMPTY;
  if (!stream.close())
    return NDepth::NString::CString::EMPTY;

  return stream;
}
/*--------------------------------------------------------------------------*/
BASE_API NDepth::NString::CString toString(const Tuint08 a_cInteger, const Tuint a_cFormatFlags/* = NStream::IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  NStream::NText::CStreamString stream;

  if (!stream.open(NStream::IStream::e_OPEN_WRITE))
    return NDepth::NString::CString::EMPTY;
  if (!stream.write(a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth).getFirst())
    return NDepth::NString::CString::EMPTY;
  if (!stream.close())
    return NDepth::NString::CString::EMPTY;

  return stream;
}
/*--------------------------------------------------------------------------*/
BASE_API NDepth::NString::CString toString(const Tsint16 a_cInteger, const Tuint a_cFormatFlags/* = NStream::IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  NStream::NText::CStreamString stream;

  if (!stream.open(NStream::IStream::e_OPEN_WRITE))
    return NDepth::NString::CString::EMPTY;
  if (!stream.write(a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth).getFirst())
    return NDepth::NString::CString::EMPTY;
  if (!stream.close())
    return NDepth::NString::CString::EMPTY;

  return stream;
}
/*--------------------------------------------------------------------------*/
BASE_API NDepth::NString::CString toString(const Tuint16 a_cInteger, const Tuint a_cFormatFlags/* = NStream::IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  NStream::NText::CStreamString stream;

  if (!stream.open(NStream::IStream::e_OPEN_WRITE))
    return NDepth::NString::CString::EMPTY;
  if (!stream.write(a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth).getFirst())
    return NDepth::NString::CString::EMPTY;
  if (!stream.close())
    return NDepth::NString::CString::EMPTY;

  return stream;
}
/*--------------------------------------------------------------------------*/
BASE_API NDepth::NString::CString toString(const Tsint32 a_cInteger, const Tuint a_cFormatFlags/* = NStream::IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  NStream::NText::CStreamString stream;

  if (!stream.open(NStream::IStream::e_OPEN_WRITE))
    return NDepth::NString::CString::EMPTY;
  if (!stream.write(a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth).getFirst())
    return NDepth::NString::CString::EMPTY;
  if (!stream.close())
    return NDepth::NString::CString::EMPTY;

  return stream;
}
/*--------------------------------------------------------------------------*/
BASE_API NDepth::NString::CString toString(const Tuint32 a_cInteger, const Tuint a_cFormatFlags/* = NStream::IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  NStream::NText::CStreamString stream;

  if (!stream.open(NStream::IStream::e_OPEN_WRITE))
    return NDepth::NString::CString::EMPTY;
  if (!stream.write(a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth).getFirst())
    return NDepth::NString::CString::EMPTY;
  if (!stream.close())
    return NDepth::NString::CString::EMPTY;

  return stream;
}
/*--------------------------------------------------------------------------*/
BASE_API NDepth::NString::CString toString(const Tsint64 a_cInteger, const Tuint a_cFormatFlags/* = NStream::IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  NStream::NText::CStreamString stream;

  if (!stream.open(NStream::IStream::e_OPEN_WRITE))
    return NDepth::NString::CString::EMPTY;
  if (!stream.write(a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth).getFirst())
    return NDepth::NString::CString::EMPTY;
  if (!stream.close())
    return NDepth::NString::CString::EMPTY;

  return stream;
}
/*--------------------------------------------------------------------------*/
BASE_API NDepth::NString::CString toString(const Tuint64 a_cInteger, const Tuint a_cFormatFlags/* = NStream::IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  NStream::NText::CStreamString stream;

  if (!stream.open(NStream::IStream::e_OPEN_WRITE))
    return NDepth::NString::CString::EMPTY;
  if (!stream.write(a_cInteger, a_cFormatFlags, a_cRadix, a_cWidth).getFirst())
    return NDepth::NString::CString::EMPTY;
  if (!stream.close())
    return NDepth::NString::CString::EMPTY;

  return stream;
}
/*--------------------------------------------------------------------------*/
BASE_API NDepth::NString::CString toString(const Tfloat a_cReal, const Tuint a_cFormatFlags/* = NStream::IStream::FORMAT_DEFAULT */, const Tuint a_cPrecision/* = 6 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  NStream::NText::CStreamString stream;

  if (!stream.open(NStream::IStream::e_OPEN_WRITE))
    return NDepth::NString::CString::EMPTY;
  if (!stream.write(a_cReal, a_cFormatFlags, a_cPrecision, a_cWidth).getFirst())
    return NDepth::NString::CString::EMPTY;
  if (!stream.close())
    return NDepth::NString::CString::EMPTY;

  return stream;
}
/*--------------------------------------------------------------------------*/
BASE_API NDepth::NString::CString toString(const Tdouble a_cReal, const Tuint a_cFormatFlags/* = NStream::IStream::FORMAT_DEFAULT */, const Tuint a_cPrecision/* = 6 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  NStream::NText::CStreamString stream;

  if (!stream.open(NStream::IStream::e_OPEN_WRITE))
    return NDepth::NString::CString::EMPTY;
  if (!stream.write(a_cReal, a_cFormatFlags, a_cPrecision, a_cWidth).getFirst())
    return NDepth::NString::CString::EMPTY;
  if (!stream.close())
    return NDepth::NString::CString::EMPTY;

  return stream;
}
/*--------------------------------------------------------------------------*/
BASE_API NDepth::NString::CString toString(Tcptr a_cpPointer, const Tuint a_cFormatFlags/* = NStream::IStream::FORMAT_DEFAULT */, const Tuint a_cWidth/* = 0 */)
{ CALL
  NStream::NText::CStreamString stream;

  if (!stream.open(NStream::IStream::e_OPEN_WRITE))
    return NDepth::NString::CString::EMPTY;
  if (!stream.write(a_cpPointer, a_cFormatFlags, a_cWidth).getFirst())
    return NDepth::NString::CString::EMPTY;
  if (!stream.close())
    return NDepth::NString::CString::EMPTY;

  return stream;
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
