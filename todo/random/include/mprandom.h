/*-----------------------------------------------------------------------------*\
| include file for Matpack random generator classes                  ranclass.h |
|                                                                               |
| Last change: Sep 12, 2004                                                     |
|                                                                               |
| Matpack Library Release 1.9.0							|
| Copyright (C) 1991-2004 by Berndt M. Gammel                                   |
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

#ifndef ranclass_h_
#define ranclass_h_

#include "common.h"

//#define RNG_DEBUG
#ifdef RNG_DEBUG
#include <iostream>
#endif

//----------------------------------------------------------------------------//
// class RandomGenerator: base class for all random generators		      //
//----------------------------------------------------------------------------//

namespace MATPACK { 

using ::log;


class RandomGenerator 
{
  private:                      // default generator state data
    long idum, idum2, iy, iv[32];
    void Init (void);

  protected:
    unsigned long seed;		// the seed of the random generator
    unsigned long max_val;	// uniform long int values within [0...max_val]
    RandomGenerator *gen;	// pointer to generator    

  public:

    unsigned long UniqueSeed (void);

    //------------------------------------------------------------------------//
    // constructor
    //------------------------------------------------------------------------//
    RandomGenerator (unsigned long new_seed = 0) 
    { 
#ifdef RNG_DEBUG
  cout << "RandomGenerator (unsigned long new_seed = 0), this=" << this <<endl;
#endif
      seed = ((new_seed == 0) ? UniqueSeed() : new_seed) & 0x7fffffff;
      Init();
    }

    //------------------------------------------------------------------------//
    // constructor
    //------------------------------------------------------------------------//
    RandomGenerator (char* hash) 
    { 
#ifdef RNG_DEBUG
  cout << "RandomGenerator (char* hash), this=" << this <<endl;
#endif
      seed = HashString2(hash) & 0x7fffffff; 
      Init();
    }

    //------------------------------------------------------------------------//
    // constructor
    //------------------------------------------------------------------------//
    RandomGenerator (RandomGenerator* ran) 
    {
      if (ran) {
          gen = ran;
          max_val = ran->max_val; 
          seed = ran->seed;
      } else {
          gen = (RandomGenerator*)this;
          seed = UniqueSeed();
          Init();
      }
#ifdef RNG_DEBUG
  cout << "RandomGenerator (RandomGenerator* ran), this=" << this  << ", ran=" <<ran<<endl 
       << "maxval="<<max_val<<endl
       << "seed="<<seed<<endl;
#endif
    }

    //------------------------------------------------------------------------//
    // virtual empty destructor
    //------------------------------------------------------------------------//
    virtual ~RandomGenerator (void) { /* void */ }

    //------------------------------------------------------------------------//
    // return the seed value
    //------------------------------------------------------------------------//
    unsigned long Seed (void) const { return seed; }

    //------------------------------------------------------------------------//
    // return the maximum value
    //------------------------------------------------------------------------//
    unsigned long Maximum (void) const { return max_val; }

    //------------------------------------------------------------------------//
    // return pointer to generator
    //------------------------------------------------------------------------//
    RandomGenerator* Generator (void) const { return gen; }

    //------------------------------------------------------------------------//
    // overloaded by derived specific generators
    //------------------------------------------------------------------------//
    virtual unsigned long Long (void); // = 0;
};

//----------------------------------------------------------------------------//
// BASIC RANDOM GENERATORS: class Ran000, Ran001, ... 			      //
//----------------------------------------------------------------------------//

class Ran000: public RandomGenerator {	// minimal congruential
  private:
    long idum;
  public:
    Ran000 (unsigned long seed = 0);
    virtual unsigned long Long (void);
};

class Ran001: public RandomGenerator {	// Press's MLCG "ran1"
  private:
    long idum, iy, iv[32];
  public:
    Ran001 (unsigned long seed = 0);
    virtual unsigned long Long (void);
};

class Ran002: public RandomGenerator {	// Press's combined MLCG "ran2"
  private:
    long idum, idum2, iy, iv[32];
  public:
    Ran002 (unsigned long seed = 0);
    virtual unsigned long Long (void);
};

