/*!
 *  \file    example-containers-CSparseArray.cpp Example of using the 
 *           CSparseArray class.
 *  \brief   Example of using the CSparseArray class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CSparseArray class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   04.03.2008 02:45:31

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
#include <Depth/include/containers/CSparseArray.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*==========================================================================*/
// Write instance of the CSparseArray<Tsint> class into the given writer.
IWriter& operator << (IWriter& writer, const CSparseArray<Tsint>& a_crArray)
{ CALL
  writer << STR("CSparseArray<Tsint>(") << STR("size = ") << a_crArray.getSize() << STR(")") << ln;
  CSparseArray<Tsint>::TAssociativeContainer::TIteratorConst it = a_crArray.getItFirst().getSparse();
  if (it.isValid())
  {
    writer << STR("{") << ln;
    do
    {
      writer << STR(" item = ") << it.getValueRef().getBuffer()[0] << STR(", ") << it.getValueRef().getBuffer()[it.getValueRef().getLength() - 1] << ln;
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

    CSparseArray<Tsint> a;

    // Fill the sparse array.
    a.fillIndex(1, 1);
    a.fillIndex(3, 3);
    a.fillIndex(5, 5);
    a.fillIndex(7, 7);
    a.fillIndex(9, 9);

    // Show the sparse array.
    stdoutput << a;

    // Join intervals.
    a.fillIndex(2, 2);
    a.fillIndex(4, 4);
    a.fillIndex(6, 6);
    a.fillIndex(8, 8);

    // Show the sparse array.
    stdoutput << a;

    // Copy the sparse array.
    CSparseArray<Tsint> b(a);

    // Show the copied sparse array.
    stdoutput << b;

    // Erase items from the sparse array.
    a.eraseIndex(1);
    a.eraseIndex(3);
    a.eraseIndex(5);
    a.eraseIndex(7);
    a.eraseIndex(9);

    // Show the sparse array.
    stdoutput << a;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
