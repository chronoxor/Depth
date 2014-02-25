/*!
 *  \file    configure.hpp Contains all architecture, compiler, OS and library
 *           dependant properties such as data types, memory configuration,
 *           byte order, etc.
 *  \brief   System dependant configuration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.12.2005
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: System dependant configuration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Configuration
    VERSION:   1.0
    CREATED:   28.12.2005 22:55:32

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
#ifndef __CONFIGURE_HPP__
#define __CONFIGURE_HPP__
/*==========================================================================*/
/* AVAILABLE DEFINES                                                        */
/*==========================================================================*/
/* ARCHITECTURE FLAGS:                                                      */
/* __ARM__               - Acorn RISC Machine architecture (32 bit).        */
/* __I386__              - Intel 386 processor architecture (32 bit).       */
/* __I486__              - Intel 486 processor architecture (32 bit).       */
/* __I586__              - Intel 586 processor architecture (32 bit).       */
/* __I686__              - Intel 686 processor architecture (32 bit).       */
/* __X86_64__            - AMD64 & EM64T processor architectures (64 bit)   */
/*                                                                          */
/* __BIG_ENDIAN__        - Use big-endian byte order.                       */
/* __LITTLE_ENDIAN__     - Use little-endian byte order.                    */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* COMPILER FLAGS:                                                          */
/* __GCC__               - GNU C++ compiler.                                */
/* __VISUALCPP__         - Microsoft Visual C++ compiler.                   */
/*                                                                          */
/* __DEBUG__             - Use debug compilation mode.                      */
/* __RELEASE__           - Use release compilation mode.                    */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* OS FLAGS:                                                                */
/* __DUMMY__             - Main define for Dummy OS support.                */
/* __CYGWIN__            - Main define for Cygwin OS support.               */
/* __LINUX__             - Main define for Linux OS support.                */
/* __UNIX__              - Main define for Unix OS support.                 */
/* __WINDOWS__           - Main define for Windows OS support.              */
/* __WINDOWS_MOBILE__    - Main define for Windows Mobile OS support.       */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* DEPTH BUILD FLAGS:                                                       */
/* __BUILD_APP__         - Current build is an application one.             */
/* __BUILD_STATIC_LIB__  - Current build is a static library one.           */
/* __BUILD_SHARED_LIB__  - Current build is a shared library one.           */
/*--------------------------------------------------------------------------*/
/* DEPTH APPLICATION FLAGS:                                                 */
/* __CONSOLE__           - Use and compile console application.             */
/* __NATIVE__            - Use and compile native application.              */
/*--------------------------------------------------------------------------*/
/* DEPTH LIBRARY FLAGS:                                                     */
/* __LIB__               - Use and compile static linking libraries.        */
/* __DLL__               - Use and compile dynamic linking libraries.       */
/* __DLL_EXPORT__        - Use __declspec(dllexport) calling convenience.   */
/* __DLL_IMPORT__        - Use __declspec(dllimport) calling convenience.   */
/* __FLOAT__             - Use float as a real.                             */
/* __DOUBLE__            - Use double as a real.                            */
/* __ASCII__             - Use ASCII as a string encoding.                  */
/* __UNICODE__           - Use Unicode as a string encoding.                */
/* __WINDOWS_LINE_END__  - Use Windows line ending.                         */
/* __UNIX_LINE_END__     - Use Unix line ending.                            */
/* __UNDERLINE__         - Use _foo as foo name (C prefix).                 */
/*                                                                          */
/* __SCHAR_S_ASCII__     - Character is signed byte in ASCII encoding.      */
/* __SCHAR_U_ASCII__     - Character is unsigned byte in ASCII encoding     */
/* __WCHAR_S_UCS2__      - Character is signed word in UCS-2 encoding.      */
/* __WCHAR_U_UCS2__      - Character is unsigned word in UCS-2 encoding.    */
/* __WCHAR_S_UCS4__      - Character is signed dword in UCS-4 encoding.     */
/* __WCHAR_U_UCS4__      - Character is unsigned dword in UCS-4 encoding.   */
/*                                                                          */
/* __SYSENC_UTF8__       - System UTF encoding is UTF-8.                    */
/* __SYSENC_UTF16BE__    - System UTF encoding is UTF-16 (Big-Endian).      */
/* __SYSENC_UTF16LE__    - System UTF encoding is UTF-16 (Little-Endian).   */
/* __SYSENC_UTF32BE__    - System UTF encoding is UTF-32 (Big-Endian).      */
/* __SYSENC_UTF32LE__    - System UTF encoding is UTF-32 (Little-Endian).   */
/*                                                                          */
/* __DEPTH_THIRD_PARTY__ - Use Depth library as a third-party one.          */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* EXTERNAL LIBRARIES FLAGS:                                                */
/* __NONLIB__            - Non external library support.                    */
/* __I386FPU__           - Intel 386 FPU math library support.              */
/*                                                                          */
/*==========================================================================*/
/* CONFIGURATIONS                                                           */
/*==========================================================================*/
#include <Depth/include/configure/autoconfig.hpp>
#include <Depth/include/configure/architectures.hpp>
#include <Depth/include/configure/compilers.hpp>
#include <Depth/include/configure/systems.hpp>
#include <Depth/include/configure/type.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/configure/libraries.hpp>
/*==========================================================================*/
#endif
