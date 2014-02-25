/*!
 *  \file    MConceptUnaryPrefixInc.inl Template checking conception. Checks
 *           if template arguments types can be used with unary prefix '++'
 *           operator.
 *  \brief   Template checking conception for using with unary prefix '++' operator (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template checking conception for using with unary prefix '++' operator (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Operators conception checking
    VERSION:   1.0
    CREATED:   16.01.2006 22:37:48

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
#ifndef __MCONCEPTUNARYPREFIXINC_INL__
#define __MCONCEPTUNARYPREFIXINC_INL__
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
template <typename T_ResultType, typename T_FirstType>
inline MConceptUnaryPrefixInc<T_ResultType, T_FirstType>::MConceptUnaryPrefixInc() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_ResultType, typename T_FirstType>
inline MConceptUnaryPrefixInc<T_ResultType, T_FirstType>::~MConceptUnaryPrefixInc()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_ResultType, typename T_FirstType>
inline void MConceptUnaryPrefixInc<T_ResultType, T_FirstType>::constraints()
{ CALL
  constraintsOperator();
}
/*--------------------------------------------------------------------------*/
template <typename T_ResultType, typename T_FirstType>
inline T_ResultType MConceptUnaryPrefixInc<T_ResultType, T_FirstType>::constraintsOperator()
{ CALL
  return (++m_X);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
