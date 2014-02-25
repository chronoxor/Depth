/*!
 *  \file    test-string-CCharacter.cpp Testing of the CCharacter class.
 *  \brief   Testing of the CCharacter class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CCharacter class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth string tests
    VERSION:   1.0
    CREATED:   30.03.2009 03:46:15

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
#include <Depth/include/string/CCharacter.hpp>
#include <Depth/include/string/CCharacterProperties.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NSerialization;
using namespace NDepth::NString;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT_EQUAL((Tchar)CCharacter(STR('A')).toLowerCase(), STR('a'));
    UT_ASSERT_EQUAL((Tchar)CCharacter(STR('z')).toUpperCase(), STR('Z'));
    UT_ASSERT_EQUAL((Tchar)CCharacter(STR('z')).toTitleCase(), STR('Z'));
    UT_ASSERT_EQUAL((Tchar)CCharacter(STR('A')).toToggleCase(), STR('a'));
    UT_ASSERT_EQUAL((Tchar)CCharacter(STR('z')).toToggleCase(), STR('Z'));

    CCharacter character(STR('\''));
    CCharacterProperties character_properties(character);
    UT_ASSERT(character_properties.isValid());
    UT_ASSERT(character_properties.isValidName());
    UT_ASSERT(character_properties.isValidOldName());
    UT_ASSERT_EQUAL(character_properties.getCode(), 0x27);
    UT_ASSERT_EQUAL(CString(character_properties.getName()), CString(STR("APOSTROPHE")));
    UT_ASSERT_EQUAL(CString(character_properties.getOldName()), CString(STR("APOSTROPHE-QUOTE")));

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CCharacter instance(STR('A'));

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
    UT_ASSERT_EQUAL((Tchar)instance, STR('A'));
  }
} the_Test;
/*==========================================================================*/
