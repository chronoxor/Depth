/*!
 *  \file    CViewPort.hpp Representation of the projection view port.
 *  \brief   View port class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: View port class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   23.07.2008 01:44:17

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
#ifndef __CVIEWPORT_HPP__
#define __CVIEWPORT_HPP__
/*==========================================================================*/
#include <Depth/include/geometry.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/geometry/CRect.hpp>
#include <Depth/include/geometry/CPoint3D.hpp>
#include <Depth/include/geometry/CVector3D.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! View port class.
/*!
    View port class is used to project normalized camera coordinates into  the
    screen plane with given position and dimensions. View port is also provide
    functionality to perform  invert  transformation  from  the  screen  plane
    coordinates into the normalized camera ones.

    Note that after view port transformation Z coordinate  becomes  normalized
    in [0, 1] range.
*/
class GEOMETRY_API CViewPort
{
  //! Type for MConceptDepthType constraint checking.
  typedef CViewPort TDepthCheckType;

  // Check CViewPort class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize view port with screen plane position and dimensions.
  /*!
      \param a_cScreenX - Screen X position (default is 0.0).
      \param a_cScreenY - Screen Y position (default is 0.0).
      \param a_cScreenWidth - Screen width (default is 1.0).
      \param a_cScreenHeight - Screen height (default is 1.0).
  */
  CViewPort(const Treal a_cScreenX = 0.0, const Treal a_cScreenY = 0.0, const Treal a_cScreenWidth = 1.0, const Treal a_cScreenHeight = 1.0);
  //! Initialize view port with screen plane rectangle.
  /*!
      \param a_crScreenRect - Constant reference to the screen plane rectangle.
  */
  CViewPort(const CRect<Treal>& a_crScreenRect);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CViewPort class.
  */
  CViewPort(const CViewPort& a_crInstance);
  //! Class destructor.
 ~CViewPort();

  //! Operator: Assign screen plane rectangle.
  /*!
      \param a_crScreenRect - Constant reference to the screen plane rectangle.
      \return Reference to the current class instance.
  */
  CViewPort& operator = (const CRect<Treal>& a_crScreenRect);
  //! Operator: Assign another CViewPort class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CViewPort class.
      \return Reference to the current class instance.
  */
  CViewPort& operator = (const CViewPort& a_crInstance);

  //! Set screen plane position and dimensions.
  /*!
      \param a_cScreenX - Screen X position.
      \param a_cScreenY - Screen Y position.
      \param a_cScreenWidth - Screen width.
      \param a_cScreenHeight - Screen height.
  */
  void set(const Treal a_cScreenX, const Treal a_cScreenY, const Treal a_cScreenWidth, const Treal a_cScreenHeight);
  //! Set screen plane rectangle.
  /*!
      \param a_crScreenRect - Constant reference to the screen plane rectangle.
  */
  void set(const CRect<Treal>& a_crScreenRect);
  //! Set another CViewPort class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CViewPort class.
  */
  void set(const CViewPort& a_crInstance);

  //! Get view port screen X position.
  /*!
      \return View port screen X position.
  */
  Treal getScreenX() const;
  //! Get view port screen Y position.
  /*!
      \return View port screen Y position.
  */
  Treal getScreenY() const;
  //! Get view port screen width.
  /*!
      \return View port screen width.
  */
  Treal getScreenWidth() const;
  //! Get view port screen height.
  /*!
      \return View port screen height.
  */
  Treal getScreenHeight() const;

  //! Get view port screen rectangle.
  /*!
      \return View port screen rectangle.
  */
  CRect<Treal> getScreenRect() const;

  //! Project point from normalized camera coordinate system into the screen plane coordinate system.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result projected instance of the CPoint3D class.
      \return true  - if projection operation was successful. \n
              false - if projection operation was not successful. \n
  */
  Tbool projectNormalizedToScreen(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Project vector from normalized camera coordinate system into the screen plane coordinate system.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_rResult - Reference to the result projected instance of the CVector3D class.
      \return true  - if projection operation was successful. \n
              false - if projection operation was not successful. \n
  */
  Tbool projectNormalizedToScreen(const CVector3D& a_crVector3D, CVector3D& a_rResult) const;

  //! Unproject point from the screen plane coordinate system into the normalized camera coordinate system.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result projected instance of the CPoint3D class.
      \return true  - if unprojection operation was successful. \n
              false - if unprojection operation was not successful. \n
  */
  Tbool unprojectScreenToNormalized(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Unproject vector from the screen plane coordinate system into the normalized camera coordinate system.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_rResult - Reference to the result projected instance of the CVector3D class.
      \return true  - if unprojection operation was successful. \n
              false - if unprojection operation was not successful. \n
  */
  Tbool unprojectScreenToNormalized(const CVector3D& a_crVector3D, CVector3D& a_rResult) const;

  //! Serialize CCamera class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CViewPort class instances.
  /*!
      \param a_rInstance - Reference to another CViewPort class instance.
  */
  void swap(CViewPort& a_rInstance);

private:
  Treal m_ScreenX;                      //!< Screen X position.
  Treal m_ScreenY;                      //!< Screen Y position.
  Treal m_ScreenWidth;                  //!< Screen width.
  Treal m_ScreenHeight;                 //!< Screen height.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CViewPort.inl>
/*==========================================================================*/
//! \example example-geometry-CViewPort.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CViewPort.cpp
/*==========================================================================*/
#endif
