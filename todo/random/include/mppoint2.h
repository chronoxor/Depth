/*-----------------------------------------------------------------------------*\
| Matpack - template class MpPoint2 for 2D coordinate                mppoint2.h |
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

// check for multiple inclusion
#ifndef _MPPOINT2_H_
#define _MPPOINT2_H_

//----------------------------------------------------------------------------//

#include <iostream>

namespace MATPACK {
using namespace std;

//----------------------------------------------------------------------------//
// class MpPoint2 - 2D point coordinate
//----------------------------------------------------------------------------//

template <class T> 
class MpPoint2 {

  protected:
    T px, py;

  public:
    MpPoint2 (void) { }
    MpPoint2 (T x, T y) : px(x), py(y) { }
    T GetX (void) const;          // return px
    T GetY (void) const;          // return py
    T& X (void);                  // return reference to px
    T& Y (void);                  // return reference to py
    void SetX (T x);              // set px
    void SetY (T y);              // set py
    void Set  (T x, T y);         // set px and py
    bool IsNull (void) const;     // return true if both, px and py, are zero
};

//-----------------------------------------------------------------------------//
// implementation of inline member function of class MpPoint2
//-----------------------------------------------------------------------------//

template <class T>
inline T MpPoint2<T>::GetX (void) const
{ return px; }

template <class T>
inline T MpPoint2<T>::GetY (void) const
{ return py; }

template <class T>
inline T& MpPoint2<T>::X (void)
{ return px; }

template <class T>
inline T& MpPoint2<T>::Y (void)
{ return py; }

template <class T>
inline void MpPoint2<T>::SetX (T x)
{ px = x; } 

template <class T>
inline void MpPoint2<T>::SetY (T y)
{ py = y; }

template <class T>
inline void MpPoint2<T>::Set (T x, T y)
{ px = x; py = y; } 

template <class T>
inline bool MpPoint2<T>::IsNull (void) const
{ return px == 0 && py == 0; }

//-----------------------------------------------------------------------------//
// implementation of other functions with MpPoint2<T> arguments
//-----------------------------------------------------------------------------//

template <class T>
inline bool operator == (const MpPoint2<T>& p1, const MpPoint2<T>& p2)
{ return p1.GetX() == p2.GetX() && p1.GetY() == p2.GetY(); }

template <class T>
inline bool operator != (const MpPoint2<T>& p1, const MpPoint2<T>& p2)
{ return p1.GetX() != p2.GetX() || p1.GetY() != p2.GetY(); }
    
template <class T>
inline ostream& operator << (ostream& os, const MpPoint2<T>& p)
{ return os << "MpPoint2(" << p.GetX() << "," << p.GetY() << ")"; }

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
