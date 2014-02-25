/*!
 *  \file    CSystemBaseEncoding-Windows.cpp Base system class contains
 *           common functionality such as memory routines, math functions,
 *           error handling, standard I/O routines.
 *  \brief   Base system class - Windows OS - encoding methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Windows OS - encoding methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   07.01.2006 01:33:12

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
#include <Depth/include/string/details/CSystemStringHelper.hpp>
#include <Depth/include/system/CSystemBase.hpp>
/*==========================================================================*/
#ifndef __CSYSTEMBASEENCODING_WINDOWS_CPP__
#define __CSYSTEMBASEENCODING_WINDOWS_CPP__
/*==========================================================================*/
#if defined(__WINDOWS__)
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CSystemBase::installSystemEncoding()
{ CALL
  NString::NDetails::CSystemStringHelper::ms_fGetMaxBytesPerASCIIChar = &NString::NDetails::CSystemStringHelper::getMaxBytesPerUCS1Char;
  #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
  NString::NDetails::CSystemStringHelper::ms_fGetMaxBytesPerUnicodeChar = &NString::NDetails::CSystemStringHelper::getMaxBytesPerUCS2Char;
  #else
  NString::NDetails::CSystemStringHelper::ms_fGetMaxBytesPerUnicodeChar = &NString::NDetails::CSystemStringHelper::getMaxBytesPerUCS4Char;
  #endif
  NString::NDetails::CSystemStringHelper::ms_fGetMaxBytesPerSystemChar = &NString::NDetails::CSystemStringHelper::getMaxBytesPerUTF16Char;
  NString::NDetails::CSystemStringHelper::ms_fGetASCIICharsCount = &NString::NDetails::CSystemStringHelper::getUCS1CharsCount;
  #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
  NString::NDetails::CSystemStringHelper::ms_fGetUnicodeCharsCount = &NString::NDetails::CSystemStringHelper::getUCS2CharsCount;
  #else
  NString::NDetails::CSystemStringHelper::ms_fGetUnicodeCharsCount = &NString::NDetails::CSystemStringHelper::getUCS4CharsCount;
  #endif
  NString::NDetails::CSystemStringHelper::ms_fGetSystemCharsCount = &NString::NDetails::CSystemStringHelper::getUTF16CharsCount;
  NString::NDetails::CSystemStringHelper::ms_fASCIIToSystemCount = &NString::NDetails::CSystemStringHelper::UCS1ToUTF16Count;
  #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
  NString::NDetails::CSystemStringHelper::ms_fUnicodeToSystemCount = &NString::NDetails::CSystemStringHelper::UCS2ToUTF16Count;
  #else
  NString::NDetails::CSystemStringHelper::ms_fUnicodeToSystemCount = &NString::NDetails::CSystemStringHelper::UCS4ToUTF16Count;
  #endif
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToSystemCount = &NString::NDetails::CSystemStringHelper::UTF8ToUTF16Count;
  NString::NDetails::CSystemStringHelper::ms_fASCIIToUTF8Count = &NString::NDetails::CSystemStringHelper::UCS1ToUTF8Count;
  #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
  NString::NDetails::CSystemStringHelper::ms_fUnicodeToUTF8Count = &NString::NDetails::CSystemStringHelper::UCS2ToUTF8Count;
  #else
  NString::NDetails::CSystemStringHelper::ms_fUnicodeToUTF8Count = &NString::NDetails::CSystemStringHelper::UCS4ToUTF8Count;
  #endif
  NString::NDetails::CSystemStringHelper::ms_fSystemToASCIICount = &NString::NDetails::CSystemStringHelper::UTF16ToUCS1Count;
  #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
  NString::NDetails::CSystemStringHelper::ms_fSystemToUnicodeCount = &NString::NDetails::CSystemStringHelper::UTF16ToUCS2Count;
  #else
  NString::NDetails::CSystemStringHelper::ms_fSystemToUnicodeCount = &NString::NDetails::CSystemStringHelper::UTF16ToUCS4Count;
  #endif
  NString::NDetails::CSystemStringHelper::ms_fSystemToUTF8Count = &NString::NDetails::CSystemStringHelper::UTF16ToUTF8Count;
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToASCIICount = &NString::NDetails::CSystemStringHelper::UTF8ToUCS1Count;
  #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToUnicodeCount = &NString::NDetails::CSystemStringHelper::UTF8ToUCS2Count;
  #else
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToUnicodeCount = &NString::NDetails::CSystemStringHelper::UTF8ToUCS4Count;
  #endif
  NString::NDetails::CSystemStringHelper::ms_fASCIIToSystem = &NString::NDetails::CSystemStringHelper::UCS1ToUTF16;
  #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
  NString::NDetails::CSystemStringHelper::ms_fUnicodeToSystem = &NString::NDetails::CSystemStringHelper::UCS2ToUTF16;
  #else
  NString::NDetails::CSystemStringHelper::ms_fUnicodeToSystem = &NString::NDetails::CSystemStringHelper::UCS4ToUTF16;
  #endif
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToSystem = &NString::NDetails::CSystemStringHelper::UTF8ToUTF16;
  NString::NDetails::CSystemStringHelper::ms_fASCIIToUTF8 = &NString::NDetails::CSystemStringHelper::UCS1ToUTF8;
  #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
  NString::NDetails::CSystemStringHelper::ms_fUnicodeToUTF8 = &NString::NDetails::CSystemStringHelper::UCS2ToUTF8;
  #else
  NString::NDetails::CSystemStringHelper::ms_fUnicodeToUTF8 = &NString::NDetails::CSystemStringHelper::UCS4ToUTF8;
  #endif
  NString::NDetails::CSystemStringHelper::ms_fSystemToASCII = &NString::NDetails::CSystemStringHelper::UTF16ToUCS1;
  #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
  NString::NDetails::CSystemStringHelper::ms_fSystemToUnicode = &NString::NDetails::CSystemStringHelper::UTF16ToUCS2;
  #else
  NString::NDetails::CSystemStringHelper::ms_fSystemToUnicode = &NString::NDetails::CSystemStringHelper::UTF16ToUCS4;
  #endif
  NString::NDetails::CSystemStringHelper::ms_fSystemToUTF8 = &NString::NDetails::CSystemStringHelper::UTF16ToUTF8;
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToASCII = &NString::NDetails::CSystemStringHelper::UTF8ToUCS1;
  #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToUnicode = &NString::NDetails::CSystemStringHelper::UTF8ToUCS2;
  #else
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToUnicode = &NString::NDetails::CSystemStringHelper::UTF8ToUCS4;
  #endif
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::uninstallSystemEncoding()
{ CALL
  NString::NDetails::CSystemStringHelper::ms_fGetMaxBytesPerASCIIChar = NULL;
  NString::NDetails::CSystemStringHelper::ms_fGetMaxBytesPerUnicodeChar = NULL;
  NString::NDetails::CSystemStringHelper::ms_fGetMaxBytesPerSystemChar = NULL;
  NString::NDetails::CSystemStringHelper::ms_fGetASCIICharsCount = NULL;
  NString::NDetails::CSystemStringHelper::ms_fGetUnicodeCharsCount = NULL;
  NString::NDetails::CSystemStringHelper::ms_fGetSystemCharsCount = NULL;
  NString::NDetails::CSystemStringHelper::ms_fASCIIToSystemCount = NULL;
  NString::NDetails::CSystemStringHelper::ms_fUnicodeToSystemCount = NULL;
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToSystemCount = NULL;
  NString::NDetails::CSystemStringHelper::ms_fASCIIToUTF8Count = NULL;
  NString::NDetails::CSystemStringHelper::ms_fUnicodeToUTF8Count = NULL;
  NString::NDetails::CSystemStringHelper::ms_fSystemToASCIICount = NULL;
  NString::NDetails::CSystemStringHelper::ms_fSystemToUnicodeCount = NULL;
  NString::NDetails::CSystemStringHelper::ms_fSystemToUTF8Count = NULL;
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToASCIICount = NULL;
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToUnicodeCount = NULL;
  NString::NDetails::CSystemStringHelper::ms_fASCIIToSystem = NULL;
  NString::NDetails::CSystemStringHelper::ms_fUnicodeToSystem = NULL;
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToSystem = NULL;
  NString::NDetails::CSystemStringHelper::ms_fASCIIToUTF8 = NULL;
  NString::NDetails::CSystemStringHelper::ms_fUnicodeToUTF8 = NULL;
  NString::NDetails::CSystemStringHelper::ms_fSystemToASCII = NULL;
  NString::NDetails::CSystemStringHelper::ms_fSystemToUnicode = NULL;
  NString::NDetails::CSystemStringHelper::ms_fSystemToUTF8 = NULL;
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToASCII = NULL;
  NString::NDetails::CSystemStringHelper::ms_fUTF8ToUnicode = NULL;
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
#endif
