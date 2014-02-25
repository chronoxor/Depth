/*!
 *  \file    CDistributionCircle.hpp Circle distribution class.
 *  \brief   Circle distribution class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    09.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Circle distribution class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   09.03.2009 03:18:28

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
#ifndef __CDISTRIBUTIONCIRCLE_HPP__
#define __CDISTRIBUTIONCIRCLE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/geometry/CPoint2D.hpp>
#include <Depth/include/geometry/CVector2D.hpp>
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
//! Circle distribution class.
/*!
    Notes:
    - Vector of two random numbers (x, y) which are  distributed  uniformly on
      the unit circle.
    - On  average  requires  2.25  deviates  per  vector  and  a  square  root
      calculation.

    References:
    - Uses the algorithm of Marsaglia, Ann. Math. Stat 43, 645 (1972).
*/
class STATISTIC_API CDistributionCircle :
  public IDistribution
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDistributionCircle TDepthCheckType;

  // Check CDistributionCircle class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_crOrigin - Constant reference to the circle origin point (default is NGeometry::CPoint2D<Treal>(0.0, 0.0)).
      \param a_crScale - Constant reference to the circle scale vector (default is NGeometry::CVector2D(1.0, 1.0)).
      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
  */
  CDistributionCircle(const NGeometry::CPoint2D<Treal>& a_crOrigin = NGeometry::CPoint2D<Treal>(0.0, 0.0), const NGeometry::CVector2D a_crScale = NGeometry::CVector2D(1.0, 1.0), NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionCircle class.
  */
  CDistributionCircle(const CDistributionCircle& a_crInstance);
  //! Class virtual destructor.
  virtual ~CDistributionCircle();

  //! Operator: Assign another CDistributionCircle class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionCircle class.
      \return Reference to the current class instance.
  */
  CDistributionCircle& operator = (const CDistributionCircle& a_crInstance);

  //! Set another CDistributionCircle class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionCircle class.
      \return true  - if another distribution was successfully set. \n
              false - if another distribution was not successfully set. \n
  */
  Tbool set(const CDistributionCircle& a_crInstance);

  //! Set distribution parameters.
  /*!
      \param a_crOrigin - Constant reference to the circle origin point.
      \param a_crScale - Constant reference to the circle scale vector.
      \return true  - if distribution parameters were successfully set. \n
              false - if distribution parameters were not successfully set. \n
  */
  Tbool setParameters(const NGeometry::CPoint2D<Treal>& a_crOrigin, const NGeometry::CVector2D a_crScale);
  //! Get distribution circle origin point.
  /*!
      \return Constant reference to the circle origin point parameter.
  */
  const NGeometry::CPoint2D<Treal>& getOrigin() const;
  //! Get distribution circle scale vector.
  /*!
      \return Constant reference to the circle scale vector parameter.
  */
  const NGeometry::CVector2D& getScale() const;

  //! Get new generated random point on the circle.
  /*!
      The method generates new random point which is distributed on the circle
      with fixed origin and scale.

      \return Distributed random point on the circle.
  */
  NGeometry::CPoint2D<Treal> randomPoint();

  //! Serialize CDistributionCircle class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDistributionCircle class instances.
  /*!
      \param a_rInstance - Reference to another CDistributionCircle class instance.
  */
  void swap(CDistributionCircle& a_rInstance);

protected:
  NGeometry::CPoint2D<Treal> m_Origin;  //!< Distribution state.
  NGeometry::CVector2D m_Scale;         //!< Distribution state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/statistic/CDistributionCircle.inl>
/*==========================================================================*/
//! \example example-statistic-CDistributionCircle.cpp
/*--------------------------------------------------------------------------*/
//! \test test-statistic-CDistributionCircle.cpp
/*==========================================================================*/
#endif
