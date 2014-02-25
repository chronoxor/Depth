/*!
 *  \file    EDecompositionMapping.inl Character decomposition mapping type
 *           enumeration.
 *  \brief   Character decomposition mapping type enumeration (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character decomposition mapping type enumeration (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 22:11:13

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
#ifndef __EDECOMPOSITIONMAPPING_INL__
#define __EDECOMPOSITIONMAPPING_INL__
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EDecompositionMapping& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EDecompositionMapping")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set EDecompositionMapping value.
  switch (value)
  {
    case 0:
      a_rInstance = NString::NUCD::e_DecompositionMapping_None;
      break;
    case 1:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Canonical;
      break;
    case 2:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Font;
      break;
    case 3:
      a_rInstance = NString::NUCD::e_DecompositionMapping_NoBreak;
      break;
    case 4:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Initial;
      break;
    case 5:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Medial;
      break;
    case 6:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Final;
      break;
    case 7:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Isolated;
      break;
    case 8:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Circle;
      break;
    case 9:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Super;
      break;
    case 10:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Sub;
      break;
    case 11:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Vertical;
      break;
    case 12:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Wide;
      break;
    case 13:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Narrow;
      break;
    case 14:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Small;
      break;
    case 15:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Square;
      break;
    case 16:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Fraction;
      break;
    case 17:
      a_rInstance = NString::NUCD::e_DecompositionMapping_Compat;
      break;
    default:
      WARNING(STR("Cannot load invalid EDecompositionMapping value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EDecompositionMapping& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get EDecompositionMapping value.
  switch (a_crInstance)
  {
    case NString::NUCD::e_DecompositionMapping_None:
      value = 0;
      break;
    case NString::NUCD::e_DecompositionMapping_Canonical:
      value = 1;
      break;
    case NString::NUCD::e_DecompositionMapping_Font:
      value = 2;
      break;
    case NString::NUCD::e_DecompositionMapping_NoBreak:
      value = 3;
      break;
    case NString::NUCD::e_DecompositionMapping_Initial:
      value = 4;
      break;
    case NString::NUCD::e_DecompositionMapping_Medial:
      value = 5;
      break;
    case NString::NUCD::e_DecompositionMapping_Final:
      value = 6;
      break;
    case NString::NUCD::e_DecompositionMapping_Isolated:
      value = 7;
      break;
    case NString::NUCD::e_DecompositionMapping_Circle:
      value = 8;
      break;
    case NString::NUCD::e_DecompositionMapping_Super:
      value = 9;
      break;
    case NString::NUCD::e_DecompositionMapping_Sub:
      value = 10;
      break;
    case NString::NUCD::e_DecompositionMapping_Vertical:
      value = 11;
      break;
    case NString::NUCD::e_DecompositionMapping_Wide:
      value = 12;
      break;
    case NString::NUCD::e_DecompositionMapping_Narrow:
      value = 13;
      break;
    case NString::NUCD::e_DecompositionMapping_Small:
      value = 14;
      break;
    case NString::NUCD::e_DecompositionMapping_Square:
      value = 15;
      break;
    case NString::NUCD::e_DecompositionMapping_Fraction:
      value = 16;
      break;
    case NString::NUCD::e_DecompositionMapping_Compat:
      value = 17;
      break;
    default:
      WARNING(STR("Cannot save invalid EDecompositionMapping value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EDecompositionMapping")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EDecompositionMapping& a_rInstance)
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
