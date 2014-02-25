/*!
 *  \file    IRandomGenerator.hpp Interface for all random number generators.
 *  \brief   Random number generator interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Random number generator interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   24.02.2009 22:42:02

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

    This program is distributed in the  hope  that  it  will  be  useful,  but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General  Public  License
    for more details.

    You should have received a copy of the GNU General  Public  License  along
    with this program; if not, write to the Free Software Foundation, Inc., 59
    Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
/*--------------------------------------------------------------------------*/
/*
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#ifndef __IRANDOMGENERATOR_HPP__
#define __IRANDOMGENERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/random.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Random number generator interface.
/*!
    Random number generator interface is used as  a  base  interface  for  all
    random number generator implementations.

    A random number generator (often abbreviated as RNG) is a computational or
    physical device designed to generate a sequence of numbers or symbols that
    any pattern, i.e. appear random. Hardware-based systems for random  number
    generation are widely used, but often fall short of this goal, though they
    may meet some of the statistical tests for randomness intended  to  ensure
    that they do  not  have  any  easily  discernible  patterns.  Methods  for
    generating random results have  existed  since  ancient  times,  including
    dice, coin flipping, the shuffling of playing cards,  the  use  of  yarrow
    stalks(by divination) in the I Ching, and many other techniques.

    The many applications of randomness have led to many different methods for
    generating random data. These methods may vary as to how unpredictable  or
    statistically random they are, and how quickly they  can  generate  random
    numbers.

    Before the advent of computational random  number  generators,  generating
    large amounts of sufficiently random  numbers  (important  in  statistics)
    required  a  lot  of  work.  Results  would  sometimes  be  collected  and
    distributed as random number tables.

    A growing number of government-run lotteries, and lottery games, are using
    RNGs instead of more traditional drawing methods, such as using  ping-pong
    or rubber balls.

    Pseudo-random  number  generators  (PRNGs)   are   algorithms   that   can
    automatically create long runs (for example,  millions  of  numbers  long)
    with good random properties but eventually the  sequence  repeats  exactly
    (or the memory usage grows without bound). One of the most common PRNG  is
    the linear congruential generator, which uses the recurrence

    \f$X_{n+1} = (a X_n + b)\, \textrm{mod}\, m\f$

    to generate numbers. The maximum number of numbers the formula can produce
    is the modulus, m. To avoid certain  non-random  properties  of  a  single
    linear congruential generator, several such random number generators  with
    slightly different values of the multiplier coeffient a are typically used
    in parallel, with a "master" random number  generator  that  selects  from
    among the several different generators.

    <b>Taken from:</b>\n
    Random number generation
    http://en.wikipedia.org/wiki/Random_number_generator
*/
class RANDOM_API IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef IRandomGenerator TDepthCheckType;

  // Check IRandomGenerator interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  //! Default interface protected constructor.
  IRandomGenerator();
  //! Interface protected copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IRandomGenerator interface.
  */
  IRandomGenerator(const IRandomGenerator & a_crInstance);

public:
  //! Interface virtual destructor.
  virtual ~IRandomGenerator();

  //! Operator: Assign another IRandomGenerator interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IRandomGenerator interface.
      \return Reference to the current interface instance.
  */
  IRandomGenerator& operator = (const IRandomGenerator& a_crInstance);

  //! Set another IRandomGenerator interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IRandomGenerator interface.
  */
  void set(const IRandomGenerator& a_crInstance);

  //! Get current seed value of the random generator.
  /*!
      \return Current seed value.
  */
  Tuint getSeed() const;
  //! Get current maximum integer random number value which can be taken from the random generator.
  /*!
      \return Current maximum integer random number value.
  */
  Tuint getMaxInteger() const;

  //! Set seed of the current random generator.
  /*!
      The method reinitializes random generator with a given seed value.

      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
      \return true  - if the random generator was successfully reinitialized. \n
              false - if the random generator was not successfully reinitialized. \n
  */
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed()) = 0;
  //! Get new generated integer random number.
  /*!
      The method generates new random  value  and  return  it  as  an  integer
      number.   Note   that   the   returned   integer   number  is   in   the
      [0, IRandomGenerator::getMaxInteger()] interval.

      \return Generated integer random value.
  */
  virtual Tuint randomInteger() = 0;
  //! Get new generated real random number.
  /*!
      The method generates new random value and return it as  a  real  number.
      Note that the returned real number is in the [0.0, 1.0] interval.

      \return Generated real random value.
  */
  virtual Treal randomReal() = 0;

  //! Get system unique seed.
  /*!
      The  method  returns  system  dependent  unique  seed  value.  For  most
      implementations system unique seed value is calculated from the  current
      time value.

      \return System dependent unique seed value.
  */
  static Tuint getSystemSeed();

  //! Serialize IRandomGenerator interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IRandomGenerator interface instances.
  /*!
      \param a_rInstance - Reference to another IRandomGenerator interface instance.
  */
  void swap(IRandomGenerator& a_rInstance);

protected:
  Tuint m_Seed;                         //!< Current seed value of the generator.
  Tuint m_MaxInteger;                   //!< Current maximum integer random number value of the generator.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/IRandomGenerator.inl>
/*==========================================================================*/
//! \example example-random-IRandomGenerator.cpp
/*--------------------------------------------------------------------------*/
//! \test test-random-IRandomGenerator.cpp
/*==========================================================================*/
#endif
