/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                     ran088.cpp |
|                                                                               |
| Implementation of Ran088: L'Ecuyer's 1996 Tausworthe generator taus88		|
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
// Ran088: L'Ecuyer's 1996 three-component Tausworthe generator "taus88"
//----------------------------------------------------------------------------//
// 
// Returns an integer random number uniformly distributed within [0,4294967295]
//
// The period length is approximately 2^88 (which is 3*10^26). 
// This generator is very fast and passes all standard statistical tests.
//
// Reference:
//   (1) P. L'Ecuyer, Maximally equidistributed combined Tausworthe generators,
//       Mathematics of Computation, 65, 203-213 (1996), see Figure 4.
//   (2) recommended in:
//       P. L'Ecuyer, Random number generation, chapter 4 of the
//       Handbook on Simulation, Ed. Jerry Banks, Wiley, 1997.
//
//----------------------------------------------------------------------------//

Ran088::Ran088 (unsigned long the_seed) : RandomGenerator(the_seed)
{ 
  // requires at least 32 bit arithmetics
  assert( sizeof(unsigned long) >= 4 );
  
  // initialize the maximum value: max_val
  max_val = 4294967295U; // which is 2^32-1
  
  // initialize seeds using the given seed value taking care of
  // the requirements. The constants below are arbitrary otherwise
  s1 = 1243598713U ^ seed; if (s1 < 2)  s1 = 1243598713U;
  s2 = 3093459404U ^ seed; if (s2 < 8)  s2 = 3093459404U;
  s3 = 1821928721U ^ seed; if (s3 < 16) s3 = 1821928721U;
}

//----------------------------------------------------------------------------//

unsigned long Ran088::Long (void)
{ 
    // use mask to make the generator portable for any word width >= 32 bit
    const unsigned long mask = 0xffffffff;
    unsigned long b;
    b  = (((s1 << 13) & mask) ^ s1) >> 19;
    s1 = (((s1 & 4294967294U) << 12) & mask) ^ b;
    b  = (((s2 << 2) & mask) ^ s2) >> 25;
    s2 = (((s2 & 4294967288U) << 4) & mask) ^ b;
    b  = (((s3 << 3) & mask) ^ s3) >> 11;
    s3 = (((s3 & 4294967280U) << 17) & mask) ^ b;
    return (s1 ^ s2 ^ s3); 
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
