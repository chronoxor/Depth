/*!
 *  \file    EUnicodeVersion.inl Character version enumeration.
 *  \brief   Character version enumeration (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character version enumeration (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   01.04.2009 22:34:42

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
#ifndef __EUNICODEVERSION_INL__
#define __EUNICODEVERSION_INL__
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EUnicodeVersion& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EUnicodeVersion")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set EUnicodeVersion value.
  switch (value)
  {
    case 0:
      a_rInstance = NString::NUCD::e_UnicodeVersion_Unassigned;
      break;
    case 11:
      a_rInstance = NString::NUCD::e_UnicodeVersion_1_1;
      break;
    case 20:
      a_rInstance = NString::NUCD::e_UnicodeVersion_2_0;
      break;
    case 21:
      a_rInstance = NString::NUCD::e_UnicodeVersion_2_1;
      break;
    case 30:
      a_rInstance = NString::NUCD::e_UnicodeVersion_3_0;
      break;
    case 31:
      a_rInstance = NString::NUCD::e_UnicodeVersion_3_1;
      break;
    case 32:
      a_rInstance = NString::NUCD::e_UnicodeVersion_3_2;
      break;
    case 40:
      a_rInstance = NString::NUCD::e_UnicodeVersion_4_0;
      break;
    case 41:
      a_rInstance = NString::NUCD::e_UnicodeVersion_4_1;
      break;
    case 50:
      a_rInstance = NString::NUCD::e_UnicodeVersion_5_0;
      break;
    case 51:
      a_rInstance = NString::NUCD::e_UnicodeVersion_5_1;
      break;
    case 52:
      a_rInstance = NString::NUCD::e_UnicodeVersion_5_2;
      break;
    default:
      WARNING(STR("Cannot load invalid EUnicodeVersion value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EUnicodeVersion& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get EUnicodeVersion value.
  switch (a_crInstance)
  {
    case NString::NUCD::e_UnicodeVersion_Unassigned:
      value = 0;
      break;
    case NString::NUCD::e_UnicodeVersion_1_1:
      value = 11;
      break;
    case NString::NUCD::e_UnicodeVersion_2_0:
      value = 20;
      break;
    case NString::NUCD::e_UnicodeVersion_2_1:
      value = 21;
      break;
    case NString::NUCD::e_UnicodeVersion_3_0:
      value = 30;
      break;
    case NString::NUCD::e_UnicodeVersion_3_1:
      value = 31;
      break;
    case NString::NUCD::e_UnicodeVersion_3_2:
      value = 32;
      break;
    case NString::NUCD::e_UnicodeVersion_4_0:
      value = 40;
      break;
    case NString::NUCD::e_UnicodeVersion_4_1:
      value = 41;
      break;
    case NString::NUCD::e_UnicodeVersion_5_0:
      value = 50;
      break;
    case NString::NUCD::e_UnicodeVersion_5_1:
      value = 51;
      break;
    case NString::NUCD::e_UnicodeVersion_5_2:
      value = 52;
      break;
    default:
      WARNING(STR("Cannot save invalid EUnicodeVersion value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EUnicodeVersion")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EUnicodeVersion& a_rInstance)
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
