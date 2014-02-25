/*!
 *  \file    CDistributionPoisson.hpp Poisson distribution class.
 *  \brief   Poisson distribution class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Poisson distribution class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:19:42

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
#ifndef __CDISTRIBUTIONPOISSON_HPP__
#define __CDISTRIBUTIONPOISSON_HPP__
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
//! Poisson distribution class.
/*!
    Returns a Poisson distributed deviate (integer returned in a double)  from
    a distribution of mean m.

    The Poisson distribution gives the probability of a certain integer number
    m of unit rate Poisson random events occurring in a given interval of time
    x:
                               j  -x
              j+eps               x  e
      integral       p (m) dm  = -------
              j-eps   x            j !

    References:
    - W. H. Press, B. P. Flannery, S. A. Teukolsky, W. T. Vetterling,
      Numerical Recipies in C, Cambridge Univ. Press, 1988.
*/
class STATISTIC_API CDistributionPoisson :
  public IDistribution
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDistributionPoisson TDepthCheckType;

  // Check CDistributionPoisson class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cMean - Mean parameter (default is 1.0).
      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
  */
  CDistributionPoisson(const Treal a_cMean = CONSTR(1.0), NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionPoisson class.
  */
  CDistributionPoisson(const CDistributionPoisson& a_crInstance);
  //! Class virtual destructor.
  virtual ~CDistributionPoisson();

  //! Operator: Assign another CDistributionPoisson class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionPoisson class.
      \return Reference to the current class instance.
  */
  CDistributionPoisson& operator = (const CDistributionPoisson& a_crInstance);

  //! Set another CDistributionPoisson class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionPoisson class.
      \return true  - if another distribution was successfully set. \n
              false - if another distribution was not successfully set. \n
  */
  Tbool set(const CDistributionPoisson& a_crInstance);

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

  //! Serialize CDistributionPoisson class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDistributionPoisson class instances.
  /*!
      \param a_rInstance - Reference to another CDistributionPoisson class instance.
  */
  void swap(CDistributionPoisson& a_rInstance);

protected:
  Treal m_Scale;                        //!< Distribution state.
  Treal m_ScalePI;                      //!< Distribution state.
  Treal m_M;                            //!< Distribution state.
  Treal m_Sq;                           //!< Distribution state.
  Treal m_Alm;                          //!< Distribution state.
  Treal m_G;                            //!< Distribution state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/statistic/CDistributionPoisson.inl>
/*==========================================================================*/
//! \example example-statistic-CDistributionPoisson.cpp
/*--------------------------------------------------------------------------*/
//! \test test-statistic-CDistributionPoisson.cpp
/*==========================================================================*/
#endif
