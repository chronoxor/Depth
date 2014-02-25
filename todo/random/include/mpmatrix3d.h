/*-----------------------------------------------------------------------------*\
| template class MpMatrix3d                                        mpmatrix3d.h |
|                                                                               |
| Last change: Dec 17, 2005                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel. All rights reserved.             |
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

// avoid multiple inclusion
#ifndef _MATRIX3D_H_
#define _MATRIX3D_H_

//----------------------------------------------------------------------------//
// template <class TYPE> class MpMatrix3d
//----------------------------------------------------------------------------//
//
// This is a basically non-arithmetic matrix container class for 3-dimensional
// matrices. This is an array accessed by three indices given in the usual C
// order (reverse to the Fortran index order).
//
// The following naming semantics for the indices is used consistently 
// througout the Matpack library:
//                  
//   1d-arrays:                       column  
//   2d-arrays:                 row   column
//   3d-arrays:         slice   row   column
//   4d-arrays:  plane  slice   row   column
//
// For instance the declaration
//
//       MpMatrix3d<double> M(1,5, 0,10, -3,3);
//
// creates a 3-dimensional array with the slice (1st) indices running from
// 1 to 5, with the row (2nd) indices running from 0 to 10, and with the 
// column indices running from -3 to 3.
//
// No arithmetic operations can be performed with 3D matrices. 
// They are only intended for storing and indexing values. Only indexing, 
// assignment, comparison, input-output and extrema finding is implemented.
//
// Currently the types
// 
//      float
//      double
//      complex<float>
//      complex<double>
//      int
//      byte        (unsigned char)
// 
// are supported.
//
//----------------------------------------------------------------------------//
//
// Implementation hints:
//
// o  A reference count scheme is used to prevent garbage on the heap
//    when a matrix or vector variable becomes Unbound !
//
//----------------------------------------------------------------------------//

#include "common.h"	 // uses common definitions - must be first one
#include "../source/Vector/vecinl.h"

namespace MATPACK {

//----------------------------------------------------------------------------//
// Reference block definition
//----------------------------------------------------------------------------//

struct MpReference3 { 
    short count; // reference count
    MpReference3 (void) { count = 1; }
};

//----------------------------------------------------------------------------//
// 3-dimensional  double precision matrix class
//----------------------------------------------------------------------------//
// This is a basically non-arithmetic matrix class. That means no arithmetics
// can be performed with 3D matrices. They are only intended for indexing
// purposes, sorting, book keeping, etc... but not for arithmetic combination 
// with double or complex matrices. Only indexing, assignment, comparison,I/O,
// and extrema finding is implemented.
//----------------------------------------------------------------------------//

class MpMatrix3dBase {

  protected:
    int sl,sh,rl,rh,cl,ch,nsli,ncol,nrow,nelem;    
    short temporary,form;      
    struct MpReference3 *D;
    inline void addref (void) const { if (D) ++(D->count); }  
    MpMatrix3dBase (void) { temporary = 0; form = MpTextFormat; }

  public:
    inline int Slo (void) const { return sl; }  
    inline int Shi (void) const { return sh; }
    inline int Rlo (void) const { return rl; }  
    inline int Rhi (void) const { return rh; }  
    inline int Clo (void) const { return cl; }  
    inline int Chi (void) const { return ch; }
    inline int Slices (void) const { return nsli; }  
    inline int Rows (void) const { return nrow; }  
    inline int Columns (void) const { return ncol; }  
    inline int Elements (void) const { return nelem; }
    inline bool Empty (void) const { return (D == 0); }
};

//----------------------------------------------------------------------------//

template <class T> 
class MpMatrix3d : public MpMatrix3dBase 
{
  protected:

    T *M;

  public:

    // constructors
    MpMatrix3d (void);
    MpMatrix3d (int,int,int,int,int,int);
    MpMatrix3d (int,int,int,int,int,int,T);

    // copy constructor
    MpMatrix3d (const MpMatrix3d<T>&);
    
    // destructor
   ~MpMatrix3d (void);
    
    // indexing
    T& operator () (int s, int r, int c);
    const T& operator () (int s, int r, int c) const;

    // assignment
    const MpMatrix3d& operator = (const MpMatrix3d<T>&);

    // setting of elements
    void Set(T);
    void Set(void(*mapper)(T &elem));
    void Set(void(*mapper)(int s, int r, int c, T &elem));

    // create return value
    inline MpMatrix3d& Value (void) 
      { temporary = 1; --(D->count); return *this; } 

    // member functions
    inline T* Store (void) const;

    inline MpMatrix3d&  Format (int format) 
      { form = format; return *this; }

    inline int Format (void) const { return form; }

    void Remove (void);

    // special
    bool Unbound (void) const;
    void checkdim (const MpMatrix3d<T>&) const;

/*    
    T        Min   (const MpMatrix3d<T>&,int&,int&,int&);
    T        Max   (const MpMatrix3d<T>&,int&,int&,int&);
    int      MatchingIndexRange (const MpMatrix3d<T>&,const MpMatrix3d<T>&);
*/
};
  
