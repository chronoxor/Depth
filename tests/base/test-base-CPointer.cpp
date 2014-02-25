/*!
 *  \file    test-base-CPointer.cpp Testing of the CPointer class.
 *  \brief   Testing of the CPointer class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CPointer class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth base tests
    VERSION:   1.0
    CREATED:   17.01.2007 02:35:39

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
// Temporary headers.
#include <Depth/todo/serialize/serialize.hpp>
/*--------------------------------------------------------------------------*/
// Common headers.
#include "unit-test.hpp"
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/algorithms/common/APointer.hpp>
#include <Depth/include/base/CPointer.hpp>
#include <Depth/include/base/CPointerMaker.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NCommon;
using namespace NDepth::NBase;
using namespace NDepth::NSerialization;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    Tsint i = 0;

    CPointer<Tsint> a(&i);
    CPointer<Tsint> b(CPointerMaker::make(&i));
    CPointer<Tsint> c(ptr(&i));

    UT_ASSERT_EQUAL(*a, 0);
    UT_ASSERT_EQUAL(*b, 0);
    UT_ASSERT_EQUAL(*c, 0);

    i = 100;

    UT_ASSERT_EQUAL(*a, 100);
    UT_ASSERT_EQUAL(*b, 100);
    UT_ASSERT_EQUAL(*c, 100);

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    Tsint i = 200;
    CPointer<Tsint> instance(&i);

    // Save instance.
    SaveArchive saver;
    UT_ASSERT(saver.open());
    UT_ASSERT(saver.serialize(instance));
    UT_ASSERT(saver.close());

    // Clear instance.
    i = 0;
    instance.clear();

    // Load instance.
    LoadArchive loader;
    UT_ASSERT(loader.open());
    UT_ASSERT(loader.serialize(instance));
    UT_ASSERT(loader.close());

    // Check the pointer value.
    UT_ASSERT_EQUAL(*instance, 200);

    // Delete serialization buffer for pointer.
    delete (Tsint*)instance;
  }
} the_Test;
/*==========================================================================*/
