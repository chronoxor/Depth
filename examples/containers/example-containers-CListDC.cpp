/*!
 *  \file    example-containers-CListDC.cpp Example of using the CListDC 
 *           class.
 *  \brief   Example of using the CListDC class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CListDC class.

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
#include <Depth/include/containers/CListDC.hpp>
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

    CListDC<Tsint> a;
    CListDC<Tsint> b;

    // Fill the first double circled list.
    a.insertCurrentForward(1);
    a.insertNext(2);
    a.insertNext(3);
    a.insertNext(4);
    a.insertNext(5);
    a.insertNext(6);
    a.stepForward();
    // Fill the second double circled list.
    b.insertCurrentBackward(6);
    b.insertPrev(5);
    b.insertPrev(4);
    b.insertPrev(3);
    b.insertPrev(2);
    b.insertPrev(1);
    b.stepBackward();

    // Show the first double circled list.
    show(stdoutput, a, true);
    // Show the second double circled list.
    show(stdoutput, b, false);

    // Copy double circled lists.
    CListDC<Tsint> c(a);
    CListDC<Tsint> d(b);

    // Reverse double circled lists.
    c.reverse();
    d.reverse();

    // Show the first reversed double circled list.
    c.stepForward();
    show(stdoutput, c, true);
    // Show the second reversed double circled list.
    d.stepBackward();
    show(stdoutput, d, false);

    // Remove items from double circled lists.
    remove(stdoutput, c, true);
    remove(stdoutput, d, false);

    // Clear reversed double circled lists.
    c.clear();
    d.clear();

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write instance of the CListDC<Tsint> class into the given writer.
  static void show(IWriter& writer, const CListDC<Tsint>& a_crList, const Tbool a_cDirectOrder)
  { CALL
    writer << STR("CListDC<Tsint>(") << STR("size = ") << a_crList.getSize() << STR(")") << ln;
    CListDC<Tsint>::TIteratorConst it = a_crList.getItCurrent();
    if (it.isValid())
    {
      writer << STR("{") << ln;
      do
      {
        writer << STR(" item = ") << *it << ln;
      } while (((a_cDirectOrder ? it.stepForward() : it.stepBackward()) == 1) &&  (it != a_crList.getItCurrent()));
      writer << STR("}") << ln;
    }
  }

  // Remove all items from the instance of the CListDC<Tsint> class.
  static void remove(IWriter& writer, CListDC<Tsint>& a_rList, const Tbool a_cDirectOrder)
  { CALL
    writer << STR("CListDC<Tsint>(") << STR("size = ") << a_rList.getSize() << STR(")") << ln;
    CListDC<Tsint>::TIterator it = a_rList.getItCurrent();
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
