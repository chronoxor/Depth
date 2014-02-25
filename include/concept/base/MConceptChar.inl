/*!
 *  \file    MConceptChar.inl Template checking conception. Checks if
 *           template argument is character type.
 *  \brief   Character value template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character value template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base types conception checking
    VERSION:   1.0
    CREATED:   10.03.2006 23:42:18

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
#ifndef __MCONCEPTCHAR_INL__
#define __MCONCEPTCHAR_INL__
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
inline MConceptChar<T_Type>::MConceptChar() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline MConceptChar<T_Type>::~MConceptChar()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void MConceptChar<T_Type>::constraints()
{ CALL
  // Check T_Type template argument constraint to be a constructible type.
  MConstraint::requiresConcept<NClass::MConceptConstructible<T_Type> >();

  Tbool logic;

  // Check for initialize with character.
  m_X = (T_Type)0;
  // Check for assign operators.
  m_X = m_Y;
  // Check for additional assign operators.
  m_X +=  m_Y;
  m_X -=  m_Y;
  m_X *=  m_Y;
  m_X /=  m_Y;
  m_X %=  m_Y;
  m_X &=  m_Y;
  m_X |=  m_Y;
  m_X ^=  m_Y;
  m_X >>= m_Y;
  m_X <<= m_Y;
  // Check for unary operators.
  m_X = +m_Y;
  m_X = -m_Y;
  m_X = ~m_Y;
  m_X = !m_Y;
  // Check for increment/decrement operators.
  m_X = ++m_Y;
  m_X = m_Y++;
  m_X = --m_Y;
  m_X = m_Y--;
  // Check for binary operators.
  m_X = (m_X +  m_Y);
  m_X = (m_X -  m_Y);
  m_X = (m_X *  m_Y);
  m_X = (m_X /  m_Y);
  m_X = (m_X %  m_Y);
  m_X = (m_X &  m_Y);
  m_X = (m_X |  m_Y);
  m_X = (m_X ^  m_Y);
  m_X = (m_X >> m_Y);
  m_X = (m_X << m_Y);
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
inline MConceptChar<Tschar>::MConceptChar() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptChar<Tschar>::~MConceptChar()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptChar<Tschar>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptChar<Twchar>::MConceptChar() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptChar<Twchar>::~MConceptChar()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptChar<Twchar>::constraints()
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
