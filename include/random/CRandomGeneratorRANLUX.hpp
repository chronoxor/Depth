/*!
 *  \file    CRandomGeneratorRANLUX.hpp Luescher-James-Marsaglia-Zaman
 *           "RANLUX" random number generator.
 *  \brief   Luescher-James-Marsaglia-Zaman "RANLUX" random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Luescher-James-Marsaglia-Zaman "RANLUX" random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 02:13:00

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
#ifndef __CRANDOMGENERATORRANLUX_HPP__
#define __CRANDOMGENERATORRANLUX_HPP__
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
//! Luescher-James-Marsaglia-Zaman "RANLUX" random number generator class.
/*!
    Subtract-and-borrow random number  generator  proposed  by  Marsaglia  and
    Zaman, implemented by F. James with the name RCARRY  in  1991,  and  later
    improved by Martin  Luescher  in  1993  to  produce  "Luxury  Pseudorandom
    Numbers". Fortran 77 coded by F. James, 1993

    LUXURY LEVELS
    -------------
    The available luxury levels are:

     level 0  (p=24): equivalent to the original RCARRY of Marsaglia
              and Zaman, very long period, but fails many tests.
     level 1  (p=48): considerable improvement in quality over level 0,
              now passes the gap test, but still fails spectral test.
     level 2  (p=97): passes all known tests, but theoretically still
              defective.
     level 3  (p=223): DEFAULT VALUE.  Any theoretically possible
              correlations have very small chance of being observed.
     level 4  (p=389): highest possible luxury, all 24 bits chaotic.


    Calling sequences for RANLUX
    ----------------------------
         CALL RANLUX (RDUM) returns a 32-bit random floating point
                  numbers between zero (not included) and one
                  (also not incl.).

         CALL RANLUXGO(LUX,INT,K1,K2) initializes the generator from
                  one 32-bit integer INT and sets Luxury Level LUX
                  which is integer between zero and MAXLEV, or if
                  LUX .GT. 24, it sets p=LUX directly.  K1 and K2
                  should be set to zero unless restarting at a break
                  point given by output of RLUXAT (see RLUXAT).

         CALL RANLUXAT(LUX,INT,K1,K2) gets the values of four integers
                  which can be used to restart the RANLUX generator
                  at the current point by calling RLUXGO.  K1 and K2
                  specify how many numbers were generated since the
                  initialization with LUX and INT.  The restarting
                  skips over  K1+K2*E9   numbers, so it can be long.

      A more efficient but less convenient way of restarting is by:
         CALL RANLUXIN(ISVEC)  restarts the generator from vector
                  ISVEC of 25 32-bit integers (see RLUXUT)
         CALL RANLUXUT(ISVEC)  outputs the current values of the 25
                  32-bit integer seeds, to be used for restarting
                  ISVEC must be dimensioned 25 in the calling program
*/
class RANDOM_API CRandomGeneratorRANLUX :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorRANLUX TDepthCheckType;

  // Check CRandomGeneratorRANLUX class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed and 3-rd luxury level.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorRANLUX(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Initialize random number generator with the given seed and luxury level.
  /*!
      \param a_cSeed - Random generator seed value.
      \param a_cLuxury - Luxury level. Possible values are in [0, 4] interval.
  */
  CRandomGeneratorRANLUX(const Tuint a_cSeed, const Tuint a_cLuxury);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorRANLUX class.
  */
  CRandomGeneratorRANLUX(const CRandomGeneratorRANLUX& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorRANLUX();

  //! Operator: Assign another CRandomGeneratorRANLUX class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorRANLUX class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorRANLUX& operator = (const CRandomGeneratorRANLUX& a_crInstance);

  //! Set another CRandomGeneratorRANLUX class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorRANLUX class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorRANLUX& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Set current luxury level.
  /*!
      \param a_cLuxury - Luxury level. Possible values are in [0, 4] interval.
  */
  void setLuxury(const Tuint a_cLuxury);
  //! Get current luxury level.
  /*!
      \return Current luxury level.
  */
  Tuint getLuxury() const;

  //! Serialize CRandomGeneratorRANLUX class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorRANLUX class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorRANLUX class instance.
  */
  void swap(CRandomGeneratorRANLUX& a_rInstance);

private:
  Tsint m_Level;                        //!< Generator state.
  Tsint m_k1;                           //!< Generator state.
  Tsint m_k2;                           //!< Generator state.

  //! RANLUX method.
  /*!
      Returns a  32-bit  random  floating  point  numbers  between  zero  (not
      included) and one (also not incl.).

      \param rdum - 'rdum' value.
  */
  void RANLUX(Treal* rdum);
  //! RANLUXGo method.
  /*!
      Initializes the generator from one 32-bit integer INT  and  sets  Luxury
      Level LUX which is integer between zero and MAXLEV, or if LUX  .GT.  24,
      it sets p=LUX  directly.  K1  and  K2  should  be  set  to  zero  unless
      restarting at a break point given by output of RLUXAT (see RLUXAT).
  */
  void RANLUXGo();
  //! RANLUXAt method.
  /*!
      Gets the values of four integers which can be used to restart the RANLUX
      generator at the current point by calling RLUXGO. K1 and K2 specify  how
      many numbers were generated since the initialization with LUX  and  INT.
      The restarting skips over K1+K2*E9 numbers, so it can be long.

      \param lout - 'lout' value.
      \param inout - 'inout' value.
  */
  void RANLUXAt(Tsint* lout, Tsint* inout);
  //! RANLUXIn method.
  /*!
      Restarts the generator from vector ISVEC  of  25  32-bit  integers.

      \param isdext - 'isdext' value.
  */
  void RANLUXIn(Tsint* isdext);
  //! RANLUXUt method.
  /*!
      Outputs the current values of the 25 32-bit integer seeds,  to  be  used
      for restarting ISVEC must be dimensioned 25 in the calling program.

      \param isdext - 'isdext' value.
  */
  void RANLUXUt(Tsint* isdext);
  //! Main RANLUX driver.
  /*!
      \param what - 'what' value.
      \param rdum - 'rdum' value.
      \param isdext - 'isdext' value.
      \param lout - 'lout' value.
      \param inout - 'inout' value.
      \param k1 - 'k1' value.
      \param k2 - 'k2' value.
      \param lux - 'lux' value.
      \param ins - 'ins' value.
  */
  void RANLUXDriver(Tsint what, Treal* rdum, Tsint* isdext, Tsint* lout, Tsint* inout, Tsint* k1, Tsint* k2, Tsint lux, Tsint ins);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorRANLUX.inl>
/*==========================================================================*/
#endif
