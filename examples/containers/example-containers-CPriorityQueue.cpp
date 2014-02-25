/*!
 *  \file    example-containers-CPriorityQueue.cpp Example of using the
 *           CPriorityQueue class.
 *  \brief   Example of using the CPriorityQueue class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CPriorityQueue class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   07.05.2007 01:21:52

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
#include <Depth/include/containers/CPriorityQueue.hpp>
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

    CPriorityQueue<Tschar> a;

    // Fill the priority queue.
    a.insert(ASC('F'), 6);
    a.insert(ASC('C'), 3);
    a.insert(ASC('G'), 7);
    a.insert(ASC('B'), 2);
    a.insert(ASC('H'), 8);
    a.insert(ASC('A'), 1);
    a.insert(ASC('D'), 4);
    a.insert(ASC('I'), 9);
    a.insert(ASC('E'), 5);
    a.insert(ASC('f'), 6);
    a.insert(ASC('c'), 3);
    a.insert(ASC('g'), 7);
    a.insert(ASC('b'), 2);
    a.insert(ASC('h'), 8);
    a.insert(ASC('a'), 1);
    a.insert(ASC('d'), 4);
    a.insert(ASC('i'), 9);
    a.insert(ASC('e'), 5);

    // Show the priority queue.
    show(stdoutput, a);

    // Copy the priority queue.
    CPriorityQueue<Tschar> b(a);

    // Show the copied priority queue.
    show(stdoutput, b);

    // Remove items from the priority queue.
    remove(stdoutput, b);

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write instance of the CPriorityQueue<Tschar> class into the given writer.
  static void show(IWriter& writer, const CPriorityQueue<Tschar>& a_crQueue)
  { CALL
    writer << STR("CPriorityQueue<Tschar>(") << STR("size = ") << a_crQueue.getSize() << STR(")") << ln;
    CPriorityQueue<Tschar>::TIteratorConst it = a_crQueue.getItFirst();
    if (it.isValid())
    {
      writer << STR("{") << ln;
      do
      {
        writer << STR(" item = ") << *it << STR(" (priority = ") << it.getPriorityRef() << STR(")") << ln;
      } while (it.stepForward() == 1);
      writer << STR("}") << ln;
    }
  }

  // Remove all items from the instance of the CPriorityQueue<Tschar> class.
  static void remove(IWriter& writer, CPriorityQueue<Tschar>& a_rQueue)
  { CALL
    writer << STR("CPriorityQueue<Tschar>(") << STR("size = ") << a_rQueue.getSize() << STR(")") << ln;
    CPriorityQueue<Tschar>::TIterator it = a_rQueue.getItFirst();
    writer << STR("{") << ln;
    while (it.isValid())
    {
      writer << STR(" removed item = ") << *it << STR(" (priority = ") << it.getPriorityRef() << STR(")") << ln;
      it.remove();
    }
    writer << STR("}") << ln;
  }
} the_Application;
/*==========================================================================*/
