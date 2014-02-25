/*!
 *  \file    CRandomGeneratorFibonacciEx.hpp Extended Knuth's lagged Fibonacci
 *           random number generator.
 *  \brief   Extended Knuth's lagged Fibonacci random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Extended Knuth's lagged Fibonacci random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 20:55:36

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
#ifndef __CRANDOMGENERATORFIBONACCIEX_HPP__
#define __CRANDOMGENERATORFIBONACCIEX_HPP__
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
//! Extended Knuth's lagged Fibonacci random number generator class.
/*!
    Notes:
    - The period is 2^55/3 > 1.2*10^16.
    - At least 32 bit long int is required, but works  with  any  larger  word
      lengths.
    - This is the same lagged Fibonacci generator as Ran055
        x(n) =  ( x(n-55) - x(n-24) ) mod 2^31
    - But a decimation strategy is applied to remove the  known  correlations.
      Only every 3rd number will be used.

    References:
    - I. Vattulainen, T. Ala-Nissila, and K. Kankaala,
      Physical Tests for Random Numbers in Simulations,
      Phys. Rev. Lett. 73, 2513 (1994).
*/
class RANDOM_API CRandomGeneratorFibonacciEx :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorFibonacciEx TDepthCheckType;

  // Check CRandomGeneratorFibonacciEx class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorFibonacciEx(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorFibonacciEx class.
  */
  CRandomGeneratorFibonacciEx(const CRandomGeneratorFibonacciEx& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorFibonacciEx();

  //! Operator: Assign another CRandomGeneratorFibonacciEx class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorFibonacciEx class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorFibonacciEx& operator = (const CRandomGeneratorFibonacciEx& a_crInstance);

  //! Set another CRandomGeneratorFibonacciEx class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorFibonacciEx class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorFibonacciEx& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorFibonacciEx class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorFibonacciEx class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorFibonacciEx class instance.
  */
  void swap(CRandomGeneratorFibonacciEx& a_rInstance);

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
#include <Depth/include/random/CRandomGeneratorFibonacciEx.inl>
/*==========================================================================*/
#endif
