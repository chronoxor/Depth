/*-----------------------------------------------------------------------------*\
| Matpack random generator - class RanLux                            ranlux.cpp |
|                                                                               |
| Last change: Nov 5, 2005                                                      |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel                                   |
|                                                                               |
| Permission to  use, copy, and  distribute  Matpack  in  its  entirety and its | 
| documentation for  non-commercial purpose and  without fee is hereby granted, | 
| provided that this license information and copyright notice appear unmodified | 
| in all copies. This software is provided 'as is'  without  express or implied | 
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

#include "mprandom.h"
#include <cassert>

//-----------------------------------------------------------------------------//
// Includes
//-----------------------------------------------------------------------------//

#include "common.h"

// define to get debugging output
//#define _RANLUX_DEBUG_

#ifdef _RANLUX_DEBUG_
#include <iostream>
#endif

namespace MATPACK {

//-----------------------------------------------------------------------------//
// Subtract-and-borrow random number generator proposed by 
// Marsaglia and Zaman, implemented by F. James with the name 
// RCARRY in 1991, and later improved by Martin Luescher 
// in 1993 to produce "Luxury Pseudorandom Numbers". 
// Fortran 77 coded by F. James, 1993 
//
// LUXURY LEVELS 
// -------------
// The available luxury levels are: 
//
//  level 0  (p=24): equivalent to the original RCARRY of Marsaglia 
//           and Zaman, very long period, but fails many tests. 
//  level 1  (p=48): considerable improvement in quality over level 0, 
//           now passes the gap test, but still fails spectral test. 
//  level 2  (p=97): passes all known tests, but theoretically still 
//           defective. 
//  level 3  (p=223): DEFAULT VALUE.  Any theoretically possible 
//           correlations have very small chance of being observed. 
//  level 4  (p=389): highest possible luxury, all 24 bits chaotic. 
//
//
// Calling sequences for RANLUX
// ----------------------------
//      CALL RANLUX (RDUM) returns a 
//                   32-bit random floating point numbers between
//                   zero (not included) and one (also not incl.).
//
//      CALL RLUXGO(LUX,INT,K1,K2) initializes the generator from
//               one 32-bit integer INT and sets Luxury Level LUX
//               which is integer between zero and MAXLEV, or if
//               LUX .GT. 24, it sets p=LUX directly.  K1 and K2 
//               should be set to zero unless restarting at a break 
//               point given by output of RLUXAT (see RLUXAT). 
//
//      CALL RLUXAT(LUX,INT,K1,K2) gets the values of four integers 
//               which can be used to restart the RANLUX generator 
//               at the current point by calling RLUXGO.  K1 and K2 
//               specify how many numbers were generated since the 
//               initialization with LUX and INT.  The restarting 
//               skips over  K1+K2*E9   numbers, so it can be long. 
//
//   A more efficient but less convenient way of restarting is by: 
//      CALL RLUXIN(ISVEC)    restarts the generator from vector 
//                   ISVEC of 25 32-bit integers (see RLUXUT) 
//      CALL RLUXUT(ISVEC)    outputs the current values of the 25 
//                 32-bit integer seeds, to be used for restarting 
//      ISVEC must be dimensioned 25 in the calling program
//-----------------------------------------------------------------------------//

static void ranlux_driver (int what, double *rdum, 
			   int *isdext, int *lout, int *inout, 
			   int *k1, int *k2, int lux, int ins)
{
  static int notyet = true;
  static int luxlev = 3;
  static int in24 = 0;
  static int kount = 0;
  static int mkount = 0;
  static int i24 = 24;
  static int j24 = 10;
  static int ndskip[5] = { 0,24,73,199,365 };
  static double carry = 0.0;

  static int next[24];
  static int nskip;
  static int inseed;
  static double seeds[24];
  static double twom12, twom24;

  // System generated locals 
  int i__1, i__2;

  // Local variables 
  int izip;
  int inner;
  int izip2, i, k, jseed;
  int lp;
  int iseeds[24], iouter, isd, isk;
  int ilx;

  double uni;

  // Parameter adjustments to 1-offset
  if (isdext) --isdext;

  switch (what) {
    case 1: goto L_rluxin;
    case 2: goto L_rluxut;
    case 3: goto L_rluxat;
    case 4: goto L_rluxgo;
  }

  //                                     default 
  // Luxury Level      0      1       2   *3*     4 
  // corresponds to p=24     48      97   223   389 
  // time factor       1      2       3     6    10   on slow workstation 
  //                   1      1.5     2     3     5   on fast mainframe 

  // notyet is true if no initialization has been performed yet. 
  // Default Initialization by Multiplicative Congruential 
  if (notyet) {
    notyet = false;
    jseed = 314159265;
    inseed = jseed;

#ifdef _RANLUX_DEBUG_
    cout << " RANLUX DEFAULT INITIALIZATION: " << jseed << endl;
#endif

    luxlev = 3;
    nskip = ndskip[luxlev];
    lp = nskip + 24;
    in24 = 0;
    kount = 0;
    mkount = 0;

#ifdef _RANLUX_DEBUG_
    cout << " RANLUX DEFAULT LUXURY LEVEL =  " 
	 << luxlev << " " << "      p = " << lp << endl;
#endif

    twom24 = 1.0;
    for (i = 1; i <= 24; ++i) {
      twom24 *= 0.5;
      k = jseed / 53668;
      jseed = (jseed - k * 53668) * 40014 - k * 12211;
      if (jseed < 0) jseed += 2147483563;
      iseeds[i - 1] = jseed % 16777216;
    }
    twom12 = twom24 * 4096.0;
    for (i = 1; i <= 24; ++i) {
      seeds[i - 1] = (double) iseeds[i - 1] * twom24;
      next[i - 1] = i - 1;
    }
    next[0] = 24;
    i24 = 24;
    j24 = 10;
    carry = 0.0;
    if (seeds[23] == 0.0) carry = twom24;
  }

  // The Generator proper: "Subtract-with-borrow", 
  // as proposed by Marsaglia and Zaman, 
  // Florida State University, March, 1989 

  uni = seeds[j24-1] - seeds[i24-1] - carry;
  if (uni < 0.0) {
    uni += 1.0;
    carry = twom24;
  } else 
    carry = 0.0;
  
  seeds[i24 - 1] = uni;
  i24 = next[i24 - 1];
  j24 = next[j24 - 1];
  *rdum = uni;

  // small numbers (with less than 12 "significant" bits) are "padded".
  if (uni < twom12) {
    *rdum += twom24 * seeds[j24 - 1];
    // and zero is forbidden in case someone takes a logarithm 
    if (*rdum == 0.0) *rdum = twom24 * twom24;
  }
  
  // Skipping to luxury.  As proposed by Martin Luscher. 
  ++in24;
  if (in24 == 24) {
    in24 = 0;
    kount += nskip;
    i__2 = nskip;
    for (isk = 1; isk <= i__2; ++isk) {
      uni = seeds[j24-1] - seeds[i24-1] - carry;
      if (uni < 0.0) {
	uni += 1.0;
	carry = twom24;
      } else 
	carry = 0.0;
      
      seeds[i24 - 1] = uni;
      i24 = next[i24 - 1];
      j24 = next[j24 - 1];
    }
  }
  
  kount++;
  if (kount >= 1000000000) {
    ++mkount;
    kount -= 1000000000;
  }
  return;


  //---------------------------------------------------------------------------//
  // Entry to input and float integer seeds from previous run 
  //---------------------------------------------------------------------------//
  L_rluxin:

  twom24 = 1.0;
  for (i = 1; i <= 24; ++i) {
    next[i - 1] = i - 1;
    twom24 *= 0.5;
  }
  next[0] = 24;
  twom12 = twom24 * 4096.0;

#ifdef _RANLUX_DEBUG_
  cout << " FULL INITIALIZATION OF RANLUX WITH 25 INTEGERS: ";
  for (int ii = 1; ii <= 25; ii++) { 
    cout << setw(12) << isdext[ii];
    if (i % 5 == 0) cout << endl;
  }
#endif

  for (i = 1; i <= 24; ++i) 
    seeds[i - 1] = (double) isdext[i] * twom24;

  carry = 0.0;
  if (isdext[25] < 0) carry = twom24;
  isd = abs(isdext[25]);
  i24 = isd % 100;
  isd /= 100;
  j24 = isd % 100;
  isd /= 100;
  in24 = isd % 100;
  isd /= 100;
  luxlev = isd;
  if (luxlev <= 4) {
    nskip = ndskip[luxlev];

#ifdef _RANLUX_DEBUG_
    cout << " RANLUX LUXURY LEVEL SET BY RLUXIN TO: " << luxlev << endl;
#endif

  } else if (luxlev >= 24) {
    nskip = luxlev - 24;

#ifdef _RANLUX_DEBUG_
    cout <<  " RANLUX P-VALUE SET BY RLUXIN TO: " << luxlev << endl;
#endif

  } else {
    nskip = ndskip[4];

#ifdef _RANLUX_DEBUG_
    cout <<  " RANLUX ILLEGAL LUXURY RLUXIN: " << luxlev << endl;
#endif
    luxlev = 4;
  }

  inseed = -1;
  return;

  //---------------------------------------------------------------------------//
  // Entry to ouput seeds as integers 
  //---------------------------------------------------------------------------//
  L_rluxut:

  for (i = 1; i <= 24; ++i) 
    isdext[i] = (int) (seeds[i - 1] * 4096. * 4096.);
  isdext[25] = i24 + j24 * 100 + in24 * 10000 + luxlev * 1000000;
  if (carry > 0.0) isdext[25] = -isdext[25];
  return;

  //---------------------------------------------------------------------------//
  // Entry to output the "convenient" restart point 
  //---------------------------------------------------------------------------//
  L_rluxat:

  *lout = luxlev;
  *inout = inseed;
  *k1 = kount;
  *k2 = mkount;
  return;

  //---------------------------------------------------------------------------//
  // Entry to initialize from one or three integers 
  //---------------------------------------------------------------------------//
  L_rluxgo:

  if (lux < 0)
    luxlev = 3;
  else if (lux <= 4)
    luxlev = lux;
  else if (lux < 24 || lux > 2000) {
    luxlev = 4;

#ifdef _RANLUX_DEBUG_
    cout <<  " RANLUX ILLEGAL LUXURY RLUXGO: " << lux << endl;
#endif

  } else {
    luxlev = lux;
    for (ilx = 0; ilx <= 4; ++ilx) {
      if (lux == ndskip[ilx] + 24) {
	luxlev = ilx;
      }
    }
  }

  if (luxlev <= 4) {
    nskip = ndskip[luxlev];
    i__1 = nskip + 24;

#ifdef _RANLUX_DEBUG_
    cout << " RANLUX LUXURY LEVEL SET BY RLUXGO : " 
	 << luxlev << "     P = " << i__1 << endl;
#endif

  } else {
    nskip = luxlev - 24;
#ifdef _RANLUX_DEBUG_
    cout << " RANLUX P-VALUE SET BY RLUXGO TO : " << luxlev << endl;
#endif
  }

  in24 = 0;
  if (ins < 0) {

#ifdef _RANLUX_DEBUG_
    cout << " Illegal initialization by RLUXGO, negative input seed" << endl;
#endif

  }

  if (ins > 0) {
    jseed = ins;

#ifdef _RANLUX_DEBUG_
    cout << " RANLUX INITIALIZED BY RLUXGO FROM SEEDS "
	 << jseed << " " << *k1 << " " << *k2 << endl;
#endif

  } else {
    jseed = 314159265;

#ifdef _RANLUX_DEBUG_
    cout << " RANLUX INITIALIZED BY RLUXGO FROM DEFAULT SEED" << endl;
#endif

  }

  inseed = jseed;
  notyet = false;
  twom24 = 1.0;
  for (i = 1; i <= 24; ++i) {
    twom24 *= 0.5;
    k = jseed / 53668;
    jseed = (jseed - k * 53668) * 40014 - k * 12211;
    if (jseed < 0) jseed += 2147483563;
    iseeds[i - 1] = jseed % 16777216;
  }
  twom12 = twom24 * 4096.0;
  for (i = 1; i <= 24; ++i) {
    seeds[i - 1] = (double) iseeds[i - 1] * twom24;
    next[i - 1] = i - 1;
  }
  next[0] = 24;
  i24 = 24;
  j24 = 10;
  carry = 0.0;
  if (seeds[23] == 0.0) carry = twom24;

  // If restarting at a break point, skip K1 + IGIGA*K2 
  // Note that this is the number of numbers delivered to 
  // the user PLUS the number skipped (if luxury .GT. 0). 
  kount = *k1;
  mkount = *k2;
  if (*k1 + *k2 != 0) {
    i__1 = *k2 + 1;
    for (iouter = 1; iouter <= i__1; ++iouter) {
      inner = 1000000000;
      if (iouter == *k2 + 1) inner = *k1;
      i__2 = inner;
      for (isk = 1; isk <= i__2; ++isk) {
	uni = seeds[j24 - 1] - seeds[i24 - 1] - carry;
	if (uni < 0.0) {
	  uni += 1.0;
	  carry = twom24;
	} else 
	  carry = 0.0;

	seeds[i24 - 1] = uni;
	i24 = next[i24 - 1];
	j24 = next[j24 - 1];
      }
    }

    // Get the right value of IN24 by direct calculation 
    in24 = kount % (nskip + 24);
    if (mkount > 0) {
      izip = 1000000000 % (nskip + 24);
      izip2 = mkount * izip + in24;
      in24 = izip2 % (nskip + 24);
    }

    // Now IN24 had better be between zero and 23 inclusive 
    if (in24 > 23) {

#ifdef _RANLUX_DEBUG_
      cout << "  Error in RESTARTING with RLUXGO: " << endl
	   << "  The values " << ins << " " << *k1 << " " << *k2
	   << " cannot occur at luxury level " << luxlev << endl;
#endif

      in24 = 0;
    }
  }
}

//-----------------------------------------------------------------------------//

static void ranlux (double *rdum)
{
  ranlux_driver(0, rdum, (int*)0, (int *)0, (int *)0, 
		(int *)0, (int *)0, 0,0);
}

//-----------------------------------------------------------------------------//
/*

static void rluxin (int *isdext)
{
  ranlux_driver(1, (double *)0, isdext, (int *)0, 
		(int *)0, (int *)0, (int *)0, 0,0);
}

//-----------------------------------------------------------------------------//

static void rluxut (int *isdext)
{
  ranlux_driver(2, (double *)0, isdext, (int *)0, (int *)0, 
		(int *)0, (int *)0, 0,0);
}

//-----------------------------------------------------------------------------//

static void rluxat(int *lout, int *inout, int *k1, int *k2)
{
  ranlux_driver(3, (double *)0, (int *)0, lout, 
		inout, k1, k2, 0,0);
}
*/

//-----------------------------------------------------------------------------//

static void rluxgo(int lux, int ins, int *k1, int *k2)
{
  ranlux_driver(4, (double *)0, (int *)0, (int *)0, (int *)0, 
		k1, k2, lux,ins);
}


//-----------------------------------------------------------------------------//
// The C++ class interface 
// Quick and dirty hack, only a part of the functionality of RANLUX is available.
//-----------------------------------------------------------------------------//


RanLux::RanLux (int luxury, unsigned long seed)
{
  SetState(luxury,seed);
}

//-----------------------------------------------------------------------------//

void RanLux::SetState (int luxury, unsigned long seed)
{
  // requires at least 32 bit integer arithmetics
  assert( sizeof(int) >= 4 );

  // if the seed is zero then a unique seed will be determined automatically
  if (seed == 0) seed = Random.UniqueSeed();

  // The seed is masked with 0x7fffffff to ensure a positive integer value
  seed &= 0x7fffffff;

  k1 = k2 = 0;
  rluxgo(luxury,int(seed),&k1,&k2);
}

//-----------------------------------------------------------------------------//

double RanLux::operator () (void)
{
  double rdum;
  ranlux(&rdum);
  return rdum;
}

} // namespace MATPACK

//-----------------------------------------------------------------------------//
