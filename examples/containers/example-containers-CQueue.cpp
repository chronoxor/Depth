/*!
 *  \file    example-containers-CQueue.cpp Example of using the CQueue class.
 *  \brief   Example of using the CQueue class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CQueue class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   10.01.2007 00:52:26

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
#include <Depth/include/containers/CQueue.hpp>
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

    CQueue<Tsint> a;

    // Fill the queue.
    a.insertLast(1);
    a.insertLast(2);
    a.insertLast(3);
    a.insertLast(4);
    a.insertLast(5);
    a.insertLast(6);

    // Show the queue.
    show(stdoutput, a);

    // Copy the queue.
    CQueue<Tsint> b(a);

    // Reverse the queue.
    b.reverse();

    // Show the reversed queue.
    show(stdoutput, b);

    // Remove items from the queue.
    remove(stdoutput, a);

    // Clear the reversed queue.
    b.clear();

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write instance of the CQueue<Tsint> class into the given writer.
  static void show(IWriter& writer, const CQueue<Tsint>& a_crQueue)
  { CALL
    writer << STR("CQueue<Tsint>(") << STR("size = ") << a_crQueue.getSize() << STR(")") << ln;
    CQueue<Tsint>::TIteratorConst it = a_crQueue.getItFirst();
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

  // Remove all items from the instance of the CQueue<Tsint> class.
  static void remove(IWriter& writer, CQueue<Tsint>& a_rQueue)
  { CALL
    writer << STR("CQueue<Tsint>(") << STR("size = ") << a_rQueue.getSize() << STR(")") << ln;
    CQueue<Tsint>::TIterator it = a_rQueue.getItFirst();
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
