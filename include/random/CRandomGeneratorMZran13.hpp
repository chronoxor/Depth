/*!
 *  \file    CRandomGeneratorMZran13.hpp Marsaglia's combined congruential
 *           random number generator.
 *  \brief   Minimal congruential random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Marsaglia's combined congruential random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 02:54:51

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
#ifndef __CRANDOMGENERATORMZRAN13_HPP__
#define __CRANDOMGENERATORMZRAN13_HPP__
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
//! Marsaglia's combined congruential random number generator class.
/*!
    Notes:
    - The period is about 2^125 > 4.25*10^37.
    - At least 32 bit long int is required, but works  with  any  larger  word
      lengths.

    References:
    - This is algorithm "mzran13"  from  G.  Marsaglia  and  A.  Zaman,  "Some
      portable  very-long-period  random  number  generators",  Computers   in
      Physics, Vol. 8, No. 1, Jan/Feb 1994.

      In the original implementation the algorithm relies on 32-bit arithmetic
      with implicit modulo 2^32 on overflow. Since the the  size  of  unsigned
      longs may not always be 32 bit the modulo 2^32 is coded explicitly using
      masks. The performance loss is not very important.

      The original code reads:

          long s;
          if (y > x+c)
           s = y - (x+c); c = 0;
          else
           s = y - (x+c) - 18; c = 1;
          x = y;
          y = z;
          return ((z = s) + (n - 69069 * n + 1013904243));
                               ^
                               Here it contains a misprint
                               Should really be a "=" !
*/
class RANDOM_API CRandomGeneratorMZran13 :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorMZran13 TDepthCheckType;

  // Check CRandomGeneratorMZran13 class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorMZran13(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMZran13 class.
  */
  CRandomGeneratorMZran13(const CRandomGeneratorMZran13& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorMZran13();

  //! Operator: Assign another CRandomGeneratorMZran13 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMZran13 class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorMZran13& operator = (const CRandomGeneratorMZran13& a_crInstance);

  //! Set another CRandomGeneratorMZran13 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMZran13 class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorMZran13& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorMZran13 class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorMZran13 class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorMZran13 class instance.
  */
  void swap(CRandomGeneratorMZran13& a_rInstance);

private:
  Tuint m_x;                            //!< Generator state.
  Tuint m_y;                            //!< Generator state.
  Tuint m_z;                            //!< Generator state.
  Tuint m_n;                            //!< Generator state.
  Tuint m_c;                            //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorMZran13.inl>
/*==========================================================================*/
#endif
