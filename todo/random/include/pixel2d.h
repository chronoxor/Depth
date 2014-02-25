/*-----------------------------------------------------------------------------*\
| include file for Matpack graphics                                   pixel2d.h |
|                                                                               |
| Last change: Feb 12, 2002                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2002 by Berndt M. Gammel. All rights reserved.             |
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
#ifndef _pixel2d_h_
#define _pixel2d_h_

// include STL definitions
#include <iostream>

//----------------------------------------------------------------------------//
// class Pixel2D - pixel coordinate
//----------------------------------------------------------------------------//

namespace MATPACK {
using std::istream;
using std::ostream;

class Pixel2D {
  public:
    short px,py;
    Pixel2D (void) {}
    Pixel2D (short x, short y) : px(x), py(y) {}

    friend int operator == (const Pixel2D& p1, const Pixel2D& p2)
        { return (p1.px == p2.px) && (p1.py == p2.py); }
    
    friend int operator != (const Pixel2D& p1, const Pixel2D& p2)
        { return (p1.px != p2.px) || (p1.py != p2.py); }

    int read  (istream& is);
    int write (ostream& os) const;

    friend istream& operator >> (istream& is, Pixel2D &p) { 
      p.read(is); return is; 
    }

    friend ostream& operator << (ostream& os, const Pixel2D &p) {
      p.write(os); return os;
    }
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
