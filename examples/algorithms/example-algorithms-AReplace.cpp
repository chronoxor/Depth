/*!
 *  \file    example-algorithms-AReplace.cpp Example of using the iterator 
 *           replace algorithm.
 *  \brief   Example of using the iterator replace algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the iterator replace algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms examples
    VERSION:   1.0
    CREATED:   11.06.2007 23:05:32

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
#include <Depth/include/algorithms/containers/AReplace.hpp>
#include <Depth/include/algorithms/containers/AReplaceIf.hpp>
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
  // Even number check static method.
  static Tbool isEven(const Tsint& a_crValue)
  { CALL
    return ((a_crValue & 1) == 0);
  }

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

    // Replace items.
    stdoutput << STR("replace(array, 2, 200) = ") << replace(array, CONSTS(2), CONSTS(200)) << ln;
    stdoutput << STR("replacePrev(array, 4, 400) = ") << replacePrev(array.getItLast(), CONSTS(4), CONSTS(400)) << ln;
    stdoutput << STR("replace(circle, 2, 200) = ") << replace(circle, CONSTS(2), CONSTS(200)) << ln;
    stdoutput << STR("replacePrev(circle, 4, 400) = ") << replacePrev(circle.getItCurrent().getBackward(), CONSTS(4), CONSTS(400)) << ln;
    stdoutput << STR("replace(list, 2, 200) = ") << replace(list, CONSTS(2), CONSTS(200)) << ln;
    stdoutput << STR("replacePrev(list, 4, 400) = ") << replacePrev(list.getItLast(), CONSTS(4), CONSTS(400)) << ln;

    // Replace conditional items.
    stdoutput << STR("replaceIf(array, 1, isOdd) = ") << replaceIf(array, CONSTS(1), isOdd) << ln;
    stdoutput << STR("replaceIfPrev(array, 2, isEven) = ") << replaceIfPrev(array.getItLast(), CONSTS(2), isEven) << ln;
    stdoutput << STR("replaceIf(circle, 1, isOdd) = ") << replaceIf(circle, CONSTS(1), isOdd) << ln;
    stdoutput << STR("replaceIfPrev(circle, 2, isEven) = ") << replaceIfPrev(circle.getItCurrent().getBackward(), CONSTS(2), isEven) << ln;
    stdoutput << STR("replaceIf(list, 1, isOdd) = ") << replaceIf(list, CONSTS(1), isOdd) << ln;
    stdoutput << STR("replaceIfPrev(list, 2, isEven) = ") << replaceIfPrev(list.getItLast(), CONSTS(2), isEven) << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
