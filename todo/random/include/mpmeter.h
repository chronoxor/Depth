/*-----------------------------------------------------------------------------*\
| Matpack X windows application programming interface include         mpmeter.h |
| Include file for a progress meter gauge                                       |
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

#ifndef _MPMETER_H_
#define _MPMETER_H_

#ifndef _MPWINDOW_H_
#include "mpwindow.h"
#endif

//-----------------------------------------------------------------------------//

namespace MATPACK {

class MpProgressMeter : public MpCanvas
{
  protected:
    const char *Format;
    float WaitDone,PercentDone;
    int Level,Waiting;
    long LastTime,WaitTime;
  public:
    MpProgressMeter (MpWindow &parent, int w, int h, int x = 0, int y = 0,
		     const char* Format = 0, 
		     float WaitTime = 1, float WaitDone = 0.5);
    virtual void Redraw (void);
    virtual void Update (int min, int max, int current);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
