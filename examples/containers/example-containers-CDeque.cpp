/*!
 *  \file    example-containers-CDeque.cpp Example of using the CDeque class.
 *  \brief   Example of using the CDeque class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CDeque class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   10.01.2007 21:01:25

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
#include <Depth/include/containers/CDeque.hpp>
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

    CDeque<Tsint> a;
    CDeque<Tsint> b;

    // Fill the first deque.
    a.insertFirst(1);
    a.insertFirst(2);
    a.insertFirst(3);
    a.insertFirst(4);
    a.insertFirst(5);
    a.insertFirst(6);
    // Fill the second deque.
    b.insertLast(1);
    b.insertLast(2);
    b.insertLast(3);
    b.insertLast(4);
    b.insertLast(5);
    b.insertLast(6);

    // Show the first deque.
    show(stdoutput, a, true);
    // Show the second deque.
    show(stdoutput, b, false);

    // Copy deques.
    CDeque<Tsint> c(a);
    CDeque<Tsint> d(b);

    // Reverse deques.
    c.reverse();
    d.reverse();

    // Show the first reversed deque.
    show(stdoutput, c, true);
    // Show the second reversed deque.
    show(stdoutput, d, false);

    // Remove items from deques.
    remove(stdoutput, c, true);
    remove(stdoutput, d, false);

    // Clear reversed deques.
    c.clear();
    d.clear();

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write instance of the CDeque<Tsint> class into the given writer.
  static void show(IWriter& writer, const CDeque<Tsint>& a_crDeque, const Tbool a_cDirectOrder)
  { CALL
    writer << STR("CDeque<Tsint>(") << STR("size = ") << a_crDeque.getSize() << STR(")") << ln;
    CDeque<Tsint>::TIteratorConst it = (a_cDirectOrder ? a_crDeque.getItFirst() : a_crDeque.getItLast());
    if (it.isValid())
    {
      writer << STR("{") << ln;
      do
      {
        writer << STR(" item = ") << *it << ln;
      } while ((a_cDirectOrder ? it.stepForward() : it.stepBackward()) == 1);
      writer << STR("}") << ln;
    }
  }

  // Remove all items from the instance of the CDeque<Tsint> class.
  static void remove(IWriter& writer, CDeque<Tsint>& a_rDeque, const Tbool a_cDirectOrder)
  { CALL
    writer << STR("CDeque<Tsint>(") << STR("size = ") << a_rDeque.getSize() << STR(")") << ln;
    CDeque<Tsint>::TIterator it = (a_cDirectOrder ? a_rDeque.getItFirst() : a_rDeque.getItLast());
    writer << STR("{") << ln;
    while (it.isValid())
    {
      writer << STR(" removed item = ") << *it << ln;
      a_cDirectOrder ? it.removeForward() : it.removeBackward();
    }
    writer << STR("}") << ln;
  }
} the_Application;
/*==========================================================================*/
