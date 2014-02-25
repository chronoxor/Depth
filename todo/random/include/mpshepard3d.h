/*-----------------------------------------------------------------------------*\
| Matpack - Shepard Method for Trivariate Interpolation           mpshepard3d.h |
|           of Scattered Data 		 					|
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

#ifndef _MPSHEPARD3D_H_
#define _MPSHEPARD3D_H_

//-----------------------------------------------------------------------------//
// class MpShepard3d: Shepard's Bivariate Interpolation of Scattered Data
//-----------------------------------------------------------------------------//

#include "vector.h"
#include "mpmatrix3d.h"

namespace MATPACK {

class MpShepard3d 
{
  protected:
    const Vector *x,*y,*z,*f;
    IntVector *next;
    Vector *rsq;
    Matrix *a;
    MpMatrix3d<int> *cells; 
    double rmax,xyzmin[3],xyzdel[3];

    MpShepard3d (const MpShepard3d&) {} 	    // copy currently forbidden
    MpShepard3d& operator = (const MpShepard3d&) { return *this; } // assigment currently forbidden
    
  public:
    enum { 
      NoError = 0,		// success
      VectorSizeMismatch,	// vectors don't have same dimension (1..n)
      TooFewNodes,		// 10 <= n
      FitNodesOutOfRange,	// 9 <= nq <= min(40,n-1)
      WeightNodesOutOfRange,	// 1 <= nw <= min(40,n-1)
      AbsentInterpolation,	// you don't have generated the interplation
      CollinearNodes,		// collinear nodes - interpolation fails
      DuplicateNodes,		// duplicate nodes - interpolation fails
      InvalidInput,		// invalid input parameters (can't happen)
      CellsOutOfRange,		// nr > 1 (can't happen)
      WorkSizeMismatch		// work array has wrong size (can't happen)
    };

    MpShepard3d (void);
   ~MpShepard3d (void);
    void Remove (void) { this->MpShepard3d::~MpShepard3d(); }

    int Interpolate (const Vector &X, const Vector &Y, 
		     const Vector &Z, const Vector &F,
		     int nq, int nw, int nr = 0);
    int GetValue    (double px, double py, double pz, double &q);
    int GetGradient (double px, double py, double pz, 
		     double &q, double &qx, double &qy, double &qz);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif

