/*-----------------------------------------------------------------------------*\
| Windows API: classes MpHelpPopupWindow and MpHelpPopupButton      mphelpwin.h |
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

#ifndef _MPHELPWIN_H_
#define _MPHELPWIN_H_

#include "mpscrollwin.h"
#include "mpbutton.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// class MpHelpPopupWindow:
//-----------------------------------------------------------------------------//

class MpHelpPopupWindow : public MpFrame 
{
  private:
    MpHelpPopupWindow **selfptr;
    bool destroy;
    void close (void);
    int MenubarH;
    const char **HelpText;
    MpCanvas* Menubar;
    MpScrollWindow *Scroll;
  public: 
    MpHelpPopupWindow (const char* label, int w, int h, const char* text[]); 
    virtual void Resize (int w, int h);
    virtual void ChangeText (const char *text[], bool resize = true);
    void DestroyOnClose (MpHelpPopupWindow* &self);
};

//-----------------------------------------------------------------------------//
// class MpHelpPopupButton: popup a window with help text
//-----------------------------------------------------------------------------//

class MpHelpPopupButton : public MpButton 
{
  private:
    const char **helptext;
    MpHelpPopupWindow* helpwin; 
    int hw, hh;
    MpHelpPopupWindow* AddHelpPopupWindow (const char* text[], int hw, int hh);
  protected:
    virtual void BClick_CB (XButtonEvent ev);

  public: 
    MpHelpPopupButton (MpWindow& parent, const string &label, 
		       int w, int h, int x, int y, 
		       const char *helptext[], 
		       int hw = 0, int hh = 0) ;

    virtual ~MpHelpPopupButton (void);

    virtual void ChangeText (const char* text[], bool resize = true);
    virtual void Popup (void);
    virtual void Popdown (void);
};

// utility to get extent of help text
void MpGetHelpTextExtent (const char *text[], int& width, int& height);

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
