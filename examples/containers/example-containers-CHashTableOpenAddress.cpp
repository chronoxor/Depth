/*!
 *  \file    example-containers-CHashTableOpenAddress.cpp Example of using 
 *           the CHashTableOpenAddress class.
 *  \brief   Example of using the CHashTableOpenAddress class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CHashTableOpenAddress class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   13.06.2008 21:40:26

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
#include <Depth/include/containers/CHashTableOpenAddress.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*==========================================================================*/
// Write instance of the CHashTableOpenAddress<Tcsstr, Tsint> class into the given writer.
IWriter& operator << (IWriter& writer, const CHashTableOpenAddress<Tcsstr, Tsint>& a_crHashTable)
{ CALL
  writer << STR("CHashTableOpenAddress<Tcsstr, Tsint>(") << STR("size = ") << a_crHashTable.getSize() << STR(")") << ln;
  CHashTableOpenAddress<Tcsstr, Tsint>::TIteratorConst it = a_crHashTable.getItFirst();
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

    CHashTableOpenAddress<Tcsstr, Tsint> a;

    // Fill the hash table.
    a.insert(ASC("abc"), 1);
    a.insert(ASC("abcd"), 2);
    a.insert(ASC("abcde"), 3);
    a[ASC("abcdef")].getValueRef() = 4;
    a[ASC("abcdefg")].getValueRef() = 5;
    a[ASC("abcdefgh")].getValueRef() = 6;

    // Find hash table items.
    stdoutput << STR("find key '") << a[ASC("abc")].getKeyRef() << STR("' = ") << a[ASC("abc")].getValueRef() << ln;
    stdoutput << STR("find key '") << a[ASC("abcd")].getKeyRef() << STR("' = ") << a[ASC("abcd")].getValueRef() << ln;
    stdoutput << STR("find key '") << a[ASC("abcde")].getKeyRef() << STR("' = ") << a[ASC("abcde")].getValueRef() << ln;

    // Show the hash table.
    stdoutput << a;

    // Copy the hash table.
    CHashTableOpenAddress<Tcsstr, Tsint> b(a);

    // Show the copied hash table.
    stdoutput << b;

    // Remove items from the hash table.
    remove(stdoutput, b);

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Remove all items from the instance of the CHashTableOpenAddress<Tcsstr, Tsint> class.
  static void remove(IWriter& writer, CHashTableOpenAddress<Tcsstr, Tsint>& a_rHashTable)
  { CALL
    writer << STR("CHashTableOpenAddress<Tcsstr, Tsint>(") << STR("size = ") << a_rHashTable.getSize() << STR(")") << ln;
    CHashTableOpenAddress<Tcsstr, Tsint>::TIterator it = a_rHashTable.getItFirst();
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
