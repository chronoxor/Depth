/*!
 *  \file    CUnitTest.hpp Unit test is a class which gives all necessary
 *           functionality to perform a unit test with setup/teardown
 *           strategy.
 *  \brief   Unit test class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test class.

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
#ifndef __CUNITTEST_HPP__
#define __CUNITTEST_HPP__
/*==========================================================================*/
#include <Depth/include/time/CTimeStamp.hpp>
#include <Depth/include/unit/CUnitTestSuite.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Unit test class.
/*!
    Unit test class provides base functionality to perform a  unit  test.  All
    particular unit tests should be derived from the CUnitTestSuite  in  order
    to be used in the unit test suite.

    Inherited classes can override 'install()'/'uninstall()' methods in  order
    to  change  initialization/deinitialization  functionality.  It  is   also
    possible to override 'test()' method in order  to  change  test  execution
    process.
*/
class UNITTEST_API CUnitTest
{
  // Friend class: Unit test suite class (CUnitTestSuite).
  friend class CUnitTestSuite;
  // Friend class: Unit test launcher class (CUnitTestLauncher).
  friend class CUnitTestLauncher;

public:
  //! Default class constructor. Initialize unit test with a corresponding name and file name.
  /*!
      \param a_crName - Unit test name (default is NDepth::NUnitTest::CUnitTest).
      \param a_crFileName - Unit test file name (default is FILE).
  */
  CUnitTest(const NString::CString& a_crName = STR("NDepth::NUnitTest::CUnitTest"), const NString::CString& a_crFileName = FILE);
  //! Class virtual destructor.
  virtual ~CUnitTest();

  //! Get name of the current unit test.
  /*!
      \return Constant reference to the name of the current unit test.
  */
  const NString::CString& getName() const;
  //! Get file name of the current unit test.
  /*!
      \return Constant reference to the file name of the current unit test.
  */
  const NString::CString& getFileName() const;
  //! Get timeout of the current unit test.
  /*!
      \return Time stamp of the timeout of the current unit test.
  */
  NTime::CTimeStamp getTimeout() const;

protected:
  //! Install unit test.
  /*!
      Default implementation of the method does nothing. But you can  override
      it in order to perform specific initialization of the unit test.

      \return true  - if unit test was successfully installed. \n
              false - if unit test was not successfully installed. \n
  */
  virtual Tbool install();
  //! Uninstall unit test.
  /*!
      Default implementation of the method does nothing. But you can  override
      it in order to perform specific deinitialization of the unit test.

      \return true  - if unit test was successfully uninstalled. \n
              false - if unit test was not successfully uninstalled. \n
  */
  virtual Tbool uninstall();
  //! Launch unit test.
  /*!
      The method shoyld be overridden in order to perform unit test.

      \return Unit tests result.
  */
  virtual EUnitTestResult test() = 0;

private:
  NString::CString  m_Name;             //!< Unit test name.
  NString::CString  m_FileName;         //!< Unit test file name.
  NTime::CTimeStamp m_Timeout;          //!< Unit test timeout.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/unit/CUnitTest.inl>
/*==========================================================================*/
//! \example example-unit-CUnitTest.cpp
/*--------------------------------------------------------------------------*/
//! \test test-unit-CUnitTest.cpp
/*==========================================================================*/
#endif
