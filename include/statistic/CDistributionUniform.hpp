/*!
 *  \file    CDistributionUniform.hpp Uniform distribution class.
 *  \brief   Uniform distribution class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Uniform distribution class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:20:37

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
#ifndef __CDISTRIBUTIONUNIFORM_HPP__
#define __CDISTRIBUTIONUNIFORM_HPP__
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
//! Uniform distribution class.
/*!
    Return uniformly distributed random deviates according to:
      p(x) dx = dx   for x in [A, B]
              =  0   otherwise
*/
class STATISTIC_API CDistributionUniform :
  public IDistribution
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDistributionUniform TDepthCheckType;

  // Check CDistributionUniform class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cA - A interval parameter (default is 0.0).
      \param a_cB - B interval parameter (default is 1.0).
      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
  */
  CDistributionUniform(const Treal a_cA = CONSTR(0.0), const Treal a_cB = CONSTR(1.0), NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionUniform class.
  */
  CDistributionUniform(const CDistributionUniform& a_crInstance);
  //! Class virtual destructor.
  virtual ~CDistributionUniform();

  //! Operator: Assign another CDistributionUniform class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionUniform class.
      \return Reference to the current class instance.
  */
  CDistributionUniform& operator = (const CDistributionUniform& a_crInstance);

  //! Set another CDistributionUniform class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionUniform class.
      \return true  - if another distribution was successfully set. \n
              false - if another distribution was not successfully set. \n
  */
  Tbool set(const CDistributionUniform& a_crInstance);

  //! Set distribution parameters.
  /*!
      \param a_cA - A interval parameter.
      \param a_cB - B interval parameter.
      \return true  - if distribution parameters were successfully set. \n
              false - if distribution parameters were not successfully set. \n
  */
  Tbool setParameters(const Treal a_cA, const Treal a_cB);
  //! Get distribution A interval parameter.
  /*!
      \return A interval parameter.
  */
  Treal getA() const;
  //! Get distribution B interval parameter.
  /*!
      \return B interval parameter.
  */
  Treal getB() const;

  // IDistribution interface overriding methods.
  virtual Treal randomReal();

  //! Serialize CDistributionUniform class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDistributionUniform class instances.
  /*!
      \param a_rInstance - Reference to another CDistributionUniform class instance.
  */
  void swap(CDistributionUniform& a_rInstance);

protected:
  Treal m_A;                            //!< Distribution state.
  Treal m_B;                            //!< Distribution state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/statistic/CDistributionUniform.inl>
/*==========================================================================*/
//! \example example-statistic-CDistributionUniform.cpp
/*--------------------------------------------------------------------------*/
//! \test test-statistic-CDistributionUniform.cpp
/*==========================================================================*/
#endif
