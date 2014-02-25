/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                  ranuniform.cpp |
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
// class UniformDistribution						      //
//----------------------------------------------------------------------------//
//									      //
// Return uniformly distributed random deviates according to:		      //
//								       	      //
// p(x) dx = dx   for x in [a,b]					      // 
//         =  0   otherwise						      //
//									      //
//----------------------------------------------------------------------------//

// completely inlined
