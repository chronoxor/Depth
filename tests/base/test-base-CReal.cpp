/*!
 *  \file    test-base-CReal.cpp Testing of the CReal class.
 *  \brief   Testing of the CReal class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CReal class.

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
#include <Depth/include/base/CReal.hpp>
#include <Depth/include/base/CRealMaker.hpp>
#include <Depth/include/math/CMath.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NBase;
using namespace NDepth::NMath;
using namespace NDepth::NSerialization;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CFloat      a(0.5f);
    CDouble     b(0.6);
    CRealNumber c(a);

    UT_ASSERT_DELTA(a.getValue(), 0.5, 0.0001);
    UT_ASSERT_DELTA(b.getValue(), 0.6, 0.0001);
    UT_ASSERT_DELTA(c.getValue(), 0.5, 0.0001);
    UT_ASSERT_DELTA(CRealMaker::make(0.7).getValue(), 0.7, 0.0001);

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CFloat instance(0.7f);

    // Save instance.
    SaveArchive saver;
    UT_ASSERT(saver.open());
    UT_ASSERT(saver.serialize(instance));
    UT_ASSERT(saver.close());

    // Clear instance.
    instance.clear();

    // Load instance.
    LoadArchive loader;
    UT_ASSERT(loader.open());
    UT_ASSERT(loader.serialize(instance));
    UT_ASSERT(loader.close());
    UT_ASSERT_DELTA(instance.getValue(), 0.7, 0.0001);
  }
} the_Test;
/*==========================================================================*/
