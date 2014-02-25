/*!
 *  \file    type-common.hpp Contains common type configuration.
 *  \brief   Common type configuration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Common type configuration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Configuration - types
    VERSION:   1.0
    CREATED:   03.06.2008 20:53:05

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
#ifndef __TYPE_COMMON_HPP__
#define __TYPE_COMMON_HPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConfigure {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* TYPES DECLARATIONS                                                       */
/*==========================================================================*/
typedef bool                 Tsys_bool;   //!< Define system type - boolean.
typedef char                 Tsys_schar;  //!< Define system type - character.
typedef wchar_t              Tsys_wchar;  //!< Define system type - wide character.
typedef float                Tsys_float;  //!< Define system type - float number.
typedef double               Tsys_double; //!< Define system type - double number.
typedef signed char          Tsys_sint08; //!< Define system type - signed byte.
typedef signed short         Tsys_sint16; //!< Define system type - signed word.
typedef signed int           Tsys_sint32; //!< Define system type - signed double word.
typedef signed long long     Tsys_sint64; //!< Define system type - signed quadra word.
typedef unsigned char        Tsys_uint08; //!< Define system type - unsigned byte.
typedef unsigned short       Tsys_uint16; //!< Define system type - unsigned word.
typedef unsigned int         Tsys_uint32; //!< Define system type - unsigned double word.
typedef unsigned long long   Tsys_uint64; //!< Define system type - unsigned quadra word.
/*--------------------------------------------------------------------------*/
#if (SYS_PLATFORM_BITS == 32)
  typedef signed int         Tsys_sint;   //!< Define system type - signed integer.
  typedef unsigned int       Tsys_uint;   //!< Define system type - unsigned integer.
#elif (SYS_PLATFORM_BITS == 64)
  typedef signed long long   Tsys_sint;   //!< Define system type - signed integer.
  typedef unsigned long long Tsys_uint;   //!< Define system type - unsigned integer.
#else
  //! Unknown platform bits count.
  #error "Unknown platform bits count!"
#endif
/*--------------------------------------------------------------------------*/
#if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_U_UCS2__))
  typedef unsigned char      Tsys_scharu; //!< Define system type - unsigned character.
  typedef unsigned short     Tsys_wcharu; //!< Define system type - unsigned wide character.
#elif (defined(__WCHAR_S_UCS4__) || defined(__WCHAR_U_UCS4__))
  typedef unsigned char      Tsys_scharu; //!< Define system type - unsigned character.
  typedef unsigned int       Tsys_wcharu; //!< Define system type - unsigned wide character.
#else
  //! Unknown unsigned character type.
  #error "Unknown wide character type!"
#endif
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
