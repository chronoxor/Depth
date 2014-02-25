/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                     ran800.cpp |
|                                                                               |
| Implementation of Ran800: twisted GFSR TT800 of Matsumoto and Kurita		|
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
// Ran800: huge period generator TT800 of Matsumoto and Kurita
//----------------------------------------------------------------------------//
// 
// Returns  integer random numbers uniformly distributed within [0,4294967295]
//          (that means [0,2^32-1]
//
// This is a twisted GFSR generator proposed by Matsumoto and
// Kurita in the ACM Transactions on Modelling and Computer
// Simulation, Vol. 4, No. 3, 1994, pp. 254-266. This generator has a
// period of 2^800 - 1 and excellent equidistribution properties up to
// dimension 25. A TGFSR with a period of more than 2^11000 is
// currently under construction by M. Matsumoto and T. Nishimura.
//
// The original code has been adapted to the general random generator class
// interface of Matpack, 1997.
//
// Original notes of the authors:
//   A C-program for TT800 : July 8th 1996 Version 
//   by M. Matsumoto, email: matumoto@math.keio.ac.jp 
//   genrand() generate one pseudorandom number with double precision 
//   which is uniformly distributed on [0,1]-interval 
//   for each call.  One may choose any initial 25 seeds 
//   except all zeros. 
//
// References: 
//   (1) ACM Transactions on Modelling and Computer Simulation, 
//       Vol. 4, No. 3, 1994, pages 254-266. 
//   (2) This is one of the recommended generators in:
//       Pierre L'Ecuyer, "Random Number Generation", Chapter 4
//       of the "Handbook on Simulation", Ed. Jerry Banks, Wiley, 1997.
//
//----------------------------------------------------------------------------//

static const int N = 25, M = 7;    

Ran800::Ran800 (unsigned long the_seed) : RandomGenerator(the_seed)
{ 
    // requires at least 32 bit arithmetics
    assert( sizeof(unsigned long) >= 4 );

    // initialize the maximum value: max_val
    max_val = (unsigned long) 0xffffffff;

    // initialize seeds
    k = 0;
    static unsigned long x_data[N] = { 
      // initial 25 seeds, change as you wish 
      0x95f24dab, 0x0b685215, 0xe76ccae7, 0xaf3ec239, 0x715fad23,
      0x24a590ad, 0x69e4b5ef, 0xbf456141, 0x96bc1b7b, 0xa7bdf825,
      0xc1de75b7, 0x8858a9c9, 0x2da87693, 0xb657f9dd, 0xffdc8a9f,
      0x8121da71, 0x8b823ecb, 0x885d05f5, 0x4e20cd47, 0x5a9ad5d9,
      0x512c0c03, 0xea857ccd, 0x4cc1d30f, 0x8891a8a1, 0xa6b7aadb
    };
    // combine table with given seed
    for (int i = 0; i < N; i++) x[i] = x_data[i] ^ seed;
}

//----------------------------------------------------------------------------//

unsigned long Ran800::Long (void)
{
  // this is magic vector `a', don't change
  const unsigned long mag01[2] = { 0x0, 0x8ebfd028 };

  if (k == N) { 
    // generate N words at one time
    int kk;
    for (kk = 0; kk < N-M; kk++) {
      x[kk] = x[kk+M] ^ (x[kk] >> 1) ^ mag01[x[kk] % 2];
    }
    for ( ; kk < N; kk++) {
      x[kk] = x[kk+(M-N)] ^ (x[kk] >> 1) ^ mag01[x[kk] % 2];
    }
    k = 0;
  }
  
  unsigned long  y;
  y = x[k];
  y ^= (y << 7) & 0x2b5b2500;	// s and b, magic vectors
  y ^= (y << 15) & 0xdb8b0000;	// t and c, magic vectors 
  y &= 0xffffffff; 		// you may delete this line if word size = 32
 
  // the following line was added by Makoto Matsumoto in the 1996 version
  // to improve lower bit's corellation.
  // Delete this line to use the code published in 1994.
  y ^= (y >> 16); 		// added to the 1994 version
  k++;

  return y;
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
