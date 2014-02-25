/*!
 *  \file    UCDParser-ScriptType.cpp Unicode characters database parser
 *           is used to parse UCD and create character properties tables for
 *           internal usage. Script.txt parser.
 *  \brief   Unicode characters database parser. Script.txt parser (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode characters database parser. Script.txt parser (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      UCD parser utility
    VERSION:   1.0
    CREATED:   04.05.2009 22:56:44

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
#ifndef __UCDPARSER_SCRIPTTYPE_INL__
#define __UCDPARSER_SCRIPTTYPE_INL__
/*==========================================================================*/
Tbool UCDParser::parseScriptType(CStreamStdOutput& a_crOutputStream)
{ CALL
  // Open Scripts.txt file.
  CFile file_Scripts(STR("Scripts.txt"));
  CHECK(file_Scripts.open(NStream::IStream::e_OPEN_READ));

  a_crOutputStream << STR("Parsing Scripts.txt file...") << ln;

  // Create the character delimiters tokenizer.
  CTokenizer tokenizer(file_Scripts.getItRead<Tschar>(), CTokenizerFunctionUCDParser());

  // Iterate through all tokens.
  Tbool error = false;
  CTokenizer::TIterator it = tokenizer.getItTop();
  while (it.isValid() && !error)
  {
    // Parse Unicode character code.
    Tuint index1 = 0;
    Tuint index2 = 0;
    if (!it->isEmpty())
    {
      a_crOutputStream << STR("Parsing Unicode character \"") << *it << STR("\"...") << ln;

      CStringASCII codes(*it);
      if (codes.getSize() < 8)
      {
        // Parse the single character code.
        CStringASCII code(codes);
        if (!code.insertFirst(ASC("0x")))
          error = true;
        index1 = toUnsigned(code);
        index2 = index1;
      }
      else
      {
        // Parse codes of the characters set.
        Tuint index = 0;
        for (; index <= codes.getSize(); ++index)
        {
          if (codes[index] == ASC('.'))
            break;
        }

        CStringASCII code1((index == codes.getSize()) ? codes : codes.getLeft(index));
        CStringASCII code2((index == codes.getSize()) ? codes : codes.getRight(codes.getSize() - index - 2));

        if (!code1.insertFirst(ASC("0x")) || !code2.insertFirst(ASC("0x")))
          error = true;
        index1 = toUnsigned(code1);
        index2 = toUnsigned(code2);
      }
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse Script Type value.
    EScriptType script_type = e_ScriptType_Zzzz;
    if (!it->isEmpty())
    {
      Tbool found = false;

      if ((CString::compareIgnoreCase(*it, STR("Arab")) == 0) || (CString::compareIgnoreCase(*it, STR("Arabic")) == 0))
      {
        script_type = e_ScriptType_Arab;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Armi")) == 0) || (CString::compareIgnoreCase(*it, STR("Imperial_Aramaic")) == 0))
      {
        script_type = e_ScriptType_Armi;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Armn")) == 0) || (CString::compareIgnoreCase(*it, STR("Armenian")) == 0))
      {
        script_type = e_ScriptType_Armn;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Avst")) == 0) || (CString::compareIgnoreCase(*it, STR("Avestan")) == 0))
      {
        script_type = e_ScriptType_Avst;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Bali")) == 0) || (CString::compareIgnoreCase(*it, STR("Balinese")) == 0))
      {
        script_type = e_ScriptType_Bali;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Bamu")) == 0) || (CString::compareIgnoreCase(*it, STR("Bamum")) == 0))
      {
        script_type = e_ScriptType_Bamu;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Batk")) == 0) || (CString::compareIgnoreCase(*it, STR("Batak")) == 0))
      {
        script_type = e_ScriptType_Batk;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Beng")) == 0) || (CString::compareIgnoreCase(*it, STR("Bengali")) == 0))
      {
        script_type = e_ScriptType_Beng;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Blis")) == 0) || (CString::compareIgnoreCase(*it, STR("Blissymbols")) == 0))
      {
        script_type = e_ScriptType_Blis;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Bopo")) == 0) || (CString::compareIgnoreCase(*it, STR("Bopomofo")) == 0))
      {
        script_type = e_ScriptType_Bopo;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Brah")) == 0) || (CString::compareIgnoreCase(*it, STR("Brahmi")) == 0))
      {
        script_type = e_ScriptType_Brah;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Brai")) == 0) || (CString::compareIgnoreCase(*it, STR("Braille")) == 0))
      {
        script_type = e_ScriptType_Brai;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Bugi")) == 0) || (CString::compareIgnoreCase(*it, STR("Buginese")) == 0))
      {
        script_type = e_ScriptType_Bugi;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Buhd")) == 0) || (CString::compareIgnoreCase(*it, STR("Buhid")) == 0))
      {
        script_type = e_ScriptType_Buhd;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Cakm")) == 0) || (CString::compareIgnoreCase(*it, STR("Chakma")) == 0))
      {
        script_type = e_ScriptType_Cakm;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Cans")) == 0) || (CString::compareIgnoreCase(*it, STR("Canadian_Aboriginal")) == 0))
      {
        script_type = e_ScriptType_Cans;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Cari")) == 0) || (CString::compareIgnoreCase(*it, STR("Carian")) == 0))
      {
        script_type = e_ScriptType_Cari;
        found = true;
      }
      if (CString::compareIgnoreCase(*it, STR("Cham")) == 0)
      {
        script_type = e_ScriptType_Cham;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Cher")) == 0) || (CString::compareIgnoreCase(*it, STR("Cherokee")) == 0))
      {
        script_type = e_ScriptType_Cher;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Cirt")) == 0) || (CString::compareIgnoreCase(*it, STR("Cirth")) == 0))
      {
        script_type = e_ScriptType_Cirt;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Copt")) == 0) || (CString::compareIgnoreCase(*it, STR("Coptic")) == 0) || (CString::compareIgnoreCase(*it, STR("Qaac")) == 0))
      {
        script_type = e_ScriptType_Copt;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Cprt")) == 0) || (CString::compareIgnoreCase(*it, STR("Cypriot")) == 0))
      {
        script_type = e_ScriptType_Cprt;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Cyrl")) == 0) || (CString::compareIgnoreCase(*it, STR("Cyrillic")) == 0))
      {
        script_type = e_ScriptType_Cyrl;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Cyrs")) == 0) || (CString::compareIgnoreCase(*it, STR("Old_Cyrillic")) == 0))
      {
        script_type = e_ScriptType_Cyrs;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Deva")) == 0) || (CString::compareIgnoreCase(*it, STR("Devanagari")) == 0))
      {
        script_type = e_ScriptType_Deva;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Dsrt")) == 0) || (CString::compareIgnoreCase(*it, STR("Deseret")) == 0))
      {
        script_type = e_ScriptType_Dsrt;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Egyd")) == 0) || (CString::compareIgnoreCase(*it, STR("Egyptian_Demotic")) == 0))
      {
        script_type = e_ScriptType_Egyd;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Egyh")) == 0) || (CString::compareIgnoreCase(*it, STR("Egyptian_Hieratic")) == 0))
      {
        script_type = e_ScriptType_Egyh;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Egyp")) == 0) || (CString::compareIgnoreCase(*it, STR("Egyptian_Hieroglyphs")) == 0))
      {
        script_type = e_ScriptType_Egyp;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Ethi")) == 0) || (CString::compareIgnoreCase(*it, STR("Ethiopic")) == 0))
      {
        script_type = e_ScriptType_Ethi;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Geok")) == 0) || (CString::compareIgnoreCase(*it, STR("Khutsuri")) == 0))
      {
        script_type = e_ScriptType_Geok;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Geor")) == 0) || (CString::compareIgnoreCase(*it, STR("Georgian")) == 0))
      {
        script_type = e_ScriptType_Geor;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Glag")) == 0) || (CString::compareIgnoreCase(*it, STR("Glagolitic")) == 0))
      {
        script_type = e_ScriptType_Glag;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Goth")) == 0) || (CString::compareIgnoreCase(*it, STR("Gothic")) == 0))
      {
        script_type = e_ScriptType_Goth;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Grek")) == 0) || (CString::compareIgnoreCase(*it, STR("Greek")) == 0))
      {
        script_type = e_ScriptType_Grek;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Gujr")) == 0) || (CString::compareIgnoreCase(*it, STR("Gujarati")) == 0))
      {
        script_type = e_ScriptType_Gujr;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Guru")) == 0) || (CString::compareIgnoreCase(*it, STR("Gurmukhi")) == 0))
      {
        script_type = e_ScriptType_Guru;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Hang")) == 0) || (CString::compareIgnoreCase(*it, STR("Hangul")) == 0))
      {
        script_type = e_ScriptType_Hang;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Hani")) == 0) || (CString::compareIgnoreCase(*it, STR("Han")) == 0))
      {
        script_type = e_ScriptType_Hani;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Hans")) == 0) || (CString::compareIgnoreCase(*it, STR("Han_Simplified")) == 0))
      {
        script_type = e_ScriptType_Hans;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Hant")) == 0) || (CString::compareIgnoreCase(*it, STR("Han_Traditional")) == 0))
      {
        script_type = e_ScriptType_Hant;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Hano")) == 0) || (CString::compareIgnoreCase(*it, STR("Hanunoo")) == 0))
      {
        script_type = e_ScriptType_Hano;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Hebr")) == 0) || (CString::compareIgnoreCase(*it, STR("Hebrew")) == 0))
      {
        script_type = e_ScriptType_Hebr;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Hira")) == 0) || (CString::compareIgnoreCase(*it, STR("Hiragana")) == 0))
      {
        script_type = e_ScriptType_Hira;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Hmng")) == 0) || (CString::compareIgnoreCase(*it, STR("Pahawh_Hmong")) == 0))
      {
        script_type = e_ScriptType_Hmng;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Hrkt")) == 0) || (CString::compareIgnoreCase(*it, STR("Katakana_Or_Hiragana")) == 0))
      {
        script_type = e_ScriptType_Hrkt;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Hung")) == 0) || (CString::compareIgnoreCase(*it, STR("Old_Hungarian")) == 0))
      {
        script_type = e_ScriptType_Hung;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Inds")) == 0) || (CString::compareIgnoreCase(*it, STR("Indus")) == 0))
      {
        script_type = e_ScriptType_Inds;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Ital")) == 0) || (CString::compareIgnoreCase(*it, STR("Old_Italic")) == 0))
      {
        script_type = e_ScriptType_Ital;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Java")) == 0) || (CString::compareIgnoreCase(*it, STR("Javanese")) == 0))
      {
        script_type = e_ScriptType_Java;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Jpan")) == 0) || (CString::compareIgnoreCase(*it, STR("Japanese")) == 0))
      {
        script_type = e_ScriptType_Jpan;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Kali")) == 0) || (CString::compareIgnoreCase(*it, STR("Kayah_Li")) == 0))
      {
        script_type = e_ScriptType_Kali;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Kana")) == 0) || (CString::compareIgnoreCase(*it, STR("Katakana")) == 0))
      {
        script_type = e_ScriptType_Kana;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Khar")) == 0) || (CString::compareIgnoreCase(*it, STR("Kharoshthi")) == 0))
      {
        script_type = e_ScriptType_Khar;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Khmr")) == 0) || (CString::compareIgnoreCase(*it, STR("Khmer")) == 0))
      {
        script_type = e_ScriptType_Khmr;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Knda")) == 0) || (CString::compareIgnoreCase(*it, STR("Kannada")) == 0))
      {
        script_type = e_ScriptType_Knda;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Kore")) == 0) || (CString::compareIgnoreCase(*it, STR("Korean")) == 0))
      {
        script_type = e_ScriptType_Kore;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Kthi")) == 0) || (CString::compareIgnoreCase(*it, STR("Kaithi")) == 0))
      {
        script_type = e_ScriptType_Kthi;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Lana")) == 0) || (CString::compareIgnoreCase(*it, STR("Tai_Tham")) == 0))
      {
        script_type = e_ScriptType_Lana;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Laoo")) == 0) || (CString::compareIgnoreCase(*it, STR("Lao")) == 0))
      {
        script_type = e_ScriptType_Laoo;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Latf")) == 0) || (CString::compareIgnoreCase(*it, STR("Latin_Fraktur")) == 0))
      {
        script_type = e_ScriptType_Latf;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Latg")) == 0) || (CString::compareIgnoreCase(*it, STR("Latin_Gaelic")) == 0))
      {
        script_type = e_ScriptType_Latg;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Latn")) == 0) || (CString::compareIgnoreCase(*it, STR("Latin")) == 0))
      {
        script_type = e_ScriptType_Latn;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Lepc")) == 0) || (CString::compareIgnoreCase(*it, STR("Lepcha")) == 0))
      {
        script_type = e_ScriptType_Lepc;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Limb")) == 0) || (CString::compareIgnoreCase(*it, STR("Limbu")) == 0))
      {
        script_type = e_ScriptType_Limb;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Lina")) == 0) || (CString::compareIgnoreCase(*it, STR("Linear_A")) == 0))
      {
        script_type = e_ScriptType_Lina;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Linb")) == 0) || (CString::compareIgnoreCase(*it, STR("Linear_B")) == 0))
      {
        script_type = e_ScriptType_Linb;
        found = true;
      }
      if (CString::compareIgnoreCase(*it, STR("Lisu")) == 0)
      {
        script_type = e_ScriptType_Lisu;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Lyci")) == 0) || (CString::compareIgnoreCase(*it, STR("Lycian")) == 0))
      {
        script_type = e_ScriptType_Lyci;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Lydi")) == 0) || (CString::compareIgnoreCase(*it, STR("Lydian")) == 0))
      {
        script_type = e_ScriptType_Lydi;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Mand")) == 0) || (CString::compareIgnoreCase(*it, STR("Mandaic")) == 0))
      {
        script_type = e_ScriptType_Mand;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Mani")) == 0) || (CString::compareIgnoreCase(*it, STR("Manichaean")) == 0))
      {
        script_type = e_ScriptType_Mani;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Maya")) == 0) || (CString::compareIgnoreCase(*it, STR("Mayan")) == 0))
      {
        script_type = e_ScriptType_Maya;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Mero")) == 0) || (CString::compareIgnoreCase(*it, STR("Meroitic")) == 0))
      {
        script_type = e_ScriptType_Mero;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Mlym")) == 0) || (CString::compareIgnoreCase(*it, STR("Malayalam")) == 0))
      {
        script_type = e_ScriptType_Mlym;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Mong")) == 0) || (CString::compareIgnoreCase(*it, STR("Mongolian")) == 0))
      {
        script_type = e_ScriptType_Mong;
        found = true;
      }
      if (CString::compareIgnoreCase(*it, STR("Moon")) == 0)
      {
        script_type = e_ScriptType_Moon;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Mtei")) == 0) || (CString::compareIgnoreCase(*it, STR("Meetei_Mayek")) == 0))
      {
        script_type = e_ScriptType_Mtei;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Mymr")) == 0) || (CString::compareIgnoreCase(*it, STR("Myanmar")) == 0))
      {
        script_type = e_ScriptType_Mymr;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Nkgb")) == 0) || (CString::compareIgnoreCase(*it, STR("Nakhi_Geba")) == 0))
      {
        script_type = e_ScriptType_Nkgb;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Nkoo")) == 0) || (CString::compareIgnoreCase(*it, STR("Nko")) == 0))
      {
        script_type = e_ScriptType_Nkoo;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Ogam")) == 0) || (CString::compareIgnoreCase(*it, STR("Ogham")) == 0))
      {
        script_type = e_ScriptType_Ogam;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Olck")) == 0) || (CString::compareIgnoreCase(*it, STR("Ol_Chiki")) == 0))
      {
        script_type = e_ScriptType_Olck;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Orkh")) == 0) || (CString::compareIgnoreCase(*it, STR("Old_Turkic")) == 0))
      {
        script_type = e_ScriptType_Orkh;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Orya")) == 0) || (CString::compareIgnoreCase(*it, STR("Oriya")) == 0))
      {
        script_type = e_ScriptType_Orya;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Osma")) == 0) || (CString::compareIgnoreCase(*it, STR("Osmanya")) == 0))
      {
        script_type = e_ScriptType_Osma;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Phag")) == 0) || (CString::compareIgnoreCase(*it, STR("Phags_Pa")) == 0))
      {
        script_type = e_ScriptType_Phag;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Phli")) == 0) || (CString::compareIgnoreCase(*it, STR("Inscriptional_Pahlavi")) == 0))
      {
        script_type = e_ScriptType_Phli;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Phlp")) == 0) || (CString::compareIgnoreCase(*it, STR("Psalter_Pahlavi")) == 0))
      {
        script_type = e_ScriptType_Phlp;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Phlv")) == 0) || (CString::compareIgnoreCase(*it, STR("Book_Pahlavi")) == 0))
      {
        script_type = e_ScriptType_Phlv;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Plrd")) == 0) || (CString::compareIgnoreCase(*it, STR("Miao_Pollard")) == 0))
      {
        script_type = e_ScriptType_Plrd;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Prti")) == 0) || (CString::compareIgnoreCase(*it, STR("Inscriptional_Parthian")) == 0))
      {
        script_type = e_ScriptType_Prti;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Phnx")) == 0) || (CString::compareIgnoreCase(*it, STR("Phoenician")) == 0))
      {
        script_type = e_ScriptType_Phnx;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Qaaa")) == 0) || (CString::compareIgnoreCase(*it, STR("Reserved_Start")) == 0))
      {
        script_type = e_ScriptType_Qaaa;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Qabx")) == 0) || (CString::compareIgnoreCase(*it, STR("Reserved_End")) == 0))
      {
        script_type = e_ScriptType_Qabx;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Rjng")) == 0) || (CString::compareIgnoreCase(*it, STR("Rejang")) == 0))
      {
        script_type = e_ScriptType_Rjng;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Roro")) == 0) || (CString::compareIgnoreCase(*it, STR("Rongorongo")) == 0))
      {
        script_type = e_ScriptType_Roro;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Runr")) == 0) || (CString::compareIgnoreCase(*it, STR("Runic")) == 0))
      {
        script_type = e_ScriptType_Runr;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Samr")) == 0) || (CString::compareIgnoreCase(*it, STR("Samaritan")) == 0))
      {
        script_type = e_ScriptType_Samr;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Sara")) == 0) || (CString::compareIgnoreCase(*it, STR("Sarati")) == 0))
      {
        script_type = e_ScriptType_Sara;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Sarb")) == 0) || (CString::compareIgnoreCase(*it, STR("Old_South_Arabian")) == 0))
      {
        script_type = e_ScriptType_Sarb;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Saur")) == 0) || (CString::compareIgnoreCase(*it, STR("Saurashtra")) == 0))
      {
        script_type = e_ScriptType_Saur;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Sgnw")) == 0) || (CString::compareIgnoreCase(*it, STR("SignWriting")) == 0))
      {
        script_type = e_ScriptType_Sgnw;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Shaw")) == 0) || (CString::compareIgnoreCase(*it, STR("Shavian")) == 0))
      {
        script_type = e_ScriptType_Shaw;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Sinh")) == 0) || (CString::compareIgnoreCase(*it, STR("Sinhala")) == 0))
      {
        script_type = e_ScriptType_Sinh;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Sund")) == 0) || (CString::compareIgnoreCase(*it, STR("Sundanese")) == 0))
      {
        script_type = e_ScriptType_Sund;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Sylo")) == 0) || (CString::compareIgnoreCase(*it, STR("Syloti_Nagri")) == 0))
      {
        script_type = e_ScriptType_Sylo;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Syrc")) == 0) || (CString::compareIgnoreCase(*it, STR("Syriac")) == 0))
      {
        script_type = e_ScriptType_Syrc;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Syre")) == 0) || (CString::compareIgnoreCase(*it, STR("Syriac_Estrangelo")) == 0))
      {
        script_type = e_ScriptType_Syre;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Syrj")) == 0) || (CString::compareIgnoreCase(*it, STR("Syriac_Western")) == 0))
      {
        script_type = e_ScriptType_Syrj;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Syrn")) == 0) || (CString::compareIgnoreCase(*it, STR("Syriac_Eastern")) == 0))
      {
        script_type = e_ScriptType_Syrn;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Tagb")) == 0) || (CString::compareIgnoreCase(*it, STR("Tagbanwa")) == 0))
      {
        script_type = e_ScriptType_Tagb;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Taml")) == 0) || (CString::compareIgnoreCase(*it, STR("Tamil")) == 0))
      {
        script_type = e_ScriptType_Taml;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Tale")) == 0) || (CString::compareIgnoreCase(*it, STR("Tai_Le")) == 0))
      {
        script_type = e_ScriptType_Tale;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Talu")) == 0) || (CString::compareIgnoreCase(*it, STR("New_Tai_Lue")) == 0))
      {
        script_type = e_ScriptType_Talu;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Tavt")) == 0) || (CString::compareIgnoreCase(*it, STR("Tai_Viet")) == 0))
      {
        script_type = e_ScriptType_Tavt;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Telu")) == 0) || (CString::compareIgnoreCase(*it, STR("Telugu")) == 0))
      {
        script_type = e_ScriptType_Telu;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Teng")) == 0) || (CString::compareIgnoreCase(*it, STR("Tengwar")) == 0))
      {
        script_type = e_ScriptType_Teng;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Tfng")) == 0) || (CString::compareIgnoreCase(*it, STR("Tifinagh")) == 0))
      {
        script_type = e_ScriptType_Tfng;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Tglg")) == 0) || (CString::compareIgnoreCase(*it, STR("Tagalog")) == 0))
      {
        script_type = e_ScriptType_Tglg;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Thaa")) == 0) || (CString::compareIgnoreCase(*it, STR("Thaana")) == 0))
      {
        script_type = e_ScriptType_Thaa;
        found = true;
      }
      if (CString::compareIgnoreCase(*it, STR("Thai")) == 0)
      {
        script_type = e_ScriptType_Thai;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Tibt")) == 0) || (CString::compareIgnoreCase(*it, STR("Tibetan")) == 0))
      {
        script_type = e_ScriptType_Tibt;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Ugar")) == 0) || (CString::compareIgnoreCase(*it, STR("Ugaritic")) == 0))
      {
        script_type = e_ScriptType_Ugar;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Vaii")) == 0) || (CString::compareIgnoreCase(*it, STR("Vai")) == 0))
      {
        script_type = e_ScriptType_Vaii;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Visp")) == 0) || (CString::compareIgnoreCase(*it, STR("Visible_Speech")) == 0))
      {
        script_type = e_ScriptType_Visp;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Xpeo")) == 0) || (CString::compareIgnoreCase(*it, STR("Old_Persian")) == 0))
      {
        script_type = e_ScriptType_Xpeo;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Xsux")) == 0) || (CString::compareIgnoreCase(*it, STR("Cuneiform")) == 0))
      {
        script_type = e_ScriptType_Xsux;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Yiii")) == 0) || (CString::compareIgnoreCase(*it, STR("Yi")) == 0))
      {
        script_type = e_ScriptType_Yiii;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Zinh")) == 0) || (CString::compareIgnoreCase(*it, STR("Inherited")) == 0))
      {
        script_type = e_ScriptType_Zinh;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Zmth")) == 0) || (CString::compareIgnoreCase(*it, STR("Mathematical")) == 0))
      {
        script_type = e_ScriptType_Zmth;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Zsym")) == 0) || (CString::compareIgnoreCase(*it, STR("Symbols")) == 0))
      {
        script_type = e_ScriptType_Zsym;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Zxxx")) == 0) || (CString::compareIgnoreCase(*it, STR("Unwritten")) == 0))
      {
        script_type = e_ScriptType_Zxxx;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Zyyy")) == 0) || (CString::compareIgnoreCase(*it, STR("Common")) == 0))
      {
        script_type = e_ScriptType_Zyyy;
        found = true;
      }
      if ((CString::compareIgnoreCase(*it, STR("Zzzz")) == 0) || (CString::compareIgnoreCase(*it, STR("Unknown")) == 0))
      {
        script_type = e_ScriptType_Zzzz;
        found = true;
      }

      // Check if provided script type was not found.
      if (!found)
      {
        ASSERT(false, STR("Unsupported Script Type was met - \"%X\").") COMMA &(*it)) error = true;
      }
    }

    // Update Script Type of all characters in the set...
    for (Tuint index = index1; index <= index2; ++index)
    {
      CSparseArray<SUnicodeCharacterProperties>::TIterator it_prop = the_UnicodeCharacterDatabase.getItIndex(index);
      if (it_prop.isValid())
      {
        SUnicodeCharacterProperties& prop = it_prop.getValueRef();
        prop.m_ScriptType = script_type;
      }
    }

    // Try to get new token.
    if (it.stepForward() == 0)
      break;
  }

  if (error)
    a_crOutputStream << STR("Cannot parse Scripts.txt file.") << ln;
  else
    a_crOutputStream << STR("Scripts.txt file successfully parsed.") << ln;

  // Close Scripts.txt file.
  CHECK(file_Scripts.close());

  return !error;
}
/*==========================================================================*/
#endif
