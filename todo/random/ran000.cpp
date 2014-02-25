/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                     ran000.cpp |
|                                                                               |
| Implementation of Ran000: minimum standard congruential			|
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
// Ran000: minimal congruential
//----------------------------------------------------------------------------//
//
// Returns integer random numbers uniformly distributed within [0,2147483646]. 
//
// Notes: - NOT RECOMENDED FOR SERIOUS APPLICATIONS.
//	    Just use it for comparison purposes, etc.
//
//        - This generator is fast
//
//        - "Minimal" random number generator of Park and Miller.
//	        x(n) = 16807 * x(n-1) mod (2^31-1)
//          also known as GGL.
//
//	  - Set seed to any integer value (except the unlikely value mask) to
//	    initialize the sequence.
//
//        - The period is 2^31-2 = 2.1*10^9. If your application needs 
//	    more numbers in sequence than 1% of the random generators period, 
//	    i.e. 10^7, then use a more elaborate random generator.
//
//        - At least 32 bit long int is required.
//
//        - References:
//           o Algorithm from CACM 31 no. 10, pp. 1192-1201, October 1988. 
//           o Algorithm "ran0" from "Portable Random Number Generators",
//             William H. Press and Saul A Teukolsky
//             Computers in Phyics, Vol. 6, No. 5, Sep/Oct 1992
//           o According to a posting by Ed Taft on comp.lang.postscript,
//             Level 2 (Adobe) PostScript interpreters use this algorithm too.
//
//----------------------------------------------------------------------------//

const long IM = 2147483647L,  // 2^31-1
           IA = 16807L,
	   IQ = 127773L,
	   IR = 2836L,
	   MASK	= 123459876L;

//----------------------------------------------------------------------------//

Ran000::Ran000 (unsigned long the_seed) : RandomGenerator(the_seed)
{
    // requires at least 32 bit arithmetics
    assert( sizeof(unsigned long) >= 4 );

    // make shure that seed is not the MASK (otherwise zero is returned always)
    if (seed == (unsigned long) MASK)
	Matpack.Error("Ran000: you selected the only illegal seed value (%d)",MASK);

    max_val = IM - 1;	// initialize the maximum value max_val

    idum = seed^MASK;	// initialize idum using the seed: 
			// XORing with MASK allows use of zero
			// and other simple bit patterns for idum.
}

//----------------------------------------------------------------------------//

unsigned long Ran000::Long (void)
{
    long k = idum/IQ;		// Compute idum=mod(IA*idum,IM)
    idum = IA*(idum-k*IQ)-IR*k;	// without overflows by  
    if (idum < 0) idum += IM;	// Schrage's method.
    return idum;		// return random number
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
