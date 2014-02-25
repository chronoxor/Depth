/*-----------------------------------------------------------------------------*\
| Matpack - quaternion template class internal include file       quaterniont.h |
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

#ifndef _QUATERNIONT_H_
#define _QUATERNIONT_H_

//-----------------------------------------------------------------------------//

#include <complex>
#include <iostream>
#include <string>

//-----------------------------------------------------------------------------//

namespace MATPACK {
using std::complex;
using std::string;
using std::istream;
using std::ostream;
using std::ios;


template <class float_t>
class quaternion
{
  public:  

    // constructor initializes always (to zero if no arguments)
    quaternion (float_t r = 0, float_t i1 = 0,  float_t i2 = 0, float_t i3 = 0)
      : re(r), im1(i1), im2(i2), im3(i3) { }

    inline float_t real  (void) const { return re; }
    inline float_t imag1 (void) const { return im1; }
    inline float_t imag2 (void) const { return im2; }
    inline float_t imag3 (void) const { return im3; }

    quaternion& operator += (const quaternion&);
    quaternion& operator += (const complex<float_t>&);
    quaternion& operator += (float_t);  
    quaternion& operator -= (const quaternion&);
    quaternion& operator -= (const complex<float_t>&);
    quaternion& operator -= (float_t);  
    quaternion& operator *= (const quaternion&);
    quaternion& operator *= (const complex<float_t>&);
    quaternion& operator *= (float_t);  
    quaternion& operator /= (const quaternion&);
    quaternion& operator /= (const complex<float_t>&);
    quaternion& operator /= (float_t);  

  private:

    float_t re, im1, im2, im3;  // storage
};

//-----------------------------------------------------------------------------//
// Declare specializations
//-----------------------------------------------------------------------------//

class quaternion<float>;
class quaternion<double>;

//-----------------------------------------------------------------------------//
// functions
//-----------------------------------------------------------------------------//

// elements

template <class float_t> 
inline float_t real (const quaternion<float_t>& q)
{ 
  return q.real(); 
}

template <class float_t> 
inline float_t imag1 (const quaternion<float_t>& q)
{ 
  return q.imag1(); 
}

template <class float_t> 
inline float_t imag2 (const quaternion<float_t>& q)
{ 
  return q.imag2(); 
}

template <class float_t> 
inline float_t imag3 (const quaternion<float_t>& q)
{ 
  return q.imag3(); 
}

// unary functions 

template <class float_t> 
inline quaternion<float_t> conj (const quaternion<float_t>& q)
{
  return quaternion<float_t>(real(q), -imag1(q), -imag2(q), -imag3(q));
}

template <class float_t> 
inline float_t norm (const quaternion<float_t>& q)
{
  return real(q) * real(q) + imag1(q) * imag1(q)
         + imag2(q) * imag2(q) + imag3(q) * imag3(q);
}

template <class float_t> 
inline quaternion<float_t> sqr (const quaternion<float_t>& q)
{
  float_t a(real(q)) , b(imag1(q)), c(imag2(q)), d(imag3(q));
  return quaternion<float_t>(a*a - b*b - c*c - d*d, 2*a*b, 2*a*c, 2*a*d);
}

template <class float_t> 
inline float_t abs (const quaternion<float_t>& q)
{
  return sqrt(real(q) * real(q) + imag1(q) * imag1(q)
              + imag2(q) * imag2(q) + imag3(q) * imag3(q));
}

template <class float_t> 
inline quaternion<float_t> polar (float_t r, float_t phi, float_t theta, float_t psi)
{
  float_t a,b,c,d;
  a = r * cos(phi);                     // r*cos(phi)
  b = (d = r*sin(phi)) * cos(theta);    // r*sin(phi)*cos(theta)
  c = (d *= sin(theta)) * cos(psi);     // r*sin(phi)*sin(theta)*cos(psi)
  d *= sin(psi);                        // r*sin(phi)*sin(theta)*sin(psi)
  return quaternion<float_t>(a,b,c,d);
}

//-----------------------------------------------------------------------------//
// member functions
//-----------------------------------------------------------------------------//

// addition

template <class float_t> inline quaternion<float_t>& 
quaternion<float_t>::operator += (const quaternion<float_t>& q)
{
  re  += q.re;
  im1 += q.im1;
  im2 += q.im2;
  im3 += q.im3;
  return *this;
}

template <class float_t> inline quaternion<float_t>& 
quaternion<float_t>::operator += (const complex<float_t>& z)
{
  re  += z.real();
  im1 += z.imag();
  return *this;
}

template <class float_t> inline quaternion<float_t>& 
quaternion<float_t>::operator += (float_t d)
{
  re += d;
  return *this;
}

// subtraction

template <class float_t> inline quaternion<float_t>& 
quaternion<float_t>::operator -= (const quaternion<float_t>& q)
{
  re  -= q.re;
  im1 -= q.im1;
  im2 -= q.im2;
  im3 -= q.im3;
  return *this;
}

template <class float_t> inline quaternion<float_t>& 
quaternion<float_t>::operator -= (const complex<float_t>& z)
{
  re  -= z.real();
  im1 -= z.imag();
  return *this;
}

template <class float_t> inline quaternion<float_t>& 
quaternion<float_t>::operator -= (float_t d)
{
  re -= d;
  return *this;
}

// multiplication

template <class float_t> inline quaternion<float_t>& 
quaternion<float_t>::operator *= (float_t d)
{
  re  *= d; im1 *= d; im2 *= d; im3 *= d;
  return *this;
}

// division

template <class float_t> inline quaternion<float_t>& 
quaternion<float_t>::operator /= (float_t d)
{
  float_t t(1.0/d);
  re  *= t; im1  *= t; im2 *= t; im3 *= t;
  return *this;
}

// sign 

template <class float_t> inline quaternion<float_t>
operator + (const quaternion<float_t>& q)
{
  return q;
}

template <class float_t> inline quaternion<float_t> 
operator - (const quaternion<float_t>& q)
{
  return quaternion<float_t>(-q.real(), -q.imag1(), -q.imag2(), -q.imag3());
}

//-----------------------------------------------------------------------------//
// non member functions
//-----------------------------------------------------------------------------//

// addition

template <class float_t> inline quaternion<float_t> 
operator + (const quaternion<float_t>& q1, const quaternion<float_t>& q2)
{
  return quaternion<float_t>(real(q1) + real(q2), imag1(q1) + imag1(q2), 
                           imag2(q1) + imag2(q2), imag3(q1) + imag3(q2));
}

template <class float_t> inline quaternion<float_t> 
operator + (const quaternion<float_t>& q, const complex<float_t>& z) 
{
  return quaternion<float_t>(real(q) + real(z), imag1(q) + imag(z), 
                           imag2(q), imag3(q));
}

template <class float_t> inline quaternion<float_t> 
operator + (const complex<float_t>& z, const quaternion<float_t>& q) 
{
  return quaternion<float_t>(real(q) + real(z), imag1(q) + imag(z), 
                           imag2(q), imag3(q));
}

template <class float_t> inline quaternion<float_t> 
operator + (const quaternion<float_t>& q, float_t d)
{
  return quaternion<float_t>(real(q) + d, imag1(q), imag2(q), imag3(q));
}

template <class float_t> inline quaternion<float_t> 
operator + (float_t d, const quaternion<float_t>& q)
{
  return quaternion<float_t>(real(q) + d, imag1(q), imag2(q), imag3(q));
}

// subtraction

template <class float_t> inline quaternion<float_t> 
operator - (const quaternion<float_t>& q1, const quaternion<float_t>& q2)
{
  return quaternion<float_t>(real(q1) - real(q2), imag1(q1) - imag1(q2), 
                           imag2(q1) - imag2(q2), imag3(q1) - imag3(q2));
}

template <class float_t> inline quaternion<float_t> 
operator - (const quaternion<float_t>& q, const complex<float_t>& z)
{
  return quaternion<float_t>(real(q) - real(z), imag1(q) - imag(z), 
                           imag2(q), imag3(q));
}

template <class float_t> inline quaternion<float_t> 
operator - (const complex<float_t>& z, const quaternion<float_t>& q)
{
  return quaternion<float_t>(real(z) - real(q), imag(z) - imag1(q), 
                           -imag2(q), -imag3(q));
}

template <class float_t> inline quaternion<float_t> 
operator - (const quaternion<float_t>& q, float_t d)
{
  return quaternion<float_t>(real(q) - d, imag1(q), imag2(q), imag3(q));
}

template <class float_t> inline quaternion<float_t> 
operator - (float_t d, const quaternion<float_t>& q)
{
  return quaternion<float_t>(d - real(q), -imag1(q), -imag2(q), -imag3(q));
}

// multiplication

template <class float_t> quaternion<float_t> 
operator * (const quaternion<float_t>& q1, const quaternion<float_t>& q2);

template <class float_t> quaternion<float_t> 
operator * (const complex<float_t>& c1, const quaternion<float_t>& q2);

template <class float_t> quaternion<float_t> 
operator * (const quaternion<float_t>& q1, const complex<float_t>& c2);

template <class float_t> inline quaternion<float_t> 
operator * (const quaternion<float_t>& q, float_t d)
{
 return quaternion<float_t>(real(q) * d, imag1(q) * d, imag2(q) * d, imag3(q) * d);
}

template <class float_t> inline quaternion<float_t> 
operator * (float_t d, const quaternion<float_t>& q)
{
 return quaternion<float_t>(real(q) * d, imag1(q) * d, imag2(q) * d, imag3(q) * d);
}

// division

template <class float_t> quaternion<float_t> 
operator / (const quaternion<float_t>& q1, const quaternion<float_t>& q2);

template <class float_t> quaternion<float_t> 
operator / (const quaternion<float_t>& q1, const complex<float_t>& c2);

template <class float_t> quaternion<float_t> 
operator / (const complex<float_t>& c1, const quaternion<float_t>& q2);

template <class float_t> quaternion<float_t> 
operator / (float_t x1, const quaternion<float_t>& q2)
{
  float_t y1(real(q2)), y2(imag1(q2)), y3(imag2(q2)), y4(imag3(q2)),
        f( -x1 / (y1 * y1 + y2 * y2 + y3 * y3 + y4 * y4) );
  return quaternion<float_t>(-f * y1, f * y2, f * y3, f * y4);
}

template <class float_t> inline quaternion<float_t> 
operator / (const quaternion<float_t>& q, float_t d)
{
  float_t t(1.0/d);
  return quaternion<float_t>(real(q) * t, imag1(q) * t, imag2(q) * t, imag3(q) * t);
}

// comparison

template <class float_t> inline bool
operator == (const quaternion<float_t>& q1, const quaternion<float_t>& q2)
{
  return real(q1) == real(q2) && imag1(q1) == imag1(q2) 
         && imag2(q1) == imag2(q2) && imag3(q1) == imag3(q2);
}

template <class float_t> inline bool
operator == (const quaternion<float_t>& q1, const complex<float_t>& c2)
{
  return real(q1) == real(c2) && imag1(q1) == imag(c2) && 
         imag2(q1) == 0 && imag3(q1) == 0;
}

template <class float_t> inline bool
operator == (const complex<float_t>& c2, const quaternion<float_t>& q1)
{
  return real(q1) == real(c2) && imag1(q1) == imag(c2) && 
         imag2(q1) == 0 && imag3(q1) == 0;
}

template <class float_t> inline bool
operator == (const quaternion<float_t>& q, float_t r)
{
  return real(q) == r && imag1(q) == 0 && imag2(q) == 0 && imag3(q) == 0;
}

template <class float_t> inline bool
operator == (float_t r, const quaternion<float_t>& q)
{
  return real(q) == r && imag1(q) == 0 && imag2(q) == 0 && imag3(q) == 0;
}

template <class float_t> inline bool
operator != (const quaternion<float_t>& q1, const quaternion<float_t>& q2)
{
  return real(q1) != real(q2) || imag1(q1) != imag1(q2)
         || imag2(q1) != imag2(q2) || imag3(q1) != imag3(q2);
}

template <class float_t> inline bool
operator != (const quaternion<float_t>& q1, const complex<float_t>& c2)
{
  return real(q1) != real(c2) || imag1(q1) != imag(c2) || 
         imag2(q1) != 0 || imag3(q1) != 0;
}

template <class float_t> inline bool
operator != (const complex<float_t>& c2, const quaternion<float_t>& q1)
{
  return real(q1) != real(c2) || imag1(q1) != imag(c2) || 
         imag2(q1) != 0 || imag3(q1) != 0;
}

template <class float_t> inline bool
operator != (const quaternion<float_t>& q, float_t r)
{
  return real(q) != r || imag1(q) != 0 || imag2(q) != 0 || imag3(q) != 0;
}

template <class float_t> inline bool
operator != (float_t r, const quaternion<float_t>& q)
{
  return real(q) != r || imag1(q) != 0 || imag2(q) != 0 || imag3(q) != 0;
}

// stream IO

template <class float_t> 
istream& operator >> (istream& is, quaternion<float_t>& q);

template <class float_t> 
ostream& operator << (ostream& os, const quaternion<float_t>& q);

//-----------------------------------------------------------------------------//
// include the specializations
//-----------------------------------------------------------------------------//

#include "fquaternion.h"        // <float>
#include "dquaternion.h"        // <double>

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