class Ran004: public RandomGenerator { // Press's pseudo-DES "ran4"
  private:
    unsigned long idums, idum; 
  public:
    Ran004 (unsigned long seed = 0);
    virtual unsigned long Long (void);
    virtual unsigned long Long (unsigned long seed, unsigned long nth);
};

class Ran005: public RandomGenerator {	// Press's old congruential with shuffle
  private:
    long r[98], x, y;
  public:
    Ran005 (unsigned long seed = 0);
    virtual unsigned long Long (void);
};

class Ran013: public RandomGenerator {	// Marsaglia's combined congruential
  private:
    unsigned long x, y, z, n; 
    unsigned c;
  public:
    Ran013 (unsigned long seed = 0);
    virtual unsigned long Long (void);
};

class Ran055: public RandomGenerator { // Knuth's lagged Fibonacci generator
  private:
    unsigned long s55[55];
    int j55, k55; 
  public:
    Ran055 (unsigned long seed = 0);
    virtual unsigned long Long (void);
};

class Ran056: public RandomGenerator { // like Ran055 but with 3-decimation
  private:
    unsigned long s55[55];
    int j55, k55; 
  public:
    Ran056 (unsigned long seed = 0);
    virtual unsigned long Long (void);
};

class Ran088: public RandomGenerator { // L'Ecuyer's 1996 Tausworthe "taus88"
  private:
    unsigned long s1,s2,s3;
  public:
    Ran088 (unsigned long seed = 0);
    virtual unsigned long Long (void);
};

class Ran205: public RandomGenerator { // L'Ecuyer's 1996 MRG
  private:
    long x10,x11,x12,x20,x21,x22;
  public:
    Ran205 (unsigned long seed = 0);
    virtual unsigned long Long (void);
};

class Ran250: public RandomGenerator { // Kirkpatrick-Stoll generator "R250"
  private:
    unsigned long r250_buffer[250];
    int r250_index;
  public:
    Ran250 (unsigned long seed = 0);
    virtual unsigned long Long (void);
};

class Ran800: public RandomGenerator {	// Matsumoto's GFSR generator "TT800"
  private:
    int k;
    unsigned long x[25];
  public:
    Ran800 (unsigned long seed = 0);
    virtual unsigned long Long (void);
};

class Ran19937: public RandomGenerator { // Matsumoto's GFSR generator "MT19937B"
  private:
    int k;
    unsigned long ptgfsr[624];
  public:
    Ran19937 (unsigned long seed = 0);
    virtual unsigned long Long (void);
};

//----------------------------------------------------------------------------//
// The Default RandomGenerator - use a good one - this may change with time   //
//----------------------------------------------------------------------------//

extern RandomGenerator Random;

//----------------------------------------------------------------------------//
// DISTRIBUTIONS:							      //
//----------------------------------------------------------------------------//
//
// Note: Each distribution class has a constructor for creating an
//	 uninitialized instance of the class, which is only usefull for 
//	 derived classes that want to do some special initialization.
//
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
// class UniformDistribution: uniformly distributed random numbers over [a,b] //
//----------------------------------------------------------------------------//

class UniformDistribution : public RandomGenerator 
{
  protected:
    double scale, low, high;
  public:
    UniformDistribution (void) {}

    UniformDistribution (double lo, 
                         double hi, 
			 RandomGenerator *ran = 0) : RandomGenerator(ran) {
      if (hi > lo) { 
        low = lo; 
        high = hi;
      } else { 
        low = hi; 
        high = lo; 
      }
      scale = (high-low) / max_val; 
    }

    double operator () (void) { return (scale * gen->Long() + low); }
    double Low (void) const { return low; }
    double High (void) const { return high; }
};

//----------------------------------------------------------------------------//
// class U01_Distribution: uniformly distributed random numbers over [0,1]     //
// This is a special case and equivalent to class UniformDistribution(0,1).
// It is included just because of speed considerations.
//----------------------------------------------------------------------------//

class U01_Distribution : public RandomGenerator {
  protected:
    double scale;
  public:
    U01_Distribution (RandomGenerator *ran = 0) : RandomGenerator(ran) { 
      scale = 1.0 / max_val;
#ifdef RNG_DEBUG
      cout << "U01_Distribution (RandomGenerator *ran = 0), this=" << this  << endl;
      cout << "max_val="<<max_val<<" scale="<<scale << endl;
#endif
    }
    double operator () (void) { return scale * gen->Long(); }
};

