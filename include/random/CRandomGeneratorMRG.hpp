/*!
 *  \file    CRandomGeneratorMRG.hpp L'Ecuyer's 1996 MRG random number
 *           generator.
 *  \brief   L'Ecuyer's 1996 MRG random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: L'Ecuyer's 1996 MRG random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 21:14:07

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
#ifndef __CRANDOMGENERATORMRG_HPP__
#define __CRANDOMGENERATORMRG_HPP__
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
//! L'Ecuyer's 1996 MRG random number generator class.
/*!
    The period length is approximately 2^205 (=5*10^61). The generator returns
    uniformly distributed integers in the  range  [0,2^31-2].  It  passes  all
    current standard statistical tests.

    Notes:
    - This generator is very slow.

    References:
    - P. L'Ecuyer, "Combined Multiple Recursive Generators,"
      Operations Research 44, 5, pp. 816-822 (1996), see figure 1.
    - recommended in:
      P. L'Ecuyer, "Random number generation", chapter 4 of the
      Handbook on Simulation, Ed. Jerry Banks, Wiley, 1997.
*/
class RANDOM_API CRandomGeneratorMRG :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorMRG TDepthCheckType;

  // Check CRandomGeneratorMRG class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorMRG(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMRG class.
  */
  CRandomGeneratorMRG(const CRandomGeneratorMRG& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorMRG();

  //! Operator: Assign another CRandomGeneratorMRG class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMRG class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorMRG& operator = (const CRandomGeneratorMRG& a_crInstance);

  //! Set another CRandomGeneratorMRG class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMRG class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorMRG& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorMRG class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorMRG class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorMRG class instance.
  */
  void swap(CRandomGeneratorMRG& a_rInstance);

private:
  Tsint m_x10;                          //!< Generator state.
  Tsint m_x11;                          //!< Generator state.
  Tsint m_x12;                          //!< Generator state.
  Tsint m_x20;                          //!< Generator state.
  Tsint m_x21;                          //!< Generator state.
  Tsint m_x22;                          //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorMRG.inl>
/*==========================================================================*/
#endif
