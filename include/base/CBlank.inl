/*!
 *  \file    CBlank.inl Blank class which swallows any argument during the
 *           creation and assigning.
 *  \brief   Empty class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Blank class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   07.03.2006 21:45:31

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
#ifndef __CBLANK_INL__
#define __CBLANK_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CBlank::CBlank()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBlank::CBlank(const T_Type& a_crValue)
{ CALL
  IGNORE_UNUSED(a_crValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CBlank& a_crInstance1, const CBlank& a_crInstance2)
{ CALL
  IGNORE_UNUSED(a_crInstance1);
  IGNORE_UNUSED(a_crInstance2);

  return true;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CBlank& a_crInstance1, const CBlank& a_crInstance2)
{ CALL
  IGNORE_UNUSED(a_crInstance1);
  IGNORE_UNUSED(a_crInstance2);

  return false;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CBlank& a_crInstance1, const CBlank& a_crInstance2)
{ CALL
  IGNORE_UNUSED(a_crInstance1);
  IGNORE_UNUSED(a_crInstance2);

  return false;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CBlank& a_crInstance1, const CBlank& a_crInstance2)
{ CALL
  IGNORE_UNUSED(a_crInstance1);
  IGNORE_UNUSED(a_crInstance2);

  return false;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CBlank& a_crInstance1, const CBlank& a_crInstance2)
{ CALL
  IGNORE_UNUSED(a_crInstance1);
  IGNORE_UNUSED(a_crInstance2);

  return true;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CBlank& a_crInstance1, const CBlank& a_crInstance2)
{ CALL
  IGNORE_UNUSED(a_crInstance1);
  IGNORE_UNUSED(a_crInstance2);

  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBlank& CBlank::operator = (const T_Type& a_crValue)
{ CALL
  IGNORE_UNUSED(a_crValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CBlank::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NBase::CBlank")));
  CHECK(a_rArchive.body());
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CBlank::swap(CBlank& a_rInstance)
{ CALL
  IGNORE_UNUSED(a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
