/*!
 *  \file    test-lib-i386FPU.cpp Testing of the i386FPU static library.
 *  \brief   Testing of the i386FPU static library.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the i386FPU static library.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      i386FPU static library tests
    VERSION:   1.0
    CREATED:   31.12.2006 01:44:27

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
#include "unit-test.hpp"
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <cmath>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*==========================================================================*/
extern "C" double CPREFIX(i386FPU_copysign)(double, double);
extern "C" double CPREFIX(i386FPU_acos)(double);
extern "C" double CPREFIX(i386FPU_acosh)(double);
extern "C" double CPREFIX(i386FPU_asin)(double);
extern "C" double CPREFIX(i386FPU_asinh)(double);
extern "C" double CPREFIX(i386FPU_atan)(double);
extern "C" double CPREFIX(i386FPU_atanh)(double);
extern "C" double CPREFIX(i386FPU_atan2)(double, double);
extern "C" double CPREFIX(i386FPU_cos)(double);
extern "C" double CPREFIX(i386FPU_cosh)(double);
extern "C" double CPREFIX(i386FPU_sin)(double);
extern "C" double CPREFIX(i386FPU_sinh)(double);
extern "C" double CPREFIX(i386FPU_tan)(double);
extern "C" double CPREFIX(i386FPU_tanh)(double);
extern "C" double CPREFIX(i386FPU_log)(double);
extern "C" double CPREFIX(i386FPU_log2)(double);
extern "C" double CPREFIX(i386FPU_log10)(double);
extern "C" double CPREFIX(i386FPU_pow)(double, double);
extern "C" double CPREFIX(i386FPU_exp)(double);
extern "C" double CPREFIX(i386FPU_exp2)(double);
extern "C" double CPREFIX(i386FPU_exp10)(double);
extern "C" double CPREFIX(i386FPU_expm1)(double);
extern "C" double CPREFIX(i386FPU_sqrt)(double);
extern "C" double CPREFIX(i386FPU_cbrt)(double);
extern "C" double CPREFIX(i386FPU_fabs)(double);
extern "C" double CPREFIX(i386FPU_fdim)(double, double);
extern "C" double CPREFIX(i386FPU_fma)(double, double, double);
extern "C" double CPREFIX(i386FPU_fmax)(double, double);
extern "C" double CPREFIX(i386FPU_fmin)(double, double);
extern "C" double CPREFIX(i386FPU_fmod)(double, double);
extern "C" double CPREFIX(i386FPU_ceil)(double);
extern "C" double CPREFIX(i386FPU_floor)(double);
extern "C" double CPREFIX(i386FPU_poly)(double, int, const double*);
extern "C" double CPREFIX(i386FPU_hypot)(double, double);
extern "C" double CPREFIX(i386FPU_frexp)(double, int*);
extern "C" double CPREFIX(i386FPU_ldexp)(double, int);
extern "C" double CPREFIX(i386FPU_modf)(double, double*);
extern "C" void CPREFIX(i386FPU_sincos)(double, double*, double*);
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT_DELTA(CPREFIX(i386FPU_acos)(0.465), acos(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_acos)(0.465), acos(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_asin)(0.465), asin(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_atan)(0.465), atan(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_atan2)(0.465, 0.532), atan2(0.465, 0.532), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_cos)(0.465), cos(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_cosh)(0.465), cosh(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_sin)(0.465), sin(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_sinh)(0.465), sinh(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_tan)(0.465), tan(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_tanh)(0.465), tanh(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_log)(0.465), log(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_log10)(0.465), log10(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_pow)(0.465, 10.532), pow(0.465, 10.532), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_exp)(0.465), exp(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_sqrt)(0.465), sqrt(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_fabs)(-0.465), fabs(-0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_fmod)(23.523, 5.473), fmod(23.523, 5.473), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_ceil)(0.465), ceil(0.465), 0.0001);
    UT_ASSERT_DELTA(CPREFIX(i386FPU_floor)(0.465), floor(0.465), 0.0001);

    int n1, n2;
    UT_ASSERT_DELTA(CPREFIX(i386FPU_frexp)(12.42, &n1), frexp(12.42, &n2), 0.0001);
    UT_ASSERT_EQUAL(n1, n2);

    UT_ASSERT_DELTA(CPREFIX(i386FPU_ldexp)(4.36, 3), ldexp(4.36, 3), 0.0001);

    double d1, d2;
    UT_ASSERT_DELTA(CPREFIX(i386FPU_modf)(-15.63, &d1), modf(-15.63, &d2), 0.0001);
    UT_ASSERT_DELTA(d1, d2, 0.0001);

    double s, c;
    CPREFIX(i386FPU_sincos)(0.465, &s, &c);
    UT_ASSERT_DELTA(s, sin(0.465), 0.0001);
    UT_ASSERT_DELTA(c, cos(0.465), 0.0001);

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
