/*!
 *  \file    AUnformat.hpp Contains string unformat algorithm.
 *  \brief   String unformat algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: String unformat algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String format algorithms
    VERSION:   1.0
    CREATED:   29.09.2008 00:45:38

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
#ifndef __AUNFORMAT_HPP__
#define __AUNFORMAT_HPP__
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
//! Algorithm: Unformat ASCII C string buffer.
/*!
    \param a_crSourceString - Constant reference to the ASCII source string.
    \param a_cpFormatString - Constant pointer to the ASCII format string buffer.
    \return true  - if source string was unformatted successfully. \n
            false - if source string was not unformatted successfully. \n
    \see NDepth::NStream::IReader::readFormat()
*/
BASE_API Tbool unformat(const NDepth::NString::CStringASCII& a_crSourceString, const Tcsstr a_cpFormatString, ...);
/*--------------------------------------------------------------------------*/
//! Algorithm: Unformat ASCII C string buffer using variable list.
/*!
    \param a_crSourceString - Constant reference to the ASCII source string.
    \param a_cpFormatString - Constant pointer to the ASCII format string buffer.
    \param a_VariableList - Variable list.
    \return true  - if source string was unformatted successfully. \n
            false - if source string was not unformatted successfully. \n
    \see NDepth::NStream::IReader::readFormat()
*/
BASE_API Tbool unformatVarList(const NDepth::NString::CStringASCII& a_crSourceString, const Tcsstr a_cpFormatString, va_list a_VariableList);
/*--------------------------------------------------------------------------*/
//! Algorithm: Unformat Unicode C string buffer.
/*!
    \param a_crSourceString - Constant reference to the Unicode source string.
    \param a_cpFormatString - Constant pointer to the Unicode format string buffer.
    \return true  - if source string was unformatted successfully. \n
            false - if source string was not unformatted successfully. \n
    \see NDepth::NStream::IReader::readFormat()
*/
BASE_API Tbool unformat(const NDepth::NString::CStringUnicode& a_crSourceString, const Tcwstr a_cpFormatString, ...);
/*--------------------------------------------------------------------------*/
//! Algorithm: Unformat Unicode C string buffer using variable list.
/*!
    \param a_crSourceString - Constant reference to the Unicode source string.
    \param a_cpFormatString - Constant pointer to the Unicode format string buffer.
    \param a_VariableList - Variable list.
    \return true  - if source string was unformatted successfully. \n
            false - if source string was not unformatted successfully. \n
    \see NDepth::NStream::IReader::readFormat()
*/
BASE_API Tbool unformatVarList(const NDepth::NString::CStringUnicode& a_crSourceString, const Tcwstr a_cpFormatString, va_list a_VariableList);
/*--------------------------------------------------------------------------*/
//! Algorithm: Unformat ASCII string.
/*!
    \param a_crSourceString - Constant reference to the ASCII source string.
    \param a_cpFormatString - Constant pointer to the ASCII format string.
    \return true  - if source string was unformatted successfully. \n
            false - if source string was not unformatted successfully. \n
    \see NDepth::NStream::IReader::readFormat()
*/
BASE_API Tbool unformat(const NDepth::NString::CStringASCII& a_crSourceString, const NDepth::NString::CStringASCII* a_cpFormatString, ...);
/*--------------------------------------------------------------------------*/
//! Algorithm: Unformat ASCII string using variable list.
/*!
    \param a_crSourceString - Constant reference to the ASCII source string.
    \param a_crFormatString - Constant reference to the ASCII format string.
    \param a_VariableList - Variable list.
    \return true  - if source string was unformatted successfully. \n
            false - if source string was not unformatted successfully. \n
    \see NDepth::NStream::IReader::readFormat()
*/
BASE_API Tbool unformatVarList(const NDepth::NString::CStringASCII& a_crSourceString, const NDepth::NString::CStringASCII& a_crFormatString, va_list a_VariableList);
/*--------------------------------------------------------------------------*/
//! Algorithm: Unformat Unicode string.
/*!
    \param a_crSourceString - Constant reference to the Unicode source string.
    \param a_cpFormatString - Constant pointer to the Unicode format string.
    \return true  - if source string was unformatted successfully. \n
            false - if source string was not unformatted successfully. \n
    \see NDepth::NStream::IReader::readFormat()
*/
BASE_API Tbool unformat(const NDepth::NString::CStringUnicode& a_crSourceString, const NDepth::NString::CStringUnicode* a_cpFormatString, ...);
/*--------------------------------------------------------------------------*/
//! Algorithm: Unformat Unicode string using variable list.
/*!
    \param a_crSourceString - Constant reference to the Unicode source string.
    \param a_crFormatString - Constant reference to the Unicode format string.
    \param a_VariableList - Variable list.
    \return true  - if source string was unformatted successfully. \n
            false - if source string was not unformatted successfully. \n
    \see NDepth::NStream::IReader::readFormat()
*/
BASE_API Tbool unformatVarList(const NDepth::NString::CStringUnicode& a_crSourceString, const NDepth::NString::CStringUnicode& a_crFormatString, va_list a_VariableList);
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
