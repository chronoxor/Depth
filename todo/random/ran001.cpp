/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                      ran001.cpp |
|                                                                               |
| Implementation of Ran001: minimum standard congruential with shuffle		|
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
// Ran001: combined congruential with shuffle
//----------------------------------------------------------------------------//
//
// Returns integer random numbers uniformly distributed within [0,2147483646]  
//
// Notes: - Minimal random number generator of Park and Miller with
//          Bays-Durham shuffle and added safeguards. 
//
//        - The period is 2^31-2 = 2.1*10^9. If your application needs 
//	    more numbers in sequence than 1% of the random generators period, 
//	    i.e. 10^7, then use a more elaborate random generator.
//          There are no statistical tests known that it fails to pass, execpt 
//          when the number of calls starts to become on the order of the period.
//	    When you need longer random sequences you should use
//          another random generator, for example Ran002 or Ran013.
//
//        - Reference:
//          Algorithm "ran1" published in "Portable Random Number Generators",
//          William H. Press and Saul A. Teukolsky
//          Computers in Phyics, Vol. 6, No. 5, Sep/Oct 1992
//
//        - At least 32 bit long int is required, but works with any larger
//	    word lengths
//
//----------------------------------------------------------------------------//

static const int NTAB = 32;

static const long IM = 2147483647L,  // 2^31-1
                  IA = 16807L,
	          IQ = 127773L,
	          IR = 2836L,
	          MASK = 123459876L;

//----------------------------------------------------------------------------//

Ran001::Ran001 (unsigned long the_seed) : RandomGenerator(the_seed)
{ 
    // requires at least 32 bit arithmetics
    assert( sizeof(unsigned long) >= 4 );

    // initialize the maximum value: max_val
    max_val = IM - 1;
    
    // initialize shuffle table using the seed: iv and idum,iy
    idum  = (seed > 1L) ? seed : 1L;    // Be sure to prevent idum = 0 
    for (int j = NTAB+7; j >= 0; j--) { // Load shuffle table (after 8 warm-ups)
	long k = idum/IQ;
	idum = IA * (idum - k * IQ) - IR * k;
	if (idum < 0) idum += IM;
	if (j < NTAB) iv[j] = idum;
    }
    iy = iv[0];
}

//----------------------------------------------------------------------------//

unsigned long Ran001::Long (void)
{
    long j, k;

    k = idum/IQ;			// Start here when not initializing
    idum = IA*(idum-k*IQ)-IR*k;		// Compute idum=mod(IA1*idum,IM1) without
    if (idum < 0) idum += IM;		// overflows by Schrage's method 
      
    j = iy/(1+(IM-1)/NTAB);		// Will be in the range 0..NTAB-1
    iy = iv[j];				// Output previously stored value and 
    iv[j] = idum;			// refill the shuffle table
    
    return iy;
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
