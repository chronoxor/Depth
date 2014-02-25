/*!
 *  \file    example-containers-CListSC.cpp Example of using the CListSC 
 *           class.
 *  \brief   Example of using the CListSC class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CListSC class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   10.01.2007 22:50:23

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
#include <Depth/include/containers/CListSC.hpp>
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

    CListSC<Tsint> a;

    // Fill the single circled list.
    a.insertNext(1);
    a.insertNext(2);
    a.insertNext(3);
    a.insertNext(4);
    a.insertNext(5);
    a.insertNext(6);
    a.stepForward();

    // Show the single circled list.
    show(stdoutput, a);

    // Copy the single circled list.
    CListSC<Tsint> b(a);

    // Reverse the single circled list.
    b.reverse();

    // Show the reversed single circled list.
    show(stdoutput, b);

    // Remove items from the single circled list.
    remove(stdoutput, a);

    // Clear the reversed single circled list.
    b.clear();

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write instance of the CListSC<Tsint> class into the given writer.
  static void show(IWriter& writer, const CListSC<Tsint>& a_crList)
  { CALL
    writer << STR("CListSC<Tsint>(") << STR("size = ") << a_crList.getSize() << STR(")") << ln;
    CListSC<Tsint>::TIteratorConst it = a_crList.getItCurrent();
    if (it.isValid())
    {
      writer << STR("{") << ln;
      do
      {
        writer << STR(" item = ") << *it << ln;
      } while ((it.stepForward() == 1) && (it != a_crList.getItCurrent()));
      writer << STR("}") << ln;
    }
  }

  // Remove all items from the instance of the CListSC<Tsint> class.
  static void remove(IWriter& writer, CListSC<Tsint>& a_rList)
  { CALL
    writer << STR("CListSC<Tsint>(") << STR("size = ") << a_rList.getSize() << STR(")") << ln;
    CListSC<Tsint>::TIterator it = a_rList.getItCurrent();
    writer << STR("{") << ln;
    while (it.isValid())
    {
      writer << STR(" removed item = ") << *it << ln;
      it.removeNext();
    }
    writer << STR("}") << ln;
  }
} the_Application;
/*==========================================================================*/
