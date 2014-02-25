/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                     ran013.cpp |
|                                                                               |
| Implementation of Ran013: Marsaglia's combined congruential mzran13		|
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
// Ran013: congruential combined					      //
//----------------------------------------------------------------------------//
//
// Returns  integer random numbers uniformly distributed within [0,4294967295]
//          (that means [0,2^32-1]
//
// Notes: - The period is about 2^125 > 4.25*10^37
//
//        - At least 32 bit long int is required, but works with any larger
//	    word lengths
//
//        - Reference:
//          This is algorithm "mzran13" from
//          G. Marsaglia and A. Zaman, 
//          "Some portable very-long-period random number generators",
//          Computers in Physics, Vol. 8, No. 1, Jan/Feb 1994.  
//
//          In the original implementation the algorithm relies on 32-bit 
//          arithmetics with implicit modulo 2^32 on overflow. Since the
//          the size of unsigned longs may not always be 32 bit the 
//          modulo 2^32 is coded explicitly using masks. 
//	    The performance loss is not very important.
//
//          The original code reads:
//
//              long s;
//              if (y > x+c) { 
//	          s = y - (x+c); c = 0; 
//              } else {
//	          s = y - (x+c) - 18; c = 1;
//              }
//              x = y;
//              y = z;
//              return ((z = s) + (n - 69069 * n + 1013904243));
//                                   ^
//                                   Here it contains a misprint
//                                   Should really be a "=" !
//----------------------------------------------------------------------------//


Ran013::Ran013 (unsigned long the_seed) : RandomGenerator(the_seed)
{
    // Ran013 requires at least 32-bit arithmetics
    assert( sizeof(unsigned long) >= 4 );

    // initialize the maximum value: 0xffffffff = 2^32-1 = 4294967295
    max_val = (unsigned long) 0xffffffff;

    // initialize the seeds
    x = (seed ^  521288629) & 0xffffffff;
    y = (seed ^  362436069) & 0xffffffff;
    z = (seed ^   16163801) & 0xffffffff;
    n = (seed ^ 1131199209) & 0xffffffff;
    c = y > z;
}

//----------------------------------------------------------------------------//

unsigned long Ran013::Long (void)
{
  // The mask 0xffffffff is neccessary in some places to assure that arithmetics
  // is performed modulo 2^32 to make the generater portable to any word length 
  // larger than 2^32.

  long s;
  if (y > x+c) { 
    s = y - (x+c); 
    c = 0; 
  } else {
    s = (y - (x+c) - 18) & 0xffffffff; // mask is neccessary here
    c = 1;
  }
  x = y;
  y = z;   

  return ((z = s) + (n = 69069 * n + 1013904243)) & 0xffffffff;  // and here
}

} // namespace MATPACK

//----------------------------------------------------------------------------//

