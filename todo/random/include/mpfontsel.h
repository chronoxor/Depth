/*-----------------------------------------------------------------------------*\
| Matpack X windows application programming interface               mpfontsel.h |
| small font selector panel                                                     |
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

#ifndef _MPFONTSEL_H_
#define _MPFONTSEL_H_

#ifndef _MPWINDOW_H_
#include "mpwindow.h"
#endif

//-----------------------------------------------------------------------------//

namespace MATPACK {

class MpFontSelectorWindow : public MpCanvas
{
  protected:
    void Initialize (void);
    MpPulldownButton *font_button, *shape_button, *weight_button, *size_button;
    virtual void Action (const char *menu, const char *newtext, void *valptr);
    virtual void Update (const XFontStruct *theFont, const char *fontname) { }
  public:
    enum { SLEN = 60 };
    char  font[SLEN], shape[SLEN], weight[SLEN], size[SLEN];
    XFontStruct *theFont; 

    MpFontSelectorWindow (MpWindow &parent, int w = 220, int h = 25, 
                          int x = 0, int y = 0);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
