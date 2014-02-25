/*!
 *  \file    CRandomGeneratorRANMAR.hpp James-Marsaglia "RANMAR" random number
 *           generator.
 *  \brief   James-Marsaglia "RANMAR" random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: James-Marsaglia "RANMAR" random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 02:03:00

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
#ifndef __CRANDOMGENERATORRANMAR_HPP__
#define __CRANDOMGENERATORRANMAR_HPP__
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
//! James-Marsaglia "RANMAR" random number generator class.
/*!
    Notes:
    - Universal random number generator  proposed  by  Marsaglia,  Zaman,  and
      Tsang. It has a period of 2^144 = 2*10^43, and is  completely  portable.
      Only 24 bits are garantueed to  be  completely  random.  Upto  now  this
      generator passes all statistical tests on randomness.
    - Ranmar generates a sequence of random numbers uniformly  distributed  in
      the interval (0,1), the end points excluded. The seed value must  be  in
      the range 0 <= ijkl <= 900 000 000.

    References:
    - G. Marsaglia and A. Zaman, Toward a Universal Random Number Generator,
      Florida State University FSU-SCRI-87-50 (1987).
    - F. James, A Review of Pseudorandom Number Generators, Computer Phys.
      Comm. 60, 329-344 (1990).
*/
class RANDOM_API CRandomGeneratorRANMAR :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorRANMAR TDepthCheckType;

  // Check CRandomGeneratorRANMAR class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorRANMAR(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorRANMAR class.
  */
  CRandomGeneratorRANMAR(const CRandomGeneratorRANMAR& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorRANMAR();

  //! Operator: Assign another CRandomGeneratorRANMAR class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorRANMAR class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorRANMAR& operator = (const CRandomGeneratorRANMAR& a_crInstance);

  //! Set another CRandomGeneratorRANMAR class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorRANMAR class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorRANMAR& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorRANMAR class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorRANMAR class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorRANMAR class instance.
  */
  void swap(CRandomGeneratorRANMAR& a_rInstance);

private:
  Treal m_u[97];                        //!< Generator state.
  Treal m_c;                            //!< Generator state.
  Treal m_cd;                           //!< Generator state.
  Treal m_cm;                           //!< Generator state.
  Tsint m_i97;                          //!< Generator state.
  Tsint m_j97;                          //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorRANMAR.inl>
/*==========================================================================*/
#endif
