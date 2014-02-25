/*!
 *  \file    comp-GCC.hpp Contains GCC compiler configuration.
 *  \brief   GCC compiler configuration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.12.2005
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: GCC compiler configuration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Configuration - compilers
    VERSION:   1.0
    CREATED:   28.12.2005 00:46:02

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
#ifndef __COMP_GCC_HPP__
#define __COMP_GCC_HPP__
/*==========================================================================*/
#if defined(__GCC__)
/*==========================================================================*/
/* COMPILER INCLUDES                                                        */
/*==========================================================================*/
#include <cstdarg>
#include <cstddef>
#include <typeinfo>
/*==========================================================================*/
/* COMPILER CONFIGURATIONS                                                  */
/*==========================================================================*/
// Configure default compilation mode as release.
#if (!defined(__DEBUG__) && !defined(__RELEASE__))
  //! Use release compilation mode.
  #define __RELEASE__
#endif
/*--------------------------------------------------------------------------*/
// Configure Cygwin and MinGW compilers to use __declspec(dllexport) calling convenience.
#if defined(__WINDOWS__)
  //! Use __declspec(dllexport) calling convenience.
  #define __DLL_EXPORT__
#endif
/*==========================================================================*/
/* COMPILER FEATURES                                                        */
/*==========================================================================*/
//! Support for the Cnull class.
#define SYS_SUPPORT_CNULL
/*==========================================================================*/
/* COMPILER MACROS                                                          */
/*==========================================================================*/
/*!
    \def SYS_ALIGN
    Defines structure align attribute.
*/
#define SYS_ALIGN(value) __attribute__((aligned(value)))
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_ALIGNOF
    Defines structure align value.
*/
#define SYS_ALIGNOF(structure) __alignof__(structure)
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_FILE
    Defines the current file name.
*/
#define SYS_FILE __FILE__
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_LINE
    Defines the current file line number.
*/
#define SYS_LINE __LINE__
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_DATE
    Defines the current date.
*/
#define SYS_DATE __DATE__
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_TIME
    Defines the current time.
*/
#define SYS_TIME __TIME__
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_FUNCTION_NAME
    Defines the current function name.
*/
#define SYS_FUNCTION_NAME __FUNCTION__
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_FUNCTION_SIGNATURE
    Defines the current function signature name.
*/
#define SYS_FUNCTION_SIGNATURE __PRETTY_FUNCTION__
/*==========================================================================*/
#endif
#endif
