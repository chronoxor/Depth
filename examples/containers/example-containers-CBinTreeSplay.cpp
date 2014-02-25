/*!
 *  \file    example-containers-CBinTreeSplay.cpp Example of using the
 *           CBinTreeSplay class.
 *  \brief   Example of using the CBinTreeSplay class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CBinTreeSplay class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   23.03.2007 23:16:46

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
#include <Depth/include/containers/CBinTreeSplay.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*==========================================================================*/
// Write instance of the CBinTreeSplay<Tsint> class into the given writer.
IWriter& operator << (IWriter& writer, const CBinTreeSplay<Tsint>& a_crBinTree)
{ CALL
  writer << STR("CBinTreeSplay<Tsint>(") << STR("size = ") << a_crBinTree.getSize() << STR(")") << ln;
  CBinTreeSplay<Tsint>::TIteratorConst it = a_crBinTree.getItFirst();
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

    CBinTreeSplay<Tsint> a;

    // Fill the binary tree.
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

    // Show the binary tree.
    stdoutput << a;

    // Copy the binary tree.
    CBinTreeSplay<Tsint> b(a);

    // Show the copied binary tree.
    stdoutput << b;

    // Remove items from the binary tree.
    remove(stdoutput, b);

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Remove all items from the instance of the CBinTreeSplay<Tsint> class.
  static void remove(IWriter& writer, CBinTreeSplay<Tsint>& a_rBinTree)
  { CALL
    writer << STR("CBinTreeSplay<Tsint>(") << STR("size = ") << a_rBinTree.getSize() << STR(")") << ln;
    CBinTreeSplay<Tsint>::TIterator it = a_rBinTree.getItFirst();
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
