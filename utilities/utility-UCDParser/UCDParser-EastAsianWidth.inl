/*!
 *  \file    UCDParser-EastAsianWidth.cpp Unicode characters database parser
 *           is used to parse UCD and create character properties tables for
 *           internal usage. EastAsianWidth.txt parser.
 *  \brief   Unicode characters database parser. EastAsianWidth.txt parser (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode characters database parser. EastAsianWidth.txt parser (source).

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
#ifndef __UCDPARSER_EASTASIANWIDTH_INL__
#define __UCDPARSER_EASTASIANWIDTH_INL__
/*==========================================================================*/
Tbool UCDParser::parseEastAsianWidth(CStreamStdOutput& a_crOutputStream)
{ CALL
  // Open EastAsianWidth.txt file.
  CFile file_EastAsianWidth(STR("EastAsianWidth.txt"));
  CHECK(file_EastAsianWidth.open(NStream::IStream::e_OPEN_READ));

  a_crOutputStream << STR("Parsing EastAsianWidth.txt file...") << ln;

  // Create the character delimiters tokenizer.
  CTokenizer tokenizer(file_EastAsianWidth.getItRead<Tschar>(), CTokenizerFunctionUCDParser());

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

    // Parse East Asian Width value.
    EEastAsianWidth east_asian_width = e_EastAsianWidth_Neutral;
    if (!it->isEmpty())
    {
      if (CString::compareIgnoreCase(*it, STR("N")) == 0)
        east_asian_width = e_EastAsianWidth_Neutral;
      else if (CString::compareIgnoreCase(*it, STR("F")) == 0)
        east_asian_width = e_EastAsianWidth_Fullwidth;
      else if (CString::compareIgnoreCase(*it, STR("H")) == 0)
        east_asian_width = e_EastAsianWidth_Halfwidth;
      else if (CString::compareIgnoreCase(*it, STR("W")) == 0)
        east_asian_width = e_EastAsianWidth_Wide;
      else if (CString::compareIgnoreCase(*it, STR("Na")) == 0)
        east_asian_width = e_EastAsianWidth_Narrow;
      else if (CString::compareIgnoreCase(*it, STR("A")) == 0)
        east_asian_width = e_EastAsianWidth_Ambiguous;
      else
      {
        ASSERT(false, STR("Unsupported East Asian Width was met - \"%X\").") COMMA &(*it)) error = true;
      }
    }


    // Update East Asian Width of all characters in the set...
    for (Tuint index = index1; index <= index2; ++index)
    {
      CSparseArray<SUnicodeCharacterProperties>::TIterator it_prop = the_UnicodeCharacterDatabase.getItIndex(index);
      if (it_prop.isValid())
      {
        SUnicodeCharacterProperties& prop = it_prop.getValueRef();
        prop.m_EastAsianWidth = east_asian_width;
      }
    }

    // Try to get new token.
    if (it.stepForward() == 0)
      break;
  }

  if (error)
    a_crOutputStream << STR("Cannot parse EastAsianWidth.txt file.") << ln;
  else
    a_crOutputStream << STR("EastAsianWidth.txt file successfully parsed.") << ln;

  // Close EastAsianWidth.txt file.
  CHECK(file_EastAsianWidth.close());

  return !error;
}
/*==========================================================================*/
#endif
