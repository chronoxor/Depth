/*!
 *  \file    CIntegralRomberg.cpp Integral class contains functionality to
 *           calculate one-dimensional integrals with Romberg method.
 *  \brief   Static class for integral calculations with Romberg method (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class for integral calculations with Romberg method (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Math
    VERSION:   1.0
    CREATED:   06.05.2006 21:34:31

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/algorithms/common/AMinMax.hpp>
#include <Depth/include/math/CIntegralRomberg.hpp>
/*==========================================================================*/
#ifndef __CINTEGRALROMBERG_CPP__
#define __CINTEGRALROMBERG_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Treal CIntegralRomberg::integral(const TFunctor& a_cfrFunction, const Treal a_cA, const Treal a_cB, const Tuint a_cOrder/* = 5 */)
{ CALL
  // Check if the given function is valid.
  ASSERT(a_cfrFunction.isValid(), STR("Cannot calculate integral with the invalid function."))
  {
    return 0.0;
  }
  // Check if the given order of integration is greater than 0.
  ASSERT(a_cOrder > 0, STR("The order of the integration must be greater than 0 (order = %u).") COMMA a_cOrder)
  {
    return 0.0;
  }

  Treal a = a_cA;
  Treal b = a_cB;
  NAlgorithms::NCommon::minMax(a, b);

  Treal* rom[2];
  rom[0] = newex Treal[a_cOrder];
  rom[1] = newex Treal[a_cOrder];

  if (rom[0] == NULL)
  {
    WARNING(STR("Cannot allocate the first memory buffer for the Romberg integral calculation (requested size is %u bytes).") COMMA (a_cOrder * sizeof(Treal)));
    return 0.0;
  }
  if (rom[1] == NULL)
  {
    delete [] rom[0];
    WARNING(STR("Cannot allocate the second memory buffer for the Romberg integral calculation (requested size is %u bytes).") COMMA (a_cOrder * sizeof(Treal)));
    return 0.0;
  }

  Treal n = b - a;
  rom[0][0] = CONSTR(0.5) * n * (a_cfrFunction(a) + a_cfrFunction(b));
  for (Tuint i = 2, p0 = 1; i <= a_cOrder; ++i, p0 *= 2, n *= 0.5)
  {
    // Approximations via the trapezoid rule
    Treal sum = 0.0;
    Tuint j;
    for (j = 1; j <= p0; ++j)
      sum += a_cfrFunction(a + n * (j - CONSTR(0.5)));
    // Richardson extrapolation
    rom[1][0] = CONSTR(0.5) * (rom[0][0] + n * sum);
    for (Tuint k = 1, p2 = 4; k < i; ++k, p2 *= 4)
      rom[1][k] = (p2 * rom[1][k - 1] - rom[0][k - 1]) / (p2 - 1);
    for (j = 0; j < i; ++j)
      rom[0][j] = rom[1][j];
  }
  n = rom[0][a_cOrder - 1];

  delete [] rom[0];
  delete [] rom[1];

  return n;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
