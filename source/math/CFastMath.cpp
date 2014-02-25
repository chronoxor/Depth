/*!
 *  \file    CFastMath.cpp Fast calculated mathematical methods definition.
 *  \brief   Static class for fast calculated mathematical methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class for fast calculated mathematical methods (source).

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
#include <Depth/include/math/CFastMath.hpp>
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/math/CMathConstants.hpp>
/*==========================================================================*/
#ifndef __CFASTMATH_CPP__
#define __CFASTMATH_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Treal CFastMath::sin1(const Treal a_cX)
{ CALL
  Treal sqrx = a_cX * a_cX;
  Treal result = CONSTR(7.61e-03);
  result *= sqrx;
  result -= CONSTR(1.6605e-01);
  result *= sqrx;
  result += CONSTR(1.0);
  result *= a_cX;
  return result;
}
/*--------------------------------------------------------------------------*/
Treal CFastMath::sin2(const Treal a_cX)
{ CALL
  Treal sqrx = a_cX * a_cX;
  Treal result = CONSTR(-2.39e-08);
  result *= sqrx;
  result += CONSTR(2.7526e-06);
  result *= sqrx;
  result -= CONSTR(1.98409e-04);
  result *= sqrx;
  result += CONSTR(8.3333315e-03);
  result *= sqrx;
  result -= CONSTR(1.666666664e-01);
  result *= sqrx;
  result += CONSTR(1.0);
  result *= a_cX;
  return result;
}
/*--------------------------------------------------------------------------*/
Treal CFastMath::cos1(const Treal a_cX)
{ CALL
  Treal sqrx = a_cX * a_cX;
  Treal result = CONSTR(3.705e-02);
  result *= sqrx;
  result -= CONSTR(4.967e-01);
  result *= sqrx;
  result += CONSTR(1.0);
  return result;
}
/*--------------------------------------------------------------------------*/
Treal CFastMath::cos2(const Treal a_cX)
{ CALL
  Treal sqrx = a_cX * a_cX;
  Treal result = CONSTR(-2.605e-07);
  result *= sqrx;
  result += CONSTR(2.47609e-05);
  result *= sqrx;
  result -= CONSTR(1.3888397e-03);
  result *= sqrx;
  result += CONSTR(4.16666418e-02);
  result *= sqrx;
  result -= CONSTR(4.999999963e-01);
  result *= sqrx;
  result += CONSTR(1.0);
  return result;
}
/*--------------------------------------------------------------------------*/
Treal CFastMath::tan1(const Treal a_cX)
{ CALL
  Treal sqrx = a_cX * a_cX;
  Treal result = CONSTR(2.033e-01);
  result *= sqrx;
  result += CONSTR(3.1755e-01);
  result *= sqrx;
  result += CONSTR(1.0);
  result *= a_cX;
  return result;
}
/*--------------------------------------------------------------------------*/
Treal CFastMath::tan2(const Treal a_cX)
{ CALL
  Treal sqrx = a_cX * a_cX;
  Treal result = CONSTR(9.5168091e-03);
  result *= sqrx;
  result += CONSTR(2.900525e-03);
  result *= sqrx;
  result += CONSTR(2.45650893e-02);
  result *= sqrx;
  result += CONSTR(5.33740603e-02);
  result *= sqrx;
  result += CONSTR(1.333923995e-01);
  result *= sqrx;
  result += CONSTR(3.333314036e-01);
  result *= sqrx;
  result += CONSTR(1.0);
  result *= a_cX;
  return result;
}
/*--------------------------------------------------------------------------*/
Treal CFastMath::asin(const Treal a_cX)
{ CALL
  Treal root = CMath::sqrt(CONSTR(1.0) - a_cX);
  Treal result = CONSTR(-0.0187293);
  result *= a_cX;
  result += CONSTR(0.0742610);
  result *= a_cX;
  result -= CONSTR(0.2121144);
  result *= a_cX;
  result += CONSTR(1.5707288);
  result = CMathConstants::PI_2 - root * result;
  return result;
}
/*--------------------------------------------------------------------------*/
Treal CFastMath::acos(const Treal a_cX)
{ CALL
  Treal root = CMath::sqrt(CONSTR(1.0) - a_cX);
  Treal result = CONSTR(-0.0187293);
  result *= a_cX;
  result += CONSTR(0.0742610);
  result *= a_cX;
  result -= CONSTR(0.2121144);
  result *= a_cX;
  result += CONSTR(1.5707288);
  result *= root;
  return result;
}
/*--------------------------------------------------------------------------*/
Treal CFastMath::atan1(const Treal a_cX)
{ CALL
  Treal sqrx = a_cX * a_cX;
  return (a_cX / (CONSTR(1.0) + CONSTR(0.28) * sqrx));
}
/*--------------------------------------------------------------------------*/
Treal CFastMath::atan2(const Treal a_cX)
{ CALL
  Treal sqrx = a_cX * a_cX;
  Treal result = CONSTR(0.0208351);
  result *= sqrx;
  result -= CONSTR(0.085133);
  result *= sqrx;
  result += CONSTR(0.180141);
  result *= sqrx;
  result -= CONSTR(0.3302995);
  result *= sqrx;
  result += CONSTR(0.999866);
  result *= a_cX;
  return result;
}
/*--------------------------------------------------------------------------*/
Treal CFastMath::atan3(const Treal a_cX)
{ CALL
  Treal sqrx = a_cX * a_cX;
  Treal result = CONSTR(0.0028662257);
  result *= sqrx;
  result -= CONSTR(0.0161657367);
  result *= sqrx;
  result += CONSTR(0.0429096138);
  result *= sqrx;
  result -= CONSTR(0.0752896400);
  result *= sqrx;
  result += CONSTR(0.1065626393);
  result *= sqrx;
  result -= CONSTR(0.1420889944);
  result *= sqrx;
  result += CONSTR(0.1999355085);
  result *= sqrx;
  result -= CONSTR(0.3333314528);
  result *= sqrx;
  result += CONSTR(1.0);
  result *= a_cX;
  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
