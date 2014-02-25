/*-----------------------------------------------------------------------------*\
| Matpack X windows GUI: cursors                                     mpcursor.h |
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

#ifndef _MPCURSOR_H_
#define _MPCURSOR_H_

#include <X11/Xlib.h>
#include "mppoint2.h"


namespace MATPACK {

class MpCursorImpl; 
class MpCursor 
{
  private:
    static MpCursorImpl *pimpl;
    int shape;
  public:
    enum
    { 
      Default = 0,
      CrossHair,
      Wait,
      SlideVertical,
      SlideHorizontal,
      TopLeftCorner,
      BottomRightCorner,
      Text,
      HandOpen, 
      HandClosed,
      HandPoint
    };

    MpCursor (void) : shape(Default) { }
    MpCursor (int shape) : shape(shape) { } // works also as implicit conversion
    MpCursor (const MpCursor &src) : shape(src.shape) { }
    MpCursor& operator = (const MpCursor &src) { shape = src.shape; return *this; }
   ~MpCursor () { }

    void SetShape (int s) { shape = s; } 
    int  GetShape (void) const { return shape; }

    static void SetPos (int x, int y);
    static MpPoint2<int> GetPos (void);

    // don't call the following methods explicitely (for use in MpGlobal/MpWindow)
    static void Setup (void);              // allocates default cursors
    static void Cleanup (void);            // cleans allocated cursors
    Cursor GetHandle (void) const;         // returns the X-Resource
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
