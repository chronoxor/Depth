/*!
 *  \file    test-containers-CMap.cpp Testing of the CMap class.
 *  \brief   Testing of the CMap class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CMap class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   27.03.2007 03:58:26

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
#include <Depth/include/containers/CMap.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NContainers;
using namespace NDepth::NSerialization;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CMap<Tsint, Tschar> a;
    UT_ASSERT_ZERO(a.getSize());

    // Fill the first map.
    UT_ASSERT_CHECK_FILL(a);
    UT_ASSERT_EQUAL(a.getSize(), 9);

    // Show the first map.
    UT_ASSERT_CHECK_SHOW(a);

    // Copy maps.
    CMap<Tsint, Tschar> b(a);
    UT_ASSERT_EQUAL(b.getSize(), 9);

    // Show the second map.
    UT_ASSERT_CHECK_SHOW(b);

    // Remove items from the first map.
    UT_ASSERT_CHECK_REMOVE(a);
    UT_ASSERT_ZERO(a.getSize());

    // Clear the second map.
    UT_ASSERT(b.clear());
    UT_ASSERT_ZERO(b.getSize());

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill functionality of the CMap<Tsint, Tschar>.
  void UT_ASSERT_CHECK_FILL(CMap<Tsint, Tschar>& a_rMap)
  { CALL
    UT_ASSERT(a_rMap.insert(6, ASC('F')));
    UT_ASSERT(a_rMap.insert(3, ASC('C')));
    UT_ASSERT(a_rMap.insert(7, ASC('G')));
    UT_ASSERT(a_rMap.insert(2, ASC('B')));
    UT_ASSERT(a_rMap.insert(8, ASC('H')));
    UT_ASSERT(a_rMap.insert(1, ASC('A')));
    UT_ASSERT(a_rMap.insert(4, ASC('D')));
    UT_ASSERT(a_rMap.insert(9, ASC('I')));
    UT_ASSERT(a_rMap.insert(5, ASC('E')));
    UT_ASSERT(!a_rMap.insert(6, ASC('f')));
    UT_ASSERT(!a_rMap.insert(3, ASC('c')));
    UT_ASSERT(!a_rMap.insert(7, ASC('g')));
    UT_ASSERT(!a_rMap.insert(2, ASC('b')));
    UT_ASSERT(!a_rMap.insert(8, ASC('h')));
    UT_ASSERT(!a_rMap.insert(1, ASC('a')));
    UT_ASSERT(!a_rMap.insert(4, ASC('d')));
    UT_ASSERT(!a_rMap.insert(9, ASC('i')));
    UT_ASSERT(!a_rMap.insert(5, ASC('e')));
  }

  // Check the show functionality of the CMap<Tsint, Tschar>.
  void UT_ASSERT_CHECK_SHOW(const CMap<Tsint, Tschar>& a_crMap)
  { CALL
    Tsint key = 1;
    Tschar value = ASC('A');
    CMap<Tsint, Tschar>::TIteratorConst it = a_crMap.getItFirst();
    if (it.isValid())
    {
      do
      {
        UT_ASSERT((it.getKeyRef() == key++) && (*it == value++));
      } while (it.stepForward() == 1);
    }
    UT_ASSERT((key == 10) && (value == ASC('J')));
  }

  // Check the remove functionality of the CMap<Tsint, Tschar>.
  void UT_ASSERT_CHECK_REMOVE(CMap<Tsint, Tschar>& a_rMap)
  { CALL
    Tsint key = 1;
    Tschar value = ASC('A');
    CMap<Tsint, Tschar>::TIterator it = a_rMap.getItFirst();
    while (it.isValid())
    {
      UT_ASSERT((it.getKeyRef() == key++) && (*it == value++));
      UT_ASSERT(it.remove());
    }
    UT_ASSERT((key == 10) && (value == ASC('J')));
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CMap<Tsint, Tschar> instance;

    // Fill the map.
    UT_ASSERT_CHECK_FILL(instance);

    // Show the map before serialization.
    UT_ASSERT_CHECK_SHOW(instance);

    // Save instance.
    SaveArchive saver;
    UT_ASSERT(saver.open());
    UT_ASSERT(saver.serialize(instance));
    UT_ASSERT(saver.close());

    // Clear instance.
    UT_ASSERT(instance.clear());

    // Load instance.
    LoadArchive loader;
    UT_ASSERT(loader.open());
    UT_ASSERT(loader.serialize(instance));
    UT_ASSERT(loader.close());

    // Show the map after serialization.
    UT_ASSERT_CHECK_SHOW(instance);
  }
} the_Test;
/*==========================================================================*/
