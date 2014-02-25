/*!
 *  \file    OS-WindowsMobile.hpp Contains Windows Mobile OS configuration.
 *  \brief   Windows Mobile OS configuration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Windows Mobile OS configuration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Configuration - OS
    VERSION:   1.0
    CREATED:   31.07.2008 20:02:46

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
#ifndef __OS_WINDOWSMOBILE_HPP__
#define __OS_WINDOWSMOBILE_HPP__
/*==========================================================================*/
#if defined(__WINDOWS_MOBILE__)
/*==========================================================================*/
/* OS CONFIGURATIONS                                                        */
/*==========================================================================*/
//! Inherit all Windows defines.
#define __WINDOWS__
/*--------------------------------------------------------------------------*/
#include <Depth/include/configure/systems/OS-Windows.hpp>
/*==========================================================================*/
#endif
#endif
