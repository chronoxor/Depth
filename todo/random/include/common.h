/*-----------------------------------------------------------------------------*\
| common definitions include file                                      common.h |
|                                                                               |
| Last change: Dec 25, 2005                                                     |
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
#ifndef _COMMON_H_
#define _COMMON_H_

//----------------------------------------------------------------------------//
// Here are the version, copyright, address, and registration strings
// Only the author and the official co-authors of the Matpack C++ Numerics
// and Graphics Library are allowed to change these entries. Only the
// registration string can be modified by a registered user. Non-registered
// users are not allowed to modify the registration string "Unregistered Copy".
//----------------------------------------------------------------------------//

#define MP_VERSION_STRING \
"Matpack Library Release 1.9.0"

#define MP_COPYRIGHT_STRING \
"Copyright (c) 1991-2006 Berndt M. Gammel, All rights reserved"

#define MP_ADDRESS_STRING \
"Address: reply@matpack.de"

#define MP_REGISTRATION_STRING \
"GPL Version"
//"Registered: Physik Department, Technische Universitaet Muenchen"
//"Registered: TKM, Univeritaet Karlsruhe"
//"Registered: Physik, Universitaet Erlangen"
//"Registered: ESEC SA, Cham, Schweiz"

//----------------------------------------------------------------------------//
// include file with compatibility stuff for various architectures
//----------------------------------------------------------------------------//

#include "compat.h"

//----------------------------------------------------------------------------//
// common include files needed everywhere
//----------------------------------------------------------------------------//

// C-style standard includes
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cerrno>

// standard STL includes
#include <string>
#include <complex>

namespace MATPACK {

// NAN should be defined in math.h, if not we have to set it here to some value
#ifndef NAN
#define NAN 0
#endif

//----------------------------------------------------------------------------//
// additional mathematical constants (32 digits)
//----------------------------------------------------------------------------//

#ifndef M_4_PI
#define M_4_PI      1.2732395447351626861510701069801   // 4/Pi
#endif
#ifndef M_SQRTPI
#define M_SQRTPI    1.7724538509055160272981674833411   // sqrt(Pi)
#endif
#ifndef M_SQRT2PI
#define M_SQRT2PI   2.5066282746310005024157652848111   // sqrt(2Pi)
#endif
#ifndef M_SQRT_PI_2
#define M_SQRT_PI_2 1.2533141373155002512078826424055   // sqrt(Pi/2)
#endif
#ifndef M_SQRT_2_PI
#define M_SQRT_2_PI 0.79788456080286535587989211986876  // sqrt(2/Pi)
#endif
#ifndef M_1_SQRTPI
#define M_1_SQRTPI  0.56418958354775628694807945156077  // 1/sqrt(Pi)
#endif
#ifndef M_2_SQRTPI
#define M_2_SQRTPI  1.1283791670955125738961589031216   // 2/sqrt(Pi)
#endif
#ifndef M_SQRT_2PI
#define M_SQRT_2PI  0.39894228040143267793994605993438  // 1/sqrt(2Pi)
#endif
#ifndef M_SQRT_2
#define M_SQRT_2    0.70710678118654752440084436210485  // sqrt(1/2)
#endif
#ifndef M_2PI
#define M_2PI       6.2831853071795864769252867665590   // 2Pi
#endif
#ifndef M_4PI
#define M_4PI       12.5663706143591729538505735331180  // 4Pi
#endif

//----------------------------------------------------------------------------//
// common definitions used for describing data types
//----------------------------------------------------------------------------//

enum MpDataT { 
  MpArray, 
  MpFacets 
};

enum MpNumberT { 
  MpRealValued, 
  MpComplexValued, 
  MpIntegerValued, 
  MpBitValued 
};

enum MpElementT { 
  MpScalar   = 1, 
  MpVector2D = 2, 
  MpVector3D = 3
};

// The format flags are constructed for packing into one integer by or-ing them,
// e.g.  MpBinaryFormat | MpSwapByteOrder | MpColumnMajor
// don't change the values below !!!!!

enum MpFormatT { 
  MpTextFormat      = 0x000, // numbers in text format (DEFAULT)
  MpBinaryFormat    = 0x001, // numbers in binary format
  MpNoHeaderFormat  = 0x002, // don't print header (descriptor) of arrays
  MpPrettyFormat    = 0x004, // pretty print text format
  MpNativeByteOrder = 0x000, // binary number in machine native byte order (DEFAULT)
  MpSwapByteOrder   = 0x008, // binary number in reverse byte order
  MpRowMajor        = 0x000, // array in row major order (C-like) (DEFAULT)
  MpColumnMajor     = 0x010, // array in column major order (Fortran-like)
  MpDouble          = 0x000, // binary double precision (DEFAULT)
  MpSingle          = 0x020, // binary single precision 
  MpByte            = 0x040, // 1-byte format (positive integer 0..255)
  Mp2Byte           = 0x080, // 2-byte format (positive integer 0..65535)
  Mp4Byte           = 0x100, // 4-byte format (integer)
  Mp8Byte           = 0x200  // 8-byte format (integer)
};

//----------------------------------------------------------------------------//
// common prototypes
//----------------------------------------------------------------------------//

// more standard functions
double  powi            (double,int);
int     powii           (int,int);

double  hypot           (double,double,double);
float   hypot           (float,float,float);

// string hashing functions
unsigned long HashString0  (const char*);
unsigned long HashString1  (const char*);
unsigned long HashString2  (const char*);
unsigned long HashString3  (const char*);
unsigned long HashString4  (const char*);
unsigned long HashString5  (const char*);
unsigned long HashString6  (const char*);
unsigned long HashString7  (const char*);
unsigned long HashString8  (const char*);
unsigned long HashString9  (const char*);
unsigned long HashString10 (const char*);

// filename pattern matching
int MpFilenamePatternIsValid (const char *pat);
int MpFilenamePatternMatch (const char *pat, const char *fname);
int MpFilenamePatternMatchUnchecked (const char *pat, const char *fname);

// split filename
const char *GetFileNameBase      (const char *fname);
const char *GetFileNameExtension (const char *fname);

// string comparison ignoring case
int strcmp_ignore_case  (const char *s1, const char *s2);
int strncmp_ignore_case (const char *s1, const char *s2, int n);

char* BaseConvert (long n, long b, char *result);
char* BaseConvertUnsigned (unsigned long n, unsigned long b, char *result);

//----------------------------------------------------------------------------//
// class Mat:
//----------------------------------------------------------------------------//
//
// PURPOSE:
// --------
//
// The class 'Mat' defines error behavior and supplies error/warning routines
//
// DESCRIPTION:
// ------------
//
// Control the behaviour after an error occured (enum Behaviour)
//
//      Mat::AbortOnError       exit with core dump
//      Mat::ExitOnError        exit with a return value of 1
//      Mat::SuppressWarning    dont't print warnings, but regard errors
//      Mat::DisregardError     disregard error, continue, but print warning
//      Mat::IgnoreError        ignore error completely and don't print warning
// 
//----------------------------------------------------------------------------//

class Mat 
{
  public:

    enum Behaviour {
        AbortOnError            = -1,
        ExitOnError             = -2,
        DisregardError          = -3,
        IgnoreError             = -4,
        SuppressWarning         = -5
    };

    enum Errors {
        NoError                 = 0,    // general error types
        UnspecifiedError        = 1,
        UnspecifiedWarning      = 2,
        AllocationFailure       = 3,

        Overflow                = 10,   // floating point errors
        Underflow               = 11,
        ZeroDivide              = 12,
        PartialPrecisionLoss    = 13,
        TotalPrecisionLoss      = 14,
        ArgumentDomain          = 15,

        NonConformant           = 20,   // matrix and vector package errors
        MatrixIsSingular,                       // Decompose
        MatrixNotSquare,                        // Decompose,EigenSystem,
        MatrixNotPositive,                      // Chreduce
        IndexOutOfRange,
        NotConverged,                           // Imtql
        
        UnknownDevice           = 200   // scene package errors
    };

  protected:

    int   errnum;       // error code (from enum)
    int   behave;       // error behaviour ( from enum)
    char  message[256]; // error message generated
    const char* version;// Matpack version/copyright string

  public:

    Mat (void);
    const char* Version (void) const { return version; }

    // error handling
    int  Behaviour (int how) { int h = behave;  behave = how; return h; }
    void Error (int err, const char* msg = 0, ...);
    void Error (const char* msg = 0, ...);
    void Warning (int err, const char* msg = 0, ...);
    void Warning (const char* msg = 0, ...);
    int  Result (void) { int h = errnum; errnum = NoError; return h; }
    const char* Message(void) const { return message; }
    int  Ok (void) { return (errnum == NoError); }
};

//----------------------------------------------------------------------------//

extern Mat Matpack;

//----------------------------------------------------------------------------//
// common inlines
//----------------------------------------------------------------------------//

// frequently used type
typedef unsigned char byte;

// line style parameters
enum { 
    Solid = 0,
    Dotted,
    Dashed,
    LongDashed,
    DotDashed,
    DotDotDashed 
};

// polygons
#define Fill 1
#define Outline 2

// these are the only predefined colors (long)
#define Black 0L
#define White 7L
#define Gray  8L

// do not change this (internal use)
#define MaxFontName 64

// rounding

// round to nearest integer
inline int      Nint (float  d) { return (d > 0.0) ? (int)(d+0.5) : -(int)(-d+0.5); }
inline int      Nint (double d) { return (d > 0.0) ? (int)(d+0.5) : -(int)(-d+0.5); }

// round towards zero (Fortran convention)
inline double   Dint (double d) { return (d<0) ? ceil(d) : floor(d); }

// modulus (Fortran convention)
inline double   Dmod (double x, double y) 
{ 
  double quotient;
  if( (quotient = x / y) >= 0)
    quotient = floor(quotient);
  else
    quotient = -floor(-quotient);
  return (x - y*quotient);
}

// even and odd

inline int      even    (int x){return!(x&1);}
inline int      even    (short x){return!(x&1);}
inline int      even    (long x){return!(x&1);}
inline int      even    (unsigned int x){return!(x&1);}
inline int      even    (unsigned short x){return!(x&1);}
inline int      even    (unsigned long x){return!(x&1);}

inline int      odd     (int x){return(x&1);}
inline int      odd     (short x){return(x&1);}
inline int      odd     (long x){return(x&1);}
inline int      odd     (unsigned int x){return(x&1);}
inline int      odd     (unsigned short x){return(x&1);}
inline int      odd     (unsigned long x){return(x&1);}
        
// logarithm to arbitrary base

inline double   log     (double b,double x) 
{
  return ::log(x)/::log(b);
}

// angle of vector (x,y) to x-axis

inline double   Angle   (double x,double y) 
{ 
  return (x == 0.0 && y == 0.0) ? 0.0 : atan2(y,x); 
}

inline float    Angle   (float x,float y) 
{
  return float( (x == 0.0 && y == 0.0) ? 0.0 : atan2(y,x)); 
}

// convert radians to degree and vice versa 

inline float    RadToDeg (int rad){return float(rad*180/M_PI);}
inline float    RadToDeg (long rad){return float(rad*180/M_PI);}
inline float    RadToDeg (float rad){return float(rad*180/M_PI);}
inline double   RadToDeg (double rad){return rad*180/M_PI;}

inline float    DegToRad (int deg){return float(deg*M_PI/180);}
inline float    DegToRad (long deg){return float(deg*M_PI/180);}
inline float    DegToRad (float deg){return float(deg*M_PI/180);}
inline double   DegToRad (double deg){return deg*M_PI/180;}


// Return total intensity i (range 0..255) of the r,g,b components  
// (range 0..255) using the formula i = 0.34r+ 0.5g+ 0.16b 

inline byte Monochrome (byte r, byte g, byte b)  
{  
    return (byte) (( (int)r*11 + (int)g*16 + (int)b*5) >> 5); 
} 

// ADDITIONAL STANDARD FUNCTIONS AS TEMPLATES

// return sign of number

template <class T> inline int sign (T x)
{ return (x > 0) ? 1 : (x < 0) ? -1 : 0; }

// return first number with sign of second number
template <class T> inline T CopySign (T x, T y)
{ return (y < 0) ? ((x < 0) ? x : -x) : ((x > 0) ? x : -x); }

//-----------------------------------------------------------------------------//
// MpMin(), MpMin(): min and max templates for upto 9 arguments
//-----------------------------------------------------------------------------//

template <class T> inline T MpMin (T x, T y) 
{ return (x<y)?x:y; }
template <class T> inline T MpMin (T x, T y, T z) 
{ return (x<y)?((x<z)?x:z):((y<z)?y:z); }
template <class T> inline T MpMin (T x, T y, T z, T w) 
{ return MpMin(MpMin(x,y),MpMin(z,w)); }
template <class T> inline T MpMin (T x1,T x2,T x3,T x4,T x5) 
{ return MpMin(MpMin(x1,x2),MpMin(x3,x4),x5); }
template <class T> inline T MpMin (T x1,T x2,T x3,T x4,T x5,T x6) 
{ return MpMin(MpMin(x1,x2,x3),MpMin(x4,x5,x6)); }
template <class T> inline T MpMin (T x1,T x2,T x3,T x4,T x5,T x6,T x7) 
{ return MpMin(MpMin(x1,x2,x3),MpMin(x4,x5,x6),x7); }
template <class T> inline T MpMin (T x1,T x2,T x3,T x4,T x5,T x6,T x7,T x8) 
{ return MpMin(MpMin(x1,x2,x3),MpMin(x4,x5,x6),MpMin(x7,x8)); }
template <class T> inline T MpMin (T x1,T x2,T x3,T x4,T x5,T x6,T x7,T x8, T x9) 
{ return MpMin(MpMin(x1,x2,x3),MpMin(x4,x5,x6),MpMin(x7,x8,x9)); }

template <class T> inline T MpMax (T x, T y) 
{ return (x>y)?x:y; }
template <class T> inline T MpMax (T x, T y, T z) 
{ return (x>y)?((x>z)?x:z):((y>z)?y:z); }
template <class T> inline T MpMax (T x, T y, T z, T w) 
{ return MpMax(MpMax(x,y),MpMax(z,w)); }
template <class T> inline T MpMax (T x1,T x2,T x3,T x4,T x5) 
{ return MpMax(MpMax(x1,x2),MpMax(x3,x4),x5); }
template <class T> inline T MpMax (T x1,T x2,T x3,T x4,T x5,T x6) 
{ return MpMax(MpMax(x1,x2,x3),MpMax(x4,x5,x6)); }
template <class T> inline T MpMax (T x1,T x2,T x3,T x4,T x5,T x6,T x7) 
{ return MpMax(MpMax(x1,x2,x3),MpMax(x4,x5,x6),x7); }
template <class T> inline T MpMax (T x1,T x2,T x3,T x4,T x5,T x6,T x7,T x8) 
{ return MpMax(MpMax(x1,x2,x3),MpMax(x4,x5,x6),MpMax(x7,x8)); }
template <class T> inline T MpMax (T x1,T x2,T x3,T x4,T x5,T x6,T x7,T x8, T x9) 
{ return MpMax(MpMax(x1,x2,x3),MpMax(x4,x5,x6),MpMax(x7,x8,x9)); }

//-----------------------------------------------------------------------------//
// MpMedian: median template for three arguments
//-----------------------------------------------------------------------------//

template <class T> inline const T& MpMedian (const T& a, const T& b, const T& c) 
{
  if (a < b)
    if (b < c)   
      return b;
    else if (a < c)
      return c;
    else
      return a;
  else if (a < c)
    return a;
  else if (b < c)
    return c;
  else
    return b;
}

//-----------------------------------------------------------------------------//
// raise to n-th power for n = 2 to 12
//-----------------------------------------------------------------------------//

template <class T> inline T    sqr  (T x) { return x*x; }
template <class T> inline T   cube  (T x) { return x*x*x; }
template <class T> inline T pow2nd  (T x) { return x*x; }
template <class T> inline T pow3rd  (T x) { return x*x*x; }
template <class T> inline T pow4th  (T x) { T y = x*x; return y*y; }
template <class T> inline T pow5th  (T x) { T y = x*x; return y*y*x; }
template <class T> inline T pow6th  (T x) { T y = x*x*x; return y*y; }
template <class T> inline T pow7th  (T x) { T y = x*x*x; return y*y*x; }
template <class T> inline T pow8th  (T x) { T y = x*x; y *= y; return y*y; }
template <class T> inline T pow9th  (T x) { T y = x*x; y *= y; return y*y*x; }
template <class T> inline T pow10th (T x) { T y = x*x; T z = y*y; return z*z*y; }
template <class T> inline T pow11th (T x) { T y = x*x; T z = y*y; return z*z*y*x; }
template <class T> inline T pow12th (T x) { T y = x*x*x; y *= y; return y*y; }

// swaps the contents of a with that of b

template <class T> inline void MpSwap (T& a, T& b)
{ T c; c = a; a = b; b = c; }

// forces a to be in the range b..c inclusive

template <class T> inline void MpForceRange (T& x, T a, T b) 
{ if (x < a) x = a; else if (x > b) x = b; }

/*!
  int MpGetEndian (void)

  Checks whether the current machine is of little or big
  endian architecture. The function returns 0 if little endian 
  and 1 if big endian representation is used on the current hardware.
*/
int MpGetEndian (void);

