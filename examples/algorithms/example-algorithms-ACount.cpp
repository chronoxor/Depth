/*!
 *  \file    example-algorithms-ACount.cpp Example of using the iterator 
 *           count algorithm.
 *  \brief   Example of using the iterator count algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the iterator count algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms examples
    VERSION:   1.0
    CREATED:   13.03.2007 20:51:22

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
#include <Depth/include/algorithms/containers/ACount.hpp>
#include <Depth/include/algorithms/containers/ACountIf.hpp>
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

    // Fill the double circled list.
    circle.insertCurrentForward(1);
    circle.insertNext(6);
    circle.insertNext(5);
    circle.insertNext(4);
    circle.insertNext(3);
    circle.insertNext(2);

    // Fill the double linked list.
    list.insertLast(1);
    list.insertLast(2);
    list.insertLast(3);
    list.insertLast(4);
    list.insertLast(5);
    list.insertLast(6);

    // Find counts.
    stdoutput << STR("count(array) = ") << count(array) << ln;
    stdoutput << STR("countPrev(array) = ") << countPrev(array.getItLast()) << ln;
    stdoutput << STR("count(circle) = ") << count(circle) << ln;
    stdoutput << STR("countPrev(circle) = ") << countPrev(circle.getItCurrent().getBackward()) << ln;
    stdoutput << STR("count(list) = ") << count(list) << ln;
    stdoutput << STR("countPrev(list) = ") << countPrev(list.getItLast()) << ln;

    // Find conditional counts.
    stdoutput << STR("countIf(array) = ") << countIf(array, isOdd) << ln;
    stdoutput << STR("countIfPrev(array) = ") << countIfPrev(array.getItLast(), isOdd) << ln;
    stdoutput << STR("countIf(circle) = ") << countIf(circle, isOdd) << ln;
    stdoutput << STR("countIfPrev(circle) = ") << countIfPrev(circle.getItCurrent().getBackward(), isOdd) << ln;
    stdoutput << STR("countIf(list) = ") << countIf(list, isOdd) << ln;
    stdoutput << STR("countIfPrev(list) = ") << countIfPrev(list.getItLast(), isOdd) << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
