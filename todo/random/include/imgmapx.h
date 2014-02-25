/*-----------------------------------------------------------------------------*\
| part of the Matpack driver for X Window 11 graphics                 imgmapx.h |
| for X Window Version 11 Release 5	          			        |
|       								        |
| Copyright (c) 1992-1995 by Berndt M. Gammel                                   |
|                                                                               |
| Permission to use, copy, modify, and distribute this software and its         |
| documentation for any purpose and without fee is hereby granted,              |
| provided that the above copyright notice appear in all copies and that        |
| both that copyright notice and this permission notice appear in               |
| supporting documentation. This software is provided "as is" without           |
| express or implied warranty.                                                  |
|                                                                               |
\*-----------------------------------------------------------------------------*/

//#define DEBUG


//-----------------------------------------------------------------------------//
// Function prototypes for file "imgmapx.cpp"
//-----------------------------------------------------------------------------//

inline byte Monochrome (byte r, byte g, byte b);
  
inline int ForceRange (int& a, int b, int c);

inline int highbit (unsigned long ul);

static byte* FloydDitherize_8_Bit (byte *pic24, 
				   int width, int height, 
				   int bval, int wval);

static void FloydDitherize_1_Bit (XImage *ximage, byte* pic24, 
				  int width, int height,
				  unsigned long theBlackPixel, 
				  unsigned long theWhitePixel);

static byte* FloydColorDitherize_332_Bit (byte* pic24, 
					  int width, int height, 
					  byte* RedMap, byte* GreenMap, byte* BlueMap);

XImage* MapImageToX (Image& theImage, 
		     Display* theDisplay, Visual* theVisual, int theDepth,
		     int theNumberOfColors,
		     byte* RedMap, byte* GreenMap, byte* BlueMap, 
		     unsigned long* PixValMap,
		     unsigned long theBlackPixel, 
		     unsigned long theWhitePixel,
		     int* DirectMap);



