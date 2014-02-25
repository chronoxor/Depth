/*!
 *  \file    MConceptNumber.inl Template checking conception. Checks if
 *           template argument is number.
 *  \brief   Number template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Number template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base types conception checking
    VERSION:   1.0
    CREATED:   15.01.2006 22:25:19

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
#ifndef __MCONCEPTNUMBER_INL__
#define __MCONCEPTNUMBER_INL__
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
inline MConceptNumber<T_Type>::MConceptNumber() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline MConceptNumber<T_Type>::~MConceptNumber()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void MConceptNumber<T_Type>::constraints()
{ CALL
  // Check T_Type template argument constraint to be a constructible type.
  MConstraint::requiresConcept<NClass::MConceptConstructible<T_Type> >();

  Tbool logic;

  // Check for initialize with number.
  m_X = (T_Type)0;
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
inline MConceptNumber<Tsint08>::MConceptNumber() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tsint08>::~MConceptNumber()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptNumber<Tsint08>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tsint16>::MConceptNumber() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tsint16>::~MConceptNumber()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptNumber<Tsint16>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tsint32>::MConceptNumber() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tsint32>::~MConceptNumber()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptNumber<Tsint32>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tsint64>::MConceptNumber() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tsint64>::~MConceptNumber()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptNumber<Tsint64>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tuint08>::MConceptNumber() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tuint08>::~MConceptNumber()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptNumber<Tuint08>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tuint16>::MConceptNumber() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tuint16>::~MConceptNumber()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptNumber<Tuint16>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tuint32>::MConceptNumber() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tuint32>::~MConceptNumber()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptNumber<Tuint32>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tuint64>::MConceptNumber() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tuint64>::~MConceptNumber()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptNumber<Tuint64>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tfloat>::MConceptNumber() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tfloat>::~MConceptNumber()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptNumber<Tfloat>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tdouble>::MConceptNumber() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptNumber<Tdouble>::~MConceptNumber()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptNumber<Tdouble>::constraints()
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
