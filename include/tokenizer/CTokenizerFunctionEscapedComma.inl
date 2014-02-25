/*!
 *  \file    CTokenizerFunctionEscapedComma.inl Escaped comma separated
 *           tokenizer function uses rules to parse tokens of the CSV
 *           (comma separated value) formats.
 *  \brief   Escaped comma separated tokenizer function class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Escaped comma separated tokenizer function class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   24.04.2009 23:41:14

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
#ifndef __CTOKENIZERFUNCTIONESCAPEDCOMMA_INL__
#define __CTOKENIZERFUNCTIONESCAPEDCOMMA_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CTokenizerFunctionEscapedComma::~CTokenizerFunctionEscapedComma()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTokenizerFunctionEscapedComma& CTokenizerFunctionEscapedComma::operator = (const CTokenizerFunctionEscapedComma& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CTokenizerFunctionEscapedComma::reset()
{ CALL
  m_TokenReturned = false;
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTokenizerFunctionEscapedComma::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTokenizer::CTokenizerFunctionEscapedComma")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Escape, STR("m_Escape")));
    CHECK(a_rArchive.doValue(m_Comma, STR("m_Comma")));
    CHECK(a_rArchive.doValue(m_Quote, STR("m_Quote")));
    CHECK(a_rArchive.doValue(m_IsEqualQuotesRequired, STR("m_IsEqualQuotesRequired")));
    CHECK(a_rArchive.doValue(m_TokenReturned, STR("m_TokenReturned")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
