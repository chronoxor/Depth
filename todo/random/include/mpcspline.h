/*-----------------------------------------------------------------------------*\
| Matpack - Cardinal cubic spline                                   mpcspline.h |
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

#include "mpcurvebase.h"

//-----------------------------------------------------------------------------//

#ifndef _MPCSPLINE_H_
#define _MPCSPLINE_H_

//----------------------------------------------------------------------------//

namespace MATPACK {

class MpCardinalCubicSpline : public MpCurveBase
{
  protected:
    void Draw4 (Scene& scene, const double *x, const double *y, int &first);

  public:
    MpCardinalCubicSpline (void) { }
    virtual ~MpCardinalCubicSpline (void) { }
    virtual int Interpolate (const Vector &x, const Vector &y);
    virtual double GetX (double u);
    virtual double GetY (double u);
    virtual void DrawClosedCurve (Scene &scene);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
