/*!
 *  \file    CViewPort.cpp Representation of the projection view port.
 *  \brief   View port class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: View port class (source).

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
#include <Depth/include/geometry.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/geometry/CViewPort.hpp>
/*==========================================================================*/
#ifndef __CVIEWPORT_CPP__
#define __CVIEWPORT_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
void CViewPort::set(const Treal a_cScreenX, const Treal a_cScreenY, const Treal a_cScreenWidth, const Treal a_cScreenHeight)
{ CALL
  // Check if view port dimensions are great than 0.
  ASSERT((a_cScreenWidth > 0.0) && (a_cScreenHeight > 0.0), STR("View port dimensions should be great than 0 (ScreenWidth = %r; ScreenHeight = %r).") COMMA a_cScreenWidth COMMA a_cScreenHeight);

  m_ScreenX = a_cScreenX;
  m_ScreenY = a_cScreenY;
  m_ScreenWidth = a_cScreenWidth;
  m_ScreenHeight = a_cScreenHeight;
}
/*--------------------------------------------------------------------------*/
void CViewPort::set(const CRect<Treal>& a_crScreenRect)
{ CALL
  // Check if screen rectangle is valid.
  ASSERT(!a_crScreenRect.isEmpty(), STR("View port screen rectangle should not be empty (ScreenRect = (%r, %r, %r, %r)).") COMMA a_crScreenRect.m_A.m_X COMMA a_crScreenRect.m_A.m_Y COMMA a_crScreenRect.m_B.m_X COMMA a_crScreenRect.m_B.m_Y);

  m_ScreenX = a_crScreenRect.m_A.m_X;
  m_ScreenY = a_crScreenRect.m_A.m_Y;
  m_ScreenWidth = a_crScreenRect.getWidth();
  m_ScreenHeight = a_crScreenRect.getHeight();
}
/*--------------------------------------------------------------------------*/
Tbool CViewPort::projectNormalizedToScreen(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  // Check if the camera normalized point is valid.
  ASSERT((a_crPoint3D.m_X >= -1.0) && (a_crPoint3D.m_X <= 1.0) && (a_crPoint3D.m_Y >= -1.0) && (a_crPoint3D.m_Y <= 1.0) && (a_crPoint3D.m_Z >= -1.0) && (a_crPoint3D.m_Z <= 1.0), STR("Camera normalized point is not valid (point = (%r, %r, %r)).") COMMA a_crPoint3D.m_X COMMA a_crPoint3D.m_Y COMMA a_crPoint3D.m_Z)
  {
    return false;
  }

  a_rResult.m_X = m_ScreenX + CONSTR(0.5) * m_ScreenWidth * (CONSTR(1.0) + a_crPoint3D.m_X);
  a_rResult.m_Y = m_ScreenY + CONSTR(0.5) * m_ScreenHeight * (CONSTR(1.0) + a_crPoint3D.m_Y);
  a_rResult.m_Z = CONSTR(0.5) * (CONSTR(1.0) + a_crPoint3D.m_Z);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CViewPort::projectNormalizedToScreen(const CVector3D& a_crVector3D, CVector3D& a_rResult) const
{ CALL
  // Check if the camera normalized vector is valid.
  ASSERT((a_crVector3D.m_X >= -1.0) && (a_crVector3D.m_X <= 1.0) && (a_crVector3D.m_Y >= -1.0) && (a_crVector3D.m_Y <= 1.0) && (a_crVector3D.m_Z >= -1.0) && (a_crVector3D.m_Z <= 1.0), STR("Camera normalized vector is not valid (point = (%r, %r, %r)).") COMMA a_crVector3D.m_X COMMA a_crVector3D.m_Y COMMA a_crVector3D.m_Z)
  {
    return false;
  }

  a_rResult.m_X = m_ScreenX + CONSTR(0.5) * m_ScreenWidth * (CONSTR(1.0) + a_crVector3D.m_X);
  a_rResult.m_Y = m_ScreenY + CONSTR(0.5) * m_ScreenHeight * (CONSTR(1.0) + a_crVector3D.m_Y);
  a_rResult.m_Z = CONSTR(0.5) * (CONSTR(1.0) + a_crVector3D.m_Z);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CViewPort::unprojectScreenToNormalized(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  // Check if the screen plane point is valid.
  ASSERT((a_crPoint3D.m_X >= m_ScreenX) && (a_crPoint3D.m_X <= (m_ScreenX + m_ScreenWidth)) && (a_crPoint3D.m_Y >= m_ScreenY) && (a_crPoint3D.m_Y <= (m_ScreenY + m_ScreenHeight)) && (a_crPoint3D.m_Z >= 0.0) && (a_crPoint3D.m_Z <= 1.0), STR("Screen plane point is not valid (point = (%r, %r, %r)).") COMMA a_crPoint3D.m_X COMMA a_crPoint3D.m_Y COMMA a_crPoint3D.m_Z)
  {
    return false;
  }

  a_rResult.m_X = ((a_crPoint3D.m_X - m_ScreenX) * CONSTR(2.0) / m_ScreenWidth - CONSTR(1.0));
  a_rResult.m_Y = ((a_crPoint3D.m_Y - m_ScreenY) * CONSTR(2.0) / m_ScreenHeight - CONSTR(1.0));
  a_rResult.m_Z = CONSTR(2.0) * a_crPoint3D.m_Z - CONSTR(1.0);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CViewPort::unprojectScreenToNormalized(const CVector3D& a_crVector3D, CVector3D& a_rResult) const
{ CALL
  // Check if the screen plane vector is valid.
  ASSERT((a_crVector3D.m_X >= m_ScreenX) && (a_crVector3D.m_X <= (m_ScreenX + m_ScreenWidth)) && (a_crVector3D.m_Y >= m_ScreenY) && (a_crVector3D.m_Y <= (m_ScreenY + m_ScreenHeight)) && (a_crVector3D.m_Z >= 0.0) && (a_crVector3D.m_Z <= 1.0), STR("Screen plane vector is not valid (point = (%r, %r, %r)).") COMMA a_crVector3D.m_X COMMA a_crVector3D.m_Y COMMA a_crVector3D.m_Z)
  {
    return false;
  }

  a_rResult.m_X = ((a_crVector3D.m_X - m_ScreenX) * CONSTR(2.0) / m_ScreenWidth - CONSTR(1.0));
  a_rResult.m_Y = ((a_crVector3D.m_Y - m_ScreenY) * CONSTR(2.0) / m_ScreenHeight - CONSTR(1.0));
  a_rResult.m_Z = CONSTR(2.0) * a_crVector3D.m_Z - CONSTR(1.0);
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
