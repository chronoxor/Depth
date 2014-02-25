/*!
 *  \file    CTokenizerFunctionOffsetDelimiters.inl Offset delimiters
 *           tokenizer function uses a list of the offset indexes to
 *           split the input stream into tokens.
 *  \brief   Offset delimiters tokenizer function class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Offset delimiters tokenizer function class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   24.04.2009 03:23:11

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
#ifndef __CTOKENIZERFUNCTIONOFFSETDELIMITERS_INL__
#define __CTOKENIZERFUNCTIONOFFSETDELIMITERS_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CTokenizerFunctionOffsetDelimiters::CTokenizerFunctionOffsetDelimiters() :
  ITokenizerFunction(),
  m_Offsets(),
  m_CurrentOffset(0),
  m_WrapOffsets(true),
  m_ReturnLastPartially(true)
{ CALL
  m_Offsets.insertLast(1);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline CTokenizerFunctionOffsetDelimiters::CTokenizerFunctionOffsetDelimiters(const T_Iterator& a_crIterator, const Tbool a_cWrapOffsets/* = true */, const Tbool a_cReturnLastPartially/* = true */) :
  ITokenizerFunction(),
  m_Offsets(),
  m_CurrentOffset(0),
  m_WrapOffsets(a_cWrapOffsets),
  m_ReturnLastPartially(a_cReturnLastPartially)
{ CALL
  set(a_crIterator, a_cWrapOffsets, a_cReturnLastPartially);
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline CTokenizerFunctionOffsetDelimiters::CTokenizerFunctionOffsetDelimiters(const Tbool a_cContainerFlag, const T_Container& a_crContainer, const Tbool a_cWrapOffsets/* = true */, const Tbool a_cReturnLastPartially/* = true */) :
  ITokenizerFunction(),
  m_Offsets(),
  m_CurrentOffset(0),
  m_WrapOffsets(a_cWrapOffsets),
  m_ReturnLastPartially(a_cReturnLastPartially)
{ CALL
  set(a_cContainerFlag, a_crContainer, a_cWrapOffsets, a_cReturnLastPartially);
}
/*--------------------------------------------------------------------------*/
inline CTokenizerFunctionOffsetDelimiters::CTokenizerFunctionOffsetDelimiters(const CTokenizerFunctionOffsetDelimiters& a_crInstance) :
  ITokenizerFunction(),
  m_Offsets(),
  m_CurrentOffset(0),
  m_WrapOffsets(true),
  m_ReturnLastPartially(true)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CTokenizerFunctionOffsetDelimiters::~CTokenizerFunctionOffsetDelimiters()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTokenizerFunctionOffsetDelimiters& CTokenizerFunctionOffsetDelimiters::operator = (const CTokenizerFunctionOffsetDelimiters& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline Tbool CTokenizerFunctionOffsetDelimiters::set(const T_Iterator& a_crIterator, const Tbool a_cWrapOffsets/* = true */, const Tbool a_cReturnLastPartially/* = true */)
{ CALL
  // Clear old offsets values.
  if (!m_Offsets.clear())
    return false;

  // Insert new offset values.
  NAlgorithms::NIterators::copyNext(a_crIterator, m_Offsets.getItLast());

  m_WrapOffsets = a_cWrapOffsets;
  m_ReturnLastPartially = a_cReturnLastPartially;
  return reset();
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline Tbool CTokenizerFunctionOffsetDelimiters::set(const Tbool a_cContainerFlag, const T_Container& a_crContainer, const Tbool a_cWrapOffsets/* = true */, const Tbool a_cReturnLastPartially/* = true */)
{ CALL
  IGNORE_UNUSED(a_cContainerFlag);

  // Clear old offsets values.
  if (!m_Offsets.clear())
    return false;

  // Insert new offset values.
  NAlgorithms::NContainers::copy(a_crContainer, m_Offsets);

  m_WrapOffsets = a_cWrapOffsets;
  m_ReturnLastPartially = a_cReturnLastPartially;
  return reset();
}
/*--------------------------------------------------------------------------*/
inline Tbool CTokenizerFunctionOffsetDelimiters::reset()
{ CALL
  m_CurrentOffset = 0;
  return !m_Offsets.isEmpty();
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTokenizerFunctionOffsetDelimiters::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTokenizer::CTokenizerFunctionOffsetDelimiters")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Offsets, STR("m_Offsets")));
    CHECK(a_rArchive.doValue(m_CurrentOffset, STR("m_CurrentOffset")));
    CHECK(a_rArchive.doValue(m_WrapOffsets, STR("m_WrapOffsets")));
    CHECK(a_rArchive.doValue(m_ReturnLastPartially, STR("m_ReturnLastPartially")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
