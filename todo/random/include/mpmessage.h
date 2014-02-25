/*-----------------------------------------------------------------------------*\
| Matpack X windows API - message dialog                            mpmessage.h |
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

#ifndef _MPMESSAGEDIALOG_H_
#define _MPMESSAGEDIALOG_H_

#include "mpwindow.h"

//-----------------------------------------------------------------------------//

namespace MATPACK {

class MpMessageDialog: public MpFrame
{
  private:
    int status, icon;
    MpCanvas *but[3];
    MpRectangle<short> trec;
    const char *text;

  protected:

    virtual void Redraw (void); // overload virtual
    virtual void ClientMsg_CB (XClientMessageEvent); // overload virtual
    virtual void Button_0_Clicked (void);
    virtual void Button_1_Clicked (void);
    virtual void Button_2_Clicked (void);

  public:

    enum {  margin = 12, icon_size = 32 };
    enum { Button_0 = 0, Button_1 = 1, Button_2 = 2 };
    enum { InfoIcon = 0, AskIcon = 1, WarnIcon = 2, ErrorIcon = 3 };

    int  GetStatus (void) const { return status; }
    void SetStatus (int s) { status = s; }

    // constructor for message dialog
    // width or height equal to 0 means auto-size. 
    MpMessageDialog (const char *title, const char *text, int icon,
                     const char *yes = "Yes", 
                     const char *no = 0, 
                     const char *cancel = 0);

    // Display modal dialog box with title, information and one button.
    // An "information" icon is shown. 
    // The dialog box disappears if the button is pressed.
    // Returns 1 always.
    static int Information (const char *title, const char *text, 
                            const char *ok = "OK");

    // Display modal dialog box with title, information and one button.
    // A "warning" icon is shown. 
    // The dialog box disappears if the button is pressed.
    // Returns 1 always.
    static int Warning (const char *title, const char *text, 
                        const char *ok = "OK");

    // Display modal dialog box with title, information and one button.
    // An "error" icon is shown. 
    // The dialog box disappears if the button is pressed.
    // Returns 1 always.
    static int Error (const char *title, const char *text, 
                      const char *ok = "OK");
   
    // Display modal dialog box with title, information and two buttons.
    // A "question" icon is shown. 
    // The dialog box disappears one of the buttons is pressed.
    // Returns 0 if the "Continue" button 0 is clicked
    //         2 if the "Cancel"   button 1 is clicked
    static int ContinueCancel (const char *title, const char *text, 
                               const char *contin = "Continue", 
                               const char *cancel = "Cancel");

    // Display modal dialog box with title, information and three buttons. 
    // A "question" icon is shown. 
    // The dialog box disappears one of the buttons is pressed.
    // Returns 0  if the "Yes" button 0 is clicked
    //         1  if the "No"  button 1 is clicked
    //         2  if the "Cancel" button 2 is clicked      
    static int YesNoCancel (const char *title, const char *text, 
                            const char *yes = "Yes", 
                            const char *no  = "No", 
                            const char *cancel = "Cancel");
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
