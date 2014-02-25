/*!
 *  \file    example-common-ILocal.cpp Example of using the ILocal interface.
 *  \brief   Example of using the ILocal interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the ILocal interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth common examples
    VERSION:   1.0
    CREATED:   03.01.2007 00:45:23

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
#include <Depth/include/application/IApplication.hpp>
#include <Depth/include/stream/CStreamStdOutput.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/common/ILocal.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NCommon;
/*==========================================================================*/
class CLocalFull :
  public ILocal
{
public:
  void test()
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CLocalFull::test()") << ln;
  }
};
/*--------------------------------------------------------------------------*/
class CLocalBase :
  public ILocalBase
{
public:
  void test()
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CLocalBase::test()") << ln;
  }
};
/*--------------------------------------------------------------------------*/
class CLocalDerived :
  public CLocalBase
{
public:
  void test()
  { CALL
    CLocalBase* local_base_dyn = newex CLocalBase();
    local_base_dyn->test();

    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CLocalDerived::test()") << ln;
  }
};
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    CLocalFull local_full;
    local_full.test();

    CLocalDerived local_derived;
    local_derived.test();

    // Error:
    // CLocalFull* local_full_dyn = newex CLocalFull();
    // local_full_dyn->test();

    // Error:
    // CLocalBase* local_base_dyn = newex CLocalBase();
    // local_base_dyn->test();

    // Error:
    // CLocalDerived* local_derived_dyn = newex CLocalDerived();
    // local_derived_dyn->test();

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
