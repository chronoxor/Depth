/*!
 *  \file    UCDParser-ArabicShaping.cpp Unicode characters database parser
 *           is used to parse UCD and create character properties tables for
 *           internal usage. ArabicShaping.txt parser.
 *  \brief   Unicode characters database parser. ArabicShaping.txt parser (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode characters database parser. ArabicShaping.txt parser (source).

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
#ifndef __UCDPARSER_ARABICSHAPING_INL__
#define __UCDPARSER_ARABICSHAPING_INL__
/*==========================================================================*/
Tbool UCDParser::parseArabicShaping(CStreamStdOutput& a_crOutputStream)
{ CALL
  // Open ArabicShaping.txt file.
  CFile file_ArabicShaping(STR("ArabicShaping.txt"));
  CHECK(file_ArabicShaping.open(NStream::IStream::e_OPEN_READ));

  a_crOutputStream << STR("Parsing ArabicShaping.txt file...") << ln;

  // Create the character delimiters tokenizer.
  CTokenizer tokenizer(file_ArabicShaping.getItRead<Tschar>(), CTokenizerFunctionUCDParser());

  // Iterate through all tokens.
  Tbool error = false;
  CTokenizer::TIterator it = tokenizer.getItTop();
  while (it.isValid() && !error)
  {
    // Parse Unicode character code.
    Tuint index = 0;
    if (!it->isEmpty())
    {
      a_crOutputStream << STR("Parsing Unicode character \"") << *it << STR("\"...") << ln;

      CStringASCII code(*it);
      if (!code.insertFirst(ASC("0x")))
        error = true;
      index = toUnsigned(code);
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    SUnicodeCharacterProperties& prop = the_UnicodeCharacterDatabase[index];

    // Parse short schematic name.
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse Unicode character joining type.
    if (!it->isEmpty())
    {
      if (CString::compareIgnoreCase(*it, STR("U")) == 0)
        prop.m_JoiningType = e_JoiningType_None;
      else if (CString::compareIgnoreCase(*it, STR("L")) == 0)
        prop.m_JoiningType = e_JoiningType_Left;
      else if (CString::compareIgnoreCase(*it, STR("R")) == 0)
        prop.m_JoiningType = e_JoiningType_Right;
      else if (CString::compareIgnoreCase(*it, STR("D")) == 0)
        prop.m_JoiningType = e_JoiningType_Dual;
      else if (CString::compareIgnoreCase(*it, STR("C")) == 0)
        prop.m_JoiningType = e_JoiningType_Causing;
      else if (CString::compareIgnoreCase(*it, STR("T")) == 0)
        prop.m_JoiningType = e_JoiningType_Transparent;
      else
      {
        ASSERT(false, STR("Unsupported Joining Type was met - \"%X\").") COMMA &(*it)) error = true;
      }
    }
    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse Unicode character joining group.
    if (!it->isEmpty())
    {
      if (CString::compareIgnoreCase(*it, STR("No_Joining_Group")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_None;
      else if (CString::compareIgnoreCase(*it, STR("AIN")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Ain;
      else if (CString::compareIgnoreCase(*it, STR("ALAPH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Alaph;
      else if (CString::compareIgnoreCase(*it, STR("ALEF")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Alef;
      else if (CString::compareIgnoreCase(*it, STR("BEH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Beh;
      else if (CString::compareIgnoreCase(*it, STR("BETH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Beth;
      else if (CString::compareIgnoreCase(*it, STR("BURUSHASKI YEH BARREE")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Burushaski_Yeh_Barree;
      else if (CString::compareIgnoreCase(*it, STR("DAL")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Dal;
      else if (CString::compareIgnoreCase(*it, STR("DALATH RISH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Dalath_Rish;
      else if (CString::compareIgnoreCase(*it, STR("E")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_E;
      else if (CString::compareIgnoreCase(*it, STR("FARSI YEH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Farsi_Yeh;
      else if (CString::compareIgnoreCase(*it, STR("FE")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Fe;
      else if (CString::compareIgnoreCase(*it, STR("FEH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Feh;
      else if (CString::compareIgnoreCase(*it, STR("FINAL SEMKATH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Final_Semkath;
      else if (CString::compareIgnoreCase(*it, STR("GAF")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Gaf;
      else if (CString::compareIgnoreCase(*it, STR("GAMAL")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Gamal;
      else if (CString::compareIgnoreCase(*it, STR("HAH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Hah;
      else if (CString::compareIgnoreCase(*it, STR("HAMZA ON HEH GOAL")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Hamza_On_Heh_Goal;
      else if (CString::compareIgnoreCase(*it, STR("HE")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_He;
      else if (CString::compareIgnoreCase(*it, STR("HEH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Heh;
      else if (CString::compareIgnoreCase(*it, STR("HEH GOAL")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Heh_Goal;
      else if (CString::compareIgnoreCase(*it, STR("HETH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Heth;
      else if (CString::compareIgnoreCase(*it, STR("KAF")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Kaf;
      else if (CString::compareIgnoreCase(*it, STR("KAPH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Kaph;
      else if (CString::compareIgnoreCase(*it, STR("KHAPH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Khaph;
      else if (CString::compareIgnoreCase(*it, STR("KNOTTED HEH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Knotted_Heh;
      else if (CString::compareIgnoreCase(*it, STR("LAM")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Lam;
      else if (CString::compareIgnoreCase(*it, STR("LAMADH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Lamadh;
      else if (CString::compareIgnoreCase(*it, STR("MEEM")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Meem;
      else if (CString::compareIgnoreCase(*it, STR("MIM")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Mim;
      else if (CString::compareIgnoreCase(*it, STR("NOON")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Noon;
      else if (CString::compareIgnoreCase(*it, STR("NUN")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Nun;
      else if (CString::compareIgnoreCase(*it, STR("NYA")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Nya;
      else if (CString::compareIgnoreCase(*it, STR("PE")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Pe;
      else if (CString::compareIgnoreCase(*it, STR("QAF")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Qaf;
      else if (CString::compareIgnoreCase(*it, STR("QAPH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Qaph;
      else if (CString::compareIgnoreCase(*it, STR("REH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Reh;
      else if (CString::compareIgnoreCase(*it, STR("REVERSED PE")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Reversed_Pe;
      else if (CString::compareIgnoreCase(*it, STR("SAD")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Sad;
      else if (CString::compareIgnoreCase(*it, STR("SADHE")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Sadhe;
      else if (CString::compareIgnoreCase(*it, STR("SEEN")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Seen;
      else if (CString::compareIgnoreCase(*it, STR("SEMKATH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Semkath;
      else if (CString::compareIgnoreCase(*it, STR("SHIN")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Shin;
      else if (CString::compareIgnoreCase(*it, STR("SWASH KAF")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Swash_Kaf;
      else if (CString::compareIgnoreCase(*it, STR("SYRIAC WAW")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Syriac_Waw;
      else if (CString::compareIgnoreCase(*it, STR("TAH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Tah;
      else if (CString::compareIgnoreCase(*it, STR("TAW")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Taw;
      else if (CString::compareIgnoreCase(*it, STR("TEH MARBUTA")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Teh_Marbuta;
      else if (CString::compareIgnoreCase(*it, STR("TETH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Teth;
      else if (CString::compareIgnoreCase(*it, STR("WAW")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Waw;
      else if (CString::compareIgnoreCase(*it, STR("YEH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Yeh;
      else if (CString::compareIgnoreCase(*it, STR("YEH BARREE")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Yeh_Barree;
      else if (CString::compareIgnoreCase(*it, STR("YEH WITH TAIL")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Yeh_With_Tail;
      else if (CString::compareIgnoreCase(*it, STR("YUDH")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Yudh;
      else if (CString::compareIgnoreCase(*it, STR("YUDH HE")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Yudh_He;
      else if (CString::compareIgnoreCase(*it, STR("ZAIN")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Zain;
      else if (CString::compareIgnoreCase(*it, STR("ZHAIN")) == 0)
        prop.m_JoiningGroup = e_JoiningGroup_Zhain;
      else
      {
        ASSERT(false, STR("Unsupported Joining Group was met - \"%X\").") COMMA &(*it)) error = true;
      }
    }

    // Add joining type assign rule.
    if ((prop.m_JoiningType == e_JoiningType_None) && ((prop.m_GeneralCategory == e_GeneralCategory_Mn) || (prop.m_GeneralCategory == e_GeneralCategory_Me) || (prop.m_GeneralCategory == e_GeneralCategory_Cf)))
      prop.m_JoiningType = e_JoiningType_Transparent;

    // Try to get new token.
    if (it.stepForward() == 0)
      break;
  }

  if (error)
    a_crOutputStream << STR("Cannot parse ArabicShaping.txt file.") << ln;
  else
    a_crOutputStream << STR("ArabicShaping.txt file successfully parsed.") << ln;

  // Close ArabicShaping.txt file.
  CHECK(file_ArabicShaping.close());

  return !error;
}
/*==========================================================================*/
#endif
