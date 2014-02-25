/*!
 *  \file    UCDParser-UnicodeVersion.cpp Unicode characters database parser
 *           is used to parse UCD and create character properties tables for
 *           internal usage. DerivedAge.txt parser.
 *  \brief   Unicode characters database parser. DerivedAge.txt parser (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode characters database parser. DerivedAge.txt parser (source).

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
#ifndef __UCDPARSER_UNICODEVERSION_INL__
#define __UCDPARSER_UNICODEVERSION_INL__
/*==========================================================================*/
Tbool UCDParser::parseUnicodeVersion(CStreamStdOutput& a_crOutputStream)
{ CALL
  // Open DerivedAge.txt file.
  CFile file_DerivedAge(STR("DerivedAge.txt"));
  CHECK(file_DerivedAge.open(NStream::IStream::e_OPEN_READ));

  a_crOutputStream << STR("Parsing DerivedAge.txt file...") << ln;

  // Create the character delimiters tokenizer.
  CTokenizer tokenizer(file_DerivedAge.getItRead<Tschar>(), CTokenizerFunctionUCDParser());

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

    // Parse Unicode character version.
    EUnicodeVersion version = e_UnicodeVersion_Unassigned;
    if (!it->isEmpty())
    {
      if (CString::compareIgnoreCase(*it, STR("1.1")) == 0)
        version = e_UnicodeVersion_1_1;
      else if (CString::compareIgnoreCase(*it, STR("2.0")) == 0)
        version = e_UnicodeVersion_2_0;
      else if (CString::compareIgnoreCase(*it, STR("2.1")) == 0)
        version = e_UnicodeVersion_2_1;
      else if (CString::compareIgnoreCase(*it, STR("3.0")) == 0)
        version = e_UnicodeVersion_3_0;
      else if (CString::compareIgnoreCase(*it, STR("3.1")) == 0)
        version = e_UnicodeVersion_3_1;
      else if (CString::compareIgnoreCase(*it, STR("3.2")) == 0)
        version = e_UnicodeVersion_3_2;
      else if (CString::compareIgnoreCase(*it, STR("4.0")) == 0)
        version = e_UnicodeVersion_4_0;
      else if (CString::compareIgnoreCase(*it, STR("4.1")) == 0)
        version = e_UnicodeVersion_4_1;
      else if (CString::compareIgnoreCase(*it, STR("5.0")) == 0)
        version = e_UnicodeVersion_5_0;
      else if (CString::compareIgnoreCase(*it, STR("5.1")) == 0)
        version = e_UnicodeVersion_5_1;
      else if (CString::compareIgnoreCase(*it, STR("5.2")) == 0)
        version = e_UnicodeVersion_5_2;
      else
      {
        ASSERT(false, STR("Unsupported Unicode version was met - \"%X\").") COMMA &(*it)) error = true;
      }
    }


    // Update Unicode version of all characters in the set...
    for (Tuint index = index1; index <= index2; ++index)
    {
      CSparseArray<SUnicodeCharacterProperties>::TIterator it_prop = the_UnicodeCharacterDatabase.getItIndex(index);
      if (it_prop.isValid())
      {
        SUnicodeCharacterProperties& prop = it_prop.getValueRef();
        prop.m_UnicodeVersion = version;
      }
    }

    // Try to get new token.
    if (it.stepForward() == 0)
      break;
  }

  if (error)
    a_crOutputStream << STR("Cannot parse DerivedAge.txt file.") << ln;
  else
    a_crOutputStream << STR("DerivedAge.txt file successfully parsed.") << ln;

  // Close DerivedAge.txt file.
  CHECK(file_DerivedAge.close());

  return !error;
}
/*==========================================================================*/
#endif
