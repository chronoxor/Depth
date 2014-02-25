/*!
 *  \file    MConceptIString.inl Template checking conception. Checks if
 *           template argument is a non constant string class.
 *  \brief   Non constant string class template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant string class template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Types conception checking
    VERSION:   1.0
    CREATED:   06.05.2008 21:25:54

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
#ifndef __MCONCEPTISTRING_INL__
#define __MCONCEPTISTRING_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NTypes {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <class T_Class>
inline MConceptIString<T_Class>::MConceptIString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptIString<T_Class>::~MConceptIString()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptIString<T_Class>::constraints()
{ CALL
  // Check T_Class template argument constraint to be a constant string class.
  MConstraint::requiresConcept<MConceptIStringConst<T_Class> >();

  Tuint index = 0;
  Tuint size = 0;
  Tbool logic = false;
  typename T_Class::TType c = 0;
  typename T_Class::TType* buffer;

  // Check for buffer operator.
  buffer = (typename T_Class::TType*)m_String;

  // Check for assign operators.
  m_String = m_String;
  // Check for string alteration.
  m_String[index] = 0;

  // Check for 'EMPTY' static attribute.
  m_String = T_Class::EMPTY;

  // Check for convesion into the system string.
  NString::CSystemString sys = m_String.operator NString::CSystemString();

  // Check for non constant string methods.
  buffer = m_String.getBuffer();
  m_String = m_String.getLeft(index);
  m_String = m_String.getRight(index);
  m_String = m_String.getMiddle(index, index);
  logic = m_String.clear();
  logic = m_String.insertFirst(c);
  logic = m_String.insertFirst(m_String);
  logic = m_String.insertLast(c);
  logic = m_String.insertLast(m_String);
  logic = m_String.insertIndex(index, c);
  logic = m_String.insertIndex(index, m_String);
  logic = m_String.removeFirst();
  logic = m_String.removeFirst(c);
  logic = m_String.removeFirst(size);
  logic = m_String.removeFirst(size, m_String);
  logic = m_String.removeLast();
  logic = m_String.removeLast(c);
  logic = m_String.removeLast(size);
  logic = m_String.removeLast(size, m_String);
  logic = m_String.removeIndex(index);
  logic = m_String.removeIndex(index, c);
  logic = m_String.removeIndex(index, size);
  logic = m_String.removeIndex(index, size, m_String);
  logic = m_String.remove(index, size);
  logic = m_String.resize(index, c);
  logic = m_String.resizeBy(index, c);
  logic = m_String.replace(index, size, m_String);
  logic = m_String.insertCEnd();
  logic = m_String.removeCEnd();
  m_String.reverse();
  m_String.toLowerCase();
  m_String.toUpperCase();
  m_String.toTitleCase();
  m_String.toToggleCase();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
