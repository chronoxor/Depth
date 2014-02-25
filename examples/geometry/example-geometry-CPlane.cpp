/*!
 *  \file    example-geometry-CPlane.cpp Example of using the CPlane class.
 *  \brief   Example of using the CPlane class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CPlane class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry examples
    VERSION:   1.0
    CREATED:   14.07.2008 23:18:50

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
#include <Depth/include/geometry/CPlane.hpp>
#include <Depth/include/math/CMathConstants.hpp>
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
using namespace NDepth::NMath;
/*==========================================================================*/
// Write instance of the CPoint3D<Treal> class into the given writer.
IWriter& operator << (IWriter& writer, const CPoint3D<Treal>& a_crPoint)
{ CALL
  return writer << STR("CPoint3D<Treal>(") << a_crPoint.m_X << STR(", ") << a_crPoint.m_Y << STR(", ") << a_crPoint.m_Z << STR(")");
}
/*--------------------------------------------------------------------------*/
// Write instance of the CVector3D class into the given writer.
IWriter& operator << (IWriter& writer, const CVector3D& a_crVector)
{ CALL
  return writer << STR("CVector3D(") << a_crVector.m_X << STR(", ") << a_crVector.m_Y << STR(", ") << a_crVector.m_Z << STR(")");
}
/*--------------------------------------------------------------------------*/
// Write instance of the CPlane class into the given writer.
IWriter& operator << (IWriter& writer, const CPlane& a_crPlane)
{ CALL
  return writer << STR("CPlane(") << STR("normal(") << a_crPlane.m_Normal << STR(")") << STR(", ") << STR("distance = ") << a_crPlane.m_Distance << STR(")");
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

    CPlane plane(CVector3D(0.0, -1.0, 0.0), -1.0);
    stdoutput << STR("CPlane plane(CVector3D(0.0, -1.0, 0.0), -1.0);") << ln << STR(" ---> ") << plane << ln;

    plane.negate();
    stdoutput << STR("plane.negate();") << ln << STR(" ---> ") << plane << ln;

    CVector3D tangent = plane.getTangent();
    stdoutput << STR("CVector3D tangent = plane.getTangent();") << ln << STR(" ---> ") << tangent << ln;

    CPoint3D<Treal> closest = plane.getClosestPoint(CPoint3D<Treal>(10.0, 0.0, 10.0));
    stdoutput << STR("CPoint3D<Treal> closest = plane.getClosestPoint(CPoint3D<Treal>(10.0, 0.0, 10.0));") << ln << STR(" ---> ") << closest << ln;

    CPlane rotated(plane);
    rotated.rotate(CMatrix3D::rotate(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2));
    stdoutput << STR("CPlane rotated(plane); rotated.rotate(CMatrix3D::rotate(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2));") << ln << STR(" ---> ") << rotated << ln;

    CPlane transformed(plane); transformed.transform(CMatrix4D::rotate(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2) * CMatrix4D::translate(2.0, 4.0, 8.0));
    stdoutput << STR("CPlane transformed(plane); transformed.transform(CMatrix4D::rotate(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2) * CMatrix4D::translate(2.0, 4.0, 8.0));") << ln << STR(" ---> ") << transformed << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
