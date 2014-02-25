/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                 ranbinomial.cpp |
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
// class BinomialDistribution						      //
//----------------------------------------------------------------------------//
//								       	      //
// Returns a binomial distributed deviate (integer returned in a double)      //
// according to the distribution:				       	      //
//                        				       	      	      //
//              j+eps                 / n \    j      n-j		      //
//      integral       p   (m) dm  = |     |  q  (1-q)		      	      //
//              j-eps   n,q           \ j /			     	      //
//								       	      //
// References:								      //
//	D. E. Knuth: The Art of Computer Programming, Vol. 2, Seminumerical   //
//	Algorithms, pp. 120, 2nd edition, 1981.			       	      //
//								       	      //
//	W. H. Press, B. P. Flannery, S. A. Teukolsky, W. T. Vetterling,	      //
//	Numerical Recipies in C, Cambridge Univ. Press, 1988.		      //
//								       	      //
//----------------------------------------------------------------------------//

double BinomialDistribution::operator () (void)
{
    double bnl;

    if (n < 25) {		// direct method for moderate n

	bnl = 0.0;
	for (int j = 0; j < n; j++)
	    if (scale * gen->Long() < p) bnl++;
	
    } else if (np < 1.0) {	// use direct Poisson method

	int j;
	double t = 1.0;
	for (j = 0; j <= n; j++) {
	    t *= scale * gen->Long();
	    if (t < npexp) break;
	}
	bnl = (j <= n ? j : n);

    } else {			// use rejection method

	double em, y, t;
	do {
	    do {
		y = tan( scalepi * gen->Long() );
		em = sq * y + np;
	    } while (em < 0.0 || em >= en1);
	    em = floor(em);
	    t = 1.2 * sq * (1.0 + y*y) * exp( gamen1 
					      - LnGamma(em+1.0) 
					      - LnGamma(en1-em) 
					      + em * plog
					      + (en-em) * pclog );
	} while (scale * gen->Long() > t);
	bnl = em;
    }
    
    if (sym) bnl = n - bnl; // undo symmetry transformation

    return bnl;
}

//----------------------------------------------------------------------------//

void BinomialDistribution::Initialize (double pp, int nn)
{
    if (pp >= 0.0 && pp <= 1.0) {

	scale = 1.0 / max_val;
	scalepi = M_PI / max_val;

	if (pp <= 0.5) {	// use invariance under  p  <==> 1-p 
	    p = pp; sym = 0;
	} else {
	    p = 1.0 - pp; sym = 1;
	}

	n = nn;
	np = n * p;
	npexp = exp(-np);

	en = n;
	en1 = en + 1.0;
	gamen1 = LnGamma(en1);
	pc = 1.0-p;
	plog = log(p);
	pclog = log(pc);
	sq = sqrt(2*np*pc);

    } else 
	Matpack.Error("BinomialDistribution: probability must be within [0,1]");
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
