/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                     ran250.cpp |
|                                                                               |
| Implementation of Ran2500: the Kirkpatrick-Stoll generator "R250"		|
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
// Ran250: the Kirkpatrick-Stoll generator "R250"
//----------------------------------------------------------------------------//
//
// Returns integer random numbers uniformly distributed within [0,2147483646]. 
//
// Notes: - SERIOUS DEFICIENCIES IN SOME PHYSICAL SIMULATIONS HAVE BEEN FOUND
//	    (e.g. in the Ising model using the Wolff cluster update algorithm)
//
//        - The period is 2^250
//
//        - At least 32 bit unsigned long is required.
//
//        - References:
//           o S. Kirkpatrick and E. Stoll, "A Very Fast
//             Shift-Register Sequence Random Number Generator",
//             Journal of Computational Physics 40, 517 (1981)
//           o W.L. Maier, "A Fast Pseudo Random Number Generator",
//             Dr. Dobb's Journal, May, 152-157 (1991) 
//----------------------------------------------------------------------------//

// Defines to allow for 16 or 31 or 32 bit integers
// In the Matpack library the 32-bit version is used !
#define N_BITS 32

#if N_BITS == 32
#define MSB          0x80000000L
#define ALL_BITS     0xffffffffL
#define HALF_RANGE   0x40000000L
#define STEP         7
#endif

#if N_BITS == 31
#define MSB          0x40000000L
#define ALL_BITS     0x7fffffffL
#define HALF_RANGE   0x20000000L
#define STEP         7
#endif

#if N_BITS == 16
#define MSB         0x8000
#define ALL_BITS    0xffff
#define HALF_RANGE  0x4000
#define STEP        11
#endif

//----------------------------------------------------------------------------//

static long GGL (long& seed)
// 
// Park and Miller's minimal standard random generator 'GGL':
// An algorithm from CACM 31 no. 10, pp. 1192-1201, October 1988.
// x[n+1] = (16807 * x[n]) mod (2^31 - 1)
//
{
  const long A = 16807, M = 0x7fffffff, Q = 127773, R = 2836;
  seed = A * (seed % Q) - R * (seed / Q);
  if (seed <= 0) seed += M;
  return seed;
}

//----------------------------------------------------------------------------//

Ran250::Ran250 (unsigned long the_seed) : RandomGenerator(the_seed)
{
  // requires at least 32 bit arithmetics
  assert( sizeof(unsigned long) >= 4 );

  // initialize the maximum value max_val
  max_val = ALL_BITS;

  // set initial state in the r250_buffer
  int j, k;
  unsigned long mask, msb;

  // set seed for the auxilliary GGL generator
  long GGL_seed = seed;
	
  r250_index = 0;
  for (j = 0; j < 250; j++)      // fill r250 buffer with N_BITS-1 bit values 
    r250_buffer[j] = GGL(GGL_seed);

  for (j = 0; j < 250; j++)	// set some MSBs to 1
    if ( GGL(GGL_seed) > HALF_RANGE )
      r250_buffer[j] |= MSB;

  msb = MSB;			// turn on diagonal bit
  mask = ALL_BITS;		// turn off the leftmost bits

  for (j = 0; j < N_BITS; j++) {
    k = STEP * j + 3;		// select a word to operate on
    r250_buffer[k] &= mask;	// turn off bits left of the diagonal
    r250_buffer[k] |= msb;	// turn on the diagonal bit
    mask >>= 1;
    msb  >>= 1;
  }
}

//----------------------------------------------------------------------------//

unsigned long Ran250::Long (void)
{
  int j;
  unsigned long new_rand;

  if ( r250_index >= 147 )
    j = r250_index - 147;	// wrap pointer around 
  else
    j = r250_index + 103;

  new_rand = r250_buffer[r250_index] ^ r250_buffer[j];
  r250_buffer[r250_index] = new_rand;

  if ( r250_index >= 249 )	// increment pointer for next time
    r250_index = 0;
  else
    r250_index++;

  return new_rand; 		// return random number
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
