/*-----------------------------------------------------------------------------*\
| Class Trafo - 4d coordinate transformation matrix class             mptrafo.h |
|                                                                               |
| Last change:  Jan 9, 2005                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel                                   |
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

#ifndef _MPTRAFO_H_
#define _MPTRAFO_H_

#include <iostream>
#include "vector3d.h"

//-----------------------------------------------------------------------------//

namespace MATPACK {

// std stream I/O
using std::istream;
using std::ostream;

// friend classes
class Vector3D;
class Vertex;

class Trafo 
{
  protected:
    float m[3][4];   

  public:
    //  The 4x4 transformation matrices are of the general shape
    //     
    //        | a00 a01 a02 tx |
    //    T = | a10 a11 a12 ty |
    //        | a20 a21 a22 tz |
    //        |  0   0   0  1  |
    // 
    //  The last row is not stored explicitly, so we have 3 by 4 matrices.

    // Constructor 1: Uninitialized transformation matrix.
    Trafo (void) {}


    // Constructor 2:
    // Initializes a diagonal matrix with the given diagonal value f.
    // The last row of the 4x4 matrix is not stored because it is always (0 0 0 1)
    Trafo (float f);

    enum { XAxis = 1, YAxis = 2, ZAxis = 3 }; // axes for rotations

    // return the element t(i,j) of the transformation matrix t.
    const float&    operator () (int i, int j) const { return m[i][j]; }
    float&          operator () (int i, int j) { return m[i][j]; }

    // Returns the matrix product c = a * b.
    friend Trafo    operator *  (const Trafo& a, const Trafo& b);

    // Returns the inverse transformation for the given transformation t.
    // If t is singular then a zero transformation matrix is returned.
    friend Trafo    invert      (const Trafo& t);

    // Return the transformation matrix for a translation 
    // by the 3d vector t=(tx,ty,tz)
    friend Trafo    trans       (float tx, float ty, float tz);
    friend Trafo    trans       (const Vector3D& t);

    // Return the transformation matrix for scaling
    // by sx, sy, and sz in the x-, y-, and z-direction respectively.
    // The vector argument denotes s = (sx, sy, sz).
    // The scalar argument sc denotes s = (sc, sc, sc).
    friend Trafo    scale       (float sx, float sy, float sz);
    friend Trafo    scale       (const Vector3D& s);
    friend Trafo    scale       (float sc); 

    // Returns a matrix for a counter clockwise rotation through the 
    // angle theta about an axis m through the origin, where m = 1,2,3
    // specifies the x,y,z-axis.
    // The enumeration variables 
    //    Trafo::XAxis=1, Trafo::YAxis=2, Trafo::ZAxis=3 
    // are defined for convenience.
    friend Trafo    rot         (int axis, float theta);

    // Deprecated function:
    // Returns a matrix for a counter clockwise rotation through the 
    // angle phi about a general axis with base point (bx,by,bz) and 
    // direction vector (dx,dy,dz).
    // This (slow version) should no longer be used !      
    // You should always use method "Trafo rot(const Vector3D& A, float theta)"
    friend Trafo    rot         (float,float,float,float,float,float,float);


    // Rotation matrix for a rotation by the angle theta about an axis 
    // defined by the unit vector E in the direction of the axis A. The axis
    // goes through the origin.
    //
    // This matrix is given by:
    // 
    //   D_a,b(E,theta) 
    //    = delta_a,b cos(theta) + E_a E_b (1-cos(theta)) + eps_a,b,c E_c sin(theta)
    //
    //   with   E = (E_x,E_y,E_z) the unit vector in direction of the axis A
    //                            of rotation through the origin
    //          theta             the angle of rotation about the axis E
    //          delta_a,b         the Kronecker delta
    //          eps_a,b,c         the anti-symmetric Levi-Civita tensor of rank 3
    //          a,b,c             indices running over {x, y, z}
    //
    // Notes: 1) The input vector "axis"  is automatically normalized.
    //           If the norm is zero an all-zero transformation matruix returned.
    //
    //        2) This algorithm for generating a 3d rotation matrix requires 
    //           only 15 multiplications, one sine and one cosine evaluation.
    //           It is probably the fastest known method.
    //
    friend  Trafo   rot         (const Vector3D& axis, float theta);

    // Return non-zero if two transformation matrices are equal, zero otherwise.
    friend bool     operator == (const Trafo& a, const Trafo& b);

    // Return non-zero if two transformation matrices are different, zero otherwise.
    friend bool     operator != (const Trafo& a, const Trafo& b);

    // Applies the given transformation to a vertex and returns
    // the result.
    friend class Vertex;
    friend Vertex   operator *  (const Trafo& t, const Vertex& v);

    // Transform the 3d vector v using the transformation t and returns
    // the result.
    friend class Vector3D;
    friend Vector3D operator *  (const Trafo& t, const Vector3D& v);
    
    // Read a transformation defined in plain text format from the stream is.
    // On sucess a value of 0 is returned, otherwise 1.
    // Upon failure the stream state fail bit is set.
    // The format is given by 
    // "Trafo( <a00>, <a01>, <a02>, <a03>, <a10>, <a11>, ..., <a23> )".
    int read  (istream& is);

    // Write a transformation in plain text format to the stream os.
    // On sucess a value of 0 is returned, otherwise 1.
    // The format is given by 
    // "Trafo( <a00>, <a01>, <a02>, <a03>, <a10>, <a11>, ..., <a23>)".
    int write (ostream& os) const;

    // For convenience the input stream and output stream operators
    // are also defined. Upon a read/write error the stream state fail bit is set.
    friend istream& operator >> (istream& is, Trafo& t) { 
      t.read(is); return is; 
    }

    friend ostream& operator << (ostream& os, const Trafo& t) {
      t.write(os); return os;
    }

}; // class Trafo 

// The identity transformation is available as a global constant
extern const Trafo Identity;

// declare the friends (gcc versions >= 4.1.0 need that)
Trafo trans  (float tx, float ty, float tz);
Trafo trans  (const Vector3D& t);
Trafo scale  (float sx, float sy, float sz);
Trafo scale  (const Vector3D& s);
Trafo scale  (float sc); 
Trafo rot    (int axis, float theta);
Trafo rot    (float,float,float,float,float,float,float);
Trafo rot    (const Vector3D& axis, float theta);
 
} // namespace MATPACK

//----------------------------------------------------------------------------//

#endif
