/*!
 *  \file    example-algorithms-ASetsSubtraction.cpp Example of using the 
 *           iterator sets subtraction algorithms.
 *  \brief   Example of using the iterator sets subtraction algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the iterator sets subtraction algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms examples
    VERSION:   1.0
    CREATED:   30.08.2007 22:16:43

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
#include <Depth/include/algorithms/containers/ASetsSubtraction.hpp>
#include <Depth/include/algorithms/containers/ASetsSubtractionCopy.hpp>
#include <Depth/include/algorithms/containers/ASetsSubtractionCount.hpp>
#include <Depth/include/containers/CArray.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NContainers;
using namespace NDepth::NAlgorithms::NIterators;
/*==========================================================================*/
// Write instance of the CArray<Tsint> class into the given writer.
IWriter& operator << (IWriter& writer, const CArray<Tsint>& a_crArray)
{ CALL
  writer << STR("CArray<Tsint>(") << STR("size = ") << a_crArray.getSize() << STR(")") << ln;
  CArray<Tsint>::TIteratorConst it = a_crArray.getItFirst();
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

    CArray<Tsint> array1;
    CArray<Tsint> array2;
    CArray<Tsint> array_result;

    // Fill the first array.
    array1.insertLast(1);
    array1.insertLast(3);
    array1.insertLast(4);
    array1.insertLast(4);
    array1.insertLast(5);
    array1.insertLast(5);
    array1.insertLast(6);
    array1.insertLast(7);

    // Fill the last array.
    array2.insertLast(2);
    array2.insertLast(3);
    array2.insertLast(4);
    array2.insertLast(4);
    array2.insertLast(5);

    // Print the count of elements in subtraction of two sets.
    stdoutput << STR("Subtractions count = ") << setsSubtractionCount(array1, array2) << ln;

    // Find and copy subtraction of two sets.
    setsSubtractionCopy(array1, array2, array_result);
    stdoutput << array_result << ln;

    // Find subtraction of two sets.
    setsSubtraction(array1, array2);
    stdoutput << array1 << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
