/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                     ran055.cpp |
|                                                                               |
| Implementation of Ran055: lagged Fibonacci generator, lag=(55,24)		|
| NOT RECOMENDED FOR SERIOUS APPLICATIONS					|
|                                                                               |
| Last change: Nov 5, 2005                                                      |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel                                   |
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
#include <cassert>

namespace MATPACK {

//----------------------------------------------------------------------------//
// Ran055: Knuth's shift & add random generator				      //
//----------------------------------------------------------------------------//
//
// Returns integer random numbers uniformly distributed within [0,2147483647]
//
// Notes:  - DON'T USE THIS GENERATOR IN SERIOUS APPLICATIONS BECAUSE
//           IT HAS SERIOUS CORRELATIONS
//
//         - The period is 2^55 = 36 028 797 018 963 968 > 3.6*10^16.
//
//        - At least 32 bit long int is required, but works with any larger
//	    word lengths
//        - This is a lagged Fibonacci generator:
//            x(n) =  ( x(n-55) - x(n-24) ) mod 2^31
//        - Reference:
//          A version of this pseudrandom number generator is described in
//          J. Bentley's column, "The Software Exploratorium", Unix Review 1991.
//          It is based on Algorithm A in D. E. Knuth, The Art of Computer-
//          Programming, Vol 2, Section 3.2.2, pp. 172 
//
//----------------------------------------------------------------------------//


const long MAX  = 2147483647,  // 2^31-1
           MASK = 123459876;

//----------------------------------------------------------------------------//

Ran055::Ran055 (unsigned long the_seed) : RandomGenerator(the_seed)
{
    int i, ii;
    long j, k;

    // requires at least 32 bit arithmetics
    assert( sizeof(unsigned long) >= 4 );

    max_val = MAX;	// initialize the maximum value max_val

    // initialize table

    s55[0] = j = seed^MASK ;	// XORing with MASK allows use of zero
				// and other simple bit patterns for idum.
    k = 1;  
    for (i = 1; i < 55; i++) {
	ii = (21 * i) % 55;
	s55[ii] = k;
	k = j - k;
	j = s55[ii] ;
    }

    j55 = 0;			// invariance (b-a-24)%55 = 0
    k55 = 24;

    for (i = 0; i < 165; i++) Long();  // warm up table three times
}

//----------------------------------------------------------------------------//

unsigned long Ran055::Long (void)
{
    // The mask 0x7fffffff assures that the result
    // is a positive 32 bit signed long.
    (k55) ? (k55--) : (k55 = 54);
    (j55) ? (j55--) : (j55 = 54);
    return ( s55[j55] -= s55[k55] ) & 0x7fffffff; 
}

} // namespace MATPACK

//----------------------------------------------------------------------------//

