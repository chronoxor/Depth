/*!
 *  \file    test-common-ISingleton.cpp Testing of the ISingleton interface.
 *  \brief   Testing of the ISingleton interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the ISingleton interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth common tests
    VERSION:   1.0
    CREATED:   24.01.2007 22:08:28

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
#include <Depth/include/common/ISingleton.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NCommon;
/*==========================================================================*/
class CTrueSingleton :
  public ISingleton<CTrueSingleton>
{
  // Friend class: Base ISingleton class.
  friend class ISingleton<CTrueSingleton>;

public:
  Tbool example()
  { CALL
    return true;
  }

private:
  CTrueSingleton() : ISingleton<CTrueSingleton>()
  { CALL

  }
 ~CTrueSingleton()
  { CALL

  }
};
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT(CTrueSingleton::getInstance().example());

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
