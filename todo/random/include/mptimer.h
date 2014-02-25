/*-----------------------------------------------------------------------------*\
| interval timers for the GUI                                         mptimer.h |
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

#ifndef _MPTIMER_H_
#define _MPTIMER_H_

#include "mpwindow.h"
#include "mptimerqueue.h"

//-----------------------------------------------------------------------------//

namespace MATPACK {

class MpTimer
{
  private:
    MpTimerInfo* info;
  public:
    
    //------------------------------------------------------------------------//
    // Constructor: 
    //    MpTimer::MpTimer (void);
    // Description:
    //    Add a new interval timer to the GUI's timer queue. The timer is idle.
    //------------------------------------------------------------------------//
    MpTimer (void);

    //------------------------------------------------------------------------//
    // Constructor: 
    //    MpTimer::MpTimer (MpWindow *receiver, int sec, int usec);
    // Description:
    //    Add a new interval timer to the GUI's timer queue. The interval is
    //    given as seconds + microseconds. Note that a normalized value is
    //    expected, i.e. the  numer of microseconds must be less than a second.
    //    The timer is started immediately. 
    //    A pointer to a window (or any class that inherits class MpWindow is 
    //    given, which will receive a timer event if the timer is expired. 
    //    You have to overload the virtual callback
    //
    //        virtual void MpWIndow::TimerExpired_CB (MpTimerInfo *info) {}
    //
    //    to accept a timer event.
    //------------------------------------------------------------------------//
    MpTimer (MpWindow *receiver, int sec, int usec);

    //------------------------------------------------------------------------//
    // Destructor:  
    //    MpTimer::~MpTimer (void);
    // Description:
    //    The interval timer is stopped and removed from the GUI's timer queue. 
    //------------------------------------------------------------------------//
    ~MpTimer (void);

    //------------------------------------------------------------------------//
    // Member function: 
    //    MpTimerInfo* MpTimer::StartTimer (MpWindow *receiver, 
    //                                       int sec, int usec);
    // Description:
    //    Start the interval timer with the interval given as seconds 
    //    + microseconds. Note that a normalized value is expected, 
    //    i.e. the  numer of microseconds must be less than a second.
    //    A pointer to a window (or any class that inherits class MpWindow is 
    //    given, which will receive a timer event if the timer is expired. 
    //    You have to overload the virtual callback
    //
    //        virtual void MpWindow::TimerExpired_CB (MpTimerInfo *info) {}
    //
    //    to accept a timer event. 
    //    If you call StartTimer() for a timer that is already running the 
    //    timer is stopped, removed, and reinserted with the new 
    //    time and receiver argument values.
    //------------------------------------------------------------------------//
    MpTimerInfo* StartTimer (MpWindow *receiver, int sec, int usec); 

    //------------------------------------------------------------------------//
    // Member function: 
    //    void MpTimer::StopTimer (void);
    // Description:
    //    The interval timer is stopped and removed from the GUI's timer queue. 
    //------------------------------------------------------------------------//
    void StopTimer (void);

    //------------------------------------------------------------------------//
    // Member function: 
    // Description:
    //    Return true if the interval timer is active (i.e. in the timer queue) 
    //------------------------------------------------------------------------//
    bool IsActive (void);
};

//-----------------------------------------------------------------------------//

inline bool MpTimer::IsActive (void)
{
  return (info != 0);
}

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
