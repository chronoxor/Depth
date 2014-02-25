/*!
 *  \file    CIntegralTrapezoid.hpp Integral class contains functionality to
 *           calculate one-dimensional integrals with Trapezoid method.
 *  \brief   Static class for integral calculations with Trapezoid method.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class for integral calculations with Trapezoid method.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Math
    VERSION:   1.0
    CREATED:   06.05.2006 23:47:22

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
#ifndef __CINTEGRALTRAPEZOID_HPP__
#define __CINTEGRALTRAPEZOID_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/functors/CFunctor1.hpp>
#include <Depth/include/math/CMath.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Static class for integral calculations with Trapezoid method.
/*!
    This class helps  to  calculate  one-dimensional  integral  value  of  the
    arbitrary function inside fixed bounds with Trapezoid method.
*/
class BASE_API CIntegralTrapezoid :
  public NDepth::NCommon::IStatic
{
public:
  //! Integral functor type.
  /*!
      This functor is used as a parameter  of  'integral()'  method.  Integral
      function should take one real argument and return value of the  function
      with this argument.

      \param a_cX - Argument of integral function.
      \return Function value at given argument.
  */
  typedef NFunctors::CFunctor<Treal (const Treal a_cX)> TFunctor;

  //! Calculate integral value.
  /*!
      Main method of integral calculation. It  takes  function  parameter  and
      bounds values. Then it returns integral value  which  calculates  inside
      the bounds.

      \param a_cfrFunction - Constant reference to the functor, which represents integral function.
      \param a_cA - Lower bound of integration.
      \param a_cB - Upper bound of integration.
      \param a_cTolerance - Maximum error tolerance (default is NDepth::NMath::CMath::getEpsilon()).
      \param a_cMaxIterations - Maximum number of iterations (default is 100).
      \return Integral value.
  */
  static Treal integral(const TFunctor& a_cfrFunction, const Treal a_cA, const Treal a_cB, const Treal a_cTolerance = CMath::getEpsilon(), const Tuint a_cMaxIterations = 100);

private:
  //! Calculate trapezoid value.
  /*!
      \param a_cfrFunction - Constant reference to the functor, which represents integral function.
      \param a_cA - Lower bound of integration.
      \param a_cB - Upper bound of integration.
      \param a_cX - Current bound of integration.
      \param a_cN - Current iteration step.
      \return Trapezoid value.
  */
  static Treal trapezoidCalculator(const TFunctor& a_cfrFunction, const Treal a_cA, const Treal a_cB, const Treal a_cX, const Tuint a_cN);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
