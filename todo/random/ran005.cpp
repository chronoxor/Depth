/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                      ran005.cpp |
|                                                                               |
| Implementation of Ran005: congruential with shuffle				|
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

//#define DEBUG

namespace MATPACK {

//----------------------------------------------------------------------------//
// Ran005: congruential with shuffle
//----------------------------------------------------------------------------//
//
// Returns an integer random number uniformly distributed within [0,714024]. 
//
// Notes: - NOT RECOMENDED FOR SERIOUS APPLICATIONS.
//	    Just use it for comparison purposes, etc.
//
//        - As you see the spacing of the numbers is very coarse.
//
//	  - Low order correlations are present.
//
//        - The period is effectively infinite.
//
//        - At least 32 bit long int is required.
//
//        - Corresponds to generator "ran2" of
//          W. H. Press, B. P. Flannery, S. A. Teukolsky, W. T. Vetterling,
//          Numerical Recipies in C, Cambridge Univ. Press, 1988.
//
//        - The generator is based upon
//          D. H. Knuth: The Art of Computer Programming, Vol.2, 2nd ed., 1981.
//
//----------------------------------------------------------------------------//

const long M = 714025L, 
           A = 1366L, 
           C = 150889L;

//----------------------------------------------------------------------------//

Ran005::Ran005 (unsigned long the_seed) : RandomGenerator(the_seed)
{
    // requires at least 32 bit arithmetics
    assert( sizeof(unsigned long) >= 4 );

    // initialize the maximum value: max_val
    max_val = M - 1;

    // initialize shuffle table r and x, y
    x = (seed > 0) ? -seed : seed;
    if ((x = (C - x) % M) < 0) x = -x;
    for (int j = 1; j <= 97; j++)
	r[j] = x = (A * x + C) % M;
    y = x = (A * x + C) % M;
}

//----------------------------------------------------------------------------//

unsigned long Ran005::Long (void)
{
    int k = 1 + (97 * y) / M;
    y = r[k];
    r[k] = x = (A * x + C) % M;
    return y;
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
