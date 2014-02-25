/*!
 *  \file    type-constants.hpp Contains type constants configuration.
 *  \brief   Type constants configuration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Type constants configuration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Configuration - types
    VERSION:   1.0
    CREATED:   03.06.2008 20:59:45

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
#ifndef __TYPE_CONSTANTS_HPP__
#define __TYPE_CONSTANTS_HPP__
/*==========================================================================*/
/* TYPES CONSTANTS                                                          */
/*==========================================================================*/
#if defined(__SCHAR_S_ASCII__)
  //! Minimal character value.
  #define SYS_SCHAR_MIN        (-0x7F-1)
  //! Maximal character value.
  #define SYS_SCHAR_MAX        (+0x7F)
#elif defined(__SCHAR_U_ASCII__)
  //! Minimal character value.
  #define SYS_SCHAR_MIN        (+0x00u)
  //! Maximal character value.
  #define SYS_SCHAR_MAX        (+0xFFu)
#else
  //! Unknown character encoding.
  #error "Unknown character encoding!"
#endif
/*--------------------------------------------------------------------------*/
//! Absolute minimal character value.
#define SYS_SCHAR_ABSMIN       (+0x00u)
//! Absolute maximal character value.
#define SYS_SCHAR_ABSMAX       (+0xFFu)
/*--------------------------------------------------------------------------*/
#if defined(__WCHAR_S_UCS2__)
  //! Minimal wide character value.
  #define SYS_WCHAR_MIN        (-0x7FFF-1)
  //! Maximal wide character value.
  #define SYS_WCHAR_MAX        (+0x7FFF)
#elif defined(__WCHAR_S_UCS4__)
  //! Minimal wide character value.
  #define SYS_WCHAR_MIN        (-0x7FFFFFFF-1)
  //! Maximal wide character value.
  #define SYS_WCHAR_MAX        (+0x7FFFFFFF)
#elif defined(__WCHAR_U_UCS2__)
  //! Minimal wide character value.
  #define SYS_WCHAR_MIN        (+0x0000u)
  //! Maximal wide character value.
  #define SYS_WCHAR_MAX        (+0xFFFFu)
#elif defined(__WCHAR_U_UCS4__)
  //! Minimal wide character value.
  #define SYS_WCHAR_MIN        (+0x00000000u)
  //! Maximal wide character value.
  #define SYS_WCHAR_MAX        (+0xFFFFFFFFu)
#else
  //! Unknown wide character encoding.
  #error "Unknown wide character encoding!"
#endif
/*--------------------------------------------------------------------------*/
#if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
  //! Absolute minimal wide character value.
  #define SYS_WCHAR_ABSMIN     (+0x0000u)
  //! Absolute maximal wide character value.
  #define SYS_WCHAR_ABSMAX     (+0xFFFFu)
#elif (defined(__WCHAR_S_UCS4__) || defined(__WCHAR_U_UCS4__))
  //! Absolute minimal wide character value.
  #define SYS_WCHAR_ABSMIN     (+0x00000000u)
  //! Absolute maximal wide character value.
  #define SYS_WCHAR_ABSMAX     (+0xFFFFFFFFu)
#else
  //! Unknown wide character encoding.
  #error "Unknown wide character encoding!"
#endif
/*--------------------------------------------------------------------------*/
#if defined(__UNICODE__)
  //! Is system character ASCII?
  #define SYS_CHAR_IS_ASCII    (false)
  //! Is system character Unicode?
  #define SYS_CHAR_IS_UNICODE  (true)
  //! Minimal system character value.
  #define SYS_CHAR_MIN         SYS_WCHAR_MIN
  //! Maximal system character value.
  #define SYS_CHAR_MAX         SYS_WCHAR_MAX
  //! Absolute minimal system character value.
  #define SYS_CHAR_ABSMIN      SYS_WCHAR_ABSMIN
  //! Absolute maximal system character value.
  #define SYS_CHAR_ABSMAX      SYS_WCHAR_ABSMAX
#else
  //! Is system character ASCII?
  #define SYS_CHAR_IS_ASCII    (true)
  //! Is system character Unicode?
  #define SYS_CHAR_IS_UNICODE  (false)
  //! Minimal system character value.
  #define SYS_CHAR_MIN         SYS_SCHAR_MIN
  //! Maximal system character value.
  #define SYS_CHAR_MAX         SYS_SCHAR_MAX
  //! Absolute minimal system character value.
  #define SYS_CHAR_ABSMIN      SYS_SCHAR_ABSMIN
  //! Absolute maximal system character value.
  #define SYS_CHAR_ABSMAX      SYS_SCHAR_ABSMAX
