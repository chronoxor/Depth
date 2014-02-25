/*-----------------------------------------------------------------------------*\
| Include file isolating compatability information for                 compat.h |
| various machines and compilers. Additional code required for                  |
| compatibility is isolated in the file compat.cpp                              |
|                                                                               |
| Last change: Oct 14, 2006                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2006 by Berndt M. Gammel. All rights reserved.             |
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

#ifndef _COMPAT_H_
#define _COMPAT_H_

//-----------------------------------------------------------------------------//
// Uncomment the following define if you want to use a BLAS library. See
// Makefile.common for further coments about BLAS usage.
//-----------------------------------------------------------------------------//
//#define _MATPACK_USE_BLAS_

#ifdef _MATPACK_USE_BLAS_

// the linker usually requires a trailing underscore
// -------------------------------------------------

#define F77NAME(x) x##_

// uncomment if the linker wants the plain name (put line above into comments)
//#define F77NAME(x) x

// C to Fortran type mapping
// -------------------------

#include <complex>

typedef char            charT;          // Fortran character type CHAR*1
typedef int             intT;           // Fortran integer type   INT*4
typedef float           floatT;         // Fortran real type      REAL*4
typedef double          doubleT;        // Fortran real type      REAL*8
typedef complex<float>  fcomplexT;      // Fortran complex type   COMPLEX*8
typedef complex<double> dcomplexT;      // Fortran complex type   COMPLEX*16

#endif

//-----------------------------------------------------------------------------//
// inline void delay (long microseconds) { ... }
//   The function "delay()" is defined in compat.h. It causes the current task 
//   to sleep/suspend for the given number of microseconds and resume thereafter. 
//   It is identical to the Unix "usleep()", but for compatibility resons it is
//   abstracted here.
//-----------------------------------------------------------------------------//

//-----------------------------------------------------------------------------//
// * gcc version 3.3.2 on SunOS 5.7 / Solaris 2.7
//-----------------------------------------------------------------------------//

#if defined( __GNUC__ ) && defined( __sun__ )

#include <time.h>
#include <sys/time.h>

// include C99 standard file to get 32 bit type (e.g. typedef unsigned int uint32_t;)
//#include <stdint.h> 

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 1e6
#endif

// supply missing prototypes
extern "C" { 
  int usleep (unsigned);
  int getrusage(int who, struct rusage *rusage);
  int chdir(const char *path);
}
// define missing functions
inline void delay (long t) { usleep( (unsigned) t ); }    
//inline int mkstemp (char *nam) { mktemp(nam); }


//-----------------------------------------------------------------------------//
// GNU g++ 2.7.2 compiler on the DEC Alpha, OSF 3.2 (UNIX)
//-----------------------------------------------------------------------------//

#elif defined( __GNUC__ ) && defined( __alpha__ )

#include <unistd.h>
#include <sys/time.h>

// include C99 standard file to get 32 bit type (e.g. typedef unsigned int uint32_t;)
#include <stdint.h> 


extern "C" {  
  unsigned usleep (unsigned);
  int mkstemp (char*);
}

inline void delay (long t) { usleep( (unsigned) t ); }

//-----------------------------------------------------------------------------//
// Intel C++ compiler 9.0 in the Gnu compatibility mode (-cxxlib-gcc flag set)
//-----------------------------------------------------------------------------//

#elif defined( __GNUC__ ) && defined( __INTEL_COMPILER )

#pragma warning(disable:981)  // disable "remark: operands are evaluated in unspecified order"
#pragma warning(disable:1572) // disable "remark: floating-point equality and inequality comparisons are unreliable"
#pragma warning(disable:383)  // disable "remark: value copied to temporary, reference to temporary used"
#pragma warning(disable:444)  // disable "remark: destructor for base class  is not virtual"
#pragma warning(disable:810)  // disable "remark: conversion from "xx" to "yy" may lose significant bits"
#pragma warning(disable:869)  // disable "remark: parameter was never referenced"

#include <stdint.h> 
#include <unistd.h>
#include <sys/time.h>

inline void delay (long t) { usleep( (unsigned) t ); }

//-----------------------------------------------------------------------------//
// MinGW -- GNU Compiler under Windows
//-----------------------------------------------------------------------------//
#elif defined( WIN32 ) && defined( __GNUC__ )

#include <unistd.h>
#include <winsock.h>    // for struct timeval and Sleep()
#include <sys/timeb.h>  // for _ftime()

// include C99 standard file to get 32 bit type (e.g. typedef unsigned int uint32_t;)
#include <stdint.h> 


inline void delay (long t) { Sleep( (unsigned long) t/1000 ); }

//-----------------------------------------------------------------------------//
//  Microsoft Visual C++ 6.0 service pack 5 (Intel 586 PC)
//  Microsoft Visual C++.NET 7.1 (Intel 586 PC)
//-----------------------------------------------------------------------------//

#elif defined( WIN32 )

#include <winsock.h>    // for struct timeval and Sleep()
#include <sys/timeb.h>  // for _ftime()

// add the Posix math constants for IEEE double type
# define M_E            2.7182818284590452354   /* e */
# define M_LOG2E        1.4426950408889634074   /* log_2 e */
# define M_LOG10E       0.43429448190325182765  /* log_10 e */
# define M_LN2          0.69314718055994530942  /* log_e 2 */
# define M_LN10         2.30258509299404568402  /* log_e 10 */
# define M_PI           3.14159265358979323846  /* pi */
# define M_PI_2         1.57079632679489661923  /* pi/2 */
# define M_PI_4         0.78539816339744830962  /* pi/4 */
# define M_1_PI         0.31830988618379067154  /* 1/pi */
# define M_2_PI         0.63661977236758134308  /* 2/pi */
# define M_2_SQRTPI     1.12837916709551257390  /* 2/sqrt(pi) */
# define M_SQRT2        1.41421356237309504880  /* sqrt(2) */
# define M_SQRT1_2      0.70710678118654752440  /* 1/sqrt(2) */

