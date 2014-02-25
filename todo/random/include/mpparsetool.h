/*-----------------------------------------------------------------------------*\
| class MpParseTool - some parser utility functions               mpparsetool.h |
|                                                                               |
| Last change: Sep 12, 2004                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel                                   |
|                                                                               |
| Permission to  use, copy, and  distribute  Matpack  in  its entirety  and its |
| documentation  for non-commercial purpose and  without fee is hereby granted, |
| provided that this license information and copyright notice appear unmodified |
| in all copies.  This software is provided 'as is'  without express or implied |
| warranty.  In no event will the author be held liable for any damages arising |
| from the use of this software.                                                |
| Note that distributing Matpack 'bundled' in with any product is considered to |
| be a 'commercial purpose'.                                                    |
| The software may be modified for your own purposes, but modified versions may |
| not be distributed without prior consent of the author.                       |
|                                                                               |
| Read the  COPYRIGHT and  README files in this distribution about registration |
| and installation of Matpack.                                                  |
|                                                                               |
\*-----------------------------------------------------------------------------*/

#ifndef _MPPARSETOOL_H_
#define _MPPARSETOOL_H_

//-----------------------------------------------------------------------------//

// include STL definitions
#include <string>
#include <iostream>

namespace MATPACK {
using std::istream;
using std::ostream;
using std::string;

class MpParseTool
{
  public:
    //-------------------------------------------------------------------------//
    // Skip stream until a non-white space character is found. The stream points
    // to the first non-white character.
    //-------------------------------------------------------------------------//
    static void SkipWhiteSpace (istream &is);

    //-------------------------------------------------------------------------//
    // Skip stream until specific termination character is found. The stream
    // points to the character after the termination character.
    //-------------------------------------------------------------------------//
    static void SkipTo (istream &is, char term);

    //-------------------------------------------------------------------------//
    // Print a quoted string taking care of escaped characters inside.
    // Escaped characters are: "\t", "\n", "\r", "\a", "\f", "\b", "\v", "\""
    //-------------------------------------------------------------------------//
    static void PrintQuotedString (ostream& os, const string &str);
   
    //-------------------------------------------------------------------------//
    // Read a quoted string taking care of escaped characters inside.
    // Recognized escape characters are: "\t", "\n", "\r", "\a", "\f", "\b", "\v"
    // All other escaped characters are replaced by themselves.
    // Examples:  "string",  "with \"quotation\" inside".
    // Returns true if no error occurs in parsing the string.
    //-------------------------------------------------------------------------//
    static bool ReadQuotedString (istream &is, string &str);

    //-------------------------------------------------------------------------//
    // Skip white space and get one word. The word is terminated by white space
    // (spaces, newlines, tabs) or any of '(', ')', '[', ']', ','.
    // Returns true if at least on character could be read.
    //-------------------------------------------------------------------------//
    static bool GetWord (istream &is, string &word);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
