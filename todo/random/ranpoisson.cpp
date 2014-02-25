/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                  ranpoisson.cpp |
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

double LnGamma (double x);

//----------------------------------------------------------------------------//
// class PoissonDistribution						      //
//----------------------------------------------------------------------------//
//								       	      //
// Returns a Poisson distributed deviate (integer returned in a double)       //
// from a distribution of mean m.					      //
// The Poisson distribution gives the probability of a certain integer	      // 
// number m of unit rate Poisson random events occurring in a given	      // 
// interval of time x.							      //
//				     j	-x			       	      //
//              j+eps               x  e				      //
//      integral       p (m) dm  = -------	 	      	      	      //
//              j-eps   x            j !		     	      	      //
//								       	      //
// References:	The method follows the outlines of:		       	      //
//	W. H. Press, B. P. Flannery, S. A. Teukolsky, W. T. Vetterling,	      //
//	Numerical Recipies in C, Cambridge Univ. Press, 1988.		      //
//								       	      //
//----------------------------------------------------------------------------//

double PoissonDistribution::operator () (void)
{
    double em, t, y; 
    
    if (m < 12.0) {         // direct method

	em = -1.0;
	t = 1.0;
	do {
	    em += 1.0;
	    t *= gen->Long() * scale;
	} while (t > g);

    } else {                // rejection method

	do {
	    do {
		y = tan( gen->Long() * scalepi );
		em = sq * y + m;
	    } while (em < 0.0);
	    em = floor(em);
	    t = 0.9 * (1.0 +  y*y) * exp( em * alm - LnGamma(em+1.0) - g );
	} while ( gen->Long() * scale > t);
    }

    return em;
}

//----------------------------------------------------------------------------//

void PoissonDistribution::Initialize (double mean)
{
    m = mean; 
    scale  = 1.0 / max_val; 
    
    if (m < 12.0) {	// direct method
	g = exp(-m);
    
    } else {		// rejection method
	scalepi = M_PI / max_val; 
	sq = sqrt(2.0*m); 
	alm = log(m);
	g = m*alm - LnGamma(m+1.0);
    }

}

} // namespace MATPACK

//----------------------------------------------------------------------------//
