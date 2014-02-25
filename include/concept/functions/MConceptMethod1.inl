/*!
 *  \file    MConceptMethod1.inl Template checking conception. Checks if
 *           template argument is a class method with 1 argument.
 *  \brief   Class method with 1 argument template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Class method with 1 argument template checking conception (inline).

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
#ifndef __MCONCEPTMETHOD1_INL__
#define __MCONCEPTMETHOD1_INL__
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
template <typename T_Method, class T_Class, typename T_Result, typename T_Argument1>
inline MConceptMethod1<T_Method, T_Class, T_Result, T_Argument1>::MConceptMethod1() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Method, class T_Class, typename T_Result, typename T_Argument1>
inline MConceptMethod1<T_Method, T_Class, T_Result, T_Argument1>::~MConceptMethod1()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Method, class T_Class, typename T_Result, typename T_Argument1>
inline void MConceptMethod1<T_Method, T_Class, T_Result, T_Argument1>::constraints()
{ CALL
  // Check for ability to directly call a class method with 1 argument.
  m_Result = (m_Class.*m_Method)(m_Argument1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Method, class T_Class, typename T_Argument1>
inline MConceptMethod1<T_Method, T_Class, void, T_Argument1>::MConceptMethod1() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Method, class T_Class, typename T_Argument1>
inline MConceptMethod1<T_Method, T_Class, void, T_Argument1>::~MConceptMethod1()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Method, class T_Class, typename T_Argument1>
inline void MConceptMethod1<T_Method, T_Class, void, T_Argument1>::constraints()
{ CALL
  // Check for ability to directly call an empty return class method with 1 argument.
  (m_Class.*m_Method)(m_Argument1);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
