/*!
 *  \file    CDistributionExponential.hpp Exponential distribution class.
 *  \brief   Exponential distribution class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Exponential distribution class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:09:36

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
#ifndef __CDISTRIBUTIONEXPONENTIAL_HPP__
#define __CDISTRIBUTIONEXPONENTIAL_HPP__
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
//! Exponential distribution class.
/*!
    Return exponentially distributed random deviates according to:

      p (x) = 1/m * exp(-x/m) dx   for x >= 0
       m
            = 0                    otherwise

    The probability density has mean = stdev = m.
*/
class STATISTIC_API CDistributionExponential :
  public IDistribution
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDistributionExponential TDepthCheckType;

  // Check CDistributionExponential class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cMean - Mean parameter (default is 1.0).
      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
  */
  CDistributionExponential(const Treal a_cMean = CONSTR(1.0), NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionExponential class.
  */
  CDistributionExponential(const CDistributionExponential& a_crInstance);
  //! Class virtual destructor.
  virtual ~CDistributionExponential();

  //! Operator: Assign another CDistributionExponential class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionExponential class.
      \return Reference to the current class instance.
  */
  CDistributionExponential& operator = (const CDistributionExponential& a_crInstance);

  //! Set another CDistributionExponential class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionExponential class.
      \return true  - if another distribution was successfully set. \n
              false - if another distribution was not successfully set. \n
  */
  Tbool set(const CDistributionExponential& a_crInstance);

  //! Set distribution parameters.
  /*!
      \param a_cMean - Mean parameter.
      \return true  - if distribution parameters were successfully set. \n
              false - if distribution parameters were not successfully set. \n
  */
  Tbool setParameters(const Treal a_cMean);
  //! Get distribution mean parameter.
  /*!
      \return Mean parameter.
  */
  Treal getMean() const;

  // IDistribution interface overriding methods.
  virtual Treal randomReal();

  //! Serialize CDistributionExponential class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDistributionExponential class instances.
  /*!
      \param a_rInstance - Reference to another CDistributionExponential class instance.
  */
  void swap(CDistributionExponential& a_rInstance);

protected:
  Treal m_M;                            //!< Distribution state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/statistic/CDistributionExponential.inl>
/*==========================================================================*/
//! \example example-statistic-CDistributionExponential.cpp
/*--------------------------------------------------------------------------*/
//! \test test-statistic-CDistributionExponential.cpp
/*==========================================================================*/
#endif
