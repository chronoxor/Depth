/*!
 *  \file    example-containers-CMap.cpp Example of using the CMap class.
 *  \brief   Example of using the CMap class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CMap class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   27.03.2007 02:40:31

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
#include <Depth/include/containers/CMap.hpp>
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

    CMap<Tsint, Tschar> a;

    // Fill the map.
    a.insert(6, ASC('F'));
    a.insert(3, ASC('C'));
    a.insert(7, ASC('G'));
    a.insert(2, ASC('B'));
    a.insert(8, ASC('H'));
    a.insert(1, ASC('A'));
    a.insert(4, ASC('D'));
    a.insert(9, ASC('I'));
    a.insert(5, ASC('E'));
    a.insert(6, ASC('f'));
    a.insert(3, ASC('c'));
    a.insert(7, ASC('g'));
    a.insert(2, ASC('b'));
    a.insert(8, ASC('h'));
    a.insert(1, ASC('a'));
    a.insert(4, ASC('d'));
    a.insert(9, ASC('i'));
    a.insert(5, ASC('e'));

    // Show the map.
    show(stdoutput, a);

    // Copy the map.
    CMap<Tsint, Tschar> b(a);

    // Show the copied map.
    show(stdoutput, b);

    // Remove items from the map.
    remove(stdoutput, b);

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write instance of the CMap<Tsint, Tschar> class into the given writer.
  static void show(IWriter& writer, const CMap<Tsint, Tschar>& a_crMap)
  { CALL
    writer << STR("CMap<Tsint, Tschar>(") << STR("size = ") << a_crMap.getSize() << STR(")") << ln;
    CMap<Tsint, Tschar>::TIteratorConst it = a_crMap.getItFirst();
    if (it.isValid())
    {
      writer << STR("{") << ln;
      do
      {
        writer << STR(" key = ") << it.getKeyRef() << STR(",");
        writer << STR(" item = ") << *it << ln;
      } while (it.stepForward() == 1);
      writer << STR("}") << ln;
    }
  }

  // Remove all items from the instance of the CMap<Tsint, Tschar> class.
  static void remove(IWriter& writer, CMap<Tsint, Tschar>& a_rMap)
  { CALL
    writer << STR("CMap<Tsint, Tschar>(") << STR("size = ") << a_rMap.getSize() << STR(")") << ln;
    CMap<Tsint, Tschar>::TIterator it = a_rMap.getItFirst();
    writer << STR("{") << ln;
    while (it.isValid())
    {
      writer << STR(" removed key = ") << it.getKeyRef() << STR(",");
      writer << STR(" removed item = ") << *it << ln;
      it.remove();
    }
    writer << STR("}") << ln;
  }
} the_Application;
/*==========================================================================*/
