/*!
 *  \file    example-tokenizer-CTokenizerOffsetDelimiters.cpp Example of using
 *           the CTokenizer class with the CTokenizerFunctionOffsetDelimiters
 *           rules.
 *  \brief   Example of using the CTokenizer class with the CTokenizerFunctionOffsetDelimiters rules.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CTokenizer class with the CTokenizerFunctionOffsetDelimiters rules.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth tokenizer examples
    VERSION:   1.0
    CREATED:   24.04.2009 02:34:57

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
// Common headers.
#include <Depth/include/application/IApplication.hpp>
#include <Depth/include/stream/CStreamStdOutput.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/containers/CWrappedArray.hpp>
#include <Depth/include/stream/CStreamStdInput.hpp>
#include <Depth/include/tokenizer/CTokenizer.hpp>
#include <Depth/include/tokenizer/CTokenizerFunctionOffsetDelimiters.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NTokenizer;
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    // Show usage information.
    stdoutput << STR("Please input single line of characters (30 or more symbols): ");

    // Use standard input stream of the current process.
    CStreamStdInput stdinput(true);

    // Create the offset tokenizer.
    Tuint offsets[] = { 1, 2, 3 };
    CWrappedArray<Tuint> offsetarray(offsets);
    CTokenizerFunctionOffsetDelimiters tf(true, offsetarray);
    CTokenizer tokenizer(stdinput.getItRead<Tschar>(), tf);

    // Iterate through first 10 tokens.
    Tuint count = 10;
    CTokenizer::TIterator it = tokenizer.getItTop();
    while (it.isValid() && (count-- > 0))
    {
      // Show the next token.
      stdoutput << STR("Next token = \"") << *it << STR("\"") << ln;
      // Get the next token.
      if (it.stepForward() == 0)
        break;
    }

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
