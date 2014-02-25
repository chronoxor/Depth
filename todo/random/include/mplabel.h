/*-----------------------------------------------------------------------------*\
| Matpack X windows API: class MpLabel                                mplabel.h |
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

#ifndef _MPLABEL_H_
#define _MPLABEL_H_

#include <string>
#include "mpwindow.h"

//-----------------------------------------------------------------------------//

namespace MATPACK {
using std::string;

class MpLabel: public MpCanvas
{
  private:

    string text;                // the text string
    const XFontStruct* font;    // current font
    unsigned short mode;        // text drawing mode
    short tx,ty;                // horizontal and vertical padding values

  protected:

    virtual void Draw (void)    // draw text
    {
      PlaceText (text.c_str(),
		 tx + GetFrameTotalWidth(),
		 ty + GetFrameTotalWidth(), 
		 (XFontStruct*) font, mode); 
    }

  public:

    //-------------------------------------------------------------------------//
    // Description:
    //   Flag bits for text drawing modes. When testing a value always use
    //   an expression like
    //
    //   if ((mode & TextModeMask) == compare_value) { ... }
    //
    //-------------------------------------------------------------------------//
    enum { Plain        = 0,        // plain characters (default)
           Etched       = 0x0100,   // etched (sunken) appearance
           Embossed     = 0x0200,   // embossed (raised) appearance
           TextModeMask = 0x0f00    // maske for flags
         };

    //-------------------------------------------------------------------------//
    // Constructor:
    //    MpLabel (MpWindow &parent, const string &text, int w, int h, 
    //             int x = 0, int y = 0,
    //             const XFontStruct *font = Mp.theFont,
    //             int mode = Plain | AlignHCenter | AlignVCenter, 
    //             int padx = 0, int pady = 0);
    //
    // Description:
    //   Instatiate a label with a given text string
    //   The width and height of the label is given by w and h, respectively.
    //   The optional top left corner position is given by (x,y). 
    //
    //   Optionally a font can be given. 
    //
    //   The mode parameter can be composed of the text mode flags 
    //   
    //       MpLabel::(Plain, Etched, Embossed) 
    //
    //   and the alignment flags defined in class MpBase
    //
    //       MpBase::(AlignHCenter, AlignLeft, AlignRight, 
    //                AlignVCenter, AlignTop, AlignBottom, AlignBase).
    //
    //   For a description see also "void SetMode (int mode);"
    //
    //   The optional padx and pady parameters can be used define an additional
    //   horizontal and vertical padding.
    //-------------------------------------------------------------------------//
    MpLabel (MpWindow &parent, const string &text, int w, int h, 
             int x = 0, int y = 0,
             const XFontStruct *fn = Mp.theFont,
             int mode = Plain | AlignHCenter | AlignVCenter, 
             int padx = 0, int pady = 0) 
      : MpCanvas(parent,w,h,x,y,MpCanvas::Flat), 
        text(text), font(fn), mode(mode) , tx(padx), ty(pady) { }

    //-------------------------------------------------------------------------//
    // Destructor:
    //   virtual ~MpLabel  (void)
    //
    // Description:
    //   Empty destructor for overloading purposes
    //-------------------------------------------------------------------------//
    virtual ~MpLabel  (void) { }

    //-------------------------------------------------------------------------//
    // Member Function:
    //   void SetPadding (int padx, int pady);
    //   int  GetXPadding (void) const;
    //   int  GetYPadding (void) const;
    //
    // Description:
    //   Change the padding value (default is 0 pixel). The padding value
    //   denotes the additional horizontal (vertical) offset of 
    //   the label from the frame.
    //-------------------------------------------------------------------------//
    void SetPadding (int padx, int pady) { tx = padx; ty = pady; }
    int  GetXPadding (void) const { return tx; }
    int  GetYPadding (void) const { return ty; }

    //-------------------------------------------------------------------------//
    // Member Function:
    //   virtual void Redraw (void);
    //
    // Description:
    //   Overloaded. Draw canvas and text.
    //-------------------------------------------------------------------------//
    virtual void Redraw (void) 
    {
      MpCanvas::RedrawPanel(); 
      Draw(); 
      MpCanvas::RedrawFrame(); 
    } 

    //-------------------------------------------------------------------------//
    // Member Function:
    //   virtual void Set (const string &text);
    //   virtual string Get (void) const;
    //
    // Description:
    //   Set the label text string and get a copy of the label text string.
    //-------------------------------------------------------------------------//
    virtual void Set (const string &val) { text = val; Redraw(); }
    virtual string Get (void) const { return text; }

    //-------------------------------------------------------------------------//
    // Member Function:
    //   string &RefText (void);
    //   const string &RefText (void);
    //
    // Description:
    //   Return reference to the text string of the label.
    //-------------------------------------------------------------------------//
    string &RefText (void) { return text; }
    const string &RefText (void) const { return text; }

    //-------------------------------------------------------------------------//
    // Member Function:
    //   void  SetFont (const XFontStruct* font);
    //   const XFontStruct* GetFont (void) const;
    //
    // Description:
    //   Set and get font
    //-------------------------------------------------------------------------//
    void  SetFont (const XFontStruct* font);
    const XFontStruct* GetFont (void) const { return font; };

    //-------------------------------------------------------------------------//
    // Member Function:
    //   void SetMode (int mode);
    //   int  GetMode (void) const;
    //
    // Description:
    //   Set and get the mode flags. The mode parameter can be composed of 
    //   the text mode flags of class MpLabel
    //
    //      MpLabel::( Plain, Etched, Embossed ) 
    // 
    //   and the alignment flags defined in class MpBase
    //
    //      MpBase::( AlignHCenter, AlignLeft, AlignRight,
    //                AlignVCenter, AlignTop,  AlignBottom, AlignBase ).
    //
    //   Example:
    //       SetMode( AlignHCenter | AlignVCenter | Embossed );
    //
    //-------------------------------------------------------------------------//
    void SetMode (int val) { mode = val; Redraw(); }
    int  GetMode (void) const { return mode; }
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
