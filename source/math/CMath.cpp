/*!
 *  \file    CMath.cpp Math class contains common functionality for various
 *           mathematical calculations.
 *  \brief   Static class for mathematical calculations (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class for mathematical calculations (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Math
    VERSION:   1.0
    CREATED:   05.01.2006 23:59:45

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
#include <Depth/include/algorithms/numeric/AIsOdd.hpp>
#include <Depth/include/base/CReal.hpp>
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/math/CMathConstants.hpp>
#include <Depth/include/system/CSystemBase.hpp>
/*==========================================================================*/
#ifndef __CMATH_CPP__
#define __CMATH_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
BASE_API Treal CMath::ms_Epsilon = NBase::CRealNumber::getCompareEpsilon();
BASE_API NProcess::CRWLock CMath::ms_Locker = NProcess::CRWLock(true);
/*--------------------------------------------------------------------------*/
CMath::ENumberState CMath::getNumberState(const Treal a_cX)
{ CALL
  Tdouble tmpX = (Tdouble)a_cX;
  struct IEEExp
  {
    #if defined(__BIG_ENDIAN__)
    unsigned m_Sign: 1;
    unsigned m_Exp :11;
    unsigned m_ManH:20;
    unsigned m_ManL:32;
    #else
    unsigned m_ManL:32;
    unsigned m_ManH:20;
    unsigned m_Exp :11;
    unsigned m_Sign: 1;
    #endif
  } *ip = (struct IEEExp*)&tmpX;

  if ((ip->m_Exp & 0x7FF) == 0x7FF)
  {
    // Infinite number.
    if ((ip->m_ManH == 0) && (ip->m_ManL == 0))
    {
      if (ip->m_Sign)
        return e_NEGINF;
      else
        return e_POSINF;
    }
    // Not a number.
    if ((ip->m_ManH != 0) || (ip->m_ManL != 0))
    {
      if (ip->m_ManH & 0x80000)
        return e_QNAN;
      else
        return e_SNAN;
    }
  }
  return e_NORMAL;
}
/*--------------------------------------------------------------------------*/
Treal CMath::getPosInf()
{ CALL
  Tdouble temp;
  #if defined(__BIG_ENDIAN__)
  ((Tbuffer)&temp)[0] = 0x7F;
  ((Tbuffer)&temp)[1] = 0xF0;
  ((Tbuffer)&temp)[2] = 0x00;
  ((Tbuffer)&temp)[3] = 0x00;
  ((Tbuffer)&temp)[4] = 0x00;
  ((Tbuffer)&temp)[5] = 0x00;
  ((Tbuffer)&temp)[6] = 0x00;
  ((Tbuffer)&temp)[7] = 0x00;
  #else
  ((Tbuffer)&temp)[0] = 0x00;
  ((Tbuffer)&temp)[1] = 0x00;
  ((Tbuffer)&temp)[2] = 0x00;
  ((Tbuffer)&temp)[3] = 0x00;
  ((Tbuffer)&temp)[4] = 0x00;
  ((Tbuffer)&temp)[5] = 0x00;
  ((Tbuffer)&temp)[6] = 0xF0;
  ((Tbuffer)&temp)[7] = 0x7F;
  #endif
  return (Treal)temp;
}
/*--------------------------------------------------------------------------*/
Treal CMath::getNegInf()
{ CALL
  Tdouble temp;
  #if defined(__BIG_ENDIAN__)
  ((Tbuffer)&temp)[0] = 0xFF;
  ((Tbuffer)&temp)[1] = 0xF0;
  ((Tbuffer)&temp)[2] = 0x00;
  ((Tbuffer)&temp)[3] = 0x00;
  ((Tbuffer)&temp)[4] = 0x00;
  ((Tbuffer)&temp)[5] = 0x00;
  ((Tbuffer)&temp)[6] = 0x00;
  ((Tbuffer)&temp)[7] = 0x00;
  #else
  ((Tbuffer)&temp)[0] = 0x00;
  ((Tbuffer)&temp)[1] = 0x00;
  ((Tbuffer)&temp)[2] = 0x00;
  ((Tbuffer)&temp)[3] = 0x00;
  ((Tbuffer)&temp)[4] = 0x00;
  ((Tbuffer)&temp)[5] = 0x00;
  ((Tbuffer)&temp)[6] = 0xF0;
  ((Tbuffer)&temp)[7] = 0xFF;
  #endif
  return (Treal)temp;
}
/*--------------------------------------------------------------------------*/
Treal CMath::getQNan()
{ CALL
  Tdouble temp;
  #if defined(__BIG_ENDIAN__)
  ((Tbuffer)&temp)[0] = 0x7F;
  ((Tbuffer)&temp)[1] = 0xF8;
  ((Tbuffer)&temp)[2] = 0x00;
  ((Tbuffer)&temp)[3] = 0x00;
  ((Tbuffer)&temp)[4] = 0x00;
  ((Tbuffer)&temp)[5] = 0x00;
  ((Tbuffer)&temp)[6] = 0x00;
  ((Tbuffer)&temp)[7] = 0x00;
  #else
  ((Tbuffer)&temp)[0] = 0x00;
  ((Tbuffer)&temp)[1] = 0x00;
  ((Tbuffer)&temp)[2] = 0x00;
  ((Tbuffer)&temp)[3] = 0x00;
  ((Tbuffer)&temp)[4] = 0x00;
  ((Tbuffer)&temp)[5] = 0x00;
  ((Tbuffer)&temp)[6] = 0xF8;
  ((Tbuffer)&temp)[7] = 0x7F;
  #endif
  return (Treal)temp;
}
/*--------------------------------------------------------------------------*/
Treal CMath::getSNan()
{ CALL
  Tdouble temp;
  #if defined(__BIG_ENDIAN__)
  ((Tbuffer)&temp)[0] = 0x7F;
  ((Tbuffer)&temp)[1] = 0xF0;
  ((Tbuffer)&temp)[2] = 0x00;
  ((Tbuffer)&temp)[3] = 0x00;
  ((Tbuffer)&temp)[4] = 0x00;
  ((Tbuffer)&temp)[5] = 0x0F;
  ((Tbuffer)&temp)[6] = 0x00;
  ((Tbuffer)&temp)[7] = 0x00;
  #else
  ((Tbuffer)&temp)[0] = 0x00;
  ((Tbuffer)&temp)[1] = 0x00;
  ((Tbuffer)&temp)[2] = 0x0F;
  ((Tbuffer)&temp)[3] = 0x00;
  ((Tbuffer)&temp)[4] = 0x00;
  ((Tbuffer)&temp)[5] = 0x00;
  ((Tbuffer)&temp)[6] = 0xF0;
  ((Tbuffer)&temp)[7] = 0x7F;
  #endif
  return (Treal)temp;
}
/*--------------------------------------------------------------------------*/
Tsint CMath::closestStep2(const Tsint a_cX)
{ CALL
  Tsint i = a_cX;
  Tsint j = 0;
  if (i == 0)
    return 0;
  while (i & (i - 1))
  {
    i &= i - 1;
    ++j;
  }
  if (j != 0)
    i <<= 1;
  return i;
}
/*--------------------------------------------------------------------------*/
Tuint CMath::closestStep2(const Tuint a_cX)
{ CALL
  Tuint i = a_cX;
  Tuint j = 0;
  if (i == 0)
    return 0;
  while (i & (i - 1))
  {
    i &= i - 1;
    ++j;
  }
  if (j != 0)
    i <<= 1;
  return i;
}
/*--------------------------------------------------------------------------*/
Treal CMath::degToRad(const Treal a_cX)
{ CALL
  return (a_cX * CMathConstants::PI / CONSTR(180.0));
}
/*--------------------------------------------------------------------------*/
Treal CMath::radToDeg(const Treal a_cX)
{ CALL
  return (a_cX * CONSTR(180.0) / CMathConstants::PI);
}
/*--------------------------------------------------------------------------*/
Treal CMath::copySign(const Treal a_cX, const Treal a_cY)
{ CALL
  return (Treal)NSystem::CSystemBase::copysign((Tdouble)a_cX, (Tdouble)a_cY);
}
/*--------------------------------------------------------------------------*/
Treal CMath::acos(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::acos((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::acosh(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::acosh((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::asin(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::asin((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::asinh(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::asinh((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::atan(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::atan((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::atanh(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::atanh((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::atan2(const Treal a_cX, const Treal a_cY)
{ CALL
  return (Treal)NSystem::CSystemBase::atan2((Tdouble)a_cX, (Tdouble)a_cY);
}
/*--------------------------------------------------------------------------*/
Treal CMath::cos(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::cos((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::cosh(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::cosh((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::sin(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::sin((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::sinh(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::sinh((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::tan(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::tan((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::tanh(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::tanh((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
void CMath::sinCos(const Treal a_cX, Treal& a_rSin, Treal& a_rCos)
{ CALL
  Tdouble tmpS = (Tdouble)a_rSin;
  Tdouble tmpC = (Tdouble)a_rCos;

  NSystem::CSystemBase::sincos((Tdouble)a_cX, &tmpS, &tmpC);
  a_rSin = (Treal)tmpS;
  a_rCos = (Treal)tmpC;
}
/*--------------------------------------------------------------------------*/
Treal CMath::log(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::log((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::log2(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::log2((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::log10(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::log10((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::logFactorial(const Tsint a_cX)
{ CALL
  // Check the given value not to be less than 0.
  ASSERT((a_cX >= 0), STR("Ln(X!) - cannot calculate negative logarithm. X value must not be less than 0 (X = %u).") COMMA a_cX)
  {
    return 0.0;
  }

  static Treal a[101];

  if (a_cX <= 1)
    return 0.0;
  if (a_cX <= 100)
    return ((a[a_cX]) ? a[a_cX] : (a[a_cX] = CMath::logGamma(CONSTR(1.0) + a_cX)));
  else
    return CMath::logGamma(CONSTR(1.0) + a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::log1X(const Treal a_cX)
{ CALL
  // Check the given value to be more than -1.
  ASSERT((a_cX > -1.0), STR("Ln(1+X) - cannot calculate negative logarithm. X value must be more than -1 (X = %u).") COMMA a_cX)
  {
    return 0.0;
  }

  if (CMath::isEqualZero(a_cX))
    return 0.0;
  else
  {
    if ((a_cX < -0.2928) || (a_cX > 0.4142))
      return CMath::log(CONSTR(1.0) + a_cX);
    else
    {
      Treal z = a_cX / (a_cX + CONSTR(2.0));
      Treal y = z * z;
      return (z * (CONSTR(2.0) + y * (CONSTR(0.666666666663366) + y * (CONSTR(0.400000001206045) + y * (CONSTR(0.285714091590488) + y * (CONSTR(0.22223823332791) + y * (CONSTR(0.1811136267967) + y * CONSTR(0.16948212488))))))));
    }
  }
}
/*--------------------------------------------------------------------------*/
Treal CMath::logGamma(const Treal a_cX)
{ CALL
  // Check the given value to be more than 0.
  ASSERT((a_cX > 0), STR("Ln(Gamma(X)) - cannot calculate negative logarithm. X value must be more than 0 (X = %u).") COMMA a_cX)
  {
    return 0.0;
  }

  static const Treal coeff[6] = {CONSTR(76.18009172947146), CONSTR(-86.50532032941677), CONSTR(24.01409824083091), CONSTR(-1.231739572460166), CONSTR(0.1208650973866179e-2), CONSTR(-0.5395239384953e-5)};
  Treal x, y, tmp, ser;
  Tsint j;

  y = x = a_cX;
  tmp = x + CONSTR(5.5);
  tmp -= (x + CONSTR(0.5)) * CMath::log(tmp);
  ser = CONSTR(1.000000000190015);
  for (j = 0; j <= 5; ++j)
    ser += coeff[j] / ++y;
  return (-tmp + CMath::log(CONSTR(2.5066282746310005) * ser / x));
}
/*--------------------------------------------------------------------------*/
Treal CMath::gamma(const Treal a_cX)
{ CALL
  return CMath::exp(CMath::logGamma(a_cX));
}
/*--------------------------------------------------------------------------*/
Treal CMath::incompleteGamma(const Treal a_cA, const Treal a_cX, const Treal a_cTolerance, const Tuint a_cNMax)
{ CALL
  // Check the given value not to be less than 0.
  ASSERT((a_cX >= 0), STR("IncompleteGamma(A, X) - cannot calculate incomplete Gamma. X value must not be less than 0 (X = %u).") COMMA a_cX)
  {
    return NBase::CRealNumber::getMax();
  }

  if (CMath::isEqualZero(a_cX))
    return 0.0;

  if (a_cX < 1.0 + a_cA)
  {
    Treal ap = a_cA;
    Treal sum = CONSTR(1.0) / a_cA;
    Treal del = sum;
    for (Tuint i = 1; i <= a_cNMax; ++i)
    {
      ap += 1.0;
      del *= a_cX / ap;
      sum += del;
      if (CMath::fabs(del) < CMath::fabs(sum) * a_cTolerance)
      {
        Treal arg = -a_cX + a_cA * CMath::log(a_cX) - CMath::logGamma(a_cA);
        return (sum * CMath::exp(arg));
      }
    }
  }
  else
  {
    Treal A0 = 1.0, A1 = a_cX;
    Treal B0 = 0.0, B1 = 1.0;
    Treal gold = 0.0, fac = 1.0;
    for (Tuint i = 1; i <= a_cNMax; ++i)
    {
      Treal I = (Treal)i;
      Treal ImA = I - a_cA;
      A0 = (A1 + A0 * ImA) * fac;
      B0 = (B1 + B0 * ImA) * fac;
      Treal ItF = I * fac;
      A1 = a_cX * A0 + ItF * A1;
      B1 = a_cX * B0 + ItF * B1;
      if (!CMath::isEqualZero(A1))
      {
        fac = CONSTR(1.0) / A1;
        Treal G = B1 * fac;
        if (CMath::fabs(((G - gold) / G)) < a_cTolerance)
        {
          Treal arg = -a_cX + a_cA * CMath::log(a_cX) - CMath::logGamma(a_cA);
          return (CONSTR(1.0) - G * CMath::exp(arg));
        }
        gold = G;
      }
    }
  }
  WARNING(STR("Calculations overflow."));
  return NBase::CRealNumber::getMax();
}
/*--------------------------------------------------------------------------*/
Treal CMath::modBessel0(const Treal a_cX)
{ CALL
  Treal XX = CMath::fabs(a_cX);
  Treal result;
  Treal T;

  if (XX <= 3.75)
  {
    static const Treal coeff[7] = {CONSTR(1.0), CONSTR(3.5156229), CONSTR(3.0899424), CONSTR(1.2067492), CONSTR(0.2659732), CONSTR(0.0360768), CONSTR(0.0045813)};
    T = XX / CONSTR(3.75);
    Treal T2 = T * T;
    result = coeff[6];
    for (Tsint i = 5; i >= 0; --i)
    {
      result *= T2;
      result += coeff[i];
    }
    // |error| < 1.6e-07
  }
  else
  {
    static const Treal coeff[9] = {CONSTR(0.39894228), CONSTR(0.01328592), CONSTR(0.00225319), CONSTR(-0.00157565), CONSTR(0.00916281), CONSTR(-0.02057706), CONSTR(0.02635537), CONSTR(-0.01647633), CONSTR(0.00392377)};
    T = XX / CONSTR(3.75);
    Treal InvT = CONSTR(1.0) / T;
    result = coeff[8];
    for (Tsint i = 7; i >= 0; --i)
    {
      result *= InvT;
      result += coeff[i];
    }
    result *= CMath::exp(XX);
    result /= CMath::sqrt(XX);
    // |error| < 1.9e-07
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Treal CMath::modBessel1(const Treal a_cX)
{ CALL
  Treal XX, result, T;
  Tsint sign;

  if (a_cX > 0.0)
  {
    XX = a_cX;
    sign = 1;
  }
  else
  {
    if (a_cX < 0.0)
    {
      XX = -a_cX;
      sign = -1;
    }
    else
      return 0.0;
  }
  if (XX <= 3.75)
  {
   static const Treal coeff[7] = {CONSTR(0.5), CONSTR(0.87890549), CONSTR(0.51498869), CONSTR(0.15084934), CONSTR(0.02658733), CONSTR(0.00301532), CONSTR(0.00032411)};
   T = XX / CONSTR(3.75);
   Treal T2 = T * T;
   result = coeff[6];
   for (Tsint i = 5; i >= 0; --i)
   {
     result *= T2;
     result += coeff[i];
   }
   result *= XX;
   // |error| < 8e-09
  }
  else
  {
   static const Treal coeff[9] = {CONSTR(0.39894228), CONSTR(-0.03988024), CONSTR(-0.00362018), CONSTR(0.00163801), CONSTR(-0.01031555), CONSTR(0.02282967), CONSTR(-0.02895312), CONSTR(0.01787654), CONSTR(-0.00420059)};
   T = XX / CONSTR(3.75);
   Treal InvT = CONSTR(1.0) / T;
   result = coeff[8];
   for (Tsint i = 7; i >= 0; --i)
   {
     result *= InvT;
     result += coeff[i];
   }
   result *= CMath::exp(XX);
   result /= CMath::sqrt(XX);
   // |error| < 2.2e-07
  }
  result *= sign;
  return result;
}
/*--------------------------------------------------------------------------*/
Treal CMath::error(const Treal a_cX)
{ CALL
 static const Treal coeff[10] = {CONSTR(-1.26551223), CONSTR(1.00002368), CONSTR(0.37409196), CONSTR(0.09678418), CONSTR(-0.18628806), CONSTR(0.27886807), CONSTR(-1.13520398), CONSTR(1.48851587), CONSTR(-0.82215223), CONSTR(0.17087277)};
 Treal Z = CMath::fabs(a_cX);
 Treal T = CONSTR(1.0) / (CONSTR(1.0) + CONSTR(0.5) * Z);
 Treal sum = coeff[9];
 for (Tsint i = 9; i >= 0; --i)
   sum = T * sum + coeff[i];
 Treal result = T * CMath::exp(-Z * Z + sum);
 return ((a_cX >= 0.0) ? (CONSTR(1.0) - result) : (result - CONSTR(1.0)));
}
/*--------------------------------------------------------------------------*/
Treal CMath::pow(const Treal a_cX, const Tsint a_cY)
{ CALL
  Tbool calculated = false;
  Tsint N = (a_cY >= 0) ? a_cY : -a_cY;
  Treal result = 1.0;
  Treal x = a_cX;

  while (!calculated)
  {
    if (NAlgorithms::NNumeric::isOdd(N))
      result *= x;
    if ((N /= 2) != 0)
      x *= x;
    else
  {
      calculated = true;
  }
  }
  return ((a_cY >= 0) ? result : (CONSTR(1.0) / result));
}
/*--------------------------------------------------------------------------*/
Treal CMath::pow(const Treal a_cX, const Treal a_cY)
{ CALL
  return (Treal)NSystem::CSystemBase::pow((Tdouble)a_cX, (Tdouble)a_cY);
}
/*--------------------------------------------------------------------------*/
Treal CMath::pow10(const Tsint a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::exp10((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::exp(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::exp((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::exp2(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::exp2((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::exp10(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::exp10((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::expm1(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::expm1((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::sqrt(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::sqrt((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::cbrt(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::cbrt((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::fabs(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::fabs((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::fdim(const Treal a_cX, const Treal a_cY)
{ CALL
  return (Treal)NSystem::CSystemBase::fdim((Tdouble)a_cX, (Tdouble)a_cY);
}
/*--------------------------------------------------------------------------*/
Treal CMath::fma(const Treal a_cX, const Treal a_cY, const Treal a_cZ)
{ CALL
  return (Treal)NSystem::CSystemBase::fma((Tdouble)a_cX, (Tdouble)a_cY, (Tdouble)a_cZ);
}
/*--------------------------------------------------------------------------*/
Treal CMath::fmax(const Treal a_cX, const Treal a_cY)
{ CALL
  return (Treal)NSystem::CSystemBase::fmax((Tdouble)a_cX, (Tdouble)a_cY);
}
/*--------------------------------------------------------------------------*/
Treal CMath::fmin(const Treal a_cX, const Treal a_cY)
{ CALL
  return (Treal)NSystem::CSystemBase::fmin((Tdouble)a_cX, (Tdouble)a_cY);
}
/*--------------------------------------------------------------------------*/
Treal CMath::fmod(const Treal a_cX, const Treal a_cY)
{ CALL
  return (Treal)NSystem::CSystemBase::fmod((Tdouble)a_cX, (Tdouble)a_cY);
}
/*--------------------------------------------------------------------------*/
Treal CMath::ceil(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::ceil((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::floor(const Treal a_cX)
{ CALL
  return (Treal)NSystem::CSystemBase::floor((Tdouble)a_cX);
}
/*--------------------------------------------------------------------------*/
Treal CMath::poly(const Treal a_cX, const Tsint a_cN, const Treal* a_cpC)
{ CALL
  return (Treal)NSystem::CSystemBase::poly((Tdouble)a_cX, a_cN, (const Tdouble*)a_cpC);
}
/*--------------------------------------------------------------------------*/
Treal CMath::hypot(const Treal a_cX, const Treal a_cY)
{ CALL
  return (Treal)NSystem::CSystemBase::hypot((Tdouble)a_cX, (Tdouble)a_cY);
}
/*--------------------------------------------------------------------------*/
Treal CMath::frexp(const Treal a_cX, Tsint& a_rExp)
{ CALL
  return (Treal)NSystem::CSystemBase::frexp((Tdouble)a_cX, &a_rExp);
}
/*--------------------------------------------------------------------------*/
Treal CMath::ldexp(const Treal a_cX, const Tsint a_cExp)
{ CALL
  return (Treal)NSystem::CSystemBase::ldexp((Tdouble)a_cX, a_cExp);
}
/*--------------------------------------------------------------------------*/
Tfloat CMath::modf(const Tfloat a_cX, Tfloat& a_rInteger)
{ CALL
  Tdouble tmp = (Tdouble)a_rInteger;
  Tdouble res = NSystem::CSystemBase::modf((Tdouble)a_cX, &tmp);

  a_rInteger = (Tfloat)tmp;
  return (Tfloat)res;
}
/*--------------------------------------------------------------------------*/
Tdouble CMath::modf(const Tdouble a_cX, Tdouble& a_rInteger)
{ CALL
  return NSystem::CSystemBase::modf(a_cX, &a_rInteger);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
