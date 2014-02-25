/*!
 *  \file    EJoiningType.inl Character joining type enumeration.
 *  \brief   Character joining type enumeration (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character joining type enumeration (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   01.04.2009 22:56:22

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
#ifndef __EJOININGTYPE_INL__
#define __EJOININGTYPE_INL__
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EJoiningType& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EJoiningType")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set EJoiningType value.
  switch (value)
  {
    case 0:
      a_rInstance = NString::NUCD::e_JoiningType_None;
      break;
    case 1:
      a_rInstance = NString::NUCD::e_JoiningType_Left;
      break;
    case 2:
      a_rInstance = NString::NUCD::e_JoiningType_Right;
      break;
    case 3:
      a_rInstance = NString::NUCD::e_JoiningType_Dual;
      break;
    case 4:
      a_rInstance = NString::NUCD::e_JoiningType_Causing;
      break;
    case 5:
      a_rInstance = NString::NUCD::e_JoiningType_Transparent;
      break;
    default:
      WARNING(STR("Cannot load invalid EJoiningType value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EJoiningType& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get EJoiningType value.
  switch (a_crInstance)
  {
    case NString::NUCD::e_JoiningType_None:
      value = 0;
      break;
    case NString::NUCD::e_JoiningType_Left:
      value = 1;
      break;
    case NString::NUCD::e_JoiningType_Right:
      value = 2;
      break;
    case NString::NUCD::e_JoiningType_Dual:
      value = 3;
      break;
    case NString::NUCD::e_JoiningType_Causing:
      value = 4;
      break;
    case NString::NUCD::e_JoiningType_Transparent:
      value = 5;
      break;
    default:
      WARNING(STR("Cannot save invalid EJoiningType value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EJoiningType")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EJoiningType& a_rInstance)
{ CALL
  // Split 'serialize()' free function into 'load()' and 'save()' ones.
  return serializeSplitFunction(a_rArchive, a_rInstance);
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
