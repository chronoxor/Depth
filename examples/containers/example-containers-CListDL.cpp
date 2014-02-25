/*!
 *  \file    example-containers-CListDL.cpp Example of using the CListDL 
 *           class.
 *  \brief   Example of using the CListDL class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CListDL class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   10.01.2007 21:11:46

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
#include <Depth/include/containers/CListDL.hpp>
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

    CListDL<Tsint> a;
    CListDL<Tsint> b;

    // Fill the first double linked list.
    a.insertFirst(1);
    a.insertFirst(2);
    a.insertFirst(3);
    a.insertFirst(4);
    a.insertFirst(5);
    a.insertFirst(6);
    // Fill the second double linked list.
    b.insertLast(1);
    b.insertLast(2);
    b.insertLast(3);
    b.insertLast(4);
    b.insertLast(5);
    b.insertLast(6);

    // Show the first double linked list.
    show(stdoutput, a, true);
    // Show the second double linked list.
    show(stdoutput, b, false);

    // Copy double linked lists.
    CListDL<Tsint> c(a);
    CListDL<Tsint> d(b);

    // Reverse double linked lists.
    c.reverse();
    d.reverse();

    // Show the first reversed double linked list.
    show(stdoutput, c, true);
    // Show the second reversed double linked list.
    show(stdoutput, d, false);

    // Remove items from double linked lists.
    remove(stdoutput, c, true);
    remove(stdoutput, d, false);

    // Clear reversed double linked lists.
    c.clear();
    d.clear();

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write instance of the CListDL<Tsint> class into the given writer.
  static void show(IWriter& writer, const CListDL<Tsint>& a_crList, const Tbool a_cDirectOrder)
  { CALL
    writer << STR("CListDL<Tsint>(") << STR("size = ") << a_crList.getSize() << STR(")") << ln;
    CListDL<Tsint>::TIteratorConst it = (a_cDirectOrder ? a_crList.getItFirst() : a_crList.getItLast());
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

  // Remove all items from the instance of the CListDL<Tsint> class.
  static void remove(IWriter& writer, CListDL<Tsint>& a_rList, const Tbool a_cDirectOrder)
  { CALL
    writer << STR("CListDL<Tsint>(") << STR("size = ") << a_rList.getSize() << STR(")") << ln;
    CListDL<Tsint>::TIterator it = (a_cDirectOrder ? a_rList.getItFirst() : a_rList.getItLast());
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
