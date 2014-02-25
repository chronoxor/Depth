/*!
 *  \file    EJoiningGroup.inl Character joining group enumeration.
 *  \brief   Character joining group enumeration (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character joining group enumeration (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   01.04.2009 23:11:42

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
#ifndef __EJOININGGROUP_INL__
#define __EJOININGGROUP_INL__
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EJoiningGroup& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EJoiningGroup")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set EJoiningGroup value.
  switch (value)
  {
    case 0:
      a_rInstance = NString::NUCD::e_JoiningGroup_None;
      break;
    case 1:
      a_rInstance = NString::NUCD::e_JoiningGroup_Ain;
      break;
    case 2:
      a_rInstance = NString::NUCD::e_JoiningGroup_Alaph;
      break;
    case 3:
      a_rInstance = NString::NUCD::e_JoiningGroup_Alef;
      break;
    case 4:
      a_rInstance = NString::NUCD::e_JoiningGroup_Beh;
      break;
    case 5:
      a_rInstance = NString::NUCD::e_JoiningGroup_Beth;
      break;
    case 6:
      a_rInstance = NString::NUCD::e_JoiningGroup_Burushaski_Yeh_Barree;
      break;
    case 7:
      a_rInstance = NString::NUCD::e_JoiningGroup_Dal;
      break;
    case 8:
      a_rInstance = NString::NUCD::e_JoiningGroup_Dalath_Rish;
      break;
    case 9:
      a_rInstance = NString::NUCD::e_JoiningGroup_E;
      break;
    case 10:
      a_rInstance = NString::NUCD::e_JoiningGroup_Farsi_Yeh;
      break;
    case 11:
      a_rInstance = NString::NUCD::e_JoiningGroup_Fe;
      break;
    case 12:
      a_rInstance = NString::NUCD::e_JoiningGroup_Feh;
      break;
    case 13:
      a_rInstance = NString::NUCD::e_JoiningGroup_Final_Semkath;
      break;
    case 14:
      a_rInstance = NString::NUCD::e_JoiningGroup_Gaf;
      break;
    case 15:
      a_rInstance = NString::NUCD::e_JoiningGroup_Gamal;
      break;
    case 16:
      a_rInstance = NString::NUCD::e_JoiningGroup_Hah;
      break;
    case 17:
      a_rInstance = NString::NUCD::e_JoiningGroup_Hamza_On_Heh_Goal;
      break;
    case 18:
      a_rInstance = NString::NUCD::e_JoiningGroup_He;
      break;
    case 19:
      a_rInstance = NString::NUCD::e_JoiningGroup_Heh;
      break;
    case 20:
      a_rInstance = NString::NUCD::e_JoiningGroup_Heh_Goal;
      break;
    case 21:
      a_rInstance = NString::NUCD::e_JoiningGroup_Heth;
      break;
    case 22:
      a_rInstance = NString::NUCD::e_JoiningGroup_Kaf;
      break;
    case 23:
      a_rInstance = NString::NUCD::e_JoiningGroup_Kaph;
      break;
    case 24:
      a_rInstance = NString::NUCD::e_JoiningGroup_Khaph;
      break;
    case 25:
      a_rInstance = NString::NUCD::e_JoiningGroup_Knotted_Heh;
      break;
    case 26:
      a_rInstance = NString::NUCD::e_JoiningGroup_Lam;
      break;
    case 27:
      a_rInstance = NString::NUCD::e_JoiningGroup_Lamadh;
      break;
    case 28:
      a_rInstance = NString::NUCD::e_JoiningGroup_Meem;
      break;
    case 29:
      a_rInstance = NString::NUCD::e_JoiningGroup_Mim;
      break;
    case 30:
      a_rInstance = NString::NUCD::e_JoiningGroup_Noon;
      break;
    case 31:
      a_rInstance = NString::NUCD::e_JoiningGroup_Nun;
      break;
    case 32:
      a_rInstance = NString::NUCD::e_JoiningGroup_Nya;
      break;
    case 33:
      a_rInstance = NString::NUCD::e_JoiningGroup_Pe;
      break;
    case 34:
      a_rInstance = NString::NUCD::e_JoiningGroup_Qaf;
      break;
    case 35:
      a_rInstance = NString::NUCD::e_JoiningGroup_Qaph;
      break;
    case 36:
      a_rInstance = NString::NUCD::e_JoiningGroup_Reh;
      break;
    case 37:
      a_rInstance = NString::NUCD::e_JoiningGroup_Reversed_Pe;
      break;
    case 38:
      a_rInstance = NString::NUCD::e_JoiningGroup_Sad;
      break;
    case 39:
      a_rInstance = NString::NUCD::e_JoiningGroup_Sadhe;
      break;
    case 40:
      a_rInstance = NString::NUCD::e_JoiningGroup_Seen;
      break;
    case 41:
      a_rInstance = NString::NUCD::e_JoiningGroup_Semkath;
      break;
    case 42:
      a_rInstance = NString::NUCD::e_JoiningGroup_Shin;
      break;
    case 43:
      a_rInstance = NString::NUCD::e_JoiningGroup_Swash_Kaf;
      break;
    case 44:
      a_rInstance = NString::NUCD::e_JoiningGroup_Syriac_Waw;
      break;
    case 45:
      a_rInstance = NString::NUCD::e_JoiningGroup_Tah;
      break;
    case 46:
      a_rInstance = NString::NUCD::e_JoiningGroup_Taw;
      break;
    case 47:
      a_rInstance = NString::NUCD::e_JoiningGroup_Teh_Marbuta;
      break;
    case 48:
      a_rInstance = NString::NUCD::e_JoiningGroup_Teth;
      break;
    case 49:
      a_rInstance = NString::NUCD::e_JoiningGroup_Waw;
      break;
    case 50:
      a_rInstance = NString::NUCD::e_JoiningGroup_Yeh;
      break;
    case 51:
      a_rInstance = NString::NUCD::e_JoiningGroup_Yeh_Barree;
      break;
    case 52:
      a_rInstance = NString::NUCD::e_JoiningGroup_Yeh_With_Tail;
      break;
    case 53:
      a_rInstance = NString::NUCD::e_JoiningGroup_Yudh;
      break;
    case 54:
      a_rInstance = NString::NUCD::e_JoiningGroup_Yudh_He;
      break;
    case 55:
      a_rInstance = NString::NUCD::e_JoiningGroup_Zain;
      break;
    case 56:
      a_rInstance = NString::NUCD::e_JoiningGroup_Zhain;
      break;
    default:
      WARNING(STR("Cannot load invalid EJoiningGroup value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EJoiningGroup& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get EJoiningGroup value.
  switch (a_crInstance)
  {
    case NString::NUCD::e_JoiningGroup_None:
      value = 0;
      break;
    case NString::NUCD::e_JoiningGroup_Ain:
      value = 1;
      break;
    case NString::NUCD::e_JoiningGroup_Alaph:
      value = 2;
      break;
    case NString::NUCD::e_JoiningGroup_Alef:
      value = 3;
      break;
    case NString::NUCD::e_JoiningGroup_Beh:
      value = 4;
      break;
    case NString::NUCD::e_JoiningGroup_Beth:
      value = 5;
      break;
    case NString::NUCD::e_JoiningGroup_Burushaski_Yeh_Barree:
      value = 6;
      break;
    case NString::NUCD::e_JoiningGroup_Dal:
      value = 7;
      break;
    case NString::NUCD::e_JoiningGroup_Dalath_Rish:
      value = 8;
      break;
    case NString::NUCD::e_JoiningGroup_E:
      value = 9;
      break;
    case NString::NUCD::e_JoiningGroup_Farsi_Yeh:
      value = 10;
      break;
    case NString::NUCD::e_JoiningGroup_Fe:
      value = 11;
      break;
    case NString::NUCD::e_JoiningGroup_Feh:
      value = 12;
      break;
    case NString::NUCD::e_JoiningGroup_Final_Semkath:
      value = 13;
      break;
    case NString::NUCD::e_JoiningGroup_Gaf:
      value = 14;
      break;
    case NString::NUCD::e_JoiningGroup_Gamal:
      value = 15;
      break;
    case NString::NUCD::e_JoiningGroup_Hah:
      value = 16;
      break;
    case NString::NUCD::e_JoiningGroup_Hamza_On_Heh_Goal:
      value = 17;
      break;
    case NString::NUCD::e_JoiningGroup_He:
      value = 18;
      break;
    case NString::NUCD::e_JoiningGroup_Heh:
      value = 19;
      break;
    case NString::NUCD::e_JoiningGroup_Heh_Goal:
      value = 20;
      break;
    case NString::NUCD::e_JoiningGroup_Heth:
      value = 21;
      break;
    case NString::NUCD::e_JoiningGroup_Kaf:
      value = 22;
      break;
    case NString::NUCD::e_JoiningGroup_Kaph:
      value = 23;
      break;
    case NString::NUCD::e_JoiningGroup_Khaph:
      value = 24;
      break;
    case NString::NUCD::e_JoiningGroup_Knotted_Heh:
      value = 25;
      break;
    case NString::NUCD::e_JoiningGroup_Lam:
      value = 26;
      break;
    case NString::NUCD::e_JoiningGroup_Lamadh:
      value = 27;
      break;
    case NString::NUCD::e_JoiningGroup_Meem:
      value = 28;
      break;
    case NString::NUCD::e_JoiningGroup_Mim:
      value = 29;
      break;
    case NString::NUCD::e_JoiningGroup_Noon:
      value = 30;
      break;
    case NString::NUCD::e_JoiningGroup_Nun:
      value = 31;
      break;
    case NString::NUCD::e_JoiningGroup_Nya:
      value = 32;
      break;
    case NString::NUCD::e_JoiningGroup_Pe:
      value = 33;
      break;
    case NString::NUCD::e_JoiningGroup_Qaf:
      value = 34;
      break;
    case NString::NUCD::e_JoiningGroup_Qaph:
      value = 35;
      break;
    case NString::NUCD::e_JoiningGroup_Reh:
      value = 36;
      break;
    case NString::NUCD::e_JoiningGroup_Reversed_Pe:
      value = 37;
      break;
    case NString::NUCD::e_JoiningGroup_Sad:
      value = 38;
      break;
    case NString::NUCD::e_JoiningGroup_Sadhe:
      value = 39;
      break;
    case NString::NUCD::e_JoiningGroup_Seen:
      value = 40;
      break;
    case NString::NUCD::e_JoiningGroup_Semkath:
      value = 41;
      break;
    case NString::NUCD::e_JoiningGroup_Shin:
      value = 42;
      break;
    case NString::NUCD::e_JoiningGroup_Swash_Kaf:
      value = 43;
      break;
    case NString::NUCD::e_JoiningGroup_Syriac_Waw:
      value = 44;
      break;
    case NString::NUCD::e_JoiningGroup_Tah:
      value = 45;
      break;
    case NString::NUCD::e_JoiningGroup_Taw:
      value = 46;
      break;
    case NString::NUCD::e_JoiningGroup_Teh_Marbuta:
      value = 47;
      break;
    case NString::NUCD::e_JoiningGroup_Teth:
      value = 48;
      break;
    case NString::NUCD::e_JoiningGroup_Waw:
      value = 49;
      break;
    case NString::NUCD::e_JoiningGroup_Yeh:
      value = 50;
      break;
    case NString::NUCD::e_JoiningGroup_Yeh_Barree:
      value = 51;
      break;
    case NString::NUCD::e_JoiningGroup_Yeh_With_Tail:
      value = 52;
      break;
    case NString::NUCD::e_JoiningGroup_Yudh:
      value = 53;
      break;
    case NString::NUCD::e_JoiningGroup_Yudh_He:
      value = 54;
      break;
    case NString::NUCD::e_JoiningGroup_Zain:
      value = 55;
      break;
    case NString::NUCD::e_JoiningGroup_Zhain:
      value = 56;
      break;
    default:
      WARNING(STR("Cannot save invalid EJoiningGroup value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EJoiningGroup")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EJoiningGroup& a_rInstance)
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
