/*-----------------------------------------------------------------------------*\
| Matpack X windows API: class MpButtonGroup                    mpbuttongroup.h |
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

#ifndef _MPBUTTONGROUP_H_
#define _MPBUTTONGROUP_H_

#include "mpbutton.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// class MpButtonGroup:
//
// Purpose:
//   group buttons
//
// Inherits:
//   class MpCanvas
//
// Description:
//   
//
//-----------------------------------------------------------------------------//

class MpButtonGroup: public MpCanvas
{
  friend class MpButton;
  private:
    string title;
    vector< MpButton* > list;
    bool exclusive_toggles;
  protected:
    virtual void RedrawFrame (void);
    virtual void BClick_Handler (MpButton *button);
  public:
    MpButtonGroup (MpWindow& parent, const string &title, 
		   int w, int h, int x = 0, int y = 0);
    virtual ~MpButtonGroup ();

    virtual void BClick_CB (MpButton *button) { } 

    // add or remove buttons to/from the group
    void InsertButton (MpButton *button);
    void RemoveButton (MpButton *button);
    void RemoveAllButtons (void);

    // toggle buttons can behave exclusive or non-exclusive
    void SetExclusiveToggles (bool val) { exclusive_toggles = val; }
    bool GetExclusiveToggles (void) const { return exclusive_toggles; }

    // get and set the title
    virtual void SetTitle (const string &text);
    virtual string GetTitle (void) const;

};
 
inline void MpButtonGroup::SetTitle (const string &text)
{
  title = text;  
  Redraw();
}

inline string MpButtonGroup::GetTitle (void) const
{
  return title;
}

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
