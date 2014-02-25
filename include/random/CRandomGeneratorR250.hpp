/*!
 *  \file    CRandomGeneratorR250.hpp Kirkpatrick-Stoll "R250" random number
 *           generator.
 *  \brief   Kirkpatrick-Stoll "R250" random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Kirkpatrick-Stoll "R250" random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 03:08:09

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
#ifndef __CRANDOMGENERATORR250_HPP__
#define __CRANDOMGENERATORR250_HPP__
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
//! Kirkpatrick-Stoll "R250" random number generator class.
/*!
    Notes:
    - SERIOUS DEFICIENCIES IN SOME PHYSICAL SIMULATIONS HAVE BEEN FOUND  (e.g.
      in the Ising model using the Wolff cluster update algorithm)
    - The period is 2^250.
    - At least 32 bit unsigned long is required.

    References:
    - S. Kirkpatrick and E. Stoll, "A Very Fast
      Shift-Register Sequence Random Number Generator",
      Journal of Computational Physics 40, 517 (1981)
    - W.L. Maier, "A Fast Pseudo Random Number Generator",
      Dr. Dobb's Journal, May, 152-157 (1991)
*/
class RANDOM_API CRandomGeneratorR250 :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorR250 TDepthCheckType;

  // Check CRandomGeneratorR250 class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorR250(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorR250 class.
  */
  CRandomGeneratorR250(const CRandomGeneratorR250& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorR250();

  //! Operator: Assign another CRandomGeneratorR250 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorR250 class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorR250& operator = (const CRandomGeneratorR250& a_crInstance);

  //! Set another CRandomGeneratorR250 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorR250 class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorR250& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorR250 class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorR250 class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorR250 class instance.
  */
  void swap(CRandomGeneratorR250& a_rInstance);

private:
  Tsint m_Index;                        //!< Generator state.
  Tuint m_Buffer[250];                  //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorR250.inl>
/*==========================================================================*/
#endif
