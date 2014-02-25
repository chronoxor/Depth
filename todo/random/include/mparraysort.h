/*-----------------------------------------------------------------------------*\
| Matpack - MpArraySort () - general array sort function          mparraysort.h |
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

#ifndef _MPARRAYSORT_H_
#define _MPARRAYSORT_H_

#include "common.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// void MpArraySort (void *data, int count, int size, int stride, int offset, 
//                   mparraysort_less_t less)
//
// This is function provides a general sort algorithm for arbitrary data arrays.
// It has a very flexible interface to support sorting of multi-dimensional arrays.
//
// The function is based on the heap sort algorithm and sorts the data with 
// O(n log n) operations. Note, that the heap sort algorithm is not stable,
// i.e. elements which are equal in the comparison will not stay in the 
// original order. The worst case (an already sorted array) is about 20% slower 
// than the average.
//
// Arguments:
// ----------
//   void *data     Base pointer of the data array. It should point to the
//                  first data block.
//   
//   int count      Number of data blocks.
//   
//   int size       Size of a data block in bytes.
//   
//   int stride     Stride for data elements to allow skipping of 
//                  data blocks. Use stride = 1 if there are no blocks to skip.
//   
//   int offset     Offset in bytes within data block. This offset is needed to
//                  specify the address of the ordering key within the data block.
//                  If the key is identical to the data the offset is zero.
//
//   mparraysort_less_t less
//
//                  Prototype:
//                    typedef bool (*mparraysort_less_t)(const void *x, const void *y);
//
//                  The comparison function should return true if the first
//                  argument is smaller than the second argument, otherwise false.
//
//                  Example for sorting doubles into increasing order:
//
//                    bool less_than (const void *a, const void *b)
//                    {
//                    	  return *(double*)a < *(double*)b;
//                    }
//
// Example:
// --------
//  The array below contains 5 data blocks each of which contains
//  3 elements which are assumed to be double precision numbers.
//  The sorting key is the middle element of each block. The blocks
//  should be sorted by the keys into decreasing numerical order. 
//
//  +----------+---------+----------+---------+----------+
//  |  0  1  6 | 9  4  5 |  8  7  2 | 3 10 11 | 14 13 12 |
//  +-----^----+----^----+-----^----+----^----+-----^----+
//
//  The expected result is                         
//
//  +----------+---------+----------+---------+----------+
//  | 14 13 12 | 3 10 11 |  8  7  2 | 9  4  5 | 0  1   6 |
//  +-----^----+----^----+-----^----+----^----+----^-----+
//
//  This is achieved by the call
//
//    MpArraySort(data, 5, 3*sizeof(double), 1, sizeof(double), less_than);
//
//  Note that size and offset are given in units of bytes.
//
//  As you may have noticed this corresponds to sorting the rows of
//  a 2-dimensional array (stored in row-order) using the elements
//  of the second column as keys (pivots).
//
//      0  1  6               14 13 12
//      9  4  5                3 10 11
//      8  7  2    sort =>     8  7  2 
//      3 10 11                9  4  5
//     14 13 12                0  1  6 
//        ^^
//       pivots
//
//-----------------------------------------------------------------------------//

typedef bool (*mparraysort_less_t)(const void *x, const void *y);

void MpArraySort (void *data, int count, int size, int stride, int offset, 
		  mparraysort_less_t less);

//-----------------------------------------------------------------------------//

} // namespace MATPACK

#endif

