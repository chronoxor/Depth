/*!
 *  \file    FUnitTestIsNeedStop.cpp Helper function that checks if unit test
 *           execution should be stopped because of errors.
 *  \brief   Unit test is need stop helper function (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test is need stop helper function (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unit test details
    VERSION:   1.0
    CREATED:   31.01.2009 21:59:18

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
#include <Depth/include/unit.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/unit/CUnitTestLauncher.hpp>
#include <Depth/include/unit/details/FUnitTestIsNeedStop.hpp>
/*==========================================================================*/
#ifndef __FUNITTESTISNEEDSTOP_CPP__
#define __FUNITTESTISNEEDSTOP_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* FUNCTION IMPLEMENTATIONS                                                 */
/*==========================================================================*/
UNITTEST_API Tbool unitTestIsNeedStop()
{ CALL
  // Check if the current unit test launcher is created.
  ASSERT(CUnitTestLauncher::isCreated(), STR("Unit test launcher is not created."))
  {
    return true;
  }

  EUnitTestResult result = CUnitTestLauncher::ms_pInstance->getUnitTestResult();
  return ((result == e_TEST_STOPPED) || (result == e_TEST_ERROR));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
