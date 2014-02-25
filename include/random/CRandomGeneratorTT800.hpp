/*!
 *  \file    CRandomGeneratorTT800.hpp Matsumoto's GFSR "TT800" random number
 *           generator.
 *  \brief   Matsumoto's GFSR "TT800" random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Matsumoto's GFSR "TT800" random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 03:13:07

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
#ifndef __CRANDOMGENERATORTT800_HPP__
#define __CRANDOMGENERATORTT800_HPP__
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
//! Matsumoto's GFSR "TT800" random number generator class.
/*!
    This is a twisted GFSR generator proposed by Matsumoto and Kurita  in  the
    ACM Transactions on Modelling and Computer  Simulation,  Vol.  4,  No.  3,
    1994, pp. 254-266. This generator has a period of 2^800 - 1 and  excellent
    equidistribution properties up to dimension 25. A TGFSR with a  period  of
    more than 2^11000 is currently under construction by M. Matsumoto  and  T.
    Nishimura.

    The original code has been adapted to the general random  generator  class
    interface of Matpack, 1997.

    Original notes of the authors:
      A C-program for TT800 : July 8th 1996 Version by  M.  Matsumoto,  email:
      matumoto@math.keio.ac.jp genrand() generate one pseudorandom number with
      double precision which is uniformly distributed  on  [0,1]-interval  for
      each call. One may choose any initial 25 seeds except all zeros.

    References:
    - ACM Transactions on Modelling and Computer Simulation,
      Vol. 4, No. 3, 1994, pages 254-266.
    - This is one of the recommended generators in:
      Pierre L'Ecuyer, "Random Number Generation", Chapter 4
      of the "Handbook on Simulation", Ed. Jerry Banks, Wiley, 1997.
*/
class RANDOM_API CRandomGeneratorTT800 :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorTT800 TDepthCheckType;

  // Check CRandomGeneratorTT800 class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorTT800(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorTT800 class.
  */
  CRandomGeneratorTT800(const CRandomGeneratorTT800& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorTT800();

  //! Operator: Assign another CRandomGeneratorTT800 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorTT800 class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorTT800& operator = (const CRandomGeneratorTT800& a_crInstance);

  //! Set another CRandomGeneratorTT800 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorTT800 class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorTT800& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorTT800 class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorTT800 class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorTT800 class instance.
  */
  void swap(CRandomGeneratorTT800& a_rInstance);

private:
  Tsint m_k;                            //!< Generator state.
  Tuint m_x[25];                        //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorTT800.inl>
/*==========================================================================*/
#endif