// swap byte order (little endian to big endian and vice versa)
void MpByteSwap (int &f);
void MpByteSwap (long &f);
void MpByteSwap (short &f);
void MpByteSwap (float &f);
void MpByteSwap (double &f);
void MpByteSwap (std::complex<float> &f);
void MpByteSwap (std::complex<double> &f);

// Count bits in binary representation of x. 
// This is the Hamming weight of the binary binary representation of x.
// The template works for all signed and unsigned integer types which
// are coded using a radix-2 two's complement representation.
template <class T>
inline unsigned MpBitCount (T x) {
  unsigned n = 0;
  if (x) do { n++; } while ((x &= x-1));
  return n;
}

//----------------------------------------------------------------------------//
// Miscellaneous
//----------------------------------------------------------------------------//

// convert between ASCII and EBCDIC character encoding (mpascii2ebdcic.cpp)
char MpASCIItoEBCDIC (const unsigned char c);
char MpEBCDICtoASCII (const unsigned char c);

// convert integer number in 1 <= num <= 8999 to a roman number (mpromannumber.cpp)
std::string  MpRomanNumber   (int num);

double  timer           (char *message);
void    delay           (long usec);             // implmented in "compat.h"
char*   DoubleToText    (double,char*,int,int); 


// I/O utility functions - deprecated - don't use any more !!!!!!!!!!!
void    readln          (void);
void    readln          (char*);
void    readln          (FILE*);
void    readln          (FILE*,char*);     

//-----------------------------------------------------------------------------//
// algebra
//-----------------------------------------------------------------------------//

void    PrimeFactor     (unsigned long val, unsigned long factors[32]);
double  IntegerFraction (double f, long& n, long& d, double error);

} // namespace MATPACK

//----------------------------------------------------------------------------//

#endif
