/*!
 *  \file    test-configure-Types.cpp Testing of the Depth types.
 *  \brief   Testing of the Depth types.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the Depth types.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth configure tests
    VERSION:   1.0
    CREATED:   05.06.2008 21:25:54

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
// Common headers.
#include "unit-test.hpp"
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/types.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NTypes;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    STATIC_ASSERT((sizeof(Tschar) == 1), STR("ASCII character should be 1 byte!"));
    STATIC_ASSERT((sizeof(Twchar) > 1), STR("Unicode character should be greater than 1 byte!"));
    STATIC_ASSERT((sizeof(Tscharu) == sizeof(Tschar)), STR("Size of the ASCII unsigned character should be equal to the signed one!"));
    STATIC_ASSERT((sizeof(Twcharu) == sizeof(Twchar)), STR("Size of the Unicode unsigned character should be equal to the signed one!"));

    STATIC_ASSERT((sizeof(Tsint08) == 1), STR("Tsint08 should be 1 byte!"));
    STATIC_ASSERT((sizeof(Tuint08) == 1), STR("Tuint08 should be 1 byte!"));
    STATIC_ASSERT((sizeof(Tsint16) == 2), STR("Tsint16 should be 2 bytes!"));
    STATIC_ASSERT((sizeof(Tuint16) == 2), STR("Tuint16 should be 2 bytes!"));
    STATIC_ASSERT((sizeof(Tsint32) == 4), STR("Tsint32 should be 4 bytes!"));
    STATIC_ASSERT((sizeof(Tuint32) == 4), STR("Tuint32 should be 4 bytes!"));
    STATIC_ASSERT((sizeof(Tsint64) == 8), STR("Tsint64 should be 8 bytes!"));
    STATIC_ASSERT((sizeof(Tuint64) == 8), STR("Tuint64 should be 8 bytes!"));

    STATIC_ASSERT((sizeof(Tfloat) == 4), STR("Float should be 4 bytes!"));
    STATIC_ASSERT((sizeof(Tdouble) == 8), STR("Double should be 8 bytes!"));

    STATIC_ASSERT((sizeof(Tbyte) == 1), STR("Tbyte should be 1 byte!"));
    STATIC_ASSERT((sizeof(Tcptr) == sizeof(Tptr)), STR("Constant pointer should be the same size as a pointer!"));
    STATIC_ASSERT((sizeof(Tcbuffer) == sizeof(Tbuffer)), STR("Constant bytes buffer should be the same size as a bytes buffer!"));

    STATIC_ASSERT((sizeof(Tbuffer) == sizeof(Tptr)), STR("Bytes buffer should be the same size as a pointer!"));
    STATIC_ASSERT((sizeof(Tsint) == sizeof(Tptr)), STR("Signed integer should be the same size as a pointer!"));
    STATIC_ASSERT((sizeof(Tuint) == sizeof(Tptr)), STR("Unsigned integer should be the same size as a pointer!"));
    STATIC_ASSERT((sizeof(Tstr) == sizeof(Tptr)), STR("'C' string should be the same size as a pointer!"));
    STATIC_ASSERT((sizeof(Tsstr) == sizeof(Tptr)), STR("ASCII 'C' string should be the same size as a pointer!"));
    STATIC_ASSERT((sizeof(Twstr) == sizeof(Tptr)), STR("Unicode 'C' string should be the same size as a pointer!"));
    STATIC_ASSERT((sizeof(Tcstr) == sizeof(Tptr)), STR("Constant 'C' string should be the same size as a pointer!"));
    STATIC_ASSERT((sizeof(Tcsstr) == sizeof(Tptr)), STR("Constant ASCII 'C' string should be the same size as a pointer!"));
    STATIC_ASSERT((sizeof(Tcwstr) == sizeof(Tptr)), STR("Constant Unicode 'C' string should be the same size as a pointer!"));

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
