/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                     ranbeta.cpp |
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
#include <float.h>

namespace MATPACK {

//----------------------------------------------------------------------------//
// class BetaDistribution						      //
//----------------------------------------------------------------------------//
//								       	      //
// Return Beta distributed random deviates according to the density	      //
//								       	      //
//                 a-1       b-1					      //
//                x 	(1-x)						      //
//  p   (x) dx = --------------- dx   for 0 < x < 1			      //
//   a,b              B(a,b)						      //
//				   					      //
//             =  0                   otherwise				      //
//								       	      //
// References:								      //
//								       	      //
//	R. C. H. Cheng, Generating Beta Variatew with Non-integral Shape      //
//	Parameters, Comm. ACM, 21, 317-322 (1978). (Algorithms BB and BC).    //
//								       	      //
//----------------------------------------------------------------------------//

double BetaDistribution::operator () (void)
{         
    // returned on overflow
    const double infinity = DBL_MAX;

    double w;

    // Algorithm BB
    if (algorithmBB) {

	double r, t;
	do {
	    double u1 = gen->Long() * scale;
	    double u2 = gen->Long() * scale;
	    double v = beta * log(u1/(1.0-u1));
	    w = (v > maxexp) ? infinity : a * exp(v);	
	    double z = u1 * u1 * u2;
	    r = gamma * v - 1.3862944;
	    double s = a + r - w;
	    if (s + 2.609438 >= 5.0 * z) break;
	    t = log(z);
	    if (s > t) break;	    
	} while (r + alpha * log(alpha/(b+w)) < t);

    // Algorithm BC
    } else { 

      loop:

        double v, y, z;
        double u1 = gen->Long() * scale;
        double u2 = gen->Long() * scale;

        if (u1 < 0.5) {
	    y = u1 * u2;
	    z = u1 * y;
	    if (0.25 * u2 + z - y >= k1) goto loop;
	} else {
	    z = u1 * u1 * u2;
	    if (z <= 0.25) {
		v = beta * log(u1/(1.0-u1));
		w = (v > maxexp) ? infinity: a * exp(v);
		goto fin;
	    }
	    if (z >= k2) goto loop;
	}
        v = beta * log(u1/(1.0-u1));
        w = (v > maxexp) ? infinity : a * exp(v);
        if (alpha * (log(alpha/(b+w))+v) - 1.3862944 < log(z)) goto loop;

      fin: ;
    }

    // return result
    return (a == aa) ? w/(b+w) : b/(b+w);   
}


//----------------------------------------------------------------------------//


void BetaDistribution::Initialize (double pa, double pb)
{
    // check parameters
    if (pa <= 0.0 || pb <= 0.0)
	Matpack.Error("BetaDistribution: arguments a and b must be positive");

    // store parameters
    aa = pa; 
    bb = pb;

    // scale random long to (0,1) - boundaries are not allowed !
    scale  = 1.0 / (max_val+1.0);

    // maximal exponent for exp() function in evaluation "a*exp(v)" below
    maxexp = DBL_MAX_EXP * M_LN2 - 1;

    if (a > 1.0) maxexp -= ceil(log(a));

    algorithmBB = MpMin(aa,bb) > 1.0;

    // initialize algorithm BB
    if (algorithmBB) {
	a = MpMin(aa,bb);
	b = MpMax(aa,bb);
	alpha = a + b;
	beta  = sqrt( (alpha - 2.0) / (2.0 * a * b - alpha) );
	gamma = a + 1.0/beta;

    // initialize algorithm BC
    } else {
	a = MpMax(aa,bb);
	b = MpMin(aa,bb);
	alpha = a + b;
	beta  = 1.0/b;
	delta = 1.0 + a - b;
	k1 = delta * (1.38889e-2 + 4.16667e-2 * b) / (a * beta - 0.777778);
	k2 = 0.25 + (0.5 + 0.25 / delta) * b;
    }
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
