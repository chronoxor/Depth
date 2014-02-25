/*-----------------------------------------------------------------------------*\
| template class for multiple array sort                          mpmultisort.h |
|       								        |
| Last change: Dec 30, 2002							|
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2002 by Berndt M. Gammel. All rights reserved.             |
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

#ifndef _MPMULTISORT_H_
#define _MPMULTISORT_H_

//-----------------------------------------------------------------------------//
//
// template <class T1, class T2> 
// inline void MpMultiSort (int n, T1 x[], T2 y[])
//
// Description:
// ------------
//
// Sort vector x[0..n-1] into ascending order while making the corresponding
// rearrangements in the array y[0..n-1]. x and y are arrays of arbitrary
// different classes T1 and T2. T1 must supply a less-than operator '<'.
// Both classes must supply indexing using the [] operator. 
// Both arrays are assumed to have zero offset.
//
// Notes:
// ------
// The heap sort algorithm is used. This is a O(n*log(n)) algorithm, but unlike 
// quicksort its worst case behavior is also O(n*log(n)) being only 20% slower 
// than the average case. It is a true inplace algorithm with no extra storage
// requirements.
//
//-----------------------------------------------------------------------------//

template <class T1, class T2> 
inline void MpMultiSort (int n, T1 x[], T2 y[])
{
  if (n < 2) return;

  // adjust to zero-offset array, because algorithm is natively 
  // formulated with one-offset
  T1 *v = &x[-1];
  T2 *w = &y[-1];
  T1 rv;
  T2 rw;
    
  int i,j;
  int l = (n >> 1) + 1;
  int k = n;
  for (;;) {
    if (l > 1) {
      rv = v[--l];
      rw = w[l];
    } else {
      rv = v[k];
      rw = w[k];
      v[k] = v[1];
      w[k] = w[1];
      if (--k == 1) {
	v[1] = rv;
	w[1] = rw;
	return;
      }
    }
    i = l;
    j = l << 1;
    while (j <= k) {
      if (j < k && v[j] < v[j+1]) ++j;
      if (rv < v[j]) {
	v[i] = v[j];
	w[i] = w[j];
	j += (i = j);
      } else 
	j = k + 1;
    }
    v[i] = rv;
    w[i] = rw;
  }
}

//-----------------------------------------------------------------------------//

#endif
