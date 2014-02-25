/*!
 *  \file    CPoint2DMaker.hpp Utility class that helps to create CPoint2D
 *           instances from specific values.
 *  \brief   Point on a plane maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Point on a plane maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   03.03.2006 02:23:15

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
#ifndef __CPOINT2DMAKER_HPP__
#define __CPOINT2DMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/geometry/CPoint2D.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Point on a plane maker class.
/*!
    With this utility class template CPoint2D instances can be created without
    specifying template arguments.
*/
class GEOMETRY_API CPoint2DMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CPoint2D instance from specified points' coordinates.
  /*!
      \param a_cX - X coordinate of the point.
      \param a_cY - Y coordinate of the point.
      \return CPoint2D class instance.
  */
  template <typename T_Type>
  static CPoint2D<T_Type> make(const T_Type a_cX, const T_Type a_cY);

  //! Make CPoint2D instance from specified points' coordinates through the array.
  /*!
      \param a_cpCoordinatesBuffer - Constant pointer to the coordinates array.
      \return CPoint2D class instance.
  */
  template <typename T_Type>
  static CPoint2D<T_Type> make(const T_Type a_cpCoordinatesBuffer[]);

  //! Make CPoint2D instance from specified CPoint2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint2D class.
      \return CPoint2D class instance.
  */
  template <typename T_Type>
  static CPoint2D<T_Type> make(const CPoint2D<T_Type>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CPoint2DMaker.inl>
/*==========================================================================*/
#endif
