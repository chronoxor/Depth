/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                     ran056.cpp |
|                                                                               |
| Implementation of Ran056: lagged Fibonacci generator, lag=(55,24), k=3	|
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
// Ran056: Knuth's lagged Fibonacci random generator with 3-decimation	      //
//----------------------------------------------------------------------------//
//
// Returns integer random numbers uniformly distributed within [0,2147483647]
//
// Notes: - The period is 2^55/3 > 1.2*10^16.
//
//        - At least 32 bit long int is required, but works with any larger
//	    word lengths
//        - This is the same lagged Fibonacci generator as Ran055
//            x(n) =  ( x(n-55) - x(n-24) ) mod 2^31
//        - but a decimation strategy is applied to remove the known 
//          correlations. Only every 3rd number will be used: 
//        - Reference:
//            I. Vattulainen, T. Ala-Nissila, and K. Kankaala, 
//            Physical Tests for Random Numbers in Simulations, 
//            Phys. Rev. Lett. 73, 2513 (1994).
//
//----------------------------------------------------------------------------//


const long MAX  = 2147483647,  // 2^31-1
           MASK = 123459876;

//----------------------------------------------------------------------------//

Ran056::Ran056 (unsigned long the_seed) : RandomGenerator(the_seed)
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

    for (i = 0; i < 55; i++) Long(); // warm up table three times
}

//----------------------------------------------------------------------------//

unsigned long Ran056::Long (void)
{
    // The mask 0x7fffffff assures that the result
    // is a positive 32 bit signed long.

    // inline the Fibonacci step three times 
    // in order to remove correlations
    
    (k55) ? (k55--) : (k55 = 54); // one
    (j55) ? (j55--) : (j55 = 54);
    s55[j55] -= s55[k55];
    (k55) ? (k55--) : (k55 = 54); // two
    (j55) ? (j55--) : (j55 = 54);
    s55[j55] -= s55[k55];
    (k55) ? (k55--) : (k55 = 54); // three
    (j55) ? (j55--) : (j55 = 54);
    return ( s55[j55] -= s55[k55] ) & 0x7fffffff; 
}

} // namespace MATPACK

//----------------------------------------------------------------------------//

