/*!
 *  \file    example-containers-CMultiset.cpp Example of using the CMultiset 
 *           class.
 *  \brief   Example of using the CMultiset class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CMultiset class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   27.03.2007 02:47:39

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
#include <Depth/include/containers/CMultiset.hpp>
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

    CMultiset<Tsint> a;

    // Fill the multiset.
    a.insert(6);
    a.insert(3);
    a.insert(7);
    a.insert(2);
    a.insert(8);
    a.insert(1);
    a.insert(4);
    a.insert(9);
    a.insert(5);
    a.insert(6);
    a.insert(3);
    a.insert(7);
    a.insert(2);
    a.insert(8);
    a.insert(1);
    a.insert(4);
    a.insert(9);
    a.insert(5);

    // Show the multiset.
    show(stdoutput, a);

    // Copy the multiset.
    CMultiset<Tsint> b(a);

    // Show the copied multiset.
    show(stdoutput, b);

    // Remove items from the multiset.
    remove(stdoutput, b);

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write instance of the CMultiset<Tsint> class into the given writer.
  static void show(IWriter& writer, const CMultiset<Tsint>& a_crMultiset)
  { CALL
    writer << STR("CMultiset<Tsint>(") << STR("size = ") << a_crMultiset.getSize() << STR(")") << ln;
    CMultiset<Tsint>::TIteratorConst it = a_crMultiset.getItFirst();
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

  // Remove all items from the instance of the CMultiset<Tsint> class.
  static void remove(IWriter& writer, CMultiset<Tsint>& a_rMultiset)
  { CALL
    writer << STR("CMultiset<Tsint>(") << STR("size = ") << a_rMultiset.getSize() << STR(")") << ln;
    CMultiset<Tsint>::TIterator it = a_rMultiset.getItFirst();
    writer << STR("{") << ln;
    while (it.isValid())
    {
      writer << STR(" removed item = ") << *it << ln;
      it.remove();
    }
    writer << STR("}") << ln;
  }
} the_Application;
/*==========================================================================*/
