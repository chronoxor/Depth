/*!
 *  \file    example-containers-CStack.cpp Example of using the CStack class.
 *  \brief   Example of using the CStack class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CStack class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   26.01.2007 23:09:35

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
#include <Depth/include/containers/CStack.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
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

    CStack<Tsint> a;

    // Fill the stack.
    a.insertTop(1);
    a.insertTop(2);
    a.insertTop(3);
    a.insertTop(4);
    a.insertTop(5);
    a.insertTop(6);

    // Show the stack.
    show(stdoutput, a);

    // Copy the stack.
    CStack<Tsint> b(a);

    // Reverse the stack.
    b.reverse();

    // Show the reversed stack.
    show(stdoutput, b);

    // Remove items from the stack.
    remove(stdoutput, a);

    // Clear the reversed stack.
    b.clear();

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write instance of the CStack<Tsint> class into the given writer.
  static void show(IWriter& writer, const CStack<Tsint>& a_crStack)
  { CALL
    writer << STR("CStack<Tsint>(") << STR("size = ") << a_crStack.getSize() << STR(")") << ln;
    CStack<Tsint>::TIteratorConst it = a_crStack.getItTop();
    if (it.isValid())
    {
      writer << STR("{") << ln;
      do
      {
        writer << STR(" item = ") << *it << ln;
      } while (it.stepForward() == 1);
      writer << STR("}") << ln;
    }
  }

  // Remove all items from the instance of the CStack<Tsint> class.
  static void remove(IWriter& writer, CStack<Tsint>& a_rStack)
  { CALL
    writer << STR("CStack<Tsint>(") << STR("size = ") << a_rStack.getSize() << STR(")") << ln;
    CStack<Tsint>::TIterator it = a_rStack.getItTop();
    writer << STR("{") << ln;
    while (it.isValid())
    {
      writer << STR(" removed item = ") << *it << ln;
      it.removeForward();
    }
    writer << STR("}") << ln;
  }
} the_Application;
/*==========================================================================*/
