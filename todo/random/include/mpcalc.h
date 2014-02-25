/*-----------------------------------------------------------------------------*\
| Matpack X windows API - mathematical expression calculator window    mpcalc.h |
|                                                                               |
| Last change: Jul 19, 2005                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel                                   |
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

#ifndef _MPCALC_H_
#define _MPCALC_H_

#include "mplabel.h"
#include "mphelpwin.h"

//-----------------------------------------------------------------------------//

namespace MATPACK {

class MpCalculatorEntry;

class MpCalculatorWindow: public MpCanvas 
{
  friend class MpCalculatorEntry;
  protected:
    int id;
    MpLabel *Hist;
    MpCalculatorEntry *IO;
    MpHelpPopupButton *Help;
  public:
    MpCalculatorWindow (MpWindow &parent, int id, 
                        int w, int h, int x = 0, int y = 0);
    virtual ~MpCalculatorWindow () {}
    virtual void Resize (int w, int h);
    void SetLanguage (const char** language);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
