/*!
 *  \file    constants.cpp Contains base constants definitions for the Depth
 *           project.
 *  \brief   Constants definitions (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constants definitions (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Constants definitions
    VERSION:   1.0
    CREATED:   02.01.2006 00:07:17

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
/*==========================================================================*/
#ifndef __CONSTANTS_CPP__
#define __CONSTANTS_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConstants {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
#if defined(__DEBUG__)
BASE_API const NTypes::Tbool CConstants::isDebug = true;
BASE_API const NTypes::Tbool CConstants::isRelease = false;
#else
BASE_API const NTypes::Tbool CConstants::isDebug = false;
BASE_API const NTypes::Tbool CConstants::isRelease = true;
#endif
/*--------------------------------------------------------------------------*/
#if defined(__BIG_ENDIAN__)
BASE_API const NTypes::Tbool CConstants::isBigEndian = true;
BASE_API const NTypes::Tbool CConstants::isLittleEndian = false;
#else
BASE_API const NTypes::Tbool CConstants::isBigEndian = false;
BASE_API const NTypes::Tbool CConstants::isLittleEndian = true;
#endif
/*--------------------------------------------------------------------------*/
#if defined(__UNICODE__)
BASE_API const NTypes::Tbool CConstants::isASCII = false;
BASE_API const NTypes::Tbool CConstants::isUnicode = true;
#else
BASE_API const NTypes::Tbool CConstants::isASCII = true;
BASE_API const NTypes::Tbool CConstants::isUnicode = false;
#endif
/*--------------------------------------------------------------------------*/
BASE_API const NTypes::Tuint CConstants::platformBits = (SYS_PLATFORM_BITS);
BASE_API const NTypes::Tuint CConstants::platformBytes = ((SYS_PLATFORM_BITS) / 8);
BASE_API const NTypes::Tuint CConstants::platformMaxBits = (SYS_PLATFORM_MAX_BITS);
BASE_API const NTypes::Tuint CConstants::platformMaxBytes = ((SYS_PLATFORM_MAX_BITS) / 8);
/*--------------------------------------------------------------------------*/
BASE_API const NTypes::Tptr CConstants::ptrMin = (NTypes::Tptr)(SYS_PTR_MIN);
BASE_API const NTypes::Tptr CConstants::ptrMax = (NTypes::Tptr)(SYS_PTR_MAX);
/*--------------------------------------------------------------------------*/
BASE_API const NTypes::Tchar   CConstants::charMin = (SYS_CHAR_MIN);
BASE_API const NTypes::Tchar   CConstants::charMax = (SYS_CHAR_MAX);
BASE_API const NTypes::Tcharu  CConstants::charAbsMin = (SYS_CHAR_ABSMIN);
BASE_API const NTypes::Tcharu  CConstants::charAbsMax = (SYS_CHAR_ABSMAX);
BASE_API const NTypes::Tschar  CConstants::scharMin = (SYS_SCHAR_MIN);
BASE_API const NTypes::Tschar  CConstants::scharMax = (SYS_SCHAR_MAX);
BASE_API const NTypes::Tscharu CConstants::scharAbsMin = (SYS_SCHAR_ABSMIN);
BASE_API const NTypes::Tscharu CConstants::scharAbsMax = (SYS_SCHAR_ABSMAX);
BASE_API const NTypes::Twchar  CConstants::wcharMin = (SYS_WCHAR_MIN);
BASE_API const NTypes::Twchar  CConstants::wcharMax = (SYS_WCHAR_MAX);
BASE_API const NTypes::Twcharu CConstants::wcharAbsMin = (SYS_WCHAR_ABSMIN);
BASE_API const NTypes::Twcharu CConstants::wcharAbsMax = (SYS_WCHAR_ABSMAX);
/*--------------------------------------------------------------------------*/
BASE_API const NTypes::Tsint CConstants::sintMin = (SYS_SINT_MIN);
BASE_API const NTypes::Tsint CConstants::sintMax = (SYS_SINT_MAX);
BASE_API const NTypes::Tuint CConstants::uintMin = (SYS_UINT_MIN);
BASE_API const NTypes::Tuint CConstants::uintMax = (SYS_UINT_MAX);
BASE_API const NTypes::Tsint08 CConstants::sint08Min = (SYS_SINT08_MIN);
BASE_API const NTypes::Tsint08 CConstants::sint08Max = (SYS_SINT08_MAX);
BASE_API const NTypes::Tuint08 CConstants::uint08Min = (SYS_UINT08_MIN);
BASE_API const NTypes::Tuint08 CConstants::uint08Max = (SYS_UINT08_MAX);
BASE_API const NTypes::Tsint16 CConstants::sint16Min = (SYS_SINT16_MIN);
BASE_API const NTypes::Tsint16 CConstants::sint16Max = (SYS_SINT16_MAX);
BASE_API const NTypes::Tuint16 CConstants::uint16Min = (SYS_UINT16_MIN);
BASE_API const NTypes::Tuint16 CConstants::uint16Max = (SYS_UINT16_MAX);
BASE_API const NTypes::Tsint32 CConstants::sint32Min = (SYS_SINT32_MIN);
BASE_API const NTypes::Tsint32 CConstants::sint32Max = (SYS_SINT32_MAX);
BASE_API const NTypes::Tuint32 CConstants::uint32Min = (SYS_UINT32_MIN);
BASE_API const NTypes::Tuint32 CConstants::uint32Max = (SYS_UINT32_MAX);
BASE_API const NTypes::Tsint64 CConstants::sint64Min = (SYS_SINT64_MIN);
BASE_API const NTypes::Tsint64 CConstants::sint64Max = (SYS_SINT64_MAX);
BASE_API const NTypes::Tuint64 CConstants::uint64Min = (SYS_UINT64_MIN);
BASE_API const NTypes::Tuint64 CConstants::uint64Max = (SYS_UINT64_MAX);
/*--------------------------------------------------------------------------*/
#if defined(__DOUBLE__)
BASE_API const NTypes::Tbool CConstants::isRealFloat = false;
BASE_API const NTypes::Tbool CConstants::isRealDouble = true;
#else
BASE_API const NTypes::Tbool CConstants::isRealFloat = true;
BASE_API const NTypes::Tbool CConstants::isRealDouble = false;
#endif
/*--------------------------------------------------------------------------*/
BASE_API const NTypes::Tfloat CConstants::floatEps = (SYS_FLOAT_EPS);
BASE_API const NTypes::Tfloat CConstants::floatCompareEps = (SYS_FLOAT_COMPARE_EPS);
BASE_API const NTypes::Tfloat CConstants::floatMin = (SYS_FLOAT_MIN);
BASE_API const NTypes::Tfloat CConstants::floatMax = (SYS_FLOAT_MAX);
BASE_API const NTypes::Tsint  CConstants::floatPrec = (SYS_FLOAT_PREC);
BASE_API const NTypes::Tsint  CConstants::floatMant = (SYS_FLOAT_MANT);
BASE_API const NTypes::Tsint  CConstants::floatMinExp = (SYS_FLOAT_MINEXP);
BASE_API const NTypes::Tsint  CConstants::floatMaxExp = (SYS_FLOAT_MAXEXP);
BASE_API const NTypes::Tsint  CConstants::floatMin10Exp = (SYS_FLOAT_MIN10EXP);
BASE_API const NTypes::Tsint  CConstants::floatMax10Exp = (SYS_FLOAT_MAX10EXP);
/*--------------------------------------------------------------------------*/
BASE_API const NTypes::Tdouble CConstants::doubleEps = (SYS_DOUBLE_EPS);
BASE_API const NTypes::Tdouble CConstants::doubleCompareEps = (SYS_DOUBLE_COMPARE_EPS);
BASE_API const NTypes::Tdouble CConstants::doubleMin = (SYS_DOUBLE_MIN);
BASE_API const NTypes::Tdouble CConstants::doubleMax = (SYS_DOUBLE_MAX);
BASE_API const NTypes::Tsint   CConstants::doublePrec = (SYS_DOUBLE_PREC);
BASE_API const NTypes::Tsint   CConstants::doubleMant = (SYS_DOUBLE_MANT);
BASE_API const NTypes::Tsint   CConstants::doubleMinExp = (SYS_DOUBLE_MINEXP);
BASE_API const NTypes::Tsint   CConstants::doubleMaxExp = (SYS_DOUBLE_MAXEXP);
BASE_API const NTypes::Tsint   CConstants::doubleMin10Exp = (SYS_DOUBLE_MIN10EXP);
BASE_API const NTypes::Tsint   CConstants::doubleMax10Exp = (SYS_DOUBLE_MAX10EXP);
/*--------------------------------------------------------------------------*/
#if defined(__DOUBLE__)
BASE_API const NTypes::Treal CConstants::realEps = (SYS_DOUBLE_EPS);
BASE_API const NTypes::Treal CConstants::realCompareEps = (SYS_DOUBLE_COMPARE_EPS);
BASE_API const NTypes::Treal CConstants::realMin = (SYS_DOUBLE_MIN);
BASE_API const NTypes::Treal CConstants::realMax = (SYS_DOUBLE_MAX);
BASE_API const NTypes::Tsint CConstants::realPrec = (SYS_DOUBLE_PREC);
BASE_API const NTypes::Tsint CConstants::realMant = (SYS_DOUBLE_MANT);
BASE_API const NTypes::Tsint CConstants::realMinExp = (SYS_DOUBLE_MINEXP);
BASE_API const NTypes::Tsint CConstants::realMaxExp = (SYS_DOUBLE_MAXEXP);
BASE_API const NTypes::Tsint CConstants::realMin10Exp = (SYS_DOUBLE_MIN10EXP);
BASE_API const NTypes::Tsint CConstants::realMax10Exp = (SYS_DOUBLE_MAX10EXP);
#else
BASE_API const NTypes::Treal CConstants::realEps = (SYS_FLOAT_EPS);
BASE_API const NTypes::Treal CConstants::realCompareEps = (SYS_FLOAT_COMPARE_EPS);
BASE_API const NTypes::Treal CConstants::realMin = (SYS_FLOAT_MIN);
BASE_API const NTypes::Treal CConstants::realMax = (SYS_FLOAT_MAX);
BASE_API const NTypes::Tsint CConstants::realPrec = (SYS_FLOAT_PREC);
BASE_API const NTypes::Tsint CConstants::realMant = (SYS_FLOAT_MANT);
BASE_API const NTypes::Tsint CConstants::realMinExp = (SYS_FLOAT_MINEXP);
BASE_API const NTypes::Tsint CConstants::realMaxExp = (SYS_FLOAT_MAXEXP);
BASE_API const NTypes::Tsint CConstants::realMin10Exp = (SYS_FLOAT_MIN10EXP);
BASE_API const NTypes::Tsint CConstants::realMax10Exp = (SYS_FLOAT_MAX10EXP);
#endif
/*--------------------------------------------------------------------------*/
CConstants::CConstants()
{ CALL

}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
