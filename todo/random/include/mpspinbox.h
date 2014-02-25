/*-----------------------------------------------------------------------------*\
| Matpack X windows API: class MpSpinBox                            mpspinbox.h |
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

#ifndef _MPSPINBOX_H_
#define _MPSPINBOX_H_

#include <string>
#include "mplineedit.h"
#include "mpbutton.h"

//-----------------------------------------------------------------------------//

namespace MATPACK {

class MpSpinBox: public MpCanvas 
{
  private:
    int minv, maxv, stepv, val;
    string prefix, suffix;
    bool circular;
    MpLineEdit *text;
    MpButton *up,*down;
    void Step (int);
  public:
  
    //-------------------------------------------------------------------------//
    // Member Function:
    //   virtual void ValueChanged (int val);
    //
    // Description:
    //   User callback function which is called whenever the value is changed.
    //   Overload it to start an immediate action. If no immediate actions
    //   are wanted use the GetValue() method to retrieve the current value
    //   of the spin box.
    //-------------------------------------------------------------------------//
    virtual void ValueChanged (int val) {  }

    //-------------------------------------------------------------------------//
    // conversion functions for optional overloading
    //-------------------------------------------------------------------------//
    virtual string ValueToString (int val, bool &error);
    virtual int StringToValue (const string &str, bool &error);
  
    //-------------------------------------------------------------------------//
    // Get and set methods 
    //-------------------------------------------------------------------------//
    void SetValue (int val);
    int  GetValue (void) const;
    void SetPrefix (const string &val);
    string GetPrefix (void) const;
    void SetSuffix (const string &val);
    string GetSufix (void) const;
    void SetRange (int min, int max, int step = 1);
    int  GetMin (void) const;
    int  GetMax (void) const;
    int  GetStep (void) const;
    void SetCircular(bool val);
    bool GetCircular(void) const;
    void StepUp (void);
    void StepDown (void);
  
    //-------------------------------------------------------------------------//
    // Constructor and Destructor:
    //   MpSpinBox (MpWindow& parent, int val, int w, int h, int x, int y);
    //   virtual ~MpSpinBox();
    //
    // Description:
    //   Note, that up and down buttons have auto-repeat activated.
    //   Use the methods of class MpGlobal
    //     void Mp.SetAutoRepeatDelay (Time t);
    //     void Mp.SetAutoRepeatInterval (Time t);
    //   to adjust the delay and interval times.
    //-------------------------------------------------------------------------//
    MpSpinBox (MpWindow& parent, int val, int w, int h, int x, int y);
    virtual ~MpSpinBox () { };

    //-------------------------------------------------------------------------//
    // Style settings:
    // All style settings from the inherited class MpCanvas can also be used.
    //-------------------------------------------------------------------------//
    void SetFrameWidth (int width);
    void SetFrameStyle (int style);
    virtual void Redraw (void);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
