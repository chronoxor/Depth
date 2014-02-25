/*!
 *  \file    Cygwin.hpp Common definitions for Cygwin OS.
 *  \brief   Cygwin OS - common definitions.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Cygwin OS - common definitions.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   26.08.2008 23:14:23

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
#ifndef __CYGWIN_HPP__
#define __CYGWIN_HPP__
/*==========================================================================*/
#if (defined(__UNIX__) && defined(__CYGWIN__))
/*==========================================================================*/
#include "../sys-Unix/Unix.hpp"
/*==========================================================================*/
// Undefine STDIO_FILE macros, which is defined in the 'Unix.hpp'.
#undef STDIO_FILE
/*--------------------------------------------------------------------------*/
// Define STDIO_FILE macros from the 'stdio.h'.
#define STDIO_FILE __FILE
/*==========================================================================*/
#endif
#endif
