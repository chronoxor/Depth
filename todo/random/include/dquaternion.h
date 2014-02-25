/*-----------------------------------------------------------------------------*\
| Matpack - quaternion template class - double specialization     dquaternion.h |
|                                                                               |
| Last change Nov 24, 2004                                                      |
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

#ifndef _DQUATERNION_H_
#define _DQUATERNION_H_

template <> class quaternion<double>
{
  public:  
    // constructor initializes always (to zero if no arguments)
    quaternion (double r = 0, double i1 = 0,  double i2 = 0, double i3 = 0)
      : re(r), im1(i1), im2(i2), im3(i3) { }

    explicit quaternion (const quaternion<float>& q)
      : re(q.real()), im1(q.imag1()), im2(q.imag2()), im3(q.imag3()) { } 

    inline double real  (void) const { return re; }
    inline double imag1 (void) const { return im1; }
    inline double imag2 (void) const { return im2; }
    inline double imag3 (void) const { return im3; }

    quaternion& operator += (const quaternion&);
    quaternion& operator += (const complex<double>&);
    quaternion& operator += (double);  
    quaternion& operator -= (const quaternion&);
    quaternion& operator -= (const complex<double>&);
    quaternion& operator -= (double);  
    quaternion& operator *= (const quaternion&);    
    quaternion& operator *= (const complex<double>&);
    quaternion& operator *= (double);  
    quaternion& operator /= (const quaternion&);   
    quaternion& operator /= (const complex<double>&); 
    quaternion& operator /= (double);  

  private:

    // for name inference purposes (e.g. number as argument)
# if ! defined( WIN32 )    
    friend inline quaternion operator + (const quaternion& q, double d)
      { return operator + <> (q,d); }
    friend inline quaternion operator + (double d, const quaternion& q)
      { return operator + <> (d,q); }
    friend inline quaternion operator - (const quaternion& q, double d)
      { return operator - <> (q,d); }
    friend inline quaternion operator - (double d, const quaternion& q)
      { return operator - <> (d,q); }
    friend inline quaternion operator * (const quaternion& q, double d)
      { return operator * <> (q,d); }
    friend inline quaternion operator * (double d, const quaternion& q)
      { return operator * <> (d,q); }
    friend inline quaternion operator / (const quaternion& q, double d)
      { return operator / <> (q,d); }
    friend inline quaternion operator / (double d, const quaternion& q)
      { return operator / <> (d,q); }
    friend inline bool operator == (const quaternion& q, double r)
      { return operator == <> (q,r); }
    friend inline bool operator == (double r, const quaternion& q)
      { return operator == <> (r,q); }
    friend inline bool operator != (const quaternion& q, double r)
      { return operator != <> (q,r); }
    friend inline bool operator != (double r, const quaternion& q)
      { return operator != <> (r,q); }
#endif

  private:

    double re, im1, im2, im3;   // storage
};

//-----------------------------------------------------------------------------//
// member functions
//-----------------------------------------------------------------------------//

// casts

inline quaternion<float>::quaternion (const quaternion<double>& q)
  : re(q.real()), im1(q.imag1()), im2(q.imag2()), im3(q.imag3()) { }

// addition

inline quaternion<double>& 
quaternion<double>::operator += (const quaternion<double>& q)
{
  re  += q.re;
  im1 += q.im1;
  im2 += q.im2;
  im3 += q.im3;
  return *this;
}

inline quaternion<double>& 
quaternion<double>::operator += (const complex<double>& z)
{
  re  += z.real();
  im1 += z.imag();
  return *this;
}

inline quaternion<double>& 
quaternion<double>::operator += (double d)
{
  re += d;
  return *this;
}

// subtraction

inline quaternion<double>& 
quaternion<double>::operator -= (const quaternion<double>& q)
{
  re  -= q.re;
  im1 -= q.im1;
  im2 -= q.im2;
  im3 -= q.im3;
  return *this;
}

inline quaternion<double>& 
quaternion<double>::operator -= (const complex<double>& z)
{
  re  -= z.real();
  im1 -= z.imag();
  return *this;
}

inline quaternion<double>& 
quaternion<double>::operator -= (double d)
{
  re -= d;
  return *this;
}

// multiplication

inline quaternion<double>& 
quaternion<double>::operator *= (double d)
{
  re  *= d; im1 *= d; im2 *= d; im3 *= d;
  return *this;
}

// division

inline quaternion<double>& 
quaternion<double>::operator /= (double d)
{
  double t(1.0/d);
  re  *= t; im1  *= t; im2 *= t; im3 *= t;
  return *this;
}

//-----------------------------------------------------------------------------//

#endif

