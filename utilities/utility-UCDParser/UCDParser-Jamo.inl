/*!
 *  \file    UCDParser-Jamo.cpp Unicode characters database parser
 *           is used to parse UCD and create character properties tables for
 *           internal usage. Jamo.txt parser.
 *  \brief   Unicode characters database parser. Jamo.txt parser (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode characters database parser. Jamo.txt parser (source).

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
#ifndef __UCDPARSER_JAMO_INL__
#define __UCDPARSER_JAMO_INL__
/*==========================================================================*/
Tbool UCDParser::parseJamo(CStreamStdOutput& a_crOutputStream)
{ CALL
  // Open Jamo.txt file.
  CFile file_Jamo(STR("Jamo.txt"));
  CHECK(file_Jamo.open(NStream::IStream::e_OPEN_READ));

  a_crOutputStream << STR("Parsing Jamo.txt file...") << ln;

  // Create the character delimiters tokenizer.
  CTokenizer tokenizer(file_Jamo.getItRead<Tschar>(), CTokenizerFunctionUCDParser());

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

    // Parse Jamo name.
    CStringASCII name(*it);
    if (name.insertCEnd())
    {
      CStringBuffer<Tsstr>::TIterator it_name = find(the_CharacterNamesJamo, *it, FStringComparator<Tsstr, CStringASCII>());
      if (it_name.isValid())
        prop.m_NameJamoID = (Tsint32)it_name.getPosition();
      else
      {
        if (!the_CharacterNamesJamo.insertLast(name.isEmpty() ? ASC("") : name))
          error = true;
        else
          prop.m_NameJamoID = (Tsint32)(the_CharacterNamesJamo.getSize() - 1);
      }
    }
    else
      error = true;

    // Try to get new token.
    if (it.stepForward() == 0)
      break;
  }

  if (error)
    a_crOutputStream << STR("Cannot parse Jamo.txt file.") << ln;
  else
    a_crOutputStream << STR("Jamo.txt file successfully parsed.") << ln;

  // Close Jamo.txt file.
  CHECK(file_Jamo.close());

  return !error;
}
/*==========================================================================*/
#endif
