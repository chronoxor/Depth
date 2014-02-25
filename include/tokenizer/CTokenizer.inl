/*!
 *  \file    CTokenizer.inl Tokenizer class is used to split input stream into
 *           the string tokens based on the given rule.
 *  \brief   Tokenizer class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   23.04.2009 03:27:25

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
#ifndef __CTOKENIZER_INL__
#define __CTOKENIZER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CTokenizer::CTokenizer() :
  NCommon::NContainers::IStackConst<CTokenizer, NString::CString, CTokenizerIterator, CTokenizerIterator>(),
  m_pInputIterator(NULL),
  m_pTokenFunction(NULL),
  m_IsEndOfStream(true)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline CTokenizer::CTokenizer(const T_Iterator& a_crInputIterator, const ITokenizerFunction& a_crTokenizerFunction/* = CTokenizerFunctionCharDelimiters() */) :
  NCommon::NContainers::IStackConst<CTokenizer, NString::CString, CTokenizerIterator, CTokenizerIterator>(),
  m_pInputIterator(NULL),
  m_pTokenFunction(NULL),
  m_IsEndOfStream(true)
{ CALL
  set(a_crInputIterator, a_crTokenizerFunction);
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline CTokenizer::CTokenizer(const Tbool a_cContainerFlag, const T_Container& a_crInputContainer, const ITokenizerFunction& a_crTokenizerFunction/* = CTokenizerFunctionCharDelimiters() */) :
  NCommon::NContainers::IStackConst<CTokenizer, NString::CString, CTokenizerIterator, CTokenizerIterator>(),
  m_pInputIterator(NULL),
  m_pTokenFunction(NULL),
  m_IsEndOfStream(true)
{ CALL
  set(a_crInputContainer, a_crTokenizerFunction);
}
/*--------------------------------------------------------------------------*/
inline CTokenizer::CTokenizer(const CTokenizer& a_crInstance) :
  NCommon::NContainers::IStackConst<CTokenizer, NString::CString, CTokenizerIterator, CTokenizerIterator>(),
  m_pInputIterator(NULL),
  m_pTokenFunction(NULL),
  m_IsEndOfStream(true)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CTokenizer& CTokenizer::operator = (const CTokenizer& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline Tbool CTokenizer::set(const T_Iterator& a_crInputIterator, const ITokenizerFunction& a_crTokenizerFunction/* = CTokenizerFunctionCharDelimiters() */)
{ CALL
  return (setInputIterator(a_crInputIterator) && setTokenizerFunction(a_crTokenizerFunction));
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline Tbool CTokenizer::set(const Tbool a_cContainerFlag, const T_Container& a_crInputContainer, const ITokenizerFunction& a_crTokenizerFunction/* = CTokenizerFunctionCharDelimiters() */)
{ CALL
  IGNORE_UNUSED(a_cContainerFlag);

  return (setInputContainer(a_crInputContainer) && setTokenizerFunction(a_crTokenizerFunction));
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline Tbool CTokenizer::setInputIterator(const T_Iterator& a_crInputIterator)
{ CALL
  // Delete a clone of the input iterator.
  if (m_pInputIterator != NULL)
    delete m_pInputIterator;

  // Store a clone of the given input iterator.
  m_pInputIterator = NDetails::CTokenizerInputIterator<T_Iterator>(a_crInputIterator).clone();
  if (m_pInputIterator == NULL)
    return false;

  m_IsEndOfStream = !m_pInputIterator->isValid();
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline Tbool CTokenizer::setInputContainer(const T_Container& a_crInputContainer)
{ CALL
  // Delete a clone of the input iterator.
  if (m_pInputIterator != NULL)
    delete m_pInputIterator;

  // Store a clone of the first iterator of the given input container.
  m_pInputIterator = NDetails::CTokenizerInputContainer<T_Container>(a_crInputContainer).clone();
  if (m_pInputIterator == NULL)
    return false;

  m_IsEndOfStream = !m_pInputIterator->isValid();
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CTokenizer::isEmpty() const
{ CALL
  return ((m_pInputIterator == NULL) || !m_pInputIterator->isValid() || (m_pTokenFunction == NULL));
}
/*--------------------------------------------------------------------------*/
inline Tuint CTokenizer::getSize() const
{ CALL
  return (isEmpty() ? 0 : 1);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTokenizer::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Tokenizer cannot be serialized."));
  return false;
}
/*--------------------------------------------------------------------------*/
inline void CTokenizer::swap(CTokenizer& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pInputIterator, a_rInstance.m_pInputIterator);
  NAlgorithms::NCommon::swap(m_pTokenFunction, a_rInstance.m_pTokenFunction);
  NAlgorithms::NCommon::swap(m_IsEndOfStream, a_rInstance.m_IsEndOfStream);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
