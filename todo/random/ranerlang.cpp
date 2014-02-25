/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                   ranerlang.cpp |
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
// class ErlangDistribution						      //
//----------------------------------------------------------------------------//
//								       	      //
// Return Erlang distributed random deviates according to:		      //
//								       	      //
//                      a-1  -bx					      //
//                b (bx)    e						      //
//  p   (x) dx = ---------------- dx   for x > 0			      //
//   a,b             Gamma(a)						      //
//				   					      //
//             =  0                    otherwise			      //
//								       	      //
// The Erlang distribution is a special case of the Gamma distribution 	      //
// with integer valued order a.					       	      //
//								       	      //
/// References:								      //
//	see references in:					       	      //
//	W. H. Press, B. P. Flannery, S. A. Teukolsky, W. T. Vetterling,	      //
//	Numerical Recipies in C, Cambridge Univ. Press, 1988.		      //
//								       	      //
//----------------------------------------------------------------------------//

double ErlangDistribution::operator () (void)
{
    if (A < 6) {	// direct method
	double x;
	do {
	    x = gen->Long() * scale;
	    for (int i = 1; i < A; i++) x *= gen->Long() * scale;
	} while (x <= 0.0);
	return ( -log(x)/B );

    } else {		// rejection method
	double x, y, b;
	do {
	    do {
		double v1,v2;
		do {
		    v1 = scale2 * gen->Long() - 1;
		    v2 = scale2 * gen->Long() - 1;
		} while ( (v1 == 0.0) || (v1*v1 + v2*v2 > 1.0) );
		y = v2/v1;
		x = sq*y + a1;
	    } while (x <= 0.0);
	    b = (1.0 + y*y) * exp( a1 * log(x/a1) - sq*y );
	} while ( (scale * gen->Long()) > b );
	return x/B;
    }
}

//----------------------------------------------------------------------------//

void ErlangDistribution::Order (int order, double loc)
{
    if (order < 1) 
	Matpack.Error("ErlangDistribution (int order, double loc):\n"
	     "order must be greater or equal than 1");
    else if (loc == 0)
	Matpack.Error("ErlangDistribution (int order, double loc):\n"
	     "location parameter must be non-zero");
    else {
	scale  = 1.0 / max_val;		// scale long to [0,1]
	scale2 = 2.0 / max_val;		// auxilliary
	A = order;			// order of Erlang distribution
	a1 = A-1.0;			// auxilliary
	sq = sqrt( 2 * a1 + 1 );	// auxilliary
	B = loc;			// location parmeter
    }
}

} // namespace MATPACK

//----------------------------------------------------------------------------//

