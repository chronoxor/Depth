/*!
 *  \file    example-geometry-CVector3D.cpp Example of using the CVector3D
 *           class.
 *  \brief   Example of using the CVector3D class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CVector3D class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry examples
    VERSION:   1.0
    CREATED:   01.07.2008 01:08:58

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
#include <Depth/include/geometry/CVector3D.hpp>
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
// Write instance of the CVector3D class into the given writer.
IWriter& operator << (IWriter& writer, const CVector3D& a_crVector)
{ CALL
  return writer << STR("CVector3D(") << a_crVector.m_X << STR(", ") << a_crVector.m_Y << STR(", ") << a_crVector.m_Z << STR(")");
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

    CVector3D vector;
    stdoutput << STR("CVector3D vector;") << ln << STR(" ---> ") << vector << ln;

    vector.set(10.0, 0.0, 0.0);
    stdoutput << STR("vector.set(10.0, 0.0, 0.0);") << ln << STR(" ---> ") << vector << ln;

    vector.normalize();
    stdoutput << STR("vector.normalize();") << ln << STR(" ---> ") << vector << ln;

    vector = vector.translate(4.0, 5.0, 5.0);
    stdoutput << STR("vector = vector.translate(4.0, 5.0, 5.0);") << ln << STR(" ---> ") << vector << ln;

    vector = vector.scale(CONSTR(0.2), CONSTR(0.2), CONSTR(0.2));
    stdoutput << STR("vector = vector.scale(CONSTR(0.2), CONSTR(0.2), CONSTR(0.2));") << ln << STR(" ---> ") << vector << ln;

    vector = vector.rotate(CMathConstants::PI_2, 0.0, 0.0);
    stdoutput << STR("vector = vector.rotate(CMathConstants::PI_2, 0.0, 0.0);") << ln << STR(" ---> ") << vector << ln;

    vector = vector.rotate(0.0, CMathConstants::PI_2, 0.0);
    stdoutput << STR("vector = vector.rotate(0.0, CMathConstants::PI_2, 0.0);") << ln << STR(" ---> ") << vector << ln;

    vector = vector.rotate(0.0, 0.0, CMathConstants::PI_2);
    stdoutput << STR("vector = vector.rotate(0.0, 0.0, CMathConstants::PI_2);") << ln << STR(" ---> ") << vector << ln;

    vector = vector.rotate(CVector3D(1.0, 0.0, 0.0), CMathConstants::PI_2);
    stdoutput << STR("vector = vector.rotate(CVector3D(1.0, 0.0, 0.0), CMathConstants::PI_2);") << ln << STR(" ---> ") << vector << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
