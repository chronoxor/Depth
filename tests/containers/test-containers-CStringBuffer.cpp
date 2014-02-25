/*!
 *  \file    test-containers-CStringBuffer.cpp Testing of the CStringBuffer 
 *           class.
 *  \brief   Testing of the CStringBuffer class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CStringBuffer class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   15.04.2009 20:11:57

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
#include <Depth/include/algorithms/string/buffer/AStrNCmp.hpp>
#include <Depth/include/algorithms/string/format/AFormat.hpp>
#include <Depth/include/containers/CStringBuffer.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NString;
using namespace NDepth::NAlgorithms::NString::NBuffer;
using namespace NDepth::NAlgorithms::NString::NFormat;
using namespace NDepth::NContainers;
using namespace NDepth::NSerialization;
using namespace NDepth::NString;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT_CHECK_TYPE(CStringBuffer<Tsstr>(), false, false);
    UT_ASSERT_CHECK_TYPE(CStringBuffer<Twstr>(), false, false);
    UT_ASSERT_CHECK_TYPE(CStringBuffer<CStringASCII>(), false, true);
    UT_ASSERT_CHECK_TYPE(CStringBuffer<CStringUnicode>(), false, true);
    UT_ASSERT_CHECK_TYPE(CStringBuffer<CSystemString>(), true, true);

    UT_ACCEPT;
  }

  // Check the the given CStringBuffer<T_StringType> type.
  template <typename T_StringType>
  void UT_ASSERT_CHECK_TYPE(const CStringBuffer<T_StringType>& a_crStringBuffer, const Tbool a_cLightCheck, const Tbool a_cSerializationCheck)
  { CALL
    CStringBuffer<T_StringType> a;
    CStringBuffer<T_StringType> b;
    UT_ASSERT_ZERO(a.getSize());
    UT_ASSERT_ZERO(b.getSize());

    // Fill the first string buffer.
    UT_ASSERT_CHECK_FILL(a, true);
    UT_ASSERT_EQUAL(a.getSize(), 6);
    // Fill the second string buffer.
    UT_ASSERT_CHECK_FILL(b, false);
    UT_ASSERT_EQUAL(b.getSize(), 6);

    // Show the first string buffer.
    UT_ASSERT_CHECK_SHOW(a, true, a_cLightCheck);
    // Show the second string buffer.
    UT_ASSERT_CHECK_SHOW(b, false, a_cLightCheck);

    // Copy string buffers.
    CStringBuffer<T_StringType> c(a);
    CStringBuffer<T_StringType> d(b);
    UT_ASSERT_EQUAL(c.getSize(), 6);
    UT_ASSERT_EQUAL(d.getSize(), 6);

    // Reverse string buffers.
    c.reverse();
    d.reverse();

    // Show the first reversed string buffer.
    UT_ASSERT_CHECK_SHOW_REVERSED(c, true, a_cLightCheck);
    // Show the last reversed string buffer.
    UT_ASSERT_CHECK_SHOW_REVERSED(d, false, a_cLightCheck);

    // Remove items from the first string buffer.
    UT_ASSERT_CHECK_REMOVE(a, true, a_cLightCheck);
    UT_ASSERT_ZERO(a.getSize());
    // Remove items from the second string buffer.
    UT_ASSERT_CHECK_REMOVE(b, false, a_cLightCheck);
    UT_ASSERT_ZERO(b.getSize());

    // Clear the first reversed string buffer.
    UT_ASSERT(c.clear());
    UT_ASSERT_ZERO(c.getSize());
    // Clear the second reversed string buffer.
    UT_ASSERT(d.clear());
    UT_ASSERT_ZERO(d.getSize());

    // Check serialization functionality.
    if (a_cSerializationCheck)
      UT_ASSERT_CHECK_SERIALIZATION(a_crStringBuffer, a_cLightCheck);
  }

  // Check the fill functionality of the CStringBuffer<T_StringType>.
  template <typename T_StringType>
  void UT_ASSERT_CHECK_FILL(CStringBuffer<T_StringType>& a_rStringBuffer, const Tbool a_cDirectOrder)
  { CALL
    UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst(STR("String 6")) : a_rStringBuffer.insertLast(STR("String 1")));
    UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst(STR("String 5")) : a_rStringBuffer.insertLast(STR("String 2")));
    UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst(STR("String 4")) : a_rStringBuffer.insertLast(STR("String 3")));
    UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst(STR("String 3")) : a_rStringBuffer.insertLast(STR("String 4")));
    UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst(STR("String 2")) : a_rStringBuffer.insertLast(STR("String 5")));
    UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst(STR("String 1")) : a_rStringBuffer.insertLast(STR("String 6")));
  }

  // Check the show functionality of the CStringBuffer<T_StringType>.
  template <typename T_StringType>
  void UT_ASSERT_CHECK_SHOW(const CStringBuffer<T_StringType>& a_crStringBuffer, const Tbool a_cDirectOrder, const Tbool a_cLightCheck)
  { CALL
    Tsint value = (a_cDirectOrder ? 1 : 6);
    typename CStringBuffer<T_StringType>::TIteratorConst it = (a_cDirectOrder ? a_crStringBuffer.getItFirst() : a_crStringBuffer.getItLast());
    if (it.isValid())
    {
      do
      {
        if (!a_cLightCheck)
          UT_ASSERT_ZERO(strNCmp(*it, format(STR("String %i"), value), 8));
        (a_cDirectOrder) ? ++value : --value;
      } while ((a_cDirectOrder ? it.stepForward() : it.stepBackward()) == 1);
    }
    UT_ASSERT_EQUAL(value, (a_cDirectOrder ? 7 : 0));
  }

  // Check the show reversed functionality of the CStringBuffer<T_StringType>.
  template <typename T_StringType>
  void UT_ASSERT_CHECK_SHOW_REVERSED(const CStringBuffer<T_StringType>& a_crStringBuffer, const Tbool a_cDirectOrder, const Tbool a_cLightCheck)
  { CALL
    Tsint value = (a_cDirectOrder ? 6 : 1);
    typename CStringBuffer<T_StringType>::TIteratorConst it = (a_cDirectOrder ? a_crStringBuffer.getItFirst() : a_crStringBuffer.getItLast());
    if (it.isValid())
    {
      do
      {
        if (!a_cLightCheck)
          UT_ASSERT_ZERO(strNCmp(*it, format(STR("String %i"), value), 8));
        (a_cDirectOrder) ? --value : ++value;
      } while ((a_cDirectOrder ? it.stepForward() : it.stepBackward()) == 1);
    }
    UT_ASSERT_EQUAL(value, (a_cDirectOrder ? 0 : 7));
  }

  // Check the remove functionality of the CStringBuffer<T_StringType>.
  template <typename T_StringType>
  void UT_ASSERT_CHECK_REMOVE(CStringBuffer<T_StringType>& a_rStringBuffer, Tbool a_cDirectOrder, const Tbool a_cLightCheck, const Tbool a_cReversed = false)
  { CALL
    Tsint value = (a_cDirectOrder || a_cReversed) ? 1 : 6;
    typename CStringBuffer<T_StringType>::TIterator it = (a_cDirectOrder ? a_rStringBuffer.getItFirst() : a_rStringBuffer.getItLast());
    while (it.isValid())
    {
      if (!a_cLightCheck)
        UT_ASSERT_ZERO(strNCmp(*it, format(STR("String %i"), value), 8));
      (a_cDirectOrder || a_cReversed) ? ++value : --value;
      UT_ASSERT(a_cDirectOrder ? it.removeForward() : it.removeBackward());
    }
    UT_ASSERT_EQUAL(value, ((a_cDirectOrder || a_cReversed) ? 7 : 0));
  }

  // Check the serialization functionality.
  template <typename T_StringType>
  void UT_ASSERT_CHECK_SERIALIZATION(const CStringBuffer<T_StringType>& a_crStringBuffer, const Tbool a_cLightCheck)
  { CALL
    CStringBuffer<T_StringType> instance(a_crStringBuffer);

    // Fill the string buffer.
    UT_ASSERT_CHECK_FILL(instance, true);

    // Show the string buffer before serialization.
    UT_ASSERT_CHECK_SHOW(instance, true, a_cLightCheck);

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

    // Show the string buffer after serialization.
    UT_ASSERT_CHECK_SHOW(instance, true, a_cLightCheck);
  }
} the_Test;
/*--------------------------------------------------------------------------*/
// Check the fill functionality of the CStringBuffer<T_StringType> ('C' string specialization).
template <>
void CTest::UT_ASSERT_CHECK_FILL(CStringBuffer<Tsstr>& a_rStringBuffer, const Tbool a_cDirectOrder)
{ CALL
  UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst((Tsstr)ASC("String 6")) : a_rStringBuffer.insertLast((Tsstr)ASC("String 1")));
  UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst((Tsstr)ASC("String 5")) : a_rStringBuffer.insertLast((Tsstr)ASC("String 2")));
  UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst((Tsstr)ASC("String 4")) : a_rStringBuffer.insertLast((Tsstr)ASC("String 3")));
  UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst((Tsstr)ASC("String 3")) : a_rStringBuffer.insertLast((Tsstr)ASC("String 4")));
  UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst((Tsstr)ASC("String 2")) : a_rStringBuffer.insertLast((Tsstr)ASC("String 5")));
  UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst((Tsstr)ASC("String 1")) : a_rStringBuffer.insertLast((Tsstr)ASC("String 6")));
}
/*--------------------------------------------------------------------------*/
// Check the fill functionality of the CStringBuffer<T_StringType> (wide 'C' string specialization).
template <>
void CTest::UT_ASSERT_CHECK_FILL(CStringBuffer<Twstr>& a_rStringBuffer, const Tbool a_cDirectOrder)
{ CALL
  UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst((Twstr)UNC("String 6")) : a_rStringBuffer.insertLast((Twstr)UNC("String 1")));
  UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst((Twstr)UNC("String 5")) : a_rStringBuffer.insertLast((Twstr)UNC("String 2")));
  UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst((Twstr)UNC("String 4")) : a_rStringBuffer.insertLast((Twstr)UNC("String 3")));
  UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst((Twstr)UNC("String 3")) : a_rStringBuffer.insertLast((Twstr)UNC("String 4")));
  UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst((Twstr)UNC("String 2")) : a_rStringBuffer.insertLast((Twstr)UNC("String 5")));
  UT_ASSERT(a_cDirectOrder ? a_rStringBuffer.insertFirst((Twstr)UNC("String 1")) : a_rStringBuffer.insertLast((Twstr)UNC("String 6")));
}
/*==========================================================================*/
