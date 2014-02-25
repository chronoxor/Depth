/*!
 *  \file    MConceptMethod5.inl Template checking conception. Checks if
 *           template argument is a class method with 5 arguments.
 *  \brief   Class method with 5 arguments template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Class method with 5 arguments template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functions conception checking
    VERSION:   1.0
    CREATED:   26.04.2006 22:24:53

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
#ifndef __MCONCEPTMETHOD5_INL__
#define __MCONCEPTMETHOD5_INL__
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
template <typename T_Method, class T_Class, typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
inline MConceptMethod5<T_Method, T_Class, T_Result, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5>::MConceptMethod5() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Method, class T_Class, typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
inline MConceptMethod5<T_Method, T_Class, T_Result, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5>::~MConceptMethod5()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Method, class T_Class, typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
inline void MConceptMethod5<T_Method, T_Class, T_Result, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5>::constraints()
{ CALL
  // Check for ability to directly call a class method with 5 arguments.
  m_Result = (m_Class.*m_Method)(m_Argument1, m_Argument2, m_Argument3, m_Argument4, m_Argument5);
}
/*--------------------------------------------------------------------------*/
template <typename T_Method, class T_Class, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
inline MConceptMethod5<T_Method, T_Class, void, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5>::MConceptMethod5() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Method, class T_Class, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
inline MConceptMethod5<T_Method, T_Class, void, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5>::~MConceptMethod5()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Method, class T_Class, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
inline void MConceptMethod5<T_Method, T_Class, void, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5>::constraints()
{ CALL
  // Check for ability to directly call an empty return class method with 5 arguments.
  (m_Class.*m_Method)(m_Argument1, m_Argument2, m_Argument3, m_Argument4, m_Argument5);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