#endif
/*--------------------------------------------------------------------------*/
//! Float epsilon value.
#define SYS_FLOAT_EPS          (+1.192092896e-07f)
//! Float compare epsilon value.
#define SYS_FLOAT_COMPARE_EPS  (+0.000001f)
//! Minimal float value.
#define SYS_FLOAT_MIN          (+1.175494351e-38f)
//! Maximal float value.
#define SYS_FLOAT_MAX          (+3.402823466e+38f)
//! Float precision value.
#define SYS_FLOAT_PREC         (+6)
//! Float mantissa value.
#define SYS_FLOAT_MANT         (+24)
//! Float minimal exponent value.
#define SYS_FLOAT_MINEXP       (-125)
//! Float maximal exponent value.
#define SYS_FLOAT_MAXEXP       (+128)
//! Float minimal 10 exponent value.
#define SYS_FLOAT_MIN10EXP     (-37)
//! Float maximal 10 exponent value.
#define SYS_FLOAT_MAX10EXP     (+38)
/*--------------------------------------------------------------------------*/
//! Double epsilon value.
#define SYS_DOUBLE_EPS         (+2.2204460492503131e-016)
//! Double compare epsilon value.
#define SYS_DOUBLE_COMPARE_EPS (+0.00000000001)
//! Minimal double value.
#define SYS_DOUBLE_MIN         (+2.2250738585072014e-308)
//! Maximal double value.
#define SYS_DOUBLE_MAX         (+1.7976931348623158e+308)
//! Double precision value.
#define SYS_DOUBLE_PREC        (+15)
//! Double mantissa value.
#define SYS_DOUBLE_MANT        (+53)
//! Double minimal exponent value.
#define SYS_DOUBLE_MINEXP      (-1021)
//! Double maximal exponent value.
#define SYS_DOUBLE_MAXEXP      (+1024)
//! Double minimal 10 exponent value.
#define SYS_DOUBLE_MIN10EXP    (-307)
//! Double maximal 10 exponent value.
#define SYS_DOUBLE_MAX10EXP    (+308)
/*--------------------------------------------------------------------------*/
#if (SYS_PLATFORM_BITS == 32)
  //! Minimal pointer value of the 32 bit architecture.
  #define SYS_PTR_MIN          (+0x00000000u)
  //! Maximal pointer value of the 32 bit architecture.
  #define SYS_PTR_MAX          (+0xFFFFFFFFu)
  //! Minimal signed integer value of the 32 bit architecture.
  #define SYS_SINT_MIN         (-0x7FFFFFFF-1)
  //! Maximal signed integer value of the 32 bit architecture.
  #define SYS_SINT_MAX         (+0x7FFFFFFF)
  //! Minimal unsigned integer value of the 32 bit architecture.
  #define SYS_UINT_MIN         (+0x00000000u)
  //! Maximal unsigned integer value of the 32 bit architecture.
  #define SYS_UINT_MAX         (+0xFFFFFFFFu)
#elif (SYS_PLATFORM_BITS == 64)
  //! Minimal pointer value of the 64 bit architecture.
  #define SYS_PTR_MIN          (+0x0000000000000000ull)
  //! Maximal pointer value of the 64 bit architecture.
  #define SYS_PTR_MAX          (+0xFFFFFFFFFFFFFFFFull)
  //! Minimal signed integer value of the 64 bit architecture.
  #define SYS_SINT_MIN         (-0x7FFFFFFFFFFFFFFFll-1)
  //! Maximal signed integer value of the 64 bit architecture.
  #define SYS_SINT_MAX         (+0x7FFFFFFFFFFFFFFFll)
  //! Minimal unsigned integer value of the 64 bit architecture.
  #define SYS_UINT_MIN         (+0x0000000000000000ull)
  //! Maximal unsigned integer value of the 64 bit architecture.
  #define SYS_UINT_MAX         (+0xFFFFFFFFFFFFFFFFull)
#else
  //! Unknown platform bits count.
  #error "Unknown platform bits count!"
