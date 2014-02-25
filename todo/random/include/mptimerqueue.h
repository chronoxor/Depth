/*-----------------------------------------------------------------------------*\
| base class for general purpose interval timers                 mptimerqueue.h |
|                                                                               |
| Last change: May 13, 2001                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2001 by Berndt M. Gammel. All rights reserved.             |
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

#ifndef _MPTIMERQUEUE_H_
#define _MPTIMERQUEUE_H_

#include <queue>       // STL queues

#include "common.h"
#include "mptimeval.h" // inline arithmetic operators for "struct timeval"

//-----------------------------------------------------------------------------//

namespace MATPACK {
using std::binary_function;
using std::vector;
using std::priority_queue;


class MpTimerInterface;

struct MpTimerInfo                      // timer info
{       
  timeval  interval;                    // timer interval
  timeval  timeout;                     // when to send event
  MpTimerInterface *receiver;           // receiver of event
};

//-----------------------------------------------------------------------------//

struct less_time: public binary_function <MpTimerInfo*, MpTimerInfo*, bool> 
{  
  bool operator () (MpTimerInfo* &a, MpTimerInfo* &b) const 
    { return (a->timeout > b->timeout); }
};

//-----------------------------------------------------------------------------//
// class MpTimerQueue:
//
// Base class for general purpose interval timers. It manages the timer queue
// and supplies functions for adding and removing timers, starting timer event
// processing and getting the time until the next timer expires.
//-----------------------------------------------------------------------------//

class MpTimerQueue
{
  private:
    typedef priority_queue<MpTimerInfo*,vector<MpTimerInfo*>,less_time> queue_t;
    queue_t queue;

  public:
    timeval GetTime(void) 
        { 
#if defined( WIN32)
                timeval now;
                struct _timeb tstruct;
                _ftime( &tstruct );
                now.tv_sec = tstruct.time;
                now.tv_usec = (long)1000*tstruct.millitm;
                return now;
#else
                timeval now; 
                gettimeofday(&now,0); 
                return now;
#endif
        }

    MpTimerInfo* StartTimer (MpTimerInterface *receiver, int sec, int usec);
    void StopTimer (MpTimerInfo* info);  // destroy this timer
    void StopAllTimers (void);           // destroy all timers
    int  EvaluateTimers (void);          // activate callbacks of expired timers
    timeval* NextTimer (void);           // get time until next timer expires
    ~MpTimerQueue();                     // destroy all timers and this class
    void SleepTime(const timeval& sleep);// time to sleep 
};

//-----------------------------------------------------------------------------//
// class MpTimerInterface:
//
// Class MpTimerInterface supplies an abstract interface for the callback 
// that is called when a timer is expired. You have to overload the method:
//
//         virtual void TimerEvent(MpTimerInfo *info)
//
//-----------------------------------------------------------------------------//

class MpTimerInterface
{
  public:
    virtual void TimerEvent (MpTimerInfo *info) = 0;
    virtual ~MpTimerInterface (void) { /* void */ }
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
