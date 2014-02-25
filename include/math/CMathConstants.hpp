/*!
 *  \file    CMathConstants.hpp Definition of most mathematical and physical
 *           constants.
 *  \brief   Static class with mathematical constants.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class with mathematical constants.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Math
    VERSION:   1.0
    CREATED:   06.01.2006 22:12:32

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
#ifndef __CMATHCONSTANTS_HPP__
#define __CMATHCONSTANTS_HPP__
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
//! Static class with mathematical constants.
/*!
    Class with mathimatical and physical constants definition.
*/
class BASE_API CMathConstants :
  public NDepth::NCommon::IStatic
{
public:
  // Math constants.
  static const Treal E;                 //!< E number.
  static const Treal E_2;               //!< E/2.
  static const Treal E2;                //!< 2*E.
  static const Treal LOG2E;             //!< log2(e).
  static const Treal LOG10E;            //!< log10(e).
  static const Treal LN2;               //!< ln(2).
  static const Treal LN10;              //!< ln(10).
  static const Treal PI;                //!< PI number.
  static const Treal PI_2;              //!< PI/2.
  static const Treal PI_4;              //!< PI/4.
  static const Treal PI2;               //!< 2*PI.
  static const Treal PI4;               //!< 4*PI.
  static const Treal ONE_PI;            //!< 1/PI.
  static const Treal TWO_PI;            //!< 2/PI.
  static const Treal TWO_SQRTPI;        //!< 2/sqrt(PI).
  static const Treal SQRT2;             //!< sqrt(2).
  static const Treal SQRT_2;            //!< sqrt(1/2).
  static const Treal SQRTPI;            //!< sqrt(PI).
  static const Treal SQRT2PI;           //!< sqrt(2*PI).
  static const Treal SQRT_PI_2;         //!< sqrt(PI/2).
  static const Treal SQRT_2_PI;         //!< sqrt(2/PI).
  static const Treal Euler;             //!< Euler number.
  // Universal constants.
  static const Treal c;                 //!< m s^(-1)           Sspeed of light.
  static const Treal G;                 //!< m^3 kg^(-1) s^(-2) Gravitation constant.
  static const Treal h;                 //!< J s                Planck constant.
  static const Treal hbar;              //!< J s                Planck constant / 2*PI.
  static const Treal mP;                //!< kg                 Planck mass.
  static const Treal lP;                //!< m                  Planck length.
  static const Treal tP;                //!< s                  Planck time.
  // Electromagnetic constants.
  static const Treal e;                 //!< C                  Elementary charge.
  static const Treal mu0;               //!< N A^(-2)           Vacuum permeability.
  static const Treal eps0;              //!< F m^(-1)           Vacuum permitivity.
  static const Treal Phi0;              //!< Wb                 Flux quantum.
  static const Treal RH;                //!< Ohm                Quantized Hall resistance.
  // Atomic constants.
  static const Treal me;                //!< kg                 Electron mass.
  static const Treal mmu;               //!< kg                 Muon mass.
  static const Treal mp;                //!< kg                 Proton mass.
  static const Treal mn;                //!< kg                 Neutron mass.
  static const Treal md;                //!< kg                 Deuteron mass.
  static const Treal mpe;               //!< 1                  Proton/electron mass.
  static const Treal alpha;             //!< 1                  Fine-structure const.
  static const Treal Ry;                //!< m(-1)              Rydberg constant.
  static const Treal a0;                //!< m                  Bohr radius.
  static const Treal Eh;                //!< J                  Hartree energy.
  static const Treal muB;               //!< J T(-1)            Bohr magneton.
  static const Treal muN;               //!< J T(-1)            Nuclear magneton.
  static const Treal ge;                //!< 1                  Electron g-factor.
  static const Treal re;                //!< m                  Classical electron radius.
  // Thermodynamic constants.
  static const Treal k;                 //!< J K(-1)            Boltzmann constant.
  static const Treal L;                 //!< mol(-1)            Avogadro constant.
  static const Treal F;                 //!< C mol(-1)          Faraday constant.
  static const Treal R;                 //!< J mol(-1) K(-1)    Gas constant.
  static const Treal sigma;             //!< W m(-2) K(-4)      Stefan-Boltzmann const.
  static const Treal Vm;                //!< l/mol              Molar volume at p=101325 Pa.
  static const Treal c1;                //!< W m2               1st radiation constant.
  static const Treal c2;                //!< m K                2nd radiation constant.
  // Conversion factors.
  static const Treal eV;                //!< J                  Electron volt.
  static const Treal amu;               //!< kg                 Atomic mass unit.
  static const Treal g;                 //!< m s(-2)            Standard acceleration.
  static const Treal atm;               //!< Pa                 Standard athmoshere.
  static const Treal cal;               //!< J                  Thermodynamic calorie.
  // US units to SI units.
  static const Treal in;                //!< m                  Inch.
  static const Treal ft;                //!< m                  Foot.
  static const Treal yd;                //!< m                  Yard.
  static const Treal mi;                //!< m                  Statute mile.
  static const Treal oz;                //!< kg                 Ounce.
  static const Treal lb;                //!< kg                 Pound.
  // Since 01.01.1990 RK90 is the recommended definition for the Ohm.
  static const Treal RK90;              //!< Ohm                Von-Klitzing constant.
  // Ref: G. Audi; A.H. Wapstra; Nucl. Phys. A565; 1 (1993).
  static const Treal mp93u;             //!< amu                Proton mass in amu.
  // Ref: D.L. Farnham; R.S. van Dyck Jr.; P.B. Schwingberg; Phys. Rev. Lett. 75; 3598 (1995).
  static const Treal me95u;             //!< amu                Electron mass in amu.
  static const Treal mpe95;             //!< 1                  Proton/electron mass.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
