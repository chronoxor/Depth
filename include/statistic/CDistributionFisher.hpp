/*!
 *  \file    CDistributionFisher.hpp Fisher-Snedecor distribution class.
 *  \brief   Fisher-Snedecor distribution class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Fisher-Snedecor distribution class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:12:41

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
#ifndef __CDISTRIBUTIONFISHER_HPP__
#define __CDISTRIBUTIONFISHER_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/statistic/IDistribution.hpp>
#include <Depth/include/statistic/CDistributionChiSquare.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Fisher-Snedecor distribution class.
/*!
    Return F-distributed (variance ratio distributed) random deviates  with  n
    numerator  degrees  of  freedom  and  d  denominator  degrees  of  freedom
    according to the density:

      p   (x) dx = ... dx
       n,d

    Both paramters n and d must be positive.

    Method: The random numbers are directly generated from ratios of ChiSquare
            variates according to: F = (ChiSquare(n)/n) / (ChiSquare(d)/d).
*/
class STATISTIC_API CDistributionFisher :
  public IDistribution
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDistributionFisher TDepthCheckType;

  // Check CDistributionFisher class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cNumF - Numerator degrees of freedom parameter (must be greater than 0.0) (default is 1.0).
      \param a_cDenomF - Denominator degrees of freedom parameter (must be greater than 0.0) (default is 1.0).
      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
  */
  CDistributionFisher(const Treal a_cNumF = CONSTR(1.0), const Treal a_cDenomF = CONSTR(1.0), NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionFisher class.
  */
  CDistributionFisher(const CDistributionFisher& a_crInstance);
  //! Class virtual destructor.
  virtual ~CDistributionFisher();

  //! Operator: Assign another CDistributionFisher class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionFisher class.
      \return Reference to the current class instance.
  */
  CDistributionFisher& operator = (const CDistributionFisher& a_crInstance);

  //! Set another CDistributionFisher class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionFisher class.
      \return true  - if another distribution was successfully set. \n
              false - if another distribution was not successfully set. \n
  */
  Tbool set(const CDistributionFisher& a_crInstance);

  //! Set distribution parameters.
  /*!
      \param a_cNumF - Numerator degrees of freedom parameter (must be greater than 0.0).
      \param a_cDenomF - Denominator degrees of freedom parameter (must be greater than 0.0).
      \return true  - if distribution parameters were successfully set. \n
              false - if distribution parameters were not successfully set. \n
  */
  Tbool setParameters(const Treal a_cNumF, const Treal a_cDenomF);
  //! Get distribution numerator degrees of freedom parameter.
  /*!
      \return Numerator degrees of freedom parameter.
  */
  Treal getNumF() const;
  //! Get distribution denominator degrees of freedom parameter.
  /*!
      \return Denominator degrees of freedom parameter.
  */
  Treal getDenomF() const;

  // IDistribution interface overriding methods.
  virtual Treal randomReal();

  //! Serialize CDistributionFisher class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDistributionFisher class instances.
  /*!
      \param a_rInstance - Reference to another CDistributionFisher class instance.
  */
  void swap(CDistributionFisher& a_rInstance);

protected:
  Treal m_NF;                           //!< Distribution state.
  Treal m_DF;                           //!< Distribution state.
  CDistributionChiSquare m_NumChi2;     //!< Distribution state.
  CDistributionChiSquare m_DenomChi2;   //!< Distribution state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/statistic/CDistributionFisher.inl>
/*==========================================================================*/
//! \example example-statistic-CDistributionFisher.cpp
/*--------------------------------------------------------------------------*/
//! \test test-statistic-CDistributionFisher.cpp
/*==========================================================================*/
#endif
