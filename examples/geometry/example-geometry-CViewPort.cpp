/*!
 *  \file    example-geometry-CViewPort.cpp Example of using the CViewPort
 *           class.
 *  \brief   Example of using the CViewPort class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CViewPort class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry examples
    VERSION:   1.0
    CREATED:   24.07.2008 02:44:18

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
#include <Depth/include/geometry/CViewPort.hpp>
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
// Write instance of the CPoint3D<Treal> class into the given writer.
IWriter& operator << (IWriter& writer, const CPoint3D<Treal>& a_crPoint)
{ CALL
  return writer << STR("CPoint3D<Treal>(") << a_crPoint.m_X << STR(", ") << a_crPoint.m_Y << STR(", ") << a_crPoint.m_Z << STR(")");
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

    CViewPort viewport(0.0, 0.0, 640.0, 480.0);

    CPoint3D<Treal> normalized(0.0, 0.0, 0.0);
    CPoint3D<Treal> screen;

    stdoutput << STR("normalized = ") << normalized << ln;
    viewport.projectNormalizedToScreen(normalized, screen);
    stdoutput << STR("screen = ") << screen << ln;
    viewport.unprojectScreenToNormalized(screen, normalized);
    stdoutput << STR("normalized = ") << normalized << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
