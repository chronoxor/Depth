/*-----------------------------------------------------------------------------*\
| Matpack - Marker definitions for plotting                            mpmark.h |
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

#ifndef _MPMARK_H_
#define _MPMARK_H_

#include "scene.h"
#include "vector.h"

//-----------------------------------------------------------------------------//

namespace MATPACK {

class MpMark
{
  protected:

    int    style, 	// Fill and/or Outline
           symbol;	// Symbol enumeration type
    double symsize,	// symbol size
           xerrsize,	// errorbar size
           yerrsize;    
    long   fillcolor; 
  
  public:

    enum Symbol {
      Point = 0,	// lines
      Plus,
      Ex,
      Asterisk,
      Circle,   	// polygonal shapes, can be filled and/or outlined
      Square,       
      Diamond,      
      TriangleUp,   
      TriangleDown, 
      TriangleLeft, 
      TriangleRight,
      Starlet,
      Tie,
      SandClock,
      Cross
    };

  enum { MaxSymbol = Cross }; // symbol indices are within [0,MaxSymbol]

  MpMark (void) 
    : style(Outline),symbol(Point),symsize(1),
      xerrsize(1),yerrsize(1),fillcolor(0) { }

  void SetSymbolSize   (double s)             { symsize = s; }
  void SetErrorbarSize (double sx, double sy) { xerrsize = sx; yerrsize = sy; }
  void SetStyle        (int s)                { style = s; }
  void SetSymbol       (int s)                { symbol = s; }
  void SetFillColor    (long f)               { fillcolor = f; }

  void DrawMarks (Scene& scene, 
		  const Vector &x, const Vector &y, 
		  const Vector &dX = NullVector,
		  const Vector &dy = NullVector);
};
 
} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
