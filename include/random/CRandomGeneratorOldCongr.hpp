/*!
 *  \file    CRandomGeneratorOldCongr.hpp Press's old congruential with
 *           shuffle random number generator.
 *  \brief   Press's old congruential with shuffle random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Press's old congruential with shuffle random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 02:23:39

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
#ifndef __CRANDOMGENERATOROLDCONGR_HPP__
#define __CRANDOMGENERATOROLDCONGR_HPP__
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
//! Press's old congruential with shuffle random number generator class.
/*!
    Notes:
    - NOT RECOMMENDED FOR SERIOUS APPLICATIONS. Just  use  it  for  comparison
      purposes, etc.
    - As you see the spacing of the numbers is very coarse.
    - Low order correlation is present.
    - The period is effectively infinite.
    - At least 32 bit long int is required.

    References:
    - Corresponds to generator "ran2" of
      W. H. Press, B. P. Flannery, S. A. Teukolsky, W. T. Vetterling,
      Numerical Recipies in C, Cambridge Univ. Press, 1988.
    - The generator is based upon
      D. H. Knuth: The Art of Computer Programming, Vol.2, 2nd ed., 1981
*/
class RANDOM_API CRandomGeneratorOldCongr :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorOldCongr TDepthCheckType;

  // Check CRandomGeneratorOldCongr class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorOldCongr(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorOldCongr class.
  */
  CRandomGeneratorOldCongr(const CRandomGeneratorOldCongr& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorOldCongr();

  //! Operator: Assign another CRandomGeneratorOldCongr class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorOldCongr class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorOldCongr& operator = (const CRandomGeneratorOldCongr& a_crInstance);

  //! Set another CRandomGeneratorOldCongr class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorOldCongr class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorOldCongr& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorOldCongr class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorOldCongr class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorOldCongr class instance.
  */
  void swap(CRandomGeneratorOldCongr& a_rInstance);

private:
  Tsint m_r[98];                        //!< Generator state.
  Tsint m_x;                            //!< Generator state.
  Tsint m_y;                            //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorOldCongr.inl>
/*==========================================================================*/
#endif
