/*!
 *  \file    MConceptBoolAll.inl Template checking conception. Checks if
 *           template arguments types can be used with all boolean operators.
 *  \brief   Template checking conception for using with boolean operators (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template checking conception for using with boolean operators (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Operators conception checking
    VERSION:   1.0
    CREATED:   16.01.2006 21:53:25

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
#ifndef __MCONCEPTBOOLALL_INL__
#define __MCONCEPTBOOLALL_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NOperators {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <typename T_FirstType, typename T_SecondType>
inline MConceptBoolAll<T_FirstType, T_SecondType>::MConceptBoolAll() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline MConceptBoolAll<T_FirstType, T_SecondType>::~MConceptBoolAll()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline void MConceptBoolAll<T_FirstType, T_SecondType>::constraints()
{ CALL
  constraintsEqualOperator();
  constraintsNotEqualOperator();
  constraintsLessThanOperator();
  constraintsMoreThanOperator();
  constraintsLessEqualOperator();
  constraintsMoreEqualOperator();
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline Tbool MConceptBoolAll<T_FirstType, T_SecondType>::constraintsEqualOperator()
{ CALL
  return (m_X == m_Y);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline Tbool MConceptBoolAll<T_FirstType, T_SecondType>::constraintsNotEqualOperator()
{ CALL
  return (m_X != m_Y);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline Tbool MConceptBoolAll<T_FirstType, T_SecondType>::constraintsLessThanOperator()
{ CALL
  return (m_X < m_Y);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline Tbool MConceptBoolAll<T_FirstType, T_SecondType>::constraintsMoreThanOperator()
{ CALL
  return (m_X > m_Y);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline Tbool MConceptBoolAll<T_FirstType, T_SecondType>::constraintsLessEqualOperator()
{ CALL
  return (m_X <= m_Y);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline Tbool MConceptBoolAll<T_FirstType, T_SecondType>::constraintsMoreEqualOperator()
{ CALL
  return (m_X >= m_Y);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
