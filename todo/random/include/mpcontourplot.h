/*-----------------------------------------------------------------------------*\
| Matpack - class ContourPlotClass                              mpcontourplot.h |
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

#ifndef _MPCONTOURPLOT_H_
#define _MPCONTOURPLOT_H_

#include "scene.h"
#include "vector.h"
#include "mpaxis.h"
#include "mpmatrix3d.h"

// IN WORK ...................

namespace MATPACK {

//-----------------------------------------------------------------------------//
// structure to describe one contour level 
//-----------------------------------------------------------------------------//

class MpContourLevel 
{
  public:
    double level;               // level height
    short thickness, pattern;   // line type
    ColorB color;               // line color
    const char* label;          // text label (NOT YET SUPPORTED)
    MpContourLevel (void) 
      { level=0; thickness=1; pattern=Solid; color=ColorB(0,0,0); label=0; }
};

//----------------------------------------------------------------------------//
// class ContourPlotClass  - description of a contour plot
//----------------------------------------------------------------------------//

#define CONTOUR_MAXTEXT 256
class ContourPlotClass 
{
  public:       
    enum   {  Lines = 4, BezierSpline = 16, CardinalSpline = 256 };

    int    level_num, interpolation, options,
           unlabeled_pattern, unlabeled_thickness, 
           labeled_frequency, labeled_offset, 
           labeled_pattern, labeled_thickness, 
           label_font,projection;

    long   unlabeled_color, labeled_color, label_color;

    double level_min, level_step, projection_height,label_size,
           label_distance,x1,x2,y1,y2;

    char   label_format[CONTOUR_MAXTEXT];

    Trafo  trafo;

    ContourPlotClass (void);

    void ContourPlot (Scene&,Matrix&,char* = 0,char* = 0,char* = 0,MpAxis* = 0);
};

//----------------------------------------------------------------------------//

void ContourLine (Scene& scene, const Matrix& z, double height,
                  int mode = ContourPlotClass::BezierSpline, double hxy = 0,
                  const Trafo &trafo = Identity, char *label = 0, 
                  double label_distance = 0.0); 

//-----------------------------------------------------------------------------//
// 2d drawing
//-----------------------------------------------------------------------------//

void ContourFill (Scene& scene, const Matrix& Z, 
                  int mode = 2, int options = Boxed, 
                  ColorMap& Colors = NoColorMap);

void ContourFill (Scene& scene, 
                  const Vector& X, const Vector& Y, 
                  const Matrix& Z, const Vector& Levels, 
                  int mode = 2, ColorMap& Colors = NoColorMap);

//-----------------------------------------------------------------------------//
// 3d contour surfaces
//-----------------------------------------------------------------------------//

void MpContourSurface (Scene& scene, const MpMatrix3d<double> &M, 
                       double height);

void MpContourSurface (Scene& scene,
                       double fcn(double x, double y, double z),
                       int nx, double x1, double x2,
                       int ny, double y1, double y2,
                       int nz, double z1, double z2,
                       double height);

void MpContourSurface (Scene& scene, const Matrix& matrix,
                       double x1, double x2, double y1, double y2,
                       const Vector &level,
                       const ColorMap& cmap, 
                       double cmapmin, double cmapmax);

} // namespace MATPACK

//----------------------------------------------------------------------------//

#endif
