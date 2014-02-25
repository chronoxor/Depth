/*-----------------------------------------------------------------------------*\
| Matpack - template class MpRectangle                            mprectangle.h |
|                                                                               |
| Last change: Sep 12, 2004                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel. All rights reserved              |
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

// check for multiple inclusion
#ifndef _MPRECTANGLE_H_
#define _MPRECTANGLE_H_

//-----------------------------------------------------------------------------//

#include "common.h"
#include "mppoint2.h"
#include <string>

namespace MATPACK {
using std::string;

//-----------------------------------------------------------------------------//
// template <class T> class MpRectangle
//
// Note that width and height of this rectangle class implementation is
// different from the usual mathematical notion of a rectangles size. If the 
// top left corner and the bottom right corner are identical, then the height 
// and the width of the rectangle will both be 1.
// I.e. width = right-left+1 and height = bottom-top+1. This correspond to
// rectangular boxes used by drawing functions, where the width and
// height denote the number of pixels. For example, drawing a rectangle
// with width and height 1 draws a single pixel.
// Hence, using float or double as base will give surprising results
// when calling e.g. the member function Contains().
//-----------------------------------------------------------------------------//

template <class T> 
class MpRectangle
{
  private:
    T x1, y1, x2, y2;

  public:
    MpRectangle (void);         // Constructs an empty rectangle.

    MpRectangle (T left, T top, T width, T height);
                                // Constructs a rectangle with given top, left 
                                // corner and width and height.

    bool IsEmpty (void) const;  // An empty rectangle has a left > right
                                // or top > bottom().
    bool IsNull (void) const;   // A null rectangle has both the width and the 
                                // height equal to 0, that is right==left()-1 
                                // and bottom==top-1. (Is also Empty !)

    void SetLeft (T pos);       // Sets the left edge of the rectangle. May
                                // change the width (but not the right edge).
    T GetLeft (void) const;     // Returns the left coordinate of the rectangle.

    void SetTop (T pos);        // Sets the top edge of the rectangle. May 
                                // change the height (but not the bottom edge).
    T GetTop (void) const;      // Returns the top coordinate of the rectangle.

    void SetRight (T pos);      // Sets the right edge of the rectangle. May
                                // change the width (but not the left edge).
    T GetRight (void) const;    // Returns the right coordinate of the rectangle.

    void SetBottom (T pos);     // Sets the bottom edge of the rectangle. May
                                // change the height (but not the top edge).
    T GetBottom (void) const;   // Returns the bottom coordinate of the rectangle.


    void SetWidth (T w);        // Sets the width of the rectangle to w. 
                                // Only the right edge is moved.
    T GetWidth (void) const;    // Returns the width of the rectangle. The width 
                                // includes both edges, i.e. right - left + 1.

    void SetHeight (T h);       // Sets the height of the rectangle to  h.
                                // Only the top edge is moved.
    T GetHeight (void) const;   // Returns the height of the rectangle. The height
                                // includes both edges, i.e. bottom - top + 1.

    void Set (T x, T y, T w, T h);
                                // Sets the rectangle's top left corner to (x,y), 
                                // and its size to (w,h).
    void Get (T &x, T &y, T &w, T &h ) const;
                                // Gets the rectangle's top left corner (x,y), 
                                // and its size to (w,h).

    void SetCoords (T xp1, T yp1, T xp2, T yp2);
                                // Sets the rectangle's top left corner (xp1,yp1), 
                                // and bottom right corner (xp2,yp2).
    void GetCoords (T &xp1, T &yp1, T &xp2, T &yp2) const;
                                // Gets the rectangle's top left corner (xp1,yp1), 
                                // and bottom right corner (xp2,yp2).

    void SetSize (T w, T h);    // Sets the size of the rectangle to (w,h). 
                                // The top left corner is not moved.

    const MpPoint2<T> GetTopLeft (void) const;
                                // Return the top left position of the rectangle.
    const MpPoint2<T> GetBottomRight (void) const;
                                // Return the bottom right position of the rectangle.
    const MpPoint2<T> GetTopRight (void) const;
                                // Return the top right position of the rectangle.
    const MpPoint2<T> GetBottomLeft (void) const;
                                // Return the bottom left position of the rectangle. 
    const MpPoint2<T> GetCenter (void) const;
                                // Returns the center point of the rectangle.

    bool  Contains (const MpPoint2<T> &p, bool strict = false) const;
                                // Returns true if the point p is inside or on the 
                                // edge of the rectangle. If strict is true then
                                // the point must be inside the rectangle.

    bool  Contains (const MpRectangle<T> &r, bool strict = false) const;
                                // Returns true if the rectangle  r is inside this
                                // rectangle. If strict is true then it must be
                                // be entirely inside (not on the edge).

    const MpRectangle<T>  Normalize (void) const;
                                // Normalize a bad rectangle, i.e. swap left-right
                                // or top-bottom coordinates if not increasing.

    const MpRectangle<T> Union (const MpRectangle<T> &r) const;
                                // Returns the union rectangle of this rectangle 
                                // and r. The union of a non-empty rectangle and an 
                                // empty rectangle is the nonempty rectangle.

    const MpRectangle<T> Intersection (const MpRectangle<T> &r) const;
                                // Returns the intersection of this rectangle and r.
                                // Returns an empty rectangle if there is no 
                                // intersection.

    bool  HasIntersection (const MpRectangle<T> &r) const;
                                // Returns true if this rectangle overlaps with r
                                // (there is at least one pixel common point).

    void  MoveTopLeft (const MpPoint2<T> &p);
                                // Sets the top left position to p, leaving the
                                // size unchanged.
    void  MoveBottomRight (const MpPoint2<T> &p);
                                // Sets the bottom right position to p, leaving the
                                // size unchanged.
    void  MoveTopRight (const MpPoint2<T> &p);
                                // Sets the top right position to p, leaving the
                                // size unchanged.
    void  MoveBottomLeft (const MpPoint2<T> &p);
                                // Sets the bottom left position to p, leaving the
                                // size unchanged.
    void  MoveCenter (const MpPoint2<T> &p);
                                // Sets the center point position to p, leaving the
                                // size unchanged.
    void  MoveBy (T dx, T dy);
                                // Moves the rectangle dx along the X axis and dy 
                                // along the Y axis, relative to the current position
                                // (Positive values move rightwards/downwards.)
    int read  (istream& is);
    int write (ostream& os) const;
};

//-----------------------------------------------------------------------------//
// implementation of inline member functions
//-----------------------------------------------------------------------------//

template <class T>  
inline MpRectangle<T>::MpRectangle (void) 
{ x1 = y1 = 0; x2 = y2 = -1; } 

template <class T>  
inline MpRectangle<T>::MpRectangle (T left, T top, T width, T height )
{
  x1 = left;
  y1 = top;
  x2 = left+width-1;
  y2 = top+height-1;
}

template <class T>  
inline bool MpRectangle<T>::IsEmpty (void) const
{ return x1 > x2 || y1 > y2; }

template <class T>  
inline bool MpRectangle<T>::IsNull (void) const
{ return x2 == x1-1 && y2 == y1-1; }

template <class T>  
inline T MpRectangle<T>::GetLeft (void) const
{ return x1; }

template <class T>  
inline T MpRectangle<T>::GetTop (void) const
{ return y1; }

template <class T>  
inline T MpRectangle<T>::GetRight (void) const
{ return x2; }

template <class T>  
inline T MpRectangle<T>::GetBottom (void) const
{ return y2; }

template <class T>  
inline void MpRectangle<T>::SetLeft (T pos)
{ x1 = pos; }

template <class T>  
inline void MpRectangle<T>::SetTop (T pos)
{ y1 = pos; }

template <class T>  
inline void MpRectangle<T>::SetRight (T pos)
{ x2 = pos; }

template <class T>  
inline void MpRectangle<T>::SetBottom (T pos)
{ y2 = pos; }

template <class T>  
void MpRectangle<T>::SetWidth (T w)
{ x2 = x1 + w - 1; }

template <class T>  
void MpRectangle<T>::SetHeight (T h)
{ y2 = y1 + h - 1; }

template <class T>  
void MpRectangle<T>::SetSize (T w, T h)
{ x2 = x1 + w - 1; y2 = y1 + h - 1; }

template <class T>  
void MpRectangle<T>::Set (T x, T y, T w, T h)
{
  x1 = x;     
  y1 = y;
  x2 = x+w-1; 
  y2 = y+h-1;
}

template <class T>  
void MpRectangle<T>::Get (T &x, T &y, T &w, T &h) const
{
  x = x1;
  y = y1;
  w = x2-x1+1;
  h = y2-y1+1;
}

template <class T>  
void MpRectangle<T>::SetCoords (T xp1, T yp1, T xp2, T yp2)
{
  x1 = xp1;
  y1 = yp1;
  x2 = xp2;
  y2 = yp2;
}

template <class T>  
void MpRectangle<T>::GetCoords (T &xp1, T &yp1, T &xp2, T &yp2) const
{
  xp1 = x1;
  yp1 = y1;
  xp2 = x2;
  yp2 = y2;
}

template <class T>  
inline T MpRectangle<T>::GetWidth() const
{ return  x2 - x1 + 1; }

template <class T>  
inline T MpRectangle<T>::GetHeight() const
{ return  y2 - y1 + 1; }


template <class T>  
inline const MpPoint2<T> MpRectangle<T>::GetTopLeft (void) const
{ return MpPoint2<T>(x1,y1); }

template <class T>  
inline const MpPoint2<T> MpRectangle<T>::GetBottomRight (void) const
{ return MpPoint2<T>(x2,y2); }

template <class T>  
inline const MpPoint2<T> MpRectangle<T>::GetTopRight (void) const
{ return MpPoint2<T>(x2,y1); }

template <class T>  
inline const MpPoint2<T> MpRectangle<T>::GetBottomLeft (void) const
{ return MpPoint2<T>(x1,y2); }

template <class T>  
inline const MpPoint2<T> MpRectangle<T>::GetCenter (void) const
{ return MpPoint2<T>((x1+x2)/2, (y1+y2)/2); }

template <class T>  
bool MpRectangle<T>::Contains (const MpPoint2<T> &p, bool strict) const
{
  return (strict) ? (p.GetX() >  x1 && p.GetX() <  x2 &&
                     p.GetY() >  y1 && p.GetY() <  y2)
                  : (p.GetX() >= x1 && p.GetX() <= x2 &&
                     p.GetY() >= y1 && p.GetY() <= y2);
}

template <class T>  
bool MpRectangle<T>::Contains (const MpRectangle<T> &r, bool strict) const
{
  return (strict) ? (r.x1 > x1 && r.x2 < x2 && r.y1 > y1 && r.y2 < y2)
                  : (r.x1 >= x1 && r.x2 <= x2 && r.y1 >= y1 && r.y2 <= y2);
}

template <class T>  
const MpRectangle<T> MpRectangle<T>::Normalize (void) const
{
  MpRectangle<T> r;
  if (x2 < x1) {        // swap bad x values
    r.x1 = x2;
    r.x2 = x1;
  } else {
    r.x1 = x1;
    r.x2 = x2;
  }
  if (y2 < y1) {        // swap bad y values
    r.y1 = y2;
    r.y2 = y1;
  } else {
    r.y1 = y1;
    r.y2 = y2;
  }
  return r;
}

template <class T> 
const MpRectangle<T> MpRectangle<T>::Union (const MpRectangle<T> &r) const
{
  if ( ! IsEmpty() ) {
    if ( ! r.IsEmpty() ) {
      MpRectangle<T> tmp;
      tmp.SetLeft  ( MpMin(x1,r.x1) );
      tmp.SetRight ( MpMax(x2,r.x2) );
      tmp.SetTop   ( MpMin(y1,r.y1) );
      tmp.SetBottom( MpMax(y2,r.y2) );
      return tmp;
    } else 
      return *this;
  } else
    return r;
}

template <class T> 
const MpRectangle<T> MpRectangle<T>::Intersection (const MpRectangle<T> &r) const
{
  MpRectangle<T> tmp;
  tmp.x1 = MpMax(x1, r.x1);
  tmp.x2 = MpMin(x2, r.x2);
  tmp.y1 = MpMax(y1, r.y1);
  tmp.y2 = MpMin(y2, r.y2);
  return tmp;
}

template <class T> 
bool MpRectangle<T>::HasIntersection (const MpRectangle<T> &r) const
{
  return ( MpMax<T>(x1, r.x1) <= MpMin<T>(x2, r.x2) &&
           MpMax<T>(y1, r.y1) <= MpMin<T>(y2, r.y2) );
}

template <class T>  
inline void MpRectangle<T>::MoveTopLeft (const MpPoint2<T> &p)
{
  x2 += p.GetX() - x1;
  y2 += p.GetY() - y1;
  x1 = p.GetX();
  y1 = p.GetY();
}

template <class T>  
inline void MpRectangle<T>::MoveBottomRight (const MpPoint2<T> &p)
{
  x1 += p.GetX() - x2;
  y1 += p.GetY() - y2;
  x2 = p.GetX();
  y2 = p.GetY();
}

template <class T>  
inline void MpRectangle<T>::MoveTopRight (const MpPoint2<T> &p)
{
  x1 += p.GetX() - x2;
  y2 += p.GetY() - y1;
  x2 = p.GetX();
  y1 = p.GetY();
}

template <class T>  
inline void MpRectangle<T>::MoveBottomLeft (const MpPoint2<T> &p)
{
    x2 += p.GetX() - x1;
    y1 += p.GetY() - y2;
    x1 = p.GetX();
    y2 = p.GetY();
}

template <class T>  
void MpRectangle<T>::MoveCenter (const MpPoint2<T> &p)
{
  T w = x2 - x1,
    h = y2 - y1;
  x1 = p.GetX() - w/2;
  y1 = p.GetY() - h/2;
  x2 = x1 + w;
  y2 = y1 + h;
}

template <class T>  
inline void MpRectangle<T>::MoveBy (T dx, T dy)
{
  x1 += dx;
  y1 += dy;
  x2 += dx;
  y2 += dy;
}

//-----------------------------------------------------------------------------//
// implementation of other rectangle functions
//-----------------------------------------------------------------------------//
 
// Returns true if r1 and r2 are equal, or false if they are different.
template <class T>  
inline bool operator == (const MpRectangle<T> &r1, const MpRectangle<T> &r2)
{
  return r1.GetLeft()==r2.GetLeft() && r1.GetRight() ==r2.GetRight() && 
         r1.GetTop() ==r2.GetTop()  && r1.GetBottom()==r2.GetBottom();
}

// Returns true if r1 and r2 are different, or false if they are equal.
template <class T>  
inline bool operator != (const MpRectangle<T> &r1, const MpRectangle<T> &r2)
{    
  return r1.GetLeft()!=r2.GetLeft() || r1.GetRight() !=r2.GetRight() || 
         r1.GetTop() !=r2.GetTop()  || r1.GetBottom()!=r2.GetBottom();
}

//-----------------------------------------------------------------------------//

// Writes a MpRectangle to the stream and returns a reference to the stream.
// Format: "MpRectangle(left,top,width,height)"  

template <class T>  
inline int MpRectangle<T>::read (istream& is)
{
  string word;
  T x,y,w,h;
  getline(is,word,'(');
  is >> x;
  getline(is,word,',');
  is >> y;
  getline(is,word,',');
  is >> w;
  getline(is,word,',');
  is >> h;
  getline(is,word,')');
  Set(x,y,w,h);
  return (is.fail()) ? 1 : 0;
}

template <class T>  
inline int MpRectangle<T>::write (ostream& os) const
{
  os << "MpRectangle(" << GetLeft() << ","  << GetTop() << ","
                       << GetWidth() << "," << GetHeight() << ")";
  return (os.fail()) ? 1 : 0;  
}

//-----------------------------------------------------------------------------//

template <class T>
inline istream& operator >> (istream& is, MpRectangle<T>& r) { 
  r.read(is); return is; 
}

template <class T>
inline ostream& operator << (ostream& os, const MpRectangle<T>& r) {
  r.write(os); return os;
}

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