#endif
/*--------------------------------------------------------------------------*/
//! Minimal signed byte value.
#define SYS_SINT08_MIN         (-0x7F-1)
//! Maximal signed byte value.
#define SYS_SINT08_MAX         (+0x7F)
/*--------------------------------------------------------------------------*/
//! Minimal signed word value.
#define SYS_SINT16_MIN         (-0x7FFF-1)
//! Maximal signed word value.
#define SYS_SINT16_MAX         (+0x7FFF)
/*--------------------------------------------------------------------------*/
//! Minimal signed double word value.
#define SYS_SINT32_MIN         (-0x7FFFFFFF-1)
//! Maximal signed double word value.
#define SYS_SINT32_MAX         (+0x7FFFFFFF)
/*--------------------------------------------------------------------------*/
//! Minimal signed quadra word value.
#define SYS_SINT64_MIN         (-0x7FFFFFFFFFFFFFFFll-1)
//! Maximal signed quadra word value.
#define SYS_SINT64_MAX         (+0x7FFFFFFFFFFFFFFFll)
/*--------------------------------------------------------------------------*/
//! Minimal unsigned byte value.
#define SYS_UINT08_MIN         (+0x00u)
//! Maximal unsigned byte value.
#define SYS_UINT08_MAX         (+0xFFu)
/*--------------------------------------------------------------------------*/
//! Minimal unsigned word value.
#define SYS_UINT16_MIN         (+0x0000u)
//! Maximal unsigned word value.
#define SYS_UINT16_MAX         (+0xFFFFu)
/*--------------------------------------------------------------------------*/
//! Minimal unsigned double word value.
#define SYS_UINT32_MIN         (+0x00000000u)
//! Maximal unsigned double word value.
#define SYS_UINT32_MAX         (+0xFFFFFFFFu)
/*--------------------------------------------------------------------------*/
//! Minimal unsigned quadra word value.
#define SYS_UINT64_MIN         (+0x0000000000000000ull)
//! Maximal unsigned quadra word value.
#define SYS_UINT64_MAX         (+0xFFFFFFFFFFFFFFFFull)
/*==========================================================================*/
/* TYPES CONVERTING MACROS                                                  */
/*==========================================================================*/
/*!
    \def CONSTS08
    Defines 1 byte signed integer number constant.
*/
#define CONSTS08(x) (NDepth::NTypes::Tsint08(x))
/*--------------------------------------------------------------------------*/
/*!
    \def CONSTU08
    Defines 1 byte unsigned integer number constant.
*/
#define CONSTU08(x) (NDepth::NTypes::Tuint08(x ## u))
/*--------------------------------------------------------------------------*/
/*!
    \def CONSTS16
    Defines 2 bytes signed integer number constant.
*/
#define CONSTS16(x) (NDepth::NTypes::Tsint16(x))
/*--------------------------------------------------------------------------*/
/*!
    \def CONSTU16
    Defines 2 bytes unsigned integer number constant.
*/
#define CONSTU16(x) (NDepth::NTypes::Tuint16(x ## u))
/*--------------------------------------------------------------------------*/
/*!
    \def CONSTS32
    Defines 4 bytes signed integer number constant.
*/
#define CONSTS32(x) (NDepth::NTypes::Tsint32(x))
/*--------------------------------------------------------------------------*/
/*!
    \def CONSTU32
    Defines 4 bytes unsigned integer number constant.
*/
#define CONSTU32(x) (NDepth::NTypes::Tuint32(x ## u))
/*--------------------------------------------------------------------------*/
/*!
    \def CONSTS64
    Defines 8 bytes signed integer number constant.
*/
#define CONSTS64(x) (NDepth::NTypes::Tsint64(x ## ll))
/*--------------------------------------------------------------------------*/
/*!
    \def CONSTU64
    Defines 8 bytes unsigned integer number constant.
*/
#define CONSTU64(x) (NDepth::NTypes::Tuint64(x ## ull))
/*--------------------------------------------------------------------------*/
/*!
    \def CONSTS
    Defines signed integer number constant.
*/
#if ((SYS_PLATFORM_BITS == 32) || defined(__DOXYGEN__))
  #define CONSTS(x) (NDepth::NTypes::Tsint(x))
#elif (SYS_PLATFORM_BITS == 64)
  #define CONSTS(x) (NDepth::NTypes::Tsint(x ## ll))
#else
  //! Unknown platform bits count.
  #error "Unknown platform bits count!"
#endif
/*--------------------------------------------------------------------------*/
/*!
    \def CONSTU
    Defines unsigned integer number constant.
*/
#if ((SYS_PLATFORM_BITS == 32) || defined(__DOXYGEN__))
  #define CONSTU(x) (NDepth::NTypes::Tuint(x ## u))
#elif (SYS_PLATFORM_BITS == 64)
  #define CONSTU(x) (NDepth::NTypes::Tuint(x ## ull))
#else
  //! Unknown platform bits count.
  #error "Unknown platform bits count!"
#endif
/*--------------------------------------------------------------------------*/
/*!
    \def CONSTF
    Defines float number constant.
*/
#define CONSTF(x) (NDepth::NTypes::Tfloat(x ## f))
/*--------------------------------------------------------------------------*/
/*!
    \def CONSTD
    Defines double number constant.
*/
#define CONSTD(x) (NDepth::NTypes::Tdouble(x))
/*--------------------------------------------------------------------------*/
/*!
    \def CONSTR
    Defines real number constant.
*/
#define CONSTR(x) (NDepth::NTypes::Treal(x))
/*==========================================================================*/
#endif
