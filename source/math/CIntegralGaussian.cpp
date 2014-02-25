/*!
 *  \file    CIntegralGaussian.cpp Integral class contains functionality to
 *           calculate one-dimensional integrals with Gaussian method.
 *  \brief   Static class for integral calculations with Gaussian method (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class for integral calculations with Gaussian method (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Math
    VERSION:   1.0
    CREATED:   06.05.2006 01:27:42

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
#include <Depth/include/math/CIntegralGaussian.hpp>
/*==========================================================================*/
#ifndef __CINTEGRALGAUSSIAN_CPP__
#define __CINTEGRALGAUSSIAN_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Treal CIntegralGaussian::integral(const TFunctor& a_cfrFunction, const Treal a_cA, const Treal a_cB)
{ CALL
  // Check if the given function is valid.
  ASSERT(a_cfrFunction.isValid(), STR("Cannot calculate integral with the invalid function."))
  {
    return 0.0;
  }

  Treal a = a_cA;
  Treal b = a_cB;
  NAlgorithms::NCommon::minMax(a, b);

  // Legendre polynomials:
  // P_0(x) = 1
  // P_1(x) = x
  // P_2(x) = (3x^2-1)/2
  // P_3(x) = x(5x^2-3)/2
  // P_4(x) = (35x^4-30x^2+3)/8
  // P_5(x) = x(63x^4-70x^2+15)/8

  // Generation of polynomials:
  //   d/dx[ (1-x^2) dP_n(x)/dx ] + n(n+1) P_n(x) = 0
  //   P_n(x) = sum_{k=0}^{floor(n/2)} c_k x^{n-2k}
  //     c_k = (-1)^k (2n-2k)! / [ 2^n k! (n-k)! (n-2k)! ]
  //   P_n(x) = ((-1)^n/(2^n n!)) d^n/dx^n[ (1-x^2)^n ]
  //   (n+1)P_{n+1}(x) = (2n+1) x P_n(x) - n P_{n-1}(x)
  //   (1-x^2) dP_n(x)/dx = -n x P_n(x) + n P_{n-1}(x)

  // Roots of the Legendre polynomial of specified degree.
  static const Tuint degree = 5;
  static const Treal root[degree] =  {CONSTR(-0.9061798459), CONSTR(-0.5384693101), CONSTR(0.0),          CONSTR(0.5384693101), CONSTR(0.9061798459)};
  static const Treal coeff[degree] = {CONSTR(0.2369268850),  CONSTR(0.4786286705),  CONSTR(0.5688888889), CONSTR(0.4786286705), CONSTR(0.2369268850)};

  // Need to transform domain [a, b] to [-1, 1].
  // If a <= x <= b and -1 <= t <= 1, then x = ((b - a) * t + (b + a)) / 2.
  Treal radius = CONSTR(0.5) * (b - a);
  Treal center = CONSTR(0.5) * (b + a);
  Treal result = 0.0;
  for (Tuint i = 0; i < degree; ++i)
    result += coeff[i] * a_cfrFunction(radius * root[i] + center);
  result *= radius;
  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
