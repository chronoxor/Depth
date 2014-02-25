/*!
 *  \file    CRandomGeneratorTaus88.hpp L'Ecuyer's 1996 Tausworthe "taus88"
 *           random number generator.
 *  \brief   L'Ecuyer's 1996 Tausworthe "taus88" random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: L'Ecuyer's 1996 Tausworthe "taus88" random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 21:05:12

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
#ifndef __CRANDOMGENERATORTAUS88_HPP__
#define __CRANDOMGENERATORTAUS88_HPP__
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
//! L'Ecuyer's 1996 Tausworthe "taus88" random number generator class.
/*!
    Notes:
     - The period length is approximately 2^88 (which is 3*10^26).
     - This generator is very fast and passes all standard statistical tests.

    References:
    - P. L'Ecuyer, Maximally equidistributed combined Tausworthe generators
      Mathematics of Computation, 65, 203-213 (1996), see Figure 4.
    - recommended in:
      P. L'Ecuyer, Random number generation, chapter 4 of the
      Handbook on Simulation, Ed. Jerry Banks, Wiley, 1997.
*/
class RANDOM_API CRandomGeneratorTaus88 :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorTaus88 TDepthCheckType;

  // Check CRandomGeneratorTaus88 class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorTaus88(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorTaus88 class.
  */
  CRandomGeneratorTaus88(const CRandomGeneratorTaus88& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorTaus88();

  //! Operator: Assign another CRandomGeneratorTaus88 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorTaus88 class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorTaus88& operator = (const CRandomGeneratorTaus88& a_crInstance);

  //! Set another CRandomGeneratorTaus88 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorTaus88 class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorTaus88& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorTaus88 class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorTaus88 class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorTaus88 class instance.
  */
  void swap(CRandomGeneratorTaus88& a_rInstance);

private:
  Tuint m_s1;                           //!< Generator state.
  Tuint m_s2;                           //!< Generator state.
  Tuint m_s3;                           //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorTaus88.inl>
/*==========================================================================*/
#endif
