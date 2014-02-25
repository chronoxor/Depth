/*!
 *  \file    CTokenizerFunctionUCDParser.inl Tokenizer function of the UCD
 *           parser.
 *  \brief   UCD parser tokenizer function class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: UCD parser tokenizer function class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      UCD parser utility
    VERSION:   1.0
    CREATED:   07.05.2009 00:35:23

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
#ifndef __CTOKENIZERFUNCTIONUCDPARSER_INL__
#define __CTOKENIZERFUNCTIONUCDPARSER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtilities {
/*--------------------------------------------------------------------------*/
namespace NUCDParser {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CTokenizerFunctionUCDParser::~CTokenizerFunctionUCDParser()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTokenizerFunctionUCDParser& CTokenizerFunctionUCDParser::operator = (const CTokenizerFunctionUCDParser& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CTokenizerFunctionUCDParser::reset()
{ CALL
  return NTokenizer::CTokenizerFunctionCharDelimiters::reset();
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTokenizerFunctionUCDParser::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTokenizer::CTokenizerFunctionUCDParser")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((NTokenizer::CTokenizerFunctionCharDelimiters&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_SkipComments, STR("m_SkipComments")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
