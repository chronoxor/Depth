/*!
 *  \file    CDistributionBeta.hpp Beta distribution class.
 *  \brief   Beta distribution class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    04.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Beta distribution class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   04.03.2009 20:46:14

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
#ifndef __CDISTRIBUTIONBETA_HPP__
#define __CDISTRIBUTIONBETA_HPP__
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
//! Beta distribution class.
/*!
    Return Beta distributed random deviates according to the density:

                     a-1       b-1
                    x     (1-x)
      p   (x) dx = --------------- dx   for 0 < x < 1
       a,b              B(a,b)

                 =  0                   otherwise

    References:
    - R. C. H. Cheng, Generating Beta Variatew with Non-integral Shape
      Parameters, Comm. ACM, 21, 317-322 (1978). (Algorithms BB and BC).
*/
class STATISTIC_API CDistributionBeta :
  public IDistribution
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDistributionBeta TDepthCheckType;

  // Check CDistributionBeta class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cPA - PA parameter (must be greater than 0.0) (default is 0.5).
      \param a_cPB - PB parameter (must be greater than 0.0) (default is 0.5).
      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
  */
  CDistributionBeta(const Treal a_cPA = CONSTR(0.5), const Treal a_cPB = CONSTR(0.5), NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionBeta class.
  */
  CDistributionBeta(const CDistributionBeta& a_crInstance);
  //! Class virtual destructor.
  virtual ~CDistributionBeta();

  //! Operator: Assign another CDistributionBeta class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionBeta class.
      \return Reference to the current class instance.
  */
  CDistributionBeta& operator = (const CDistributionBeta& a_crInstance);

  //! Set another CDistributionBeta class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionBeta class.
      \return true  - if another distribution was successfully set. \n
              false - if another distribution was not successfully set. \n
  */
  Tbool set(const CDistributionBeta& a_crInstance);

  //! Set distribution parameters.
  /*!
      \param a_cPA - PA parameter (must be greater than 0.0).
      \param a_cPB - PB parameter (must be greater than 0.0).
      \return true  - if distribution parameters were successfully set. \n
              false - if distribution parameters were not successfully set. \n
  */
  Tbool setParameters(const Treal a_cPA, const Treal a_cPB);
  //! Get distribution PA parameter.
  /*!
      \return PA parameter.
  */
  Treal getPA() const;
  //! Get distribution PB parameter.
  /*!
      \return PB parameter.
  */
  Treal getPB() const;

  // IDistribution interface overriding methods.
  virtual Treal randomReal();

  //! Serialize CDistributionBeta class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDistributionBeta class instances.
  /*!
      \param a_rInstance - Reference to another CDistributionBeta class instance.
  */
  void swap(CDistributionBeta& a_rInstance);

protected:
  Tbool m_AlgorithmBB;                  //!< Distribution state.
  Treal m_aa;                           //!< Distribution state.
  Treal m_bb;                           //!< Distribution state.
  Treal m_scale;                        //!< Distribution state.
  Treal m_a;                            //!< Distribution state.
  Treal m_alpha;                        //!< Distribution state.
  Treal m_b;                            //!< Distribution state.
  Treal m_beta;                         //!< Distribution state.
  Treal m_delta;                        //!< Distribution state.
  Treal m_gamma;                        //!< Distribution state.
  Treal m_k1;                           //!< Distribution state.
  Treal m_k2;                           //!< Distribution state.
  Treal m_maxexp;                       //!< Distribution state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/statistic/CDistributionBeta.inl>
/*==========================================================================*/
//! \example example-statistic-CDistributionBeta.cpp
/*--------------------------------------------------------------------------*/
//! \test test-statistic-CDistributionBeta.cpp
/*==========================================================================*/
#endif
