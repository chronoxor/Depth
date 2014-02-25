/*-----------------------------------------------------------------------------*\
| Matpack X windows API: class MpLineEdit                          mplineedit.h |
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

#ifndef _MPLINEEDIT_H_
#define _MPLINEEDIT_H_

#include "mplabel.h"
#include <string>

namespace MATPACK {

//-----------------------------------------------------------------------------//
// class MpLineEdit: edit strings
//   Three virtual functions can be defined in derived classes:
//   Enter       - action on completion (e.g. return)
//   Escape      - action on Escape (e.g. clear string)
//   FormatError - action on bad input
//-----------------------------------------------------------------------------//

class MpLineEdit : public MpLabel
{
  private:
    enum { offset = 5 };        // horizontal offset from frame (cur. 5)
    int cpos,                   // current text cursor position
        shift,                  // shift of text string (in pixel)
        cut_lo,cut_len,cut,     // cut selection    
        slen;                   // current string length
    bool echo,                  // echo on/off toggle
         overwrite;             // overwrite on/off toggle
    void DrawCursor (void);     // draw cursor image

  protected:
    // event handlers
    virtual void Enter_CB (XCrossingEvent ev);
    virtual void Leave_CB (XCrossingEvent ev);
    virtual void KeyPress_CB (XKeyEvent ev);
    virtual void BPress_CB (XButtonEvent ev);
    virtual void BDoubleClick_CB (XButtonEvent);
    virtual void Motion_CB (XMotionEvent ev);
    virtual void Selection_CB (XSelectionEvent ev);
    virtual void SelectionClear_CB (XSelectionClearEvent ev);
    virtual void SelectionRequest_CB(XSelectionRequestEvent ev);

  public:  
    MpLineEdit(MpWindow &parent, const string &str, int w, int h, int x, int y);
    virtual ~MpLineEdit (void) { }

    virtual void Draw (void);   // draw text + frame
    virtual void Redraw (void); // overloaded: redraw canvas and text

    // Set(), Get() are overloaded members from inherited class MpLabel
    virtual void Set (const string &text);
    virtual string Get (void) const;

    // clear whole text, identical to Set("")
    void Clear (void); 

    // SetFont(), GetFont() derived from class MpLabel

    // set and get echo mode
    void SetEcho (bool echo = true);
    bool GetEcho (void) const;

    // get value and convert to numeric type
    bool   Get (int&) const;
    bool   Get (unsigned int&) const;
    bool   Get (long&) const;
    bool   Get (unsigned long&) const;
    bool   Get (float&) const;
    bool   Get (double&) const;

    // low level cursor movement
    void CursorMoveLeft (bool mark = false);
    void CursorMoveRight (bool mark = false);
    void CursorMoveBegin (bool mark = false);
    void CursorMoveEnd (bool mark = false);
    void CursorDelete (void);
    void CursorDeleteBack (void);
    void CursorDeleteToBegin (void);
    void CursorDeleteToEnd (void);
    void SetOverwriteMode (bool over = true);
    void CursorInsertChar (char keysym);
    void SetCursor (int pos);
    int  GetCursor (void) const;
    void SetMarkedText (int pos, int len);
    string GetMarkedText (void) const;
    void GetMarkedTextPosition (int &pos, int &len);

    // for overloading
    virtual void Enter (void)  {  }
    virtual void Escape (void) { Clear(); }
    virtual void FormatError (void) { Mp.Bell(); }
};

inline int MpLineEdit::GetCursor (void) const
{
  return cpos;
}

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
