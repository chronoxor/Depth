/*!
 *  \file    example-algorithms-AGenerateN.cpp Example of using the iterator
 *           generate N items algorithm.
 *  \brief   Example of using the iterator generate N items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the iterator generate N items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms examples
    VERSION:   1.0
    CREATED:   23.05.2007 22:38:53

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
#include <Depth/include/algorithms/containers/AGenerateN.hpp>
#include <Depth/include/algorithms/functions/FIncrement.hpp>
#include <Depth/include/algorithms/functions/FDecrement.hpp>
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
using namespace NDepth::NAlgorithms::NFunctions;
/*==========================================================================*/
class FMyIncrement :
  public FIncrement<Tuint>
{
public:
  FMyIncrement(const Tuint a_cInitialValue) :
    FIncrement<Tuint>(a_cInitialValue)
  {
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("FMyIncrement(") << a_cInitialValue << STR(")") << ln;
  }

  Tuint operator () () const
  {
    Tuint value = FIncrement<Tuint>::operator()();

    CStreamStdOutput stdoutput(true);
    stdoutput << STR("FMyIncrement::operator() = ") << value << ln;
    return value;
  }
};
/*--------------------------------------------------------------------------*/
class FMyDecrement :
  public FDecrement<Tuint>
{
public:
  FMyDecrement(const Tuint a_cInitialValue) :
    FDecrement<Tuint>(a_cInitialValue)
  {
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("FMyDecrement(") << a_cInitialValue << STR(")") << ln;
  }

  Tuint operator () () const
  {
    Tuint value = FDecrement<Tuint>::operator()();

    CStreamStdOutput stdoutput(true);
    stdoutput << STR("FMyDecrement::operator() = ") << value << ln;
    return value;
  }
};
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

    // Generate containers.
    stdoutput << STR("generateN(array, 10, FMyIncrement(10)) = ") << generateN(array, 10, FMyIncrement(0)) << ln;
    stdoutput << STR("generateN(circle, 10, FMyDecrement(10)) = ") << generateN(circle, 10, FMyDecrement(9)) << ln;
    stdoutput << STR("generateN(list, 10, FMyIncrement(10)) = ") << generateN(list, 10, FMyIncrement(0)) << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
