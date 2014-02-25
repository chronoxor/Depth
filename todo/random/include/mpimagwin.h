/*-----------------------------------------------------------------------------*\
| Matpack X windows API - image windows                             mpimagwin.h |
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

#ifndef _MPIMAGWIN_H_
#define _MPIMAGWIN_H_

#include "mpscrollwin.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// class MpImageWindow: draw image (class MpImage) in a window
//-----------------------------------------------------------------------------//

class MpImageWindow: public MpCanvas
{
  private:
    bool hold;
    const MpImage* image;
    XImage* theXImage;

  protected:
    XImage* GetXImage (void) { return theXImage; }
    virtual void DestroyXImage (void);
    virtual void ConvertToXImage (const MpImage *img);
    virtual void MapXImage (void);
    virtual void RedrawPanel (void) { } // deactivate canvas panel clearing

  public:
    MpImageWindow (MpWindow &parent, const MpImage *source, 
                   int w, int h, int x = 0, int y = 0, 
                   bool hold = true); 
    virtual ~MpImageWindow (void);

    virtual void Resize (int w,int h);
    virtual void Redraw (void);

    void SetImage (const MpImage *source);
    const MpImage* GetSourceImage (void);

    void SetHold (bool val);
    bool GetHold (void) const;
};

//-----------------------------------------------------------------------------//
// class MpResizeImageWindow:
// This class is derived from class MpImageWindow. It supports automatic
// smooth resizing of the image, e.g.  when the window frame is dragged. 
// The base class MpImageWindow doesn't resize its image automatically if the 
// window is resized.
//-----------------------------------------------------------------------------//

class MpResizeImageWindow: public MpImageWindow 
{
  private:
    bool SmoothResize;     // flag to set for smooth resize
    MpImage WorkImage;     // hold working copy for resizing
    const MpImage *source; // pointer to original image

  public:
    MpResizeImageWindow(MpWindow &parent, const MpImage *source, 
                        int w, int h, int x = 0, int y = 0, 
                        bool SmoothResize = 0);
    virtual ~MpResizeImageWindow (void) { }

    virtual void Resize (int w, int h);

    void SetImage (const MpImage *source);
    const MpImage* GetSourceImage (void);

    MpImage* GetWorkImage (void); // get pointer to resized working copy

    void SetSmoothResize (bool val);
    bool GetSmoothResize (void) const;
};

//-----------------------------------------------------------------------------//
// class MpScrollImageBase:
//-----------------------------------------------------------------------------//

class MpScrollImageWindow;

class MpScrollImageBase: public MpWindow 
{ 
  public:
    MpScrollImageWindow *top; // back link, necessary for calling the overloadable DrawCanvas()

    MpImage* image;
    XImage* theXImage;
    int hold, init;
    
    MpScrollImageBase (MpScrollImageWindow *top,
                       MpScrollWindow *parent, MpImage& image, 
                       int hold, int init);

    virtual void DestroyXImage (void);
    virtual void ConvertToXImage (MpImage& img);
    virtual void MapXImage (void);
    virtual void Redraw (void);
    virtual void Resize (int, int) { /* do not resize */ }

    virtual ~MpScrollImageBase (void) { DestroyXImage(); }    
};

//-----------------------------------------------------------------------------//
// class MpScrollImageWindow: 
// This class which attaches scrollbars to an image if neccessary, i.e. if
// the window is resized.
//
// shifter_width <= 0 sets the width of the shifter to MpGlobal::ShifterWidth
//-----------------------------------------------------------------------------//

class MpScrollImageWindow: public MpWindow 
{
  public:    
    MpScrollWindow* frame;
    MpScrollImageBase* canvas;
    
    MpScrollImageWindow (MpWindow& parent, MpImage& image,
                         int w, int h, int x = 0, int y = 0, 
                         int shifter_width = 0, int bw = 0, int init = true);

    virtual void Configure (MpImage& image); // shouldn't be virtual
    virtual void DrawCanvas (void) { }       // callback for overloading
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
