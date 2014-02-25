/*!
 *  \file    CSystemStringHelper.inl System string helper class contains
 *           strings encoding functionality.
 *  \brief   System string helper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: System string helper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String details
    VERSION:   1.0
    CREATED:   01.04.2008 21:27:16

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
#ifndef __CSYSTEMSTRINGHELPER_INL__
#define __CSYSTEMSTRINGHELPER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline Tuint CSystemStringHelper::getMaxBytesPerASCIIChar()
{ CALL
  return ms_fGetMaxBytesPerASCIIChar();
}
/*--------------------------------------------------------------------------*/
inline Tuint CSystemStringHelper::getMaxBytesPerUnicodeChar()
{ CALL
  return ms_fGetMaxBytesPerUnicodeChar();
}
/*--------------------------------------------------------------------------*/
inline Tuint CSystemStringHelper::getMaxBytesPerSystemChar()
{ CALL
  return ms_fGetMaxBytesPerSystemChar();
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::getASCIICharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount)
{ CALL
  return ms_fGetASCIICharsCount(a_cpBuffer, a_cSize, a_rCount);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::getUnicodeCharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount)
{ CALL
  return ms_fGetUnicodeCharsCount(a_cpBuffer, a_cSize, a_rCount);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::getSystemCharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount)
{ CALL
  return ms_fGetSystemCharsCount(a_cpBuffer, a_cSize, a_rCount);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::ASCIIToSystemCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fASCIIToSystemCount(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::UnicodeToSystemCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fUnicodeToSystemCount(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::UTF8ToSystemCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fUTF8ToSystemCount(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::ASCIIToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fASCIIToUTF8Count(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::UnicodeToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fUnicodeToUTF8Count(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::SystemToASCIICount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fSystemToASCIICount(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::SystemToUnicodeCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fSystemToUnicodeCount(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::SystemToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fSystemToUTF8Count(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::UTF8ToASCIICount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fUTF8ToASCIICount(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::UTF8ToUnicodeCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fUTF8ToUnicodeCount(a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::ASCIIToSystem(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fASCIIToSystem(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::UnicodeToSystem(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fUnicodeToSystem(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::UTF8ToSystem(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fUTF8ToSystem(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::ASCIIToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fASCIIToUTF8(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::UnicodeToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fUnicodeToUTF8(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::SystemToASCII(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fSystemToASCII(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::SystemToUnicode(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fSystemToUnicode(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::SystemToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fSystemToUTF8(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::UTF8ToASCII(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fUTF8ToASCII(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringHelper::UTF8ToUnicode(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  return ms_fUTF8ToUnicode(a_pDestination, a_cpSource, a_cCount, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline Tuint CSystemStringHelper::getMaxBytesPerUCS1Char()
{ CALL
  return 1;
}
/*--------------------------------------------------------------------------*/
inline Tuint CSystemStringHelper::getMaxBytesPerUCS2Char()
{ CALL
  return 2;
}
/*--------------------------------------------------------------------------*/
inline Tuint CSystemStringHelper::getMaxBytesPerUCS4Char()
{ CALL
  return 4;
}
/*--------------------------------------------------------------------------*/
inline Tuint CSystemStringHelper::getMaxBytesPerUTF8Char()
{ CALL
  return 6;
}
/*--------------------------------------------------------------------------*/
inline Tuint CSystemStringHelper::getMaxBytesPerUTF16Char()
{ CALL
  return 4;
}
/*--------------------------------------------------------------------------*/
inline Tuint CSystemStringHelper::getMaxBytesPerUTF32Char()
{ CALL
  return 2;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
