/*!
 *  \file    CDistributionErlang.hpp Erlang distribution class.
 *  \brief   Erlang distribution class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Erlang distribution class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:07:33

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
#ifndef __CDISTRIBUTIONERLANG_HPP__
#define __CDISTRIBUTIONERLANG_HPP__
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
//! Erlang distribution class.
/*!
    Return Erlang distributed random deviates according to:

                          a-1  -bx
                    b (bx)    e
      p   (x) dx = ---------------- dx   for x > 0
       a,b             Gamma(a)

                 =  0                    otherwise

    The Erlang distribution is a special case of the Gamma  distribution  with
    integer valued order a.

    References:
    - W. H. Press, B. P. Flannery, S. A. Teukolsky, W. T. Vetterling,
      Numerical Recipies in C, Cambridge Univ. Press, 1988.
*/
class STATISTIC_API CDistributionErlang :
  public IDistribution
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDistributionErlang TDepthCheckType;

  // Check CDistributionErlang class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cOrder - Order parameter (must be greater or equal to 1) (default is 1).
      \param a_cLocation - Location parameter (must not be equal to 0.0) (default is 2.0).
      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
  */
  CDistributionErlang(const Tuint a_cOrder = 1, const Treal a_cLocation = CONSTR(2.0), NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionErlang class.
  */
  CDistributionErlang(const CDistributionErlang& a_crInstance);
  //! Class virtual destructor.
  virtual ~CDistributionErlang();

  //! Operator: Assign another CDistributionErlang class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionErlang class.
      \return Reference to the current class instance.
  */
  CDistributionErlang& operator = (const CDistributionErlang& a_crInstance);

  //! Set another CDistributionErlang class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionErlang class.
      \return true  - if another distribution was successfully set. \n
              false - if another distribution was not successfully set. \n
  */
  Tbool set(const CDistributionErlang& a_crInstance);

  //! Set distribution parameters.
  /*!
      \param a_cOrder - Order parameter (must be greater or equal to 1).
      \param a_cLocation - Location parameter (must not be equal to 0.0).
      \return true  - if distribution parameters were successfully set. \n
              false - if distribution parameters were not successfully set. \n
  */
  Tbool setParameters(const Tuint a_cOrder, const Treal a_cLocation);
  //! Get distribution order parameter.
  /*!
      \return Order parameter.
  */
  Tuint getOrder() const;
  //! Get distribution location parameter.
  /*!
      \return Location parameter.
  */
  Treal getLocation() const;

  // IDistribution interface overriding methods.
  virtual Treal randomReal();

  //! Serialize CDistributionErlang class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDistributionErlang class instances.
  /*!
      \param a_rInstance - Reference to another CDistributionErlang class instance.
  */
  void swap(CDistributionErlang& a_rInstance);

protected:
  Tuint m_A;                            //!< Distribution state.
  Treal m_B;                            //!< Distribution state.
  Treal m_a1;                           //!< Distribution state.
  Treal m_sq;                           //!< Distribution state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/statistic/CDistributionErlang.inl>
/*==========================================================================*/
//! \example example-statistic-CDistributionErlang.cpp
/*--------------------------------------------------------------------------*/
//! \test test-statistic-CDistributionErlang.cpp
/*==========================================================================*/
#endif
