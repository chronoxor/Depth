/*-----------------------------------------------------------------------------*\
| include file for Matpack class MpImage                              mpimage.h |
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
#ifndef _MPIMAGE_H_
#define _MPIMAGE_H_

//-----------------------------------------------------------------------------//
// common includes
//-----------------------------------------------------------------------------//

#include "common.h"     // first common definitions and machine dependencies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "color.h"      
#include "pixel2d.h"    


// Bit order parameter for MpImage::DitherizeBitPacked() 
#define LSBFirst 0 
#define MSBFirst 1

// line pattern buffer
#define LinePatternLength 16

// maximal number of characters in image file path (excluding closing '\0')
#define ImagePathLength 256 


//-----------------------------------------------------------------------------//
// include base class class MpImageBase
//-----------------------------------------------------------------------------//

#include "mpimagebase.h"

//-----------------------------------------------------------------------------//
// class MpImage
//-----------------------------------------------------------------------------//

namespace MATPACK {

class MpImage : public MpImageBase <byte>
{ 
  protected: 

    ImageChannelT R,G,B;                // current drawing color

    short LineThickness,                // current line style 
          LinePatternCnt,
          LinePatternSolid; 
    byte  LinePattern[LinePatternLength]; 

    char ImagePath[ImagePathLength+1];  // file path of image

    
    // private member functions
    void ThinLineSolid (int x1, int y1, int x2, int y2);
    void ThinLinePattern (int x1, int y1, int x2, int y2);
    void ThinLine (int x1, int y1, int x2, int y2); 
    void HorizontalLine (int,int,int); 
    friend void ScanOutAET (MpImage& image, int YToScan);

    void BuildGammaTable (ImageChannelT table[], 
                          ImageChannelT minval, ImageChannelT maxval, 
                          double gamma);

  public: 

    enum { BoundaryFill, TraceFill, DiagonalTraceFill };

    // public members
    MpImage (void);
    MpImage (int width, int length); 
    MpImage (const char* name);
    MpImage (const MpImage& source); 

    virtual ~MpImage (void) { this->MpImageBase<ImageChannelT>::~MpImageBase(); }
    virtual void Resize (int w, int l);

    void Get (int,int,ColorB&) const;
    ColorB Get (int,int) const;

    void Set (int,int,const ColorB&);
    void Set (int,int,byte,byte,byte); 
    void Set (int,int); 

    void Color (byte,byte,byte); 
    void Color (const ColorB&); 

    void SetBackground (byte,byte,byte); 
    void SetBackground (const ColorB&); 
    
    void Insert (const MpImage& source, 
                 int x = 0, int y = 0, int alpha = 128,
                 int sx = 0, int sy = 0, int sw = -1, int sh = -1);

    void InsertTiled (const MpImage& source, 
                      int x = 0, int y = 0, int alpha = 128,
                      int sx = 0, int sy = 0, int sw = -1, int sh = -1);

    void FloodFill (int seed_x, int seed_y, 
                    const ColorB& fill, const ColorB& bound, 
                    int mode = BoundaryFill,
                    int reg_x = 0,int reg_y = 0,int reg_w = -1,int reg_h = -1);

    int GammaCorrection (double red_gamma,double green_gamma,double blue_gamma,
                         int minval = 0, int maxval = -1);

    void InsertResize (const MpImage& source, int smooth = 0);
 
    void FlipHorizontal (void);
    void FlipVertical (void);

    void Line (int,int,int,int); 
    void LineStyle (int,int); 

    int Polygon (int Length, Pixel2D* VertexList, ColorB theColor,
                 int mode=Fill|Outline, int XOffset=0, int YOffset=0);

    void DrawLines (int,Pixel2D*,int=0,int=0);

    void Arc (int x,int y, int ra, int rb, int a, int b, int=Fill); 

    int  ReadPbmFile    (const char* name);
    int  WritePbmFile   (const char* name, bool raw=true); 
   
    int  ReadTiffFile   (const char* name);
    int  WriteTiffFile  (const char* name);
  
    int  ReadGifFile    (const char* name);
    int  WriteGifFile   (const char* name); 
  
    int  ReadPngFile    (const char* name, double gamma = 0.0,
                         const ColorB &background = ColorB(0,0,0));

    int  WritePngFile   (const char* name, double gamma = 1.0, int interlace = 0); 
  
    int  ReadJpegFile   (const char* name);

    int  WriteJpegFile  (const char* name, int quality = 80, int smoothing = 0);

    int  WritePostScriptFile (const char* name, float w=150.0, float h=150.0,
                              float=20.0,float=70.0, 
                              int compression = 0, bool eps = true); 

    int  ReadAnyFile    (const char* name); 

    void  SetPath (const char* name);
    const char* GetPath (void) const { return ImagePath; }

    int  Smooth (void);
    int  AddNoise (byte);
    int  FilterNoise (int window=5, float filter=2.5F, float reduction=1.2F);
    int  Monochrome (void);
    int  ColorQuantize (int,byte*,byte*,byte*,byte*);

    int  Ditherize (byte*,byte,byte);
    int  DitherizeBitPacked (byte*,byte,byte,int);

};
 
//-----------------------------------------------------------------------------//
// inline functions
//-----------------------------------------------------------------------------//

inline void MpImage::Get (int x, int y, ColorB& c) const
// 
// Get the RGB value of the pixel at (x,y). Boundary checking is  
// performed, that means nothing is returned for a pixel outside. 
// 
{ 
  if (y >= 0 && y < ImageLength && x >= 0 && x < ImageWidth) { 
    byte *p = ImageData + (long) y * ImageWidthX + 3 * x; 
    c.red = *p++; c.green = *p++; c.blue = *p; 
  } 
} 

inline ColorB MpImage::Get (int x, int y) const
// 
// Get the RGB value of the pixel at (x,y). Boundary checking is  
// performed, that means nothing is returned for a pixel outside. 
// 
{ 
  if (y >= 0 && y < ImageLength && x >= 0 && x < ImageWidth) { 
    const byte *p = ImageData + (long) y * ImageWidthX + 3 * x;
    return ColorB(p[0],p[1],p[2]);
  } else
    return ColorB(0,0,0);
} 

inline void MpImage::Set (int x, int y, const ColorB& c) 
// 
// Sets the pixel at (x,y) to the given RGB value. Boundary checking is  
// performed, that means 'clipping'. 
// 
{ 
    if (y >= 0 && y < ImageLength && x >= 0 && x < ImageWidth) { 
        byte *p = ImageData + (long) y * ImageWidthX + 3 * x; 
        *p++ = c.red; *p++ = c.green; *p = c.blue; 
    } 
} 
 

inline void MpImage::Set (int x, int y, byte r, byte g, byte b) 
// 
// Sets the pixel at (x,y) to the given RGB value. Boundary checking is  
// performed, that means 'clipping'. 
// 
{ 
    if (y >= 0 && y < ImageLength && x >= 0 && x < ImageWidth) { 
        byte *p = ImageData + (long) y * ImageWidthX + 3 * x; 
        *p++ = r; *p++ = g; *p = b; 
    } 
} 
 
 
inline void MpImage::Set (int x, int y) 
// 
// Sets the pixel at (x,y) to the current RGB value. Boundary checking is  
// performed, that means 'clipping'. 
// 
{ 
    if (y >= 0 && y < ImageLength && x >= 0 && x < ImageWidth) { 
        byte *p = ImageData + (long) y * ImageWidthX + 3 * x; 
        *p++ = R; *p++ = G; *p++ = B; 
    } 
} 
 
 
inline void MpImage::Color (byte r, byte g, byte b) 
// 
// Sets the current drawing color. 
// 
{ 
    R = r; G = g; B = b; 
} 

inline void MpImage::Color (const ColorB& c) 
// 
// Sets the current drawing color. 
// 
{ 
    R = c.red; G = c.green; B = c.blue; 
} 
 
 
inline void MpImage::HorizontalLine (int x1, int x2, int y) 
// 
// Draws a horizontal line from x1 to x2 at height y using  
// the current color. The line is solid with thickness 1. 
//  Boundary checking is performed. x2 >= x1 is required !
// 
{ 
    if (y >= 0 && y < ImageLength) { 
        if (x1 < 0) x1 = 0; 
        if (x2 >= ImageWidth) x2 = ImageWidth-1; 
        byte* p = ImageData + y * ImageWidthX + 3 * x1; 
        for (int x = x1; x <= x2; x++) { 
            *p++ = R; *p++ = G; *p++ = B; 
        } 
    } 
} 


//-----------------------------------------------------------------------------//
// prototypes
//-----------------------------------------------------------------------------//

void    RGB_to_HSV      (float R, float G, float B, float& H, float& S, float& V);
void    HSV_to_RGB      (float H, float S, float V, float& R, float& G, float& B);

void    CMYKtoRGB       (float,float,float,float,float&,float&,float&);
void    RGBtoCMYK       (float,float,float,float&,float&,float&,float&);

void    InitNoise       (long seed);
float   Noise           (float px, float py, float pz);
void    DNoise          (float& px, float& py, float& pz);
float   Turbulence      (float px, float py, float pz, float cutoff);

void    Turbulence      (MpImage&, float = 10.0, float = 0.0, 
                         ColorMap& = NoColorMap);

void    Crater          (MpImage&, int = 50000, double = 1.0, double = 1.5, 
                         long = 0, unsigned short **aux = 0);

void    Clouds          (MpImage&, double = 2.15, double = 0.75, int= 256, 
                         long = 0);

void    Planet          (MpImage&, double fracdim = 2.4, double powscale = 1.20, 
                         double scale = 0.75, double ice = 0.4, 
                         double glac = 0.75, double atthick = 1.03, 
                         int starfrac = 100, int starcol = 125, 
                         double hour = -1, double title = -1, 
                         int meshsize = 256, long myseed = 0);

void    Stars           (MpImage&, int =100, int = 125, long = 0);

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif

