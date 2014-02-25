/*!
 *  \file    CUnitTestSuite.inl Unit test suite collects all unit tests
 *           and allows to launch them with a unit test launcher. Base
 *           implementation of the unit test suite simple launches all
 *           registered tests in the suite.
 *  \brief   Unit test suite class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test suite class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unit test
    VERSION:   1.0
    CREATED:   15.01.2009 23:09:21

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
#ifndef __CUNITTESTSUITE_INL__
#define __CUNITTESTSUITE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CUnitTestSuite::~CUnitTestSuite()
{ CALL
  CUnitTestSuite::ms_pInstance = NULL;
}
/*--------------------------------------------------------------------------*/
inline const NString::CString& CUnitTestSuite::getName() const
{ CALL
  return m_Name;
}
/*--------------------------------------------------------------------------*/
inline const NString::CString& CUnitTestSuite::getFileName() const
{ CALL
  return m_FileName;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestSuite::isCreated()
{ CALL
  return (CUnitTestSuite::ms_pInstance != NULL);
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestSuite::isLaunched()
{ CALL
  return CUnitTestSuite::ms_IsLaunched;
}
/*--------------------------------------------------------------------------*/
inline CUnitTestSuite& CUnitTestSuite::getCurrentRef()
{ CALL
  // Verify that the current unit test suite instance is created.
  VERIFY(CUnitTestSuite::isCreated(), STR("Taking reference to the unit test suite instance which is not created leads to the error."));

  return *CUnitTestSuite::ms_pInstance;
}
/*--------------------------------------------------------------------------*/
inline CUnitTestSuite* CUnitTestSuite::getCurrentPtr()
{ CALL
  return CUnitTestSuite::ms_pInstance;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestSuite::install()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTestSuite::uninstall()
{ CALL
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
