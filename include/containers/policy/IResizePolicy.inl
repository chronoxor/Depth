/*!
 *  \file    IResizePolicy.inl Resize policy interface. Resize policy is an
 *           allocation strategy which is used with arrays for determine when
 *           memory reallocation is need.
 *  \brief   Resize policy interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Resize policy interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers policy
    VERSION:   1.0
    CREATED:   15.03.2006 22:08:24

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
#ifndef __IRESIZEPOLICY_INL__
#define __IRESIZEPOLICY_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NPolicy {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline IResizePolicy::IResizePolicy() :
  m_ResizeFactor(0),
  m_LoCapacity(0),
  m_HiCapacity(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IResizePolicy::IResizePolicy(const IResizePolicy& a_crInstance) :
  m_ResizeFactor(0),
  m_LoCapacity(0),
  m_HiCapacity(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline IResizePolicy::~IResizePolicy()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IResizePolicy& IResizePolicy::operator = (const IResizePolicy& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void IResizePolicy::set(const IResizePolicy& a_crInstance)
{ CALL
  m_ResizeFactor = a_crInstance.m_ResizeFactor;
  m_LoCapacity = a_crInstance.m_LoCapacity;
  m_HiCapacity = a_crInstance.m_HiCapacity;
}
/*--------------------------------------------------------------------------*/
inline Tuint IResizePolicy::getResizeFactor() const
{ CALL
  return m_ResizeFactor;
}
/*--------------------------------------------------------------------------*/
inline Tuint IResizePolicy::getLoCapacity() const
{ CALL
  return m_LoCapacity;
}
/*--------------------------------------------------------------------------*/
inline Tuint IResizePolicy::getHiCapacity() const
{ CALL
  return m_HiCapacity;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IResizePolicy::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NPolicy::IResizePolicy")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_ResizeFactor, STR("m_ResizeFactor")));
    CHECK(a_rArchive.doValue(m_LoCapacity, STR("m_LoCapacity")));
    CHECK(a_rArchive.doValue(m_HiCapacity, STR("m_HiCapacity")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void IResizePolicy::swap(IResizePolicy& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_ResizeFactor, a_rInstance.m_ResizeFactor);
  NAlgorithms::NCommon::swap(m_LoCapacity, a_rInstance.m_LoCapacity);
  NAlgorithms::NCommon::swap(m_HiCapacity, a_rInstance.m_HiCapacity);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
