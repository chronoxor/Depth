/*!
 *  \file    CViewPort.inl Representation of the projection view port.
 *  \brief   View port class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: View port class (inline).

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
#ifndef __CVIEWPORT_INL__
#define __CVIEWPORT_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CViewPort::CViewPort(const Treal a_cScreenX/* = 0.0 */, const Treal a_cScreenY/* = 0.0 */, const Treal a_cScreenWidth/* = 1.0 */, const Treal a_cScreenHeight/* = 1.0 */) :
  m_ScreenX(),
  m_ScreenY(),
  m_ScreenWidth(),
  m_ScreenHeight()
{ CALL
  set(a_cScreenX, a_cScreenY, a_cScreenWidth, a_cScreenHeight);
}
/*--------------------------------------------------------------------------*/
inline CViewPort::CViewPort(const CRect<Treal>& a_crScreenRect) :
  m_ScreenX(),
  m_ScreenY(),
  m_ScreenWidth(),
  m_ScreenHeight()
{ CALL
  set(a_crScreenRect);
}
/*--------------------------------------------------------------------------*/
inline CViewPort::CViewPort(const CViewPort& a_crInstance) :
  m_ScreenX(),
  m_ScreenY(),
  m_ScreenWidth(),
  m_ScreenHeight()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CViewPort::~CViewPort()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CViewPort& CViewPort::operator = (const CRect<Treal>& a_crScreenRect)
{ CALL
  set(a_crScreenRect);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CViewPort& CViewPort::operator = (const CViewPort& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CViewPort::set(const CViewPort& a_crInstance)
{ CALL
  m_ScreenX = a_crInstance.m_ScreenX;
  m_ScreenY = a_crInstance.m_ScreenY;
  m_ScreenWidth = a_crInstance.m_ScreenWidth;
  m_ScreenHeight = a_crInstance.m_ScreenHeight;
}
/*--------------------------------------------------------------------------*/
inline Treal CViewPort::getScreenX() const
{ CALL
  return m_ScreenX;
}
/*--------------------------------------------------------------------------*/
inline Treal CViewPort::getScreenY() const
{ CALL
  return m_ScreenY;
}
/*--------------------------------------------------------------------------*/
inline Treal CViewPort::getScreenWidth() const
{ CALL
  return m_ScreenWidth;
}
/*--------------------------------------------------------------------------*/
inline Treal CViewPort::getScreenHeight() const
{ CALL
  return m_ScreenHeight;
}
/*--------------------------------------------------------------------------*/
inline CRect<Treal> CViewPort::getScreenRect() const
{ CALL
  return CRect<Treal>(m_ScreenX, m_ScreenY, m_ScreenX + m_ScreenWidth, m_ScreenY + m_ScreenHeight);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CViewPort::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NGeometry::CViewPort")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_ScreenX, STR("m_ScreenX")));
    CHECK(a_rArchive.doValue(m_ScreenY, STR("m_ScreenY")));
    CHECK(a_rArchive.doValue(m_ScreenWidth, STR("m_ScreenWidth")));
    CHECK(a_rArchive.doValue(m_ScreenHeight, STR("m_ScreenHeight")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CViewPort::swap(CViewPort& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_ScreenX, a_rInstance.m_ScreenX);
  NAlgorithms::NCommon::swap(m_ScreenY, a_rInstance.m_ScreenY);
  NAlgorithms::NCommon::swap(m_ScreenWidth, a_rInstance.m_ScreenWidth);
  NAlgorithms::NCommon::swap(m_ScreenHeight, a_rInstance.m_ScreenHeight);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
