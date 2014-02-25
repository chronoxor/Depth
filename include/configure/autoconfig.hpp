/*!
 *  \file    autoconfig.hpp Contains preprocessor definitions for
 *           auto-configuration.
 *  \brief   Preprocessor definitions for auto-configuration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.12.2005
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Preprocessor definitions for auto-configuration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Configuration
    VERSION:   1.0
    CREATED:   28.12.2005 22:59:25

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
#ifndef __AUTOCONFIG_HPP__
#define __AUTOCONFIG_HPP__
/*==========================================================================*/
/* AUTO-CONFIGURATION                                                       */
/*==========================================================================*/
// Configure build type.
#if (!defined(__BUILD_APP__) && !defined(__BUILD_STATIC_LIB__) && !defined(__BUILD_SHARED_LIB__))
  //! Use build type as a default one.
  #define __BUILD_APP__
#endif
/*--------------------------------------------------------------------------*/
// Configure architecture.
#if (!defined(__I386__) && !defined(__I486__) && !defined(__I586__) && !defined(__I686__) && !defined(__X86_64__))
  #if ((defined(_M_IX86) && (_M_IX86 == 300)) || defined(__i386))
    //! Intel 386 processor architecture (32 bit).
    #define __I386__
  #elif (defined(_M_IX86) && (_M_IX86 == 400))
    //! Intel 486 processor architecture (32 bit).
    #define __I486__
  #elif (defined(_M_IX86) && (_M_IX86 == 500))
    //! Intel 586 processor architecture (32 bit).
    #define __I586__
  #elif (defined(_M_IX86) && (_M_IX86 == 600))
    //! Intel 686 processor architecture (32 bit).
    #define __I686__
  #elif (defined(_M_X64) || defined(__x86_64__))
    //! AMD64 & EM64T processor architectures (64 bit).
    #define __X86_64__
  #elif (defined(ARM) || defined(_ARM_))
    //! ARM processor architectures (32 bit).
    #define __ARM__
  #else
    //! Unknown architecture.
    #error "Unknown architecture!"
  #endif
#endif
/*--------------------------------------------------------------------------*/
// Configure compiler.
#if (!defined(__GCC__) && !defined(__VISUALCPP__))
  #if defined(__GNUC__)
    //! GNU C++.
    #define __GCC__
  #elif defined(_MSC_VER)
    //! Microsoft Visual C++.
    #define __VISUALCPP__
  #else
    //! Unknown compiler.
    #error "Unknown compiler!"
  #endif
#endif
/*--------------------------------------------------------------------------*/
// Configure OS.
#if (!defined(__DUMMY__) && !defined(__CYGWIN__) && !defined(__LINUX__) && !defined(__UNIX__) && !defined(__WINDOWS__))
  #if (defined(__CYGWIN32__))
    //! Cygwin.
    #define __CYGWIN__
  #elif (defined(linux) || defined(__linux) || defined(__linux__))
    //! Linux.
    #define __LINUX__
  #elif (defined(_WIN32_WCE) || defined(WINCE))
    //! Windows Mobile.
    #define __WINDOWS_MOBILE__
  #elif (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
    //! Windows.
    #define __WINDOWS__
  #else
    //! Unknown OS.
    #error "Unknown OS!"
  #endif
#endif
/*--------------------------------------------------------------------------*/
// Configure external libraries.
#if (!defined(__NONLIB__) && !defined(__I386FPU__) && (defined(__I386__) || defined(__I486__) || defined(__I586__) && defined(__I686__)))
  //! Use Intel 386 FPU math library.
  #define __I386FPU__
#endif
/*==========================================================================*/
/* CONFIGURATION VALIDATING                                                 */
/*==========================================================================*/
// Check build type definitions.
#if (defined(__BUILD_APP__) && defined(__BUILD_STATIC_LIB__) && defined(__BUILD_SHARED_LIB__))
  #error "Only one build type definition is allowed!"
#endif
/*--------------------------------------------------------------------------*/
// Check application type definitions.
#if (defined(__CONSOLE__) && defined(__NATIVE__))
  #error "Only one application type definition is allowed!"
#endif
/*--------------------------------------------------------------------------*/
// Check library linking definitions.
#if (defined(__LIB__) && defined(__DLL__))
  #error "Only one library linking definition is allowed!"
#endif
/*--------------------------------------------------------------------------*/
// Check compilation mode definitions.
#if (defined(__DEBUG__) && defined(__RELEASE__))
  #error "Only one compilation mode definition is allowed!"
#endif
/*--------------------------------------------------------------------------*/
// Check byte order definitions.
#if (defined(__BIG_ENDIAN__) && defined(__LITTLE_ENDIAN__))
  #error "Only one byte order definition is allowed!"
#endif
/*--------------------------------------------------------------------------*/
// Check real number type definitions.
#if (defined(__FLOAT__) && defined(__DOUBLE__))
  #error "Only one real number type definition is allowed!"
#endif
/*--------------------------------------------------------------------------*/
// Check string encoding definitions.
#if (defined(__ASCII__) && defined(__UNICODE__))
  #error "Only one string encoding definition is allowed!"
#endif
/*--------------------------------------------------------------------------*/
// Check line ending definitions.
#if (defined(__WINDOWS_LINE_END__) && defined(__UNIX_LINE_END__))
  #error "Only one line ending definition is allowed!"
#endif
/*==========================================================================*/
#endif
