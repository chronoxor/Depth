/*!
 *  \file    CMath.hpp Math class contains common functionality for various
 *           mathematical calculations.
 *  \brief   Static class for mathematical calculations.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class for mathematical calculations.

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
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

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
#ifndef __CMATH_HPP__
#define __CMATH_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/process/CRWLock.hpp>
#include <Depth/include/process/CScopeReader.hpp>
#include <Depth/include/process/CScopeWriter.hpp>
#include <Depth/include/serialization.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Static class for mathematical calculations.
/*!
    Math class gives lots of common functions for  developer.  Most  of  class
    methods replace similar C functions.
*/
class BASE_API CMath :
  public NDepth::NCommon::IStatic
{
public:
  enum ENumberState                     //! Real number state.
  {
    e_NORMAL,                           //!< Normal real number.
    e_POSINF,                           //!< Positive infinite real number.
    e_NEGINF,                           //!< Negative infinite real number.
    e_QNAN,                             //!< Quiet "Not a number" real number.
    e_SNAN                              //!< Signal "Not a number" real number.
  };

  //! Set calculations accuracy.
  /*!
      \param a_cEpsilon - Calculations accuracy.
  */
  static void setEpsilon(const Treal a_cEpsilon);

  //! Get calculations accuracy.
  /*!
      \return Calculations accuracy.
  */
  static Treal getEpsilon();

  //! Get number state.
  /*!
      \param a_cX - Real number.
      \return Real number state.
  */
  static ENumberState getNumberState(const Treal a_cX);

  //! Is number normal real number?
  /*!
      \param a_cX - Real number.
      \return true  - if number is normal real number. \n
              false - if number is not normal real number. \n
  */
  static Tbool isNormal(const Treal a_cX);
  //! Is number infinite real number?
  /*!
      \param a_cX - Real number.
      \return true  - if number is infinite real number. \n
              false - if number is not infinite real number. \n
  */
  static Tbool isInfinite(const Treal a_cX);
  //! Is number positive infinite real number?
  /*!
      \param a_cX - Real number.
      \return true  - if number is positive infinite real number. \n
              false - if number is not positive infinite real number. \n
  */
  static Tbool isPosInf(const Treal a_cX);
  //! Is number negative infinite real number?
  /*!
      \param a_cX - Real number.
      \return true  - if number is negative infinite real number. \n
              false - if number is not negative infinite real number. \n
  */
  static Tbool isNegInf(const Treal a_cX);
  //! Is number "Not a number" real number?
  /*!
      \param a_cX - Real number.
      \return true  - if number is "Not a number" real number. \n
              false - if number is not "Not a number" real number. \n
  */
  static Tbool isNan(const Treal a_cX);
  //! Is number quiet "Not a number" real number?
  /*!
      \param a_cX - Real number.
      \return true  - if number is quiet "Not a number" real number. \n
              false - if number is not quiet "Not a number" real number. \n
  */
  static Tbool isQNan(const Treal a_cX);
  //! Is number signal "Not a number" real number?
  /*!
      \param a_cX - Real number.
      \return true  - if number is signal "Not a number" real number. \n
              false - if number is not signal "Not a number" real number. \n
  */
  static Tbool isSNan(const Treal a_cX);

  //! Get positive infinite real number.
  /*!
      \return Positive infinite real number.
  */
  static Treal getPosInf();
  //! Get negative infinite real number.
  /*!
      \return Negative infinite real number.
  */
  static Treal getNegInf();
  //! Get quiet "Not a number" real number.
  /*!
      \return Quiet "Not a number" real number.
  */
  static Treal getQNan();
  //! Get signal "Not a number" real number.
  /*!
      \return Signal "Not a number" real number.
  */
  static Treal getSNan();

  //! Detect equality of two real numbers.
  /*!
      The method uses the following rule to detect the equality  of  two  real
      numbers: | x - y | <= delta

      \param a_cX - First real number.
      \param a_cY - Second real number.
      \param a_cDelta - Delta precision value (default is NDepth::NMath::CMath::getEpsilon()).
      \return true  - if numbers are equal. \n
              false - if numbers are not equal. \n
  */
  static Tbool isEqual(const Treal a_cX, const Treal a_cY, const Treal a_cDelta = CMath::getEpsilon());

  //! Detect equality of real number and zero.
  /*!
      The method uses the following rule to detect the equality of real number
      to zero: | x | <= delta

      \param a_cX - Real real number.
      \param a_cDelta - Delta precision value (default is NDepth::NMath::CMath::getEpsilon()).
      \return true  - if number is equal to zero. \n
              false - if number is not equal to zero. \n

  */
  static Tbool isEqualZero(const Treal a_cX, const Treal a_cDelta = CMath::getEpsilon());

  //! Get closest step 2 of given number.
  /*!
      \param a_cX - Integer number.
      \return Closest step 2 of given number.
  */
  static Tsint closestStep2(const Tsint a_cX);
  //! Get closest step 2 of given number.
  /*!
      \param a_cX - Integer number.
      \return Closest step 2 of given number.
  */
  static Tuint closestStep2(const Tuint a_cX);

  //! Convert from degrees into radians.
  /*!
      \param a_cX - Degree value.
      \return Radian value.
  */
  static Treal degToRad(const Treal a_cX);

  //! Convert from radians into degrees.
  /*!
      \param a_cX - Radian value.
      \return Degree value.
  */
  static Treal radToDeg(const Treal a_cX);

  //! Copy sign from Y to X.
  /*!
      \param a_cX - Real number X.
      \param a_cY - Real number Y.
      \return Number X with sign as in number Y.
  */
  static Treal copySign(const Treal a_cX, const Treal a_cY);

  //! Returns arccos(X).
  /*!
      \param a_cX - Real number.
      \return arccos(X).
  */
  static Treal acos(const Treal a_cX);
  //! Returns the inverse hyperbolic cosine of X.
  /*!
      \param a_cX - Real number.
      \return arccosh(X).
  */
  static Treal acosh(const Treal a_cX);
  //! Returns arcsin(X).
  /*!
      \param a_cX - Real number.
      \return arcsin(X).
  */
  static Treal asin(const Treal a_cX);
  //! Returns the inverse hyperbolic sine of X.
  /*!
      \param a_cX - Real number.
      \return arcsinh(X).
  */
  static Treal asinh(const Treal a_cX);
  //! Returns arctan(X).
  /*!
      \param a_cX - Real number.
      \return arctan(X).
  */
  static Treal atan(const Treal a_cX);
  //! Returns the inverse hyperbolic tangent of X.
  /*!
      \param a_cX - Real number.
      \return arctanh(X)
  */
  static Treal atanh(const Treal a_cX);
  //! Returns arctan2(X, Y).
  /*!
      \param a_cX - Real number X.
      \param a_cY - Real number Y.
      \return arctan2(X, Y).
  */
  static Treal atan2(const Treal a_cX, const Treal a_cY);

  //! Returns cos(X).
  /*!
      \param a_cX - Real number.
      \return cos(X).
  */
  static Treal cos(const Treal a_cX);
  //! Returns cosh(X).
  /*!
      \param a_cX - Real number.
      \return cosh(X).
  */
  static Treal cosh(const Treal a_cX);

  //! Returns sin(X).
  /*!
      \param a_cX - Real number.
      \return sin(X).
  */
  static Treal sin(const Treal a_cX);
  //! Returns sinh(X).
  /*!
      \param a_cX - Real number.
      \return sinh(X).
  */
  static Treal sinh(const Treal a_cX);

  //! Returns tan(X).
  /*!
      \param a_cX - Real number.
      \return tan(X).
  */
  static Treal tan(const Treal a_cX);
  //! Returns tanh(X).
  /*!
      \param a_cX - Real number.
      \return tanh(X).
  */
  static Treal tanh(const Treal a_cX);

  //! Calculate both sin(X) and cos(X).
  /*!
      \param a_cX - Real number.
      \param a_rSin - Reference to result value - sin(X).
      \param a_rCos - Reference to result value - cos(X).
  */
  static void sinCos(const Treal a_cX, Treal& a_rSin, Treal& a_rCos);

  //! Returns ln(X).
  /*!
      \param a_cX - Real number.
      \return ln(X).
  */
  static Treal log(const Treal a_cX);
  //! Returns log2(X).
  /*!
      \param a_cX - Real number.
      \return log2(X).
  */
  static Treal log2(const Treal a_cX);
  //! Returns log10(X).
  /*!
      \param a_cX - Real number.
      \return Log10(X).
  */
  static Treal log10(const Treal a_cX);
  //! Returns ln(X!).
  /*!
      \param a_cX - Integer number.
      \return ln(X!).
  */
  static Treal logFactorial(const Tsint a_cX);
  //! Returns ln(1+X).
  /*!
      \param a_cX - Real number.
      \return ln(1+X).
  */
  static Treal log1X(const Treal a_cX);
  //! Returns ln(gamma(X)).
  /*!
      \param a_cX - Real number.
      \return ln(gamma(X)).
  */
  static Treal logGamma(const Treal a_cX);

  //! Returns gamma(X).
  /*!
      \param a_cX - Real number.
      \return gamma(X).
  */
  static Treal gamma(const Treal a_cX);
  //! Returns incomplete gamma(A, X).
  /*!
      \param a_cA - Real number A.
      \param a_cX - Real number X.
      \param a_cTolerance - Maximum error tolerance (default is NDepth::NMath::CMath::getEpsilon()).
      \param a_cNMax - Maximum number of iterations (default is 100).
      \return Incomplete gamma(A, X).
  */
  static Treal incompleteGamma(const Treal a_cA, const Treal a_cX, const Treal a_cTolerance = CMath::getEpsilon(), const Tuint a_cNMax = 100);

  //! Returns modified bessel(X) of order 0.
  /*!
      \param a_cX - Real number.
      \return Modified bessel(X) of order 0.
  */
  static Treal modBessel0(const Treal a_cX);
  //! Returns modified bessel(X) of order 1.
  /*!
      \param a_cX - Real number.
      \return Modified bessel(X) of order 1.
  */
  static Treal modBessel1(const Treal a_cX);

  //! Returns error(X).
  /*!
      \param a_cX - Real number.
      \return error(X).
  */
  static Treal error(const Treal a_cX);

  //! Raise the real number X to an integer power Y with the minimal number of multiplications.
  /*!
      \param a_cX - Real number X.
      \param a_cY - Real number Y.
      \return X^Y.
  */
  static Treal pow(const Treal a_cX, const Tsint a_cY);
  //! Returns X^Y.
  /*!
      \param a_cX - Real number X.
      \param a_cY - Real number Y.
      \return X^Y.
  */
  static Treal pow(const Treal a_cX, const Treal a_cY);
  //! Returns 10^X.
  /*!
      \param a_cX - Integer number.
      \return 10^X.
  */
  static Treal pow10(const Tsint a_cX);

  //! Returns e^X.
  /*!
      \param a_cX - Real number.
      \return e^X.
  */
  static Treal exp(const Treal a_cX);
  //! Returns 2^X.
  /*!
      \param a_cX - Real number.
      \return 2^X.
  */
  static Treal exp2(const Treal a_cX);
  //! Returns 10^X.
  /*!
      \param a_cX - Real number.
      \return 10^X.
  */
  static Treal exp10(const Treal a_cX);
  //! Returns e^X-1 (Using: e^x-1=2^(x*log2(e))-1).
  /*!
      \param a_cX - Real number.
      \return e^X-1.
  */
  static Treal expm1(const Treal a_cX);

  //! Returns square root of X.
  /*!
      \param a_cX - Real number.
      \return sqrt(X).
  */
  static Treal sqrt(const Treal a_cX);
  //! Returns cubic root of X.
  /*!
      \param a_cX - Real number.
      \return cbrt(X).
  */
  static Treal cbrt(const Treal a_cX);

  //! Returns |X|.
  /*!
      \param a_cX - Real number.
      \return |X|.
  */
  static Treal fabs(const Treal a_cX);

  //! Compute positive difference.
  /*!
      \param a_cX - Real number X.
      \param a_cY - Real number Y.
      \return Positive difference.
  */
  static Treal fdim(const Treal a_cX, const Treal a_cY);

  //! Compute (X * Y) + Z as ternary operation.
  /*!
      \param a_cX - Real number X.
      \param a_cY - Real number Y.
      \param a_cZ - Real number Z.
      \return (X * Y) + Z.
  */
  static Treal fma(const Treal a_cX, const Treal a_cY, const Treal a_cZ);

  //! Compute maximum of two numbers, regarding NaN as missing argument.
  /*!
      \param a_cX - Real number X.
      \param a_cY - Real number Y.
      \return Maximum of two numbers.
  */
  static Treal fmax(const Treal a_cX, const Treal a_cY);
  //! Compute minimum of two numbers, regarding NaN as missing argument.
  /*!
      \param a_cX - Real number X.
      \param a_cY - Real number Y.
      \return Minimum of two numbers.
  */
  static Treal fmin(const Treal a_cX, const Treal a_cY);

  //! Returns X mod Y.
  /*!
      \param a_cX - Real number X.
      \param a_cY - Real number Y.
      \return X mod Y.
  */
  static Treal fmod(const Treal a_cX, const Treal a_cY);

  //! Returns ceil(X).
  /*!
      \param a_cX - Real number.
      \return ceil(X).
  */
  static Treal ceil(const Treal a_cX);

  //! Returns floor(X).
  /*!
      \param a_cX - Real number.
      \return floor(X).
  */
  static Treal floor(const Treal a_cX);

  //! Calculate polynome p=C[n-1]*X^n+C[n-2]*X^(n-1)+...+C[1]*X+C[0].
  /*!
      \param a_cX - Real number X.
      \param a_cN - Size of the polynome coefficients.
      \param a_cpC - Constant pointer to the polynome coefficient array.
      \return Polinome value.
  */
  static Treal poly(const Treal a_cX, const Tsint a_cN, const Treal* a_cpC);

  //! Calculate hypotinuse C=sqrt(X^2+Y^2).
  /*!
      \param a_cX - Real number X.
      \param a_cY - Real number Y.
      \return Hypotinuse value.
  */
  static Treal hypot(const Treal a_cX, const Treal a_cY);

  //! Get M and P where X=M*2^P (0.5<=M<1).
  /*!
      \param a_cX - Real number X.
      \param a_rExp - Reference to result value - exponent.
      \return frexp(X, Exp).
  */
  static Treal frexp(const Treal a_cX, Tsint& a_rExp);
  //! Calculate value=X*2^exp (0.5<=X<1).
  /*!
      \param a_cX - Real number X.
      \param a_cExp - Exponent.
      \return ldexp(X, Exp).
  */
  static Treal ldexp(const Treal a_cX, const Tsint a_cExp);

  //! Make integer and real part of a number.
  /*!
      \param a_cX - Real number.
      \param a_rInteger - Reference to result value - integer part of the number.
      \return Real part.
  */
  static Tfloat modf(const Tfloat a_cX, Tfloat& a_rInteger);
  //! Make integer and real part of a number.
  /*!
      \param a_cX - Real number.
      \param a_rInteger - Reference to result value - integer part of the number.
      \return Real part.
  */
  static Tdouble modf(const Tdouble a_cX, Tdouble& a_rInteger);

private:
  static Treal ms_Epsilon;              //!< Accuracy for common mathematical calculations.
  static NProcess::CRWLock ms_Locker;   //!< Math class reader/writer locker.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* SERIALIZATION FUNCTION DECLARATIONS                                      */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
//! Serialization load real number state.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized real number state instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NMath::CMath::ENumberState& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save real number state.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized real number state instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NMath::CMath::ENumberState& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize real number state.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized real number state instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NMath::CMath::ENumberState& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/math/CMath.inl>
/*==========================================================================*/
//! \example example-math-CMath.cpp
/*--------------------------------------------------------------------------*/
//! \test test-math-CMath.cpp
/*==========================================================================*/
#endif
