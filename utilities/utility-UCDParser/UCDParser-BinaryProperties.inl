/*!
 *  \file    UCDParser-BinaryProperties.cpp Unicode characters database parser
 *           is used to parse UCD and create character properties tables for
 *           internal usage. PropList.txt & DerivedCoreProperties.txt parser.
 *  \brief   Unicode characters database parser. PropList.txt & DerivedCoreProperties.txt parser (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode characters database parser. PropList.txt & DerivedCoreProperties.txt parser (source).

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
#ifndef __UCDPARSER_BINARYPROPERTIES_INL__
#define __UCDPARSER_BINARYPROPERTIES_INL__
/*==========================================================================*/
Tbool UCDParser::parseBinaryProperties(CStreamStdOutput& a_crOutputStream, const Tcstr a_cpFileName)
{ CALL
  // Open Binary Properties file.
  CFile file_PropList(a_cpFileName);
  CHECK(file_PropList.open(NStream::IStream::e_OPEN_READ));

  a_crOutputStream << STR("Parsing ") << a_cpFileName << STR(" file...") << ln;

  // Create the character delimiters tokenizer.
  CTokenizer tokenizer(file_PropList.getItRead<Tschar>(), CTokenizerFunctionUCDParser());

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

    // Parse Unicode character binary properties.
    Tuint64 binary_property = 0;
    if (!it->isEmpty())
    {
      if ((CString::compareIgnoreCase(*it, STR("AHex")) == 0) || (CString::compareIgnoreCase(*it, STR("ASCII_Hex_Digit")) == 0))
        binary_property |= CBinaryProperties::AHex;
      else if ((CString::compareIgnoreCase(*it, STR("Alpha")) == 0) || (CString::compareIgnoreCase(*it, STR("Alphabetic")) == 0))
        binary_property |= CBinaryProperties::Alpha;
      else if ((CString::compareIgnoreCase(*it, STR("Bidi_C")) == 0) || (CString::compareIgnoreCase(*it, STR("Bidi_Control")) == 0))
        binary_property |= CBinaryProperties::Bidi_C;
      else if ((CString::compareIgnoreCase(*it, STR("Bidi_M")) == 0) || (CString::compareIgnoreCase(*it, STR("Bidi_Mirrored")) == 0))
        binary_property |= CBinaryProperties::Bidi_M;
      else if ((CString::compareIgnoreCase(*it, STR("Cased")) == 0) || (CString::compareIgnoreCase(*it, STR("Cased")) == 0))
        binary_property |= CBinaryProperties::Cased;
      else if ((CString::compareIgnoreCase(*it, STR("CaseIgnorable")) == 0) || (CString::compareIgnoreCase(*it, STR("Case_Ignorable")) == 0))
        binary_property |= CBinaryProperties::CaseIgnorable;
      else if ((CString::compareIgnoreCase(*it, STR("CWLower")) == 0) || (CString::compareIgnoreCase(*it, STR("Changes_When_Lowercased")) == 0))
        binary_property |= CBinaryProperties::CWLower;
      else if ((CString::compareIgnoreCase(*it, STR("CWUpper")) == 0) || (CString::compareIgnoreCase(*it, STR("Changes_When_Uppercased")) == 0))
        binary_property |= CBinaryProperties::CWUpper;
      else if ((CString::compareIgnoreCase(*it, STR("CWTitle")) == 0) || (CString::compareIgnoreCase(*it, STR("Changes_When_Titlecased")) == 0))
        binary_property |= CBinaryProperties::CWTitle;
      else if ((CString::compareIgnoreCase(*it, STR("CWCasefold")) == 0) || (CString::compareIgnoreCase(*it, STR("Changes_When_Casefolded")) == 0))
        binary_property |= CBinaryProperties::CWCasefold;
      else if ((CString::compareIgnoreCase(*it, STR("CWCasemap")) == 0) || (CString::compareIgnoreCase(*it, STR("Changes_When_Casemapped")) == 0))
        binary_property |= CBinaryProperties::CWCasemap;
      else if ((CString::compareIgnoreCase(*it, STR("Dash")) == 0) || (CString::compareIgnoreCase(*it, STR("Dash")) == 0))
        binary_property |= CBinaryProperties::Dash;
      else if ((CString::compareIgnoreCase(*it, STR("Dep")) == 0) || (CString::compareIgnoreCase(*it, STR("Deprecated")) == 0))
        binary_property |= CBinaryProperties::Dep;
      else if ((CString::compareIgnoreCase(*it, STR("DI")) == 0) || (CString::compareIgnoreCase(*it, STR("Default_Ignorable_Code_Point")) == 0))
        binary_property |= CBinaryProperties::DI;
      else if ((CString::compareIgnoreCase(*it, STR("Dia")) == 0) || (CString::compareIgnoreCase(*it, STR("Diacritic")) == 0))
        binary_property |= CBinaryProperties::Dia;
      else if ((CString::compareIgnoreCase(*it, STR("Ext")) == 0) || (CString::compareIgnoreCase(*it, STR("Extender")) == 0))
        binary_property |= CBinaryProperties::Ext;
      else if ((CString::compareIgnoreCase(*it, STR("Hex")) == 0) || (CString::compareIgnoreCase(*it, STR("Hex_Digit")) == 0))
        binary_property |= CBinaryProperties::Hex;
      else if ((CString::compareIgnoreCase(*it, STR("Hyphen")) == 0) || (CString::compareIgnoreCase(*it, STR("Hyphen")) == 0))
        binary_property |= CBinaryProperties::Hyphen;
      else if ((CString::compareIgnoreCase(*it, STR("Ideo")) == 0) || (CString::compareIgnoreCase(*it, STR("Ideographic")) == 0))
        binary_property |= CBinaryProperties::Ideo;
      else if ((CString::compareIgnoreCase(*it, STR("IDSB")) == 0) || (CString::compareIgnoreCase(*it, STR("IDS_Binary_Operator")) == 0))
        binary_property |= CBinaryProperties::IDSB;
      else if ((CString::compareIgnoreCase(*it, STR("IDST")) == 0) || (CString::compareIgnoreCase(*it, STR("IDS_Trinary_Operator")) == 0))
        binary_property |= CBinaryProperties::IDSB;
      else if ((CString::compareIgnoreCase(*it, STR("Join_C")) == 0) || (CString::compareIgnoreCase(*it, STR("Join_Control")) == 0))
        binary_property |= CBinaryProperties::Join_C;
      else if ((CString::compareIgnoreCase(*it, STR("LOE")) == 0) || (CString::compareIgnoreCase(*it, STR("Logical_Order_Exception")) == 0))
        binary_property |= CBinaryProperties::LOE;
      else if ((CString::compareIgnoreCase(*it, STR("Lower")) == 0) || (CString::compareIgnoreCase(*it, STR("Lowercase")) == 0))
        binary_property |= CBinaryProperties::Lower;
      else if ((CString::compareIgnoreCase(*it, STR("Math")) == 0) || (CString::compareIgnoreCase(*it, STR("Math")) == 0))
        binary_property |= CBinaryProperties::Math;
      else if ((CString::compareIgnoreCase(*it, STR("NChar")) == 0) || (CString::compareIgnoreCase(*it, STR("Noncharacter_Code_Point")) == 0))
        binary_property |= CBinaryProperties::NChar;
      else if ((CString::compareIgnoreCase(*it, STR("OAlpha")) == 0) || (CString::compareIgnoreCase(*it, STR("Other_Alphabetic")) == 0))
        binary_property |= CBinaryProperties::OAlpha;
      else if ((CString::compareIgnoreCase(*it, STR("ODI")) == 0) || (CString::compareIgnoreCase(*it, STR("Other_Default_Ignorable_Code_Point")) == 0))
        binary_property |= CBinaryProperties::ODI;
      else if ((CString::compareIgnoreCase(*it, STR("OGr_Ext")) == 0) || (CString::compareIgnoreCase(*it, STR("Other_Grapheme_Extend")) == 0))
        binary_property |= CBinaryProperties::OGr_Ext;
      else if ((CString::compareIgnoreCase(*it, STR("OIDC")) == 0) || (CString::compareIgnoreCase(*it, STR("Other_ID_Continue")) == 0))
        binary_property |= CBinaryProperties::OIDC;
      else if ((CString::compareIgnoreCase(*it, STR("OIDS")) == 0) || (CString::compareIgnoreCase(*it, STR("Other_ID_Start")) == 0))
        binary_property |= CBinaryProperties::OIDS;
      else if ((CString::compareIgnoreCase(*it, STR("OLower")) == 0) || (CString::compareIgnoreCase(*it, STR("Other_Lowercase")) == 0))
        binary_property |= CBinaryProperties::OLower;
      else if ((CString::compareIgnoreCase(*it, STR("OMath")) == 0) || (CString::compareIgnoreCase(*it, STR("Other_Math")) == 0))
        binary_property |= CBinaryProperties::OMath;
      else if ((CString::compareIgnoreCase(*it, STR("OUpper")) == 0) || (CString::compareIgnoreCase(*it, STR("Other_Uppercase")) == 0))
        binary_property |= CBinaryProperties::OUpper;
      else if ((CString::compareIgnoreCase(*it, STR("QMark")) == 0) || (CString::compareIgnoreCase(*it, STR("Quotation_Mark")) == 0))
        binary_property |= CBinaryProperties::QMark;
      else if ((CString::compareIgnoreCase(*it, STR("Radical")) == 0) || (CString::compareIgnoreCase(*it, STR("Radical")) == 0))
        binary_property |= CBinaryProperties::Radical;
      else if ((CString::compareIgnoreCase(*it, STR("SD")) == 0) || (CString::compareIgnoreCase(*it, STR("Soft_Dotted")) == 0))
        binary_property |= CBinaryProperties::SD;
      else if ((CString::compareIgnoreCase(*it, STR("Term")) == 0) || (CString::compareIgnoreCase(*it, STR("Terminal_Punctuation")) == 0))
        binary_property |= CBinaryProperties::Term;
      else if ((CString::compareIgnoreCase(*it, STR("UIdeo")) == 0) || (CString::compareIgnoreCase(*it, STR("Unified_Ideograph")) == 0))
        binary_property |= CBinaryProperties::UIdeo;
      else if ((CString::compareIgnoreCase(*it, STR("Upper")) == 0) || (CString::compareIgnoreCase(*it, STR("Uppercase")) == 0))
        binary_property |= CBinaryProperties::Upper;
      else if ((CString::compareIgnoreCase(*it, STR("VS")) == 0) || (CString::compareIgnoreCase(*it, STR("Variation_Selector")) == 0))
        binary_property |= CBinaryProperties::VS;
      else if ((CString::compareIgnoreCase(*it, STR("WSpace")) == 0) || (CString::compareIgnoreCase(*it, STR("White_Space")) == 0) || (CString::compareIgnoreCase(*it, STR("space")) == 0))
        binary_property |= CBinaryProperties::WSpace;
      else if ((CString::compareIgnoreCase(*it, STR("STerm")) == 0) || (CString::compareIgnoreCase(*it, STR("STerm")) == 0))
        binary_property |= CBinaryProperties::STerm;
      else if ((CString::compareIgnoreCase(*it, STR("Gr_Base")) == 0) || (CString::compareIgnoreCase(*it, STR("Grapheme_Base")) == 0))
        binary_property |= CBinaryProperties::Gr_Base;
      else if ((CString::compareIgnoreCase(*it, STR("Gr_Ext")) == 0) || (CString::compareIgnoreCase(*it, STR("Grapheme_Extend")) == 0))
        binary_property |= CBinaryProperties::Gr_Ext;
      else if ((CString::compareIgnoreCase(*it, STR("Gr_Link")) == 0) || (CString::compareIgnoreCase(*it, STR("Grapheme_Link")) == 0))
        binary_property |= CBinaryProperties::Gr_Link;
      else if ((CString::compareIgnoreCase(*it, STR("Pat_Syn")) == 0) || (CString::compareIgnoreCase(*it, STR("Pattern_Syntax")) == 0))
        binary_property |= CBinaryProperties::Pat_Syn;
      else if ((CString::compareIgnoreCase(*it, STR("Pat_WS")) == 0) || (CString::compareIgnoreCase(*it, STR("Pattern_White_Space")) == 0))
        binary_property |= CBinaryProperties::Pat_WS;
      else if ((CString::compareIgnoreCase(*it, STR("IDC")) == 0) || (CString::compareIgnoreCase(*it, STR("ID_Continue")) == 0))
        binary_property |= CBinaryProperties::IDC;
      else if ((CString::compareIgnoreCase(*it, STR("IDS")) == 0) || (CString::compareIgnoreCase(*it, STR("ID_Start")) == 0))
        binary_property |= CBinaryProperties::IDS;
      else if ((CString::compareIgnoreCase(*it, STR("XIDC")) == 0) || (CString::compareIgnoreCase(*it, STR("XID_Continue")) == 0))
        binary_property |= CBinaryProperties::XIDC;
      else if ((CString::compareIgnoreCase(*it, STR("XIDS")) == 0) || (CString::compareIgnoreCase(*it, STR("XID_Start")) == 0))
        binary_property |= CBinaryProperties::XIDS;
      else if ((CString::compareIgnoreCase(*it, STR("CE")) == 0) || (CString::compareIgnoreCase(*it, STR("Composition_Exclusion")) == 0))
        binary_property |= CBinaryProperties::CE;
      else if ((CString::compareIgnoreCase(*it, STR("Comp_Ex")) == 0) || (CString::compareIgnoreCase(*it, STR("Full_Composition_Exclusion")) == 0))
        binary_property |= CBinaryProperties::Comp_Ex;
      else if ((CString::compareIgnoreCase(*it, STR("XO_NFC")) == 0) || (CString::compareIgnoreCase(*it, STR("Expands_On_NFC")) == 0))
        binary_property |= CBinaryProperties::XO_NFC;
      else if ((CString::compareIgnoreCase(*it, STR("XO_NFD")) == 0) || (CString::compareIgnoreCase(*it, STR("Expands_On_NFD")) == 0))
        binary_property |= CBinaryProperties::XO_NFD;
      else if ((CString::compareIgnoreCase(*it, STR("XO_NFKC")) == 0) || (CString::compareIgnoreCase(*it, STR("Expands_On_NFKC")) == 0))
        binary_property |= CBinaryProperties::XO_NFKC;
      else if ((CString::compareIgnoreCase(*it, STR("XO_NFKD")) == 0) || (CString::compareIgnoreCase(*it, STR("Expands_On_NFKD")) == 0))
        binary_property |= CBinaryProperties::XO_NFKD;
      else
      {
        ASSERT(false, STR("Unsupported Binary Property was met - \"%X\").") COMMA &(*it)) error = true;
      }
    }


    // Update binary properties of all characters in the set...
    for (Tuint index = index1; index <= index2; ++index)
    {
      CSparseArray<SUnicodeCharacterProperties>::TIterator it_prop = the_UnicodeCharacterDatabase.getItIndex(index);
      if (it_prop.isValid())
      {
        SUnicodeCharacterProperties& prop = it_prop.getValueRef();

        prop.m_BinaryProperties |= binary_property;

        // Additional checks.
        if (prop.m_BidiMirrored)
          prop.m_BinaryProperties |= CBinaryProperties::Bidi_M;
      }
    }

    // Try to get new token.
    if (it.stepForward() == 0)
      break;
  }

  if (error)
    a_crOutputStream << STR("Cannot parse ") << a_cpFileName << STR(" file.") << ln;
  else
    a_crOutputStream << a_cpFileName << STR(" file successfully parsed.") << ln;

  // Close Binary Properties file.
  CHECK(file_PropList.close());

  return !error;
}
/*==========================================================================*/
#endif
