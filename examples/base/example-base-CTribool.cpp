/*!
 *  \file    example-base-CTribool.cpp Example of using the CTribool class.
 *  \brief   Example of using the CTribool class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CTribool class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth base examples
    VERSION:   1.0
    CREATED:   17.01.2007 02:46:32

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
#include <Depth/include/base/CTribool.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NBase;
/*==========================================================================*/
// Write value of the CTribool::ETriboolState enumeration into the given writer.
IWriter& operator << (IWriter& writer, const CTribool::ETriboolState& a_crTriboolState)
{ CALL
  switch (a_crTriboolState)
  {
    case CTribool::e_FALSE:
      writer << STR("false");
      break;
    case CTribool::e_TRUE:
      writer << STR("true");
      break;
    case CTribool::e_NULL:
      writer << STR("null");
      break;
  }
  return writer;
}
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

    CTribool a(true);
    CTribool b(a && false);
    CTribool c(a && CTribool::e_NULL);

    CTribool::ETriboolState d = CTribool::getConjuction(CTribool::e_NULL, CTribool::e_TRUE);
    CTribool::ETriboolState e = CTribool::getDisjunction(CTribool::e_NULL, CTribool::e_FALSE);

    stdoutput << STR("a = ") << (CTribool::ETriboolState)a << ln;
    stdoutput << STR("b = ") << (CTribool::ETriboolState)b << ln;
    stdoutput << STR("c = ") << (CTribool::ETriboolState)c << ln;
    stdoutput << STR("d = ") << (CTribool::ETriboolState)d << ln;
    stdoutput << STR("e = ") << (CTribool::ETriboolState)e << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
