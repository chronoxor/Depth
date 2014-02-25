/*!
 *  \file    example-algorithms-ALowerBound.cpp Example of using the lower 
 *           bound algorithm.
 *  \brief   Example of using the lower bound algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the lower bound algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms examples
    VERSION:   1.0
    CREATED:   15.03.2007 22:54:32

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
#include <Depth/include/algorithms/containers/ALowerBound.hpp>
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

    // Find lower bounds.
    stdoutput << STR("lowerBound(array, 0).getValueRef() = ") << lowerBound(array, CONSTS(0)).getValueRef() << ln;
    stdoutput << STR("lowerBound(array, 4).getValueRef() = ") << lowerBound(array, CONSTS(4)).getValueRef() << ln;
    stdoutput << STR("lowerBound(array, 8).isValid() = ") << lowerBound(array, CONSTS(8)).isValid() << ln;
    stdoutput << STR("lowerBoundPrev(array, 0).getValueRef() = ") << lowerBoundPrev(array.getItLast(), CONSTS(0)).getValueRef() << ln;
    stdoutput << STR("lowerBoundPrev(array, 4).getValueRef() = ") << lowerBoundPrev(array.getItLast(), CONSTS(4)).getValueRef() << ln;
    stdoutput << STR("lowerBoundPrev(array, 8).isValid() = ") << lowerBoundPrev(array.getItLast(), CONSTS(8)).isValid() << ln;
    stdoutput << STR("lowerBound(circle, 0).getValueRef() = ") << lowerBound(circle, CONSTS(0)).getValueRef() << ln;
    stdoutput << STR("lowerBound(circle, 4).getValueRef() = ") << lowerBound(circle, CONSTS(4)).getValueRef() << ln;
    stdoutput << STR("lowerBound(circle, 8).isValid() = ") << lowerBound(circle, CONSTS(8)).isValid() << ln;
    stdoutput << STR("lowerBoundPrev(circle, 0).getValueRef() = ") << lowerBoundPrev(circle.getItCurrent().getBackward(), CONSTS(0)).getValueRef() << ln;
    stdoutput << STR("lowerBoundPrev(circle, 4).getValueRef() = ") << lowerBoundPrev(circle.getItCurrent().getBackward(), CONSTS(4)).getValueRef() << ln;
    stdoutput << STR("lowerBoundPrev(circle, 8).isValid() = ") << lowerBoundPrev(circle.getItCurrent().getBackward(), CONSTS(8)).isValid() << ln;
    stdoutput << STR("lowerBound(list, 0).getValueRef() = ") << lowerBound(list, CONSTS(0)).getValueRef() << ln;
    stdoutput << STR("lowerBound(list, 4).getValueRef() = ") << lowerBound(list, CONSTS(4)).getValueRef() << ln;
    stdoutput << STR("lowerBound(list, 8).isValid() = ") << lowerBound(list, CONSTS(8)).isValid() << ln;
    stdoutput << STR("lowerBoundPrev(list, 0).getValueRef() = ") << lowerBoundPrev(list.getItLast(), CONSTS(0)).getValueRef() << ln;
    stdoutput << STR("lowerBoundPrev(list, 4).getValueRef() = ") << lowerBoundPrev(list.getItLast(), CONSTS(4)).getValueRef() << ln;
    stdoutput << STR("lowerBoundPrev(list, 8).isValid() = ") << lowerBoundPrev(list.getItLast(), CONSTS(8)).isValid() << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
