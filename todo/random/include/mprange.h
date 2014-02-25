/*-----------------------------------------------------------------------------*\
| Matpack X windows API: template class MpRange                       mprange.h |
|                                                                               |
| Last change: Jan 22, 2005							|
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel. All rights reserved.             |
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

#ifndef _MPRANGE_H_
#define _MPRANGE_H_

//-----------------------------------------------------------------------------//
// template class for range control 
//-----------------------------------------------------------------------------//

template <class T>
class MpRange
{
  private:
    T val, min, max, smallstep, bigstep;

    void ForceRange (T& x, const T &a, const T &b) 
    { 
      if      (x < a) ValueChanged(x = a); 
      else if (x > b) ValueChanged(x = b); 
    }

  public:

    // virtual signal functions
    virtual void ValueChanged (T value) { }
    virtual void RangeChanged (T min, T max) { }
    virtual void StepsChanged (T small, T big) { }

    // access functions
    T GetValue     (void) const { return val; }
    T GetMin       (void) const { return min; }
    T GetMax       (void) const { return max; }
    T GetSmallStep (void) const { return smallstep; }
    T GetBigStep   (void) const { return bigstep; }


    void SetValue (const T &value) 
    { 
      if      (value < min) { if (val != min) ValueChanged(val = min); }
      else if (value > max) { if (val != max) ValueChanged(val = max); }
      else if (val != value) ValueChanged(val = value); 
    }

    void AddBigStep   (void) { SetValue(val + bigstep);   }
    void SubBigStep   (void) { SetValue(val - bigstep);   }
    void AddSmallStep (void) { SetValue(val + smallstep); }
    void SubSmallStep (void) { SetValue(val - smallstep); }

    void SetRange (const T &mini, const T &maxi) 
    { 
      if (min != mini || max != maxi) { 
	RangeChanged(min = mini, max = maxi);
	ForceRange(val,min,max);
      }
    }

    void SetSteps (const T &small, const T &big) 
    { 
      if (smallstep != small || bigstep != big) 
	StepsChanged(smallstep = small, bigstep = big); 
    }

    MpRange (T min, T max, T smallstep, T bigstep, T val)
      : val(val), min(min), max(max), smallstep(smallstep), bigstep(bigstep)
    { 
      ForceRange(val,min,max);
    }

    virtual ~MpRange (void) { }
};

//-----------------------------------------------------------------------------//

#endif
