/*-----------------------------------------------------------------------------*\
| Matpack date class (Julian/Gregorian date conversion)                mpdate.h |
|                                                                               |
| Last change: Sep 12, 2004                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel                                   |
|                                                                               |
| Permission to  use, copy, and  distribute  Matpack  in  its  entirety and its | 
| documentation for  non-commercial purpose and  without fee is hereby granted, | 
| provided that this license information and copyright notice appear unmodified | 
| in all copies. This software is provided 'as is'  without  express or implied | 
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

#ifndef _MPDATE_H_
#define _MPDATE_H_

#include "common.h"

namespace MATPACK {
using std::ostream;

//-----------------------------------------------------------------------------//
// class MpDate:
// Stores date and time as a julian day number with fractional part.
// Conversion routines 
//-----------------------------------------------------------------------------//

class MpDate
{ 
  private:
    double julian;
  public:
    enum type { no_reform, reform_1582, reform_1752 };
    MpDate (void);
    MpDate (double julian);
    MpDate (int day, int month, int year, 
            int hour, int minute, double second, int type = reform_1582);
    MpDate (int day, int month, int year, int type = reform_1582);

    void Date (int &day, int &month, int &year, 
               int &hour, int &minute, double &second, 
               int type = reform_1582) const;
    void Date (int &day, int &month, int &year, int type = reform_1582) const;
    void Date (char date[], int type = reform_1582) const;

    int Day (int type = reform_1582) const;
    int Month (int type = reform_1582) const;
    int Year (int type = reform_1582) const;
    int Hour (int type = reform_1582) const;
    int Minute (int type = reform_1582) const;
    double Second (int type = reform_1582) const;
    int DayOfWeek (void) const;
    double Julian (void) const { return julian; }

    friend ostream& operator << (ostream& of, const MpDate&);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
