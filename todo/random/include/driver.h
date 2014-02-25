/*-----------------------------------------------------------------------------*\
| Matpack Library  - graphics driver prototypes                	       driver.h |
|       							      		|
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

#ifndef _DRIVER_H
#define _DRIVER_H 1

namespace MATPACK {

// define a color cell entry for a color table (inspired by X11)
// -------------------------------------------------------------
typedef struct {
    byte red,green,blue;     // rgb intensities 0..255
    unsigned long pixel;     // the pixel value code
    short shade;             // internal pointer for colortable lookup
} ColorDef;

extern ColorDef ColorTable[MaxColor+1];

// inlines
// -------

inline float RGBintensity (short color)
//
// Computes the grayscale intensity of a given RGB value (with 0 <=r,g,b<=255)
// according to the NTSC standard, that is i = 0.30*r+0.59*g+0.11*b
// This inline is used in the following driver include files
//
{
    ColorDef& c = ColorTable[color];
    return 0.9999F/255.0F * (0.30F * c.red + 0.59F * c.green + 0.11F * c.blue);        
}


// dummy drivers for devices that have not this feature
// ----------------------------------------------------

void DUMMY_Flush    (Scene&);
void DUMMY_ColorMap (Scene&,short,short,short,short,short&);
void DUMMY_PutImage (Scene&,MpImage&,int);

// the class Image drivers
// ------------------------------

void IM_Open		(Scene&,const char*,int,int,int,int,int&);
void IM_Close		(Scene&);
void IM_Line		(Scene&,Pixel2D,Pixel2D);
void IM_Dot		(Scene&,Pixel2D);
void IM_Arc		(Scene&,Pixel2D,int,int,int,int,int);
void IM_LineStyle  	(Scene&,short,short);
void IM_Color		(Scene&,long,short);
void IM_Polygon	        (Scene&,short,Pixel2D*,long,short);
void IM_Clear		(Scene&);
void IM_PutImage	(Scene& scene, MpImage& image, int tile);

// the class MpWindow drivers
// ------------------------------
void MP_Open		(Scene&,const char*,int,int,int,int,int&);
void MP_Close		(Scene&);
void MP_Line		(Scene&,Pixel2D,Pixel2D);
void MP_Dot		(Scene&,Pixel2D);
void MP_Arc		(Scene&,Pixel2D,int,int,int,int,int);
void MP_LineStyle  	(Scene&,short,short);
void MP_Color		(Scene&,long,short);
void MP_Polygon	        (Scene&,short,Pixel2D*,long,short);
void MP_Clear		(Scene&);
void MP_Flush		(Scene&);
void MP_PutImage	(Scene& scene, MpImage& image, int tile);

// the PostScript drivers
// ----------------------
void PS_Open		(Scene&,const char*,int,int,int,int,int&);
void LPS_Open		(Scene&,const char*,int,int,int,int,int&);
void PSBW_Open		(Scene&,const char*,int,int,int,int,int&);
void LPSBW_Open		(Scene&,const char*,int,int,int,int,int&);
void PS_Close		(Scene&);
void PS_Line		(Scene&,Pixel2D,Pixel2D);
void PS_Dot		(Scene&,Pixel2D);
void PS_Arc		(Scene&,Pixel2D,int,int,int,int,int);
void PS_LineStyle  	(Scene&,short,short);
void PS_Color		(Scene&,long,short);
void PS_Polygon		(Scene&,short,Pixel2D*,long,short);
void PS_Clear		(Scene&);
void PS_PutImage	(Scene& scene, MpImage& source, int tile);

// the Postscript color image drivers
// ----------------------------------
void PSI_Open		(Scene&,const char*,int,int,int,int,int&);
void PSI_Close		(Scene&);

// the Tiff drivers
// ----------------
void TIFF_Open		(Scene&,const char*,int,int,int,int,int&);
void TIFF_Close		(Scene&);

// the Gif drivers
// ----------------
void GIF_Open		(Scene&,const char*,int,int,int,int,int&);
void GIF_Close		(Scene&);

// the Pbm drivers
// ----------------
void PBM_Open		(Scene&,const char*,int,int,int,int,int&);
void PBM_Close		(Scene&);

// the Jpeg drivers
// ----------------
void JPEG_Open		(Scene&,const char*,int,int,int,int,int&);
void JPEG_Close		(Scene&);

} // namespace MATPACK

#endif
