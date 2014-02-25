/*!
 *  \file    AToString.hpp Contains set of algorithms for converting boolean,
 *           integer, real values into strings.
 *  \brief   Algorithms for converting values into strings.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithms for converting values into strings.

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
#ifndef __ATOSTRING_HPP__
#define __ATOSTRING_HPP__
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
//! Algorithm: Convert boolean number value into the string.
/*!
    \param a_cBoolean - Boolean number value.
    \param a_cFormatFlags - Combination of the format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
    \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
    \return String with converted boolean number value (default is STR("")).
    \see NDepth::NStream::IWriter::write()
*/
BASE_API NDepth::NString::CString toString(const Tbool a_cBoolean, const Tuint a_cFormatFlags = NStream::IStream::FORMAT_DEFAULT, const Tuint a_cWidth = 0);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert signed 1 byte integer value the string.
/*!
    \param a_cInteger - Signed 1 byte integer value.
    \param a_cFormatFlags - Combination of the format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
    \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
    \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
    \return String with converted signed 1 byte integer value (default is STR("")).
    \see NDepth::NStream::IWriter::write()
*/
BASE_API NDepth::NString::CString toString(const Tsint08 a_cInteger, const Tuint a_cFormatFlags = NStream::IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert unsigned 1 byte integer value the string.
/*!
    \param a_cInteger - Unsigned 1 byte integer value.
    \param a_cFormatFlags - Combination of the format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
    \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
    \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
    \return String with converted unsigned 1 byte integer value (default is STR("")).
    \see NDepth::NStream::IWriter::write()
*/
BASE_API NDepth::NString::CString toString(const Tuint08 a_cInteger, const Tuint a_cFormatFlags = NStream::IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert signed 2 bytes integer value the string.
/*!
    \param a_cInteger - Signed 2 bytes integer value.
    \param a_cFormatFlags - Combination of the format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
    \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
    \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
    \return String with converted signed 2 bytes integer value (default is STR("")).
    \see NDepth::NStream::IWriter::write()
*/
BASE_API NDepth::NString::CString toString(const Tsint16 a_cInteger, const Tuint a_cFormatFlags = NStream::IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert unsigned 2 bytes integer value the string.
/*!
    \param a_cInteger - Unsigned 2 bytes integer value.
    \param a_cFormatFlags - Combination of the format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
    \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
    \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
    \return Successful flag and count of written bytes/characters.
    \return String with converted unsigned 2 bytes integer value (default is STR("")).
    \see NDepth::NStream::IWriter::write()
*/
BASE_API NDepth::NString::CString toString(const Tuint16 a_cInteger, const Tuint a_cFormatFlags = NStream::IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert signed 4 bytes integer value the string.
/*!
    \param a_cInteger - Signed 4 bytes integer value.
    \param a_cFormatFlags - Combination of the format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
    \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
    \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
    \return String with converted signed 4 bytes integer value (default is STR("")).
    \see NDepth::NStream::IWriter::write()
*/
BASE_API NDepth::NString::CString toString(const Tsint32 a_cInteger, const Tuint a_cFormatFlags = NStream::IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert unsigned 4 bytes integer value the string.
/*!
    \param a_cInteger - Unsigned 4 bytes integer value.
    \param a_cFormatFlags - Combination of the format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
    \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
    \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
    \return String with converted unsigned 4 bytes integer value (default is STR("")).
    \see NDepth::NStream::IWriter::write()
*/
BASE_API NDepth::NString::CString toString(const Tuint32 a_cInteger, const Tuint a_cFormatFlags = NStream::IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert signed 8 bytes integer value the string.
/*!
    \param a_cInteger - Signed 8 bytes integer value.
    \param a_cFormatFlags - Combination of the format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
    \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
    \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
    \return String with converted signed 8 bytes integer value (default is STR("")).
    \see NDepth::NStream::IWriter::write()
*/
BASE_API NDepth::NString::CString toString(const Tsint64 a_cInteger, const Tuint a_cFormatFlags = NStream::IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert unsigned 8 bytes integer value the string.
/*!
    \param a_cInteger - Unsigned 8 bytes integer value.
    \param a_cFormatFlags - Combination of the format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
    \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
    \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
    \return String with converted unsigned 8 bytes integer value (default is STR("")).
    \see NDepth::NStream::IWriter::write()
*/
BASE_API NDepth::NString::CString toString(const Tuint64 a_cInteger, const Tuint a_cFormatFlags = NStream::IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert single accuracy real value the string.
/*!
    \param a_cReal - Single accuracy real value.
    \param a_cFormatFlags - Combination of the format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
    \param a_cPrecision - Count of precision numbers after the decimal point (default is 6).
    \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
    \return String with converted single accuracy real value (default is STR("")).
    \see NDepth::NStream::IWriter::write()
*/
BASE_API NDepth::NString::CString toString(const Tfloat a_cReal, const Tuint a_cFormatFlags = NStream::IStream::FORMAT_DEFAULT, const Tuint a_cPrecision = 6, const Tuint a_cWidth = 0);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert double accuracy real value the string.
/*!
    \param a_cReal - Double accuracy real value.
    \param a_cFormatFlags - Combination of the format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
    \param a_cPrecision - Count of precision numbers after the decimal point (default is 6).
    \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
    \return String with converted double accuracy real value (default is STR("")).
    \see NDepth::NStream::IWriter::write()
*/
BASE_API NDepth::NString::CString toString(const Tdouble a_cReal, const Tuint a_cFormatFlags = NStream::IStream::FORMAT_DEFAULT, const Tuint a_cPrecision = 6, const Tuint a_cWidth = 0);
/*--------------------------------------------------------------------------*/
//! Algorithm: Convert pointer value the string.
/*!
    \param a_cpPointer - Pointer value.
    \param a_cFormatFlags - Combination of the format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
    \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
    \return String with converted pointer value (default is STR("")).
    \see NDepth::NStream::IWriter::write()
*/
BASE_API NDepth::NString::CString toString(Tcptr a_cpPointer, const Tuint a_cFormatFlags = NStream::IStream::FORMAT_DEFAULT, const Tuint a_cWidth = 0);
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
