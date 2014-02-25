/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                     ran205.cpp |
|                                                                               |
| Implementation of Ran205: L'Ecuyer's 1996 combined multiple recursive PRNG	|
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
// Ran205: L'Ecuyer's 1996 combined multiple recursive PRNG
//----------------------------------------------------------------------------//
//
// Returns an integer random number uniformly distributed within [0,2147483646]
//
// The period length is approximately 2^205 (=5*10^61). The generator
// returns uniformly distributed integers in the range [0,2^31-2].
// It passes all current standard statistical tests.
//
// References:
//   (1) P. L'Ecuyer, "Combined Multiple Recursive Generators,"
//       Operations Research 44, 5, pp. 816-822 (1996), see figure 1.
//   (2) recommended in:
//       P. L'Ecuyer, "Random number generation", chapter 4 of the
//       Handbook on Simulation, Ed. Jerry Banks, Wiley, 1997.
//
// Notes:
//    -  This generator is very slow
//
//----------------------------------------------------------------------------//


Ran205::Ran205 (unsigned long the_seed) : RandomGenerator(the_seed)
{ 
  // requires at least 32 bit arithmetics
  assert( sizeof(long) >= 4 );
  
  // initialize the maximum value: max_val
  max_val = 2147483646; // which is 2^31-2
  
  // initialize seeds using the given seed value:  
  // The seeds must be within [1,2145483478]
  const long smax = 2145483478, 
             mask = 0x7fffffff; // to get positive integer <= 2^31-1
  x10 = ((2039845123 ^ seed) & mask) % smax + 1;
  x11 = (( 182401045 ^ seed) & mask) % smax + 1;
  x12 = ((1190945568 ^ seed) & mask) % smax + 1;
  x20 = (( 943583831 ^ seed) & mask) % smax + 1;
  x21 = ((1345908737 ^ seed) & mask) % smax + 1;
  x22 = (( 723161013 ^ seed) & mask) % smax + 1;
}

//----------------------------------------------------------------------------//

unsigned long Ran205::Long (void)
{
  // constant numbers
  const long  m1  = 2147483647,  m2  = 2145483479,
              a12 =      63308,  q12 =      33921,  r12 = 12979,
              a13 =    -183326,  q13 =      11714,  r13 =  2883,
              a21 =      86098,  q21 =      24919,  r21 =  7417,
              a23 =    -539608,  q23 =       3976,  r23 =  2071;

  long h, p12, p13, p21, p23;
  // component 1
  h = x10 / q13;	
  p13 = -a13 * (x10 - h * q13) - h * r13;
  h = x11 / q12;	
  p12 =  a12 * (x11 - h * q12) - h * r12;
  if (p13 < 0) p13 += m1;
  if (p12 < 0) p12 += m1;
  x10 = x11;
  x11 = x12;
  x12 = p12 - p13;
  if (x12 < 0) x12 += m1;
  // component 2
  h = x20 / q23;
  p23 = -a23 * (x20 - h * q23) - h * r23;
  h = x22 / q21;
  p21 =  a21 * (x22 - h * q21) - h * r21;
  if (p23 < 0) p23 += m2;
  if (p21 < 0) p21 += m2;
  x20 = x21;
  x21 = x22;
  x22 = p21 - p23;
  if (x22 < 0) x22 += m2;
  // combination
  return (x12 < x22) ? (x12 - x22 + m1) : (x12 - x22);
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
