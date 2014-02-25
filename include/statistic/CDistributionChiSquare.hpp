/*!
 *  \file    CDistributionChiSquare.hpp Chi-square distribution class.
 *  \brief   Chi-square distribution class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Chi-square distribution class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:01:12

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
#ifndef __CDISTRIBUTIONCHISQUARE_HPP__
#define __CDISTRIBUTIONCHISQUARE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/statistic/IDistribution.hpp>
#include <Depth/include/statistic/CDistributionGamma.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Chi-square distribution class.
/*!
    Generates random deviates from a central chi-square distribution with  'f'
    degrees of freedom. f must be positive. The density of  this  distribution
    is:

                    -f/2   f/2-1  -x/2
                   2      x      e
      p (x) dx =  --------------------- dx  for x > 0
       f               Gamma(f/2)

               =  0                         otherwise

    The  calculation  uses  the  relation   between   chi-square   and   gamma
    distribution:

      ChiSquare(f) = GammaDistribution(f/2,1/2)

    References:
    - K. Behnen, G. Neuhaus, "Grundkurs Stochastik", Teubner Studienbuecher
      Mathematik, Teubner Verlag, Stuttgart, 1984.
*/
class STATISTIC_API CDistributionChiSquare :
  public CDistributionGamma
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDistributionChiSquare TDepthCheckType;

  // Check CDistributionChiSquare class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cFreedom - Degrees of freedom parameter (must be greater than 0.0) (default is 1.0).
      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
  */
  CDistributionChiSquare(const Treal a_cFreedom = CONSTR(1.0), NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionChiSquare class.
  */
  CDistributionChiSquare(const CDistributionChiSquare& a_crInstance);
  //! Class virtual destructor.
  virtual ~CDistributionChiSquare();

  //! Operator: Assign another CDistributionChiSquare class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionChiSquare class.
      \return Reference to the current class instance.
  */
  CDistributionChiSquare& operator = (const CDistributionChiSquare& a_crInstance);

  //! Set another CDistributionChiSquare class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionChiSquare class.
      \return true  - if another distribution was successfully set. \n
              false - if another distribution was not successfully set. \n
  */
  Tbool set(const CDistributionChiSquare& a_crInstance);

  //! Set distribution parameters.
  /*!
      \param a_cFreedom - Degrees of freedom parameter (must be greater than 0.0).
      \return true  - if distribution parameters were successfully set. \n
              false - if distribution parameters were not successfully set. \n
  */
  Tbool setParameters(const Treal a_cFreedom);
  //! Get distribution degrees of freedom parameter.
  /*!
      \return Degrees of freedom parameter.
  */
  Treal getFreedom() const;

  // IDistribution interface overriding methods.
  virtual Treal randomReal();

  //! Serialize CDistributionChiSquare class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDistributionChiSquare class instances.
  /*!
      \param a_rInstance - Reference to another CDistributionChiSquare class instance.
  */
  void swap(CDistributionChiSquare& a_rInstance);

protected:
  Treal m_F;                            //!< Distribution state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/statistic/CDistributionChiSquare.inl>
/*==========================================================================*/
//! \example example-statistic-CDistributionChiSquare.cpp
/*--------------------------------------------------------------------------*/
//! \test test-statistic-CDistributionChiSquare.cpp
/*==========================================================================*/
#endif
