/*!
 *  \file    example-statistic-CDistributionSphere.cpp Example of using the
 *           CDistributionSphere class.
 *  \brief   Example of using the CDistributionSphere class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CDistributionSphere class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth statistic examples
    VERSION:   1.0
    CREATED:   09.03.2009 03:31:28

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
#include <Depth/include/statistic/CDistributionSphere.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NGeometry;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NStatistic;
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

    CDistributionSphere sphere_distribution(CPoint3D<Treal>(2.0, 2.0, 2.0), CVector3D(2.0, 2.0, 2.0));

    stdoutput << STR("CDistributionSphere(CPoint3D<Treal>(2.0, 2.0, 2.0), CVector3D(2.0, 2.0, 2.0))") << ln;

    // Show sphere distributed values.
    for (Tuint i = 0; i < 1000; ++i)
    {
      CPoint3D<Treal> p = sphere_distribution.randomPoint();
      stdoutput << tab << STR("CPoint3D<Treal>(") << p.m_X << STR(", ") << p.m_Y << STR(", ") << p.m_Z << STR(")") << ln;
    }

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
