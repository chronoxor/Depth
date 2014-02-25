/*!
 *  \file    example-algorithms-ACast.cpp Example of using the cast 
 *           algorithms.
 *  \brief   Example of using the cast algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the cast algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms examples
    VERSION:   1.0
    CREATED:   17.01.2007 22:55:38

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
#include <Depth/include/algorithms/common/ACast.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NCommon;
/*==========================================================================*/
class CNonPolymorphicBase
{
public:
  Tuint test()
  { CALL
    return 0;
  }
};
/*--------------------------------------------------------------------------*/
class CNonPolymorphicDerived :
  public CNonPolymorphicBase
{
public:
  Tuint test()
  { CALL
    return 1;
  }
};
/*==========================================================================*/
class CPolymorphicBase
{
public:
  virtual ~CPolymorphicBase()
  {

  }

  virtual Tuint test()
  { CALL
    return 0;
  }
};
/*--------------------------------------------------------------------------*/
class CPolymorphicDerived :
  public CPolymorphicBase
{
public:
  virtual ~CPolymorphicDerived()
  {

  }

  virtual Tuint test()
  { CALL
    return 1;
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

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    // Non polymorphic cast.
    CNonPolymorphicBase* a = newex CNonPolymorphicDerived();
    CNonPolymorphicDerived* b = nonPolymorphicCast<CNonPolymorphicDerived*>(a);

    if (b != NULL)
      stdoutput << STR("Non polymorphic: Dynamic cast success!") << ln;
    else
      stdoutput << STR("Non polymorphic: Dynamic cast failed!") << ln;

    delete a;

    // Polymorphic cast.
    CPolymorphicBase* c = newex CPolymorphicDerived();
    CPolymorphicDerived* d = nonPolymorphicCast<CPolymorphicDerived*>(c);

    if (d != NULL)
      stdoutput << STR("Polymorphic: Dynamic cast success!") << ln;
    else
      stdoutput << STR("Polymorphic: Dynamic cast failed!") << ln;

    delete c;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
