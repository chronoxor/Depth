/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                  ranchisqr.cpp |
|                                                                               |
| Last change: Mar 8, 1997                                                      |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-1997 by Berndt M. Gammel                                   |
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

//----------------------------------------------------------------------------//
// class ChiSquareDistribution: central chi-square distributed random numbers //
//----------------------------------------------------------------------------//
//
// Generates random deviates from a central chi-square distribution with 
// f degrees of freedom. f must be positive. 
// The density of this distribution is:
//
//
//                -f/2   f/2-1  -x/2
//               2      x      e
//  p (x) dx =  --------------------- dx  for x > 0
//   f               Gamma(f/2)
//
//           =  0                         otherwise
//
// The calculation uses the relation between chi-square and gamma distribution:
//
//  ChiSquare(f) = GammaDistribution(f/2,1/2)
//
// References:
//    K. Behnen, G. Neuhaus, "Grundkurs Stochastik", Teubner Studienbuecher
//    Mathematik, Teubner Verlag, Stuttgart, 1984.
//
//----------------------------------------------------------------------------//

// completely inlined

