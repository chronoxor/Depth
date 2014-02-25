/*-----------------------------------------------------------------------------*\
| 3d vector for graphics kernel                                      vector3d.h |
|                                                                               |
| Last change: Jul 16, 2005                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel. All rights reserved.             |
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

// check for multiple inclusion
#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_

#include <iostream>
#include "common.h"
#include "mptrafo.h"

namespace MATPACK {

// friend classes
class Trafo;

//----------------------------------------------------------------------------//
// class Vector3D - coordinate vector in 3D space
//----------------------------------------------------------------------------//

class Vector3D 
{
  public:
    float x,y,z;

    Vector3D (void) {}
    Vector3D (float vx, float vy, float vz) : x(vx), y(vy), z(vz) {}
    
    // transformation
    friend class Trafo;
    friend Vector3D operator * (const Trafo& t, const Vector3D& v);
    Vector3D& operator *= (const Trafo& t);

    // cross product
    friend Vector3D operator ^ (const Vector3D& a, const Vector3D& b);

    // dot product
    friend float operator * (const Vector3D& a, const Vector3D& b)
        { return (a.x * b.x + a.y * b.y + a.z * b.z); }

    // vector addition
    friend Vector3D operator + (const Vector3D& a, const Vector3D& b)
        { return Vector3D(a.x+b.x, a.y+b.y, a.z+b.z); }

    Vector3D& operator += (const Vector3D& b)
       { x += b.x; y += b.y; z += b.z;  return *this; }

    // equality
    friend bool operator == (const Vector3D& p1, const Vector3D& p2)
        { return (p1.x == p2.x) && (p1.y == p2.y) && (p1.z == p2.z); }

    friend bool operator != (const Vector3D& p1, const Vector3D& p2)
        { return (p1.x != p2.x) || (p1.y != p2.y) || (p1.z != p2.z); }

    // norm 
    friend float Norm (const Vector3D& a) 
        { return hypot(a.x,a.y,a.z); }

    // I/O
    int read  (istream& is);
    int write (ostream& os) const;

    friend istream& operator >> (istream& is, Vector3D& v) { 
      v.read(is); return is; 
    }

    friend ostream& operator << (ostream& os, const Vector3D& v) { 
      v.write(os); return os; 
    }   
};

} // namespace MATPACK

//----------------------------------------------------------------------------//

#endif
