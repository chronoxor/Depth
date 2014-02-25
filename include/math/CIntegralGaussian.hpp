/*!
 *  \file    CIntegralGaussian.hpp Integral class contains functionality to
 *           calculate one-dimensional integrals with Gaussian method.
 *  \brief   Static class for integral calculations with Gaussian method.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class for integral calculations with Gaussian method.

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
#ifndef __CINTEGRALGAUSSIAN_HPP__
#define __CINTEGRALGAUSSIAN_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/functors/CFunctor1.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Static class for integral calculations with Gaussian method.
/*!
    This class helps  to  calculate  one-dimensional  integral  value  of  the
    arbitrary function inside fixed bounds with Gaussian method.
*/
class BASE_API CIntegralGaussian :
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
      \return Integral value.
  */
  static Treal integral(const TFunctor& a_cfrFunction, const Treal a_cA, const Treal a_cB);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
