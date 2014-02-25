/*-----------------------------------------------------------------------------*\
| Matpack X windows API: class MpComboBox                          mpcombobox.h |
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
| not be distributed without pior consent of the author.			|
|                                                                               |
| Read the  COPYRIGHT and  README files in this distribution about registration	|
| and installation of Matpack.							|
|                                                                               |
\*-----------------------------------------------------------------------------*/


#ifndef _MPCOMBOBOX_H_
#define _MPCOMBOBOX_H_

#include "mplistbox.h"
#include "mpbutton.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// class MpComboButton: internal interface class for class MpComboBox
//-----------------------------------------------------------------------------//

class MpComboButton: public MpButton
{
  protected:
    MpListBox *listbox;
    virtual void BPress (XButtonEvent ev) = 0;
    virtual void BRelease (XButtonEvent ev) = 0;    
    void BPress_CB   (XButtonEvent ev) { BPress(ev);   }
    void BRelease_CB (XButtonEvent ev) { BRelease(ev); }

  public:
    MpComboButton (MpWindow &parent, int w, int h, int x, int y);
    virtual void Redraw (void);
    virtual void Draw (void);
};

//-----------------------------------------------------------------------------//
// class MpComboList: internal interface class for class MpComboBox
//-----------------------------------------------------------------------------//

class MpComboList: public MpListBox
{
  protected:
    virtual void LPress (XButtonEvent ev) = 0;
    virtual void LRelease (XButtonEvent ev) = 0;
    virtual bool EFilter (MpWindow* target, XEvent &event) = 0;
    virtual void BPress_CB (XButtonEvent ev) { LPress(ev); }
    virtual void BRelease_CB (XButtonEvent ev) { LRelease(ev); }
    virtual bool EventFilter (MpWindow* target, XEvent &ev) { return EFilter(target,ev); }

  public:
    MpComboList (MpWindow& parent, int w, int h, int x, int y);
};

//-----------------------------------------------------------------------------//
// class MpComboBox: implements a combo box
//-----------------------------------------------------------------------------//

class MpComboBox: public MpComboButton, public MpComboList
{
  private:
    int ListBoxMaxHeight, ListBoxMaxWidth;
    bool AutoWidth,BPressed,LPressed,Marked;
    void Popdown (void);

  protected:    
    virtual void BPress (XButtonEvent ev);
    virtual void BRelease (XButtonEvent ev);
    virtual void LPress (XButtonEvent ev);
    virtual void LRelease (XButtonEvent ev);
    virtual bool EFilter (MpWindow* target, XEvent &event);
    virtual void ItemMarked   (MpListBoxItem *item);
    virtual void ItemSelected (MpListBoxItem *item);

  public:
    MpComboBox (MpWindow& parent, int w, int h, int x = 0, int y = 0);
    virtual ~MpComboBox ();

    // additional layout setting (see class MpListBox for all other)
    void SetListBoxMaxHeight (int pixel);
    int  GetListBoxMaxHeight (void) const;
    void SetListBoxMaxWidth (int pixel);
    int  GetListBoxMaxWidth (void) const;
    void SetAutoWidth (bool val);
    bool GetAutoWidth (void) const;

    virtual void UpdateView (void);

    // signals (virtual callbacks to overload)
    virtual void ComboItemMarked   (MpListBoxItem *item) { }
    virtual void ComboItemSelected (MpListBoxItem *item) { }
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
