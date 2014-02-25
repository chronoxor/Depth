/*!
 *  \file    CMathConstants.cpp Definition of most mathematical and physical
 *           constants.
 *  \brief   Static class with mathematical constants (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class with mathematical constants (source).

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
#include <Depth/include/math/CMathConstants.hpp>
/*==========================================================================*/
#ifndef __CMATHCONSTANTS_CPP__
#define __CMATHCONSTANTS_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
BASE_API const Treal CMathConstants::E          = (Treal)2.71828182845904523536;
BASE_API const Treal CMathConstants::E_2        = (Treal)1.35914091422952261768;
BASE_API const Treal CMathConstants::E2         = (Treal)5.43656365691809047072;
BASE_API const Treal CMathConstants::LOG2E      = (Treal)1.44269504088896340736;
BASE_API const Treal CMathConstants::LOG10E     = (Treal)0.434294481903251827651;
BASE_API const Treal CMathConstants::LN2        = (Treal)0.693147180559945309417;
BASE_API const Treal CMathConstants::LN10       = (Treal)2.30258509299404568402;
BASE_API const Treal CMathConstants::PI         = (Treal)3.14159265358979323846264338327950288419716939937511;
BASE_API const Treal CMathConstants::PI_2       = (Treal)1.57079632679489662;
BASE_API const Treal CMathConstants::PI_4       = (Treal)0.78539816339744831;
BASE_API const Treal CMathConstants::PI2        = (Treal)6.2831853071795864769252867665590;
BASE_API const Treal CMathConstants::PI4        = (Treal)12.5663706143591729538505735331180;
BASE_API const Treal CMathConstants::ONE_PI     = (Treal)0.318309886183790671538;
BASE_API const Treal CMathConstants::TWO_PI     = (Treal)0.636619772367581343076;
BASE_API const Treal CMathConstants::TWO_SQRTPI = (Treal)1.12837916709551257390;
BASE_API const Treal CMathConstants::SQRT_2     = (Treal)0.70710678118654752440084436210485;
BASE_API const Treal CMathConstants::SQRT2      = (Treal)1.41421356237309504880168872420969807857;
BASE_API const Treal CMathConstants::SQRTPI     = (Treal)1.7724538509055160272981674833411;
BASE_API const Treal CMathConstants::SQRT2PI    = (Treal)2.5066282746310005024157652848111;
BASE_API const Treal CMathConstants::SQRT_PI_2  = (Treal)1.2533141373155002512078826424055;
BASE_API const Treal CMathConstants::SQRT_2_PI  = (Treal)0.79788456080286535587989211986876;
BASE_API const Treal CMathConstants::Euler      = (Treal)0.5772156649015328606065120900824024310422;
BASE_API const Treal CMathConstants::c          = (Treal)299792458.0;
BASE_API const Treal CMathConstants::G          = (Treal)6.67259e-11;
BASE_API const Treal CMathConstants::h          = (Treal)6.6260755e-34;
BASE_API const Treal CMathConstants::hbar       = (Treal)(CMathConstants::h / CMathConstants::PI / 2);
BASE_API const Treal CMathConstants::mP         = (Treal)2.17671e-8;
BASE_API const Treal CMathConstants::lP         = (Treal)1.61605e-35;
BASE_API const Treal CMathConstants::tP         = (Treal)5.39056e-44;
BASE_API const Treal CMathConstants::e          = (Treal)1.60217733e-19;
BASE_API const Treal CMathConstants::mu0        = (Treal)(CMathConstants::PI * 4.0e-7);
BASE_API const Treal CMathConstants::eps0       = (Treal)(1.0 / (CMathConstants::mu0 * CMathConstants::c * CMathConstants::c));
BASE_API const Treal CMathConstants::Phi0       = (Treal)2.06783461e-15;
BASE_API const Treal CMathConstants::RH         = (Treal)25812.8056;
BASE_API const Treal CMathConstants::me         = (Treal)9.1093897e-31;
BASE_API const Treal CMathConstants::mmu        = (Treal)1.8835327e-28;
BASE_API const Treal CMathConstants::mp         = (Treal)1.6726231e-27;
BASE_API const Treal CMathConstants::mn         = (Treal)1.6749286e-27;
BASE_API const Treal CMathConstants::md         = (Treal)3.3435860e-27;
BASE_API const Treal CMathConstants::mpe        = (Treal)1836.152701;
BASE_API const Treal CMathConstants::alpha      = (Treal)7.29735308e-3;
BASE_API const Treal CMathConstants::Ry         = (Treal)10973731.534;
BASE_API const Treal CMathConstants::a0         = (Treal)0.529177249e-10;
BASE_API const Treal CMathConstants::Eh         = (Treal)4.3597482e-18;
BASE_API const Treal CMathConstants::muB        = (Treal)9.2740154e-24;
BASE_API const Treal CMathConstants::muN        = (Treal)5.0507866e-27;
BASE_API const Treal CMathConstants::ge         = (Treal)2.002319304386;
BASE_API const Treal CMathConstants::re         = (Treal)2.81794092e-15;
BASE_API const Treal CMathConstants::k          = (Treal)1.380658e-23;
BASE_API const Treal CMathConstants::L          = (Treal)6.0221367e23;
BASE_API const Treal CMathConstants::F          = (Treal)96485.309;
BASE_API const Treal CMathConstants::R          = (Treal)8.314510;
BASE_API const Treal CMathConstants::sigma      = (Treal)5.67051e-8;
BASE_API const Treal CMathConstants::Vm         = (Treal)22.41410;
BASE_API const Treal CMathConstants::c1         = (Treal)3.7417749e-16;
BASE_API const Treal CMathConstants::c2         = (Treal)0.01438769;
BASE_API const Treal CMathConstants::eV         = (Treal)(CMathConstants::e);
BASE_API const Treal CMathConstants::amu        = (Treal)1.6605402e-27;
BASE_API const Treal CMathConstants::g          = (Treal)9.80665;
BASE_API const Treal CMathConstants::atm        = (Treal)101325;
BASE_API const Treal CMathConstants::cal        = (Treal)4.1840;
BASE_API const Treal CMathConstants::in         = (Treal)0.0254;
BASE_API const Treal CMathConstants::ft         = (Treal)(12 * CMathConstants::in);
BASE_API const Treal CMathConstants::yd         = (Treal)(3 * CMathConstants::ft);
BASE_API const Treal CMathConstants::mi         = (Treal)(1760 * CMathConstants::yd);
BASE_API const Treal CMathConstants::oz         = (Treal)0.02834952;
BASE_API const Treal CMathConstants::lb         = (Treal)(16 * CMathConstants::oz);
BASE_API const Treal CMathConstants::RK90       = (Treal)25812.807;
BASE_API const Treal CMathConstants::mp93u      = (Treal)1.0072764666;
BASE_API const Treal CMathConstants::me95u      = (Treal)0.0005485799111;
BASE_API const Treal CMathConstants::mpe95      = (Treal)1836.1526665;
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
