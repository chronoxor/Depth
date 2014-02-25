/*-----------------------------------------------------------------------------*\
| include file for Matpack graphics                                     color.h |
| find impementation in "source/Image/color.cpp"                                |
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
#ifndef _color_h_
#define _color_h_

// include STL definitions
#include <iostream>
#include "common.h"

namespace MATPACK {
using std::istream;
using std::ostream;

class ColorF;
class ColorB;

//----------------------------------------------------------------------------//
// class ColorB - RGB color components in three 8 bit unsigned char [0...255] //
//----------------------------------------------------------------------------//

class ColorB {
    
  public:
    byte red,green,blue;

    ColorB (void) {}
    ColorB (byte r, byte g, byte b) : red(r), green(g), blue(b) {}
    ColorB (const ColorF& c);
    ColorB (const char*);

    friend int operator == (const ColorB& a, const ColorB& b)
        { return (a.red==b.red) && (a.green==b.green) && (a.blue==b.blue); }

    friend int operator != (const ColorB& a, const ColorB& b)
        { return (a.red!=b.red) || (a.green!=b.green) || (a.blue!=b.blue); }

    int read  (istream& is);
    int write (ostream& os) const;

    friend istream& operator >> (istream& is, ColorB &p) { 
      p.read(is); return is; 
    }

    friend ostream& operator << (ostream& os, const ColorB &p) {
      p.write(os); return os;
    }
};

//----------------------------------------------------------------------------//
// class ColorF - RGB color components in three floats [0.0...1.0]            //
//----------------------------------------------------------------------------//

class ColorF {
    
  public:
    float red,green,blue;

    ColorF (void) {}
    ColorF (float r, float g, float b) : red(r), green(g), blue(b) {}
    ColorF (const ColorB& c);

    friend int operator == (const ColorF& a, const ColorF& b)
        { return (a.red==b.red) && (a.green==b.green) && (a.blue==b.blue); }

    friend int operator != (const ColorF& a, const ColorF& b)
        { return (a.red!=b.red) || (a.green!=b.green) || (a.blue!=b.blue); }

    int read  (istream& is);
    int write (ostream& os) const;

    friend istream& operator >> (istream& is, ColorF &p) { 
      p.read(is); return is; 
    }

    friend ostream& operator << (ostream& os, const ColorF &p) {
      p.write(os); return os;
    }
};

//----------------------------------------------------------------------------//
// type casts
//----------------------------------------------------------------------------//

inline ColorB::ColorB (const ColorF& c) 
{ 
    red = (byte)(255*c.red);
    green = (byte)(255*c.green);
    blue = (byte)(255*c.blue); 
}

inline ColorF::ColorF (const ColorB& c) 
{ 
    red = c.red/255.0; 
    green = c.green/255.0; 
    blue  = c.blue/255.0; 
} 

//----------------------------------------------------------------------------//
// class ColorMap - defines a color map                                       //
//----------------------------------------------------------------------------//

class ColorMap {

  private:
    int ncol;       // number of colors
    ColorB* color;  // vector of colors [0..ncols-1]

  public:
    ColorMap (void) { ncol = 0; color = 0; } 
    ColorMap (int n){ ncol = n; color = new ColorB[n]; }

   ~ColorMap (void) { if (color) delete[] color; ncol = 0; color = 0; }

    int Load (istream& fin);
    ColorMap (istream& fin) { ncol = 0; color = 0; Load(fin); } 
    int Load (const char* fname);
    ColorMap (const char* fname) { ncol = 0; color = 0; Load(fname); } 

    int Save (ostream& fout) const;
    int Save (const char* fname) const;

    void Remove (void) { this->ColorMap::~ColorMap(); }

    // indexing
    ColorB& operator [] (int n) { 
#if defined(DEBUG) || defined (IndexRangeChecking) || defined (ColorMapIndexRangeChecking)
        if (n < 0 || n >= ncol)
          Matpack.Error("ColorMap: index out of range (%d)", n);        
#endif
        return color[n]; 
    } 

    const ColorB& operator [] (int n) const {   // reading of element only
#if defined(DEBUG) || defined (IndexRangeChecking) || defined (ColorMapIndexRangeChecking)
        if (n < 0 || n >= ncol)
          Matpack.Error("ColorMap: index out of range (%d)", n);        
#endif
        return color[n]; 
    } 

    operator int  () const { return (ncol > 0); } 
    int operator !() const { return (ncol <= 0); }
    ColorMap& operator = (const ColorMap& cmap);
    int Size (void) const { return ncol; } 
    void Reverse (void);
};

//-----------------------------------------------------------------------------//
// externals
//-----------------------------------------------------------------------------//

// default empty colormap
extern ColorMap NoColorMap;

} // namespace MATPACK

#endif

//-----------------------------------------------------------------------------//
