/*!
 *  \file    types.hpp Contains base data types definitions for the Depth
 *           project.
 *  \brief   Types definitions.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Types definitions.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Types definitions
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
#ifndef __TYPES_HPP__
#define __TYPES_HPP__
/*==========================================================================*/
#include <Depth/include/configure.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTypes {
/*==========================================================================*/
/* TYPES DECLARATIONS                                                       */
/*==========================================================================*/
typedef NConfigure::NDetails::Tsys_bool    Tbool;   //!< Boolean type.
/*--------------------------------------------------------------------------*/
typedef NConfigure::NDetails::Tsys_schar   Tschar;  //!< ASCII character.
typedef NConfigure::NDetails::Tsys_wchar   Twchar;  //!< Unicode character.
typedef NConfigure::NDetails::Tsys_scharu  Tscharu; //!< ASCII unsigned character (only for singed/unsigned conversions).
typedef NConfigure::NDetails::Tsys_wcharu  Twcharu; //!< Unicode unsigned character (only for singed/unsigned conversions).
/*--------------------------------------------------------------------------*/
#ifndef __UNICODE__
typedef NConfigure::NDetails::Tsys_schar   Tchar;   //!< System character (ASCII).
typedef NConfigure::NDetails::Tsys_scharu  Tcharu;  //!< System unsigned character (ASCII) (only for singed/unsigned conversions).
#else
typedef NConfigure::NDetails::Tsys_wchar   Tchar;   //!< System character (Unicode).
typedef NConfigure::NDetails::Tsys_wcharu  Tcharu;  //!< System unsigned character (Unicode) (only for singed/unsigned conversions).
#endif
/*--------------------------------------------------------------------------*/
typedef NConfigure::NDetails::Tsys_sint    Tsint;   //!< Signed integer number.
typedef NConfigure::NDetails::Tsys_uint    Tuint;   //!< Unsigned integer number.
typedef NConfigure::NDetails::Tsys_sint08  Tsint08; //!< Signed integer number: 8-bit.
typedef NConfigure::NDetails::Tsys_sint16  Tsint16; //!< Signed integer number: 16-bit.
typedef NConfigure::NDetails::Tsys_sint32  Tsint32; //!< Signed integer number: 32-bit.
typedef NConfigure::NDetails::Tsys_sint64  Tsint64; //!< Signed integer number: 64-bit.
typedef NConfigure::NDetails::Tsys_uint08  Tuint08; //!< Unsigned integer number: 8-bit.
typedef NConfigure::NDetails::Tsys_uint16  Tuint16; //!< Unsigned integer number: 16-bit.
typedef NConfigure::NDetails::Tsys_uint32  Tuint32; //!< Unsigned integer number: 32-bit.
typedef NConfigure::NDetails::Tsys_uint64  Tuint64; //!< Unsigned integer number: 64-bit.
typedef NConfigure::NDetails::Tsys_float   Tfloat;  //!< Real number: single accuracy 16-bit.
typedef NConfigure::NDetails::Tsys_double  Tdouble; //!< Real number: double accuracy 32-bit.
/*--------------------------------------------------------------------------*/
#ifndef __DOUBLE__
typedef NConfigure::NDetails::Tsys_float  Treal;    //!< System real number (single accuracy).
#else
typedef NConfigure::NDetails::Tsys_double Treal;    //!< System real number (double accuracy).
#endif
/*--------------------------------------------------------------------------*/
typedef void*          Tptr;                        //!< Pointer type.
typedef const void*    Tcptr;                       //!< Pointer to the constant type.
/*--------------------------------------------------------------------------*/
typedef Tuint08        Tbyte;                       //!< Single byte type.
typedef Tbyte*         Tbuffer;                     //!< Pointer to the bytes buffer.
typedef const Tbyte*   Tcbuffer;                    //!< Pointer to the constant bytes buffer.
/*--------------------------------------------------------------------------*/
typedef Tchar*         Tstr;                        //!< Pointer to the 'C' string.
typedef Tschar*        Tsstr;                       //!< Pointer to the ASCII 'C' string.
typedef Twchar*        Twstr;                       //!< Pointer to the Unicode 'C' string.
typedef const Tchar*   Tcstr;                       //!< Pointer to the constant 'C' string.
typedef const Tschar*  Tcsstr;                      //!< Pointer to the constant ASCII 'C' string.
typedef const Twchar*  Tcwstr;                      //!< Pointer to the constant Unicode 'C' string.
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
