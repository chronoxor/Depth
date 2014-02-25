/*-----------------------------------------------------------------------------*\
| Matpack - general include file                                      matpack.h |
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
| from the use of this software.                                                |
| Note that distributing Matpack 'bundled' in with any product is considered to |
| be a 'commercial purpose'.                                                    |
| The software may be modified for your own purposes, but modified versions may |
| not be distributed without prior consent of the author.                       |
|                                                                               |
| Read the  COPYRIGHT and  README files in this distribution about registration |
| and installation of Matpack.                                                  |
|                                                                               |
\*-----------------------------------------------------------------------------*/

#ifndef _MATPACK_H_
#define _MATPACK_H_

//-----------------------------------------------------------------------------//

#include "scene.h"	   // class Scene
#include "mpmatrix3d.h"    // 3d matrix template classes
#include "vector.h"	   // vector and matrix classes
#include "mpspecfun.h"	   // special function prototypes
#include "mpstatistics.h"  // statistics function prototypes
#include "mproots.h"       // roots and minimum finding function prototypes
#include "mpphysics.h"     // physics related function prototypes
#include "mpdataformat.h"  // I/O data format functions
#include "mp2dplots.h"     // 2D graphics functions
#include "mp3dplots.h"     // 3D graphics functions
#include "mprandom.h"      // random number generators
#include "mpaxis.h"


namespace MATPACK {

//-----------------------------------------------------------------------------//
// differential equations
//-----------------------------------------------------------------------------//

int ODE_Bulirsch (double& x, Vector& y, 
		  void (*Function) (double x, Vector& y, Vector& f), 
		  double xend, double& h, double hmax, 
		  double eps_abs, double eps_rel, int max_fct,
		  int start, Vector* aux, int& row, double& x0);

//-----------------------------------------------------------------------------//
// integration
//-----------------------------------------------------------------------------//

double AdaptiveSimpson (double a, double b, 
			double (*funct)(double x), 
			double eps);



//-----------------------------------------------------------------------------//
// geometry
//-----------------------------------------------------------------------------//

double MpTriangleArea (double a, double b, double c, int &error);


} // namespace MATPACK


//-----------------------------------------------------------------------------//

#endif
