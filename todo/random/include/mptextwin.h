/*-----------------------------------------------------------------------------*\
| Matpack X windows API   text viewer windows                       mptextwin.h |
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

#ifndef _MPTEXTWIN_H_
#define _MPTEXTWIN_H_

#include "mphandle.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// class MpTextWindow: window to display a clipped portion of text
//-----------------------------------------------------------------------------//

class MpTextWindow : public MpWindow 
{
  private:  
    const char *buffer_first;             // start of buffer
    const char **line_starts;             // the vector of line beginnings
    int   display_lines,                  // lines displayed in window
          shift_lines;                    // line shifting
    const XFontStruct* font;
    void Init (const char *buf, int nc);

  public:
    int line_height,                      // pixel height of a line
        num_lines;                        // num_lines number of total lines

    MpTextWindow(MpWindow &parent, int w, int h, int x, int y, 
                 const char *buf, int nc);
    virtual ~MpTextWindow (void);

    void Reset (const char *buf, int nc);   
    void Redraw (void); 
    virtual bool GUIColorChange_CB (void);
    virtual void Resize (int w, int h); 
    void DrawTextLine (int y, const char *lp);
    void shift (int i); 
    float move (float z);
    float jmp (int up);
    float jmp1 (int up);
    void SetFont (const XFontStruct* fn = 0);
};

//-----------------------------------------------------------------------------//
// class MpTextScrollbar: scrollbar with specialized callback for text scrolling
//-----------------------------------------------------------------------------//

class MpTextScrollbar : public MpVerticalScrollbar 
{
  private:
    MpTextWindow *tw;

  public:
    MpTextScrollbar(MpWindow &parent, int w, int h, int x, int y, int sh, 
                   MpTextWindow *tw) :
        MpVerticalScrollbar(parent, w, h, x, y, sh), tw(tw) {}

    // replaces callback form MpVerticalScrollbar
    // 1. moves the text window, then sets the slider relative
    virtual void move_callback (int y) 
    { 
        if (yspan) SetSliderRelative( tw->move(y/float(yspan)) ); 
    } 

    virtual void jmp_callback (int up) 
    { 
        SetSliderRelative(tw->jmp(up));
    }

    virtual void jmp1_callback (int up) 
    { 
        SetSliderRelative(tw->jmp1(up));
    }
};

//-----------------------------------------------------------------------------//
// class MpTextViewerWindow: is a MpTextWindow with an attached scrollbar
//-----------------------------------------------------------------------------//

class MpTextViewerWindow : public MpWindow 
{
  private:
    MpTextScrollbar *vs;
    MpTextWindow *tw;

  public: 
    int slider_height (int zz);
    void Reset (const char *buf, int nc);
    MpTextWindow *TextWindow (void) const { return tw; }
    MpTextScrollbar *Scrollbar (void) const { return vs; }
    MpTextViewerWindow(MpWindow &parent, int w, int h, int x, int y, 
                       const char *buf, int nc, int bw = 0);
    virtual void KeyPress_CB (XKeyEvent ev);
    virtual void Resize (int w, int h);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
