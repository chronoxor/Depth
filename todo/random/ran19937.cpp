/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                   ran19937.cpp |
|                                                                               |
| Implementation of Ran19937: generator MT19937B of Matsumoto and Nishimura	|
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
// Ran19937: huge period generator MT19937B of Matsumoto and Nishimura
//----------------------------------------------------------------------------//
// 
// Returns integer random numbers uniformly distributed within [0,4294967295]
//          (that means [0,2^32-1]
//
// The Mersenne Twister, a new variant of the twisted GFSR (``TGFSR'') 
// by Matsumoto and Nishimura, sets new standards for the period, quality 
// and speed of random number generators. The incredible period
// is 2^19937 - 1, a number with about 6000 decimal digits; the 32-bit random 
// numbers exhibit best possible equidistribution properties in dimensions up
// to 623; and it's fast, very fast. 
// A paper on the Mersenne Twister has been submitted to ACM TOMACS.
//
// May 1997: First empirical results for this generator are available 
// on the news page of the pLab group at the University of Salzburg's
// Mathematics Department. WWW address: "http://random.mat.sbg.ac.at/news/".
//
// The original code has been adapted to the general random generator class
// interface of Matpack, 1997.
//
//----------------------------------------------------------------------------//
//
// Original Notes of the authors:    
//
//   A C-program for MT19937B: Integer Version
//   genrand() generate one pseudorandom integer which is
//   uniformly distributed among the 32bit unsigned integers
//   sgenrand(seed) set initial values to the working area of 624 words.
//   sgenrand(seed) must be called once before calling genrand()
//   (seed is any integer except 0).
//
//   LICENCE CONDITIONS: 
//
//                Matsumoto and Nishimura consent to GNU General 
//                Public Licence for this code.
//
//    NOTE: 
//                When you use it in your program, please let Matsumoto
//                <matumoto@math.keio.ac.jp> know it.
//
//----------------------------------------------------------------------------//

// Period parameters
#define N 624
#define M 397
#define MATRIX_A 0x9908b0df   // constant vector a
#define UPPER_MASK 0x80000000 // most significant w-r bits
#define LOWER_MASK 0x7fffffff // least significant r bits

// for tempering
#define TEMPERING_MASK_B 0x9d2c5680
#define TEMPERING_MASK_C 0xefc60000
#define TEMPERING_SHIFT_U(y)  (y >> 11)
#define TEMPERING_SHIFT_S(y)  (y << 7)
#define TEMPERING_SHIFT_T(y)  (y << 15)
#define TEMPERING_SHIFT_L(y)  (y >> 18)

//----------------------------------------------------------------------------//

Ran19937::Ran19937 (unsigned long the_seed) : RandomGenerator(the_seed)
{ 
  // requires at least 32 bit arithmetics
  assert( sizeof(unsigned long) >= 4 );

  // initialize the maximum value: max_val
  max_val = (unsigned long) 0xffffffff;
  
  // setting initial seeds to ptgfsr[N] using
  // the generator Line 25 of Table 1 in
  // [KNUTH 1981, The Art of Computer Programming
  // Vol. 2 (2nd Ed.), pp102]

  ptgfsr[0]= seed & 0xffffffff;
  for (int i = 1; i < N; i++)
    ptgfsr[i] = (69069 * ptgfsr[i-1]) & 0xffffffff;
  
  // set initial index
  k = 1;
}

//----------------------------------------------------------------------------//

unsigned long Ran19937::Long (void)
{
  unsigned long y;
  const unsigned long mag01[2] = { 0x0, MATRIX_A };
  // mag01[x] = x * MATRIX_A  for x=0,1
  
  if (k == N) { // generate N words at one time
    int kk;
    for (kk = 0; kk < N-M; kk++) {
      y = (ptgfsr[kk]&UPPER_MASK)|(ptgfsr[kk+1]&LOWER_MASK);
      ptgfsr[kk] = ptgfsr[kk+M] ^ (y >> 1) ^ mag01[y & 0x1];
    }
    for (; kk < N-1; kk++) {
      y = (ptgfsr[kk]&UPPER_MASK)|(ptgfsr[kk+1]&LOWER_MASK);
      ptgfsr[kk] = ptgfsr[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1];
    }
    y = (ptgfsr[N-1]&UPPER_MASK)|(ptgfsr[0]&LOWER_MASK);
    ptgfsr[N-1] = ptgfsr[M-1] ^ (y >> 1) ^ mag01[y & 0x1];
	
    k = 0;
  }
  
  y = ptgfsr[k++];
  y ^= TEMPERING_SHIFT_U(y);
  y ^= TEMPERING_SHIFT_S(y) & TEMPERING_MASK_B;
  y ^= TEMPERING_SHIFT_T(y) & TEMPERING_MASK_C;
  y &= 0xffffffff; // you may delete this line if word size = 32
  y ^= TEMPERING_SHIFT_L(y);

  return y;
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
