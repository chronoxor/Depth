/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                      ran002.cpp |
|                                                                               |
| Implementation of Ran002: combined congruential with shuffle			|
|                                                                               |
| Last change: Nov 5, 2005                                                      |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel                                   |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
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
// Ran002: combined congruential with shuffle
//----------------------------------------------------------------------------//
//
// Returns an integer random number uniformly distributed within [1,2147483562]  
//
// Reference:
//  (1) This is the long period ( > 2.3 * 10^18 ) random number generator of 
//      P. L'Ecuyer, Commun. ACM 31, 743 (1988), but with Bays-Durham shuffle 
//      and "added safeguards" as proposed by
//  (2) William H. Press and Saul A. Teukolsky,
//      "Portable Random Number Generators",
//      Computers in Physics, Vol. 6, No. 5, Sep/Oct 1992, Algorithm "ran2"
//  (3) This generator has been validated also by 
//      G. Marsaglia and A. Zaman, 
//      "Some portable very-long-period random number generators",
//      Computers in Physics, Vol. 8, No. 1, Jan/Feb 1994.  
//
// Notes:
//   -  William Press and Saul Teukolsky think that this is a "perfect" 
//      random generator and will pay $1000 for the first one who convinces 
//      them otherwise.
//
//   -  This generator is very slow
//
//----------------------------------------------------------------------------//

static const int NTAB = 32;

static const long IM1  = 2147483563L,
             	  IM2  = 2147483399L,
             	  IA1  = 40014L,
             	  IA2  = 40692L,
             	  IQ1  = 53668L,
             	  IQ2  = 52774L,
             	  IR1  = 12211L,
             	  IR2  = 3791L,
             	  IMM1 = IM1-1L;

//----------------------------------------------------------------------------//

Ran002::Ran002 (unsigned long the_seed) : RandomGenerator(the_seed)
{ 
    // requires at least 32 bit arithmetics
    assert( sizeof(unsigned long) >= 4 );

    // initialize the maximum value: max_val
    max_val = IMM1;

    // initialize shuffle table using the seed: iv and idum,idum2,iy
    idum  = (seed > 1L) ? seed : 1L;    // Be sure to prevent idum = 0 
    idum2 = idum;			// was previously: idum2 = 123456789L;

    for (int j = NTAB+7; j >= 0; j--) { // Load shuffle table (after 8 warm-ups)
	long k = idum/IQ1;
	idum = IA1 * (idum - k * IQ1) - IR1 * k;
	if (idum < 0) idum += IM1;
	if (j < NTAB) iv[j] = idum;
    }
    iy = iv[0];
}

//----------------------------------------------------------------------------//

unsigned long Ran002::Long (void)
{
    long j, k;

    k = idum/IQ1;			// Start here when not initializing
    idum = IA1*(idum-k*IQ1)-IR1*k;	// Compute idum=mod(IA1*idum,IM1) without
					// overflows by Schrage's method 
    if (idum < 0) idum += IM1;
    
    k = idum2/IQ2;			// Compute idum2=mod(IA2*idum2,IM2) likewise
    idum2 = IA2*(idum2-k*IQ2)-IR2*k;	// Compute idum=mod(IA1*idum,IM1) without
					// overflows by Schrage's method
    if (idum2 < 0) idum2 += IM2;
    
    j = iy/(1L+IMM1/NTAB);		// Will be in the range 0..NTAB-1
    iy = iv[j]-idum2;			// Output previously stored value and 
					// refill the shuffle table
    iv[j] = idum;
    if (iy < 1) iy += IMM1;
    
    return iy;
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
