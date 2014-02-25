/*-----------------------------------------------------------------------------*\
| Matpack - Akima cubic spline interpolation                       mpaspline .h |
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

#ifndef _MPASPLINE_H_
#define _MPASPLINE_H_

//----------------------------------------------------------------------------//

namespace MATPACK {

class MpAkimaCubicSpline : public MpCurveBase
{
  protected:
    Vector y1, y2, y3;

  public:
    virtual ~MpAkimaCubicSpline (void) { }
    virtual int Interpolate (const Vector &x, const Vector &y);
    virtual double GetX (double u) { return u; }
    virtual double GetY (double u) { return CubicSplineHorner(u,*x,*y,y1,y2,y3); }
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
