/*!
 *  \file    CKernel.cpp Definitions of the mathematical kernel methods.
 *  \brief   Static class for mathematical kernel methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class for mathematical kernel methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Math
    VERSION:   1.0
    CREATED:   26.01.2006 02:52:45

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
#include <Depth/include/math/CKernel.hpp>
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/math/CMathConstants.hpp>
/*==========================================================================*/
#ifndef __CKERNEL_CPP__
#define __CKERNEL_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Treal CKernel::biweight(const Treal a_cX)
{ CALL
  Treal temp;

  if ((-1.0 <= a_cX) && (a_cX <= 1.0))
  {
    temp = CONSTR(1.0) - a_cX * a_cX;
    return (CONSTR(0.3125) * temp * temp);
  }
  else
    return 0.0;
}
/*--------------------------------------------------------------------------*/
Treal CKernel::cosine(const Treal a_cX)
{ CALL
  if ((-1.0 <= a_cX) && (a_cX <= 1.0))
    return (CONSTR(0.5) + CONSTR(0.5) * CMath::cos(CMathConstants::PI * a_cX));
  else
    return 0.0;
}
/*--------------------------------------------------------------------------*/
Treal CKernel::epanech(const Treal a_cX)
{ CALL
  if ((-1.0 <= a_cX) && (a_cX <= 1.0))
    return (CONSTR(0.75) - CONSTR(0.75) * a_cX * a_cX);
  else
    return 0.0;
}
/*--------------------------------------------------------------------------*/
Treal CKernel::gaussian(const Treal a_cX)
{ CALL
  return (CONSTR(0.3989422804014327) * CMath::exp(-a_cX * a_cX * CONSTR(0.5)));
}
/*--------------------------------------------------------------------------*/
Treal CKernel::rectangular(const Treal a_cX)
{ CALL
  if ((-1.0 <= a_cX) && (a_cX <= 1.0))
    return 0.5;
  else
    return 0.0;
}
/*--------------------------------------------------------------------------*/
Treal CKernel::triangular(const Treal a_cX)
{ CALL
  if ((-1.0 <= a_cX) && (a_cX <= 1.0))
    return CMath::fabs(CONSTR(1.0) - a_cX);
  else
    return 0.0;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
