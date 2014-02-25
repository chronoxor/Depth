/*-----------------------------------------------------------------------------*\
| include file for  2d data visualization methods                   mp2dplots.h |
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

#ifndef _MP2DPLOTS_H_
#define _MP2DPLOTS_H_

#include "scene.h"
#include "vector.h"
#include "mpmark.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// 2D data visualization methods
// method implementations can be found in source/Draw2D/
//-----------------------------------------------------------------------------//

class MpBoxPlot 
{
  public:
    enum { Squares  = 0x00, 
           Circles  = 0x01, 
           Outlined = 0x02 };
    static void Draw (Scene& scene, const Matrix& data,
                      const ColorMap& cmap, double cmin, double cmax, 
                      int shape = Squares|Outlined);
};

class MpSpecklePlot 
{
  public:
    enum { ColorMapped         = 0x01, 
           ErrorDiffusion      = 0x02, 
           OrderedDither       = 0x04, 
           BezierInterpolation = 0x08 };
    static void Draw (Scene &scene, const Matrix &data,
                      const ColorMap &cmap, double cmin, double cmax,
                      int mode = 0, double resolution = 1.0);
};

class MpComplex2dFieldPlot 
{
  public:
    enum { Modulus   = 0x01, 
           Thickness = 0x02 };
    static void Draw (Scene &scene, const ComplexMatrix &data,
                      const ColorMap &cmap, double cminmod, double cmaxmod,
                      int mode = 0);
};

class MpDensityPlot 
{
  public:
    enum { Outlined   = 0x01 };
    static void Draw (Scene &scene, const Matrix &data,
                      const ColorMap &cmap, double cmin, double cmax,
                      int mode = 0);
};

class MpLambertShader
{
  public:
    void MakeHistogram (const Matrix &Z, int N=0, int Lo=0, int Hi=0);
    void MakeImage (const Matrix &Z, MpImage& image, 
                    double theta = 45, double phi = 45, 
                    double enhance = 1, 
                    const ColorMap& cmap = NoColorMap, 
                    double cmin = 0, double cmax = 0);

    MpLambertShader (void) { }
    MpLambertShader (const Matrix &Z, int N=0, int Lo=0, int Hi=0)
                         { MakeHistogram(Z,N,Lo,Hi); }

  protected:
    Vector Hist;
    double Dmax,Dmin,slope,intercept;
    void MakeHistogramFit (int Lo, int Hi);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
