/*!
 *  \file    EEastAsianWidth.inl Character East Asian width enumeration.
 *  \brief   Character East Asian width enumeration (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character East Asian width enumeration (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   01.04.2009 23:33:33

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
#ifndef __EEASTASIANWIDTH_INL__
#define __EEASTASIANWIDTH_INL__
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EEastAsianWidth& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EEastAsianWidth")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set EEastAsianWidth value.
  switch (value)
  {
    case 0:
      a_rInstance = NString::NUCD::e_EastAsianWidth_Neutral;
      break;
    case 1:
      a_rInstance = NString::NUCD::e_EastAsianWidth_Fullwidth;
      break;
    case 2:
      a_rInstance = NString::NUCD::e_EastAsianWidth_Halfwidth;
      break;
    case 3:
      a_rInstance = NString::NUCD::e_EastAsianWidth_Wide;
      break;
    case 4:
      a_rInstance = NString::NUCD::e_EastAsianWidth_Narrow;
      break;
    case 5:
      a_rInstance = NString::NUCD::e_EastAsianWidth_Ambiguous;
      break;
    default:
      WARNING(STR("Cannot load invalid EEastAsianWidth value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EEastAsianWidth& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get EEastAsianWidth value.
  switch (a_crInstance)
  {
    case NString::NUCD::e_EastAsianWidth_Neutral:
      value = 0;
      break;
    case NString::NUCD::e_EastAsianWidth_Fullwidth:
      value = 1;
      break;
    case NString::NUCD::e_EastAsianWidth_Halfwidth:
      value = 2;
      break;
    case NString::NUCD::e_EastAsianWidth_Wide:
      value = 3;
      break;
    case NString::NUCD::e_EastAsianWidth_Narrow:
      value = 4;
      break;
    case NString::NUCD::e_EastAsianWidth_Ambiguous:
      value = 5;
      break;
    default:
      WARNING(STR("Cannot save invalid EEastAsianWidth value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EEastAsianWidth")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EEastAsianWidth& a_rInstance)
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
