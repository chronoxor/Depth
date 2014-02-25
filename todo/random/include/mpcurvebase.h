/*-----------------------------------------------------------------------------*\
| Matpack - abstract class MpCurveBase                            mpcurvebase.h |
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

// uncomment to switch on index range checking
//#define DEBUG

#include "vector.h"
#include "scene.h"

//-----------------------------------------------------------------------------//

#ifndef _MPCURVEBASE_H_
#define _MPCURVEBASE_H_


namespace MATPACK {

//----------------------------------------------------------------------------//
//
// class MpCurveBase is currently inherited by:
//
//   class MpFritschCarlsonCubicSpline
//   class MpAkimaCubicSpline
//   class MpBezierCubicSpline
//   class MpCardinalCubicSpline
//   class MpRationalCubicSpline
//   class MpExponentialSpline
//   class MpPolynomialInterpolation
//   class MpRationalInterpolation
//
//----------------------------------------------------------------------------//

class MpCurveBase
{
  protected:

    const Vector *x,*y;
  
    int FindIntervall (double u, const Vector &x) const;

    int GetResolution (const Scene& scene, 
		       double x1, double y1, double x2, double y2) const;

    double CubicSplineHorner (double u, 
			      const Vector &x, const Vector &y, 
			      const Vector &y1, const Vector &y2, 
			      const Vector &y3) const;

    void CubicSplineCoefficients (const Vector &x, 
				  const Vector &y, 
				  const Vector &y1, 
				  Vector &y2, Vector &y3) const;


  public:

    enum BoundaryConditions 
    { 
      Natural = 0, 		// natural boundaries, zero 2nd deriv.
      FiniteDifferences, 	// finite differences for 1st derivatives
      Supply1stDerivative,	// user supplied f'(x_lo), f'(x_hi)
      Supply2ndDerivative,	// user supplied f''(x_lo), f''(x_hi)
      Periodic  		// periodic boundaries (NOT YET IMPLEMENTED)
    };

    enum Parametrization 	// curve parametrization methods
    {
      No = 0,			// don't parametrize (default)
      Norm2,			// use sqrt(dx^2+dy^2)
      SqrNorm2,			// use (dx^2+dy^2)
      Norm1 			// use |dx| + |dy|
    };

    MpCurveBase (void) : x(0), y(0) { }
    virtual ~MpCurveBase (void) { }

    virtual int Interpolate (const Vector &x, const Vector &y) = 0;
    virtual double GetX (double x) = 0;
    virtual double GetY (double x) = 0;

    virtual void DrawCurve (Scene &scene, double x_lo, double x_hi);

    virtual void Parametrize (const Vector& x, const Vector& y, 
			      Vector& t, int parametrization) const;
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
