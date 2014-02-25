/*!
 *  \file    CRectMaker.hpp Utility class that helps to create CRect
 *           instances from specific values.
 *  \brief   Rectangle maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Rectangle maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   03.03.2006 02:17:37

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
#ifndef __CRECTMAKER_HPP__
#define __CRECTMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/geometry/CRect.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Rectangle maker class.
/*!
    With this utility class template CRect instances can  be  created  without
    specifying template arguments.
*/
class GEOMETRY_API CRectMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CRect instance from specified rectangle points' coordinates.
  /*!
      \param a_cX1 - X coordinate of the left-bottom point.
      \param a_cY1 - Y coordinate of the left-bottom point.
      \param a_cX2 - X coordinate of the right-top point.
      \param a_cY2 - Y coordinate of the right-top point.
      \return CRect class instance.
  */
  template <typename T_Type>
  static CRect<T_Type> make(const T_Type a_cX1, const T_Type a_cY1, const T_Type a_cX2, const T_Type a_cY2);

  //! Make CRect instance from specified rectangle's points.
  /*!
      \param a_crA - Rectangle's left-bottom-deep point.
      \param a_crB - Rectangle's right-top-high point.
      \return CRect class instance.
  */
  template <typename T_Type>
  static CRect<T_Type> make(const CPoint2D<T_Type>& a_crA, const CPoint2D<T_Type>& a_crB);

  //! Make CRect instance from specified rectangle points' coordinates through the array.
  /*!
      \param a_cpCoordinatesBuffer - Constant pointer to the coordinates array.
      \return CRect class instance.
  */
  template <typename T_Type>
  static CRect<T_Type> make(const T_Type a_cpCoordinatesBuffer[]);

  //! Make CRect instance from specified CRect class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRect class.
      \return CRect class instance.
  */
  template <typename T_Type>
  static CRect<T_Type> make(const CRect<T_Type>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CRectMaker.inl>
/*==========================================================================*/
#endif
