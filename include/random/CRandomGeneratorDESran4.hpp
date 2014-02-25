/*!
 *  \file    CRandomGeneratorDESran4.hpp Press's pseudo-DES "ran4" random
 *           number generator.
 *  \brief   Press's pseudo-DES "ran4" random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Press's pseudo-DES "ran4" random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 02:05:03

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
#ifndef __CRANDOMGENERATORDESRAN4_HPP__
#define __CRANDOMGENERATORDESRAN4_HPP__
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
//! Press's pseudo-DES "ran4" random number generator class.
/*!
    The period length for one seed  is  2^32,  but  the  seed  is  incremented
    automatically if the series for one seed  is  exhausted.  There  are  2^32
    possible seeds.

    Notes:
    - The original version of Ref. (1) is not portable to machines with larger
      word lengths. That means different random  sequences  are  obtained  for
      32-bit long integers and 64-bit long integers.
    - This version is made portable by using bit-masks. The run  time  penalty
      is negligible.
    - The random sequence for one seed has only a period  of  maximally  2^32.
      This is definitely to short for nowadays MC simulations. In this version
      the seed is automatically incremented to jump to the next  segment  when
      one segment is exhausted.
    - Also the extremely inconvenient  interface  of  the  original  has  been
      changed.

    References:
    - W.H. Press, S.A. Teukolsky, Vetterling, Teukolsky,
      Numerical Recipies in C, 2nd edition, 1992.
    - Major modifications a) to c) and inclusion into Matpack
      by B. M. Gammel, Apr 1, 1997 (no joke!)
*/
class RANDOM_API CRandomGeneratorDESran4 :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorDESran4 TDepthCheckType;

  // Check CRandomGeneratorDESran4 class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorDESran4(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorDESran4 class.
  */
  CRandomGeneratorDESran4(const CRandomGeneratorDESran4& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorDESran4();

  //! Operator: Assign another CRandomGeneratorDESran4 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorDESran4 class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorDESran4& operator = (const CRandomGeneratorDESran4& a_crInstance);

  //! Set another CRandomGeneratorDESran4 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorDESran4 class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorDESran4& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorDESran4 class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorDESran4 class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorDESran4 class instance.
  */
  void swap(CRandomGeneratorDESran4& a_rInstance);

private:
  Tuint m_idums;                        //!< Generator state.
  Tuint m_idum;                         //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorDESran4.inl>
/*==========================================================================*/
#endif
