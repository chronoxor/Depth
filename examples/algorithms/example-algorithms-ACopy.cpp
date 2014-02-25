/*!
 *  \file    example-algorithms-ACopy.cpp Example of using the iterator copy
 *           algorithm.
 *  \brief   Example of using the iterator copy algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the iterator copy algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms examples
    VERSION:   1.0
    CREATED:   10.05.2007 22:30:24

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
#include <Depth/include/algorithms/containers/ACopy.hpp>
#include <Depth/include/algorithms/containers/ACopyIf.hpp>
#include <Depth/include/containers/CArray.hpp>
#include <Depth/include/containers/CListDC.hpp>
#include <Depth/include/containers/CListDL.hpp>
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
// Write instance of the CListDC<Tsint> class into the given writer.
IWriter& operator << (IWriter& writer, const CListDC<Tsint>& a_crList)
{ CALL
  writer << STR("CListDC<Tsint>(") << STR("size = ") << a_crList.getSize() << STR(")") << ln;
  CListDC<Tsint>::TIteratorConst it = a_crList.getItCurrent();
  if (it.isValid())
  {
    writer << STR("{") << ln;
    do
    {
      writer << STR(" item = ") << *it << ln;
    } while ((it.stepForward() == 1) &&  (it != a_crList.getItCurrent()));
    writer << STR("}") << ln;
  }
  return writer;
}
/*--------------------------------------------------------------------------*/
// Write instance of the CListDL<Tsint> class into the given writer.
IWriter& operator << (IWriter& writer, const CListDL<Tsint>& a_crList)
{ CALL
  writer << STR("CListDL<Tsint>(") << STR("size = ") << a_crList.getSize() << STR(")") << ln;
  CListDL<Tsint>::TIteratorConst it = a_crList.getItFirst();
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
  // Odd number check static method.
  static Tbool isOdd(const Tsint& a_crValue)
  { CALL
    return ((a_crValue & 1) != 0);
  }

  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    CArray<Tsint> array;
    CListDC<Tsint> circle;
    CListDL<Tsint> list;

    // Fill the array.
    array.insertLast(1);
    array.insertLast(2);
    array.insertLast(3);
    array.insertLast(4);
    array.insertLast(5);
    array.insertLast(6);

    // Copy the array into the double circled list.
    copy(array, circle);
    stdoutput << circle << ln;

    // Copy the array into the double linked list.
    copy(array, list);
    stdoutput << list << ln;

    circle.clear();
    list.clear();

    // Copy the array into the double circled list.
    copyIf(array, circle, isOdd);
    stdoutput << circle << ln;

    // Copy the array into the double linked list.
    copyIf(array, list, isOdd);
    stdoutput << list << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
