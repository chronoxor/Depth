/*!
 *  \file    CBoxMaker.hpp Utility class that helps to create CBox
 *           instances from specific values.
 *  \brief   Box maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Box maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   03.03.2006 02:09:25

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
#ifndef __CBOXMAKER_HPP__
#define __CBOXMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/geometry/CBox.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Box maker class.
/*!
    With this utility class template CBox instances  can  be  created  without
    specifying template arguments.
*/
class GEOMETRY_API CBoxMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CBox instance from specified box points' coordinates.
  /*!
      \param a_cX1 - X coordinate of the left-bottom-deep point.
      \param a_cY1 - Y coordinate of the left-bottom-deep point.
      \param a_cZ1 - Z coordinate of the left-bottom-deep point.
      \param a_cX2 - X coordinate of the right-top-high point.
      \param a_cY2 - Y coordinate of the right-top-high point.
      \param a_cZ2 - Z coordinate of the right-top-high point.
      \return CBox class instance.
  */
  template <typename T_Type>
  static CBox<T_Type> make(const T_Type a_cX1, const T_Type a_cY1, const T_Type a_cZ1, const T_Type a_cX2, const T_Type a_cY2, const T_Type a_cZ2);

  //! Make CBox instance from specified box's points.
  /*!
      \param a_crA - Box's left-bottom-deep point.
      \param a_crB - Box's right-top-high point.
      \return CBox class instance.
  */
  template <typename T_Type>
  static CBox<T_Type> make(const CPoint3D<T_Type>& a_crA, const CPoint3D<T_Type>& a_crB);

  //! Make CBox instance from specified boxs points' coordinates through the array.
  /*!
      \param a_cpCoordinatesBuffer - Constant pointer to the coordinates array.
      \return CBox class instance.
  */
  template <typename T_Type>
  static CBox<T_Type> make(const T_Type a_cpCoordinatesBuffer[]);

  //! Make CBox instance from specified CBox class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBox class.
      \return CBox class instance.
  */
  template <typename T_Type>
  static CBox<T_Type> make(const CBox<T_Type>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CBoxMaker.inl>
/*==========================================================================*/
#endif
