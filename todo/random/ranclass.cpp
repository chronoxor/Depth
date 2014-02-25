/*-----------------------------------------------------------------------------*\
| Matpack random generator class                                   ranclass.cpp |
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

//----------------------------------------------------------------------------//
// Matpack's includes
//----------------------------------------------------------------------------//

#include "mprandom.h"
#include "md5.h"

//----------------------------------------------------------------------------//
// system includes
//----------------------------------------------------------------------------//

#include <cassert>
#include <time.h>

#if defined( WIN32)

// Windows specific
#include <process.h>
#include <sys/timeb.h>

#else

// Unix and Linux specific
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#endif

namespace MATPACK {

//----------------------------------------------------------------------------//
// unsigned long RandomGenerator::UniqueSeed (void)
//----------------------------------------------------------------------------//
// Generate an unique seed using the process id, the parents process id,
// time and clock ticks.
// 
// The seed returned is positive with 0 < seed < 2^31.
//
// NOTE: Never use repeated calls to the seed generator as a substitute for
//       generating a random sequence! Always use one of the random 
//       generators for this purpose. This function is very slow.
//
// HINT: It is in general not sufficient to use the function time() to get 
//       a seed, because of the intrinsic resolution of one second. Thus if 
//       more than one initialization of the same random number generator
//       is done in one second then the same sequence would be generated. 
//       Therefore also a call to the processor clock() is performed to get a 
//       unique time stamp. The result is combined with the value of time(). 
//       All this will fail if the time resolution of clock() is so bad,
//       that more than one initialization within two clock ticks can be done.
//       This happens indeed on fast machines if new seeds are requested 
//       in a short time interval. To overcome this difficulty the seed 
//       generated previously is mixed into the new seed to make it unique. 
//       All this will fail if for instance the program (not this function)
//       is called two times within one second. Then the value of time() might
//       not have changed and clock() always starts counting from zero each
//       time the program is started.
//       For this reason the process id and the parents process id is mixed
//       into the seed. These values should be unique.
//       Additionally, the system information available with getrusage()
//       is mixed into the seed. This includes random events like page faults,
//       swaps, signals received, system times, user times, and many other.
//       Now the seed should be really unique !
//----------------------------------------------------------------------------//

unsigned long RandomGenerator::UniqueSeed (void)
{
  // the static pool of randomness - with some arbitrary initialization value
  static unsigned char digest[16] = { 
    0xd1, 0x98, 0x2f, 0xd0, 0xb8, 0x6a, 0xba, 0xf1, 
    0x24, 0xb3, 0x08, 0x85, 0x63, 0x71, 0xa4, 0xf4 };

  // a static random counter which is mixed into the pool every time this
  // function is called. This ensures at least deterministic randomness even 
  // if all system calls fail to provide true randomness.
  static unsigned long randcnt = 1;

once_again:

  // initialize the MD5 hashing with the random pool
  struct MD5Context context; 
  MD5Init(&context);
  MD5Update(&context,digest,sizeof(digest));

  // increment counter and mix value into pool
  randcnt++;
  MD5Update(&context,(unsigned char*)&randcnt,sizeof(randcnt));

  // Now mix random system values into the pool
  clock_t clk = clock();                                // cpu time [clock]
  MD5Update(&context,(unsigned char*)&clk,sizeof(clock_t));


#if defined( WIN32 )

  // MS Windows specific
  int pid = _getpid();                                  // process id
  MD5Update(&context,(unsigned char*)&pid,sizeof(int));

  struct _timeb timeb;                                  // time at a high resolution
  _ftime(&timeb);
  MD5Update(&context,(unsigned char*)&timeb,sizeof(struct _timeb));


#else

  // Unix/Linux specific
  pid_t pid = getpid();                                 // process id
  MD5Update(&context,(unsigned char*)&pid,sizeof(pid_t));

  pid = getppid();                                      // parent process id
  MD5Update(&context,(unsigned char*)&pid,sizeof(pid_t));

  struct timeval tim;                                   // time at high resolution
  gettimeofday(&tim,NULL);
  MD5Update(&context,(unsigned char*)&tim,sizeof(struct timeval));

  struct rusage rus;                                    // sys resource usage
  getrusage(RUSAGE_SELF,&rus);
  MD5Update(&context,(unsigned char*)&rus,sizeof(struct rusage));

#endif


  // finalize hash calculation, i.e. value is saved in digest
  MD5Final(digest,&context);
  
  // convert bytes to number within 0 < seed < 2^31.
  unsigned long unique_seed = *((unsigned long*) digest) & 0x7fffffff; 
  if (unique_seed == 0) goto once_again; // extremly rare, but possible

  return unique_seed;
}

//----------------------------------------------------------------------------//
// RandomGenerator default: combined congruential with shuffle
//----------------------------------------------------------------------------//
//
// Returns an integer random number uniformly distributed within [1,2147483562]  
//
// Reference:
//  (1) This is the long period ( > 2.3 * 10^18 ) random number generator of 
//      P. L'Ecuyer, Commun. ACM 31, 743 (1988), but with Bays-Durham shuffle 
//      and "added safeguards" as proposed by
//  (2) William H. Press and Saul A. Teukolsky,
//      "Portable Random Number Generators",
//      Computers in Physics, Vol. 6, No. 5, Sep/Oct 1992, Algorithm "ran2"
//  (3) This generator has been validated also by 
//      G. Marsaglia and A. Zaman, 
//      "Some portable very-long-period random number generators",
//      Computers in Physics, Vol. 8, No. 1, Jan/Feb 1994.  
//
// Notes:
//   -  William Press and Saul Teukolsky think that this is a "perfect" 
//      random generator and will pay $1000 for the first one who convinces 
//      them otherwise.
//
//   -  This generator is very slow
//
//----------------------------------------------------------------------------//

static const int NTAB = 32;

static const long IM1  = 2147483563L,
                  IM2  = 2147483399L,
                  IA1  = 40014L,
                  IA2  = 40692L,
                  IQ1  = 53668L,
                  IQ2  = 52774L,
                  IR1  = 12211L,
                  IR2  = 3791L,
                  IMM1 = IM1-1L;

//----------------------------------------------------------------------------//

void RandomGenerator::Init (void)
{ 
    // requires at least 32 bit arithmetics
    assert( sizeof(unsigned long) >= 4 );

    // initialize the maximum value: max_val
    max_val = IMM1;

    // initialize shuffle table using the seed: iv and idum,idum2,iy
    idum  = (seed > 1L) ? seed : 1L;    // Be sure to prevent idum = 0 
    idum2 = idum;                       // was previously: idum2 = 123456789L;

    for (int j = NTAB+7; j >= 0; j--) { // Load shuffle table (after 8 warm-ups)
        long k = idum/IQ1;
        idum = IA1 * (idum - k * IQ1) - IR1 * k;
        if (idum < 0) idum += IM1;
        if (j < NTAB) iv[j] = idum;
    }
    iy = iv[0];
}

//----------------------------------------------------------------------------//

unsigned long RandomGenerator::Long (void)
{
    long j, k;

    k = idum/IQ1;                       // Start here when not initializing
    idum = IA1*(idum-k*IQ1)-IR1*k;      // Compute idum=mod(IA1*idum,IM1) without
                                        // overflows by Schrage's method 
    if (idum < 0) idum += IM1;
    
    k = idum2/IQ2;                      // Compute idum2=mod(IA2*idum2,IM2) likewise
    idum2 = IA2*(idum2-k*IQ2)-IR2*k;    // Compute idum=mod(IA1*idum,IM1) without
                                        // overflows by Schrage's method
    if (idum2 < 0) idum2 += IM2;
    
    j = iy/(1L+IMM1/NTAB);              // Will be in the range 0..NTAB-1
    iy = iv[j]-idum2;                   // Output previously stored value and 
                                        // refill the shuffle table
    iv[j] = idum;
    if (iy < 1) iy += IMM1;
    
    return iy;
}

//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
// The Default RandomGenerator
//----------------------------------------------------------------------------//

RandomGenerator Random;

} // namespace MATPACK

//----------------------------------------------------------------------------//
