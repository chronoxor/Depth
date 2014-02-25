/*!
 *  \file    example-containers-CSortedArray.cpp Example of using the
 *           CSortedArray class.
 *  \brief   Example of using the CSortedArray class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CSortedArray class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   19.03.2007 00:42:23

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
#include <Depth/include/base/CInteger.hpp>
#include <Depth/include/containers/CSortedArray.hpp>
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
// Write instance of the CSortedArray<Tschar> class into the given writer.
IWriter& operator << (IWriter& writer, const CSortedArray<Tschar>& a_crArray)
{ CALL
  writer << STR("CSortedArray<Tschar>(") << STR("size = ") << a_crArray.getSize() << STR(")") << ln;
  CSortedArray<Tschar>::TIteratorConst it = a_crArray.getItFirst();
  if (it.isValid())
  {
    writer << STR("{") << ln;
    do
    {
      writer << STR(" item = ") << *it << ln;
    } while (it.stepForward() == 1);
    writer << STR("}") << ln;
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

    CSortedArray<Tschar> a;

    // Fill the array.
    a.insert(ASC('F'));
    a.insert(ASC('C'));
    a.insert(ASC('G'));
    a.insert(ASC('B'));
    a.insert(ASC('H'));
    a.insert(ASC('A'));
    a.insert(ASC('D'));
    a.insert(ASC('I'));
    a.insert(ASC('E'));
    a.insert(ASC('f'));
    a.insert(ASC('c'));
    a.insert(ASC('g'));
    a.insert(ASC('b'));
    a.insert(ASC('h'));
    a.insert(ASC('a'));
    a.insert(ASC('d'));
    a.insert(ASC('i'));
    a.insert(ASC('e'));

    // Show the array.
    stdoutput << a;

    // Copy the array.
    CSortedArray<Tschar> b(a);

    // Show the copied array.
    stdoutput << b;

    // Remove items from the array.
    remove(stdoutput, b);

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Remove all items from the instance of the CSortedArray<Tschar> class.
  static void remove(IWriter& writer, CSortedArray<Tschar>& a_rArray)
  { CALL
    writer << STR("CSortedArray<Tschar>(") << STR("size = ") << a_rArray.getSize() << STR(")") << ln;
    CSortedArray<Tschar>::TIterator it = a_rArray.getItFirst();
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
