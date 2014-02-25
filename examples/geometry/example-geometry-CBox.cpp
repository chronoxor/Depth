/*!
 *  \file    example-geometry-CBox.cpp Example of using the CBox class.
 *  \brief   Example of using the CBox class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CBox class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry examples
    VERSION:   1.0
    CREATED:   24.06.2008 23:39:57

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
#include <Depth/include/geometry/CPoint3D.hpp>
#include <Depth/include/geometry/CBox.hpp>
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
// Write instance of the CBox<Tsint> class into the given writer.
IWriter& operator << (IWriter& writer, const CBox<Tsint>& a_crBox)
{ CALL
  return writer << STR("CBox<Tsint>(") << a_crBox.m_A.m_X << STR(", ") << a_crBox.m_A.m_Y << STR(", ") << a_crBox.m_A.m_Z << STR(", ") << a_crBox.m_B.m_X << STR(", ") << a_crBox.m_B.m_Y << STR(", ") << a_crBox.m_B.m_Z << STR(")");
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

    CBox<Tsint> box;
    stdoutput << STR("CBox<Tsint> box;") << ln << STR(" ---> ") << box << ln;

    box.set(10, 20, 30, 40, 50, 60);
    stdoutput << STR("box.set(10, 20, 30, 40, 50, 60);") << ln << STR(" ---> ") << box << ln;

    stdoutput << STR("box.getWidth();") << ln << STR(" ---> ") << box.getWidth() << ln;
    stdoutput << STR("box.getHeight();") << ln << STR(" ---> ") << box.getHeight() << ln;
    stdoutput << STR("box.getDepth();") << ln << STR(" ---> ") << box.getDepth() << ln;

    box += 20;
    stdoutput << STR("box += 20;") << ln << STR(" ---> ") << box << ln;

    box -= 50;
    stdoutput << STR("box -= 50;") << ln << STR(" ---> ") << box << ln;

    box.moveBy(CPoint3D<Tsint>(10, 20, 30));
    stdoutput << STR("box.moveBy(CPoint3D<Tsint>(10, 20, 30));") << ln << STR(" ---> ") << box << ln;

    box.moveTo(CPoint3D<Tsint>(0, 0, 0));
    stdoutput << STR("box.moveTo(CPoint3D<Tsint>(0, 0, 0));") << ln << STR(" ---> ") << box << ln;

    box = box.getEmpty();
    stdoutput << STR("box = box.isEmpty();") << ln << STR(" ---> ") << box << ln;
    stdoutput << STR("box.isEmpty();") << ln << STR(" ---> ") << box.isEmpty() << ln;
    stdoutput << STR("box.isNormal();") << ln << STR(" ---> ") << box.isNormal() << ln;

    box = box.getNormal();
    stdoutput << STR("box = box.isNormal();") << ln << STR(" ---> ") << box << ln;
    stdoutput << STR("box.isEmpty();") << ln << STR(" ---> ") << box.isEmpty() << ln;
    stdoutput << STR("box.isNormal();") << ln << STR(" ---> ") << box.isNormal() << ln;

    box.inverse();
    stdoutput << STR("box.inverse();") << ln << STR(" ---> ") << box << ln;
    stdoutput << STR("box.isEmpty();") << ln << STR(" ---> ") << box.isEmpty() << ln;
    stdoutput << STR("box.isNormal();") << ln << STR(" ---> ") << box.isNormal() << ln;

    stdoutput << STR("box.isInside(CPoint3D<Tsint>(10, 10, 10));") << ln << STR(" ---> ") << box.isInside(CPoint3D<Tsint>(10, 10, 10)) << ln;
    stdoutput << STR("box.isInside(CPoint3D<Tsint>(40, 40, 40));") << ln << STR(" ---> ") << box.isInside(CPoint3D<Tsint>(40, 40, 40)) << ln;
    stdoutput << STR("box.isInside(CBox<Tsint>(10, 10, 10, 15, 15, 15));") << ln << STR(" ---> ") << box.isInside(CBox<Tsint>(10, 10, 10, 15, 15, 15)) << ln;
    stdoutput << STR("box.isInside(CBox<Tsint>(10, 10, 10, 45, 45, 45));") << ln << STR(" ---> ") << box.isInside(CBox<Tsint>(10, 10, 10, 45, 45, 45)) << ln;

    stdoutput << STR("box.isIntersect(CBox<Tsint>(10, 10, 10, 15, 15, 15));") << ln << STR(" ---> ") << box.isIntersect(CBox<Tsint>(10, 10, 10, 15, 15, 15)) << ln;
    stdoutput << STR("box.isIntersect(CBox<Tsint>(10, 10, 10, 45, 45, 45));") << ln << STR(" ---> ") << box.isIntersect(CBox<Tsint>(10, 10, 10, 45, 45, 45)) << ln;
    stdoutput << STR("box.isIntersect(CBox<Tsint>(40, 40, 40, 65, 65, 65));") << ln << STR(" ---> ") << box.isIntersect(CBox<Tsint>(40, 40, 40, 65, 65, 65)) << ln;

    CBox<Tsint> intersection = box.getIntersection(CBox<Tsint>(10, 10, 10, 40, 40, 40));
    stdoutput << STR("box.getIntersection(CBox<Tsint>(10, 10, 10, 40, 40, 40));") << ln << STR(" ---> ") << intersection << ln;

    CBox<Tsint> unionPoint = box.getUnion(CPoint3D<Tsint>(40, 10, 0));
    stdoutput << STR("box.getUnion(CPoint3D<Tsint>(40, 10, 0));") << ln << STR(" ---> ") << unionPoint << ln;

    CBox<Tsint> unionBox = box.getUnion(CBox<Tsint>(10, 10, 10, 40, 40, 40));
    stdoutput << STR("box.getUnion(CBox<Tsint>(10, 10, 10, 40, 40, 40));") << ln << STR(" ---> ") << unionBox << ln;

    box.clear();
    stdoutput << STR("box.clear();") << ln << STR(" ---> ") << box << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
