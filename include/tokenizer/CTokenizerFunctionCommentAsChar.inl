/*!
 *  \file    CTokenizerFunctionCommentAsChar.inl Character comment
 *           tokenizer function uses rules to parse tokens of the
 *           character comment formats.
 *  \brief   Character comment tokenizer function class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.06.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character comment tokenizer function class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   15.06.2010 19:47:09

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
#ifndef __CTOKENIZERFUNCTIONCOMMENTASCHAR_INL__
#define __CTOKENIZERFUNCTIONCOMMENTASCHAR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CTokenizerFunctionCommentAsChar::CTokenizerFunctionCommentAsChar(const Tchar a_cComment/* = STR('#') */) :
  CTokenizerFunctionCharDelimiters(NString::CString(STR(" \n\r\t")), NString::CString::EMPTY, false),
  m_Comment(a_cComment)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTokenizerFunctionCommentAsChar::CTokenizerFunctionCommentAsChar(const CTokenizerFunctionCommentAsChar& a_crInstance) :
  CTokenizerFunctionCharDelimiters(a_crInstance),
  m_Comment(a_crInstance.m_Comment)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTokenizerFunctionCommentAsChar::~CTokenizerFunctionCommentAsChar()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTokenizerFunctionCommentAsChar& CTokenizerFunctionCommentAsChar::operator = (const CTokenizerFunctionCommentAsChar& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CTokenizerFunctionCommentAsChar::reset()
{ CALL
  return CTokenizerFunctionCharDelimiters::reset();
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTokenizerFunctionCommentAsChar::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTokenizer::CTokenizerFunctionCommentAsChar")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CTokenizerFunctionCharDelimiters&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_Comment, STR("m_Comment")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
