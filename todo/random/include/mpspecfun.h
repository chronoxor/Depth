/*-----------------------------------------------------------------------------*\
| Matpack special functions prototypes                              mpspecfun.h |
|                                                                               |
| Last change: Jan 20, 2003                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2003 by Berndt M. Gammel. All rights reserved.             |
|                                                                               |
| Permission to  use, copy, and  distribute  Matpack  in  its entirety  and its |
| documentation  for non-commercial purpose and  without fee is hereby granted, |
| provided that this license information and copyright notice appear unmodified |
| in all copies.  This software is provided 'as is'  without express or implied |
| warranty.  In no event will the author be held liable for any damages arising |
| from the use of this software.                                                |
| Note that distributing Matpack 'bundled' in with any product is considered to |
| be a 'commercial purpose'.                                                    |
| The software may be modified for your own purposes, but modified versions may |
| not be distributed without prior consent of the author.                       |
|                                                                               |
| Read the  COPYRIGHT and  README files in this distribution about registration |
| and installation of Matpack.                                                  |
|                                                                               |
\*-----------------------------------------------------------------------------*/

// check for multiple inclusion
#ifndef _MPSPECFUN_H_
#define _MPSPECFUN_H_ 

#include "common.h"

//-----------------------------------------------------------------------------//

namespace MATPACK {
using std::complex;

// Basic functions
double  Cbrt            (double x);     // cube root
double  LogRel          (double x);     // log(1+x)

// complex 
complex<double> LogRel  (const complex<double> &z);

// Exponential functions
double  ExpIntegralEi    (double x);
double  ExpIntegralExpEi (double x);
double  ExpIntegralE1    (double x);

// Error functions
double  Erf             (double x);
double  Erfc            (double x);
double  Dawson          (double x);
double  Dawson_2        (double x);
complex<double> Faddeeva        (const complex<double>& z);
complex<double> Faddeeva_2      (const complex<double>& z);

// Gamma functions
double  Gamma           (double x);
double  LnGamma         (double x);
double  LnGamma         (double x, double &sgn);
double  RcpGamma        (double x);
double  Fac             (int n);

// incomplete
double  GammaI          (double x, double a);
double  GammaIC         (double x, double a);
double  GammaIT         (double x, double a);

// complex
complex<double> Gamma   (const complex<double> &z);
complex<double> LnGamma (const complex<double> &z);

// Beta functions
double  LnBeta          (double a, double b);

// incomplete
double  BetaI           (double x, double p, double q);

// Bessel functions
double  BesselI0        (double x);
double  BesselExpI0     (double x);
double  BesselI1        (double x);
double  BesselExpI1     (double x);

double  BesselK0        (double x);
double  BesselExpK0     (double x);
double  BesselK1        (double x);
double  BesselExpK1     (double x);

double  BesselJ0        (double x);
double  BesselJ1        (double x);
double  BesselJ         (int n, double x);

double  BesselY0        (double x);
double  BesselY1        (double x);
double  BesselY         (int n, double x);

double  AiryAi          (double x);
double  AiryExpAi       (double x);
double  AiryBi          (double x);
double  AiryExpBi       (double x);

// Orthogonal polynomials and associate functions

void    HermiteH        (int n, double x, 
                         double &y, double &dy, double &d2y);
void    LaguerreL       (int n, double a, double x, 
                         double &y, double &dy, double &d2y);
void    JacobiP         (int n, double a, double b, double x, 
                         double &y, double &dy, double &d2y);
void    ChebyshevT      (int n, double x, 
                         double &y, double &dy, double &d2y);
void    LegendreP       (int n, double x, 
                         double &y, double &dy, double &d2y);

double  LegendreP       (int l, int m, double x);

complex<double> SphericalHarmonicY (int l, int m, double theta, double phi);

// Vector coupling coefficients for rotations ( SU(2) )

void ThreeJSymbolM      (double l1, double l2, double l3, double m1, 
                         double &m2min, double &m2max, double *thrcof, int ndim, 
                         int &errflag);
void ThreeJSymbolJ      (double l2, double l3, double m2, double m3, 
                         double &l1min, double &l1max, double *thrcof, int ndim, 
                         int &errflag);
void SixJSymbol         (double l2, double l3, double l4, 
                         double l5, double l6, double &l1min, double &l1max, 
                         double *sixcof, int ndim, int &errflag);
double ClebschGordan    (double l1, double m1, double l2, double m2,
                         double l3, double m3, int &errflag);

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
