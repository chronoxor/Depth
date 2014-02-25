/*-----------------------------------------------------------------------------*\
| Matpack X windows application programming interface                 mpcolor.h |
| include file for class MpColor                                                |
|                                                                               |
| Last change: Oct 29, 2005                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel                                   |
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

#ifndef _MPCOLOR_H_
#define _MPCOLOR_H_

//----------------------------------------------------------------------------//

// include STL definitions
#include <string>
#include <iostream>

#include "common.h"
#include "mpdevice.h"

namespace MATPACK {
using std::string;
using std::istream;
using std::ostream;

//----------------------------------------------------------------------------//
// class MpColor
//----------------------------------------------------------------------------//

class MpColor
{
  public:
    typedef unsigned long pixel_t;     // X11 compatible pixel value type

    enum ColorSpace { RGB, HSV };

    // construct color with RGB=(0,0,0) and alpha=255. The color is not
    // yet set up for the underlying graphics system, i.e. the pixel
    // value is not yet valid
    MpColor (void);

    //------------------------------------------------------------------------//
    // Constructor:
    //   MpColor::MpColor (int x, int y, int z, 
    //                     ColorSpace s = RGB, int alpha = 0xff);
    //
    // The meaning of the arguments x,y,z depends on selected color space as
    // given by the argument ColorSpace s.
    //
    // ColorSpace s = HSV
    // ------------------
    // The Hue/Saturation/Value system (or also called Hexcone model) was
    //  created by Smith in 1978. It was for an aesthetic purpose, accessing
    //  color by family, purety and intensity rather than by its component.
    //
    //  The H value is a 360 degree value (modulo 360) through color families.
    //   where
    //       H  =   0 ... 60 ...  120 ... 180 ... 240 ... 300      ... 360
    //              red   yellow  green   cyan    blue    magenta      red
    //
    //  The S (or Saturation) is the degree of strength of a color. Greater is
    //  S, the purest is the color. If S max is 1, then Hue = red and S = 1 
    //  would produce an intense red (reproduced by RGB (max,0,0)) .
    //  S is the saturation in the range 0 <= S <= 1 where S = 0 means
    //  lowest saturation, i.e. gray with a value defined by V.
    // 
    //  Finally, the V, for value, is the darkness/lightness of a color. More
    //  V is great, more the color is close to white. V is the brightness 
    //  in the range 0 <= V <= 1 where V = 0 means lowest brightness, 
    //  i.e. black. Highest brilliance is reached with with S = V = 1.
    //  
    //  The arguments to the constructor MpColor::MpColor are defined as
    //    x in the range 0..360*64  (23040) correponding to H = hue in degrees * 64, 
    //    y in the range 0...0xffff (65535) correponding to S = saturation 0...1
    //    z in the range 0...0xffff (65535) correponding to V = value 0...1     
    //
    // ColorSpace s = RGB
    // ------------------
    // The arguments to the constructor MpColor::MpColor are defined as
    //
    //    x in the range 0...0xffff (65535) corresponding to red (R)
    //    y in the range 0...0xffff (65535) corresponding to green (G)
    //    z in the range 0...0xffff (65535) corresponding to blue (B)
    //
    // alpha = 0xff
    // ------------
    // The alpha value in the range 0..0xff (255) defines the opacity of
    // the color in several image operations (overpainting, blending)
    // The default value of alpha = 0xff menas completly opaque and a 
    // value of alpha = 0 means completely transparent.
    //
    //------------------------------------------------------------------------//

    MpColor (int x, int y, int z, ColorSpace s = RGB, int alpha = 0xff);

    //------------------------------------------------------------------------//
    // Constructor:
    //   MpColor::MpColor (const string &name, int alpha = 0xff);
    //
    // The color name may be in one of five formats.
    // (each of R, G and B is a single hex digit)
    //
    // 1.  #RGB         
    // 2.  #RRGGBB
    // 3.  #RRRGGGBBB
    // 4.  #RRRRGGGGBBBB
    // 5.  A named from the X color data base (rgb.txt),  e.g.
    //     "steelblue" or "AliceBlue". If there is no X server connection
    //     we can also work with color names: In this case we look up the 
    //     color name in the MATPACK data base $MATPACK/cmaps/color.tbl
    //
    // Note, that the definition of colors by conventional names (format 5)
    // is not recommended, because it requires a slow data base access. 
    //------------------------------------------------------------------------//
      
    MpColor (const string &name, int alpha = 0xff);

    //------------------------------------------------------------------------//
    // Member Function:
    //   void MpColor::SetRGBA (int r, int g, int b, int a = 0xff);
    //
    // set current color to the given RGB color values and set the alpha value
    //    r in the range 0...0xffff (65535) corresponding to red 
    //    g in the range 0...0xffff (65535) corresponding to green
    //    b in the range 0...0xffff (65535) corresponding to blue
    //    a in the range 0...0xff   (255)   corresponding to alpha
    //
    // the floating point version takes normalized arguments in the range 0..1
    //
    //------------------------------------------------------------------------//

    void SetRGBA (int r, int g, int b, int a = 0xff);
    void SetRGBA (float r, float g, float b, float a = 1.0);

    //------------------------------------------------------------------------//
    // Member Function:
    //   void SetHSVA (int h, int s, int v, int a = 0xff);
    //
    //  set current color to the given HSV color values and set the alpha value
    //    h in the range 0..360*64  (23040) correponding to hue in degrees * 64,
    //    s in the range 0...0xffff (65535) correponding to saturation 0...1
    //    v in the range 0...0xffff (65535) correponding to value 0...1     
    //
    // the floating point version takes h in the range 0..360 (mod 360) and
    // normalized arguments s and v in the range 0..1
    //
    //------------------------------------------------------------------------//

    void SetHSVA (int h, int s, int v, int a = 0xff);
    void SetHSVA (float h, float s, float v, float a = 1.0);


    // set alpha value without changing the color
    void SetAlpha(int a);

    // return the current R, G, B, and Alpha value, respectively
    int Red()   const;
    int Green() const;
    int Blue()  const;
    int Alpha() const;

    // color is valid/allocated
    bool Valid() const;
    bool Allocated() const;

    // return the pixel value (forces allocation if not yet allocated)
    pixel_t Pixel() const;

    //------------------------------------------------------------------------//
    // force allocation of the pixel value, a default pixel value "default_pixel"
    // can be given which is used if the color cannot be allocated within the
    // given distance in the color space "color_dist". color_dist = 0 means an
    // exact allocation is required, otherwise the default is used.
    //------------------------------------------------------------------------//

    pixel_t AllocateColor (pixel_t default_pixel, int color_dist = -1);

    // Colors are equal if the RGB components and the allocated pixel
    // values are equal. The alpha value is not considered in the comparison.
    friend bool operator == (const MpColor& x, const MpColor& y);
    friend bool operator != (const MpColor& x, const MpColor& y);

    // write color definition to stream in plain text format:
    //   MpColor(<r>,<g>,<b>,<a>)
    friend ostream& operator << (ostream& s, const MpColor& x);

    // read color definition string in above format
    friend istream& operator >> (istream& s, MpColor& x);

  private:
    pixel_t  pix;    // device dependent pixel value (e.g. X11, PostScript)

    uint32_t flar,gb; // flar  = 8 bit flags | 8 bit alpha | 16 bit red
                      // gb   = 16 bit green | 16 bit blue

    // mask constants for flags
    static const uint32_t ValidFlag, AllocFlag, DirectFlag;

    // pointer to underlying graphics device descriptor
    friend class MpX11Device;
    friend class MpPSDevice;
    static const MpDevice *Dev;
    static void SetDevice (const MpDevice *d) { MpColor::Dev = d; }
};

//----------------------------------------------------------------------------//

inline int MpColor::Red()   const { return flar & 0xffff;   }
inline int MpColor::Green() const { return (gb >> 16) & 0xffff; }
inline int MpColor::Blue()  const { return gb & 0xffff;  }
inline int MpColor::Alpha() const { return (flar >> 16) & 0xff; }

//----------------------------------------------------------------------------//

// return the pixel value
inline MpColor::pixel_t MpColor::Pixel () const
{
  return (flar & AllocFlag) 
          ? pix                    // color is allocated, return pixel value
          : ((MpColor*)this)->AllocateColor(0); // do allocation 
} 

//----------------------------------------------------------------------------//

inline void MpColor::SetAlpha (int a)
{ 
  flar = (flar & 0xff00ffff) | ((a & 0xff) << 16); 
}

inline bool MpColor::Valid() const
{
  return (flar & ValidFlag);
}

inline bool MpColor::Allocated() const
{
  return (flar & AllocFlag);
}

//----------------------------------------------------------------------------//
// Colors are equal if the RGB components are equal. 
// The alpha value is not considered.
//----------------------------------------------------------------------------//

inline bool operator == (const MpColor& x, const MpColor& y)
{
  return ((x.flar & 0xffff) == (y.flar & 0xffff)) && (x.gb == y.gb);
  // check valid flags !!
}

//----------------------------------------------------------------------------//

inline bool operator != (const MpColor& x, const MpColor& y)
{
  return ! operator == (x,y);
}

} // namespace MATPACK

//----------------------------------------------------------------------------//

#endif
