/*!
 *  \file    UCDParser-LineBreakClass.cpp Unicode characters database parser
 *           is used to parse UCD and create character properties tables for
 *           internal usage. LineBreak.txt parser.
 *  \brief   Unicode characters database parser. LineBreak.txt parser (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode characters database parser. LineBreak.txt parser (source).

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
#ifndef __UCDPARSER_LINEBREAKCLASS_INL__
#define __UCDPARSER_LINEBREAKCLASS_INL__
/*==========================================================================*/
Tbool UCDParser::parseLineBreakClass(CStreamStdOutput& a_crOutputStream)
{ CALL
  // Open LineBreak.txt file.
  CFile file_LineBreak(STR("LineBreak.txt"));
  CHECK(file_LineBreak.open(NStream::IStream::e_OPEN_READ));

  a_crOutputStream << STR("Parsing LineBreak.txt file...") << ln;

  // Create the character delimiters tokenizer.
  CTokenizer tokenizer(file_LineBreak.getItRead<Tschar>(), CTokenizerFunctionUCDParser());

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

    // Parse Line Break Class value.
    ELineBreakClass line_break_class = e_LineBreakClass_XX;
    if (!it->isEmpty())
    {
      if (CString::compareIgnoreCase(*it, STR("BK")) == 0)
        line_break_class = e_LineBreakClass_BK;
      else if (CString::compareIgnoreCase(*it, STR("CR")) == 0)
        line_break_class = e_LineBreakClass_CR;
      else if (CString::compareIgnoreCase(*it, STR("LF")) == 0)
        line_break_class = e_LineBreakClass_LF;
      else if (CString::compareIgnoreCase(*it, STR("CM")) == 0)
        line_break_class = e_LineBreakClass_CM;
      else if (CString::compareIgnoreCase(*it, STR("NL")) == 0)
        line_break_class = e_LineBreakClass_NL;
      else if (CString::compareIgnoreCase(*it, STR("SG")) == 0)
        line_break_class = e_LineBreakClass_SG;
      else if (CString::compareIgnoreCase(*it, STR("WJ")) == 0)
        line_break_class = e_LineBreakClass_WJ;
      else if (CString::compareIgnoreCase(*it, STR("ZW")) == 0)
        line_break_class = e_LineBreakClass_ZW;
      else if (CString::compareIgnoreCase(*it, STR("GL")) == 0)
        line_break_class = e_LineBreakClass_GL;
      else if (CString::compareIgnoreCase(*it, STR("SP")) == 0)
        line_break_class = e_LineBreakClass_SP;
      else if (CString::compareIgnoreCase(*it, STR("B2")) == 0)
        line_break_class = e_LineBreakClass_B2;
      else if (CString::compareIgnoreCase(*it, STR("BA")) == 0)
        line_break_class = e_LineBreakClass_BA;
      else if (CString::compareIgnoreCase(*it, STR("BB")) == 0)
        line_break_class = e_LineBreakClass_BB;
      else if (CString::compareIgnoreCase(*it, STR("HY")) == 0)
        line_break_class = e_LineBreakClass_HY;
      else if (CString::compareIgnoreCase(*it, STR("CB")) == 0)
        line_break_class = e_LineBreakClass_CB;
      else if (CString::compareIgnoreCase(*it, STR("CL")) == 0)
        line_break_class = e_LineBreakClass_CL;
      else if (CString::compareIgnoreCase(*it, STR("CP")) == 0)
        line_break_class = e_LineBreakClass_CP;
      else if (CString::compareIgnoreCase(*it, STR("EX")) == 0)
        line_break_class = e_LineBreakClass_EX;
      else if (CString::compareIgnoreCase(*it, STR("IN")) == 0)
        line_break_class = e_LineBreakClass_IN;
      else if (CString::compareIgnoreCase(*it, STR("NS")) == 0)
        line_break_class = e_LineBreakClass_NS;
      else if (CString::compareIgnoreCase(*it, STR("OP")) == 0)
        line_break_class = e_LineBreakClass_OP;
      else if (CString::compareIgnoreCase(*it, STR("QU")) == 0)
        line_break_class = e_LineBreakClass_QU;
      else if (CString::compareIgnoreCase(*it, STR("IS")) == 0)
        line_break_class = e_LineBreakClass_IS;
      else if (CString::compareIgnoreCase(*it, STR("NU")) == 0)
        line_break_class = e_LineBreakClass_NU;
      else if (CString::compareIgnoreCase(*it, STR("PO")) == 0)
        line_break_class = e_LineBreakClass_PO;
      else if (CString::compareIgnoreCase(*it, STR("PR")) == 0)
        line_break_class = e_LineBreakClass_PR;
      else if (CString::compareIgnoreCase(*it, STR("SY")) == 0)
        line_break_class = e_LineBreakClass_SY;
      else if (CString::compareIgnoreCase(*it, STR("AI")) == 0)
        line_break_class = e_LineBreakClass_AI;
      else if (CString::compareIgnoreCase(*it, STR("AL")) == 0)
        line_break_class = e_LineBreakClass_AL;
      else if (CString::compareIgnoreCase(*it, STR("H2")) == 0)
        line_break_class = e_LineBreakClass_H2;
      else if (CString::compareIgnoreCase(*it, STR("H3")) == 0)
        line_break_class = e_LineBreakClass_H3;
      else if (CString::compareIgnoreCase(*it, STR("ID")) == 0)
        line_break_class = e_LineBreakClass_ID;
      else if (CString::compareIgnoreCase(*it, STR("JL")) == 0)
        line_break_class = e_LineBreakClass_JL;
      else if (CString::compareIgnoreCase(*it, STR("JV")) == 0)
        line_break_class = e_LineBreakClass_JV;
      else if (CString::compareIgnoreCase(*it, STR("JT")) == 0)
        line_break_class = e_LineBreakClass_JT;
      else if (CString::compareIgnoreCase(*it, STR("SA")) == 0)
        line_break_class = e_LineBreakClass_SA;
      else if (CString::compareIgnoreCase(*it, STR("XX")) == 0)
        line_break_class = e_LineBreakClass_XX;
      else
      {
        ASSERT(false, STR("Unsupported Line Break Class was met - \"%X\").") COMMA &(*it)) error = true;
      }
    }


    // Update Line Break Class of all characters in the set...
    for (Tuint index = index1; index <= index2; ++index)
    {
      CSparseArray<SUnicodeCharacterProperties>::TIterator it_prop = the_UnicodeCharacterDatabase.getItIndex(index);
      if (it_prop.isValid())
      {
        SUnicodeCharacterProperties& prop = it_prop.getValueRef();
        prop.m_LineBreakClass = line_break_class;
      }
    }

    // Try to get new token.
    if (it.stepForward() == 0)
      break;
  }

  if (error)
    a_crOutputStream << STR("Cannot parse LineBreak.txt file.") << ln;
  else
    a_crOutputStream << STR("LineBreak.txt file successfully parsed.") << ln;

  // Close LineBreak.txt file.
  CHECK(file_LineBreak.close());

  return !error;
}
/*==========================================================================*/
#endif
