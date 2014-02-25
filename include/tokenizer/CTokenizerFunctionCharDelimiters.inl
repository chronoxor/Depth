/*!
 *  \file    CTokenizerFunctionCharDelimiters.inl Character delimiters
 *           tokenizer function uses a list of characters as token
 *           delimiters.
 *  \brief   Character delimiters tokenizer function class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character delimiters tokenizer function class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   21.04.2009 03:27:49

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
#ifndef __CTOKENIZERFUNCTIONCHARDELIMITERS_INL__
#define __CTOKENIZERFUNCTIONCHARDELIMITERS_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CTokenizerFunctionCharDelimiters::~CTokenizerFunctionCharDelimiters()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTokenizerFunctionCharDelimiters& CTokenizerFunctionCharDelimiters::operator = (const CTokenizerFunctionCharDelimiters& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CTokenizerFunctionCharDelimiters::reset()
{ CALL
  m_TokenReturned = false;
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTokenizerFunctionCharDelimiters::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTokenizer::CTokenizerFunctionCharDelimiters")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Dropped, STR("m_Dropped")));
    CHECK(a_rArchive.doValue(m_Kept, STR("m_Kept")));
    CHECK(a_rArchive.doValue(m_DroppedIsSpace, STR("m_DroppedIsSpace")));
    CHECK(a_rArchive.doValue(m_KeptIsPunct, STR("m_KeptIsPunct")));
    CHECK(a_rArchive.doValue(m_ReturnEmptyTokens, STR("m_ReturnEmptyTokens")));
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
