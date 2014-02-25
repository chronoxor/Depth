/*!
 *  \file    CUnitTest.cpp Unit test is a class which gives all necessary
 *           functionality to perform a unit test with setup/teardown
 *           strategy.
 *  \brief   Unit test class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unit test
    VERSION:   1.0
    CREATED:   16.01.2009 03:39:24

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
#include <Depth/include/unit/CUnitTest.hpp>
/*==========================================================================*/
#ifndef __CUNITTEST_CPP__
#define __CUNITTEST_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CUnitTest::CUnitTest(const NString::CString& a_crName/* = STR("NDepth::NUnitTest::CUnitTest") */, const NString::CString& a_crFileName/* = FILE */) :
  m_Name(a_crName),
  m_FileName(a_crFileName),
  m_Timeout(NTime::CTimeStamp::getSystemTimeStamp())
{ CALL
  // If there no instance of unit test suite is created, then create default one.
  if (!CUnitTestSuite::isCreated())
    CUnitTestSuite::CreateDefaultInstance();

  // Register current unit test in the unit test suite.
  CUnitTestSuite::RegisterUnitTest(this);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
