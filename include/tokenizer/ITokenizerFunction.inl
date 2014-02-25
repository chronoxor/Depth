/*!
 *  \file    ITokenizerFunction.inl Tokenizer function interface is a base
 *           interface for all tokenize functions which are used to separate
 *           string tokens based on their corresponding rules.
 *  \brief   Tokenizer function interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer function interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   20.04.2009 20:28:52

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

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
#ifndef __ITOKENIZERFUNCTION_INL__
#define __ITOKENIZERFUNCTION_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline ITokenizerFunction::ITokenizerFunction() :
  NCommon::IClonable<ITokenizerFunction>()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline ITokenizerFunction::~ITokenizerFunction()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline Tbool ITokenizerFunction::operator () (NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, NString::CString& a_rResult)
{ CALL
  return getNextToken(a_rInputIterator, a_rIsEndOfStream, a_rResult);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
