/*!
 *  \file    UCDParser-UnicodeData.cpp Unicode characters database parser is
 *           used to parse UCD and create character properties tables for
 *           internal usage. UnicodeData.txt parser.
 *  \brief   Unicode characters database parser. UnicodeData.txt parser (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode characters database parser. UnicodeData.txt parser (source).

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
#ifndef __UCDPARSER_UNICODEDATA_INL__
#define __UCDPARSER_UNICODEDATA_INL__
/*==========================================================================*/
Tbool UCDParser::parseUnicodeData(CStreamStdOutput& a_crOutputStream)
{ CALL
  // Open UnicodeData.txt file.
  CFile file_UnicodeData(STR("UnicodeData.txt"));
  CHECK(file_UnicodeData.open(NStream::IStream::e_OPEN_READ));

  a_crOutputStream << STR("Parsing UnicodeData.txt file...") << ln;

  // Create the character delimiters tokenizer.
  CTokenizer tokenizer(file_UnicodeData.getItRead<Tschar>(), CTokenizerFunctionUCDParser());

  // Iterate through all tokens.
  Tbool error = false;
  CTokenizer::TIterator it = tokenizer.getItTop();
  while (it.isValid() && !error)
  {
    SUnicodeCharacterProperties prop;

    // Parse Unicode character code.
    if (!it->isEmpty())
    {
      a_crOutputStream << STR("Parsing Unicode character \"") << *it << STR("\"...") << ln;

      CStringASCII code(*it);
      if (!code.insertFirst(ASC("0x")))
        error = true;
      prop.m_Code = (Tuint32)toUnsigned(code);
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse Unicode character name.
    if (!it->isEmpty())
    {
      CStringASCII name(*it);
      if (name.insertCEnd())
      {
        CStringBuffer<Tsstr>::TIterator it_name = find(the_CharacterNames, *it, FStringComparator<Tsstr, CStringASCII>());
        if (it_name.isValid())
          prop.m_NameID = (Tsint32)it_name.getPosition();
        else
        {
          if (!the_CharacterNames.insertLast(name))
            error = true;
          else
            prop.m_NameID = (Tsint32)(the_CharacterNames.getSize() - 1);
        }
      }
      else
        error = true;
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse General Category type.
    if (!it->isEmpty())
    {
      if (CString::compareIgnoreCase(*it, STR("Lu")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Lu;
      else if (CString::compareIgnoreCase(*it, STR("Ll")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Ll;
      else if (CString::compareIgnoreCase(*it, STR("Lt")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Lt;
      else if (CString::compareIgnoreCase(*it, STR("Lm")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Lm;
      else if (CString::compareIgnoreCase(*it, STR("Lo")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Lo;
      else if (CString::compareIgnoreCase(*it, STR("Mn")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Mn;
      else if (CString::compareIgnoreCase(*it, STR("Mc")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Mc;
      else if (CString::compareIgnoreCase(*it, STR("Me")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Me;
      else if (CString::compareIgnoreCase(*it, STR("Nd")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Nd;
      else if (CString::compareIgnoreCase(*it, STR("Nl")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Nl;
      else if (CString::compareIgnoreCase(*it, STR("No")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_No;
      else if (CString::compareIgnoreCase(*it, STR("Pc")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Pc;
      else if (CString::compareIgnoreCase(*it, STR("Pd")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Pd;
      else if (CString::compareIgnoreCase(*it, STR("Ps")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Ps;
      else if (CString::compareIgnoreCase(*it, STR("Pe")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Pe;
      else if (CString::compareIgnoreCase(*it, STR("Pi")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Pi;
      else if (CString::compareIgnoreCase(*it, STR("Pf")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Pf;
      else if (CString::compareIgnoreCase(*it, STR("Po")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Po;
      else if (CString::compareIgnoreCase(*it, STR("Sm")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Sm;
      else if (CString::compareIgnoreCase(*it, STR("Sc")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Sc;
      else if (CString::compareIgnoreCase(*it, STR("Sk")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Sk;
      else if (CString::compareIgnoreCase(*it, STR("So")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_So;
      else if (CString::compareIgnoreCase(*it, STR("Zs")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Zs;
      else if (CString::compareIgnoreCase(*it, STR("Zl")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Zl;
      else if (CString::compareIgnoreCase(*it, STR("Zp")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Zp;
      else if (CString::compareIgnoreCase(*it, STR("Cc")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Cc;
      else if (CString::compareIgnoreCase(*it, STR("Cf")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Cf;
      else if (CString::compareIgnoreCase(*it, STR("Cs")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Cs;
      else if (CString::compareIgnoreCase(*it, STR("Co")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Co;
      else if (CString::compareIgnoreCase(*it, STR("Cn")) == 0)
        prop.m_GeneralCategory = e_GeneralCategory_Cn;
      else
      {
        ASSERT(false, STR("Unsupported General Category type was met - \"%X\").") COMMA &(*it)) error = true;
      }
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse Canonical Combining class.
    if (!it->isEmpty())
    {
      prop.m_CanonicalCombiningClass = (Tuint08)toUnsigned(*it);
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse Bidi class.
    if (!it->isEmpty())
    {
      if (CString::compareIgnoreCase(*it, STR("L")) == 0)
        prop.m_BidiClass = e_BidiClass_L;
      else if (CString::compareIgnoreCase(*it, STR("LRE")) == 0)
        prop.m_BidiClass = e_BidiClass_LRE;
      else if (CString::compareIgnoreCase(*it, STR("LRO")) == 0)
        prop.m_BidiClass = e_BidiClass_LRO;
      else if (CString::compareIgnoreCase(*it, STR("R")) == 0)
        prop.m_BidiClass = e_BidiClass_R;
      else if (CString::compareIgnoreCase(*it, STR("AL")) == 0)
        prop.m_BidiClass = e_BidiClass_AL;
      else if (CString::compareIgnoreCase(*it, STR("RLE")) == 0)
        prop.m_BidiClass = e_BidiClass_RLE;
      else if (CString::compareIgnoreCase(*it, STR("RLO")) == 0)
        prop.m_BidiClass = e_BidiClass_RLO;
      else if (CString::compareIgnoreCase(*it, STR("PDF")) == 0)
        prop.m_BidiClass = e_BidiClass_PDF;
      else if (CString::compareIgnoreCase(*it, STR("EN")) == 0)
        prop.m_BidiClass = e_BidiClass_EN;
      else if (CString::compareIgnoreCase(*it, STR("ES")) == 0)
        prop.m_BidiClass = e_BidiClass_ES;
      else if (CString::compareIgnoreCase(*it, STR("ET")) == 0)
        prop.m_BidiClass = e_BidiClass_ET;
      else if (CString::compareIgnoreCase(*it, STR("AN")) == 0)
        prop.m_BidiClass = e_BidiClass_AN;
      else if (CString::compareIgnoreCase(*it, STR("CS")) == 0)
        prop.m_BidiClass = e_BidiClass_CS;
      else if (CString::compareIgnoreCase(*it, STR("NSM")) == 0)
        prop.m_BidiClass = e_BidiClass_NSM;
      else if (CString::compareIgnoreCase(*it, STR("BN")) == 0)
        prop.m_BidiClass = e_BidiClass_BN;
      else if (CString::compareIgnoreCase(*it, STR("B")) == 0)
        prop.m_BidiClass = e_BidiClass_B;
      else if (CString::compareIgnoreCase(*it, STR("S")) == 0)
        prop.m_BidiClass = e_BidiClass_S;
      else if (CString::compareIgnoreCase(*it, STR("WS")) == 0)
        prop.m_BidiClass = e_BidiClass_WS;
      else if (CString::compareIgnoreCase(*it, STR("ON")) == 0)
        prop.m_BidiClass = e_BidiClass_ON;
      else
      {
        ASSERT(false, STR("Unsupported Bidirectional Behavior class was met - \"%X\").") COMMA &(*it)) error = true;
      }
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse Decomposition Type Mapping value.
    EDecompositionMapping decomposition_mapping_type(e_DecompositionMapping_None);
    Tsint32 decomposition_mapping[18] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    if (!it->isEmpty())
    {
      Tuint count = 0;
      Tuint index = 0;
      Tuint item = 0;
      Tbool end_with_error = false;
      while (!end_with_error)
      {
        // Parse the single Decomposition Type Mapping value.
        CStringASCII value;
        while ((index < it->getSize()) && ((*it)[index] != STR(' ')))
        {
          if (!value.insertLast((Tschar)((*it)[index++])))
          {
            end_with_error = true;
            break;
          }
        }

        // If the single Decomposition Type Mapping value was successfully parsed...
        if (!end_with_error && !value.isEmpty())
        {
          if (value[CONSTU(0)] == ASC('<'))
          {
            if (CString::compareIgnoreCase(value, ASC("<canonical>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Canonical;
            else if (CString::compareIgnoreCase(value, ASC("<font>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Font;
            else if (CString::compareIgnoreCase(value, ASC("<noBreak>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_NoBreak;
            else if (CString::compareIgnoreCase(value, ASC("<initial>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Initial;
            else if (CString::compareIgnoreCase(value, ASC("<medial>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Medial;
            else if (CString::compareIgnoreCase(value, ASC("<final>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Final;
            else if (CString::compareIgnoreCase(value, ASC("<isolated>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Isolated;
            else if (CString::compareIgnoreCase(value, ASC("<circle>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Circle;
            else if (CString::compareIgnoreCase(value, ASC("<super>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Super;
            else if (CString::compareIgnoreCase(value, ASC("<sub>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Sub;
            else if (CString::compareIgnoreCase(value, ASC("<vertical>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Vertical;
            else if (CString::compareIgnoreCase(value, ASC("<wide>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Wide;
            else if (CString::compareIgnoreCase(value, ASC("<narrow>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Narrow;
            else if (CString::compareIgnoreCase(value, ASC("<small>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Small;
            else if (CString::compareIgnoreCase(value, ASC("<square>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Square;
            else if (CString::compareIgnoreCase(value, ASC("<fraction>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Fraction;
            else if (CString::compareIgnoreCase(value, ASC("<compat>")) == 0)
              decomposition_mapping_type = e_DecompositionMapping_Compat;
            else
            {
              ASSERT(false, STR("Unsupported Decomposition Type Mapping value was met - \"%X\").") COMMA &(*it)) error = true;
              end_with_error = true;
              break;
            }
          }
          else
          {
            // Decomposition Type Mapping value without tag is Canonical.
            if (item == 0)
              decomposition_mapping_type = e_DecompositionMapping_Canonical;
            // Store Decomposition Mapping value.
            if ((count >= countOf(decomposition_mapping)) || (!value.insertFirst(ASC("0x"))))
            {
              end_with_error = true;
              break;
            }
            decomposition_mapping[count++] = (Tsint32)toUnsigned(value);
          }
          // Switch to new Decomposition Mapping value.
          ++item;
        }

        if ((index < it->getSize()) && ((*it)[index] == STR(' ')))
          index++;
        if (index == it->getSize())
          break;
      }

      // If we failed to parse Decomposition Type Mapping value...
      if (end_with_error)
      {
        ASSERT(false, STR("Unsupported Decomposition Type Mapping value was met - \"%X\").") COMMA &(*it)) error = true;
      }
    }
    else
    {
      // Special check for Hangul Syllable characters.
      if ((prop.m_Code >= 0xAC00) && (prop.m_Code <= 0xD7A3))
        decomposition_mapping_type = e_DecompositionMapping_Canonical;
    }
    // Check for a new Decomposition Mapping value in the corresponding table.
    if (decomposition_mapping_type != e_DecompositionMapping_None)
    {
      Tsint32 found = -1;
      Tsint32 dmt = (Tsint32)(decomposition_mapping_type - e_DecompositionMapping_None);
      for (Tuint i = 0; i < the_DecompositionMappings.getSize(); ++i)
      {
        // Check for the Decomposition Mapping type.
        if (the_DecompositionMappings[i].m_DecompositionMappingType == dmt)
        {
          // Check for the Decomposition Mapping value.
          for (Tuint j = 0; j < countOf(decomposition_mapping); ++j)
          {
            if (the_DecompositionMappings[i].m_DecompositionMappingValues[j] != decomposition_mapping[j])
              break;
            if (j == (countOf(decomposition_mapping) - 1))
              found = (Tsint32)i;
          }
        }
        if (found > 0)
          break;
      }
      // Insert a new set of Decomposition Mapping values in the corresponding table.
      if (found > 0)
        prop.m_DecompositionMappingID = found;
      else
      {
        if (!the_DecompositionMappings.resizeBy(1))
          error = true;
        else
        {
          // Update Decomposition Mapping ID.
          prop.m_DecompositionMappingID = (Tsint32)(the_DecompositionMappings.getSize() - 1);
          // Update Decomposition Mapping type.
          the_DecompositionMappings[(Tuint)prop.m_DecompositionMappingID].m_DecompositionMappingType = dmt;
          // Update Decomposition Mapping values.
          for (Tuint i = 0; i < countOf(decomposition_mapping); ++i)
          {
            // Update Decomposition Mapping values count.
            if (decomposition_mapping[i] > 0)
              the_DecompositionMappings[(Tuint)prop.m_DecompositionMappingID].m_DecompositionMappingSize = (Tsint32)(i + 1);
            // Update next Decomposition Mapping value.
            the_DecompositionMappings[(Tuint)prop.m_DecompositionMappingID].m_DecompositionMappingValues[i] = decomposition_mapping[i];
          }
        }
      }
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse Decimal Digit value.
    if (!it->isEmpty())
    {
      CStringASCII decimal_digit(*it);
      if (decimal_digit.insertCEnd())
      {
        CStringBuffer<Tsstr>::TIterator it_decimal_digit = find(the_DecimalDigitValues, *it, FStringComparator<Tsstr, CStringASCII>());
        if (it_decimal_digit.isValid())
          prop.m_DecimalDigitID = (Tsint32)it_decimal_digit.getPosition();
        else
        {
          if (!the_DecimalDigitValues.insertLast(decimal_digit))
            error = true;
          else
            prop.m_DecimalDigitID = (Tsint32)(the_DecimalDigitValues.getSize() - 1);
        }
      }
      else
        error = true;
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse Digit value.
    if (!it->isEmpty())
    {
      CStringASCII digit(*it);
      if (digit.insertCEnd())
      {
        CStringBuffer<Tsstr>::TIterator it_digit = find(the_DigitValues, *it, FStringComparator<Tsstr, CStringASCII>());
        if (it_digit.isValid())
          prop.m_DigitID = (Tsint32)it_digit.getPosition();
        else
        {
          if (!the_DigitValues.insertLast(digit))
            error = true;
          else
            prop.m_DigitID = (Tsint32)(the_DigitValues.getSize() - 1);
        }
      }
      else
        error = true;
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse Numeric value.
    if (!it->isEmpty())
    {
      CStringASCII numeric(*it);
      if (numeric.insertCEnd())
      {
        CStringBuffer<Tsstr>::TIterator it_numeric = find(the_NumericValues, *it, FStringComparator<Tsstr, CStringASCII>());
        if (it_numeric.isValid())
          prop.m_NumericID = (Tsint32)it_numeric.getPosition();
        else
        {
          if (!the_NumericValues.insertLast(numeric))
            error = true;
          else
            prop.m_NumericID = (Tsint32)(the_NumericValues.getSize() - 1);
        }
      }
      else
        error = true;
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse Bidi mirrored flag.
    if (!it->isEmpty())
    {
      if (CString::compareIgnoreCase(*it, STR("N")) == 0)
        prop.m_BidiMirrored = false;
      else if (CString::compareIgnoreCase(*it, STR("Y")) == 0)
        prop.m_BidiMirrored = true;
      else
      {
        ASSERT(false, STR("Unsupported Bidirectional Mirrored flag value was met - \"%X\").") COMMA &(*it)) error = true;
      }
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse old Unicode character name.
    if (!it->isEmpty())
    {
      CStringASCII name(*it);
      if (name.insertCEnd())
      {
        CStringBuffer<Tsstr>::TIterator it_name = find(the_CharacterNamesOld, *it, FStringComparator<Tsstr, CStringASCII>());
        if (it_name.isValid())
          prop.m_NameOldID = (Tsint32)it_name.getPosition();
        else
        {
          if (!the_CharacterNamesOld.insertLast(name))
            error = true;
          else
            prop.m_NameOldID = (Tsint32)(the_CharacterNamesOld.getSize() - 1);
        }
      }
      else
        error = true;
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Skip obsolete ISO_Comment value.
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse upper case mapping.
    if (!it->isEmpty())
    {
      CStringASCII code(*it);
      if (!code.insertFirst(ASC("0x")))
        error = true;
      prop.m_UppercaseMapping = (Tsint32)toUnsigned(code);
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse lower case mapping.
    if (!it->isEmpty())
    {
      CStringASCII code(*it);
      if (!code.insertFirst(ASC("0x")))
        error = true;
      prop.m_LowercaseMapping = (Tsint32)toUnsigned(code);
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse title case mapping.
    if (!it->isEmpty())
    {
      CStringASCII code(*it);
      if (!code.insertFirst(ASC("0x")))
        error = true;
      prop.m_TitlecaseMapping = (Tsint32)toUnsigned(code);
    }

    // Store Unicode character in the Database.
    if (!the_UnicodeCharacterDatabase.insertIndex(prop.m_Code, prop))
      error = true;

    // Try to get new token.
    if (it.stepForward() == 0)
      break;
  }

  if (error)
    a_crOutputStream << STR("Cannot parse UnicodeData.txt file.") << ln;
  else
    a_crOutputStream << STR("UnicodeData.txt file successfully parsed.") << ln;

  // Close UnicodeData.txt file.
  CHECK(file_UnicodeData.close());

  return !error;
}
/*==========================================================================*/
#endif
