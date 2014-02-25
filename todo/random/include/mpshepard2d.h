/*-----------------------------------------------------------------------------*\
| Matpack - Shepard Method for Bivariate Interpolation            mpshepard2d.h |
|           of Scattered Data                                                   |
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

#ifndef _MPSHEPARD2D_H_
#define _MPSHEPARD2D_H_

//-----------------------------------------------------------------------------//
// class MpShepard2d: Shepard's Bivariate Interpolation of Scattered Data
//-----------------------------------------------------------------------------//

#include "vector.h"

namespace MATPACK {

class MpShepard2d 
{
  protected:
    const Vector *x,*y,*f;
    IntMatrix *cells; 
    IntVector *next;
    Vector *rsq;
    Matrix *a;
    double xmin,ymin,dx,dy,rmax;

    MpShepard2d (const MpShepard2d&) {}             // copy currently forbidden
    MpShepard2d& operator = (const MpShepard2d&) { return *this; } // assigment currently forbidden
    
  public:
    enum { 
      NoError = 0,              // success
      VectorSizeMismatch,       // vectors don't have same dimension (1..n)
      TooFewNodes,              // 6 <= n
      FitNodesOutOfRange,       // 5 <= nq <= min(40,n-1)
      WeightNodesOutOfRange,    // 1 <= nw <= min(40,n-1)
      AbsentInterpolation,      // you don't have generated the interplation
      CollinearNodes,           // collinear nodes - interpolation fails
      DuplicateNodes,           // duplicate nodes - interpolation fails
      InvalidInput,             // invalid input parameters (can't happen)
      CellsOutOfRange,          // nr > 1 (can't happen)
      WorkSizeMismatch          // work array has wrong size (can't happen)
    };

    MpShepard2d (void);
   ~MpShepard2d (void);
    void Remove (void) { this->MpShepard2d::~MpShepard2d(); }

    int Interpolate (const Vector &X, const Vector &Y, const Vector &F,
                     int nq, int nw, int nr = 0);
    int GetValue    (double px, double py, double &q);
    int GetGradient (double px, double py, double &q, double &qx, double &qy);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
