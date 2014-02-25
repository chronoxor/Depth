/*!
 *  \file    example-geometry-CPoint2D.cpp Example of using the CPoint2D
 *           class.
 *  \brief   Example of using the CPoint2D class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CPoint2D class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry examples
    VERSION:   1.0
    CREATED:   24.06.2008 22:26:47

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
#include <Depth/include/geometry/CPoint2D.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NGeometry;
/*==========================================================================*/
// Write instance of the CPoint2D<Tsint> class into the given writer.
IWriter& operator << (IWriter& writer, const CPoint2D<Tsint>& a_crPoint)
{ CALL
  return writer << STR("CPoint2D<Tsint>(") << a_crPoint.m_X << STR(", ") << a_crPoint.m_Y << STR(")");
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

    CPoint2D<Tsint> point;
    stdoutput << STR("CPoint2D<Tsint> point;") << ln << STR(" ---> ") << point << ln;

    point.set(10, 20);
    stdoutput << STR("point.set(10, 20);") << ln << STR(" ---> ") << point << ln;

    point.negate();
    stdoutput << STR("point.negate();") << ln << STR(" ---> ") << point << ln;

    point.absolute();
    stdoutput << STR("point.absolute();") << ln << STR(" ---> ") << point << ln;

    point += 20;
    stdoutput << STR("point += 20;") << ln << STR(" ---> ") << point << ln;

    point -= 50;
    stdoutput << STR("point -= 50;") << ln << STR(" ---> ") << point << ln;

    point.clear();
    stdoutput << STR("point.clear();") << ln << STR(" ---> ") << point << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
