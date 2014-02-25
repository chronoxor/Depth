/*!
 *  \file    CSystemBaseMath-All.cpp Base system class contains common
 *           functionality such as memory routines, math functions, error
 *           handling, standard I/O routines.
 *  \brief   Base system class - All OS - math methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - All OS - math methods (source).

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
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/system/CSystemBase.hpp>
/*==========================================================================*/
#ifndef __CSYSTEMBASEMATH_ALL_CPP__
#define __CSYSTEMBASEMATH_ALL_CPP__
/*==========================================================================*/
#if (!defined(__I386FPU__))
/*==========================================================================*/
#include <math.h>
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
  if (a_cY < 0.0)
    return (a_cX < 0.0) ? a_cX : -a_cX;
  else
    return (a_cX < 0.0) ? -a_cX : a_cX;
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::acos(const Tdouble a_cX)
{ CALL
  return (Tdouble)::acos((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::acosh(const Tdouble a_cX)
{ CALL
  return (Tdouble)((a_cX <= 1.0) ? 0.0 : ((a_cX > 1.0e10) ? (0.69314718055995 + (Tdouble)NMath::CMath::log((Treal)a_cX)) : (Tdouble)NMath::CMath::log((Treal)(a_cX + (Tdouble)NMath::CMath::sqrt((Treal)((a_cX - 1.0) * (a_cX + 1.0)))))));
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::asin(const Tdouble a_cX)
{ CALL
  return (Tdouble)::asin((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::asinh(const Tdouble a_cX)
{ CALL
  Tdouble ax = (Tdouble)NMath::CMath::fabs((Treal)a_cX);

  if (ax > 1.0e10)
    return (Tdouble)((a_cX > 0.0) ? (0.69314718055995 + (Tdouble)NMath::CMath::log((Treal)ax)) : (-0.69314718055995 + (Tdouble)NMath::CMath::log((Treal)ax)));
  else
  {
    double y = a_cX * a_cX;
    return (Tdouble)(((Tdouble)NMath::CMath::isEqualZero((Treal)a_cX)) ? 0.0 : ((a_cX > 0.0) ? (Tdouble)NMath::CMath::log1X((Treal)(ax + y / (1.0 + (Tdouble)NMath::CMath::sqrt((Treal)(1.0 + y))))) : -(Tdouble)NMath::CMath::log1X((Treal)(ax + y / (1.0 + (Tdouble)NMath::CMath::sqrt((Treal)(1.0 + y)))))));
  }
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::atan(const Tdouble a_cX)
{ CALL
  return (Tdouble)::atan((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::atanh(const Tdouble a_cX)
{ CALL
  Tdouble ax = (Tdouble)NMath::CMath::fabs((Treal)a_cX);

  if (ax >= 1.0)
    return (Tdouble)((a_cX > 0.0) ? NConstants::CConstants::doubleMax : -NConstants::CConstants::doubleMax);
  else
    return (Tdouble)(((Tdouble)NMath::CMath::isEqualZero((Treal)a_cX)) ? 0.0 : ((a_cX > 0.0) ? 0.5 * (Tdouble)NMath::CMath::log1X((Treal)(2.0 * ax / (1.0 - ax))) : -0.5 * (Tdouble)NMath::CMath::log1X((Treal)(2.0 * ax / (1.0 - ax)))));
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::atan2(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)::atan2((double)a_cX, (double)a_cY);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::cos(const Tdouble a_cX)
{ CALL
  return (Tdouble)::cos((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::cosh(const Tdouble a_cX)
{ CALL
  return (Tdouble)::cosh((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::sin(const Tdouble a_cX)
{ CALL
  return (Tdouble)::sin((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::sinh(const Tdouble a_cX)
{ CALL
  return (Tdouble)::sinh((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::tan(const Tdouble a_cX)
{ CALL
  return (Tdouble)::tan((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::tanh(const Tdouble a_cX)
{ CALL
  return (Tdouble)::tanh((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::log(const Tdouble a_cX)
{ CALL
  return (Tdouble)::log((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::log2(const Tdouble a_cX)
{ CALL
  return (Tdouble)(::log((double)a_cX) / ::log(2.0));
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::log10(const Tdouble a_cX)
{ CALL
  return (Tdouble)(::log((double)a_cX) / ::log(10.0));
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::pow(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)::pow((double)a_cX, (double)a_cY);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::exp(const Tdouble a_cX)
{ CALL
  return (Tdouble)::exp((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::exp2(const Tdouble a_cX)
{ CALL
  return (Tdouble)::exp((double)a_cX * log(2.0));
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::exp10(const Tdouble a_cX)
{ CALL
  return (Tdouble)::pow(10.0, (double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::expm1(const Tdouble a_cX)
{ CALL
  return (Tdouble)(::exp((double)a_cX) - 1.0);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::sqrt(const Tdouble a_cX)
{ CALL
  return (Tdouble)::sqrt((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::cbrt(const Tdouble a_cX)
{ CALL
  return (Tdouble)::pow((double)a_cX, 1.0 / 3.0);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::fabs(const Tdouble a_cX)
{ CALL
  return (Tdouble)((a_cX < 0.0) ? -a_cX : a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::fdim(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)(a_cX - a_cY);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::fma(const Tdouble a_cX, const Tdouble a_cY, const Tdouble a_cZ)
{ CALL
  return (Tdouble)((a_cX * a_cY) + a_cZ);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::fmax(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)((a_cX < a_cY) ? a_cY : a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::fmin(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)((a_cX < a_cY) ? a_cX : a_cY);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::fmod(const Tdouble a_cX, const Tdouble a_cY)
{ CALL
  return (Tdouble)::fmod((double)a_cX, (double)a_cY);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::ceil(const Tdouble a_cX)
{ CALL
  return (Tdouble)::ceil((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::floor(const Tdouble a_cX)
{ CALL
  return (Tdouble)::floor((double)a_cX);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::poly(const Tdouble a_cX, const Tsint a_cN, const Tdouble* a_cpC)
{ CALL
  const Tdouble *array = a_cpC;
  Tdouble result = *array;
  Tdouble scaler = 1.0;
  Tsint length = a_cN;

  while (length-- > 0)
  {
    scaler *= a_cX;
    result += *(++array) * scaler;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::frexp(const Tdouble a_cX, Tsint* a_pExp)
{ CALL
  return (Tdouble)::frexp((double)a_cX, (int*)a_pExp);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::ldexp(const Tdouble a_cX, const Tsint a_cExp)
{ CALL
  return (Tdouble)::ldexp((double)a_cX, (int)a_cExp);
}
/*--------------------------------------------------------------------------*/
Tdouble CSystemBase::modf(const Tdouble a_cX, Tdouble* a_pInteger)
{ CALL
  return (Tdouble)::modf((double)a_cX, (double*)a_pInteger);
}
/*--------------------------------------------------------------------------*/
void CSystemBase::sincos(const Tdouble a_cX, Tdouble* a_pSin, Tdouble* a_pCos)
{ CALL
  if (a_pSin != NULL)
    *a_pSin = (Tdouble)::sin((double)a_cX);
  if (a_pCos != NULL)
    *a_pCos = (Tdouble)::cos((double)a_cX);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
#endif
