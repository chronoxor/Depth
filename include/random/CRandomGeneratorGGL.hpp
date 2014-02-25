/*!
 *  \file    CRandomGeneratorGGL.hpp Minimal congruential random number
 *           generator.
 *  \brief   Minimal congruential random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    24.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Minimal congruential random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   24.02.2009 21:27:33

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
#ifndef __CRANDOMGENERATORGGL_HPP__
#define __CRANDOMGENERATORGGL_HPP__
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
//! Minimal congruential random number generator class.
/*!
    Notes:
    - NOT RECOMENDED FOR SERIOUS APPLICATIONS.  Just  use  it  for  comparison
      purposes, etc.
    - This generator is fast
    - "Minimal" random number generator of Park and Miller.
        x(n) = 16807 * x(n-1) mod (2^31-1)
      also known as GGL.
    - Set seed to any integer  value  (except  the  unlikely  value  mask)  to
      initialize the sequence.
    - The period is 2^31-2 = 2.1*10^9. If your application needs more  numbers
      in sequence than 1% of the random generators period, i.e. 10^7, then use
      a more elaborate random generator.
    - At least 32 bit long int is required.

    References:
    - Algorithm from CACM 31 no. 10, pp. 1192-1201, October 1988.
    - Algorithm "ran0" from "Portable Random Number Generators",
      William H. Press and Saul A Teukolsky
      Computers in Phyics, Vol. 6, No. 5, Sep/Oct 1992
    - According to a posting by Ed Taft on comp.lang.postscript,
      Level 2 (Adobe) PostScript interpreters use this algorithm too.
*/
class RANDOM_API CRandomGeneratorGGL :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorGGL TDepthCheckType;

  // Check CRandomGeneratorGGL class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorGGL(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorGGL class.
  */
  CRandomGeneratorGGL(const CRandomGeneratorGGL& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorGGL();

  //! Operator: Assign another CRandomGeneratorGGL class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorGGL class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorGGL& operator = (const CRandomGeneratorGGL& a_crInstance);

  //! Set another CRandomGeneratorGGL class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorGGL class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorGGL& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorGGL class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorGGL class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorGGL class instance.
  */
  void swap(CRandomGeneratorGGL& a_rInstance);

private:
  Tsint m_idum;                         //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorGGL.inl>
/*==========================================================================*/
#endif
