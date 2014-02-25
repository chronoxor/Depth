/*!
 *  \file    unit-test.hpp Common unit test definitions for the CMake
 *           unit test launcher class and the CMake/CTest environment.
 *  \brief   Common CMake unit test definitions.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Common CMake unit test definitions.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   16.01.2009 23:45:30

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
#ifndef __UNIT_TEST_HPP__
#define __UNIT_TEST_HPP__
/*==========================================================================*/
#include "../../sys-All/unit-cmake/CUnitTestLauncherCMake-All.hpp"
#include "../../sys-WindowsMobile/unit-mobile/CUnitTestLauncherMobile-WindowsMobile.hpp"
/*==========================================================================*/
/* GLOBAL VARIABLES DECLARATIONS                                            */
/*==========================================================================*/
#if (defined(__WINDOWS__) && defined(__WINDOWS_MOBILE__))
  //! Windows Mobile unit test launcher.
  NDepth::NUnitTest::CUnitTestLauncherMobile the_MobileUnitTestLauncher(STR("NDepth::NUnitTest::CUnitTestLauncherMobile"), FILE);
#else
  //! CMake unit test launcher.
  NDepth::NUnitTest::CUnitTestLauncherCMake the_CMakeUnitTestLauncher(STR("NDepth::NUnitTest::CUnitTestLauncherCMake"), FILE);
#endif
/*==========================================================================*/
#endif
