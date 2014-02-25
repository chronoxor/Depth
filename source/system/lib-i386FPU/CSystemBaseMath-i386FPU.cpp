/*!
 *  \file    CSystemBaseMath-i386FPU.cpp Base system class contains common
 *           functionality such as memory routines, math functions, error
 *           handling, standard I/O routines.
 *  \brief   Base system class - i386 math methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - i386 math methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   07.01.2006 01:33:12

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
#include <Depth/include/system/CSystemBase.hpp>
/*==========================================================================*/
#ifndef __CSYSTEMBASEMATH_I386FPU_CPP__
#define __CSYSTEMBASEMATH_I386FPU_CPP__
/*==========================================================================*/
#if defined(__I386FPU__)
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
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tdouble CSystemBase::copysign(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_copysign)((double)a_cX, (double)a_cY);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::acos(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_acos)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::acosh(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_acosh)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::asin(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_asin)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::asinh(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_asinh)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::atan(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_atan)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::atanh(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_atanh)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::atan2(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_atan2)((double)a_cX, (double)a_cY);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::cos(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_cos)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::cosh(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_cosh)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::sin(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_sin)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::sinh(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_sinh)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::tan(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_tan)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::tanh(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_tanh)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::log(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_log)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::log2(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_log2)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::log10(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_log10)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::pow(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_pow)((double)a_cX, (double)a_cY);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::exp(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_exp)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::exp2(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_exp2)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::exp10(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_exp10)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::expm1(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_expm1)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::sqrt(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_sqrt)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::cbrt(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_cbrt)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::fabs(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_fabs)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::fdim(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_fdim)((double)a_cX, (double)a_cY);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::fma(const Tdouble a_cX, const Tdouble a_cY, const Tdouble a_cZ)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_fma)((double)a_cX, (double)a_cY, (double)a_cZ);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::fmax(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_fmax)((double)a_cX, (double)a_cY);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::fmin(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_fmin)((double)a_cX, (double)a_cY);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::fmod(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_fmod)((double)a_cX, (double)a_cY);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::ceil(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_ceil)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::floor(const Tdouble a_cX)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_floor)((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::poly(const Tdouble a_cX, const Tsint a_cN, const Tdouble* a_cpC)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_poly)((double)a_cX, (int)a_cN, (const double*)a_cpC);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::hypot(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_hypot)((double)a_cX, (double)a_cY);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::frexp(const Tdouble a_cX, Tsint* a_pExp)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_frexp)((double)a_cX, (int*)a_pExp);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::ldexp(const Tdouble a_cX, const Tsint a_cExp)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_ldexp)((double)a_cX, (int)a_cExp);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::modf(const Tdouble a_cX, Tdouble* a_pInteger)
{ CALL
  return (Tdouble)::CPREFIX(i386FPU_modf)((double)a_cX, (double*)a_pInteger);
}
/*--------------------------------------------------------------------------*/
void CSystemBase::sincos(const Tdouble a_cX, Tdouble* a_pSin, Tdouble* a_pCos)
{ CALL
  if ((a_pSin != NULL) && (a_pCos != NULL))
    ::CPREFIX(i386FPU_sincos)((double)a_cX, (double*)a_pSin, (double*)a_pCos);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
#endif
