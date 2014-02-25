/*-----------------------------------------------------------------------------*\
| Matpack random generator - class Ran32k3a                        ran32k3a.cpp |
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
// This is Pierre L'Ecuyer's pseudorandum number generator MRG32k3a.
//
// The period length is about 2^191 (which is approximately 3*10^57).
// The implementation uses floating-point arithmetic and works under the 
// sufficient condition that the double precision floating-point arithmetic 
// satisfies the IEEE 754 standard. That means all integers between -2^53
// and 2^53 are represented exactly in a number of type double. Note, that
// this generator gives no more than 32 random bits although a 53-bit floating
// point number is returned.
//
// Initialization:
//    The six global variables s10,s11,s12, s20,s21,s22 constitute the seed.
//    Before called the first time one must initialize s10,s11,s12 to (exact)
//    non-negative integer values less than m1 (i.e. in [0...4294967086]), but
//    not all zero, and s20,s21,s22 to (exact) non-negative integer values 
//    less than m2  (i.e. in [0...4294944442]), but not all zero.
//
// Reference:
//    Pierre L'Ecuyer, 
//    Good Parameter Sets for Combined Multiple Recursive Random
//    Number Generators, Preprint, July 28, 1997, Code of Figure I.
//
// Note:
//   1. The time being this is presumably one of the best pseudorandom number
//      generators and it is also very fast. (Sep 26, 1997, B.M.Gammel) 
//   2. CPU time to generate and add 10^7 numbers:
//      6 sec for DEC Alpha Station, 21161 CPU, 400 MHz, GNU g++ 2.7.1 compiler
//   3. The time overhead for virtual vs. non-virtual operator () is 
//      about 1-2 percent and is therefore considered as neglegible.
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
// Seeding
//----------------------------------------------------------------------------//

void Ran32k3a::SetState (unsigned long u10, unsigned long u11, unsigned long u12, 
			 unsigned long u20, unsigned long u21, unsigned long u22)
		  
{
    // make some consistency checks on the seeds
    const unsigned long u1 = 4294967086U, 
                        u2 = 4294944442U;

    if ( u10 > u1 || u11 > u1 || u12 > u1 ||
	 u20 > u2 || u21 > u2 || u22 > u2 ||
	 (u10 == 0 && u11 == 0 && u12 == 0) ||
	 (u20 == 0 && u21 == 0 && u22 == 0) )
      Matpack.Error("Ran32k3a::Seed: Illegal seed values given");
	
    // set the new state
    s10 = u10; s11 = u11; s12 = u12; 
    s20 = u20; s21 = u21; s22 = u22;
}

//----------------------------------------------------------------------------//
// Constructor
//----------------------------------------------------------------------------//

Ran32k3a::Ran32k3a (unsigned long u10, unsigned long u11, unsigned long u12, 
		    unsigned long u20, unsigned long u21, unsigned long u22)
{
    // assure that we have at least 53 bit precission floating point arithmetic
    assert(DBL_MANT_DIG >= 53);
    
    // now set the new state
    SetState(u10,u11,u12,u20,u21,u22);
}

//----------------------------------------------------------------------------//
// The generator
//----------------------------------------------------------------------------//

double Ran32k3a::operator () (void)
{
    // Implementation constants
    const double norm = 2.328306549295728e-10,
                 m1   = 4294967087.0,
	         m2   = 4294944443.0;

    long k;
    double p;

    // Component 1
    p = 1403580.0 * s11 - 810728.0 * s10;
    k = long(p / m1);
    p -= k * m1;
    if (p < 0.0) p += m1;
    s10 = s11; s11 = s12; s12 = p;

    // Component 2
    p = 527612.0 * s22 - 1370589.0 * s20;
    k = long(p / m2);
    p -= k * m2;
    if (p < 0.0) p += m2;
    s20 = s21; s21 = s22; s22 = p;

    // Combination
    return (s12 <= s22) ? ((s12 - s22 + m1) * norm) : ((s12 - s22) * norm);
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
