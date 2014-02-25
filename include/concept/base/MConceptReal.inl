/*!
 *  \file    MConceptReal.inl Template checking conception. Checks if
 *           template argument is real number type.
 *  \brief   Real number template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Real number template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base types conception checking
    VERSION:   1.0
    CREATED:   15.01.2006 22:36:15

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
#ifndef __MCONCEPTREAL_INL__
#define __MCONCEPTREAL_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <typename T_Type>
inline MConceptReal<T_Type>::MConceptReal() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline MConceptReal<T_Type>::~MConceptReal()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void MConceptReal<T_Type>::constraints()
{ CALL
  // Check T_Type template argument constraint to be a constructible type.
  MConstraint::requiresConcept<NClass::MConceptConstructible<T_Type> >();

  Tbool logic;

  // Check for initialize with real number.
  m_X = (T_Type)0.0;
  // Check for assign operators.
  m_X = m_Y;
  // Check for additional assign operators.
  m_X += m_Y;
  m_X -= m_Y;
  m_X *= m_Y;
  m_X /= m_Y;
  // Check for unary operators.
  m_X = +m_Y;
  m_X = -m_Y;
  m_X = !m_Y;
  // Check for increment/decrement operators.
  m_X = ++m_Y;
  m_X = m_Y++;
  m_X = --m_Y;
  m_X = m_Y--;
  // Check for binary operators.
  m_X = (m_X + m_Y);
  m_X = (m_X - m_Y);
  m_X = (m_X * m_Y);
  m_X = (m_X / m_Y);
  // Check for compare operators.
  logic = (m_X == m_Y);
  logic = (m_X != m_Y);
  logic = (m_X <  m_Y);
  logic = (m_X >  m_Y);
  logic = (m_X <= m_Y);
  logic = (m_X >= m_Y);
  // Check for logic operators.
  logic = (m_X && m_Y);
  logic = (m_X || m_Y);
}
/*--------------------------------------------------------------------------*/
inline MConceptReal<Tfloat>::MConceptReal() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptReal<Tfloat>::~MConceptReal()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptReal<Tfloat>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptReal<Tdouble>::MConceptReal() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptReal<Tdouble>::~MConceptReal()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptReal<Tdouble>::constraints()
{ CALL

}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
