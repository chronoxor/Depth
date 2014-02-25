/*!
 *  \file    CIntegralSimpsons.cpp Integral class contains functionality to
 *           calculate one-dimensional integrals with Simpsons method.
 *  \brief   Static class for integral calculations with Simpsons method (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class for integral calculations with Simpsons method (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Math
    VERSION:   1.0
    CREATED:   06.05.2006 22:43:47

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
#include <Depth/include/math/CIntegralSimpsons.hpp>
/*==========================================================================*/
#ifndef __CINTEGRALSIMPSONS_CPP__
#define __CINTEGRALSIMPSONS_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Treal CIntegralSimpsons::integral(const TFunctor& a_cfrFunction, const Treal a_cA, const Treal a_cB, const Treal a_cTolerance/* = CMath::getEpsilon() */, const Tuint a_cMaxIterations/* = 100 */)
{ CALL
  // Check if the given function is valid.
  ASSERT(a_cfrFunction.isValid(), STR("Cannot calculate integral with the invalid function."))
  {
    return 0.0;
  }

  Treal a = a_cA;
  Treal b = a_cB;
  NAlgorithms::NCommon::minMax(a, b);

  Tuint j = 1;
  Treal y1, y2;
  Treal yt1, yt2;

  yt1 = CIntegralSimpsons::trapezoidCalculator(a_cfrFunction, a, b, 0.0, j);
  y1 = CONSTR(4.0) * yt1 / CONSTR(3.0);
  do
  {
    ++j;
    yt2 = yt1;
    y2 = y1;
    yt1 = CIntegralSimpsons::trapezoidCalculator(a_cfrFunction, a, b, yt1, j);
    y1 = (CONSTR(4.0) * yt1 - yt2) / CONSTR(3.0);
  } while ((j < a_cMaxIterations) && (CMath::fabs(y1 - y2) > a_cTolerance * CMath::fabs(y2)));

  if (j < a_cMaxIterations)
    return y1;
  else
  {
    WARNING(STR("Failed to converge (iterations = %u).") COMMA j);
    return 0.0;
  }
}
/*--------------------------------------------------------------------------*/
Treal CIntegralSimpsons::trapezoidCalculator(const TFunctor& a_cfrFunction, const Treal a_cA, const Treal a_cB, const Treal a_cX, const Tuint a_cN)
{ CALL
  Treal x, tnm, sum, del, ret;
  Tuint it, j;

  if (a_cN <= 1)
    ret = CONSTR(0.5) * (a_cB - a_cA) * (a_cfrFunction(a_cA) + a_cfrFunction(a_cB));
  else
  {
    for (it = 1, j = 1; j < (a_cN - 1); ++j)
      it <<= 1;
    tnm = (Treal)it;
    del = (a_cB - a_cA) / tnm;
    x = a_cA + CONSTR(0.5) * del;
    for (sum = 0.0, j = 1; j <= it; ++j, x += del)
      sum += a_cfrFunction(x);
    ret = CONSTR(0.5) * (a_cX + (a_cB - a_cA) * sum / tnm);
  }
  return ret;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
