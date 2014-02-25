/*-----------------------------------------------------------------------------*\
| Matpack root/minimum finding functions prototypes                   mproots.h |
|                                                                               |
| Last change: Sep 12, 2004                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel                                   |
|                                                                               |
| Permission to  use, copy, and  distribute  Matpack  in  its entirety  and its |
| documentation  for non-commercial purpose and  without fee is hereby granted, |
| provided that this license information and copyright notice appear unmodified |
| in all copies.  This software is provided 'as is'  without express or implied |
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

// check for multiple inclusion
#ifndef _MPROOTS_H_
#define _MPROOTS_H_

#include "vector.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// univariate zero and extremum finding
//-----------------------------------------------------------------------------//

void MpFindQuadraticRoots (double a, double b, double c, double x[], int &mt);

void MpFindCubicRoots (double r, double s, double t, double x[], double &dc);

void MpFindQuarticRoots (double a, double b, double c, double d,
			 complex<double> z[], double &dc, int &mt);

double FindZero (double t1, double t2, double (*function)(double), 
		 double tol = DBL_EPSILON);

double FindZeroB (double t1, double t2, double (*function)(double), 
		  double tol = DBL_EPSILON);

double FindMinimum (double t1, double t2, double (*function)(double x),	
		    double tol = DBL_EPSILON);

int FindZeros (const ComplexVector& Coeff, 
	       ComplexVector& Zero, int guess,
	       Vector& Bound, ComplexVector& Aux);

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
