/*!
 *  \file    MConceptAssignCopy.inl Template checking conception. Checks if
 *           template argument has both assign operator and copy constructor.
 *  \brief   Assignable and copyable template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Assignable and copyable template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Class conception checking
    VERSION:   1.0
    CREATED:   16.01.2006 00:56:25

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
#ifndef __MCONCEPTASSIGNCOPY_INL__
#define __MCONCEPTASSIGNCOPY_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NClass {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <class T_Class>
inline MConceptAssignCopy<T_Class>::MConceptAssignCopy() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptAssignCopy<T_Class>::~MConceptAssignCopy()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void MConceptAssignCopy<T_Type>::constraints()
{ CALL
  T_Type y(m_X);
  m_X = m_X;
  constraintsConst(m_X);

  IGNORE_UNUSED(y);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void MConceptAssignCopy<T_Type>::constraintsConst(const T_Type& a_crX)
{ CALL
  T_Type z(a_crX);
  m_X = a_crX;

  IGNORE_UNUSED(z);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
