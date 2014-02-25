/*!
 *  \file    EBidiClass.inl Character Bidirectional Behavior class
 *           enumeration.
 *  \brief   Character Bidirectional Behavior class enumeration (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character Bidirectional Behavior class enumeration (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 22:27:57

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
#ifndef __EBIDICLASS_INL__
#define __EBIDICLASS_INL__
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EBidiClass& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EBidiClass")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set EBidiClass value.
  switch (value)
  {
    case 0:
      a_rInstance = NString::NUCD::e_BidiClass_L;
      break;
    case 1:
      a_rInstance = NString::NUCD::e_BidiClass_LRE;
      break;
    case 2:
      a_rInstance = NString::NUCD::e_BidiClass_LRO;
      break;
    case 3:
      a_rInstance = NString::NUCD::e_BidiClass_R;
      break;
    case 4:
      a_rInstance = NString::NUCD::e_BidiClass_AL;
      break;
    case 5:
      a_rInstance = NString::NUCD::e_BidiClass_RLE;
      break;
    case 6:
      a_rInstance = NString::NUCD::e_BidiClass_RLO;
      break;
    case 7:
      a_rInstance = NString::NUCD::e_BidiClass_PDF;
      break;
    case 8:
      a_rInstance = NString::NUCD::e_BidiClass_EN;
      break;
    case 9:
      a_rInstance = NString::NUCD::e_BidiClass_ES;
      break;
    case 10:
      a_rInstance = NString::NUCD::e_BidiClass_ET;
      break;
    case 11:
      a_rInstance = NString::NUCD::e_BidiClass_AN;
      break;
    case 12:
      a_rInstance = NString::NUCD::e_BidiClass_CS;
      break;
    case 13:
      a_rInstance = NString::NUCD::e_BidiClass_NSM;
      break;
    case 14:
      a_rInstance = NString::NUCD::e_BidiClass_BN;
      break;
    case 15:
      a_rInstance = NString::NUCD::e_BidiClass_B;
      break;
    case 16:
      a_rInstance = NString::NUCD::e_BidiClass_S;
      break;
    case 17:
      a_rInstance = NString::NUCD::e_BidiClass_WS;
      break;
    case 18:
      a_rInstance = NString::NUCD::e_BidiClass_ON;
      break;
    default:
      WARNING(STR("Cannot load invalid EBidiClass value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EBidiClass& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get EBidiClass value.
  switch (a_crInstance)
  {
    case NString::NUCD::e_BidiClass_L:
      value = 0;
      break;
    case NString::NUCD::e_BidiClass_LRE:
      value = 1;
      break;
    case NString::NUCD::e_BidiClass_LRO:
      value = 2;
      break;
    case NString::NUCD::e_BidiClass_R:
      value = 3;
      break;
    case NString::NUCD::e_BidiClass_AL:
      value = 4;
      break;
    case NString::NUCD::e_BidiClass_RLE:
      value = 5;
      break;
    case NString::NUCD::e_BidiClass_RLO:
      value = 6;
      break;
    case NString::NUCD::e_BidiClass_PDF:
      value = 7;
      break;
    case NString::NUCD::e_BidiClass_EN:
      value = 8;
      break;
    case NString::NUCD::e_BidiClass_ES:
      value = 9;
      break;
    case NString::NUCD::e_BidiClass_ET:
      value = 10;
      break;
    case NString::NUCD::e_BidiClass_AN:
      value = 11;
      break;
    case NString::NUCD::e_BidiClass_CS:
      value = 12;
      break;
    case NString::NUCD::e_BidiClass_NSM:
      value = 13;
      break;
    case NString::NUCD::e_BidiClass_BN:
      value = 14;
      break;
    case NString::NUCD::e_BidiClass_B:
      value = 15;
      break;
    case NString::NUCD::e_BidiClass_S:
      value = 16;
      break;
    case NString::NUCD::e_BidiClass_WS:
      value = 17;
      break;
    case NString::NUCD::e_BidiClass_ON:
      value = 18;
      break;
    default:
      WARNING(STR("Cannot save invalid EBidiClass value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EBidiClass")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EBidiClass& a_rInstance)
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
