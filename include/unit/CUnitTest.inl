/*!
 *  \file    CUnitTest.inl Unit test is a class which gives all necessary
 *           functionality to perform a unit test with setup/teardown
 *           strategy.
 *  \brief   Unit test class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test class (inline).

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
#ifndef __CUNITTEST_INL__
#define __CUNITTEST_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CUnitTest::~CUnitTest()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline const NString::CString& CUnitTest::getName() const
{ CALL
  return m_Name;
}
/*--------------------------------------------------------------------------*/
inline const NString::CString& CUnitTest::getFileName() const
{ CALL
  return m_FileName;
}
/*--------------------------------------------------------------------------*/
inline NTime::CTimeStamp CUnitTest::getTimeout() const
{ CALL
  return NTime::CTimeStamp::getSystemTimeStamp() - m_Timeout;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTest::install()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CUnitTest::uninstall()
{ CALL
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