//----------------------------------------------------------------------------//
// class NormalDistribution: normal (Gaussian) distributed random numbers     //
//----------------------------------------------------------------------------//

class NormalDistribution : public RandomGenerator 
{
  protected:
    double m, s, scale, cacheval;
    int cached;
  public:
    NormalDistribution (void) {}
    NormalDistribution (double mean, double stdev, 
			RandomGenerator *ran = 0) : RandomGenerator(ran) 
        { cached = 0; m = mean; s = stdev; scale  = 2.0 / max_val; }
    double operator () (void);
    double Mean (void) const { return m; }
    double Stdev (void) const { return s; }
};

//----------------------------------------------------------------------------//
// class LogNormalDistribution: log-normal distributed random numbers         //
//----------------------------------------------------------------------------//

class LogNormalDistribution 
    : public NormalDistribution {
  protected:
    double m_log, s_log;
    void Initialize (double mean, double stdev);
  public:
    LogNormalDistribution (void) {}
    LogNormalDistribution (double mean, double stdev, 
			   RandomGenerator* ran = 0) 
	: NormalDistribution(mean,stdev,ran) { Initialize(mean,stdev); }
    double operator () (void) 
        { return exp(this->NormalDistribution::operator()()); }
    double Mean (void) const { return m_log; }
    double Stdev (void) const { return s_log; }
};

//----------------------------------------------------------------------------//
// class ExponentialDistribution: exponentially distributed random numbers    //
//----------------------------------------------------------------------------//

class ExponentialDistribution : public RandomGenerator 
{
  protected:
    double m, scale;
  public:
    ExponentialDistribution (void) {}
    ExponentialDistribution (double mean, RandomGenerator* ran = 0)
	: RandomGenerator(ran), m(mean), scale(1.0/max_val) { }
    double operator () (void) { return (-m * log( gen->Long() * scale)); }
    double Mean (void) const { return m; }
};

//----------------------------------------------------------------------------//
// class ErlangDistribution: Erlang distributed random numbers		      //
//----------------------------------------------------------------------------//

class ErlangDistribution : public RandomGenerator {
  protected:
    int A;
    double B, a1, sq, scale, scale2;
    void Order (int order, double loc);
  public:
    ErlangDistribution (void) {}
    ErlangDistribution (int order, double loc, 
			RandomGenerator* ran = 0): RandomGenerator(ran) 
        { Order(order,loc); }
    double operator () (void);
    int Order (void) const { return A; }
    double Location (void) const { return B; }
};

//----------------------------------------------------------------------------//
// class GammaDistribution: Gamma distributed random numbers		      //
//----------------------------------------------------------------------------//

class GammaDistribution 
    : public NormalDistribution, 
      public ExponentialDistribution 
{
  protected:
    double A, B, s, s2, d, r, q0, b, si, c, scale;
    int algorithmGD;
    void Initialize (double order, double loc);
  public:
    GammaDistribution (void) {}
    GammaDistribution (double order, double loc, 
		       RandomGenerator* ran = 0) 
      : NormalDistribution(0.0,1.0,ran), // std. normal
        ExponentialDistribution(1.0,ran) // std. exponential
      { Initialize(order,loc); }
    double operator () (void);
    double Order (void) const { return A; }
    double Location (void) const { return B; }
};

//----------------------------------------------------------------------------//
// class BetaDistribution: Beta distributed random numbers		      //
//----------------------------------------------------------------------------//

class BetaDistribution : public RandomGenerator 
{
  protected:
    double aa, bb;
    double scale, a, alpha, b, beta, delta, gamma, k1, k2, maxexp;
    int algorithmBB;
    void Initialize (double pa, double pb);
  public:
    BetaDistribution (void) {}
    BetaDistribution (double pa, double pb, 
		      RandomGenerator* ran = 0): RandomGenerator(ran) 
        { Initialize(pa,pb); }
    double operator () (void);
    double A (void) const { return aa; }
    double B (void) const { return bb; }
};

//----------------------------------------------------------------------------//
// class ChiSquareDistribution: central chi-square distributed random numbers //
//----------------------------------------------------------------------------//

