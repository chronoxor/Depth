/*!
 *  \file    CDistributionGamma.hpp Gamma distribution class.
 *  \brief   Gamma distribution class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Gamma distribution class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:13:55

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
#ifndef __CDISTRIBUTIONGAMMA_HPP__
#define __CDISTRIBUTIONGAMMA_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/statistic/IDistribution.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Gamma distribution class.
/*!
    Return Gamma distributed random deviates according to:

                          a-1  -bx
                    b (bx)    e
      p   (x) dx = ---------------- dx   for x > 0
       a,b             Gamma(a)

                 =  0                    otherwise

    The arguments must satisfy the conditions:
      a > 0   (positive)
      b != 0  (non-zero)

    References:
    - For parameter a >= 1 corresponds to algorithm GD in:
      J. H. Ahrens and U. Dieter, Generating Gamma Variates by a
      Modified Rejection Technique, Comm. ACM, 25, 1, 47-54 (1982).
    - For parameter 0 < a < 1 corresponds to algorithm GS in:
      J. H. Ahrens and U. Dieter, Computer Methods for Sampling
      from Gamma, Beta, Poisson and Binomial Distributions,
      Computing, 12, 223-246 (1974).
*/
class STATISTIC_API CDistributionGamma :
  public IDistribution
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDistributionGamma TDepthCheckType;

  // Check CDistributionGamma class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cOrder - Order parameter (must be greater than 0.0) (default is 1.0).
      \param a_cLocation - Location parameter (must not be equal to 0.0) (default is 2.0).
      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
  */
  CDistributionGamma(const Treal a_cOrder = CONSTR(1.0), const Treal a_cLocation = CONSTR(2.0), NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionGamma class.
  */
  CDistributionGamma(const CDistributionGamma& a_crInstance);
  //! Class virtual destructor.
  virtual ~CDistributionGamma();

  //! Operator: Assign another CDistributionGamma class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionGamma class.
      \return Reference to the current class instance.
  */
  CDistributionGamma& operator = (const CDistributionGamma& a_crInstance);

  //! Set another CDistributionGamma class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionGamma class.
      \return true  - if another distribution was successfully set. \n
              false - if another distribution was not successfully set. \n
  */
  Tbool set(const CDistributionGamma& a_crInstance);

  //! Set distribution parameters.
  /*!
      \param a_cOrder - Order parameter (must be greater than 0.0).
      \param a_cLocation - Location parameter (must not be equal to 0.0).
      \return true  - if distribution parameters were successfully set. \n
              false - if distribution parameters were not successfully set. \n
  */
  Tbool setParameters(const Treal a_cOrder, const Treal a_cLocation);
  //! Get distribution order parameter.
  /*!
      \return Order parameter.
  */
  Treal getOrder() const;
  //! Get distribution location parameter.
  /*!
      \return Location parameter.
  */
  Treal getLocation() const;

  // IDistribution interface overriding methods.
  virtual Treal randomReal();

  //! Serialize CDistributionGamma class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDistributionGamma class instances.
  /*!
      \param a_rInstance - Reference to another CDistributionGamma class instance.
  */
  void swap(CDistributionGamma& a_rInstance);

protected:
  Tbool m_AlgorithmGD;                  //!< Distribution state.
  Tbool m_Cached;                       //!< Distribution state.
  Treal m_Cache;                        //!< Distribution state.
  Treal m_A;                            //!< Distribution state.
  Treal m_B;                            //!< Distribution state.
  Treal m_s;                            //!< Distribution state.
  Treal m_s2;                           //!< Distribution state.
  Treal m_d;                            //!< Distribution state.
  Treal m_r;                            //!< Distribution state.
  Treal m_q0;                           //!< Distribution state.
  Treal m_b;                            //!< Distribution state.
  Treal m_si;                           //!< Distribution state.
  Treal m_c;                            //!< Distribution state.
  Treal m_scale;                        //!< Distribution state.
  Treal m_M;                            //!< Distribution state.
  Treal m_S;                            //!< Distribution state.
  Treal m_MExp;                         //!< Distribution state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/statistic/CDistributionGamma.inl>
/*==========================================================================*/
//! \example example-statistic-CDistributionGamma.cpp
/*--------------------------------------------------------------------------*/
//! \test test-statistic-CDistributionGamma.cpp
/*==========================================================================*/
#endif
