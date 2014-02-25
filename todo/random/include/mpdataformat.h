/*-----------------------------------------------------------------------------*\
| Matpack data formats                                           mpdataformat.h |
|                                                                               |
| Last change: Sep 12, 2004							|
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel. All rights reserved.             |
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

#ifndef _MPDATAFORMAT_H_
#define _MPDATAFORMAT_H_

#include "vector.h"
#include "mpmatrix3d.h"
#include "mptrafo.h"
#include "color.h"

namespace MATPACK {

class Scene;

//----------------------------------------------------------------------------//
// general data I/O functions
//----------------------------------------------------------------------------//

class  MpDataFormat {
  public:
    int data,           // data type: MpArray, MpFacets
        format,         // data format: MpTextFormat, MpBinaryFormat
        order,          // array order: Mp(Row/Column)Major
        array,          // array dimension: 1, 2, or 3
        number,         // number type: Mp(Real/Complex/Integer/Bit)Valued
        element,        // element type: scalar = 1, 2D = 2, 3D = 3
        precision,      // MpSingle, MpDouble
        endian,         // MpNativeByteOrder, MpSwapByteOrder
        arraydim[6],    // array lower and upper index bounds
        npoints,        // number of points
        vertexcolor,    // MpSingle, MpByte
        npolys,         // number of polygons
        facetcolor,     // MpSingle, MpByte
        set_globalcolor;// global color is set
    bool offset1,       // offset=1 for facet lists (else 0)
         negli;         // negative last vertex index in facet
    char include[256];  // include file name
    Trafo trafo;        // transformation
    ColorB globalcolor;

    MpDataFormat (void)
    {
      // initialize results with undefined value (-1)
      data = format = order = number = element = precision = endian = 
        array = npoints = npolys = vertexcolor = facetcolor = -1;
      include[0] = '\0';
      trafo = Identity;
      set_globalcolor = 0; 
      offset1 = negli = false;
      for (int i = 0; i < 6; i++) arraydim[i] = -1;
    }
};

//----------------------------------------------------------------------------//
// Reading and writing of Matpack native data format string
//----------------------------------------------------------------------------//

int MpReadDataFormat (istream &is, MpDataFormat &dataformat);

void MpWriteDataFormat (ostream &os,
                        int format, int order, int array, int number,
                        int element, int precision, int endian, int dim[]);

istream& MpEatComments (istream &is);
istream& MpEatNumericalSeparator (istream &is);

//----------------------------------------------------------------------------//
// basic data load and save routines
//----------------------------------------------------------------------------//

// 1-dim array of scalar

int MpLoad1dArrayOfRealScalar (istream &f, 
                               Vector &x, int dim[], 
                               int format, int precision, int byteorder);
int MpSave1dArrayOfRealScalar (ostream &f, const Vector &x,
                               int format, int precision, int byteorder);

int MpLoad1dArrayOfIntegerScalar (istream &f, 
                                  IntVector &x, int dim[], 
                                  int format, int precision, int byteorder);
int MpSave1dArrayOfIntegerScalar (ostream &f, const IntVector &x,
                                  int format, int precision, int byteorder);

int MpLoad1dArrayOfComplexScalar (istream &f, 
                                  ComplexVector &x, int dim[], 
                                  int format, int precision, int byteorder);
int MpSave1dArrayOfComplexScalar (ostream &f, const ComplexVector &x,
                                  int format, int precision, int byteorder);

// 1-dim array of 3-dim vector

int MpLoad1dArrayOfRealVector3D (istream &f, 
                                 Vector &x, Vector &y, Vector &z, int dim[], 
                                 int format, int precision, int byteorder);
int MpSave1dArrayOfRealVector3D (ostream &f, 
                                 const Vector &x, const Vector &y, const Vector &z, 
                                 int format, int precision, int byteorder);

// 2-dim array of scalar

int MpLoad2dArrayOfRealScalar (istream &f, 
                               Matrix& M, int dim[], int arrayorder, int format, 
                               int precision, int byteorder);
int MpSave2dArrayOfRealScalar (ostream &f, const Matrix &x,
                               int arrayorder, int format, 
                               int precision, int byteorder);

int MpLoad2dArrayOfIntegerScalar (istream &f, 
                                  IntMatrix& M, int dim[], 
                                  int arrayorder, int format, 
                                  int precision, int byteorder);
int MpSave2dArrayOfIntegerScalar (ostream &f, const IntMatrix &x,
                                  int arrayorder, int format, 
                                  int precision, int byteorder);

int MpLoad2dArrayOfComplexScalar (istream &f, ComplexMatrix& C, 
                                  int dim[], int arrayorder, int format, 
                                  int precision, int byteorder);
int MpSave2dArrayOfComplexScalar (ostream &f, const ComplexMatrix &x,
                                  int arrayorder, int format, 
                                  int precision, int byteorder);
// 3-dim array of scalar

int MpLoad3dArrayOfRealScalar (istream &f, MpMatrix3d<double> &V, 
                               int dim[], int arrayorder, int format, 
                               int precision, int byteorder);
// solid bodies (scenes)

int MpLoadFacetData (istream &f, Scene &scene, 
                     int nvertices, int nfacets, 
                     int per_vertex_color, int per_facet_color,
                     const ColorB *global_color,
                     const Trafo &P,
                     int idx_offset = 0,
                     bool neg_last_index = false);

int MpLoadScene (istream &is, Scene &scene, 
                 const ColorB *global_color, const Trafo &P);

int MpSaveScene (ostream &os, const Scene &scene, int mode = 0);

//-----------------------------------------------------------------------------//

} // namespace MATPACK

#endif