class ChiSquareDistribution : public GammaDistribution
{
  protected:
    double F;
   public:
    ChiSquareDistribution (void) {}
    ChiSquareDistribution (double f, RandomGenerator* ran = 0) 
      : GammaDistribution(0.5*f,1.0,ran), F(f) {};
    double operator () (void) 
	{ return 2.0 * this->GammaDistribution::operator()();};
    double Freedom (void) const { return F; }
};

//----------------------------------------------------------------------------//
// class FDistribution: F-distributed random numbers 		              //
//----------------------------------------------------------------------------//

class FDistribution
{
  protected:
    double NF, DF;
    ChiSquareDistribution NumChi2, DenomChi2; // uninitialized !
  public:
    FDistribution (void) {}
    FDistribution (double numf, double denomf, RandomGenerator* ran = 0); 
    double operator () (void) ;
    double NumF (void) const { return NF; }
    double DenomF (void) const { return DF; }
};

//----------------------------------------------------------------------------//
// class PoissonDistribution: Poisson distributed random numbers	      //
//----------------------------------------------------------------------------//

class PoissonDistribution : public RandomGenerator 
{
  protected:
    double scale, scalepi, m, sq, alm, g;
    void Initialize (double mean);
  public:
    PoissonDistribution (void) {}
    PoissonDistribution (double mean, 
		         RandomGenerator* ran = 0): RandomGenerator(ran) 
        { Initialize(mean); }
    double operator () (void);
    double Mean (void) const { return m; }
};

//----------------------------------------------------------------------------//
// class BinomialDistribution: Binomial distributed random numbers	      //
//----------------------------------------------------------------------------//

class BinomialDistribution : public RandomGenerator 
{
  protected:
    double scale, scalepi, p, pc, plog, pclog, np, npexp, en, en1, gamen1, sq;
    int n, sym;
    void Initialize (double pp, int nn);
  public:
    BinomialDistribution (void) {}
    BinomialDistribution (double prob, int num, 
		          RandomGenerator* ran = 0) : RandomGenerator(ran)
        { Initialize(prob,num); }

    double operator () (void);
    double Prob (void) const { return p; }
    int Num (void) const { return n; }
};

//----------------------------------------------------------------------------//
// Here start the exceptions from our nice scheme ...
//----------------------------------------------------------------------------//

class Ranmar		// James - Marsaglia - RANMAR
{
  private:
    double u[97],c,cd,cm;
    int i97, j97;
  public:
    void Seed (unsigned long seed = 0);
    Ranmar (unsigned long seed = 0) { Seed(seed); }
    double operator () (void);
};

//----------------------------------------------------------------------------//

class RanLux		// Luescher - James - Marsaglia - Zaman - RANLUX
{
  private:
    int k1,k2;
  public:
    RanLux (int luxury, unsigned long seed);
    void SetState (int luxury, unsigned long seed = 0);
    double operator () (void);
};

//----------------------------------------------------------------------------//

class Ran32k3a 		// L'Ecuyer's 1997 MRG
{
  private:
    double s10,s11,s12,s20,s21,s22;
  public:
    void SetState (unsigned long u10, unsigned long u11, unsigned long u12, 
		   unsigned long u20, unsigned long u21, unsigned long u22);
    Ran32k3a      (unsigned long u10, unsigned long u11, unsigned long u12, 
	           unsigned long u20, unsigned long u21, unsigned long u22);

    double operator () (void);
};

//----------------------------------------------------------------------------//
// class UnitSphereDistribution:		 			      //
// Vector of three random numbers distributed uniformly on the unit sphere.   //
// Uses the algorithm of Marsaglia, Ann. Math. Stat 43, 645 (1972).           //
// On average requires 2.25 deviates per vector and a square root calculation //
//----------------------------------------------------------------------------//

class UnitSphereDistribution : public RandomGenerator 
{
  protected:
    double scale;
  public:
    UnitSphereDistribution (RandomGenerator* ran = 0) 
      : RandomGenerator(ran) { scale = 2.0 / Maximum(); }
    void operator () (double& x, double &y, double &z);
 };

} // namespace MATPACK

//----------------------------------------------------------------------------//

#endif
