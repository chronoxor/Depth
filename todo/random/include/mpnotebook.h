/*-----------------------------------------------------------------------------*\
| Matpack X windows application programming interface              mpnotebook.h |
| include file for class MpNotebook                                             |
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

#ifndef _MPNOTEBOOK_H_
#define _MPNOTEBOOK_H_

//-----------------------------------------------------------------------------//

#include "mpwindow.h"                   // general definitions
#include "mprectangle.h"                // rectangle and point classes

#include <string>                       // STL string

//-----------------------------------------------------------------------------//

namespace MATPACK {

class TabPrivate;

class MpNotebook : public MpCanvas
{ 
  private:

    int tabpos,
        mintabwidth, 
        mintabheight;
    TabPrivate *tabs;

    MpNotebook& operator = (const MpNotebook&) { return *this; } // no assignment

  protected:
    
    virtual void RedrawFrame (void);
    virtual void BPress_CB (XButtonEvent ev);
    virtual void BRelease_CB (XButtonEvent ev);
    virtual void PageSelected (void) { } // handler supplied for overloading

  public:
  
    // possible values for alignment are:
    // MpGlobal::AlignLeft / AlignRight / AlignTop / AlignBottom

    MpNotebook (MpWindow& parent, int w, int h, int x = 0, int y = 0, 
                int tabpos = AlignTop, 
                int mintabwidth = 4, int mintabheight = 25);
    virtual ~MpNotebook (void);

    MpCanvas*   InsertPage (const string &label);

    void        SetCurrentPage (const MpCanvas* page); // select by page pointer
    void        SetCurrentPage (int page);             // select by page index
    MpCanvas*   GetCurrentPage (void) const;
    string      GetCurrentPageLabel (void) const;

    void RemovePage (int num) { /* NOT YET */ }
    void Resize (int w, int h) { /* NOT YET */ }
    void Enable (int num) { /* NOT YET */ }
    void Disable (int num) { /* NOT YET */ }
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
