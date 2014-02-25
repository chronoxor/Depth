/*!
 *  \file    AFormat.hpp Contains string format algorithm.
 *  \brief   String format algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: String format algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String format algorithms
    VERSION:   1.0
    CREATED:   29.09.2008 00:36:10

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
#ifndef __AFORMAT_HPP__
#define __AFORMAT_HPP__
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
//! Algorithm: Format ASCII C string buffer.
/*!
    \param a_cpFormatString - Constant pointer to the ASCII format string buffer.
    \return Formatted ASCII string (default is ASC("")).
    \see NDepth::NStream::IWriter::writeFormat()
*/
BASE_API NDepth::NString::CStringASCII format(const Tcsstr a_cpFormatString, ...);
/*--------------------------------------------------------------------------*/
//! Algorithm: Format ASCII C string buffer using variable list.
/*!
    \param a_cpFormatString - Constant pointer to the ASCII format string buffer.
    \param a_VariableList - Variable list.
    \return Formatted ASCII string (default is ASC("")).
    \see NDepth::NStream::IWriter::writeFormat()
*/
BASE_API NDepth::NString::CStringASCII formatVarList(const Tcsstr a_cpFormatString, va_list a_VariableList);
/*--------------------------------------------------------------------------*/
//! Algorithm: Format Unicode C string buffer.
/*!
    \param a_cpFormatString - Constant pointer to the Unicode format string buffer.
    \return Formatted Unicode string (default is ASC("")).
    \see NDepth::NStream::IWriter::writeFormat()
*/
BASE_API NDepth::NString::CStringUnicode format(const Tcwstr a_cpFormatString, ...);
/*--------------------------------------------------------------------------*/
//! Algorithm: Format Unicode C string buffer using variable list.
/*!
    \param a_cpFormatString - Constant pointer to the Unicode format string buffer.
    \param a_VariableList - Variable list.
    \return Formatted Unicode string (default is ASC("")).
    \see NDepth::NStream::IWriter::writeFormat()
*/
BASE_API NDepth::NString::CStringUnicode formatVarList(const Tcwstr a_cpFormatString, va_list a_VariableList);
/*--------------------------------------------------------------------------*/
//! Algorithm: Format ASCII string.
/*!
    \param a_cpFormatString - Constant pointer to the ASCII format string.
    \return Formatted ASCII string (default is ASC("")).
    \see NDepth::NStream::IWriter::writeFormat()
*/
BASE_API NDepth::NString::CStringASCII format(const NDepth::NString::CStringASCII* a_cpFormatString, ...);
/*--------------------------------------------------------------------------*/
//! Algorithm: Format ASCII string using variable list.
/*!
    \param a_crFormatString - Constant reference to the ASCII format string.
    \param a_VariableList - Variable list.
    \return Formatted ASCII string (default is ASC("")).
    \see NDepth::NStream::IWriter::writeFormat()
*/
BASE_API NDepth::NString::CStringASCII formatVarList(const NDepth::NString::CStringASCII& a_crFormatString, va_list a_VariableList);
/*--------------------------------------------------------------------------*/
//! Algorithm: Format Unicode string.
/*!
    \param a_cpFormatString - Constant pointer to the Unicode format string.
    \return Formatted Unicode string (default is UNC("")).
    \see NDepth::NStream::IWriter::writeFormat()
*/
BASE_API NDepth::NString::CStringUnicode format(const NDepth::NString::CStringUnicode* a_cpFormatString, ...);
/*--------------------------------------------------------------------------*/
//! Algorithm: Format Unicode string using variable list.
/*!
    \param a_crFormatString - Constant reference to the Unicode format string.
    \param a_VariableList - Variable list.
    \return Formatted Unicode string (default is UNC("")).
    \see NDepth::NStream::IWriter::writeFormat()
*/
BASE_API NDepth::NString::CStringUnicode formatVarList(const NDepth::NString::CStringUnicode& a_crFormatString, va_list a_VariableList);
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
