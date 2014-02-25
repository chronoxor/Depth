/*!
 *  \file    CRandomGeneratorMLCGran1.hpp Press's MLCG "ran1" random number
 *           generator.
 *  \brief   Press's MLCG "ran1" random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Press's MLCG "ran1" random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 03:55:10

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
#ifndef __CRANDOMGENERATORMLCGRAN1_HPP__
#define __CRANDOMGENERATORMLCGRAN1_HPP__
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
//! Press's MLCG "ran1" random number generator class.
/*!
    Notes:
    - Minimal random number generator of  Park  and  Miller  with  Bays-Durham
      shuffle and added safeguards.
    - The period is 2^31-2 = 2.1*10^9. If your application needs more  numbers
      in sequence than 1% of the random generators period, i.e. 10^7, then use
      a more elaborate random generator. There are no statistical tests  known
      that it fails to pass, except when the number of calls starts to  become
      on the order of the period. When you need longer  random  sequences  you
      should use another random generator, for example Ran003 or Ran014.
    - At least 32 bit long int is required, but works  with  any  larger  word
      lengths.

    References:
    - Algorithm "ran1" published in "Portable Random Number Generators",
      William H. Press and Saul A. Teukolsky
      Computers in Phyics, Vol. 6, No. 5, Sep/Oct 1992
*/
class RANDOM_API CRandomGeneratorMLCGran1 :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorMLCGran1 TDepthCheckType;

  // Check CRandomGeneratorMLCGran1 class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorMLCGran1(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMLCGran1 class.
  */
  CRandomGeneratorMLCGran1(const CRandomGeneratorMLCGran1& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorMLCGran1();

  //! Operator: Assign another CRandomGeneratorMLCGran1 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMLCGran1 class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorMLCGran1& operator = (const CRandomGeneratorMLCGran1& a_crInstance);

  //! Set another CRandomGeneratorMLCGran1 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMLCGran1 class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorMLCGran1& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorMLCGran1 class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorMLCGran1 class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorMLCGran1 class instance.
  */
  void swap(CRandomGeneratorMLCGran1& a_rInstance);

private:
  Tsint m_idum;                         //!< Generator state.
  Tsint m_iy;                           //!< Generator state.
  Tsint m_iv[32];                       //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorMLCGran1.inl>
/*==========================================================================*/
#endif
