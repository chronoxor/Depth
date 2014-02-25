/*!
 *  \file    CResizePolicyAdditive.inl Additive resize policy class. It uses
 *           additive resize factor allocation strategy.
 *  \brief   Additive resize policy class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Additive resize policy class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers policy
    VERSION:   1.0
    CREATED:   15.03.2006 23:36:31

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
#ifndef __CRESIZEPOLICYADDITIVE_INL__
#define __CRESIZEPOLICYADDITIVE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NPolicy {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CResizePolicyAdditive::CResizePolicyAdditive(const Tuint a_cResizeFactor/* = CResizePolicyAdditive::getDefaultResizeFactor() */) :
  IResizePolicy()
{ CALL
  setResizeFactor(a_cResizeFactor);
}
/*--------------------------------------------------------------------------*/
inline CResizePolicyAdditive::CResizePolicyAdditive(const CResizePolicyAdditive& a_crInstance) :
  IResizePolicy()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CResizePolicyAdditive::~CResizePolicyAdditive()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CResizePolicyAdditive& CResizePolicyAdditive::operator = (const CResizePolicyAdditive& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CResizePolicyAdditive::set(const CResizePolicyAdditive& a_crInstance)
{ CALL
  IResizePolicy::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline Tuint CResizePolicyAdditive::getDefaultResizeFactor()
{ CALL
  return 1;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CResizePolicyAdditive::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NPolicy::CResizePolicyAdditive")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IResizePolicy&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CResizePolicyAdditive::swap(CResizePolicyAdditive& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IResizePolicy&)(*this), (IResizePolicy&)(a_rInstance));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
