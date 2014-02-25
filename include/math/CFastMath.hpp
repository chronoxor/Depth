/*!
 *  \file    CFastMath.hpp Fast calculated mathematical methods definition.
 *  \brief   Static class for fast calculated mathematical methods.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class for fast calculated mathematical methods.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Math
    VERSION:   1.0
    CREATED:   26.01.2006 02:11:52

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
#ifndef __CFASTMATH_HPP__
#define __CFASTMATH_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Static class for fast calculated mathematical methods.
/*!
    For the inverse tangent calls, all approximations are valid for |t| <=  1.
    To compute ATAN(t) for t > 1, use ATAN(t) = PI/2 - ATAN(1/t). For t <  -1,
    use ATAN(t) = -PI/2 - ATAN(1/t).

    The approximation formulas are from the following source:
    Handbook of Mathematical Functions
    Edited by M. Abramowitz and I.A. Stegun.
    Dover Publications, Inc.
    New York, NY
    Ninth printing, December 1972
*/
class BASE_API CFastMath :
  public NDepth::NCommon::IStatic
{
public:
  //! Returns sin(X). Version 1.
  /*!
      The angle must be in [0,pi/2].
      The maximum absolute error is about 1.6415e-04.
      The speed up is about 1.91.

      \param a_cX - Value X.
      \return sin(x).
  */
  static Treal sin1(const Treal a_cX);
  //! Returns sin(X). Version 2.
  /*!
      The angle must be in [0,pi/2].
      The maximum absolute error is about 2.3279e-09.
      The speed up is about 1.40.

      \param a_cX - Value X.
      \return sin(x).
  */
  static Treal sin2(const Treal a_cX);

  //! Returns cos(X). Version 1.
  /*!
      The angle must be in [0,pi/2].
      The maximum absolute error is about 1.1880e-03.
      The speed up is about 2.14.

      \param a_cX - Value X.
      \return cos(x).
  */
  static Treal cos1(const Treal a_cX);
  //! Returns cos(X). Version 2.
  /*!
      The angle must be in [0,pi/2].
      The maximum absolute error is about 2.3082e-09.
      The speed up is about 1.47.

      \param a_cX - Value X.
      \return cos(x).
  */
  static Treal cos2(const Treal a_cX);

  //! Returns tan(X). Version 1.
  /*!
      The angle must be in [0,pi/4].
      The maximum absolute error is about 8.0613e-04.
      The speed up is about 2.51.

      \param a_cX - Value X.
      \return tan(x).
  */
  static Treal tan1(const Treal a_cX);
  //! Returns tan(X). Version 2.
  /*!
      The angle must be in [0,pi/4].
      The maximum absolute error is about 1.8897e-08.
      The speed up is about 1.71.

      \param a_cX - Value X.
      \return tan(x).
  */
  static Treal tan2(const Treal a_cX);

  //! Returns asin(X).
  /*!
      The angle must be in [0,1].
      The maximum absolute error is about 6.7626e-05.
      The speed up is about 2.59 (apparently asin()  is  much  more  expensive
      than sqrt()).

      \param a_cX - Value X.
      \return asin(x).
  */
  static Treal asin(const Treal a_cX);

  //! Returns acos(X).
  /*!
      The angle must be in [0,1].
      The maximum absolute error is about 6.7626e-05.
      The speed up is about 2.59 (apparently acos()  is  much  more  expensive
      than sqrt()).

      \param a_cX - Value X.
      \return acos(x).
  */
  static Treal acos(const Treal a_cX);

  //! Returns atan(X). Version 1.
  /*!
      The angle must be in [0,1].
      The maximum absolute error is about 4.8830e-03.
      The speed up is about 2.14.

      \param a_cX - Value X.
      \return atan(x).
  */
  static Treal atan1(const Treal a_cX);
  //! Returns atan(X). Version 2.
  /*!
      The angle must be in [0,1].
      The maximum absolute error is about 1.1492e-05.
      The speed up is about 2.16.

      \param a_cX - Value X.
      \return atan(x).
  */
  static Treal atan2(const Treal a_cX);
  //! Returns atan(X). Version 3.
  /*!
      The angle must be in [0,1].
      The maximum absolute error is about 1.3593e-08.
      The speed up is about 1.50.

      \param a_cX - Value X.
      \return atan(x).
  */
  static Treal atan3(const Treal a_cX);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
