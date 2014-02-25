/*!
 *  \file    CDistributionSphere.hpp Sphere distribution class.
 *  \brief   Sphere distribution class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    09.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Sphere distribution class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   09.03.2009 03:59:07

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
#ifndef __CDISTRIBUTIONSPHERE_HPP__
#define __CDISTRIBUTIONSPHERE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/geometry/CPoint3D.hpp>
#include <Depth/include/geometry/CVector3D.hpp>
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
//! Sphere distribution class.
/*!
    Notes:
    - Vector of two random numbers (x, y, z) which are  distributed  uniformly
      on the unit Sphere.
    - On  average  requires  2.25  deviates  per  vector  and  a  square  root
      calculation.

    References:
    - Uses the algorithm of Marsaglia, Ann. Math. Stat 43, 645 (1972).
*/
class STATISTIC_API CDistributionSphere :
  public IDistribution
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDistributionSphere TDepthCheckType;

  // Check CDistributionSphere class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_crOrigin - Constant reference to the sphere origin point (default is NGeometry::CPoint3D<Treal>(0.0, 0.0, 0.0)).
      \param a_crScale - Constant reference to the sphere scale vector (default is NGeometry::CVector3D(1.0, 1.0, 1.0)).
      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
  */
  CDistributionSphere(const NGeometry::CPoint3D<Treal>& a_crOrigin = NGeometry::CPoint3D<Treal>(0.0, 0.0, 0.0), const NGeometry::CVector3D a_crScale = NGeometry::CVector3D(1.0, 1.0, 1.0), NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionSphere class.
  */
  CDistributionSphere(const CDistributionSphere& a_crInstance);
  //! Class virtual destructor.
  virtual ~CDistributionSphere();

  //! Operator: Assign another CDistributionSphere class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionSphere class.
      \return Reference to the current class instance.
  */
  CDistributionSphere& operator = (const CDistributionSphere& a_crInstance);

  //! Set another CDistributionSphere class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionSphere class.
      \return true  - if another distribution was successfully set. \n
              false - if another distribution was not successfully set. \n
  */
  Tbool set(const CDistributionSphere& a_crInstance);

  //! Set distribution parameters.
  /*!
      \param a_crOrigin - Constant reference to the sphere origin point.
      \param a_crScale - Constant reference to the sphere scale vector.
      \return true  - if distribution parameters were successfully set. \n
              false - if distribution parameters were not successfully set. \n
  */
  Tbool setParameters(const NGeometry::CPoint3D<Treal>& a_crOrigin, const NGeometry::CVector3D a_crScale);
  //! Get distribution sphere origin point.
  /*!
      \return Constant reference to the sphere origin point parameter.
  */
  const NGeometry::CPoint3D<Treal>& getOrigin() const;
  //! Get distribution sphere scale vector.
  /*!
      \return Constant reference to the sphere scale vector parameter.
  */
  const NGeometry::CVector3D& getScale() const;

  //! Get new generated random point on the sphere.
  /*!
      The method generates new random point which is distributed on the sphere
      with fixed origin and scale.

      \return Distributed random point on the sphere.
  */
  NGeometry::CPoint3D<Treal> randomPoint();

  //! Serialize CDistributionSphere class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDistributionSphere class instances.
  /*!
      \param a_rInstance - Reference to another CDistributionSphere class instance.
  */
  void swap(CDistributionSphere& a_rInstance);

protected:
  NGeometry::CPoint3D<Treal> m_Origin;  //!< Distribution state.
  NGeometry::CVector3D m_Scale;         //!< Distribution state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/statistic/CDistributionSphere.inl>
/*==========================================================================*/
//! \example example-statistic-CDistributionSphere.cpp
/*--------------------------------------------------------------------------*/
//! \test test-statistic-CDistributionSphere.cpp
/*==========================================================================*/
#endif
