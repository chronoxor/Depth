/*!
 *  \file    OFormatFlags.cpp Format flags stream control operators. They are
 *           used to manipulate stream format flags through stream operators.
 *  \brief   Format flags stream control operators (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Format flags stream control operators (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   02.10.2008 01:48:42

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/stream/operators/OFormatFlags.hpp>
/*==========================================================================*/
#ifndef __OFORMATFLAGS_CPP__
#define __OFORMATFLAGS_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NOperators {
/*==========================================================================*/
/* OPERATOR IMPLEMENTATIONS                                                 */
/*==========================================================================*/
BASE_API flags defaults(IStream::FORMAT_DEFAULT | IStream::PARSE_DEFAULT);
BASE_API flags plus((IStream::FORMAT_PLUS | IStream::FORMAT_SPACE), IStream::FORMAT_PLUS);
BASE_API flags space((IStream::FORMAT_PLUS | IStream::FORMAT_SPACE), IStream::FORMAT_SPACE);
BASE_API flags binary((IStream::FORMAT_binary | IStream::FORMAT_BINARY | IStream::FORMAT_octal | IStream::FORMAT_OCTAL | IStream::FORMAT_DECIMAL | IStream::FORMAT_hex | IStream::FORMAT_HEX | IStream::FORMAT_GROUPS), IStream::FORMAT_binary);
BASE_API flags BINARY((IStream::FORMAT_binary | IStream::FORMAT_BINARY | IStream::FORMAT_octal | IStream::FORMAT_OCTAL | IStream::FORMAT_DECIMAL | IStream::FORMAT_hex | IStream::FORMAT_HEX | IStream::FORMAT_GROUPS), IStream::FORMAT_BINARY);
BASE_API flags octal((IStream::FORMAT_binary | IStream::FORMAT_BINARY | IStream::FORMAT_octal | IStream::FORMAT_OCTAL | IStream::FORMAT_DECIMAL | IStream::FORMAT_hex | IStream::FORMAT_HEX | IStream::FORMAT_GROUPS), IStream::FORMAT_octal);
BASE_API flags OCTAL((IStream::FORMAT_binary | IStream::FORMAT_BINARY | IStream::FORMAT_octal | IStream::FORMAT_OCTAL | IStream::FORMAT_DECIMAL | IStream::FORMAT_hex | IStream::FORMAT_HEX | IStream::FORMAT_GROUPS), IStream::FORMAT_OCTAL);
BASE_API flags decimal((IStream::FORMAT_binary | IStream::FORMAT_BINARY | IStream::FORMAT_octal | IStream::FORMAT_OCTAL | IStream::FORMAT_DECIMAL | IStream::FORMAT_hex | IStream::FORMAT_HEX), IStream::FORMAT_DECIMAL);
BASE_API flags hex((IStream::FORMAT_binary | IStream::FORMAT_BINARY | IStream::FORMAT_octal | IStream::FORMAT_OCTAL | IStream::FORMAT_DECIMAL | IStream::FORMAT_hex | IStream::FORMAT_HEX | IStream::FORMAT_GROUPS), IStream::FORMAT_hex);
BASE_API flags HEX((IStream::FORMAT_binary | IStream::FORMAT_BINARY | IStream::FORMAT_octal | IStream::FORMAT_OCTAL | IStream::FORMAT_DECIMAL | IStream::FORMAT_hex | IStream::FORMAT_HEX | IStream::FORMAT_GROUPS), IStream::FORMAT_HEX);
BASE_API flags lower((IStream::FORMAT_LOWER | IStream::FORMAT_UPPER), IStream::FORMAT_LOWER);
BASE_API flags upper((IStream::FORMAT_LOWER | IStream::FORMAT_UPPER), IStream::FORMAT_UPPER);
BASE_API flags lalign((IStream::FORMAT_LALIGN | IStream::FORMAT_RALIGN | IStream::FORMAT_FILL_0), IStream::FORMAT_LALIGN);
BASE_API flags ralign((IStream::FORMAT_LALIGN | IStream::FORMAT_RALIGN | IStream::FORMAT_FILL_0), IStream::FORMAT_RALIGN);
BASE_API flags fill_0((IStream::FORMAT_LALIGN | IStream::FORMAT_RALIGN | IStream::FORMAT_FILL_0), IStream::FORMAT_FILL_0);
BASE_API flags groups(0, IStream::FORMAT_GROUPS);
BASE_API flags dot((IStream::FORMAT_DOT | IStream::FORMAT_exp | IStream::FORMAT_EXP), IStream::FORMAT_DOT);
BASE_API flags exp((IStream::FORMAT_DOT | IStream::FORMAT_exp | IStream::FORMAT_EXP), IStream::FORMAT_exp);
BASE_API flags EXP((IStream::FORMAT_DOT | IStream::FORMAT_exp | IStream::FORMAT_EXP), IStream::FORMAT_EXP);
BASE_API flags ascii((IStream::FORMAT_UNICODE | IStream::PARSE_UNICODE), (IStream::FORMAT_ASCII | IStream::PARSE_ASCII));
BASE_API flags unicode((IStream::FORMAT_ASCII | IStream::PARSE_ASCII), (IStream::FORMAT_UNICODE | IStream::PARSE_UNICODE));
BASE_API flags noplus(IStream::FORMAT_PLUS, 0);
BASE_API flags nospace(IStream::FORMAT_SPACE, 0);
BASE_API flags nogroups(IStream::FORMAT_GROUPS, 0);
/*==========================================================================*/
BASE_API resetStream reset;
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
