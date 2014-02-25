/*-----------------------------------------------------------------------------*\
| Matpack Numerical Expression Evaluator - class MpNumex              mpnumex.h |
|						 			        |
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
| from the use of this software.						|
| Note that distributing Matpack 'bundled' in with any product is considered to |
| be a 'commercial purpose'.							|
| The software may be modified for your own purposes, but modified versions may |
| not be distributed without prior consent of the author.			|
|                                                                               |
| Read the  COPYRIGHT and  README files in this distribution about registration	|
| and installation of Matpack.							|
|                                                                               |
\*-----------------------------------------------------------------------------*/

// avoid multiple inclusion
#ifndef _MPNUMEX_H_
#define _MPNUMEX_H_

//-----------------------------------------------------------------------------//

#include <string>

namespace MATPACK {
using std::string;

//-----------------------------------------------------------------------------//
//
// class MpNumex
//
// Constructor:
// ------------
//   MpNumex(int id = 0);
//   
//   Optionally a variable space ID can be given. If two instances of MpNumex
//   have the same ID they share the defined variables and function definitions.
//   Default is the ID = 0.
//
// Destructor:
// -----------
//   ~MpNumex();
//   If the destructor is called all variable definitions are destroyed.
//
// Methods:
// --------
//   double EvalNumex (const string &expression, string &error);
//
//   Evaluate the expression given in the first argument. If no error occurs
//   the numerical result is returned as a double precision numerical value
//   and error is an empty string.
//   If an error occurs NAN is returned and the error description is returned
//   in the error string.
//
//-----------------------------------------------------------------------------//

class MpNumex
{
  private:
    int id;
    static bool init;
  public:
    MpNumex(int id = 0);
   ~MpNumex();
    double EvalNumex (const string &expression, string &error);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
