/*!
 *  \file    EGeneralCategory.inl Character General Category type enumeration.
 *  \brief   Character General Category type enumeration (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character General Category type enumeration (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 23:07:14

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
#ifndef __EGENERALCATEGORY_INL__
#define __EGENERALCATEGORY_INL__
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EGeneralCategory& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EGeneralCategory")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set EGeneralCategory value.
  switch (value)
  {
    case 0:
      a_rInstance = NString::NUCD::e_GeneralCategory_Lu;
      break;
    case 1:
      a_rInstance = NString::NUCD::e_GeneralCategory_Ll;
      break;
    case 2:
      a_rInstance = NString::NUCD::e_GeneralCategory_Lt;
      break;
    case 3:
      a_rInstance = NString::NUCD::e_GeneralCategory_Lm;
      break;
    case 4:
      a_rInstance = NString::NUCD::e_GeneralCategory_Lo;
      break;
    case 5:
      a_rInstance = NString::NUCD::e_GeneralCategory_Mn;
      break;
    case 6:
      a_rInstance = NString::NUCD::e_GeneralCategory_Mc;
      break;
    case 7:
      a_rInstance = NString::NUCD::e_GeneralCategory_Me;
      break;
    case 8:
      a_rInstance = NString::NUCD::e_GeneralCategory_Nd;
      break;
    case 9:
      a_rInstance = NString::NUCD::e_GeneralCategory_Nl;
      break;
    case 10:
      a_rInstance = NString::NUCD::e_GeneralCategory_No;
      break;
    case 11:
      a_rInstance = NString::NUCD::e_GeneralCategory_Pc;
      break;
    case 12:
      a_rInstance = NString::NUCD::e_GeneralCategory_Pd;
      break;
    case 13:
      a_rInstance = NString::NUCD::e_GeneralCategory_Ps;
      break;
    case 14:
      a_rInstance = NString::NUCD::e_GeneralCategory_Pe;
      break;
    case 15:
      a_rInstance = NString::NUCD::e_GeneralCategory_Pi;
      break;
    case 16:
      a_rInstance = NString::NUCD::e_GeneralCategory_Pf;
      break;
    case 17:
      a_rInstance = NString::NUCD::e_GeneralCategory_Po;
      break;
    case 18:
      a_rInstance = NString::NUCD::e_GeneralCategory_Sm;
      break;
    case 19:
      a_rInstance = NString::NUCD::e_GeneralCategory_Sc;
      break;
    case 20:
      a_rInstance = NString::NUCD::e_GeneralCategory_Sk;
      break;
    case 21:
      a_rInstance = NString::NUCD::e_GeneralCategory_So;
      break;
    case 22:
      a_rInstance = NString::NUCD::e_GeneralCategory_Zs;
      break;
    case 23:
      a_rInstance = NString::NUCD::e_GeneralCategory_Zl;
      break;
    case 24:
      a_rInstance = NString::NUCD::e_GeneralCategory_Zp;
      break;
    case 25:
      a_rInstance = NString::NUCD::e_GeneralCategory_Cc;
      break;
    case 26:
      a_rInstance = NString::NUCD::e_GeneralCategory_Cf;
      break;
    case 27:
      a_rInstance = NString::NUCD::e_GeneralCategory_Cs;
      break;
    case 28:
      a_rInstance = NString::NUCD::e_GeneralCategory_Co;
      break;
    case 29:
      a_rInstance = NString::NUCD::e_GeneralCategory_Cn;
      break;
    default:
      WARNING(STR("Cannot load invalid EGeneralCategory value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EGeneralCategory& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get EGeneralCategory value.
  switch (a_crInstance)
  {
    case NString::NUCD::e_GeneralCategory_Lu:
      value = 0;
      break;
    case NString::NUCD::e_GeneralCategory_Ll:
      value = 1;
      break;
    case NString::NUCD::e_GeneralCategory_Lt:
      value = 2;
      break;
    case NString::NUCD::e_GeneralCategory_Lm:
      value = 3;
      break;
    case NString::NUCD::e_GeneralCategory_Lo:
      value = 4;
      break;
    case NString::NUCD::e_GeneralCategory_Mn:
      value = 5;
      break;
    case NString::NUCD::e_GeneralCategory_Mc:
      value = 6;
      break;
    case NString::NUCD::e_GeneralCategory_Me:
      value = 7;
      break;
    case NString::NUCD::e_GeneralCategory_Nd:
      value = 8;
      break;
    case NString::NUCD::e_GeneralCategory_Nl:
      value = 9;
      break;
    case NString::NUCD::e_GeneralCategory_No:
      value = 10;
      break;
    case NString::NUCD::e_GeneralCategory_Pc:
      value = 11;
      break;
    case NString::NUCD::e_GeneralCategory_Pd:
      value = 12;
      break;
    case NString::NUCD::e_GeneralCategory_Ps:
      value = 13;
      break;
    case NString::NUCD::e_GeneralCategory_Pe:
      value = 14;
      break;
    case NString::NUCD::e_GeneralCategory_Pi:
      value = 15;
      break;
    case NString::NUCD::e_GeneralCategory_Pf:
      value = 16;
      break;
    case NString::NUCD::e_GeneralCategory_Po:
      value = 17;
      break;
    case NString::NUCD::e_GeneralCategory_Sm:
      value = 18;
      break;
    case NString::NUCD::e_GeneralCategory_Sc:
      value = 19;
      break;
    case NString::NUCD::e_GeneralCategory_Sk:
      value = 20;
      break;
    case NString::NUCD::e_GeneralCategory_So:
      value = 21;
      break;
    case NString::NUCD::e_GeneralCategory_Zs:
      value = 22;
      break;
    case NString::NUCD::e_GeneralCategory_Zl:
      value = 23;
      break;
    case NString::NUCD::e_GeneralCategory_Zp:
      value = 24;
      break;
    case NString::NUCD::e_GeneralCategory_Cc:
      value = 25;
      break;
    case NString::NUCD::e_GeneralCategory_Cf:
      value = 26;
      break;
    case NString::NUCD::e_GeneralCategory_Cs:
      value = 27;
      break;
    case NString::NUCD::e_GeneralCategory_Co:
      value = 28;
      break;
    case NString::NUCD::e_GeneralCategory_Cn:
      value = 29;
      break;
    default:
      WARNING(STR("Cannot save invalid EGeneralCategory value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EGeneralCategory")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EGeneralCategory& a_rInstance)
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
