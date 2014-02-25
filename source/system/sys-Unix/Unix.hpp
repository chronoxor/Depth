/*!
 *  \file    Unix.hpp Common definitions for Unix OS.
 *  \brief   Unix OS - common definitions.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unix OS - common definitions.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   26.08.2008 23:38:20

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
#ifndef __UNIX_HPP__
#define __UNIX_HPP__
/*==========================================================================*/
#if defined(__UNIX__)
/*==========================================================================*/
// Undefine Depth FILE macros.
#undef FILE
/*--------------------------------------------------------------------------*/
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <sys/time.h>
/*--------------------------------------------------------------------------*/
// Undefine FILE macros, which is defined in the 'stdio.h'.
#undef FILE
/*--------------------------------------------------------------------------*/
// Restore Depth FILE macros.
#define FILE STR(SYS_FILE)
/*--------------------------------------------------------------------------*/
// Define STDIO_FILE macros from the 'stdio.h'.
#define STDIO_FILE _IO_FILE
/*==========================================================================*/
#endif
#endif
