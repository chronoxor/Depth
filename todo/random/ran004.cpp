/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                      ran004.cpp |
|                                                                               |
| Implementation of Ran004: Numerical recipies pseudo-DES generator ran4	|
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
// Ran004: W.H. Press/S.A. Teukolsky: Numerical recipies pseudo-DES ran4
//----------------------------------------------------------------------------//
// 
// Returns an integer random number uniformly distributed within [0,4294967295]
//
// The period length for one seed is 2^32, but the seed is incremented
// automatically if the series for one seed is exhausted. There are
// 2^32 possible seeds.
//
// Notes:
//
// a) The original version of Ref. (1) is not portable to machines with larger
//    word lengths. That means different random sequences are obtained for
//    32-bit long integers and 64-bit long integers. 
//    This version is made portable by using bit-masks. The run time penalty
//    is neglegible.
// b) The random sequence for one seed has only a period of maximally 2^32.
//    This is definitly to short for nowadays MC simulations. In this version
//    the seed is automatically incremented to jump to the next segment
//    when one segment is exhausted. 
// c) Also the extremely inconvenient interface of the original 
//    has been changed.
// 
// Reference:
//   (1) W.H. Press, S.A. Teukolsky, Vetterling, Teukolsky,
//       Numerical Recipies in C, 2nd edition, 1992.
//   (2) Major modifications a) to c) and inclusion into Matpack
//       by B. M. Gammel, Apr 1, 1997 (no joke!)
//----------------------------------------------------------------------------//

Ran004::Ran004 (unsigned long the_seed) : RandomGenerator(the_seed)
{
  // Ran004 requires at least 32-bit arithmetics
  assert( sizeof(unsigned long) >= 4 );

  // initialize the maximum value: 0xffffffff = 2^32-1 = 4294967295
  max_val = 0xffffffff;

  // initialize the seed
  idums = seed;

  // first value to be hashed for the sequence associated to seed
  idum = 1;
}

//----------------------------------------------------------------------------//
// pseudo-DES hashing algorithm
// not yet portable to 64-bit machines - use masks !
//----------------------------------------------------------------------------//

inline void psdes (unsigned long &lword, unsigned long &irword)
{
  const unsigned long c1[4] = {0xbaa96887L,0x1e17d32cL,0x03bcdc3cL,0x0f33d1b2L},
		      c2[4] = {0x4b0f3b58L,0xe874f0c3L,0x6955c5a6L,0x55a7ca46L};
  unsigned long ia, ib, iswap, itmph = 0, itmpl = 0;

  // four iterations of the non-linear pseude-DES mixing
  for (int i = 0; i < 4; i++) {
    ia = (iswap = irword) ^ c1[i];
    itmpl = ia & 0xffff;
    itmph = ia >> 16;
    ib = (itmpl*itmpl + ~(itmph*itmph)) & 0xffffffff;
    irword = (lword ^ (((ia = (ib >> 16) | ((ib & 0xffff) << 16)) ^ c2[i]) 
		       + itmpl*itmph)) & 0xffffffff;
    lword = iswap & 0xffffffff;
  }
}

//----------------------------------------------------------------------------//
// deliver next pseudorandom number
//----------------------------------------------------------------------------//

unsigned long Ran004::Long (void)
{
  unsigned long irword, lword;
  irword = idum;	// next idum
  lword  = idums; 	// the seed
  psdes(lword,irword);	// hash

  if (idum == 0xffffffff) {	// this sequence is exhausted
    idum = 0;			// reset to start 
    if (idums == 0xffffffff) 
      idums = 1; 
    else 
      idums++;			// increment seed to get next sequence
  }
  idum++;			// increment idum
  return irword;
}

//----------------------------------------------------------------------------//
// reset the sequence to the n-th deviate for the given seed and return number
//----------------------------------------------------------------------------//

unsigned long Ran004::Long (unsigned long new_seed, unsigned long nth)
{
  unsigned long irword, lword;
  lword = idums = new_seed;	// the new seed
  irword = idum = nth;		// reset idum to nth element od the sequence
  psdes(lword,irword);		// hash
  if (idum == 0xffffffff) {	// this sequence is exhausted
    idum = 0;			// reset to start 
    if (idums == 0xffffffff) 
      idums = 1; 
    else 
      idums++;			// increment seed to get next sequence
  }
  idum++;			// increment idum
  return irword;
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
