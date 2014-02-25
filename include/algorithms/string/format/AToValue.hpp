/*!
 *  \file    AToValue.hpp Contains set of algorithms for converting strings
 *           into boolean, integer, real values.
 *  \brief   Algorithms for converting strings into values.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithms for converting strings into values.

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
#ifndef __AFROMSTRING_HPP__
#define __AFROMSTRING_HPP__
/*==========================================================================*/
#include <Depth/include/stream/IStream.hpp>
#include <Depth/include/string/CString.hpp>
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
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Convert string into the boolean number value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Boolean number value from the string (default is false).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tbool toBool(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the signed integer value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Signed integer value from the string (default is 0).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tsint toSigned(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the unsigned integer value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Unsigned integer value from the string (default is 0).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tuint toUnsigned(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the signed 1 byte integer value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Signed 1 byte integer value from the string (default is 0).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tsint08 toSigned08(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the unsigned 1 byte integer value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Unsigned 1 byte integer value from the string (default is 0).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tuint08 toUnsigned08(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the signed 2 bytes integer value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Signed 2 bytes integer value from the string (default is 0).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tsint16 toSigned16(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the unsigned 2 bytes integer value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Unsigned 2 bytes integer value from the string (default is 0).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tuint16 toUnsigned16(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the signed 4 bytes integer value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Signed 4 bytes integer value from the string (default is 0).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tsint32 toSigned32(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the unsigned 4 bytes integer value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Unsigned 4 bytes integer value from the string (default is 0).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tuint32 toUnsigned32(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the signed 8 bytes integer value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Signed 8 bytes integer value from the string (default is 0).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tsint64 toSigned64(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the unsigned 8 bytes integer value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Unsigned 8 bytes integer value from the string (default is 0).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tuint64 toUnsigned64(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the single accuracy real value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Single accuracy real value from the string (default is 0.0).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tfloat toFloat(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the double accuracy real value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Double accuracy real value from the string (default is 0.0).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tdouble toDouble(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the real value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Double real value from the string (default is 0.0).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Treal toReal(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert string into the pointer value.
/*!
    \param a_crSourceString - Constant reference to the source string.
    \param a_cParseFlags - Combination of the parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
    \return Pointer value from the string (default is NULL).
    \see NDepth::NStream::IReader::read()
*/
BASE_API Tptr toPointer(const NDepth::NString::CString& a_crSourceString, const Tuint a_cParseFlags = NStream::IStream::PARSE_DEFAULT);
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
