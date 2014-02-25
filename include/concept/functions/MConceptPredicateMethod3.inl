/*!
 *  \file    MConceptPredicateMethod3.inl Template checking conception.
 *           Checks if template argument is a class predicate method
 *           with 3 arguments.
 *  \brief   Class predicate method with 3 arguments template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Class predicate method with 3 arguments template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functions conception checking
    VERSION:   1.0
    CREATED:   26.04.2006 22:36:42

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
#ifndef __MCONCEPTPREDICATEMETHOD3_INL__
#define __MCONCEPTPREDICATEMETHOD3_INL__
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
template <typename T_PredicateMethod, class T_Class, typename T_Argument1, typename T_Argument2, typename T_Argument3>
inline MConceptPredicateMethod3<T_PredicateMethod, T_Class, T_Argument1, T_Argument2, T_Argument3>::MConceptPredicateMethod3() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_PredicateMethod, class T_Class, typename T_Argument1, typename T_Argument2, typename T_Argument3>
inline MConceptPredicateMethod3<T_PredicateMethod, T_Class, T_Argument1, T_Argument2, T_Argument3>::~MConceptPredicateMethod3()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_PredicateMethod, class T_Class, typename T_Argument1, typename T_Argument2, typename T_Argument3>
inline void MConceptPredicateMethod3<T_PredicateMethod, T_Class, T_Argument1, T_Argument2, T_Argument3>::constraints()
{ CALL
  // Check for ability to directly call a class predicate method with 3 arguments.
  MConstraint::requiresConvertibleToBoolean((m_Class.*m_PredicateMethod)(m_Argument1, m_Argument2, m_Argument3));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
