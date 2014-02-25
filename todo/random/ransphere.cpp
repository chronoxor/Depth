/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                   ransphere.cpp |
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
// class UnitSphereDistribution 		 			      //
//----------------------------------------------------------------------------//
//								       	      //
// Vector of three random numbers (x,y,z) which are distributed uniformly     //
// on the unit sphere.                                                        //
//								       	      //
// Uses the algorithm of Marsaglia, Ann. Math. Stat 43, 645 (1972).           //
// On average requires 2.25 deviates per vector and a square root calculation //
//								       	      //
//----------------------------------------------------------------------------//

void UnitSphereDistribution::operator () (double &x, double &y, double &z) 
{ 
  for (;;) {
    double d1 = 1.0 - scale * Long(),
           d2 = 1.0 - scale * Long(),
           dd = d1 * d1 + d2 * d2;
    if (dd < 1.0) { 
      z = 1 - 2 * dd;
      dd = 2 * sqrt(1.0-dd);
      x = d1 * dd;
      y = d2 * dd;
      return;
    }
  }
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
