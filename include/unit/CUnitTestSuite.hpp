/*!
 *  \file    CUnitTestSuite.hpp Unit test suite collects all unit tests
 *           and allows to launch them with a unit test launcher. Base
 *           implementation of the unit test suite simple launches all
 *           registered tests in the suite.
 *  \brief   Unit test suite class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test suite class.

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
#ifndef __CUNITTESTSUITE_HPP__
#define __CUNITTESTSUITE_HPP__
/*==========================================================================*/
#include <Depth/include/containers/CListSL.hpp>
#include <Depth/include/unit/CUnitTestLauncher.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Unit test suite class.
/*!
    Unit test suite class collects all unit tests and allows  to  launch  them
    with unit test launcher. Base implementation of the unit test suite simple
    launches all registered tests in the suite.

    Inherited classes can override 'install()'/'uninstall()' methods in  order
    to  change  initialization/deinitialization  functionality.  It  is   also
    possible to override 'test()' method in order  to  change  test  execution
    process.
*/
class UNITTEST_API CUnitTestSuite
{
  // Friend class: Unit test class (CUnitTest).
  friend class CUnitTest;
  // Friend class: Unit test launcher class (CUnitTestLauncher).
  friend class CUnitTestLauncher;

public:
  //! Default class constructor. Initialize unit test suite with a corresponding name and file name.
  /*!
      \param a_crName - Unit test suite name (default is NDepth::NUnitTest::CUnitTestSuite).
      \param a_crFileName - Unit test suite file name (default is FILE).
  */
  CUnitTestSuite(const NString::CString& a_crName = STR("NDepth::NUnitTest::CUnitTestSuite"), const NString::CString& a_crFileName = FILE);
  //! Class virtual destructor.
  virtual ~CUnitTestSuite();

  //! Get name of the current unit test suite.
  /*!
      \return Constant reference to the name of the current unit test suite.
  */
  const NString::CString& getName() const;
  //! Get file name of the current unit test suite.
  /*!
      \return Constant reference to the file name of the current unit test suite.
  */
  const NString::CString& getFileName() const;

  //! Is instance of the unit test suite created?
  /*!
      \return true  - if the unit test suite instance was created. \n
              false - if the unit test suite instance was not created. \n
  */
  static Tbool isCreated();
  //! Is unit test suite launched?
  /*!
      \return true  - if the unit test suite instance is launched. \n
              false - if the unit test suite instance is not launched. \n
  */
  static Tbool isLaunched();

  //! Get reference to the current unit test suite instance.
  /*!
      Method returns reference to the current unit test suite  instance.  Note
      that result may be broken if the current unit test suite instance is not
      created. So use 'isCreated()' method before to check its valid state.

      \return Reference to the current unit test launcher suite.
  */
  static CUnitTestSuite& getCurrentRef();
  //! Get pointer to the current unit test suite instance.
  /*!
      Method returns pointer to the current unit  test  suite  instance.  Note
      that result may be NULL if the current unit test suite instance  is  not
      created. So use 'isCreated()' method before to check its valid state  or
      use NULL checking strategy to define unit test  suite  instance  is  not
      created state alternatively.

      \return Pointer to the current unit test suite instance.
  */
  static CUnitTestSuite* getCurrentPtr();

protected:
  //! Install unit test suite.
  /*!
      Default implementation of the method does nothing. But you can  override
      it in order to perform specific initialization of the unit test suite.

      \return true  - if unit test suite was successfully installed. \n
              false - if unit test suite was not successfully installed. \n
  */
  virtual Tbool install();
  //! Uninstall unit test suite.
  /*!
      Default implementation of the method does nothing. But you can  override
      it in order to perform specific deinitialization of the unit test suite.

      \return true  - if unit test suite was successfully uninstalled. \n
              false - if unit test suite was not successfully uninstalled. \n
  */
  virtual Tbool uninstall();
  //! Launch all registered unit tests in the suite.
  /*!
      Default implementation of the method  simple  launches  registered  unit
      tests in the suite. But you can override it in order to perform specific
      launching of the unit tests.

      \return Composite unit tests result.
  */
  virtual EUnitTestResult test();

private:
  NString::CString m_Name;                      //!< Unit test suite name.
  NString::CString m_FileName;                  //!< Unit test suite file name.
  NContainers::CListSL<CUnitTest*> m_TestList;  //!< List with all registered unit tests.

  static Tbool ms_IsLaunched;                   //!< Is unit test suite launched?
  static Tbool ms_IsInstanceCreated;            //!< Is unit test suite instance created?
  static CUnitTestSuite* ms_pInstance;          //!< Pointer to the current instance of the unit test suite.

  //! Initialize default unit test suite instance.
  /*!
      \param a_cUnitTestFlag - Unit test dummy flag.
  */
  CUnitTestSuite(const Tbool a_cUnitTestFlag);

  //! Create default instance of the CUnitTestSuite.
  /*!
      \return true  - if instance of the CUnitTestSuite was successfully created. \n
              false - if instance of the CUnitTestSuite was not successfully created. \n
  */
  static Tbool CreateDefaultInstance();
  //! Destroy default instance of the CUnitTestSuite.
  /*!
      \return true  - if instance of the CUnitTestSuite was successfully destroy. \n
              false - if instance of the CUnitTestSuite was not successfully destroy. \n
  */
  static Tbool DestroyDefaultInstance();
  //! Register unit test in the current suite.
  /*!
      \param a_pUnitTest - Pointer to the unit test instance.
      \return true  - if the unit test was successfully registered. \n
              false - if the unit test was not successfully registered. \n
  */
  static Tbool RegisterUnitTest(CUnitTest* a_pUnitTest);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/unit/CUnitTestSuite.inl>
/*==========================================================================*/
//! \example example-unit-CUnitTestSuite.cpp
/*--------------------------------------------------------------------------*/
//! \test test-unit-CUnitTestSuite.cpp
/*==========================================================================*/
#endif
