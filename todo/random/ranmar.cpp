/*-----------------------------------------------------------------------------*\
| Matpack random generator - class Ranmar                            ranmar.cpp |
|                                                                               |
| Last change: Sep 12, 2004                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel                                   |
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

namespace MATPACK {

//----------------------------------------------------------------------------//
// Universal random number generator proposed by Marsaglia, Zaman, and Tsang.
// It has a period of 2^144 = 2*10^43, and is completely portable.
// Only 24 bits are garantueed to be completely random. 
// Upto now this generator passes all statistical tests on randomness.
//
// Ranmar generates a sequence of random numbers uniformly distributed in the
// interval (0,1), the end points excluded. 
// The seed value must be in the range 0 <= ijkl <= 900 000 000.
//
// References:
//      
//  1. G. Marsaglia and A. Zaman, Toward a Universal Random Number Generator,
//     Florida State University FSU-SCRI-87-50 (1987).
//  2. F. James, A Review of Pseudorandom Number Generators, Computer Phys.
//     Comm. 60, 329-344 (1990).    
//----------------------------------------------------------------------------//

void Ranmar::Seed (unsigned long ijkl)
{
    // Initializing routine for ranmar: Called by the constructor, can be
    // also called later to reseed the generator.
    // The input value must be in the range:  
    //
    //     0 <= ijkl <= 900 000 000
    //
    // Correspondence between the simplified input seed ijkl 
    // and the original Marsaglia-Zaman paper (i=12, j=34, k=56, l=78)  
    // is found with ijkl = 54217137.
    // 
    // (If a two-seed version is used the input values must be in the ranges
    // 0 <= ij <= 31328, 0 <= kl <= 30081 and Marsaglia-Zaman is found with
    // ij=1802, kl=9373)

    // if the seed is zero then a unique seed will be determined automatically
    if (ijkl == 0) ijkl = Random.UniqueSeed();
    ijkl &= 0x7fffffff;
    if (ijkl > 900000000) ijkl %= 900000001;

    //if ( ijkl < 0 || ijkl > 900000000 )
    //  Matpack.Error("Ranmar::Seed: 0 <= seed <= 900000000");

    int   ij, kl, i, j, k, l, m;

    ij = ijkl / 30082;
    kl = ijkl - 30082 * ij;
    i = ((ij / 177) % 177) + 2;
    j = (ij % 177) + 2;
    k = ((kl/169) % 178) + 1;
    l = kl % 169;

    for (int ii = 1; ii <= 97; ii++) {
         double s = 0.0;
         double t = 0.5;
         for (int jj = 1; jj <= 24; jj++) {
	     m = (((i*j) % 179)*k) % 179;
	     i = j;
	     j = k;
	     k = m;
	     l = (53*l+1) % 169;
	     if ( ((l*m) % 64) >= 32) s += t;
	     t = 0.5 * t;
	 }
	 u[ii-1] = s;
    }
    c  =   362436.0 / 16777216.0;
    cd =  7654321.0 / 16777216.0;
    cm = 16777213.0 / 16777216.0;
    i97 = 97;
    j97 = 33;
}

//----------------------------------------------------------------------------//

double Ranmar::operator () (void)
{
    double uni = u[i97-1] - u[j97-1];
    if (uni < 0) uni += 1.0;
    u[--i97] = uni;
    if (i97 == 0) i97 = 97;
    j97--;
    if (j97 == 0) j97 = 97;
    c -= cd;
    if (c < 0) c += cm;
    uni -= c;
    if (uni < 0) uni++;

    // to avoid that the return value is exactly zero (see F. James)
    if (uni == 0.0) {
      uni = u[j97-1] / 16777216.0; // * 2^-24
      if (uni == 0.0) 
	uni = 1.0/281474976710656.0;  // * 2^-48
    }

    return uni;
}

} // namespace MATPACK

//----------------------------------------------------------------------------//

