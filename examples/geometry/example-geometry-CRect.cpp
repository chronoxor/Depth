/*!
 *  \file    example-geometry-CRect.cpp Example of using the CRect class.
 *  \brief   Example of using the CRect class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CRect class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry examples
    VERSION:   1.0
    CREATED:   24.06.2008 23:11:49

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
#include <Depth/include/geometry/CRect.hpp>
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
// Write instance of the CRect<Tsint> class into the given writer.
IWriter& operator << (IWriter& writer, const CRect<Tsint>& a_crRect)
{ CALL
  return writer << STR("CRect<Tsint>(") << a_crRect.m_A.m_X << STR(", ") << a_crRect.m_A.m_Y << STR(", ") << a_crRect.m_B.m_X << STR(", ") << a_crRect.m_B.m_Y << STR(")");
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

    CRect<Tsint> rect;
    stdoutput << STR("CRect<Tsint> rect;") << ln << STR(" ---> ") << rect << ln;

    rect.set(10, 20, 30, 40);
    stdoutput << STR("rect.set(10, 20, 30, 40);") << ln << STR(" ---> ") << rect << ln;
    stdoutput << STR("rect.getWidth();") << ln << STR(" ---> ") << rect.getWidth() << ln;
    stdoutput << STR("rect.getHeight();") << ln << STR(" ---> ") << rect.getHeight() << ln;

    rect += 20;
    stdoutput << STR("rect += 20;") << ln << STR(" ---> ") << rect << ln;

    rect -= 50;
    stdoutput << STR("rect -= 50;") << ln << STR(" ---> ") << rect << ln;

    rect.moveBy(CPoint2D<Tsint>(10, 20));
    stdoutput << STR("rect.moveBy(CPoint2D<Tsint>(10, 20));") << ln << STR(" ---> ") << rect << ln;

    rect.moveTo(CPoint2D<Tsint>(0, 0));
    stdoutput << STR("rect.moveTo(CPoint2D<Tsint>(0, 0));") << ln << STR(" ---> ") << rect << ln;

    rect = rect.getEmpty();
    stdoutput << STR("rect = rect.getEmpty();") << ln << STR(" ---> ") << rect << ln;
    stdoutput << STR("rect.isEmpty();") << ln << STR(" ---> ") << rect.isEmpty() << ln;
    stdoutput << STR("rect.isNormal();") << ln << STR(" ---> ") << rect.isNormal() << ln;

    rect = rect.getNormal();
    stdoutput << STR("rect = rect.getNormal();") << ln << STR(" ---> ") << rect << ln;
    stdoutput << STR("rect.isEmpty();") << ln << STR(" ---> ") << rect.isEmpty() << ln;
    stdoutput << STR("rect.isNormal();") << ln << STR(" ---> ") << rect.isNormal() << ln;

    rect.inverse();
    stdoutput << STR("rect.inverse();") << ln << STR(" ---> ") << rect << ln;
    stdoutput << STR("rect.isEmpty();") << ln << STR(" ---> ") << rect.isEmpty() << ln;
    stdoutput << STR("rect.isNormal();") << ln << STR(" ---> ") << rect.isNormal() << ln;

    stdoutput << STR("rect.isInside(CPoint2D<Tsint>(10, 10));") << ln << STR(" ---> ") << rect.isInside(CPoint2D<Tsint>(10, 10)) << ln;
    stdoutput << STR("rect.isInside(CPoint2D<Tsint>(30, 30));") << ln << STR(" ---> ") << rect.isInside(CPoint2D<Tsint>(30, 30)) << ln;
    stdoutput << STR("rect.isInside(CRect<Tsint>(10, 10, 15, 15));") << ln << STR(" ---> ") << rect.isInside(CRect<Tsint>(10, 10, 15, 15)) << ln;
    stdoutput << STR("rect.isInside(CRect<Tsint>(10, 10, 25, 25));") << ln << STR(" ---> ") << rect.isInside(CRect<Tsint>(10, 10, 25, 25)) << ln;

    stdoutput << STR("rect.isIntersect(CRect<Tsint>(10, 10, 15, 15));") << ln << STR(" ---> ") << rect.isIntersect(CRect<Tsint>(10, 10, 15, 15)) << ln;
    stdoutput << STR("rect.isIntersect(CRect<Tsint>(10, 10, 25, 25));") << ln << STR(" ---> ") << rect.isIntersect(CRect<Tsint>(10, 10, 25, 25)) << ln;
    stdoutput << STR("rect.isIntersect(CRect<Tsint>(30, 30, 45, 45));") << ln << STR(" ---> ") << rect.isIntersect(CRect<Tsint>(30, 30, 45, 45)) << ln;

    CRect<Tsint> intersection = rect.getIntersection(CRect<Tsint>(10, 10, 30, 30));
    stdoutput << STR("CRect<Tsint> intersection = rect.getIntersection(CRect<Tsint>(10, 10, 30, 30));") << ln << STR(" ---> ") << intersection << ln;

    CRect<Tsint> unionPoint = rect.getUnion(CPoint2D<Tsint>(30, 10));
    stdoutput << STR("CRect<Tsint> unionPoint = rect.getUnion(CPoint2D<Tsint>(30, 10));") << ln << STR(" ---> ") << unionPoint << ln;

    CRect<Tsint> unionRect = rect.getUnion(CRect<Tsint>(10, 10, 30, 30));
    stdoutput << STR("CRect<Tsint> unionRect = rect.getUnion(CRect<Tsint>(10, 10, 30, 30));") << ln << STR(" ---> ") << unionRect << ln;

    rect.clear();
    stdoutput << STR("rect.clear();") << ln << STR(" ---> ") << rect << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
