/*!
 *  \file    Windows.hpp Common definitions for Windows OS.
 *  \brief   Windows OS - common definitions.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.05.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Windows OS - common definitions.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   02.05.2008 23:26:48

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
/*==========================================================================*/
#ifndef __WINDOWS_HPP__
#define __WINDOWS_HPP__
/*==========================================================================*/
#if (defined(__WINDOWS__) || defined(__CYGWIN__))
/*==========================================================================*/
// Undefine Depth DATE macros.
#undef DATE
// Undefine Depth ERROR macros.
#undef ERROR
// Undefine Depth ASSERT macros.
#undef ASSERT
// Undefine Depth VERIFY macros.
#undef VERIFY
/*--------------------------------------------------------------------------*/
// Define _WIN32_WINNT if it is not defined.
#if (!defined(__WINDOWS_MOBILE__) && !defined(_WIN32_WINNT))
  #define _WIN32_WINNT _WIN32_WINNT_LONGHORN
#endif
/*--------------------------------------------------------------------------*/
// Define NOMINMAX in order to prevent appearance of the min(), max() macros.
#ifndef NOMINMAX
  #define NOMINMAX
#endif
/*--------------------------------------------------------------------------*/
#if (defined(__WINDOWS_MOBILE__))
  #undef __WINDOWS__
  #include <windows.h>
  #define __WINDOWS__
#else
  #include <windows.h>
#endif
/*--------------------------------------------------------------------------*/
// Undefine DATE macros, which is defined in the 'wtypes.h'.
#undef DATE
// Undefine ERROR macros, which is defined in the 'wingdi.h'.
#undef ERROR
// Undefine ASSERT macros, which is defined in the 'dbgapi.h'.
#undef ASSERT
// Undefine VERIFY macros, which is defined in the 'dbgapi.h'.
#undef VERIFY
/*--------------------------------------------------------------------------*/
// Restore Depth DATE macros.
#define DATE STR(SYS_DATE)
// Restore Depth ERROR macros.
#define ERROR NDepth::NErrors::NDetails::error(FUNCTION_SIGNATURE, FILE, LINE, message);
// Restore Depth ASSERT macros.
#define ASSERT(condition, message) if (!(condition) && !NDepth::NErrors::NDetails::assert(FUNCTION_SIGNATURE, FILE, LINE, false, STR(STRINGIZE(condition)), message))
// Restore Depth VERIFY macros.
#define VERIFY(condition, message) if (!(condition)) NDepth::NErrors::NDetails::verify(FUNCTION_SIGNATURE, FILE, LINE, false, STR(STRINGIZE(condition)), message)
/*==========================================================================*/

/*==========================================================================*/
#endif
#endif
