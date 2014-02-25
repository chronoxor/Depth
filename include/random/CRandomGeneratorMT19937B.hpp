/*!
 *  \file    CRandomGeneratorMT19937B.hpp Matsumoto's GFSR "MT19937B" random
 *           number generator.
 *  \brief   Matsumoto's GFSR "MT19937B" random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Matsumoto's GFSR "MT19937B" random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 03:19:00

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
#ifndef __CRANDOMGENERATORMT19937B_HPP__
#define __CRANDOMGENERATORMT19937B_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/random/IRandomGenerator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Matsumoto's GFSR "MT19937B" random number generator class.
/*!
    The Mersenne Twister, a new variant  of  the  twisted  GFSR  ("TGFSR")  by
    Matsumoto and Nishimura, sets new standards for the  period,  quality  and
    speed of random number generators. The incredible period is 2^19937 - 1, a
    number with about 6000 decimal digits; the 32-bit random  numbers  exhibit
    best possible equidistribution properties in dimensions  up  to  623;  and
    it's fast, very fast. A paper on the Mersenne Twister has  been  submitted
    to ACM TOMACS.

    May 1997: First empirical results for this generator are available on  the
    news page of the pLab group at the University  of  Salzburg's  Mathematics
    Department. WWW address: "http:/random.mat.sbg.ac.at/news/".

    The original code has been adapted to the general random  generator  class
    interface of Matpack, 1997.

    Original Notes of the authors:
    - A  C-program  for  MT19937B:  Integer  Version  genrand()  generate  one
      pseudorandom integer which is  uniformly  distributed  among  the  32bit
      unsigned integers sgenrand(seed) set initial values to the working  area
      of  624  words.  sgenrand(seed)  must  be  called  once  before  calling
      genrand() (seed is any integer except 0).

    LICENCE CONDITIONS:
    - Matsumoto and Nishimura consent to GNU General Public Licence  for  this
      code.

    NOTE:
      When you use it in your program, please let Matsumoto know it.
      <matumoto@math.keio.ac.jp>
*/
class RANDOM_API CRandomGeneratorMT19937B :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorMT19937B TDepthCheckType;

  // Check CRandomGeneratorMT19937B class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorMT19937B(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMT19937B class.
  */
  CRandomGeneratorMT19937B(const CRandomGeneratorMT19937B& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorMT19937B();

  //! Operator: Assign another CRandomGeneratorMT19937B class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMT19937B class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorMT19937B& operator = (const CRandomGeneratorMT19937B& a_crInstance);

  //! Set another CRandomGeneratorMT19937B class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMT19937B class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorMT19937B& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorMT19937B class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorMT19937B class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorMT19937B class instance.
  */
  void swap(CRandomGeneratorMT19937B& a_rInstance);

private:
  Tsint m_k;                            //!< Generator state.
  Tuint m_ptgfsr[624];                  //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorMT19937B.inl>
/*==========================================================================*/
#endif
