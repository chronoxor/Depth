/*!
 *  \file    MConceptStringConst.inl Template checking conception. Checks if
 *           template argument is a constant string type.
 *  \brief   Constant string value template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant string value template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base types conception checking
    VERSION:   1.0
    CREATED:   27.03.2008 00:53:10

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
#ifndef __MCONCEPTSTRINGCONST_INL__
#define __MCONCEPTSTRINGCONST_INL__
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
inline MConceptStringConst<T_Type>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline MConceptStringConst<T_Type>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void MConceptStringConst<T_Type>::constraints()
{ CALL
  Tuint index;
  Tbool logic;

  // Check for string valid condition.
  logic = ((Tcptr)m_X == NULL);
  logic = ((Tcptr)m_X != NULL);
  // Check for compare operators.
  logic = (m_X[index] == 0);
  logic = (m_X[index] != 0);
  logic = (m_X[index] == m_Y[index]);
  logic = (m_X[index] != m_Y[index]);
  logic = (m_X[index] <  m_Y[index]);
  logic = (m_X[index] >  m_Y[index]);
  logic = (m_X[index] <= m_Y[index]);
  logic = (m_X[index] >= m_Y[index]);
}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<Tschar*>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<Tschar*>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<Tschar*>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const Tschar*>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const Tschar*>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<const Tschar*>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<volatile Tschar*>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<volatile Tschar*>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<volatile Tschar*>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const volatile Tschar*>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const volatile Tschar*>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<const volatile Tschar*>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<Tschar[]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<Tschar[]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<Tschar[]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const Tschar[]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const Tschar[]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<const Tschar[]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<volatile Tschar[]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<volatile Tschar[]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<volatile Tschar[]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const volatile Tschar[]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const volatile Tschar[]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<const volatile Tschar[]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<Tschar[t_N]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<Tschar[t_N]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline void MConceptStringConst<Tschar[t_N]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<const Tschar[t_N]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<const Tschar[t_N]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline void MConceptStringConst<const Tschar[t_N]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<volatile Tschar[t_N]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<volatile Tschar[t_N]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline void MConceptStringConst<volatile Tschar[t_N]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<const volatile Tschar[t_N]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<const volatile Tschar[t_N]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline void MConceptStringConst<const volatile Tschar[t_N]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<Twchar*>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<Twchar*>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<Twchar*>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const Twchar*>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const Twchar*>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<const Twchar*>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<volatile Twchar*>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<volatile Twchar*>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<volatile Twchar*>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const volatile Twchar*>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const volatile Twchar*>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<const volatile Twchar*>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<Twchar[]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<Twchar[]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<Twchar[]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const Twchar[]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const Twchar[]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<const Twchar[]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<volatile Twchar[]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<volatile Twchar[]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<volatile Twchar[]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const volatile Twchar[]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptStringConst<const volatile Twchar[]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptStringConst<const volatile Twchar[]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<Twchar[t_N]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<Twchar[t_N]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline void MConceptStringConst<Twchar[t_N]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<const Twchar[t_N]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<const Twchar[t_N]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline void MConceptStringConst<const Twchar[t_N]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<volatile Twchar[t_N]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<volatile Twchar[t_N]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline void MConceptStringConst<volatile Twchar[t_N]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<const volatile Twchar[t_N]>::MConceptStringConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptStringConst<const volatile Twchar[t_N]>::~MConceptStringConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline void MConceptStringConst<const volatile Twchar[t_N]>::constraints()
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
