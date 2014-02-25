/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                 ranfdistrib.cpp |
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
#include <float.h>

namespace MATPACK {

//----------------------------------------------------------------------------//
// class FDistribution: F-distributed random numbers 		              //
//----------------------------------------------------------------------------//
//								       	      //
// Return F-distributed (variance ratio distributed) random deviates	      //
// with n numerator degrees of freedom and d denominator degrees of freedom   //
// according to the density:						      //
//								       	      //
//   p   (x) dx =  ... dx						      //
//    n,d								      //
//									      //
// Both paramters n and d must be positive.				      //
//									      //
// Method: The random numbers are directly generated from ratios of    	      //
//         ChiSquare variates according to:				      //
//								       	      //
//  F = (ChiSquare(n)/n) / (ChiSquare(d)/d)				      //
//								       	      //
//----------------------------------------------------------------------------//

FDistribution::FDistribution (double numf, double denomf, RandomGenerator* ran) 
{ 
  // check parameter range
  if (numf < 0.0 || denomf < 0.0)
    Matpack.Error("FDistribution: numerator (%g) and denominator (%g) degrees\n" 
		  "of freedom must be positive", numf, denomf);
  
  // store parameters
  NF = numf; 
  DF = denomf; 
  
  // initialize numerator and denominator chi-square distributions
  NumChi2 = ChiSquareDistribution(NF,ran);
  DenomChi2 = ChiSquareDistribution(DF,ran);
}

//----------------------------------------------------------------------------//

double FDistribution::operator() (void)
{
  double numerator   = NumChi2()/NF,
         denominator = DenomChi2()/DF;
  
  // return avoiding overflow
  return (denominator <= numerator*DBL_MIN) ? DBL_MAX : numerator/denominator;
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
