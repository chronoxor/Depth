/*!
 *  \file    MConceptPredicate2.inl Template checking conception. Checks if
 *           template argument is a predicate with 2 arguments.
 *  \brief   Predicate with 2 arguments template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Predicate with 2 arguments template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functions conception checking
    VERSION:   1.0
    CREATED:   26.04.2006 20:47:53

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
#ifndef __MCONCEPTPREDICATE2_INL__
#define __MCONCEPTPREDICATE2_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NFunctions {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <typename T_Predicate, typename T_Argument1, typename T_Argument2>
inline MConceptPredicate2<T_Predicate, T_Argument1, T_Argument2>::MConceptPredicate2() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Predicate, typename T_Argument1, typename T_Argument2>
inline MConceptPredicate2<T_Predicate, T_Argument1, T_Argument2>::~MConceptPredicate2()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Predicate, typename T_Argument1, typename T_Argument2>
inline void MConceptPredicate2<T_Predicate, T_Argument1, T_Argument2>::constraints()
{ CALL
  // Check for ability to directly call a predicate with 2 arguments.
  MConstraint::requiresConvertibleToBoolean(m_fPredicate(m_Argument1, m_Argument2));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
