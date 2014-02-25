/*-----------------------------------------------------------------------------*\
| class RungeKuttaFehlberg - RKF integrator class definition            mprkf.h |
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

#ifndef _MPRKF_H_
#define _MPRKF_H_

#include "vector.h"

//-----------------------------------------------------------------------------//

namespace MATPACK {

class RungeKuttaFehlberg
{
  protected:
    double ErrorTerm(int k);
    void RungeKuttaStep (void (*Model)(double t, const Vector &y, Vector &yp),
                         Vector &y, double t, double h, Vector &s);
    int norder,nfe,kop,init,kflag,jflag;                
    double h,savre,savae,order,iorder,crit,criti;
    Vector Work[7];
  
  public:
    enum {
        Start              =  1,
        StartSingleStep    = -1,
        NormalStep         =  2,
        SingleStep         = -2,
        SmallRelErrorBound =  3,
        TooManyIterations  =  4,
        SmallAbsErrorBound =  5,
        MinimumStepReached =  6,
        TooManyCalls       =  7,
        InvalidParameters  =  8,
        UnsolvableProblem  =  9
    };

    RungeKuttaFehlberg (const Vector &y, int norder=5);

    void Integrate (void (*Model)(double t, const Vector &y, Vector &yp),
                    Vector &y, double &t, double &tout, 
                    double relerr, double abserr, int &iflag, int maxnfe = 3000);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
