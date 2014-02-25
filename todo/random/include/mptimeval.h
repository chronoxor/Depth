/*-----------------------------------------------------------------------------*\
| convenience functions for caluculating with timevals              mptimeval.h |
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

#ifndef _MPTIMEVAL_H_
#define _MPTIMEVAL_H_

// include STL definition
#include <iostream>
#include <math.h>  

#include "compat.h"

namespace MATPACK {
using std::ostream;

//-----------------------------------------------------------------------------//
// Convenience inline functions for calculations with time values 
// of "struct timeval" as defined in "sys/time.h".
//
//       struct timeval {
//         long tv_sec;        /* seconds */
//         long tv_usec;       /* microseconds */
//       };
//
// Supported inline operators are '<', '>', '==', '+', '+=', '-', '-=', and 
// stream output via "<<" (mainly for debugging putposes).
// The operator << is also overloaded to initialize timeval with
// with a time given as a double in units of seconds.
//
// Note, that all operators require normalized values, i.e. the number
// of microseconds must be smaller than one second!
//
// Examples:
//
//    timeval a, b, c; 
//    a << 20.40;  cout << a << endl;
//    b <<  1.02;  cout << b << endl;
//    c  = a + b;  cout << c << endl; 
//    c  = a - b;  cout << c << endl;
//    c += b;      cout << c << endl;
//    c -= b;      cout << c << endl; 
//    cout << (a >  b) << endl;
//    cout << (a <  b) << endl;
//    cout << (a == b) << endl;
// 
//-----------------------------------------------------------------------------//

inline bool operator < ( const timeval &t1, const timeval &t2 )
{
  return t1.tv_sec < t2.tv_sec ||
         (t1.tv_sec == t2.tv_sec && t1.tv_usec < t2.tv_usec);
}

//-----------------------------------------------------------------------------//

inline bool operator > ( const timeval &t1, const timeval &t2 )
{
  return t1.tv_sec > t2.tv_sec ||
         (t1.tv_sec == t2.tv_sec && t1.tv_usec > t2.tv_usec);
}

//-----------------------------------------------------------------------------//

inline bool operator == ( const timeval &t1, const timeval &t2 )
{
  return (t1.tv_sec == t2.tv_sec && t1.tv_usec == t2.tv_usec);
}

//-----------------------------------------------------------------------------//

inline timeval operator + ( const timeval &t1, const timeval &t2 )
{
  timeval tmp;
  tmp.tv_sec = t1.tv_sec + t2.tv_sec;
  if ( (tmp.tv_usec = t1.tv_usec + t2.tv_usec) >= 1000000 ) {
    ++tmp.tv_sec;
    tmp.tv_usec -= 1000000;
  }
  return tmp;
}

//-----------------------------------------------------------------------------//

inline timeval& operator += ( timeval &t1, const timeval &t2 )
{
  t1.tv_sec += t2.tv_sec;
  if ( (t1.tv_usec += t2.tv_usec) >= 1000000 ) {
    ++t1.tv_sec;
    t1.tv_usec -= 1000000;
  }
  return t1;
}

//-----------------------------------------------------------------------------//

inline timeval operator - ( const timeval &t1, const timeval &t2 )
{
  timeval tmp;
  tmp.tv_sec = t1.tv_sec - t2.tv_sec;
  if ( (tmp.tv_usec = t1.tv_usec - t2.tv_usec) < 0 ) {
    --tmp.tv_sec;
    tmp.tv_usec += 1000000;
  }
  return tmp;
}

//-----------------------------------------------------------------------------//

inline timeval& operator -= ( timeval &t1, const timeval &t2 )
{
  t1.tv_sec -= t2.tv_sec;
  if ( (t1.tv_usec -= t2.tv_usec) < 0 ) {
    --t1.tv_sec;
    t1.tv_usec += 1000000;
  }
  return t1;
}

//-----------------------------------------------------------------------------//

inline ostream& operator << (ostream& os, const timeval& t)
{
  os << t.tv_sec << "s+" << t.tv_usec << "us";
  return os;
  
}

//-----------------------------------------------------------------------------//

inline timeval& operator << (timeval &t, double val)
{
  double integral;
  t.tv_usec = (long)(1000000 * modf(val,&integral) + 0.5);
  t.tv_sec  = (long)integral;
  return t;
}

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
