/*-----------------------------------------------------------------------------*\
| Matpack statistics/combinatorics functions prototypes          mpstatistics.h |
|                                                                               |
| Last change: Mar 6, 2005                                                      |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel. All rights reserved.             |
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

// check for multiple inclusion
#ifndef _MPSTATISTICS_H_
#define _MPSTATISTICS_H_

#include "vector.h"
#include "mparraysort.h" // array sorting prototypes

namespace MATPACK {

//----------------------------------------------------------------------------//
// Statistics/Combinatorics prototypes
//----------------------------------------------------------------------------//

int MpCentralSums (const Vector &X, 
                   double &S1, double &S2, double &S3, double &S4,
                   double &mean, double &variance, 
                   double &skewness, double &kurtosis);

void MpQuantile (const float *a, unsigned n, unsigned m, 
               float q, float &pqq, float &pstdv);

void MpQuantile (const double *a, unsigned n, unsigned m, 
               double q, double &pqq, double &pstdv);

void MpQuantile (const float *a, unsigned n, unsigned m, 
                 float q, float &pqq, float &pstdv);

void MpQuantile (const double *a, unsigned n, unsigned m, 
                 double q, double &pqq, double &pstdv);

// class Vector interface adapters
inline void MpQuantile (const Vector& a, int m, double q, double &qq, double &stdv)
{ 
  MpQuantile (a.Store(), a.Elements(), (unsigned) m, q, qq, stdv);  
}

inline void MpQuantile (const Matrix& a, int m, double q, double &qq, double &stdv)
{
  MpQuantile (a.Store(), a.Elements(), (unsigned) m, q, qq, stdv); 
}


void MpSJTpermutation (int n, int *a, bool &next, bool &even);

void MpPearsonCorrCoeff (int n, const double x[], const double y[],
                         int m, double r[], double probr[] = 0, int stride = 0);
void MpPearsonCorrCoeff (int n, const float x[], const float y[],
                         int m, float r[], float probr[] = 0, int stride = 0);

void MpSpearmanCorrCoeff (int n, const double x[], const double y[],
                          int m, double rs[], double probrs[] = 0, int stride = 0);
void MpSpearmanCorrCoeff (int n, const float x[], const float y[],
                          int m, float rs[], float probrs[] = 0, int stride = 0);

bool MpFindPeak (int n, const float  x[], float  threshold, int &pos, int mode = 0);
bool MpFindPeak (int n, const double x[], double threshold, int &pos, int mode = 0);

void MpRank (int n, float  x[], float  &s, bool IsSorted = false);
void MpRank (int n, double x[], double &s, bool IsSorted = false);

//----------------------------------------------------------------------------//
// Statistics/Cryptography prototypes
//----------------------------------------------------------------------------//

int MpBerlekampMassey (int n,                     // in:  bit length
		       const unsigned char s[],   // in:  sequence
		       unsigned char C[],         // out: polynomial
		       unsigned char B[],         // (auxilliary)
		       unsigned char T[],         // (auxilliary)
		       int LCP[] = 0);            // out: optional profile

int MpBerlekampMasseyPacked (int n,               // in:  bit length
                             const uint32_t s[],  // in:  sequence
                             uint32_t C[],        // out: polynomial
                             uint32_t B[],        // (auxilliary)
                             uint32_t T[],        // (auxilliary)
                             int LCP[] = 0);      // out: optional profile

unsigned long MpGamesChanPacked (unsigned long n, // in:  bit length
				 uint32_t s[]);   // in:  sequence

//-----------------------------------------------------------------------------//
// modell fitting
//-----------------------------------------------------------------------------//

void MpFitLineMinSqrDev (const Vector &x, const Vector &y, const Vector &y_sdev,
                         double& a, double& b, 
                         double& a_sdev, double& b_sdev, double& chi2);

void MpFitLineMinAbsDev (const Vector& X, const Vector& Y, 
                         double& a, double& b, double& abdev);

void MpFitLineLocWeight (const Vector& x, const Vector& y, double f, int steps, double delta, 
                         Vector& ys, Vector& rw, Vector& res);

//-----------------------------------------------------------------------------//
// general non-linear least-square minimization
//-----------------------------------------------------------------------------//

typedef void (*LMFunction) (int,int,double*,double*,int&);

void LevenbergMarquardtFit (LMFunction fcn, Vector& x, Vector& f, 
                            double tol, int& info, int *iwa, double *wa, int lwa);

void LevenbergMarquardtFit (LMFunction fcn, Vector& x, Vector& f, 
                            double tol, int& info);

void LevenbergMarquardtFit (LMFunction fcn, Vector& x, Vector& f,
                            double ftol, double xtol, double gtol,
                            int maxfev, double epsfcn, double *diag, int mode, 
                            double factor, int nprint, int& info, 
                            int& nfev, double *fjac, 
                            int ldfjac, int *ipvt,
                            double *qtf, double *wa1, double *wa2, 
                            double *wa3, double *wa4);

//-----------------------------------------------------------------------------//
// fractals and physical modelling
//-----------------------------------------------------------------------------//

void FractalBrownianMotion (Vector& X, int b, double H, long seed = 0);
void FractalSurface (Matrix& X, int b, double H, long seed = 0);

int RS_Analysis (const Vector& X, int low, int lag,
                 double& Ave, double& Min, double& Max, 
                 double& Sdev, double& RS);

int RS_Analysis (const Vector& X, const IntVector& Lag, Vector& RS);

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
