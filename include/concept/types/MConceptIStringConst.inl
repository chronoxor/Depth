/*!
 *  \file    MConceptIStringConst.inl Template checking conception. Checks if
 *           template argument is a constant string class.
 *  \brief   Constant string class template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant string class template checking conception (inline).

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
#ifndef __MCONCEPTISTRINGCONST_INL__
#define __MCONCEPTISTRINGCONST_INL__
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
inline MConceptIStringConst<T_Class>::MConceptIStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptIStringConst<T_Class>::~MConceptIStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptIStringConst<T_Class>::constraints()
{ CALL
  Tuint cmp = 0;
  Tuint index = 0;
  Tbool logic = false;
  const typename T_Class::TType* buffer;

  // Check for buffer operator.
  buffer = (const typename T_Class::TType*)m_StringConst;

  // Check for compare operators.
  logic = (m_StringConst[index] == m_StringConst[index]);
  logic = (m_StringConst[index] != m_StringConst[index]);
  logic = (m_StringConst[index] <  m_StringConst[index]);
  logic = (m_StringConst[index] >  m_StringConst[index]);
  logic = (m_StringConst[index] <= m_StringConst[index]);
  logic = (m_StringConst[index] >= m_StringConst[index]);
  logic = (m_StringConst == m_StringConst);
  logic = (m_StringConst != m_StringConst);

  // Check for constant string methods.
  logic  = m_StringConst.isEmpty();
  index  = m_StringConst.getSize();
  buffer = m_StringConst.getBuffer();

  // Check for constant string static methods.
  cmp  = T_Class::compare(m_StringConst, m_StringConst);
  cmp  = T_Class::compareIgnoreCase(m_StringConst, m_StringConst);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
