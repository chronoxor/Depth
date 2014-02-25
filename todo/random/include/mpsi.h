/*-----------------------------------------------------------------------------*\
| include file for Matpack: physical constants and conversions           mpsi.h |
|                                                                               |
| Last change: Sep 12, 2004                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel                                   |
|                                                                               |
| Permission to  use, copy, and  distribute  Matpack  in  its  entirety and its | 
| documentation for  non-commercial purpose and  without fee is hereby granted, | 
| provided that this license information and copyright notice appear unmodified | 
| in all copies. This software is provided 'as is'  without  express or implied | 
| warranty.  In no event will the author be held liable for any damages arising | 
| from the use of this software.						|
| Note that distributing Matpack 'bundled' in with any product is considered to | 
| be a 'commercial purpose'.							|
| The software may be modified for your own purposes, but modified versions may | 
| not be distributed without prior consent of the author.			|
|                                                                               |
| Read the  COPYRIGHT and  README files in this distribution about registration	|
| and installation of Matpack.							|
|                                                                               |
\*-----------------------------------------------------------------------------*/

#ifndef _MPSI_H_
#define _MPSI_H_

#include <compat.h>
#include <math.h>

namespace MATPACK {

//-----------------------------------------------------------------------------//
//
// This file defines "class SI" which contains tables of adjusted physical 
// constants according to the CODATA 1986 recommendations in  SI-units.
// To use the class include "mpsi.h"
//
// Reference:
// E. R. Cohen, B. N. Taylor, J. Res. Nat. Bureau of Standards, 92, 85 (1987).
//
// The name of the constants follows as close as possible the commonly used
// abbreviations for the quantity using upper and lower case letters. This
// way the constants are most easy to remember.
//
// For instance:
//
// 	SI::c  is the speed of light
//      SI::G  is the constant of gravitation
//
// The commonly used subscripts are attached to the name:
//
//	SI::mu0 for mu with subscript 0 for the magnetic permeability
//
// Greek letters are spelled out:
//
//	SI::Phi0 for the flux quantum
//
// For every constant SI::x there is a constant SI::x_tol which gives the
// tolerance. This is the relative uncertainty as given from the measurements
// and the least squares adjustment. Quantities for which this value is zero
// are given "by definition".
//
// In the "demos" directory there is a program which prints out all values!
//
//-----------------------------------------------------------------------------//

class SI {

  public:
  static const double

    // Universal Constants

    c,      c_tol,      // m s^(-1)		speed of light
    G,      G_tol,      // m^3 kg^(-1) s^(-2)	gravitation constant
    h,      h_tol,      // J s			Planck constant
    hbar,   hbar_tol,   // J s			Planck constant/2pi
    mP,     mP_tol,     // kg			Planck mass
    lP,     lP_tol,     // m			Planck length
    tP,     tP_tol,     // s			Planck time

    // Electromagnetic constants

    e,       e_tol,      // C			elementary charge
    mu0,     mu0_tol,    // N A^(-2)		vacuum permeability
    eps0,    eps0_tol,   // F m^(-1)		vacuum permitivity
    Phi0,    Phi0_tol,   // Wb			flux quantum
    RH,      RH_tol,     // Ohm			quantized Hall resistance

    // Atomic constants

    me,      me_tol,     // kg			electron mass
    mmu,     mmu_tol,    // kg			muon mass
    mp,      mp_tol,     // kg			proton mass
    mn,      mn_tol,     // kg			neutron mass
    md,      md_tol,     // kg			deuteron mass
    mpe,     mpe_tol,    // 1			proton/electron mass
    alpha,   alpha_tol,  // 1			fine-structure const.
    Ry,      Ry_tol,     // m(-1)		Rydberg constant
    a0,      a0_tol,     // m			Bohr radius
    Eh,      Eh_tol,     // J			Hartree energy
    muB,     muB_tol,    // J T(-1)		Bohr magneton
    muN,     muN_tol,    // J T(-1)		nuclear magneton
    ge,      ge_tol,     // 1			electron g-factor
    re,      re_tol,     // m			classical electron radius

    // Thermodynamic constants

    k,       k_tol,       // J K(-1)            Boltzmann constant
    L,       L_tol,       // mol(-1)		Avogadro constant
    F,       F_tol,       // C mol(-1)		Faraday constant
    R,       R_tol,       // J mol(-1) K(-1)    Gas constant
    sigma,   sigma_tol,   // W m(-2) K(-4)      Stefan-Boltzmann const.
    Vm,      Vm_tol,      // l/mol		Molar volume at p=101325 Pa
    c1,      c1_tol,      // W m2		1st radiation constant
    c2,      c2_tol,      // m K		2nd radiation constant

    // Conversion factors

    eV,      eV_tol,       // J			electron volt
    amu,     amu_tol,      // kg		atomic mass unit
    g,       g_tol,        // m s(-2)		standard acceleration
    atm,     atm_tol,      // Pa		standard athmoshere
    cal,     cal_tol,      // J			thermodynamic calorie

    // US units to SI units

    in,      in_tol,        // m		inch
    ft,      ft_tol,        // m		foot
    yd,      yd_tol,        // m		yard
    mi,      mi_tol,        // m		statute mile
    oz,      oz_tol,        // kg		ounce
    lb,      lb_tol,        // kg		pound

    // latest high precision measurements - not adjusted

    // Since 1.1.1990 RK90 is the recommended definition for the Ohm
    RK90,    RK90_tol,       // Ohm		von-Klitzing constant

    // Ref: G. Audi, A.H. Wapstra, Nucl. Phys. A565, 1 (1993)
    mp93u,   mp93u_tol,      // amu		proton mass in amu

    // Ref: D.L. Farnham, R.S. van Dyck Jr., P.B. Schwingberg, Phys. Rev. Lett. 75, 3598 (1995)
    me95u,   me95u_tol,      // amu 		electron mass in amu
    mpe95,   mpe95_tol;      // 1		proton/electron mass
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
