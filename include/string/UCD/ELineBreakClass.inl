/*!
 *  \file    ELineBreakClass.inl Character line break class enumeration.
 *  \brief   Character line break class enumeration (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character line break class enumeration (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 03:16:56

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
#ifndef __ELINEBREAKCLASS_INL__
#define __ELINEBREAKCLASS_INL__
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::ELineBreakClass& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::ELineBreakClass")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set ELineBreakClass value.
  switch (value)
  {
    case 0:
      a_rInstance = NString::NUCD::e_LineBreakClass_BK;
      break;
    case 1:
      a_rInstance = NString::NUCD::e_LineBreakClass_CR;
      break;
    case 2:
      a_rInstance = NString::NUCD::e_LineBreakClass_LF;
      break;
    case 3:
      a_rInstance = NString::NUCD::e_LineBreakClass_CM;
      break;
    case 4:
      a_rInstance = NString::NUCD::e_LineBreakClass_NL;
      break;
    case 5:
      a_rInstance = NString::NUCD::e_LineBreakClass_SG;
      break;
    case 6:
      a_rInstance = NString::NUCD::e_LineBreakClass_WJ;
      break;
    case 7:
      a_rInstance = NString::NUCD::e_LineBreakClass_ZW;
      break;
    case 8:
      a_rInstance = NString::NUCD::e_LineBreakClass_GL;
      break;
    case 9:
      a_rInstance = NString::NUCD::e_LineBreakClass_SP;
      break;
    case 10:
      a_rInstance = NString::NUCD::e_LineBreakClass_B2;
      break;
    case 11:
      a_rInstance = NString::NUCD::e_LineBreakClass_BA;
      break;
    case 12:
      a_rInstance = NString::NUCD::e_LineBreakClass_BB;
      break;
    case 13:
      a_rInstance = NString::NUCD::e_LineBreakClass_HY;
      break;
    case 14:
      a_rInstance = NString::NUCD::e_LineBreakClass_CB;
      break;
    case 15:
      a_rInstance = NString::NUCD::e_LineBreakClass_CL;
      break;
    case 16:
      a_rInstance = NString::NUCD::e_LineBreakClass_CP;
      break;
    case 17:
      a_rInstance = NString::NUCD::e_LineBreakClass_EX;
      break;
    case 18:
      a_rInstance = NString::NUCD::e_LineBreakClass_IN;
      break;
    case 19:
      a_rInstance = NString::NUCD::e_LineBreakClass_NS;
      break;
    case 20:
      a_rInstance = NString::NUCD::e_LineBreakClass_OP;
      break;
    case 21:
      a_rInstance = NString::NUCD::e_LineBreakClass_QU;
      break;
    case 22:
      a_rInstance = NString::NUCD::e_LineBreakClass_IS;
      break;
    case 23:
      a_rInstance = NString::NUCD::e_LineBreakClass_NU;
      break;
    case 24:
      a_rInstance = NString::NUCD::e_LineBreakClass_PO;
      break;
    case 25:
      a_rInstance = NString::NUCD::e_LineBreakClass_PR;
      break;
    case 26:
      a_rInstance = NString::NUCD::e_LineBreakClass_SY;
      break;
    case 27:
      a_rInstance = NString::NUCD::e_LineBreakClass_AI;
      break;
    case 28:
      a_rInstance = NString::NUCD::e_LineBreakClass_AL;
      break;
    case 29:
      a_rInstance = NString::NUCD::e_LineBreakClass_H2;
      break;
    case 30:
      a_rInstance = NString::NUCD::e_LineBreakClass_H3;
      break;
    case 31:
      a_rInstance = NString::NUCD::e_LineBreakClass_ID;
      break;
    case 32:
      a_rInstance = NString::NUCD::e_LineBreakClass_JL;
      break;
    case 33:
      a_rInstance = NString::NUCD::e_LineBreakClass_JV;
      break;
    case 34:
      a_rInstance = NString::NUCD::e_LineBreakClass_JT;
      break;
    case 35:
      a_rInstance = NString::NUCD::e_LineBreakClass_SA;
      break;
    case 36:
      a_rInstance = NString::NUCD::e_LineBreakClass_XX;
      break;
    default:
      WARNING(STR("Cannot load invalid ELineBreakClass value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::ELineBreakClass& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get ELineBreakClass value.
  switch (a_crInstance)
  {
    case NString::NUCD::e_LineBreakClass_BK:
      value = 0;
      break;
    case NString::NUCD::e_LineBreakClass_CR:
      value = 1;
      break;
    case NString::NUCD::e_LineBreakClass_LF:
      value = 2;
      break;
    case NString::NUCD::e_LineBreakClass_CM:
      value = 3;
      break;
    case NString::NUCD::e_LineBreakClass_NL:
      value = 4;
      break;
    case NString::NUCD::e_LineBreakClass_SG:
      value = 5;
      break;
    case NString::NUCD::e_LineBreakClass_WJ:
      value = 6;
      break;
    case NString::NUCD::e_LineBreakClass_ZW:
      value = 7;
      break;
    case NString::NUCD::e_LineBreakClass_GL:
      value = 8;
      break;
    case NString::NUCD::e_LineBreakClass_SP:
      value = 9;
      break;
    case NString::NUCD::e_LineBreakClass_B2:
      value = 10;
      break;
    case NString::NUCD::e_LineBreakClass_BA:
      value = 11;
      break;
    case NString::NUCD::e_LineBreakClass_BB:
      value = 12;
      break;
    case NString::NUCD::e_LineBreakClass_HY:
      value = 13;
      break;
    case NString::NUCD::e_LineBreakClass_CB:
      value = 14;
      break;
    case NString::NUCD::e_LineBreakClass_CL:
      value = 15;
      break;
    case NString::NUCD::e_LineBreakClass_CP:
      value = 16;
      break;
    case NString::NUCD::e_LineBreakClass_EX:
      value = 17;
      break;
    case NString::NUCD::e_LineBreakClass_IN:
      value = 18;
      break;
    case NString::NUCD::e_LineBreakClass_NS:
      value = 19;
      break;
    case NString::NUCD::e_LineBreakClass_OP:
      value = 20;
      break;
    case NString::NUCD::e_LineBreakClass_QU:
      value = 21;
      break;
    case NString::NUCD::e_LineBreakClass_IS:
      value = 22;
      break;
    case NString::NUCD::e_LineBreakClass_NU:
      value = 23;
      break;
    case NString::NUCD::e_LineBreakClass_PO:
      value = 24;
      break;
    case NString::NUCD::e_LineBreakClass_PR:
      value = 25;
      break;
    case NString::NUCD::e_LineBreakClass_SY:
      value = 26;
      break;
    case NString::NUCD::e_LineBreakClass_AI:
      value = 27;
      break;
    case NString::NUCD::e_LineBreakClass_AL:
      value = 28;
      break;
    case NString::NUCD::e_LineBreakClass_H2:
      value = 29;
      break;
    case NString::NUCD::e_LineBreakClass_H3:
      value = 30;
      break;
    case NString::NUCD::e_LineBreakClass_ID:
      value = 31;
      break;
    case NString::NUCD::e_LineBreakClass_JL:
      value = 32;
      break;
    case NString::NUCD::e_LineBreakClass_JV:
      value = 33;
      break;
    case NString::NUCD::e_LineBreakClass_JT:
      value = 34;
      break;
    case NString::NUCD::e_LineBreakClass_SA:
      value = 35;
      break;
    case NString::NUCD::e_LineBreakClass_XX:
      value = 36;
      break;
    default:
      WARNING(STR("Cannot save invalid ELineBreakClass value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::ELineBreakClass")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::ELineBreakClass& a_rInstance)
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
