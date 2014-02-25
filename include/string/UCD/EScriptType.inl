/*!
 *  \file    EScriptType.inl Character script type enumeration.
 *  \brief   Character script type enumeration (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character script type enumeration (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 02:44:42

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
#ifndef __ESCRIPTTYPE_INL__
#define __ESCRIPTTYPE_INL__
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EScriptType& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EScriptType")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set EScriptType value.
  switch (value)
  {
    case 0:
      a_rInstance = NString::NUCD::e_ScriptType_Arab;
      break;
    case 1:
      a_rInstance = NString::NUCD::e_ScriptType_Armi;
      break;
    case 2:
      a_rInstance = NString::NUCD::e_ScriptType_Armn;
      break;
    case 3:
      a_rInstance = NString::NUCD::e_ScriptType_Avst;
      break;
    case 4:
      a_rInstance = NString::NUCD::e_ScriptType_Bali;
      break;
    case 5:
      a_rInstance = NString::NUCD::e_ScriptType_Bamu;
      break;
    case 6:
      a_rInstance = NString::NUCD::e_ScriptType_Batk;
      break;
    case 7:
      a_rInstance = NString::NUCD::e_ScriptType_Beng;
      break;
    case 8:
      a_rInstance = NString::NUCD::e_ScriptType_Blis;
      break;
    case 9:
      a_rInstance = NString::NUCD::e_ScriptType_Bopo;
      break;
    case 10:
      a_rInstance = NString::NUCD::e_ScriptType_Brah;
      break;
    case 11:
      a_rInstance = NString::NUCD::e_ScriptType_Brai;
      break;
    case 12:
      a_rInstance = NString::NUCD::e_ScriptType_Bugi;
      break;
    case 13:
      a_rInstance = NString::NUCD::e_ScriptType_Buhd;
      break;
    case 14:
      a_rInstance = NString::NUCD::e_ScriptType_Cakm;
      break;
    case 15:
      a_rInstance = NString::NUCD::e_ScriptType_Cans;
      break;
    case 16:
      a_rInstance = NString::NUCD::e_ScriptType_Cari;
      break;
    case 17:
      a_rInstance = NString::NUCD::e_ScriptType_Cham;
      break;
    case 18:
      a_rInstance = NString::NUCD::e_ScriptType_Cher;
      break;
    case 19:
      a_rInstance = NString::NUCD::e_ScriptType_Cirt;
      break;
    case 20:
      a_rInstance = NString::NUCD::e_ScriptType_Copt;
      break;
    case 21:
      a_rInstance = NString::NUCD::e_ScriptType_Cprt;
      break;
    case 22:
      a_rInstance = NString::NUCD::e_ScriptType_Cyrl;
      break;
    case 23:
      a_rInstance = NString::NUCD::e_ScriptType_Cyrs;
      break;
    case 24:
      a_rInstance = NString::NUCD::e_ScriptType_Deva;
      break;
    case 25:
      a_rInstance = NString::NUCD::e_ScriptType_Dsrt;
      break;
    case 26:
      a_rInstance = NString::NUCD::e_ScriptType_Egyd;
      break;
    case 27:
      a_rInstance = NString::NUCD::e_ScriptType_Egyh;
      break;
    case 28:
      a_rInstance = NString::NUCD::e_ScriptType_Egyp;
      break;
    case 29:
      a_rInstance = NString::NUCD::e_ScriptType_Ethi;
      break;
    case 30:
      a_rInstance = NString::NUCD::e_ScriptType_Geok;
      break;
    case 31:
      a_rInstance = NString::NUCD::e_ScriptType_Geor;
      break;
    case 32:
      a_rInstance = NString::NUCD::e_ScriptType_Glag;
      break;
    case 33:
      a_rInstance = NString::NUCD::e_ScriptType_Goth;
      break;
    case 34:
      a_rInstance = NString::NUCD::e_ScriptType_Grek;
      break;
    case 35:
      a_rInstance = NString::NUCD::e_ScriptType_Gujr;
      break;
    case 36:
      a_rInstance = NString::NUCD::e_ScriptType_Guru;
      break;
    case 37:
      a_rInstance = NString::NUCD::e_ScriptType_Hang;
      break;
    case 38:
      a_rInstance = NString::NUCD::e_ScriptType_Hani;
      break;
    case 39:
      a_rInstance = NString::NUCD::e_ScriptType_Hans;
      break;
    case 40:
      a_rInstance = NString::NUCD::e_ScriptType_Hant;
      break;
    case 41:
      a_rInstance = NString::NUCD::e_ScriptType_Hano;
      break;
    case 42:
      a_rInstance = NString::NUCD::e_ScriptType_Hebr;
      break;
    case 43:
      a_rInstance = NString::NUCD::e_ScriptType_Hira;
      break;
    case 44:
      a_rInstance = NString::NUCD::e_ScriptType_Hmng;
      break;
    case 45:
      a_rInstance = NString::NUCD::e_ScriptType_Hrkt;
      break;
    case 46:
      a_rInstance = NString::NUCD::e_ScriptType_Hung;
      break;
    case 47:
      a_rInstance = NString::NUCD::e_ScriptType_Inds;
      break;
    case 48:
      a_rInstance = NString::NUCD::e_ScriptType_Ital;
      break;
    case 49:
      a_rInstance = NString::NUCD::e_ScriptType_Java;
      break;
    case 50:
      a_rInstance = NString::NUCD::e_ScriptType_Jpan;
      break;
    case 51:
      a_rInstance = NString::NUCD::e_ScriptType_Kali;
      break;
    case 52:
      a_rInstance = NString::NUCD::e_ScriptType_Kana;
      break;
    case 53:
      a_rInstance = NString::NUCD::e_ScriptType_Khar;
      break;
    case 54:
      a_rInstance = NString::NUCD::e_ScriptType_Khmr;
      break;
    case 55:
      a_rInstance = NString::NUCD::e_ScriptType_Knda;
      break;
    case 56:
      a_rInstance = NString::NUCD::e_ScriptType_Kore;
      break;
    case 57:
      a_rInstance = NString::NUCD::e_ScriptType_Kthi;
      break;
    case 58:
      a_rInstance = NString::NUCD::e_ScriptType_Lana;
      break;
    case 59:
      a_rInstance = NString::NUCD::e_ScriptType_Laoo;
      break;
    case 60:
      a_rInstance = NString::NUCD::e_ScriptType_Latf;
      break;
    case 61:
      a_rInstance = NString::NUCD::e_ScriptType_Latg;
      break;
    case 62:
      a_rInstance = NString::NUCD::e_ScriptType_Latn;
      break;
    case 63:
      a_rInstance = NString::NUCD::e_ScriptType_Lepc;
      break;
    case 64:
      a_rInstance = NString::NUCD::e_ScriptType_Limb;
      break;
    case 65:
      a_rInstance = NString::NUCD::e_ScriptType_Lina;
      break;
    case 66:
      a_rInstance = NString::NUCD::e_ScriptType_Linb;
      break;
    case 67:
      a_rInstance = NString::NUCD::e_ScriptType_Lisu;
      break;
    case 68:
      a_rInstance = NString::NUCD::e_ScriptType_Lyci;
      break;
    case 69:
      a_rInstance = NString::NUCD::e_ScriptType_Lydi;
      break;
    case 70:
      a_rInstance = NString::NUCD::e_ScriptType_Mand;
      break;
    case 71:
      a_rInstance = NString::NUCD::e_ScriptType_Mani;
      break;
    case 72:
      a_rInstance = NString::NUCD::e_ScriptType_Maya;
      break;
    case 73:
      a_rInstance = NString::NUCD::e_ScriptType_Mero;
      break;
    case 74:
      a_rInstance = NString::NUCD::e_ScriptType_Mlym;
      break;
    case 75:
      a_rInstance = NString::NUCD::e_ScriptType_Mong;
      break;
    case 76:
      a_rInstance = NString::NUCD::e_ScriptType_Moon;
      break;
    case 77:
      a_rInstance = NString::NUCD::e_ScriptType_Mtei;
      break;
    case 78:
      a_rInstance = NString::NUCD::e_ScriptType_Mymr;
      break;
    case 79:
      a_rInstance = NString::NUCD::e_ScriptType_Nkgb;
      break;
    case 80:
      a_rInstance = NString::NUCD::e_ScriptType_Nkoo;
      break;
    case 81:
      a_rInstance = NString::NUCD::e_ScriptType_Ogam;
      break;
    case 82:
      a_rInstance = NString::NUCD::e_ScriptType_Olck;
      break;
    case 83:
      a_rInstance = NString::NUCD::e_ScriptType_Orkh;
      break;
    case 84:
      a_rInstance = NString::NUCD::e_ScriptType_Orya;
      break;
    case 85:
      a_rInstance = NString::NUCD::e_ScriptType_Osma;
      break;
    case 86:
      a_rInstance = NString::NUCD::e_ScriptType_Perm;
      break;
    case 87:
      a_rInstance = NString::NUCD::e_ScriptType_Phag;
      break;
    case 88:
      a_rInstance = NString::NUCD::e_ScriptType_Phli;
      break;
    case 89:
      a_rInstance = NString::NUCD::e_ScriptType_Phlp;
      break;
    case 90:
      a_rInstance = NString::NUCD::e_ScriptType_Phlv;
      break;
    case 91:
      a_rInstance = NString::NUCD::e_ScriptType_Phnx;
      break;
    case 92:
      a_rInstance = NString::NUCD::e_ScriptType_Plrd;
      break;
    case 93:
      a_rInstance = NString::NUCD::e_ScriptType_Prti;
      break;
    case 94:
      a_rInstance = NString::NUCD::e_ScriptType_Qaaa;
      break;
    case 95:
      a_rInstance = NString::NUCD::e_ScriptType_Qabx;
      break;
    case 96:
      a_rInstance = NString::NUCD::e_ScriptType_Rjng;
      break;
    case 97:
      a_rInstance = NString::NUCD::e_ScriptType_Roro;
      break;
    case 98:
      a_rInstance = NString::NUCD::e_ScriptType_Runr;
      break;
    case 99:
      a_rInstance = NString::NUCD::e_ScriptType_Samr;
      break;
    case 100:
      a_rInstance = NString::NUCD::e_ScriptType_Sara;
      break;
    case 101:
      a_rInstance = NString::NUCD::e_ScriptType_Sarb;
      break;
    case 102:
      a_rInstance = NString::NUCD::e_ScriptType_Saur;
      break;
    case 103:
      a_rInstance = NString::NUCD::e_ScriptType_Sgnw;
      break;
    case 104:
      a_rInstance = NString::NUCD::e_ScriptType_Shaw;
      break;
    case 105:
      a_rInstance = NString::NUCD::e_ScriptType_Sinh;
      break;
    case 106:
      a_rInstance = NString::NUCD::e_ScriptType_Sund;
      break;
    case 107:
      a_rInstance = NString::NUCD::e_ScriptType_Sylo;
      break;
    case 108:
      a_rInstance = NString::NUCD::e_ScriptType_Syrc;
      break;
    case 109:
      a_rInstance = NString::NUCD::e_ScriptType_Syre;
      break;
    case 110:
      a_rInstance = NString::NUCD::e_ScriptType_Syrj;
      break;
    case 111:
      a_rInstance = NString::NUCD::e_ScriptType_Syrn;
      break;
    case 112:
      a_rInstance = NString::NUCD::e_ScriptType_Tagb;
      break;
    case 113:
      a_rInstance = NString::NUCD::e_ScriptType_Taml;
      break;
    case 114:
      a_rInstance = NString::NUCD::e_ScriptType_Tale;
      break;
    case 115:
      a_rInstance = NString::NUCD::e_ScriptType_Talu;
      break;
    case 116:
      a_rInstance = NString::NUCD::e_ScriptType_Tavt;
      break;
    case 117:
      a_rInstance = NString::NUCD::e_ScriptType_Telu;
      break;
    case 118:
      a_rInstance = NString::NUCD::e_ScriptType_Teng;
      break;
    case 119:
      a_rInstance = NString::NUCD::e_ScriptType_Tfng;
      break;
    case 120:
      a_rInstance = NString::NUCD::e_ScriptType_Tglg;
      break;
    case 121:
      a_rInstance = NString::NUCD::e_ScriptType_Thaa;
      break;
    case 122:
      a_rInstance = NString::NUCD::e_ScriptType_Thai;
      break;
    case 123:
      a_rInstance = NString::NUCD::e_ScriptType_Tibt;
      break;
    case 124:
      a_rInstance = NString::NUCD::e_ScriptType_Ugar;
      break;
    case 125:
      a_rInstance = NString::NUCD::e_ScriptType_Vaii;
      break;
    case 126:
      a_rInstance = NString::NUCD::e_ScriptType_Visp;
      break;
    case 127:
      a_rInstance = NString::NUCD::e_ScriptType_Xpeo;
      break;
    case 128:
      a_rInstance = NString::NUCD::e_ScriptType_Xsux;
      break;
    case 129:
      a_rInstance = NString::NUCD::e_ScriptType_Yiii;
      break;
    case 130:
      a_rInstance = NString::NUCD::e_ScriptType_Zinh;
      break;
    case 131:
      a_rInstance = NString::NUCD::e_ScriptType_Zmth;
      break;
    case 132:
      a_rInstance = NString::NUCD::e_ScriptType_Zsym;
      break;
    case 133:
      a_rInstance = NString::NUCD::e_ScriptType_Zxxx;
      break;
    case 134:
      a_rInstance = NString::NUCD::e_ScriptType_Zyyy;
      break;
    case 135:
      a_rInstance = NString::NUCD::e_ScriptType_Zzzz;
      break;
    default:
      WARNING(STR("Cannot load invalid EScriptType value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EScriptType& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get EScriptType value.
  switch (a_crInstance)
  {
    case NString::NUCD::e_ScriptType_Arab:
      value = 0;
      break;
    case NString::NUCD::e_ScriptType_Armi:
      value = 1;
      break;
    case NString::NUCD::e_ScriptType_Armn:
      value = 2;
      break;
    case NString::NUCD::e_ScriptType_Avst:
      value = 3;
      break;
    case NString::NUCD::e_ScriptType_Bali:
      value = 4;
      break;
    case NString::NUCD::e_ScriptType_Bamu:
      value = 5;
      break;
    case NString::NUCD::e_ScriptType_Batk:
      value = 6;
      break;
    case NString::NUCD::e_ScriptType_Beng:
      value = 7;
      break;
    case NString::NUCD::e_ScriptType_Blis:
      value = 8;
      break;
    case NString::NUCD::e_ScriptType_Bopo:
      value = 9;
      break;
    case NString::NUCD::e_ScriptType_Brah:
      value = 10;
      break;
    case NString::NUCD::e_ScriptType_Brai:
      value = 11;
      break;
    case NString::NUCD::e_ScriptType_Bugi:
      value = 12;
      break;
    case NString::NUCD::e_ScriptType_Buhd:
      value = 13;
      break;
    case NString::NUCD::e_ScriptType_Cakm:
      value = 14;
      break;
    case NString::NUCD::e_ScriptType_Cans:
      value = 15;
      break;
    case NString::NUCD::e_ScriptType_Cari:
      value = 16;
      break;
    case NString::NUCD::e_ScriptType_Cham:
      value = 17;
      break;
    case NString::NUCD::e_ScriptType_Cher:
      value = 18;
      break;
    case NString::NUCD::e_ScriptType_Cirt:
      value = 19;
      break;
    case NString::NUCD::e_ScriptType_Copt:
      value = 20;
      break;
    case NString::NUCD::e_ScriptType_Cprt:
      value = 21;
      break;
    case NString::NUCD::e_ScriptType_Cyrl:
      value = 22;
      break;
    case NString::NUCD::e_ScriptType_Cyrs:
      value = 23;
      break;
    case NString::NUCD::e_ScriptType_Deva:
      value = 24;
      break;
    case NString::NUCD::e_ScriptType_Dsrt:
      value = 25;
      break;
    case NString::NUCD::e_ScriptType_Egyd:
      value = 26;
      break;
    case NString::NUCD::e_ScriptType_Egyh:
      value = 27;
      break;
    case NString::NUCD::e_ScriptType_Egyp:
      value = 28;
      break;
    case NString::NUCD::e_ScriptType_Ethi:
      value = 29;
      break;
    case NString::NUCD::e_ScriptType_Geok:
      value = 30;
      break;
    case NString::NUCD::e_ScriptType_Geor:
      value = 31;
      break;
    case NString::NUCD::e_ScriptType_Glag:
      value = 32;
      break;
    case NString::NUCD::e_ScriptType_Goth:
      value = 33;
      break;
    case NString::NUCD::e_ScriptType_Grek:
      value = 34;
      break;
    case NString::NUCD::e_ScriptType_Gujr:
      value = 35;
      break;
    case NString::NUCD::e_ScriptType_Guru:
      value = 36;
      break;
    case NString::NUCD::e_ScriptType_Hang:
      value = 37;
      break;
    case NString::NUCD::e_ScriptType_Hani:
      value = 38;
      break;
    case NString::NUCD::e_ScriptType_Hans:
      value = 39;
      break;
    case NString::NUCD::e_ScriptType_Hant:
      value = 40;
      break;
    case NString::NUCD::e_ScriptType_Hano:
      value = 41;
      break;
    case NString::NUCD::e_ScriptType_Hebr:
      value = 42;
      break;
    case NString::NUCD::e_ScriptType_Hira:
      value = 43;
      break;
    case NString::NUCD::e_ScriptType_Hmng:
      value = 44;
      break;
    case NString::NUCD::e_ScriptType_Hrkt:
      value = 45;
      break;
    case NString::NUCD::e_ScriptType_Hung:
      value = 46;
      break;
    case NString::NUCD::e_ScriptType_Inds:
      value = 47;
      break;
    case NString::NUCD::e_ScriptType_Ital:
      value = 48;
      break;
    case NString::NUCD::e_ScriptType_Java:
      value = 49;
      break;
    case NString::NUCD::e_ScriptType_Jpan:
      value = 50;
      break;
    case NString::NUCD::e_ScriptType_Kali:
      value = 51;
      break;
    case NString::NUCD::e_ScriptType_Kana:
      value = 52;
      break;
    case NString::NUCD::e_ScriptType_Khar:
      value = 53;
      break;
    case NString::NUCD::e_ScriptType_Khmr:
      value = 54;
      break;
    case NString::NUCD::e_ScriptType_Knda:
      value = 55;
      break;
    case NString::NUCD::e_ScriptType_Kore:
      value = 56;
      break;
    case NString::NUCD::e_ScriptType_Kthi:
      value = 57;
      break;
    case NString::NUCD::e_ScriptType_Lana:
      value = 58;
      break;
    case NString::NUCD::e_ScriptType_Laoo:
      value = 59;
      break;
    case NString::NUCD::e_ScriptType_Latf:
      value = 60;
      break;
    case NString::NUCD::e_ScriptType_Latg:
      value = 61;
      break;
    case NString::NUCD::e_ScriptType_Latn:
      value = 62;
      break;
    case NString::NUCD::e_ScriptType_Lepc:
      value = 63;
      break;
    case NString::NUCD::e_ScriptType_Limb:
      value = 64;
      break;
    case NString::NUCD::e_ScriptType_Lina:
      value = 65;
      break;
    case NString::NUCD::e_ScriptType_Linb:
      value = 66;
      break;
    case NString::NUCD::e_ScriptType_Lisu:
      value = 67;
      break;
    case NString::NUCD::e_ScriptType_Lyci:
      value = 68;
      break;
    case NString::NUCD::e_ScriptType_Lydi:
      value = 69;
      break;
    case NString::NUCD::e_ScriptType_Mand:
      value = 70;
      break;
    case NString::NUCD::e_ScriptType_Mani:
      value = 71;
      break;
    case NString::NUCD::e_ScriptType_Maya:
      value = 72;
      break;
    case NString::NUCD::e_ScriptType_Mero:
      value = 73;
      break;
    case NString::NUCD::e_ScriptType_Mlym:
      value = 74;
      break;
    case NString::NUCD::e_ScriptType_Mong:
      value = 75;
      break;
    case NString::NUCD::e_ScriptType_Moon:
      value = 76;
      break;
    case NString::NUCD::e_ScriptType_Mtei:
      value = 77;
      break;
    case NString::NUCD::e_ScriptType_Mymr:
      value = 78;
      break;
    case NString::NUCD::e_ScriptType_Nkgb:
      value = 79;
      break;
    case NString::NUCD::e_ScriptType_Nkoo:
      value = 80;
      break;
    case NString::NUCD::e_ScriptType_Ogam:
      value = 81;
      break;
    case NString::NUCD::e_ScriptType_Olck:
      value = 82;
      break;
    case NString::NUCD::e_ScriptType_Orkh:
      value = 83;
      break;
    case NString::NUCD::e_ScriptType_Orya:
      value = 84;
      break;
    case NString::NUCD::e_ScriptType_Osma:
      value = 85;
      break;
    case NString::NUCD::e_ScriptType_Perm:
      value = 86;
      break;
    case NString::NUCD::e_ScriptType_Phag:
      value = 87;
      break;
    case NString::NUCD::e_ScriptType_Phli:
      value = 88;
      break;
    case NString::NUCD::e_ScriptType_Phlp:
      value = 89;
      break;
    case NString::NUCD::e_ScriptType_Phlv:
      value = 90;
      break;
    case NString::NUCD::e_ScriptType_Phnx:
      value = 91;
      break;
    case NString::NUCD::e_ScriptType_Plrd:
      value = 92;
      break;
    case NString::NUCD::e_ScriptType_Prti:
      value = 93;
      break;
    case NString::NUCD::e_ScriptType_Qaaa:
      value = 94;
      break;
    case NString::NUCD::e_ScriptType_Qabx:
      value = 95;
      break;
    case NString::NUCD::e_ScriptType_Rjng:
      value = 96;
      break;
    case NString::NUCD::e_ScriptType_Roro:
      value = 97;
      break;
    case NString::NUCD::e_ScriptType_Runr:
      value = 98;
      break;
    case NString::NUCD::e_ScriptType_Samr:
      value = 99;
      break;
    case NString::NUCD::e_ScriptType_Sara:
      value = 100;
      break;
    case NString::NUCD::e_ScriptType_Sarb:
      value = 101;
      break;
    case NString::NUCD::e_ScriptType_Saur:
      value = 102;
      break;
    case NString::NUCD::e_ScriptType_Sgnw:
      value = 103;
      break;
    case NString::NUCD::e_ScriptType_Shaw:
      value = 104;
      break;
    case NString::NUCD::e_ScriptType_Sinh:
      value = 105;
      break;
    case NString::NUCD::e_ScriptType_Sund:
      value = 106;
      break;
    case NString::NUCD::e_ScriptType_Sylo:
      value = 107;
      break;
    case NString::NUCD::e_ScriptType_Syrc:
      value = 108;
      break;
    case NString::NUCD::e_ScriptType_Syre:
      value = 109;
      break;
    case NString::NUCD::e_ScriptType_Syrj:
      value = 110;
      break;
    case NString::NUCD::e_ScriptType_Syrn:
      value = 111;
      break;
    case NString::NUCD::e_ScriptType_Tagb:
      value = 112;
      break;
    case NString::NUCD::e_ScriptType_Taml:
      value = 113;
      break;
    case NString::NUCD::e_ScriptType_Tale:
      value = 114;
      break;
    case NString::NUCD::e_ScriptType_Talu:
      value = 115;
      break;
    case NString::NUCD::e_ScriptType_Tavt:
      value = 116;
      break;
    case NString::NUCD::e_ScriptType_Telu:
      value = 117;
      break;
    case NString::NUCD::e_ScriptType_Teng:
      value = 118;
      break;
    case NString::NUCD::e_ScriptType_Tfng:
      value = 119;
      break;
    case NString::NUCD::e_ScriptType_Tglg:
      value = 120;
      break;
    case NString::NUCD::e_ScriptType_Thaa:
      value = 121;
      break;
    case NString::NUCD::e_ScriptType_Thai:
      value = 122;
      break;
    case NString::NUCD::e_ScriptType_Tibt:
      value = 123;
      break;
    case NString::NUCD::e_ScriptType_Ugar:
      value = 124;
      break;
    case NString::NUCD::e_ScriptType_Vaii:
      value = 125;
      break;
    case NString::NUCD::e_ScriptType_Visp:
      value = 126;
      break;
    case NString::NUCD::e_ScriptType_Xpeo:
      value = 127;
      break;
    case NString::NUCD::e_ScriptType_Xsux:
      value = 128;
      break;
    case NString::NUCD::e_ScriptType_Yiii:
      value = 129;
      break;
    case NString::NUCD::e_ScriptType_Zinh:
      value = 130;
      break;
    case NString::NUCD::e_ScriptType_Zmth:
      value = 131;
      break;
    case NString::NUCD::e_ScriptType_Zsym:
      value = 132;
      break;
    case NString::NUCD::e_ScriptType_Zxxx:
      value = 133;
      break;
    case NString::NUCD::e_ScriptType_Zyyy:
      value = 134;
      break;
    case NString::NUCD::e_ScriptType_Zzzz:
      value = 135;
      break;
    default:
      WARNING(STR("Cannot save invalid EScriptType value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NUCD::EScriptType")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EScriptType& a_rInstance)
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
