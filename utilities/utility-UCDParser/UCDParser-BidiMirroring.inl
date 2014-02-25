/*!
 *  \file    UCDParser-BidiMirroring.cpp Unicode characters database parser
 *           is used to parse UCD and create character properties tables for
 *           internal usage. BidiMirroring.txt parser.
 *  \brief   Unicode characters database parser. BidiMirroring.txt parser (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode characters database parser. BidiMirroring.txt parser (source).

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
#ifndef __UCDPARSER_BIDIMIRRORING_INL__
#define __UCDPARSER_BIDIMIRRORING_INL__
/*==========================================================================*/
Tbool UCDParser::parseBidiMirroring(CStreamStdOutput& a_crOutputStream)
{ CALL
  // Open BidiMirroring.txt
  CFile file_BidiMirroring(STR("BidiMirroring.txt"));
  CHECK(file_BidiMirroring.open(NStream::IStream::e_OPEN_READ));

  a_crOutputStream << STR("Parsing BidiMirroring.txt file...") << ln;

  // Create the character delimiters tokenizer.
  CTokenizer tokenizer(file_BidiMirroring.getItRead<Tschar>(), CTokenizerFunctionUCDParser(false));

  // Iterate through all tokens.
  Tbool error = false;
  CTokenizer::TIterator it = tokenizer.getItTop();
  while (it.isValid() && !error)
  {
    CStringASCII code1(*it);

    // Check for comment token.
    if (!code1.isEmpty() && (code1[CONSTU(0)] == STR('#')))
    {
      if (it.stepForward() == 0)
        break;

      continue;
    }

    ASSERT((it.stepForward() > 0), STR("Cannot get the next token (previous token is \"%X\").") COMMA &(*it)) error = true;

    // Parse Bidi Mirroring Glyph values.
    CStringASCII code2(it->getLeft(4));
    if (!code1.isEmpty() && !code2.isEmpty())
    {
      a_crOutputStream << STR("Parsing Unicode character \"") << code1 << STR("\"...") << ln;

      if (!code1.insertFirst(ASC("0x")))
        error = true;
      if (!code2.insertFirst(ASC("0x")))
        error = true;

      Tuint index1 = toUnsigned(code1);
      Tuint index2 = toUnsigned(code2);

      SUnicodeCharacterProperties& prop = the_UnicodeCharacterDatabase[index1];

      prop.m_BidiMirroringGlyph = (Tsint32)index2;

      // Parse Bidi Mirroring Glyph best fit flag.
      CStringASCII best_fit(it->getMiddle(7, 10));
      if (!best_fit.isEmpty() && (CString::compareIgnoreCase(best_fit, STR("[BEST FIT]")) == 0))
        prop.m_BidiMirroringGlyphBestFit = true;
    }

    // Try to get new token.
    if (it.stepForward() == 0)
      break;
  }

  if (error)
    a_crOutputStream << STR("Cannot parse BidiMirroring.txt file.") << ln;
  else
    a_crOutputStream << STR("BidiMirroring.txt file successfully parsed.") << ln;

  // Close BidiMirroring.txt file.
  CHECK(file_BidiMirroring.close());

  return !error;
}
/*==========================================================================*/
#endif
