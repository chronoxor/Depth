/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                    rangamma.cpp |
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

#include "mprandom.h"

namespace MATPACK {

//----------------------------------------------------------------------------//
// class GammaDistribution						      //
//----------------------------------------------------------------------------//
//								       	      //
// Return Gamma distributed random deviates according to:		      //
//								       	      //
//                      a-1  -bx					      //
//                b (bx)    e						      //
//  p   (x) dx = ---------------- dx   for x > 0			      //
//   a,b             Gamma(a)						      //
//				   					      //
//             =  0                    otherwise			      //
//								       	      //
// The arguments must satisfy the conditions:			       	      //
//	a > 0   (positive)					       	      //
//	b != 0	(non-zero)					       	      //
//								       	      //
// References:								      //
//								       	      //
//	For parameter a >= 1 corresponds to algorithm GD in:	       	      //
//	J. H. Ahrens and U. Dieter, Generating Gamma Variates by a	      //
//	Modified Rejection Technique, Comm. ACM, 25, 1, 47-54 (1982).	      //
//								       	      //
//	For parameter 0 < a < 1 corresponds to algorithm GS in:	       	      //
//	J. H. Ahrens and U. Dieter, Computer Methods for Sampling 	      //
//	from Gamma, Beta, Poisson and Binomial Distributions,		      // 
//	Computing, 12, 223-246 (1974).					      //
//								       	      //
//----------------------------------------------------------------------------//

void GammaDistribution::Initialize (double order, double loc)
{
    // check parameters
    if (order <= 0)
	Matpack.Error("GammaDistribution (double order, double loc):\n"
		      "order must be greater than zero");
    if (loc == 0)
	Matpack.Error("GammaDistribution (double order, double loc):\n"
		      "location parameter must be non-zero");

    // store parameters
    A = order;	// a is the mean of the standard gamma distribution (b = 0)
    B = loc;

    // scale random long to (0,1) - boundaries are not allowed !
    scale  = 1.0 / (NormalDistribution::max_val+1.0);

    // select algorithm
    algorithmGD = (A >= 1);

    // initialize algorithm GD
    if (algorithmGD) {    

	// coefficients q(k) for q0 = sum(q(k)*a**(-k))
	const double 
	    q1 = 4.166669e-2,
	    q2 = 2.083148e-2,
	    q3 = 8.01191e-3,
	    q4 = 1.44121e-3,
	    q5 = -7.388e-5,
	    q6 = 2.4511e-4,
	    q7 = 2.424e-4;

	// calculates s, s2, and d
	s2 = A - 0.5;
	s = sqrt(s2);
	d = sqrt(32.0) - 12.0 * s;	

	// calculate q0, b, si, and c
	r = 1.0 / A;
	q0 = ((((((q7*r+q6)*r+q5)*r+q4)*r+q3)*r+q2)*r+q1)*r;

	// Approximation depending on size of parameter A.
	// The constants in the expressions for b, si, and
	// c were established by numerical experiments.

	if (A <= 3.686) {		// case 1.0 <= A <= 3.686
	    b = 0.463 + s + 0.178 * s2;
	    si = 1.235;
	    c = 0.195 / s - 7.9e-2 + 1.6e-1 * s;
	} else if (A <= 13.022) {	// case  3.686 < A <= 13.022
	    b = 1.654 + 7.6e-3 * s2;
	    si = 1.68 / s + 0.275;
	    c = 6.2e-2 / s + 2.4e-2;
	} else {			// case A > 13.022
	    b = 1.77;
	    si = 0.75;
	    c = 0.1515 / s;
	}

    // initialize algorithm GS
    } else {
	b = 1.0 + 0.3678794 * A;
    }
}


//----------------------------------------------------------------------------//


double GammaDistribution::operator () (void)
{
    // algorithm GD for A >= 1
    if (algorithmGD) {

	const double 
	    // coefficients a(k) for q = q0+(t*t/2)*sum(a(k)*v**k)	
	    a1 = 0.3333333,
	    a2 = -0.250003,
	    a3 = 0.2000062,
	    a4 = -0.1662921,
	    a5 = 0.1423657,
	    a6 = -0.1367177,
	    a7 = 0.1233795,
	    // coefficients e(k) for exp(q)-1 = sum(e(k)*q**k)	
	    e1 = 1.0,
	    e2 = 0.4999897,
	    e3 = 0.166829,
	    e4 = 4.07753E-2,
	    e5 = 1.0293E-2;
	
	double q, w, gamdis;

	// standard normal deviate
	double t = this->NormalDistribution::operator()();

	// (s,1/2)-normal deviate
	double x = s + 0.5 * t;
	
	// immediate acceptance
	gamdis = x * x;
	if (t >= 0.0) return gamdis/B;

	// (0,1) uniform sample, squeeze acceptance
	double u = NormalDistribution::gen->Long() * scale;
	if ( d * u <= t * t * t ) return gamdis/B;

	// no quotient test if x not positive
	if (x > 0.0) { 

	    // calculation of v and quotient q
	    double v = t / (s + s);
	    if (fabs(v) <= 0.25)
		q = q0 + 0.5*t*t * ((((((a7*v+a6)*v+a5)*v+a4)*v+a3)*v+a2)*v+a1)*v;
	    else 
		q = q0 - s * t + 0.25 * t * t + (s2+s2) * log(1.0+v);
	    
	    // quotient acceptance 
	    if (log(1.0-u) <= q) return gamdis/B;
	}

      loop:

	// stdandard exponential deviate
	double e = this->ExponentialDistribution::operator()();

	// (0,1) uniform deviate
	u = NormalDistribution::gen->Long() * scale;

	u += (u-1.0);	

	// (b,si) double exponential (Laplace)
	t = b + CopySign(si*e,u);

	// rejection if t < tau(1) = -0.71874483771719
	if (t < -0.71874483771719) goto loop;

	// calculation of v and quotient q
	double v = t / (s + s);
	if (fabs(v) <= 0.25) 
	    q = q0 + 0.5*t*t * ((((((a7*v+a6)*v+a5)*v+a4)*v+a3)*v+a2)*v+a1)*v;
	else
	    q = q0 - s * t + 0.25*t*t + (s2+s2) * log(1.0+v);
	
	// hat acceptance
	if (q <= 0.0) goto loop;

	if (q <= 0.5) 
	    w = ((((e5*q+e4)*q+e3)*q+e2)*q+e1)*q;
	else
	    w = exp(q) - 1.0;

	// if t is rejected, sample again
	if ( c * fabs(u) > w * exp(e-0.5*t*t) ) goto loop;

	x = s + 0.5*t;
	gamdis = x * x;
	return gamdis/B;


    // algorithm GS for 0 < A < 1
    } else {
	
	double gamdis;
	for (;;) {
	    double p = b * NormalDistribution::gen->Long() * scale;
	    if (p < 1.0) {
		gamdis = exp( log(p) / A );
		if (this->ExponentialDistribution::operator()() 
				>= gamdis) return gamdis/B;
	    } else {
		gamdis = -log( (b-p) / A );
		if (this->ExponentialDistribution::operator()() 
				>= (1.0-A)*log(gamdis)) return gamdis/B;
	    }
	} // for

    }
}

} // namespace MATPACK

//----------------------------------------------------------------------------//

