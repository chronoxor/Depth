/*-----------------------------------------------------------------------------*\
| Matpack X windows API: class MpScrollWindow                     mpscrollwin.h |
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


#ifndef _MPSCROLLWIN_H_
#define _MPSCROLLWIN_H_

#include "mphandle.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// class MpScrollWindow:
//     MpScrollWindow has a virtual window which can be scrolled
//     Arguments: real width/height, virtual width/height
//     Note: the virtual window must be derived from class MpVirtualWindow
//
// shifter_width <= 0 sets the width of the shifter to MpGlobal::ShifterWidth
//-----------------------------------------------------------------------------//

class MpClipWindow : public MpWindow  // auxilliary
{
  public:
    MpClipWindow (MpWindow& parent,
		  int w = 0, int h = 0, int x = 0, int y = 0, int border_width = 0)
      : MpWindow(parent,w,h,x,y,border_width) { }
    virtual bool GUIColorChange_CB (void) { return true; } 
    // return true to suppress automatic background redraw when GUI colors changed
    // this must be done explicitely by the parent scroll window
};

class MpScrollWindow : public MpWindow 
{
  private:
    MpClipWindow *clip_win; // the clipped region
    MpWindow *virt_win; // the virtual window
    int hvirt, wvirt;	// the virtual size
    int xp, yp;		// shifted position of virtual window
    int hvis,wvis;	// visible window size
    int ShifterWidth;   // width of shifter
    MpHandle<MpScrollWindow> *vs, *hs;	// vertical and horizontal shifter

    // same like in class MpCanvas
    int   FrameStyle;			// frame style as given by enums below
    short FrameWidth,			// width of frame
          FrameMidWidth;		// width of frame mid in box style
    bool  ScrollHorizontal, ScrollVertical;

    // hook called from shifters : shifts drawing area
    //    void cbhook (MpHandle *ts); 
    void cbhook (MpHandle<MpScrollWindow> *ts); 

  public:
    MpScrollWindow (MpWindow &parent, int w, int h, int wvirt, int hvirt, 
		    int x = 0, int y = 0, int shifter_width = 0);

    virtual ~MpScrollWindow() { }

    virtual void Resize(int w, int h);
    virtual void Redraw (void);

    int GetFrameWidth()    const { return FrameWidth; }
    int GetFrameMidWidth() const { return FrameMidWidth; }
    int GetFrameStyle ()   const { return FrameStyle; }
    int GetFrameType ()    const { return FrameStyle & MpCanvas::TypeMask; }
    int GetFrameShadow ()  const { return FrameStyle & MpCanvas::ShadowMask; }
    int GetFrameOutline()  const { return FrameStyle & MpCanvas::OutlineMask; }

    void SetFrameWidth (int width);
    void SetFrameMidWidth (int width);
    void SetFrameStyle (int style);
    
    MpClipWindow* GetClipWindow (void) { return clip_win; }
    MpWindow* GetVirtualWindow (void) { return virt_win; }
    void SetVirtualWindow (MpWindow* v) { virt_win = v; };

    void SetVirtualSize (int w, int h) { wvirt = w; hvirt = h; }
    int GetVirtualWidth  (void) const { return wvirt; }
    int GetVirtualHeight (void) const { return hvirt; }

    int GetVirtualXOffset (void) const { return xp; }
    int GetVirtualYOffset (void) const { return yp; }

    int GetViewportWidth (void) const { return wvis; }
    int GetViewportHeight (void) const { return hvis; }

    MpHandle<MpScrollWindow>* GetVerticalShifter (void) { return vs; }
    MpHandle<MpScrollWindow>* GetHorizontalShifter (void) { return hs; }
};


//-----------------------------------------------------------------------------//
// class MpVirtualWindow: 
//     Enable linking of a virtual window for MpScrollWindow. An instance 
//     of MpVirtualWindow must be defined for every MpScrollWindow.
//-----------------------------------------------------------------------------//

class MpVirtualWindow : public MpWindow 
{
  public: 
    MpVirtualWindow (MpScrollWindow *scr) 
	: MpWindow(*(scr->GetClipWindow()), 
		   scr->GetVirtualWidth(), 
		   scr->GetVirtualHeight(),0,0,0) // no borders
    { scr->SetVirtualWindow(this); }

    virtual ~MpVirtualWindow () { }
    virtual void Redraw () = 0;        // useless if it's not defined
    virtual void Resize (int, int) { } // don't do anything !
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