// define the missing C99 standard types
typedef unsigned int uint32_t;

typedef _int32 int32_t;
typedef _int64 int64_t;


inline void delay (long t) { Sleep( (unsigned long) t/1000 ); }


#if (_MSC_VER < 7) 
//  Microsoft Visual C++ 6.0 service pack 5
inline float    abs     (float x){return(x<0)?-x:x;}
inline double   abs     (double x){return(x<0)?-x:x;}
#else
//  Microsoft Visual C++.NET 7.1
#pragma warning( disable : 4244 ) // loss of precission from automatic type down casts
#pragma warning( disable : 4800 ) // forcing value to bool 'true' or 'false' 
#endif

//-----------------------------------------------------------------------------//
// This section is valid for Linux, Unix, and Cywin on Windows platforms
// tested on:
// * gcc version 2.96  on i386, Redhat Linux 7.2
// * gcc version 3.3.1 on i386, SuSE Linux 9.1
// * fcc version 3.2   on i386, CYGWIN under Win2000
//-----------------------------------------------------------------------------//

#elif defined( __GNUC__ )

#include <unistd.h>
#include <sys/time.h>

// include C99 standard file to get 32 bit type (e.g. typedef unsigned int uint32_t;)
#include <stdint.h> 


inline void delay (long t) { usleep( (unsigned long) t ); }

//-----------------------------------------------------------------------------//
// add for other unix systems 
//-----------------------------------------------------------------------------//

#else 

#include <unistd.h>
#include <sys/time.h>

typedef unsigned int uint32_t;

extern "C" { 
  int mkstemp (char*); 
}

inline void delay (long t) { usleep( (unsigned) t ); }

#endif

//-----------------------------------------------------------------------------//
// for all machines except ...
//-----------------------------------------------------------------------------//

#if ! defined( __GNUC__ ) && ! defined( __alpha__ ) && ! defined( WIN32 )

inline float    abs     (float x){return(x<0)?-x:x;}
inline double   abs     (double x){return(x<0)?-x:x;}

#endif

//-----------------------------------------------------------------------------//

#endif
