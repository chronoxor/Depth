/*!
 *  \file    CDistributionLogNormal.hpp Log-normal distribution class.
 *  \brief   Log-normal distribution class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Log-normal distribution class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:15:23

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
#ifndef __CDISTRIBUTIONLOGNORMAL_HPP__
#define __CDISTRIBUTIONLOGNORMAL_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/statistic/IDistribution.hpp>
#include <Depth/include/statistic/CDistributionNormal.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Log-normal distribution class.
/*!
    Return log-normal distributed random deviates with given mean and standard
    deviation stdev according to the density function:

                                                 2
                          1                (ln x - m)
      p   (x) dx =  -------------- exp( - ------------ ) dx  for x > 0
       m,s          sqrt(2 pi x) s               2
                                              2 s

                 = 0   otherwise

      where  m  and  s  are related to the arguments mean and stdev by:

                             2
                         mean
      m = ln ( --------------------- )
                          2      2
               sqrt( stdev + mean  )

                          2      2
                     stdev + mean
      s = sqrt( ln( -------------- ) )
                             2
                         mean
*/
class STATISTIC_API CDistributionLogNormal :
  public CDistributionNormal
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDistributionLogNormal TDepthCheckType;

  // Check CDistributionLogNormal class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cMean - Mean parameter (default is 1.0).
      \param a_cStdDev - Standard deviation parameter (default is 1.0).
      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
  */
  CDistributionLogNormal(const Treal a_cMean = CONSTR(1.0), const Treal a_cStdDev = CONSTR(1.0), NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionLogNormal class.
  */
  CDistributionLogNormal(const CDistributionLogNormal& a_crInstance);
  //! Class virtual destructor.
  virtual ~CDistributionLogNormal();

  //! Operator: Assign another CDistributionLogNormal class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionLogNormal class.
      \return Reference to the current class instance.
  */
  CDistributionLogNormal& operator = (const CDistributionLogNormal& a_crInstance);

  //! Set another CDistributionLogNormal class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionLogNormal class.
      \return true  - if another distribution was successfully set. \n
              false - if another distribution was not successfully set. \n
  */
  Tbool set(const CDistributionLogNormal& a_crInstance);

  //! Set distribution parameters.
  /*!
      \param a_cMean - Mean parameter.
      \param a_cStdDev - Standard deviation parameter.
      \return true  - if distribution parameters were successfully set. \n
              false - if distribution parameters were not successfully set. \n
  */
  Tbool setParameters(const Treal a_cMean, const Treal a_cStdDev);
  //! Get distribution mean parameter.
  /*!
      \return Mean parameter.
  */
  Treal getMean() const;
  //! Get distribution standard deviation parameter.
  /*!
      \return Standard deviation parameter.
  */
  Treal getStdDev() const;

  // IDistribution interface overriding methods.
  virtual Treal randomReal();

  //! Serialize CDistributionLogNormal class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDistributionLogNormal class instances.
  /*!
      \param a_rInstance - Reference to another CDistributionLogNormal class instance.
  */
  void swap(CDistributionLogNormal& a_rInstance);

protected:
  Treal m_MLog;                         //!< Distribution state.
  Treal m_SLog;                         //!< Distribution state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/statistic/CDistributionLogNormal.inl>
/*==========================================================================*/
//! \example example-statistic-CDistributionLogNormal.cpp
/*--------------------------------------------------------------------------*/
//! \test test-statistic-CDistributionLogNormal.cpp
/*==========================================================================*/
#endif
