/*-----------------------------------------------------------------------------*\
| Matpack graphics kernel - class MpAxis                               mpaxis.h |
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
#ifndef _MPAXIS_H_
#define _MPAXIS_H_

#include <string>

#include "mp3dplots.h"

namespace MATPACK {

class MpContextSave;

//----------------------------------------------------------------------------//
// class MpAxis - define layout of axis and draw to scene
//----------------------------------------------------------------------------//

class MpAxis: public MpBase
{
  public:    
    enum { Automatic=-1, Parallel=0, Orthogonal=1, Horizontal=2, Vertical=4 };

    MpAxis (void);      

    double LogBase;
    bool   AxisShow;

    bool   LabelShow,
           LabelOpposite;
    int    LabelDirection, // see enum above
           LabelFont,    
           LabelWidth;
    double LabelSize,
           LabelMin,
           LabelMax,
           LabelZero;
    ColorF LabelColor;
    string LabelFormat;

    bool   TitleShow;
    int    TitleFont,
           TitleWidth;
    double TitleSize,
           TitleOffset;
    ColorF TitleColor;
    string Title;

    bool   TickOpposite;
    int    TickMajorNum,
           TickMajorWidth,
           TickMinorNum,
           TickMinorWidth;
    double TickMajorLength,
           TickMinorLength;

    int    AxisBarWidth;
    ColorF AxisBarColor;
    string AxisBarArrowLabel;

    // draw in viewport pixel coordinates
    void  Draw (Scene& scene,
                const Pixel2D& p1, const Pixel2D& p2);

    // draw in 2-dim coordinate frame
    void  Draw (Scene& scene,
                double x1, double y1, double x2, double y2);

    // draw in 3-dim coordinated frame
    void  Draw (Scene& scene,
                double x1, double y1, double z1,
                double x2, double y2, double z2);

   // stream i/o functions
   int read  (istream& is);
   int write (ostream& os) const;

  private:

    // helper function
    void DrawAxis (Scene& scene,int threedim, 
                   const Pixel2D& p1,const Pixel2D& p2,
                   double x1,double y1,double z1,double x2,double y2,double z2);

    void DefineContext (MpContextSave *ctx) const;
};

} // namespace MATPACK

//----------------------------------------------------------------------------//

#endif