//----------------------------------------------------------------------------//
// inline member functions
//----------------------------------------------------------------------------//

template <class T>
inline T& MpMatrix3d<T>::operator () (int s, int r, int c) 
{
#if defined(DEBUG) || defined (IndexRangeChecking) || defined (MpMatrix3dIndexRangeChecking)
  if (s < sl || s > sh || r < rl || r > rh || c < cl || c > ch)
    Matpack.Error("MpMatrix3d: index out of range (%d,%d,%d)", s,r,c);	
#endif
  return M[s-sl+nsli*(r-rl+nrow*(c-cl))];
}

template <class T>
inline const T& MpMatrix3d<T>::operator() (int s, int r, int c) const 
{
#if defined(DEBUG) || defined (IndexRangeChecking) || defined (MpMatrix3dIndexRangeChecking)
  if (s < sl || s > sh || r < rl || r > rh || c < cl || c > ch)
    Matpack.Error("MpMatrix3d: index out of range (%d,%d,%d)", s,r,c);	
#endif
  return M[s-sl+nsli*(r-rl+nrow*(c-cl))];
}

template <class T>
inline T* MpMatrix3d<T>::Store (void) const 
{ return (D == 0) ? (T*)0 : M; }

template <class T>
inline bool MpMatrix3d<T>::Unbound (void) const
{ return (temporary == 1); }

//----------------------------------------------------------------------------//
// comparison and extrema
//----------------------------------------------------------------------------//

template <class T>
bool operator == (const MpMatrix3d<T> &A, const MpMatrix3d<T> &B);

template <class T>
bool operator != (const MpMatrix3d<T> &A, const MpMatrix3d<T> &B);


template <class T>
T Min (const MpMatrix3d<T>&);

template <class T>
T Max (const MpMatrix3d<T>&);

//----------------------------------------------------------------------------//
// stream input/output
//----------------------------------------------------------------------------//

template <class T>
ostream& operator << (ostream&, const MpMatrix3d<T>&);

template <class T>
istream& operator >> (istream&, MpMatrix3d<T>&);


//----------------------------------------------------------------------------//
// prototypes
//----------------------------------------------------------------------------//

void MpQuantile (const float *a, unsigned n, unsigned m, 
		 float q, float &pqq, float &pstdv);

void MpQuantile (const double *a, unsigned n, unsigned m, 
		 double q, double &pqq, double &pstdv);

inline void MpQuantile (const MpMatrix3d<float> &a, int m, float q, 
			float &qq, float &stdv)
{
  MpQuantile (a.Store(), a.Elements(), (unsigned) m, q, qq, stdv); 
}

inline void MpQuantile (const MpMatrix3d<double> &a, int m, double q, 
			double &qq, double &stdv)
{
  MpQuantile (a.Store(), a.Elements(), (unsigned) m, q, qq, stdv); 
}

} // namespace MATPACK

#endif

//----------------------------------------------------------------------------//
