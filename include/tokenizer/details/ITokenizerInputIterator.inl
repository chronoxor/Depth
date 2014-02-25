/*!
 *  \file    ITokenizerInputIterator.inl Tokenizer input iterator interface.
 *           It gives ability to check for valid state and input characters
 *           for the tokenizer.
 *  \brief   Tokenizer input iterator interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer input iterator interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer details
    VERSION:   1.0
    CREATED:   17.04.2009 02:38:24

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
#ifndef __ITOKENIZERINPUTITERATOR_INL__
#define __ITOKENIZERINPUTITERATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline ITokenizerInputIterator::ITokenizerInputIterator() :
  NCommon::IClonable<ITokenizerInputIterator>()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline ITokenizerInputIterator::~ITokenizerInputIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline const Tuint& ITokenizerInputIterator::operator* () const
{ CALL
  return getValueRef();
}
/*--------------------------------------------------------------------------*/
inline const Tuint* ITokenizerInputIterator::operator-> () const
{ CALL
  return getValuePtr();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
