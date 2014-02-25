/*!
 *  \file    CRandomGeneratorMRG32k3a.hpp L'Ecuyer's 1997 MRG "MRG32k3a"
 *           random number generator.
 *  \brief   L'Ecuyer's 1997 MRG "MRG32k3a" random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: L'Ecuyer's 1997 MRG "MRG32k3a" random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 02:18:12

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
#ifndef __CRANDOMGENERATORMRG32K3A_HPP__
#define __CRANDOMGENERATORMRG32K3A_HPP__
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
//! L'Ecuyer's 1997 MRG "MRG32k3a" random number generator class.
/*!
    The period length is about 2^191 (which  is  approximately  3*10^57).  The
    implementation  uses  floating-point  arithmetic  and  works   under   the
    sufficient condition that the double precision  floating-point  arithmetic
    satisfies the IEEE 754 standard. That means all integers between -2^53 and
    2^53 are represented exactly in a number of type double. Note,  that  this
    generator gives no more than 32 random bits  although  a  53-bit  floating
    point number is returned.

    Initialization:
    - The six global variables s10,s11,s12, s20,s21,s22 constitute  the  seed.
      Before called the first time one must initialize s10,s11,s12 to  (exact)
      non-negative integer values less than m1 (i.e. in [0...4294967086]), but
      not all zero, and s20,s21,s22 to  (exact)  non-negative  integer  values
      less than m2 (i.e. in [0...4294944442]), but not all zero.

    Notes:
    - The time being this is presumably one of the  best  pseudorandom  number
      generators and it is also very fast. (Sep 26, 1997, B.M.Gammel)
    - CPU time to generate and add 10^7 numbers: 6 sec for DEC Alpha  Station,
      21161 CPU, 400 MHz,GNU g++ 2.7.1 compiler
    - The time overhead for vs. non-operator () is about 1-2  percent  and  is
      therefore considered as neglegible.

    References:
    - Pierre L'Ecuyer, Good Parameter Sets for Combined Multiple Recursive
      Random Number Generators, Preprint, July 28, 1997, Code of Figure I.
*/
class RANDOM_API CRandomGeneratorMRG32k3a :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorMRG32k3a TDepthCheckType;

  // Check CRandomGeneratorMRG32k3a class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorMRG32k3a(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Initialize random number generator with the given 6 different seeds.
  /*!
      \param a_cSeed10 - Random generator seed value 10.
      \param a_cSeed11 - Random generator seed value 11.
      \param a_cSeed12 - Random generator seed value 12.
      \param a_cSeed20 - Random generator seed value 20.
      \param a_cSeed21 - Random generator seed value 21.
      \param a_cSeed22 - Random generator seed value 22.
  */
  CRandomGeneratorMRG32k3a(const Tuint a_cSeed10, const Tuint a_cSeed11, const Tuint a_cSeed12, const Tuint a_cSeed20, const Tuint a_cSeed21, const Tuint a_cSeed22);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMRG32k3a class.
  */
  CRandomGeneratorMRG32k3a(const CRandomGeneratorMRG32k3a& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorMRG32k3a();

  //! Operator: Assign another CRandomGeneratorMRG32k3a class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMRG32k3a class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorMRG32k3a& operator = (const CRandomGeneratorMRG32k3a& a_crInstance);

  //! Set another CRandomGeneratorMRG32k3a class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMRG32k3a class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorMRG32k3a& a_crInstance);

  //! Set 6 different seeds of the current random generator.
  /*!
      \param a_cSeed10 - Random generator seed value 10.
      \param a_cSeed11 - Random generator seed value 11.
      \param a_cSeed12 - Random generator seed value 12.
      \param a_cSeed20 - Random generator seed value 20.
      \param a_cSeed21 - Random generator seed value 21.
      \param a_cSeed22 - Random generator seed value 22.
      \return true  - if the random generator was successfully reinitialized. \n
              false - if the random generator was not successfully reinitialized. \n
  */
  Tbool setSeed(const Tuint a_cSeed10, const Tuint a_cSeed11, const Tuint a_cSeed12, const Tuint a_cSeed20, const Tuint a_cSeed21, const Tuint a_cSeed22);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorMRG32k3a class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorMRG32k3a class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorMRG32k3a class instance.
  */
  void swap(CRandomGeneratorMRG32k3a& a_rInstance);

private:
  Treal m_s10;                          //!< Generator state.
  Treal m_s11;                          //!< Generator state.
  Treal m_s12;                          //!< Generator state.
  Treal m_s20;                          //!< Generator state.
  Treal m_s21;                          //!< Generator state.
  Treal m_s22;                          //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorMRG32k3a.inl>
/*==========================================================================*/
#endif
