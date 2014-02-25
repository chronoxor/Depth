/*-----------------------------------------------------------------------------*\
| Matpack statistics/combinatorics functions prototypes             mp3dplots.h |
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

// check for multiple inclusion
#ifndef _MP3DPLOTS_H_
#define _MP3DPLOTS_H_

#include "scene.h"
#include "mpmatrix3d.h"
#include "vector.h"

namespace MATPACK {

class MpAxis;

//-----------------------------------------------------------------------------//
// Create 3D surface visualization from 3-dimensional array data
//-----------------------------------------------------------------------------//

// Iso-surfaces of volumes
// -----------------------

int IsoSurface3D (Scene& scene,int xdim, int ydim, int zdim, const float *data, 
                  float threshold, 
                  int EdgeLinesX = 1, int EdgeLinesY = 1, int EdgeLinesZ = 1, 
                  ColorB *color = 0);

int IsoSurface3D (Scene& scene,int xdim, int ydim, int zdim, const double *data, 
                  double threshold, 
                  int EdgeLinesX = 1, int EdgeLinesY = 1, int EdgeLinesZ = 1,
                  ColorB *color = 0);

int IsoSurface3D (Scene& scene, const MpMatrix3d<float> &matrix, 
                  float threshold,
                  int EdgeLineX = 1, int EdgeLineY = 1, int EdgeLineZ = 1,
                  ColorB *color = 0);

int IsoSurface3D (Scene& scene, const MpMatrix3d<double> &matrix, 
                  double threshold,
                  int EdgeLinesX = 1, int EdgeLinesY = 1, int EdgeLinesZ = 1,
                  ColorB *color = 0);

int IsoSurface3D (Scene& scene, 
                  int nx, float x1, float x2,
                  int ny, float y1, float y2,
                  int nz, float z1, float z2,
                  float (*fcn)(float x, float y, float z),
                  float threshold, 
                  int EdgeLinesX = 1, int EdgeLinesY = 1, int EdgeLinesZ = 1, 
                  ColorB *color = 0);

int IsoSurface3D (Scene& scene, 
                  int nx, double x1, double x2,
                  int ny, double y1, double y2,
                  int nz, double z1, double z2,
                  double (*fcn)(double x, double y, double z),
                  double threshold, 
                  int EdgeLinesX = 1, int EdgeLinesY = 1, int EdgeLinesZ = 1,
                  ColorB *color = 0);

// Slice plots of volume data
// --------------------------

void MpSlicePlot (Scene& scene,
                  const MpMatrix3d<double> &data, 
                  const IntVector& dim1, const IntVector& dim2, const IntVector& dim3,
                  const ColorMap& cmap = NoColorMap, 
                  double cmin = 0.0, double cmax = 0.0,
                  bool outline = true);

//-----------------------------------------------------------------------------//
// Create 3D surface from 2-dimensional array data
//-----------------------------------------------------------------------------//

void MpSurface (Scene& scene, 
                const Matrix& z, 
                int edgelines = 3, 
                const ColorMap& cmap = NoColorMap, 
                double cmin = 0.0, double cmax = 0.0,
                int xstride = 1, int ystride = 1);

void MpComplexSurface (Scene& scene, 
                       const ComplexMatrix& z, 
                       double MapHeight (const complex<double>& z), 
                       double MapColor  (const complex<double>& z), 
                       int edgelines = 3, 
                       const ColorMap& cmap = NoColorMap,
                       double cmin = 0.0, double cmax = 0.0,
                       int xstride = 1, int ystride = 1);

void MpSurfaceBands (Scene& S, const Matrix& z, int direction, double width = 1.0,
                     const ColorMap& cmap = NoColorMap,
                     double cmin = 0.0, double cmax = 0.0); 

void MpSurfacePatches (Scene& S, const Matrix& z, double  r, int mode = 0,
                       const ColorMap& cmap = NoColorMap,
                       double cmin = 0.0, double cmax = 0.0,
                       double height = 0.0);

void MpSurfaceHistogram (Scene& S, const Matrix& z, bool sides = true,  
                         const ColorMap& cmap = NoColorMap, 
                         double cmin = 0.0, double cmax = 0.0,
                         const ColorB &sidecolor = ColorB(255,255,255));

void MpSurfaceHorizon (Scene& S, const Matrix& z, int direction, 
                       const ColorMap &cmap = NoColorMap);

void MpSurfacePrism (Scene &S, const Matrix &Z, int nsegments,
                     double wx = 0.5, double wy = 0.5, 
                     const ColorMap &cmap = NoColorMap, 
                     double cmin = 0.0, double cmax = 0.0);

void MpSurfaceCones (Scene& S, const Matrix& z, int nseg = 4, 
                     double wx = 0.5, double wy = 0.5,
                     double angle = 0, const ColorMap& cmap = NoColorMap, 
                     double cmin = 0.0, double cmax = 0.0);

int  MpWarpMatrixToSphere (Scene& S, Matrix& H, Vector& Pol, Vector& Azm,
                           double r, const Trafo& T, 
                           int facet_culling, bool periodic,
                           bool south_pole_cap, double h_south, 
                           bool north_pole_cap, double h_north, 
                           const ColorMap& cmap, double cmin, double cmax,
                           int PolStride, int AzmStride);
 
//-----------------------------------------------------------------------------//
// Create parametric surfaces
//-----------------------------------------------------------------------------//

void ParametricSurface (Scene &scene, 
                        void (*fcn)(double u, double v,
                                    double& x, double& y, double& z, void *vptr),
                        double u1, double u2, int nu, int su, 
                        double v1, double v2, int nv, int sv,
                        int mode = 0, 
                        const Trafo &P = Identity,
                        ColorB (*colorfcn)(double u, double v, void *vptr) = NULL,
                        void *vptr = NULL);

void AddTube (Scene &scene, const Vector3D &p1, const Vector3D &p2, 
              double rad, int na, int sa, int nr, int sr, ColorB *color = NULL);

//-----------------------------------------------------------------------------//

void    Grid             (Vector& x, Vector& y, Vector& z,
                          double co, double sill, double range, 
                          double angle, double horiz,
                          int neigbors, double radius, int stationarity, 
                          double gridxmax, double gridymax, 
                          double deltax, double deltay, Matrix& Grd, Matrix& Var);

//-----------------------------------------------------------------------------//
// other 2d/3d plot types
//-----------------------------------------------------------------------------//

void    FieldPlot        (Scene&,int,Vertex*,float len, int=0,
                          const char* =0,const char* =0,const char* =0,const char* =0,MpAxis* =0);

//-----------------------------------------------------------------------------//

void ColorMapLegend (Scene& scene, ColorMap& cmap, 
                     double x, double y, double width, double length,
                     double lo, double hi,
                     char* title = 0,
                     int direction = 0, 
                     ColorF* cellframecolor = 0, 
                     ColorF* framecolor = 0, 
                     MpAxis* axis = 0);

void axisframe (Scene& scene,
                double xlo, double xhi, double ylo, double yhi,
                const char* title,
                double x1, double x2, const char* xtitle,
                double y1, double y2, const char* ytitle,
                MpAxis* A);

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
