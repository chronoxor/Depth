/*!
 *  \file    CRandomGeneratorFibonacci.hpp Knuth's lagged Fibonacci random
 *           number generator.
 *  \brief   Knuth's lagged Fibonacci random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Knuth's lagged Fibonacci random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 02:44:03

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
#ifndef __CRANDOMGENERATORFIBONACCI_HPP__
#define __CRANDOMGENERATORFIBONACCI_HPP__
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
//! Knuth's lagged Fibonacci random number generator class.
/*!
    Notes:
    - DON'T USE THIS GENERATOR IN SERIOUS APPLICATIONS BECAUSE IT HAS  SERIOUS
      CORRELATION.
    - The period is 2^55 = 36 028 797 018 963 968 > 3.6*10^16.
    - At least 32 bit long int is required, but works  with  any  larger  word
      lengths.
    - This is a lagged Fibonacci generator:
        x(n) =  ( x(n-55) - x(n-24) ) mod 2^31

    References:
    - A version of this pseudrandom number generator is described in
      J.Bentley's column, "The Software Exploratorium", Unix Review 1991
      It is based on Algorithm A in D. E. Knuth, The Art of Computer-
      Programming, Vol 2, Section 3.2.2, pp. 172
*/
class RANDOM_API CRandomGeneratorFibonacci :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorFibonacci TDepthCheckType;

  // Check CRandomGeneratorFibonacci class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorFibonacci(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorFibonacci class.
  */
  CRandomGeneratorFibonacci(const CRandomGeneratorFibonacci& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorFibonacci();

  //! Operator: Assign another CRandomGeneratorFibonacci class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorFibonacci class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorFibonacci& operator = (const CRandomGeneratorFibonacci& a_crInstance);

  //! Set another CRandomGeneratorFibonacci class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorFibonacci class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorFibonacci& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorFibonacci class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorFibonacci class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorFibonacci class instance.
  */
  void swap(CRandomGeneratorFibonacci& a_rInstance);

private:
  Tsint m_j55;                          //!< Generator state.
  Tsint m_k55;                          //!< Generator state.
  Tuint m_s55[55];                      //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorFibonacci.inl>
/*==========================================================================*/
#endif
