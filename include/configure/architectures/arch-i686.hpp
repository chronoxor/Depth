/*!
 *  \file    arch-i686.hpp Contains Intel 686 processor architecture (32 bit)
 *           configuration.
 *  \brief   Intel 686 processor architecture (32 bit) configuration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.12.2005
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Intel 686 processor architecture (32 bit) configuration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Configuration - architecture
    VERSION:   1.0
    CREATED:   28.12.2005 23:47:37

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
#ifndef __ARCH_I686_HPP__
#define __ARCH_I686_HPP__
/*==========================================================================*/
#if defined(__I686__)
/*==========================================================================*/
/* ARCHITECTURE CONFIGURATIONS                                              */
/*==========================================================================*/
// Configure byte endians.
#if (!defined(__BIG_ENDIAN__) && !defined(__LITTLE_ENDIAN__))
  //! Intel x86 processors use little-endian byte order.
  #define __LITTLE_ENDIAN__
#endif
/*--------------------------------------------------------------------------*/
//! Platform bits value.
#define SYS_PLATFORM_BITS 32
//! Platform maximal bits value.
#define SYS_PLATFORM_MAX_BITS 64
/*==========================================================================*/
#endif
#endif
